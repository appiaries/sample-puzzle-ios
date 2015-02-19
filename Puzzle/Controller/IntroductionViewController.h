//
//  IntroductionViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/14/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IntroductionViewController : UIViewController
{
    NSMutableArray *listInformation;
    int index;
}

@property (strong, nonatomic) IBOutlet UIButton *btnSkip;
@property (strong, nonatomic) IBOutlet UIButton *btnBack;
@property (strong, nonatomic) IBOutlet UIButton *btnNext;
@property (strong, nonatomic) IBOutlet UIScrollView *scrollView;
@property (strong, nonatomic) IBOutlet UITextView *tvDescription;

- (IBAction)backPage:(id)sender;
- (IBAction)nextPage:(id)sender;
- (IBAction)skipPage:(id)sender;

@end
