//
//  PlayViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TileBoardView;
@class Stage;

@interface PlayViewController : UIViewController <UIAlertViewDelegate>
#pragma mark - Properties
@property (weak, nonatomic) IBOutlet TileBoardView *board;
@property (weak, nonatomic) IBOutlet UILabel *lbTimer;
@property (strong, nonatomic) Stage *stage;

@end
