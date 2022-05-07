//
// Created by Tal on 5/5/2022.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) {
    Player player(playerName);
    this->m_player = player;
    this->m_cardArray = cardsArray;
    this->m_numOfCards = numOfCards;
    this->m_status = GameStatus::MidGame;
    this->m_currentCard = 0;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_status;
}

void Mtmchkin::playNextCard()
{
    this->m_cardArray[this->m_currentCard].printInfo();
    this->m_cardArray[this->m_currentCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    if(this->m_currentCard == this->m_numOfCards-1)
    {
        this->m_currentCard = 0;
    }
    else
    {
        this->m_currentCard++;
    }
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