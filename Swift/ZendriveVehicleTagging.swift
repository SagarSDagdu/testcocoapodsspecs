//
//  ZendriveVehicleTagging.swift
//  ZendriveSDKSwift
//
//  Created by Abhishek Aggarwal on 22/04/20.
//  Copyright © 2020 Zendrive Inc. All rights reserved.
//

import UIKit
import ZendriveSDK

/// This class manages association and dissociation of vehicles to Zendrive SDK.
@objc(ZDZendriveVehicleTagging) public class ZendriveVehicleTagging: NSObject {

    /// Associates the vehicle to Zendrive SDK.
    ///
    /// After successful association of vehicle information, whenever Zendrive SDK will detect
    /// a connection to this bluetooth device while the user is driving, it will include this vehicleId
    /// in the tags array of `AnalyzedDriveInfo`.
    ///
    /// If the user connect to bluetooth of multiple associated vehicles during the drive
    /// the latest vehicleId will be used as tag.  Maximum of two vehicles can be associated.
    ///
    /// - Note: The bluetooth device of the associated vehicle needs to be the audio route for some
    /// duration of the drive for tagging to happen.
    ///
    /// - Parameter vehicleInfo: The `VehicleInfo` object to associate.
    ///
    /// Refer to `ZendriveVehicleTaggingError` to get details on the errors thrown by this method.
    ///
    /// Example:
    ///
    /// ```
    /// let vehicleInfo = VehicleInfo(vehicleId: "vehicleId",
    ///                               bluetoothId: "14:0F:C7:62:F8:9E")
    /// try ZendriveVehicleTagging.associateVehicle(vehicleInfo)
    ///  ```
    ///
    /// Bluetooth stereos in automobiles are primarily classic Bluetooth devices, which might not be discoverable from your app.
    /// When you associate the user's vehicle, ask the user to connect their stereo and play audio.
    /// Then, use `getActiveBluetoothDevice()` to determine the active bluetooth connection and get the identifier
    /// of the device.
    /// Start with this code:
    ///
    /// ```
    ///  if let bluetoothDevice = ZendriveVehicleTagging.getActiveBluetoothDevice() {
    ///     let vehicleInfo = VehicleInfo(vehicleId: "vehicleId",
    ///                                   bluetoothId: bluetoothDevice.identifier)
    ///     try ZendriveVehicleTagging.associateVehicle(vehicleInfo)
    ///  }
    /// ```
    @objc public static func associateVehicle(_ vehicleInfo: VehicleInfo) throws {
        let objcVehicleInfo = vehicleInfo.toObjcVehicleInfo()
        do {
            try ZendriveSDK.ZendriveVehicleTagging.associateVehicle(objcVehicleInfo)
        } catch {
            throw ZendriveVehicleTaggingError.fromError(error) ?? error
        }
    }

    /// Dissociates the vehicle from Zendrive SDK.
    ///
    /// After successful dissociation of the vehicle, Zendrive SDK will stop tagging the trips for this vehicle.
    ///
    /// - Parameter vehicleId: The vehicleId of the vehicle which is to be dissociated.
    ///
    /// Refer to `ZendriveVehicleTaggingError` to get details on the errors thrown by this method.
    ///
    /// Example:
    ///
    /// ```
    /// let vehicleInfo = VehicleInfo(vehicleId: "vehicleId",
    ///                               bluetoothId: "14:0F:C7:62:F8:9E")
    /// try ZendriveVehicleTagging.dissociateVehicle(vehicleInfo.vehicleId)
    /// ```
    @objc public static func dissociateVehicle(_ vehicleId: String) throws {
        do {
            try ZendriveSDK.ZendriveVehicleTagging.dissociateVehicle(vehicleId)
        } catch {
            throw ZendriveVehicleTaggingError.fromError(error) ?? error
        }
    }

