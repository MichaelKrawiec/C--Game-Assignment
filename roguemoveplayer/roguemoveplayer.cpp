#include <windows.h>
#include <iostream>
#include <string>
#include "utility.h"
#include "rogueMap.h"
#include <fstream>



// Global Variables
unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

unsigned int health = 0;

char playerChar1 = 2;
char playerChar2 = 179;

RogueMap map;

//End of Global Variables

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState(VK_UP) & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void renderPlayer()
{

	
	// Draw new player position
	utility::gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << " ";
	utility::gotoScreenPosition(playerPositionX, playerPositionY + 1);
	std::cout << " ";

	// Draw new player position
	utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar1;
	utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY+1);
	std::cout << playerChar2;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(120);
}

int main()
{

	map.loadmap(30, 30);

	while (true)
	{
		// // Handles the input and updates the players position
		handleInput();

		// Render the scene
		renderPlayer();
	}
	
	

	return 0;

}