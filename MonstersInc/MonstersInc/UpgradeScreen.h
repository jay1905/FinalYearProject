//
//  UpgradeScreen.h
//  MonstersInc
//
//  Created by Jaime Aughney on 28/02/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_UpgradeScreen_h
#define MonstersInc_UpgradeScreen_h

#include "cocos2d.h"



class UpgradeScreen :public cocos2d::CCLayer{
    
public:
    UpgradeScreen();
    static cocos2d::CCScene* scene();

    
    
private:
    
     cocos2d::CCSprite *background;
    cocos2d::CCSprite *gunwheel;
    std::vector<cocos2d::CCPoint*> handGunSelect;
    
    //cocos2d::CCPointArray test;
};

#endif
