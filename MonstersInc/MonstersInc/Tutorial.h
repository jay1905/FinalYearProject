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


class Tutorial: public cocos2d::CCLayer
{
    
public:
    
    
    void init();
    
    
    
    
private:
    
    cocos2d::CCLabelTTF *label ;//= CCLabelTTF::create("Tap screen", "Marker Felt", 32);
    //    addChild(label, 0);
    //    label->setColor(ccc3(0,0,255));
    //    label->setPosition(ccp( s.width/2, s.height-50));

    
    
    
};

#endif
