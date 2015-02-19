//
//  APISQueryCondition.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/13.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

@class APISLocation;

/**
 * 検索条件オブジェクト
 *
 * Reference: http://docs.appiaries.com/v1/api/datastore/conditions
 *
 * @since AppiariesSDK 1.2.0
 */
@interface APISQueryCondition : NSObject
#pragma mark - Public methods
/** @name Public methods */
/**
 * 存在チェック条件を追加する
 * @brief 存在チェック条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setExistValue:(BOOL)value forKey:(NSString *)key;
/**
 * "="チェック条件を追加する
 * @brief "="チェック条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setEqualValue:(id)value forKey:(NSString *)key;
/**
 * "!="条件を追加する
 * @brief "!="条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setNotEqualValue:(id)value forKey:(NSString *)key;
/**
 * BOOL値の"="条件を追加する
 * @brief BOOL値の"="条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setIsValue:(BOOL)value forKey:(NSString *)key;
/**
 * BOOL値の"!="条件を追加する
 * @brief BOOL値の"!="条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setIsNotValue:(BOOL)value forKey:(NSString *)key;
/**
 * "<"条件を追加する
 * @brief "<"条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setLessThanValue:(id)value forKey:(NSString *)key;
/**
 * "<="条件を追加する
 * @brief "<="条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setLessThanEqualValue:(id)value forKey:(NSString *)key;
/**
 * ">"条件を追加する
 * @brief ">"条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setGreaterThanValue:(id)value forKey:(NSString *)key;
/**
 * ">="条件を追加する
 * @brief ">="条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setGreaterThanEqualValue:(id)value forKey:(NSString *)key;
/**
 * 開始値条件を追加する
 * @brief 開始値条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setStartWithValue:(NSString *)value forKey:(NSString *)key;
/**
 * 非開始値条件を追加する
 * @brief 非開始値条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setNotStartWithValue:(NSString *)value forKey:(NSString *)key;
/**
 * between条件を追加する
 * @brief between条件を追加します。
 * @param value 検索値
 * @param key   検索キー
 * @since AppiariesSDK 1.2.0
 */
- (void)setInValue:(NSArray *)value forKey:(NSString *)key;
/**
 * 円形位置情報条件を追加する
 * @brief 円形位置情報条件を追加します。<br/>
 *        中心座標から半径<半径>kmの円に収まるもの位置情報を持つデータが抽出対象となります。
 * @param location 位置情報オブジェクト
 * @since AppiariesSDK 1.2.0
 */
- (void)setWithInCircle:(APISLocation *)location;
/**
 * 矩形位置情報条件を追加する
 * @brief 矩形位置情報条件を追加します。<br/>
 *        座標1(locationA)と座標2(locationB)を角とする傾いていない矩形に収まる位置情報を持つデータが抽出対象となります。
 * @param locationA  位置情報オブジェクトA
 * @param locationB  位置情報オブジェクトB
 * @since AppiariesSDK 1.2.0
 */
- (void)setWithInBox:(APISLocation *)locationA target:(APISLocation *)locationB;
/**
 * ポリゴン位置情報条件を追加する
 * @brief ポリゴン位置情報条件を追加します。<br/>
 *        座標1(longitudes[0],latitudes[0]), ... , 座標n, 座標1を結んだポリゴンに収まる位置情報を持つデータが抽出対象となります。
 * @param longitudes 経度配列
 * @param latitudes  緯度配列
 * @since AppiariesSDK 1.2.0
 */
- (void)setWithInPolygonWithLongitudes:(NSArray *)longitudes latitudes:(NSArray *)latitudes;
/**
 * 検索条件文字列を返す
 * @brief 検索条件文字列を返します。
 * @return 検索条件文字列
 * @since AppiariesSDK 1.2.0
 */
- (NSString *)string;

#pragma mark - Public methods (Class methods)
/** @name Public methods (Class methods) */
/**
 * リクエスト・パラメータの組み立て
 * @brief リクエスト・パラメータを組み立てます。
 * @param value パラメータ値
 * @param operator 条件演算子
 * @param key パラメータキー
 * @return リクエスト・パラメータ文字列
 */
+ (NSString *)buildRequestParameterWithValue:(id)value operator:(NSString *)operator forKey:(NSString *)key;
/**
 * リクエスト・パラメータの組み立て
 * @brief リクエスト・パラメータを組み立てます。
 * @param value パラメータ値
 * @return リクエスト・パラメータ文字列
 */
+ (NSString *)buildRequestParameterStringWithValue:(id)value;

@end
