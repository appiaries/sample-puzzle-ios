//
//  APISResponseObject.h
//  AppiariesSDK
//
// Created by Appiaries Corporation on 2014/08/25.
// Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * APIバージョン
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISAPIVersion;

/**
 * SDKバージョン
 */
extern NSString *APISSDKVersion;

/**
 * アピアリーズ Web API レスポンスコード
 */
typedef NS_ENUM(NSInteger, APISResponseStatusCode) {
    /**
     * レスポンスコード - OK (200)
     * <br/>ケース: 検索成功, 一括削除成功
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeOK = 200,
    /**
     * レスポンスコード - 作成成功 (201)
     * <br/>ケース: 登録成功, 置き換え登録成功
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeCreated = 201,
    /**
     * レスポンスコード - 成功(返却値なし) (204)
     * <br/>ケース: 更新成功, 削除成功, プッシュ通知成功
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeNoContent = 204,
    /**
     * レスポンスコード - 不正なリクエスト
     * <br/>ケース: 不正なフォーマット (Content unspecified, content format invalid)
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeBadRequest = 400,
    /**
     * レスポンスコード - 認証失敗または未認証
     * <br/>ケース: トークン未指定, 認証失敗 (Token unspecified, Authentication failure)
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeUnauthorized = 401,
    /**
     * レスポンスコード - リクエスト拒否
     * <br/>ケース: アプリにアクセスする権限がない, コレクションにcreate権限がない, コレクションに格納可能なオブジェクトが"JSONオブジェクト"ではない (No permission to access the app. No permission to create in the collection. The object that can be stored in the collection is not "JSON Data".)
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeForbidden = 403,
    /**
     * レスポンスコード - 対象が見つからない
     * <br/>ケース: コレクション未作成
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeNotFound = 404,
    /**
     * レスポンスコード - コンフリクト
     * <br/>ケース: オブジェクト登録済み
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeConflict = 409,
    /**
     * レスポンスコード - 前提条件失敗
     * <br/>ケース: コントロールパネル上で設定が有効化されていない
     * @since AppiariesSDK 1.4.0
     */
    APISResponseStatusCodePreconditionFailed = 412,
    /**
     * レスポンスコード - サイズ超過
     * <br/>ケース: オブジェクトサイズ上限超え
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeRequestEntityTooLarge = 413,
    /**
     * レスポンスコード - 処理不可
     * <br/>ケース: コンテント不適切
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeUnprocessableEntity = 422,
    /**
     * レスポンスコード - ロックされている
     * <br/>ケース: アカウントがロックされている
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeLocked = 423,
    /**
     * レスポンスコード - 内部サーバエラー
     * <br/>ケース: 予期しないエラー (Unexpected error)
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInternalServerError = 500,
    /**
     * レスポンスコード - ストレージ容量不足
     * <br/>ケース: 使用可能ストレージ容量超過 (Available storage capacity exceeded)
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInsufficientStorage = 507,
    /**
     * レスポンスコード - 通信エラー (connection error)
     * <br/>ケース: ネットワーク接続不可環境下でのAPI呼び出し, 通信瞬断
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeHttpConnectionError = 1001,
    /**
     * レスポンスコード - 不正なID (invalid id)
     * <br/>ケース: IDとして許可していない文字列を含むIDの取得・生成
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInvalidId = -1,
    /**
     * レスポンスコード - 不正なトークン (invalid token)
     * <br/>ケース: トークンとして許可していない文字列を含むトークンの取得・生成
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInvalidToken = -1001,
    /**
     * レスポンスコード - 不正なパスコンポーネント (invalid path component)
     * <br/>ケース: URIとして許可していない文字列を含むURIの取得・生成
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInvalidPathSegment = -1002,
    /**
     * レスポンスコード - 不正な引数 (invalid argument)
     * <br/>ケース: 引数として許可していない文字列を含む引数が渡された場合
     * @since AppiariesSDK 1.2.0
     */
    APISResponseStatusCodeInvalidArgument = -1003,
    /**
     * レスポンスコード - 認証キャンセル (authentication cancelled)
     * <br/>ケース: SNS連携でログインをキャンセルした場合
     * @since AppiariesSDK 1.3.0
     */
    APISResponseStatusCodeAuthenticationCancelled = -1004,
};

