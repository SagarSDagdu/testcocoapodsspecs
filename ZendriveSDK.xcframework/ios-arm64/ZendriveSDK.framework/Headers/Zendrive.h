//  Zendrive.h
//  Zendrive
//
//  Created by Sumant Hanumante on 1/1/14.
//  Copyright (c) 2014 Zendrive Inc. All rights reserved.

#import <Foundation/Foundation.h>

/**
 * Project version number for ZendriveSDK.
 */
FOUNDATION_EXPORT double ZendriveSDKVersionNumber;
/**
 * Project version string for ZendriveSDK.
*/
FOUNDATION_EXPORT const unsigned char ZendriveSDKVersionString[];

#import "ZendriveConfiguration.h"
#import "ZendriveDriverAttributes.h"
#import "ZendriveDriveStartInfo.h"
#import "ZendriveActiveDriveInfo.h"
#import "ZendriveEstimatedDriveInfo.h"
#import "ZendriveAnalyzedDriveInfo.h"
#import "ZendriveAccidentInfo.h"
#import "ZendriveLocationPoint.h"
#import "ZendriveErrorDomain.h"
#import "ZendriveError.h"
#import "ZendriveLocationPoint.h"
#import "ZendriveEvent.h"
#import "ZendriveDriveScore.h"
#import "ZendriveDriveResumeInfo.h"
#import "ZendriveFeedback.h"
#import "ZendriveDebug.h"
#import "ZendriveInsurance.h"
#import "ZendriveTest.h"
#import "ZendriveSDKConstants.h"
#import "ZendriveStarRating.h"
#import "ZendriveEventRatings.h"
#import "ZendriveState.h"
#import "ZendriveTripWarning.h"
#import "ZendriveVehicleInfo.h"
#import "ZendriveVehicleTagging.h"
#import "ZendriveVehicleTaggingError.h"
#import "ZendriveVehicleTaggingErrorDomain.h"
#import "ZendriveSettings.h"
#import "ZendriveSettingsError.h"
#import "ZendriveBluetoothDevice.h"
#import "ZendriveExtrapolationDetails.h"
#import "ZendriveScannedBeaconInfo.h"
#import "ZendriveShiftTime.h"
#import "ZendriveShiftInterval.h"
#import "ZendriveShiftDetail.h"
#import "ZendriveVehicleTaggingDetails.h"
#import "ZendrivePausedReason.h"
#import "ZendriveSDKHealthReason.h"

/**
 * Identifier used by `Zendrive` SDK for region monitoring geofences
 */
extern NSString * __nonnull const kZendriveGeofenceIdentifier;

@protocol ZendriveDelegateProtocol;

/**
 *
 * Block type used to define blocks called by `Zendrive` public api calls on completion
 *
 * If api call succeeds, success is set to YES and error is nil. If api call fails,
 * success is set to NO and error contains details for why api call failed. Refer to
 * `ZendriveError` for a list of error codes.
 */
typedef void (^ZendriveApiCallHandler)(BOOL success, NSError * __nullable error);

/**
 *  Zendrive Object.
 */
@interface Zendrive : NSObject

/**
 * Initializes the Zendrive library to automatically detect driving and collect
 * data. Client code should call this method before anything else in the Zendrive API.
 *
 * This method requires network connection to validate the applicationKey from the server.
 * Setup fails and returns NO if network is not available.
 *
 * This method returns NO whenever setup fails and sets up the error with the
 * error code, cause and description.
 *
 * Things to Consider:-
 * * To change the `ZendriveConfiguration.region`, you need to call `+wipeOut:` first.
 * * If you are doing multiple setups, i.e calling this API multiple times and the newer setup fails,
 *  then the SDK may continue working according to parameters provided in older setup or it may
 *  get torndown. In all such cases please check `+isSDKSetup` in the completion handler to confirm
 *  if the SDK is setup or not.
 * * If `ZendriveConfiguration.driverId` or `ZendriveConfiguration.applicationKey` is changed while doing
 *  multiple setups, it will be the same as calling teardown followed by calling setup with the new parameters.
 *
 * When data collection needs to be stopped call the teardown method.
 * This might be done for example when the application's user has
 * logged out (and possibly a different user might login later).
 *
 * @param zendriveConfiguration The configuration object used to setup the SDK. This
 *                              object contains your credentials along with
 *                              additional setup parameters that you can use to provide
 *                              meta-information about the user or to tune the sdk
 *                              functionality.
 * @param delegate The delegate object on which Zendrive SDK will issue callbacks for
 *                 handling various events. Can be nil if you do not want to
 *                 register for callbacks.
 *                 The delegate can also be set at a later point using `+setDelegate:`
 *                 method.
 * @param handler This block is called when zendrive setup completes.
 *                The application is expected to use the success and error
 *                params passed to this block to handle failures. The handler
 *                would be invoked on the main thread. Can be nil.
 *
 */
