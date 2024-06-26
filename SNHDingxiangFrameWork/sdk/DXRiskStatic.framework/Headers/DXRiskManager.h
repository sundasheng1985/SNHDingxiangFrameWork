//
//  DXRiskManager.h
//  STEEForiOS
//
//  Created by echonn on 04/07/2017.
//  Copyright © 2017 echonn. All rights reserved.
//

// 不要修改
#define DXRISK_SDK_VERSION "v7_3_10r_2ee4e543"

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>


// 风控组件：DXRiskManager类
@interface DXRiskManager : NSObject

// 字符串常量
extern NSString* const DXRiskManagerKeyUserId;
extern NSString* const DXRiskManagerKeyEmail;
extern NSString* const DXRiskManagerKeyPhone;
extern NSString* const DXRiskManagerKeyUserExtend1;
extern NSString* const DXRiskManagerKeyUserExtend2;
extern NSString* const DXRiskManagerKeyURL;
extern NSString* const DXRiskManagerKeyBackup;
extern NSString* const DXRiskManagerKeyALGORITHM;
extern NSString* const DXRiskManagerKeyDegradeNotify;
extern NSString* const DXRiskManagerKeyCountry;
extern NSString* const DXRiskManagerKeyBackupAppId;

extern NSString* const DXRiskManagerKeyDelayMsTime;
/* 态势感知 URL*/
extern NSString* const DXRiskManagerSituationUrl;
// NoticeDegrade参数
/* The NoticeDegrade Value. This value only be used pair with key:DXRiskManagerKeyDegradeNotify to notify token degrade. */
extern NSString* const DXRiskManagerKeyDegradeNotifyEnable;
// Backup参数
/* The Backup Value. This value only be used pair with key:DXRiskManagerKeyBackup to set data backup. */
extern NSString* const DXRiskManagerKeyBackupEnable;
// Country参数
/* The Country Value. This value only be used pair with key:DXRiskManagerKeyCountry to set country. */
extern NSString* const DXRiskManagerCountryChina;
/* The Country Value. This value only be used pair with key:DXRiskManagerKeyCountry to set country. */
extern NSString* const DXRiskManagerCountryIndonesia;

/**
 采集端的设备指纹信息，上传至风控后台，再由风控后台返回token。
 该API为耗时操作，因此必须在非主线程上调用。
 @param extendsParams 业务方用户唯一标识，用户名，用户ID，Email等等，常用Key值可参考DXRiskManagerKeyUserId, DXRiskManagerKeyEmail等等
 @param appId appId
 @param sid 业务数据 hex
 @return token
 */
+ (NSString *)getToken:(NSString*) appId extendsParams:(NSDictionary *)extendsParams WithSid:(NSString *)sid;
/** 
 DXRiskManager -- 初始化方法
 */
+ (BOOL)setup;

/**
 态势感知场景上报
 @param scene 业务场景
 */
+ (void)beginScene:(NSString *)scene;
/**
 当前场景结束
*/
+ (void)endScene;
/**
 是否降级
 @param token 获取到的设备 token
*/
+ (BOOL)isDetoken:(NSString *)token;
/**
 用户上传的态势感知相关配置
 @param Params 用户传入的配置
*/
+ (void)addParams:(NSDictionary *)Params;
/**
 态势感知主动上报接口
*/
+ (void)updateSituation;
/**
 上报第三方SDK数据
  @param json 第三方数据json字符串
 */
+ (void)updateThirdPartSDKData:(NSString *)json;
@end
