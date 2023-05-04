#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <string>
# include "smash.hpp"

class Player
{

	public:

		Player();
		Player(int x, int y);
		Player( Player const & src );
		~Player();

		Player &		operator=( Player const & rhs );

		void			move();

	private:
		t_rect	body;
		t_move	controls;
		t_pos	pos;

};

std::ostream &			operator<<( std::ostream & o, Player const & i );

#endif /* ********************************************************** PLAYER_H */