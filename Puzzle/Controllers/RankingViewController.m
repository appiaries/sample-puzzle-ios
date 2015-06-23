//
//  RankingViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "RankingViewController.h"
#import "RankingViewCell.h"
#import "FirstComeRanking.h"
#import "TimeRanking.h"
#import "Stage.h"
#import "Constants.h"

@implementation RankingViewController
{
    UIPickerView *_stagePickerView;
    UIToolbar *_toolbarStage;
    NSArray *_stages;
    NSArray *_rankingList;
    NSString *_kindOfRanking;
}

#pragma mark - Constants
CGFloat animatedDistance;

static const CGFloat KEYBOARD_ANIMATION_DURATION = 0.3;
static const CGFloat MINIMUM_SCROLL_FRACTION     = 0.2;
static const CGFloat MAXIMUM_SCROLL_FRACTION     = 0.8;
static const CGFloat PORTRAIT_KEYBOARD_HEIGHT    = 216;
static const CGFloat LANDSCAPE_KEYBOARD_HEIGHT   = 162;


#pragma mark - Initialization
- (id)initWithCoder:(NSCoder *)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        _kindOfRanking = kRankingKindTimeRanking;
    }
    return self;
}

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];

    //----------------------------------------
    // Find all stages
    //----------------------------------------
    ABQuery *query = [[Stage query] orderBy:@"order" direction:ABSortASC];
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
        if (err == nil) {
            _stages = ret.data;

            [self initPickerStage];

            Stage *stage = _stages[0];
            _tfStage.text = stage.name;

            [SVProgressHUD dismiss];

            [self reloadData];
        } else {
            [SVProgressHUD showErrorWithStatus:err.description];
        }
    }];
}

#pragma mark - Actions
- (IBAction)btnHomeTapped:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:kBackToResultNotification object:self];
}

- (IBAction)segmentSwitch:(id)sender
{
    UISegmentedControl *segmentedControl = (UISegmentedControl *)sender;
    if (segmentedControl.selectedSegmentIndex == 0) {
        _kindOfRanking = kRankingKindTimeRanking;
        
        NSInteger selectedIndex = [_stagePickerView selectedRowInComponent:0];
        Stage *stage = _stages[(NSUInteger) selectedIndex];

        //----------------------------------------
        // Find all time ranking
        //----------------------------------------
        ABQuery *query = [[[TimeRanking query] where:@"stage_id" equalsTo:stage.ID] orderBy:@"score" direction:ABSortASC];
        [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
            if (err == nil) {
                _rankingList = ret.data;

                // Set title segment
                [_segmentSwitch setTitle:[NSString stringWithFormat:@"時間 (全%li人中)", (long)[_rankingList count]] forSegmentAtIndex:0];
                [_segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
                [self.rankingClearTable reloadData];

                [SVProgressHUD dismiss];
            } else {
                [SVProgressHUD showErrorWithStatus:err.description];
            }
        }];

    } else {
        _kindOfRanking = kRankingKindFirstComeRanking;
        
        NSInteger selectedIndex = [_stagePickerView selectedRowInComponent:0];
        Stage *stage = _stages[(NSUInteger) selectedIndex];

        //----------------------------------------
        // Find all first come ranking
        //----------------------------------------
        ABQuery *query = [[[FirstComeRanking query] where:@"stage_id" equalsTo:stage.ID] orderBy:@"_cts" direction:ABSortASC];
        [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
            if (err == nil) {
                _rankingList = ret.data;

                // Set title segment
                [_segmentSwitch setTitle:@"時間" forSegmentAtIndex:0];
                [_segmentSwitch setTitle:[NSString stringWithFormat:@"先着 (全%li人中)", (long)[_rankingList count]] forSegmentAtIndex:1];
                [self.rankingClearTable reloadData];

                [SVProgressHUD dismiss];
            } else {
                [SVProgressHUD showErrorWithStatus:err.description];
            }
        }];
    }
}

#pragma mark - UITableView data sources
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [_rankingList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    RankingViewCell *cell = (RankingViewCell *)[tableView dequeueReusableCellWithIdentifier:@"RankingViewCell"];
    if ([_kindOfRanking isEqualToString:@"timeRanking"]) {
        TimeRanking *objRanking = (_rankingList)[(NSUInteger)indexPath.row];
        cell.lblRank.text = [NSString stringWithFormat:@"%ld位", (long)indexPath.row + 1];
        cell.lblName.text = objRanking.nickname;

        if ([objRanking.playerId isEqualToString:baas.session.user.ID]) {
            cell.lblName.font = [UIFont boldSystemFontOfSize:18.0f];
        }
        cell.lblTime.text = [NSString stringWithFormat:@"%d sec", objRanking.score];
    } else {
        FirstComeRanking *objRanking = (_rankingList)[(NSUInteger)indexPath.row];
        cell.lblRank.text = [NSString stringWithFormat:@"%ld位", (long)indexPath.row + 1];
        cell.lblName.text = objRanking.nickname;

        if ([objRanking.playerId isEqualToString:baas.session.user.ID]) {
            cell.lblName.font = [UIFont boldSystemFontOfSize:18.0f];
        }
        cell.lblTime.text = @"";
    }
    return cell;
}

