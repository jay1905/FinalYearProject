//
//  MainMenu.h
//  MonstersInc
//
//  Created by Jaime Aughney on 12/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_MainMenu_h
#define MonstersInc_MainMenu_h

#include "cocos2d.h"


class MainMenu: public cocos2d::CCLayer
{
  
public:
    
    static cocos2d::CCScene* scene();
    MainMenu();
    
    void init();
    void tutorialLevel();
    void level1();
    void level2();
    void test();
    
    
private:
    
        
    cocos2d::CCMenuItemImage *pCloseItem;
    cocos2d::CCMenuItemImage *tutorial;
    cocos2d::CCMenuItemImage *level1btn;
    cocos2d::CCMenuItemImage *level2btn;


    cocos2d::CCSprite *jaime;
    
     cocos2d::CCLabelTTF *label;
    
};

#endif
