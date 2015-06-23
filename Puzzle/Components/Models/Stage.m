//
//  Stage.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "Stage.h"


@implementation Stage
@dynamic name;
@dynamic image_id;
@dynamic number_of_horizontal_pieces;
@dynamic number_of_vertical_pieces;
@dynamic time_limit;
@dynamic order;

#pragma mark - Initialization
+ (id)stage
{
    return [[self class] object];
}

#pragma mark - ABManagedProtocol implementations
+ (NSString *)collectionID
{
    return @"Stages";
}

@end