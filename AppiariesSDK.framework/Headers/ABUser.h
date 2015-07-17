//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABQuery;
@class ABACL;
@class ABModel;
@protocol ABManagedProtocol;

/*!
 ユーザ・モデル
 @discussion アプリ内のユーザを表現するモデルクラスです。<br>
 コントロールパネル上の「会員管理」で管理するユーザと連動します。
 
 __See Also__: [アピアリーズドキュメント &raquo; 会員管理](http://docs.appiaries.com/?p=30)
 */
@interface ABUser : ABModel <ABManagedProtocol>
#pragma mark - Properties
/*! @name Properties */
// **RESERVED** *!
// アクセス制御リスト
// */
//@property (strong, nonatomic) ABACL *ACL;
/*!
 ログインID
 */
@property (strong, nonatomic) NSString *loginId;
/*!
 メールアドレス
 */
@property (strong, nonatomic) NSString *email;
/*!
 メールによる本人確認が済んでいるか (YES=済んでいる)
 */
@property (nonatomic) BOOL emailVerified;
/*!
 ログイン・パスワード
 */
@property (strong, nonatomic) NSString *password;
/*!
 認証データ
 */
@property (strong, nonatomic) NSDictionary *authData;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ユーザ・オブジェクトを生成する
 @return ABUser オブジェクト
 */
+ (instancetype)user;
/*!
 ユーザ・オブジェクトを生成する
 @param collectionID コレクションID
 @return ABUser オブジェクト
 */
+ (instancetype)userWithCollectionID:(NSString *)collectionID;
/*!
 ユーザ・オブジェクトを生成する
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABUser オブジェクト
 */
+ (instancetype)userWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Sing-Up
/*! @name Sing-Up */
/*!
 サインアップする
 @discussion 同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)signUpSynchronouslyWithError:(ABError **)error;
/*!
 サインアップする
 @discussion 同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserSignUpOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)signUpSynchronouslyWithOption:(ABUserSignUpOption)option error:(ABError **)error;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 */
- (Async)signUp;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserSignUpOption オプション
 */
- (Async)signUpWithOption:(ABUserSignUpOption)option;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)signUpWithTarget:(id)target selector:(SEL)selector;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserSignUpOption オプション
 */
- (Async)signUpWithTarget:(id)target selector:(SEL)selector option:(ABUserSignUpOption)option;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)signUpWithBlock:(ABResultBlock)block;
/*!
 サインアップする
 @discussion 非同期モードでサインアップ(ユーザ登録＋ログイン)します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserSignUpOption オプション
 */
- (Async)signUpWithBlock:(ABResultBlock)block option:(ABUserSignUpOption)option;

#pragma mark - Log-In
/*! @name Log-In */
/*!
 ログインする
 @discussion 同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInSynchronouslyWithError:(ABError **)error;
/*!
 ログインする
 @discussion 同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserLogInOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logInSynchronouslyWithOption:(ABUserLogInOption)option error:(ABError **)error;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 */
- (Async)logIn;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithOption:(ABUserLogInOption)option;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logInWithTarget:(id)target selector:(SEL)selector;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithTarget:(id)target selector:(SEL)selector option:(ABUserLogInOption)option;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logInWithBlock:(ABResultBlock)block;
/*!
 ログインする
 @discussion 非同期モードでログインします。
 @see [アピアリーズドキュメント &raquo; ログインする](http://docs.appiaries.com/?p=1190)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogInOption オプション
 */
- (Async)logInWithBlock:(ABResultBlock)block option:(ABUserLogInOption)option;

#pragma mark - Log-In As Anonymous
/*! @name Log-In As Anonymous */
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
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logOutSynchronouslyWithError:(ABError **)error;
/*!
 ログアウトする
 @discussion 同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param option ABUserLogOutOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)logOutSynchronouslyWithOption:(ABUserLogOutOption)option error:(ABError **)error;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 */
- (Async)logOut;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param option ABUserLogOutOption オプション
 */
- (Async)logOutWithOption:(ABUserLogOutOption)option;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)logOutWithTarget:(id)target selector:(SEL)selector;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserLogOutOption オプション
 */
- (Async)logOutWithTarget:(id)target selector:(SEL)selector option:(ABUserLogOutOption)option;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)logOutWithBlock:(ABResultBlock)block;
/*!
 ログアウトする
 @discussion 非同期モードでログアウトします。
 @see [アピアリーズドキュメント &raquo; ログアウトする](http://docs.appiaries.com/?p=1200)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserLogOutOption オプション
 */
- (Async)logOutWithBlock:(ABResultBlock)block option:(ABUserLogOutOption)option;

#pragma mark - Save
/*! @name Save */
/*!
 ユーザ・オブジェクトを保存する
 @discussion 同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithError:(ABError **)error;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param option ABUserSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithOption:(ABUserSaveOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 */
