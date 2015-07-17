//
// Created by Appiaries Corporation on 15/03/19.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ABPopoverWebViewDelegate;

/*!
 WebView サポート
 @discussion リッチプッシュ通知の Webコンテンツを表示する WebView をカスタマイズする場合に、<br>
             ユーザ定義の UIViewController に本プロトコルを実装します。
 */
@protocol ABWebViewSupport <NSObject>
@required
#pragma mark - Properties
/*! name Properties */
/*!
 delegate
 @discussion ABPopoverWebViewDelegate を実装した UIViewController のインスタンスを指定します。
 */
@property (nonatomic) id<ABPopoverWebViewDelegate> baasDelegate;

#pragma mark - Initialization
/*! @name Initialization */
/*!
 インスタンスを生成する
 @discussion 新しいインスタンスを生成します。
 @param url オープンするURL
 @return インスタンス
 */
- (id)initWithURL:(NSURL *)url;

@end