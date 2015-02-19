//
//  ViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 14/10/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "SplashViewController.h"
#import "PuzAPIClient.h"
#import "LoginViewController.h"
#import "PuzStage.h"
#import "StageManager.h"

@implementation SplashViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    isExitApp = YES;
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(exitApplication)
                                                 name:@"ExitApplication"
                                               object:nil];
    [self getStageList];
}

- (void)getStageList
{
    [[StageManager sharedManager] getStagesWithCompletion:^(NSDictionary *stageInfo){
        if (stageInfo != nil) {
            NSArray *stageInfos = stageInfo[@"_objs"];
            listStage = [[NSMutableArray alloc] init];
            for (int i = 0; i < [stageInfos count]; i++) {
                PuzStage *stage = [[PuzStage alloc] initWithDict:stageInfos[i]];
                [listStage addObject:stage];
            }
            [self sortArrayStage];
            // Save images
            [self saveImageList];
            [self gotoLoginScreen:listStage];
            isExitApp = NO;
        }
    } failedBlock:^(NSError *block){
        if (block != nil) {
            NSLog(@"get player failed");
        }
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)gotoLoginScreen:(NSArray *)arr
{
    LoginViewController *viewController = [self.storyboard instantiateViewControllerWithIdentifier:@"IdentityLoginView"];
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:viewController];
    [viewController setListStage:arr];
    
    [self presentViewController:navController animated:NO completion:nil];
}

//save Image and Image ID List to the local storage
- (void)saveImageList
{
    //get imageId list from server
    NSMutableArray *imgList = [[NSMutableArray alloc] init];
    for (PuzStage *obj in listStage) {
        [imgList addObject:obj.imageId];
    }
    
    //save the down the image list Id to local
    if ([imgList count] > 0) {
        if ([[self getImgIdList] count] < 1) {
            //imageId list is not exist- insert imageId List and image to local storage
            NSUserDefaults *userDefaultObj = [NSUserDefaults standardUserDefaults];
            [userDefaultObj setObject:imgList forKey:@"imgIdList"];
            
            //save down all image to local
            for (NSString *imgId in imgList) {
                NSString *stringURL = [PuzAPIClient getImageFileUrlWithObjectId:imgId];
                NSURL *url = [NSURL URLWithString:stringURL];
                NSData *urlData = [NSData dataWithContentsOfURL:url];
                if (urlData) {
                    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
                    NSString *documentsDirectory = paths[0];
                    NSString *filePath = [NSString stringWithFormat:@"%@/%@", documentsDirectory,[NSString stringWithFormat:@"%@.png",imgId]];
                    [urlData writeToFile:filePath atomically:YES];
                }
            }
            NSLog(@"insert new imageId and image list to local :%lu", (unsigned long)imgList.count);
        } else {
            //imageId list exist check for update.
            NSMutableArray *localImageIdList = [NSMutableArray arrayWithArray:[self getImgIdList]];
            BOOL changeFlg = NO;
            for (NSString *imageId in imgList) {
                if (![localImageIdList containsObject:imageId]) {
                    changeFlg = YES;
                    [localImageIdList addObject:imageId];
                    NSString *stringURL = [PuzAPIClient getImageFileUrlWithObjectId:imageId];
                    NSURL *url = [NSURL URLWithString:stringURL];
                    NSData *urlData = [NSData dataWithContentsOfURL:url];
                    if (urlData) {
                        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
                        NSString *documentsDirectory = paths[0];
                        
                        NSString *filePath = [NSString stringWithFormat:@"%@/%@", documentsDirectory,[NSString stringWithFormat:@"%@.png",imageId]];
                        [urlData writeToFile:filePath atomically:YES];
                    }
                    NSLog(@"update image to localstorage successful");
                }
            }
            
            if (changeFlg) {
                NSUserDefaults *userDefaultObj = [NSUserDefaults standardUserDefaults];
                [userDefaultObj removeObjectForKey:@"imgIdList"];
                [userDefaultObj setObject:localImageIdList forKey:@"imgIdList"];
                NSLog(@"update new imageId list to localstorage successful");
            }
        }
    } else {
        NSLog(@" cannot get image id list or image id list is null");
    }
}

//get image list ID from local storage
- (NSArray *)getImgIdList
{
    NSArray *imgListFromLocal = [[NSArray alloc] init];
    NSUserDefaults *userDefaultObj = [NSUserDefaults standardUserDefaults];
    imgListFromLocal = [[NSMutableArray alloc] initWithArray: [userDefaultObj objectForKey:@"imgIdList"]];
    NSLog(@"image list load from local :%lu", (unsigned long)imgListFromLocal.count);
    
    return imgListFromLocal;
}

- (void)sortArrayStage
{
    NSSortDescriptor *sortDescriptor1 = [[NSSortDescriptor alloc] initWithKey:@"stageId" ascending:YES];
    NSArray *sortDescriptors = [@[sortDescriptor1] mutableCopy];
    NSArray *array = [NSArray arrayWithArray:listStage];
    array = [array sortedArrayUsingDescriptors:sortDescriptors];
    listStage = [NSMutableArray arrayWithArray:array];
}

- (void)exitApplication
{
    if (isExitApp) {
        exit(0);
    }
}

@end
