//
// Created by Appiaries Corporation on 2015/03/09.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;
@class ABFile;
@class ABQuery;

/*!
 ファイル・サービス
 
 __See Also__: [アピアリーズドキュメント &raquo; ファイルを管理する](http://docs.appiaries.com/?p=80)<br/>
 */
@interface ABFileService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABFileService のシングルトン・インスタンスを返す
 @return ABFileService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;
/*!
 ファイル・オブジェクトを生成する
 @return ABFile オブジェクト (またはその派生オブジェクト)
 */
- (ABFile *)file;
/*!
 ファイル・オブジェクトを生成する
 @param collectionID コレクションID
 @return ABFile オブジェクト (またはその派生オブジェクト)
 */
- (ABFile *)fileWithCollectionID:(NSString *)collectionID;
/*!
 ファイル・オブジェクトを生成する
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABFile オブジェクト (またはその派生オブジェクト)
 */
- (ABFile *)fileWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Save
/*! @name Save */
/*!
 ファイル・オブジェクトを保存する
 @discussion 同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABFile *)file error:(ABError **)error;
/*!
 ファイル・オブジェクトを保存する
 @discussion 同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABFile *)file option:(ABFileSaveOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 */
- (Async)save:(ABFile *)file;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileSaveOption オプション
 */
- (Async)save:(ABFile *)file option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)save:(ABFile *)file target:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)save:(ABFile *)file target:(id)target selector:(SEL)selector option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 */
- (Async)save:(ABFile *)file target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)save:(ABFile *)file target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)save:(ABFile *)file block:(ABResultBlock)block;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)save:(ABFile *)file block:(ABResultBlock)block option:(ABFileSaveOption)option;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 */
- (Async)save:(ABFile *)file block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock;
/*!
 ファイル・オブジェクトを保存する
 @discussion 非同期モードでファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param file 保存する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)save:(ABFile *)file block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock option:(ABFileSaveOption)option;

#pragma mark - Save (Objects)
/*! @name Save (Objects) */
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveAllSynchronously:(NSArray *)files error:(ABError **)error;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABFileSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveAllSynchronously:(NSArray *)files option:(ABFileSaveOption)option error:(ABError **)error;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 */
- (Async)saveAll:(NSArray *)files;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABFileSaveOption オプション
 */
- (Async)saveAll:(NSArray *)files option:(ABFileSaveOption)option;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)saveAll:(NSArray *)files target:(id)target selector:(SEL)selector;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)saveAll:(NSArray *)files target:(id)target selector:(SEL)selector option:(ABFileSaveOption)option;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 */
- (Async)saveAll:(NSArray *)files target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 @param option ABFileSaveOption オプション
 */
- (Async)saveAll:(NSArray *)files target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector option:(ABFileSaveOption)option;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)saveAll:(NSArray *)files block:(ABResultBlock)block;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)saveAll:(NSArray *)files block:(ABResultBlock)block option:(ABFileSaveOption)option;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 */
- (Async)saveAll:(NSArray *)files block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock;
/*!
 すべてのファイル・オブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを登録する](http://docs.appiaries.com/?p=1080)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1090)
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを更新する](http://docs.appiaries.com/?p=1100)
 @param files 保存する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 @param option ABFileSaveOption オプション
 */
- (Async)saveAll:(NSArray *)files block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock option:(ABFileSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 ファイル・オブジェクトを削除する
 @discussion 同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABFile *)file error:(ABError **)error;
/*!
 ファイル・オブジェクトを削除する
 @discussion 同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABFile *)file option:(ABFileDeleteOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 */
- (Async)delete:(ABFile *)file;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileDeleteOption オプション
 */
- (Async)delete:(ABFile *)file option:(ABFileDeleteOption)option;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)delete:(ABFile *)file target:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDeleteOption オプション
 */
- (Async)delete:(ABFile *)file target:(id)target selector:(SEL)selector option:(ABFileDeleteOption)option;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)delete:(ABFile *)file block:(ABResultBlock)block;
/*!
 ファイル・オブジェクトを削除する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param file 削除する ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDeleteOption オプション
 */
- (Async)delete:(ABFile *)file block:(ABResultBlock)block option:(ABFileDeleteOption)option;

