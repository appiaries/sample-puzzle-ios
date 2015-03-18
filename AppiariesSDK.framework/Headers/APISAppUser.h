//
//  APISAppUser.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/09/05.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//


/**
 * 会員オブジェクト
 * @since AppiariesSDK 1.2.0
 */
@interface APISAppUser : NSObject <NSCopying, NSCoding>
#pragma mark - Properties
/** @name Properties */
/**
 * 会員ID
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *id;
/**
 * 会員のログインID
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *loginId;
/**
 * 会員のログインパスワード
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *password;
/**
 * 会員のメールアドレス
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *email;
/**
 * 会員のカスタム属性
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSDictionary *attributes;
/**
 * 会員の削除対象カスタム属性リスト
 * @warning 会員のカスタム属性から任意属性を削除する際に指定します。
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSArray *unsetAttributes;
/**
 * 会員のストアトークン
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *storeToken;
/**
 * 自動ログインフラグ (YES=自動ログインする)
 * @since AppiariesSDK 1.4.0
 */
@property (nonatomic) BOOL autoLogin;
/**
* 認証データ
* @since AppiariesSDK 1.3.0
*/
@property (strong, nonatomic) NSDictionary *authData;

#pragma mark - Initialization
/** @name Initialization */
/**
 * 指定イニシャライザ
 * @brief ディクショナリから APISAppUser オブジェクトを生成して返します。
 * @param dictionary APISAppUser のプロパティにマッピングする、プロパティ名をキーとしたディクショナリ
 * @return APISAppUser オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initFromDictionary:(NSDictionary *)dictionary;
/**
 * 指定イニシャライザ
 * @brief ディクショナリから APISAppUser オブジェクトを生成して返します。
 * @param dictionary APISAppUser のプロパティにマッピングする、プロパティ名をキーとしたディクショナリ
 * @param map 引数dictionaryのキーを変換するためのディクショナリ（キーがプロパティ名、値がdictionaryのキー名となります）
 * @return APISAppUser オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (id)initFromDictionary:(NSDictionary *)dictionary map:(NSDictionary *)map;

@end
