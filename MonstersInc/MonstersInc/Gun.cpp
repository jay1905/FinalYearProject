//
//  Gun.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 26/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Gun.h"



using namespace cocos2d;

Gun::Gun(int d,int fr,int cost, std::string n){
    
    damage=d;
    fireRate=fr;
    name=n;
    locked=true;
    price=cost;
}