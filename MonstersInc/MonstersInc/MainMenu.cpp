//
//  MainMenu.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 12/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "Tutorial.h"
#include "SimpleAudioEngine.h"


#include <CCUserDefault.h>


using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;


static size_t curl_to_string(void *ptr, size_t size, size_t nmemb, void *data)
{
    std::string *str = (std::string *) data;
    char *sptr = (char *) ptr;
    int x;
    
    for(x = 0; x < size * nmemb; ++x)
    {
        (*str) += sptr[x];
    }
    
    return size * nmemb;
}
static int curlWriter(char *data, size_t size, size_t nmemb, std::string *outputBuffer)
{
    if (outputBuffer != NULL){
        CCLOG("%s", data);
        
    }
    
    return size * nmemb;
}
MainMenu::MainMenu(){
    
    init();
    
    
}
void MainMenu::init(){
    
    world = new b2World(b2Vec2_zero);

    
    pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",this,menu_selector(MainMenu::test));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    addChild(pMenu, 1);

    
//    tutorial=CCMenuItemImage::create("Tutorial.png", "Tutorial.png", this, menu_selector(MainMenu::tutorialLevel));
//    tutorial->setPosition(CCPoint(100, 500));
//    CCMenu *tut=CCMenu::create(tutorial,NULL);
//    tut->setPosition(CCPointZero);
//    addChild(tut,1);
    
    level1btn=CCMenuItemImage::create("play.bmp", "playdown.bmp", this, menu_selector(MainMenu::level1));
    level1btn->setPosition(CCPoint(100, 400));
    CCMenu *lev1=CCMenu::create(level1btn,NULL);
    lev1->setPosition(CCPointZero);
    addChild(lev1,1);
    
    
    
//    level2btn=CCMenuItemImage::create("Level2.png", "Level2.png", this, menu_selector(MainMenu::level2));
//    level2btn->setPosition(CCPoint(100, 300));
//    CCMenu *lev2=CCMenu::create(level2btn,NULL);
//    lev2->setPosition(CCPointZero);
//    addChild(lev2,1);
    
    
    towerGame=CCMenuItemImage::create("TowersButton.bmp", "TowersButtonDown.bmp", this, menu_selector(MainMenu::towerDefence));
    towerGame->setPosition(CCPoint(100, 300));
    CCMenu *towergame=CCMenu::create(towerGame,NULL);
    towergame->setPosition(CCPointZero);
    addChild(towergame,1);
    
    
    
    jaime = CCSprite::create("MonstersInc.jpg");
    jaime->setPosition(CCPointMake(510, 380));
    addChild(jaime);
    
    label = CCLabelTTF::create("", "Marker Felt", 32);
    addChild(label, 1);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( 160, 745));
    
    Namelabel = CCLabelTTF::create("Name:", "Marker Felt", 32);
    addChild(Namelabel, 1);
    Namelabel->setColor(ccc3(0,0,255));
    Namelabel->setPosition(ccp( 60, 745));

    
    goldlabel=CCLabelTTF::create("gold:", "Marker Felt", 32);
    addChild(goldlabel,1);
    goldlabel->setColor(ccc3(0,0,255));
    goldlabel->setPosition(ccp( 360, 745));
    
    goldlabel2=CCLabelTTF::create("", "Marker Felt", 32);
    addChild(goldlabel2,1);
    goldlabel2->setColor(ccc3(0,0,255));
    goldlabel2->setPosition(ccp(430, 745));
    
    data=CCLabelTTF::create("", "Marker Felt", 32);
    addChild(data,1);
    data->setColor(ccc3(0,0,255));
    data->setPosition(ccp(400, 205));
    
    Name=CCLabelTTF::create("Name", "Marker Felt", 32);
    addChild(Name,1);
    Name->setColor(ccc3(0,0,255));
    Name->setPosition(ccp(1800, 600));
    
    Score=CCLabelTTF::create("Coins", "Marker Felt", 32);
    addChild(Score,1);
    Score->setColor(ccc3(0,0,255));
    Score->setPosition(ccp(1850, 600));

    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Final Fantasy 7 Music - Aerith's Theme.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Final Fantasy 7 Music - Aerith's Theme.mp3", true);
    
    int yPos=550;
    for(int i=0;i<10;i++){
    
        cocos2d::CCLabelTTF *profile;
        profile=CCLabelTTF::create("", "Marker Felt", 32);
        addChild(profile,1);
        profile->setColor(ccc3(0,0,255));
        profile->setPosition(ccp(850, yPos));
        profiles[i]=profile;
        yPos-=50;
        
        
    }
    
    newGame=CCMenuItemImage::create("NewGame.bmp", "NewGameDown.bmp", this, menu_selector(MainMenu::newPlayer));
    newGame->setPosition(CCPoint(100, 500));
    CCMenu *newFile=CCMenu::create(newGame,NULL);
    newFile->setPosition(CCPointZero);
    addChild(newFile,1);
    
   
        
    
    pNormal9SpriteBg= cocos2d::extension::CCScale9Sprite::create("assaultRifleSelect.png");
    m_pEditName = cocos2d::extension::CCEditBox::create(CCSize(250, 30), pNormal9SpriteBg);
    m_pEditName->setPosition(ccp(1400, 200));
    m_pEditName->setFontColor(ccBLUE);
    m_pEditName->setPlaceHolder("Name:");
    m_pEditName->setMaxLength(8);
    addChild(m_pEditName);
    
    enter=CCMenuItemImage::create("Enter.png", "Enter.png", this, menu_selector(MainMenu::enterPlayer));
    enter->setPosition(CCPoint(1400, 400));
    CCMenu *enterB=CCMenu::create(enter,NULL);
    enterB->setPosition(CCPointZero);
    addChild(enterB,1);
    
    sizeOfPlayers =10;
   
  
    savedData= new SaveFileData();
     wait=0;
    multiplayer=false;
    connected=false;
     
    scheduleUpdate();
       
}
void MainMenu::disassembleCurl(std::string data){
    for(int i =0;i<sizeOfPlayers;i++){
        Players[i]="";
        Scores[i]=0;
        
    }
    const char * c;
    bool start=false;
    int count =0;
    int j=0;
    std::string scor;
    for (int i=0; i<data.length(); i++) {
        if (data[i]=='"') {
            if(start==true){
                start=false;
                c="";
                j=i+1;
                if (data[j]==',') {
                    j++;
                    while (data[j]!=']') {
                         c= new char(data[j]);
                        scor.append(c);
                        j++;
                    }
                    j=0;
                }
                Scores[count]= atoi(scor.c_str());
                scor="";
                count++;
                c="";
            }
            else{
                start=true;
            }
        }
        else if(start){
            c= new char(data[i]);
            Players[count].append(c);
        }
    }    
}
void MainMenu::saveWithCurl(std::string n, int s){
    
    CURL *curl;
    CURLcode res;
    char t[100];
    snprintf(t, 100, "%i",s);
    curl = curl_easy_init();
    std::string line ="'"+n+"' ,'"+t+"'";
    const char * use =line.c_str();
   
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://10.40.8.117:8080/insertScore/");
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, use);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    
    
}
void MainMenu::enterPlayer(){
    
    
   // level2btn->setPosition(CCPoint(100, 300));
    level1btn->setPosition(CCPoint(100, 400));
     towerGame->setPosition(CCPoint(100, 300));
    m_pEditName->setPosition(ccp(1400, 200));
    enter->setPosition(CCPoint(1400, 400));
    newGame->setPosition(CCPoint(100, 500));
    
    if(m_pEditName->getText()!=NULL){
        
        savedData->newPlayer(m_pEditName->getText());
       // saveWithCurl(m_pEditName->getText(), 200);
    
    }
    
    
    
}
void MainMenu::newPlayer(){
     towerGame->setPosition(CCPoint(1400, 400));
    level1btn->setPosition(CCPoint(1400, 400));
    //tutorial->setPosition(CCPoint(1400, 400));
    m_pEditName->setPosition(ccp(400, 500));
    enter->setPosition(CCPoint(400, 400));
    newGame->setPosition(CCPoint(1400, 500));
    
 
}
void MainMenu::update(float dt){
    int velocityIterations = 8;
    int positionIterations = 1;
    
    
    const char * c = savedData->name.c_str();
    label->setString(c);
    snprintf(ttt, 100, "%i",savedData->gold);
    goldlabel2->setString(ttt);
    
    //const char * p = Players[1].c_str();
    //data->setString(p);
    if(multiplayer){
        
        
       
      
            if(wait>120){
                checkMultiPlayer();
               
            }
            wait++;
        
        
    }
    
    world->Step(dt, velocityIterations, positionIterations);

}
void MainMenu::test(){
    
   
}
void MainMenu::checkMultiPlayer(){
    CURL *curl;
    CURLcode res;
    multi="";
    curl = curl_easy_init();
    if (curl) 
    {
        curl_easy_setopt(curl,   CURLOPT_URL, "http://10.40.8.117:8080/getSession/");
        curl_easy_setopt(curl,   CURLOPT_NOPROGRESS  ,1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &multi);
        
        res = curl_easy_perform(curl);
        
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            CCLOG("0 response (success)");
        }
        else
        {
            CCLog("code: %i",res);
        }
    } 
    else 
    {
        CCLOG("no curl");
    } 
    std::string scor;
    const char * c;
    for (int i=0; i<multi.length(); i++) {
        if (multi[i]=='3') {
            c= new char(multi[i]);
            scor.append(c);
            
        }
    }
    if(scor.length()>1){
        
        data->setString("Ready");

        
    }
    
}
void MainMenu::tutorialLevel(){;
    
    level2btn->setPosition(CCPoint(1400, 400));
    level1btn->setPosition(CCPoint(1400, 400));
    tutorial->setPosition(CCPoint(1400, 400));

    CURL *curl;
    CURLcode res;
    std::string datab="";
    curl = curl_easy_init();
    if (curl) 
    {
        curl_easy_setopt(curl,   CURLOPT_URL, "http://10.40.8.117:8080/SearchForSession/");
        curl_easy_setopt(curl,   CURLOPT_NOPROGRESS  ,1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &datab);
        
        res = curl_easy_perform(curl);
        
        /* always cleanup */
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            CCLOG("0 response (success)");
        }
        else
        {
            CCLog("code: %i",res);
        }
    } 
    else 
    {
        CCLOG("no curl");
    } 
    const char * test = datab.c_str();
    data->setString(test);

    multiplayer=true;
    
}
void MainMenu::level1(){
    
    CCScene *pScene1= HelloWorld::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
    
}
void MainMenu::towerDefence(){
    
    CCScene *pScene1= LevelManager::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
    
}
void MainMenu::level2(){
    
    Name->setPosition(ccp(800, 600));
    Score->setPosition(ccp(900, 600));

    CURL *curl;
    CURLcode res;
    std::string datab="";
    curl = curl_easy_init();
    if (curl) 
    {
        curl_easy_setopt(curl,   CURLOPT_URL, "http://10.40.8.117:8080/getScore/");
        curl_easy_setopt(curl,   CURLOPT_NOPROGRESS  ,1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &datab);
        
        res = curl_easy_perform(curl);
        
        /* always cleanup */
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            CCLOG("0 response (success)");
        }
        else
        {
            CCLog("code: %i",res);
        }
    } 
    else 
    {
        CCLOG("no curl");
    } 
    disassembleCurl(datab);
    char d[100];
    for (int i =0; i<sizeOfPlayers; i++) {
        
        snprintf(d, 100, "%i",Scores[i]);
        std::string n= Players[i]+" "+d;
        const char * c = n.c_str();
        if(Scores[i]==0){
            c="Empty";
            
        }
        profiles[i]->setString(c);
    }
}
CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new MainMenu();
    
    
    
    scene->addChild(layer);
    layer->release();
    
    return scene;
}