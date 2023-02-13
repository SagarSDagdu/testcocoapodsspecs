//
//  ZendriveScannedBeaconInfo.h
//  ZendriveSDK
//
//  Created by Pushya Mitra on 30/04/21.
//  Copyright © 2021 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 *  Wrapper for beacons scanned using `+[ZendriveVehicleTagging: getNearbyBeacons:uuid:major:minor:completionHandler:]`.
 */
@interface ZendriveScannedBeaconInfo : NSObject

/**
 * The UUID of the scanned beacon.
 */
@property (nonatomic, nonnull) NSString *uuid;

/**
 * The major of the scanned beacon.
 */
@property (nonatomic, nonnull) NSNumber *major;

/**
 * The minor of the scanned beacon.
 */
@property (nonatomic, nonnull) NSNumber *minor;

/**
 * The RSSI of the scanned beacon.
 */
@property (nonatomic) NSInteger rssi;

/**
 * The proximity of the scanned beacon.
 */
@property (nonatomic) CLProximity proximity;

/**
 * The accuracy of the proximity value, measured in meters from the beacon.
 */
@property (nonatomic) CLLocationAccuracy accuracy;

/**
 * The timestamp representing when the beacon was observed.
 */
@property (nonatomic) long long timestamp;

/**
 * Initialize the beacon with UUID, major, minor, RSSI, proximity and accuracy.
 */
- (instancetype _Nonnull )initWithUUID:(NSString * _Nonnull)uuid
                       major:(NSNumber * _Nonnull)major
                       minor:(NSNumber * _Nonnull)minor
                                  rssi:(NSInteger)rssi
                             proximity:(CLProximity)proximity
                              accuracy:(CLLocationAccuracy)accuracy
                             timestamp:(long long)timestamp;

/**
 * Initialize the beacon with UUID, major, minor.
 */
- (instancetype _Nonnull )initWithUUID:(NSString * _Nonnull)uuid
                                 major:(NSNumber * _Nonnull)major
                                 minor:(NSNumber * _Nonnull)minor;

/**
 * Initialize the beacon with CLBeacon.
 */
- (instancetype _Nonnull )initWithCLBeacon:(CLBeacon * _Nonnull)clBeacon;

/**
 * Returns a dictionary that represents the `ZendriveScannedBeaconInfo` object.
 */
-(NSDictionary *_Nonnull)toDictionary;

@end




