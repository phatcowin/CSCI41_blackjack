//#include <cassert>
//#pragma once
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <string>
using namespace std;

void uppercasify(string &x) {
	for(size_t i = 0; i < x.size(); i++) {
		x.at(i) = toupper(x.at(i));
	}
}
/*
void add_bot(string name) {
	players.push_back(Player(false, "name");
}

void add_bots(vector<Player> &players, int play_num) { // Feed the function &players and play_num and it will fill the remaining 
	int bot_num(6 - play_num);
	vector<string> bots[5] {"Hera", "Icarus", "Dionysus", "Demeter", "Echo"};
	for (int  x(0); x < bots.size(); x++) {
		bool bot_exists(false);
		for (int y(0); y < players.size(); y++) if (players.at(y).get_name() == bots.at(x)) bot_exists = true;
		if (bot_exists == true) bots.at(x) = "";
	}
	for (int x(0); x < bot_num; x++) {
		int rng(rand() % 5);
		if (bots.at(rng) != "") add_bot(bots.at(rng));
	}
}

int bot_bet(vector<Player> &players, int i) { // Will output a given bot's bet as an integer. Needs &players and the i value of the for loop
	double temp;
    if (players.at(i).get_name() == "Hera") {
		temp = players.at(i).get_money() * 0.5; // Hera bets half her deck
		return static_cast<int>(temp);

    } else if (players.at(i).get_name() == "Icarus") { // Icarus bets 80% of his deck
   		temp = players.at(i).get_money() * 0.8;
		return static_cast<int>(temp);

    } else if (players.at(i).get_name() == "Dionysus") { // Dionysus bets on RNG
		temp = rand() % players.at(i).get_money();
		return static_cast<int> (temp);

    } else if (players.at(i).get_name() == "Echo") { // Echo copies the previous bet
        return players.at(i - 1).get_bet();

    } else if (players.at(i).get_name() == "Demeter") {
		temp = players.at(i).get_money() * 0.4; // Demeter bets conservatively
		return static_cast<int>(temp);

    } else return 0;
}

string bot_turn(vector<Player> &players, int i, string input) {
    if (players.at(i).get_name() == "Hera") { // Hera hits until her hand is 17 or higher
		if (players.at(i).total() < 17) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Icarus") { // Icarus hits until his hand is 19 or higher
		if (players.at(i).total() < 19) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Dionysus") { // Dionysus hits/stands on rng
		bool rng(rand() % 2 - 1);
		if (rng == 0) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Echo") { // Echo copies the previous player's turn
		return input; 

    } else if (players.at(i).get_name() == "Demeter") { // Demeter bets until she has 4 cards in her hand
		//if (players.at(i).hand.size() < 4) return "BET";
		else return "STAND";

    } else return "Error: bot_turn() did not recognize the player name.";
	return "";
}
*/
int main() {
	srand(time(0));
	string input;
	Player(true, "Name"); 
	string card;
	vector<Player> players;
//	Card(52);
	Deck deck;
	int play_num = 0;
	cout << "BLACK JACK\n";
//	cout << "Dumping out the deck" << endl;
	/*deck.dump();
	return 0;*/
	while(true){
		cout << "Please enter the number of players: " << endl;
		cin >> play_num;
		if(!cin || play_num < 1){
			cout << "Please enter a valid number of players (at least 1)\n";
			continue;
		}
		else break;

	}


	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 0; i < play_num+1; i++){ //player 0 will be the dealer
		players.push_back(Player(true, "Name"));
	}
	
