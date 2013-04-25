//
//  SaveFileData.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 12/03/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SaveFileData.h"

#include <CCUserDefault.h>



using namespace cocos2d;


SaveFileData::SaveFileData(){
    
    
    gold=CCUserDefault::sharedUserDefault()->getIntegerForKey("gold");
    name=CCUserDefault::sharedUserDefault()->getStringForKey("name");
    currentLevel=CCUserDefault::sharedUserDefault()->getIntegerForKey("level");
    
    
}
void SaveFileData::newPlayer(std::string n){
    
    name=n;
    CCUserDefault::sharedUserDefault()->setStringForKey("name", n);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("gold", 200);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("level",0);
    CCUserDefault::sharedUserDefault()->flush();
    gold=200;
    
    
}
void SaveFileData::updateGold(int newgold){
    
     gold=newgold;
     CCUserDefault::sharedUserDefault()->setIntegerForKey("gold", gold);
     CCUserDefault::sharedUserDefault()->flush();
    
}
void SaveFileData::updateLevel(int current){
    
    currentLevel=current;
    CCUserDefault::sharedUserDefault()->setIntegerForKey("level", currentLevel);
    CCUserDefault::sharedUserDefault()->flush();

}