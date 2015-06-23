//
// Created by Appiaries Corporation on 2015/02/21.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 座標モデル 
 @discussion 座標（位置情報）を表現するモデルです。位置情報検索機能に使用します。
 
 __See Also__: [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
@interface ABGeoPoint : NSObject
#pragma mark - Properties
/*! @name Properties */
/*!
 緯度
 */
@property (nonatomic) double latitude;
/*!
 経度
 */
@property (nonatomic) double longitude;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABGeoPoint インスタンス
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param latitude 緯度
 @param longitude 経度
 @return ABGeoPoint インスタンス
 */
- (instancetype)initWithLatitude:(double)latitude longitude:(double)longitude;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param location CLLocation オブジェクト
 @return ABGeoPoint インスタンス
 */
- (instancetype)initWithCLLocation:(CLLocation *)location;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABGeoPoint インスタンス
 */
+ (instancetype)pointWithDictionary:(NSDictionary *)dictionary;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param latitude 緯度
 @param longitude 経度
 @return ABGeoPoint インスタンス
 */
+ (instancetype)pointWithLatitude:(double)latitude longitude:(double)longitude;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param location CLLocation オブジェクト
 @return ABGeoPoint インスタンス
 */
+ (instancetype)pointWithCLLocation:(CLLocation *)location;

/*!
 CLLocationCoordinate2D データを返す
 @return CLLocationCoordinate2D
 @return CLLocationCoordinate2D データ
 */
- (CLLocationCoordinate2D)locationCoordinate2D;

@end
