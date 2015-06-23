//
// Created by Appiaries Corporation on 15/03/18.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 Twitter セッション
 */
@interface ABTwitterSession : NSObject <NSCoding>
#pragma mark - Properties
/*! @name Properties */
/*!
 Twitter アクセストークン
 */
@property (nonatomic, copy) NSString *authToken;
/*!
 Twitter トークン・シークレット
 */
@property (nonatomic, copy) NSString *authTokenSecret;
/*!
 ユーザID (Twitter ID)
 */
@property (nonatomic, copy) NSString *userId;
/*!
 スクリーンネーム
 */
@property (nonatomic, copy) NSString *screenName;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABTwitterSession のシングルトン・インスタンスを返す
 @return ABTwitterSession のシングルトン・インスタンス
 */
+ (instancetype)sharedSession;

#pragma mark - Public methods
/*! @name Public methods */
/*!
 セッションを無効にする
 */
- (void)invalidate;

@end