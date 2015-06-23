//
//  RankingViewCell.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RankingViewCell : UITableViewCell
#pragma mark - Properties
@property (strong, nonatomic) IBOutlet UILabel *lblRank;
@property (strong, nonatomic) IBOutlet UILabel *lblName;
@property (strong, nonatomic) IBOutlet UILabel *lblTime;

@end
