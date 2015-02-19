//
//  SampleViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SampleViewController : UIViewController <UIAlertViewDelegate>
{
    NSTimer *puzTimer;
}

@property (strong, nonatomic) UIImage *mImage;
@property (weak, nonatomic) NSString *mTitleStage;
@property (unsafe_unretained, nonatomic) NSInteger mTime;
@property (weak, nonatomic) IBOutlet UIImageView *sampleImage;
@property (weak, nonatomic) IBOutlet UILabel *mTimer;

@end
