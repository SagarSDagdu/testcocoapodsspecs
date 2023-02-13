//
//  ZendriveExtrapolationDetails.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 16/04/21.
//  Copyright © 2021 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZendriveLocationPoint.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Wrapper for extrapolated details for a drive.
 */
@interface ZendriveExtrapolationDetails : NSObject

/**
 *  The additional distance that might be covered before the drive start is detected.
 */
@property (nonatomic, assign) double extrapolatedDistance;

/**
 *  The estimated start location of the active drive.
 */
@property (nonatomic, strong) ZendriveLocationPoint *estimatedStartLocation;

@end

NS_ASSUME_NONNULL_END

/* ZendriveExtrapolationDetails_h */
