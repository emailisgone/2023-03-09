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
    int value;
    Card();
    Card(int suit, int face = 0);
    ~Card();

    std::string toString();
};




#endif