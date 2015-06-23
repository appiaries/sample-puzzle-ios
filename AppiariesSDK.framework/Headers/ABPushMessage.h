//
// Created by Appiaries Corporation on 2015/03/10.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABDevice;
@class ABModel;
@protocol ABManagedProtocol;

/*!
 プッシュ通知メッセージ・モデル
 @discussion プッシュ通知メッセージを表現するモデルクラスです。

 __See Also__: [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=130)<br/>
*/
@interface ABPushMessage : ABModel <ABManagedProtocol>
#pragma mark - Properties
/*! @name Properties */
/*!
 プッシュ通知を受信したデバイス
 */
@property (strong, nonatomic) ABDevice *device;
/*!
 プッシュ通知ID
 */
@property (nonatomic) long long pushId;
/*!
 プラットフォーム
 @discussion メッセージを送信するプラットフォームを指定します。
 */
@property (nonatomic) ABPlatform platform;
/*!
 バッヂ
 */
@property (nonatomic) int badge;
/*!
 再生サウンド
 @discussion 通知受信時に再生するサウンドを指定します。
 */
@property (strong, nonatomic) NSString *sound;
/*!
 メッセージ
 */
@property (strong, nonatomic) NSString *message;
/*!
 URL
 @discussion リッチプッシュ通知を送信する場合に表示させるWebコンテンツのURLを指定します。
 */
@property (strong, nonatomic) NSString *url;
/*!
 アクション
 @warning NOT YET IMPLEMENTED
 */
@property (strong, nonatomic) NSString *action;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABPushMessage インスタンス
 */
+ (instancetype)message;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABPushMessage インスタンス
 */
+ (instancetype)messageWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABPushMessage インスタンス
 */
+ (instancetype)messageWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Open
/*! @name Open */
/*!
 メッセージを開封する
 @discussion 同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)openSynchronouslyWithError:(ABError **)error;
/*!
 メッセージを開封する
 @discussion 同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param option ABPushMessageOpenOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)openSynchronouslyWithOption:(ABPushMessageOpenOption)option error:(ABError **)error;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 */
- (Async)open;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openWithOption:(ABPushMessageOpenOption)option;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)openWithTarget:(id)target selector:(SEL)selector;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openWithTarget:(id)target selector:(SEL)selector option:(ABPushMessageOpenOption)option;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)openWithBlock:(ABResultBlock)block;
/*!
 メッセージを開封する
 @discussion 非同期モードでメッセージを開封します。このタイミングで、サーバにメッセージが開封されたことが通知されます。
 @see [アピアリーズドキュメント &raquo; 開封登録をする](http://docs.appiaries.com/?p=1250)
 @param block ABResultBlock コールバック・ブロック
 @param option ABPushMessageOpenOption オプション
 */
- (Async)openWithBlock:(ABResultBlock)block option:(ABPushMessageOpenOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 クエリオブジェクトを返す
 @discussion プッシュ通知メッセージ・オブジェクト検索用のクエリオブジェクトを返します。
 <div class="important">
 v2.0.0 ではこのメソッドはご利用いただけません。
 </div>
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end