//
//  PayModel.h
//  movikr
//
//  Created by Mapollo27 on 15/9/14.
//  Copyright (c) 2015年 movikr. All rights reserved.
//

#import "JSONModel.h"


//支付宝回调
@interface ZhifubaoModel : JSONModel
@property (nonatomic ,strong) NSString<Optional> *memo;
@property (nonatomic ,strong) NSString<Optional> *result;
@property (nonatomic ,strong) NSString<Optional> *resultStatus;
@end

//微信支付
@interface WeinxinPayModel : JSONModel
@property (nonatomic ,strong) NSString<Optional> *appid;
@property (nonatomic ,strong) NSString<Optional> *noncestr;
@property (nonatomic ,strong) NSString<Optional> *package;
@property (nonatomic ,strong) NSString<Optional> *partnerid;
@property (nonatomic ,strong) NSString<Optional> *prepayid;
@property (nonatomic ,strong) NSString<Optional> *sign;
@property (nonatomic ,strong) NSNumber<Optional> *timestamp;
@end
