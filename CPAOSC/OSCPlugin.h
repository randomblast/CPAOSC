//
//  OSCPlugin.h
//  CPAOSC
//
//  Created by Josh Channings on 26/10/2012.
//  Copyright (c) 2012 Josh Channings. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface OSCPlugin : NSObject <CPAPluginPrincipalClassProtocol>
{
    CPAPlugInsController *controller;
}

@end
