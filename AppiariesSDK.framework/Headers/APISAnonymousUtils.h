//
//  APISAnonymousUtils.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/12/08.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APISConstants.h"

@class APISAppUser;

/**
 * 匿名会員用ユーティリティ
 * @discussion 匿名会員としてログインする際に使用します。匿名会員は通常の会員と異なり、ログインする際にログインIDとパスワード（またはメールアドレスとパスワード）を必要としません。
 * @since AppiariesSDK 1.4.0
 */
@interface APISAnonymousUtils : NSObject
#pragma mark - Public methods (LogIn)
/** @name Public methods (logIn) */

/**
 * 匿名会員としてログインする
 * @brief 匿名会員としてアプリにログインします。
 * @param autoLogin 自動ログインフラグ (YES=自動ログインする)
 * @param block コールバック・ブロック
 */
+ (void)logInWithAutoLogin:(BOOL)autoLogin block:(APISGenericCallbackBlock)block;

/**
 * 匿名会員としてログインする
 * @brief 匿名会員としてアプリにログインします。
 * @param autoLogin 自動ログインフラグ (YES=自動ログインする)
 * @param target コールバック先オブジェクト
 * @param selector コールバックハンドラ
 */
+ (void)logInWithAutoLogin:(BOOL)autoLogin target:(id)target selector:(SEL)selector;

@end
