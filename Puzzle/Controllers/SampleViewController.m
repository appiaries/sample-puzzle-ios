//
//  SampleViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "SampleViewController.h"

#define kTagTimeIsUpAlertView 1

@implementation SampleViewController
{
    NSTimer *_timer;
}

#pragma mark - Initialization
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    return self;
}

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];

    _timer = [NSTimer scheduledTimerWithTimeInterval:1
                                                target:self
                                              selector:@selector(startTimer)
                                              userInfo:nil
                                               repeats:YES];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [self stopTimerIfNeeded];
}

#pragma mark - UIAlertView delegates
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertView.tag == kTagTimeIsUpAlertView) {
        if (buttonIndex == 0) {
            [self.navigationController popViewControllerAnimated:YES];
        }
    }
}

#pragma mark - MISC
- (void)setupView
{
    self.title = _stageName;

    _sampleImage.image = _image;
    _mTimer.text = [NSString stringWithFormat:@"%ld", (long) _time];
}

- (void)startTimer
{
    if (_time > 0) {
        _time--;
        _mTimer.text = [NSString stringWithFormat:@"%ld", (long) _time];
    } else {
        [self stopTimerIfNeeded];
    }
}

- (void)stopTimerIfNeeded
{
    if ([_timer isValid]) {
        [_timer invalidate];
        _timer = nil;
    }
}

@end
