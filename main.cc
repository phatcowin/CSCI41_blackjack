//#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Deck.h"
using namespace std;

int main() {
	string input;
	vector<Player> players;
	int play_num = 0;
	cout << "BLACK JACK\n";
	cout << "Please enter the number of players: " << endl;
	cin >> play_num;

	//create a vector of players that we can traverse to simulate turns
	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 0; i < play_num; i++){
		players.push_back(true);
	}
	
}

/*
LIST OF AVAILABLE FUNCTIONS FROM HEADERS:
class Card:
	string get_face();
		Example outputs: "Ace" "Queen" "2"
	string get_suit();
		Example outputs: "Clubs" "Hearts"
*** functions from Card should not be needed for main.cc ***

class Deck:
	Deck();
		Purpose: creates a shuffled deck
	string deal();
		Purpose: draws a card from the top of the deck and returns the card as a string
		Example outputs: "Queen of Spades" "4 of Diamonds"
	void shuffle();
		Purpose: shuffles a new deck

class Player:
	Player(bool x);
		Purpose: generates a new player. If the player is a human, x = true. If the player is a bot, x = false.
	void get_hand();
		Purpose: couts all items in a player's hand
		Example output:
			3 of Hearts
			Ace of Spades
			7 of Clubs
	int total();
		Purpose: returns the value of the sum of the cards in a player's hand (aces adjusted automatically) as an int
		Example output: 6 21 26 9
	bool busted();
		Purpose: returns true if the player's hand's total exceeds 21, else return false
	void draw(string x);
		Purpose: adds string x to the player's hand
		Suggestion: draw(deck.deal()); should draw a card and add it directly to the player's hand
*/
