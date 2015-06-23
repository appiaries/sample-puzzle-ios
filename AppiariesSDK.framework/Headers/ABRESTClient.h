//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;


typedef void (^ABRESTClientCallbackBlock)(ABResult *result, ABError *error);
typedef void (^ABRESTClientResponseFilterBlock)(ABResult **result, ABError **error);
typedef void (^ABRESTClientProgressBlock)(float progress);

/*!
REST API クライアント
 */
@interface ABRESTClient : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*! インタンスを返す */
+ (instancetype)client;

#pragma mark - Accessors
/*! @name Accessors */
/*! デフォルトヘッダを返す */
+ (NSDictionary *)defaultHeaders;
/*! Multipart用のデフォルトヘッダを返す */
+ (NSDictionary *)defaultMultipartHeaders;
/*! デフォルタヘッダを返す (ログイン中であれば X-APPIARIES-TOKEN にストアトークンを指定する) */
+ (NSDictionary *)defaultHeadersWithStoreTokenIfPossible;
/*! Multipart用のデフォルトヘッダを返す (ログイン中であれば X-APPIARIES-TOKEN にストアトークンを指定する) */
+ (NSDictionary *)defaultMultipartHeadersWithStoreTokenIfPossible;
/*! アップロード用のリクエストBODYを組み立てる */
+ (NSData *)buildUploadRequestBodyDataWithJSONDictionary:(NSDictionary *)json filename:(NSString *)filename fileData:(NSData *)fileData;

#pragma mark - GET
/*! @name GET */
- (Async)GET:(NSString *)url callback:(ABRESTClientCallbackBlock)callback;
- (Async)GET:(NSString *)url callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)GET:(NSString *)url customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback;
- (Async)GET:(NSString *)url customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)GET:(NSString *)url headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback;
- (Async)GET:(NSString *)url headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;

#pragma mark - PUT
/*! @name PUT */
- (Async)PUT:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback;
- (Async)PUT:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)PUT:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback;
- (Async)PUT:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)PUT:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback;
- (Async)PUT:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;

#pragma mark - POST
/*! @name POST */
- (Async)POST:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback;
- (Async)POST:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)POST:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback;
- (Async)POST:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)POST:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback;
- (Async)POST:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;

#pragma mark - DELETE
/*! @name DELETE */
- (Async)DELETE:(NSString *)url callback:(ABRESTClientCallbackBlock)callback;
- (Async)DELETE:(NSString *)url callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)DELETE:(NSString *)url customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback;
- (Async)DELETE:(NSString *)url customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)DELETE:(NSString *)url headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback;
- (Async)DELETE:(NSString *)url headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;

#pragma mark - PATCH
/*! @name PATCH */
- (Async)PATCH:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback;
- (Async)PATCH:(NSString *)url body:(NSData *)body callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)PATCH:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback;
- (Async)PATCH:(NSString *)url body:(NSData *)body customHeaders:(NSDictionary *)customHeaders callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;
- (Async)PATCH:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback;
- (Async)PATCH:(NSString *)url body:(NSData *)body headers:(NSDictionary *)headers callback:(ABRESTClientCallbackBlock)callback progressCallback:(ABRESTClientProgressBlock)progressCallback;

@end


/*!
 アピアリーズ Web API レスポンスコード
 
 __See Also__: [アピアリーズドキュメント &raquo; 共通エラー](http://docs.appiaries.com/?p=1140#i-5)
 */
