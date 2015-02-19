//
//  PuzTimeRanking.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PuzTimeRanking : NSObject

@property (strong, nonatomic) NSString *id;
@property (strong, nonatomic) NSString *stageId;
@property (strong, nonatomic) NSString *userId;
@property (strong, nonatomic) NSString *nickname;
@property (strong, nonatomic) NSNumber *rank;
@property (strong, nonatomic) NSNumber *score;
@property (strong, nonatomic) NSNumber *cts;
@property (strong, nonatomic) NSNumber *uts;
@property (strong, nonatomic) NSString *cby;
@property (strong, nonatomic) NSString *uby;

- (id)initWithDict:(NSDictionary *)timeRankingDict;

@end
