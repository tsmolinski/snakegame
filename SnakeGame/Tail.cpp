#include "Tail.h"

// private functions
void Tail::initShape()
{
	shape.setSize(Vector2f(20.f, 20.f));
	shape.setFillColor(Color(0, 255, 0, 200));
}

// con / des
Tail::Tail(float pos_x, float pos_y)
{
	movementSpeed = 1.0f;

	grid = 20.f;

	initShape();
}

Tail::~Tail()
{
}

const FloatRect Tail::getBounds() const
{
	return shape.getGlobalBounds();
}

Vector2f Tail::getPos()
{
	return shape.getPosition();
}

void Tail::setPos(float pos_x, float pos_y)
{
	shape.setPosition(pos_x, pos_y);
}

void Tail::move(float dir_x, float dir_y)
{
	return shape.move(movementSpeed * grid * dir_x, movementSpeed * grid * dir_y);
}

void Tail::update()
{
}

void Tail::render(RenderTarget& target)
{
	target.draw(shape);
}

