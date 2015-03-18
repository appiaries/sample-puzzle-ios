//
//  APISTwitterUtils.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/12/01.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APISSession.h"
#import "APISConstants.h"

@class APISTwitterAPIClient;

/**
 * Twitter連携ユーティリティ
 * @discussion アピアリーズの会員情報とTwitterのアカウントを連携させる際に使用します。
 * @since AppiariesSDK 1.3.0
 */
@interface APISTwitterUtils : NSObject
#pragma mark - Initialization
/** @name Initialization */
/**
 * Twitter連携ユーティリティ初期化
 * @brief Twitter連携用ユーティリティを初期化します。
 * @warning 本クラスの各メソッドを使用する前に initializeWithConsumerKey:consumerSecret: を必ず実行してください。
 * @param consumerKey Twitter コンシューマ・キー
 * @param consumerSecret Twitter コンシューマ・シークレット
 * @since AppiariesSDK 1.3.0
 */
+ (void)initializeWithConsumerKey:(NSString *)consumerKey
                   consumerSecret:(NSString *)consumerSecret;

#pragma mark - Public methods (LogIn)
/** @name Public methods (LogIn) */
/**
 * Twitterアカウントを使用して会員ログインする
 * @brief Twitterアカウントを使用してアプリにします。会員が作成されていない場合は新規作成されます。
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param block コールバック・ブロック
 * @since AppiariesSDK 1.3.0
 */
+ (void)logInWithAutoLogin:(BOOL)autoLogin
                     block:(APISGenericCallbackBlock)block;

/**
 * Twitterアカウントを使用して会員ログインする
 * @brief Twitterアカウントを使用してアプリにします。会員が作成されていない場合は新規作成されます。
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param selector  コールバックハンドラ
 * @since AppiariesSDK 1.3.0
 */
+ (void)logInWithAutoLogin:(BOOL)autoLogin
                    target:(id)target selector:(SEL)selector;

/**
 * Twitterアカウントを使用して会員ログインする
 * @brief Twitterアカウントを使用してアプリにします。会員が作成されていない場合は新規作成されます。
 * @param twitterId Twitter ID (ユーザID)
 * @param screenName スクリーンネーム
 * @param authToken OAuth認証トークン
 * @param authTokenSecret OAuth認証トークン・シークレット
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param block コールバック・ブロック
 * @since AppiariesSDK 1.3.0
 */
+ (void)logInWithTwitterId:(NSString *)twitterId
                screenName:(NSString *)screenName
                 authToken:(NSString *)authToken
           authTokenSecret:(NSString *)authTokenSecret
                 autoLogin:(BOOL)autoLogin
                     block:(APISGenericCallbackBlock)block;

/**
 * Twitterアカウントを使用して会員ログインする
 * @brief Twitterアカウントを使用してアプリにします。会員が作成されていない場合は新規作成されます。
 * @param twitterId Twitter ID (ユーザID)
 * @param screenName スクリーンネーム
 * @param authToken OAuth認証トークン
 * @param authTokenSecret OAuth認証トークン・シークレット
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param selector  コールバックハンドラ
 * @since AppiariesSDK 1.3.0
 */
+ (void)logInWithTwitterId:(NSString *)twitterId
                screenName:(NSString *)screenName
                 authToken:(NSString *)authToken
           authTokenSecret:(NSString *)authTokenSecret
                 autoLogin:(BOOL)autoLogin
                    target:(id)target
                  selector:(SEL)selector;

#pragma mark - Public methods (Misc)
/** @name Public methods (Misc) */
/**
 * Twitter API クライアントを返す
 * @return Twitter API クライアント
 * @since AppiariesSDK 1.3.0
 */
+ (APISTwitterAPIClient *)twitter;

@end