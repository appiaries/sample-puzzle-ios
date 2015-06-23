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
    ABSortASC,
    ABSortDESC,
} ABSortOrderDirection;

typedef enum {
    ALL,
} UnionOption;

typedef NS_OPTIONS(NSInteger, ABRegexOption) {
    /*!
     指定なし
     */
    ABRegexOptionNone = 1 << 0,
    /*!
     大小文字を区別しない
     */
    ABRegexOptionCaseInsensitive = 1 << 1,
};

/*!
 クエリ・オブジェクト
 @discussion アピアリーズ BaaS 上の各種データを検索する際に使用する汎用クエリオブジェクトです。
 
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
 exists 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field exists:(BOOL)value;
/*!
 exists 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field exists:(BOOL)value;
/*!
 exists 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field exists:(BOOL)value;

/*!
 is true 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field isTrue:(BOOL)value;
/*!
 is true 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field isTrue:(BOOL)value;
/*!
 is true 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field isTrue:(BOOL)value;

/*!
 is null 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field isNull:(BOOL)value;
/*!
 is null 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field isNull:(BOOL)value;
/*!
 is null 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field isNull:(BOOL)value;

/*!
 equalsTo 条件
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
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field equalsTo:(id)value;

/*!
 notEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEqualsTo:(id)value;
/*!
 notEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEqualsTo:(id)value;
/*!
 notEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notEqualsTo:(id)value;

/*!
 greaterThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field greaterThan:(id)value;
/*!
 greaterThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field greaterThan:(id)value;
/*!
 greaterThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field greaterThan:(id)value;

/*!
 greaterThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field greaterThanOrEqualsTo:(id)value;
/*!
 greaterThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field greaterThanOrEqualsTo:(id)value;
/*!
 greaterThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field greaterThanOrEqualsTo:(id)value;

/*!
 lessThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field lessThan:(id)value;
/*!
 lessThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field lessThan:(id)value;
/*!
 lessThan 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field lessThan:(id)value;

/*!
 lessThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field lessThanOrEqualsTo:(id)value;
/*!
 lessThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field lessThanOrEqualsTo:(id)value;
/*!
 lessThanOrEqualsTo 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field lessThanOrEqualsTo:(id)value;

/*!
 contains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field contains:(NSArray *)fields;
/*!
 contains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field contains:(NSArray *)fields;
/*!
 contains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field contains:(NSArray *)fields;

/*!
 notContains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notContains:(NSArray *)fields;
/*!
 notContains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notContains:(NSArray *)fields;
/*!
 notContains 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notContains:(NSArray *)fields;

/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;
/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;
/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field startsWith:(id)value;
/*!
 startsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field startsWith:(id)value option:(ABRegexOption)option;

/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;
/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;
/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notStartsWith:(id)value;
/*!
 notStartsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notStartsWith:(id)value option:(ABRegexOption)option;

/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;
/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;
/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field endsWith:(id)value;
/*!
 endsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field endsWith:(id)value option:(ABRegexOption)option;

/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;
/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;
/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notEndsWith:(id)value;
/*!
 notEndsWith 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notEndsWith:(id)value option:(ABRegexOption)option;

/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field like:(id)value;
/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field like:(id)value option:(ABRegexOption)option;
/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field like:(id)value;
/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field like:(id)value option:(ABRegexOption)option;
/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field like:(id)value;
/*!
 like 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field like:(id)value option:(ABRegexOption)option;

/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field notLike:(id)value option:(ABRegexOption)option;
/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field notLike:(id)value option:(ABRegexOption)option;
/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notLike:(id)value;
/*!
 notLike 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field notLike:(id)value option:(ABRegexOption)option;

/*!
 between 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range
/*!
 between 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range
/*!
 between 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSString *)field between:(NSNumber *)from and:(NSNumber *)to; // or range

/*!
 withCircle 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;
/*!
 withCircle 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;
/*!
 withCircle 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
//- (instancetype)or:(NSString *)field withinCircle:(ABGeoPoint *)point kilometers:(CGFloat)km;

/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;
/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;
/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
//- (instancetype)or:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2;
/*!
 withBox 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
//- (instancetype)or:(NSString *)field withinBoxWithPoint1:(ABGeoPoint *)point1 point2:(ABGeoPoint *)point2 basePoint:(ABGeoPoint *)basePoint;

/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)where:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;
/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
- (instancetype)and:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;
/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
//- (instancetype)or:(NSString *)field withinPolygonWithPoints:(NSArray *)points;
/*!
 withPolygon 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 @see [アピアリーズドキュメント &raquo; 機能概要 &raquo; ジオロケーション](http://docs.appiaries.com/?p=20)
 */
//- (instancetype)or:(NSString *)field withinPolygonWithPoints:(NSArray *)points basePoint:(ABGeoPoint *)basePoint;

/*!
 predicate 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)where:(NSPredicate *)predicate;
/*!
 predicate 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)and:(NSPredicate *)predicate;
/*!
 predicate 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)or:(NSPredicate *)predicate;

/*!
 union
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
//- (instancetype)union:(ABQuery *)query option:(UnionOption)option;

/*!
 order by 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)orderBy:(NSString *)field direction:(ABSortOrderDirection)direction;
/*!
 order by 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)orderBy:(NSArray *)fields directions:(NSArray *)directions;

/*!
 limit 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)limit:(NSUInteger)limit;
/*!
 limit 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)limit:(NSUInteger)limit skip:(NSUInteger)skip;
- (instancetype)limit:(NSUInteger)limit skip:(NSUInteger)skip depth:(NSUInteger)depth;
/*!
 skip 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)skip:(NSUInteger)skip;
/*!
 skip 条件
 @see [アピアリーズドキュメント &raquo; データ検索における条件式](http://docs.appiaries.com/?p=1280)
 */
- (instancetype)skip:(NSUInteger)skip depth:(NSUInteger)depth;
- (instancetype)depth:(NSUInteger)depth;

#pragma mark - Accessors
/*! @name Accessors */
- (NSString *)string;
- (NSString *)queryString;
- (NSString *)conditionString;

@end
