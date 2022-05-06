//
// Created by Tal on 5/5/2022.
//
#include "Player.h"

Player::Player(char* name, int HP, int force)
{
    this->name = allocateAndCopy(name, strlen(name));
}

char* Player::allocateAndCopy(const char* str, int size) {
    return strcpy(new char[size + 1], str);
}
