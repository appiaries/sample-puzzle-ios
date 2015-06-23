//
//  SignUpViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/13/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SignUpViewController : UIViewController<UITextFieldDelegate>
#pragma mark - Properties
@property (strong, nonatomic) IBOutlet UILabel *lbError;
@property (strong, nonatomic) IBOutlet UITextField *tfEmail;
@property (strong, nonatomic) IBOutlet UITextField *tfId;
@property (strong, nonatomic) IBOutlet UITextField *tfNickName;
@property (strong, nonatomic) IBOutlet UITextField *tfPassword;
@property (strong, nonatomic) IBOutlet UIButton *btnRegist;

#pragma mark - Actions
- (IBAction)signUp:(id)sender;

@end
