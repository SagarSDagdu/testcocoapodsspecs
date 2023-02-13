//
//  ZendriveMockHandsFreePhoneCallEventBuilder.h
//  ZendriveMockDrive
//
//  Created by Madalin Sava on 20.06.2022.
//  Copyright © 2022 Sudeep Kumar. All rights reserved.
//

#import "ZendriveMockRangeEventBuilder.h"

/**
 * An event builder for [hands free phone call](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Enums/ZendriveEventType.html#/c:@E@ZendriveEventType@ZendriveEventHandsFreePhoneCall) event.
 */
@interface ZendriveMockHandsFreePhoneCallEventBuilder : ZendriveMockRangeEventBuilder

/**
 * Constructs and return a new hands free phone call event builder.
 * @param startTimestamp [start timestamp](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Classes/ZendriveEvent.html#/c:objc(cs)ZendriveEvent(py)startTime) of the event.
 * @param endTimestamp [end timestamp](https://zendrive-root.bitbucket.io/ios/docs/sdk-9.1.0-a1/Classes/ZendriveEvent.html#/c:objc(cs)ZendriveEvent(py)endTime) of the event.
 */
- (id)initWithStartTimestamp:(long long)startTimestamp
                endTimestamp:(long long)endTimestamp;

@end
