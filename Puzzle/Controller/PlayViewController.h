//
//  PlayViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PuzPlayers.h"
#import "PuzStage.h"

@class TileBoardView;

@interface PlayViewController : UIViewController <UIAlertViewDelegate>
{
    NSInteger mTimer;
    NSTimer *puzTimer;
}

@property (strong, nonatomic) NSString *mUserID;
@property (strong, nonatomic) PuzPlayers *mPuzPlayer;
@property (strong, nonatomic) PuzStage *mPuzStage;
@property (weak, nonatomic) IBOutlet TileBoardView *board;
@property (weak, nonatomic) IBOutlet UILabel *lbTimer;

@end