- (Async)save;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param option ABUserSaveOption オプション
 */
- (Async)saveWithOption:(ABUserSaveOption)option;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserSaveOption オプション
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector option:(ABUserSaveOption)option;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)saveWithBlock:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトを保存する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; 会員を登録する](http://docs.appiaries.com/?p=1150)
 @see [アピアリーズドキュメント &raquo; 会員を更新する](http://docs.appiaries.com/?p=1160)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserSaveOption オプション
 */
- (Async)saveWithBlock:(ABResultBlock)block option:(ABUserSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithError:(ABError **)error;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param option ABUserDeleteOption オブション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithOption:(ABUserDeleteOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 */
- (Async)delete;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param option ABUserDeleteOption オブション
 */
- (Async)deleteWithOption:(ABUserDeleteOption)option;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserDeleteOption オブション
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector option:(ABUserDeleteOption)option;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteWithBlock:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトを削除する
 @discussion 非同期モードでユーザ・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; 会員を削除する](http://docs.appiaries.com/?p=1170)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserDeleteOption オブション
 */
- (Async)deleteWithBlock:(ABResultBlock)block option:(ABUserDeleteOption)option;

#pragma mark - Refresh
/*! @name Refresh */
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)refreshSynchronouslyWithError:(ABError **)error;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param option ABUserRefreshOption オブション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)refreshSynchronouslyWithOption:(ABUserRefreshOption)option error:(ABError **)error;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 */
- (Async)refresh;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param option ABUserRefreshOption オブション
 */
- (Async)refreshWithOption:(ABUserRefreshOption)option;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserRefreshOption オブション
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector option:(ABUserRefreshOption)option;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)refreshWithBlock:(ABResultBlock)block;
/*!
 ユーザ・オブジェクトをリフレッシュする
 @discussion 非同期モードでユーザ・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; 会員情報を取得する](http://docs.appiaries.com/?p=1180)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserRefreshOption オブション
 */
- (Async)refreshWithBlock:(ABResultBlock)block option:(ABUserRefreshOption)option;

#pragma mark - Verify Email
/*! @name Verify Email */
/*!
 本人確認メール送信をリクエストする
 @discussion 同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)verifyEmailSynchronouslyWithError:(ABError **)error;
/*!
 本人確認メール送信をリクエストする
 @discussion 同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param option ABUserResetPasswordOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)verifyEmailSynchronouslyWithOption:(ABUserVerifyEmailOption)option error:(ABError **)error;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 */
- (Async)verifyEmail;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param option ABUserResetPasswordOption オプション
 */
- (Async)verifyEmailWithOption:(ABUserVerifyEmailOption)option;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)verifyEmailWithTarget:(id)target selector:(SEL)selector;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserResetPasswordOption オプション
 */
- (Async)verifyEmailWithTarget:(id)target selector:(SEL)selector option:(ABUserVerifyEmailOption)option;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)verifyEmailWithBlock:(ABResultBlock)block;
/*!
 本人確認メール送信をリクエストする
 @discussion 非同期モードで本人確認メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; メールアドレス確認通知を依頼する](http://docs.appiaries.com/?p=12891)
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserResetPasswordOption オプション
 */
- (Async)verifyEmailWithBlock:(ABResultBlock)block option:(ABUserVerifyEmailOption)option;

#pragma mark - Reset Password
/*! @name Reset Password */
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetPasswordSynchronouslyWithError:(ABError **)error;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param option ABUserResetPasswordOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetPasswordSynchronouslyWithOption:(ABUserResetPasswordOption)option error:(ABError **)error;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 */
- (Async)resetPassword;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでユーザのパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordWithOption:(ABUserResetPasswordOption)option;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)resetPasswordWithTarget:(id)target selector:(SEL)selector;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordWithTarget:(id)target selector:(SEL)selector option:(ABUserResetPasswordOption)option;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)resetPasswordWithBlock:(ABResultBlock)block;
/*!
 パスワード再設定メール送信をリクエストする
 @discussion 非同期モードでパスワード再設定メール送信をリクエストします。
 @see [アピアリーズドキュメント &raquo; パスワード再設定メール送信をリクエストする]()
 @param block ABResultBlock コールバック・ブロック
 @param option ABUserResetPasswordOption オプション
 */
- (Async)resetPasswordWithBlock:(ABResultBlock)block option:(ABUserResetPasswordOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 ユーザは "locked" 状態か (YES="locked"状態)
 @see [アピアリーズドキュメント &raquo; アカウントロック機能](http://docs.appiaries.com/?p=1140)
 */
- (BOOL)isLocked;
/*!
 ユーザは "locking" 状態か (YES="locking"状態)
 @see [アピアリーズドキュメント &raquo; アカウントロック機能](http://docs.appiaries.com/?p=1140)
 */
- (BOOL)isLocking;
/*!
 クエリオブジェクトを返す
 @discussion ユーザ・オブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end