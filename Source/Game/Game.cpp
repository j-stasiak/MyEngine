#include "Game.h"
#include "../Utility/Log/Log.h"
#include "../Utility/TxtParser/TxtParser.h"

#include <GL/glew.h>
#include <iostream>

Game::Game() :
	window					(),
	event					(),
	clock					()
	//m_map					(),
	//event_context			(),
	//event_context_manager	()

{
	sf::ContextSettings settings;
	TxtParser txtParser{ "res/settings/settings.txt" };

	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;
	
	unsigned int width = txtParser.getProperty<unsigned int>("window", "width");
	unsigned int height = txtParser.getProperty<unsigned int>("window", "height");
	std::string title = txtParser.getProperty<std::string>("window", "title");
	

	window.create(sf::VideoMode{ width, height }, title, sf::Style::Default, settings);

	glewExperimental = true;

	if (glewInit() ==  GLEW_OK)
	{
		LOG_DEBUG("Glew initialized...");
	}
	else
	{
		LOG_ERROR("Glew failed to initialize!");
	}

	LOG_DEBUG("Game object created...");

	addState<MenuState>(*this);
}


Game::~Game()
{
	LOG_DEBUG("Game object is destroyed");
}

void Game::runMainLoop()
{
	float accumulator = 0.f;

	while (window.isOpen() && !states.empty())
	{
		accumulator += clock.restart().asSeconds();
		auto& currentState = getCurrentState();


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				currentState.handleEvent(event);
				break;
			}
		}

		if (accumulator >= float(1 / MAX_FPS))
		{
			currentState.fixedUpdate(sf::Time());
			accumulator = 0.f;
		}

		render();
	}
}

sf::RenderWindow & Game::getWindow()
{
	return window;
}

void Game::deleteCurrentState()
{
	if (!states.empty())
	{
		states.pop_back();
	}
}

BaseState & Game::getCurrentState()
{
	return *states.back();
}

void Game::handleEvents(const sf::Event & event)
{
	//event_context_manager.getActiveEventContext().update(event);
	getCurrentState().handleEvent(event);
}

void Game::update(const float &dt)
{
	getCurrentState().fixedUpdate(sf::Time());
}

void Game::render()
{	
	window.clear(sf::Color::White);
	getCurrentState().render(window);
	window.display();
}
