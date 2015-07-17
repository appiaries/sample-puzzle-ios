//
// Created by Appiaries Corporation on 2015/02/21.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ABGeoPoint;
@class AB;


#define ABQueryParamSelectedFieldsKey @"sel"
#define ABQueryParamExcludedFieldsKey @"excpt"
#define ABQueryParamObjectOnlyKey @"oonly"
#define ABQueryParamGetKey @"get"
#define ABQueryParamProcessKey @"proc"
#define ABQueryParamSortOrderKey @"order"
#define ABQueryParamDepthKey @"depth"
#define ABQueryParamProcessValueCountKey @"count"

#define ABQueryOperatorExists @"exist"
#define ABQueryOperatorEqualsTo @"eq"
#define ABQueryOperatorNotEqualsTo @"neq"
#define ABQueryOperatorIs @"is"
#define ABQueryOperatorIsNot @"isn"
#define ABQueryOperatorLessThan @"lt"
#define ABQueryOperatorLessThanOrEqualsTo @"lte"
#define ABQueryOperatorGreaterThan @"gt"
#define ABQueryOperatorGreaterThanOrEqualsTo @"gte"
#define ABQueryOperatorStartsWith @"sw"
#define ABQueryOperatorStartsWithCaseInsensitive @"swi"
#define ABQueryOperatorNotStartsWith @"nsw"
#define ABQueryOperatorNotStartsWithCaseInsensitive @"nswi"
#define ABQueryOperatorEndsWith @"ew"
#define ABQueryOperatorEndsWithCaseInsensitive @"ewi"
#define ABQueryOperatorNotEndsWith @"new"
#define ABQueryOperatorNotEndsWithCaseInsensitive @"newi"
#define ABQueryOperatorLike @"li"
#define ABQueryOperatorLikeWithCaseInsensitive @"lii"
#define ABQueryOperatorNotLike @"nli"
#define ABQueryOperatorNotLikeWithCaseInsensitive @"nlii"
#define ABQueryOperatorContains @"in"
#define ABQueryOperatorNotContains @"nin"
#define ABQueryOperatorWithinCircle @"wic"
#define ABQueryOperatorWithinBox @"wib"
#define ABQueryOperatorWithinPolygon @"wip"

#define ABSearchConditionSeparator @";"

typedef enum {
    ABQueryConjunctionAND,
    ABQueryConjunctionOR,
} ABQueryConjunction;

typedef enum {
    ABSortASC,
    ABSortDESC,
} ABSortOrderDirection;

typedef enum {
    ALL,
} UnionOption;

typedef NS_OPTIONS(NSInteger, ABRegexOption) {
    /*!
     指定なし (ABRegexOptionCaseSensitive が指定されたものと見なされる)
     */
    ABRegexOptionNone = 1 << 0,
    /*!
     大小文字を区別しない
     */
    ABRegexOptionCaseInsensitive = 1 << 1,
    /*!
     大小文字を区別する
     */
    ABRegexOptionCaseSensitive = 1 << 2,
};

@class ABQueryConditionBundle;
/*!
 クエリ条件結束ブロック
 @discussion 複数の条件を連結・グルーピングする際に使用するブロックです。
 */
typedef ABQueryConditionBundle *(^ABQueryConditionBundler)(ABQueryConditionBundle *conditionBundle);

/*!
 検索条件結束クラス
 @discussion 複数の検索条件を内部に保持し、出力時に連結した条件として出力します。<br/>
             SQLにおいて複数条件を1つの塊として扱う際に条件全体を「括弧（カッコ）」で括る、条件指定方法に相当します。
 */
@interface ABQueryConditionBundle : NSObject <NSCopying>
#pragma mark - Properties
@property (nonatomic) ABQueryConjunction conjunction;
@property (strong, nonatomic) NSMutableArray *existsArray;
@property (strong, nonatomic) NSMutableArray *isArray;
@property (strong, nonatomic) NSMutableArray *equalsToArray;
@property (strong, nonatomic) NSMutableArray *notEqualsToArray;
@property (strong, nonatomic) NSMutableArray *greaterThanArray;
@property (strong, nonatomic) NSMutableArray *greaterThanOrEqualsToArray;
@property (strong, nonatomic) NSMutableArray *lessThanArray;
@property (strong, nonatomic) NSMutableArray *lessThanOrEqualsToArray;
@property (strong, nonatomic) NSMutableArray *containsArray;
@property (strong, nonatomic) NSMutableArray *notContainsArray;
@property (strong, nonatomic) NSMutableArray *startsWithArray;
@property (strong, nonatomic) NSMutableArray *notStartsWithArray;
@property (strong, nonatomic) NSMutableArray *endsWithArray;
@property (strong, nonatomic) NSMutableArray *notEndsWithArray;
@property (strong, nonatomic) NSMutableArray *likeArray;
@property (strong, nonatomic) NSMutableArray *notLikeArray;
@property (strong, nonatomic) NSMutableArray *betweenArray;
@property (strong, nonatomic) NSMutableArray *withinCircleArray;
@property (strong, nonatomic) NSMutableArray *withinBoxArray;
@property (strong, nonatomic) NSMutableArray *withinPolygonArray;

