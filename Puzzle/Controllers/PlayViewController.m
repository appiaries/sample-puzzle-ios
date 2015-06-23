//
//  PlayViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <SHAlertViewBlocks/UIAlertView+SHAlertViewBlocks.h>
#import "PlayViewController.h"
#import "SampleViewController.h"
#import "TilePuzzle.h"
#import "ResultViewController.h"
#import "Player.h"
#import "Stage.h"
#import "TimeRanking.h"
#import "FirstComeRanking.h"
#import "FirstComeRankingSequence.h"
#import "Constants.h"

@interface PlayViewController () <TileBoardViewDelegate>
#pragma mark - Properties (Private)
@property (weak, nonatomic) UIImageView *imageView;
@property (nonatomic, weak, readonly) UIImage *boardImage;
@property (nonatomic) NSInteger steps;
@end


@implementation PlayViewController
{
    NSInteger _remainingTime;
    NSTimer *_timer;
    NSUInteger _startDelay;
}

#pragma mark - Constants
static const NSTimeInterval AnimationSpeed = 0.2;

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(backToRootView)
                                                 name:kBackToRootNotification
                                               object:nil];
    [self startGame];

    [self restart:nil];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.title = _stage.name;
}

#pragma mark - Memory management
- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

#pragma mark - UIContainerViewController callbacks
- (void)willMoveToParentViewController:(UIViewController *)parent
{
    // Check click back button
    if (parent == nil) {
        [self stopTimerIfNeeded];
    }
}

#pragma mark - Actions
- (IBAction)restart:(UIButton *)sender
{
    [self.board playWithImage:self.boardImage
               sizeHorizontal:_stage.numberOfHorizontalPieces
                 sizeVertical:_stage.numberOfVerticalPieces];
    [self.board shuffleTimes:100];
    [self hideImage];
}

#pragma mark - TileBoardView delegates
- (void)tileBoardView:(TileBoardView *)tileBoardView tileDidMove:(CGPoint)position
{
    NSLog(@"tile move : %@", [NSValue valueWithCGPoint:position]);
    self.steps++;
}

- (void)tileBoardViewDidFinished:(TileBoardView *)tileBoardView
{
    [self didClearStage];
}

#pragma mark - Accessors
- (UIImage *)boardImage
{
    NSString *dir = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
    NSError *err = nil;
    NSArray * directoryContents =  [[NSFileManager defaultManager] contentsOfDirectoryAtPath:dir error:&err];
    if (err == nil && [directoryContents count] > 0) {
        for (NSString *content in directoryContents) {
            if ([content hasPrefix:_stage.image_id]) {
                NSString *path = [dir stringByAppendingPathComponent:content];
                NSData *imageData = [NSData dataWithContentsOfFile:path];
                return [UIImage imageWithData:imageData];
            }
        }
    }
    return nil;
}

#pragma mark - MISC
- (void)setupView
{
    UIBarButtonItem *sampleButton = [[UIBarButtonItem alloc] initWithTitle:@"見本"
                                                                     style:UIBarButtonItemStyleBordered
                                                                    target:self
                                                                    action:@selector(goToSample)];
    self.navigationItem.rightBarButtonItem = sampleButton;
    _lbTimer.text = [NSString stringWithFormat:@"%ld",(long)_stage.timeLimit];
    _remainingTime = _stage.timeLimit;
}

- (void)startGame
{
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    _startDelay = 3;
    _timer = [NSTimer scheduledTimerWithTimeInterval:1
                                              target:self
                                            selector:@selector(startTimer)
                                            userInfo:nil
                                             repeats:YES];
}

- (void)hideImage
{
    if (!self.imageView) return;
    
    [UIView animateWithDuration:AnimationSpeed animations:^{
        self.imageView.alpha = 0.0;
        self.board.alpha = 1.0;
    } completion:^(BOOL finished){
        [self.imageView removeFromSuperview];
        self.imageView = nil;
    }];
}

- (void)backToRootView
{
    [self.navigationController popToRootViewControllerAnimated:NO];
}

- (void)startTimer
{
    // waiting 3 seconds
    if (_startDelay > 0) {
        _startDelay--;
        if (_startDelay == 0) {
            [SVProgressHUD dismiss];
        }
        return;
    }

    if (_remainingTime > 0) {
        _remainingTime--;
        _lbTimer.text = [NSString stringWithFormat:@"%ld", (long) _remainingTime];
    } else {
        [self stopTimerIfNeeded];

        [[UIAlertView SH_alertViewWithTitle:@""
                                andMessage:@"残念！時間切れです。"
                              buttonTitles:nil
                               cancelTitle:@"OK"
                                 withBlock:^(NSInteger buttonIndex){
                                     [self.navigationController popToRootViewControllerAnimated:YES];
                                 }
        ] show];
    }
}

- (void)stopTimerIfNeeded
{
    if ([_timer isValid]) {
        [_timer invalidate];
        _timer = nil;
    }
}

