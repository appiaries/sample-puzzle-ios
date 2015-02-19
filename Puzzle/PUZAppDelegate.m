//
//  AppDelegate.m
//  Puzzle
//
//  Created by Appiaries Corporation on 14/10/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PUZAppDelegate.h"
#import <UIKit/UIKit.h>
#import "SplashViewController.h"

@implementation PUZAppDelegate

#pragma mark - Application Lifecycle
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle: nil];
    SplashViewController *mainController =
            (SplashViewController *)[mainStoryboard instantiateViewControllerWithIdentifier:@"SplashIdentity"];
    
    self.window.rootViewController = mainController;
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"ExitApplication" object:self];
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
