//
//  APISWebViewController.h
//  AppiariesSDK
//
//  Created by Appiaries Corporation on 2014/08/22.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APISPushAPIClient.h"

@protocol APISWebViewControllerDelegate;

/**
 * AppiariesSDK組み込みWebViewコントローラ
 * @since AppiariesSDK 1.2.0
 */
@interface APISWebViewController : UIViewController <UIWebViewDelegate, APISPushNotificationSupport>
#pragma mark - Properties
/** @name Properties */
/**
 * webView の背景色
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) UIColor *backgroundColor;
/**
 * ボーダー色
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) UIColor *borderColor;
/**
 * ボーダー太さ
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) CGFloat borderWidth;
/**
 * コーナー半径(角丸)
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) CGFloat cornerRadius;
/**
 * 閉じるボタン画像
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) UIImage *closeButtonImage;
/**
 * ActivityIndicatorView のスタイル
 * @since AppiariesSDK 1.2.0
 */
@property (nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
/**
 * ActivityIndicatorView の色
 * @since AppiariesSDK 1.2.0
 */
@property (strong, nonatomic) UIColor *activityIndicatorViewColor;

@end


/**
 * APISWebViewController用delegate
 * @since AppiariesSDK 1.2.0
 */
@protocol APISWebViewControllerDelegate <NSObject>
#pragma mark - Delegate methods
/** @name Delegate methods */
@required
/**
 * 画面を閉じる直前に呼ばれるdelegateメソッド
 * @param viewController 画面表示中のviewControllerインスタンス
 * @since AppiariesSDK 1.2.0
 */
- (void)apisWebViewControllerWillDismiss:(UIViewController *)viewController;

@optional
- (BOOL)apisWebViewController:(UIViewController *)controller webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)apisWebViewController:(UIViewController *)controller webViewDidStartLoad:(UIWebView *)webView;
- (void)apisWebViewController:(UIViewController *)controller webViewDidFinishLoad:(UIWebView *)webView;
- (void)apisWebViewController:(UIViewController *)controller webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end