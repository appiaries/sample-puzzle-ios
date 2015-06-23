//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABUserService;
@class ABPushService;
@class ABDBService;
@class ABSequenceService;
@class ABConfig;
@class ABFileService;
@class ABDeviceService;
@class ABSession;
@protocol ABManagedProtocol;
@class ABTwitterService;

/*!
 アピアリーズ BaaS
 @discussion アピアリーズ BaaS の各種サービスにアクセスするための窓口となるクラスです。
 */
@interface AB : NSObject
#pragma mark - Properties
/*! @name Properties */
/*!
 アピアリーズ設定
 @discussion ABConfig に簡易アクセスするためのプロパティです。
 */
@property (weak, nonatomic, readonly) ABConfig *config;
/*!
 セッション
 @discussion ABSession に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABSession *session;
/*!
 デバイス・サービス
 @discussion ABDeviceService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABDeviceService *device;
/*!
 ユーザ・サービス
 @discussion ABUserService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABUserService *user;
/*!
 プッシュ通知サービス
 @discussion ABPushService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABPushService *push;
/*!
 ファイル・サービス
 @discussion ABFileService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABFileService *file;
/*!
 DBサービス
 @discussion ABDBService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABDBService *db;
/*!
 シーケンス・サービス
 @discussion ABSequenceService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABSequenceService *seq;
/*!
 Twitter サービス
 @discussion ABTwitterService に簡易にアクセスするためのプロパティです。
 */
@property (weak, nonatomic) ABTwitterService *twitter;
/*!
 Appiaries SDK は初期化済みか
 @discussion Appiaries SDK が初期化済みかどうかを取得します。(YES: 初期化済み)
 */
@property (nonatomic, readonly, getter=isActivated) BOOL activated;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 AB のシングルトン・インスタンスを返す
 @return AB のシングルトン・インスタンス
 */
+ (instancetype)sharedFacade;
/*!
 Appiaries SDK の初期化
 @discussion Appiaries SDK を初期化します。
 @return YES: 初期化成功
 */
- (BOOL)activate;

#pragma mark - Class Repository
/*! @name Class Repository */
/*!
 サブクラスをリポジトリに登録する
 @discussion 組み込みクラスを拡張して作成した複数のサブクラスをリポジトリに登録します。
 @param clazz ABModel クラスの派生クラス
 */
- (void)registerClass:(Class<ABManagedProtocol>)clazz;
/*!
 サブクラスをリポジトリに登録する
 @discussion リポジトリに複数のサブクラスを登録します。
 @param clazz ABModel クラスの派生クラス
 */
- (void)registerClasses:(NSArray *)classes;
/*!
 リポジトリをリセットする
 @discussion 本メソッドを実行すると、リポジトリは初期状態（サブクラス未登録状態）となります。
 */
- (void)resetClassRepository;

#pragma mark - API URLs
/*! @name API URLs */
+ (NSString *)baasAPIBaseURL:(NSString *)baseUrl version:(NSString *)version;
+ (NSString *)baasTokenAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasTokenAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;
+ (NSString *)baasUserAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasUserAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;
+ (NSString *)baasDatastoreAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasDatastoreAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;
+ (NSString *)baasFileAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasFileAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;
+ (NSString *)baasPushAPIURLWithConfig:(ABConfig *)config platform:(ABPlatform)platform path:(NSString *)path;
+ (NSString *)baasPushAPIURLWithConfig:(ABConfig *)config platform:(ABPlatform)platform pathFormat:(NSString *)fmt,...;
+ (NSString *)baasPushAnalyticsAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasPushAnalyticsAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;
+ (NSString *)baasSequenceAPIURLWithConfig:(ABConfig *)config path:(NSString *)path;
+ (NSString *)baasSequenceAPIURLWithConfig:(ABConfig *)config pathFormat:(NSString *)fmt,...;

- (NSString *)baasAPIBaseURL;
- (NSString *)baasTokenAPIURLWithPath:(NSString *)path;
- (NSString *)baasTokenAPIURLWithPathFormat:(NSString *)fmt,...;
- (NSString *)baasUserAPIURLWithPath:(NSString *)path;
- (NSString *)baasUserAPIURLWithPathFormat:(NSString *)fmt,...;
- (NSString *)baasDatastoreAPIURLWithPath:(NSString *)path;
- (NSString *)baasDatastoreAPIURLWithPathFormat:(NSString *)fmt,...;
- (NSString *)baasFileAPIURLWithPath:(NSString *)path;
- (NSString *)baasFileAPIURLWithPathFormat:(NSString *)fmt,...;
- (NSString *)baasPushAPIURLWithPlatform:(ABPlatform)platform path:(NSString *)path;
- (NSString *)baasPushAPIURLWithPlatform:(ABPlatform)platform pathFormat:fmt,...;
- (NSString *)baasPushAnalyticsAPIURLWithPath:(NSString *)path;
- (NSString *)baasPushAnalyticsAPIURLWithPathFormat:(NSString *)fmt,...;
- (NSString *)baasSequenceAPIURLWithPath:(NSString *)path;
- (NSString *)baasSequenceAPIURLWithPathFormat:(NSString *)fmt,...;

@end