//
//  RankingViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "RankingViewController.h"
#import "ClearCell.h"
#import "PuzAPIClient.h"
#import "PuzRankingManager.h"
#import "PuzComeRanking.h"
#import "PuzTimeRanking.h"
#import "StageManager.h"
#import "PuzStage.h"
#import "MBProgressHUD.h"

#define TAG_ALERT_DELETE_DATA 999

@implementation RankingViewController
@synthesize btnHome, segmentSwitch;

CGFloat animatedDistance;

static const CGFloat KEYBOARD_ANIMATION_DURATION = 0.3;
static const CGFloat MINIMUM_SCROLL_FRACTION = 0.2;
static const CGFloat MAXIMUM_SCROLL_FRACTION = 0.8;
static const CGFloat PORTRAIT_KEYBOARD_HEIGHT = 216;
static const CGFloat LANDSCAPE_KEYBOARD_HEIGHT = 162;

NSMutableArray *arrRanking;
NSString *rankTyped = @"timeRanking";

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.rankingClearTable setDelegate:self];
    [self.rankingClearTable setDataSource:self];
    
    selectedSegmentAtIndex = 0;
    
    // Do any additional setup after loading the view.
    arrRanking = [[NSMutableArray alloc] init];
    // Get list stage
    [self getListStages];
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self
                                                                          action:@selector(pickerDoneClicked)];
    [self.view addGestureRecognizer:tap];
    
    [segmentSwitch setTitle:@"時間 (全500人中)" forSegmentAtIndex:0];
    [segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
    
    NSDictionary *userInfo = [[PuzAPIClient sharedClient] loadLogInInfo];
    userId = userInfo[@"user_id"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - Action method
- (IBAction)btnHomeTapped:(id)sender
{
    NSLog(@"button home tapped");
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"NotificationBackToResultView" object:self];
}

- (IBAction)segmentSwitch:(id)sender
{
    UISegmentedControl *segmentedControl = (UISegmentedControl *)sender;
    NSInteger selectedSegment = segmentedControl.selectedSegmentIndex;
    
    if (selectedSegment == 0) {
        
        selectedSegmentAtIndex = 0;
        //toggle the correct view to be visible
        NSLog(@"segment 1 selected");
        rankTyped = @"timeRanking";
        
        arrRanking = [[NSMutableArray alloc] init];
        
        NSInteger indexSelected = [pickerStage selectedRowInComponent:0];
        PuzStage *stage = arrPickerStage[(NSUInteger)indexSelected];
        
        [[PuzRankingManager sharedManager] getTimeRankingListByStageID:stage.id withCompleteBlock:^(NSMutableArray *completeBlock){
            
            NSLog(@"ranking list lengh %lu",(unsigned long)[completeBlock count]);
            arrRanking = completeBlock;
            [self sortArrayRanking];
            
            // Set title segment
            [segmentSwitch setTitle:[NSString stringWithFormat:@"時間 (全%li人中)", (long)[arrRanking count]] forSegmentAtIndex:0];
            [segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
            [self.rankingClearTable reloadData];
            
        } failBlock:^(NSError *failBlock){

            NSLog(@"get time ranking fail");

        }];
    } else {
        selectedSegmentAtIndex = 1;
        
        //toggle the correct view to be visible
        NSLog(@"segment 2 selected");
        rankTyped = @"firstClearRanking";
        
        NSInteger indexSelected = [pickerStage selectedRowInComponent:0];
        PuzStage *stage = arrPickerStage[(NSUInteger)indexSelected];
        arrRanking = [[NSMutableArray alloc] init];
        
        [[PuzRankingManager sharedManager] getComeRankingListByStageID:stage.id withCompleteBlock:^(NSMutableArray *completeBlock){
            
            NSLog(@"ranking list lengh %lu",(unsigned long)[completeBlock count]);
            arrRanking = completeBlock;
            [self sortArrayRanking];
            
            // Set title segment
            [segmentSwitch setTitle:@"時間" forSegmentAtIndex:0];
            [segmentSwitch setTitle:[NSString stringWithFormat:@"先着 (全%li人中)", (long)[arrRanking count]] forSegmentAtIndex:1];
            [self.rankingClearTable reloadData];
            
        }failBlock:^(NSError *failBlock){
            
            NSLog(@"get come ranking fail");
            
        }];
        
    }
}

#pragma mark - Private method
- (void)initPickerStage
{
    pickerStage = [[UIPickerView alloc] initWithFrame:CGRectMake(200, 43, 320, 480)];
    pickerStage.delegate = self;
    pickerStage.dataSource = self;
    pickerStage.showsSelectionIndicator = YES;
    tfStage.inputView = pickerStage;
    
    //set picker position at index.
    [pickerStage selectRow:0 inComponent:0 animated:YES];
    
    toolbarStage = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, 320, 56)];
    toolbarStage.barStyle = UIBarStyleBlackOpaque;
    [toolbarStage sizeToFit];
    
    NSMutableArray *barItems = [[NSMutableArray alloc] init];
    UIBarButtonItem *flexSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:self action:nil];
    [barItems addObject:flexSpace];

    UIBarButtonItem *doneBtn = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(pickerDoneClicked)];
    [barItems addObject:doneBtn];

    [toolbarStage setItems:barItems animated:YES];
    
    tfStage.inputAccessoryView = toolbarStage;
}

