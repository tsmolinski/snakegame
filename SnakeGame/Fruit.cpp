#include "Fruit.h"

void Fruit::initShape()
{
	shape.setRadius(12);
	shape.setPointCount(4);
	shape.setFillColor(Color::Red);
}

void Fruit::initVariables()
{
	points = 10;
}

Fruit::Fruit(float pos_x, float pos_y)
{
	initShape();
	initVariables();

	shape.setPosition(pos_x, pos_y);
}

Fruit::~Fruit()
{
}

// accessors
const FloatRect Fruit::getBounds() const
{
	return shape.getGlobalBounds();
}

// functions
void Fruit::update()
{
}

void Fruit::render(RenderTarget* target)
{
	target->draw(shape);
}