/*	
	while(true) {
		cout << "Please enter the number of bots you would like to play with:\n";
		cin >> play_num;
		if(!cin || play_num < 0) {
			cout << "Please enter a valid number of bot players (zero or more)\n";
		continue;
		}
		else break;
	}
*/
	//deal cards to the players
	for(size_t i = 0; i < players.size(); i++) {
//		cerr << players.size();
		card = deck.deal();
		players.at(i).draw(card);
		card = deck.deal();
		players.at(i).draw(card);
//		players.at(i).draw();
//		players.at(i).draw();
		if(i > 0) {
			cout << "PLAYER " << i << "'s cards: \n";
			players.at(i).get_hand();
		}
	}

	size_t turn = 1;
	int bid = 0;
	string check;
	while(true) {
	//show one of dealers cards
	cout << "Dealer's shown card:\n";
	cout << players.at(0).get_hand(0) << endl;
	//players' turns
	while(true) {
		if(players.size() < 2) break;
		int total = 0;
		cout << "PLAYER " << turn << "'s turn\n";
		cout << "Your hand total is: " << players.at(turn).total() << endl;
		cout << "PLAY or QUIT?\n";
		cin >> input;
		uppercasify(input);
		if(input == "PLAY") {
			while(true) {
				cout << "Make your bid\n";
				cin >> check;
				for(size_t i = 0; i < check.size(); i++) {
					if(!isdigit(check.at(i))) {
						cout << "Please enter a valid number.\n";
						cin >> check;
						i = 0;
					}
				}
				bid = stoi(check);
				if(bid > players.at(turn).get_money()) {
					cout << "You don't have that much money\n";
					continue;
				}
				else if(bid <= 0) {
					cout << "You can't bid less than $1\n";
					continue;
				}
				else players.at(turn).set_bet(bid);
				break;
			}
			while(true) {
				cout << "HIT or STAY?\n";
				cin >> input;
				uppercasify(input);
				if(input == "HIT") {
					card = deck.deal();
					players.at(turn).draw(card);
					players.at(turn).get_hand();
					players.at(turn).total();
					if(players.at(turn).busted()) {
						cout << "BUSTED\n" << "Player " << turn << " lost $" << players.at(turn).get_bet() << "!" << endl;
						players.at(turn).set_money((players.at(turn).get_bet() * -1));
						cout << "Player  " << turn << " is currently at $" << players.at(turn).get_money() << ".\n";
						break;
					}
					else continue;
				}
				else if (input == "STAY") break;
				else {
					cout << "BAD INPUT\n";
					continue;
				}
			}
		}
		else if(input == "QUIT") {
			cout << "Player " << turn << " drops out! Player " << turn << " won $" << players.at(turn).get_money() << endl;
			for(size_t i = turn; i < players.size()-1; i++) {
				if(players.size() == 2) {
					players.pop_back();
					break;
				}
				else players.at(i) = players.at(i+1);
			}
			if(players.size() > 1) players.pop_back();
			else break;
		}
		else {
			cout << "BAD INPUT\n";
			continue;
		}
		if(turn >= players.size() - 1) {
			turn = 1;
			break;
		}
		else turn++;
	}
	//dealer's turn
	if(players.size() < 2) {
		cout << "There are no more players. The House wins!\n";
		return 0;
	}
	cout << "Dealer's turn\n";
	cout << "Dealer's cards:\n";
	players.at(0).get_hand();
	//Put if dealer BLACKJACKS here
	if(players.at(0).total() == 21) {
		cout << "Dealer Blackjacks!\n";
		for(size_t i = 1; i < players.size(); i++) {
			cout << "Player " << i << " lost $" << players.at(i).get_bet() << "!\n";
			players.at(i).set_money((players.at(i).get_bet() * -1));
			cout << "Player  " << i << " is currently at $" << players.at(i).get_money() << ".\n";
		}
	}
	while(players.at(0).total() < 17) {
		card = deck.deal();
		players.at(0).draw(card);
		cout << "Dealer drew! Dealers new hand:\n";
		players.at(0).get_hand();
	}
	//Dealer busts
	if(players.at(0).total() > 21) {
		cout << "Dealer busted!" << endl;
		for(size_t i = 1; i < players.size(); i++) {
			if(players.at(i).total() < 22) {
				players.at(i).set_money(players.at(i).get_bet());
			}
		}
	}
	//calculating winners (no money awarded or taken during tie)
	for(size_t i = 1; i < players.size(); i++) {
		int dealer_total = players.at(0).total();
		int player_total = players.at(i).total();
		if(dealer_total > player_total) {
			//dealer win conditions here
			cout << "Player " << i << " lost $" << players.at(i).get_bet() << "!\n";
			players.at(i).set_money((players.at(i).get_bet() * -1));
			cout << "Player  " << i << " is currently at $" << players.at(i).get_money() << ".\n";
		}
		else if(player_total > dealer_total) {
			//player win conditions here
			cout << "Player " << i << " won $" << players.at(i).get_bet() << "!\n";
			players.at(i).set_money((players.at(i).get_bet() * 1.5));
			cout << "Player  " << i << " is currently at $" << players.at(i).get_money() << ".\n";
		}
		else {
			cout << "Player " << i << " and the Dealer tied! No money won or lost.\n";
			continue;
		}
	}
	//win lose <$5 or $1000
	for(size_t i = 1; i < players.size(); i++) {
		if(players.at(i).get_money() < 5) {
			cout << "Player " << i << " has less than $5. Player " << i << " loses.\n";
			for(size_t j = i; j < players.size() - 1; j++) {
				players.at(j) = players.at(j+1);
			}
			players.pop_back();
		}
		if(players.at(i).get_money() > 1000) {
			cout << "Player " << i << " has more than $1000! Player " << i << " Wins!\n";
			return 0;
		}
	}
	Deck();
	}
}



