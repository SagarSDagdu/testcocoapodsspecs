//
//  ZendriveShiftTime.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 06/01/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifndef ZendriveShiftTime_h
#define ZendriveShiftTime_h
NS_ASSUME_NONNULL_BEGIN

/**
 *  Enum to represent a day of the week.
 */
typedef NS_ENUM(int, ZendriveDayOfWeek) {
Sunday=1, Monday=2, Tuesday=3, Wednesday=4,Thursday=5,Friday=6,Saturday=7
};

/**
 *  Represents a particular day and time in a weekly schedule.
 *  The shift time is represented in 24 hour time format.
 */
@interface ZendriveShiftTime : NSObject

/**
 *  Represents the day of the week, range: [1-7]
 */
@property (nonatomic, assign) ZendriveDayOfWeek dayOfWeek;

/**
 *  Represents the hour of the day. range: [0-23].
 */
@property (nonatomic, assign) NSInteger hour;

/**
 *  Represents the minute of the hour. range: [0-59].
 */
@property (nonatomic, assign) NSInteger minute;

/**
 *  Initializes the ZendriveShiftTime object.
 *  Example
 *  @code
 *  ZendriveShiftTime *startTime = [[ZendriveShiftTime alloc initWithDayOfWeek:2 hour:11 minute:30];
 *  @endcode
 */
-(id)initWithDayOfWeek:(ZendriveDayOfWeek)dayOfWeek
                  hour:(NSInteger)hour
                minute:(NSInteger)minute;

/**
 *  Initializes the ZendriveShiftTime object with NSDictionary..
 *  Example
 *  @code
 *  NSDictionary *shiftTimeDictionary = {
 *      @"day_of_week": @"Sunday",
 *      @"hour": 11,
 *      @"minute": 30
 * }
 *  ZendriveShiftTime *startTime = [[ZendriveShiftTime alloc initWithDictionary:shiftTimeDictionary];
 *  @endcode
 */
-(id)initWithDictionary:(NSDictionary *)dictionary;

/**
 *  Initializes the ZendriveShiftTime object with NSDate.
 *  Example
 *  @code
 *  ZendriveShiftTime *startTime = [[ZendriveShiftTime alloc initWithDate:[[NSDate alloc] init]];
 *  @endcode
 */

-(id)initWithDate:(NSDate *)date timeZone:(NSTimeZone *)timezone;

/**
 *  Converts the the ZendriveShiftTime to dictionary.
 *  Example:
 *  @code
 *  {
 *      @"day_of_week": @"Sunday",
 *      @"hour": 11,
 *      @"minute": 30
 * }
 * @endcode
 */
-(NSDictionary *)toDictionary;

/**
 *  Converts the  String to ZendriveDayOfWeekEnum.
 */
+(ZendriveDayOfWeek)stringToDayOfWeek:(NSString *)dayOfWeekString;

/**
 *  Converts the  ZendriveDayOfWeekEnum to String.
 */
+(NSString *)getStringFromDayOfWeek:(ZendriveDayOfWeek)dayOfWeek;

/**
 *  Primarily used to compare two shift time objects having consecutive days,
 *  Example
 *  ZendriveShiftTime(Sunday 11,0) is less than ZendriveShiftTime(Sunday, 14,0)
 *  ZendriveShiftTime(Sunday 11,0) is less than ZendriveShiftTime(Monday, 14,0)
 *  ZendriveShiftTime(Sunday 11,0) is less than ZendriveShiftTime(Sunday, 11,1)
 *  ZendriveShiftTime(Sunday 11,0) is greater than ZendriveShiftTime(Sunday, 10,0)
 *  ZendriveShiftTime(Sunday 11,0) is greater than ZendriveShiftTime(Saturday, 14,0). (In a weekly schedule, the next day following Saturday is Sunday.)
 */
-(NSComparisonResult)compare:(id)object;

NS_ASSUME_NONNULL_END
@end
#endif /* ZendriveShiftInterval_h */


