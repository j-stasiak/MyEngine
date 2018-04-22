#include "PlayingState.h"
#include "../Game/Game.h"


PlayingState::PlayingState(Game &game) :
	BaseState(game)
{
	LOG_DEBUG("PlayingState is up!");

	actionMap["exit"] = Action{ sf::Keyboard::BackSpace, ActionType::CLICKED };
	actionMap.bind("exit", [&game]() {
		game.addState<MenuState>(game);
	});
	evctx.setActionMap(actionMap);

	int xTiles = game.getWindow().getSize().x / TILE_SIZE;
	int yTiles = game.getWindow().getSize().y / TILE_SIZE;

	for (int x = 0; x <= xTiles; ++x)
	{
		for (int y = 0; y <= yTiles; ++y)
		{
			Tile tile{ {float(TILE_SIZE), float(TILE_SIZE)} };
			tile.setTexture(ResourceManager::getInstance().images.get("tile"));
			tile.setPosition({float(TILE_SIZE * x), float(TILE_SIZE * y)});
			map.addTile(std::make_unique<Tile>(tile));
		}
	}
	
}


PlayingState::~PlayingState()
{
	LOG_DEBUG("PlayingState is destroyed.");
}

void PlayingState::handleEvent(sf::Event ev)
{
	//menu.handleEvent(ev, game->getWindow());
	evctx.update(ev);
}

void PlayingState::handleInput()
{
}

void PlayingState::fixedUpdate(sf::Time dt)
{
}

void PlayingState::update(sf::Time dt)
{
}

void PlayingState::render(sf::RenderTarget & target)
{
	map.render(target);
}