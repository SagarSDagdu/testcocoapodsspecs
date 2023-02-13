//
//  ZendriveShiftInterval.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 07/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZendriveShiftTime.h"

NS_ASSUME_NONNULL_BEGIN

@class ZendriveShiftTime;

/**
 *  Wrapper for a single business hour interval.
 */
@interface ZendriveShiftInterval: NSObject

/**
 *  Start time of the shift interval, indicates when the shift interval starts.
 */
@property (nonatomic, nonnull) ZendriveShiftTime *startTime;

/**
 *  End time of the shift interval, indicates when the shift interval ends.
 */
@property (nonatomic, nonnull) ZendriveShiftTime *endTime;

/**
 *  Initializer the shift interval object with start time and end time.
 */
-(id)initWithStartTime:(ZendriveShiftTime * _Nonnull)startTime
               endTime:(ZendriveShiftTime * _Nonnull)endTime;


/**
 *  Initialize the shift interval object with dictionary containing start_time and end_time keys.
 *  Example input dictionary:
 *  @code
 *  NSDictionary *dictionary = {
 *     @"start_time": {
 *         @"day_of_week": @"Sunday",
 *         @"hour": 11,
 *         @"minute": 30
 *     },
 *     @"end_time": {
 *         @"day_of_week": @"Sunday",
 *         @"hour": 14,
 *         @"minute": 0
 *     }
 * }
 *@endcode
 */
-(id)initWithDictionary:(NSDictionary * _Nonnull)dictionary;

/**
 * Converts the shift detail object to dictionary.
 * This can be used for logging the shift interval.
 * Example:
 * @code
 *NSDictionary *resultantDictionary = {
 *     @"start_time": {
 *         @"day_of_week": @"Sunday",
 *         @"hour": 11,
 *         @"minute": 30
 *     },
 *     @"end_time": {
 *         @"day_of_week": @"Sunday",
 *         @"hour": 14,
 *         @"minute": 0
 *     }
 * }
 * @endcode
 */
-(NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
