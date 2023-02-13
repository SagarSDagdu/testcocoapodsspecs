//
//  ZendriveVehicleTagging.h
//  ZendriveSDK
//
//  Created by Abhishek Aggarwal on 15/04/20.
//  Copyright © 2020 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZendriveVehicleInfo.h"
#import "ZendriveDriveInfo.h"
#import "ZendriveBluetoothDevice.h"
#import "ZendriveScannedBeaconInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class manages association and dissociation of vehicles to ZendriveSDK.
 */
@interface ZendriveVehicleTagging : NSObject

/**
 * Associates the vehicle to ZendriveSDK.
 *
 * After successful association of vehicle information, whenever ZendriveSDK will detect
 * a connection to this bluetooth device while the user is driving, it will include this vehicleId
 * in the `ZendriveAnalyzedDriveInfo`.
 *
 * If the user connect to bluetooth of multiple associated vehicles during the drive the latest vehicleId
 * will be used as tag. Maximum of two vehicles can be associated.
 *
 * @note The bluetooth device of the associated vehicle needs to be the audio route for some
 * duration of the drive for tagging to happen.
 *
 * Refer to `ZendriveVehicleTaggingError` to get details on the errors thrown by this method.
 *
 * @param vehicleInfo The `ZendriveVehicleInfo` object to associate.
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *
 * Example:
 *
 * @code
 *NSError *error;
 *ZendriveVehicleInfo *vehicleInfo = [[ZendriveVehicleInfo alloc] initWithVehicleId:@"vehicleId" bluetoothId:@"14:0F:C7:62:F8:9E"];
 *BOOL success = [ZendriveVehicleTagging associateVehicle:vehicleInfo error:&error];
 * @endcode
 *
 * Bluetooth stereos in automobiles are primarily classic Bluetooth devices, which might not be discoverable from your app.
 * When you associate the user's vehicle, ask the user to connect their stereo and play audio.
 * Then, use `+getActiveBluetoothDevice` to determine the active bluetooth connection and get the identifier of the device.
 * Start with this code:
 *
 * @code
 *ZendriveBluetoothDevice *bluetoothDevice = [ZendriveVehicleTagging getActiveBluetoothDevice];
 *if (bluetoothDevice) {
 *    NSError *error;
 *    ZendriveVehicleInfo *vehicleInfo = [[ZendriveVehicleInfo alloc] initWithVehicleId:@"vehicleId" bluetoothId:bluetoothDevice.identifier];
 *    BOOL success = [ZendriveVehicleTagging associateVehicle:vehicleInfo error:&error];
 *}
 * @endcode
 *
 * @return YES if association is successful, else NO.
 */
+ (BOOL)associateVehicle:(ZendriveVehicleInfo * _Nonnull)vehicleInfo
                   error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Dissociates the vehicle from ZendriveSDK.
 *
 * After successful dissociation of the vehicle, ZendriveSDK will stop tagging the trips for this vehicle.
 *
 * @param vehicleId The vehicleId of the vehicle which is to be dissociated.
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *
 * Refer to `ZendriveVehicleTaggingError` to get details on the errors thrown by this method.
 *
 * Example:
 *
 * @code
 *NSError *error;
 *ZendriveVehicleInfo *vehicleInfo = [[ZendriveVehicleInfo alloc] initWithVehicleId:@"vehicleId" bluetoothId:@"14:0F:C7:62:F8:9E"];
 *BOOL success = [ZendriveVehicleTagging dissociateVehicle:vehicleInfo.vehicleId error:&error];
 * @endcode
 *
 * @return YES if dissociation is successful, else NO.
 */
+ (BOOL)dissociateVehicle:(NSString * _Nonnull)vehicleId
                    error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 *  @return The list of associated vehicles if sdk is setup, else nil.
 */
+ (NSArray<ZendriveVehicleInfo *> * _Nullable)getAssociatedVehicles;

/**
 * Returns the active bluetooth device, if there is any, otherwise returns nil.
 *
 * The active bluetooth device is the one through which audio will play.
 * Example: You may be connected to both car's stereo and airpods but only
 * one of them will be active, the one through which audio is playing or
 * will play.
 *
 * @note If the user does not have multiple connected audio devices
 * like headphones, airpods etc, then the connected car's stereo is the
 * active device.
 */
+ (ZendriveBluetoothDevice * _Nullable)getActiveBluetoothDevice;

/**
 * Get all the beacons which are in the device's range using UUID, major, minor.
 *
 * @param uuid The UUID of the beacons that are to be scanned.
 * @param major The major of the beacons that are to be scanned.
 * @param minor The minor of the beacons that are to be scanned.
 * @param completionHandler The completion handler which is to be executed after the completion of beacon scan.
 *
 * Example:
 *
 * @code
 *[ZendriveVehicleTagging getNearbyBeacons:"FD94C06F-8667-46C2-A334-14C6BF8EDEC3" major:100 minor:100 completionHandler: ^{
 *^([ZendriveScannedBeaconInfo] scannedBeaconList, NSError *error) {
 *  // update scanned beacons list in state or redraw UI
 *})
 *}];
 * @endcode
 */
+ (void)getNearbyBeacons:(NSString *)uuid
                   major:(int)major
                   minor:(int)minor
       completionHandler:(void (^)(NSArray<ZendriveScannedBeaconInfo *> *scannedBeacons, NSError * _Nullable))completionHandler;

/**
 * Get all the beacons which are in the device's range using UUID.
 *
 * @param uuid The UUID of the beacons that are to be scanned.
 * @param completionHandler The completion handler which is to be executed after the completion of beacon scan.
 *
 * Example:
 *
 * @code
 *[ZendriveVehicleTagging getNearbyBeacons:"FD94C06F-8667-46C2-A334-14C6BF8EDEC3" completionHandler: ^{
 *^([ZendriveScannedBeaconInfo] scannedBeaconList, NSError *error) {
 *  // update scanned beacons list in state or redraw UI
 *})
 *}];
 * @endcode
 */
+ (void)getNearbyBeacons:(NSString *)uuid
       completionHandler:(void (^)(NSArray<ZendriveScannedBeaconInfo *> *scannedBeacons, NSError * _Nullable))completionHandler;

@end

NS_ASSUME_NONNULL_END
