//
//  TopViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "TopViewController.h"
#import "Stage.h"
#import "PlayViewController.h"
#import "Constants.h"

@implementation TopViewController
{
    int _index;
}

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.title = @"";
}

#pragma mark - Actions
- (IBAction)btnBackStageTapped:(id)sender
{
    if (_index > 0) {
        _index --;
        Stage *stage = _stages[(NSUInteger)_index];
        _lbStageLevel.text = stage.name;
        
        self.btnNext.alpha = 1;
        if (_index == 0) {
            self.btnBack.alpha = 0;
        }
    }
}

- (IBAction)btnNextStageTapped:(id)sender
{
    if (_index < [_stages count] - 1) {
        _index ++;
        Stage *stage = _stages[(NSUInteger)_index];
        _lbStageLevel.text = stage.name;
        
        self.btnBack.alpha = 1;
        if (_index == [_stages count] - 1) {
            self.btnNext.alpha = 0;
        }
    }
}

- (IBAction)btnStartTapped:(id)btnStart
{
    PlayViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:kPlayViewControllerID];
    vc.stage = _stages[(NSUInteger)_index];

    self.title = @"戻る";
    [self.navigationController pushViewController:vc animated:YES];
}

- (IBAction)btnRankingTapped:(id)btnRanking
{
    [self performSegueWithIdentifier:kSegueTopToRanking sender:self];
}

#pragma mark - MISC
- (void)setupView
{
    self.title = @"Puzzle";

    _viewContainer.layer.borderColor = [UIColor blackColor].CGColor;
    _viewContainer.layer.borderWidth = 1.0f;

    _index = 0;

    Stage *stage = _stages[(NSUInteger)_index];
    _lbStageLevel.text = stage.name;

    _btnBack.alpha = 0;
    if ([_stages count] == 1) {
        _btnNext.alpha = 0;
    } else if ([_stages count] > 0) {
        _btnNext.alpha = 1;
    }
}

@end
