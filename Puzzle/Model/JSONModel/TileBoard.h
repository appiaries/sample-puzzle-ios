//
//  TileBoard.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TileBoard : NSObject

@property (nonatomic) NSInteger sizeHorizontal;
@property (nonatomic) NSInteger sizeVertical;

- (instancetype)initWithSize:(NSInteger)sizeHorizontal sizeVertical:(NSInteger)sizeVertical;
- (void)setTileAtCoordinate:(CGPoint)coor with:(NSNumber *)number;
- (NSNumber *)tileAtCoordinate:(CGPoint)coor;
- (BOOL)canMoveTile:(CGPoint)coor;
- (CGPoint)shouldMove:(BOOL)move tileAtCoordinate:(CGPoint)coor;
- (BOOL)isAllTilesCorrect;
- (void)shuffle:(NSInteger)times;

@end
