//
//  LoginViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/11/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "LoginViewController.h"
#import "TopViewController.h"
#import "PuzPlayerManager.h"
#import "PuzPlayers.h"
#import "PuzAPIClient.h"

#import "MBProgressHUD.h"

@implementation LoginViewController
@synthesize tfID, tfPassWord, btnLogIn, btnRegist, lbLinkToPass, lbErrMessage, listStage;

- (void)viewDidLoad
{
    [super viewDidLoad];
        
    self.title = @"";
    [[self.btnLogIn layer] setCornerRadius:7.0f];
    [[self.btnLogIn layer] setMasksToBounds:YES];
    
    [[self.btnRegist layer] setCornerRadius:7.0f];
    [[self.btnRegist layer] setMasksToBounds:YES];
    
    //set style link to web to get password.
    [self.lbErrMessage setText:@" "];
    [self setLinkType];
    
    UITapGestureRecognizer *remindGesture = [[UITapGestureRecognizer alloc]
                                   initWithTarget:self
                                   action:@selector(linkToPassWord)];
    
    [lbLinkToPass setUserInteractionEnabled:YES];
    [lbLinkToPass addGestureRecognizer:remindGesture];
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]
                                   initWithTarget:self
                                   action:@selector(dismissKeyboard)];
    
    [self.view addGestureRecognizer:tap];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action method
- (IBAction)logIn:(id)sender
{
    NSLog(@" button Login Click");
    
    if ([self validAccountWithId:tfID.text andPassWord:tfPassWord.text]) {
        //execute after check password
        [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        
        PuzPlayers *playerInfo = [[PuzPlayers alloc] init];
        playerInfo.loginId = tfID.text;
        playerInfo.password = tfPassWord.text;
        
        [[PuzPlayerManager sharedManager] doLogin:playerInfo
                                   WithCompletion:^(NSDictionary *completeBlock){
                                       NSLog(@"log in successful");
                                       [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
                                       
                                       userID = completeBlock[@"user_id"];
                                       [self performSegueWithIdentifier:@"segueLoginToTop" sender:self];
                                       
                                       [[PuzAPIClient sharedClient] saveLogInInfo:completeBlock];
                                   }
                                        failBlock:^(NSError *error){
                                            NSLog(@"Log in fail");
                                            [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
                                            [lbErrMessage setText:error.localizedDescription];
                                   }];
        
    } else {
        [lbErrMessage setText:@"入力された内容に誤りがあります。"];
    }
}

- (IBAction)registNewID:(id)sender
{
    NSLog(@" button Regist Click");
    [self performSegueWithIdentifier:@"segueToRegister" sender:self];
}

#pragma mark - Private method
-  (void)linkToPassWord
{
    NSLog(@"link to web for get the forget password");
    [self performSegueWithIdentifier:@"segueToReminder" sender:self];
}

- (void)setLinkType
{
    UIFont *font = [UIFont fontWithName:@"Hiragino Kaku Gothic ProN W3" size:16];
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:@"→パスワードを忘れた方はこちら"];
    [string addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, string.length)];
    
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor blueColor] range:NSMakeRange(0, string.length)]; //TextColor
    [string addAttribute:NSUnderlineStyleAttributeName value:@(NSUnderlineStyleSingle) range:NSMakeRange(0, string.length)]; //Underline color
    [string addAttribute:NSUnderlineColorAttributeName value:[UIColor blueColor] range:NSMakeRange(0, string.length)]; //TextColor
    
    lbLinkToPass.attributedText =  string;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"segueLoginToTop"]) {
        UINavigationController *navigationController = segue.destinationViewController;
        TopViewController *topViewController = [navigationController viewControllers][0];
        [topViewController setUserID:userID];
        [topViewController setListStage:listStage];
    }
}

- (BOOL)validAccountWithId:(NSString *)strID andPassWord:(NSString *)strPassWord
{
    [lbErrMessage setText:@""];
    tfID.layer.borderColor = [[UIColor blackColor] CGColor];
    tfPassWord.layer.borderColor = [[UIColor blackColor] CGColor];
    tfID.layer.borderWidth = 0;
    tfPassWord.layer.borderWidth = 0;
    
    BOOL retFlag = YES;
    
    //valid do not input ID
    if (strID == nil || [strID length] == 0) {
        NSLog(@"ID is blank");
        tfID.layer.borderColor = [[UIColor redColor] CGColor];
        tfID.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid input length id
    if ([strID length] < 3 || [strID length] > 20) {
        NSLog(@"ID invalid lenght");
        tfID.layer.borderColor = [[UIColor redColor] CGColor];
        tfID.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid do not input password
    if (strPassWord == nil || [strPassWord length] == 0) {
        NSLog(@"password is blank");
        tfPassWord.layer.borderColor = [[UIColor redColor] CGColor];
        tfPassWord.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    //valid input length password
    if ([strPassWord length] < 6 || [strPassWord length] > 20) {
        NSLog(@"Password invalid lenght");
        tfPassWord.layer.borderColor = [[UIColor redColor] CGColor];
        tfPassWord.layer.borderWidth = 1.0;
        retFlag = NO;
    }
    
    return retFlag;
}

- (void)dismissKeyboard
{
    [tfID resignFirstResponder];
    [tfPassWord resignFirstResponder];
}

@end
