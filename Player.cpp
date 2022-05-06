//
// Created by Tal on 5/5/2022.
//
#include "Player.h"
#include "utilities.h"

const int MAX_LEVEL = 10;

Player::Player(char* name, int HP, int force)
{
    this->name = allocateAndCopy(name, strlen(name));
    this->HP = HP;
    this->maxHP = HP;
    this->force = force;
    this->coins = 0;
    this->level = 1;
}

Player::Player(const Player& player) {
    this->name = allocateAndCopy(player.name, strlen(player.name));
    this->level = player.level;
    this->HP = player.HP;
    this->maxHP = player.maxHP;
    this->coins = player.coins;
    this->force = player.force;
}

Player& Player::operator=(const Player& player){
    if(this == &player){
        return *this;
    }
    level = player.level;
    HP = player.HP;
    maxHP = player.maxHP;
    coins = player.coins;
    delete[] name;
    name = allocateAndCopy(player.name, strlen(player.name));
    force = player.force;
}

Player::~Player() {
    delete[] name;
}

char* Player::allocateAndCopy(const char* str, int size) {
    return strcpy(new char[size + 1], str);
}

void Player::printInfo()
{
    printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}

void Player::levelUp()
{
    if (this->level<MAX_LEVEL)
    {
        this->level++;
    }
}

int Player::getLevel()
{
    return this->level;
}

bool Player::isKnockedOut() {
    if(HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) {
    if(coinsToAdd>0){
        this->coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay <= 0){
        return true;
    }
    if(coinsToPay > coins){
        return false;
    }
    else{
        coins-=coinsToPay;
        return true;
    }
}





