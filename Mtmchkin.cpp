//
// Created by Tal on 5/5/2022.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    Player player1(playerName);
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_status;
}

void Mtmchkin::playNextCard()
{

}

bool Mtmchkin::isOver()
{
    if(this->m_status == GameStatus::MidGame)
    {
        return false;
    }
    else
    {
        return true;
    }
}