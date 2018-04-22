#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "BaseState.h"
#include "../GUI/Menu/Menu.h"
#include "../GUI/Buttons/SimpleButton.h"

/*
	@class MenuState

	Represents main menu of the game. Consists of buttons, music and background.

	@see Menu

*/
class MenuState : public BaseState
{
public:
	///
	/// Default constructor
	///
	MenuState(Game &game);

	///
	/// Default destructor
	///
	~MenuState();

	void handleEvent(sf::Event ev) override;
	void handleInput() override;
	void fixedUpdate(sf::Time dt) override;
	void update(sf::Time dt) override;
	void render(sf::RenderTarget &target) override;

private:
	Menu		menu;
	sf::Sound	bgMusic;
	sf::Texture texture;
	sf::Sprite	background;
};

#endif //MENU_STATE_H