- (void)sortArrayRanking
{
    NSSortDescriptor *sortDescriptor1 = [[NSSortDescriptor alloc] initWithKey:@"score" ascending:YES];
    NSSortDescriptor *sortDescriptor2 = [[NSSortDescriptor alloc] initWithKey:@"cts" ascending:YES];
    NSArray *sortDescriptors = @[sortDescriptor1, sortDescriptor2];
    sortArrRanking = [arrRanking sortedArrayUsingDescriptors:sortDescriptors];
}

- (void)sortArrayStage
{
    NSSortDescriptor *sortDescriptor1 = [[NSSortDescriptor alloc] initWithKey:@"stageId" ascending:YES];
    NSArray *sortDescriptors = [@[sortDescriptor1] mutableCopy];
    NSArray *array = [NSArray arrayWithArray:arrPickerStage];
    array = [array sortedArrayUsingDescriptors:sortDescriptors];
    arrPickerStage = [NSMutableArray arrayWithArray:array];
}

- (void)getListStages
{
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[StageManager sharedManager] getStagesWithCompletion:^(NSDictionary *stageInfo){
        if (stageInfo != nil) {
            NSArray *stageInfos = stageInfo[@"_objs"];
            arrPickerStage = [[NSMutableArray alloc] init];
            for (int i = 0; i < [stageInfos count]; i++) {
                PuzStage *stage = [[PuzStage alloc] initWithDict:stageInfos[(NSUInteger)i]];
                [arrPickerStage addObject:stage];
            }
            [self sortArrayStage];
            [self initPickerStage];
            PuzStage *stage = arrPickerStage[0];
            tfStage.text = stage.stageId;
            
            [self reloadData];
        }
        [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
    } failedBlock:^(NSError * block){
        [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
        if (block != nil) {
            NSLog(@"get player failed");
        }
    }];
}

- (void)reloadData
{
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    
    arrRanking = [[NSMutableArray alloc] init];
    
    NSInteger indexSelected = [pickerStage selectedRowInComponent:0];
    PuzStage *stage = arrPickerStage[(NSUInteger)indexSelected];
    
    if (selectedSegmentAtIndex == 0) {
        [[PuzRankingManager sharedManager] getTimeRankingListByStageID:stage.id withCompleteBlock:^(NSMutableArray *completeBlock){
            
            NSLog(@"ranking list lengh %lu",(unsigned long)[completeBlock count]);
            arrRanking = completeBlock;
            [self sortArrayRanking];
            
            // Set title segment
            [segmentSwitch setTitle:[NSString stringWithFormat:@"時間 (全%li人中)", (long)[arrRanking count]] forSegmentAtIndex:0];
            [segmentSwitch setTitle:@"先着" forSegmentAtIndex:1];
            [self.rankingClearTable reloadData];
            [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
            
        } failBlock:^(NSError *failBlock){
            
            NSLog(@"get time ranking fail");
        }];
    } else {
        [[PuzRankingManager sharedManager] getComeRankingListByStageID:stage.id withCompleteBlock:^(NSMutableArray *completeBlock){
            
            NSLog(@"ranking list lengh %lu",(unsigned long)[completeBlock count]);
            arrRanking = completeBlock;
            [self sortArrayRanking];
            
            // Set title segment
            [segmentSwitch setTitle:@"時間" forSegmentAtIndex:0];
            [segmentSwitch setTitle:[NSString stringWithFormat:@"先着 (全%li人中)", (long)[arrRanking count]] forSegmentAtIndex:1];
            [self.rankingClearTable reloadData];
            [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
            
        }failBlock:^(NSError *failBlock){
            
            NSLog(@"get come ranking fail");
            
        }];
    }
}

- (void)pickerDoneClicked
{
    NSLog(@"picker done clicked");
    [self.view endEditing:YES];
}

#pragma mark - UITableView Delegate Method
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [arrRanking count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ClearCell *cell = (ClearCell *)[tableView dequeueReusableCellWithIdentifier:@"rankingClearCell"];
    if ([rankTyped isEqualToString:@"timeRanking"]) {
        PuzTimeRanking *objRanking = (sortArrRanking)[(NSUInteger)indexPath.row];
        cell.lblRank.text = [NSString stringWithFormat:@"%ld位", (long)indexPath.row + 1];
        cell.lblName.text = objRanking.nickname;
        
        if ([objRanking.userId isEqualToString:userId]) {
            cell.lblName.font = [UIFont boldSystemFontOfSize:18.0f];
        }
        cell.lblTime.text = [NSString stringWithFormat:@"%@ sec", [objRanking.score stringValue]];
    } else {
        PuzComeRanking *objRanking = (sortArrRanking)[(NSUInteger)indexPath.row];
        cell.lblRank.text = [NSString stringWithFormat:@"%ld位", (long)indexPath.row + 1];
        cell.lblName.text = objRanking.nickname;
        
        if ([objRanking.userId isEqualToString:userId]) {
            cell.lblName.font = [UIFont boldSystemFontOfSize:18.0f];
        }
        cell.lblTime.text = @"";
    }
    return cell;
}

#pragma mark - UIPickerView Delegate Method
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return [arrPickerStage count];
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    PuzStage *stage = arrPickerStage[(NSUInteger)row];
    return stage.stageId;
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    PuzStage *stage = arrPickerStage[(NSUInteger)row];
    tfStage.text = stage.stageId;
    [self reloadData];
}

#pragma mark - UITextField Delegate Method
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
    
    UIInterfaceOrientation orientation =
    [[UIApplication sharedApplication] statusBarOrientation];
    if (orientation == UIInterfaceOrientationPortrait ||
        orientation == UIInterfaceOrientationPortraitUpsideDown) {
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

@end
