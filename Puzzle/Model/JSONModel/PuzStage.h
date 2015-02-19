//
//  PuzStage.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PuzStage : NSObject

@property (strong, nonatomic) NSString *id;
@property (strong, nonatomic) NSString *stageId;
@property (strong, nonatomic) NSString *imageId;
@property (strong, nonatomic) NSNumber *numberOfHrzPieces;
@property (strong, nonatomic) NSNumber *numberOfVtlPieces;
@property (strong, nonatomic) NSNumber *timeLimit;
@property (strong, nonatomic) NSNumber *cts;
@property (strong, nonatomic) NSNumber *uts;
@property (strong, nonatomic) NSString *cby;
@property (strong, nonatomic) NSString *uby;

- (id)initWithDict:(NSDictionary *)stageDict;

@end
