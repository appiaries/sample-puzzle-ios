//
//  AppiariesPush.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/04/15.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "APISPushAPIClient.h"


/**
 * Appiariesプッシュ通知APIクラス
 * @discussion Appiariesのプッシュ通知APIを利用する際に使用します。
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISPushAPIClient instead.
 */
__attribute__ ((deprecated))
@interface AppiariesPush : NSObject
#pragma mark - Initialization
/** @name Initialization */
/**
 * API初期化処理
 * @brief アピアリーズ・プッシュ通知APIクラスの使用に先立って必ず実行する初期化処理です。
 * @param strDataStoreId  データストアID
 * @param strAppliId      アプリID
 * @param strAppliToken   アプリトークン
 * @warning アピアリーズ・プッシュ通知APIクラスの使用に先立って**必ず**実行する必要があります。
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISPushAPIClient#configureAPIWithDatastoreId:applicationId:applicationToken: instead.
 */
+ (void)initialize:(NSString *)strDataStoreId appliId:(NSString *)strAppliId appliToken:(NSString *)strAppliToken DEPRECATED_ATTRIBUTE;

#pragma mark - APIs
/** @name APIs */
/**
 * デバイス・トークン登録
 * @brief APNsより取得したデバイス・トークンをアピアリーズへ登録します。
 * 処理が完了すると、セレクタへ結果を返却します。
 * 返却されるオブジェクトは AppiariesEntity になります。
 * @param dataDeviceToken  APNsより取得したデバイス・トークン
 * @param dicAttr          任意、お客様が自由に設定できる属性。プッシュ通知送信時、ここに設定した値で送信対象者を絞り込むことができる
 * @param delegate         コールバック先オブジェクト
 * @param selector         コールバックハンドラ
 * @since AppiariesSDK 1.0.0
 * @deprecated use registerDeviceToken:attributes:target:action: instead.
 */
+ (void)sendDeviceToken:(NSData *)dataDeviceToken dicAttr:(NSDictionary *)dicAttr delegate:(id)delegate selector:(SEL)selector DEPRECATED_ATTRIBUTE;
/**
 * デバイス・トークン登録解除
 * @brief sendDeviceToken:dicAttr:delegate:selector: でアピアリーズへ登録したデバイス・トークンの登録を解除します。
 * @param delegate  コールバック先オブジェクト
 * @param selector  コールバックハンドラ (ハンドラの第一引数には AppiariesEntity が渡されます)
 * @since AppiariesSDK 1.0.0
 * @deprecated use unregisterDeviceTokenWithTarget:action: instead.
 */
+ (void)removeDeviceToken:(id)delegate selector:(SEL)selector DEPRECATED_ATTRIBUTE;
/**
 * push 通知開封通知
 * @brief プッシュ通知がユーザのデバイス上で開封されたことをアピアリーズへ通知します。
 * @param strPushId  push 通知受信時の NSDictionary 内の pushId をキーに持つ value
 * @param delegate   コールバック先オブジェクト
 * @param selector   コールバックハンドラ
 * @since AppiariesSDK 1.0.0
 * @deprecated use notifyMessageOpenedWithPushId:target:action: instead.
 */
+ (void)sendOpened:(NSString *)strPushId delegate:(id)delegate selector:(SEL)selector DEPRECATED_ATTRIBUTE;
@end
