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
        y=0;
    }
    for(int i=0;i<tiles.size();i++){
        
        if(i==5||i==12||i==11||i==10||i==9||i==8||i==7||i==14||i==21||i==28||i==35||i==42||i==49||i==50||i==51||i==52||i==53||i==56||i==57||i==60||i==64||i==63||i==65||i==66||i==67||i==68||i==69){
            tiles[i]->occupied=true;
        }
    }
    
}
void TowerManager::createTower(b2Vec2 position,cocos2d::CCLayer *layer,b2World* world){
    
    
    
    for (int i=0; i<tiles.size(); i++) {
        
        if(position.x>tiles[i]->xpos&&position.x<tiles[i]->xpos+100){
            if(position.y>tiles[i]->ypos&&position.y<tiles[i]->ypos+100){
                
                if (tiles[i]->occupied==false) {
                    Tower *t = new Tower();
                    CCSpriteBatchNode * tow= CCSpriteBatchNode::create("tower1.png", 100);
                    t->initialize(tow, world,b2Vec2(tiles[i]->xpos+50, tiles[i]->ypos+50), 20, b2Vec2(97, 67), "tower");
                    layer->addChild(t);
                    towers.push_back(t);
                    tiles[i]->occupied=true;

                }
            }
      
        }
    }
                                   
    
    
}
void TowerManager::update(std::vector<Enemy*> enemys,b2World* world,cocos2d::CCLayer* layer){
    
    
                if(towers.size()!=0){
                    for (int i=0; i<towers.size(); i++){
                        Tower  *b = static_cast<Tower *>(towers[i]);
                        b->update(world,enemys,layer);
        
                    }
                }
    
    
    
}