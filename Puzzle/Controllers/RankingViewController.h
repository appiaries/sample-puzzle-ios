//
//  RankingViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RankingViewController : UIViewController
        <UITextFieldDelegate, UIPickerViewDataSource, UIPickerViewDelegate,
        UITableViewDataSource, UITableViewDelegate, UIAlertViewDelegate>
#pragma mark - Properties
@property (strong, nonatomic) IBOutlet UIButton *btnHome;
@property (strong, nonatomic) IBOutlet UISegmentedControl *segmentSwitch;
@property (strong, nonatomic) IBOutlet UITableView *rankingClearTable;
@property (strong, nonatomic) IBOutlet UITextField *tfStage;

#pragma mark - Actions
- (IBAction)btnHomeTapped:(id)sender;
- (IBAction)segmentSwitch:(id)sender;

@end
