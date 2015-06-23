//
//  ABTwitterClient.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/12/01.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABTwitterConfig;
@class ABError;
@class ABTwitterSession;


/*
 ABTwitterClient 用コールバック・ブロック
 */
typedef void (^ABTwitterClientCallbackBlock)(BOOL isValid, ABError *error);


/*
 Twitter API クライアント
 */
@interface ABTwitterClient : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*
 ABTwitterClient のシングルトンインスタンスを返す
 @return ABTwitterClient のシングルトンインスタンス
 */
+ (instancetype)sharedClient;

#pragma mark - Public methods
/*! @name Public methods */
/*
 OAuthによる認証を行いアクセストークンを取得する
 @discussion OAuthによる認証を行いアクセストークンを取得します。
 @param block ABResultBlock コールバック・ブロック
 @param cancelBlock ABVoidBlock キャンセル・ブロック
 */
- (void)authorizeWithBlock:(ABResultBlock)block cancel:(ABVoidBlock)cancelBlock;

@end
