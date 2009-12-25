/*
 *  FrameHandle.h
 *  MFR
 *
 *  Created by Noobidoo on 12/24/09.
 *  Copyright 2009 Novia. All rights reserved.
 *
 */
#import <ogre/ogre.h>
class FrameHandle : public Ogre::FrameListener{
public:
	FrameHandle();
	~FrameHandle();
	bool	frameStarted(const Ogre::FrameEvent &evt);
};

