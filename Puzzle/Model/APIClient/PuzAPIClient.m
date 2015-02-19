//
//  PuzAPIClient.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzAPIClient.h"

/** Appiaries datastore file API URL */
static NSString *const kDatastoreFileUrlBase = @"https://api-datastore.appiaries.com/v1/bin";

/** UserDefaults key */
static NSString *const kUserDefaultsKeyAccessToken = @"PUZAccessToken";
static NSString *const kUserDefaultsKeyStoreToken = @"PUZStoreToken";
static NSString *const kUserDefaultsKeyTokenExpireDate = @"PUZTokenExpireDate";
static NSString *const kPuzUserDefaultKeyStoreToken = @"PUZStoreToken";
static NSString *const kPuzUserDefaultKeyUserId = @"PUZUserId";

/** 画像を保存しているcollectionId */
static NSString *const kImageCollectionId = @"Images";


@interface PuzAPIClient ()
@property (nonatomic, readwrite) NSString *accessToken;
@property (nonatomic, readwrite) NSString *storeToken;
@property (nonatomic, readwrite) NSDate *tokenExpireDate;
@property (nonatomic, readwrite) NSString *userId;
@end


@implementation PuzAPIClient

//--------------------------------------------------------------//
#pragma mark -- initial --
//--------------------------------------------------------------//
+ (instancetype)sharedClient
{
    static PuzAPIClient *_sharedClient = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        configuration.HTTPAdditionalHeaders = @{ @"Accept" : @"application/json" };
        _sharedClient = [[PuzAPIClient alloc] initWithSessionConfiguration:configuration];
        //reachability
        [_sharedClient.reachabilityManager startMonitoring];
        //Tokenの呼び出し
        [_sharedClient loadCredential];
    });
    
    //共通処理
    if (_sharedClient != nil) {
    }
    
    return _sharedClient;
}

- (id)init
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

+ (NSString *)getImageFileUrlWithObjectId:(NSString *)objectId
{
    return [NSString stringWithFormat:@"%@/%@/%@/%@/%@/_bin", kDatastoreFileUrlBase, PUZAPISDatastoreId, PUZAPISAppId, kImageCollectionId, objectId];
}

#pragma mark --- private method

- (void)setHeader
{
    if (self.storeToken.length > 0) {
        [self.requestSerializer setValue:self.storeToken forHTTPHeaderField:@"X-APPIARIES-TOKEN"];
    }
    if (self.accessToken.length > 0) {
        [self.requestSerializer setValue:[NSString stringWithFormat:@"Bearer %@",self.accessToken] forHTTPHeaderField:@"Authorization"];
    }
}

- (void)saveCredential
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:self.accessToken forKey:kUserDefaultsKeyAccessToken];
    [userDefaults setObject:self.storeToken forKey:kUserDefaultsKeyStoreToken];
    [userDefaults setObject:self.tokenExpireDate forKey:kUserDefaultsKeyTokenExpireDate];
    [userDefaults synchronize];
}

- (void)loadCredential
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    self.accessToken = [userDefaults objectForKey:kUserDefaultsKeyAccessToken];
    self.storeToken = [userDefaults objectForKey:kUserDefaultsKeyStoreToken];
    self.tokenExpireDate = [userDefaults objectForKey:kUserDefaultsKeyTokenExpireDate];
}

- (void)removeCredential
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults removeObjectForKey:kUserDefaultsKeyAccessToken];
    [userDefaults removeObjectForKey:kUserDefaultsKeyStoreToken];
    [userDefaults removeObjectForKey:kUserDefaultsKeyTokenExpireDate];
    [userDefaults synchronize];
}

- (void)saveLogInInfo:(NSDictionary *)data
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    
    [userDefaults removeObjectForKey:kPuzUserDefaultKeyStoreToken];
    [userDefaults removeObjectForKey:kPuzUserDefaultKeyUserId];
    [userDefaults synchronize];

    [userDefaults setObject:data[@"_token"] forKey:kPuzUserDefaultKeyStoreToken];
    [userDefaults setObject:data[@"user_id"] forKey:kPuzUserDefaultKeyUserId];
    [userDefaults synchronize];
}

- (NSDictionary *)loadLogInInfo
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    self.storeToken = [userDefaults objectForKey:kPuzUserDefaultKeyStoreToken];
    self.userId = [userDefaults objectForKey:kPuzUserDefaultKeyUserId];
    
    NSMutableDictionary *data = [[NSMutableDictionary alloc] init];
    
    [data setValue:self.storeToken forKey:@"_token"];
    [data setValue:self.userId forKey:@"user_id"];

    return data;
}

@end
