//
// Created by Appiaries Corporation on 2015/02/28.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//
//

#ifndef AppiariesSDK_ABObject____FILEEXTENSION___
#define AppiariesSDK_ABObject____FILEEXTENSION___

#import <Foundation/Foundation.h>

@class ABResult;
@protocol ABManagedProtocol;
@class ABQuery;

/*!
 基底モデル
 @discussion アピアリーズ BaaS 上で扱われる各種データ（オブジェクト）の基底モデルクラスです。
 */
@interface ABModel : NSObject <NSCoding, NSCopying>
#pragma mark - Properties
/*! @name Properties */
@property (strong, nonatomic, readonly) NSMutableDictionary *estimatedData;
@property (strong, nonatomic, readonly) NSMutableDictionary *originalData;
@property (strong, nonatomic, readonly) NSString *collectionID;
/*!
 オブジェクトID
 */
@property (strong, nonatomic) NSString *ID;
/*!
 オブジェクトが作成された日時
 */
@property (strong, nonatomic) NSDate *created;
/*!
 オブジェクトを作成したユーザ
 */
@property (strong, nonatomic) NSString *createdBy;
/*!
 オブジェクトが最後に更新された日時
 */
@property (strong, nonatomic) NSDate *updated;
/*!
 オブジェクトを最後に更新したユーザ
 */
@property (strong, nonatomic) NSString *updatedBy;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
- (instancetype)initWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
+ (instancetype)baasObject;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
+ (instancetype)baasObjectWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
+ (instancetype)baasObjectWithDictionary:(NSDictionary *)dictionary;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
- (instancetype)baasObject;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
- (instancetype)baasObjectWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABModel インスタンス、または継承クラスのインスタンス
 */
- (instancetype)baasObjectWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Instance methods
/*! @name Instance methods */
/*!
 オブジェクト内部で保持するすべてのプロパティ・キーを返す
 @return オブジェクト内部で保持するすべてのプロパティ・キー
 */
- (NSArray *)allKeys;
/*!
 オブジェクト内部で保持するすべてのプロパティ・キーと値を返す
 @return オブジェクト内部で保持するすべてのプロパティ・キーと値
 */
- (NSDictionary *)allKeysAndValues;
/*!
 プロパティ・キーに対応する値を返す
 @param key プロパティ・キー
 @return プロパティ・キーに対応する値を返す
 */
- (id)objectForKey:(NSString *)key;
/*!
 プロパティ・キーに対応する値を返す
 @param key プロパティ・キー
 @return プロパティ・キーに対応する値を返す
 */
- (id)objectForKeyedSubscript:(NSString *)key;
/*!
 プロパティに値をセットする
 @param object プロパティにセットする値
 @param key プロパティ・キー
 */
- (void)setObject:(id)object forKey:(NSString *)key;
/*!
 プロパティに値をセットする
 @param object プロパティにセットする値
 @param key プロパティ・キー
 */
- (void)setObject:(id)object forKeyedSubscript:(NSString *)key;
/*!
 オブジェクトからプロパティを削除する
 @param key プロパティ・キー
 */
- (void)removeObjectForKey:(NSString *)key;
/*!
 オブジェクトからプロパティを削除する
 @param key プロパティ・キー
 */
- (void)removeObjectsForKeys:(NSArray *)keys;
/*!
 オブジェクトからすべてのプロパティを削除する
 */
- (void)removeAllObjects;
/*!
 オブジェクトに追加されたプロパティのキー・リストを返す
 @return オブジェクトに追加されたプロパティのキー・リスト
 */
- (NSSet *)addedKeys;
/*!
 オブジェクトに追加されたプロパティのキーと値のリストを返す
 @return オブジェクトに追加されたプロパティのキーと値のリスト
 */
- (NSDictionary *)addedKeysAndValues;
/*!
 オブジェクトから削除されたプロパティのキー・リストを返す
 @return オブジェクトから削除されたプロパティのキー・リスト
 */