/**
 * レスポンス・メッセージ - OK (200)
 * <br/>ケース: 検索成功, 一括削除成功
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeOKMessage;
/**
 * レスポンス・メッセージ - 作成成功 (201)
 * <br/>ケース: 登録成功, 置き換え登録成功
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeCreatedMessage;
/**
 * レスポンス・メッセージ - 成功(返却値なし) (204)
 * <br/>ケース: 更新成功, 削除成功, プッシュ通知成功
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeNoContentMessage;
/**
 * レスポンス・メッセージ - 不正なリクエスト
 * <br/>ケース: 不正なフォーマット (Content unspecified, content format invalid)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeBadRequestMessage;
/**
 * レスポンス・メッセージ - 認証失敗または未認証
 * <br/>ケース: トークン未指定, 認証失敗 (Token unspecified, Authentication failure)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeUnauthorizedMessage;
/**
 * レスポンス・メッセージ - リクエスト拒否
 * <br/>ケース: アプリにアクセスする権限がない, コレクションにcreate権限がない, コレクションに格納可能なオブジェクトが"JSONオブジェクト"ではない (No permission to access the app. No permission to create in the collection. The object that can be stored in the collection is not "JSON Data".)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeForbiddenMessage;
/**
 * レスポンス・メッセージ - 対象が見つからない
 * <br/>ケース: コレクション未作成
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeNotFoundMessage;
/**
 * レスポンス・メッセージ - コンフリクト
 * <br/>ケース: オブジェクト登録済み
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeConflictMessage;
/**
 * レスポンス・メッセージ - 前提条件失敗
 * <br/>ケース: コントロールパネルで設定が有効化されていない
 * @since AppiariesSDK 1.4.0
 */
