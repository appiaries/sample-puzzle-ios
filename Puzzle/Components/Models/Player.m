//
//  Player.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "Player.h"


@implementation Player
@dynamic nickname;

#pragma mark - Initialization
+ (id)player
{
    return [[self class] user];
}

#pragma mark - ABManagedProtocol implementations
+ (NSString *)collectionID
{
    return @"Player";
}

@end