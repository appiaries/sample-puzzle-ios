//
//  StageManager.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/19/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "StageManager.h"
#import <AppiariesSDK/AppiariesSDK.h>
#import "PuzStage.h"

@interface StageManager ()
@property (nonatomic, readwrite) PuzStage *stage;
@end

@implementation StageManager

APISSession *apisSession;

+ (StageManager *)sharedManager
{
    static StageManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[StageManager alloc] initSharedInstance];
    });
    return sharedInstance;
}

- (id)initSharedInstance
{
    self = [super init];
    if (self) {
        // 初期化処理
        self.stage = [[PuzStage alloc] init];
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

- (void)getStagesWithCompletion:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block
{
    [self initialize];
    
    NSString *collectionId = @"Stages"; // 検索対象のJSONオブジェクトが格納されているコレクションのIDを指定します
    APISQueryCondition *query = [[APISQueryCondition alloc] init];

    // JSONオブジェクト検索APIの実行
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionId];
    [api searchJsonObjectsWithQueryCondition:query
                                     success:^(APISResponseObject *response){
                                         NSLog(@"ステージ情報の取得成功 [ステータス:%ld, レスポンス:%@]",
                                               (long)response.statusCode, response.data);

                                         if (completeBlock) completeBlock(response.data);
                                     }
                                     failure:^(NSError *error){
                                         NSLog(@"ステージ情報の取得失敗 [原因:%@]", [error localizedDescription]);
                                         if (block) block(error);
                                     }];
}


@end
