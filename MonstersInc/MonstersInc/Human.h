//
//  Human.h
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Human_h
#define MonstersInc_Human_h


#include "cocos2d.h"
#include "Entity.h"



class Human: public Entity
{
    
public:
    
    Human(b2World* world, b2Vec2, float, b2Vec2, cocos2d::CCLayer * );
    void move( cocos2d::CCPoint point);
    void build();
    void defend();
    void update();
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
private:
    
    cocos2d::CCLayer * mainLayer;
     b2Vec2 position;
    
   
    cocos2d::CCArray* allTouchesFromSet(cocos2d::CCSet *touches);
    
    float height;
    float width;
    bool isSelected;
    b2Vec2 direction;
    cocos2d::CCPoint destination;
    
};

#endif
