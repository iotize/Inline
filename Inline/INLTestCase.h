//
//  INLTestCase.h
//  Inline
//
//  Created by Ryan Davies on 18/01/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import <SenTestingKit/SenTestingKit.h>
@class INLStack, INLCompiler;

/** Extends SenTestCase to allow developers to set a builder and compiler for tests. This class is abstract and is intended to be subclassed. Class methods performed on a subclass apply only to that subclass, and not to the superclass or siblings. */
@interface INLTestCase : SenTestCase

/** Returns the builder assigned to the current class. */
+ (INLStack *)builder;

/** Assigns a builder to the current class. 
 @param builder The builder to assign. */
+ (void)setBuilder:(INLStack *)builder;

/** Returns the compiler assigned to the current class. */
+ (INLCompiler *)compiler;

/** Assigns a compiler to the current class.
 @param compiler The compiler to assign. */
+ (void)setCompiler:(INLCompiler *)compiler;

/** @return Returns an immutable list of the invocations added, generated by handing the builder's tests to the compiler. */
+ (NSArray *)testInvocations;

/** @return The list of superclasses for any subclass of SenTestCase, with the items in blacklistedClasses removed. Blacklisted classes do not show up in test results. */
+ (NSArray *)senAllSuperclasses;

/** @return A list of classes which should not appear in the test results. */
+ (NSArray *)blacklistedClasses;

/** @return The description of the current test. */
- (NSString *)name;

@end
