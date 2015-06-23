//
//  Validator.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/27.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABError;


typedef NS_ENUM(NSInteger, ValidationRule) {
    ValidationRuleRequired,
    ValidationRuleEmail,
    ValidationRuleLoginId,
    ValidationRuleNickname,
    ValidationRulePassword,
};

@interface Validator : NSObject
#pragma mark - Public methods
+ (ABError *)validateFor:(NSString *)key value:(id)value rules:(NSArray *)rules ruleArgs:(NSDictionary *)ruleArgs;
@end
