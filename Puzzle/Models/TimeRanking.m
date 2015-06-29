//
//  TimeRanking.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "TimeRanking.h"


@implementation TimeRanking
@dynamic stage_id;
@dynamic player_id;
@dynamic nickname;
@dynamic score;

#pragma mark - Initialization
+ (id)ranking
{
    return [[self class] object];
}

#pragma mark - ABManagedProtocol implementations
+ (NSString *)collectionID
{
    return @"TimeRanking";
}

@end