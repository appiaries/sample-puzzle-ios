//
// Created by Appiaries Corporation on 15/03/18.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AppiariesSDK/ABWebViewSupport.h>


@protocol ABPopoverWebViewDelegate;

/*!
 ポップオーバ WebView コントローラ
 */
@interface ABPopoverWebViewController : UIViewController  <UIWebViewDelegate, ABWebViewSupport>
#pragma mark - Properties
/** @name Properties */
/*!
 delegate
 @discussion ABPopoverWebViewDelegate を実装した UIViewController のインスタンスを指定します。
 */
@property (nonatomic) id<ABPopoverWebViewDelegate> baasDelegate;
/*!
 webView の背景色
 */
@property (strong, nonatomic) UIColor *backgroundColor;
/*!
 ボーダー色
 */
@property (strong, nonatomic) UIColor *borderColor;
/*!
 ボーダー太さ
 */
@property (nonatomic) CGFloat borderWidth;
/*
 コーナー半径(角丸)
 */
@property (nonatomic) CGFloat cornerRadius;
/*!
 閉じるボタン画像
 */
@property (strong, nonatomic) UIImage *closeButtonImage;
/*!
 ActivityIndicatorView のスタイル
 */
@property (nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
/*!
 ActivityIndicatorView の色
 */
@property (strong, nonatomic) UIColor *activityIndicatorViewColor;

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
