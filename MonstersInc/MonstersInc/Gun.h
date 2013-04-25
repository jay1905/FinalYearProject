//
//  Gun.h
//  MonstersInc
//
//  Created by Jaime Aughney on 26/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Gun_h
#define MonstersInc_Gun_h

#include "cocos2d.h"

class Gun{
    
public:
    Gun(int,int,int, std::string name);
    float damage;
    int fireRate;
   
    bool locked;
    std::string name;
    int price;
private:
      
    
    
};
#endif
