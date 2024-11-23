#pragma once
#include <iostream>
#include <complex>
using namespace std;
using namespace sf;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

enum STATE {CALCULATING , DISPLAYING};

class ComplexPlane : public sf::Drawable
{
public:
	ComplexPlane(int pixelWidth, int pixelHeight);
	void draw(RenderTarget& target, RenderStates states) const;
	void updateRender();
 	void zoomOut();
	void setCenter(Vector2i mousePixel);
	void setMouseLocation(Vector2i mousPixel);
	void loadText(Text& text);
	size_t countIterations(Vector2f coord);
	void countIterations(Vector2f coord);
	Vector2f mapPixelToCoords(Vector2i mousePixel);
}
