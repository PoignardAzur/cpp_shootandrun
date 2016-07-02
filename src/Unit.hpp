#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <memory>

using sf_Vector2sz = sf::Vector2<size_t>;

class Unit
{
	public:
		sf_Vector2sz get_pos();
		int get_team();
		int get_move ();
		int get_life ();
		int get_range();
		int get_firepower ();
		int get_max_life();
		int get_max_move();
		int get_animLength();
		bool isDead();
		bool isInTransition();
		void move();
		void attack();
		void takeDamage(int);
		void update();
	private:
		sf_Vector2sz     pos;

		int     team;
		int     speed;
		int     move;
		int     max_life;
		int     life;
		int     range;
		int     firepower;

		using UPtr = std::unique_ptr<Unit>;

		bool isInTransition() { return false; }
};

#endif // !UNIT_HPP_