+ (void)setupWithConfiguration:(nonnull ZendriveConfiguration *)zendriveConfiguration
                      delegate:(nullable id<ZendriveDelegateProtocol>)delegate
             completionHandler:(nullable ZendriveApiCallHandler)handler;

/**
 * Set delegate to receive callbacks for various events from Zendrive SDK.
 * See `ZendriveDelegateProtocol` for further details.
 *
 * Calling this if Zendrive is not setup is a no-op.
 * @see `+setupWithConfiguration:delegate:completionHandler:` for further details.
 *
 * @param delegate The delegate object to give callbacks on.
 *
 */
+ (void)setDelegate:(nullable id<ZendriveDelegateProtocol>)delegate;

/**
 * The drive detection mode controls how Zendrive SDK detects drives.
 * See `ZendriveDriveDetectionMode` for further details.
 *
 * Use this method to get the current `ZendriveDriveDetectionMode`.
 */
+ (ZendriveDriveDetectionMode)getDriveDetectionMode;


/**
 * Change the drive detection mode to control how Zendrive SDK detects drives.
 * See `ZendriveDriveDetectionMode` for further details. This will override the mode sent
 * with `ZendriveConfiguration` during setup.
 *
 * Calling this method stops an ongoing auto-detected drive.
 * Calling this method when the SDK is not setup is a no-op.
 *
 * @param driveDetectionMode The new drive detection mode.
 * @param completionHandler A block object to be executed when the task finishes.
 * This block has no return value and two arguments:
 * isSuccess, A boolean that suggests if drive is started successfully
 * error, A valid error of `ZendriveErrorDomain.kZendriveErrorDomain` (`ZendriveError`) is
 * returned in case of a failure.
 * Possible error codes returned: kZendriveErrorNotSetup
 * Refer to ZendriveError for more details on the errors.
 */
+ (void)setDriveDetectionMode:(ZendriveDriveDetectionMode)driveDetectionMode
            completionHandler:(nullable ZendriveApiCallHandler)completionHandler;

/**
 * Stops driving data collection. The application can disable the Zendrive SDK
 * by invoking this method. This method is asynchronous.
 *
 * The teardown method is internally synchronized with
 * `+setupWithConfiguration:delegate:completionHandler:` method, and the enclosing
 * application should avoid synchronizing the two methods independently. Calling this
 * with nil completion handler is same as calling teardown method.
 *
 * @param handler Called when method completes. The handler would be invoked on main
 *        thread. Can be nil.
 */
+ (void)teardownWithCompletionHandler:(void(^ __nullable)(void))handler;

/**
 * Wipe out all the data that zendrive keeps locally on the device.
 *
 * When Zendrive SDK is torn down, trip data that is locally persisted continues to remain persisted.
 * The data will be uploaded when SDK setup is called at a later time.
 * Wipeout should be used when the application wants to remove all traces of Zendrive on the device.
 * Data cannot be recovered after this call.
 * NOTE: This call can only be made when the SDK is not running.
 * Call `+teardownWithCompletionHandler:` to tear down a live SDK before making this call.
 */
+ (BOOL)wipeOut:(NSError * __nullable * __nullable)error;

