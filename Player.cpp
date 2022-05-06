//
// Created by Tal on 5/5/2022.
//
#include "Player.h"

const int MAX_LEVEL = 10;
Player::Player(char* name, int HP, int force)
{
    this->name = allocateAndCopy(name, strlen(name));
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