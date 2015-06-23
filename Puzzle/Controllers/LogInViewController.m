//
//  LogInViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/11/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "LogInViewController.h"
#import "TopViewController.h"
#import "Player.h"
#import "Validator.h"
#import "Constants.h"

@implementation LogInViewController

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];
}

#pragma mark - Actions
- (IBAction)logIn:(id)sender
{
    if ([self validate]) {
        //----------------------------------------
        // Log-In
        //----------------------------------------
        Player *player = [Player player];
        player.loginId  = _tfID.text;
        player.password = _tfPassWord.text;

        [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
        [player logInWithBlock:^(ABResult *ret, ABError *err){
            [SVProgressHUD dismiss];
            if (err == nil) {
                [self performSegueWithIdentifier:kSegueLogInToTop sender:self];
            } else {
                [_lbErrMessage setText:err.localizedDescription];
            }
        } option:ABUserLogInOptionLogInAutomatically];

    } else {
        [_lbErrMessage setText:@"入力された内容に誤りがあります。"];
    }
}

- (IBAction)signUp:(id)sender
{
    [self performSegueWithIdentifier:kSegueLogInToSignUp sender:self];
}

#pragma mark - Public methods
-  (void)linkToPassword
{
    [self performSegueWithIdentifier:kSegueLogInToPasswordReminder sender:self];
}

#pragma mark - Segues
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:kSegueLogInToTop]) {
        UINavigationController *nav = segue.destinationViewController;
        TopViewController *vc = [nav viewControllers][0];
        vc.stages = _stages;
    }
}

#pragma mark - MISC
- (void)setupView
{
    self.title = @"";

    _lbErrMessage.text = @" ";

    _btnLogIn.layer.cornerRadius = 7.0f;
    _btnLogIn.layer.masksToBounds = YES;

    _btnRegist.layer.cornerRadius = 7.0f;
    _btnRegist.layer.masksToBounds = YES;

    UIFont *font = [UIFont fontWithName:@"Hiragino Kaku Gothic ProN W3" size:16];
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:@"→パスワードを忘れた方はこちら"];
    [string addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, string.length)];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor blueColor] range:NSMakeRange(0, string.length)]; //TextColor
    [string addAttribute:NSUnderlineStyleAttributeName value:@(NSUnderlineStyleSingle) range:NSMakeRange(0, string.length)]; //Underline color
    [string addAttribute:NSUnderlineColorAttributeName value:[UIColor blueColor] range:NSMakeRange(0, string.length)]; //TextColor
    _lbLinkToPass.attributedText =  string;
    _lbLinkToPass.userInteractionEnabled = YES;

    UITapGestureRecognizer *remindGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(linkToPassword)];
    [_lbLinkToPass addGestureRecognizer:remindGesture];

    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissKeyboard)];
    [self.view addGestureRecognizer:tap];
}

- (void)dismissKeyboard
{
    [_tfID resignFirstResponder];
    [_tfPassWord resignFirstResponder];
}

- (BOOL)validate
{
    _lbErrMessage.text = @"";
    _tfID.layer.borderColor = [UIColor blackColor].CGColor;
    _tfID.layer.borderWidth = 0;
    _tfPassWord.layer.borderColor = [UIColor blackColor].CGColor;
    _tfPassWord.layer.borderWidth = 0;

    ABError *err = nil;

    //valid loginId
    err = [Validator validateFor:@"ID"
                           value:_tfID.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRuleLoginId)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"ID is blank"}, @(ValidationRuleLoginId):@{@"msg":@"Invalid ID"}}];
    if (err) {
        _lbErrMessage.text = err.localizedDescription;
        _tfID.layer.borderColor = [UIColor redColor].CGColor;
        _tfID.layer.borderWidth = 1.0;
        return NO;
    }

    //valid password
    err = [Validator validateFor:@"Password"
                           value:_tfPassWord.text
                           rules:@[@(ValidationRuleRequired), @(ValidationRulePassword)]
                        ruleArgs:@{@(ValidationRuleRequired):@{@"msg":@"Password is blank"}, @(ValidationRulePassword):@{@"msg":@"Invalid Password"}}];
    if (err) {
        _lbErrMessage.text = err.localizedDescription;
        _tfPassWord.layer.borderColor = [UIColor redColor].CGColor;
        _tfPassWord.layer.borderWidth = 1.0;
        return NO;
    }

    return YES;
}

@end
