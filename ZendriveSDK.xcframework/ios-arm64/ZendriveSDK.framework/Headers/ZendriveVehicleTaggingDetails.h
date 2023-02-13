//
//  ZendriveVehicleTaggingDetails.h
//  ZendriveSDK
//
//  Created by Atul Manwar on 04/02/22.
//  Copyright © 2022 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The vehicle tagging details of a drive.
 * These details are provided for drives that are tagged by a vehicle. For a given vehicle,
 * both bluetooth car stereo and beacon can be used to tag with the same ``vehicleId`.
 *
 * In case a drive is tagged using both bluetooth car stereo and beacon having different
 * associated vehicleIds, the bluetooth car stereo vehicleId supersedes the beacon vehicleId.
 */
@interface ZendriveVehicleTaggingDetails : NSObject
/**
 * The vehicleId of the tagged vehicle
 */
@property (nonatomic, nonnull) NSString *vehicleId;

/**
 * This flag determines if vehicle is tagged using beacon
 */
@property (nonatomic) BOOL isTaggedByBeacon;

/**
 * This flag determines if vehicle is tagged using bluetooth stereo
 */
@property (nonatomic) BOOL isTaggedByBluetoothStereo;

@end

NS_ASSUME_NONNULL_END
