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
       
        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData ){
            //static_cast<Ball*>( bodyUserData )->startContact();
            char* str=(char*)contact->GetFixtureA()->GetBody()->GetUserData();
            if(!strcmp(str,"Bullet")){
                int i=0;
            }
        }
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData ){

            PhysicsSprite *p =(PhysicsSprite*)contact->GetFixtureB()->GetBody()->GetUserData();
            
            std::string hell= p->name;
            cocos2d::CCString st=p->name;
            if(hell=="bullet"){
               p->timetolive=500;
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
