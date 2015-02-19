//
//  PuzAPIClient.h
//  Puzzle
//
//  Created by Appiaries Corporation on 11/18/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPSessionManager.h>

@interface PuzAPIClient : AFHTTPSessionManager

/** accessToken */
@property (nonatomic, readonly) NSString *accessToken;
/** storeToken */
@property (nonatomic, readonly) NSString *storeToken;
/** トークンの有効期限 */
@property (nonatomic, readonly) NSDate *tokenExpireDate;
/** storeToken */
@property (nonatomic, readonly) NSString *userId;

/** class method for singleton */
+ (instancetype)sharedClient;

/*!
画像を保存しているファイルAPIからURLを取得
@param objectId imageFileのオブジェクトID
@return 画像URL
*/
+ (NSString *)getImageFileUrlWithObjectId:(NSString *)objectId;

- (void)saveLogInInfo:(NSDictionary *)data;

- (NSDictionary *)loadLogInInfo;

@end
