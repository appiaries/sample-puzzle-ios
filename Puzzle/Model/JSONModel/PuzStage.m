//
//  PuzStage.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzStage.h"
#import "PuzAPIClient.h"

@implementation PuzStage

- (id)initWithDict:(NSDictionary *)stageDict
{
    if (self = [super init]) {
        _id        = stageDict[@"_id"];
        _stageId   = stageDict[@"stage_id"];
        _imageId   = stageDict[@"image_id"];
        _numberOfHrzPieces = stageDict[@"number_of_horizontal_pieces"];
        _numberOfVtlPieces = stageDict[@"number_of_vertical_pieces"];
        _timeLimit = stageDict[@"time_limit"];
        _cts       = stageDict[@"_cts"];
        _uts       = stageDict[@"_uts"];
        _cby       = stageDict[@"_cby"];
        _uby       = stageDict[@"_uby"];
    }
    return self;
}

@end
