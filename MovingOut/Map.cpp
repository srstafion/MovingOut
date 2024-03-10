#include "Map.h"

Map::Map()
{
	Color color;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			maskTiles[i][j].setSize(sf::Vector2f(32, 32));
			switch (mask[i][j]) {
			default:
				color = Color(118, 98, 87);
				break;
			}
			maskTiles[i][j].setFillColor(color);
			maskTiles[i][j].setOutlineThickness(32);
			maskTiles[i][j].setOutlineColor(Color(85, 66, 60));
			maskTiles[i][j].setPosition(sf::Vector2f((j * 64) + 16, (i * 64) + 16));
		}
	}
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			window.draw(maskTiles[i][j]);
		}
	}
}

int Map::getElementByPosition(int x, int y)
{
	return mask[y][x];
}

vector<vector<int>> Map::getArrayCoordsByNum(int num) {
	vector<vector<int>> coords;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			if (mask[i][j] == num) {
				vector<int> coord;
				coord.push_back(i);
				coord.push_back(j);
				coords.push_back(coord);
			}
		}
	}
	return coords;
}

void Map::changeMask(int x, int y, int value)
{
	mask[y][x] = value;
}
