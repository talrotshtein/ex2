//
// Created by Tal on 5/5/2022.
//
#include <cstring>
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

class Player{
    char* name;
    int coins;
    int force;
    int HP;
    int level;

    static char* allocateAndCopy(const char* data, int size);

public:
    Player(char* name, int = 100, int force = 5);
    Player(const Player& player);
    ~Player();
    Player& operator=(const Player&);
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int force);
    void heal(int HP);
    void damage(int HP);
    void isKnockedOut();
    void addCoins(int coins);
    bool pay(int coins);
    int getAttackStrength();
};



#endif //EX2_PLAYER_H
