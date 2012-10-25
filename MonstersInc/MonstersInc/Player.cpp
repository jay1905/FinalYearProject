//
//  Player.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MonstersInc__. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Player::Player(cocos2d::CCLayer* layer){
    
    lay = layer;
    CCMenuItemImage *icecream = CCMenuItemImage::create("icecream.png","icecream2.png",this,  menu_selector(Player::drawStuf));
    icecream->setPosition( ccp( 400, 100) );
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(icecream, NULL);
    pMenu->setPosition( ccp(400,100));
    layer->addChild(pMenu, 1);
    //pMenu->release();
    
}
void Player::update(){
    
    

}
void Player::drawStuf(){
    
    
    
//    pSprite = CCSprite::create("HelloWorld.png");
//    
//    // position the sprite on the center of the screen
//    pSprite->setPosition( ccp(300,400) );
//    
//    // add the sprite as a child to this layer
//    lay->addChild(pSprite, 0);

   
    //this->getBody()->setPosition(ccp(400, 600));
   // this->m_pBody->SetLinearVelocity(b2Vec2(0.0f, 5.0f));
    //this->m_pBody->ApplyAngularImpulse(90.0f);
    //this->m_pBody->ApplyTorque(30.0f);
    //this->m_pBody->ApplyForce(b2Vec2(0, 10), b2Vec2(0, 20));
    this->m_pBody->ApplyForceToCenter(b2Vec2(0, 50000));
    this->m_pBody->SetBullet(true);
    
}