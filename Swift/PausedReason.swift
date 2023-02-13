//
//  PausedReason.swift
//  ZendriveSDKSwift
//
//  Created by Pushya Mitra on 09/03/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

@objc(ZDPausedReason) public final class PausedReason: NSObject {

    @objc public var pausedReason: ZendrivePausedReasonEnum

    @objc public convenience init(pausedReason: NSInteger) {
        let objcPausedReason =  ZendrivePausedReason(zdrzdrPauseTrackingReason: pausedReason)
        self.init(with: objcPausedReason)
    }

    init(with objcPausedReason: ZendrivePausedReason) {
        self.pausedReason = objcPausedReason.pausedReason
    }
}
