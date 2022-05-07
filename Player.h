//
// Created by Tal on 5/5/2022.
//
#include <cstring>
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

class Player{

private:
    char* m_name;
    int m_coins;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_level;

    static char* allocateAndCopy(const char* data, int size);

public:
    Player(const char* name, int HP=100, int force=5);
    Player(const Player& player);
    ~Player();
    Player& operator=(const Player& player);
    void printInfo();
    void levelUp();
    int getLevel() const;
    void buff(int forceToAdd);
    void heal(int HPToAdd);
    void damage(int HPToRemove);
    bool isKnockedOut() const;
    void addCoins(int coinsToAdd);
    bool pay(int coinsToPay);
    int getAttackStrength() const;
};



#endif //EX2_PLAYER_H
