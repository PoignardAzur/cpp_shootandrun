#ifndef LEVEL_HANDLER_HPP_
#define LEVEL_HANDLER_HPP_

#define WINDOW_WIDTH    300
#define WINDOW_HEIGHT   300
#define WINDOW_TITLE    "Awesome turn-based game"

#define TILE_SIZE 10

#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include "Tilemap.hpp"
#include "Unit.hpp"

enum class TileId : int
{
    FLAT, FOREST, WATER
};

class LevelHandler
{
public:
    LevelHandler();

    void    draw(sf::RenderTarget& target) const;
    void    update();
    bool    isDone() const;

    void    keyPressed(const char* eventName, bool firstPress);
    void    keyPressed(const std::string& eventName, bool firstPress);
    void    keyReleased(const char* eventName);
    void    keyReleased(const std::string& eventName);
    void    moveMouse(const sf::Vector2f& nPos, const sf::Vector2f& dPos);
    void    closeWindow();

private:
    void    drawTile(sf::RenderTarget& target, size_t x, size_t y) const;
    void    drawUnit(sf::RenderTarget& target, const Unit& unit) const;
    bool    isInTransition() const;

    Tilemap<TileId>         m_map;
    std::list<Unit::UPtr>   m_units;

    Unit*       m_hoveredUnit = nullptr;
    Unit*       m_selectedUnit = nullptr;
    Unit*       m_targetUnit = nullptr;

    bool    m_isDone = false;
};

#endif // !LEVEL_HANDLER_HPP_
