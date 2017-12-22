#include <windows.h>

#include "game_main.hpp"

int CALLBACK WinMain(
		HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow) {
	game_main();

	return 0;
}
