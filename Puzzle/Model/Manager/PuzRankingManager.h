//
//  PuzComeRanking.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PuzComeRanking;

@interface PuzRankingManager : NSObject

@property (readonly, nonatomic) PuzComeRanking *objFirstComeRanking;

+ (PuzRankingManager *)sharedManager;
- (void)getComeRankingListWithCompleteBlock:(void(^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock;
- (void)getTimeRankingListWithCompleteBlock:(void(^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock;
- (void)createTimeRankingWithData:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock;
- (void)createComeRankingWithData:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock;
- (void)updateTimeRankingWithObjectId:(NSString *)objId data:(NSDictionary *)data failBlock:(void(^)(NSError *))failBlock;
- (void)getComeRankingListByStageID:(NSString *)stageID withCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock;
- (void)getTimeRankingListByStageID:(NSString *)stageID withCompleteBlock:(void (^)(NSMutableArray *))completeBlock failBlock:(void (^)(NSError *))failedBlock;
- (void)getRankForFirstComeRanking:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block;

@end
