//
//  SampleViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "SampleViewController.h"

#define TAG_ALER_TIME_IS_UP 1

@implementation SampleViewController
@synthesize mImage;
@synthesize mTime;
@synthesize mTimer;
@synthesize mTitleStage;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = mTitleStage;
    self.sampleImage.image = mImage;
    mTimer.text = [NSString stringWithFormat:@"%ld", (long)mTime];
    
    puzTimer = [NSTimer scheduledTimerWithTimeInterval:1
                                                target:self
                                              selector:@selector(startTimer)
                                              userInfo:nil
                                               repeats:YES];
}

#pragma mark - Private method
- (void)startTimer
{
    if (mTime > 0) {
        mTime --;
        mTimer.text = [NSString stringWithFormat:@"%ld", (long)mTime];
    } else {
        [puzTimer invalidate];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UIAlertView delegates
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertView.tag == TAG_ALER_TIME_IS_UP) {
        if (buttonIndex == 0) {
            [self.navigationController popViewControllerAnimated:YES];
        }
    }
}

@end
