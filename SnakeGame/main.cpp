#include <time.h>

#include "Game.h"

int main()
{
	srand(time(static_cast<unsigned>(0)));

	Game game;

	game.run();

	// end of application
	return 0;
}