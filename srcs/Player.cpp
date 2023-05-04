#include "../includes/Player.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Player::Player()
{
}

Player::Player(int x, int y)
{
	body.w = 10;
	body.h = 10;
	pos.x = x;
	pos.y = y;
	controls.up = 0;
	controls.down = 0;
	controls.left = 0;
	controls.right = 0;
}

Player::Player( const Player & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Player::~Player()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Player &				Player::operator=( Player const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Player const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Player::move(void)
{
    int speed = 9;
    if (rec.move.left && rec.x - speed > 0) { rec.x -= speed; }
    if (rec.move.right && rec.x + speed + 3 < 1000) { rec.x += speed; }
    if (rec.move.up && rec.y - speed > 0) { rec.y -= speed; }
    if (rec.move.down && rec.y + speed + 3 < 1000) { rec.y += speed; }
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */