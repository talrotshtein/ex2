//
// Created by Tal on 5/5/2022.
//
#include "Player.h"

Player::Player(char* name, int HP=100, int force=5):
    name(allocateAndCopy(name, strlen(name)))
    //continue
    {}

char* Player::allocateAndCopy(const char* str, int size) {
    return strcpy(new char[size + 1], str);
}
