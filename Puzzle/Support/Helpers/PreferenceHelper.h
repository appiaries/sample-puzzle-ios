//
//  PreferenceHelper.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPSessionManager.h>

@interface PreferenceHelper : NSObject
#pragma mark - Initialization
+ (id)sharedPreference;

#pragma mark - Public methods
- (NSArray *)loadImageIdList;
- (void)saveImageIdList:(NSArray *)imageIdList;

@end
