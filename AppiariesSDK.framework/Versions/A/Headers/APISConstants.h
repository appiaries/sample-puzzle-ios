//
//  APISConstants.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/11/20.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APISResponseObject;

/**
 * 汎用コールバック・ブロック
 * @brief APISResponseObject を引数にとる汎用コールバック・ブロックです。
 * @since AppiariesSDK 1.3.0
 */
typedef void (^APISGenericCallbackBlock)(APISResponseObject *result, NSError *error);

/**
 * BOOL値コールバック・ブロック
 * @brief BOOL値を引数にとる汎用コールバック・ブロックです。
 * @since AppiariesSDK 1.3.0
 */
typedef void (^APISBooleanCallbackBlock)(BOOL success, NSError *error);


/**
 * 認証プロバイダ定数
 * @brief SNS連携や匿名会員の認証に使用する認証プロバイダの定数です。
 * @since AppiariesSDK 1.4.0
 */
typedef NS_ENUM(NSUInteger, APISAuthenticationProvider) {
    /**
     * 認証プロバイダ (不明)
     * @since AppiariesSDK 1.4.0
     */
    APISAuthenticationProviderUnknown = 0,
    /**
     * 認証プロバイダ (匿名会員)
     * @since AppiariesSDK 1.4.0
     */
    APISAuthenticationProviderAnonymous,
    /**
     * 認証プロバイダ (SNS:Facebook)
     * @since AppiariesSDK 1.4.0
     */
    APISAuthenticationProviderFacebook,
    /**
     * 認証プロバイダ (SNS:Twitter)
     * @since AppiariesSDK 1.4.0
     */
    APISAuthenticationProviderTwitter,
};
#define APISAuthenticationProviderUnknownKey @"unknown"
#define APISAuthenticationProviderAnonymousKey @"anonymous"
#define APISAuthenticationProviderFacebookKey @"facebook"
#define APISAuthenticationProviderTwitterKey @"twitter"

/*
 * SNSプロバイダ定数
 * @brief SNS連携の認証に使用する認証プロバイダの定数です。
 * @since AppiariesSDK 1.3.0
 * @deprecated use APISAuthenticationProvider instead.
 */
typedef enum {
    /**
     * SNSプロバイダ (不明)
     * @since AppiariesSDK 1.3.0
     */
    APISSNSProviderUnknown __attribute__((deprecated("use APISAuthenticationProviderUnknown instead."))) = APISAuthenticationProviderUnknown,
    /**
     * SNSプロバイダ (Facebook)
     * @since AppiariesSDK 1.3.0
     */
    APISSNSProviderFacebook __attribute__((deprecated("use APISAuthenticationProviderFacebook instead."))) = APISAuthenticationProviderFacebook,
    /**
     * SNSプロバイダ (Twitter)
     * @since AppiariesSDK 1.3.0
     */
    APISSNSProviderTwitter __attribute__((deprecated("use APISAuthenticationProviderTwitter"))) = APISAuthenticationProviderTwitter,
} APISSNSProvider;
