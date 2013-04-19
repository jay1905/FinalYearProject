//
//  Metroid.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 15/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Metroid.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Metroid::Metroid( b2World *world,b2Vec2 pos,float spd)
:Enemy()
{
    size= b2Vec2(26,43);

    cocos2d::CCAnimation * anim = CCAnimation::animation();
    anim->addSpriteFrameWithFileName("metroid1.png");
    anim->addSpriteFrameWithFileName("metroid2.png");
    anim->addSpriteFrameWithFileName("metroid3.png");
    anim->addSpriteFrameWithFileName("metroid4.png");
    anim->addSpriteFrameWithFileName("metroid5.png");
    anim->addSpriteFrameWithFileName("metroid6.png"); 
    anim->addSpriteFrameWithFileName("metroid7.png");
    anim->addSpriteFrameWithFileName("metroid8.png");
    anim->addSpriteFrameWithFileName("metroid9.png");
    anim->addSpriteFrameWithFileName("metroid10.png");
    
    
    anim->setDelayPerUnit(.1f);
    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);
    CCAction *jumpAct = CCRepeatForever::create(theAnim);
    cocos2d::CCSpriteBatchNode *pSprite= cocos2d::CCSpriteBatchNode::create("metroidStand.png");
    
    this->initWithFile("metroidStand.png", CCRectMake(0, 0, size.x, size.y));
    this->initialize(pSprite, world, pos, spd, size, "Enemy");
    this->CCSprite::m_pActionManager->addAction(jumpAct, this, false);
    
    
}
