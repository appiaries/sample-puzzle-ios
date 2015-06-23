//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABDevice;
@class ABUser;
@class ABTwitterSession;
//@class ABFacebookSession;

/*!
 セッション
 */
@interface ABSession : NSObject
#pragma mark - Properties
/*! @name Properties */
@property (strong, nonatomic, readonly) ABDevice *device;
@property (strong, nonatomic, readonly) ABUser *user;
@property (strong, nonatomic, readonly) NSString *token;
@property (weak, nonatomic, readonly) ABTwitterSession *twitter;
//@property (weak, nonatomic) ABFacebookSession *facebook;

#pragma mark - Initialization
/*! @name Initialization */
+ (instancetype)sharedSession;

#pragma mark - Instance methods
/*! @name Instance methods */
- (void)storeDevice:(ABDevice *)device;
- (void)storeDevice:(ABDevice *)device isPermanently:(BOOL)isPermanently;
- (void)storeUser:(ABUser *)user;
- (void)storeUser:(ABUser *)user isPermanently:(BOOL)isPermanently;
- (void)storeToken:(NSString *)token;
- (void)storeToken:(NSString *)token isPermanently:(BOOL)isPermanently;
- (BOOL)isLoggedIn;
- (BOOL)isRegisteredDevice;
- (void)invalidateDevice;
- (void)invalidateToken;
- (void)invalidateUser;
- (void)invalidateTwitter;
- (void)invalidateAll;

@end