    /// - Returns:- The list of associated vehicles if sdk is setup, else nil.
    @objc public static func getAssociatedVehicles() -> [VehicleInfo]? {
        if let objcVehicleInfoArray =
            ZendriveSDK.ZendriveVehicleTagging.getAssociatedVehicles() {
            return objcVehicleInfoArray.map({ (objcVehicleInfo) -> VehicleInfo in
                return VehicleInfo(with: objcVehicleInfo)
            })
        } else {
            return nil
        }
    }

    ///
    /// Returns the active bluetooth device, if there is any, otherwise returns nil.
    ///
    /// The active bluetooth device is the one through which audio will play.
    /// Example: You may be connected to both car's stereo and airpods but only
    /// one of them will be active, the one through which audio is playing or
    /// will play.
    ///
    /// - Note: If the user does not have multiple connected audio devices
    /// like headphones, airpods etc, then the connected car's stereo is the
    /// active device.
    ///
    @objc public static func getActiveBluetoothDevice() -> BluetoothDevice? {
        if let objcBluetoothDevice = ZendriveSDK.ZendriveVehicleTagging .getActiveBluetoothDevice() {
            return  BluetoothDevice(with: objcBluetoothDevice)
        }
        return nil
    }

    ///
    /// Get all the beacons which are in the device's range.
    /// - Parameter uuid: The UUID of the beacons that are to be scanned.
    /// - Parameter major: The major of the beacons that are to be scanned.
    /// - Parameter minor:  The minor of the beacons that are to be scanned.
    /// - Parameter completionHandler: The completion handler which is to be executed after the completion of beacon scan.
    ///
    /// Example:
    /// ```
    /// ZendriveVehicleTagging.getNearbyBeacons(uuid: "FD94C06F-8667-46C2-A334-14C6BF8EDEC3",
    ///  major: 100,
    ///  minor: 100,
    ///  completionHandler: { (beaconsList: [ZendriveScannedBeaconInfo], error:  NSError?) -> Void in
    ///      if let error = error {
    ///          // handle the error
    ///      }
    ///     // update scanned beacons list in state or redraw UI
    ///     })
    /// ```
    ///
    @objc public static func getNearbyBeacons(uuid: String,
                                              major: Int32,
                                              minor: Int32,
                                              completionHandler: @escaping (_ scannedBeacons: [ScannedBeaconInfo], _ error: Error?) -> Void) {
        ZendriveSDK.ZendriveVehicleTagging.getNearbyBeacons(uuid, major: major, minor: minor) { scannedBeacons, error  in
            let beacons = scannedBeacons.map({ scannedBeacon in
                return ScannedBeaconInfo(with: scannedBeacon)
            })
            let swiftError = ZendriveError.fromError(error) ?? error
            completionHandler(beacons, swiftError)
        }
    }

    ///
    /// Get all the beacons which are in the device's range.
    ///
    /// - Parameter uuid: The UUID of the beacons that are to be scanned.
    /// - Parameter completionHandler: The completion handler which is to be executed after the completion of beacon scan.
    ///
    /// Example:
    /// ```
    /// ZendriveVehicleTagging.getNearbyBeacons(uuid: "FD94C06F-8667-46C2-A334-14C6BF8EDEC3",
    ///  completionHandler: { (beaconsList: [ZendriveScannedBeaconInfo], error:  NSError?) -> Void in
    ///      if let error = error {
    ///          // handle the error
    ///      }
    ///     // update scanned beacons list in state or redraw UI
    ///     })
    /// ```
    ///
    @objc public static func getNearbyBeacons(uuid: String,
                                              completionHandler: @escaping (_ scannedBeacons: [ScannedBeaconInfo], _ error: Error?) -> Void) {
        ZendriveSDK.ZendriveVehicleTagging.getNearbyBeacons(uuid, major: -1, minor: -1) { scannedBeacons, error  in
            let beacons = scannedBeacons.map({ scannedBeacon in
                return ScannedBeaconInfo(with: scannedBeacon)
            })
            let swiftError = ZendriveError.fromError(error) ?? error
            completionHandler(beacons, swiftError)
        }
    }
}
