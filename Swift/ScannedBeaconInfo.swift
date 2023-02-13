//
//  ScannedBeaconInfo.swift
//  ZendriveSDKSwift
//
//  Created by Prakash Salawria on 03/05/21.
//  Copyright © 2021 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK
import CoreLocation

///
/// Wrapper for beacons scanned using `ZendriveVehicleTagging.getNearbyBeacons(uuid:major:minor:completionHandler:)`.
///
@objc(ZDScannedBeaconInfo) public class ScannedBeaconInfo: NSObject {

    /// The UUID of the scanned beacon.
    @objc public var uuid: String

    /// The major of the scanned beacon.
    @objc public var major: Int32

    /// The minor of the scanned beacon.
    @objc public var minor: Int32

    /// The RSSI of the scanned beacon.
    @objc public var rssi: Int

    /// Constants that reflect the relative distance to a beacon.
    @objc public var proximity: CLProximity

    /// The accuracy of the proximity value, measured in meters from the beacon.
    @objc public var accuracy: CLLocationAccuracy

    /// The timestamp representing when the beacon was observed.
    @objc public var timestamp: Int64

    /// Initialize with UUID, major, minor, RSSI, proximity, accuracy.
    @objc public convenience init(uuid: String,
                                  major: Int32,
                                  minor: Int32,
                                  rssi: Int,
                                  proximity: CLProximity,
                                  accuracy: CLLocationAccuracy,
                                  timestamp: Int64) {
        let objcScannedBeaconInfo: ZendriveSDK.ZendriveScannedBeaconInfo =
            ZendriveSDK.ZendriveScannedBeaconInfo(uuid: uuid,
                                              major: major as NSNumber,
                                              minor: minor as NSNumber,
                                              rssi: rssi as NSInteger,
                                              proximity: proximity,
                                              accuracy: accuracy,
                                              timestamp: timestamp)
        self.init(with: objcScannedBeaconInfo)
    }

    /// Initialize the beacon with UUID, major, minor.
    @objc public convenience init(uuid: String,
                                  major: Int32,
                                  minor: Int32) {

        let objcScannedBeaconInfo: ZendriveSDK.ZendriveScannedBeaconInfo =
            ZendriveSDK.ZendriveScannedBeaconInfo(uuid: uuid,
                                              major: major as NSNumber,
                                              minor: minor as NSNumber)
        self.init(with: objcScannedBeaconInfo)
    }

    /// Initialize the beacon with objective-c ZendriveScannedBeaconInfo object.
    @objc public init(with objcScannedBeaconInfo: ZendriveScannedBeaconInfo) {
        self.uuid = objcScannedBeaconInfo.uuid
        self.major = objcScannedBeaconInfo.major.int32Value
        self.minor = objcScannedBeaconInfo.minor.int32Value
        self.rssi = objcScannedBeaconInfo.rssi
        self.proximity = objcScannedBeaconInfo.proximity
        self.accuracy = objcScannedBeaconInfo.accuracy
        self.timestamp = objcScannedBeaconInfo.timestamp
        super.init()
    }

    /// Initialize the beacon with a CLBeacon object.
    @objc public convenience init(clBeacon: CLBeacon) {
        let objcScannedBeaconInfo: ZendriveSDK.ZendriveScannedBeaconInfo =
            ZendriveSDK.ZendriveScannedBeaconInfo(clBeacon: clBeacon)
        self.init(with: objcScannedBeaconInfo)
    }
}
