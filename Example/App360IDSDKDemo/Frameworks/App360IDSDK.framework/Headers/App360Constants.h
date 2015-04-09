//
//  App360Constants.h
//  App360IDSDK
//
//  Created by Tuan Tran Manh on 4/7/15.
//  Copyright (c) 2015 Mwork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class App360User;

///--------------------------------------
/// @name Constants
///--------------------------------------

/*! @abstract scope basic. */
extern NSString *const k360IDScopeBasic;

///--------------------------------------
/// @name Blocks
///--------------------------------------

/*! @abstract User block. Return user if success. If not, return with error object. */
typedef void (^App360UserResultBlock)(App360User *user, NSError *error);

///--------------------------------------
/// @name Errors
///--------------------------------------

/*! @abstract Error domain. */
extern NSString *const k360IDErrorDomain;

/*! @abstract 1: User cancel. */
extern NSInteger const k360IDErrorUserCancel;

/*! @abstract 100: Login error. */
extern NSInteger const k360IDErrorLoginError;

/*! @abstract 101: Can not login without UI. */
extern NSInteger const k360IDErrorCannotLoginWithoutUI;

///--------------------------------------
/// @name Exception
///--------------------------------------

/*! Exception because of missing config file. */
extern NSString *const k360IDExceptionMissingConfigFile;

/*! Exception because of invalid appid. */
extern NSString *const k360IDExceptionInvalidAppId;

/*! Exception because of invalid app secret. */
extern NSString *const k360IDExceptionInvalidAppSecret;