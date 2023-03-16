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
    void shuffle();
    std::string getCard(int index);
    bool moreCards();
    Card dealCard();
};



#endif