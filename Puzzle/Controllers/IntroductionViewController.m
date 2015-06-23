//
//  IntroductionViewController.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/14/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "IntroductionViewController.h"
#import "Introduction.h"

@implementation IntroductionViewController
{
    NSArray *_introductionList;
    int _index;
}

#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];

    [self setupView];

    //----------------------------------------
    // Find all introduction
    //----------------------------------------
    ABQuery *query = [[Introduction query] orderBy:@"order" direction:ABSortASC];
    [SVProgressHUD showWithMaskType:SVProgressHUDMaskTypeBlack];
    [baas.db findWithQuery:query block:^(ABResult *ret, ABError *err){
        if (err == nil) {
            _introductionList = ret.data;
            if ([_introductionList count] >= _index) {
                Introduction *intro = [_introductionList firstObject];
                _tvDescription.text = intro.content;
            }
            self.btnBack.alpha = 0;
            if ([_introductionList count] == 1) {
                self.btnNext.alpha = 0;
            }
            [SVProgressHUD dismiss];
        } else {
            [SVProgressHUD showErrorWithStatus:err.description maskType:SVProgressHUDMaskTypeBlack];
        }
    }];
}

#pragma mark - Actions
- (IBAction)backPage:(id)sender
{
    if (_index > 0) {
        _index --;
        Introduction *intro = _introductionList[(NSUInteger)_index];
        _tvDescription.text = intro.content;
        
        self.btnNext.alpha = 1;
        if (_index == 0) {
            self.btnBack.alpha = 0;
        }
    }
}

- (IBAction)nextPage:(id)sender
{
    if (_index < [_introductionList count] - 1) {
        _index ++;
        Introduction *intro = _introductionList[(NSUInteger)_index];
        _tvDescription.text = intro.content;
        
        self.btnBack.alpha = 1;
        if (_index == [_introductionList count] - 1) {
            self.btnNext.alpha = 0;
        }
    }
}

- (IBAction)skipPage:(id)sender
{
    [self.navigationController popToRootViewControllerAnimated:YES];
}

#pragma mark - MISC
- (void)setupView
{
    self.navigationItem.hidesBackButton = YES;
    _index = 0;
}

@end
