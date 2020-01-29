#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
  
class Card {
    private:
        int card_number, card_suit;
    public:
        // Constructors:
        Card(int x);
        // Accessors:
        string get_face();
        string get_suit();
};

// Implementations:
Card::Card(int x) {
	// TO DO: Break if the card value is invalid
	while (x > 12) { // Assign the number of times 13 can be subtracted from our card number and remain above 12 to the card suite
		x -= 13;
 		card_suit++; // Card suite is either 0 (clubs), 1 (diamonds), 2 (hearts) or 3 (spades)
	}
	card_number = x + 1; // Assign the sum of the remainder and 1 as the card number
}
string Card::get_face() {
	if (card_number == 1) return "Ace";
	else if (card_number == 11) return "Jack";
	else if (card_number == 12) return "Queen";
	else if (card_number == 13) return "King";
	else return to_string(card_number);
}
string Card::get_suit() {
	if (card_suit == 0) return "Clubs";
	else if (card_suit == 1) return "Diamonds";
	else if (card_suit == 2) return "Hearts";
	else return "Spades";
}


class Deck {
   	private:
       	vector<Card> deck(); // Create a vector to hold 52 cards, initialized as -1 (card_number == 0)
		int deck_queue();
   	public:
       	// Constructors:
       	Deck();
		// Accessors:		
		string draw();
		// Mutators:
		void shuffle();
};

// Implementations:
Deck::Deck() {
	int shuffle; // Create an int to store our randomly generated number
	srand(time(NULL)); // Makes rand work better, I guess
	for (int i(0); i < 52; i++) deck.push_back(-1);

		do {
			shuffle = rand() % 51; // Store a random number between 0 and 51 
		} while (Deck::deck[shuffle].get_face() != "0"); // Continue generating random numbers until the card_number at that index is 0 (empty)...
		deck.at(shuffle) = Card(i); // ...then assign card i to the random index
	}
}
string Deck::deal() {
	deck_queue++;
	if (deck_queue > 51 || deck_queue < 0) break;
	string drawn_card = deck.at(deck_queue).get_face(); // Create a new string and store the face value
	drawn_card += " of "; // Store " of " after the face to separate it from the suite
	drawn_card += deck.at(deck_queue).get_suit(); // Finish the string by storing the suite
	return drawn_card;
}
void Deck::shuffle() {
	deck.clear(); // Empty the deck
	deck_queue = -1; // Reset the deck queue
	for (int i(0); i < 52; i++) deck.push_back(-1); // Add 52 cards initialized as -1 (card_number == 0)
	Deck() // Then run the deck constructor to assign cards randomly to each index
}
