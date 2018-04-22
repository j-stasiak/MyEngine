#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

/*!
	@enum_class TileType

	Constains possible types of tile.
*/
enum class TileType {
	GROUND,
	PATH,
	TURN,
	CROSS
};

constexpr unsigned int TILE_SIZE = 64;

/*!
	@class Tile

	Class represents one tile of a map.
*/
class Tile
{
public:
	///
	/// Default constructor
	///
	Tile(const sf::Vector2f &size);

	///
	/// Default destructor
	///
	~Tile();

	///
	/// Sets type of tile
	///
	/// @see TileType
	///
	void setType(TileType type);

	///
	/// Sets texture for tile
	///
	void setTexture(const sf::Texture &text);

	///
	/// Sets position of tile
	///
	void setPosition(const sf::Vector2f &pos);

	///
	/// Returns position of tile
	///
	sf::Vector2f getPosition() const;

	///
	/// Returns size of tile
	///
	sf::Vector2f getSize() const;

	///
	/// Renders tile on target
	///
	void render(sf::RenderTarget &target);

private:
	sf::Texture			texture;
	sf::RectangleShape	tileRect;
	TileType			type;
};

#endif //TILE_H