//
//  VehicleTaggingDetails.swift
//  ZendriveSDKSwift
//
//  Created by Atul Manwar on 04/02/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

/// Wrapper for vehicle tagging details for a drive.
@objc(ZDVehicleTaggingDetails) public class VehicleTaggingDetails: NSObject {

    /// The vehicleId of the tagged vehicle
    @objc public var vehicleId: String

    /// This flag determines if vehicle is tagged using beacon
    @objc public var isTaggedByBeacon: Bool

    /// This flag determines if vehicle is tagged using bluetooth stereo
    @objc public var isTaggedByBluetoothStereo: Bool

    /// Initializer for `VehicleTaggingDetails`.
    @objc public override convenience init() {
        self.init(with: ZendriveSDK.ZendriveVehicleTaggingDetails())
    }

    convenience init?(with objcVehicleTaggingDetails: ZendriveSDK.ZendriveVehicleTaggingDetails?) {
        if let objcVehicleTaggingDetails = objcVehicleTaggingDetails {
            self.init(with: objcVehicleTaggingDetails)
        } else {
            return nil
        }
    }

    init(with objcVehicleTaggingDetails: ZendriveSDK.ZendriveVehicleTaggingDetails) {
        vehicleId = objcVehicleTaggingDetails.vehicleId
        isTaggedByBeacon = objcVehicleTaggingDetails.isTaggedByBeacon
        isTaggedByBluetoothStereo = objcVehicleTaggingDetails.isTaggedByBluetoothStereo
    }

    func toObjcVehicleTaggingDetails() -> ZendriveVehicleTaggingDetails {
        let objcVehicleTaggingDetails = ZendriveVehicleTaggingDetails()
        objcVehicleTaggingDetails.vehicleId = vehicleId
        objcVehicleTaggingDetails.isTaggedByBeacon = isTaggedByBeacon
        objcVehicleTaggingDetails.isTaggedByBluetoothStereo = isTaggedByBluetoothStereo
        return objcVehicleTaggingDetails
    }
}
