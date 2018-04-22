#include "Tile.h"



Tile::Tile(const sf::Vector2f &size)
{
	tileRect.setSize(size);
}


Tile::~Tile()
{
}

void Tile::setType(TileType type)
{
	this->type = type;
}

void Tile::setTexture(const sf::Texture & text)
{
	tileRect.setTexture(&text);
}

void Tile::setPosition(const sf::Vector2f & pos)
{
	tileRect.setPosition(pos);
}

sf::Vector2f Tile::getPosition() const
{
	return tileRect.getPosition();
}

sf::Vector2f Tile::getSize() const
{
	return tileRect.getSize();
}

void Tile::render(sf::RenderTarget & target)
{
	target.draw(tileRect);
}
