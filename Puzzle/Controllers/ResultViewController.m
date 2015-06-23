//
//  ResultViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "FirstComeRanking.h"
#import "ResultViewController.h"
#import "TimeRanking.h"
#import "Constants.h"

@implementation ResultViewController

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(backToResultView)
                                                 name:kBackToResultNotification
                                               object:nil];
    [self loadData];
}

#pragma mark - Memory management
- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

#pragma mark - Actions
- (IBAction)btnHomeTapped:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:kBackToRootNotification object:self];
}

- (IBAction)btnRankingTapped:(id)sender
{
    [self performSegueWithIdentifier:kSegueResultToRanking sender:self];
}

#pragma mark - MISC
- (void)setupView
{
    _lblResult.text = [NSString stringWithFormat:@"%ld秒", (long) _score];
    _lbResultTitle.text = _stageName;
}

- (void)backToResultView
{
    [self dismissViewControllerAnimated:YES completion:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:kBackToRootNotification object:self];
}

- (void)loadData
{
    NSString *playerId = baas.session.user.ID;

    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSString *timeRankingText = @"";
        NSString *firstComeRankingText = @"";
        //----------------------------------------
        // Find all first come ranking
        //----------------------------------------
        ABError *err = nil;
        ABQuery *query1 = [[[FirstComeRanking query] where:@"stage_id" equalsTo:_stageId]orderBy:@"rank" direction:ABSortASC];
        ABResult *ret1 = [baas.db findSynchronouslyWithQuery:query1 error:&err];
        if (err == nil) {
            NSArray *foundArray = ret1.data;
            if ([foundArray count] > 0) {
                FirstComeRanking *ownFirstComeRanking = nil;
                for (FirstComeRanking *ranking in foundArray) {
                    if ([ranking.playerId isEqualToString:playerId]) {
                        ownFirstComeRanking = ranking;
                        break;
                    }
                }
                NSInteger rank = 1;
                for (FirstComeRanking *ranking in foundArray) {
                    if (ranking.score < ownFirstComeRanking.score) {
                        rank++;
                    } else if (ranking.score == ownFirstComeRanking.score) {
                        if ([ranking.created timeIntervalSince1970] < [ownFirstComeRanking.created timeIntervalSince1970]) {
                            rank++;
                        }
                    } else {
                        /* NOP */
                    }
                }
                firstComeRankingText = [NSString stringWithFormat:@"%li位/%li人中", (long)rank, (long)[foundArray count]];
            }
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [SVProgressHUD showErrorWithStatus:err.description];
                return;
            });
        }

        //----------------------------------------
        // Find all time ranking
        //----------------------------------------
        ABQuery *query2 = [[[TimeRanking query] where:@"stage_id" equalsTo:_stageId] orderBy:@"_cts" direction:ABSortASC];
        ABResult *ret2 = [baas.db findSynchronouslyWithQuery:query2 error:&err];
        if (err == nil) {
            NSArray *foundArray = ret2.data;
            if ([foundArray count] > 0) {
                TimeRanking *ownTimeRanking = nil;
                for (TimeRanking *ranking in foundArray) {
                    if ([ranking.playerId isEqualToString:playerId]) {
                        ownTimeRanking = ranking;
                        break;
                    }
                }
                NSInteger rank = 1;
                for (TimeRanking *ranking in foundArray) {
                    if (ranking.score < ownTimeRanking.score) {
                        rank++;
                    } else if (ranking.score == ownTimeRanking.score) {
                        if ([ranking.created timeIntervalSince1970] < [ownTimeRanking.created timeIntervalSince1970]) {
                            rank++;
                        }
                    } else {
                        /* NOP */
                    }
                }
                timeRankingText = [NSString stringWithFormat:@"%li位/%li人中", (long)rank, (long)[foundArray count]];
            }
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [SVProgressHUD showErrorWithStatus:err.description];
                return;
            });
        }

        dispatch_async(dispatch_get_main_queue(), ^{
            _lblClearTime.text = timeRankingText;
            _lblRanking.text   = firstComeRankingText;
            [SVProgressHUD dismiss];
        });
    });
}

@end
