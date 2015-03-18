//
//  APISJsonAPIClient.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/11.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

@class APISQueryCondition;
@class APISResponseObject;
@class APISSession;
@class APISAppUser;

/**
 * JSONオブジェクトAPIクラス
 * @discussion データストア上のJSONオブジェクトを操作する際に使用します。
 * @since AppiariesSDK 1.2.0
 */
@interface APISJsonAPIClient : NSObject
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
 * @brief APISJsonAPIClient オブジェクトを生成して返します。
 * @param session APISSessionオブジェクト
 * @return APISJsonAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithSession:(APISSession *)session;

#pragma mark - APIs
/** @name APIs */
/**
 * JSONオブジェクト登録API
 * @brief アピアリーズのデータストアにJSONオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data;
/**
 * JSONオブジェクト登録API
 * @brief アピアリーズのデータストアにJSONオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト登録API
 * @brief アピアリーズのデータストアにJSONオブジェクトを登録します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @warning objectId に nil を指定した場合、システム側で生成されたランダム文字列が設定されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)createJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト取得API
 * @brief アピアリーズのデータストアからJSONオブジェクトを取得します。
 * @param objectId  オブジェクトID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveJsonObjectWithId:(NSString *)objectId target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト取得API
 * @brief アピアリーズのデータストアからJSONオブジェクトを取得します。
 * @param objectId  オブジェクトID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveJsonObjectWithId:(NSString *)objectId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト検索API
 * @brief アピアリーズのデータストアからJSONオブジェクトを検索します。
 * @param queryCondition  検索条件
 * @param target          コールバック先オブジェクト
 * @param action          コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)searchJsonObjectsWithQueryCondition:(APISQueryCondition *)queryCondition target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト検索API
 * @brief アピアリーズのデータストアからJSONオブジェクトを検索します。
 * @param queryCondition  検索条件
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)searchJsonObjectsWithQueryCondition:(APISQueryCondition *)queryCondition success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト置換API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを置換します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @warning 置換対象のJSONオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data;
/**
 * JSONオブジェクト置換API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを置換します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @warning 置換対象のJSONオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト置換API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを置換します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @warning 置換対象のJSONオブジェクトが未登録であった場合は新規に登録されます。
 * @since AppiariesSDK 1.2.0
 */
- (void)replaceJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト更新API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを更新します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateJsonObjectWithId:(NSString *)objectId data:(NSDictionary *
)data;
/**
 * JSONオブジェクト更新API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを更新します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト更新API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを更新します。
 * @param objectId  オブジェクトID
 * @param data      オブジェクトに設定するディクショナリ形式のJSONデータ
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateJsonObjectWithId:(NSString *)objectId data:(NSDictionary *)data success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト削除API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを削除します。
 * @param objectId  オブジェクトID
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId;
/**
 * JSONオブジェクト削除API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを削除します。
 * @param objectId  オブジェクトID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト削除API
 * @brief アピアリーズのデータストア上のJSONオブジェクトを削除します。
 * @param objectId  オブジェクトID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクトから特定の1フィールドを削除するAPI
 * @brief アピアリーズのデータストア上のJSONオブジェクトから特定1フィールドを削除します。
 * @param objectId   オブジェクトID
 * @param fieldName  フィールド名
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId fieldName:(NSString *)fieldName;
/**
 * JSONオブジェクトから特定の1フィールドを削除するAPI
 * @brief アピアリーズのデータストア上のJSONオブジェクトから特定1フィールドを削除します。
 * @param objectId   オブジェクトID
 * @param fieldName  フィールド名
 * @param target     コールバック先オブジェクト
 * @param action     コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId fieldName:(NSString *)fieldName target:(id)target action:(SEL)action;
/**
 * JSONオブジェクトから特定の1フィールドを削除するAPI
 * @brief アピアリーズのデータストア上のJSONオブジェクトから特定1フィールドを削除します。
 * @param objectId   オブジェクトID
 * @param fieldName  フィールド名
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectWithId:(NSString *)objectId fieldName:(NSString *)fieldName success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * JSONオブジェクト一括削除API
 * @brief 検索条件に合致するアピアリーズのデータストア上のJSONオブジェクトを一括削除します。
 * @param queryCondition  検索条件
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectsWithQueryCondition:(APISQueryCondition *)queryCondition;
/**
 * JSONオブジェクト一括削除API
 * @brief 検索条件に合致するアピアリーズのデータストア上のJSONオブジェクトを一括削除します。
 * @param queryCondition  検索条件
 * @param target  コールバック先オブジェクト
 * @param action  コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectsWithQueryCondition:(APISQueryCondition *)queryCondition target:(id)target action:(SEL)action;
/**
 * JSONオブジェクト一括削除API
 * @brief 検索条件に合致するアピアリーズのデータストア上のJSONオブジェクトを一括削除します。
 * @param queryCondition  検索条件
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteJsonObjectsWithQueryCondition:(APISQueryCondition *)queryCondition success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;

@end
