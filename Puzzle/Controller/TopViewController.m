//
//  TopViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "TopViewController.h"
#import "PuzPlayerManager.h"
#import "PuzPlayers.h"
#import "PuzStage.h"
#import "PlayViewController.h"
#import "PuzAPIClient.h"
#import "MBProgressHUD.h"

@implementation TopViewController
@synthesize lbStageLevel;
@synthesize btnBack;
@synthesize btnNext;
@synthesize viewContainer;
@synthesize userID;
@synthesize listStage;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"アプリタイトル";
    viewContainer.layer.borderColor = [UIColor blackColor].CGColor;
    viewContainer.layer.borderWidth = 1.0f;
    index = 0;

    PuzStage *stageAtIndex = listStage[(NSUInteger)index];
    lbStageLevel.text = stageAtIndex.stageId;
    
    self.btnBack.alpha = 0;
    if ([listStage count] == 1) {
        self.btnNext.alpha = 0;
    } else if ([listStage count] > 0) {
        self.btnNext.alpha = 1;
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    self.title = @"";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action method
- (IBAction)btnBackStageTapped:(id)sender
{
    NSLog(@"button back stage tapped");
    
    if (index > 0) {
        index --;
        PuzStage *stageAtIndex = listStage[(NSUInteger)index];
        lbStageLevel.text = stageAtIndex.stageId;
        
        self.btnNext.alpha = 1;
        if (index == 0) {
            self.btnBack.alpha = 0;
        }
    }
}

- (IBAction)btnNextStageTapped:(id)sender
{
    NSLog(@"button next stage tapped");
    
    if (index < [listStage count] - 1) {
        index ++;
        PuzStage *stageAtIndex = listStage[(NSUInteger)index];
        lbStageLevel.text = stageAtIndex.stageId;
        
        self.btnBack.alpha = 1;
        if (index == [listStage count] - 1) {
            self.btnNext.alpha = 0;
        }
    }
}

- (IBAction)btnStartTapped:(id)btnStart
{
    NSLog(@"btn start tapped");
    
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[PuzPlayerManager sharedManager] getPlayerWithCompletion:^(NSDictionary *playerInfo){
        if (playerInfo != nil) {
            [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
            
            PuzStage *stage = listStage[(NSUInteger)index];
            PuzPlayers *player = [[PuzPlayers alloc] initWithDict:playerInfo];
            PlayViewController *viewController = [self.storyboard instantiateViewControllerWithIdentifier:@"PlayScreen"];
            [viewController setMPuzPlayer:player];
            [viewController setMPuzStage:stage];
            [viewController setMUserID:userID];
            
            self.title = @"戻る";
            [self.navigationController pushViewController:viewController animated:YES];
        }
    } failedBlock:^(NSError *block){
        if (block != nil) {
            NSLog(@"get player failed");
            [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
        }
    }];
}

- (IBAction)btnRankingTapped:(id)btnRanking
{
    NSLog(@"btn Ranking tapped");
    [self performSegueWithIdentifier:@"segueTopToRanking" sender:self];
}

#pragma mark - Private method
- (void)sortArrayStage
{
    NSSortDescriptor *sortDescriptor1 = [[NSSortDescriptor alloc] initWithKey:@"stageId" ascending:YES];
    NSArray *sortDescriptors = [@[sortDescriptor1] mutableCopy];
    NSArray *array = [NSArray arrayWithArray:listStage];
    array = [array sortedArrayUsingDescriptors:sortDescriptors];
    listStage = [NSMutableArray arrayWithArray:array];
}

@end
