//
//  Image.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "Image.h"


@implementation Image

#pragma mark - Initialization
+ (id)image
{
    return [[self class] file];
}

#pragma mark - ABManagedProtocol implementations
+ (NSString *)collectionID
{
    return @"Images";
}

@end