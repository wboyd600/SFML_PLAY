#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iterator>
using namespace std;
using namespace sf;
void RandomizeColors(sf::VertexArray &t, int count) {
	for (int j = 0; j < count; ++j) {
		int x = (rand() % 255);
		int y = (rand() % 255);
		int z = (rand() % 255);
		int a = (rand() % 255);
		if ((a + 90) <= 255) {
			a += 90;
		}
		else {
			a = 255;
		}
		t[j].color = Color(Uint8(x), Uint8(y), Uint8(z), Uint8(a));
	}
}



class TrianglesRandom : public sf::Drawable, public sf::Transformable {
public:
	TrianglesRandom(int count) : triangle_vertices(sf::Triangles, count), count(count) {
		RandomizeColors(triangle_vertices, this->count);
		srand((int)time(0));
		for (int i = 0; i < count; i += 3) {
			triangle_vertices[i].position = Vector2f(400.0f, 300.0f);
			float x = (rand() % 800);
			float y = (rand() % 600);
			triangle_vertices[i + 1].position = sf::Vector2f((x), y);
			int j = (rand() % 800);
			int k = (rand() % 600);
			triangle_vertices[i + 2].position = sf::Vector2f(j, k);
		}
	}
	void Update() {
		RandomizeColors(triangle_vertices, count);
	}
	void SetColor(sf::Color col) {
		for (int i = 0; i < count; ++i) {
			triangle_vertices[i].color = col;
		}
	}




private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		states.transform *= getTransform();
		states.texture = NULL;
		target.draw(triangle_vertices, states);
	}

	sf::VertexArray triangle_vertices;
	int count;
};
