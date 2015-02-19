//
//  StageManager.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/19/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PuzStage;

@interface StageManager : NSObject

@property (readonly, nonatomic) PuzStage *stage;

+ (StageManager *)sharedManager;
- (void)getStagesWithCompletion:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block;

@end
