#ifndef WIDGET_H
#define WIDGET_H

#include <functional>
#include <SFML/Graphics.hpp>

#include "../../ResourceManager/ResourceManager.h"

// Zmienic na ³adniejszy kod (wywaliæ zagnie¿d¿one klasy)

/*!
	@class Widget

	@desription Base class for every GUI element.
*/
class Widget
{
public:
	///
	/// Default constructor
	///
	Widget();

	///
	/// Default destructor
	///
	virtual ~Widget();

	///
	/// Sets behaviour of given widget. 
	///
	virtual void handleEvent(sf::Event ev, const sf::RenderWindow &window) = 0;

	///
	/// Renders widget on given target.
	///
	virtual void render(sf::RenderTarget &target) = 0;

	///
	/// Sets position of widget
	///
	virtual void setPosition(const sf::Vector2f &pos) = 0;

	///
	/// Returns size of given widget
	///
	virtual sf::Vector2f getSize() const = 0;

protected:
	class Text : public sf::Text
	{
		public:
			Text();
	};

	class Rectangle : public sf::RectangleShape
	{
		public:
			bool isHovered(const sf::RenderWindow& window) const;
			bool isClicked(sf::Event, const sf::RenderWindow& window);
	};
};

#endif //WIDGET_H