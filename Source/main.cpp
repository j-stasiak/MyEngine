#include <SFML/Graphics.hpp>
#include "Game/Game.h"
#include "Utility/Log/Log.h"
#include <GL/glew.h>

///
/// Project: D.O.F.F
/// Defend our fucking future
///

int main(void)
{
	CLEAR_LOG; // Aby oczyœciæ plik logów po ostatnim u¿yciu.
	LOG("Program started...");

	Game game;
	game.runMainLoop();

	LOG("Program ended...");
	return 0;
}