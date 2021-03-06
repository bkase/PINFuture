//
//  PINTask.h
//  Pods
//
//  Created by Chris Danford on 12/12/16.
//  Copyright (c) 2016 Pinterest. All rights reserved.
//

#import "PINDefines.h"
#import "PINExecutor.h"
#import "PINPair.h"
#import "PINCancelToken.h"

NS_ASSUME_NONNULL_BEGIN

@interface PINTask<ObjectType> : NSObject

#pragma mark - constructors
/**
 * Computation is a function that accepts two callbacks. It should call one of them after completion with the final result (success or failure).
 * Also a computation may return a CancellationBlock with cancellation logic or it can return undefined if there is no cancellation logic
 */
+ (PINTask<ObjectType> *)create:(PINCancelToken * _Nullable (^)(void(^resolve)(ObjectType), void(^reject)(NSError *)))block PIN_WARN_UNUSED_RESULT;
+ (PINTask<ObjectType> *)withValue:(ObjectType)value PIN_WARN_UNUSED_RESULT;
+ (PINTask<ObjectType> *)withError:(NSError *)error PIN_WARN_UNUSED_RESULT;

- (PINTask<ObjectType> *)executor:(id<PINExecutor>)executor doSuccess:(nullable void(^)(ObjectType value))success failure:(nullable void(^)(NSError *error))failure PIN_WARN_UNUSED_RESULT;
- (PINCancelToken *)run;

@end

NS_ASSUME_NONNULL_END

// Import everything for caller convenience.
#import "PINTask+All.h"
#import "PINTask+Cache.h"
#import "PINTask+Do.h"
#import "PINTask+DoAsync.h"
#import "PINTaskMap.h"
#import "PINTaskMap+Map.h"
#import "PINTaskMap+FlatMap.h"
#import "PINTaskMap+MapToValue.h"
