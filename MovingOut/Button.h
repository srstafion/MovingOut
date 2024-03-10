#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Button
{
private:
	RectangleShape button;
public:
	Button(Vector2f startPosition);
	void draw(RenderWindow& window);
	Vector2f getPosition();
	void setPosition(Vector2f position);
};