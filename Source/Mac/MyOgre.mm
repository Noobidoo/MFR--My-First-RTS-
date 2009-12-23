//
//  MyDocument.m
//  MFR
//
//  Created by Noobidoo on 12/17/09.
//  Copyright 2009 Novia. All rights reserved.
//

#import "MyOgre.h"
#include <Ogre/Ogre.h>

using namespace	Ogre;

@implementation MyOgre

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
	std::string mResourcePath = [[[NSBundle mainBundle] resourcePath] UTF8String];
	
	// Create a new root object with the correct paths
	Root *mRoot = new Root(mResourcePath + "/plugins.cfg", mResourcePath + "/ogre.cfg", mResourcePath + "/Ogre.log");
	
	// use pbuffers not frame buffers because of driver problems ?? true?
	// mRoot->getRenderSystem()->setConfigOption("RTT Preferred Mode", "PBuffer");
	
	// Show a configure box and exit if user clicked cancel
	if(!mRoot->showConfigDialog())
		return;
	
	// Initialise
	[self locateResources];
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	RenderWindow* mWindow = mRoot->initialise(true,"Ogre 1");
	SceneManager *mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "my scene manager");
	
	// Create the camera, node & attach camera
	Camera *mCamera = mSceneMgr->createCamera("PlayerCam");
	SceneNode* camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	camNode->attachObject(mCamera);
	mWindow->addViewport(mCamera);
	camNode->setPosition(Vector3(100,100,100));
	mCamera->lookAt(Vector3(0,0,0));
	mSceneMgr->setAmbientLight(ColourValue(20,0,80));
	
	SceneNode* OgreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Entity* head = mSceneMgr->createEntity("Head", "ogrehead.mesh");
	OgreNode->attachObject(head);
	mRoot->startRendering();
}

-(void) locateResources
{
	// load resource paths from config file
	Ogre::ConfigFile cf;
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
	std::string macBundlePath = [[[NSBundle mainBundle]resourcePath]UTF8String];
	cf.load(macBundlePath + "/resources.cfg");
#else
	cf.load("resources.cfg");
#endif
	
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
	Ogre::String sec, type, arch;
	
	// go through all specified resource groups
	while (seci.hasMoreElements())
	{
		sec = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		
		// go through all resource paths
		for (i = settings->begin(); i != settings->end(); i++)
		{
			type = i->first;
			arch = i->second;
			
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
			// OS X does not set the working directory relative to the app,
			// In order to make things portable on OS X we need to provide
			// the loading with it's own bundle path location
			if (!Ogre::StringUtil::startsWith(arch, "/", false)) // only adjust relative dirs
				arch = Ogre::String(macBundlePath + "/" + arch);
#endif
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
		}
	}
}
@end
