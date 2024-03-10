#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player {
private:
	RectangleShape player;
public:
	Player(Vector2f startPosition);
	void move(int direction);
	void draw(RenderWindow& window);
	Vector2f getPosition();
	void setPosition(Vector2f pos);
};