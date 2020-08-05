#include "Game.h"


// private functions
void Game::initWindow()
{
	window = new RenderWindow(VideoMode(800, 600), "Snake Game", Style::Close | Style::Titlebar);
	window->setFramerateLimit(10);
	window->setVerticalSyncEnabled(false);

	grid = 20.f;
}

void Game::initPlayer()
{
	player = new Player;
}

void Game::initFruits()
{
	spawn_fruit = true;
}

void Game::initTail()
{
	spawn_tail = false;
}

void Game::initGUI()
{
	// load font

	if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "ERROR::GAME::Failed to load font pixellettersfull" << "\n";
	}

	// init point text
	pointText.setPosition(650.f, 25.f);
	pointText.setFont(font);
	pointText.setCharacterSize(30);
	pointText.setFillColor(Color::White);
	pointText.setString("test");
}

void Game::initSystems()
{
	points = 0;

	endGame = false;
}

// constructor/destructor
Game::Game()
{
	initWindow();
	initPlayer();
	initFruits();
	initTail();
	initGUI();
	initSystems();
}

Game::~Game()
{
	delete window;
	delete player;

	for (auto *i : fruits)
	{
		delete i;
	}

	for (auto* j : tail)
	{
		delete j;
	}
}

// functions
void Game::run()
{
	while (window->isOpen())
	{
		updatePollEvents();

		if (!endGame)
		{
			update();
		}

		render();
	}
}

void Game::updatePollEvents()
{
	Event e;
	while (window->pollEvent(e))
	{
		if (e.Event::type == Event::Closed)
		{
			window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == Keyboard::Escape)
		{
			window->close();
		}
	}
}

void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Points: " << points;

	pointText.setString(ss.str());
}

void Game::updatePlayerTailCollision()
{
	for (int i = 1; i < tail.size(); i++)
	{
		if (player->getBounds().intersects(tail[i]->getBounds()))
		{
			endGame = true;
		}

		else
		{
			endGame = false;
		}
	}
}

void Game::updatePlayerWindowCollision()
{
	// top and bottom
	if (player->getBounds().top < 0.f)
	{
		player->setPos(player->getBounds().left, window->getSize().y - player->getBounds().height);
	}
	else if (player->getBounds().top + player->getBounds().height > window->getSize().y)
	{
		player->setPos(player->getBounds().left, 0.f);
	}

	// left and right
	if (player->getBounds().left < 0.f)
	{
		player->setPos(window->getSize().x - player->getBounds().width, player->getBounds().top);
	}
	else if (player->getBounds().left + player->getBounds().width > window->getSize().x)
	{
		player->setPos(0.f + player->getBounds().width, player->getBounds().top);
	}
}

void Game::updateDirection()
{
	if (dir == UP)
	{
		player->move(0.f, -1.f);
	}
	if (dir == DOWN)
	{
		player->move(0.f, 1.f);
	}
	if (dir == LEFT)
	{
		player->move(-1.f, 0.f);
	}
	if (dir == RIGHT)
	{
		player->move(1.f, 0.f);
	}
}

void Game::updateInput()
{
	// move player
	bool keep_moving = false;

		if ((Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) && dir != RIGHT)
		{
			dir = LEFT;
		}

		else if ((Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) && dir != LEFT)
		{
			dir = RIGHT;
		}

		else if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && dir != DOWN)
		{
			dir = UP;
		}

		else if ((Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)) && dir != UP)
		{
			dir = DOWN;
		}
}

void Game::updateFruits()
{
	if (spawn_fruit)
	{
		fruits.push_back(new Fruit
						(grid * (rand() % static_cast<int>(window->getSize().x / grid)), 
						grid * (rand() % static_cast<int>(window->getSize().y / grid))));
		spawn_fruit = false;
	}
}

// spawn snake's tail
void Game::updateTail()
{
	if (tail.size() == 0)
	{
		tail.push_back(new Tail(player->getPos().x, player->getPos().y));
	}

	if (spawn_tail)
	{
		tail.push_back(new Tail(
					   player->getPos().x,
					   player->getPos().y));

		spawn_tail = false;
	}

		float prevX = tail.at(0)->getPos().x;
		float prevY = tail.at(0)->getPos().y;
		float prev2X, prev2Y;
		tail.at(0)->setPos(player->getPos().x, player->getPos().y);

		for (int k = 1; k < tail.size(); k++)
		{
			prev2X = tail.at(k)->getPos().x;
			prev2Y = tail.at(k)->getPos().y;
			tail.at(k)->setPos(prevX, prevY);
			prevX = prev2X;
			prevY = prev2Y;
		}
}

void Game::updateEatFruits()
{
	for (size_t i = 0; i < fruits.size(); i++)
	{
		if (player->getBounds().intersects(fruits[i]->getBounds()))
		{
			points += fruits[i]->getPoints();
			spawn_tail = true;
			fruits.erase(fruits.begin() + i);
			spawn_fruit = true;
		}
	}

}

void Game::update()
{
	updateGUI();
	updatePlayerTailCollision();
	updatePlayerWindowCollision();
	updateDirection();
	updateInput();
	updateEatFruits();
	updateFruits();
	updateTail();
}

void Game::renderGUI()
{
	window->draw(pointText);
}

void Game::render()
{
	window->clear();

	// draw all the stuffs
	player->render(*window);

	for (auto *fruit : fruits)
	{
		fruit->render(window);
	}

	if (tail.size() > 0)
	{
		for (auto* t : tail)
		{
			t->render(*window);
		}
	}

	renderGUI();

	window->display();
}
