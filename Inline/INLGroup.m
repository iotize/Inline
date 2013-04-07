//
//  INLGroup.m
//  Inline
//
//  Created by Ryan Davies on 28/01/2013.
//  Copyright (c) 2013 Ryan Davies. All rights reserved.
//

#import "INLGroup.h"
#import "INLVisitor.h"

@interface INLGroup ()
@property (copy, nonatomic) NSString *name;
@property (strong, nonatomic) CBDSortedArray *nodes;
@property (copy, nonatomic) NSNumber *weight;
@end

@implementation INLGroup

- (id)initWithName:(NSString *)name nodes:(CBDSortedArray *)nodes weight:(NSNumber *)weight
{
    if (self = [super init]) {
        [self setName:name];
        [self setNodes:nodes];
        [self setWeight:weight];
    }
    return self;
}

- (void)acceptVisitor:(id<INLVisitor>)visitor
{
    [visitor enterGroup:self];
    [[self nodes] enumerateObjectsUsingBlock:^(id<INLNode> node, NSUInteger idx, BOOL *stop) {
        [node acceptVisitor:visitor];
    }];
    [visitor leaveGroup:self];
}

@end
