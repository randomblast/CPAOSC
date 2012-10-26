//
//  OSCPlugin.m
//  CPAOSC
//
//  Created by Josh Channings on 26/10/2012.
//  Copyright (c) 2012 Josh Channings. All rights reserved.
//

#import "OSCPlugin.h"

@implementation OSCPlugin

#pragma mark <CPAPluginPrincipalClassProtocol>

- (id) initWithPlugInsController:(CPAPlugInsController*)plugInsController
{
    self = [super init];
    if(!self) return self;

    controller = plugInsController;

    return self;
}

+ (NSString *) pluginTitle
{
    return @"OSC";
}

+ (NSString *) pluginDescription
{
    return @"OpenSoundControl 1.0 Packet Analyzer";
}

+ (NSString *) pluginVersion
{
    return [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
}

+ (NSString *) pluginAuthor
{
    return @"Josh Channings";
}

@end
