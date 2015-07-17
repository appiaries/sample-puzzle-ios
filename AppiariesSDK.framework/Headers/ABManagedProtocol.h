//
// Created by Appiaries Corporation on 2015/02/23.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABGeoPoint;

/*!
 アピアリーズ管理オブジェクト・プロトコル
 @discussion アピアリーズで管理するオブジェクトに使用します。<br/>
 実際には、ABModel を継承した組み込みクラス (ABDBObject / ABFile / ABSequence / ABUser / ABPushMessage) と合わせて使用します。
 */
@protocol ABManagedProtocol <NSObject>

@required
/*!
 コレクションIDを返す
 @discussion アピアリーズ上の対応するコレクションのIDを返却するよう実装します。
 @return コレクションID
 */
+ (NSString *)collectionID;

@optional
@property (strong, nonatomic) ABGeoPoint *geoPoint;

@end