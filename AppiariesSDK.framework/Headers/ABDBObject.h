//
// Created by Appiaries Corporation on 2015/03/09.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>
#import <AppiariesSDK/ABModel.h>

@class ABACL;
@class ABGeoPoint;
@class ABResult;
@class ABModel;
@protocol ABManagedProtocol;
@class ABQuery;

/*!
 DBオブジェクト・モデル
 @discussion JSONデータ・コレクションに格納するJSONデータを表現するモデルクラスです。
 
 __See Also__: [アピアリーズドキュメント &raquo; JSONデータを管理する](http://docs.appiaries.com/?p=70)<br/>
 __See Also__: [アピアリーズドキュメント &raquo; JSONについて](http://tutorial.appiaries.com/v1/tutorial/json/)
 */
@interface ABDBObject : ABModel <ABManagedProtocol>
#pragma mark - Properties
/*! @name Properties */
// ** RESERVED ** *!
// アクセス制御リスト
// */
//@property (strong, nonatomic) ABACL *ACL;
/*!
 位置情報 (緯度・経度)
 @see [アピアリーズドキュメント &raquo; 位置情報を利用する](http://docs.appiaries.com/?p=100)
 */
@property (strong, nonatomic) ABGeoPoint *geoPoint;
/*!
 基準点から距離
 @see [アピアリーズドキュメント &raquo; 位置情報を利用する](http://docs.appiaries.com/?p=100)
 */
@property (nonatomic) double distance;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABDBObject オブジェクト
 */
+ (instancetype)object;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABDBObject オブジェクト
 */
+ (instancetype)objectWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABDBObject オブジェクト
 */
+ (instancetype)objectWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Save
/*! @name Save */
/*!
 DBオブジェクトを保存する
 @discussion 同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithError:(ABError **)error;
/*!
 DBオブジェクトを保存する
 @discussion 同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param option ABDBObjectSaveOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)saveSynchronouslyWithOption:(ABDBObjectSaveOption)option error:(ABError **)error;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 */
- (Async)save;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveWithOption:(ABDBObjectSaveOption)option;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveWithTarget:(id)target selector:(SEL)selector option:(ABDBObjectSaveOption)option;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)saveWithBlock:(ABResultBlock)block;
/*!
 DBオブジェクトを保存する
 @discussion 非同期モードでDBオブジェクトをデータストアへ保存します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを登録する](http://docs.appiaries.com/?p=1020)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを置き換え登録する](http://docs.appiaries.com/?p=1030)
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを更新する](http://docs.appiaries.com/?p=1040)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectSaveOption オプション
 */
- (Async)saveWithBlock:(ABResultBlock)block option:(ABDBObjectSaveOption)option;

#pragma mark - Delete
/*! @name Delete */
/*!
 DBオブジェクトを削除する
 @discussion 同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithError:(ABError **)error;
/*!
 DBオブジェクトを削除する
 @discussion 同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param option ABDBObjectDeleteOption オブション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)deleteSynchronouslyWithOption:(ABDBObjectDeleteOption)option error:(ABError **)error;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 */
- (Async)delete;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param option ABDBObjectDeleteOption オブション
 */
- (Async)deleteWithOption:(ABDBObjectDeleteOption)option;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectDeleteOption オブション
 */
- (Async)deleteWithTarget:(id)target selector:(SEL)selector option:(ABDBObjectDeleteOption)option;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)deleteWithBlock:(ABResultBlock)block;
/*!
 DBオブジェクトを削除する
 @discussion 非同期モードでDBオブジェクトをデータストアから削除します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを削除する](http://docs.appiaries.com/?p=1050)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectDeleteOption オブション
 */
- (Async)deleteWithBlock:(ABResultBlock)block option:(ABDBObjectDeleteOption)option;

#pragma mark - Refresh
/*! @name Refresh */
/*!
 DBオブジェクトをリフレッシュする
 @discussion 同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)refreshSynchronouslyWithError:(ABError **)error;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 @param option ABDBObjectRefreshOption オブション
 */
- (ABResult *)refreshSynchronouslyWithOption:(ABDBObjectRefreshOption)option error:(ABError **)error;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 */
- (Async)refresh;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param option ABDBObjectRefreshOption オブション
 */
- (Async)refreshWithOption:(ABDBObjectRefreshOption)option;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABDBObjectRefreshOption オブション
 */
- (Async)refreshWithTarget:(id)target selector:(SEL)selector option:(ABDBObjectRefreshOption)option;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)refreshWithBlock:(ABResultBlock)block;
/*!
 DBオブジェクトをリフレッシュする
 @discussion 非同期モードでDBオブジェクトをリフレッシュします。<br>
             オブジェクトをサーバに保存されている最新の状態にリフレッシュしたい場合に利用します。
 @see [アピアリーズドキュメント &raquo; JSONオブジェクトを検索する](http://docs.appiaries.com/?p=1070)
 @param block ABResultBlock コールバック・ブロック
 @param option ABDBObjectRefreshOption オブション
 */
- (Async)refreshWithBlock:(ABResultBlock)block option:(ABDBObjectRefreshOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 クエリオブジェクトを返す
 @discussion DBオブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end
