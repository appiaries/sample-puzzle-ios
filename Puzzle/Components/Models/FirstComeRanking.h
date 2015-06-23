//
//  FirstComeRanking.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FirstComeRanking : ABDBObject <ABManagedProtocol>
#pragma mark - Properties
@property (strong, nonatomic, getter=stageId,  setter=setStageId:)  NSString *stage_id;
@property (strong, nonatomic, getter=playerId, setter=setPlayerId:) NSString *player_id;
@property (strong, nonatomic) NSString *nickname;
@property (nonatomic) NSInteger rank;
@property (nonatomic) NSInteger score;

#pragma mark - Initialization
+ (id)ranking;

@end