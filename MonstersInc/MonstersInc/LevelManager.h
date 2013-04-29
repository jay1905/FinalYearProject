//
//  LevelManager.h
//  MonstersInc
//
//  Created by Jaime Aughney on 11/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_LevelManager_h
#define MonstersInc_LevelManager_h

#include "cocos2d.h"
#include "Box2D.h"
#include "Base.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Analogue.h"
#include "Level.h"
#include "MainMenu.h"
#include "UpgradeScreen.h"
#include "TowerManager.h"
#include "BaseButton.h"
#include "MyContactListener.h"
#include "BulletManager.h"

class LevelManager : public cocos2d::CCLayer
{
    
public:
    LevelManager();
    void initialize();
    
    static cocos2d::CCScene* scene();
    void initPhysics();
    
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual  void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void update(float dt);
    
    void exitMainMenu();
    
    
    
private:
    int currentLevel;
    b2World* world;
    cocos2d::CCSprite *background;
    Base * castle;
    Player* player;
    EnemyManager *eman;
    TowerManager * towerMan;
     BaseButton *baseButton;
   
    Analogue * analog2;    
       UpgradeScreen *upgradeScn;
     MyContactListener mycontact;
     int firecount;
    BulletManager * bulletMan;
    std::vector<Level*> levels;
    
    
   
};

#endif
