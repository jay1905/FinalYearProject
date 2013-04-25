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
    
    int posx=-950;
    int posy=950;
    
    for (int i=0; i<19; i++) {
        
        spawnPos.push_back(b2Vec2(posx, posy));
        posy-=100;
    }
     posx=-950;
     posy=-950;
    
    for (int i=0; i<19; i++) {
        
        spawnPos.push_back(b2Vec2(posx, posy));
        posx+=100;
    }
    posx=950;
    posy=-950;
    
    for (int i=0; i<19; i++) {
        
        spawnPos.push_back(b2Vec2(posx, posy));
        posy+=100;
    }
    posx=950;
    posy=950;
    
    for (int i=0; i<19; i++) {
        
        spawnPos.push_back(b2Vec2(posx, posy));
        posx-=100;
    }
    addcount=0;
    levelCompleted=false;
    totalEnemys=0;
    towerLevel=false;
    srand (time(NULL));
    spawnpoint=b2Vec2(0,0);
    

}
void EnemyManager::update(){
   
    
    if(towerLevel==true){
        
        spawnpoint=b2Vec2(20,550);

    }
    else{
        
        int ran = rand() % 76;
        spawnpoint=spawnPos[ran];
        
    }
    
    
        if( enemiesToBeAdded[addcount]!=0)
        {
            if(count>minSpawn){
            
            //random generate 1 in 5 chance then count = maxspawn
                if(count>maxSpawn){
               
                switch (addcount) {
                    case 0:
                        addEnemy(spawnpoint);
                        break;
                    case 1:
                        addAxeBaby(spawnpoint);
                        break;
                    case 2:
                        addPikachu(spawnpoint);
                        break;
                    case 3:
                        addSully(spawnpoint);
                        break;
                    case 4:
                        addMetroid(spawnpoint);
                        break;  
                    }
                
                    enemiesToBeAdded[addcount]-=1;
                     count=0;
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
   

   
    Enemy * enemy = new Enemy(world,b2Vec2(pos.x, pos.y),2.5);
    enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addPikachu(b2Vec2 pos){
    
    
 
    Pikachu * enemy = new Pikachu(world,b2Vec2(pos.x, pos.y),4.3);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
    
}
void EnemyManager::addAxeBaby(b2Vec2 pos){
    
  
    AxeBaby * enemy = new AxeBaby(world,b2Vec2(pos.x, pos.y),4);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addSully(b2Vec2 pos){
    
    
    Sully * enemy = new Sully(world,b2Vec2(pos.x, pos.y),3.2);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}
void EnemyManager::addMetroid(b2Vec2 pos){
    
    
    Metroid * enemy = new Metroid(world,b2Vec2(pos.x, pos.y),3);
     enemy->setPath(path);
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}