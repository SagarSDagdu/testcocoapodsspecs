//
//  ZendriveConfiguration.h
//  Zendrive
//
//  Created by Sumant Hanumante on 11/11/14.
//  Copyright (c) 2014 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  Dictates the functioning of Zendrive's drive detection.
 */
typedef NS_ENUM(int, ZendriveDriveDetectionMode) {
    /**
     * `Zendrive` SDK will automatically track drives in background in
     * this mode once the SDK is setup. At the same time, the application can invoke
     * `+[Zendrive startManualDrive:completionHandler]` to explicitly start recording a drive.
     * This is the Default mode.
     */
    ZendriveDriveDetectionModeAutoON = 0,

    /**
     * In this mode auto drive-detection is disabled. All other APIs on `Zendrive`
     * can be invoked independent of this mode. For recording trips in this mode, the
     * application has to explicitly invoke the `+[Zendrive startManualDrive:completionHandler]` method.
     */
    ZendriveDriveDetectionModeAutoOFF = 1,

    /**
     * In this mode drive detection is controlled by period APIs present in
     * `ZendriveInsurance` class. Only `ZendriveInsurance` APIs should be used in
     * this mode to control ZendriveSDK behavior.
     */
    ZendriveDriveDetectionModeInsurance = 2
};

/**
 *  Dictates the region where user's data will reside.
 */
typedef NS_ENUM(int, ZendriveRegion) {
    /**
     * Indicates that the user's data will reside in US region.
     * This is the default region.
     */
    ZendriveRegionUS = 0,


    /**
     * Indicates that the user's data will reside in EU region.
     */
    ZendriveRegionEU = 1,
};

@class ZendriveDriverAttributes;

/**
 *  This class contains parameters required by `Zendrive` during setup.
 */
@interface ZendriveConfiguration : NSObject<NSCopying>

/**
 * Your application key.
 *
 * Pass in the application key for your app. If you don't
 * have one, please create one at https://developers.zendrive.com/signup
 *
 * This field is REQUIRED and should be a valid string.
 * Check `+[Zendrive isValidInputParameter:]` to validate this field. Nil strings are not
 * allowed.
 * Passing invalid string would cause SDK setup to fail.
 */
@property (nonatomic, strong, nonnull) NSString *applicationKey;

/**
 * Unique ID for the current user. This can be any ID used by your app to
 * identify its users. This is the ID which will be used in Zendrive reports.
 * Use `+[Zendrive isValidInputParameter:]` to verify that userId is valid.
 *
 * This field is REQUIRED and should be a valid string.
 * Check `+[Zendrive isValidInputParameter:]` to validate this field. Nil strings are not
 * allowed.
 * Passing invalid string would cause SDK setup to fail.
 */
@property (nonatomic, strong, nonnull) NSString *driverId;

/**
 * Attributes for the current user. These attributes are stored on the server
 * and are provided in Zendrive's APIs. Any existing attributes would be overwritten
 * on the server when a non-nil value for this param is passed. Passing nil is a no-op.
 *
 * Use this param to provide meta-information about the user like name,
 * email, groupId or any custom attributes you wish to provide.
 * Default value is nil.
 */
@property (nonatomic, strong, nullable) ZendriveDriverAttributes *driverAttributes;

/**
 * Use this mode to control the SDK's behaviour for detecting drives
 * automatically. This mode can be changed at a later point using
 * `+[Zendrive setDriveDetectionMode:completionHandler:]` method.
 *
 * Applications which do not want the SDK to continuously track drives in
 * background should set this value to ZendriveDriveDetectionModeAutoOFF. With this, the
 * application needs to call `+[Zendrive startManualDrive:completionHandler:]` method to record drives. In case the application
 * wants to enable auto drive detection only for a fixed duration (like when the driver is
 * on-duty), use method `+[Zendrive setDriveDetectionMode:completionHandler:]`
 * to change the mode to ZendriveDriveDetectionModeAutoON for that period and set it
 * back to ZendriveDriveDetectionModeAutoOFF (once the driver goes off-duty).
 *
 */
@property (nonatomic, assign) ZendriveDriveDetectionMode driveDetectionMode;

/**
 * This field specifies the region where user's data will reside.
 *
 * This field is OPTIONAL.
 * Default value is `ZendriveRegion.ZendriveRegionUS`.
 *
 * Application will not be allowed to change the region post Zendrive SDK setup.
 * To change region application should call `-[Zendrive wipeOut:]` api first.
 */
@property (nonatomic, assign) ZendriveRegion region;

/**
 * Developers can set this property value to @c NO to have complete control on the
 * location permission User Experience.
 *
 * If set to @c YES, ZendriveSDK would trigger location permission dialog on setup if
 * permission is not available.
 * `-[ZendriveDelegateProtocol processLocationApproved]` and `-[ZendriveDelegateProtocol processLocationDenied]`
 * callbacks are not sent to Zendrive delegate if this property is set to @c NO.
 *
 * The default value of this property is @c YES.
 */
@property (nonatomic, assign) BOOL managesLocationPermission __deprecated_msg("This property needs to be set to NO and the application should completely control the user experience related to asking location permission.");

/**
 * Developers can set this property value to @c NO to have complete control on the
 * fitness and activity permission User Experience.
 *
 * If set to @c YES, ZendriveSDK would trigger fitness and activity permission dialog on setup if
 * permission is not available.
 *
 * The default value of this property is @c YES.
 */
@property (nonatomic, assign) BOOL managesActivityPermission __deprecated_msg("This property needs to be set to NO and the application should completely control the user experience related to asking motion and fitness permission.");


/**
 * Developers have to set this property to @c YES if the app implements multiple accident callbacks - [potential callback][potentialId]
 * and the [final callback][finalId]
 *
 * If set to @c NO, the SDK assumes that [potential accident callback][potentialId] is not implemented.
 *
 * The default value of this property is @c NO.
 *
 * [potentialId]: ../Protocols/ZendriveDelegateProtocol.html#/c:objc(pl)ZendriveDelegateProtocol(im)processPotentialAccidentDetected:
 * [finalId]: ../Protocols/ZendriveDelegateProtocol.html#/c:objc(pl)ZendriveDelegateProtocol(im)processAccidentDetected:
 */
@property (nonatomic, assign) BOOL implementsMultipleAccidentCallbacks;

@end
