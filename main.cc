//#include <cassert>
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include <vector>
using namespace std;

string uppercasify(string &x) {
	for(char c : &x) {
		toupper(c);
	}
}

int main() {
	string input;
	Player p1; //Problem 1
	string card;
	vector<Player> players;
	int play_num = 0;
	cout << "BLACK JACK\n";
	while(true){
		cout << "Please enter the number of players: " << endl;
		cin >> play_num;
		if(!cin){
			cout << "Please enter a valid number of players (at least 1)\n";
			continue;
		}
		else break;
	}

	//create the deck
	Deck();

	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 1; i < play_num+1; i++){ //player 0 will be the dealer
		
	}
	//deal cards to the players
	for(int i = 1; i < players.size(); i++) {
		card = deal();
		players.at(i).draw(card);
		card = deal();
		players.at(i).draw(card);
		cout << "PLAYER " << i << "'s cards: ";
		players.at(i).get_hand();
	}

	int turn = 1;
	int bid = 0;
	while(true) {
		//show one of dealers cards
		cout << "Dealer's shown card:\n";
		cout << players.at(0).get_hand(0) << endl;
		//players' turns
	while(true){
		int total = 0;
		cout << "PLAYER " << turn << "'s turn\n";
		cout << "PLAY or QUIT?\n";
		cin >> input;
		input = uppercasify(input);
		if(input == "PLAY") {
			while(true) {
				cout << "Make your bid\n";
				cin >> bid; 
				if(!cin) {
					cout << "BAD INPUT\n";
					continue;
				}
				else if(bid > players.at(turn).get_money) {
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
				input = uppercasify(input);
				if(input == "HIT") {
					card = deal();
					players.at(i).hand.push_back(card);
					players.at(i).get_hand();
					players.at(i).total();
					if(players.at(i).busted()) {
						cout << "BUSTED\n" << "Player " << turn << " lost $" << players.at(i).get_bet() << "!" << endl;
						players.at(i).set_money((players.at(i).get_bet() * -1));
						cout << "Player  " << i << " is currently at $" << players.at(i).get_money() << ".\n";
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
		players.at(0).hand.push_back(card);
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
