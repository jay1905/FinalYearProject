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
#include "Box2D.h"
#include <CCEditBox.h>
#include "SaveFileData.h"

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
    void update(float t);
    void newPlayer();
    void enterPlayer();
    
    
private:
      b2World* world;
        
    cocos2d::CCMenuItemImage *pCloseItem;
    cocos2d::CCMenuItemImage *tutorial;
    cocos2d::CCMenuItemImage *level1btn;
    cocos2d::CCMenuItemImage *level2btn;
    cocos2d::CCMenuItemImage *newGame;
     cocos2d::CCMenuItemImage *enter;

    cocos2d::CCSprite *jaime;
    
    cocos2d::CCLabelTTF *label;
    cocos2d::CCLabelTTF *goldlabel;
    cocos2d::CCLabelTTF *Namelabel;
    cocos2d::CCLabelTTF *goldlabel2;
    
     cocos2d::extension::CCScale9Sprite *pNormal9SpriteBg;
    cocos2d::extension::CCEditBox *m_pEditName;
    
    SaveFileData* savedData;
    
     char ttt[100];
    
};

#endif
