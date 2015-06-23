//
//  SampleViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/20/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SampleViewController : UIViewController <UIAlertViewDelegate>
#pragma mark - Properties
@property (strong, nonatomic) UIImage *image;
@property (weak, nonatomic) NSString *stageName;
@property (unsafe_unretained, nonatomic) NSInteger time;
@property (weak, nonatomic) IBOutlet UIImageView *sampleImage;
@property (weak, nonatomic) IBOutlet UILabel *mTimer;

@end
