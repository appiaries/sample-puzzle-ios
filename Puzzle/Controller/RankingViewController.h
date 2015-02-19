//
//  RankingViewController.h
//  Puzzle
//
//  Created by Tran Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RankingViewController : UIViewController
        <UITextFieldDelegate, UIPickerViewDataSource, UIPickerViewDelegate,
        UITableViewDataSource, UITableViewDelegate, UIAlertViewDelegate>
{
    IBOutlet UITextField *tfStage;

    UIPickerView *pickerStage;
    UIToolbar *toolbarStage;
    NSArray *sortArrRanking;
    NSMutableArray *arrPickerStage;
    NSInteger selectedSegmentAtIndex;
    NSString *userId;
}

@property (strong, nonatomic) IBOutlet UIButton *btnHome;
@property (strong, nonatomic) IBOutlet UISegmentedControl *segmentSwitch;
@property (strong, nonatomic) IBOutlet UITableView *rankingClearTable;

- (IBAction)btnHomeTapped:(id)sender;
- (IBAction)segmentSwitch:(id)sender;

@end
