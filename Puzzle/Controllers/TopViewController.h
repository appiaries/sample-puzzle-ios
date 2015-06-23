//
//  TopViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TopViewController : UIViewController
#pragma mark - Properties
@property (strong, nonatomic) IBOutlet UIButton *btnBack;
@property (strong, nonatomic) IBOutlet UIButton *btnNext;
@property (strong, nonatomic) IBOutlet UILabel *lbStageLevel;
@property (strong, nonatomic) IBOutlet UIButton *btnStart;
@property (strong, nonatomic) IBOutlet UIButton *btnRanking;
@property (weak, nonatomic) IBOutlet UIView *viewContainer;
@property (weak, nonatomic) NSArray *stages;

#pragma mark - Actions
- (IBAction)btnBackStageTapped:(id)btnBack;
- (IBAction)btnNextStageTapped:(id)btnNext;
- (IBAction)btnStartTapped:(id)btnStart;
- (IBAction)btnRankingTapped:(id)btnRanking;

@end
