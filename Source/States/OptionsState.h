#ifndef OPTIONS_STATE_H
#define OPTIONS_STATE_H

#include "BaseState.h"

/*
	
*/
class OptionsState : public BaseState
{
public:
	OptionsState(Game &game);
	~OptionsState();

	void handleEvent(sf::Event ev) override;
	void handleInput() override;
	void fixedUpdate(sf::Time dt) override;
	void update(sf::Time dt) override;
	void render(sf::RenderTarget &target) override;
};

#endif //OPTIONS_STATE_H