//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABTwitterConfig;

/*!
 アピアリーズ BaaS 設定
 
 __See Also__: [アピアリーズドキュメント &raquo; アプリを設定する](http://docs.appiaries.com/?p=60)<br/>
 */
@interface ABConfig : NSObject
#pragma mark - Properties
/*! @name Properties */
/*!
 アピアリーズ・アプリID
 @discussion [コントロールパネル] &raquo; [ダッシュボード] &raquo; [アプリ情報] 欄に表記されている__アプリID__を指定します。
 */
@property (strong, nonatomic) NSString *applicationID;
/*!
 アピアリーズ・アプリトークン
 @discussion [コントロールパネル] &raquo; [ダッシュボード] &raquo; [アプリ情報] 欄に表記されている__アプリトークン__を指定します。
 */
@property (strong, nonatomic) NSString *applicationToken;
/*!
 アピアリーズ・データストアID
 @discussion [コントロールパネル] &raquo; [ダッシュボード] &raquo; [アプリ情報] 欄に表記されている__データストアID__を指定します。
 */
@property (strong, nonatomic) NSString *datastoreID;
/*!
 SDKバージョン
 */
@property (strong, nonatomic) NSString *sdkVersion;
/*!
 APIバージョン
 */
@property (strong, nonatomic) NSString *apiVersion;
/*!
 接続タイムアウト間隔 (秒)
 @discussion APIサーバとの通信時のタイムアウト間隔を秒数で指定します。指定しない場合は初期値の__30秒__となります。
 */
@property (nonatomic) NSTimeInterval connectionTimeoutInterval;
/*!
 アップロード時の接続タイムアウト間隔 (秒)
 @discussion APIサーバとの通信時のタイムアウト間隔を秒数で指定します。指定しない場合は初期値の__300秒__となります。
 */
@property (nonatomic) NSTimeInterval uploadTimeoutInterval;
/*!
 ダウンロード時の接続タイムアウト間隔 (秒)
 @discussion APIサーバとの通信時のタイムアウト間隔を秒数で指定します。指定しない場合は初期値の__300秒__となります。
 */
@property (nonatomic) NSTimeInterval downloadTimeoutInterval;
/*!
 ダウンロード時のリトライ間隔 (秒)
 @discussion ダウンロード時のリトライ間隔を秒数で指定します。指定しない場合は初期値の__0秒__となります。 (最大30秒)
 */
@property (nonatomic) NSTimeInterval downloadRetryInterval;
/*!
 Twitter 設定
 */
@property (weak, nonatomic) ABTwitterConfig *twitter;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABConfig のシングルトン・インスタンスを返す
 @return ABConfig のシングルトン・インスタンス
 */
+ (instancetype)sharedConfig;

#pragma mark - Instance methods
/*! @name Instance methods */
/*!
 設定情報をデバイスに保存する
 @discussion 設定情報を NSUserDefaults を介してデバイスに保存します。
 @param object 設定値
 @param key 設定項目キー
 */
- (void)saveObject:(id)object forKey:(NSString *)key;
/*!
 設定情報をデバイスから読み出す
 @discussion 設定情報を NSUserDefaults を介してデバイスから読み出します。
 @param key 設定項目キー
 @return 設定値
 */
- (id)loadObjectForKey:(NSString *)key;
/*!
 オブジェクトをシリアライズしてからデバイスに保存する
 @discussion オブジェクトを NSUserDefaults を介してデバイスに保存します。
 @param object 設定値
 @param key 設定項目キー
 */
- (void)saveObjectWithSerialization:(id)object forKey:(NSString *)key;
/*!
 シリアライズされたオブジェクトをデバイスから読み出す
 @discussion オブジェクトを NSUserDefaults を介してデバイスから読み出します。
 @param key 設定項目キー
 @return 設定値
 */
- (id)loadObjectWithDeserializationForKey:(NSString *)key;
/*!
 デバイスに保存されている設定情報を破棄する
 @discussion NSUserDefaults を介してデバイスに保存された、引数キーに該当する設定情報を破棄します。
 @param key 破棄する設定情報の設定項目キー
 */
- (void)discardKey:(NSString *)key;
/*!
 デバイスに保存されているすべての設定情報を破棄する
 @discussion NSUserDefaults を介してデバイスに保存された、すべての設定情報を破棄します。
 */
- (void)discardAll;

@end