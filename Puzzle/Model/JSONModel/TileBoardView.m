//
//  TileBoardView.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "TileBoardView.h"
#import "TileBoard.h"
#import "UIImage+Resize.h"

typedef enum {
    DirectionUp = 1,
    DirectionRight,
    DirectionDown,
    DirectionLeft
} Direction;


@interface TileBoardView()
@property (nonatomic) CGFloat tileWidth;
@property (nonatomic) CGFloat tileHeight;
@property (nonatomic, getter = isGestureRecognized) BOOL gestureRecognized;
@property (strong, nonatomic) TileBoard *board;
@property (strong, nonatomic) NSMutableArray *tiles;
@property (strong, nonatomic) UIImageView *draggedTile;
@property (nonatomic) NSInteger draggedDirection;
@end


@implementation TileBoardView

#pragma mark - Initialization Methods
- (id)initWithFrame:(CGRect)frame
{
    if (!(self = [super initWithFrame:frame])) return nil;
    return self;
}

- (void)playWithImage:(UIImage *)image sizeHorizontal:(NSInteger)sizeHorizontal sizeVertical:(NSInteger)sizeVertical
{
    // make the board model
    self.board = [[TileBoard alloc] initWithSize:sizeHorizontal sizeVertical:sizeVertical];
    
    // slice the images
    UIImage *resizedImage = [image resizedImageWithSize:self.frame.size];
    self.tileWidth = resizedImage.size.width / sizeHorizontal;
    self.tileHeight = resizedImage.size.height / sizeVertical;
    self.tiles = [self sliceImageToAnArray:resizedImage];
    
    // recognize gestures
    if (!self.isGestureRecognized) [self addGestures];
}

- (NSMutableArray *)sliceImageToAnArray:(UIImage *)image
{
    NSMutableArray *slices = [NSMutableArray array];
    
    for (int i = 0; i < self.board.sizeVertical; i++) {
        for (int j = 0; j < self.board.sizeHorizontal; j++) {
            if (i == self.board.sizeVertical && j == self.board.sizeHorizontal) continue;
            
            CGRect f = CGRectMake(self.tileWidth * j, self.tileHeight * i, self.tileWidth, self.tileHeight);
            UIImageView *tileImageView = [self tileImageViewWithImage:image frame:f];
            [slices addObject:tileImageView];
        }
    }
    return slices;
}

- (UIImageView *)tileImageViewWithImage:(UIImage *)image frame:(CGRect)frame
{
    UIImage *tileImage = [image cropImageFromFrame:frame];
    UIImageView *tileImageView = [[UIImageView alloc] initWithImage:tileImage];
    [tileImageView.layer setBorderColor: [[UIColor whiteColor] CGColor]];
    [tileImageView.layer setBorderWidth: 1.0];
    return tileImageView;
}

- (void)addGestures
{
    // add panning recognizer
    UIPanGestureRecognizer *dragGesture = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(dragging:)];
    [dragGesture setMaximumNumberOfTouches:1];
    [dragGesture setMinimumNumberOfTouches:1];
    [self addGestureRecognizer:dragGesture];
    
    // add tapping recognizer
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapMove:)];
    [tapGesture setNumberOfTapsRequired:1];
    [self addGestureRecognizer:tapGesture];
}

#pragma mark - Public Methods for playing puzzle

- (void)shuffleTimes:(NSInteger)times
{
    [self.board shuffle:times];
    [self drawTiles];
}

- (void)drawTiles
{
    for (UIView *view in self.subviews) {
        [view removeFromSuperview];
    }

    [self traverseTilesWithBlock:^(UIImageView *tileImageView, int i, int j) {
        CGRect frame = CGRectMake(self.tileWidth*(i-1), self.tileHeight*(j-1), self.tileWidth, self.tileHeight);
        tileImageView.frame = frame;
        [self addSubview:tileImageView];
    }];
}

- (void)finishDrawTiles
{
    for (UIView *view in self.subviews) {
        [view removeFromSuperview];
    }

    [self finisTraverseTilesWithBlock:^(UIImageView *tileImageView, int i, int j) {
        CGRect frame = CGRectMake(self.tileWidth*(i-1), self.tileHeight*(j-1), self.tileWidth, self.tileHeight);
        tileImageView.frame = frame;
        [self addSubview:tileImageView];
    }];
}

