#include "MenuState.h"

#include "../Game/Game.h"
#include "../Utility/Log/Log.h"
#include "OptionsState.h"
#include "PlayingState.h"
#include "../GUI/Buttons/ButtonFactory.h"


MenuState::MenuState(Game &game) :
	BaseState(game),
	menu(),
	//bgMusic(ResourceManager::getInstance().soundBuffers.get("are_we_alone")),
	texture(ResourceManager::getInstance().images.get("menu_background"))
{
	background.setTexture(texture);

	menu.setPostion({ float(game.getWindow().getSize().x / 2),
		float(game.getWindow().getSize().y / 2) });

	auto play = ButtonFactory::createButton([&]() {
		bgMusic.stop();
		game.addState<PlayingState>(game);
	}, "Play");

	auto opts = ButtonFactory::createButton([&]() {
		LOG("Options button pressed!");
	}, "Options");

	auto credits = ButtonFactory::createButton([&]() {
		LOG("Credits button pressed!");
	}, "Credits");

	auto exit = ButtonFactory::createButton([&]() {
		game.getWindow().close();
	}, "Exit");


	menu.addWidget(std::move(play));
	menu.addWidget(std::move(opts));
	menu.addWidget(std::move(credits));
	menu.addWidget(std::move(exit));

	//bgMusic.play();
	//bgMusic.setLoop(true);
}


MenuState::~MenuState()
{
}

void MenuState::handleEvent(sf::Event ev)
{
	menu.handleEvent(ev, game->getWindow());
}

void MenuState::handleInput()
{
}

void MenuState::fixedUpdate(sf::Time dt)
{
}

void MenuState::update(sf::Time dt)
{
}

void MenuState::render(sf::RenderTarget & target)
{
	target.draw(background);
	menu.render(target);
}