#pragma mark - UIPickerView data sources
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return [_stages count];
}

#pragma mark - UIPickerView delegates
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    Stage *stage = _stages[(NSUInteger)row];
    return stage.name;
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    Stage *stage = _stages[(NSUInteger)row];
    _tfStage.text = stage.name;
    [self reloadData];
}

#pragma mark - UITextField delegates
- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    CGRect textFieldRect = [self.view.window convertRect:textField.bounds fromView:textField];
    CGRect viewRect = [self.view.window convertRect:self.view.bounds fromView:self.view];
    CGFloat midline = (CGFloat) (textFieldRect.origin.y + 0.5 * textFieldRect.size.height);
    CGFloat numerator = midline - viewRect.origin.y - MINIMUM_SCROLL_FRACTION * viewRect.size.height;
    CGFloat denominator = (MAXIMUM_SCROLL_FRACTION - MINIMUM_SCROLL_FRACTION) * viewRect.size.height;
    CGFloat heightFraction = numerator / denominator;

    if (heightFraction < 0.0) {
        heightFraction = 0.0;
    } else if (heightFraction > 1.0) {
        heightFraction = 1.0;
    }

    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown) {
        animatedDistance = (CGFloat) floor(PORTRAIT_KEYBOARD_HEIGHT * heightFraction);
    } else {
        animatedDistance = (CGFloat) floor(LANDSCAPE_KEYBOARD_HEIGHT * heightFraction);
    }

    CGRect viewFrame = self.view.frame;
    viewFrame.origin.y -= animatedDistance;

    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:KEYBOARD_ANIMATION_DURATION];

    [self.view setFrame:viewFrame];

    [UIView commitAnimations];
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    CGRect viewFrame = self.view.frame;
    viewFrame.origin.y += animatedDistance;

    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:KEYBOARD_ANIMATION_DURATION];

    [self.view setFrame:viewFrame];

    [UIView commitAnimations];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

#pragma mark - MISC
- (void)setupView
{
    _rankingClearTable.delegate = self;
    _rankingClearTable.dataSource = self;

    [_segmentSwitch setTitle:@"時間 (全500人中)" forSegmentAtIndex:0];
    [_segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
    _segmentSwitch.selectedSegmentIndex = 0;

    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(pickerDoneClicked)];
    [self.view addGestureRecognizer:tapGesture];
}

- (void)initPickerStage
{
    _stagePickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(200, 43, 320, 480)];
    _stagePickerView.delegate = self;
    _stagePickerView.dataSource = self;
    _stagePickerView.showsSelectionIndicator = YES;
    _tfStage.inputView = _stagePickerView;
    
    //set picker position at index.
    [_stagePickerView selectRow:0 inComponent:0 animated:YES];

    _toolbarStage = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, 320, 56)];
    _toolbarStage.barStyle = UIBarStyleBlackOpaque;
    [_toolbarStage sizeToFit];
    
    NSMutableArray *barItems = [[NSMutableArray alloc] init];
    UIBarButtonItem *flexSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:self action:nil];
    [barItems addObject:flexSpace];

    UIBarButtonItem *doneBtn = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(pickerDoneClicked)];
    [barItems addObject:doneBtn];

    [_toolbarStage setItems:barItems animated:YES];

    _tfStage.inputAccessoryView = _toolbarStage;
}

- (void)reloadData
{
    NSInteger selectedIndex = [_stagePickerView selectedRowInComponent:0];
    Stage *stage = _stages[(NSUInteger) selectedIndex];
    
    if (_segmentSwitch.selectedSegmentIndex == 0) {
        //----------------------------------------
        // Find all time ranking
        //----------------------------------------
        [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
        ABQuery *query = [[[TimeRanking query] where:@"stage_id" equalsTo:stage.ID] orderBy:@"_cts" direction:ABSortASC];
        [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
            if (err == nil) {
                _rankingList = ret.data;
                // Set title segment
                [_segmentSwitch setTitle:[NSString stringWithFormat:@"時間 (全%li人中)", (long) [_rankingList count]] forSegmentAtIndex:0];
                [_segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
                [self.rankingClearTable reloadData];
                [SVProgressHUD dismiss];
            } else {
                [SVProgressHUD showErrorWithStatus:err.description];
            }
        }];

    } else {
        //----------------------------------------
        // Find all first come ranking
        //----------------------------------------
        [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
        ABQuery *query = [[[FirstComeRanking query] where:@"stage_id" equalsTo:stage.ID] orderBy:@"_cts" direction:ABSortASC];
        [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
            if (err == nil) {
                _rankingList = ret.data;
                // Set title segment
                [_segmentSwitch setTitle:@"時間" forSegmentAtIndex:0];
                [_segmentSwitch setTitle:[NSString stringWithFormat:@"先着 (全%li人中)", (long)[_rankingList count]] forSegmentAtIndex:1];
                [self.rankingClearTable reloadData];
                [SVProgressHUD dismiss];
            } else {
                [SVProgressHUD showErrorWithStatus:err.description];
            }
        }];
    }
}

- (void)pickerDoneClicked
{
    [self.view endEditing:YES];
}

@end
