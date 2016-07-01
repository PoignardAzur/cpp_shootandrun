#include <cstring>
#include "LevelHandler.hpp"

LevelHandler::LevelHandler()
{
    m_map.resize(10, 10);
    for (size_t x = 0; x < m_map.getWidth(); ++x)
        m_map.setTile(x, 3, TileId::FOREST);
}

void    LevelHandler::draw(sf::RenderTarget& target) const
{
    target.clear();

    for (size_t x = 0; x < m_map.getWidth(); ++x)
        for (size_t y = 0; y < m_map.getHeight(); ++y)
            drawTile(target, x, y);

    for (const Unit::UPtr& unit_ptr : m_units)
        drawUnit(target, *unit_ptr);
}

void    LevelHandler::drawTile(sf::RenderTarget& target, size_t x, size_t y) const
{
    TileId  tile = m_map.getTile(x, y);

    sf::RectangleShape  tileSprite(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    sf::Color           color;

    switch (tile)
    {
        case (TileId::FLAT):
            color = sf::Color::White;
            break;
        case (TileId::FOREST):
            color = sf::Color::Green;
            break;
        case (TileId::WATER):
            color = sf::Color::Blue;
            break;
    }

    tileSprite.setFillColor(color);
    tileSprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
    target.draw(tileSprite);
}

void    LevelHandler::drawUnit(sf::RenderTarget& target, const Unit& unit) const
{
    (void)target;
    (void)unit;
}

void    LevelHandler::update()
{

}

bool    LevelHandler::isDone() const
{
    return m_isDone;
}

void    LevelHandler::keyPressed(const char* eventName, bool firstPress)
{
    if (firstPress && !std::strcmp("select", eventName))
    {
        // TODO
        (void)m_hoveredUnit;
    }
}

void    LevelHandler::keyPressed(const std::string& eventName, bool firstPress)
{
    keyPressed(eventName.c_str(), firstPress);
}

void    LevelHandler::keyReleased(const char* eventName)
{
    (void)eventName;
}

void    LevelHandler::keyReleased(const std::string& eventName)
{
    keyReleased(eventName.c_str());
}

void    LevelHandler::moveMouse(const sf::Vector2f& nPos, const sf::Vector2f& dPos)
{
    (void)nPos;
    (void)dPos;
}

void    LevelHandler::closeWindow()
{
    m_isDone = true;
}

bool    LevelHandler::isInTransition() const
{
    return (m_selectedUnit && m_selectedUnit->isInTransition())
    || (m_targetUnit && m_targetUnit->isInTransition());
}
