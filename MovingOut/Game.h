#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Player.h"
#include "Map.h"
#include "Box.h"
#include "Button.h"
#include <vector>
using namespace sf;

class Game
{
private:
	RenderWindow window;
	Map map;
	Player player;
	vector<Box> boxes;
	vector<Button> buttons;
	vector<vector<int>> buttonCoords;
	int playerMoveDirection = 0;
	int lastFaced = 0;

	Font font;
	Text text;
	const Time TimePerFrame = seconds(1.f / 10.f);

	void processEvents();
	void update();
	void render();
public:
	Game();
	void winAndRestart();
	void run();
};

