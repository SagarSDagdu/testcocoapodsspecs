//
//  ExtrapolationDetails.swift
//  ZendriveSDKSwift
//
//  Created by Prakash Salawria on 14/04/21.
//  Copyright © 2021 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

/// Wrapper for extrapolated details for a drive.
@objc(ZDExtrapolationDetails) public class ExtrapolationDetails: NSObject {

    /// The additional distance that might be covered before the drive start is detected.
    @objc public var extrapolatedDistance: Double

    /// The estimated start location of the active drive.
    @objc public var estimatedStartLocation: LocationPoint

    /// Initializer for `ExtrapolationDetails`.
    @objc public override convenience init() {
        self.init(with: ZendriveSDK.ZendriveExtrapolationDetails())
    }

    convenience init?(with objcExtrapolationDetails: ZendriveSDK.ZendriveExtrapolationDetails?) {
        if let objcExtrapolationDetails = objcExtrapolationDetails {
            self.init(with: objcExtrapolationDetails)
        } else {
            return nil
        }
    }

    init(with objcExtrapolationDetails: ZendriveSDK.ZendriveExtrapolationDetails) {
        self.extrapolatedDistance = objcExtrapolationDetails.extrapolatedDistance
        self.estimatedStartLocation = LocationPoint.fromObjcLocationPoint(objcExtrapolationDetails.estimatedStartLocation)
    }

    func toObjcExtrapolationDetails() -> ZendriveExtrapolationDetails {
        let objcExtrapolationDetails = ZendriveExtrapolationDetails()
        objcExtrapolationDetails.estimatedStartLocation = estimatedStartLocation.toObjcLocationPoint()
        objcExtrapolationDetails.extrapolatedDistance = extrapolatedDistance
        return objcExtrapolationDetails
    }
}
