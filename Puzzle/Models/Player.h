//
//  Player.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Player : ABUser <ABManagedProtocol>
#pragma mark - Properties
@property (strong, nonatomic) NSString *nickname;

#pragma mark - Initialization
+ (id)player;

@end