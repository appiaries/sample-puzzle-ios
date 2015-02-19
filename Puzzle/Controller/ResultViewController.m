//
//  ResultViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "ResultViewController.h"
#import "PuzAPIClient.h"
#import "PuzTimeRanking.h"
#import "PuzComeRanking.h"
#import "PuzRankingManager.h"
#import "MBProgressHUD.h"

@implementation ResultViewController
@synthesize btnHome, btnRanking, mStageID, timeScore, mPuzPlayer, mStageName;
@synthesize lblResult, lblClearTime, lblRanking, lbResultTitle;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    lblResult.text = [NSString stringWithFormat:@"%ld秒", (long)timeScore];
    lbResultTitle.text = mStageName;
    
    //To Do update new score to server
    [self updateUserResult];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(backToResultView)
                                                 name:@"NotificationBackToResultView"
                                               object:nil];
}

- (void)dealloc
{
    // If you don't remove yourself as an observer, the Notification Center
    // will continue to try and send notification objects to the deallocated
    // object.
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action method
- (IBAction)btnHomeTapped:(id)sender
{
    NSLog(@"btn Home Tapped");
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"NotificationBackToRootView" object:self];
}

- (IBAction)btnRankingTapped:(id)sender
{
    NSLog(@"btn Ranking Tapped");
    [self performSegueWithIdentifier:@"segueResultToRanking" sender:self];
}

- (void)backToResultView
{
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"NotificationBackToRootView" object:self];
}

#pragma mark - Private method
- (void)LoadData
{
    //get first come ranking info
    [[PuzRankingManager sharedManager] getTimeRankingListByStageID:mStageID withCompleteBlock: ^(NSMutableArray *completeBlock){
        NSLog(@"get come ranking success");
        if ([completeBlock count] > 0) {
            PuzTimeRanking *timeRankingOfUser;
            NSDictionary *userInfo = [[PuzAPIClient sharedClient] loadLogInInfo];
            NSString *userId = userInfo[@"user_id"];
            for (PuzTimeRanking *timeRanking in completeBlock) {
                if ([timeRanking.userId isEqualToString:userId]) {
                    timeRankingOfUser = timeRanking;
                }
            }
            
            NSInteger rank = 1;
            for (PuzTimeRanking *obj in completeBlock) {
                if ([obj.score intValue] < [timeRankingOfUser.score intValue]) {
                    rank ++;
                } else if ([obj.score intValue] == [timeRankingOfUser.score intValue]) {
                    if (obj.cts < timeRankingOfUser.cts) {
                        rank ++;
                    }
                }
            }
            lblClearTime.text = [NSString stringWithFormat:@"%li位/%li", (long)rank, (long)[completeBlock count]];
        }
    } failBlock:^(NSError *failBlock){
        NSLog(@"calculate TimeRanking fail");
    }];

    
    //get first come ranking info
    [[PuzRankingManager sharedManager] getComeRankingListByStageID:mStageID withCompleteBlock: ^(NSMutableArray *completeBlock){
        NSLog(@"get come ranking success");
        if ([completeBlock count] > 0) {
            PuzComeRanking *comeRankingOfUser;
            NSDictionary *userInfo = [[PuzAPIClient sharedClient] loadLogInInfo];
            NSString *userId = userInfo[@"user_id"];
            for (PuzComeRanking *comeRanking in completeBlock) {
                if ([comeRanking.userId isEqualToString:userId]) {
                    comeRankingOfUser = comeRanking;
                }
            }
            
            NSInteger rank = 1;
            for (PuzComeRanking *obj in completeBlock) {
                if ([obj.score intValue] < [comeRankingOfUser.score intValue]) {
                    rank ++;
                } else if ([obj.score intValue] == [comeRankingOfUser.score intValue]) {
                    if (obj.cts < comeRankingOfUser.cts) {
                        rank ++;
                    }
                }
            }
            lblRanking.text = [NSString stringWithFormat:@"%li位/%li", (long)rank, (long)[completeBlock count]];
            [MBProgressHUD hideHUDForView:self.view animated:YES];
        }
    } failBlock:^(NSError *failBlock){
        NSLog(@"calculate ComeRanking fail");
    }];
}

