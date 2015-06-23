//
//  SignUpViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/13/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <SHAlertViewBlocks/SHAlertViewBlocks.h>
#import "SignUpViewController.h"
#import "Player.h"
#import "Validator.h"
#import "Constants.h"

@implementation SignUpViewController

#pragma mark - Constants
CGFloat animatedDistance;
static const CGFloat KEYBOARD_ANIMATION_DURATION = 0.3;
static const CGFloat MINIMUM_SCROLL_FRACTION     = 0.2;
static const CGFloat MAXIMUM_SCROLL_FRACTION     = 0.8;
static const CGFloat PORTRAIT_KEYBOARD_HEIGHT    = 150;
static const CGFloat LANDSCAPE_KEYBOARD_HEIGHT   = 162;

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];
}

#pragma mark - Actions
- (IBAction)signUp:(id)sender
{
    if ([self validate]) {
        //----------------------------------------
        // Sign-Up
        //----------------------------------------
        Player *player = [Player player];
        player.loginId  = _tfId.text;
        player.email    = _tfEmail.text;
        player.nickname = _tfNickName.text;
        player.password = _tfPassword.text;

        [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
        [player signUpWithBlock:^(ABResult *ret, ABError *err){
            [SVProgressHUD dismiss];
            if (err == nil) {
                [[UIAlertView SH_alertViewWithTitle:@"ご確認"
                                        andMessage:@"ご案内のためのメールが送信されました。ご確認ください。"
                                      buttonTitles:nil
                                       cancelTitle:@"OK"
                                         withBlock:^(NSInteger buttonIndex){
                                             if (buttonIndex ==  0) {
                                                 [self performSegueWithIdentifier:kSegueSignUpToIntroduction sender:nil];
                                             }
                                         }
                ] show];
            } else {
                [_lbError setText:err.description];
            }
        } option:ABUserSignUpOptionLogInAutomatically];
    }
    
    [self dismissKeyboard];
}

#pragma mark - UITextField delegates
- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    CGRect textFieldRect = [self.view.window convertRect:textField.bounds fromView:textField];
    CGRect viewRect = [self.view.window convertRect:self.view.bounds fromView:self.view];
    CGFloat midline = textFieldRect.origin.y + 0.5f * textFieldRect.size.height;
    CGFloat numerator = midline - viewRect.origin.y - MINIMUM_SCROLL_FRACTION * viewRect.size.height;
    CGFloat denominator = (MAXIMUM_SCROLL_FRACTION - MINIMUM_SCROLL_FRACTION) * viewRect.size.height;
    CGFloat heightFraction = numerator / denominator;

    if (heightFraction < 0.0f) {
        heightFraction = 0.0f;
    } else if (heightFraction > 1.0f) {
        heightFraction = 1.0f;
    }

    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown) {
        animatedDistance = (CGFloat)floor(PORTRAIT_KEYBOARD_HEIGHT * heightFraction);
    } else {
        animatedDistance = (CGFloat)floor(LANDSCAPE_KEYBOARD_HEIGHT * heightFraction);
    }

    CGRect viewFrame = self.view.frame;
    viewFrame.origin.y -= animatedDistance;

    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:KEYBOARD_ANIMATION_DURATION];

    [self.view setFrame:viewFrame];

    [UIView commitAnimations];
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    CGRect viewFrame = self.view.frame;
    viewFrame.origin.y += animatedDistance;

    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:KEYBOARD_ANIMATION_DURATION];

    [self.view setFrame:viewFrame];

    [UIView commitAnimations];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

#pragma mark - MISC
- (void)setupView
{
    self.title = @"";

    self.view.backgroundColor = [UIColor whiteColor];

    _lbError.text = @" ";

    _tfNickName.delegate = self;
    _tfPassword.delegate = self;

    _btnRegist.layer.cornerRadius = 7.0f;
    _btnRegist.layer.masksToBounds = YES;

    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissKeyboard)];
    [self.view addGestureRecognizer:tapGesture];
}

- (void)dismissKeyboard
{
    [_tfEmail resignFirstResponder];
    [_tfId resignFirstResponder];
    [_tfNickName resignFirstResponder];
    [_tfPassword resignFirstResponder];
}

- (BOOL)validate
{
    _lbError.text = @"";
    _tfEmail.layer.borderColor = [UIColor blackColor].CGColor;
    _tfEmail.layer.borderWidth = 0;
    _tfId.layer.borderColor = [UIColor blackColor].CGColor;
    _tfId.layer.borderWidth = 0;
    _tfNickName.layer.borderColor = [UIColor blackColor].CGColor;
    _tfNickName.layer.borderWidth = 0;
    _tfPassword.layer.borderColor = [UIColor blackColor].CGColor;
    _tfPassword.layer.borderWidth = 0;
    
    ABError *err = nil;

    //valid email
    err = [Validator validateFor:@"Email"
                           value:_tfEmail.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRuleEmail)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"メールアドレスは入力必須です。"}, @(ValidationRuleEmail):@{@"msg":@"無効なメールアドレスです。"}}];
    if (err) {
        _lbError.text = err.localizedDescription;
        _tfEmail.layer.borderColor = [UIColor redColor].CGColor;
        _tfEmail.layer.borderWidth = 1.0;
        return NO;
    }

    //valid loginId
    err = [Validator validateFor:@"ID"
                           value:_tfId.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRuleLoginId)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"IDは入力必須です。"}, @(ValidationRuleLoginId):@{@"msg":@"IDは4桁から20桁である必要があります。"}}];
    if (err) {
        _lbError.text = err.localizedDescription;
        _tfId.layer.borderColor = [UIColor redColor].CGColor;
        _tfId.layer.borderWidth = 1.0;
        return NO;
    }

    //valid nickname
    err = [Validator validateFor:@"Nickname"
                           value:_tfNickName.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRuleNickname)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"ニックネームは入力必須です。"}, @(ValidationRuleNickname):@{@"msg":@"ニックネームは4桁から20桁である必要があります。"}}];
    if (err) {
        _lbError.text = err.localizedDescription;
        _tfNickName.layer.borderColor = [UIColor redColor].CGColor;
        _tfNickName.layer.borderWidth = 1.0;
        return NO;
    }

    //valid password
    err = [Validator validateFor:@"Password"
                           value:_tfPassword.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRulePassword)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"パスワードは入力必須です。"}, @(ValidationRulePassword):@{@"msg":@"パスワードは8桁から20桁である必要があります。"}}];
    if (err) {
        _lbError.text = err.localizedDescription;
        _tfPassword.layer.borderColor = [UIColor redColor].CGColor;
        _tfPassword.layer.borderWidth = 1.0;
        return NO;
    }

    return YES;
}

@end
