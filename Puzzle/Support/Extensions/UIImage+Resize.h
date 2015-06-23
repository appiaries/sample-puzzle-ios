//
//  TilePuzzle.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Resize)
#pragma mark - Extension methods
- (UIImage *)resizedImageWithSize:(CGSize)size;
- (UIImage *)cropImageFromFrame:(CGRect)frame;
@end
