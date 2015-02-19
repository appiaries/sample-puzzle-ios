//
//  NSError+AppiariesSDK.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/11.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Appiariesエラードメイン */
static NSString * const kAppiariesSDKErrorDomain = @"com.appiaries.sdk.errorDomain";

extern NSString *APISErrorDescriptionNetworkAccessError;
extern NSString *APISErrorDescriptionInvalidArgumentError;
extern NSString *APISErrorDescription;
extern NSString *APISErrorDescription;
extern NSString *APISErrorDescription;
extern NSString *APISErrorDescription;
extern NSString *APISErrorDescription;
#define kErrorDescriptionNetworkAccessError @"NetworkAccessError occurred."
#define kErrorDescriptionInvalidArgumentError @"InvalidArgumentError occurred. [reason: %@]"
#define kErrorDescriptionInvalidIdError @"InvalidIdError occurred. [reason: %@]"
#define kErrorDescriptionInvalidTokenError @"InvalidTokenError occurred. [reason: %@]"
#define kErrorDescriptionUnprocessableEntityError @"UnprocessableEntityError occurred. [reason: %@]"
#define kErrorDescriptionNoContentError @"NoContentError occurred. [reason: %@]"
#define kErrorDescriptionAuthorizationError @"AuthorizationError occurred. [reason: %@]"


@class APISResponseObject;

/**
 * AppiariesSDK用 NSError 拡張カテゴリ
 * @since AppiariesSDK 1.2.0
 */
@interface NSError (AppiariesSDK)
#pragma mark - Properties
/** @name Properties */
/**
 * 詳細エラーコード
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *detailCode;
/**
 * 詳細エラーコードを含むか (YES:含む)
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic, readonly) BOOL hasDetailCode;

#pragma mark - Extension methods
/** @name Extension methods */
/**
 * 指定イニシャライザ
 * @brief AppiariesSDK用 NSError オブジェクトを生成して返します。
 * @param domain エラードメイン
 * @param code エラーコード
 * @param detailCode 詳細エラーコード
 * @param userInfo エラー情報ディクショナリ
 * @return NSError オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithDomain:(NSString *)domain code:(NSInteger)code detailCode:(NSString *)detailCode userInfo:(NSDictionary *)userInfo;
/**
 * AppiariesSDK用エラーオブジェクト生成
 * @brief AppiariesSDK用エラーオブジェクトを生成して返します。
 * @param response APISResponseObject オブジェクト
 * @return NSError オブジェクト
 * @since AppiariesSDK 1.2.0
 */
+ (id)errorWithAPISResponseObject:(APISResponseObject *)response;

/**
 * AppiariesSDK用エラーオブジェクト生成
 * @brief AppiariesSDK用エラーオブジェクトを生成して返します。
 * @param response APISResponseObject オブジェクト
 * @param description エラー説明
 * @param recoverySuggestion エラー回復ヒント
 * @return NSError オブジェクト
 * @since AppiariesSDK 1.2.0
 */
+ (id)errorWithAPISResponseObject:(APISResponseObject *)response description:(NSString *)description recoverySuggestion:(NSString *)recoverySuggestion;

@end