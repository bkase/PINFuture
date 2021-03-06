//
//  NSURLSession+PINFuture.h
//  Pods
//
//  Created by Chris Danford on 12/8/16.
//  Copyright (c) 2016 Pinterest. All rights reserved.
//

#import <Foundation/NSURLSession.h>

#import "PINNSURLSessionDataTaskResult.h"
#import "PINFuture.h"
#import "PINPair.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSURLSession (PINFuture)

/**
 * Returns a Future that never rejects.  The value type has an error field.
 * that is set in non-exceptional cases such as 4xx response codes.
 */
- (PINPair<NSURLSessionDataTask *, PINFuture<PINNSURLSessionDataTaskResult *> *> *)pinfuture_dataTaskWithRequest:(NSURLRequest *)request;

@end

NS_ASSUME_NONNULL_END
