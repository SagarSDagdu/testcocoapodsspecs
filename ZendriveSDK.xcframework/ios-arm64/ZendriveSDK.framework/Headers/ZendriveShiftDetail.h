//
//  ZendriveShiftDetail.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 11/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#ifndef ZendriveShiftDetail_h
#define ZendriveShiftDetail_h

#import <Foundation/Foundation.h>
#import "ZendriveShiftInterval.h"

@class ZendriveShiftInterval;
/**
 *  Represents a shift comprising of shift intervals over the week.
 */
@interface  ZendriveShiftDetail : NSObject

/**
 * The name of the shift.
 */
@property (nonatomic, nullable) NSString *shiftName;

/**
 * The unique identifer used to identify a shift.
 */
@property (nonatomic, nonnull) NSString *shiftId;

/**
 * An NSTimezone object which specifies the timezone of the shift.
 */
@property (nonatomic, nonnull) NSTimeZone *timezone;

/**
 * Shift intervals specify the intervals when the SDK should be active.
 */
@property (nonatomic, nullable) NSArray<ZendriveShiftInterval *> *shiftIntervals;

/**
 * Initialize the shift details object with shiftName, shiftId, timezone and shiftIntervals.
 */
-(id _Nonnull )initWithShiftName:(NSString *_Nullable)shiftName shiftId:(NSString * _Nonnull)shiftId timezone:(NSTimeZone * _Nonnull)timezone shiftIntervals:(NSArray <ZendriveShiftInterval*>*_Nonnull)shiftIntervals;

/**
 * Initialize the shift details object with Dictionary.
 */
-(id _Nonnull)initWithDictionary:(NSDictionary * _Nonnull)dictionary;

/**
 * Converts the ZendriveShiftDetail object to dictionary.
 * This function could be used for printing the shift details returned by SDK.
 * Example:
 * @code
 * {
 *     @"shift_id": "zendrive_shift_1",
 *     @"shift_name": "shift_1",
 *     @"timezone": "Asia/Kolkata",
 *     @"shift_intervals": {{
 *         @"start_time": {
 *             @"day_of_week": @"Sunday",
 *             @"hour": 11,
 *             @"minute": 30
 *         },
 *         @"end_time": {
 *             @"day_of_week": @"Sunday",
 *             @"hour": 14,
 *             @"minute": 0
 *         }
 *     }}
 * }
 * @endcode
 */
-(NSDictionary *_Nonnull)toDictionary;

@end

#endif /* ZendriveShiftDetail_h */
