//
// Created by Appiaries Corporation on 15/03/17.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 Twitter 設定
 @discussion Twitter との連携に必要となる設定情報を保持します。
 <div class="important">
 設定情報は、AB#activate を実行する前にセットする必要があります。
 </div>
 */
@interface ABTwitterConfig : NSObject
#pragma mark - Properties
/*! @name Properties */
/*!
 Twitter コンシューマ・キー
 @discussion [Twitter Application Management](https://apps.twitter.com/) サイトで登録したアプリの ___コンシューマ・キー___ を指定します。
 */
@property (nonatomic, copy) NSString *consumerKey;
/*!
 Twitter コンシューマ・シークレット
 @discussion [Twitter Application Management](https://apps.twitter.com/) サイトで登録したアプリの ___コンシューマ・シークレット___ を指定します。
 */
@property (nonatomic, copy) NSString *consumerSecret;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABTwitterConfig のシングルトン・インスタンスを返す
 @return ABTwitterConfig のシングルトン・インスタンス
 */
+ (instancetype)sharedConfig;

@end