#pragma mark - Initialization
- (instancetype)initWithConjunction:(ABQueryConjunction)conjunction;

/*!
 exists 条件
 @discussion フィールド自体の存在有無を指定し該当データを抽出します。
 @param field フィールド名
 @param value 真偽値 (YES:フィールドは存在する, NO:フィールドは存在しない)
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field exists:(BOOL)value;

/*!
 is true 条件
 @discussion フィールドの値が真(または偽)であるデータを抽出します。
 @param field フィールド名
 @param value 真偽値 (YES:真, NO:偽)
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field isTrue:(BOOL)value;

/*!
 is null 条件
 @discussion フィールドの値がNULL(または非NULL)であるデータを抽出します。
 @param field フィールド名
 @param value 真偽値 (YES:NULL, NO:NULLではない)
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field isNull:(BOOL)value;

/*!
 equalsTo 条件
 @discussion フィールドの値が比較対象値と同値であるデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field equalsTo:(id)value;

/*!
 notEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値でないデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notEqualsTo:(id)value;

/*!
 greaterThan 条件
 @discussion フィールドの値が比較対象値より大きいデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field greaterThan:(id)value;

/*!
 greaterThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは大きいデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field greaterThanOrEqualsTo:(id)value;

/*!
 lessThan 条件
 @discussion フィールドの値が比較対象値より小さいデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field lessThan:(id)value;

/*!
 lessThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは小さいデータを抽出します。
 @param field フィールド名
 @param value 比較対象値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field lessThanOrEqualsTo:(id)value;

/*!
 contains 条件
 @discussion フィールドの値が値リストに含まれるデータを抽出します。
 @param field フィールド名
 @param values 値リスト
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field contains:(NSArray *)values;

/*!
 notContains 条件
 @discussion フィールドの値が値リストに含まれるないデータを抽出します。
 @param field フィールド名
 @param values 値リスト
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notContains:(NSArray *)values;

/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;

/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;

/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;

/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;

/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。
 @param field フィールド名
 @param value 検索文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field like:(id)value;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field like:(id)value option:(ABRegexOption)option;

/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。
 @param field フィールド名
 @param value 検索文字列
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field notLike:(id)value option:(ABRegexOption)option;

/*!
 between 条件
 @discussion フィールドの値が上下限範囲内のデータを抽出します。
 @param field フィールド名
 @param from 下限値
 @param to 上限値
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range

/*!
 withCircle 条件
 @discussion 中心座標から半径 <_N_>kmの円圏内のデータを抽出します。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point 中心座標
 @param km 半径Km
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)add:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;

/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)add:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @param basePoint 基準座標
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)add:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;

/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)add:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @param basePoint 基準座標
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)add:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;

/* !
 predicate 条件
 @param NSPredicate 条件
 @return ABQueryConditionBundle オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)add:(NSPredicate *)predicate;

@end


/*!
 クエリ・オブジェクト
 @discussion アピアリーズ上の各種データを検索する際に使用する汎用クエリオブジェクトです。
 
 __See Also__: [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
@interface ABQuery : NSObject <NSCopying>
#pragma mark - Properties
/*! @name Properties */
@property (strong, nonatomic) NSString *collectionID;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param collectionID コレクションID
 @return ABQuery インスタンス
 */
- (instancetype)initWithCollectionID:(NSString *)collectionID;
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @return ABQuery インスタンス
 */
+ (instancetype)query;

#pragma mark - Execute
/*! @name Execute */
+ (void)execute:(ABQuery *)query;
- (void)execute;

#pragma mark - Query Conditions
/*! @name Conditions */
- (instancetype)selectAll;
- (instancetype)selectAllWithExcludedFields:(NSArray *)excludedFields;
- (instancetype)select:(NSArray *)fields;
- (instancetype)selectAllObjects;
- (instancetype)selectAllObjectsWithExcludedFields:(NSArray *)excludedFields;
- (instancetype)selectObjects:(NSArray *)fields;
- (instancetype)count;

