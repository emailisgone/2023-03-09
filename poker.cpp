#include "card.hpp"
#include "deckofcards.hpp"
#include "pokerhand.hpp"

// -------------------STATIC INITIALIZERS-----------------------------------------

const std::string Card::suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
const std::string Card::faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const int DeckOfCards::sizeOfDeck = 52;

// -----------------------------------------CARD CLASS--------------------------------

Card::Card(){
    suit = 0;
    face = 0;
    value = face+1;
}

Card::Card(int suit, int face){
    if(suit>3 || suit<0){
        std::cout<<"Incorrect suit chosen. Program was terminated.";
        exit(1);
    }
    if(face>12 || face<0){
        std::cout<<"Incorrect face chosen. Program was terminated.";
        exit(1);
    }
    this->suit = suit;
    this->face = face;
    this->value = face+1;
}

Card::~Card(){

}

std::string Card::toString(){
    return faces[face] + " of " + suits[suit];
}

// -----------------------------------------DECK OF CARDS CLASS-----------------------

DeckOfCards::DeckOfCards(){
    this->deck = std::vector<Card>();
    for(int i=0; i<4; ++i){
        for(int j=0; j<13; ++j){
            deck.push_back(Card(i, j));
        }
    }
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

std::string DeckOfCards::getCard(int index){
    return deck[index].toString();
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

// -----------------------------------------POKER HAND CLASS-----------------------

PokerHand::PokerHand(){
    
}

PokerHand::~PokerHand(){

}

void PokerHand::dealHand(DeckOfCards* deck){
    for(int i=0; i<5; ++i)
        if(deck->moreCards()) hand.push_back(deck->dealCard());
}

void PokerHand::showHand(){
    for(int i=0; i<5; ++i){
        std::cout<<i+1<<") "<<hand[i].toString()<<std::endl;
    } 
}

int PokerHand::onePairValue(){
    std::vector<int> values;
    for(int i=0; i<hand.size(); ++i){
        for(int j=i+1; j<hand.size(); ++j){
            if(hand[i].value == hand[j].value){
                values.push_back(hand[i].value);
            } 
        }
    }
    if(values.size()==1) return values.at(0);
    return 0;
}

int PokerHand::twoPairValue(){
    std::vector<int> values;
    for(int i=0; i<hand.size(); ++i){
        for(int j=i+1; j<hand.size(); ++j){
            if(hand[i].value == hand[j].value){
                values.push_back(hand[i].value);
            } 
        }
    }
    if(values.size()==2){
        if(values.at(0)>values.at(1)) return values.at(0);
        else return values.at(1);
    }
    return 0;
}

int PokerHand::highCardValue(){
    int max = hand.at(0).value;
    for(int i=1; i<5; ++i)
        if(hand.at(i).value>max)
            max = hand.at(i).value;

    return max;
}

int PokerHand::evaluateScore(){
    if(onePairValue()!=0) return onePairValue()+100;
    if(twoPairValue()!=0) return twoPairValue()+50;
    return highCardValue();
}

// -----------------------------------------MAIN--------------------------------

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Card card = Card(3);
    std::cout<<card.toString();
    DeckOfCards theDeck;
    theDeck.shuffle();
//    for(int i=0; i<52; ++i){
//        std::cout<<t.getCard(i)<<std::endl;
//    }

    PokerHand player1, player2;
    player1.dealHand(&theDeck);
    player2.dealHand(&theDeck);
    std::cout<<"Player 1's hand is: "<<std::endl;
    player1.showHand();
    std::cout<<"Player 2's hand is: "<<std::endl;
    player2.showHand();
    if(player1.evaluateScore()>player2.evaluateScore())
        std::cout<<std::endl<<"Player 1 wins!";
    else
        std::cout<<std::endl<<"Player 2 wins!";

    return 0;
}