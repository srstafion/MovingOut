#include "Button.h"

Button::Button(Vector2f startPosition)
{
	button.setFillColor(Color(191, 77, 59));
	button.setSize(Vector2f(32, 32));
	button.setOutlineThickness(16);
	button.setOutlineColor(Color(153, 138, 136));
	button.setPosition(sf::Vector2f(startPosition.x + 16, startPosition.y + 16));
}

void Button::draw(RenderWindow& window)
{
	window.draw(button);
}

Vector2f Button::getPosition()
{
	return button.getPosition();
}

void Button::setPosition(Vector2f position)
{
	button.setPosition(position);
}
