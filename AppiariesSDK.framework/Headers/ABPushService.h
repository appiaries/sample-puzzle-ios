//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABPopoverWebViewDelegate.h>
#import <AppiariesSDK/ABConstants.h>

@class ABPushMessage;
@class ABResult;
@protocol ABPopoverWebViewDelegate;
@protocol ABWebViewSupport;

/*!
 プッシュ通知サービス
 
 __See Also__: [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=130)<br/>
 */
@interface ABPushService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABPushService のシングルトン・インスタンスを返す
 @return ABPushService のシングルトン・インスタンス
*/
+ (instancetype)sharedService;
/*!
 プッシュ通知メッセージ・オブジェクトを生成する
 @discussion 新しいプッシュ通知メッセージ・オブジェクトのインスタンスを生成します。
 @return ABPushMessage オブジェクト (またはその派生オブジェクト)
 */
- (ABPushMessage *)message;
/*!
 プッシュ通知メッセージ・オブジェクトを生成する
 @discussion 新しいプッシュ通知メッセージ・オブジェクトのインスタンスを生成します。
 @param collectionID コレクションID
 @return ABPushMessage オブジェクト (またはその派生オブジェクト)
 */
- (ABPushMessage *)messageWithCollectionID:(NSString *)collectionID;
/*!
 プッシュ通知メッセージ・オブジェクトを生成する
 @discussion 新しいプッシュ通知メッセージ・オブジェクトのインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABPushMessage オブジェクト (またはその派生オブジェクト)
 */
- (ABPushMessage *)messageWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Open Message
/*! @name Open Message */
/*!
 プッシュ通知メッセージを開封する
 @discussion 同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)openMessageSynchronously:(ABPushMessage *)message error:(ABError **)error;
/*!
 プッシュ通知メッセージを開封する
 @discussion 同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param option ABPushMessageOpenOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)openMessageSynchronously:(ABPushMessage *)message option:(ABPushMessageOpenOption)option error:(ABError **)error;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 */
- (Async)openMessage:(ABPushMessage *)message;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openMessage:(ABPushMessage *)message option:(ABPushMessageOpenOption)option;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)openMessage:(ABPushMessage *)message target:(id)target selector:(SEL)selector;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openMessage:(ABPushMessage *)message target:(id)target selector:(SEL)selector option:(ABPushMessageOpenOption)option;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)openMessage:(ABPushMessage *)message block:(ABResultBlock)block;
/*!
 プッシュ通知メッセージを開封する
 @discussion 非同期モードでプッシュ通知メッセージを開封します。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param message 開封する ABPushMessage オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openMessage:(ABPushMessage *)message block:(ABResultBlock)block option:(ABPushMessageOpenOption)option;

#pragma mark - Handle Notification
/*! @name Handle Notification */
/*!
 プッシュ通知を捕捉する
 @discussion アプリ内でプッシュ通知を捕捉し、適切な方法でアプリ利用者に通知メッセージを表示します。
 @see [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=40)
 @param userInfo プッシュ通知情報ディクショナリ
 @return YES: 引数ディクショナリにアピアリーズ BaaS で管理するプッシュ通知情報が含まれており、かつ、それを表示する方法が見つかった場合
 */
- (BOOL)handlePushIfNeeded:(NSDictionary *)userInfo;
/*!
 プッシュ通知を捕捉する
 @discussion アプリ内でプッシュ通知を捕捉し、適切な方法でアプリ利用者に通知メッセージを表示します。
 @see [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=40)
 @param userInfo プッシュ通知情報ディクショナリ
 @param option ABPushViewOption オプション
 @return YES: 引数ディクショナリにアピアリーズ BaaS で管理するプッシュ通知情報が含まれており、かつ、それを表示する方法が見つかった場合
 */
- (BOOL)handlePushIfNeeded:(NSDictionary *)userInfo option:(ABHandlePushOption)option;
/*!
 プッシュ通知を捕捉する
 @discussion アプリ内でプッシュ通知を捕捉し、適切な方法でアプリ利用者に通知メッセージを表示します。
 @see [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=40)
 @param userInfo プッシュ通知情報ディクショナリ
 @param viewController URLが指定されていた場合にWebコンテンツを表示するビュー・コントローラ
 @return YES: 引数ディクショナリにアピアリーズ BaaS で管理するプッシュ通知情報が含まれており、かつ、それを表示する方法が見つかった場合
 */
- (BOOL)handlePushIfNeeded:(NSDictionary *)userInfo viewController:(UIViewController<ABWebViewSupport> *)viewController;
/*!
 プッシュ通知を捕捉する
 @discussion アプリ内でプッシュ通知を捕捉し、適切な方法でアプリ利用者に通知メッセージを表示します。
 @see [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=40)
 @param userInfo プッシュ通知情報ディクショナリ
 @param viewController URLが指定されていた場合にWebコンテンツを表示するビュー・コントローラ
 @param option ABPushViewOption オプション
 @return YES: 引数ディクショナリにアピアリーズ BaaS で管理するプッシュ通知情報が含まれており、かつ、それを表示する方法が見つかった場合
 */
- (BOOL)handlePushIfNeeded:(NSDictionary *)userInfo viewController:(UIViewController <ABWebViewSupport> *)viewController option:(ABHandlePushOption)option;

@end
