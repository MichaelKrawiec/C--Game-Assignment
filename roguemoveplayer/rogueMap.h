#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "utility.h"

class RogueMap {
private:
	//Map size
	int mapHeight;
	int mapWidth;
	//pointer to the map
	char* map;
	char* map2;

public:
	RogueMap();
	~RogueMap();

	
	void loadmap(int height, int width);
	void loadmap2(int height, int width);
	char getXY(int x, int y);

	bool setXY(int x, int  y, char value);
	
	void printmap();
	void printmap2();
};