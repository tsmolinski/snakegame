#pragma once

#include "Player.h"
#include "Fruit.h"
#include "Tail.h"

#include <vector>
#include <deque>
#include <iostream>
#include<math.h>

class Game
{
	RenderWindow* window;

	float grid;

	enum direction {UP, DOWN, LEFT, RIGHT};
	direction dir;

	// systems
	int points;
	
	// player - snake
	Player* player;

	//tail
	bool spawn_tail;
	std::deque<Tail*> tail;

	// fruits
	bool spawn_fruit;
	std::vector<Fruit*> fruits;

	// private functions
	void initWindow();

	void initPlayer();
	void initFruits();
	void initTail();
	void initSystems();

public:
	Game();
	virtual ~Game();

	// functions
	void run();

	void updatePollEvents();
	void updatePlayerWindowCollision();
	void updateDirection();
	void updateInput();
	void updateFruits();
	void updateTail();

	void updateEatFruits();

	void update();
	void render();
};

