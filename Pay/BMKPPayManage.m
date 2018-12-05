//
//  BMKPPayManage
//  BMKP
//
//  Created by dust.zhang on 18/11/28.
//  Copyright (c) 2018年 BMKP. All rights reserved.
//

#import "BMKPPayManage.h"

@implementation BMKPPayManage

static id _instance;
+(instancetype)sharedApi
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[BMKPPayManage alloc] init];
    });
    return _instance;
}

#pragma mark -- 支付宝支付
- (void) BMKPZhifubaoPay:(NSString *) orderString
                    tag:(NSString *) backZfbTag
                success:(void (^)(PayCode code)) successBlock
                failure:(void (^)(PayCode code)) failBlock
{
    NSLog(@"zhifubao pay string === %@", orderString );
    
    [[AlipaySDK defaultService] payOrder:orderString fromScheme:backZfbTag callback:^(NSDictionary *resultDic)
    {
        
        if (![[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"alipay:"]])
        {
            NSInteger resultCode = [resultDic[@"resultStatus"] integerValue];
            switch (resultCode)
            {
                case 9000: //支付成功
                    successBlock(ALIPAYSUCESS);
                    break;
                case 6001: //支付取消
                    failBlock(ALIPAYCANCEL);
                    break;
                default: //支付失败
                    failBlock(ALIPAYERROR);
                break;
            }
        }
    }];
}

#pragma mark -- 微信支付
- (void) BMKPWeixinPay:(WeinxinPayModel *) weixinModel
               success:(void (^)(PayCode code)) successBlock
               failure:(void (^)(PayCode code)) failBlock
{
    //判断是否安装微信
    if(![WXApi isWXAppInstalled])
    {
        failBlock(WXERROR_NOTINSTALL);
        return ;
    }
    //    判断当前微信的版本是否支持OpenApi
    if (![WXApi isWXAppSupportApi])
    {
        failBlock(WXERROR_UNSUPPORT);
        return ;
    }

    PayReq *request = [[PayReq alloc] init];
    request.partnerId =weixinModel.partnerid;
    request.prepayId=weixinModel.prepayid;
    request.package = weixinModel.package;
    request.nonceStr=weixinModel.noncestr;
    request.timeStamp=[weixinModel.timestamp intValue];
    request.sign= weixinModel.sign;
    [WXApi sendReq:request];
    
    NSLog(@"wei xin pay string === %@",[weixinModel  toJSONString]);
    
}



@end
