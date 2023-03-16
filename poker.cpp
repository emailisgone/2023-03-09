#include "card.cpp"
#include "deckofcards.cpp"
#include "pokerhand.cpp"

// -------------------STATIC INITIALIZERS-----------------------------------------

const std::string Card::suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
const std::string Card::faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const int DeckOfCards::sizeOfDeck = 52;

// -----------------------------------------MAIN--------------------------------

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //Card card = Card(3);
    //std::cout<<card.toString();
    DeckOfCards theDeck;
    theDeck.shuffle();

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