//
//  ZendriveEstimatedDriveInfo.h
//  ZendriveSDK
//
//  Created by Yogesh on 3/16/17.
//  Copyright © 2017 Zendrive Inc. All rights reserved.
//

#import "ZendriveDriveInfo.h"

/**
 * This contains the best estimated results for a drive, this is returned from
 * `-[ZendriveDelegateProtocol processEndOfDrive:]` callback.
 *
 * The data of this type will always be of same or little bad quality than
 * `ZendriveAnalyzedDriveInfo` returned from `-[ZendriveDelegateProtocol processAnalysisOfDrive:]`
 *
 * All drives with driveType not set to `ZendriveDriveTypeInvalid` will get a
 * corresponding `-[ZendriveDelegateProtocol processAnalysisOfDrive:]` callback.
 *
 * Typically `-[ZendriveDelegateProtocol processAnalysisOfDrive:]` will be fired within
 * a few seconds after `-[ZendriveDelegateProtocol processEndOfDrive:]` callback but in some rare cases
 * this delay can be really large depending on phone network conditions.
 */
@interface ZendriveEstimatedDriveInfo : ZendriveDriveInfo

@end
