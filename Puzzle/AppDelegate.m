//
//  AppDelegate.m
//  Puzzle
//
//  Created by Appiaries Corporation on 14/10/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "AppDelegate.h"
#import <UIKit/UIKit.h>
#import "SplashViewController.h"
#import "Introduction.h"
#import "Stage.h"
#import "Image.h"
#import "TimeRanking.h"
#import "FirstComeRanking.h"
#import "Player.h"
#import "FirstComeRankingSequence.h"
#import "Constants.h"

@implementation AppDelegate

#pragma mark - Application lifecycle
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // SDKの初期化
    baas.config.datastoreID      = kDatastoreID;
    baas.config.applicationID    = kApplicationID;
    baas.config.applicationToken = kApplicationToken;
    [baas activate];

    // モデル・クラスの登録
    [baas registerClasses:@[
            [Introduction class], [Stage class], [Image class], [Player class],
            [FirstComeRankingSequence class], [FirstComeRanking class], [TimeRanking class]
    ]];


    [self setupAppearance];

    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:kStoryboardName bundle: nil];
    SplashViewController *vc = [mainStoryboard instantiateViewControllerWithIdentifier:kSplashViewControllerID];
    self.window.rootViewController = vc;

    return YES;
}

- (void)setupAppearance
{
    // SVProgressHUD
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeBlack];
    [SVProgressHUD setBackgroundColor:[[UIColor blackColor] colorWithAlphaComponent:0.75]];
    [SVProgressHUD setForegroundColor:[UIColor whiteColor]];
}

@end
