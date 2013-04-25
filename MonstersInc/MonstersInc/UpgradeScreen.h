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
#include "Gun.h"


class UpgradeScreen :public cocos2d::CCLayer{
    
public:
    UpgradeScreen();
    void hide();
    void show();
    void exit();
    
    bool StartLevel;
    std::vector<Gun*> guns;
    int GunEquipNum;
    
    virtual  void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);


private:
    
    cocos2d::CCSprite *background;
    cocos2d::CCMenuItemImage *play;
    cocos2d::CCMenuItemImage *quit;
    std::vector<cocos2d::CCSprite*> gunBars;
    std::vector<cocos2d::CCPoint> gunbarPositions;
    
    
    cocos2d::CCSprite *equipedGun;
    std::vector<cocos2d::CCSprite*> locked;
    std::vector<cocos2d::CCPoint> lockedUnlockedPositions;
    cocos2d::CCLabelTTF *name;
    cocos2d::CCLabelTTF *damage;
    cocos2d::CCLabelTTF *firerate;
    cocos2d::CCLabelTTF *cost;
    
    cocos2d::CCLabelTTF *name2;
    cocos2d::CCLabelTTF *damage2;
    cocos2d::CCLabelTTF *firerate2;
    cocos2d::CCLabelTTF *cost2;

    
};

#endif
