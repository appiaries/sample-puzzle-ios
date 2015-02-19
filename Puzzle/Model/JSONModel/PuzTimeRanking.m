//
//  PuzTimeRanking.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzTimeRanking.h"

@implementation PuzTimeRanking

- (id)initWithDict:(NSDictionary *)timeRankingDict
{
    if (self = [super init]) {
        _id       = timeRankingDict[@"_id"];
        _stageId  = timeRankingDict[@"stage_id"];
        _userId   = timeRankingDict[@"user_id"];
        _nickname = timeRankingDict[@"nickname"];
        _rank     = timeRankingDict[@"rank"];
        _score    = timeRankingDict[@"score"];
        _cts      = timeRankingDict[@"_cts"];
        _uts      = timeRankingDict[@"_uts"];
        _cby      = timeRankingDict[@"_cby"];
        _uby      = timeRankingDict[@"_uby"];
    }
    return self;
}

@end
