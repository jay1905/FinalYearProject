//
//  TowerManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 24/04/2013.
//
//

#include "TowerManager.h"


TowerManager::TowerManager(){
    
     cocos2d::CCSize s = cocos2d::CCDirector::sharedDirector()->getWinSize();
    height = s.height;
    width=s.width;
    int x=0;
    int y=0;
    for (int i=0;i<10;i++){
        
        for (int j =0; j<7; j++) {
            TileSquare* t = new TileSquare(x,y);
            tiles.push_back(t);
         
            y+=100;
        }
        x+=100;
    }
    
}
void TowerManager::createTower(b2Vec2 position,cocos2d::CCLayer *layer,b2World* world){
    
    
    
    for (int i=0; i<tiles.size(); i++) {
        if(position.x>tiles[i]->xpos){
            if(position.y>tiles[i]->ypos){
                
                if (tiles[i]->occupied==false) {
                    Tower *t = new Tower();
                    CCSpriteBatchNode * tow= CCSpriteBatchNode::create("tower1.png", 100);
                    t->initialize(tow, world,position, 20, b2Vec2(97, 67), "tower");
                    layer->addChild(t);
                    towers.push_back(t);

                }
            }
      
        }
    }
                                   
    
    
}
void TowerManager::update(){
    
    
        //        if(towers.size()!=0){
        //            for (int i=0; i<towers.size(); i++){
        //                Tower  *b = static_cast<Tower *>(towers[i]);
        //                b->update(world,eManager->enemys,this,world);
        //
        //            }
        //        }
    
    
    
}