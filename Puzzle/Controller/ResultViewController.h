//
//  ResultViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PuzPlayers.h"

@interface ResultViewController : UIViewController

@property (strong, nonatomic) NSString *mStageID;
@property (strong, nonatomic) NSString *mStageName;
@property (strong, nonatomic) PuzPlayers *mPuzPlayer;
@property (unsafe_unretained, nonatomic) NSInteger timeScore;
@property (weak, nonatomic) IBOutlet UILabel *lbResultTitle;
@property (strong, nonatomic) IBOutlet UILabel *lblResult;
@property (strong, nonatomic) IBOutlet UILabel *lblClearTime;
@property (strong, nonatomic) IBOutlet UILabel *lblRanking;
@property (strong, nonatomic) IBOutlet UIButton *btnHome;
@property (strong, nonatomic) IBOutlet UIButton *btnRanking;

- (IBAction)btnHomeTapped:(id)sender;
- (IBAction)btnRankingTapped:(id)btnRanking;

@end
