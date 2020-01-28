#ifndef Deck_h
#define Deck_h

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
  
class Card {
    private:
        int card_number, card_suite(0);
    public:
        // Constructors:
        Card(int x);

        // Accessors:
        int get_number();
        int get_suite();

        // Implementations:
        Card::Card(int x) {
            while (x > 12) { // Assign the number of times 13 can be subtracted from our card number and remain above 12 to the card suite
                x -= 13;
                card_suite++ // Card suite is either 0 (clubs), 1 (diamonds), 2 (hearts) or 3 (spades)
            }
            card_number = x + 1; // Assign the sum of the remainder and 1 as the card number
        }

        int Card::get_number() {
            return card_number;
        }
        int Card::get_suite() {
            return card_suite;
        }
};

class Deck {
    private:
        vector<Card> deck(52, {0, 0}); // 
    public:
        // Constructors:
        Deck();

	// Accessors:
	string output_card();

	// Mutators:
	void reshuffle();
	
        // Implementations:
        Deck::Deck() {
            int shuffle; // Create an int to store our randomly generated number
            srand(time(NULL)); // Makes rand work better, I guess

            for (int i(0); i < 52; i++) { // For every card in our deck (minus one to account for card 0)
                do {
                    shuffle = rand() % 51; // Store a random number between 0 and 51 
                } while (deck.at(shuffle) != {0, 0}); // Continue generating numbers until the deck at that index is 0 (empty)...
                deck.at(shuffle) = Card(i); // ...then assign card i to the random index
            }
        }
        string Deck::output_card(int x) {
            string y;
            if (deck.at(x).get_number() == 1) y = "Ace"; // If the card is an ace or face, add its full name to the string
            else if (deck.at(x).get_number() == 11) y = "Jack";
            else if (deck.at(x).get_number() == 12) y = "Queen";
            else if (deck.at(x).get_number() == 13) y = "King";
            else y = to_string(deck.at(x).get_number()); // If it's not an ace or face, convert its number and add it to the string
            if (deck.at(x).get_suite() == 0) y += " of Clubs"; // Check for the suite, then add " of suite" to the string
            else if (deck.at(x).get_suite() == 1) y += " of Diamonds";
            else if (deck.at(x).get_suite() == 2) y += " of Hearts";
            else y += " of Spades"
            return y;
        }
	void Deck::shuffle() {

	}
};

#endif /* Deck_h */
