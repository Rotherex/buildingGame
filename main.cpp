#include <iostream>
#include <conio.h>
#include <string>

char map[10][10];

struct Vector2 {
	int x;
	int y;
};

int blocksMined;
int frames;

Vector2 playerPos;

void generateMap() 
{
	for (int i = 4; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = '#';
		}
	}

	for (int k = 0; k < 4; k++) {
		for (int l = 0; l < 10; l++) {
			map[k][l] = '.';
		}
	}

	map[3][7] = 'P';
}

void drawMap()
{
	system("cls");

	std::cout << "Amount of blocks: " << std::to_string(blocksMined) << std::endl;
	std::cout << "Amount of turns: " << std::to_string(frames) << std::endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			std::cout << map[i][j] << ' ';
		}

		std::cout << '\n';
	}
}

char checkForInput()
{
	return (char)_getch();
}

int main()
{
	playerPos.x = 3;
	playerPos.y = 7;

	generateMap();

	for(; ;) {

		drawMap();

		char input = checkForInput();

		if (input == 'a') {
			char slot = map[playerPos.x][playerPos.y - 1];

			if (slot == '.') {

				if (playerPos.y== 0) {
					continue;
				}
				map[playerPos.x][playerPos.y - 1] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.y -= 1;

				drawMap();
			}
			else if (slot == '#') {
				map[playerPos.x][playerPos.y - 1] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.y -= 1;
				blocksMined += 1;

			}

		}else if (input == 'd') {
			char slot = map[playerPos.x][playerPos.y + 1];

			if (playerPos.y == 9) {
				continue;
			}

			if (slot == '.') {

				if (playerPos.y == 9) {
					continue;
				}
				map[playerPos.x][playerPos.y + 1] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.y += 1;

				drawMap();
			}
			else if (slot == '#') {
				map[playerPos.x][playerPos.y + 1] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.y += 1;
				blocksMined += 1;

			}
		}
		else if (input == 'm') {
			char slot = map[playerPos.x + 1][playerPos.y];

			if (slot == '#') {
				map[playerPos.x + 1][playerPos.y] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.x += 1;
				blocksMined += 1;

			}
		}
		else if (input == 'p') {
			char slot = map[playerPos.x - 1][playerPos.y];

			if (slot == '.' && blocksMined > 0) {
				map[playerPos.x - 1][playerPos.y] = 'P';
				map[playerPos.x][playerPos.y] = '#';

				blocksMined -= 1;
				playerPos.x -= 1;
			}
		} 
		else if (input == 'w') {
			char slot = map[playerPos.x - 1][playerPos.y];

			std::cout << slot;

			if (slot == '#') {
				map[playerPos.x - 1][playerPos.y] = '.';


				blocksMined += 1;
			} else if (slot == '.') {
				map[playerPos.x - 1][playerPos.y] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.x -= 1;
			}
		}
		else if (input == 's') {
			char slot = map[playerPos.x + 1][playerPos.y];

			if (slot == '.') {
				map[playerPos.x + 1][playerPos.y] = 'P';
				map[playerPos.x][playerPos.y] = '.';

				playerPos.x += 1;
			}
		}

		frames += 1;

		std::cout << playerPos.y;
	}
}
