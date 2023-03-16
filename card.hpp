#ifndef CARD_HPP
#define CARD_HPP

#include "libraries.hpp"

class Card{
    private:
    int suit;
    int face;
    static const std::string suits[];
    static const std::string faces[];

    public:
    void setSuit(int number);
    void setFace(int number);
    int getSuit();
    int getFace();
    int value;
    Card();
    Card(int suit, int face);
    ~Card();

    std::string toString();
};




#endif