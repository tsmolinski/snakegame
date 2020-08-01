#include "Player.h"

// private functions
void Player::initShape()
{
	shape.setSize(Vector2f(20.f, 20.f));
	shape.setFillColor(Color::Green);
	shape.setPosition(400, 300);
}

Player::Player()
{
	movementSpeed = 1.0f;

	grid = 20.f;

	initShape();
}

Player::~Player()
{
}

// accessors
const FloatRect Player::getBounds() const
{
	return shape.getGlobalBounds();
}

const Vector2f Player::getPos() const
{
	return shape.getPosition();
}

void Player::setPos(float pos_x, float pos_y)
{
	shape.setPosition(pos_x, pos_y);
}

void Player::move(const float dir_x, const float dir_y)
{
	shape.move(movementSpeed * grid * dir_x, movementSpeed * grid * dir_y);
}

// functions
void Player::update()
{

}

void Player::render(RenderTarget& target)
{
	target.draw(shape);
}
