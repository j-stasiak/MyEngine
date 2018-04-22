#ifndef SIMPLEBUTTON_H
#define SIMPLEBUTTON_H

#include <SFML\Graphics.hpp>
#include "../../ResourceManager/ResourceManager.h"
#include "../Widget/Widget.h"

/*!
	@class SimpleButton

	Class represents clickable buttons with four states:
	-Up
	-Pressed
	-Hovered (highlighted)
	-Disabled (not really clickable)
*/
class SimpleButton : public Widget
{
public:
	enum class ButtonWidth {
		SHORT,
		WIDE
	};
	///
	/// Default constructor
	///
	SimpleButton(SimpleButton::ButtonWidth wid = SimpleButton::ButtonWidth::SHORT);

	///
	/// Parametered constructor
	///
	SimpleButton(const std::string &text);


	///
	/// Copy constructor
	///
	SimpleButton(const SimpleButton& simple_button);

	///
	/// Move constructor
	///
	SimpleButton(SimpleButton&& simple_button);

	///
	/// Default destructor
	///
	~SimpleButton();

	///
	/// Sets behaviour of given widget. 
	///
	void setFunction(const std::function<void()> &func);

	///
	/// Sets text on button
	///
	void setText(const std::string &str);

	///
	/// Handles given event
	///
	void handleEvent(sf::Event ev, const sf::RenderWindow &window) override;

	///
	/// Renders widget on given target.
	///
	void render(sf::RenderTarget &target) override;

	///
	/// Sets position of a button.
	///
	void setPosition(const sf::Vector2f &pos) override;

	///
	/// Returns size of a button
	///
	sf::Vector2f getSize() const override;

private:	
	Text						buttonText;
	Rectangle					rect;
	std::vector<sf::Texture>	textures;
	std::function<void()>		func;
	sf::Sound					buttonHover;
	sf::Sound					buttonPressed;
	bool 						soundPlayable;
};

#endif //SIMPLEBUTTON_H