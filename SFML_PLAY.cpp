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
					//positions.push_back(mousePos);
					//                    lastOne = mousePos;
					//                    mouseClicked = true;
				}
			}
			else if (event.type == Event::MouseButtonReleased) {
				//                    mouseClicked = false;
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
//int main() {
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML_Practice");
//	sf::Clock clock;
//	window.setVerticalSyncEnabled(true);
//	SpiralSpinner toDisplay(300);
//	while (window.isOpen()) {
//		// handle events
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			//mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//			else if (event.type == Event::MouseButtonPressed) {
//				if (event.mouseButton.button == Mouse::Left) {
//					//positions.push_back(mousePos);
//					//                    lastOne = mousePos;
//					//                    mouseClicked = true;
//				}
//			}
//			else if (event.type == Event::MouseButtonReleased) {
//				//                    mouseClicked = false;
//			}
//		}
//		toDisplay.Reset();
//		toDisplay.Rotate();
//		toDisplay.draw(window);
//		window.display();
//	}
//	return 0;
//}
//bool PlaceDot(Vector2f lastOne, Vector2f mousPos) {
//	float dt = 6.0f;
//	float sqrty = sqrt(pow((mousPos.x - lastOne.x), 2) + pow((mousPos.y - lastOne.y), 2));
//	if (sqrty > dt) {
//		return true;
//	}
//	return false;
//}
//bool PlaceDot(Vector2f lastOne, Vector2f mousPos);
//void FillLines(VertexArray &lines, vector<sf::Vector2f> &positionsClicked);
//void FillTriangles(VertexArray &triangles, vector<sf::Vector2f> &positionsClicked);
//for (int i = 0; i < (int)positions.size(); ++i) {
//	points[i].position = positions[i];
//	points[i].color = Color::Cyan;
//}
//FillLines(lines, positions);
//FillTriangles(triangles, positions);
//sf::Time elapsed = clock.restart();
//window.clear();
//RandomizeColors(triangles, positions.size() + 10);
//window.draw(points);
//window.draw(lines);
//window.draw(triangles);
//vector<sf::Vector2f> positions;
//Vector2f mousePos;
//VertexArray points(sf::Points, 3000);
//VertexArray lines(sf::Lines, 3000);
//VertexArray triangles(sf::Triangles, 3000);
//for (int j = 0; j < 3000; ++j) {
//	lines[j].color = Color::Cyan;
//	triangles[j].color = Color::Cyan;
//}
//void FillLines(VertexArray &lines,vector<sf::Vector2f> &positionsClicked);
//        lol2.RandomizeColors();
//        window.draw(g);
//        window.draw(lol2);
//        window.draw(points);
//        window.draw(lines);
//        window.draw(triangles);
//        g = t.GetPoints();
//        for (int i = 0; i < positionsClicked.size(); ++i) {
//            points[i].position = positionsClicked[i];
//            points[i].color = Color::Red;
//        }
//        FillLines(lines,positionsClicked);
//        FillTriangles(triangles,positionsClicked);
//        lol2.rotate(10.0f);
//        lol.RandomizeColors();
//    lol2.setOrigin(400.0f,300.0f);
//    lol2.setPosition(400.0f,300.0f);
//    lol2.setScale(1.3f,1.8f);

//    for (int j = 0; j < 3000; ++j) {
//        int x = (rand() % 255);
//        int y = (rand() % 255);
//        int z = (rand() % 255);
//        int a = (rand() % 255);
//        if((a + 90) <= 255){
//            a +=90;
//        }else{
//            a = 255;
//        }
//        triangles[j].color = Color(Uint8(x + 100),Uint8(y),Uint8 (z),Uint8(a));
//    }
//
void FillLines(VertexArray &lines, vector<sf::Vector2f> &positionsClicked) {
	int numberClicked = positionsClicked.size();
	if (numberClicked < 3) {
		//do nothing
	}
	else {
		int i = 0;
		int j = 0;
		Vector2f pos = positionsClicked[0];
		while (j < (int)positionsClicked.size()) {
			lines[i].position = pos;
			lines[i + 1].position = positionsClicked[j];
			pos = positionsClicked[j];
			j++;
			i += 2;
		}
	}
}

void FillTriangles(VertexArray &triangles, vector<sf::Vector2f> &positionsClicked) {
	int numberClicked = positionsClicked.size();
	if (numberClicked < 3) {
		//nothing
	}
	else {
		int i = 0;
		int j = 2;
		Vector2f pos = positionsClicked[0];
		Vector2f pos2 = positionsClicked[1];
		while (j < (int) positionsClicked.size()) {
			triangles[i].position = positionsClicked[0];
			triangles[i + 1].position = pos2;
			triangles[i + 2].position = positionsClicked[j];
			pos = positionsClicked[j];
			pos2 = positionsClicked[j + 1];
			j += 2;
			i += 3;
		}
	}
}
//VertexArray points(sf::Points,3000);
//    VertexArray lines(sf::Lines,3000);
//    VertexArray triangles(sf::Triangles,3000);
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu