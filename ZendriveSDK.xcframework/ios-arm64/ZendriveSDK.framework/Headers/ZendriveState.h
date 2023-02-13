//
//  ZendriveState.h
//  ZendriveSDK
//
//  Created by Arpit Panda on 27/02/19.
//  Copyright © 2019 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZendriveConfiguration.h"
#import "ZendriveShiftDetail.h"

/**
 * Represents the current state of the Zendrive SDK.
 */
@interface ZendriveState : NSObject

/**
 * The current configuration of the SDK.
 * Refer to `ZendriveConfiguration` for further details.
 */
@property ZendriveConfiguration *zendriveConfiguration;

/**
 * Is the SDK currently tracking a drive?
 */
@property BOOL isDriveInProgress;

/**
 * Current value of pausedTillTimestamp.
 * pausedTillTimestamp is set when `+[Zendrive pauseAutoTracking:error:]` gets called.
 */
@property long long pausedTillTimestamp;

/**
 * Current value of businessHour.
 * businessHour is set when the SDK detects a change in the business hours set by the fleet manager and the current
 * business hours applied on the SDK.
 */
@property ZendriveShiftDetail *businessHour;

@end

