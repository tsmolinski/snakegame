#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Fruit
{
	CircleShape shape;

	int points;

	void initShape();
	void initVariables();

public:
	Fruit(float pos_x, float pos_y);
	virtual ~Fruit();

	// accessors
	const FloatRect getBounds() const;
	const int& getPoints() const;

	// functions
	void update();
	void render(RenderTarget* target);
};

