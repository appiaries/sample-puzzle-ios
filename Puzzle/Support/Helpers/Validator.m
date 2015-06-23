//
//  Validator.m
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/27.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import "Validator.h"


@implementation Validator

#pragma mark - Public methods
+ (ABError *)validateFor:(NSString *)key value:(id)value rules:(NSArray *)rules ruleArgs:(NSDictionary *)ruleArgs
{
    for (id r in rules) {
        ValidationRule rule = (ValidationRule)[r intValue];

        switch (rule) {
            case ValidationRuleRequired:
                if (!value || [value isEqualToString:@""] || [value isEqual:[NSNull null]]) {
                    NSString *msg = [Validator messageForRule:ValidationRuleRequired ruleArgs:ruleArgs
                                                 defaultMessage:@"Insufficient parameter. [param: %@]"];
                    return [ABError errorWithDomain:@"com.appiaries" code:10001 userInfo:@{
                            NSLocalizedDescriptionKey : [NSString stringWithFormat:msg, key],
                    }];
                }
                break;
            case ValidationRuleEmail: {
                NSPredicate *emailPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}"];
                if (![emailPredicate evaluateWithObject:value]) {
                    NSString *msg = [Validator messageForRule:ValidationRuleEmail ruleArgs:ruleArgs
                                               defaultMessage:@"Invalid email address. [param: %@]"];
                    return [ABError errorWithDomain:@"com.appiaries" code:10001 userInfo:@{
                            NSLocalizedDescriptionKey : [NSString stringWithFormat:msg, key],
                    }];
                }
                break;
            }
            case ValidationRuleLoginId: {
                int len = [value length];
                if (4 > len || len > 20) {
                    NSString *msg = [Validator messageForRule:ValidationRuleLoginId ruleArgs:ruleArgs
                                               defaultMessage:@"Invalid loginId. [param: %@]"];
                    return [ABError errorWithDomain:@"com.appiaries" code:10001 userInfo:@{
                            NSLocalizedDescriptionKey : [NSString stringWithFormat:msg, key],
                    }];
                }
                break;
            }
            case ValidationRuleNickname: {
                int len = [value length];
                if (4 > len || len > 20) {
                    NSString *msg = [Validator messageForRule:ValidationRuleNickname ruleArgs:ruleArgs
                                               defaultMessage:@"Invalid nickname. [param: %@]"];
                    return [ABError errorWithDomain:@"com.appiaries" code:10001 userInfo:@{
                            NSLocalizedDescriptionKey : [NSString stringWithFormat:msg, key],
                    }];
                }
                break;
            }
            case ValidationRulePassword: {
                int len = [value length];
                if (8 > len || len > 20) {
                    NSString *msg = [Validator messageForRule:ValidationRulePassword ruleArgs:ruleArgs
                                               defaultMessage:@"Invalid password. [param: %@]"];
                    return [ABError errorWithDomain:@"com.appiaries" code:10001 userInfo:@{
                            NSLocalizedDescriptionKey : [NSString stringWithFormat:msg, key],
                    }];
                }
                break;
            }
            default:
                break;
        }
    }
    return nil;
}

#pragma mark - MISC
+ (NSString *)messageForRule:(ValidationRule)rule ruleArgs:(NSDictionary *)ruleArgs
{
    return [Validator messageForRule:rule ruleArgs:ruleArgs defaultMessage:nil];
}
+ (NSString *)messageForRule:(ValidationRule)rule ruleArgs:(NSDictionary *)ruleArgs defaultMessage:(NSString *)defaultMessage
{
    if (ruleArgs) {
        NSDictionary *args = ruleArgs[@(rule)];
        if (args) {
            NSString *msg = args[@"msg"];
            if (msg && ![msg isEqualToString:@""] && ![msg isEqual:[NSNull null]]) {
                return msg;
            }
        }
    }
    return defaultMessage;
}

@end