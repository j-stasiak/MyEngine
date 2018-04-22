#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::addTile(std::unique_ptr<Tile> tile)
{
	tiles.push_back(std::move(tile));
}

void Map::render(sf::RenderTarget & target)
{
	for (auto &tile : tiles)
	{
		tile->render(target);
	}
}
