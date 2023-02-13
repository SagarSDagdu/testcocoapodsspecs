//
//  ZendriveBluetoothDevice.h
//  ZendriveSDK
//
//  Created by Abhishek Aggarwal on 06/11/20.
//  Copyright © 2020 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Wrapper to describe a bluetooth device.
 */
@interface ZendriveBluetoothDevice : NSObject

/**
 * The name of the bluetooth device.
 */
@property(nonatomic, nonnull) NSString *name;

/**
 * The mac address of the bluetooth device.
 */
@property(nonatomic, nonnull) NSString *identifier;

@end

NS_ASSUME_NONNULL_END
