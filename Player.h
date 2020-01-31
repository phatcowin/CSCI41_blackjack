#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"

using namespace std;

class Player {
	private:
		vector<string> hand;
		int hand_sum, wallet, bet;
		bool human;
		string name;
	public:
		// Constructors:
		Player(bool x, string y);
		// Accessors:
		bool is_human();
		string get_name();
		string get_hand(int x);
		void get_hand();
		int get_money();
		int get_bet();
		int total();
		bool busted();
		// Mutators:
		void draw(string x);
		void set_money(int x);
		void set_bet(int x);
};

// Implementations:
Player::Player(bool x, string y) {
	human = x; // Set whether the player is a human or bot
	name = y; // Set the player's name
	wallet = 100; // All players start with 100
}
bool Player::is_human() {
	return human;
}
string Player::get_hand(int x) {
	return hand.at(i);
}
void Player::get_hand() {
	for (int i(0); i < hand.size(); i++) {
		cout << get_hand(i) << "\n";
	}
}
string Player::get_name() {
	return name;
}
int Player::get_money() {
	return wallet;
}
int Player::get_bet() {
	return bet;
}
int Player::total() {
	hand_sum = 0;
	int aces(0);
	for (int i(0); i < hand.size(); i++) { // For every item in the player's hand...
		if (to_string(hand.at(i)[0]) == "A") { // If it's an ace, add 1 to the ace count and the hand sum
			hand_sum++;
			aces++;
		}  
		else if (to_string(hand.at(i)[0]) == "J" || to_string(hand.at(i)[0]) == "Q" || to_string(hand.at(i)[0]) == "K" || to_string(hand.at(i)[0]) == "1") hand_sum += 10; // If it's a face card or ten, add 10
		else hand_sum += u_int(hand.at(i)[0]);
	}
	while (aces > 0 && hand_sum < 12) { // Change the value of as many aces as possible to 11
		hand_sum += 10;
		aces--;
	}
	return hand_sum;
}
bool Player::busted() {
	if (hand_sum > 21) return true;
	else return false;
}
void Player::draw(string x) {
	hand.push_back(x);
}
void Player::set_money(int x) {
	wallet += x;
}
void Player::set_bet(int x) {
	bet = x;
}
