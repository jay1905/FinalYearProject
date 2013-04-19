//
//  Level.h
//  MonstersInc
//
//  Created by Jaime Aughney on 12/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#ifndef MonstersInc_Level_h
#define MonstersInc_Level_h

#include "cocos2d.h"


class Level
{
    
public:
    Level(float ,float ,int,int,int ,int,int);
    void initialize();
    
    int enemies[5];
    float minSpawnTime;
    float maxSpawnTime;
    
    
private:
       
   
    
};

#endif
