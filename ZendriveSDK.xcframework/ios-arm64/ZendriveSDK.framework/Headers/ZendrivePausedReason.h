//
//  ZendrivePausedReason.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 09/03/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifndef ZendrivePausedReason_h
#define ZendrivePausedReason_h

typedef NS_ENUM(int, ZendrivePausedReasonEnum) {
    ZendrivePausedReasonUser,
    ZendrivePausedReasonBusinessHours,
    ZendrivePausedReasonNotPaused
};

@interface ZendrivePausedReason : NSObject

@property (nonatomic, assign) ZendrivePausedReasonEnum pausedReason;

-(id _Nonnull)initWithZDRZDRPauseTrackingReason:(NSInteger)pausedReason;

@end

#endif /* ZendrivePausedReason_h */
