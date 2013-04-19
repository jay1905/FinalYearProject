//
//  Level.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 12/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Level.h"


using namespace cocos2d;


Level::Level(float minSpawn,float maxSpawn,int enemyOne,int enemyTwo,int enemyThree,int enemyFour,int enemyFive){
    
	minSpawnTime = minSpawn;
	maxSpawnTime = maxSpawn;
 
    for (int i=0; i<5; i++) {
        enemies[i]=0;
    }
    enemies[0]=enemyOne;
    enemies[1]=enemyTwo;
    enemies[2]=enemyThree;
    enemies[3]=enemyFour;
    enemies[4]=enemyFive;
    
}
void Level::initialize(){
    
    
    
    
}