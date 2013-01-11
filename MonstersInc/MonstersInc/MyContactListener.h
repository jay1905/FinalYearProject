//
//  MyContactListener.h
//  MonstersInc
//
//  Created by Jaime Aughney on 03/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_MyContactListener_h
#define MonstersInc_MyContactListener_h
#include "cocos2d.h"
#include "Box2D.h"
#include "Bullet.h"
#include "PhysicsSprite.h"

class MyContactListener : public b2ContactListener{
    
    void BeginContact(b2Contact* contact) {
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        PhysicsSprite *p1;
        PhysicsSprite *p2;        
        if ( bodyUserData ){
            p1 =(PhysicsSprite*)contact->GetFixtureA()->GetBody()->GetUserData();
            p2 =(PhysicsSprite*)contact->GetFixtureB()->GetBody()->GetUserData();
            std::string name1= p1->name;
            std::string name2= p2->name;
            if(name1=="bullet"&& name2=="Enemy"){
                p1->timetolive=500;
                p2->health-=20;
            }
            else if(name2=="bullet"&&name1=="Enemy"){
                p1->health-=20;
                p2->timetolive=500;
            }
            else if(name1=="player"&&name2=="Enemy"){
                p1->health-=8;
            }
            else if(name1=="Enemy"&&name2=="player"){
                p2->health-=8;
            }
            else if (name1=="bullet"){
                p1->timetolive=500;
            }
            else if (name2=="bullet"){
                p2->timetolive=500;  
            }
        }
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData ){
            p2 =(PhysicsSprite*)contact->GetFixtureB()->GetBody()->GetUserData();
            std::string name2= p2->name;
            if (name2=="bullet"){
                p2->timetolive=500;
            }
        }
    }
    void EndContact(b2Contact* contact) {
        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData ){
            //static_cast<Ball*>( bodyUserData )->endContact();
        }
        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData ){
            //static_cast<Ball*>( bodyUserData )->endContact();
        }
    }
};
#endif
