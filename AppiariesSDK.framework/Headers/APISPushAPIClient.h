//
//  APISPushAPIClient.h
//  AppiariesSDK
//
// Created by Appiaries Corporation on 2014/08/25.
// Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 * アピアリーズ・プッシュ通知オプション定数
 * @since AppiariesSDK 1.2.0
 */
typedef NS_OPTIONS(NSUInteger, APISPushNotificationOption) {
    /**
     * プッシュ通知でURL(userInfo[@"_openUrl"])が渡された際、何も実行しません。
     * @since AppiariesSDK 1.2.0
     */
    APISPushNotificationOptionNone = 0,
    /**
     * プッシュ通知でURL(userInfo[@"_openUrl"])が渡された際、AppiariesSDKの組み込みWebViewController（またはカスタムUIViewController）で当該URLを開きます。
     * @since AppiariesSDK 1.2.0
     */
    APISPushNotificationOptionOpenURL = 1 << 0,
    /**
     * プッシュ通知でURL(userInfo[@"_openUrl"])が渡された際、Safariで当該URLを開きます。
     * @since AppiariesSDK 1.2.0
     */
    APISPushNotificationOptionOpenURLWithSafari = 1 << 1,
};


@protocol APISPushNotificationSupport;
@protocol APISWebViewControllerDelegate;
@class APISResponseObject;
@class APISSession;
@class APISAppUser;

/**
 * アピアリーズ・プッシュ通知APIクラス
 * @discussion アピアリーズのプッシュ通知APIを利用する際に使用します。
 * @since AppiariesSDK 1.0.0
 */
@interface APISPushAPIClient : NSObject
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
 * デバイス・トークン登録
 * @brief アピアリーズへデバイス・トークンを送信/登録します。
 * @param deviceToken デバイス・トークン
 * @param attributes 属性 (カンマ区切りで複数指定可)
 * @since AppiariesSDK 1.2.0
 */
- (void)registerDeviceToken:(NSData *)deviceToken attributes:(NSDictionary *)attributes;
/**
 * デバイス・トークン登録
 * @brief アピアリーズへデバイス・トークンを送信/登録します。
 * @param deviceToken デバイス・トークン
 * @param attributes 属性 (カンマ区切りで複数指定可)
 * @param target コールバック先オブジェクト
 * @param action コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)registerDeviceToken:(NSData *)deviceToken attributes:(NSDictionary *)attributes target:(id)target action:(SEL)action;
/**
 * デバイス・トークン登録
 * @brief アピアリーズへデバイス・トークンを送信/登録します。
 * @param deviceToken デバイス・トークン
 * @param attributes 属性 (カンマ区切りで複数指定可)
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)registerDeviceToken:(NSData *)deviceToken attributes:(NSDictionary *)attributes success:(void(^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * デバイス・トークン登録解除
 * @brief registerDeviceToken:attributes:target:action: でアピアリーズへ登録したデバイス・トークンの登録を解除します。
 * @since AppiariesSDK 1.2.0
 */
- (void)unregisterDeviceToken;
/**
 * デバイス・トークン登録解除
 * @brief registerDeviceToken:attributes:target:action: でアピアリーズへ登録したデバイス・トークンの登録を解除します。
 * @param target コールバック先オブジェクト
 * @param action コールバックハンドラ (ハンドラの第一引数には APISResponseObject が渡されます)
 * @since AppiariesSDK 1.2.0
 */
- (void)unregisterDeviceTokenWithTarget:(id)target action:(SEL)action;
/**
 * デバイス・トークン登録解除
 * @brief registerDeviceToken:attributes:target:action: でアピアリーズへ登録したデバイス・トークンの登録を解除します。
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)unregisterDeviceTokenWithSuccess:(void(^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 開封通知
 * @brief プッシュ通知がユーザのデバイス上で開封されたことをアピアリーズへ通知します。
 * @param pushId プッシュID
 * @since AppiariesSDK 1.2.0
 */
- (void)notifyMessageOpenedWithPushId:(NSInteger)pushId;
/**
 * 開封通知
 * @brief プッシュ通知がユーザのデバイス上で開封されたことをアピアリーズへ通知します。
 * @param pushId プッシュID
 * @param target コールバック先オブジェクト
 * @param action コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)notifyMessageOpenedWithPushId:(NSInteger)pushId target:(id)target action:(SEL)action;
/**
 * 開封通知
 * @brief プッシュ通知がユーザのデバイス上で開封されたことをアピアリーズへ通知します。
 * @param pushId プッシュID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)notifyMessageOpenedWithPushId:(NSInteger)pushId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * プッシュ通知ハンドラ
 * @brief デバイス上でプッシュ通知をタップした際の挙動を制御します。
 * @param userInfo 通知情報ディクショナリ
 * @param option プッシュ通知オプション
 * @since AppiariesSDK 1.2.0
 */
- (void)handlePushNotification:(NSDictionary *)userInfo option:(APISPushNotificationOption)option;
/**
 * プッシュ通知ハンドラ
 * @brief デバイス上でプッシュ通知をタップした際の挙動を制御します。
 * @param userInfo 通知情報ディクショナリ
 * @param option プッシュ通知オプション
 * @param customViewController URL表示にAppiariesSDKの組み込みWebViewControllerの代替として使用するユーザ実装のUIViewController
 * @warning customViewControllerを用いてURLを開く場合は、オプションに APISPushNotificationOptionOpenURL を指定する必要があります。
 * @since AppiariesSDK 1.2.0
 */
- (void)handlePushNotification:(NSDictionary *)userInfo option:(APISPushNotificationOption)option customViewController:(UIViewController<APISPushNotificationSupport> *)customViewController;

@end



/**
 * アピアリーズ・プッシュ通知サポート
 * @brief handlePushNotification:option:customViewController: のcustomViewControllerに実装する必要があります。
 * @since AppiariesSDK 1.2.0
 */
@protocol APISPushNotificationSupport <NSObject>
#pragma mark - Properties
/** @name Properties */
/**
 * APIWebViewController用delegate
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) id<APISWebViewControllerDelegate> apisWebViewDelegate;

#pragma mark - Support methods
/** @name Support methods */
@required
/**
 * 指定イニシャライザ
 * @brief UIViewController オブジェクトを生成して返します。
 * @param url NSURL オブジェクト
 * @return UIViewController オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithURL:(NSURL *)url;
@end
