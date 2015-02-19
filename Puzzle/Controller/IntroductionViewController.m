//
//  IntroductionViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/14/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "IntroductionViewController.h"
#import "InformationManager.h"
#import "PuzInformation.h"
#import "MBProgressHUD.h"

@implementation IntroductionViewController
@synthesize btnBack, btnNext, btnSkip;
@synthesize tvDescription;

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.navigationItem.hidesBackButton = YES;
    index = 0;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [self getListInformation];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Action method
- (IBAction)backPage:(id)sender
{
    if (index > 0) {
        index --;
        PuzInformation *infoAtIndex = listInformation[(NSUInteger)index];
        tvDescription.text = infoAtIndex.content;
        
        self.btnNext.alpha = 1;
        if (index == 0) {
            self.btnBack.alpha = 0;
        }
    }
}

- (IBAction)nextPage:(id)sender
{
    if (index < [listInformation count] - 1) {
        index ++;
        PuzInformation *infoAtIndex = listInformation[(NSUInteger)index];
        tvDescription.text = infoAtIndex.content;
        
        self.btnBack.alpha = 1;
        if (index == [listInformation count] - 1) {
            self.btnNext.alpha = 0;
        }
    }
}

- (IBAction)skipPage:(id)sender
{
    NSLog(@"btn skip Page clicked");
    [self.navigationController popToRootViewControllerAnimated:YES];
}

#pragma mark - Private method
- (void)getListInformation
{
    [[InformationManager sharedManager] getInformationsWithCompletion:^(NSDictionary *information){
        [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
        if (information != nil) {
            NSArray *informations = information[@"_objs"];
            listInformation = [[NSMutableArray alloc]init];
            for (int i = 0; i < [informations count]; i++) {
                PuzInformation *info = [[PuzInformation alloc] initWithDict:informations[(NSUInteger)i]];
                [listInformation addObject:info];
            }
            PuzInformation *infoAtIndex = listInformation[(NSUInteger)index];
            tvDescription.text = infoAtIndex.content;
            
            self.btnBack.alpha = 0;
            if ([listInformation count] == 1) {
                self.btnNext.alpha = 0;
            }
        }
    } failedBlock:^(NSError *block){
        [MBProgressHUD hideAllHUDsForView:self.view animated:NO];
        if (block != nil) {
            NSLog(@"get information failed");
        }
    }];
}

@end
