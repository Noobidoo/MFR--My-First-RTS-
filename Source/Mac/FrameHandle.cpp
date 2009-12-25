/*
 *  FrameHandle.cpp
 *  MFR
 *
 *  Created by Noobidoo on 12/24/09.
 *  Copyright 2009 Novia. All rights reserved.
 *
 */

#include "FrameHandle.h"

FrameHandle::FrameHandle(void){}
FrameHandle::~FrameHandle(void){}
bool FrameHandle::frameStarted(const Ogre::FrameEvent& evt)
{
	return true;
}