/**
 * This API allows application to override Zendrive's auto drive detection
 * algorithm.
 *
 * Invoking this method forces the start of a drive. If this API is
 * used then it is application's responsibility to terminate the drive by
 * invoking stopManualDrive:completionHandler: method. If an auto-detected drive is in progress, that drive
 * is stopped and a new drive is started.
 *
 * These methods should be used only by applications which have explicit
 * knowledge of start and end of drives and want to attribute drive data to
 * specific trackingIds.
 *
 * Calling it without having initialized the Zendrive framework
 * (setupWithApplicationId) is a no-op.
 *
 * Calling startManualDrive:completionHandler: with the same trackingId without calling stopManualDrive:completionHandler: in between
 * is a no-op. Calling startManualDrive:completionHandler: with a different trackingId: with implicitly call
 * stopManualDrive:completionHandler: before starting a new drive.
 *
 * This is an asynchronous method, `-[ZendriveDelegateProtocol processStartOfDrive:]`
 * is triggered once this finishes with basic information about the drive
 * `+activeDriveInfo` will return nil until `processStartOfDrive:` is called
 *
 * @param completionHandler A block object to be executed when the task finishes.
 * This block has no return value and two arguments:
 * isSuccess, A boolean that suggests if drive is started successfully
 * error, A valid error of `ZendriveErrorDomain.kZendriveErrorDomain` (`ZendriveError`) is
 * returned in case of a failure.
 * Possible error codes returned: kZendriveErrorNotSetup, kZendriveErrorInvalidTrackingId
 * Refer to ZendriveError for more details on the errors.
 *
 * @see `+stopManualDrive:completionHandler:`
 *
 * You need to call `+stopManualDrive:completionHandler:` to stop drive data collection.
 *
 */
+ (void)startManualDrive:(nullable NSString *)trackingId completionHandler:(nullable ZendriveApiCallHandler)completionHandler;

/**
 * This should be called to indicate the end of a drive started by invoking
 * `+startManualDrive:completionHandler:`
 *
 *
 * This block has no return value and two arguments:
 * the error, A valid error of `ZendriveErrorDomain.kZendriveErrorDomain` (`ZendriveError`) is
 * returned in case of a failure.
 * Possible error codes returned: kZendriveErrorNotSetup, kZendriveErrorInvalidTrackingId,
 * kZendriveErrorInternalFailure. Refer to ZendriveError for more details on the errors.
 * isSuccess, A boolean that suggests if drive is stopped successfully
 *
 * Calling it without having initialized the Zendrive SDK is a no-op.
 *
 * @see `+startManualDrive:completionHandler:`
 *
 */
+ (void)stopManualDrive:(nullable ZendriveApiCallHandler)completionHandler;

/**
 * Start a session in the SDK.
 *
 * Applications which want to record several user's drives as a session may use
 * this call.
 *
 * All drives, either automatically detected or started using `+startManualDrive:completionHandler:`,
 * will be tagged with the sessionId if a session is already in progress. If a drive
 * is already on when this call is made, that drive will not belong to this
 * session.
 *
 * This session id will be made available as a query parameter in the
 * reports and API that Zendrive provides.
 *
 * The application must call `+stopSession` when it wants to end the session.
 *
 * Only one session may be active at a time. Calling startSession when a session is
 * already active with a new sessionId will stop the ongoing session and start a new
 * one.
 *
 * Calling it without having initialized the Zendrive SDK is a no-op.
 *
 * @param sessionId an identifier that identifies this session uniquely. Cannot
 *                  be null or an empty string. Cannot be longer than 64 characters.
 *                  Use `+isValidInputParameter:` to verify that groupId is valid.
 *                  Passing invalid string is a no-op.
 *
 */
+ (void)startSession:(nonnull NSString *)sessionId;

/**
 * Stop currently ongoing session. No-op if no session is ongoing. Trips that
 * start after this call do not belong to the session. Ongoing trips at the time of this
 * call will continue to belong to the session that was just stopped.
 *
 * @see `+startSession:`
 *
 */
+ (void)stopSession;

/**
 * Use this method to check whether the parameter string passed
 * to the SDK is valid.
 *
 * All strings passed as input params to Zendrive SDK cannot contain
 * the following characters-
 * "?", " ", "&", "/", "\", ";", "#", "\n".
 * Non-utf8 characters are not allowed.
 *
 * @param input The string to validate.
 * @return YES if the string is nil or valid, NO otherwise.
 *
 */
+ (BOOL)isValidInputParameter:(nullable NSString *)input;

/**
 * Is the Zendrive SDK already setup?
 *
 * @return YES if Zendrive SDK is already setup. Else NO.
 */
+ (BOOL)isSDKSetup;

/**
 * @return An identifier which can be used to identify this SDK build.
 */
+ (nonnull NSString *)buildVersion;

/**
 * Get info on the currently active drive. If sdk is not setup or if
 * no drive is in progress, nil is returned.
 *
 * @return The currently active drive information.
 */
