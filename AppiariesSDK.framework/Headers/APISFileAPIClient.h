//
//  APISFileAPIClient.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/13.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

@class APISQueryCondition;
@class APISResponseObject;
@class APISSession;
@class APISAppUser;

/**
 * ファイルAPIクラス
 * @discussion データストア上のバイナリオブジェクトを操作する際に使用します。
 * @since AppiariesSDK 1.2.0
 */
@interface APISFileAPIClient : NSObject
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

#pragma mark - Initialization
/** @name Initialization */
/**
 * 指定イニシャライザ
 * @brief APISFileAPIClient オブジェクトを生成して返します。
 * @param session APISSessionオブジェクト
 * @return APISFileAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithSession:(APISSession *)session;

#pragma mark - APIs
/** @name APIs */
/**
 * バイナリオブジェクト登録API
 * @brief アピアリーズのデータストアにバイナリオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta;
/**
 * バイナリオブジェクト登録API
 * @brief アピアリーズのデータストアにバイナリオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクト登録API
 * @brief アピアリーズのデータストアにバイナリオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクトのメタ情報取得API
 * @brief アピアリーズのデータストアからバイナリオブジェクトのメタ情報を取得します。
 * @param objectId  オブジェクトID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveBinaryObjectMetaWithId:(NSString *)objectId target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクトのメタ情報取得API
 * @brief アピアリーズのデータストアからバイナリオブジェクトのメタ情報を取得します。
 * @param objectId  オブジェクトID
 * @param successHandler  成功時実行ハンドラ
 * @param failureHandler  失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveBinaryObjectMetaWithId:(NSString *)objectId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクトの実体(バイナリデータ)取得API
 * @brief アピアリーズのデータストアからバイナリオブジェクトの実体(バイナリデータ)を取得します。
 * @param objectId  オブジェクトID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveBinaryObjectBinaryWithId:(NSString *)objectId target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクトの実体(バイナリデータ)取得API
 * @brief アピアリーズのデータストアからバイナリオブジェクトの実体(バイナリデータ)を取得します。
 * @param objectId  オブジェクトID
 * @param successHandler  成功時実行ハンドラ
 * @param failureHandler  失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveBinaryObjectBinaryWithId:(NSString *)objectId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクト検索API
 * @brief アピアリーズのデータストアからバイナリオブジェクトを検索します。
 * @param queryCondition  検索条件
 * @param target  コールバック先オブジェクト
 * @param action  コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)searchBinaryObjectsMetaWithQueryCondition:(APISQueryCondition *)queryCondition target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクト検索API
 * @brief アピアリーズのデータストアからバイナリオブジェクトを検索します。
 * @param queryCondition  検索条件
 * @param successHandler  成功時実行ハンドラ
 * @param failureHandler  失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)searchBinaryObjectsMetaWithQueryCondition:(APISQueryCondition *)queryCondition success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクト置換API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを置換します。
 * @param objectId  オブジェクトID ※nullの場合はランダム文字列が設定される
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @warning 置換対象のバイナリオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta;
/**
 * バイナリオブジェクト置換API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを置換します。
 * @param objectId  オブジェクトID ※nullの場合はランダム文字列が設定される
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @param target  コールバック先オブジェクト
 * @param action  コールバックハンドラ
 * @warning 置換対象のバイナリオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクト置換API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを置換します。
 * @param objectId  オブジェクトID ※nullの場合はランダム文字列が設定される
 * @param filename  アップロードファイルのファイル名
 * @param binary    アップロードファイルのバイナリデータ
 * @param meta      アップロードファイルのメタ情報
 * @param successHandler  成功時実行ハンドラ
 * @param failureHandler  失敗時実行ハンドラ
 * @warning 置換対象のバイナリオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクト更新API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを更新します。
 * @param objectId オブジェクトID
 * @param filename ファイル名
 * @param binary バイナリデータ
 * @param meta ファイルメタ情報
 * @since AppiariesSDK 1.2.0
 */
- (void)updateBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta;
/**
 * バイナリオブジェクト更新API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを更新します。
 * @param objectId  オブジェクトID
 * @param filename ファイル名
 * @param binary バイナリデータ
 * @param meta ファイルメタ情報
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクト更新API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを更新します。
 * @param objectId  オブジェクトID
 * @param filename ファイル名
 * @param binary バイナリデータ
 * @param meta ファイルメタ情報
 * @param successHandler  成功時実行ハンドラ
 * @param failureHandler  失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateBinaryObjectWithId:(NSString *)objectId filename:(NSString *)filename binary:(NSData *)binary meta:(NSDictionary *)meta success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * バイナリオブジェクト削除API
 * @brief アピアリーズのデータストア上のバイナリブジェクトを削除します。
 * @param objectId オブジェクトID
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteBinaryObjectWithId:(NSString *)objectId;
/**
 * バイナリオブジェクト削除API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを削除します。
 * @param objectId  オブジェクトID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteBinaryObjectWithId:(NSString *)objectId target:(id)target action:(SEL)action;
/**
 * バイナリオブジェクト削除API
 * @brief アピアリーズのデータストア上のバイナリオブジェクトを削除します。
 * @param objectId オブジェクトID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteBinaryObjectWithId:(NSString *)objectId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;

@end
