//
//  Stage.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Stage : ABDBObject <ABManagedProtocol>
#pragma mark - Properties
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic, getter=imageId, setter=setImageId:) NSString *image_id;
@property (nonatomic, getter=numberOfHorizontalPieces, setter=setNumberOfHorizontalPieces:) NSInteger number_of_horizontal_pieces;
@property (nonatomic, getter=numberOfVerticalPieces,   setter=setNumberOfVerticalPieces:)   NSInteger number_of_vertical_pieces;
@property (nonatomic, getter=timeLimit, setter=setTimeLimit:) NSInteger time_limit;
@property (nonatomic) NSInteger order;

#pragma mark - Initialization
+ (id)stage;

@end