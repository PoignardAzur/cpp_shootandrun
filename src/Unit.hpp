#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <memory>

using sf_Vector2sz = sf::Vector2<size_t>;

struct Unit
{
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
