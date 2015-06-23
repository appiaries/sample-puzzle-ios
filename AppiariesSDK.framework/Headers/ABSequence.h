//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABModel;
@class ABACL;
@class ABQuery;
@protocol ABManagedProtocol;

/*!
 シーケンス・モデル 
 @discussion シーケンス・コレクションを表現するモデルクラスです。
 
 __See Also__: [アピアリーズドキュメント &raquo; シーケンス値を管理する](http://docs.appiaries.com/?p=90)
 */
@interface ABSequence : ABModel <ABManagedProtocol>
#pragma mark - Properties
/*! @name Properties */
// **RESERVED** *!
// アクセス制御リスト
// */
//@property (strong, nonatomic) ABACL *ACL;
/*!
 シーケンス名
 */
@property (strong, nonatomic) NSString *name;
/*!
 初期値
 */
@property (nonatomic) long long initialValue;
/*!
 シーケンス値（現在値）
 */
@property (nonatomic) long long value;
/*!
 減算を許可するか (YES=許可する)
 */
@property (nonatomic, getter=isDecrementable) BOOL decrementable;
//FIXME: propertyのアクセス制限をどうするか？

#pragma mark - Initialization
/*! @name Initialization */
/*!
 シングルトン・インスタンスを返す
 @discussion ABSequence のシングルトン・インスタンスを返します。
 @return ABSequence のシングルトンインスタンス
 */
+ (instancetype)sequence;
+ (instancetype)sequenceWithCollectionID:(NSString *)collectionID;
/*!
 シングルトン・インスタンスを返す
 @discussion ABSequence のシングルトン・インスタンスを返します。
 @return ABSequence のシングルトンインスタンス
 */
+ (instancetype)sequenceWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Get Current Value
/*! @name Get Current Value */
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値
 */
- (long long)getCurrentValueSynchronouslyWithError:(ABError **)error;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param option ABSequenceFetchOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値
 */
- (long long)getCurrentValueSynchronouslyWithOption:(ABSequenceFetchOption)option error:(ABError **)error;
/*!
 シーケンスの現在値を取得する
 @discussion 非同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getCurrentValueWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値を取得する
 @discussion 非同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceFetchOption オプション
 */
- (Async)getCurrentValueWithTarget:(id)target selector:(SEL)selector option:(ABSequenceFetchOption)option;
/*!
 シーケンスの現在値を取得する
 @discussion 非同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getCurrentValueWithBlock:(ABLongLongBlock)block;
/*!
 シーケンスの現在値を取得する
 @discussion 非同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceFetchOption オプション
 */
- (Async)getCurrentValueWithBlock:(ABLongLongBlock)block option:(ABSequenceFetchOption)option;

#pragma mark - Increment
/*! @name Increment */
/*!
 シーケンスをインクリメントする
 @discussion 同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)incrementSynchronouslyWithError:(ABError **)error;
/*!
 シーケンスをインクリメントする
 @discussion 同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)incrementSynchronouslyWithOption:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 */
- (Async)increment;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 */
- (Async)incrementWithOption:(ABSequenceAddValueOption)option;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)incrementWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)incrementWithTarget:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)incrementWithBlock:(ABResultBlock)block;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)incrementWithBlock:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Next Value
/*! @name Get Next Value */
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getNextValueSynchronouslyWithError:(ABError **)error;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getNextValueSynchronouslyWithOption:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getNextValueWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getNextValueWithTarget:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getNextValueWithBlock:(ABLongLongBlock)block;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getNextValueWithBlock:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Decrement
/*! @name Decrement */
/*!
 シーケンスをデクリメントする
 @discussion 同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)decrementSynchronouslyWithError:(ABError **)error;
/*!
 シーケンスをデクリメントする
 @discussion 同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)decrementSynchronouslyWithOption:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 */
- (Async)decrement;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrementWithOption:(ABSequenceAddValueOption)option;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)decrementWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrementWithTarget:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)decrementWithBlock:(ABResultBlock)block;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrementWithBlock:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Previous Value
/*! @name Get Previous Value */
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getPreviousValueSynchronouslyWithError:(ABError **)error;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getPreviousValueSynchronouslyWithOption:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getPreviousValueWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getPreviousValueWithTarget:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getPreviousValueWithBlock:(ABLongLongBlock)block;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getPreviousValueWithBlock:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Add
/*! @name Add */
/*!
 シーケンスに値を加算(減算)する
 @discussion 同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)addSynchronously:(long long)amount error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)する
 @discussion 同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)addSynchronously:(long long)amount option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 */
- (Async)add:(long long)amount;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(long long)amount option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)add:(long long)amount target:(id)target selector:(SEL)selector;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(long long)amount target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)add:(long long)amount block:(ABResultBlock)block;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(long long)amount block:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Value With Adding Amount
/*! @name Get Value With Adding Amount */
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param error 実行時のエラーを格納する
 @return シーケンスに値を加算(減算)した計算後の値
 */
- (long long)getValueSynchronouslyWithAddingAmount:(long long)amount error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスに値を加算(減算)した計算後の値
 */
- (long long)getValueSynchronouslyWithAddingAmount:(long long)amount option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getValueWithAddingAmount:(long long)amount target:(id)target selector:(SEL)selector;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getValueWithAddingAmount:(long long)amount target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getValueWithAddingAmount:(long long)amount block:(ABLongLongBlock)block;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getValueWithAddingAmount:(long long)amount block:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Reset
/*! @name Reset */
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetSynchronouslyWithError:(ABError **)error;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param option ABSequenceResetOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetSynchronouslyWithOption:(ABSequenceResetOption)option error:(ABError **)error;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 */
- (Async)reset;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param option ABSequenceResetOption オプション
 */
- (Async)resetWithOption:(ABSequenceResetOption)option;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)resetWithTarget:(id)target selector:(SEL)selector;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceResetOption オプション
 */
- (Async)resetWithTarget:(id)target selector:(SEL)selector option:(ABSequenceResetOption)option;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)resetWithBlock:(ABResultBlock)block;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceResetOption オプション
 */
- (Async)resetWithBlock:(ABResultBlock)block option:(ABSequenceResetOption)option;

#pragma mark - Miscellaneous
/*! @name Miscellaneous */
/*!
 クエリオブジェクトを返す
 @discussion シーケンス・オブジェクト検索用のクエリオブジェクトを返します。
 @return ABQuery オブジェクト
 */
+ (ABQuery *)query;

@end