
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D.h"
#include "Player.h"
#include "PhysicsSprite.h"
#include "Analogue.h"
#include "Enemy.h"
#include "Base.h"
#include "Bullet.h"
#include "MyContactListener.h"
#include "EnemyManager.h"
//#include "MainMenu.h"
#include "Gun.h"
#include "Human.h"
#include "BaseButton.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    //CREATE_FUNC(HelloWorld);
    void initPhysics();
    // adds a new sprite at a given coordinate
    void addNewSpriteAtPosition(cocos2d::CCPoint p);
    
    virtual void draw();
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    void update(float dt);
    void move();
    void exitMainMenu();

     void menuCloseCallback(CCObject* pSender);
    Analogue * analog;
    Analogue * analog2;
    Human *human;

private:
    b2World* world;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
    cocos2d::CCPoint location;
    Player *player;
    Enemy *enemy;
    Enemy *enemy2;
    Base *base;
    BaseButton *baseButton;
    cocos2d::CCSprite *jaime;
    cocos2d::CCArray *bullets;
    cocos2d::CCSpriteBatchNode *bulletSprite;
  
    MyContactListener mycontact;
    EnemyManager *eManager;
    Gun *gun;
    int firecount;
    int enemyCount;
    cocos2d::CCLabelTTF *win;
    cocos2d::CCLabelTTF *win2;
    cocos2d::CCLabelTTF *loose;

    
    
    cocos2d::CCLabelTTF *label;
    cocos2d::CCLabelTTF *label2;
    cocos2d::CCLabelTTF *label3;
    cocos2d::CCLabelTTF *label4;
    cocos2d::CCMenuItemImage * pCloseItem ;   
   
};

#endif // __HELLOWORLD_SCENE_H__
