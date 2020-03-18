//game.cpp
//Implementation of Game class
#include "game.h"
#include <iostream>

Game::Game(int** map, int** c) {
	level = map;
	this->c = c;
	wintexture.loadFromFile("winmark.png");
	winsign.setPosition(11520, 760);
	winsign.setSize(sf::Vector2f(16, 32));
	winsign.setTexture(&wintexture);

}

void Game::init() {
	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	view.setViewport(sf::FloatRect(0, 0, 1, 1));
	window.setKeyRepeatEnabled(false);

	font.loadFromFile("NotoSansDisplay-ExtraBold.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Yellow);
	temp.setFont(font);
	temp.setCharacterSize(25);
	temp.setFillColor(sf::Color::Red);

	tilemap.load("tilemap.png", Vectori(16, 16), 6, level[0], 124, 3, Vectori(0, 792));
	coins.load("coinset.png", Vectori(10, 14), 2, c[0], 500, 2, Vectori(0, 600));
	mario.setPositionY(100);
	world.addParticle(&mario);
	setEnemy(0);
	buffer.loadFromFile("mario.wav");
	sound.setBuffer(buffer);
	sound.setVolume(10.f);

	return;
}


void Game::start() {

	showmenu();
	sound.play();
	sound.setLoop(true);
	elapsed = clock.restart();

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (cancontrol)
				movementHandle();
		}

		elapsed = clock.restart();
		world.runPhysics(elapsed.asSeconds());//更新物理引擎，改變mario的物理參數
		for (int i = 0; i < enemys.size(); i++)
			enemys[i]->integrate(elapsed.asSeconds());

		for (int i = 0; i < enemys.size(); i++)
		{
			enemys[i]->checkkill(mario);

		}
		if (!mario.attacked) {
			tilemap.resolveCollision(mario);
		}
		else
		{
			cancontrol = false;
		}

		tilemap.resolveCollision(enemy);
		for (int i = 0; i < enemys.size(); i++) {
			tilemap.resolveCollision(*enemys[i]);
		}
		coins.resolveCollision(mario);

		//判斷mario是否摔死 
		if (mario.getPositionY() - mario.getHeight() / 2 > 1100) {//重頭開始
			cancontrol = true;
			fall();
			leftswitch = false;
			rightswitch = false;
			clock.restart();
		}

		if (mario.getlife() < 0) {//遊戲結束gameover
			sound.stop();
			mario.setlife(3);
			currentlevel = 0;
			for (int i = 0; i < 3; i++) {
				coins.load("coinset.png", Vectori(10, 14), 2, c[i], 5, 2, Vectori(0, 400));
				coins.reset();
				score[i] = 0;
			}
			window.setView(window.getDefaultView());
			//temp.setFont(font);
			//temp.setCharacterSize(25);
			temp.setString("GAMEOVER");
			//temp.setFillColor(sf::Color::Red);
			window.clear();
			window.draw(temp);
			window.display();
			Sleep(5000);
			setEnemy(0);
			coins.load("coinset.png", Vectori(10, 14), 2, c[0], 500, 2, Vectori(0, 600));
			tilemap.load("tilemap.png", Vectori(16, 16), 6, level[0], 124, 3, Vectori(0, 792));
			showmenu();
			cancontrol = true;
			leftswitch = false;
			rightswitch = false;
			sound.play();
			clock.restart();
		}

		if (mario.getPositionX() + mario.getWidth() > 11520) {
			cancontrol = false;
			mario.setVelocityX(100);
			mario.setAccelerationX(0);
			if (mario.getPositionX() + mario.getWidth() > 11904) {



				if (currentlevel == 2)
				{
					sound.stop();
					//clock.restart();
					win();
					//temp.setFont(font);
					//temp.setCharacterSize(25);
					temp.setString("YOU WIN");
					//temp.setFillColor(sf::Color::Yellow);
					window.clear();
					window.draw(temp);
					window.display();
					Sleep(5000);
					showmenu();
					leftswitch = false;
					rightswitch = false;
					sound.play();
					clock.restart();
					cancontrol = true;

				}
				else {
					uplevel();
					leftswitch = false;
					rightswitch = false;
					cancontrol = true;
					clock.restart();
					mario.setlife(mario.getlife() + 4);
				}
			}
		}


		window.clear(sf::Color(200, 200, 200));//清除畫面
		window.setView(window.getDefaultView());
		text.setString("coins: " + std::to_string(coins.getcount()) +
			"         scores: " + std::to_string(score[currentlevel]) +
			"         life: " + std::to_string(mario.getlife()) +
			"                                      world 1-" + std::to_string(currentlevel + 1));
		window.draw(text);

		//處理視窗捲動
		if (mario.getPositionX() >= 1920 / 2) {
			view.setCenter(mario.getPositionX(), 540);
			window.setView(view);
		}
		if (mario.getPositionX() >= 10944) {
			view.setCenter(10944, 540);
			window.setView(view);
		}

		tilemap.draw(window);//畫地圖
		coins.draw(window);// draw coins
		//enemy.draw(window);
		for (int i = 0; i < enemys.size(); i++)
		{
			enemys[i]->draw(window);

		}

		mario.draw(window, elapsed.asSeconds());//畫mario
		window.draw(winsign);
		window.display();//顯示圖案
		score[currentlevel] = 10 * coins.getcount();
	}
	return;
}

