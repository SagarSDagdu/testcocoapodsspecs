//
//  ShiftInterval.swift
//  ZendriveSDKSwift
//
//  Created by Pushya Mitra on 11/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//
//
 import UIKit
 import ZendriveSDK

///
/// Wrapper for a single business hour interval.
///
 @objc(ZDShiftInterval) public final class ShiftInterval: NSObject {

    /// Start time of the shift interval, indicates when the shift interval starts.
    @objc public var startTime: ShiftTime

    /// End time of the shift interval, indicates when the shift interval ends.
    @objc public var endTime: ShiftTime

    /// Initialize the shift interval object with start time and end time.
    @objc public init(startTime: ShiftTime, endTime: ShiftTime) {
        self.startTime = startTime
        self.endTime = endTime
        super.init()
    }

    /// Initialize the `ShiftInterval` object with `ZendriveShiftInterval`.
    convenience init(with objcShiftInterval: ZendriveShiftInterval) {
        let startTime = ShiftTime(with: objcShiftInterval.startTime)
        let endTime = ShiftTime(with: objcShiftInterval.endTime)
        self.init(startTime: startTime, endTime: endTime)
    }

    /// Converts the shift interval object to `ZendriveShiftInterval` object.
    func toObjcShiftInterval() -> ZendriveShiftInterval {
        ZendriveShiftInterval(start: self.startTime.toObjcShiftTime(), end: self.endTime.toObjcShiftTime())
    }

    /// Converts an array of `ZendriveShiftInterval` to an array of `ShiftInterval`
    static func convertArray(_ objcShiftIntervals: [ZendriveShiftInterval]?) -> [ShiftInterval] {
        objcShiftIntervals?.map { ShiftInterval(with: $0) } ?? []
    }

    /// Converts an array of `ShiftInterval` to an array of `ZendriveShiftInterval`
    static func convertArray(_ shiftIntervals: [ShiftInterval]?) -> [ZendriveShiftInterval] {
        shiftIntervals?.map { $0.toObjcShiftInterval() } ?? []
    }

    /// Converts the shift interval object to dictionary
    /// Example
    /// ```
    ///     [
    ///         "start_time": [
    ///         "day_of_week": "Monday",
    ///         "hour": 11,
    ///         "minute": 0
    ///         ],
    ///         "end_time": [
    ///             "day_of_week": "Monday",
    ///             "hour": 14
    ///             "minute": 0
    ///         ]
    ///     ]
    /// ]
    /// ```
    ///
    @objc public func toDictionary() -> [String: Any]? {
        self.toObjcShiftInterval().toDictionary() as? [String: Any]
    }
 }