- (void)finisTraverseTilesWithBlock:(void (^)(UIImageView *tileImageView, int i, int j))block
{
    int index = 0;
    for (int j = 1; j <= self.board.sizeVertical; j++) {
        for (int i = 1; i <= self.board.sizeHorizontal; i++) {
            UIImageView *tileImageView = self.tiles[(NSUInteger)index];
            block(tileImageView, i, j);
            index ++;
        }
    }
}

- (void)orderingTiles
{
    [self traverseTilesWithBlock:^(UIImageView *tileImageView, int i, int j) {
        [self bringSubviewToFront:tileImageView];
    }];
}

- (void)traverseTilesWithBlock:(void (^)(UIImageView *tileImageView, int i, int j))block
{
    for (int j = 1; j <= self.board.sizeVertical; j++) {
        for (int i = 1; i <= self.board.sizeHorizontal; i++) {
            NSNumber *value = [self.board tileAtCoordinate:CGPointMake(i, j)];
            
            if ([value intValue] == 0) continue;
            
            UIImageView *tileImageView = self.tiles[(NSUInteger)[value intValue] - 1];
            block(tileImageView, i, j);
        }
    }
}

#pragma mark - Movers Methods

- (void)moveTileAtPosition:(CGPoint)position
{
    __block UIImageView *tileView = [self tileViewAtPosition:position];
    if (![self.board canMoveTile:position] || !tileView) return;
    
    CGPoint p = [self.board shouldMove:YES tileAtCoordinate:position];
    CGRect newFrame = CGRectMake(self.tileWidth * (p.x - 1), self.tileHeight * (p.y - 1), self.tileWidth, self.tileHeight);
    [UIView animateWithDuration:.1 animations:^{
        tileView.frame = newFrame;
    } completion:^(BOOL finished) {
        if (self.delegate) [self.delegate tileBoardView:self tileDidMove:position];
        [self tileWasMoved];
    }];
    
}

- (UIImageView *)tileViewAtPosition:(CGPoint)position
{
    UIImageView *tileView;
    CGRect checkRect = CGRectMake((position.x - 1) * self.tileWidth + 1, (position.y - 1) * self.tileHeight + 1, 1.0, 1.0);
    for (UIImageView *enumTile in self.tiles) {
        if (CGRectIntersectsRect(enumTile.frame, checkRect)) {
            tileView = enumTile;
            break;
        }
    }
    return tileView;
}

- (void)tileWasMoved
{
    [self orderingTiles];
    
    if ([self.board isAllTilesCorrect]) {
        if (self.delegate) [self.delegate tileBoardViewDidFinished:self];
    }
}

- (CGPoint)coordinateFromPoint:(CGPoint)point
{
    return CGPointMake((int)(point.x / self.tileWidth) + 1, (int)(point.y / self.tileHeight) + 1);
}

#pragma mark - Gesture Methods

- (void)dragging:(UIPanGestureRecognizer *)gestureRecognizer
{
    switch (gestureRecognizer.state) {
        case UIGestureRecognizerStateBegan: {
            CGPoint p = [gestureRecognizer locationInView:self];
            [self assignDraggedTileAtPoint:p];
            break;
        }
        case UIGestureRecognizerStateChanged: {
            if (!self.draggedTile) break;
            
            CGPoint translation = [gestureRecognizer translationInView:self];
            [self movingDraggedTile:translation];
            
            break;
        }
        case UIGestureRecognizerStateEnded: {
            if (!self.draggedTile) break;
            
            [self snapDraggedTile];
            
            break;
        }
        default:
            break;
    }
}

- (void)assignDraggedTileAtPoint:(CGPoint)position
{
    CGPoint coor = [self coordinateFromPoint:position];
    
    if (![self.board canMoveTile:coor]) {
        self.draggedDirection = 0;
        self.draggedTile = nil;
        return;
    }
    
    if ([[self.board tileAtCoordinate:CGPointMake(coor.x, coor.y-1)] isEqualToNumber:@0]) {
        self.draggedDirection = DirectionUp;
    } else if ([[self.board tileAtCoordinate:CGPointMake(coor.x+1, coor.y)] isEqualToNumber:@0]) {
        self.draggedDirection = DirectionRight;
    } else if ([[self.board tileAtCoordinate:CGPointMake(coor.x, coor.y+1)] isEqualToNumber:@0]) {
        self.draggedDirection = DirectionDown;
    } else if ([[self.board tileAtCoordinate:CGPointMake(coor.x-1, coor.y)] isEqualToNumber:@0]) {
        self.draggedDirection = DirectionLeft;
    }
    
    for (UIImageView *tile in self.tiles) {
        if (CGRectContainsPoint(tile.frame, position)) {
            self.draggedTile = tile;
            break;
        }
    }
}