void Game::movementHandle() {
	//static bool rightswitch = false;
		//static bool leftswitch = false;
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W)
		{
			//jumpeffect.play();
			mario.jump();
		}
		if (event.key.code == sf::Keyboard::D)
		{
			rightswitch = true;
		}
		if (event.key.code == sf::Keyboard::A)
		{
			leftswitch = true;
		}
	}


	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			rightswitch = false;

		}
		if (event.key.code == sf::Keyboard::A)
		{
			leftswitch = false;
		}
	}

	if (leftswitch && rightswitch) {
		mario.stopWalking();
	}
	else if (leftswitch) {
		mario.walkLeft();
	}
	else if (rightswitch) {
		mario.walkRight();
	}
	else
	{
		mario.stopWalking();
	}
}



void Game::showmenu() {

	text.setString("Press spacebar to start\nUse w,a,d keys to control the mario!");
	window.setView(window.getDefaultView());
	mario.setAccelerationY(0);
	mario.setVelocityX(300);
	float time;
	while (true) {
		time = clock.restart().asSeconds();
		mario.integrate(time);
		if (mario.getPositionX() > 1900)
		{
			mario.setPositionX(0);

		}
		window.clear();
		window.draw(text);
		mario.draw(window, time);
		window.display();
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Space) {
				window.clear();
				mario.reset();
				return;
			}
			else if (event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::E) {
				window.close();
			}

		}

	}

}




void Game::fall() {
	window.setView(window.getDefaultView());
	mario.reset();
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->reset();

	}
	//enemy.reset();
	coins.reset();
	score[currentlevel] = 0;
	mario.reducelife();
	Sleep(1000);
}

void Game::win() {
	window.setView(window.getDefaultView());
	mario.reset();
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->reset();

	}
	for (int i = 0; i < 3; i++)
	{
		coins.load("coinset.png", Vectori(10, 14), 2, c[i], 500, 2, Vectori(0, 600));
		coins.reset();
		score[i] = 0;
	}
	mario.setlife(3);
	currentlevel = 0;
	setEnemy(currentlevel);
	coins.load("coinset.png", Vectori(10, 14), 2, c[0], 500, 2, Vectori(0, 600));
	tilemap.load("tilemap.png", Vectori(16, 16), 6, level[0], 124, 3, Vectori(0, 792));
	return;

}
void Game::uplevel() {
	mario.reset();
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->reset();

	}
	//coins.reset();
	if (currentlevel == 2)
		return;
	currentlevel++;
	setEnemy(currentlevel);
	coins.load("coinset.png", Vectori(10, 14), 2, c[currentlevel], 500, 2, Vectori(0, 600));
	tilemap.load("tilemap.png", Vectori(16, 16), 6, level[currentlevel], 124, 3, Vectori(0, 792));
	Sleep(1000);
	return;
}

void Game::setEnemy(int currentlevel) {

	for (int i = 0; i < enemys.size(); i++)
	{
		delete enemys[i];
	}
	enemys.clear();


	if (currentlevel == 0)
	{

		enemys.push_back(new Enemy(850, 60, 792));
		enemys.push_back(new Enemy(2370, 30, 792));
		enemys.push_back(new Enemy(4680, 70, 792));
		enemys.push_back(new Enemy(11420, 30, 792));
	}
	else if (currentlevel == 1)
	{
		enemys.push_back(new Enemy(700, 30, 792));
		enemys.push_back(new Enemy(1900, 30, 792));
		enemys.push_back(new Enemy(3100, 30, 792));
		enemys.push_back(new Enemy(4000, 30, 792));
		enemys.push_back(new Enemy(7900, 30, 792));
		enemys.push_back(new Enemy(9100, 30, 792));
		enemys.push_back(new Enemy(10420, 30, 792));
		enemys.push_back(new Enemy(11020, 30, 792));
		enemys.push_back(new Enemy(11470, 30, 792));
	}
	else if (currentlevel == 2)
	{
		enemys.push_back(new Enemy(500, 30, 792));
		enemys.push_back(new Enemy(700, 30, 792));
		enemys.push_back(new Enemy(1100, 30, 792));
		enemys.push_back(new Enemy(1460, 75, 792));
		enemys.push_back(new Enemy(2950, 30, 792));
		enemys.push_back(new Enemy(4300, 30, 792));
		enemys.push_back(new Enemy(5850, 30, 792));
		enemys.push_back(new Enemy(7300, 30, 792));
		enemys.push_back(new Enemy(8850, 30, 792));
		enemys.push_back(new Enemy(9020, 30, 792));
		enemys.push_back(new Enemy(9820, 30, 792));
		enemys.push_back(new Enemy(11120, 30, 792));
		enemys.push_back(new Enemy(11420, 30, 792));
	}
}