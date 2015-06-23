//
// Created by Appiaries Corporation on 2015/03/10.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSString *ABErrorDomain;
extern NSString *ABErrorDetailCodesKey;
extern NSString *ABErrorErrorFieldsKey;

/*!
 エラーオブジェクト
 
 __See Also__: [アピアリーズドキュメント &raquo; 共通エラー](http://docs.appiaries.com/?p=1140#i-5)
 */
@interface ABError : NSError
#pragma mark - Properties
/*! @name Properties */
/*!
 詳細エラーコード
 @discussion エラー発生時、より粒度の細かいエラーコードが格納される場合があります。
 */
@property (strong, nonatomic, readonly) NSOrderedSet *detailCodes;
/*!
 エラー・フィールド
 @discussion エラー発生時に、原因となったフィールド（リクエストに含まれるフィールドなど）が格納される場合があります。
 */
@property (strong, nonatomic, readonly) NSOrderedSet *errorFields;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 エラーオブジェクトを生成する
 @param code エラーコード
 @param userInfo エラー情報
 @return エラーオブジェクト
 */
+ (instancetype)errorWithCode:(NSInteger)code userInfo:(NSDictionary *)userInfo;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 連結された詳細エラーコード文字列を返す
 @discussion 詳細エラーコードが複数存在した場合に、カンマ(,)で連結した文字列を返します。
 @param detailCodes 詳細エラーコード
 @return 連結された詳細エラーコード文字列
 */
+ (NSString *)joinedDetailCodes:(NSOrderedSet *)detailCodes;
/*!
 連結されたエラー・フィールド文字列を返す
 @discussion エラー・フィールドが複数存在した場合に、カンマ(,)で連結した文字列を返します。
 @param errorFields エラー・フィールド
 @return 連結されたエラー・フィールド文字列
 */
+ (NSString *)joinedErrorFields:(NSOrderedSet *)errorFields;

@end