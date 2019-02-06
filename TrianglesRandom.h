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
//a * 180 / 3.14159265;
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


class GradientLines : public sf::Drawable, public sf::Transformable {
public:
	GradientLines(int count) : spiral_points(sf::Points, count) {
		Vector2f origin(400.0f, 300.0f);
		this->count = count;
		for (int k = 0; k < count; ++k) {   //720

		}
		for (int i = 0; i < count; i += 3) {
			if (i % 2 == 0) {
				spiral_points[i].position = origin;
				spiral_points[i + 1].position = Vector2f(origin.x + 1.0f, origin.y + 1);
				spiral_points[i + 2].position = Vector2f(origin.x + 2.0f, origin.y + 1);
				origin = Vector2f(origin.x + 2.0f, origin.y + 3);
			}
			else {
				spiral_points[i].position = origin;
				spiral_points[i + 1].position = Vector2f(origin.x + 3.0f, origin.y + 1);
				spiral_points[i + 2].position = Vector2f(origin.x + 2.0f, origin.y + 2);
				origin = Vector2f(origin.x + 2.0f, origin.y + 3);
			}
		}
		for (int j = 0; j < count; ++j) {
			spiral_points[j].color = Color::Red;
		}
	}

	void RandomizeColors() {
		srand((int)time(0));
		for (int i = 0; i < this->count; ++i) {
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
			spiral_points[i].color = Color(Uint8(x), Uint8(y), Uint8(z), Uint8(a));
		}
	}

	void SetColor(sf::Color collyFlower) {
		for (int j = 0; j < count; ++j) {
			spiral_points[j].color = collyFlower;
		}
	}

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		// apply the transform
		states.transform *= getTransform();
		// apply the tileset texture
		states.texture = NULL;
		// draw the vertex array
		target.draw(spiral_points, states);
	}

	VertexArray spiral_points;
	int count;
};

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
		// apply the transform
		states.transform *= getTransform();
		// apply the tileset texture
		states.texture = NULL;
		// draw the vertex array
		target.draw(triangle_vertices, states);
	}

	sf::VertexArray triangle_vertices;
	int count;
};
//	void Fade(sf::Time elapsed) {
//	for (int j = 0; j < count; ++j) {
//	int x = (rand() % 255);
//	int y = (rand() % 255);
//	int z = (rand() % 255);
//	lifeTime -= elapsed;
//	float ratio = lifeTime.asSeconds() / allottedTime.asSeconds();
//	triangle_vertices[j].color.a = static_cast<sf::Uint8>(ratio * 255);
//}
//	}
//class SpiralWheel{
//public:
//    SpiralWheel(){
//        vector<GradientLines> mySpirals(360);
//        float rotate = 0;
//        for (int i = 0; i < 360; ++i) {
//            GradientLines gg;
//            gg.rotate(rotate);
//            int x = (rand() % 255);
//            int y = (rand() % 255);
//            int z = (rand() % 255);
//            int a = (rand() % 255);
//            if((a + 90) <= 255){
//                a +=90;
//            }else{
//                a = 255;
//            }
//            gg.SetColor(Color(Uint8(x),Uint8(y),Uint8(z),Uint8(a)));
//            gg.setOrigin(400.0f,300.f);
//            mySpirals.push_back(gg);
//            rotate += 1.0f;
//        }
//    }
//    vector<GradientLines>& GetSpiralVector(){
//        return mySpirals;
//    }
//
//private:
//    vector<GradientLines> mySpirals;
//};