#ifndef MAP_H
#define MAP_H

#include "../Tile/Tile.h"
#include <memory>

/*!
	@class Map

	Represents whole map on a level. Basicly bunch of tiles.
*/
class Map
{
public:
	///
	/// Default constructor
	///	
	Map();

	///
	/// Default destructor
	///
	~Map();

	///
	/// Adds tile to a tiles vector
	///
	void addTile(std::unique_ptr<Tile> tile);

	///
	/// Renders tiles on target
	///
	void render(sf::RenderTarget &target);

private:
	std::vector<std::unique_ptr<Tile>>	tiles;
};

#endif //MAP_H