- (instancetype)from:(NSString *)collectionID;
- (instancetype)fromQuery:(ABQuery *)query;

/*!
 クエリ条件連結
 @discussion 複数のクエリ条件を連結します。<br/>
             SQLにおいて複数条件を1つの塊として扱う際に条件全体を「括弧（カッコ）」で括る、条件指定方法に相当します。
 @param bundler ABQueryConditionBundler ブロック
 @param conjunction 連結子
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)bundle:(ABQueryConditionBundler)bundler conjunction:(ABQueryConjunction)conjunction;

/*!
 exists 条件
 @discussion フィールド自体の存在有無を指定し該当データを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:フィールドは存在する, NO:フィールドは存在しない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field exists:(BOOL)value;
/*!
 exists 条件
 @discussion フィールド自体の存在有無を指定し該当データを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:フィールドは存在する, NO:フィールドは存在しない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field exists:(BOOL)value;
/*!
 exists 条件
 @discussion フィールド自体の存在有無を指定し該当データを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:フィールドは存在する, NO:フィールドは存在しない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field exists:(BOOL)value;

/*!
 is true 条件
 @discussion フィールドの値が真(または偽)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:真, NO:偽)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field isTrue:(BOOL)value;
/*!
 is true 条件
 @discussion フィールドの値が真(または偽)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:真, NO:偽)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field isTrue:(BOOL)value;
/*!
 is true 条件
 @discussion フィールドの値が真(または偽)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:真, NO:偽)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field isTrue:(BOOL)value;

/*!
 is null 条件
 @discussion フィールドの値がNULL(または非NULL)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:NULL, NO:NULLではない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field isNull:(BOOL)value;
/*!
 is null 条件
 @discussion フィールドの値がNULL(または非NULL)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:NULL, NO:NULLではない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field isNull:(BOOL)value;
/*!
 is null 条件
 @discussion フィールドの値がNULL(または非NULL)であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 真偽値 (YES:NULL, NO:NULLではない)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field isNull:(BOOL)value;

/*!
 equalsTo 条件
 @discussion フィールドの値が比較対象値と同値であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field equalsTo:(id)value;
/*!
 equalsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field equalsTo:(id)value;
/*!
 equalsTo 条件
 @discussion フィールドの値が比較対象値と同値であるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field equalsTo:(id)value;

/*!
 notEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値でないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEqualsTo:(id)value;
/*!
 notEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値でないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEqualsTo:(id)value;
/*!
 notEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値でないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notEqualsTo:(id)value;

/*!
 greaterThan 条件
 @discussion フィールドの値が比較対象値より大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field greaterThan:(id)value;
/*!
 greaterThan 条件
 @discussion フィールドの値が比較対象値より大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field greaterThan:(id)value;
/*!
 greaterThan 条件
 @discussion フィールドの値が比較対象値より大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field greaterThan:(id)value;

/*!
 greaterThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field greaterThanOrEqualsTo:(id)value;
/*!
 greaterThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field greaterThanOrEqualsTo:(id)value;
/*!
 greaterThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは大きいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field greaterThanOrEqualsTo:(id)value;

/*!
 lessThan 条件
 @discussion フィールドの値が比較対象値より小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field lessThan:(id)value;
/*!
 lessThan 条件
 @discussion フィールドの値が比較対象値より小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field lessThan:(id)value;
/*!
 lessThan 条件
 @discussion フィールドの値が比較対象値より小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field lessThan:(id)value;

/*!
 lessThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field lessThanOrEqualsTo:(id)value;
/*!
 lessThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field lessThanOrEqualsTo:(id)value;
/*!
 lessThanOrEqualsTo 条件
 @discussion フィールドの値が比較対象値と同値かまたは小さいデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 比較対象値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field lessThanOrEqualsTo:(id)value;

/*!
 contains 条件
 @discussion フィールドの値が値リストに含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field contains:(NSArray *)fields;
/*!
 contains 条件
 @discussion フィールドの値が値リストに含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field contains:(NSArray *)fields;
/*!
 contains 条件
 @discussion フィールドの値が値リストに含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field contains:(NSArray *)fields;

/*!
 notContains 条件
 @discussion フィールドの値が値リストに含まれるないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notContains:(NSArray *)fields;
/*!
 notContains 条件
 @discussion フィールドの値が値リストに含まれるないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notContains:(NSArray *)fields;
/*!
 notContains 条件
 @discussion フィールドの値が値リストに含まれるないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param values 値リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notContains:(NSArray *)fields;

/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;

/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @discussion フィールドの値の先頭がPREFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value PREFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;

/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致するデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;

/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @discussion フィールドの値の先頭がSUFFIX文字列と一致しないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value SUFFIX文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;

/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field like:(id)value;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field like:(id)value option:(ABRegexOption)option;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field like:(id)value;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field like:(id)value option:(ABRegexOption)option;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field like:(id)value;
/*!
 like 条件
 @discussion フィールドの値に検索文字列が含まれるデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field like:(id)value option:(ABRegexOption)option;

/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notLike:(id)value option:(ABRegexOption)option;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notLike:(id)value option:(ABRegexOption)option;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @discussion フィールドの値に検索文字列が含まれないデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param value 検索文字列
 @param option オプション
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field notLike:(id)value option:(ABRegexOption)option;

/*!
 between 条件
 @discussion フィールドの値が上下限範囲内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param from 下限値
 @param to 上限値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range
/*!
 between 条件
 @discussion フィールドの値が上下限範囲内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名
 @param from 下限値
 @param to 上限値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range
/*!
 between 条件
 @discussion フィールドの値が上下限範囲内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名
 @param from 下限値
 @param to 上限値
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range

/*!
 withCircle 条件
 @discussion 中心座標から半径 <_N_>kmの円圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point 中心座標
 @param km 半径Km
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;
/*!
 withCircle 条件
 @discussion 中心座標から半径 <_N_>kmの円圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point 中心座標
 @param km 半径Km
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;
/*!
 withCircle 条件
 @discussion 中心座標から半径 <_N_>kmの円圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point 中心座標
 @param km 半径Km
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)or:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;

/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)or:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @discussion 座標1と座標2を角とする矩形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param point1 座標1
 @param point2 座標2
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)or:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;

/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に AND 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)or:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @discussion 座標1, ... 座標<_N_>を直線で結んだ多角形圏内のデータを抽出します。<br/>
             既に他の条件が指定されている場合は、それら条件に OR 連結されます。
 @param field フィールド名 <div class="important">"_coord" 固定</div>
 @param points 座標リスト
 @param basePoint 基準座標
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)or:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;

/* !
 predicate 条件
 @param NSPredicate 条件
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSPredicate *)predicate;
/* !
 @param NSPredicate 条件
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSPredicate *)predicate;
/* !
 @param NSPredicate 条件
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)or:(NSPredicate *)predicate;

/* !
 union
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)union:(ABQuery *)query option:(UnionOption)option;

/*!
 order by 条件
 @param field フィールド名
 @param direction ソート向き
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)orderBy:(NSString *)field direction:(ABSortOrderDirection)direction;
/*!
 order by 条件
 @param fields フィールド名リスト
 @param directions ソート向きリスト
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)orderBy:(NSArray *)fields directions:(NSArray *)directions;

/*!
 limit 条件
 @param limit 取得上限件数
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)limit:(NSUInteger)limit;
/*!
 limit 条件
 @param limit 取得上限件数
 @param skip スキップ件数 (読み飛ばし件数)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)limit:(NSUInteger)limit skip:(NSUInteger)skip;
/* !
 limit 条件
 @param limit 取得上限件数
 @param skip スキップ件数 (読み飛ばし件数)
 @param depth 取得データ深度
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)limit:(NSUInteger)limit skip:(NSUInteger)skip depth:(NSUInteger)depth;
/* !
 skip 条件
 @param skip スキップ件数 (読み飛ばし件数)
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)skip:(NSUInteger)skip;
/* !
 skip 条件
 @param skip スキップ件数 (読み飛ばし件数)
 @param depth 取得データ深度
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)skip:(NSUInteger)skip depth:(NSUInteger)depth;
/* !
 depth 条件
 @param depth 取得データ深度
 @return ABQuery オブジェクト
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)depth:(NSUInteger)depth;

#pragma mark - Accessors
/*! @name Accessors */
/*!
 文字列を返す
 @discussion 検索実行時に REST API へ渡される検索パラメータ文字列を返します。
 @return 検索パラメータ文字列
 */
- (NSString *)string;
/* !
 クエリ文字列を返す
 @discussion 検索実行時に REST API へ渡される検索パラメータ文字列の内、クエリ文字列部のみを返します。
 @return クエリ文字列
 */
- (NSString *)queryString;
/* !
 検索条件文字列を返す
 @discussion 検索実行時に REST API へ渡される検索パラメータ文字列の内、検索条件文字列部のみを返します。
 @return 検索条件文字列
 */
- (NSString *)conditionString;

@end
