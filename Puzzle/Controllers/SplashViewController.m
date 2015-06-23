//
//  SplashViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 14/10/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "SplashViewController.h"
#import "LogInViewController.h"
#import "Stage.h"
#import "Image.h"
#import "PreferenceHelper.h"
#import "Constants.h"

@implementation SplashViewController
{
    NSArray *_stages;
}

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        ABError *err = nil;
        //----------------------------------------
        // Find all stages
        //----------------------------------------
        ABQuery *query = [[Stage query] orderBy:@"order" direction:ABSortASC];
        ABResult *findResult = [baas.db findSynchronouslyWithQuery:query error:&err];
        if (err) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [SVProgressHUD showErrorWithStatus:err.description];
            });
            return;
        }
        _stages = findResult.data;

        // Load stored image's ID list
        NSArray *storedImageIds = [[PreferenceHelper sharedPreference] loadImageIdList];

        NSMutableArray *downloadedImageIds = [@[] mutableCopy];
        for (Stage *stage in _stages) {
            if ([storedImageIds containsObject:stage.image_id]) continue;

            //----------------------------------------
            // Fetch a image for the stage
            //----------------------------------------
            Image *image = [Image image];
            image.ID = stage.image_id;
            ABResult *fetchResult = [baas.file fetchSynchronously:image error:&err];
            if (err == nil) {
                //----------------------------------------
                // Download the image
                //----------------------------------------
                Image *fetched = fetchResult.data;
                ABResult *downloadResult = [fetched downloadSynchronouslyWithError:&err];
                if (err == nil) {
                    NSData *binary = downloadResult.rawData;
                    //----------------------------------------
                    // Cache the image to local storage
                    //----------------------------------------
                    NSString *dir = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
                    NSString *path = [dir stringByAppendingPathComponent:[NSString stringWithFormat:@"%@-%@", fetched.ID, fetched.name]];
                    BOOL success = [binary writeToFile:path atomically:YES];
                    if (success) {
                        [downloadedImageIds addObject:fetched.ID];
                    }
                } else {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [SVProgressHUD showErrorWithStatus:err.description];
                    });
                    return;
                }
            } else {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [SVProgressHUD showErrorWithStatus:err.description];
                });
                return;
            }
        }

        if ([downloadedImageIds count] > 0) {
            [[PreferenceHelper sharedPreference] saveImageIdList:downloadedImageIds];
        }

        dispatch_async(dispatch_get_main_queue(), ^{
            [SVProgressHUD dismiss];

            LogInViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:kLogInViewControllerID];
            vc.stages = _stages;
            UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:vc];
            [self presentViewController:navController animated:NO completion:nil];
        });
    });
}

@end
