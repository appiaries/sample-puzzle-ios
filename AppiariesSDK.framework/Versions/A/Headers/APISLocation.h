//
//  APISLocation.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/13.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 * 位置情報オブジェクト
 * @since AppiariesSDK 1.2.0
 */
@interface APISLocation : NSObject
#pragma mark - Properties
/** @name Properties */
/**
 * 経度
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) CGFloat longitude;
/**
 * 緯度
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) CGFloat latitude;
/**
 * 半径
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) CGFloat radius;

@end