+ (nullable ZendriveActiveDriveInfo *)activeDriveInfo;

/**
 * Temporary function for retrieving the drive type (internal) for a trip with a given timestamp.
 *  @param timestamp: timestamp of the trip
 *  @return internal drive type enum
 */
+ (ZendriveInternalDriveTypePreview)getInternalDriveTypeForTimestamp:(long long)timestamp;

/**
 * Logs all the critical permission required by the SDK
 *  @param sdkHealthReason indicates the reason for logging SDK Health
 *  @param completionHandler The error pointer where ZendriveSDK will populate the error thrown by the method. mainly when sdk is not setup
 *
 */
+ (void)logSDKHealth:(ZendriveSDKHealthReason)sdkHealthReason error:(void (^ _Nonnull)(NSError * _Nullable))completionHandler;

/**
 * Get the current state of the Zendrive SDK.
 *
 * @param completionHandler A block object to be executed when the task finishes.
 * This block has no return value and a single argument:
 * zendriveState, A `ZendriveState` object that informs about the current state
 * of the sdk. If the SDK is not set up, the zendriveState is nil.
 */
+ (void)getZendriveState:(void (^_Nullable)(ZendriveState* _Nullable zendriveState))completionHandler;

/**
 * @return A boolean indicating whether ZendriveSDK can detect accidents
 * on this devices or not.
 */
+ (BOOL)isAccidentDetectionSupportedByDevice;

/**
 * Returns a NSDictionary with keys as `ZendriveEventType` and values being BOOL which represent
 * if a particular event will be detected by the SDK on this device.
 */
+ (nonnull NSDictionary *)getEventSupportForDevice;

/**
 * Send a debug report of the current driver to Zendrive.
 * The ZendriveSDK will create a background task to ensure the
 * completion of this upload task.
 */
+ (void)uploadAllDebugDataAndLogs;

/**
 * @return A valid `ZendriveSettings` object if the SDK is setup, otherwise nil.
 */
+ (ZendriveSettings *_Nullable)getZendriveSettings;

/**
 *
 * After success of pauseAutoTracking request, automatic trip detection by the SDK will be paused till pausedTillTimestamp which will be provided as part of the parameter.
 *
 * Refer to `ZendriveError` to get details on the errors thrown by this method.
 *
 * @param pausedTillTimestamp - till the pausedTillTimestamp auto tracking will be paused
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *
 * Example:
 *
 * @code
 *NSError *error;
 *long long pausedTillTimestamp = 1634014320000;
 *BOOL success = [Zendrive pauseAutoTracking:pausedTillTimestamp error:&error];
 * @endcode
 *
 * @return YES if pauseAutoTracking is successful, else NO.
 */
+ (BOOL)pauseAutoTracking:(long long)pausedTillTimestamp
            error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 *
 * After success of resumeAutoTracking request, auto tracking of the SDK will be resumed right away.
 *
 * Refer to `ZendriveError` to get details on the errors thrown by this method.
 *
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *
 * Example:
 *
 * @code
 *NSError *error;
 *BOOL success = [Zendrive resumeAutoTracking:&error];
 * @endcode
 *
 * @return YES if resumeAutoTracking is successful, else NO.
 */
+ (BOOL)resumeAutoTracking:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 *
 * After success of isAutoTrackingPaused request, it will return the current status of SDK's auto tracking.
 *
 * Refer to `ZendriveError` to get details on the errors thrown by this method.
 *
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *
 * Example:
 *
 * @code
 * NSError *error;
 * BOOL success = [[Zendrive isAutoTrackingPaused:&error] boolValue];
 * @endcode
 *
 * @return NSNumber instance with boolValue:
 *                      - true if auto tracking is paused.
 *                      - false if auto tracking is resumed.
 * @return nil if SDK throws any error
 */