typedef NS_ENUM(NSInteger, ABStatus) {
    /*!
    レスポンスコード - OK (200)
    <br/>ケース: 検索成功, 一括削除成功
     */
    ABStatusOK = 200,
    /*!
    レスポンスコード - 作成成功 (201)
    <br/>ケース: 登録成功, 置き換え登録成功
     */
    ABStatusCreated = 201,
    /*!
    レスポンスコード - 成功(返却値なし) (204)
    <br/>ケース: 更新成功, 削除成功, プッシュ通知成功
     */
    ABStatusNoContent = 204,
    /*!
    レスポンスコード - 不正なリクエスト
    <br/>ケース: 不正なフォーマット (Content unspecified, content format invalid)
     */
    ABStatusBadRequest = 400,
    /*!
    レスポンスコード - 認証失敗または未認証
    <br/>ケース: トークン未指定, 認証失敗 (Token unspecified, Authentication failure)
     */
    ABStatusUnauthorized = 401,
    /*!
    レスポンスコード - リクエスト拒否
    <br/>ケース: アプリにアクセスする権限がない, コレクションにcreate権限がない, コレクションに格納可能なオブジェクトが"JSONオブジェクト"ではない (No permission to access the app. No permission to create in the collection. The object that can be stored in the collection is not "JSON Data".)
     */
    ABStatusForbidden = 403,
    /*!
    レスポンスコード - 対象が見つからない
    <br/>ケース: コレクション未作成
     */
    ABStatusNotFound = 404,
    /*!
    レスポンスコード - コンフリクト
    <br/>ケース: オブジェクト登録済み
     */
    ABStatusConflict = 409,
    /*!
    レスポンスコード - 前提条件失敗
    <br/>ケース: コントロールパネル上で設定が有効化されていない
     */
    ABStatusPreconditionFailed = 412,
    /*!
    レスポンスコード - サイズ超過
    <br/>ケース: オブジェクトサイズ上限超え
     */
    ABStatusRequestEntityTooLarge = 413,
    /*!
    レスポンスコード - 処理不可
    <br/>ケース: コンテント不適切
     */
    ABStatusUnprocessableEntity = 422,
    /*!
    レスポンスコード - ロックされている
    <br/>ケース: アカウントがロックされている
     */
    ABStatusLocked = 423,
    /*!
    レスポンスコード - 内部サーバエラー
    <br/>ケース: 予期しないエラー (Unexpected error)
     */
    ABStatusInternalServerError = 500,
    /*!
    レスポンスコード - ストレージ容量不足
    <br/>ケース: 使用可能ストレージ容量超過 (Available storage capacity exceeded)
     */
    ABStatusInsufficientStorage = 507,
    /*!
    レスポンスコード - 通信エラー (connection error)
    <br/>ケース: ネットワーク接続不可環境下でのAPI呼び出し, 通信瞬断
     */
    ABStatusHttpConnectionError = 1001,
    /*!
    レスポンスコード - 不正なID (invalid id)
    <br/>ケース: IDとして許可していない文字列を含むIDの取得・生成
     */
    ABStatusInvalidId = -1,
    /*!
    レスポンスコード - 不正なトークン (invalid token)
    <br/>ケース: トークンとして許可していない文字列を含むトークンの取得・生成
     */
    ABStatusInvalidToken = -1001,
    /*!
    レスポンスコード - 不正なパスコンポーネント (invalid path component)
    <br/>ケース: URIとして許可していない文字列を含むURIの取得・生成
     */
    ABStatusInvalidPathSegment = -1002,
    /*!
    レスポンスコード - 不正な引数 (invalid argument)
    <br/>ケース: 引数として許可していない文字列を含む引数が渡された場合
     */
    ABStatusInvalidArgument = -1003,
    /*!
    レスポンスコード - キャンセル (operation cancelled)
    <br/>ケース: 処理をキャンセルした場合
     */
    ABStatusOperationCancelled = -1004,
};

/*!
レスポンス・メッセージ - OK (200)
<br/>ケース: 検索成功, 一括削除成功
 */
extern NSString *ABResponseStatusCodeOKMessage;
/*!
レスポンス・メッセージ - 作成成功 (201)
<br/>ケース: 登録成功, 置き換え登録成功
 */
extern NSString *ABResponseStatusCodeCreatedMessage;
/*!
レスポンス・メッセージ - 成功(返却値なし) (204)
<br/>ケース: 更新成功, 削除成功, プッシュ通知成功
 */
extern NSString *ABResponseStatusCodeNoContentMessage;
/*!
レスポンス・メッセージ - 不正なリクエスト
<br/>ケース: 不正なフォーマット (Content unspecified, content format invalid)
 */
extern NSString *ABResponseStatusCodeBadRequestMessage;
/*!
レスポンス・メッセージ - 認証失敗または未認証
<br/>ケース: トークン未指定, 認証失敗 (Token unspecified, Authentication failure)
 */
extern NSString *ABResponseStatusCodeUnauthorizedMessage;
/*!
レスポンス・メッセージ - リクエスト拒否
<br/>ケース: アプリにアクセスする権限がない, コレクションにcreate権限がない, コレクションに格納可能なオブジェクトが"JSONオブジェクト"ではない (No permission to access the app. No permission to create in the collection. The object that can be stored in the collection is not "JSON Data".)
 */
