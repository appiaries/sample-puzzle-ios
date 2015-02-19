//
//  PuzComeRanking.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzComeRanking.h"

@implementation PuzComeRanking

- (id)initWithDict:(NSDictionary *)firstComeRankingDict
{
    if (self = [super init]) {
        _id       = firstComeRankingDict[@"_id"];
        _stageId  = firstComeRankingDict[@"stage_id"];
        _userId   = firstComeRankingDict[@"user_id"];
        _nickname = firstComeRankingDict[@"nickname"];
        _rank     = firstComeRankingDict[@"rank"];
        _score    = firstComeRankingDict[@"score"];
        _cts      = firstComeRankingDict[@"_cts"];
        _uts      = firstComeRankingDict[@"_uts"];
        _cby      = firstComeRankingDict[@"_cby"];
        _uby      = firstComeRankingDict[@"_uby"];
    }
    return self;
}

@end