- (NSSet *)removedKeys;
/*!
 オブジェクトから削除されたプロパティのキーと値リストを返す
 @return オブジェクトから削除されたプロパティのキーと値のリスト
 */
- (NSDictionary *)removedKeysAndValues;
/*!
 オブジェクト内で値が更新されたプロパティのキー・リストを返す
 @return オブジェクト内で値が更新されたプロパティのキー・リスト
 */
- (NSSet *)updatedKeys;
/*!
 オブジェクト内で値が更新されたプロパティのキーと値のリストを返す
 @return オブジェクト内で値が更新されたプロパティのキーと値のリスト
 */
- (NSDictionary *)updatedKeysAndValues;
/*!
 オブジェクト内で発生した変更を適用する
 @discussion オブジェクトに対してメモリ上で行われた変更履歴を破棄し、現在のオブジェクトの状態をオリジナルの状態とします。<br/>以下に、オブジェクトの内部フラグの状態遷移の例を示します。
 
  a. オブジェクトを手動で生成した場合
      1. オブジェクト生成 (isNew=YES, isDirty=NO)
      2. プロパティの値を変更 (isNew=YES, isDirty=YES)
      3. apply 実行 (isNew=NO, isDirty=NO)
  b. APIサーバからデータを取得した場合
      1. データ取得 (isNew=NO, isDirty=NO)
      2. プロパティの値を変更 (isNew=NO, isDirty=YES)
      3. apply 実行 (isNew=NO, isDirty=NO)
 
 <div class="important">
 apply はあくまでメモリ上でのオブジェクト状態を変更するに過ぎません。サーバ上のデータを更新する場合は、save を実行します。<br/>
 ただし、save はプロパティ値の変更差分をチェックした上でAPIサーバとの通信を行うため、apply 実行直後に save を実行したとしても更新は行われません。
 </div>
 */
- (void)apply;
/*!
 オブジェクトに対してメモリ上で行われた変更を破棄し元の状態に復帰させる
 @discussion オブジェクトの状態を、オブジェクトが isDirty=NO であった時点にまで戻します。
 */
- (void)revert;
- (void)postRefreshProcessWithFetchedObject:(ABModel <ABManagedProtocol> *)fetchedObject;
/*!
 入力データ・フィルタ
 @discussion サーバから受け取った JSON 形式のデータを、オブジェクトのプロパティに格納する直前に、データ形式を変換する必要がある場合に Overwrite して使用します。<br/>
 具体的には、プロパティのデータ型が日付型(NSDate)で、JSONで受け取ったデータ型が数値であった場合に、この入力データ・フィルタ内で NSDate へ変換するコードを記述します。
 @param data JSONから受け取った値
 @param key プロパティ・キー
 */
- (id)baasInputDataFilter:(id)data forKey:(NSString *)key;
/*!
 出力データ・フィルタ
 @discussion サーバへ受け渡すデータは JSON 形式である必要があり、オブジェクトのプロパティ値が直接JSONで扱えるデータ型でない場合に Overwrite して使用します。<br/>
 具体的には、プロパティのデータ型が日付型(NSDate)で、JSONへ受け渡すデータ型を数値にするとした場合に、この出力データ・フィルタ内で数値へ変換するコードを記述します。
 @param data プロパティ値
 @param key プロパティ・キー
 */
- (id)baasOutputDataFilter:(id)data forKey:(NSString *)key;

#pragma mark - Accessors
/*! @name Accessors */
/*!
 コレクションIDを返す
 @return コレクションID
 */
- (NSString *)collectionID;
/*!
 新規のオブジェクトか
 @return YES=新規オブジェクト
 */
- (BOOL)isNew;
/*!
 オブジェクトに更新が発生しているか
 @return YES: 更新あり
 */
- (BOOL)isDirty;
+ (BOOL)isRegistered;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 クエリオブジェクトを返す
 @discussion オブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end

#endif