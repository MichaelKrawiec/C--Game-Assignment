#include "rogueMap.h"
#include <fstream>
#include <iostream>

RogueMap::RogueMap() {
	mapHeight = 0;
	mapWidth = 0;

	map = nullptr;
	map2 = nullptr;
}

RogueMap::~RogueMap() {
	delete[] map;
	delete[] map2;
}

void RogueMap::loadmap(int height, int width) {
	
	HWND hWnd = GetConsoleWindow();
	DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
	SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

	/*HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);*/

	utility::showConsoleCursor(false);

	mapHeight = height;
	mapWidth = width;

	// Allocating memory for the map.
	map = new char[mapHeight * mapWidth];

	std::ifstream gameMapFile{ "Map.txt", std::ios::in };
	
	if (!gameMapFile) {
		std::cerr << "Error opening level file\n";
		exit(1);
	}

	char c;
	int counter{};
	while (gameMapFile >> c) {

		if (c == '=')
			c = ' ';

		if (c == '_')

			c = 177;
		map[counter] = c;
		counter++;
	}

	/*for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) 
		{
			if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
				map[y * mapWidth + y] = ' # ';
			}
			else {
				map[y * mapWidth + y] = ' ';
			}
		}
	}*/
	printmap();
	gameMapFile.close();
}

void RogueMap::loadmap2(int height, int width) {

	HWND hWnd = GetConsoleWindow();
	DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
	SendMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	
	/*HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);*/

	utility::showConsoleCursor(false);

	mapHeight = height;
	mapWidth = width;

	// Allocating memory for the map.

	map2 = new char[mapHeight * mapWidth];
	std::ifstream gameMapFile2{ "GameoverMap.txt", std::ios::in };


	if (!gameMapFile2) {
		std::cerr << "Error opening GamerOver file\n";
		exit(2);
	}

	char c2;
	int counter2{};
	while (gameMapFile2 >> c2) {

		if (c2 == '=')
			c2 = ' ';

		if (c2 == '_')

			c2 = 177;

		if (c2 == '~')

			c2 = 197;

		if (c2 == ';')

			c2 = 223;

		if (c2 == '/')

			c2 = 220;

		if (c2 == '#')

			c2 = 219;
		
		map2[counter2] = c2;
		counter2++;
	}

	printmap2();
	gameMapFile2.close();
}
char RogueMap::getXY(int x, int y) {
	return map[y*mapWidth+x];
	return map2[y * mapWidth + x];
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
				std::cout << map[y * mapWidth + x];
			}
			std::cout << std::endl;
		}
	}

}
void RogueMap::printmap2() {

	utility::gotoScreenPosition(0, 0); {


		for (int y = 0; y < mapHeight; y++)
		{
			for (int x = 0; x < mapWidth; x++)
			{
				std::cout << map2[y * mapWidth + x];
			}
			std::cout << std::endl;
		}
	}
}