extern NSString *APISResponseStatusCodePreconditionFailedMessage;
/**
 * レスポンス・メッセージ - サイズ超過
 * <br/>ケース: オブジェクトサイズ上限超え
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeRequestEntityTooLargeMessage;
/**
 * レスポンス・メッセージ - 処理不可
 * <br/>ケース: コンテント不適切
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeUnprocessableEntityMessage;
/**
 * レスポンス・メッセージ - ロックされている
 * <br/>ケース: アカウントがロックされている
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeLockedMessage;
/**
 * レスポンス・メッセージ - 内部サーバエラー
 * <br/>ケース: 予期しないエラー (Unexpected error)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInternalServerErrorMessage;
/**
 * レスポンス・メッセージ - ストレージ容量不足
 * <br/>ケース: 使用可能ストレージ容量超過 (Available storage capacity exceeded)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInsufficientStorageMessage;
/**
 * レスポンス・メッセージ - 通信エラー (connection error)
 * <br/>ケース: ネットワーク接続不可環境下でのAPI呼び出し, 通信瞬断
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeHttpConnectionErrorMessage;
/**
 * レスポンス・メッセージ - 不正なID (invalid id)
 * <br/>ケース: IDとして許可していない文字列を含むIDの取得・生成
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInvalidIdMessage;
/**
 * レスポンス・メッセージ - 不正なトークン (invalid token)
 * <br/>ケース: トークンとして許可していない文字列を含むトークンの取得・生成
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInvalidTokenMessage;
/**
 * レスポンス・メッセージ - 不正なパスコンポーネント (invalid path component)
 * <br/>ケース: URIとして許可していない文字列を含むURIの取得・生成
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInvalidPathSegmentMessage;
/**
 * レスポンス・メッセージ - 不正な引数 (invalid argument)
 * <br/>ケース: 引数として許可していない文字列を含む引数が渡された場合
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseStatusCodeInvalidArgumentMessage;

#pragma mark - Constants (for JSON object)
/** @name Constants for JSON object */
/**
 * JSONオブジェクト - オブジェクトID - null, 空文字 (0060101)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectIdIsEmpty;
/**
 * JSONオブジェクト - オブジェクトID - 文字列ではない (0060102)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectIdIsNotValidString;
/**
 * JSONオブジェクト - オブジェクトID - URI 書式が間違っている (0060104)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectIdIsInvalidFormat;
/**
 * JSONオブジェクト - オブジェクトID - オブジェクトIDが使用済み (0060109)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectDuplicateId;
/**
 * JSONオブジェクト - コンテントボディ - コンテント名不適切 (0060002)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectContentBodyInvalidContentName;
/**
 * JSONオブジェクト - コンテントボディ - LF, CR, TAB を除く制御文字が含まれている (0060011)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectContentBodyContainedControlCharacter;
/**
 * JSONオブジェクト - フィールド全般 - フィールド不足 (0070001)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectMissingField;
/**
 * JSONオブジェクト - フィールド全般 - フィールド名不適切 (0070002)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeJsonObjectInvalidFieldName;

#pragma mark - Constants (for File object)
/** @name Constants for File object */
/**
 * バイナリオブジェクト - オブジェクトID - null, 空文字 (0070101)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectIdIsEmpty;
/**
 * バイナリオブジェクト - オブジェクトID - 文字列ではない (0070102)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectIdIsNotValidString;
/**
 * バイナリオブジェクト - オブジェクトID - URI書式ではない (0070104)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectIdIsNotUriFormat;
/**
 * バイナリオブジェクト - オブジェクトID - 使用済みのオブジェクトID (0070109)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectDuplicateId;
/**
 * バイナリオブジェクト - ファイル - null, サイズが0 (0070201)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectSizeIsZero;
/**
 * バイナリオブジェクト - ファイル - バイナリではない (0070202)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectIsNotBinary;
/**
 * バイナリオブジェクト - ファイル名 - null, 空文字 (0070301)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectNameIsNotValidString;
/**
 * バイナリオブジェクト - ファイル名 - 文字列ではない (0070302)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectNameIsEmpty;
/**
 *  バイナリオブジェクト - ファイル名 - LF, CR, TABを除く制御文字が含まれている (0070303)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectNameContainedControlCharacter;
/**
 * バイナリオブジェクト - コンテントタイプ - null, 空文字 (0070401)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectContentTypeIsEmpty;
/**
 * バイナリオブジェクト - コンテントタイプ - 文字列ではない (0070402)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectContentTypeIsNotString;
/**
 * バイナリオブジェクト - コンテントタイプ - LF, CR, TABを除く制御文字が含まれている (0070403)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectContentTypeContainedControlCharacter;
/**
 * バイナリオブジェクト - タグ - null, 空文字 (0071001)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectTagsIsEmpty;
/**
 * バイナリオブジェクト - タグ - 配列ではない (0071002)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectTagsIsNotArray;
/**
 * バイナリオブジェクト - タグ - 配列がnull (0071005)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectTagsIsEmptyArray;
/**
 * バイナリオブジェクト - タグ - 配列が文字列ではない (0071006)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectTagsIsNotValidString;
/**
 * バイナリオブジェクト - タグ - 配列の要素数超過(要素数が10以上) (0071007)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodeFileObjectTagsCapacityExceeded;

#pragma mark - Constants (for Push Notification)
/** @name Constants for Push Notification */
/**
 * プッシュ通知 - プッシュIDが空の場合のエラーコード (008100)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationIdIsEmpty;
/**
 * プッシュ通知 - プッシュIDが数値でない場合のエラーコード (0081002)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationIdIsNotNumeric;
/**
 * プッシュ通知 - フィールド不足のエラーコード (0080001)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationMissingField;
/**
 * プッシュ通知 - フィールド名が不適切場合のエラーコード (0080002)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationInvalidFieldName;
/**
 * プッシュ通知 - デバイスIDが空の場合のエラーコード (0081101)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationDeviceIdIsEmpty;
/**
 * プッシュ通知 - デバイスIDが文字列でない場合のエラーコード (0081102)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationDeviceIdIsNotValidString;
/**
 * プッシュ通知 - デバイス属性に制御文字が含まれている場合のエラーコード (0080103)
 * @since AppiariesSDK 1.2.0
 */
extern NSString *APISResponseDetailCodePushNotificationDeviceAttributesContainedControlCharacter;


/**
 * アピアリーズ Web API レスポンス・オブジェクト
 * @since AppiariesSDK 1.0.0
 */
@interface APISResponseObject : NSObject
#pragma mark - Properties
/** @name Properties */
/**
 * アピアリーズ Web API レスポンスコード
 * @since AppiariesSDK 1.0.0
 */
@property (nonatomic) APISResponseStatusCode statusCode;
/**
 * ロケーションヘッダ
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) NSString *location;
/**
 * APIレスポンス
 * @since AppiariesSDK 1.0.0
 */
@property (strong, nonatomic) NSDictionary *data;
/**
 * API実行結果が成功かどうか (YES=成功, NO=失敗)
 * @since AppiariesSDK 1.0.0
 */
@property (nonatomic, readonly, getter=isSuccess) BOOL success;

@end
