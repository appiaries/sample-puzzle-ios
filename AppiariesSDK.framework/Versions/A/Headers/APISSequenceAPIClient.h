//
//  APISSequenceAPIClient.h
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
 * シーケンスAPIクラス
 * @discussion データストア上のシーケンス値を操作する際に使用します。
 * @since AppiariesSDK 1.2.0
 */
@interface APISSequenceAPIClient : NSObject
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
 * @brief APISPushAPIClient オブジェクトを生成して返します。
 * @param session APISSessionオブジェクト
 * @return APISPushAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithSession:(APISSession *)session;

#pragma mark - APIs
/** @name APIs */
/**
 * シーケンス値発行API
 * @brief アピアリーズのデータストアのシーケンスを発行（加減算）します。
 * @param value  シーケンス値
 * @warning シーケンス・コレクション作成時に「減算を利用する」としていない場合は、 value に対して負数を指定することはできません。
 * @since AppiariesSDK 1.2.0
 */
- (void)publishSequenceNumberWithValue:(NSInteger)value;
/**
 * シーケンス値発行API
 * @brief アピアリーズのデータストアのシーケンスを発行（加減算）します。
 * @param value  シーケンス値
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @warning シーケンス・コレクション作成時に「減算を利用する」としていない場合は、 value に対して負数を指定することはできません。
 * @since AppiariesSDK 1.2.0
 */
- (void)publishSequenceNumberWithValue:(NSInteger)value target:(id)target action:(SEL)action;
/**
 * シーケンス値発行API
 * @brief アピアリーズのデータストアのシーケンスを発行（加減算）します。
 * @param value  シーケンス値
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @warning シーケンス・コレクション作成時に「減算を利用する」としていない場合は、 value に対して負数を指定することはできません。
 * @since AppiariesSDK 1.2.0
 */
- (void)publishSequenceNumberWithValue:(NSInteger)value success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * シーケンス値取得API
 * @brief アピアリーズのデータストアからシーケンスの現在値を取得します。
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveSequenceNumberWithTarget:(id)target action:(SEL)action;
/**
 * シーケンス値取得API
 * @brief アピアリーズのデータストアからシーケンスの現在値を取得します。
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveSequenceNumberWithSuccess:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;

@end
