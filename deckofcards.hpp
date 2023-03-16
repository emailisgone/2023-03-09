#ifndef DECKOFCARDS_HPP
#define DECKOFCARDS_HPP

#include "card.hpp"

class DeckOfCards{
    private:
    static const int sizeOfDeck;
    std::vector<Card> deck;

    public:
    DeckOfCards();
    ~DeckOfCards();
    void setDeck(std::vector<Card> deck);
    std::string getDeck();
    void shuffle();
    bool moreCards();
    Card dealCard();
};



#endif