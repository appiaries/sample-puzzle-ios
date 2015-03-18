//
//  APISAppUserAPIClient.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/11.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "APISConstants.h"

@class APISQueryCondition;
@class APISResponseObject;
@class APISAppUser;
@class APISSession;

/**
 * 会員APIクラス
 * @discussion 会員（アプリ会員）を操作する際に使用します。
 * @since AppiariesSDK 1.2.0
 */
@interface APISAppUserAPIClient : NSObject
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
 * @brief APISAppUserAPIClient オブジェクトを生成して返します。
 * @param session APISSessionオブジェクト
 * @return APISAppUserAPIClient オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initWithSession:(APISSession *)session;

#pragma mark - APIs
/** @name APIs */
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param email 会員のメールアドレス
 * @param attributes カスタム属性（アプリ制作者が任意に指定することができる属性群です）
 * @since AppiariesSDK 1.2.0
 */
- (void)createAppUserWithLoginId:(NSString *)loginId password:(NSString *)password email:(NSString *)email attributes:(NSDictionary *)attributes;
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param email 会員のメールアドレス
 * @param attributes カスタム属性（アプリ制作者が任意に指定することができる属性群です）
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)createAppUserWithLoginId:(NSString *)loginId password:(NSString *)password email:(NSString *)email attributes:(NSDictionary *)attributes target:(id)target action:(SEL)action;
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param email 会員のメールアドレス
 * @param attributes カスタム属性（アプリ制作者が任意に指定することができる属性群です）
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)createAppUserWithLoginId:(NSString *)loginId password:(NSString *)password email:(NSString *)email attributes:(NSDictionary *)attributes success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param email 会員のメールアドレス
 * @since AppiariesSDK 1.4.0
 */
- (void)createAppUserWithEmail:(NSString *)email;
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param email 会員のメールアドレス
 * @param target コールバック先オブジェクト
 * @param action コールバックハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)createAppUserWithEmail:(NSString *)email target:(id)target action:(SEL)action;
/**
 * 会員作成API
 * @brief アプリに紐づく会員を登録します。
 * @param email 会員のメールアドレス
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)createAppUserWithEmail:(NSString *)email success:(void(^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員取得API
 * @brief アプリに紐づく会員を取得します。
 * @param appUserId 会員ID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveAppUserWithId:(NSString *)appUserId target:(id)target action:(SEL)action;
/**
 * 会員取得API
 * @brief アプリに紐づく会員を取得します。
 * @param appUserId 会員ID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)retrieveAppUserWithId:(NSString *)appUserId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員更新API
 * @brief アプリに紐づく会員を更新します。
 * @param appUser 更新対象の会員オブジェクト
 * @warning appUser.attributes から特定属性を削除する場合は、appUser.unsetAttributes に削除する属性を指定してください。
 * @since AppiariesSDK 1.2.0
 */
- (void)updateAppUser:(APISAppUser *)appUser;
/**
 * 会員更新API
 * @brief アプリに紐づく会員を更新します。
 * @param appUser 更新対象の会員オブジェクト
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @warning appUser.attributes から特定属性を削除する場合は、appUser.unsetAttributes に削除する属性を指定してください。
 * @since AppiariesSDK 1.2.0
 */
- (void)updateAppUser:(APISAppUser *)appUser target:(id)target action:(SEL)action;
/**
 * 会員更新API
 * @brief アプリに紐づく会員を更新します。
 * @param appUser 更新対象の会員オブジェクト
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)updateAppUser:(APISAppUser *)appUser success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員削除API
 * @brief アプリに紐づく会員を削除します。
 * @param appUserId 会員ID
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserWithId:(NSString *)appUserId;
/**
 * 会員削除API
 * @brief アプリに紐づく会員を削除します。
 * @param appUserId 会員ID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserWithId:(NSString *)appUserId target:(id)target action:(SEL)action;
/**
 * 会員削除API
 * @brief アプリに紐づく会員を削除します。
 * @param appUserId 会員ID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserWithId:(NSString *)appUserId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員のメールアドレス削除API
 * @brief アプリに紐づく会員のメールアドレスを削除します。
 * @param appUserId 会員ID
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserEmailWithId:(NSString *)appUserId;
/**
 * 会員のメールアドレス削除API
 * @brief アプリに紐づく会員のメールアドレスを削除します。
 * @param appUserId 会員ID
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserEmailWithId:(NSString *)appUserId target:(id)target action:(SEL)action;
/**
 * 会員のメールアドレス削除API
 * @brief アプリに紐づく会員のメールアドレスを削除します。
 * @param appUserId 会員ID
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)deleteAppUserEmailWithId:(NSString *)appUserId success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @since AppiariesSDK 1.2.0
 */
