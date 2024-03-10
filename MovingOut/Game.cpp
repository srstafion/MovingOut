#include "Game.h"
#include <iostream>
using namespace std;
#define random(a, b) (a + rand()% (b + 1 - a)) 

void Game::processEvents()
{
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerMoveDirection = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerMoveDirection = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerMoveDirection = 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerMoveDirection = 4;
		}
		else {
			playerMoveDirection = 0;
		}
	}
}

void Game::update() {
	if (map.getArrayCoordsByNum(1).size() == 0) winAndRestart();
	sf::Vector2f pPos = player.getPosition();
	/*std::cout << playerMoveDirection << " : " << lastFaced << " : " << map.getElementByPosition(pPos.x / 64, (pPos.y - 64) / 64) << ":"
		<< map.getElementByPosition((pPos.x + 64) / 64, pPos.y / 64) << ":"
		<< map.getElementByPosition(pPos.x / 64, (pPos.y + 64) / 64) << ":"
		<< map.getElementByPosition((pPos.x - 64) / 64, pPos.y / 64) << " : "
		<< pPos.x / 64 << " : " << pPos.y / 64 << std::endl;*/
	switch (playerMoveDirection) {
	case 1:
		if (pPos.y >= 64) {
			for (auto& box : boxes) {
				if (box.getPosition() == sf::Vector2f(pPos.x, pPos.y - 64)
					&& map.getElementByPosition(box.getPosition().x / 64,
						(box.getPosition().y - 64) / 64) < 2) {
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 0);
					box.setPosition(Vector2f(box.getPosition().x, box.getPosition().y - 64));
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 2);
				}
			}
			if (map.getElementByPosition(pPos.x / 64, (pPos.y - 64) / 64) < 2) player.move(1);
		}
		break;
	case 2: // right x
		if (pPos.x < 960 - 64) {
			for (auto& box : boxes) {
				if (box.getPosition() == sf::Vector2f(pPos.x + 64, pPos.y)
					&& pPos.x + 64 < 960 - 64
					&& map.getElementByPosition((box.getPosition().x + 64) / 64,
						box.getPosition().y / 64) < 2) {
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 0);
					box.setPosition(Vector2f(box.getPosition().x + 64, box.getPosition().y));
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 2);
				}
			}
			if (map.getElementByPosition((pPos.x + 64) / 64, pPos.y / 64) < 2) player.move(2);
		}
		break;

	case 3: // down y
		if (pPos.y < 640 - 64) {
			for (auto& box : boxes) {
				if (box.getPosition() == sf::Vector2f(pPos.x, pPos.y + 64)
					&& pPos.y + 64 < 640 - 64
					&& map.getElementByPosition(box.getPosition().x / 64,
						(box.getPosition().y + 64) / 64) < 2) {
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 0);
					box.setPosition(Vector2f(box.getPosition().x, box.getPosition().y + 64));
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 2);
				}
			}
			if (map.getElementByPosition(pPos.x / 64, (pPos.y + 64) / 64) < 2) player.move(3);
		}
		break;

	case 4: // left -x
		if (pPos.x > 0) {
			for (auto& box : boxes) {
				if (box.getPosition() == sf::Vector2f(pPos.x - 64, pPos.y)
					&& pPos.x - 64 >= 64
					&& map.getElementByPosition((box.getPosition().x - 64) / 64,
						box.getPosition().y / 64) < 2) {
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 0);
					box.setPosition(Vector2f(box.getPosition().x - 64, box.getPosition().y));
					map.changeMask(box.getPosition().x / 64, box.getPosition().y / 64, 2);
				}
			}
			if (map.getElementByPosition((pPos.x - 64) / 64, pPos.y / 64) < 2) player.move(4);
		}
		break;
	}

	for (auto& button : buttons) {
		if (map.getElementByPosition(button.getPosition().x / 64,
			button.getPosition().y / 64) == 0) {
			map.changeMask(button.getPosition().x / 64, button.getPosition().y / 64, 1);
		}
	}

	if (playerMoveDirection != 0) {
		lastFaced = playerMoveDirection;
	}
}

void Game::render()
{
	window.clear();
	map.draw(window);
	for (auto i : buttons) {
		i.draw(window);
	}
	for (auto i : boxes) {
		i.draw(window);
	}
	player.draw(window);
	if (map.getArrayCoordsByNum(1).size() == 0) window.draw(text);
	window.display();
}

void Game::winAndRestart() {
	font.loadFromFile("CooperBits.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(Color::White);
	text.setOutlineThickness(6);
	text.setOutlineColor(Color::Black);
	text.setPosition(364, 256);
	text.setString("You win!");
	render();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			map.changeMask(j, i, 0);
		}
	}

	player.setPosition(Vector2f(448, 0));

	Sleep(1000);

	boxes.clear();
	for (int i = 0; i < random(3, 4); i++) {
		int x = random(1, 13);
		int y = random(1, 8);
		if (map.getElementByPosition(x, y) == 2) {
			x = random(1, 13);
			y = random(1, 8);
		}
		boxes.push_back(Box(Vector2f(x * 64, y * 64)));
		map.changeMask(x, y, 2);
	}
	buttons.clear();
	for (int i = 0; i < boxes.size(); i++) {
		int x = random(1, 13);
		int y = random(1, 8);
		if (map.getElementByPosition(x, y) == 2) {
			x = random(1, 13);
			y = random(1, 8);
		}
		buttons.push_back(Button(Vector2f(x * 64, y * 64)));
		map.changeMask(x, y, 1);
	}
}

Game::Game()
	: window(sf::VideoMode(960, 640), "Moving Out"),
	player(sf::Vector2f(448, 0))
{
	srand(time(NULL));
	vector<vector<int>> coords = map.getArrayCoordsByNum(2);

	for (int i = 0; i < random(3, 4); i++) {
		int x = random(1, 13);
		int y = random(1, 8);
		if (map.getElementByPosition(x, y) == 2) {
			x = random(1, 13);
			y = random(1, 8);
		}
		boxes.push_back(Box(Vector2f(x * 64, y * 64)));
		map.changeMask(x, y, 2);
	}

	buttonCoords = map.getArrayCoordsByNum(2);

	for (int i = 0; i < boxes.size(); i++) {
		int x = random(1, 13);
		int y = random(1, 8);
		if (map.getElementByPosition(x, y) == 2) {
			x = random(1, 13);
			y = random(1, 8);
		}
		buttons.push_back(Button(Vector2f(x * 64, y * 64)));
		map.changeMask(x, y, 1);
	}
}

void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	while (window.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update();
		}
		render();
	}
}