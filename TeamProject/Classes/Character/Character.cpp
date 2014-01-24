//
//  Character.cpp
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#include "Character.h"
Character::Character(){
}

Character::~Character(){
}

void Character::autoRun(RMTiledMap* tileMap){

}

void Character::create(){
}

void Character::addToMap(CCPoint location, CCLayer* layer, RMTiledMap *tiledMap){
    this->position  = location;
    this->spr->setPosition(tiledMap->convertPosMapToPoint(location));
    layer->addChild(spr);
}

bool Character::checkLeft(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.x <= 0)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x - 1 , currenPos.y));
    if (type && type->compare("1") == 0 && currenPos.x > 0) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkRight(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.x >= 25)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x + 1 , currenPos.y));
    if (type && type->compare("1") == 0 && currenPos.x < 25) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkBelow(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.y >= 28)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x, currenPos.y + 1));
    if (type && type->compare("1") == 0) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

bool Character::checkUpward(RMTiledMap *tiledMap, CCPoint currenPos){
    if(currenPos.y <= 0)
        return false;
    CCString *type = tiledMap->typeAtTileCoord(ccp(currenPos.x, currenPos.y - 1));
    if (type && type->compare("1") == 0) {
        return true;
    }
    else if(type == NULL){
        return true;
    }
    else return false;
}

void Character::moveLeft(RMTiledMap *tiledMap){
    if(checkLeft(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(tiledMap->getTiledMap()->getTileSize().width * (-1), 0)));
        this->position = ccp(this->position.x - 1, this->position.y);
        this->setRunCurrent(2);
    }
}

void Character::moveRight(RMTiledMap *tiledMap){
    if(checkRight(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(tiledMap->getTiledMap()->getTileSize().width, 0)));
        this->position = ccp(this->position.x + 1, this->position.y);
        this->setRunCurrent(1);
    }
}

void Character::moveBelow(RMTiledMap *tiledMap){
    if(checkBelow(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(0, tiledMap->getTiledMap()->getTileSize().width * (-1))));
        this->position = ccp(this->position.x, this->position.y + 1);
        this->setRunCurrent(4);
    }
}

void Character::moveUpward(RMTiledMap *tiledMap){
    if(checkUpward(tiledMap, this->position)){
        this->spr->runAction(CCMoveBy::create(this->getVelocity(), ccp(0, tiledMap->getTiledMap()->getTileSize().width)));
        this->position = ccp(this->position.x, this->position.y - 1);
        this->setRunCurrent(3);
    }
}