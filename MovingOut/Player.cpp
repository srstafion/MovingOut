#include "Player.h"

Player::Player(Vector2f startPosition)
{
	player.setFillColor(Color(175, 29, 73));
	player.setSize(sf::Vector2f(64.f, 64.f));
	player.setPosition(startPosition);
}

void Player::move(int direction)
{
	// 1 - up; 
	// 2 - right; 
	// 3 - down; 
	// 4 - left
	switch (direction) {
	case 1:
		player.move(sf::Vector2f(0, -64));
		break;
	case 2:
		player.move(sf::Vector2f(64, 0));
		break;
	case 3:
		player.move(sf::Vector2f(0, 64));
		break;
	case 4:
		player.move(sf::Vector2f(-64, 0));
		break;
	}
}

void Player::draw(RenderWindow& window)
{
	window.draw(player);
}

Vector2f Player::getPosition()
{
	return player.getPosition();
}

void Player::setPosition(Vector2f pos)
{
	player.setPosition(pos);
}
