//
//  Tutorial.h
//  MonstersInc
//
//  Created by Jaime Aughney on 11/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Tutorial_h
#define MonstersInc_Tutorial_h


#include "cocos2d.h"
#include "Box2D.h"
#include "Analogue.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "MyContactListener.h"
#include "Gun.h"
#include "Base.h"
#include "BaseButton.h"
#include "Tower.h"



class Tutorial: public cocos2d::CCLayer
{
    
public:
    
    Tutorial();
     static cocos2d::CCScene* scene();
    void init();
    
    void update(float t);
    void createBounds();
    void exit();
    
        
private:
    b2World* world;

    cocos2d::CCLabelTTF *label;
    cocos2d::CCLabelTTF *label2;
    cocos2d::CCLabelTTF *label3;
    cocos2d::CCLabelTTF *label4;
    cocos2d::CCLabelTTF *label5;
    cocos2d::CCLabelTTF *label6;
    cocos2d::CCLabelTTF *label7;
    cocos2d::CCLabelTTF *label8;
    cocos2d::CCLabelTTF *label9;
    cocos2d::CCLabelTTF *label10;
    cocos2d::CCLabelTTF *label11;
    cocos2d::CCLabelTTF *label12;
    cocos2d::CCLabelTTF *label13;
    cocos2d::CCLabelTTF *label14;

    
    cocos2d::CCSprite *thumb1;
    cocos2d::CCSprite *thumb2;
    
    Base *base;
    BaseButton *baseButton;
    std::vector<Tower*> towers;

    cocos2d::CCMenuItemImage *pCloseItem;
    Analogue * analog;
    Analogue * analog2;
    Player *player;
    cocos2d::CCArray *bullets;
    cocos2d::CCSpriteBatchNode *bulletSprite;
    cocos2d::CCSize s ;
    EnemyManager *eMan;
    Gun* gun;
    MyContactListener mycontact;
    int count;
    int fireCount;
    bool builed;

    
};

#endif
