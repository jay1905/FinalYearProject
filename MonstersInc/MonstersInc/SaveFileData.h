//
//  SaveFileData.h
//  MonstersInc
//
//  Created by Jaime Aughney on 12/03/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_SaveFileData_h
#define MonstersInc_SaveFileData_h

#include "cocos2d.h"

class SaveFileData{
    
public:
    SaveFileData();
    
    
    std::string name;
    int gold;
    int currentLevel;
    void newPlayer(std::string);
    void updateGold(int );
    void updateLevel(int);
private:
    
    
    
    
};
#endif
