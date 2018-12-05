//
//  BMKPPayManage
//  BMKP
//
//  Created by dust.zhang on 18/11/28.
//  Copyright (c) 2018年 BMKP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AlipaySDK/AlipaySDK.h>
#import "BMKPPayModel.h"
#import "WXApi.h"
#import "JSONKit.h"

typedef NS_ENUM(NSInteger, PayCode)
{
    //微信
    WXSUCESS = 1001,                /**< 成功 */
    WXERROR = 1002,                 /**< 失败 */
    WXSCANCEL = 1003,               /**< 取消 */
    WXERROR_NOTINSTALL = 1004,      /**< 未安装微信 */
    WXERROR_UNSUPPORT = 1005,       /**< 微信不支持 */
    WXERROR_PARAM = 1006,           /**< 支付参数解析错误 */
    //支付宝
    ALIPAYSUCESS = 1101,            /**< 支付宝支付成功 */
    ALIPAYERROR = 1102,             /**< 支付宝支付错误 */
    ALIPAYCANCEL = 1103,            /**< 支付宝支付取消 */
};

@interface BMKPPayManage : NSObject

/* 支付宝支付
 orderString : 支付信息字符串
 backZfbTag  : 支付成功后的返回标识符 URL type 里的设置
 success     : 支付成功后返回code
 failure     : 支付失败后返回code
 */
- (void) BMKPZhifubaoPay:(NSString *) orderString
                     tag:(NSString *) backZfbTag
                 success:(void (^)(PayCode code)) successBlock
                 failure:(void (^)(PayCode code)) failBlock;

/*
 微信支付
 weixinModel : 微信支付参数model
 success     : 支付成功后返回code
 failure     : 支付失败后返回code
 */
- (void) BMKPWeixinPay:(WeinxinPayModel *) weixinModel
              success:(void (^)(PayCode code)) successBlock
              failure:(void (^)(PayCode code)) failBlock ;



@end
