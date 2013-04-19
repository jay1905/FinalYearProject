//
//  AxeBaby.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 15/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>


#include "AxeBaby.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

AxeBaby::AxeBaby( b2World *world,b2Vec2 pos,float spd)
:Enemy()
{
    size = b2Vec2(11,30);
    cocos2d::CCAnimation * anim = CCAnimation::animation();
    anim->addSpriteFrameWithFileName("axeBaby1.png");
    anim->addSpriteFrameWithFileName("axeBaby2.png");
    anim->addSpriteFrameWithFileName("axeBaby3.png");
    anim->addSpriteFrameWithFileName("axeBaby4.png");
    anim->setDelayPerUnit(.3f);
    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);
    CCAction *jumpAct = CCRepeatForever::create(theAnim);
    cocos2d::CCSpriteBatchNode *pSprite= cocos2d::CCSpriteBatchNode::create("axeBaby1.png");
    
    this->initWithFile("axeBaby1.png", CCRectMake(0, 0, size.x, size.y));
    this->initialize(pSprite, world, pos, spd, size, "Enemy");
    this->CCSprite::m_pActionManager->addAction(jumpAct, this, false);
 
    
}
