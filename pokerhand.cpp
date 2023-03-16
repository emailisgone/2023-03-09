#include "pokerhand.hpp"

// -----------------------------------------POKER HAND CLASS-----------------------

void PokerHand::setHand(std::vector<Card> hand){
    this->hand = hand;
}

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
            if(hand[i].getFace()+1 == hand[j].getFace()+1){
                values.push_back(hand[i].getFace()+1);
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
            if(hand[i].getFace()+1 == hand[j].getFace()+1){
                values.push_back(hand[i].getFace()+1);
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
    int max = hand.at(0).getFace()+1;
    for(int i=1; i<5; ++i)
        if(hand.at(i).getFace()+1>max)
            max = hand.at(i).getFace()+1;

    return max;
}

int PokerHand::evaluateScore(){
    if(onePairValue()!=0) return onePairValue()+100;
    if(twoPairValue()!=0) return twoPairValue()+50;
    return highCardValue();
}