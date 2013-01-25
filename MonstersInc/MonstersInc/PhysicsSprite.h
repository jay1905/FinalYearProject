//
//  PhysicsSprite.h
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_PhysicsSprite_h
#define MonstersInc_PhysicsSprite_h

#include "cocos2d.h"
#include "Box2D.h"



class PhysicsSprite : public cocos2d::CCSprite
{
public:
    PhysicsSprite();
    void setPhysicsBody(b2Body * body);
    virtual bool isDirty(void);
    virtual cocos2d::CCAffineTransform nodeToParentTransform(void);
    b2Body getBody();
    b2Body* m_pBody;    // strong ref
    std::string name;
    float timetolive;
    int health;
    bool dieing;
    void die();

private:
   };

#endif