- (void)loginWithLoginId:(NSString *)loginId password:(NSString *)password autoLogin:(BOOL)autoLogin;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)loginWithLoginId:(NSString *)loginId password:(NSString *)password autoLogin:(BOOL)autoLogin target:(id)target action:(SEL)action;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param loginId 会員のログインID
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)loginWithLoginId:(NSString *)loginId password:(NSString *)password autoLogin:(BOOL)autoLogin success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param email 会員のメールアドレス
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @since AppiariesSDK 1.4.0
 */
- (void)loginWithEmail:(NSString *)email password:(NSString *)password autoLogin:(BOOL)autoLogin;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param email 会員のメールアドレス
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)loginWithEmail:(NSString *)email password:(NSString *)password autoLogin:(BOOL)autoLogin target:(id)target action:(SEL)action;
/**
 * 会員ログインAPI
 * @brief アプリに会員でログインします。
 * @param email 会員のメールアドレス
 * @param password 会員のパスワード
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)loginWithEmail:(NSString *)email password:(NSString *)password autoLogin:(BOOL)autoLogin success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * SNS経由の会員ログインAPI
 * @brief SNSのアカウントを使用してアプリにログインします。会員が作成されていない場合は新規作成されます。
 * @param provider SNSプロバイダ
 * @param authData 認証データ
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.3.0
 * @deprecated use <a href="#//api/name/loginWithAuthenticationProvider:authData:autoLogin:target:action:">loginWithAuthenticationProvider:authData:autoLogin:target:action:</a> instead.
 */
- (void)loginViaSNS:(APISSNSProvider)provider authData:(NSDictionary *)authData autoLogin:(BOOL)autoLogin target:(id)target action:(SEL)action DEPRECATED_ATTRIBUTE;
/**
 * SNS経由の会員ログインAPI
 * @brief SNSのアカウントを使用してアプリにログインします。会員が作成されていない場合は新規作成されます。
 * @param provider SNSプロバイダ
 * @param authData 認証データ
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.3.0
 * @deprecated use <a href="#//api/name/loginWithAuthenticationProvider:authData:autoLogin:success:failure:">loginWithAuthenticationProvider:authData:autoLogin:success:failure:</a> instead.
 */
- (void)loginViaSNS:(APISSNSProvider)provider authData:(NSDictionary *)authData autoLogin:(BOOL)autoLogin success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler DEPRECATED_ATTRIBUTE;
/**
 * 会員ログインAPI
 * @brief 認証プロバイダを指定してアプリにログインします。<br/>認証プロバイダには、Facebook／Twitter／匿名会員(Anonymous)の３種類が存在します。<br/>尚、メソッド実行時点で会員が未登録であった場合は新規に会員が作成されます。
 * @param provider 認証プロバイダ
 * @param authData 認証データ
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)loginWithAuthenticationProvider:(APISAuthenticationProvider)provider authData:(NSDictionary *)authData autoLogin:(BOOL)autoLogin target:(id)target action:(SEL)action;
/**
 * 会員ログインAPI
 * @brief 認証プロバイダを指定してアプリにログインします。<br/>認証プロバイダには、Facebook／Twitter／匿名会員(Anonymous)の３種類が存在します。<br/>尚、メソッド実行時点で会員が未登録であった場合は新規に会員が作成されます。
 * @param provider 認証プロバイダ
 * @param authData 認証データ
 * @param autoLogin 自動ログインフラグ（YES=自動ログインする）
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.4.0
 */
- (void)loginWithAuthenticationProvider:(APISAuthenticationProvider)provider authData:(NSDictionary *)authData autoLogin:(BOOL)autoLogin success:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 自動ログインAPI
 * @brief アプリに会員で自動ログインします。
 * @since AppiariesSDK 1.2.0
 */
- (void)autoLogin;
/**
 * 自動ログインAPI
 * @brief アプリに会員で自動ログインします。
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)autoLoginWithTarget:(id)target action:(SEL)action;
/**
 * 自動ログインAPI
 * @brief アプリに会員で自動ログインします。
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)autoLoginWithSuccess:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;
/**
 * 会員ログアウトAPI
 * @brief アプリからログアウトします。
 * @since AppiariesSDK 1.2.0
 */
- (void)logout;
/**
 * 会員ログアウトAPI
 * @brief アプリからログアウトします。
 * @param target    コールバック先オブジェクト
 * @param action    コールバックハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)logoutWithTarget:(id)target action:(SEL)action;
/**
 * 会員ログアウトAPI
 * @brief アプリからログアウトします。
 * @param successHandler 成功時実行ハンドラ
 * @param failureHandler 失敗時実行ハンドラ
 * @since AppiariesSDK 1.2.0
 */
- (void)logoutWithSuccess:(void (^)(APISResponseObject *response))successHandler failure:(void(^)(NSError *error))failureHandler;

@end
