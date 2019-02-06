#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iterator>
//Ear cliping one day
bool PlaceDot(Vector2f lastOne, Vector2f mousPos) {
	float dt = 6.0f;
	float sqrty = sqrt(pow((mousPos.x - lastOne.x), 2) + pow((mousPos.y - lastOne.y), 2));
	if (sqrty > dt) {
		return true;
	}
	return false;
}

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
		while (j < (int)positionsClicked.size()) {
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