	//
	//  CPAPlugInsController.h
	//  CocoaPacketAnalyzer
	//
	//  Created by Jens Francke on 16.03.08.
	//  Copyright BitControl Networks GmbH. All rights reserved.
	//

#import <Cocoa/Cocoa.h>

typedef enum {
    kCPAProtocolNone        = -1,
    kCPAProtocolTCP         = 0,
    kCPAProtocolUDP         = 1,
    kCPAProtocolUDPandTCP   = 100
}kCPASourceProtocols;

#define CPAFindPredicateDisplayName			@"CPAFindPredicateDisplayName"
#define CPAFindPredicateLeftExpression	    @"CPAFindPredicateLeftExpression"
#define CPAFindPredicateAttrType			@"CPAFindPredicateAttrType"


__attribute__((visibility("default")))
@interface CPAPlugInsController : NSObject {
@private
    BOOL		    hasInited;
    NSMutableArray          *loadedPlugInsArray;
    NSMutableDictionary     *analyzersProtocolsDictionary;
    NSMutableDictionary     *analyzersKeysDictionary;
}
@property BOOL	hasInited;
@property (nonatomic,retain) NSMutableArray			*loadedPlugInsArray;
@property (nonatomic,retain) NSMutableDictionary	*analyzersProtocolsDictionary;
@property (nonatomic,retain) NSMutableDictionary	*analyzersKeysDictionary;


+ (CPAPlugInsController *)sharedPlugInsController;

- (void)cleanUp;
- (void)activatePlugIns;

/* register the plugin preference instance */
- (BOOL)registerPluginPreferencesInstance:(id)aPreferencesInstance forPlugin:(NSBundle *)thePluginBundle;

/* register the plugin analyzer class */
- (BOOL)registerAnalyzerClass:(Class)anAnalyzerClass forPlugin:(NSBundle *)thePluginBundle;

/*  register/unregister a protocol for port based analysis, possibly values for sourceProtocol are: kCPAProtocolNone, kCPAProtocolTCP, kCPAProtocolUDP, kCPAProtocolUDPandTCP */
- (BOOL)registerProtocol:(NSString *)aProtocol port:(NSNumber *)aPort sourceProtocol:(int8_t)aSourceProtocol forPlugin:(NSBundle *)thePluginBundle;
- (BOOL)unregisterProtocol:(NSString *)aProtocol port:(NSNumber *)aPort sourceProtocol:(int8_t)aSourceProtocol forPlugin:(NSBundle *)thePluginBundle;

/*  register a protocol and ethertype. This will also update the description in the preferences. */
- (BOOL)registerProtocol:(NSString *)aProtocol ethertype:(NSString *)eType forPlugin:(NSBundle *)thePluginBundle;
/*  register a protocol and linktype. This will also update the description in the preferences. */
- (BOOL)registerProtocol:(NSString *)aProtocol linktype:(NSString *)eType forPlugin:(NSBundle *)thePluginBundle;

/* register a table column for the packet view */
- (BOOL)registerTableColumn:(NSTableColumn *)aColumn keyPath:(NSString *)aKeyPath bindingOptions:(NSDictionary *)theOptions forPlugin:(NSBundle *)thePluginBundle;

/* register a predicate for the search */
- (BOOL)registerPredicateOption:(NSDictionary *)predicateOptionDictionary forPlugin:(NSBundle *)thePluginBundle;

- (Class)analyzerClassForProtocol:(NSString *)aProtocol;
- (id)preferencesForAnalyzer:(id)anAnalyzer ;
- (Class)analyzerClassForKey:(NSString *)aKey;
@end
