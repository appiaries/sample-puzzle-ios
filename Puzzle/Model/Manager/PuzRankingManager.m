//
//  PuzComeRanking.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzRankingManager.h"
#import "PuzComeRanking.h"
#import "PuzTimeRanking.h"
#import <AppiariesSDK/AppiariesSDK.h>


@interface PuzRankingManager ()
@property (nonatomic, readwrite) PuzComeRanking *objFirstComeRanking;
@end

@implementation PuzRankingManager

APISSession *apisSession;
NSString static *collectionIdFirstCome = @"FirstComeRanking";
NSString static *collectionIdTimeRanking = @"TimeRanking";

+ (PuzRankingManager *)sharedManager
{
    static PuzRankingManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[PuzRankingManager alloc] initSharedInstance];
    });
    return sharedInstance;
}

- (id)initSharedInstance
{
    self = [super init];
    if (self) {
        // 初期化処理
        self.objFirstComeRanking = [[PuzComeRanking alloc] init];
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

#pragma mark - Method of ComeRanking collection
- (void)getComeRankingListWithCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock
{
    [self initialize];

    APISQueryCondition *query = [[APISQueryCondition alloc] init];
    
    // JSONオブジェクト検索APIの実行
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdFirstCome];
    [api searchJsonObjectsWithQueryCondition:query
                                     success:^(APISResponseObject *response){
                                         NSLog(@"getComeRankingList successfull");
                                         NSMutableArray *objList = [[NSMutableArray alloc] init];
                                         
                                         if ((response.data) && [response.data isKindOfClass:[NSDictionary class]]) {
                                             NSArray *objs = response.data[@"_objs"];
                                             if ([objs isKindOfClass:[NSArray class]] && [objs count] > 0) {
                                                 for (NSDictionary *v in objs) {
                                                     PuzComeRanking *comeRankingObj = [[PuzComeRanking alloc] initWithDict:v];
                                                     [objList addObject:comeRankingObj];
                                                 }
                                             }
                                         }
                                         if (completeBlock) completeBlock(objList);
                                         NSLog(@"getComeRankingListWithCompleteBlock successfull: %li Object", (long)[objList count]);
                                     }
                                     failure:^(NSError *error){
                                         NSLog(@"getComeRankingList failed");
                                         if (failedBlock) failedBlock(error);
                                     }];
}

- (void)getComeRankingListByStageID:(NSString *)stageID withCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock
{
    [self initialize];
    
    APISQueryCondition *query = [[APISQueryCondition alloc] init];
    [query setEqualValue:stageID forKey:@"stage_id"];
    
    // JSONオブジェクト検索APIの実行
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdFirstCome];
    [api searchJsonObjectsWithQueryCondition:query
                                     success:^(APISResponseObject *response){
                                         NSMutableArray *objList = [[NSMutableArray alloc] init];
                                         
                                         if ((response.data) && [response.data isKindOfClass:[NSDictionary class]]) {
                                             NSArray *objs = response.data[@"_objs"];
                                             if ([objs isKindOfClass:[NSArray class]] && [objs count] > 0) {
                                                 for (NSDictionary *v in objs) {
                                                     PuzComeRanking *comeRankingObj = [[PuzComeRanking alloc] initWithDict:v];
                                                     [objList addObject:comeRankingObj];
                                                 }
                                             }
                                         }
                                         if (completeBlock) completeBlock(objList);
                                         NSLog(@"getComeRankingListByStageID successfull: %li Object", (long)[objList count]);
                                     }
                                     failure:^(NSError *error){
                                         NSLog(@"getComeRankingList failed");
                                         if (failedBlock) failedBlock(error);
                                     }];
}

- (void)createComeRankingWithData:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock
{
    [self initialize];
    
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdFirstCome];
    
    [api createJsonObjectWithId:@"" data:data
                        success:^(APISResponseObject *response){
                            NSLog(@"JSONオブジェクトの登録成功 [ステータス:%ld, レスポンス:%@, ロケーション:%@]",
                                  (long)response.statusCode, response.data, response.location);
                            failBlock(nil);
                        }
                        failure:^(NSError *error){
                            NSLog(@"JSONオブジェクトの登録失敗 [原因:%@]", [error localizedDescription]);
                            failBlock(error);
                        }];
}

