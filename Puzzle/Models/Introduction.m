//
//  Introduction.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "Introduction.h"


@implementation Introduction
@dynamic content;
@dynamic order;

#pragma mark - Initialization
+ (id)introduction
{
    return [[self class] object];
}

#pragma mark - ABManagedProtocol implementations
+ (NSString *)collectionID
{
    return @"Introductions";
}

@end