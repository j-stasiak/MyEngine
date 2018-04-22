#include "Menu.h"



Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::addWidget(std::unique_ptr<Widget> widget)
{
	widget->setPosition({ menuPosition.x - widget->getSize().x / 2 + newWidgetPosition.x, 
						 menuPosition.y / 2 - widget->getSize().y + newWidgetPosition.y});

	newWidgetPosition.y += widget->getSize().y + 25;
	menuSize.y += widget->getSize().y + 25;

	widgets.push_back(std::move(widget));
	background.setSize(menuSize);
}

void Menu::handleEvent(sf::Event e, const sf::RenderWindow & window)
{
	for (auto &widget : widgets)
	{
		widget->handleEvent(e, window);
	}
}

void Menu::setPostion(const sf::Vector2f & vec)
{
	menuPosition = vec;
}

void Menu::render(sf::RenderTarget & target)
{
	target.draw(background);
	for (auto & widget : widgets)
	{
		widget->render(target);
	}
}
