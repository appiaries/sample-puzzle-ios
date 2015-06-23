//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABModel.h>
#import <AppiariesSDK/ABManagedProtocol.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;
@class ABQuery;

/*!
 デバイス・モデル 
 @discussion アプリがインストールされたデバイスを表現するモデルクラスです。

 __See Also__: [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=130)<br/>
*/
@interface ABDevice : ABModel <ABManagedProtocol, NSCoding>
#pragma mark - Properties
/*! @name Properties */
/*!
 デバイストークン
 */
@property (strong, nonatomic) NSString *deviceToken;
/*!
 デバイストークン (バイナリ)
 */
@property (strong, nonatomic) NSData *rawDeviceToken;
/*!
 デバイス・タイプ
 @discussion iPhone端末の場合は"apns"が、Android端末の場合は"gcm"が格納されます。
 */
@property (strong, nonatomic) NSString *type;
/*!
 デバイス・プラットフォーム
 */
@property (nonatomic) ABPlatform platform;
/*!
 プッシュ通知配信環境
 @discussion Production環境でプッシュ通知を配信する場合は1が、Sandbox環境の場合は0が格納されます。
 */
@property (nonatomic) ABPushEnvironment environment;
/*!
 デバイス属性
 */
@property (strong, nonatomic, readonly) NSDictionary *attributes;
/*!
 予約されたプッシュ通知ID
 */
@property (strong, nonatomic) NSArray *reservedPushIds;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABDevice オブジェクト
 */
+ (instancetype)device;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABDevice オブジェクト
 */
+ (instancetype)deviceWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABDevice オブジェクト
 */
+ (instancetype)deviceWithDictionary:(NSDictionary *)dictionary;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param deviceToken デバイストークン
 @return ABDevice オブジェクト
 */
+ (instancetype)deviceWithDeviceToken:(NSString *)deviceToken;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param rawDeviceToken デバイストークン (バイナリ)
 @return ABDevice オブジェクト
 */
+ (instancetype)deviceWithRawDeviceToken:(NSData *)rawDeviceToken;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param deviceToken デバイストークン
 @return ABDevice オブジェクト
 */
- (instancetype)initWithDeviceToken:(NSString *)deviceToken;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param rawDeviceToken デバイストークン (バイナリ)
 @return ABDevice オブジェクト
 */
- (instancetype)initWithRawDeviceToken:(NSData *)rawDeviceToken;

#pragma mark - Register
/*! @name Register */
/*!
 デバイス・オブジェクトを登録する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)registerSynchronouslyWithError:(ABError **)error;
/*!
 デバイス・オブジェクトを登録する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param option ABDeviceRegistrationOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)registerSynchronouslyWithOption:(ABDeviceRegistrationOption)option error:(ABError **)error;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @return ABResult オブジェクト
 */
- (Async)register;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)registerWithOption:(ABDeviceRegistrationOption)option;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @return ABResult オブジェクト
 */
- (Async)registerWithTarget:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)registerWithTarget:(id)target selector:(SEL)selector option:(ABDeviceRegistrationOption)option;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param block ABResultBlock コールバック・ブロック
 @return ABResult オブジェクト
 */
- (Async)registerWithBlock:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)registerWithBlock:(ABResultBlock)block option:(ABDeviceRegistrationOption)option;

#pragma mark - Save
/*! @name Save */
/*!
 デバイス・オブジェクトを保存する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
//- (ABResult *)saveSynchronouslyWithError:(ABError **)error;;
/*!
 デバイス・オブジェクトを保存する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param option ABDeviceSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
//- (ABResult *)saveSynchronouslyWithOption:(ABDeviceSaveOption)option error:(ABError **)error;;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 */
//- (Async)save;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveWithOption:(ABDeviceSaveOption)option;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)saveWithTarget:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveWithTarget:(id)target selector:(SEL)selector option:(ABDeviceSaveOption)option;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)saveWithBlock:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveWithBlock:(ABResultBlock)block option:(ABDeviceSaveOption)option;

#pragma mark - Unregister
/*! @name Unregister */
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)unregisterSynchronouslyWithError:(ABError **)error;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param option ABDeviceUnregistrationOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)unregisterSynchronouslyWithOption:(ABDeviceUnregistrationOption)option error:(ABError **)error;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 */
- (Async)unregister;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param option ABDeviceUnregistrationOption オプション
 */
- (Async)unregisterWithOption:(ABDeviceUnregistrationOption)option;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)unregisterWithTarget:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceUnregistrationOption オプション
 */
- (Async)unregisterWithTarget:(id)target selector:(SEL)selector option:(ABDeviceUnregistrationOption)option;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)unregisterWithBlock:(ABResultBlock)block;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param option ABDeviceUnregistrationOption オプション
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)unregisterWithBlock:(ABResultBlock)block option:(ABDeviceUnregistrationOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 クエリオブジェクトを返す
 @discussion デバイス・オブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end