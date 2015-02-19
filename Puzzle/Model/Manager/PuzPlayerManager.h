//
//  PUZAppInfoManager.h
//  Puzzle
//
//  Created by Appiaries Corporation on 10/16/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PuzPlayers;

@interface PuzPlayerManager : NSObject

@property (readonly, nonatomic) PuzPlayers *playerInfo;

+ (PuzPlayerManager *)sharedManager;
- (void)createUser:(PuzPlayers *)playerInfo withBlock:(void (^)(NSError *))block;
- (void)getPlayerWithCompletion:(void(^)(NSDictionary *))completeBlock failedBlock:(void(^)(NSError *))block;
- (void)doLogin:(PuzPlayers *)playerInfo WithCompletion:(void (^)(NSDictionary *))completeBlock failBlock:(void(^)(NSError *))block;

@end
