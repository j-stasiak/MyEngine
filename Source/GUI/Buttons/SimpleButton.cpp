#include "SimpleButton.h"



SimpleButton::SimpleButton(SimpleButton::ButtonWidth width) :
	buttonText(),
	textures({ResourceManager::getInstance().images.get("active_menu_button"), ResourceManager::getInstance().images.get("not_active_menu_button") }),
	rect(),
	buttonHover(ResourceManager::getInstance().soundBuffers.get("menu_button_hover")),
	buttonPressed(ResourceManager::getInstance().soundBuffers.get("menu_button_press")),
	soundPlayable(true)
{
	switch (width)
	{
	case SimpleButton::ButtonWidth::SHORT:
		rect.setSize(sf::Vector2f(200, 100));
		break;
	case SimpleButton::ButtonWidth::WIDE:
		rect.setSize(sf::Vector2f(400, 100));
		break;
	}

	buttonHover.setVolume(30);
	rect.setTexture(&textures.at(1));

	LOG_DEBUG("SimpleButton is created!");
}

SimpleButton::SimpleButton(const std::string & text)
{
	buttonText.setString(text);
}

SimpleButton::SimpleButton(const SimpleButton & simple_button) :
	buttonText(simple_button.buttonText),
	textures(simple_button.textures)
{
}

SimpleButton::SimpleButton(SimpleButton && simple_button) :
	buttonText(std::move(simple_button.buttonText)),
	textures(std::move(simple_button.textures))
{
}


SimpleButton::~SimpleButton()
{
	LOG_DEBUG("SimpleButton is destroyed");
}

void SimpleButton::setFunction(const std::function<void()>& func)
{
	this->func = func;
}

void SimpleButton::setText(const std::string & str)
{
	buttonText.setString(str);
}

void SimpleButton::handleEvent(sf::Event ev, const sf::RenderWindow & window)
{
	if (rect.isHovered(window))
	{
		
		rect.setTexture(&textures.at(0));

		if (soundPlayable && buttonHover.getStatus() != sf::Sound::Playing)
		{
			buttonHover.play();
		}

		soundPlayable = false;

		if (rect.isClicked(ev, window))
		{
			try
			{
				std::invoke(func);
				if (buttonPressed.getStatus() != sf::Sound::Playing) buttonPressed.play();
			}
			catch (const std::bad_function_call &err)
			{
				LOG_ERROR("No such function for SimpleButton. Message: " + std::string(err.what()));
			}
		}
	}
	else
	{
		soundPlayable = true;
		rect.setTexture(&textures.at(1));
	}
}

void SimpleButton::render(sf::RenderTarget & target)
{
	target.draw(rect);
	target.draw(buttonText);
}

void SimpleButton::setPosition(const sf::Vector2f & pos)
{
	rect.setPosition(pos);
	buttonText.setPosition(pos.x + rect.getGlobalBounds().width / 2, 
							pos.y + rect.getGlobalBounds().height / 2);
	buttonText.move(-buttonText.getGlobalBounds().width / 2, -buttonText.getGlobalBounds().height / 2 - 10);
}

sf::Vector2f SimpleButton::getSize() const
{
	return rect.getSize();
}
