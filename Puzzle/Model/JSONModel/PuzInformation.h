//
//  PuzInformation.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/19/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PuzInformation : NSObject

@property (strong, nonatomic) NSString *id;
@property (strong, nonatomic) NSString *content;
@property (strong, nonatomic) NSString *order;
@property (strong, nonatomic) NSString *cby;
@property (strong, nonatomic) NSString *uby;
@property (strong, nonatomic) NSNumber *cts;
@property (strong, nonatomic) NSNumber *uts;

- (id)initWithDict:(NSDictionary *)informationDict;

@end
