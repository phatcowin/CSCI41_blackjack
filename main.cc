//#include <cassert>
#include <iostream>
#include <Player.h>
#include <Deck.h>
using namespace std;

int main() {
	string input;
	vector<Player> players;
	int play_num = 0;
	cout << "BLACK JACK\N";
	cout << "Please enter the number of players: " << endl;
	cin >> play_num;

	//create a vector of players that we can traverse to simulate turns
	//when a player loses, cashes out/quits, or breaks the bank, they can then be removed from the vector
	for(int i = 0; i < play_num; i++){
		players.push_back();
	}
}