#pragma mark - Delete (Objects)
/*! @name Delete (Objects) */
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteAllSynchronously:(NSArray *)files error:(ABError **)error;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABFileDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteAllSynchronously:(NSArray *)files option:(ABFileDeleteOption)option error:(ABError **)error;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 */
- (Async)deleteAll:(NSArray *)files;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)files option:(ABFileDeleteOption)option;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteAll:(NSArray *)files target:(id)target selector:(SEL)selector;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)files target:(id)target selector:(SEL)selector option:(ABFileDeleteOption)option;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteAll:(NSArray *)files block:(ABResultBlock)block;
/*!
 すべてのファイル・オブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを削除する](http://docs.appiaries.com/?p=1110)
 @param files 削除する ABFile オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)files block:(ABResultBlock)block option:(ABFileDeleteOption)option;

#pragma mark - Delete (Query)
/*! @name Delete (Query) */
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query error:(ABError **)error;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABFileDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query option:(ABFileDeleteOption)option error:(ABError **)error;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 */
- (Async)deleteWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query option:(ABFileDeleteOption)option;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABFileDeleteOption)option;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするファイル・オブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを一括削除する]()
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABFileDeleteOption)option;

#pragma mark - Fetch
/*! @name Fetch */
/*!
 ファイル・オブジェクトを取得する
 @discussion 同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABFile *)file error:(ABError **)error;
/*!
 ファイル・オブジェクトを取得する
 @discussion 同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileFetchOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABFile *)file option:(ABFileFetchOption)option error:(ABError **)error;
/*!
 ファイル・オブジェクトを取得する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)fetch:(ABFile *)file target:(id)target selector:(SEL)selector;
/*!
 ファイル・オブジェクトを取得する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileFetchOption オプション
 */
- (Async)fetch:(ABFile *)file target:(id)target selector:(SEL)selector option:(ABFileFetchOption)option;
/*!
 ファイル・オブジェクトを取得する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)fetch:(ABFile *)file block:(ABResultBlock)block;
/*!
 ファイル・オブジェクトを取得する
 @discussion 非同期モードでファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileFetchOption オプション
 */
- (Async)fetch:(ABFile *)file block:(ABResultBlock)block option:(ABFileFetchOption)option;

#pragma mark - Find (Query)
/*! @name Find (Query) */
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query error:(ABError **)error;
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param option ABFileFindOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query option:(ABFileFindOption)option error:(ABError **)error;
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileFindOption オプション
 */
- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABFileFindOption)option;
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするファイル・オブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするファイル・オブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(メタ情報部)](http://docs.appiaries.com/?p=1120)
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileFindOption オプション
 */
- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABFileFindOption)option;

#pragma mark - Download
/*! @name Download */
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)downloadSynchronously:(ABFile *)file error:(ABError **)error;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileDownloadOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)downloadSynchronously:(ABFile *)file option:(ABFileDownloadOption)option error:(ABError **)error;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)download:(ABFile *)file target:(id)target selector:(SEL)selector;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABFileDownloadOption オプション
 */
- (Async)download:(ABFile *)file target:(id)target selector:(SEL)selector option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 */
- (Async)download:(ABFile *)file target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param progressSelector 進捗コールバック・セレクタ
 @param option ABFileDownloadOption オプション
 */
- (Async)download:(ABFile *)file target:(id)target selector:(SEL)selector progressSelector:(SEL)progressSelector option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)download:(ABFile *)file block:(ABResultBlock)block;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABFileDownloadOption オプション
 */
- (Async)download:(ABFile *)file block:(ABResultBlock)block option:(ABFileDownloadOption)option;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 */
- (Async)download:(ABFile *)file block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock;
/*!
 ファイル実体(バイナリ)をダウンロードする
 @see [アピアリーズドキュメント &raquo; バイナリオブジェクトを検索する(バイナリ)](http://docs.appiaries.com/?p=1130)
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param progressBlock ABProgressBlock 進捗コールバック・ブロック
 @param option ABFileDownloadOption オプション
 */
- (Async)download:(ABFile *)file block:(ABResultBlock)block progressBlock:(ABProgressBlock)progressBlock option:(ABFileDownloadOption)option;

#pragma mark - Cancel
/*! @name Cancel */
/*!
 実行中の処理をキャンセルする
 @discussion 処理中のアップロード／ダウンロード処理をキャンセルすることができます。
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 */
- (void)cancel:(ABFile *)file;
/*!
 実行中の処理をキャンセルする
 @discussion 処理中のアップロード／ダウンロード処理をキャンセルすることができます。
 @param file ABFile オブジェクト (またはその派生オブジェクト)
 @param option ABFileCancelOption オプション
 */
- (void)cancel:(ABFile *)file option:(ABFileCancelOption)option;

@end