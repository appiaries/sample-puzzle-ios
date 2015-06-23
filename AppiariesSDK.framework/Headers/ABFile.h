//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABModel;
@class ABResult;
@class ABACL;
@class ABQuery;
@protocol ABManagedProtocol;

/*!
 ファイル・モデル
 @discussion ファイル・コレクションに格納するファイルを表現するモデルクラスです。

 __See Also__: [アピアリーズドキュメント &raquo; ファイルを管理する](http://docs.appiaries.com/?p=80)<br/>
 */
@interface ABFile : ABModel <ABManagedProtocol>
#pragma mark - Properties
/*! @name Properties */
// **RESERVED** *!
// アクセス制御リスト
// */
//@property (strong, nonatomic) ABACL *ACL;
/*!
 URL
 @discussion ファイル実体のダウンロードURLです。
 
 */
@property (strong, nonatomic, readonly) NSString *url;
/*!
 ファイル名
 
 */
@property (strong, nonatomic) NSString *name;
/*!
 コンテンツタイプ
 
 */
@property (strong, nonatomic) NSString *contentType;
/*!
 ファイルサイズ (バイト数)
 
 */
@property (nonatomic, readonly) unsigned long long length;
/*!
 タグ
 
 */
@property (strong, nonatomic) NSArray *tags;
/*!
 データ (バイナリ)
 @discussion ファイル実体のバイナリデータが格納されます。
 
 */
@property (strong, nonatomic) NSData *data;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABFile オブジェクト
 */
+ (instancetype)file;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABFile オブジェクト
 */
+ (instancetype)fileWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABFile オブジェクト
 */
+ (instancetype)fileWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Save
/*! @name Save */
/*!
 ファイル・オブジェクトを保存する
 @discussion 同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithError:(ABError **)error;
/*!
 ファイル・オブジェクトを保存する
 @discussion 同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param option ABFileSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithOption:(ABFileSaveOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 */
- (Async)save;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param option ABFileSaveOption オプション
 */
- (Async)saveWithOption:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)saveWithBlock:(ABResultBlock)block;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)saveWithBlock:(ABResultBlock)block option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 */
- (Async)saveWithBlock:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)saveWithBlock:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock option:(ABFileSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 ファイル・オブジェクトを削除する
 @discussion 同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithError:(ABError **)error;
/*!
 ファイル・オブジェクトを削除する
 @discussion 同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param option ABFileDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithOption:(ABFileDeleteOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 */
- (Async)delete;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithOption:(ABFileDeleteOption)option;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector option:(ABFileDeleteOption)optionb;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteWithBlock:(ABResultBlock)block;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithBlock:(ABResultBlock)block option:(ABFileDeleteOption)option;

#pragma mark - Refresh
/*! @name Refresh */
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)refreshSynchronouslyWithError:(ABError **)error;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param option ABFileRefreshOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)refreshSynchronouslyWithOption:(ABFileRefreshOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 */
- (Async)refresh;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param option ABFileRefreshOption オプション
 */
- (Async)refreshWithOption:(ABFileRefreshOption)option;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileRefreshOption オプション
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector option:(ABFileRefreshOption)option;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)refreshWithBlock:(ABResultBlock)block;
/*!
 ファイル・オブジェクトをリフレッシュする
 @discussion 非同期モードでファイル・オブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileRefreshOption オプション
 */
- (Async)refreshWithBlock:(ABResultBlock)block option:(ABFileRefreshOption)option;

#pragma mark - Download
/*! @name Download */
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)downloadSynchronouslyWithError:(ABError **)error;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param option ABFileDownloadOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)downloadSynchronouslyWithOption:(ABFileDownloadOption)option error:(ABError **)error;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)downloadWithTarget:(id)target selector:(SEL)selector;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDownloadOption オプション
 */
- (Async)downloadWithTarget:(id)target selector:(SEL)selector option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 */
- (Async)downloadWithTarget:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 @param option ABFileDownloadOption オプション
 */
- (Async)downloadWithTarget:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)downloadWithBlock:(ABResultBlock)block;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDownloadOption オプション
 */
- (Async)downloadWithBlock:(ABResultBlock)block option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 */
- (Async)downloadWithBlock:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @discussion 非同期モードでファイル実体(バイナリ)をダウンロードします。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 @param option ABFileDownloadOption オプション
 */
- (Async)downloadWithBlock:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock option:(ABFileDownloadOption)option;

#pragma mark - Cancel
/*! @name Cancel */
/*!
 実行中の処理をキャンセルする
 @discussion 処理中のアップロード／ダウンロード処理をキャンセルすることができます。
 */
- (void)cancel;
/*!
 実行中の処理をキャンセルする
 @discussion 処理中のアップロード／ダウンロード処理をキャンセルすることができます。
 @param option ABFileCancelOption オプション
 */
- (void)cancelWithOption:(ABFileCancelOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 ファイル実体(バイナリ)をロードする
 @discussion ファイル実体(バイナリ)をファイルシステムからロードし、プロパティ"data"にセットします。
             また、ロード時点でファイル名やコンテンツタイプが未指定であった場合は、それらが自動的にプロパティにセットされます。
 @param path ファイルパス
 */
- (void)loadDataWithContentsOfFile:(NSString *)path;
/*!
 クエリオブジェクトを返す
 @discussion ファイル・オブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end