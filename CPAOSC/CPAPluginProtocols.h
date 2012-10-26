/*
 *  CPAPluginProtocols.h
 *  CocoaPacketAnalyzer
 *
 *
 *  Formal Protocol Interface Version 1.00
 *
 *  Copyright BitControl Networks GmbH. All rights reserved.
 *
 */

#import "CPANode.h"
#import "CPAPlugInsController.h"

/*  Notifications: 
 *  if the plugin defaults changed you can inform any active document and refresh the views or clear analyzing caches to reprocess packets on next view.
 */
#define kReloadPacketsView		@"CPAReloadPacketsViewDataNotification"	// Reload the packet view (does not reprocess packets)
#define kReloadDetailsView		@"CPAReloadDetailsViewDataNotification"	// Reload the detail view (reprocess the values)
#define kClearAnalyzingCaches	@"CPAClearAnalyzingCachesNotification"	// Clear the analyzing cache in all packets to enable reprocessing

/*
 *  Plugin Principal Class
 */
@protocol CPAPluginPrincipalClassProtocol
@required
- (id) initWithPlugInsController:(CPAPlugInsController*)plugInsController;
+ (NSString *) pluginTitle; 
@optional
+ (NSString *) pluginDescription; 
+ (NSString *) pluginVersion;
+ (NSString *) pluginAuthor;
@end



/*
 *  Analyzer Model Class
 */
@protocol CPAPluginAnalyzerProtocol
@required
- (id) initWithBytes:(const void *)bytes length:(uint16_t)length previousAnalyzer:(id)prevAnalyzer;
- (uint16_t) protocolSize;
- (NSArray *) protocolNodes;
- (NSString *) nextProtocol;
- (NSString *) protocolName;
- (NSString *) protocolInfo;
- (BOOL) hasPayload;
@end


/*  
 *  Plugin Preferences Controller Class
 */
@protocol CPAPluginPreferencesProtocol
@optional
- (NSWindow*) preferencesSheet;
- (BOOL) usesColor;
- (NSColor*) protocolColor;
@end
