//
//  ViewController.m
//  DGWebView
//
//  Created by Gavin on 16/7/29.
//  Copyright © 2016年 DGNICE. All rights reserved.
//

#import "ViewController.h"

#import "DGWebView.h"

@interface ViewController ()
<
DGWebViewDelegate
>
@property (nonatomic, strong) DGWebView *showWebView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self setSelfAttribution];
    [self configSubView];
}

- (void)setSelfAttribution{
    self.title = @"@DGNICE";
}

- (void)configSubView{
    [self.view addSubview:self.showWebView];
}

#pragma mark - DGWebViewDelegate
- (void)dgwebViewDidStartLoad:(DGWebView *)webview
{
    NSLog(@"页面开始加载");
}
- (void)dgwebView:(DGWebView *)webview shouldStartLoadWithURL:(NSURL *)URL
{
    NSLog(@"截取到URL：%@",URL);
}
- (void)dgwebView:(DGWebView *)webview didFinishLoadingURL:(NSURL *)URL
{
    NSLog(@"页面加载完成");
}
- (void)dgwebView:(DGWebView *)webview didFailToLoadURL:(NSURL *)URL error:(NSError *)error
{
    NSLog(@"加载出现错误");
}

-(DGWebView *)showWebView{
    if (_showWebView == nil) {
        _showWebView = [[DGWebView alloc] initWithFrame:self.view.bounds];
        [_showWebView loadURLString:@"http://www.baidu.com"];
        _showWebView.delegate = self;
    }
    return _showWebView;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
