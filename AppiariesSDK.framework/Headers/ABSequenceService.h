//
// Created by Appiaries Corporation on 2015/02/22.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppiariesSDK/ABConstants.h>

@class ABResult;
@class ABSequence;

/*!
 シーケンス・サービス

 __See Also__: [アピアリーズドキュメント &raquo; シーケンス値を管理する](http://docs.appiaries.com/?p=90)
 */
@interface ABSequenceService : NSObject

#pragma mark - Initialization
/*! @name Initialization */
/*!
 シングルトン・インスタンスを返す
 @discussion ABSequenceService のシングルトン・インスタンスを返します。
 @return ABSequenceService のシングルトン・インスタンス
 */
+ (instancetype)sharedService;
/*!
 ABSequence のシングルトン・インスタンスを返す
 @discussion ABSequence のシングルトン・インスタンスを返します。
 @return ABSequence (またはその派生クラス) のシングルトン・インスタンス
 */
- (ABSequence *)sequence;
/*- (ABSequence *)sequenceWithCollectionID:(NSString *)collectionID;*/
/*!
 ABSequence のシングルトン・インスタンスを返す
 @discussion ABSequence のシングルトン・インスタンスを返します。
 @param dictionary ディクショナリ形式のJSONデータ
 @return ABSequence (またはその派生クラス) のシングルトン・インスタンス
 */
- (ABSequence *)sequenceWithDictionary:(NSDictionary *)dictionary;

#pragma mark - Fetch
/*! @name Fetch */
/*!
 シーケンスを取得する
 @discussion 同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスを取得する
 @discussion 同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceFetchOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)fetchSynchronously:(ABSequence *)sequence option:(ABSequenceFetchOption)option error:(ABError **)error;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 */
- (Async)fetch:(ABSequence *)sequence;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceFetchOption オプション
 */
- (Async)fetch:(ABSequence *)sequence option:(ABSequenceFetchOption)option;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)fetch:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceFetchOption オプション
 */
- (Async)fetch:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceFetchOption)option;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)fetch:(ABSequence *)sequence block:(ABResultBlock)block;
/*!
 シーケンスを取得する
 @discussion 非同期モードでシーケンスを取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceFetchOption オプション
 */
- (Async)fetch:(ABSequence *)sequence block:(ABResultBlock)block option:(ABSequenceFetchOption)option;

#pragma mark - Get Current Value
/*! @name Get Current Value */
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値
 */
- (long long)getCurrentValueSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceFetchOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値
 */
- (long long)getCurrentValueSynchronously:(ABSequence *)sequence option:(ABSequenceFetchOption)option error:(ABError **)error;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getCurrentValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceFetchOption オプション
 */
- (Async)getCurrentValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceFetchOption)option;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getCurrentValue:(ABSequence *)sequence block:(ABLongLongBlock)block;
/*!
 シーケンスの現在値を取得する
 @discussion 同期モードでシーケンスの現在値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス取得](http://docs.appiaries.com/?p=1270)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceFetchOption オプション
 */
- (Async)getCurrentValue:(ABSequence *)sequence block:(ABLongLongBlock)block option:(ABSequenceFetchOption)option;

#pragma mark - Increment
/*! @name Increment */
/*!
 シーケンスをインクリメントする
 @discussion 同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)incrementSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスをインクリメントする
 @discussion 同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)incrementSynchronously:(ABSequence *)sequence option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 */
- (Async)increment:(ABSequence *)sequence;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 */
- (Async)increment:(ABSequence *)sequence option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)increment:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)increment:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)increment:(ABSequence *)sequence block:(ABResultBlock)block;
/*!
 シーケンスをインクリメントする
 @discussion 非同期モードでシーケンスをインクリメント(シーケンスの現在値に+1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)increment:(ABSequence *)sequence block:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Next Value
/*! @name Get Next Value */
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getNextValueSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getNextValueSynchronously:(ABSequence *)sequence option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getNextValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getNextValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getNextValue:(ABSequence *)sequence block:(ABLongLongBlock)block;
/*!
 シーケンスの現在値に+1した値を取得する
 @discussion 非同期モードでシーケンスの現在値に+1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getNextValue:(ABSequence *)sequence block:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Decrement
/*! @name Decrement */
/*!
 シーケンスをデクリメントする
 @discussion 同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)decrementSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスをデクリメントする
 @discussion 同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)decrementSynchronously:(ABSequence *)sequence option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 */
