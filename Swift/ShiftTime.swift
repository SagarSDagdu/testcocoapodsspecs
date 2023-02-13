//
//  ShiftTime.swift
//  ZendriveSDKSwift
//
//  Created by Pushya Mitra on 11/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

 import UIKit
 import ZendriveSDK

/// Represents a particular day and time in a weekly schedule, The shift time is represented in 24 hour time format.
 @objc(ZDShiftTime) public final class ShiftTime: NSObject {

    /// Represents the day of the week, range: [1-7]
    @objc public var dayOfWeek: ZendriveDayOfWeek

    /// Represents the hour of the day. range: [0-23].
    @objc public var hour: Int

    /// Represents the minute of the hour. range: [0-59].
    @objc public var minute: Int

    /// initializes the `ShiftTime` object.
    /// Example
    /// ```
    /// let shiftTime = ShiftTime(dayOfWeek: .sunday, hour: 11, minute: 40)
    /// ```
    @objc public convenience init(dayOfWeek: ZendriveDayOfWeek, hour: Int, minute: Int) {
        let objcShiftTime: ZendriveShiftTime = ZendriveShiftTime(dayOfWeek: dayOfWeek, hour: hour, minute: minute)
        self.init(with: objcShiftTime)
    }

    init(with objcShiftTime: ZendriveShiftTime) {
        self.dayOfWeek = objcShiftTime.dayOfWeek
        self.hour = objcShiftTime.hour
        self.minute = objcShiftTime.minute
    }

    /// Converts the `ShiftDetail` object to `ZendriveShiftDetail` object.
    @objc public func toObjcShiftTime() -> ZendriveShiftTime {
        return ZendriveShiftTime(dayOfWeek: dayOfWeek, hour: hour, minute: minute)
    }

    /// Converts the ShiftTime object to dictionary
    /// Example:
    /// ```
    /// ["day_of_week": "Sunday",
    /// "hour": 11,
    /// "minute": 59
    /// ]
    /// ```
    @objc public func toDictionary() -> [String: Any]? {
        return self.toObjcShiftTime().toDictionary() as? [String: Any]
    }
 }
