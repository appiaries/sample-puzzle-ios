//
//  RegisterViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/13/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "RegisterViewController.h"
#import "PuzPlayers.h"
#import "PuzPlayerManager.h"
#import "MBProgressHUD.h"

#define TAG_ALERT_SUCCESSFUL 99

NSString *INVALID_INFORMATION = @"入力された内容に誤りがあります。";

CGFloat animatedDistance;

static const CGFloat KEYBOARD_ANIMATION_DURATION = 0.3;
static const CGFloat MINIMUM_SCROLL_FRACTION = 0.2;
static const CGFloat MAXIMUM_SCROLL_FRACTION = 0.8;
static const CGFloat PORTRAIT_KEYBOARD_HEIGHT = 150;
static const CGFloat LANDSCAPE_KEYBOARD_HEIGHT = 162;


@implementation RegisterViewController
@synthesize lbError;
@synthesize tfEmail, tfId, tfNickName, tfPassword;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    tfNickName.delegate = self;
    tfPassword.delegate = self;
    
    [self tapOut];
    
    self.title = @"";
    [lbError setText:@""];
    [[self.btnRegist layer] setCornerRadius:7.0f];
    [[self.btnRegist layer] setMasksToBounds:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action method
- (IBAction)registNewID:(id)sender
{
    NSLog(@"button regist clicked");
    
    //validation data
    if ([self dataValidation]) {
        if ([tfId.text length] < 3 || [tfId.text length] > 20) {
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"ご確認"
                                                                message:@"IDは3桁から20桁である必要があります"
                                                               delegate:self
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles:nil, nil];
            [alertView show];
        } else if ([tfPassword.text length] < 6 || [tfPassword.text length] > 20) {
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"ご確認"
                                                                message:@"パスワードは8桁から20桁である必要があります"
                                                               delegate:self
                                                      cancelButtonTitle:@"OK"
                                                      otherButtonTitles:nil, nil];
            [alertView show];
        } else {
            //regist new account
            PuzPlayers *playerInfo = [[PuzPlayers alloc] init];
            playerInfo.loginId = tfId.text;
            playerInfo.email = tfEmail.text;
            playerInfo.password = tfPassword.text;
            playerInfo.nickname = tfNickName.text;
            
            [MBProgressHUD showHUDAddedTo:self.view animated:YES];
            [[PuzPlayerManager sharedManager] createUser:playerInfo withBlock:^(NSError *error){
                [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
                if (error != nil) {
                    NSLog(@"Error: %@", [error localizedDescription]);
                    [lbError setText:error.localizedDescription];
                } else {
                    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"ご確認"
                                                                        message:@"ご案内のためのメールが送信されました。ご確認下さい。"
                                                                       delegate:self
                                                              cancelButtonTitle:@"OK"
                                                              otherButtonTitles:nil, nil];
                    alertView.tag = TAG_ALERT_SUCCESSFUL;
                    [alertView show];
                }
            }];
        }
        
    } else {
        NSLog(@"validation register form fail");
    }
    
    [self dismissKeyboard];
}

#pragma mark - Private method
- (void)tapOut
{
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self
                                                                          action:@selector(dismissKeyboard)];
    [self.view addGestureRecognizer:tap];
}

- (void)dismissKeyboard
{
    [tfEmail resignFirstResponder];
    [tfId resignFirstResponder];
    [tfNickName resignFirstResponder];
    [tfPassword resignFirstResponder];
}

- (BOOL)dataValidation
{
    [lbError setText:@""];
    tfEmail.layer.borderColor = [[UIColor blackColor] CGColor];
    tfId.layer.borderColor = [[UIColor blackColor] CGColor];
    tfNickName.layer.borderColor = [[UIColor blackColor] CGColor];
    tfPassword.layer.borderColor = [[UIColor blackColor] CGColor];
    
    tfEmail.layer.borderWidth = 0;
    tfId.layer.borderWidth = 0;
    tfNickName.layer.borderWidth = 0;
    tfPassword.layer.borderWidth = 0;
    
    BOOL retFlag = YES;
    
    //valid email nil or blank
    if (tfEmail.text == nil || [tfEmail.text length] == 0) {
        [lbError setText:INVALID_INFORMATION];
        tfEmail.layer.borderColor = [[UIColor redColor] CGColor];
        tfEmail.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid email type
    if (![self validateEmail:tfEmail.text]) {
        [lbError setText:INVALID_INFORMATION];
        tfEmail.layer.borderColor = [[UIColor redColor] CGColor];
        tfEmail.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid id nil or blank
    if (tfId.text == nil || [tfId.text length] == 0) {
        [lbError setText:INVALID_INFORMATION];
        tfId.layer.borderColor = [[UIColor redColor] CGColor];
        tfId.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid id in use
    
    //valid nickname
    if (tfNickName.text == nil || [tfNickName.text length] == 0) {
        [lbError setText:INVALID_INFORMATION];
        tfNickName.layer.borderColor =[[UIColor redColor] CGColor];
        tfNickName.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid password
    if (tfPassword.text == nil || [tfPassword.text length] == 0) {
        [lbError setText:INVALID_INFORMATION];
        tfPassword.layer.borderColor = [[UIColor redColor] CGColor];
        tfPassword.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    return retFlag;
}

- (BOOL)validateEmail:(NSString *)candidate
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:candidate];
}

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
    
    UIInterfaceOrientation orientation =
    [[UIApplication sharedApplication] statusBarOrientation];
    if (orientation == UIInterfaceOrientationPortrait ||
        orientation == UIInterfaceOrientationPortraitUpsideDown) {
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

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertView.tag == TAG_ALERT_SUCCESSFUL) {
        if (buttonIndex ==  0) {
            [self performSegueWithIdentifier:@"segueToIntroduction" sender:nil];
        }
    }
}

@end
