#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"

using namespace std;

class Player {
	private:
		vector<string> hand;
		int hand_sum;
		bool human;
	public:
		// Constructors:
		Player(bool x);
		// Accessors:
		void get_hand();
		int total();
		bool busted();
		// Mutators:
		void draw(string x);
};

// Implementations:
Player::Player(bool x) { // Make a player
	human = x; // Set whether the player is a human or bot
}
void Player::get_hand() {
	for (int i(0); i < hand.size(); i++) { // For every item in the player's hand
		cout << hand.at(i) << "\n"; // Output the item
	}
}
int Player::total() {
	hand_sum = 0;
	int aces(0);
	for (int i(0); i < hand.size(); i++) { // For every item in the player's hand...
		if (hand.at(i)[0] == "A") { // If it's an ace, add 1 to the ace count and the hand sum
			hand_sum++;
			aces++;
		}  
		else if (hand.at(i)[0] == "J" || hand.at(i)[0] == "Q" || hand.at(i)[0] == "K" || hand.at(i)[0] == "1") hand_sum += 10; // If it's a face card or ten, add 10
		else hand_sum += to_int(hand.at(i)[0])
	}
	while (aces > 0 && hand_sum < 12) { // Change the value of as many aces as possible to 11
		hand_sum += 10;
		aces--;
	}
	return hand_sum;
bool Player::busted() {
	if (hand_sum > 21) return true;
	else return false;
}
void draw(string x) {
	hand.push_back(x);
}
