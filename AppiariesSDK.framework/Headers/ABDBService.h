//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;
@class ABModel;
@class ABQuery;
@class ABDBObject;

/*!
 DBサービス
 
 __See Also__: [アピアリーズドキュメント &raquo; JSONデータを管理する](http://docs.appiaries.com/?p=70)<br/>
 __See Also__: [アピアリーズドキュメント &raquo; JSONについて](http://tutorial.appiaries.com/v1/tutorial/json/)
 */
@interface ABDBService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABDBService のシングルトン・インスタンスを返す
 @return ABDBService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;
/*!
 DBオブジェクトを生成する
 @return ABDBObject オブジェクト (またはその派生オブジェクト)
 */
- (ABDBObject *)object;
/*!
 DBオブジェクトを生成する
 @param collectionID コレクションID
 @return ABDBObject オブジェクト (またはその派生オブジェクト)
 */
- (ABDBObject *)objectWithCollectionID:(NSString *)collectionID;
/*!
 DBオブジェクトを生成する
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABDBObject オブジェクト (またはその派生オブジェクト)
 */
- (ABDBObject *)objectWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Save
/*! @name Save */
/*!
 DBオブジェクトを保存する
 @discussion 同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABDBObject *)object error:(ABError **)error;
/*!
 DBオブジェクトを保存する
 @discussion 同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param option ABDBObjectSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronously:(ABDBObject *)object option:(ABDBObjectSaveOption)option error:(ABError **)error;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 */
- (Async)save:(ABDBObject *)object;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param option ABDBObjectSaveOption オプション
 */
- (Async)save:(ABDBObject *)object option:(ABDBObjectSaveOption)option;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)save:(ABDBObject *)object target:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectSaveOption オプション
 */
- (Async)save:(ABDBObject *)object target:(id)target selector:(SEL)selector option:(ABDBObjectSaveOption)option;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)save:(ABDBObject *)object block:(ABResultBlock)block;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param object 保存する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectSaveOption オプション
 */
- (Async)save:(ABDBObject *)object block:(ABResultBlock)block option:(ABDBObjectSaveOption)option;

#pragma mark - Save (Objects)
/*! @name Save (Objects) */
/*!
 すべてのDBオブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveAllSynchronously:(NSArray *)objects error:(ABError **)error;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDBObjectSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveAllSynchronously:(NSArray *)objects option:(ABDBObjectSaveOption)option error:(ABError **)error;
/*!
 すべてのDBオブジェクトを保存する
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 */
- (Async)saveAll:(NSArray *)objects;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveAll:(NSArray *)objects option:(ABDBObjectSaveOption)option;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)saveAll:(NSArray *)objects target:(id)target selector:(SEL)selector;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveAll:(NSArray *)objects target:(id)target selector:(SEL)selector option:(ABDBObjectSaveOption)option;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)saveAll:(NSArray *)objects block:(ABResultBlock)block;
/*!
 すべてのDBオブジェクトを保存する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param objects 保存する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveAll:(NSArray *)objects block:(ABResultBlock)block option:(ABDBObjectSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 DBオブジェクトを削除する
 @discussion 同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABDBObject *)object error:(ABError **)error;
/*!
 DBオブジェクトを削除する
 @discussion 同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param option ABDBObjectDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronously:(ABDBObject *)object option:(ABDBObjectDeleteOption)option error:(ABError **)error;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 */
- (Async)delete:(ABDBObject *)object;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)delete:(ABDBObject *)object option:(ABDBObjectDeleteOption)option;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)delete:(ABDBObject *)object target:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)delete:(ABDBObject *)object target:(id)target selector:(SEL)selector option:(ABDBObjectDeleteOption)option;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)delete:(ABDBObject *)object block:(ABResultBlock)block;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param object 削除する ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)delete:(ABDBObject *)object block:(ABResultBlock)block option:(ABDBObjectDeleteOption)option;

#pragma mark - Delete (Objects)
/*! @name Delete (Objects) */
/*!
 すべてのDBオブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteAllSynchronously:(NSArray *)objects error:(ABError **)error;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDBObjectDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteAllSynchronously:(NSArray *)objects option:(ABDBObjectDeleteOption)option error:(ABError **)error;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 */
- (Async)deleteAll:(NSArray *)objects;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)objects option:(ABDBObjectDeleteOption)option;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteAll:(NSArray *)objects target:(id)target selector:(SEL)selector;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)objects target:(id)target selector:(SEL)selector option:(ABDBObjectDeleteOption)option;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteAll:(NSArray *)objects block:(ABResultBlock)block;
/*!
 すべてのDBオブジェクトを削除する
 @discussion 非同期モードで引数に渡したすべてのDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param objects 削除する ABDBObject オブジェクト配列 (またはその派生オブジェクト配列)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteAll:(NSArray *)objects block:(ABResultBlock)block option:(ABDBObjectDeleteOption)option;

#pragma mark - Delete (Query)
/*! @name Delete (Query) */
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query error:(ABError **)error;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param option ABDBObjectDeleteOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithQuery:(ABQuery *)query option:(ABDBObjectDeleteOption)option error:(ABError **)error;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 */
- (Async)deleteWithQuery:(ABQuery *)query;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query option:(ABDBObjectDeleteOption)option;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABDBObjectDeleteOption)option;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするDBオブジェクトを削除する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを一括削除する](http://docs.appiaries.com/?p=1060)
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectDeleteOption オプション
 */
- (Async)deleteWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABDBObjectDeleteOption)option;

#pragma mark - Fetch
/*! @name Fetch */
/*!
 DBオブジェクトを取得する
 @discussion 同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABDBObject *)object error:(ABError **)error;
/*!
 DBオブジェクトを取得する
 @discussion 同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param option ABDBObjectFetchOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABDBObject *)object option:(ABDBObjectFetchOption)option error:(ABError **)error;
/*!
 DBオブジェクトを取得する
 @discussion 非同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)fetch:(ABDBObject *)object target:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトを取得する
 @discussion 非同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectFetchOption オプション
 */
- (Async)fetch:(ABDBObject *)object target:(id)target selector:(SEL)selector option:(ABDBObjectFetchOption)option;
/*!
 DBオブジェクトを取得する
 @discussion 非同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)fetch:(ABDBObject *)object block:(ABResultBlock)block;
/*!
 DBオブジェクトを取得する
 @discussion 非同期モードでDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param object ABDBObject オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectFetchOption オプション
 */
- (Async)fetch:(ABDBObject *)object block:(ABResultBlock)block option:(ABDBObjectFetchOption)option;

#pragma mark - Find (Query)
/*! @name Find (Query) */
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query error:(ABError **)error;
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param option ABDBObjectFindOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)findSynchronouslyWithQuery:(ABQuery *)query option:(ABDBObjectFindOption)option error:(ABError **)error;
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector;
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectFindOption オプション
 */
- (Async)findWithQuery:(ABQuery *)query target:(id)target selector:(SEL)selector option:(ABDBObjectFindOption)option;
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block;
/*!
 検索条件にマッチするDBオブジェクトを取得する
 @discussion 非同期モードで検索条件にマッチするDBオブジェクトをデータストアから取得します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param query ABQuery オブジェクト
 @param option ABDBObjectFindOption オプション
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)findWithQuery:(ABQuery *)query block:(ABResultBlock)block option:(ABDBObjectFindOption)option;

@end