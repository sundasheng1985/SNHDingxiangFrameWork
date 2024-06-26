#ifndef DXCaptchaView_h
#define DXCaptchaView_h

#import <WebKit/WebKit.h>
#import "DXCaptchaDelegate.h"

@interface DXCaptchaView: WKWebView

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame configuration:(WKWebViewConfiguration *)configuration NS_UNAVAILABLE;

- (instancetype)initWithConfig:(NSDictionary *)config delegate:(id<DXCaptchaDelegate>)delegate frame:(CGRect)frame extraEvents:(NSArray *)extraEvents;
- (instancetype)initWithConfig:(NSDictionary *)config delegate:(id<DXCaptchaDelegate>)delegate frame:(CGRect)frame;
- (instancetype)initWithConfig:(NSDictionary *)config delegate:(id<DXCaptchaDelegate>)delegate;
- (instancetype)initWithAppId:(NSString *)appId delegate:(id<DXCaptchaDelegate>)delegate frame:(CGRect)frame;

@end

@interface DXCaptchaView () <WKScriptMessageHandler, WKNavigationDelegate>

@property uint _sdkVersion;
@property NSString* _constId;
@property NSArray* extraEvents;
@property (weak) id<DXCaptchaDelegate> delegate;
@property NSDictionary *config;
@property NSCondition *condition;
@property BOOL isGetTokenTaskFinish;


@end



@interface DXCaptchaViewV5 : DXCaptchaView

@end

#endif /* DXCaptchaView_h */
