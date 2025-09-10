//Answers 14.11 Programming Project Question

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Suit{
  Club,
  Diamond,
  Heart,
  Spade,
  lastSuit
};

enum Rank{
  Ace,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  Jack,
  Queen,
  King,
  lastRank
};

class Card{
  Suit suit;
  Rank rank;
public:
  Card(Suit c, Rank r){
    suit = c;
    rank = r;
  }

  Suit getSuit(){
    return suit;
  }

  Rank getRank(){
    return rank;
  }

  string convertToRank(Rank r);
  string convertToSuit(Suit s);

  void print(){
    cout << convertToRank(rank) << " of " << convertToSuit(suit) << endl;
  }
};

string Card::convertToRank(Rank r){
  switch (r){
    case Ace:
        return "Ace";
    case two:
        return "2";
    case three:
        return "3";
    case four:
        return "4";
    case five:
        return "5";
    case six:
        return "6";
    case seven:
        return "7";
    case eight:
        return "8";
    case nine:
        return "9";
    case ten:
        return "10";
    case Jack:
        return "Jack";
    case Queen:
        return "Queen";
    case King:
        return "King";

    default:
      return "None";
      break;
    }
  }

string Card::convertToSuit(Suit s){
  switch (s){
    case Club:
        return "Club";
    case Diamond:
        return "Diamond";
    case Heart:
        return "Heart";
    case Spade:
        return "Spade";

    default:
        return "None";
        break;
      }
    }


class Deck{
protected:
  vector<Card>cards;
public:
  Deck(){
    for (int typeOfSuit = Club; typeOfSuit != lastSuit; typeOfSuit++)
        {
            Suit cardSuit = static_cast<Suit>(typeOfSuit);
            for (int r = Ace; r != lastRank; r++)
            {
                Rank cardRank = static_cast<Rank>(r);
                cards.push_back(Card(cardSuit, cardRank));
            }
        }
    }

    void printDeck(){
      for (Card newCard : cards){ // for the range-based for loop, I passed --std=c++11 to the compiler and the previous warning of "ange-based for loop is a C++11
                                //extension [-Wc++11-extensions]" for gone
        newCard.print();
      }
    }

    void shuffleDeck(Deck& deck){
      Deck shuffled;
      while(!deck.cards.empty()){
        size_t rand_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[rand_index]); //shuffled.cards is a vector
        deck.cards.erase(deck.cards.begin() + rand_index);

      }
      deck = shuffled;
    }

    void addCard(Card card){
      cards.push_back(card);
    }

    Card removeCard(){
      Card temp = *cards.begin();
      cards.erase(cards.begin());
      return temp;
    }

    static bool compare(Card& card1, Card& card2);

    void sortDeck(){
      sort(cards.begin(), cards.end(), compare);
    }

    int getSize(){
      return cards.size();
    }
};

bool Deck::compare(Card& card1, Card& card2){
  return card1.getRank() < card2.getRank();
}

class Hand : public Deck{
public:
  Hand(){
    cards = vector<Card>();
  }
};

int main(){
  Deck deck = Deck();
  cout << "Suffling the deck..." << endl;
  deck.shuffleDeck(deck);
  cout << "Printing deck: " << endl;
  deck.printDeck();
  cout << "_______________________________" << endl;
  Hand hand1;
  Hand hand2;
  for (int i = 0; i < 6; i++){
    hand1.addCard(deck.removeCard());
  }

  for (int i = 0; i < 5; i++){
    hand2.addCard(deck.removeCard());
  }
  cout << "_______________________________" << endl;
  cout << "Printing deck in hand 1: " << endl;
  hand1.printDeck();
  cout << "Printing deck in hand 2: " << endl;
  hand2.printDeck();
  return 0;
}