+ (nullable NSNumber *)isAutoTrackingPaused:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 *
 * Returns the reason for the SDK being paused.
 *
 * Refer to `ZendriveError` to get details on the errors thrown by this method.
 *
 * @param error The error pointer where ZendriveSDK will populate the error thrown by the method.
 *  throws ZendriveError.
 *
 * Example:
 *
 * @code
 * NSError *error;
 * ZendrivePausedReason *pausedReason = [Zendrive getPausedReason:&error];
 * if (error != nil) {
 *      // handle the error
 * } else {
 *      ZendrivePausedResasonEnum pausedReasonEnum = pausedReason.pausedReason
 * }
 * @endcode
 *
 * @return ZendrivePausedReason which encapsulates ZendrivePausedReasonEnum with one of the following paused reasons:
 *                      - ZendrivePausedReasonUser : The SDK is paused manually by user.
 *                       -ZendrivePausedReasonBusinessHours : The SDK is paused automatically due to business hours.
 *                      - ZendrivePausedReasonNotPaused : The SDK is not paused.
 * @return nil if SDK throws any error
 *
 */
+ (ZendrivePausedReason *_Nullable)getPausedReason:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 *
 * Refreshes the business hours, the SDK makes an API call to the backend to fetch the latest business hours set by the fleet manager..
 *
 * @param completionHandler A block object to be executed when the task finishes.
 * This block has no return value and two arguments:
 * shiftDetails, A nullable ZendriveShiftDetail object which provide the business hours.
 * error, A valid error of `ZendriveErrorDomain.kZendriveErrorDomain` (`ZendriveError`) is
 * returned in case of a failure.
 * Possible error codes returned: kZendriveErrorRefreshBusinessHoursTimeout,kZendriveErrorNotSetup, kZendriveErrorRefreshBusinessHoursNetworkNotAvailable, kZendriveErrorRefreshBusinessHoursNotEnabled error.
 * Refer to ZendriveError for more details on the errors.
 * Example:
 * @code
 * NSError *error;
 * [Zendrive refreshBusinessHours:completionHandler:&error];
 * @endcode
 *
 */
+(void)refreshBusinessHours:(void (^ _Nonnull)(ZendriveShiftDetail * _Nullable businessHours, NSError * _Nullable))completionHandler;

@end

/**
 *  Delegate for `Zendrive`.
 */
@protocol ZendriveDelegateProtocol <NSObject>

@optional
/**
 *
 * Called on delegate in the main thread when `Zendrive` SDK detects a potential
 * start of a drive.
 *
 * @param startInfo Info about drive start. Refer to `ZendriveDriveStartInfo` for
 *                  further details.
 *
 */
- (void)processStartOfDrive:(nonnull ZendriveDriveStartInfo *)startInfo;

/**
 *
 * Called on delegate in the main thread when `Zendrive` SDK resumes a
 * drive after a gap.
 *
 * The gap in drive recording may occur due to an application restart by the OS,
 * application kill and restart by a user, an application crash or other reasons.
 * Drives started by calling `+[Zendrive startManualDrive:completionHandler:]` are always resumed and they
 * will not end until `+[Zendrive stopManualDrive:completionHandler:]` is called.
 *
 * @param resumeInfo Info about drive resume. Refer to `ZendriveDriveResumeInfo` for
 *                  further details.
 *
 */
- (void)processResumeOfDrive:(nonnull ZendriveDriveResumeInfo *)resumeInfo;

/**
 * Called on the delegate in the main thread when `Zendrive` SDK detects a drive
 * to have been completed.
 *
 * It is possible that `Zendrive` SDK might decide at a later time that an
 * ongoing trip was a falsely detected trip. In such scenario `processEndOfDrive:` will be
 * invoked on delegate with `ZendriveDriveInfo`.driveType set to `ZendriveDriveTypeInvalid`.
 *
 * Every trip with `ZendriveDriveInfo`.driveType not set to `ZendriveDriveTypeInvalid`
 * will receive a corresponding `-processAnalysisOfDrive:` callback containing
 * additional info related to this drive.
 *
 * @param estimatedDriveInfo Best estimate info about the drive.
 * Refer to `ZendriveEstimatedDriveInfo` for further details.
 *
 */
- (void)processEndOfDrive:(nonnull ZendriveEstimatedDriveInfo *)estimatedDriveInfo;

/**
 * Called on the delegate in the main thread when `Zendrive` SDK finishes
 * full analysis of all valid drives returned from `-processEndOfDrive:` callback.
 *
 * This will be called for all the `-processEndOfDrive:` callbacks
 * with the value of `ZendriveDriveInfo`.driveType not set to `ZendriveDriveTypeInvalid`.
 *
 * This may contain additional or improved data over the `ZendriveEstimatedDriveInfo`
 * returned from `-processEndOfDrive:`
 *
 * Typically this callback will be fired within a few seconds after `-processEndOfDrive:`
 * callback but in some rare cases this delay can be really large depending on
 * phone network conditions.
 *
 * This callback will be fired in trip occurrence sequence, i.e from oldest trip to
 * the latest trip.
 *
 * @param analyzedDriveInfo Analyzed insights of the drive.
 *
 */
