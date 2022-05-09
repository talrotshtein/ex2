//
// Created by Tal on 5/5/2022.
//
#include "Player.h"
#include "utilities.h"

static const int MAX_LEVEL = 10;
static const int MAX_HP = 100;
static const int DEFAULT_FORCE = 5;

Player::Player(const char* name, int HP, int force)
{
    this->m_name = allocateAndCopy(name, strlen(name));
    if(HP > 0){
        this->m_HP = HP;
        this->m_maxHP = HP;
    }
    else if(HP<=0)
    {
        this->m_HP = MAX_HP;
        this->m_maxHP = MAX_HP;
    }
    if(force >0){
        this->m_force = force;
    }
    else if(force<=0)
    {
        this->m_force = DEFAULT_FORCE;
    }
    this->m_coins = 0;
    this->m_level = 1;
}

Player::Player(const Player& player) {
    this->m_name = allocateAndCopy(player.m_name, strlen(player.m_name));
    this->m_level = player.m_level;
    this->m_HP = player.m_HP;
    this->m_maxHP = player.m_maxHP;
    this->m_coins = player.m_coins;
    this->m_force = player.m_force;
}

Player& Player::operator=(const Player& player){
    if(this == &player){
        return *this;
    }
    m_level = player.m_level;
    m_HP = player.m_HP;
    m_maxHP = player.m_maxHP;
    m_coins = player.m_coins;
    delete[] m_name;
    m_name = allocateAndCopy(player.m_name, strlen(player.m_name));
    m_force = player.m_force;
    return *this;
}

Player::~Player() {
    delete[] m_name;
}

char* Player::allocateAndCopy(const char* str, int size) {
    return strcpy(new char[size + 1], str);
}

void Player::printInfo()
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp()
{
    if (this->m_level<MAX_LEVEL)
    {
        this->m_level++;
    }
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int forceToAdd)
{
    if(forceToAdd>0){
        this->m_force += forceToAdd;
    }
}

void Player::heal(int HPToAdd)
{
    if(HPToAdd <= 0){
        return;
    }
    if(this->m_HP + HPToAdd >= this->m_maxHP)
    {
        this->m_HP = this->m_maxHP;
    }
    else
    {
        this->m_HP += HPToAdd;
    }
}

void Player::damage(int HPToRemove)
{
    if(HPToRemove <= 0){
        return;
    }
    if(this->m_HP - HPToRemove <= 0)
    {
        this->m_HP = 0;
    }
    else
    {
        this->m_HP -= HPToRemove;
    }
}

bool Player::isKnockedOut() const{
    if(m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) {
    if(coinsToAdd>0){
        this->m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay <= 0){
        return true;
    }
    if(coinsToPay > m_coins){
        return false;
    }
    else{
        m_coins-=coinsToPay;
        return true;
    }
}

int Player::getAttackStrength() const{
    return m_level + m_force;
}





