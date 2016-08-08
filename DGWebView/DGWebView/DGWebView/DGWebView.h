//
//  DGWebView.h
//  DGWebView
//
//  Created by Gavin on 16/7/29.
//  Copyright © 2016年 DGNICE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class DGWebView;
@protocol DGWebViewDelegate <NSObject>

@optional
- (void)dgwebViewDidStartLoad:(DGWebView *)webview;

- (void)dgwebView:(DGWebView *)webview didFinishLoadingURL:(NSURL *)URL;
- (void)dgwebView:(DGWebView *)webview didFailToLoadURL:(NSURL *)URL error:(NSError *)error;

- (void)dgwebView:(DGWebView *)webview shouldStartLoadWithURL:(NSURL *)URL;

@end

@interface DGWebView : UIView<WKNavigationDelegate, WKUIDelegate, UIWebViewDelegate>

#pragma mark - Public Properties
@property (nonatomic, weak) id <DGWebViewDelegate> delegate;

// The main and only UIProgressView
@property (nonatomic, strong) UIProgressView *progressView;
// The web views
// Depending on the version of iOS, one of these will be set
@property (nonatomic, strong) WKWebView *wkWebView;
@property (nonatomic, strong) UIWebView *uiWebView;

#pragma mark - Initializers view
- (instancetype)initWithFrame:(CGRect)frame;

#pragma mark - Static Initializers
@property (nonatomic, strong) UIBarButtonItem *actionButton;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, strong) UIColor *barTintColor;
@property (nonatomic, assign) BOOL actionButtonHidden;
@property (nonatomic, assign) BOOL showsURLInNavigationBar;
@property (nonatomic, assign) BOOL showsPageTitleInNavigationBar;

//Allow for custom activities in the browser by populating this optional array
@property (nonatomic, strong) NSArray *customActivityItems;

#pragma mark - Public Interface
/**
 *  Load a NSURLURLRequest to web view
 *
 *  @param request NSURLRequest
 */
- (void)loadRequest:(NSURLRequest *)request;

/**
 *  Load a NSURL to web view
 *
 *  @param URL NSURL
 */
- (void)loadURL:(NSURL *)URL;

/**
 *  Loads a URL as NSString to web view
 *
 *  @param URLString URL String
 */
- (void)loadURLString:(NSString *)URLString;

/**
 *  Loads an string containing HTML to web view
 *
 *  @param HTMLString HTML Code
 */
- (void)loadHTMLString:(NSString *)HTMLString;

@end