#pragma mark - Method of TimeRanking collection
- (void)getTimeRankingListWithCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock
{
    [self initialize];
    
    APISQueryCondition *query = [[APISQueryCondition alloc] init];
    
    // JSONオブジェクト検索APIの実行
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdTimeRanking];
    [api searchJsonObjectsWithQueryCondition:query
                                     success:^(APISResponseObject *response){
                                         
                                         NSMutableArray *objList = [[NSMutableArray alloc] init];
                                         
                                         if ((response.data) && [response.data isKindOfClass:[NSDictionary class]]) {
                                             NSArray *objs = response.data[@"_objs"];
                                             if ([objs isKindOfClass:[NSArray class]] && [objs count] > 0) {
                                                 for (NSDictionary *v in objs) {
                                                      PuzTimeRanking *timeRankingObj = [[PuzTimeRanking alloc] initWithDict:v];
                                                     [objList addObject:timeRankingObj];
                                                 }
                                             }
                                         }
                                         if (completeBlock) completeBlock(objList);
                                         NSLog(@"getTimeRankingListWithCompleteBlock successfull: %li Object", (long)[objList count]);
                                     }
                                     failure:^(NSError *error){
                                         NSLog(@"getTimeRankingList error");
                                         failedBlock(error);
                                     }];
}

- (void)getTimeRankingListByStageID:(NSString *)stageID withCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock
{
    [self initialize];
    
    APISQueryCondition *query = [[APISQueryCondition alloc] init];
    [query setEqualValue:stageID forKey:@"stage_id"];
    
    // JSONオブジェクト検索APIの実行
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdTimeRanking];
    [api searchJsonObjectsWithQueryCondition:query
                                     success:^(APISResponseObject *response){
                                         NSLog(@"getTimeRankingList successfull");
                                         
                                         NSMutableArray *objList = [[NSMutableArray alloc] init];
                                         
                                         if ((response.data) && [response.data isKindOfClass:[NSDictionary class]]) {
                                             NSArray *objs = response.data[@"_objs"];
                                             if ([objs isKindOfClass:[NSArray class]] && [objs count] > 0) {
                                                 for (NSDictionary *v in objs) {
                                                     PuzTimeRanking *timeRankingObj = [[PuzTimeRanking alloc] initWithDict:v];
                                                     [objList addObject:timeRankingObj];
                                                 }
                                             }
                                         }
                                         if (completeBlock) completeBlock(objList);
                                         NSLog(@"getTimeRankingListByStageID successfull: %li Object", (long)[objList count]);
                                     }
                                     failure:^(NSError *error){
                                         NSLog(@"getTimeRankingListByStageID error");
                                         failedBlock(error);
                                     }];
}

- (void)createTimeRankingWithData:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock
{
    [self initialize];
    
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdTimeRanking];
    
    [api createJsonObjectWithId:@"" data:data
                        success:^(APISResponseObject *response){
                            NSLog(@"JSONオブジェクトの登録成功 [ステータス:%ld, レスポンス:%@, ロケーション:%@]",
                                  (long)response.statusCode, response.data, response.location);
                            failBlock(nil);
                        }
                        failure:^(NSError *error){
                            NSLog(@"JSONオブジェクトの登録失敗 [原因:%@]", [error localizedDescription]);
                            failBlock(error);
                        }];
}


- (void)updateTimeRankingWithObjectId:(NSString *)objId data:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock
{
    [self initialize];
    
    APISJsonAPIClient *api = [[APISSession sharedSession] createJsonAPIClientWithCollectionId:collectionIdTimeRanking];
    [api updateJsonObjectWithId:objId
                           data:data
                        success:^(APISResponseObject *response){
                            NSLog(@"JSONオブジェクトの更新成功 [ステータス:%ld, レスポンス:%@, ロケーション:%@]",
                                  (long)response.statusCode, response.data, response.location);
                            failBlock(nil);
                        }
                        failure:^(NSError *error){
                            NSLog(@"JSONオブジェクトの更新失敗 [原因:%@]", [error localizedDescription]);
                            failBlock(nil);
                        }];
    
}

#pragma mark - Method of ComeRankingSeq collection

- (void)getRankForFirstComeRanking:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block
{
    NSString *collectionId = @"FirstComeRankingSeq";
    APISSequenceAPIClient *api = [[APISSession sharedSession] createSequenceAPIClientWithCollectionId:collectionId];
    [api publishSequenceNumberWithValue:1
                                success:^(APISResponseObject *response){
                                    NSLog(@"シーケンスの発行成功 [ステータス:%ld, レスポンス:%@]",
                                          (long)response.statusCode, response.data);
                                    completeBlock(response.data);
                                }
                                failure:^(NSError *error){
                                    NSLog(@"シーケンスの発行失敗 [原因:%@]", [error localizedDescription]);
                                }];
}

@end
