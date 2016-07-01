#include "LevelHandler.hpp"

int     main()
{
    LevelHandler        level;
    sf::RenderWindow    window;

    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(30);

    while (window.isOpen() && !level.isDone())
    {
        level.update();
        level.draw(window);
        window.display();
    }
    return (0);
}
