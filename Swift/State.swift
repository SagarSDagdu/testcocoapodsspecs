//
//  ZendriveState.swift
//  ZendriveSDKSwift
//
//  Created by Sudeep Kumar on 21/06/19.
//  Copyright © 2019 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

/// Represents the current state of the Zendrive SDK.
@objc(ZDState) public class State: NSObject {

    /// The current configuration of the SDK.
    /// Refer to `Configuration` for further details.
    @objc public var zendriveConfiguration: Configuration!

    /// Is the SDK currently tracking a drive?
    @objc public var isDriveInProgress: Bool

    /**
     * Current value of businessHour.
     * businessHour is set when the SDK detects a change in the business hours set by the fleet manager and the current
     * business hours applied on the SDK.
     */
    @objc public var shiftDetails: ShiftDetail?

    /// Current value of pausedTillTimestamp.
    /// pausedTillTimestamp is set when `Zendrive.pauseAutoTracking(_:)` gets called.
    @objc public var pausedTillTimestamp: Int64

    @objc override convenience init() {
        self.init(with: ZendriveSDK.ZendriveState())!
    }

    convenience init?(with objcState: ZendriveSDK.ZendriveState?) {
        if let objcState = objcState {
            self.init(with: objcState)
        } else {
            return nil
        }
    }

    init(with objcState: ZendriveSDK.ZendriveState) {
        self.zendriveConfiguration = Configuration(with: objcState.zendriveConfiguration)
        self.isDriveInProgress = objcState.isDriveInProgress
        self.pausedTillTimestamp = objcState.pausedTillTimestamp
        self.shiftDetails = ShiftDetail(with: objcState.businessHour)
    }

    static func fromObjcState(with objcState: ZendriveSDK.ZendriveState?) -> State? {
        return State(with: objcState)
    }
}
