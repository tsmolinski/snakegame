#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	RectangleShape shape;

	float movementSpeed;
	float grid;

	// private functions
	void initShape();

public:
	Player();
	virtual ~Player();

	// accessors
	const FloatRect getBounds() const;
	const Vector2f getPos() const;
	void setPos(float pos_x, float pos_y);

	// functions
	void move(const float dir_x, const float dir_y);

	void update();
	void render(RenderTarget& target);
};

