// SFML_PLAY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "TrianglesRandom.h"
#include "SpiralSpinner.h"
#include "misc.h"
#include <math.h>
using namespace std;
using namespace sf;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML_Practice");
	sf::Clock clock;
	window.setVerticalSyncEnabled(true);
	TrianglesRandom toDisplay(3000);
	toDisplay.setOrigin(400, 300);
	toDisplay.setPosition(400, 300);
	Vector2f scale(1.6f, 1.75f);
	toDisplay.setScale(scale);
	SpiralSpinner spirals(30);
	while (window.isOpen()) {
		// handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			//mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					//handle event
				}
			}
			else if (event.type == Event::MouseButtonReleased) {
					//
			}
		}
		toDisplay.Update();
		window.clear();
		toDisplay.rotate(7.5f);
		spirals.Rotate();
		window.draw(toDisplay);
		spirals.draw(window);
		window.display();
	}
	return 0;
}



