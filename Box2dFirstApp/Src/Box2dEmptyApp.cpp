#include "Game.h"
#include <tchar.h>

using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Game* Juego;
	Juego = new Game(800, 600, "Esqueleto de Aplicaci�n - MAVII");
	Juego->Loop();

	return 0;
}