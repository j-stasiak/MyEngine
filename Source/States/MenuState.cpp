#include "MenuState.h"

#include "../Game/Game.h"
#include "../Utility/Log/Log.h"
#include "OptionsState.h"
#include "PlayingState.h"

MenuState::MenuState(Game &game) :
	BaseState(game),
	menu(),
	bgMusic(ResourceManager::getInstance().soundBuffers.get("are_we_alone")),
	texture(ResourceManager::getInstance().images.get("menu_background"))
{
	background.setTexture(texture);

	menu.setPostion({float(game.getWindow().getSize().x / 2), 
		float(game.getWindow().getSize().y / 2) });

	auto play = std::make_unique<SimpleButton>(SimpleButton::ButtonWidth::WIDE);
	play->setFunction([&]() {
		bgMusic.stop();
		game.addState<PlayingState>(game);
	});
	play->setText("Play");

	auto opts = std::make_unique<SimpleButton>(SimpleButton::ButtonWidth::WIDE);
	opts->setFunction([]() {
		LOG("Options button pressed!");
	});
	opts->setText("Options");

	auto credits = std::make_unique<SimpleButton>(SimpleButton::ButtonWidth::WIDE);
	credits->setFunction([]() {
		LOG("Credits button pressed!");
	});
	credits->setText("Credits");

	auto exit = std::make_unique<SimpleButton>(SimpleButton::ButtonWidth::WIDE);
	exit->setFunction([&game]() {
		game.getWindow().close();
	});
	exit->setText("Exit");


	menu.addWidget(std::move(play));
	menu.addWidget(std::move(opts));
	menu.addWidget(std::move(credits));
	menu.addWidget(std::move(exit));

	bgMusic.play();
	bgMusic.setLoop(true);
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
