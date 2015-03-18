//
//  APISTwitterAPIClient.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/12/01.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

/**
 * Twitter API クライアント
 * @since AppiariesSDK 1.3.0
 */
@interface APISTwitterAPIClient : NSObject
#pragma mark - Properties
/** @name Properties */
/**
 * Twitter コンシューマ・キー
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *consumerKey;
/**
 * Twitter コンシューマ・シークレット
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *consumerSecret;
/**
 * Twitter アクセストークン
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *authToken;
/**
 * Twitter トークン・シークレット
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *authTokenSecret;
/**
 * ユーザID (Twitter ID)
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *userId;
/**
 * スクリーンネーム
 * @since AppiariesSDK 1.3.0
 */
@property (nonatomic, copy) NSString *screenName;

#pragma mark - Public methods

/**
 * OAuthによる認証を行いアクセストークンを取得する
 * @brief OAuthによる認証を行いアクセストークンを取得します。
 * @param success 認証成功時のコールバックハンドラ
 * @param failure 認証失敗時のコールバックハンドラ
 * @param cancel 認証キャンセル時のコールバックハンドラ
 * @since AppiariesSDK 1.3.0
 */
- (void)authorizeWithSuccess:(void (^)(void))success failure:(void (^)(NSError *error))failure cancel:(void (^)(void))cancel;

@end
