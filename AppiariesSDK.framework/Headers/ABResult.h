//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABError;

/*!
結果オブジェクト
 */
@interface ABResult : NSObject
#pragma mark - Properties
/*! @name Properties */
@property (strong, nonatomic) id data;
@property (strong, nonatomic) id rawData;
@property (nonatomic) NSInteger code;
@property (nonatomic) NSUInteger total;
@property (nonatomic) NSUInteger start;
@property (nonatomic) NSUInteger end;
@property (nonatomic, getter=hasPrevious) BOOL previous;
@property (nonatomic, getter=hasNext) BOOL next;
@property (strong, nonatomic) NSMutableDictionary *extra;

@end