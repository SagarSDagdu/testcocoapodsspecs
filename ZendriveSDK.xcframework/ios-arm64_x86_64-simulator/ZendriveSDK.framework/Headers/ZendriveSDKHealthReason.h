//
//  ZendriveSDKHealthReason.h
//  ZendriveSDK
//
//  Created by Ashish Agarwal on 08/07/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#ifndef ZendriveSDKHealthReason_h
#define ZendriveSDKHealthReason_h


/**
 *  Dictates the reason for is logging SDK Health
 *  The SDK health will be recorded when there is any update in permission from last recorded SDK health.
 */
typedef NS_ENUM(int, ZendriveSDKHealthReason) {
    /**
     * Indicates the reason  is unknown.
     * This is the default value.
     */
    ZendriveSDKHealthReasonUnknown = 0,

    /**
     * Indicates the SDK health will recorded due to silent push notification
     */
    ZendriveSDKHealthReasonSilentPushNotification = 1,

    /**
     * Indicates the SDK health will recorded due to background processing
     */
    ZendriveSDKHealthReasonBackgroundProcessing = 2,
};


#endif /* ZendriveSDKHealthReason_h */
