//
//  PreferenceHelper.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "PreferenceHelper.h"

static NSString *const kPreferenceImageIdListKey = @"puzzle.image_id_list";

@implementation PreferenceHelper

#pragma mark - Initialization
+ (instancetype)sharedPreference
{
    static PreferenceHelper *_sharedPreference = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedPreference = [[PreferenceHelper alloc] initSharedPreference];
    });
    return _sharedPreference;
}

- (instancetype)initSharedPreference
{
    if (self = [super init]) { }
    return self;
}

- (id)init {
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

#pragma mark - Public methods
- (NSArray *)loadImageIdList {
    return [[NSUserDefaults standardUserDefaults] objectForKey:kPreferenceImageIdListKey];
}

- (void)saveImageIdList:(NSArray *)imageIdList {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:imageIdList forKey:kPreferenceImageIdListKey];
}

@end
