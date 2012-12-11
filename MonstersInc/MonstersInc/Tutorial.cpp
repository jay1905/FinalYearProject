//
//  Tutorial.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 11/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Tutorial.h"
#include "SimpleAudioEngine.h"


using namespace cocos2d;
using namespace CocosDenshion;

void Tutorial::init(){
    
    
        label = CCLabelTTF::create("touch here to move", "Marker Felt", 32);
        addChild(label, 0);
        label->setColor(ccc3(0,0,255));
        label->setPosition(ccp( 150, 100));

    
    
}