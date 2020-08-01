#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Tail
{
	RectangleShape shape;

	float movementSpeed;
	float grid;

	// private functions
	void initShape();

public:
	// con / des
	Tail(float pos_x, float pos_y);
	virtual ~Tail();

	// accessors
	Vector2f getPos();
	void setPos(float pos_x, float pos_y);

	// functions
	void move(float dir_x, float dir_y);

	void update();
	void render(RenderTarget& target);

};

