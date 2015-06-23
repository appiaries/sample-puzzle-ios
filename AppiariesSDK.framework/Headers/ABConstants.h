
#ifndef AppiariesSDK_ABConstants____FILEEXTENSION___
#define AppiariesSDK_ABConstants____FILEEXTENSION___

#import <Foundation/Foundation.h>


// Alias
#define baas  [AB sharedFacade]



@class ABResult;
@class ABError;

/*!
 ABResult 用コールバック・ブロック
 @discussion 引数に APISResult オブジェクトを１つとるコールバック・ブロックです。
 */
typedef void (^ABResultBlock)(ABResult *result, ABError *error);
//typedef void (^ABBooleanCallbackBlock)(BOOL success, NSError *error);

/*!
 long long 用コールバック・ブロック
 @discussion 引数に long long 値を１つとるコールバック・ブロックです。
 */
typedef void (^ABLongLongBlock)(long long value, ABError *error);

/*!
 引数無しコールバック・ブロック
 @discussion 引数をとらないコールバック・ブロックです。
 */
typedef void (^ABVoidBlock)();

/*!
 進捗用コールバック・ブロック
 @discussion 引数に float 値を１つとるコールバック・ブロックです。
 */
typedef void (^ABProgressBlock)(float progress);


#pragma mark - DBObject Options
/*!
 ABDBObject saveメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDBObjectSaveOption) {
    /*!
     指定なし
     */
    ABDBObjectSaveOptionNone = 1 << 0,
};
/*!
 ABDBObject deleteメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDBObjectDeleteOption) {
    /*!
     指定なし
     */
    ABDBObjectDeleteOptionNone = 1 << 0,
};
/*!
 ABDBObject fetchメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDBObjectFetchOption) {
    /*!
     指定なし
     */
    ABDBObjectFetchOptionNone = 1 << 0,
};
/*!
 ABDBObject findメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDBObjectFindOption) {
    /*!
     指定なし
     */
    ABDBObjectFindOptionNone = 1 << 0,
    /*!
     検索結果にオブジェクトデータ以外を含めない
     */
    ABDBObjectFindOptionObjectOnly = 1 << 1,
};
/*!
 ABDBObject refreshメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDBObjectRefreshOption) {
    /*!
     指定なし
     */
    ABDBObjectRefreshOptionNone = ABDBObjectFetchOptionNone,
};

#pragma mark - File Options
/*!
 ABFile saveメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileSaveOption) {
    /*!
     指定なし
     */
    ABFileSaveOptionNone = 1 << 0,
};
/*!
 ABFile deleteメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileDeleteOption) {
    /*!
     指定なし
     */
    ABFileDeleteOptionNone = 1 << 0,
};
/*!
 ABFile fetchメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileFetchOption) {
    /*!
     指定なし
     */
    ABFileFetchOptionNone = 1 << 0,
    /*!
     ファイル実体の遅延ローディング
     */
    ABFileFetchOptionLazyLoading = 1 << 1,
};
/*!
 ABFile findメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileFindOption) {
    /*!
     指定なし
     */
    ABFileFindOptionNone = 1 << 0,
    /*!
     検索結果にオブジェクトデータ以外を含めない
     */
    ABFileFindOptionObjectOnly = 1 << 1,
    /*!
     ファイル実体の遅延ローディング
     */
    ABFileFindOptionLazyLoading = 1 << 2,
};
/*!
 ABFile refreshメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileRefreshOption) {
    /*!
     指定なし
     */
    ABFileRefreshOptionNone = ABFileFindOptionNone,
    /*!
     ファイル実体の遅延ローディング
     */
    ABFileRefreshOptionLazyLoading = ABFileFetchOptionLazyLoading,
};
/*!
 ABFile cancelメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileCancelOption) {
    /*!
     指定なし
     */
    ABFileCancelOptionNone = 1 << 0,
};
/*!
 ABFile downloadメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABFileDownloadOption) {
    /*!
     指定なし
     */
    ABFileDownloadOptionNone = 1 << 0,
};

#pragma mark - User Options
/*!
 ABUser signInメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserSignUpOption) {
    /*!
     指定なし
     */
    ABUserSignUpOptionNone = 1 << 0,
    /*!
     ログインは行わない
     */
    ABUserSignUpOptionWithoutLogIn = 1 << 1,
    /*!
     自動ログインを有効にする
     */
    ABUserSignUpOptionLogInAutomatically = 1 << 2,
    /*!
     ログイン成功時のレスポンスにIDのみを返却する
     IMPORTANT: ログインIDやメールアドレス、その他属性情報などをセッションに保持しておきたい場合は、このオプションは指定しないでください。
     */
    ABUserSignUpOptionUseIncompleteData = 1 << 3,
};
/*!
 ABUser logInメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserLogInOption) {
    /*!
     指定なし
     */
    ABUserLogInOptionNone = 1 << 0,
    /*!
     自動ログインを有効にする
     */
    ABUserLogInOptionLogInAutomatically = 1 << 1,
    /*!
     ログイン成功時のレスポンスにIDのみを返却する
     IMPORTANT: ログインIDやメールアドレス、その他属性情報などをセッションに保持しておきたい場合は、このオプションは指定しないでください。
     */
    ABUserLogInOptionUseIncompleteData = 1 << 2,
    ABUserLogInOptionNeedsVerify = 1 << 3,
};
/*!
 ABUser logOutメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserLogOutOption) {
    /*!
     指定なし
     */
    ABUserLogOutOptionNone = 1 << 0,
};
/*!
 ABUser saveメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserSaveOption) {
    /*!
     指定なし
     */
    ABUserSaveOptionNone = 1 << 0,
};
/*!
 ABUser deleteメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserDeleteOption) {
    /*!
     指定なし
     */
    ABUserDeleteOptionNone = 1 << 0,
};
/*!
 ABUser fetchメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserFetchOption) {
    /*!
     指定なし
     */
    ABUserFetchOptionNone = 1 << 0,
};
/*!
 ABUser findメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserFindOption) {
    /*!
     指定なし
     */
    ABUserFindOptionNone = 1 << 0,
    /*!
     検索結果にオブジェクトデータ以外を含めない
     */
    ABUserFindOptionObjectOnly = 1 << 1,
};
/*!
 ABUser refreshメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserRefreshOption) {
    /*!
     指定なし
     */
    ABUserRefreshOptionNone = ABUserFindOptionNone,
};
/*!
 ABUser resetPasswordメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserResetPasswordOption) {
    /*!
     指定なし
     */
    ABUserResetPasswordOptionNone = 1 << 0,
};
/*!
 ABUser requestVerificationEmailメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABUserVerifyEmailOption) {
    /*!
     指定なし
     */
    ABUserVerifyEmailOptionNone = 1 << 0,
};

