//
//  PuzImages.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzImages.h"

@implementation PuzImages

- (id)initWithDict:(NSDictionary *)imageDict
{
    if (self = [super init]) {
        _id       = imageDict[@"_id"];
        _mimeType = imageDict[@"mime_type"];
        _fileName = imageDict[@"filename"];
        _data     = imageDict[@"data"];
        _cts      = imageDict[@"_cts"];
        _uts      = imageDict[@"_uts"];
        _cby      = imageDict[@"_cby"];
        _uby      = imageDict[@"_uby"];
    }
    return self;
}

@end
