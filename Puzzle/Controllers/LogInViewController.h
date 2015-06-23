//
//  LogInViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/11/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LogInViewController : UIViewController
#pragma mark - Properties
@property (weak, nonatomic) NSArray *stages;
@property (strong, nonatomic) IBOutlet UILabel *lbErrMessage;
@property (strong, nonatomic) IBOutlet UITextField *tfID;
@property (strong, nonatomic) IBOutlet UITextField *tfPassWord;
@property (strong, nonatomic) IBOutlet UILabel *lbLinkToPass;
@property (strong, nonatomic) IBOutlet UIButton *btnLogIn;
@property (strong, nonatomic) IBOutlet UIButton *btnRegist;

#pragma mark - Actions
- (IBAction)logIn:(id)sender;
- (IBAction)signUp:(id)sender;

#pragma mark - Public methods
- (void)linkToPassword;

@end