extern NSString *ABResponseStatusCodeForbiddenMessage;
/*!
レスポンス・メッセージ - 対象が見つからない
<br/>ケース: コレクション未作成
*/
extern NSString *ABResponseStatusCodeNotFoundMessage;
/*!
レスポンス・メッセージ - コンフリクト
<br/>ケース: オブジェクト登録済み
 */
extern NSString *ABResponseStatusCodeConflictMessage;
/*!
レスポンス・メッセージ - 前提条件失敗
<br/>ケース: コントロールパネルで設定が有効化されていない
 */
extern NSString *ABResponseStatusCodePreconditionFailedMessage;
/*!
レスポンス・メッセージ - サイズ超過
<br/>ケース: オブジェクトサイズ上限超え
 */
extern NSString *ABResponseStatusCodeRequestEntityTooLargeMessage;
/*!
レスポンス・メッセージ - 処理不可
<br/>ケース: コンテント不適切
 */
extern NSString *ABResponseStatusCodeUnprocessableEntityMessage;
/*!
レスポンス・メッセージ - ロックされている
<br/>ケース: アカウントがロックされている
 */
extern NSString *ABResponseStatusCodeLockedMessage;
/*!
レスポンス・メッセージ - 内部サーバエラー
<br/>ケース: 予期しないエラー (Unexpected error)
 */
extern NSString *ABResponseStatusCodeInternalServerErrorMessage;
/*!
レスポンス・メッセージ - ストレージ容量不足
<br/>ケース: 使用可能ストレージ容量超過 (Available storage capacity exceeded)
 */
extern NSString *ABResponseStatusCodeInsufficientStorageMessage;
/*!
レスポンス・メッセージ - 通信エラー (connection error)
<br/>ケース: ネットワーク接続不可環境下でのAPI呼び出し, 通信瞬断
 */
extern NSString *ABResponseStatusCodeHttpConnectionErrorMessage;
/*!
レスポンス・メッセージ - 不正なID (invalid id)
<br/>ケース: IDとして許可していない文字列を含むIDの取得・生成
 */
extern NSString *ABResponseStatusCodeInvalidIdMessage;
/*!
レスポンス・メッセージ - 不正なトークン (invalid token)
<br/>ケース: トークンとして許可していない文字列を含むトークンの取得・生成
 */
extern NSString *ABResponseStatusCodeInvalidTokenMessage;
/*!
レスポンス・メッセージ - 不正なパスコンポーネント (invalid path component)
<br/>ケース: URIとして許可していない文字列を含むURIの取得・生成
 */
extern NSString *ABResponseStatusCodeInvalidPathSegmentMessage;
/*!
レスポンス・メッセージ - 不正な引数 (invalid argument)
<br/>ケース: 引数として許可していない文字列を含む引数が渡された場合
 */
extern NSString *ABResponseStatusCodeInvalidArgumentMessage;

#pragma mark - Constants (for JSON object)
/*! @name Constants for JSON object */
/*!
JSONオブジェクト - オブジェクトID - null, 空文字 (0060101)
 */
extern NSString *ABResponseDetailCodeJsonObjectIdIsEmpty;
/*!
JSONオブジェクト - オブジェクトID - 文字列ではない (0060102)
 */
extern NSString *ABResponseDetailCodeJsonObjectIdIsNotValidString;
/*!
JSONオブジェクト - オブジェクトID - URI 書式が間違っている (0060104)
 */
extern NSString *ABResponseDetailCodeJsonObjectIdIsInvalidFormat;
/*!
JSONオブジェクト - オブジェクトID - オブジェクトIDが使用済み (0060109)
 */
extern NSString *ABResponseDetailCodeJsonObjectDuplicateId;
/*!
JSONオブジェクト - コンテントボディ - コンテント名不適切 (0060002)
 */
extern NSString *ABResponseDetailCodeJsonObjectContentBodyInvalidContentName;
/**
JSONオブジェクト - コンテントボディ - LF, CR, TAB を除く制御文字が含まれている (0060011)
 */
extern NSString *ABResponseDetailCodeJsonObjectContentBodyContainedControlCharacter;
/**
JSONオブジェクト - フィールド全般 - フィールド不足 (0070001)
 */
extern NSString *ABResponseDetailCodeJsonObjectMissingField;
/**
JSONオブジェクト - フィールド全般 - フィールド名不適切 (0070002)
 */
extern NSString *ABResponseDetailCodeJsonObjectInvalidFieldName;

#pragma mark - Constants (for File object)
/*! @name Constants for File object */
/*!
バイナリオブジェクト - オブジェクトID - null, 空文字 (0070101)
 */
