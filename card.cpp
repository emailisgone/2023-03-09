#include "card.hpp"

// -----------------------------------------CARD CLASS--------------------------------

void Card::setSuit(int number){
    if(number>3 || number<0){
        std::cout<<"Incorrect suit chosen. Program was terminated.";
        exit(1);
    }
    this->suit = number;
}

void Card::setFace(int number){
    if(number>12 || number<0){
        std::cout<<"Incorrect face chosen. Program was terminated.";
        exit(1);
    }
    this->face = number;
}

int Card::getSuit(){
    return this->suit;
}

int Card::getFace(){
    return this->face;
}

Card::Card(){
    setSuit(0);
    setFace(0);
    value = face+1;
}

Card::Card(int suit, int face = 0){
    setSuit(suit);
    setFace(face);
    this->value = face+1;
}

Card::~Card(){

}

std::string Card::toString(){
    return faces[face] + " of " + suits[suit];
}