//
//  Image.h
//  Puzzle
//
//  Created by Appiaries Corporation on 2015/05/29.
//  Copyright (c) 2015 Appiaries Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Image : ABFile <ABManagedProtocol>

#pragma mark - Initialization
+ (id)image;

@end