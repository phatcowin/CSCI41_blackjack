//#include <cassert>
#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <vectors>
using namespace std;

int main() {
	string input;
	Player p1;
	string card;
	vector<Player> players;
	int play_num = 0;
	cout << "=====================================================\n"
    << " ____  _        _    ____ _  __   _   _    ____ _  __\n"
    << "| __ )| |      / \\  / ___| |/ /  | | / \\  / ___| |/ /\n"
    << "|  _ \\| |     / _ \\| |   | ' /_  | |/ _ \\| |   | ' /\n"
    << "| |_) | |___ / ___ \\ |___| . \\ |_| / ___ \\ |___| . \\\n"
    << "|____/|_____/_/   \\_\\____|_|\\_\\___/_/   \\_\\____|_|\\_\\\n\n"
    << "=====================================================\n\n"
	<< "Please enter the number of players: " << endl;
	cin >> play_num;
	//create the deck
	Deck();
	//create a vector that stores the players' money
	vector<int> cash;
	vector<int> players_bid;

	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 0; i < play_num+1; i++){ //player 0 will be the dealer
		players.push_back(p1);
		cash.push_back(100);
		players_bids.push_back(0);
	}
	//deal cards to the players
	for(int i = 1; i < players.size(); i++) {
		card = deal();
		players.at(i).hand.push_back(card);
		card = deal();
		players.at(i).hand.push_back(card);
		cout << "PLAYER " << i << "'s cards: ";
		players.at(i).get_hand(); //cout cards using function inside class
	}

	int turn = 1;
	int bid = 0;
	while(true){
		int total = 0;
		cout << "PLAYER " << turn << "'s turn\n";
		cout << "PLAY or QUIT?\n";
		cin >> input;
		if(input == "PLAY") {
			while(true) {
				cout << "Make you're bid\n";
				cin >> bid;
				if(!cin) {
					cout << "BAD INPUT\n";
					continue;
				}
				else if(bid > cash.at(i)) {
					cout << "You don't have that much money\n";
					continue;
				}
				else if(bid <= 0) {
					cout << "You can't bid less than $1\n";
					continue;
				}
				else players_bid.at(i) = bid;
				break;
			}
			while(true) {
				cout << "HIT or STAY?\n";
				cin >> input;
				if(input == "HIT") {
					card = deal();
					players.at(i).deck.push_back(card);
				}
				else if (input == "STAY") break;
				else {
					cout << "BAD INPUT\N";
					continue;
				}
			}
		}
	}
	for(int i = 1; i < play_num+1; i++) {
		int total = 0;
		cout << "PLAYER " << i << "'s turn\n";
		cout << "HIT, STAY, or QUIT\n";
		cin >> input;
		if(/*hit*/) {
			players.at(i).push_back(draw());
		}
		if(/*quit*/) {
		}
		if(players.at(i).busted
	}
	//dealer draws here
	//win lose <$5 or $1000>
	
}