- (Async)decrement:(ABSequence *)sequence;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrement:(ABSequence *)sequence option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)decrement:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrement:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)decrement:(ABSequence *)sequence block:(ABResultBlock)block;
/*!
 シーケンスをデクリメントする
 @discussion 非同期モードでシーケンスをデクリメント(シーケンスの現在値を-1)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)decrement:(ABSequence *)sequence block:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Previous Value
/*! @name Get Previous Value */
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getPreviousValueSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスの現在値に+1した値
 */
- (long long)getPreviousValueSynchronously:(ABSequence *)sequence option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getPreviousValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getPreviousValue:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getPreviousValue:(ABSequence *)sequence block:(ABLongLongBlock)block;
/*!
 シーケンスの現在値を-1した値を取得する
 @discussion 非同期モードでシーケンスの現在値を-1した値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getPreviousValue:(ABSequence *)sequence block:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Add Value
/*! @name Add Value */
/*!
 シーケンスに値を加算(減算)する
 @discussion 同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)addSynchronously:(ABSequence *)sequence amount:(long long)amount error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)する
 @discussion 同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)addSynchronously:(ABSequence *)sequence amount:(long long)amount option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount target:(id)target selector:(SEL)selector;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount block:(ABResultBlock)block;
/*!
 シーケンスに値を加算(減算)する
 @discussion 非同期モードでシーケンスに値を加算(減算)します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)add:(ABSequence *)sequence amount:(long long)amount block:(ABResultBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Get Value
/*! @name Get Value */
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param error 実行時のエラーを格納する
 @return シーケンスに値を加算(減算)した計算後の値
 */
- (long long)getValueSynchronously:(ABSequence *)sequence addingAmount:(long long)amount error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param amount シーケンスの現在値に対して加算(減算)する値
 @param option ABSequenceAddValueOption オプション
 @param error 実行時のエラーを格納する
 @return シーケンスに値を加算(減算)した計算後の値
 */
- (long long)getValueSynchronously:(ABSequence *)sequence addingAmount:(long long)amount option:(ABSequenceAddValueOption)option error:(ABError **)error;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)getValue:(ABSequence *)sequence addingAmount:(long long)amount target:(id)target selector:(SEL)selector;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getValue:(ABSequence *)sequence addingAmount:(long long)amount target:(id)target selector:(SEL)selector option:(ABSequenceAddValueOption)option;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABLongLongBlock コールバック・ブロック
 */
- (Async)getValue:(ABSequence *)sequence addingAmount:(long long)amount block:(ABLongLongBlock)block;
/*!
 シーケンスに値を加算(減算)した計算後の値を取得する
 @discussion 非同期モードでシーケンスに値を加算(減算)した計算後の値を取得します。
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @see [アピアリーズドキュメント &raquo; シーケンス発行](http://docs.appiaries.com/?p=1260)
 @param block ABLongLongBlock コールバック・ブロック
 @param option ABSequenceAddValueOption オプション
 */
- (Async)getValue:(ABSequence *)sequence addingAmount:(long long)amount block:(ABLongLongBlock)block option:(ABSequenceAddValueOption)option;

#pragma mark - Reset
/*! @name Reset */
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetSynchronously:(ABSequence *)sequence error:(ABError **)error;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceResetOption オプション
 @param error 実行時のエラーを格納する
 @return ABResult オブジェクト
 */
- (ABResult *)resetSynchronously:(ABSequence *)sequence option:(ABSequenceResetOption)option error:(ABError **)error;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 */
- (Async)reset:(ABSequence *)sequence;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param option ABSequenceResetOption オプション
 */
- (Async)reset:(ABSequence *)sequence option:(ABSequenceResetOption)option;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 */
- (Async)reset:(ABSequence *)sequence target:(id)target selector:(SEL)selector;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param target コールバック・ターゲット
 @param selector コールバック・セレクタ
 @param option ABSequenceResetOption オプション
 */
- (Async)reset:(ABSequence *)sequence target:(id)target selector:(SEL)selector option:(ABSequenceResetOption)option;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 */
- (Async)reset:(ABSequence *)sequence block:(ABResultBlock)block;
/*!
 シーケンス・オブジェクトをリセットする
 @discussion 非同期モードでシーケンス・オブジェクトをリセットします。
 @see [アピアリーズドキュメント &raquo; シーケンス・リセット]()
 @param sequence シーケンス・オブジェクト (またはその派生オブジェクト)
 @param block ABResultBlock コールバック・ブロック
 @param option ABSequenceResetOption オプション
 */
- (Async)reset:(ABSequence *)sequence block:(ABResultBlock)block option:(ABSequenceResetOption)option;

@end