- (void)movingDraggedTile:(CGPoint)translationPoint
{
    CGFloat x = 0.0, y = 0.0;
    CGPoint translation = translationPoint;
    
    switch (self.draggedDirection) {
        case DirectionUp :
            if (translation.y > 0) y = 0.0;
            else if (translation.y < - self.tileHeight) y = -self.tileHeight;
            else y = translation.y;
            break;
        case DirectionRight:
            if (translation.x < 0) x = 0.0;
            else if (translation.x > self.tileWidth) x = self.tileWidth;
            else x = translation.x;
            break;
        case DirectionDown :
            if (translation.y < 0) y = 0.0;
            else if (translation.y > self.tileHeight) y = self.tileHeight;
            else y = translation.y;
            break;
        case DirectionLeft:
            if (translation.x > 0) x = 0.0;
            else if (translation.x < -self.tileWidth) x = -self.tileWidth;
            else x = translation.x;
            break;
        default:
            return;
    }
    [self.draggedTile setTransform:CGAffineTransformMakeTranslation(x, y)];
}

- (void)moveTile:(UIImageView *)tile withDirection:(int)direction fromTilePoint:(CGPoint)tilePoint
{
    int deltaX = 0;
    int deltaY = 0;
    
    switch (direction) {
        case DirectionUp :
            deltaY = -1; break;
        case DirectionRight :
            deltaX = 1; break;
        case DirectionDown :
            deltaY = 1; break;
        case DirectionLeft :
            deltaX = -1; break;
        default: break;
    }
    CGRect newFrame = CGRectMake((tilePoint.x + deltaX - 1) * self.tileWidth,
                                 (tilePoint.y + deltaY - 1) * self.tileHeight,
                                 tile.frame.size.width,
                                 tile.frame.size.height);
    
    [UIView animateWithDuration:.1
                          delay:0.0
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
                         tile.frame = newFrame;
                     }
                     completion:^(BOOL finished){
                         [tile setTransform:CGAffineTransformIdentity];
                         tile.frame = newFrame;
                         
                         if (direction != 0) {
                             [self.board shouldMove:YES tileAtCoordinate:tilePoint];
                             if (self.delegate) [self.delegate tileBoardView:self tileDidMove:tilePoint];
                             [self tileWasMoved];
                         }
                     }];
}


- (void)snapDraggedTile
{
    CGPoint movingTilePoint = CGPointMake(floorf(self.draggedTile.center.x / self.tileWidth) + 1,
                                          floorf(self.draggedTile.center.y / self.tileHeight) + 1);
    
    if (self.draggedTile.transform.ty < 0) {
        if (self.draggedTile.transform.ty < - (self.tileHeight/2)) {
            [self moveTile:self.draggedTile withDirection:DirectionUp fromTilePoint:movingTilePoint];
        } else {
            [self moveTile:self.draggedTile withDirection:0 fromTilePoint:movingTilePoint];
        }
    } else if (self.draggedTile.transform.tx > 0) {
        if (self.draggedTile.transform.tx > (self.tileWidth/2)) {
            [self moveTile:self.draggedTile withDirection:DirectionRight fromTilePoint:movingTilePoint];
        } else {
            [self moveTile:self.draggedTile withDirection:0 fromTilePoint:movingTilePoint];
        }
    } else if (self.draggedTile.transform.ty > 0) {
        if (self.draggedTile.transform.ty > (self.tileHeight/2)) {
            [self moveTile:self.draggedTile withDirection:DirectionDown fromTilePoint:movingTilePoint];
        } else {
            [self moveTile:self.draggedTile withDirection:0 fromTilePoint:movingTilePoint];
        }
    } else if (self.draggedTile.transform.tx < 0) {
        if (self.draggedTile.transform.tx < - (self.tileWidth/2)) {
            [self moveTile:self.draggedTile withDirection:DirectionLeft fromTilePoint:movingTilePoint];
        } else {
            [self moveTile:self.draggedTile withDirection:0 fromTilePoint:movingTilePoint];
        }
    }
}

- (void)tapMove:(UITapGestureRecognizer *)tapRecognizer
{
    CGPoint tapPoint = [tapRecognizer locationInView:self];
    [self moveTileAtPosition:[self coordinateFromPoint:tapPoint]];
}

@end
