//
//  OpenIDSDK.h
//  OpenIDSDK
//
//  Created by Tuan Tran Manh on 4/7/15.
//  Copyright (c) 2015 Mwork. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "App360Constants.h"
#import "App360User.h"

//! Project version number for OpenIDSDK.
FOUNDATION_EXPORT double OpenIDSDKVersionNumber;

//! Project version string for OpenIDSDK.
FOUNDATION_EXPORT const unsigned char OpenIDSDKVersionString[];

#define SDK_VERSION     @"2.0.0"

@interface App360IDSDK : NSObject

/**
 *  @abstract Initialize SDK
 *
 *  @param appId        application id
 *  @param appSecret    application secret key
 */
+ (void)initializeWithAppId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 *  Login with specify scope. This method will login silently if there's valid access token. If not, it will display form for user to login if param `shouldDisplayUI` = YES
 *
 *  @param scope            Scope (permission) want to access
 *  @param shouldDisplayUI  Should SDK show form for user login.
 *  @param block            The block to execute
 It should have the following argument signature: `^(App360User *user, NSError *error)`.
 */
+ (void)loginWithScope:(NSString *)scope shouldDisplayUI:(BOOL)shouldDisplayUI fromController:(UIViewController *)controller block:(App360UserResultBlock)block;

/**
 *  Logout current account
 */
+ (void)logout;

/*!
 @abstract Get SDK version
 */
+ (NSString *)getSDKVersion;


@end


