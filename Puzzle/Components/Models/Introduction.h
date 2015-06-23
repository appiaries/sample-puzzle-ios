//
//  Introduction.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Introduction : ABDBObject <ABManagedProtocol>
#pragma mark - Properties
@property (strong, nonatomic) NSString *content;
@property (nonatomic) NSInteger order;

#pragma mark - Initialization
+ (id)introduction;

@end