- (void)processAnalysisOfDrive:(nonnull ZendriveAnalyzedDriveInfo *)analyzedDriveInfo;

/**
 * [Disabled by default]
 * This callback is fired on the main thread when a potential accident is detected by the SDK during a drive.
 * This is a preliminary callback of a potential collision. This collision is confirmed or invalidated by
 * `-processAccidentDetected:` callback.
 *
 * To enable contact: support@zendrive.com
 *
 * @param accidentInfo Info about accident.
 */
- (void)processPotentialAccidentDetected:(nonnull ZendriveAccidentInfo *)accidentInfo;

/**
 * This callback is fired on the main thread when an accident is detected by
 * the SDK during a drive. Any ongoing auto-detected/manual drives will be stopped
 * after this point.
 *
 * @param accidentInfo Info about accident.
 *
 */
- (void)processAccidentDetected:(nonnull ZendriveAccidentInfo *)accidentInfo;

/**
 * This callback is fired on main thread when location services are denied for
 * the SDK. After this callback, drive detection is paused until location
 * services are re-enabled for the SDK.
 *
 * The expected behaviour is that the enclosing application shows an
 * appropriate popup prompting the user to allow location services for the app.
 *
 * The callback is triggered once every time location services are denied by the user
 * and can be triggered in background or in foreground, depending on whether the SDK
 * has enough CPU time to execute.
 *
 * This callback is not sent if `ZendriveConfiguration.managesLocationPermission`
 * value was set to NO at setup.
 */
- (void)processLocationDenied __deprecated_msg("Use `-settingsChanged:` callback instead.");

/**
 * This method is called when location permission state is determined
 * for the first time or whenever it changes.
 *
 * This callback is not sent if `ZendriveConfiguration.managesLocationPermission`
 * value was set to NO at setup.
 */
- (void)processLocationApproved __deprecated_msg("Use `-settingsChanged:` callback instead.");

/**
 * This callback is fired if activity and fitness permission is denied for the SDK.
 *
 * This callback is not sent if `ZendriveConfiguration.managesActivityPermission`
 * value was set to NO at setup
 */
- (void)processActivityDenied __deprecated_msg("Use `settingsChanged:` callback instead.");

/**
 * This callback is fired if activity and fitness permission is approved for the SDK.
 *
 * This callback is not sent if `ZendriveConfiguration.managesActivityPermission`
 * value was set to NO at setup
 */
- (void)processActivityApproved __deprecated_msg("Use `-settingsChanged:` callback instead.");


/**
 * This callback gives information about errors in device or application settings that
 * may be affecting Zendrive SDK.
 *
 * This callback is fired on the main thread after SDK setup and whenever
 * location permission or `ZendriveConfiguration.driveDetectionMode` changes,
 * provided the location permission is determined.
 *
 * The recommended flow is to ask for the permissions before SDK is setup
 * because if the location permission is not determined this callback will not be
 * fired.
 *
 * If you receive this callback in the foreground you can show the errors using  any UI
 * constructs like alert controllers, if this callback is received in the background you can
 * use a notification. If you want to add actions to the notification then please don't
 * rely on errors received at the time of notification as they might have changed by
 * the time the user clicks on the notification. Instead use `+[Zendrive getZendriveSettings]`
 * to get the latest errors and show appropriate message to the user.
 *
 * @param settings A valid `ZendriveSettings` object that contains
 * information about errors affecting the Zendrive SDK.
 */
- (void)settingsChanged:(ZendriveSettings *_Nonnull)settings;

/**
 * This callback is fired when the SDK detects a change in the business hours set by the fleet manager and the current
 * business hours applied on the SDK.
 * NOTE: to fetch the business hours instantly use `Zendrive:refreshBusinessHours:completionHandler`
 * @param businessHours A valid `ZendriveShiftDetail` object that contains the new business hours.
 */
-(void)businessHoursChanged:(ZendriveShiftDetail *_Nonnull)businessHours;

@end
