//
// Created by Appiaries Corporation on 2015/02/28.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol ABManagedProtocol;

/*!
 クラス・リポジトリ
 @discussion 組み込みクラスを拡張して作成したユーザ定義モデルクラスを管理します。
 */
@interface ABClassRepository : NSObject
#pragma mark - Properties
/*! @name Properties */
/*!
 登録数
 @discussion 登録済みのユーザ定義モデルクラス数を返します。
 */
@property (nonatomic, readonly) NSUInteger count;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 ABClassRepository のシングルトン・インスタンスを返す
 @discussion ABClassRepository のシングルトン・インスタンスを返します。
 @return ABClassRepository のシングルトン・インスタンス
 */
+ (instancetype)sharedRepository;

#pragma mark - Instance methods
/*! @name Instance methods */
/*!
 ユーザ定義モデルクラスを登録する
 @discussion 組み込みクラスを拡張して作成したユーザ定義モデルクラスをリポジトリに登録します。
 @param baasClass ABModel クラスの派生クラス
 <div class="important">ユーザ定義モデルクラスのインスタンスを生成する前に必ず登録を行ってください。</div>
 */
- (void)registerClass:(Class<ABManagedProtocol>)baasClass;
/*!
 ユーザ定義モデルクラスを登録する
 @discussion 組み込みクラスを拡張して作成した複数のユーザ定義モデルクラスをリポジトリに登録します。
 @param baasClasses ABModel クラスの派生クラス
 <div class="important">ユーザ定義モデルクラスのインスタンスを生成する前に必ず登録を行ってください。</div>
 */
- (void)registerClasses:(NSArray *)baasClasses;
/*!
 ユーザ定義モデルクラス定義を取得する
 @discussion リポジトリに登録されているユーザ定義モデルクラスのクラス定義を取得します。
 @param baasClass ABModel クラスの派生クラス
 */
- (NSDictionary *)definitionForBaaSClass:(Class<ABManagedProtocol>)baasClass;
/*!
 ユーザ定義モデルクラスを取得する
 @discussion アピアリーズのコレクションIDを使用して登録済みユーザ定義モデルクラスを取得します。
 @param baasClassName コレクションID
 */
- (Class<ABManagedProtocol>)baasClassForBaaSClassName:(NSString *)baasClassName;
/*!
 ユーザ定義モデルクラスを取得する
 @discussion アピアリーズのコレクションIDを使用して登録済みユーザ定義モデルクラスを取得します。
 @param baasClassName コレクションID
 */
- (Class)baasClassForCollectionID:(NSString *)collectionID;
/*!
 アクセサに対応するプロパティ名を取得する
 @discussion 引数アクセサ(getter/setter)に対応するプロパティ名を取得します。
 @param accessor アクセサ
 @param baasClass モデルクラス
 @return プロパティ名
 */
- (NSString *)propertyNameForAccessor:(SEL)accessor baasClass:(Class<ABManagedProtocol>)baasClass;
/*!
 読み取り専用プロパティか
 @discussion 引数プロパティが読み取り専用かどうかを返します。
 @param propertyName プロパティ名
 @param baasClass モデルクラス
 @return YES:読み取り専用
 */
- (BOOL)isReadonlyProperty:(NSString *)propertyName baasClass:(Class<ABManagedProtocol>)baasClass;
/*!
 リポジトリをリセットする
 @discussion リポジトリをリセットし初期状態（ユーザ定義モデルクラスが未登録の状態）に戻します。
 */
- (void)reset;

@end