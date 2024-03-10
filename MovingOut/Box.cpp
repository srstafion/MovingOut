#include "Box.h"

Box::Box(Vector2f startPosition)
{
	box.setFillColor(Color(28, 17, 14));
	box.setPosition(startPosition);
	box.setSize(Vector2f(64, 64));
}

void Box::draw(RenderWindow& window)
{
	window.draw(box);
}

Vector2f Box::getPosition()
{
	return box.getPosition();
}

void Box::setPosition(Vector2f position)
{
	box.setPosition(position);
}
