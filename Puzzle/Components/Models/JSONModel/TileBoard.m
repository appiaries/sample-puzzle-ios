//
//  TileBoard.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "TileBoard.h"

@interface TileBoard ()
#pragma mark - Properties (Private)
@property (strong, nonatomic) NSMutableArray *tiles;
@end


@implementation TileBoard

#pragma mark - Constants
static const NSInteger TileMinSize = 2;
static const NSInteger TileMaxSize = 6;

#pragma mark - Initialization
- (instancetype)init
{
    return nil;
}

- (instancetype)initWithSize:(NSInteger)sizeHorizontal sizeVertical:(NSInteger)sizeVertical
{
    if (!(self = [super init]) || ![self isSizeValid:sizeVertical] || ![self isSizeValid:sizeHorizontal]) return nil;
    
    self.sizeVertical = sizeVertical;
    self.sizeHorizontal = sizeHorizontal;
    
    [self setSizeBoard];
    return self;
}

#pragma mark - Public methods
- (BOOL)isSizeValid:(NSInteger)size
{
    return (size >= TileMinSize && size <= TileMaxSize);
}

- (BOOL)isCoordinateInBound:(CGPoint)coor
{
    return (coor.x > 0 && coor.x <= self.sizeHorizontal && coor.y > 0 && coor.y <= self.sizeVertical);
}

- (NSMutableArray *)tileValuesForSize:(NSInteger)sizeVertical sizeHorizontal:(NSInteger)sizeHorizontal
{
    int value = 1;
    NSMutableArray *tiles = [NSMutableArray arrayWithCapacity:(NSUInteger)sizeVertical];
    for (int i = 0; i < sizeVertical; i++)
    {
        NSMutableArray *values = [NSMutableArray arrayWithCapacity:(NSUInteger)sizeHorizontal];
        for (int j = 0; j < sizeHorizontal; j++)
            values[(NSUInteger)j] = (value != sizeHorizontal * sizeVertical)? @(value++) : @0;
        tiles[(NSUInteger)i] = values;
    }
    
    return tiles;
}

- (void)setSizeBoard
{
    _tiles = [self tileValuesForSize:self.sizeVertical sizeHorizontal:self.sizeHorizontal];
}

- (void)setTileAtCoordinate:(CGPoint)coor with:(NSNumber *)number
{
    if ([self isCoordinateInBound:coor]) {
        self.tiles[(NSUInteger)coor.y-1][(NSUInteger)coor.x-1] = number;
    }
}

- (NSNumber *)tileAtCoordinate:(CGPoint)coor
{
    if ([self isCoordinateInBound:coor]) {
        return self.tiles[(NSUInteger)coor.y-1][(NSUInteger)coor.x-1];
    }
    return nil;
}

- (BOOL)canMoveTile:(CGPoint)coor
{
    return ([[self tileAtCoordinate:CGPointMake(coor.x, coor.y-1)] isEqualToNumber:@0] || // upper neighbor
            [[self tileAtCoordinate:CGPointMake(coor.x+1, coor.y)] isEqualToNumber:@0] || // right neighbor
            [[self tileAtCoordinate:CGPointMake(coor.x, coor.y+1)] isEqualToNumber:@0] || // lower neighbor
            [[self tileAtCoordinate:CGPointMake(coor.x-1, coor.y)] isEqualToNumber:@0]);  // left neighbor
}

- (CGPoint)shouldMove:(BOOL)move tileAtCoordinate:(CGPoint)coor
{
    if (![self canMoveTile:coor]) return CGPointZero;
    
    CGPoint lowerNeighbor = CGPointMake(coor.x, coor.y+1);
    CGPoint rightNeighbor = CGPointMake(coor.x+1, coor.y);
    CGPoint upperNeighbor = CGPointMake(coor.x, coor.y-1);
    CGPoint leftNeighbor  = CGPointMake(coor.x-1, coor.y);
    
    CGPoint neighbor;
    if ([[self tileAtCoordinate:lowerNeighbor] isEqualToNumber:@0]) {
        neighbor = lowerNeighbor;
    } else if ([[self tileAtCoordinate:rightNeighbor] isEqualToNumber:@0]) {
        neighbor = rightNeighbor;
    } else if ([[self tileAtCoordinate:upperNeighbor] isEqualToNumber:@0]) {
        neighbor = upperNeighbor;
    } else if ([[self tileAtCoordinate:leftNeighbor] isEqualToNumber:@0]) {
        neighbor = leftNeighbor;
    } else {
        neighbor = CGPointZero;
    }
    
    if (move) {
        NSNumber *number = [self tileAtCoordinate:coor];
        [self setTileAtCoordinate:coor with:[self tileAtCoordinate:neighbor]];
        [self setTileAtCoordinate:neighbor with:number];
    }
    
    return neighbor;
}

- (void)shuffle:(NSInteger)times
{
    for (int t = 0; t < times; t++) {
        NSMutableArray *validMoves = [NSMutableArray array];
        
        for (int j = 1; j <= self.sizeVertical; j++) {
            for (int i = 1; i <= self.sizeHorizontal; i++) {
                CGPoint p = CGPointMake(i, j);
                if ([self canMoveTile:p]) {
                    [validMoves addObject:[NSValue valueWithCGPoint:p]];
                }
            }
        }
        
        NSValue *v = validMoves[arc4random_uniform((int)[validMoves count])];
        CGPoint p = [v CGPointValue];
        [self shouldMove:YES tileAtCoordinate:p];
    }
}

- (BOOL)isAllTilesCorrect
{
    int i = 1;
    BOOL correct = YES;
    
    for (NSArray *values in self.tiles) {
        for (NSNumber *value in values) {
            if ([value integerValue] != i) {
                correct = NO;
                break;
            } else {
                i = (i < (self.sizeVertical * self.sizeHorizontal) - 1)? i+1 : 0;
            }
        }
    }
    return correct;
}

@end

