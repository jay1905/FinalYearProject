//
//  JoyStick.h
//  MonstersInc
//
//  Created by Jaime Aughney on 31/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_JoyStick_h
#define MonstersInc_JoyStick_h

#include "cocos2d.h"
//#include "Box2D.h"
//#include "PhysicsSprite.h"

class JoyStick:public cocos2d::CCLayer
{
public:
    
    
    JoyStick(cocos2d::CCLayer* l);
    cocos2d::CCSprite * stick;
    void moveMe();
    
    
    
};

#endif
