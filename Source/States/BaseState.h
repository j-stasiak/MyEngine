#ifndef BASE_STATE_H
#define BASE_STATE_H

#include <SFML/Graphics.hpp>
#include "../Utility/NonCopyable.h"
#include "../Utility/NonMovable.h"

class Game;

/*!
	@class BaseState

	This class representates base state in game. States will be:
	-PlayingState
	-MenuState
	-OptionsState
	-CreditsState

	Besides state system, you can aswell use event driven system 

	@see EventSystem
*/
class BaseState
{
public:
	///
	/// Default constructor
	///
	BaseState(Game &game) :
		game(&game)
	{}

	///
	/// Default destructor
	///
	virtual ~BaseState() = default;

	virtual void handleEvent(sf::Event ev) = 0;
	virtual void handleInput() = 0;
	virtual void fixedUpdate(sf::Time dt) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void render(sf::RenderTarget &target) = 0;

protected:
	Game *game;
};

#endif //BASE_STATE_H