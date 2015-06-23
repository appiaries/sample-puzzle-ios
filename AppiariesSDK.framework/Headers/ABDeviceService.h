//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABDevice;
@class ABQuery;

/*!
 デバイス・サービス
 
 __See Also__: [アピアリーズドキュメント &raquo; プッシュ通知](http://docs.appiaries.com/?p=130)<br/>
 */
@interface ABDeviceService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABDeviceService のシングルトン・インスタンスを返す
 @return ABDeviceService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;
/*!
 デバイス・オブジェクトを生成する
 @return ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (ABDevice *)device;
/*!
 デバイス・オブジェクトを生成する
 @param collectionID コレクションID
 @return ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (ABDevice *)deviceWithCollectionID:(NSString *)collectionID;
/*!
 デバイス・オブジェクトを生成する
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (ABDevice *)deviceWithDictionary:(NSDictionary *)dictionary;
/*!
 デバイス・オブジェクトを生成する
 @param rawDeviceToken デバイストークン (バイナリ)
 @return ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (ABDevice *)deviceWithRawDeviceToken:(NSData *)rawDeviceToken;
/*!
 デバイス・オブジェクトを生成する
 @param deviceToken デバイストークン
 @return ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (ABDevice *)deviceWithDeviceToken:(NSString *)deviceToken;

#pragma mark - Register
/*! @name Register */
/*!
 デバイス・オブジェクトを登録する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)registerSynchronously:(ABDevice *)device error:(ABError **)error;
/*!
 デバイス・オブジェクトを登録する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceRegistrationOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)registerSynchronously:(ABDevice *)device option:(ABDeviceRegistrationOption)option error:(ABError **)error;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device option:(ABDeviceRegistrationOption)option;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device target:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device target:(id)target selector:(SEL)selector option:(ABDeviceRegistrationOption)option;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device block:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを登録する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 登録する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceRegistrationOption オプション
 @return ABResult オブジェクト
 */
- (Async)register:(ABDevice *)device block:(ABResultBlock)block option:(ABDeviceRegistrationOption)option;

#pragma mark - Unregister
/*! @name Unregister */
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)unregisterSynchronously:(ABDevice *)device error:(ABError **)error;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceUnregistrationOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)unregisterSynchronously:(ABDevice *)device option:(ABDeviceUnregistrationOption)option error:(ABError **)error;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 */
- (Async)unregister:(ABDevice *)device;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceUnregistrationOption オプション
 */
- (Async)unregister:(ABDevice *)device option:(ABDeviceUnregistrationOption)option;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)unregister:(ABDevice *)device target:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceUnregistrationOption オプション
 */
- (Async)unregister:(ABDevice *)device target:(id)target selector:(SEL)selector option:(ABDeviceUnregistrationOption)option;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)unregister:(ABDevice *)device block:(ABResultBlock)block;
/*!
 デバイス・オブジェクトの登録を解除する
 @discussion 非同期モードでデバイス・オブジェクトの登録を解除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 登録を解除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceUnregistrationOption オプション
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)unregister:(ABDevice *)device block:(ABResultBlock)block option:(ABDeviceUnregistrationOption)option;

#pragma mark - Save
/*! @name Save */
/*!
 デバイス・オブジェクトを保存する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @return ABResult オブジェクト
 */
//- (ABResult *)saveSynchronously:(ABDevice *)device;
/*!
 デバイス・オブジェクトを保存する
 @discussion 同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceSaveOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)saveSynchronously:(ABDevice *)device option:(ABDeviceSaveOption)option;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 */
//- (Async)save:(ABDevice *)device;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceSaveOption オプション
 */
//- (Async)save:(ABDevice *)device option:(ABDeviceSaveOption)option;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)save:(ABDevice *)device target:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceSaveOption オプション
 */
//- (Async)save:(ABDevice *)device target:(id)target selector:(SEL)selector option:(ABDeviceSaveOption)option;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)save:(ABDevice *)device block:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを保存する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param device 保存する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceSaveOption オプション
 */
//- (Async)save:(ABDevice *)device block:(ABResultBlock)block option:(ABDeviceSaveOption)option;


#pragma mark - Save (Objects)
/*! @name Save (Objects) */
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @return ABResult オブジェクト
 */
