//
// Created by Appiaries Corporation on 2015/02/28.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 アピアリーズ BaaS 例外
 */
@interface ABExceptions : NSObject

#pragma mark - BaaS Exceptions
/*! @name BaaS Exceptions */

/*!
 初期化未済み例外を生成する
 @discussion [AB activate] を実行せずにSDKの各種機能を利用した場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasNotYetInitializedException;
/*!
 初期化未済み例外を生成する
 @discussion [AB activate] を実行せずにSDKの各種機能を利用した場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasNotYetInitializedExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 設定不足例外を生成する
 @discussion SDK の各種機能を利用するにあたり、事前に ABConfig に設定する必要のある設定がなされていない場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasInsufficientConfigurationException;
/*!
 設定不足例外を生成する
 @discussion SDK の各種機能を利用するにあたり、事前に ABConfig に設定する必要のある設定がなされていない場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasInsufficientConfigurationExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 未サポートクラス例外を生成する
 @discussion ABClassRepository で管理できないクラスが登録されようとした場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasUnsupportedClassException;
/*!
 未サポートクラス例外を生成する
 @discussion ABClassRepository で管理できないクラスが登録されようとした場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasUnsupportedClassExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 クラス解析例外を生成する
 @discussion ABClassRepository に登録を試みたクラスの解析に失敗した場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasClassParseException;
/*!
 クラス解析例外を生成する
 @discussion ABClassRepository に登録を試みたクラスの解析に失敗した場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasClassParseExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 プロパティアクセス例外を生成する
 @discussion ABModel を継承したクラスで、禁止された方法でプロパティにアクセスした場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasPropertyAccessException;
/*!
 プロパティアクセス例外を生成する
 @discussion ABModel を継承したクラスで、禁止された方法でプロパティにアクセスした場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasPropertyAccessExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 デバイス未登録例外を生成する
 @discussion デバイス情報がアピアリーズ BaaS に登録されていない状態でプッシュ通知サービス等を利用しようとした場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasDeviceNotYetRegisteredException;
/*!
 デバイス未登録例外を生成する
 @discussion デバイス情報がアピアリーズ BaaS に登録されていない状態でプッシュ通知サービス等を利用しようとした場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasDeviceNotYetRegisteredExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 JSONデータ解析例外を生成する
 @discussion アピアリーズ BaaS から受信した JSON データの解析時に回復不能なエラーが発生した場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasJSONParseException;
/*!
 JSONデータ解析例外を生成する
 @discussion アピアリーズ BaaS から受信した JSON データの解析時に回復不能なエラーが発生した場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasJSONParseExceptionWithUserInfo:(NSDictionary *)userInfo;

/*!
 引数不足例外を生成する
 @discussion SDK の各種機能へのアクセス時に想定外の引数不足が生じた場合にスローされる例外です。
 @return NSException オブジェクト
 */
+ (NSException *)baasInsufficientArgumentException;
/*!
 引数不足例外を生成する
 @discussion SDK の各種機能へのアクセス時に想定外の引数不足が生じた場合にスローされる例外です。
 @param userInfo 例外情報ディクショナリ
 @return NSException オブジェクト
 */
+ (NSException *)baasInsufficientArgumentExceptionWithUserInfo:(NSDictionary *)userInfo;

@end