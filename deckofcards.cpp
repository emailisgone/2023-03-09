#include "deckofcards.hpp"

// -----------------------------------------DECK OF CARDS CLASS-----------------------
void DeckOfCards::setDeck(std::vector<Card> deck){
    this->deck = deck;
}

std::string DeckOfCards::getDeck(){
    std::string reso;
    for(int i=0; i<sizeOfDeck; ++i){
        reso.append(i+") "+deck.at(i).toString()+"\n");
    }
    return reso;
}

DeckOfCards::DeckOfCards(){
    std::vector<Card> deck;
    for(int i=0; i<4; ++i){
        for(int j=0; j<13; ++j){
            deck.push_back(Card(i, j));
        }
    }
    setDeck(deck);
}

DeckOfCards::~DeckOfCards(){

}



void DeckOfCards::shuffle(){
    //auto rnd = std::default_random_engine(837);
    //std::shuffle(deck.begin(), deck.end(), rnd);

    for(int i=0; i<sizeOfDeck; ++i){
        int rng1 = std::rand()%sizeOfDeck;
        int rng2 = std::rand()%sizeOfDeck;
        std::swap(deck[rng1], deck[rng2]);
    }
}

bool DeckOfCards::moreCards(){
    if(deck.size()!=0) return true;
    return false;
}

// before calling, check moreCards()
Card DeckOfCards::dealCard(){
    Card res = deck.at(deck.size()-1);
    deck.pop_back();
    return res;
}