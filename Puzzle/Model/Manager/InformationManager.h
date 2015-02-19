//
//  InformationManager.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/19/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PuzInformation;

@interface InformationManager : NSObject

@property (readonly, nonatomic) PuzInformation *information;

+ (InformationManager *)sharedManager;
- (void)getInformationsWithCompletion:(void(^)(NSDictionary *))completeBlock failedBlock:(void (^)(NSError *))block;

@end
