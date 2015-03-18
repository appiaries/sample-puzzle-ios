//
//  AppiariesEntity.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/05/01.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <AppiariesSDK/NSError+AppiariesSDK.h>
#import <AppiariesSDK/APISResponseObject.h>

/**
 * セレクタで返却するオブジェクト
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseObject instead.
 */
__attribute__ ((deprecated))
@interface AppiariesEntity : NSObject
#pragma mark - Properties
/** @name Properties */
/**
 * AppiariesConstConnectionResponse.h に定義されたステータスコード
 * @since AppiariesSDK 1.0.0
 */
@property (nonatomic) NSInteger statusCode;
/**
 * 位置情報
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *location;
/**
 * APIレスポンス
 * @since AppiariesSDK 1.0.0
 */
@property (strong, nonatomic) NSDictionary *entity;

@end