extern NSString *ABResponseDetailCodeFileObjectIdIsEmpty;
/*!
バイナリオブジェクト - オブジェクトID - 文字列ではない (0070102)
 */
extern NSString *ABResponseDetailCodeFileObjectIdIsNotValidString;
/*!
バイナリオブジェクト - オブジェクトID - URI書式ではない (0070104)
 */
extern NSString *ABResponseDetailCodeFileObjectIdIsNotUriFormat;
/*!
バイナリオブジェクト - オブジェクトID - 使用済みのオブジェクトID (0070109)
 */
extern NSString *ABResponseDetailCodeFileObjectDuplicateId;
/*!
バイナリオブジェクト - ファイル - null, サイズが0 (0070201)
 */
extern NSString *ABResponseDetailCodeFileObjectSizeIsZero;
/*!
バイナリオブジェクト - ファイル - バイナリではない (0070202)
 */
extern NSString *ABResponseDetailCodeFileObjectIsNotBinary;
/*!
バイナリオブジェクト - ファイル名 - null, 空文字 (0070301)
 */
extern NSString *ABResponseDetailCodeFileObjectNameIsNotValidString;
/*!
バイナリオブジェクト - ファイル名 - 文字列ではない (0070302)
 */
extern NSString *ABResponseDetailCodeFileObjectNameIsEmpty;
/*!
バイナリオブジェクト - ファイル名 - LF, CR, TABを除く制御文字が含まれている (0070303)
 */
extern NSString *ABResponseDetailCodeFileObjectNameContainedControlCharacter;
/*!
バイナリオブジェクト - コンテントタイプ - null, 空文字 (0070401)
 */
extern NSString *ABResponseDetailCodeFileObjectContentTypeIsEmpty;
/*!
バイナリオブジェクト - コンテントタイプ - 文字列ではない (0070402)
*/
extern NSString *ABResponseDetailCodeFileObjectContentTypeIsNotString;
/*!
バイナリオブジェクト - コンテントタイプ - LF, CR, TABを除く制御文字が含まれている (0070403)
*/
extern NSString *ABResponseDetailCodeFileObjectContentTypeContainedControlCharacter;
/*!
バイナリオブジェクト - タグ - null, 空文字 (0071001)
*/
extern NSString *ABResponseDetailCodeFileObjectTagsIsEmpty;
/*!
バイナリオブジェクト - タグ - 配列ではない (0071002)
 */
extern NSString *ABResponseDetailCodeFileObjectTagsIsNotArray;
/*!
バイナリオブジェクト - タグ - 配列がnull (0071005)
 */
extern NSString *ABResponseDetailCodeFileObjectTagsIsEmptyArray;
/*!
バイナリオブジェクト - タグ - 配列が文字列ではない (0071006)
 */
extern NSString *ABResponseDetailCodeFileObjectTagsIsNotValidString;
/*!
バイナリオブジェクト - タグ - 配列の要素数超過(要素数が10以上) (0071007)
 */
extern NSString *ABResponseDetailCodeFileObjectTagsCapacityExceeded;

#pragma mark - Constants (for Push Notification)
/*! @name Constants for Push Notification */
/*!
プッシュ通知 - プッシュIDが空の場合のエラーコード (008100)
 */
extern NSString *ABResponseDetailCodePushNotificationIdIsEmpty;
/*!
プッシュ通知 - プッシュIDが数値でない場合のエラーコード (0081002)
 */
extern NSString *ABResponseDetailCodePushNotificationIdIsNotNumeric;
/*!
プッシュ通知 - フィールド不足のエラーコード (0080001)
 */
extern NSString *ABResponseDetailCodePushNotificationMissingField;
/*!
プッシュ通知 - フィールド名が不適切場合のエラーコード (0080002)
 */
extern NSString *ABResponseDetailCodePushNotificationInvalidFieldName;
/*!
プッシュ通知 - デバイスIDが空の場合のエラーコード (0081101)
 */
extern NSString *ABResponseDetailCodePushNotificationDeviceIdIsEmpty;
/*!
プッシュ通知 - デバイスIDが文字列でない場合のエラーコード (0081102)
 */
extern NSString *ABResponseDetailCodePushNotificationDeviceIdIsNotValidString;
/*!
プッシュ通知 - デバイス属性に制御文字が含まれている場合のエラーコード (0080103)
 */
extern NSString *ABResponseDetailCodePushNotificationDeviceAttributesContainedControlCharacter;
