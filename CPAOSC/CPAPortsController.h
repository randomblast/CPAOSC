//
//  CPAPortsController.h
//  CocoaPacketAnalyzer
//
//  Copyright BitControl Networks GmbH. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CPAPortsController : NSObject {

}

+ (CPAPortsController *) sharedPortsController;

- (void) addAnalyzerProtocol:(NSString *)aProtocol port:(uint16_t)aPort sourceProtocol:(int8_t)aSourceProtocol;
- (void) removeAnalyzerProtocolForPort:(uint16_t)aPort sourceProtocol:(int8_t)aSourceProtocol;

- (NSString *) analyzerProtocolForPort:(uint16_t)aPort sourceProtocol:(int8_t)aSourceProtocol;
- (NSString *) analyzerTCPProtocolForPort:(uint16_t)aPort;
- (NSString *) analyzerUDPProtocolForPort:(uint16_t)aPort;

@end
