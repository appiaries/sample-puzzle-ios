//
//  RankingViewCell.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "RankingViewCell.h"

@implementation RankingViewCell

- (void)awakeFromNib
{
    _lblRank.layer.borderColor = [UIColor blackColor].CGColor;
    _lblRank.layer.borderWidth = 1.0f;
}

@end
