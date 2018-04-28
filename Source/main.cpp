#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "Utility/Log/Log.h"
#include <GL/glew.h>

#include "Utility/TxtParser/TxtParser.h"

///
/// Project: D.O.F.F
/// Defend our fucking future
///

int main(void)
{
	CLEAR_LOG; // Aby oczyœciæ plik logów po ostatnim u¿yciu.
	LOG("Program started...");

	TxtParser parser{ "res/settings/settings.txt" };

	int value = parser.getProperty<int>("WINDOW", "width");

	LOG_DEBUG(std::to_string(value));

	/*
	Game game;
	game.runMainLoop();
	*/
	LOG("Program ended...");
	std::system("pause>nul");
	return 0;
}