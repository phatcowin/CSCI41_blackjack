//#include <cassert>
//#pragma once
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <string>
using namespace std;

void add_bot(string name) {
	Player(false, name) bot;
	players.push_back(bot);
}

void add_bots(vector<Player> *players, int play_num) { // Feed the function &players and play_num and it will fill the remaining 
	int bot_num(6 - play_num);
	vector<string> bots[5] {"Hera", "Icarus", "Dionysus", "Demeter", "Echo"};
	for (int  x(0); x < bots.size(); x++) {
		bool bot_exists(false);
		for (int y(0); y < players.size(); y++) if (players.at(y).get_name() == bots.at(x)) bot_exists = true;
		if (bot_exists == true) bots.at(x) = "";
	}
	for (int x(0); x < bot_num; x++) {
		srand(time(NULL));
		int rng(rand() % 5);
		if (bots.at(rng) != "") add_bot(bots.at(rng));
	}
}

int bot_bet(vector<Player> *players, int i) { // Will output a given bot's bet as an integer. Needs &players and the i value of the for loop
	double temp;
    if (name == "Hera") {
		temp = players.at(i).get_money() * 0.5; // Hera bets half her deck
		return static_cast<int>(temp);

    } else if (name == "Icarus") { // Icarus bets 80% of his deck
   		temp = players.at(i).get_money() * 0.8;
		return static_cast<int>(temp);

    } else if (name == "Dionysus") { // Dionysus bets on RNG
		srand(time(NULL));
		temp = rand % players.at(i).get_money();
		return static_cast<int> (temp);

    } else if (name == "Echo") { // Echo copies the previous bet
        return players.at(i - 1).get_bet();

    } else if (name == "Demeter") {
		temp = players.at(i).get_money() * 0.4; // Demeter bets conservatively
		return static_cast<int>(temp);

    } else return "";
}

string bot_turn(vector<Player> *players, int i, string input) {
    if (players.at(i).get_name() == "Hera") { // Hera hits until her hand is 17 or higher
		if (players.at(i).total() < 17) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Icarus") { // Icarus hits until his hand is 19 or higher
		if (players.at(i).total() < 19) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Dionysus") { // Dionysus hits/stands on rng
		srand(time(NULL));
		bool rng(rand() % 2 - 1);
		if (rng == 0) return "HIT";
		else return "STAND";

    } else if (players.at(i).get_name() == "Echo") { // Echo copies the previous player's turn
		return input; 

    } else if (players.at(i).get_name() == "Demeter") { // Demeter bets until she has 4 cards in her hand
		if (players.at.(i).hand_size() < 4) return "BET";
		else return "STAND";

    } else return "Error: bot_turn() did not recognize the player name.";
}

void uppercasify(string &x) {
	for(size_t i = 0; i < x.size(); i++) {
		x.at(i) = toupper(x.at(i));
	}
}

int main() {
	string input;
//	Player p1; //Problem 1
	string card;
	vector<Player> players;
	int play_num = 0;
	cout << "BLACK JACK\n";
	while(true){
		cout << "Please enter the number of players: " << endl;
		cin >> play_num;
		if(!cin || play_num < 1){
			cout << "Please enter a valid number of players (at least 1)\n";
			continue;
		}
		else break;
	}

	//create the deck
	Deck();

	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 0; i < play_num+1; i++){ //player 0 will be the dealer
		players.push_back(Player(true, "Name"));
	}

	//deal cards to the players
	for(int i = 1; i < players.size(); i++) {
		card = deal();
		players.at(i).draw(card);
		card = deal();
		players.at(i).draw(card);
		cout << "PLAYER " << i << "'s cards: \n";
		players.at(i).get_hand();
	}

	int turn = 1;
	int bid = 0;
	while(true) {
	//show one of dealers cards
	cout << "Dealer's shown card:\n";
	cout << players.at(0).get_hand(0) << endl;
	//players' turns
	while(true) {
		int total = 0;
		cout << "PLAYER " << turn << "'s turn\n";
		cout << "PLAY or QUIT?\n";
		cin >> input;
		uppercasify(input);
		if(input == "PLAY") {
			while(true) {
				cout << "Make your bid\n";
				cin >> bid; 
				if(!cin) {
					cout << "BAD INPUT\n";
					continue;
				}
				else if(bid > players.at(turn).get_money()) {
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
					card = deal();
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
			for(int i = turn; i < players.size()-1; i++) {
				players.at(i) = players.at(i+1);
			}
			players.pop_back();
		}
		else {
			cout << "BAD INPUT\n";
			continue;
		}
		if(turn == players.size()) break;
		else turn++;
	}
	//dealer's turn
	cout << "Dealer's turn\n";
	cout << "Dealer's cards:\n";
	players.at(0).get_hand();
	//Put if dealer BLACKJACKS here
	if(players.at(0).total() == 21) {
		cout << "Dealer Blackjacks!\n";
		for(int i = 1; i < players.size(); i++) {
			cout << "Player " << i << " lost $" << players.at(i).get_bet() << "!\n";
			players.at(i).set_money((players.at(i).get_bet() * -1));
			cout << "Player  " << i << " is currently at $" << players.at(i).get_money() << ".\n";
		}
	}
	while(players.at(0).total() < 17) {
		card = deal();
		players.at(0).draw(card);
		cout << "Dealer drew! Dealers new hand:\n";
		players.at(0).get_hand();
	}
	//Dealer busts
	if(players.at(0).total() > 21) {
		cout << "Dealer busted!" << endl;
		for(int i = 1; i < players.size(); i++) {
			if(players.at(i).total() < 22) {
				players.at(i).set_money(players.at(i).get_bet());
			}
		}
	}
	//calculating winners (no money awarded or taken during tie)
	for(int i = 1; i < players.size(); i++) {
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
	for(int i = 1; i < players.size(); i++) {
		if(players.at(i).get_money() < 5) {
			cout << "Player " << i << " has less than $5. Player " << i << " loses.\n";
			for(int j = i; j < players.size() - 1; j++) {
				players.at(j) = players.at(j+1);
			}
			players.pop_back();
		}
		if(players.at(i).get_money() > 1000) {
			cout << "Player " << i << " has more than $1000! Player " << i << " Wins!\n";
			return 0;
		}
	}	
	}
}



