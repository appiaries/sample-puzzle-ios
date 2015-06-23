//
//  ResultViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Player;

@interface ResultViewController : UIViewController
#pragma mark - Properties
@property (strong, nonatomic) NSString *stageId;
@property (strong, nonatomic) NSString *stageName;
@property (unsafe_unretained, nonatomic) NSInteger score;
@property (weak, nonatomic) IBOutlet UILabel *lbResultTitle;
@property (strong, nonatomic) IBOutlet UILabel *lblResult;
@property (strong, nonatomic) IBOutlet UILabel *lblClearTime;
@property (strong, nonatomic) IBOutlet UILabel *lblRanking;
@property (strong, nonatomic) IBOutlet UIButton *btnHome;
@property (strong, nonatomic) IBOutlet UIButton *btnRanking;

#pragma mark - Actions
- (IBAction)btnHomeTapped:(id)sender;
- (IBAction)btnRankingTapped:(id)btnRanking;

@end
