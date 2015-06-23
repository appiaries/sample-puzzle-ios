//
// Created by Appiaries Corporation on 15/03/18.
// Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UIViewController;
@class UIWebView;
@protocol ABWebViewSupport;

/*!
 ポップオーバ WebView コントローラ用 Delegate
 @discussion ポップオーバ WebView コントローラ (ABPopoverWebViewController) の委譲メソッドを実装する際に使用します。
 */
@protocol ABPopoverWebViewDelegate <NSObject>
@required
//#pragma mark - Properties
//@property (weak, nonatomic) id<ABPopoverWebViewDelegate> baasDelegate;
//
//#pragma mark - Initialization
//- (id)initWithURL:(NSURL *)url;

#pragma mark - Delegate methods
/*! @name Delegate methods */
/*
 画面を閉じる直前に呼ばれるdelegateメソッド
 @param viewController 画面表示中のviewControllerインスタンス
 */
- (void)abPopoverWebViewControllerWillDismiss:(UIViewController<ABWebViewSupport> *)viewController;

@optional
/*!
 ABPopoverWebViewController が内包する UIWebView に対して [UIWebViewDelegate webView:shouldStartLoadWithRequest:navigationType:] を実装するためのアダプタです。
 @see https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIWebViewDelegate_Protocol/
 */
- (BOOL)abPopoverWebViewController:(UIViewController *)controller webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
/*!
 ABPopoverWebViewController が内包する UIWebView に対して [UIWebViewDelegate webViewDidStartLoad:] を実装するためのアダプタです。
 @see https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIWebViewDelegate_Protocol/
 */
- (void)abPopoverWebViewController:(UIViewController *)controller webViewDidStartLoad:(UIWebView *)webView;
/*!
 ABPopoverWebViewController が内包する UIWebView に対して [UIWebViewDelegate webViewDidFinishLoad:] を実装するためのアダプタです。
 @see https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIWebViewDelegate_Protocol/
 */
- (void)abPopoverWebViewController:(UIViewController *)controller webViewDidFinishLoad:(UIWebView *)webView;
/*!
 ABPopoverWebViewController が内包する UIWebView に対して [UIWebViewDelegate webView:didFailLoadWithError:] を実装するためのアダプタアダプタです。
 @see https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIWebViewDelegate_Protocol/
 */
- (void)abPopoverWebViewController:(UIViewController *)controller webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end