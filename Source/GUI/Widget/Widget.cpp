#include "Widget.h"



Widget::Text::Text()
{
	setCharacterSize(40);
	setOutlineColor(sf::Color::Black);
	setFillColor(sf::Color::White);
	setFont(ResourceManager::getInstance().fonts.get("destructobeambb_reg"));
}



//Rectangle
bool Widget::Rectangle::isHovered(const sf::RenderWindow& window) const
{
	auto pos = sf::Mouse::getPosition(window);
	return getGlobalBounds().contains(pos.x, pos.y);
}

bool Widget::Rectangle::isClicked(sf::Event e, const sf::RenderWindow& window)
{
	if (isHovered(window))
	{
		if (e.type == sf::Event::MouseButtonPressed)
		{
			return e.mouseButton.button == sf::Mouse::Left;
		}
	}
	return false;
}

Widget::Widget()
{
}

Widget::~Widget()
{
}