//- (ABResult *)saveAllSynchronously:(NSArray *)devices;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDeviceSaveOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)saveAllSynchronously:(NSArray *)devices option:(ABDeviceSaveOption)option;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 */
//- (Async)saveAll:(NSArray *)devices;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)devices option:(ABDeviceSaveOption)option;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)saveAll:(NSArray *)devices target:(id)target selector:(SEL)selector;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)devices target:(id)target selector:(SEL)selector option:(ABDeviceSaveOption)option;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)saveAll:(NSArray *)devices block:(ABResultBlock)block;
/*!
 すべてのデバイス・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを登録する](http://docs.appiaries.com/?p=1230)
 @param devices 保存する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceSaveOption オプション
 */
//- (Async)saveAll:(NSArray *)devices block:(ABResultBlock)block option:(ABDeviceSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 デバイス・オブジェクトを削除する
 @discussion 同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronously:(ABDevice *)device;
/*!
 デバイス・オブジェクトを削除する
 @discussion 同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceDeleteOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronously:(ABDevice *)device option:(ABDeviceDeleteOption)option;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 */
//- (Async)delete:(ABDevice *)device;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)delete:(ABDevice *)device option:(ABDeviceDeleteOption)option;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)delete:(ABDevice *)device target:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)delete:(ABDevice *)device target:(id)target selector:(SEL)selector option:(ABDeviceDeleteOption)option;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)delete:(ABDevice *)device block:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを削除する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param device 削除する ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)delete:(ABDevice *)device block:(ABResultBlock)block option:(ABDeviceDeleteOption)option;

#pragma mark - Delete (Objects)
/*! @name Delete (Objects) */
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteAllSynchronously:(NSArray *)devices;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDeviceDeleteOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteAllSynchronously:(NSArray *)devices option:(ABDeviceDeleteOption)option;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 */
//- (Async)deleteAll:(NSArray *)devices;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)devices option:(ABDeviceDeleteOption)option;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)deleteAll:(NSArray *)devices target:(id)target selector:(SEL)selector;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)devices target:(id)target selector:(SEL)selector option:(ABDeviceDeleteOption)option;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)deleteAll:(NSArray *)devices block:(ABResultBlock)block;
/*!
 すべてのデバイス・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを削除する](http://docs.appiaries.com/?p=1240)
 @param devices 削除する ABDevice オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteAll:(NSArray *)devices block:(ABResultBlock)block option:(ABDeviceDeleteOption)option;

#pragma mark - Delete (Query)
/*! @name Delete (Query) */
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABDeviceDeleteOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query option:(ABDeviceDeleteOption)option;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 */
//- (Async)deleteWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query option:(ABDeviceDeleteOption)option;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABDeviceDeleteOption)option;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするデバイス・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; デバイストークンを一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceDeleteOption オプション
 */
//- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABDeviceDeleteOption)option;

#pragma mark - Fetch
/*! @name Fetch */
/*!
 デバイス・オブジェクトを取得する
 @discussion 同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @return ABResult オブジェクト
 */
//- (ABResult *)fetchSynchronously:(ABDevice *)device;
/*!
 デバイス・オブジェクトを取得する
 @discussion 同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @param option ABDeviceFetchOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)fetchSynchronously:(ABDevice *)device option:(ABDeviceFetchOption)option;
/*!
 デバイス・オブジェクトを取得する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)fetch:(ABDevice *)device target:(id)target selector:(SEL)selector;
/*!
 デバイス・オブジェクトを取得する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceFetchOption オプション
 */
//- (Async)fetch:(ABDevice *)device target:(id)target selector:(SEL)selector option:(ABDeviceFetchOption)option;
/*!
 デバイス・オブジェクトを取得する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)fetch:(ABDevice *)device block:(ABResultBlock)block;
/*!
 デバイス・オブジェクトを取得する
 @discussion 非同期モードでデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を取得する]()
 @param device ABDevice オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceFetchOption オプション
 */
//- (Async)fetch:(ABDevice *)device block:(ABResultBlock)block option:(ABDeviceFetchOption)option;

#pragma mark - Find (Query)
/*! @name Find (Query) */
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @return ABResult オブジェクト
 */
//- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @param option ABDeviceFindOption オプション
 @return ABResult オブジェクト
 */
//- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query option:(ABDeviceFindOption)option;
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
//- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDeviceFindOption オプション
 */
//- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABDeviceFindOption)option;
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
//- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするデバイス・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするデバイス・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; デバイス情報を検索する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABDeviceFindOption オプション
 */
//- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABDeviceFindOption)option;

@end