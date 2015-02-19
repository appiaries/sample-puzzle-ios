//
//  PuzInformation.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/19/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzInformation.h"

@implementation PuzInformation

- (id)initWithDict:(NSDictionary *)informationDict
{
    if (self = [super init]) {
        _id      = informationDict[@"_id"];
        _content = informationDict[@"content"];
        _cts     = informationDict[@"_cts"];
        _uts     = informationDict[@"_uts"];
        _cby     = informationDict[@"_cby"];
        _uby     = informationDict[@"_uby"];
    }
    return self;
}

@end
