//
//  TowerManager.h
//  MonstersInc
//
//  Created by Jaime Aughney on 24/04/2013.
//
//

#ifndef MonstersInc_TowerManager_h
#define MonstersInc_TowerManager_h

#include "cocos2d.h"
#include "TileSquare.h"
#include "Tower.h"
#include "Box2D.h"

using namespace cocos2d;

class TowerManager{
    
public:
    
    TowerManager();
    void createTower(b2Vec2 ,cocos2d::CCLayer*,b2World* world);
    void update();
    
    
private:
    int height;
    int width;
    
    std::vector<TileSquare * > tiles;
    
    std::vector<Tower*> towers;
    
};

#endif
