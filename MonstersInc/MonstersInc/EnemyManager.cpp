//
//  EnemyManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 10/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EnemyManager.h"

using namespace cocos2d;

EnemyManager::EnemyManager(b2World *w,cocos2d::CCLayer* lay){
    
    world= w;
    layer = lay;
    coins=0;
    count=0;
    EnemyCount=0;
    enemyCurrent=0;
    spawn=550;
    minSpawn=0;
    maxSpawn=0;
    for(int i=0;i<5;i++){
        enemiesToBeAdded[i]=0;
    }
    addcount=0;
    levelCompleted=false;
    totalEnemys=0;
    towerLevel=false;

}
void EnemyManager::update(){
   
    
   
        if( enemiesToBeAdded[addcount]!=0)
        {
            if(count>minSpawn){
            
            //random generate 1 in 5 chance then count = maxspawn
                if(count>maxSpawn){
               
                switch (addcount) {
                    case 0:
                        addEnemy(b2Vec2(20, spawn));
                        break;
                    case 1:
                        addAxeBaby(b2Vec2(20, spawn));
                        break;
                    case 2:
                        addPikachu(b2Vec2(20, spawn));
                        break;
                    case 3:
                        addSully(b2Vec2(20, spawn));
                        break;
                    case 4:
                        addMetroid(b2Vec2(20, spawn));
                        break;  
                    }
                
                    enemiesToBeAdded[addcount]-=1;
                    if(towerLevel==false){
                        spawn+=200;
                    }
                    count=0;
                    if(spawn>600){
                        spawn=100;
                    }
                }
            }
            count++;
        }
        else{
        
            addcount++;
        }
        
       
    
     destroy();
    
}
void EnemyManager::setPath(std::vector<b2Vec2 *> p)
{
    for (int i = 0; i<p.size(); i++) {
        path.push_back(p[i]);
    }
    
}
void EnemyManager::setEnemiesToBeAdded( int enemies[],float min,float max){
    
    minSpawn=min;
    maxSpawn=max;
    addcount=0;
    for(int i=0;i<5;i++){
        enemiesToBeAdded[i]=enemies[i];
        totalEnemys+=enemies[i];
    }
    
    
}
void EnemyManager::destroy(){
    
    for(int i = 0; i<enemys.size();i++){
        
        if(enemys[i]->health<=0){
            
            world->DestroyBody(enemys[i]->m_pBody);
            layer->removeChild(enemys[i], true);
            enemys.erase(enemys.begin()+i);
            coins+=6;
            enemyCurrent--;
            totalEnemys--;
        }
    
    }
    
}
void EnemyManager::moveEnemy(b2Vec2 pos){
    
     for(int i = 0; i<enemys.size();i++){
      
         
         enemys[i]->moveTo(pos);
         
     }
    
    
}
void EnemyManager::movePath(){
    
    for(int i = 0; i<enemys.size();i++){
        
        
        enemys[i]->walkPath();
        
    }
    
}
void EnemyManager::addEnemy(b2Vec2 pos){
   

   
    Enemy * enemy = new Enemy(world,b2Vec2(pos.x, pos.y),2);
    enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addPikachu(b2Vec2 pos){
    
    
 
    Pikachu * enemy = new Pikachu(world,b2Vec2(pos.x, pos.y),4);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
    
}
void EnemyManager::addAxeBaby(b2Vec2 pos){
    
  
    AxeBaby * enemy = new AxeBaby(world,b2Vec2(pos.x, pos.y),1);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addSully(b2Vec2 pos){
    
    
    Sully * enemy = new Sully(world,b2Vec2(pos.x, pos.y),2);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addMetroid(b2Vec2 pos){
    
    
    Metroid * enemy = new Metroid(world,b2Vec2(pos.x, pos.y),2);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}