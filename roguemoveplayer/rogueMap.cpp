#include "rogueMap.h"

RogueMap::RogueMap() {
	mapHeight = 0;
	mapWidth = 0;

	map = nullptr;
}

RogueMap::~RogueMap() {
	delete[] map;
}

void RogueMap::loadmap(int height, int width) {
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	utility::showConsoleCursor(false);

	mapHeight = height;
	mapWidth = width;

	// Allocating memory for the map.
	map = new char[mapHeight * mapWidth];

	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) 
		{
			if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
				map[y * mapWidth + y] = ' # ';
			}
			else {
				map[y * mapWidth + y] = ' ';
			}
		}
	}
	printmap();
}

char RogueMap::getXY(int x, int y) {
	return ' ';
}

bool RogueMap::setXY(int x, int  y, char value) {
	return false;
}

void RogueMap::printmap() {
	utility::gotoScreenPosition(0, 0); {

		for (int y = 0; y < mapHeight; y++)
		{
			for (int x = 0; x < mapWidth; x++)
			{
				std::cout << map[y * mapWidth + y];
			}
			std::cout << std::endl;
		}
	}
}