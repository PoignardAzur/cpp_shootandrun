#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <stdexcept>
#include <vector>
#include <SFML/Graphics.hpp>

template <typename TileType>
class Tilemap
{
public:
    Tilemap();
    Tilemap(size_t width, size_t height, TileType defTile = TileType());

    void        resize(size_t width, size_t height, TileType defTile = TileType());
    TileType    getTile(size_t x, size_t y) const;
    void        setTile(size_t x, size_t y, TileType tile);

    size_t  getWidth() const;
    size_t  getHeight() const;
    sf::Vector2<size_t> getSize() const;

private:
    std::vector<TileType>   m_array;
    size_t                  m_width;
    size_t                  m_height;

};

template <typename TileType>
Tilemap<TileType>::Tilemap()
{
    m_width = 0;
    m_height = 0;
}

template <typename TileType>
Tilemap<TileType>::Tilemap(size_t width, size_t height, TileType defTile)
{
    m_width = 0;
    m_height = 0;
    resize(width, height, defTile);
}

template <typename TileType>
void        Tilemap<TileType>::resize(size_t width, size_t height, TileType defTile)
{
    std::vector<TileType> newArray(width * height);

    for (size_t x = 0; x < width; ++x)
    {
        for (size_t y = 0; y < height; ++y)
        {
            TileType  tile;

            if (x >= m_width || y >= m_height)
                tile = defTile;
            else
                tile = getTile(x, y);
            newArray[y * width + x] = tile;
        }
    }
    m_array = std::move(newArray);
    m_width = width;
    m_height = height;
}

template <typename TileType>
TileType  Tilemap<TileType>::getTile(size_t x, size_t y) const
{
    if (x >= m_width || y >= m_height)
        throw std::out_of_range("Trying to access out of range tile");
    return m_array[y * m_width + x];
}

template <typename TileType>
void    Tilemap<TileType>::setTile(size_t x, size_t y, TileType tile)
{
    if (x >= m_width || y >= m_height)
        throw std::out_of_range("Trying to access out of range tile");
    m_array[y * m_width + x] = tile;
}

template <typename TileType>
size_t      Tilemap<TileType>::getWidth() const
{
    return m_width;
}

template <typename TileType>
size_t      Tilemap<TileType>::getHeight() const
{
    return m_height;
}

template <typename TileType>
sf::Vector2<size_t>     Tilemap<TileType>::getSize() const
{
    return sf::Vector2<size_t>(m_width, m_height);
}

#endif // !TILEMAP_HPP_
