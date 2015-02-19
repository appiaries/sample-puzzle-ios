//
//  TileBoardView.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TileBoardView;

@protocol TileBoardViewDelegate <NSObject>
@optional
- (void)tileBoardViewDidFinished:(TileBoardView *)tileBoardView;
- (void)tileBoardView:(TileBoardView *)tileBoardView tileDidMove:(CGPoint)position;
@end


@interface TileBoardView : UIView

@property (weak, nonatomic) IBOutlet id<TileBoardViewDelegate> delegate;

- (void)playWithImage:(UIImage *)image sizeHorizontal:(NSInteger)sizeHorizontal sizeVertical:(NSInteger)sizeVertical;
- (void)shuffleTimes:(NSInteger)times;
- (void)finishDrawTiles;

@end
