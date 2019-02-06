#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iterator>
class Spiral : public sf::Drawable, public sf::Transformable {
public:
	Spiral() : pointsToSpiral(sf::Points, 1500) {
		double angle = 0.0;
		double radius = 0.0;
		while (radius < 500) {
			auto x = radius * cos(angle * 180 / 3.14159265);
			auto y = radius * sin(angle * 180 / 3.14159265);
			pointsToSpiral[radius].position = Vector2f(x, y);
			pointsToSpiral[radius].color = Color::Cyan;
			radius++;
			angle++;
		}
	}

	void RandomizeSpiral() {
		RandomizeColors(pointsToSpiral, 500);
	}
	VertexArray &GetVertexArrary() {
		return pointsToSpiral;
	}
	void SetColor(sf::Color col) {
		for (int i = 0; i < 500; ++i) {
			pointsToSpiral[i].color = col;
		}

	}

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		// apply the transform
		states.transform *= getTransform();
		// apply the tileset texture
		states.texture = NULL;
		// draw the vertex array
		target.draw(pointsToSpiral, states);
	}

	VertexArray pointsToSpiral;
};


class SpiralSpinner {
public:
	SpiralSpinner(int count) : count(count) {
		float rotate = 0.0f;
		for (int i = 0; i < count; ++i) {
			Spiral g;
			g.rotate(rotate);
			g.setPosition(400.0f, 300.0f);
			rotate += 1.5f;
			g.RandomizeSpiral();
			spiralsToSpin.push_back(g);
		}
	}
	void Rotate() {
		for (int i = 0; i < this->count; ++i) {
			spiralsToSpin[i].rotate(1.5f);
			spiralsToSpin[i].RandomizeSpiral();
		}
	}
	void Reset() {
		spiralsToSpin.clear();
		float rotate = 0.0f;
		for (int i = 0; i < this->count; ++i) {
			Spiral g;
			g.rotate(rotate);
			g.setPosition(400.0f, 300.0f);
			rotate += 1.5f;
			g.RandomizeSpiral();
			spiralsToSpin.push_back(g);
		}
	}
	void draw(sf::RenderWindow &window) {
		for (int i = 0; i < this->count; ++i) {
			window.draw(spiralsToSpin[i]);
		}
	}
private:
	int count;
	vector<Spiral> spiralsToSpin;
};
