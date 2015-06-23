//
// Created by Appiaries Corporation on 15/03/17.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABTwitterClient;

/*!
 Twitter サービス

 __See Also__: [アピアリーズドキュメント &raquo; SNS連携](http://docs.appiaries.com/?p=11373)<br/>
 */
@interface ABTwitterService : NSObject
#pragma mark - Initialization
/*! @name Initialization */
/*!
 シングルトン・インスタンスを返す
 @discussion ABTwitterService のシングルトン・インスタンスを返します。
 @return ABTwitterService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;

#pragma mark - Log-In via Twitter
/*! @name Log-In via Twitter */
/*!
 Twitter アカウントを使用してログインする
 @discussion ABTwitterConfig (baas.config.twitter) の設定情報を使用して Twitter へ認証を行い、アプリにログインします。
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logInWithTarget:(id)target selector:(SEL)selector;
/*!
 Twitter アカウントを使用してログインする
 @discussion ABTwitterConfig (baas.config.twitter) の設定情報を使用して Twitter へ認証を行い、アプリにログインします。
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithTarget:(id)target selector:(SEL)selector option:(ABUserLogInOption)option;
/*!
 Twitter アカウントを使用してログインする
 @discussion ABTwitterConfig (baas.config.twitter) の設定情報を使用して Twitter へ認証を行い、アプリにログインします。
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logInWithBlock:(ABResultBlock)block;
/*!
 Twitter アカウントを使用してログインする
 @discussion ABTwitterConfig (baas.config.twitter) の設定情報を使用して Twitter へ認証を行い、アプリにログインします。
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithBlock:(ABResultBlock)block option:(ABUserLogInOption)option;
/*!
 Twitter アカウントを使用してログインする
 @discussion Twitter アカウントの各種情報を使用してアプリにログインします。
 @param twitterId TwitterアカウントのID
 @param screeName Twitterアカウントのスクリーン名
 @param authToken TwitterアカウントのOAuth認証トークン
 @param authTokenSecret TwitterアカウントのOAuth認証トークン・シークレット
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logInWithTwitterId:(NSString *)twitterId screenName:(NSString *)screenName authToken:(NSString *)authToken authTokenSecret:(NSString *)authTokenSecret target:(id)target selector:(SEL)selector;
/*!
 Twitter アカウントを使用してログインする
 @discussion Twitter アカウントの各種情報を使用してアプリにログインします。
 @param twitterId TwitterアカウントのID
 @param screeName Twitterアカウントのスクリーン名
 @param authToken TwitterアカウントのOAuth認証トークン
 @param authTokenSecret TwitterアカウントのOAuth認証トークン・シークレット
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithTwitterId:(NSString *)twitterId screenName:(NSString *)screenName authToken:(NSString *)authToken authTokenSecret:(NSString *)authTokenSecret target:(id)target selector:(SEL)selector option:(ABUserLogInOption)option;
/*!
 Twitter アカウントを使用してログインする
 @discussion Twitter アカウントの各種情報を使用してアプリにログインします。
 @param twitterId TwitterアカウントのID
 @param screeName Twitterアカウントのスクリーン名
 @param authToken TwitterアカウントのOAuth認証トークン
 @param authTokenSecret TwitterアカウントのOAuth認証トークン・シークレット
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logInWithTwitterId:(NSString *)twitterId screenName:(NSString *)screenName authToken:(NSString *)authToken authTokenSecret:(NSString *)authTokenSecret block:(ABResultBlock)block;
/*!
 Twitter アカウントを使用してログインする
 @discussion Twitter アカウントの各種情報を使用してアプリにログインします。
 @param twitterId TwitterアカウントのID
 @param screeName Twitterアカウントのスクリーン名
 @param authToken TwitterアカウントのOAuth認証トークン
 @param authTokenSecret TwitterアカウントのOAuth認証トークン・シークレット
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithTwitterId:(NSString *)twitterId screenName:(NSString *)screenName authToken:(NSString *)authToken authTokenSecret:(NSString *)authTokenSecret block:(ABResultBlock)block option:(ABUserLogInOption)option;
/*!
 Twitter API クライアントを取得する
 @return ABTwitterClient オブジェクト
 */
- (ABTwitterClient *)twitter;

@end