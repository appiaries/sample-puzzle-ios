//
//  PlayViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PlayViewController.h"
#import "SampleViewController.h"
#import "MBProgressHUD.h"
#import "TilePuzzle.h"
#import "ResultViewController.h"

#define TAG_ALER_TIME_IS_UP 1

static const NSTimeInterval AnimationSpeed = 0.2;

@interface PlayViewController () <TileBoardViewDelegate>
@property (weak, nonatomic) UIImageView *imageView;
@property (nonatomic, weak, readonly) UIImage *boardImage;
@property (nonatomic) NSInteger steps;
@end


@implementation PlayViewController
@synthesize mPuzStage;
@synthesize mPuzPlayer;
@synthesize lbTimer;
@synthesize mUserID;

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(backToRootView)
                                                 name:@"NotificationBackToRootView"
                                               object:nil];
    
    UIBarButtonItem *sampleButton = [[UIBarButtonItem alloc] initWithTitle:@"見本"
                                                                     style:UIBarButtonItemStyleBordered
                                                                    target:self
                                                                    action:@selector(goToSample)];
    self.navigationItem.rightBarButtonItem = sampleButton;
    lbTimer.text = [NSString stringWithFormat:@"%ld",(long)[mPuzStage.timeLimit integerValue]];
    mTimer = [mPuzStage.timeLimit integerValue];
    
    [NSTimer scheduledTimerWithTimeInterval:3 target:self selector:@selector(startGame) userInfo:nil repeats:NO];
    
    [self restart:nil];
}

- (void)viewWillAppear:(BOOL)animated
{
    self.title = mPuzStage.stageId;
}

- (void)startGame
{
    puzTimer = [NSTimer scheduledTimerWithTimeInterval:1
                                                target:self
                                              selector:@selector(startTimer)
                                              userInfo:nil
                                               repeats:YES];
}

// Check click back button
- (void)willMoveToParentViewController:(UIViewController *)parent
{
    if (parent == nil) {
        // Stop timer
        [puzTimer invalidate];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)restart:(UIButton *)sender
{
    [self.board playWithImage:self.boardImage
               sizeHorizontal:[mPuzStage.numberOfHrzPieces integerValue]
                 sizeVertical:[mPuzStage.numberOfVtlPieces integerValue]];
    [self.board shuffleTimes:100];
    [self hideImage];
}

- (IBAction)buttonTouchDown:(id)sender
{
    [self showImage];
}

- (IBAction)buttonTouchUpInside:(id)sender
{
    [self hideImage];
}

- (IBAction)sizeChanged:(UISegmentedControl *)sender
{
    [self restart:nil];
}

#pragma mark - Private method

- (void)backToRootView
{
    [self.navigationController popToRootViewControllerAnimated:NO];
}

//using ImageId to get image file
- (NSString *)getImageWithId:(NSString *)imageId
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *localPath = paths[0];
    NSString *strImage = [NSString stringWithFormat:@"%@.png",imageId];
    NSString *imageName = [localPath stringByAppendingPathComponent:strImage];
    
    return imageName;
}

- (void)startTimer
{
    if (mTimer > 0) {
        mTimer --;
        lbTimer.text = [NSString stringWithFormat:@"%ld", (long)mTimer];
    } else {
        [puzTimer invalidate];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@""
                                                        message:@"残念！時間切れです"
                                                       delegate:self
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        alert.tag = TAG_ALER_TIME_IS_UP;
        [alert show];
    }
}

- (UIImage *)boardImage
{
    NSString *pathFileImage = [self getImageWithId:mPuzStage.imageId];
    NSData *pngData = [NSData dataWithContentsOfFile:pathFileImage];
    return [UIImage imageWithData:pngData];;
}

- (void)showImage
{
    UIImageView *originalImage = [[UIImageView alloc] initWithImage:self.boardImage];
    originalImage.frame = self.board.frame;
    originalImage.alpha = 0.0;
    
    [originalImage.layer setShadowColor:[UIColor blackColor].CGColor];
    [originalImage.layer setShadowOpacity:0.65];
    [originalImage.layer setShadowRadius:1.5];
    [originalImage.layer setShadowOffset:CGSizeMake(1.5, 1.5)];
    [originalImage.layer setShadowPath:[[UIBezierPath bezierPathWithRect:originalImage.layer.bounds] CGPath]];
    
    [self.view addSubview:originalImage];
    
    [UIView animateWithDuration:AnimationSpeed animations:^{
        originalImage.alpha = 1.0;
        self.board.alpha = 0.0;
    } completion:^(BOOL finished) {
        self.imageView = originalImage;
    }];
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

- (void)goToSample
{
    SampleViewController *viewController = [self.storyboard instantiateViewControllerWithIdentifier:@"SampleScreen"];
    [viewController setMImage:self.boardImage];
    [viewController setMTime:[lbTimer.text integerValue]];
    [viewController setMTitleStage:mPuzStage.stageId];
    self.title = @"戻る";
    [self.navigationController pushViewController:viewController animated:YES];
}

- (void)goToGameResultScreen
{
    [MBProgressHUD hideAllHUDsForView:self.view animated:YES];
    ResultViewController *viewController = [self.storyboard instantiateViewControllerWithIdentifier:@"GameResultScreen"];
    [viewController setMStageID:mPuzStage.id];
    [viewController setMStageName:mPuzStage.stageId];
    [viewController setTimeScore:[mPuzStage.timeLimit integerValue] - mTimer];
    [viewController setMPuzPlayer:mPuzPlayer];
    [self presentViewController:viewController animated:YES completion:nil];
}

#pragma mark - Tile Board Delegate Method
- (void)tileBoardView:(TileBoardView *)tileBoardView tileDidMove:(CGPoint)position
{
    NSLog(@"tile move : %@", [NSValue valueWithCGPoint:position]);
    self.steps++;
}

- (void)tileBoardViewDidFinished:(TileBoardView *)tileBoardView
{
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    NSLog(@"tile is completed");
    [puzTimer invalidate];
    //[self showImage];
    [self.board playWithImage:self.boardImage
               sizeHorizontal:[mPuzStage.numberOfHrzPieces integerValue]
                 sizeVertical:[mPuzStage.numberOfVtlPieces integerValue]];
    [self.board finishDrawTiles];
    
    [NSTimer scheduledTimerWithTimeInterval:2
                                     target:self
                                   selector:@selector(goToGameResultScreen)
                                   userInfo:nil
                                    repeats:NO];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertView.tag == TAG_ALER_TIME_IS_UP) {
        if (buttonIndex == 0) {
            [self.navigationController popToRootViewControllerAnimated:YES];
        }
    }
}

@end
