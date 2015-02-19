//
//  PuzPlayers.m
//  Puzzle
//
//  Created by Appiaries Corporation on 11/17/14.
//  Copyright (c) 2014 Appiaries Corporation. All rights reserved.
//

#import "PuzPlayers.h"

@implementation PuzPlayers

- (id)initWithDict:(NSDictionary *)playerDict
{
    if (self = [super init]) {
        _id        = playerDict[@"_id"];
        _loginId   = playerDict[@"login_id"];
        _password  = playerDict[@"password"];
        _email     = playerDict[@"email"];
        _autoLogin = playerDict[@"auto_login"];
        _nickname  = playerDict[@"nickname"];
        _cts       = playerDict[@"_cts"];
        _uts       = playerDict[@"_uts"];
        _cby       = playerDict[@"_cby"];
        _uby       = playerDict[@"_uby"];
    }
    return self;
}

@end
