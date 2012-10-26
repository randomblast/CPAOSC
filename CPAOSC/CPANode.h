//
//  CPANode.h
//  CocoaPacketAnalyzer
//
//  Copyright BitControl Networks GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CPANode : NSObject {

}

// convenience method
+ (CPANode *)nodeWithName:(NSString *)aNodename;
+ (CPANode *)nodeWithName:(NSString *)aNodename value:(id)aValue;

// For headers: The headerLength in bytes
@property uint16_t		headerLength;

// For headers: if its a child we need to know the location, absolut to the parent header.
@property uint16_t		headerLocation;

// For headers: if its a child we want to know its parent
@property (nonatomic,assign,setter=setParent:) CPANode	*parent;

// For headers: should be YES if the header and its children should not be list-indented for printing (PRINTING ONLY).
@property (nonatomic,assign) BOOL usePrintListIndention;

// For headers: used for protocols which are nested in other protocol trees (PRINTING ONLY).
@property (nonatomic,assign,setter=setIsNested:) BOOL isNested;

// The name of the node
@property (nonatomic,copy) NSString *nodeName;

// The value of the node
@property (nonatomic,copy) NSString *nodeValue;

// The children
- (void) addChild:(CPANode *)aChild;
@end
