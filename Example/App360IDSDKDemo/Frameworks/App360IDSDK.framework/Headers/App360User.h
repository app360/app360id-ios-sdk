//
//  App360User.h
//  App360IDSDK
//
//  Created by Tuan Tran Manh on 4/7/15.
//  Copyright (c) 2015 Mwork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "App360Constants.h"

@interface App360UserSocialInfo : NSObject

@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *firstname;
@property (nonatomic, strong) NSString *lastname;
@property (nonatomic, strong) NSString *fullName;
@property (nonatomic, strong) NSString *gender;
@property (nonatomic, strong) NSString *socialId;
@property (nonatomic, strong) NSString *locale;
@property (nonatomic, strong) NSString *link;
@property (nonatomic, assign) NSInteger timeZone;
@property (nonatomic, strong) NSString *updateTime;
@property (nonatomic, assign) BOOL verified;

- (instancetype)initWithJSON:(NSDictionary *)JSON;

@end

@interface App360User : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *fullName;
@property (nonatomic, strong) NSString *lastLogin;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *profilePicture;
@property (nonatomic, strong) NSString *facebookId;
@property (nonatomic, strong) NSString *googleId;
@property (nonatomic, strong) App360UserSocialInfo *info;

@property (nonatomic, assign) NSInteger loginCount;

@end
