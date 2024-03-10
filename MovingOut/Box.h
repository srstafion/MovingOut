#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Box
{
private:
	RectangleShape box;
public:
	Box(Vector2f startPosition);
	void draw(RenderWindow& window);
	Vector2f getPosition();
	void setPosition(Vector2f position);
};

