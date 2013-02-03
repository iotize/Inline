//
//  INLInvocation.h
//  Inline
//
//  Created by Ryan Davies on 18/01/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import <Foundation/Foundation.h>
@class INLTest;

/** A subclass of NSInvocation which calls [INLTest execute] on test rather than invoking a selector, necessary due to the fact that SenTestCase reassigns an invocation's target. */
@interface INLInvocation : NSInvocation

/** Creates an INLInvocation instance with the given test.
 @param test The test to assign to the INLInvocation instance.
 @return A new instance of INLInvocation. */
+ (instancetype)invocationWithTest:(INLTest *)test;

/** Calls [INLTest execute] on test. */
- (void)invoke;

/** The test assigned to the invocation, which will be executed upon invoke. */
@property (strong, nonatomic) INLTest *test;

@end