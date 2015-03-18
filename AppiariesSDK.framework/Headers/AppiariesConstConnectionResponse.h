//
//  AppiariesConstConnectionResponse.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/04/22.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

__attribute__ ((deprecated))

#ifndef AppiariesSDK_AppiariesConstConnectionResponse_h
#define AppiariesSDK_AppiariesConstConnectionResponse_h

/**
 * Appiaries API 通信レスポンスコード
 */

/**
 * 成功 (Success)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeNoContent instead.
 */
#define APPIARIES_RESPONSE_SUCCESS                   APISResponseStatusCodeNoContent

/**
 * 不正なフォーマット (Content unspecified, content format invalid)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeBadRequest instead.
 */
#define APPIARIES_RESPONSE_FORMAT_INVALID            APISResponseStatusCodeBadRequest

/**
 * トークン未指定, 認証失敗 (Token unspecified, Authentication failure)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeUnauthorized instead.
 */
#define APPIARIES_RESPONSE_AUTH_ERROR                APISResponseStatusCodeUnauthorized

/**
 * 権限エラー
 * @brief アプリにアクセスする権限がない。コレクションに create 権限がない。コレクションに格納可能なオブジェクトが"JSONオブジェクト"ではない。
 *        (No permission to access the app. No permission to create in the collection. The object that can be stored in the collection is not "JSON Data".)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeForbidden instead.
 */
#define APPIARIES_RESPONSE_PERMISSION_ERROR          APISResponseStatusCodeForbidden

/**
 * コンテント値不適切
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeUnprocessableEntity instead.
 */
#define APPIARIES_RESPONSE_VALUE_INVALID             APISResponseStatusCodeUnprocessableEntity

/**
 * 予期せぬエラー発生 (Unexpected error)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeInternalServerError instead.
 */
#define APPIARIES_RESPONSE_UNEXPECTED_ERROR          APISResponseStatusCodeInternalServerError

/**
 * 使用可能ストレージ容量超過 (Available storage capacity exceeded)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeInsufficientStorage instead.
 */
#define APPIARIES_RESPONSE_STORAGE_OVER              APISResponseStatusCodeInsufficientStorage

/**
 * 通信エラー (connection error)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeHttpConnectionError instead.
 */
#define HTTP_CONNECTION_ERROR   APISResponseStatusCodeHttpConnectionError

/**
 * 不正なID (invalid id)
 * @since AppiariesSDK 1.0.0
 * @deprecated use APISResponseStatusCodeInvalidId instead.
 */
#define APPIARIES_INVALID_ID    APISResponseStatusCodeInvalidId

#endif
