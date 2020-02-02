//#include <cassert>
#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <vectors>
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
				cout << "Make your bid\n";
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
			players.at(i).draw(deal());
		}
		if(/*quit*/) {
		}
		if(players.at(i).busted
	}
	//dealer draws here
	//win lose <$5 or $1000>
	
}
