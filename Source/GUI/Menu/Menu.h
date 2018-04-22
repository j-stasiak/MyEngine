#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../../Utility/NonCopyable.h"
#include "../Widget/Widget.h"

/*!
	@class Menu

	Class used for every kind of drawable menu (Stack menu etc.).
*/
class Menu : public NonCopyable
{
public:
	///
	/// Default constructor
	///
	Menu();

	///
	/// Default destructor
	///
	~Menu();

	///	
	/// Adds new widget to menu
	///
	void addWidget(std::unique_ptr<Widget> widget);

	///
	/// Handles events 
	///
	void handleEvent(sf::Event e, const sf::RenderWindow &window);

	///
	/// Sets position of menu 
	///
	void setPostion(const sf::Vector2f &vec);

	///
	/// Renders whole menu on screen
	///
	void render(sf::RenderTarget &target);

private:
	std::vector<std::unique_ptr<Widget>> widgets;
	sf::RectangleShape					 background;

	sf::Vector2f						 newWidgetPosition;
	sf::Vector2f						 menuPosition;
	sf::Vector2f						 menuSize;

};
#endif //MENU_H