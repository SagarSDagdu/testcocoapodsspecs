//
//  ZendriveMockPhoneScreenInteractionEventBuilder.h
//  ZendriveMockDriveTests
//
//  Created by Sudeep Kumar on 08/12/18.
//  Copyright © 2018 Zendrive Inc. All rights reserved.
//

#import "ZendriveMockRangeEventBuilder.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * An event builder for [phone screen interaction](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Enums/ZendriveEventType.html#/c:@E@ZendriveEventType@ZendriveEventPhoneScreenInteraction) event.
 */
@interface ZendriveMockPhoneScreenInteractionEventBuilder : ZendriveMockRangeEventBuilder

/**
 * Constructs and return a new phone screen interaction event builder.
 * @param startTimestamp [start timestamp](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Classes/ZendriveEvent.html#/c:objc(cs)ZendriveEvent(py)startTime) of the event
 * @param endTimestamp [end timestamp](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Classes/ZendriveEvent.html#/c:objc(cs)ZendriveEvent(py)endTime) of the event.
 */
- (id)initWithStartTimestamp:(long long)startTimestamp
                endTimestamp:(long long)endTimestamp;

@end

NS_ASSUME_NONNULL_END
