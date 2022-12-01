#include <windows.h>
#include <iostream>
#include <string>
#include "utility.h"
#include "rogueMap.h"
#include <fstream>



// Global Variables
unsigned int playerPositionX = 3;
unsigned int playerPositionY = 14;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

unsigned int health = 3;
unsigned int score = 10;

char playerChar1 = 2;
char playerChar2 = 179;

RogueMap map;
RogueMap map2;

//End of Global Variables

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState(VK_UP) & 0x8000)
	{
		if (map.getXY(playerPositionX, playerPositionY - 1) == ' ') {

			newPlayerPositionY = playerPositionY - 1;
			
			//map2.loadmap2(22, 79);

			
		}
		if (map.getXY(playerPositionX, playerPositionY - 1) == '-' || map.getXY(playerPositionX, playerPositionY) == '-') {

				newPlayerPositionY = playerPositionY - 1;
				map2.loadmap2(22, 79);
			}
			if (map.getXY(playerPositionX, playerPositionY - 1) == '*' || map.getXY(playerPositionX, playerPositionY) == '*') {

				newPlayerPositionY = playerPositionY - 1;
				score += 10;
			}
			if (map.getXY(playerPositionX, playerPositionY - 1) == '@' || map.getXY(playerPositionX, playerPositionY) == '@') {

				newPlayerPositionY = playerPositionY - 1;
				health - 1;
			}

	}


	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (map.getXY(playerPositionX, playerPositionY + 2) == ' ' && map.getXY(playerPositionX, playerPositionY + 1) == ' ') {

			newPlayerPositionY = playerPositionY + 1;
		}
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (map.getXY(playerPositionX + 1, playerPositionY) == ' ' && map.getXY(playerPositionX + 1, playerPositionY + 1) == ' ') {
			newPlayerPositionX = playerPositionX + 1;
		}
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (map.getXY(playerPositionX - 1, playerPositionY) == ' ' && map.getXY(playerPositionX - 1, playerPositionY + 1) == ' ') {
			newPlayerPositionX = playerPositionX - 1;
		}
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
	utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY + 1);
	std::cout << playerChar2;


	////if (map.getXY(playerPositionX, playerPositionY + 2) == ' ') {
	////	while (true) {

	////		// Draw new player position
	////		utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY += 1);
	////		std::cout << playerChar1;
	////		utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY += 1);
	////		std::cout << playerChar2;
	////		utility::gotoScreenPosition(playerPositionX, playerPositionY - 1);
	////		std::cout << " ";
	////		utility::gotoScreenPosition(playerPositionX, playerPositionY);
	////		std::cout << " ";
	////		playerPositionX = newPlayerPositionX;
	////		playerPositionY = newPlayerPositionY;
	////		Sleep(500);


	////		if (map.getXY(playerPositionX, playerPositionY + 2) == 177 || map.getXY(playerPositionX, playerPositionY + 1) == 177) break;
	////	}
	////}


	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;



	Sleep(150);
}

int main()
{

	map.loadmap(22, 79);
	/*char ch;
	for (int i = 6; i < 256; i++)
	{
		ch = i;
		utility::gotoScreenPosition(0, i);

		std::cout << i << " = " << ch << std::endl;
	}*/
	while (true)
	{
		// // Handles the input and updates the players position
		handleInput();
		utility::gotoScreenPosition(2, 23);
		std::cout << "Score: " << score;

		utility::gotoScreenPosition(36, 23);
		std::cout << "Hearts: " << health;
		// Render the scene
		renderPlayer();

	}
	

	return 0;

}