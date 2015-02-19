//
//  ClearCell.m
//  Puzzle
//
//  Created by Tran Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "ClearCell.h"

@implementation ClearCell

- (void)awakeFromNib
{
    self.lblRank.layer.borderColor = [UIColor blackColor].CGColor;
    self.lblRank.layer.borderWidth = 1.0f;
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];
    // Configure the view for the selected state
}

@end
