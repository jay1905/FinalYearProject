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

Gun::Gun(){
    
    damage=5;
    
    fireRate=13;
    
    reloadSpeed=0.5;
    ammoCapacity=30;
    currentAmmo=30;
    
}