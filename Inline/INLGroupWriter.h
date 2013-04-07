//
//  INLGroupWriter.h
//  Inline
//
//  Created by Ryan Davies on 07/04/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INLRunnerDelegate.h"

/** Writes out the name of each group as a runner proceeds through a hierarchy. */
@interface INLGroupWriter : NSObject <INLRunnerDelegate>

/**
 Initialize a test writer.
 @param output The output for the test writer.
 @return An initialized test writer.
 */
- (id)initWithOutput:(NSMutableString *)output;

@end
