//
//  Zendrive+Private.h
//  ZendriveSDK
//
//  Created by Sudeep on 29/12/19.
//  Copyright © 2019 Zendrive Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZendriveSDK/Zendrive.h>

typedef NS_ENUM(NSUInteger, ZDRLogLevel) {
    ZDRLogLevelError = 0,
    ZDRLogLevelWarn = 1,
    ZDRLogLevelInfo = 2,
    ZDRLogLevelDebug = 3,
    ZDRLogLevelVerbose = 4
};

@interface Zendrive (Private)

+ (void)log:(NSString *)message
      level:(ZDRLogLevel)level
  className:(NSString *)className
 methodName:(NSString *)methodName;

+ (NSArray *)getGpsPointsFromTimestamp:(long long)timestampStart
                           toTimestamp:(long long)timestampEnd;

+ (NSDictionary *)getTripSummaryDictFor:(long long)timestampStart;
+ (ZendriveAnalyzedDriveInfo *)getAnalyzedDriveInfoFor:(NSDictionary *)tripSummaryDict;

+ (BOOL)setTripParameterForKey:(NSString *)key
                     withValue:(id)value
                         error:(NSError **)perror;

@end
