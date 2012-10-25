//
//  Analogue.h
//  MonstersInc
//
//  Created by Jaime Aughney on 25/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Analogue_h
#define MonstersInc_Analogue_h

#include "cocos2d.h"

class Analogue
{
public:
    Analogue(cocos2d::CCLayer *layer);
    
    void update();
   private:
    cocos2d::CCSprite* solidAnalogMove;
    cocos2d::CCSprite* solidAnalogShoot;
};
#endif
