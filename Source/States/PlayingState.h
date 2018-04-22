#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "BaseState.h"
#include "../Logic/Map/Map.h"
#include "../Events/EventSystem.h"

class PlayingState : public BaseState
{
public:
	///
	/// Default constructor
	///
	PlayingState(Game &game);

	///
	/// Default destructor
	///
	~PlayingState();

	void handleEvent(sf::Event ev) override;
	void handleInput() override;
	void fixedUpdate(sf::Time dt) override;
	void update(sf::Time dt) override;
	void render(sf::RenderTarget &target) override;

private:
	//LevelManager lvlmgr;
	//SoundManager sfxmgr;
	//UnitsManager unmgr;
	Map			 map;
	ActionMap	 actionMap;
	EventContext evctx;
};

#endif PLAYING_STATE_H