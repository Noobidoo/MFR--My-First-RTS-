//
//  MyDocument.h
//  MFR
//
//  Created by Noobidoo on 12/17/09.
//  Copyright 2009 Novia. All rights reserved.
//


#import <Cocoa/Cocoa.h>
#import <Ogre/OgreOSXCocoaView.h>

@interface MyOgre : NSObject
{
	IBOutlet OgreView *ogreView;
	NSColor *diffuseLight;
	NSColor *specularLight;
}
@end
