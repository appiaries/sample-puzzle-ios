//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;
@class ABUser;
@class ABQuery;

/*!
 ユーザ・サービス
 
 __See Also__: [アピアリーズドキュメント &raquo; 会員管理](http://docs.appiaries.com/?p=30)
 */
@interface ABUserService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABUserService のシングルトン・インスタンスを返す
 @return ABUserService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;
/*!
 ユーザ・オブジェクトを生成する
 @return ABUser オブジェクト (またはその派生オブジェクト)
 */
- (ABUser *)user;
/*!
 ユーザ・オブジェクトを生成する
 @param collectionID コレクションID
 @return ABUser オブジェクト (またはその派生オブジェクト)
 */
- (ABUser *)userWithCollectionID:(NSString *)collectionID;
/*!
 ユーザ・オブジェクトを生成する
 @param dictionary ディクショナリ形式のJSONデータ
 @discussion 引数ディクショナリのキー名などについては、[アピアリーズドキュメント](http://docs.appiaries.com/)の__REST API リファレンス__を参照ください。
 @return ABUser オブジェクト (またはその派生オブジェクト)
 */
- (ABUser *)userWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Sign-Up
/*! @name Sign-Up */
/*!
 サインアップする
 @discussion 同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)signUpSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 サインアップする
 @discussion 同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserSignUpOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)signUpSynchronously:(ABUser *)user option:(ABUserSignUpOption)option error:(ABError **)error;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 */
- (Async)signUp:(ABUser *)user;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserSignUpOption オプション
 */
- (Async)signUp:(ABUser *)user option:(ABUserSignUpOption)option;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)signUp:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserSignUpOption オプション
 */
- (Async)signUp:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserSignUpOption)option;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)signUp:(ABUser *)user block:(ABResultBlock)block;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user サインアップするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserSignUpOption オプション
 */
- (Async)signUp:(ABUser *)user block:(ABResultBlock)block option:(ABUserSignUpOption)option;

#pragma mark - Log-In with User
/*! @name Log-In with User */
/*!
 ログインする
 @discussion 同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 ログインする
 @discussion 同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserLogInOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInSynchronously:(ABUser *)user option:(ABUserLogInOption)option error:(ABError **)error;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 */
- (Async)logIn:(ABUser *)user;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserLogInOption オプション
 */
- (Async)logIn:(ABUser *)user option:(ABUserLogInOption)option;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logIn:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogInOption オプション
 */
- (Async)logIn:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserLogInOption)option;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logIn:(ABUser *)user block:(ABResultBlock)block;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param user ログインするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogInOption オプション
 */
- (Async)logIn:(ABUser *)user block:(ABResultBlock)block option:(ABUserLogInOption)option;

#pragma mark - Log-In as Anonymous
/*! @name Log-In as Anonymous */
/*!
 ログインする (匿名)
 @discussion 同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInAsAnonymousSynchronouslyWithError:(ABError **)error;
/*!
 ログインする (匿名)
 @discussion 同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserAnonymousLogInOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInAsAnonymousSynchronouslyWithOption:(ABUserLogInOption)option error:(ABError **)error;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 */
- (Async)logInAsAnonymous;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserAnonymousLogInOption オプション
 */
- (Async)logInAsAnonymousWithOption:(ABUserLogInOption)option;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logInAsAnonymousWithTarget:(id)target selector:(SEL)selector;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserAnonymousLogInOption オプション
 */
- (Async)logInAsAnonymousWithTarget:(id)target selector:(SEL)selector option:(ABUserLogInOption)option;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logInAsAnonymousWithBlock:(ABResultBlock)block;
/*!
 ログインする (匿名)
 @discussion 非同期モードで匿名ログインします。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserAnonymousLogInOption オプション
 */
- (Async)logInAsAnonymousWithBlock:(ABResultBlock)block option:(ABUserLogInOption)option;

#pragma mark - Log-Out
/*! @name Log-Out */
/*!
 ログアウトする
 @discussion 同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logOutSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 ログアウトする
 @discussion 同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param option ABUserLogOutOption オプション
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logOutSynchronously:(ABUser *)user option:(ABUserLogOutOption)option error:(ABError **)error;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 */
- (Async)logOut:(ABUser *)user;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserLogOutOption オプション
 */
- (Async)logOut:(ABUser *)user option:(ABUserLogOutOption)option;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logOut:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogOutOption オプション
 */
- (Async)logOut:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserLogOutOption)option;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logOut:(ABUser *)user block:(ABResultBlock)block;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param user ログアウトするユーザの ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogOutOption オプション
 */
- (Async)logOut:(ABUser *)user block:(ABResultBlock)block option:(ABUserLogOutOption)option;

#pragma mark - Save
/*! @name Save */
/*!
 ユーザ・オブジェクトを保存する
 @discussion 同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABUser *)user option:(ABUserSaveOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 */
- (Async)save:(ABUser *)user;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserSaveOption オプション
 */
- (Async)save:(ABUser *)user option:(ABUserSaveOption)option;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)save:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserSaveOption オプション
 */
- (Async)save:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserSaveOption)option;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)save:(ABUser *)user block:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param user 保存する ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserSaveOption オプション
 */
- (Async)save:(ABUser *)user block:(ABResultBlock)block option:(ABUserSaveOption)option;

#pragma mark - Save (Objects)
/*! @name Save (Objects) */
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @return ABResult オブジェクト
 */
