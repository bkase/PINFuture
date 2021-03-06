//
// Created by Brandon Kase on 12/19/16.
// Copyright (c) 2016 Pinterest. All rights reserved.
//

#import "PINResultFailure.h"

NS_ASSUME_NONNULL_BEGIN

@interface PINResultFailure ()
@property (nonatomic, strong) NSError *error;
@end

@implementation PINResultFailure

- (PINResultFailure <id> *)initWithError:(NSError *)error {
    if (self == [super init]) {
        self.error = error;
    }
    return self;
}

@end

NS_ASSUME_NONNULL_END