#pragma mark - Sequence Options
/*!
 ABSequence fetchメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABSequenceFetchOption) {
    /*!
     指定なし
     */
    ABSequenceFetchOptionNone = 1 << 0,
};
/*!
 ABSequence addValueメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABSequenceAddValueOption) {
    /*!
     指定なし
     */
    ABSequenceAddValueOptionNone = 1 << 0,
};
/*!
 ABSequence resetメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABSequenceResetOption) {
    /*!
     指定なし
     */
    ABSequenceResetOptionNone = 1 << 0,
};

#pragma mark - Device Options
/*!
 ABDevice registerメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceRegistrationOption) {
    /*!
     指定なし
     */
    ABDeviceRegistrationOptionNone = 1 << 0,
    /*!
     デバイス登録後にセッションにデバイス情報を保持しない
     */
    ABDeviceRegistrationOptionWithoutSaving = 1 << 1,
};
/*!
 ABDevice unregisterメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceUnregistrationOption) {
    /*!
     指定なし
     */
    ABDeviceUnregistrationOptionNone = 1 << 0,
};
/*!
 ABDevice saveメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceSaveOption) {
    /*!
     指定なし
     */
    ABDeviceSaveOptionNone = 1 << 0,
};
/*!
 ABDevice deleteメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceDeleteOption) {
    /*!
     指定なし
     */
    ABDeviceDeleteOptionNone = 1 << 0,
};
/*!
 ABDevice fetchメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceFetchOption) {
    /*!
     指定なし
     */
    ABDeviceFetchOptionNone = 1 << 0,
};
/*!
 ABDevice findメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABDeviceFindOption) {
    /*!
     指定なし
     */
    ABDeviceFindOptionNone = 1 << 0,
    /*!
     検索結果にオブジェクトデータ以外を含めない
     */
    ABDeviceFindOptionObjectOnly = 1 << 1,
};
/*!
 デバイス・プラットフォーム定数
 */
typedef NS_ENUM(NSInteger, ABPlatform) {
    /*!
     Android
     */
    ABPlatformAndroid = 0,
    /*!
     iOS
     */
    ABPlatformIOS = 1,
    /*!
     Unknown
     */
    ABPlatformUnknown = 9,
};
/*!
 プッシュ通知配信環境定数
 */
typedef NS_ENUM(NSInteger, ABPushEnvironment) {
    /*!
     Sandbox 環境
     */
    ABPushEnvironmentSandbox = 0,
    /*!
     Production 環境
     */
     ABPushEnvironmentProduction = 1,
};

#pragma mark - Push Options
/*!
 ABPushMessage openメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABPushMessageOpenOption) {
    /*!
     指定なし
     */
    ABPushMessageOpenOptionNone = 1 << 0,
};
/*!
 ABPushService handleNotificationメソッド用オプション
 */
typedef NS_OPTIONS(NSInteger, ABHandlePushOption) {
    /*!
     指定なし
     @discussion 組み込みWebViewコントローラ（ABPopoverWebViewController) 上にURLで指定されたWebコンテンツを表示します。
     */
    ABHandlePushOptionNone = 1 << 0,
    /*!
     Safari
     Safari にURLで指定されたWebコンテンツを表示します。
     */
    ABHandlePushOptionSafari = 1 << 1,
    /*!
     WebView
     @discussion 組み込みWebViewコントローラ（ABPopoverWebViewController) 上にURLで指定されたWebコンテンツを表示します。
     */
    ABHandlePushOptionWebView = 1 << 2,
};

/*!
 認証プロバイダ定数
 @discussion SNS連携や匿名ユーザ認証時に使用する認証プロバイダの定数です。
 */
typedef NS_ENUM(NSUInteger, ABAuthenticationProvider) {
    /*!
     不明
     */
    ABAuthenticationProviderUnknown = 0,
    /*!
     匿名
     */
    ABAuthenticationProviderAnonymous,
    /*!
     Twitter
     */
    ABAuthenticationProviderTwitter,
    /*!
     Facebook
     */
    ABAuthenticationProviderFacebook,
};
#define ABAuthenticationProviderUnknownKey    @"unknown"
#define ABAuthenticationProviderAnonymousKey  @"anonymous"
#define ABAuthenticationProviderTwitterKey    @"twitter"
#define ABAuthenticationProviderFacebookKey   @"facebook"


/*
 NULLコレクションID
 @discussion コレクションを持たないオブジェクトに指定します。
 */
#define ABNullCollectionID  @""

// 非同期メソッド用マーカー
#define Async void



#endif

