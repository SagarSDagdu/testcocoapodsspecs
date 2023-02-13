//
//  ShiftDetail.swift
//  ZendriveSDKSwift
//
//  Created by Pushya Mitra on 11/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

import Foundation
import ZendriveSDK

/// Represents a shift comprising of shift intervals over the week.
@objc(ZDShiftDetail) public final class ShiftDetail: NSObject {

    /// The name of the shift.
    @objc public var shiftName: String?

    /// The unique identifer used to identify a shift.
    @objc public var shiftId: String

    /// A Timezone object which specifies the timezone of the shift.
    @objc public var timezone: TimeZone

    /// Shift intervals specify the intervals when the SDK should be active.
    @objc public var shiftIntervals: [ShiftInterval]

    /// Initialize the shift details object with shiftName, shiftId, timezone and shiftIntervals.
    @objc public init(shiftName: String?, shiftId: String, timezone: TimeZone, shiftIntervals: [ShiftInterval]) {
        self.shiftId = shiftId
        self.shiftName = shiftName
        self.timezone = timezone
        self.shiftIntervals = shiftIntervals
        super.init()
    }

    /// Initialize the shift details object with `ZendriveShiftDetail`.
    convenience init(with objcShiftDetail: ZendriveShiftDetail) {
        let shiftId = objcShiftDetail.shiftId
        let shiftName = objcShiftDetail.shiftName
        let timezone = objcShiftDetail.timezone
        let shiftIntervals = ShiftInterval.convertArray(objcShiftDetail.shiftIntervals)
        self.init(shiftName: shiftName, shiftId: shiftId, timezone: timezone, shiftIntervals: shiftIntervals)
    }

    /// Initialize the shift details object with `ZendriveShiftDetail`.
    convenience init?(with objcShiftDetail: ZendriveShiftDetail?) {
        guard let objcShiftDetail = objcShiftDetail else {
            return nil
        }
        self.init(with: objcShiftDetail)
    }

    /// Converts the object to `ZendriveShiftDetail`.
    func toObjcShiftDetail() -> ZendriveShiftDetail {
        ZendriveShiftDetail(shiftName: shiftName, shiftId: shiftId, timezone: timezone, shiftIntervals: ShiftInterval.convertArray(shiftIntervals))
    }

    /// Returns a dictionary format of the `shiftDetail`  object.
    /// This function can be used for printing the shift details returned by the SDK.
    /// Example:
    /// ```
    /// ["shift_name": "morning_shift",
    /// "timezone": "America/Los_Angeles",
    /// "shift_intervals":
    /// [
    ///     [
    ///         "start_time": [
    ///         "day_of_week": "Monday",
    ///         "time": "11:00 AM"
    ///         ],
    ///         "end_time": [
    ///             "day_of_week": "Monday",
    ///             "time": "02:00 PM"
    ///         ]
    ///     ]
    /// ],
    /// "shift_id": "zendrive_shift_1"]
    /// ```
    ///
    @objc public func toDictionary() -> [String: Any]? {
        self.toObjcShiftDetail().toDictionary() as? [String: Any]
    }
}
