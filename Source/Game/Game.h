#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
//#include "../Events/EventSystem.h"
#include "../States/MenuState.h"

const std::size_t MAX_FPS = 60;

/*!
	@class Game
	
	@brief Class represents hw

	@detail Class starts whole program by running main loop. 
			Renders, updates and polls for events. 
*/
class Game
{
public:

	///
	///Default constructor
	///
	Game();

	///
	///Copy constructor deleted
	///
	Game(const Game&) = delete;

	///
	///Default destructor
	///
	~Game();

	///
	///Starts main loop
	///
	void runMainLoop();

	///
	/// Returns original window
	///
	sf::RenderWindow & getWindow();

	///
	/// Pushes new state to the game
	///
	template<typename T, typename... Args>
	void addState(Args&&... args);

	///
	/// Deletes current state
	///
	void deleteCurrentState();

	///
	/// Returns current state
	///
	BaseState &getCurrentState();

private:
	void handleEvents(const sf::Event &event);
	void update(const float &dt);
	void render();

	sf::RenderWindow		window;
	sf::Event				event;
	sf::Clock				clock;
	//ActionMap				map;
	//EventContext			event_context;
	//EventContextManager		event_context_manager;
	std::vector<std::unique_ptr<BaseState>>  states;
};

template<typename T, typename... Args>
void Game::addState(Args&&... args)
{
	states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}

#endif //GAME_H