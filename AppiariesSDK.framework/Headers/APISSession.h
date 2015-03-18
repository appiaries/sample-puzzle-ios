//
//  APISSession.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/09/05.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

@class APISPushAPIClient;
@class APISJsonAPIClient;
@class APISFileAPIClient;
@class APISAppUserAPIClient;
@class APISSequenceAPIClient;
@class APISAppUser;

/**
 * アピアリーズ・セッション管理クラス
 * @discussion アピアリーズの Web API を利用する際に必要となる認証情報や接続情報を集約管理します。
 * @since AppiariesSDK 1.2.0
 */
@interface APISSession : NSObject
#pragma mark - Properties
/** @name Properties */
/**
 * データストアID
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *datastoreId;
/**
 * アプリID
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *applicationId;
/**
 * アプリトークン
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *applicationToken;
/**
 * 会員
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) APISAppUser *appUser;
/**
 * コレクションID
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *collectionId;

#pragma mark - Singleton methods
/** @name Singleton methods */
/**
 * シングルトン・インスタンス取得
 * @brief APISSession のシングルトン・インスタンスを返します。
 * @return APISSession インスタンス
 * @since AppiariesSDK 1.2.0
 */
+ (APISSession *)sharedSession;

#pragma mark - Public methods (Configuration)
/** @name Public methods (Configuration) */
/**
 * セッション初期化
 * @brief セッションを初期化します。
 * @param datastoreId データストアID
 * @param applicationId アプリID
 * @param applicationToken アプリトークン
 * @since AppiariesSDK 1.2.0
 */
- (void)configureWithDatastoreId:(NSString *)datastoreId applicationId:(NSString *)applicationId applicationToken:(NSString *)applicationToken;
/**
 * セッション初期化
 * @brief セッションを初期化します。
 * @param datastoreId データストアID
 * @param applicationId アプリID
 * @param applicationToken アプリトークン
 * @param collectionId コレクションID
 * @since AppiariesSDK 1.2.0
 */
- (void)configureWithDatastoreId:(NSString *)datastoreId applicationId:(NSString *)applicationId applicationToken:(NSString *)applicationToken collectionId:(NSString *)collectionId;
/**
 * セッション初期化
 * @brief セッションを初期化します。
 * @param datastoreId データストアID
 * @param applicationId アプリID
 * @param applicationToken アプリトークン
 * @param appUser  会員オブジェクト
 * @since AppiariesSDK 1.2.0
*/
- (void)configureWithDatastoreId:(NSString *)datastoreId applicationId:(NSString *)applicationId applicationToken:(NSString *)applicationToken appUser:(APISAppUser *)appUser;
/**
 * セッション初期化
 * @brief セッションを初期化します。
 * @param datastoreId データストアID
 * @param applicationId アプリID
 * @param applicationToken アプリトークン
 * @param appUser  会員オブジェクト
 * @param collectionId コレクションID
 * @since AppiariesSDK 1.2.0
 */
- (void)configureWithDatastoreId:(NSString *)datastoreId applicationId:(NSString *)applicationId applicationToken:(NSString *)applicationToken appUser:(APISAppUser *)appUser collectionId:(NSString *)collectionId;

#pragma mark - Public methods (Create API instance)
/** @name Public methods (Create API instance) */
/**
 * APISPushAPIClient 生成
 * @brief Push API クライアントを生成して返します。
 * @return APISPushAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (APISPushAPIClient *)createPushAPIClient;
/**
 * APISJsonAPIClient 生成
 * @brief JSON API クライアントを生成して返します。
 * @return APISJsonAPIClient オブジェクト
 * @warning JSON API の実行にはコレクションIDの指定が必須となりますので、オブジェクト生成後にプロパティ collectionId にコレクションIDをセットしてください。
 * @since AppiariesSDK 1.2.0
 */
- (APISJsonAPIClient *)createJsonAPIClient;
/**
 * APISJsonAPIClient 生成
 * @brief JSON API クライアントを生成して返します。
 * @param collectionId コレクションID
 * @return APISJsonAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (APISJsonAPIClient *)createJsonAPIClientWithCollectionId:(NSString *)collectionId;
/**
 * APISFileAPIClient 生成
 * @brief File API クライアントを生成して返します。
 * @return APISFileAPIClient オブジェクト
 * @warning File API の実行にはコレクションIDの指定が必須となりますので、オブジェクト生成後にプロパティ collectionId にコレクションIDをセットしてください。
 * @since AppiariesSDK 1.2.0
 */
- (APISFileAPIClient *)createFileAPIClient;
/**
 * APISFileAPIClient 生成
 * @brief File API クライアントを生成して返します。
 * @param collectionId コレクションID
 * @return APISFileAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (APISFileAPIClient *)createFileAPIClientWithCollectionId:(NSString *)collectionId;
/**
 * APISSequenceAPIClient 生成
 * @brief Sequence API クライアントを生成して返します。
 * @return APISSequenceAPIClient オブジェクト
 * @warning Sequence API の実行にはコレクションIDの指定が必須となりますので、オブジェクト生成後にプロパティ collectionId にコレクションIDをセットしてください。
 * @since AppiariesSDK 1.2.0
 */
- (APISSequenceAPIClient *)createSequenceAPIClient;
/**
 * APISSequenceAPIClient 生成
 * @brief Sequence API クライアントを生成して返します。
 * @param collectionId コレクションID
 * @return APISSequenceAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (APISSequenceAPIClient *)createSequenceAPIClientWithCollectionId:(NSString *)collectionId;
/**
 * APISAppUserAPIClient 生成
 * @brief App User API クライアントを生成して返します。
 * @return APISAppUserAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (APISAppUserAPIClient *)createAppUserAPIClient;
/**
 * ログイン中かどうかを返す
 * @brief ログインしているかどうかを返します。 (YES=ログイン中)
 * @return ログイン中か (YES=ログイン中)
 * @since AppiariesSDK 1.2.0
 */
- (BOOL)isLoggedIn;

/**
 * 匿名会員としてログイン中かどうかを返す
 * @brief 匿名会員としてログイン中かどうかを返します。 (YES=ログイン中)
 * @return ログイン中か (YES=ログイン中)
 * @since AppiariesSDK 1.4.0
 */
- (BOOL)isLoggedInAsAnonymous;

@end