// Create ComeRanking object
- (void)createComeRanking:(NSMutableDictionary *)updateComeRankingObj
{
    [[PuzRankingManager sharedManager] getRankForFirstComeRanking: ^(NSDictionary *completeBlock){
    
        
        updateComeRankingObj[@"rank"] = completeBlock[@"seq"];
        [[PuzRankingManager sharedManager] createComeRankingWithData:updateComeRankingObj failBlock:^(NSError *error){
            if (error != nil) {
                NSLog(@" insert come ranking fail");
            } else {
                //TO DO Load data to result screen
                [self LoadData];
                NSLog(@" insert come ranking success");
            }
        }];
        
    }failedBlock:^(NSError *failBlock){
        NSLog(@"create ComeRanking fail");
    }];
}

// Create TimeRanking object
- (void)createTimeRanking:(NSMutableDictionary *)updateTimeRankingObj
{
    [[PuzRankingManager sharedManager] createTimeRankingWithData:updateTimeRankingObj failBlock:^(NSError *error){
        if (error != nil) {
            NSLog(@" insert time ranking fail");
        } else {
            //TO DO Load data to result screen
            [self LoadData];
            NSLog(@" insert time ranking success");
        }
    }];
}

- (void)updateUserResult
{
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    
    //Dummy data for update object
    NSDictionary *userInfo = [[PuzAPIClient sharedClient] loadLogInInfo];
    NSString *stageId = mStageID;
    NSString *userId = userInfo[@"user_id"];
    NSNumber *newComeScore = @(timeScore);
    NSNumber *newTimeScore = @(timeScore);
    
    NSMutableDictionary *updateComeRankingObj = [[NSMutableDictionary alloc] init];
    
    updateComeRankingObj[@"stage_id"] = stageId;
    updateComeRankingObj[@"user_id"] = userId;
    updateComeRankingObj[@"score"] = newComeScore;
    updateComeRankingObj[@"nickname"] = mPuzPlayer.nickname;
    
    NSMutableDictionary *updateTimeRankingObj = [[NSMutableDictionary alloc] init];
    
    updateTimeRankingObj[@"stage_id"] = stageId;
    updateTimeRankingObj[@"user_id"] = userId;
    updateTimeRankingObj[@"score"] = newComeScore;
    updateTimeRankingObj[@"nickname"] = mPuzPlayer.nickname;
    
    //get come ranking list check and create new or update
    [[PuzRankingManager sharedManager] getComeRankingListWithCompleteBlock:^(NSMutableArray *completeBlock){
        
        BOOL insertFlag = YES;
        
        if ([completeBlock count] > 0) {
            for (PuzComeRanking *obj in completeBlock) {
                if ([obj.stageId isEqualToString:stageId] && [obj.userId isEqualToString:userId]) {
                    insertFlag = NO;
                }
            }
        }
        
        if (insertFlag) {
            [self createComeRanking:updateComeRankingObj];
        }
        // If no insert
        else {
            [self LoadData];
        }
        
    } failBlock:^(NSError *failBlock){
        NSLog(@"get come ranking fail");
    }];
    
    //get time ranking list check and create new or update
    [[PuzRankingManager sharedManager] getTimeRankingListWithCompleteBlock:^(NSMutableArray *completeBlock){

        BOOL insertFlag = YES;
        BOOL updateFlag = NO;
        NSString *objectId = @"";
        
        if ([completeBlock count] > 0) {
            for (PuzTimeRanking *obj in completeBlock) {
                if ([obj.stageId isEqualToString:stageId] && [obj.userId isEqualToString:userId]) {
                    insertFlag = NO;
                    if (newTimeScore.intValue < obj.score.intValue) {
                        updateFlag = YES;
                        objectId = obj.id;
                    }
                }
            }
        }
        
        if (insertFlag) {
            //insert new archive for new player
            [self createTimeRanking:updateTimeRankingObj];
        }
        
        if (updateFlag) {
            //update new archive for exist player
            [[PuzRankingManager sharedManager] updateTimeRankingWithObjectId:objectId data:updateTimeRankingObj failBlock:^(NSError *error){
                if (error != nil) {
                    NSLog(@" update time ranking");
                } else {
                    //TO DO Load data to result screen
                    [self LoadData];
                    NSLog(@" update time ranking success");
                }
            }];
        }
        // If no insert, no update
        else {
            [self LoadData];
        }
        
    } failBlock:^(NSError *failBlock){
        NSLog(@"get time ranking fail");
    }];
}

@end
