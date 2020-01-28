#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>

using namespace std;

class Player {
	private:
		int player_score;
		vector<int> player_hand;
	public:
		// Constructors:
		Player(int x);
		
		// Accessors:
		int get_score();

		// Mutators:
		void draw_card();

		// Implementations:
		Player::Player(int x) {

		}
		int Player::get_score() {

		}
		void Player::draw_card() {

		}
};

#endif /* Player_h */
