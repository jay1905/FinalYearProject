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
    cocos2d::CCMenuItemImage *pCloseItem;
    Analogue * analog;
    Analogue * analog2;
    Player *player;
    cocos2d::CCArray *bullets;
    cocos2d::CCSpriteBatchNode *bulletSprite;
    cocos2d::CCSize s ;


    
};

#endif
