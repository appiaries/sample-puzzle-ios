//
//  PUZAppInfoManager.m
//  Puzzle
//
//  Created by Appiaries Corporation on 10/16/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzPlayerManager.h"
#import "PuzAPIClient.h"
#import "PuzPlayers.h"
#import <AppiariesSDK/AppiariesSDK.h>


@interface PuzPlayerManager ()
@property (nonatomic, readwrite) PuzPlayers *playerInfo;
@end

@implementation PuzPlayerManager

APISSession *apisSession;

+ (PuzPlayerManager *)sharedManager
{
    static PuzPlayerManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[PuzPlayerManager alloc] initSharedInstance];
    });
    return sharedInstance;
}

- (id)initSharedInstance
{
    self = [super init];
    if (self) {
        // 初期化処理
        self.playerInfo = [[PuzPlayers alloc] init];
    }
    return self;
}

- (id)init
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (void)initialize
{
    apisSession = [APISSession sharedSession];
    apisSession.datastoreId = PUZAPISDatastoreId;
    apisSession.applicationId = PUZAPISAppId;
    apisSession.applicationToken = PUZAPISAppToken;
}

#pragma do login
- (void)doLogin:(PuzPlayers *)playerInfo WithCompletion:(void (^)(NSDictionary *))completeBlock failBlock:(void (^)(NSError *))block
{
    // 会員・ログインAPIの実行
    [self initialize];
    
    APISAppUserAPIClient *api = [[APISSession sharedSession] createAppUserAPIClient];
    [api loginWithLoginId:playerInfo.loginId
                 password:playerInfo.password
                 autoLogin:YES
                 success:^(APISResponseObject *response){
                      NSLog(@"会員のログイン成功 [ステータス:%ld, レスポンス:%@, ロケーション:%@]",
                            (long)response.statusCode, response.data, response.location);
                    if (completeBlock) completeBlock(response.data);
                  }
                  failure:^(NSError *error){
                      NSLog(@"会員のログイン失敗 [原因:%@]", [error localizedDescription]);
                    if (block) block(error);
                  }];
}

#pragma regist new account
- (void)createUser:(PuzPlayers *)playerInfo withBlock:(void (^)(NSError *))block
{
    NSMutableDictionary *attribute = [[NSMutableDictionary alloc] init];
    [attribute setValue:playerInfo.nickname forKey:@"nickname"];
    
    [self initialize];
    
    APISAppUserAPIClient *apiClient = [[APISSession sharedSession] createAppUserAPIClient];
    [apiClient createAppUserWithLoginId:playerInfo.loginId
                               password:playerInfo.password
                                  email:playerInfo.email
                             attributes:attribute
                                success:^(APISResponseObject *response){
                                    NSLog(@"会員の登録成功 [ステータス:%ld, レスポンス:%@, ロケーション:%@]",
                                          (long)response.statusCode, response.data, response.location);
                                    block(nil);
                                }
                                failure:^(NSError *error){
                                    NSLog(@"会員の登録失敗 [原因:%@]", [error localizedDescription]);
                                    block(error);
                                }];
}

- (void)getPlayerWithCompletion:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block
{
    APISAppUser *appUser = [APISSession sharedSession].appUser;
    
    [self initialize];
    
    // 会員取得APIの実行
    APISAppUserAPIClient *api = [[APISSession sharedSession] createAppUserAPIClient];
    [api retrieveAppUserWithId:appUser.id
                       success:^(APISResponseObject *response){
                           NSLog(@"会員の取得成功 [ステータス:%ld, レスポンス:%@]",
                                 (long)response.statusCode, response.data);
                           NSDictionary *playerInfo =  response.data;
                           if (completeBlock) completeBlock(playerInfo);
                       }
                       failure:^(NSError *error){
                           NSLog(@"会員の取得失敗 [原因:%@]", [error localizedDescription]);
                           if (block) block(error);
                       }];
}

@end
