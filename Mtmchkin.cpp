//
// Created by Tal on 5/5/2022.
//
#include "Mtmchkin.h"

static const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
    m_player(Player(playerName)),
    m_cardArray(allocateAndCopyCardArray(cardsArray, numOfCards)),
    m_numOfCards(numOfCards),
    m_status(GameStatus::MidGame),
    m_currentCard(0)
{}

Card *Mtmchkin::allocateAndCopyCardArray(const Card *cardsArray, int numOfCards) {
    Card* tempCardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i) {
        tempCardsArray[i] = cardsArray[i];
    }
    return tempCardsArray;
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
    if(CheckWin())
    {
        this->m_status = GameStatus::Win;
        return;
    }
    if(CheckLoss())
    {
        this->m_status = GameStatus::Loss;
        return;
    }
    if(this->m_currentCard == this->m_numOfCards-1)
    {
        this->m_currentCard = 0;
    }
    else
    {
        this->m_currentCard++;
    }
}

bool Mtmchkin::CheckWin(){
    if(this->m_player.getLevel() == MAX_LEVEL)
        return true;
    return false;
}

bool Mtmchkin::CheckLoss() {
    if(this->m_player.isKnockedOut())
        return true;
    return false;
}

Mtmchkin::~Mtmchkin() {
    delete[] this->m_cardArray;
}

 bool Mtmchkin::isOver() const
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