//- (ABResult *)saveAllSynchronously:(NSArray *)users;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABUserSaveOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)saveAllSynchronously:(NSArray *)users option:(ABUserSaveOption)option;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 */
//- (Async)saveAll:(NSArray *)users;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABUserSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)users option:(ABUserSaveOption)option;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)saveAll:(NSArray *)users target:(id)target selector:(SEL)selector;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)users target:(id)target selector:(SEL)selector option:(ABUserSaveOption)option;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)saveAll:(NSArray *)users block:(ABResultBlock)block;
/*!
 すべてのユーザ・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param users 保存する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)users block:(ABResultBlock)block option:(ABUserSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABUser *)user option:(ABUserDeleteOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 */
- (Async)delete:(ABUser *)user;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserDeleteOption オプション
 */
- (Async)delete:(ABUser *)user option:(ABUserDeleteOption)option;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)delete:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserDeleteOption オプション
 */
- (Async)delete:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserDeleteOption)option;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)delete:(ABUser *)user block:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param user 削除する ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserDeleteOption オプション
 */
- (Async)delete:(ABUser *)user block:(ABResultBlock)block option:(ABUserDeleteOption)option;

#pragma mark - Delete (Objects)
/*! @name Delete (Objects) */
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteAllSynchronously:(NSArray *)users;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABUserDeleteOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteAllSynchronously:(NSArray *)users option:(ABUserDeleteOption)option;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 */
//- (Async)deleteAll:(NSArray *)users;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)users option:(ABUserDeleteOption)option;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)deleteAll:(NSArray *)users target:(id)target selector:(SEL)selector;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)users target:(id)target selector:(SEL)selector option:(ABUserDeleteOption)option;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)deleteAll:(NSArray *)users block:(ABResultBlock)block;
/*!
 すべてのユーザ・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param users 削除する ABUser オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)users block:(ABResultBlock)block option:(ABUserDeleteOption)option;

#pragma mark - Delete (Query)
/*! @name Delete (Query) */
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABUserDeleteOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query option:(ABUserDeleteOption)option;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 */
//- (Async)deleteWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query option:(ABUserDeleteOption)option;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABUserDeleteOption)option;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするユーザ・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABUserDeleteOption)option;

#pragma mark - Fetch
/*! @name Fetch */
/*!
 ユーザ・オブジェクトを取得する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABUser *)user error:(ABError **)error;
/*!
 ユーザ・オブジェクトを取得する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param option ABUserFetchOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABUser *)user option:(ABUserFetchOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトを取得する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)fetch:(ABUser *)user target:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトを取得する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserFetchOption オプション
 */
- (Async)fetch:(ABUser *)user target:(id)target selector:(SEL)selector option:(ABUserFetchOption)option;
/*!
 ユーザ・オブジェクトを取得する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)fetch:(ABUser *)user block:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトを取得する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param user ABUser オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserFetchOption オプション
 */
- (Async)fetch:(ABUser *)user block:(ABResultBlock)block option:(ABUserFetchOption)option;

#pragma mark - Find (Query)
/*! @name Find (Query) */
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @return ABResult オブジェクト
 */
//- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @param option ABUserFindOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query option:(ABUserFindOption)option;
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserFindOption オプション
 */
//- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABUserFindOption)option;
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするユーザ・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするユーザ・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; 会員を検索する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserFindOption オプション
 */
//- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABUserFindOption)option;

#pragma mark - Verify Email
/*! @name Verify Email */
/*!
 本人確認メール送信をリクエストする
 @discussion 同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)verifyEmailSynchronously:(NSString *)email error:(ABError **)error;
/*!
 本人確認メール送信をリクエストする
 @discussion 同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param option ABUserVerifyEmailOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)verifyEmailSynchronously:(NSString *)email option:(ABUserVerifyEmailOption)option error:(ABError **)error;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 */
- (Async)verifyEmail:(NSString *)email;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param option ABUserVerifyEmailOption オプション
 */
- (Async)verifyEmail:(NSString *)email option:(ABUserVerifyEmailOption)option;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)verifyEmail:(NSString *)email target:(id)target selector:(SEL)selector;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserVerifyEmailOption オプション
 */
- (Async)verifyEmail:(NSString *)email target:(id)target selector:(SEL)selector option:(ABUserVerifyEmailOption)option;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)verifyEmail:(NSString *)email block:(ABResultBlock)block;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param email 本人確認メールの宛先メールアドレス
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserVerifyEmailOption オプション
 */
- (Async)verifyEmail:(NSString *)email block:(ABResultBlock)block option:(ABUserVerifyEmailOption)option;

#pragma mark - Reset Password
/*! @name Reset Password */
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetPasswordForEmailSynchronously:(NSString *)email error:(ABError **)error;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param option ABUserResetPasswordOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetPasswordForEmailSynchronously:(NSString *)email option:(ABUserResetPasswordOption)option error:(ABError **)error;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 */
- (Async)resetPasswordForEmail:(NSString *)email;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordForEmail:(NSString *)email option:(ABUserResetPasswordOption)option;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)resetPasswordForEmail:(NSString *)email target:(id)target selector:(SEL)selector;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordForEmail:(NSString *)email target:(id)target selector:(SEL)selector option:(ABUserResetPasswordOption)option;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)resetPasswordForEmail:(NSString *)email block:(ABResultBlock)block;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; 会員のパスワードをリセットする]()
 @param email パスワード再設定メールの宛先メールアドレス
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordForEmail:(NSString *)email block:(ABResultBlock)block option:(ABUserResetPasswordOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 ログイン中か (YES=ログイン中)
 */
- (BOOL)isLoggedIn;
/*!
 匿名ユーザとしてログイン中か (YES=ログイン中)
 */
- (BOOL)isLoggedInAsAnonymous;
/*!
 Twitterアカウントを利用してログイン中か (YES=ログイン中)
 */
- (BOOL)isLoggedInViaTwitter;
/*!
 Facebookアカウントを利用してログイン中か (YES=ログイン中)
 */
- (BOOL)isLoggedInViaFacebook;

@end