- (void)goToSample
{
    SampleViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:kSampleViewControllerID];
    vc.image = self.boardImage;
    vc.time  = [_lbTimer.text intValue];
    vc.stageName = _stage.name;
    self.title = @"戻る";
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)didClearStage
{
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    [self stopTimerIfNeeded];

    [self.board playWithImage:self.boardImage
               sizeHorizontal:_stage.numberOfHorizontalPieces
                 sizeVertical:_stage.numberOfVerticalPieces];
    [self.board finishDrawTiles];

    Player *player = (Player *)baas.session.user;
    NSString *playerId  = player.ID;
    NSString *nickname  = player.nickname;
    NSString *stageId   = _stage.ID;
    NSString *stageName = _stage.name;
    NSInteger score     = _stage.timeLimit - _remainingTime;

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        //----------------------------------------
        // Find all first come ranking
        //----------------------------------------
        ABError *err = nil;
        ABQuery *firstComeRankingFindQuery = [[FirstComeRanking query] orderBy:@"rank" direction:ABSortASC];
        ABResult *firstComeRankingFindResult = [baas.db findSynchronouslyWithQuery:firstComeRankingFindQuery error:&err];
        if (err == nil) {
            BOOL isAlreadyRegistered = NO;
            NSArray *foundArray = firstComeRankingFindResult.data;
            if ([foundArray count] > 0) {
                for (FirstComeRanking *ranking in foundArray) {
                    if ([ranking.stageId isEqualToString:stageId] && [ranking.playerId isEqualToString:playerId]) {
                        isAlreadyRegistered = YES;
                        break;
                    }
                }
            }
            if (!isAlreadyRegistered) {
                //----------------------------------------
                // Get next sequence value
                //----------------------------------------
                FirstComeRankingSequence *seq = [FirstComeRankingSequence sequence];
                long long value = [baas.seq getNextValueSynchronously:seq error:&err];
                if (err == nil) {
                    //----------------------------------------
                    // Create first come ranking
                    //----------------------------------------
                    FirstComeRanking *newRanking = [FirstComeRanking ranking];
                    newRanking.stageId  = stageId;
                    newRanking.playerId = playerId;
                    newRanking.nickname = nickname;
                    newRanking.score    = score;
                    newRanking.rank     = (int)value;
                    [newRanking saveSynchronouslyWithError:&err];
                    if (err != nil) {
                        dispatch_async(dispatch_get_main_queue(), ^{
                            [SVProgressHUD showErrorWithStatus:err.description];
                            return;
                        });
                    }
                } else {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [SVProgressHUD showErrorWithStatus:err.description];
                        return;
                    });
                }
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
        ABQuery *timeRankingFindQuery = [[TimeRanking query] orderBy:@"_cts" direction:ABSortASC];
        ABResult *timeRankingFindResult = [baas.db findSynchronouslyWithQuery:timeRankingFindQuery error:&err];
        if (err == nil) {
            TimeRanking *updateRanking = nil;
            NSArray *foundArray = timeRankingFindResult.data;
            BOOL isAlreadyRegistered = NO;
            if ([foundArray count] > 0) {
                for (TimeRanking *ranking in foundArray) {
                    if ([ranking.stageId isEqualToString:stageId] && [ranking.playerId isEqualToString:playerId]) {
                        isAlreadyRegistered = YES;
                        if (score < ranking.score) {
                            updateRanking = ranking;
                        }
                        break;
                    }
                }
            }

            if (isAlreadyRegistered) {
                if (updateRanking) {
                    //----------------------------------------
                    // Update time ranking
                    //----------------------------------------
                    updateRanking.score = score;
                    [updateRanking saveSynchronouslyWithError:&err];
                    if (err != nil) {
                        dispatch_async(dispatch_get_main_queue(), ^{
                            [SVProgressHUD showErrorWithStatus:err.description];
                            return;
                        });
                    }
                }
            } else {
                //----------------------------------------
                // Create time ranking
                //----------------------------------------
                TimeRanking *newRanking = [TimeRanking ranking];
                newRanking.stageId  = stageId;
                newRanking.playerId = playerId;
                newRanking.nickname = nickname;
                newRanking.score    = score;
                [newRanking saveSynchronouslyWithError:&err];
                if (err != nil) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [SVProgressHUD showErrorWithStatus:err.description];
                        return;
                    });
                }
            }

        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [SVProgressHUD showErrorWithStatus:err.description];
                return;
            });
        }

        double delayInSeconds = 2.0;
        dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)delayInSeconds * NSEC_PER_SEC);
        dispatch_after(popTime, dispatch_get_main_queue(), ^{
            [SVProgressHUD dismiss];
            ResultViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:kResultViewControllerID];
            vc.stageId   = stageId;
            vc.stageName = stageName;
            vc.score     = score;
            [self presentViewController:vc animated:YES completion:nil];
        });
    });
}

@end
