//
//  LoginViewController.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/11/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController
{
    NSString *userID;
}

@property (weak, nonatomic) NSArray *listStage;
@property (strong, nonatomic) IBOutlet UILabel *lbErrMessage;
@property (strong, nonatomic) IBOutlet UITextField *tfID;
@property (strong, nonatomic) IBOutlet UITextField *tfPassWord;
@property (strong, nonatomic) IBOutlet UILabel *lbLinkToPass;
@property (strong, nonatomic) IBOutlet UIButton *btnLogIn;
@property (strong, nonatomic) IBOutlet UIButton *btnRegist;

- (void)linkToPassWord;
- (IBAction)logIn:(id)sender;
- (IBAction)registNewID:(id)sender;

@end
