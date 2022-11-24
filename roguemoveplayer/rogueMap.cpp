#include "rogueMap.h"
#include <fstream>

RogueMap::RogueMap() {
	mapHeight = 0;
	mapWidth = 0;

	map = nullptr;
}

RogueMap::~RogueMap() {
	delete[] map;
}

void RogueMap::loadmap(int height, int width) {
	
	HWND hWnd = GetConsoleWindow();
	DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
	SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

	//HWND console = GetConsoleWindow();
	//RECT r;
	//GetWindowRect(console, &r);

	//MoveWindow(console, r.left, r.top, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);

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

		std::ifstream myfile; myfile.open("Map.txt");

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