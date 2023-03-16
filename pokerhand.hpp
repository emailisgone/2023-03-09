#ifndef POKERHAND_HPP
#define POKERHAND_HPP

#include "card.hpp"
#include "deckofcards.hpp"

class PokerHand{
    private:
    std::vector<Card> hand;

    public:
    PokerHand();
    ~PokerHand();
    void setHand(std::vector<Card> hand);
    void dealHand(DeckOfCards* deck);
    void showHand();
    int onePairValue();
    int twoPairValue();
    int highCardValue();
    int evaluateScore();
};



#endif