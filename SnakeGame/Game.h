#pragma once

#include "Player.h"
#include "Fruit.h"
#include "Tail.h"

#include <vector>
#include <deque>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

class Game
{
	RenderWindow* window;

	float grid;

	enum direction {UP, DOWN, LEFT, RIGHT};
	direction dir;

	// GUI
	Font font;
	Text pointText;

	Text gameOverText;


	// systems
	int points;
	
	bool endGame;
	
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
	void initGUI();
	void initSystems();

public:
	Game();
	virtual ~Game();

	// functions
	void run();

	void updatePollEvents();
	void updateGUI();
	void updatePlayerTailCollision();
	void updatePlayerWindowCollision();
	void updateDirection();
	void updateInput();
	void updateFruits();
	void updateTail();
	void updateEatFruits();

	void update();

	void renderGUI();
	void render();
};

