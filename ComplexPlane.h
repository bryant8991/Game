#pragma once
#include <iostream>
#include <complex>
using namespace std;
using namespace sf;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

enum State {CALCULATING , DISPLAYING};

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
	void zoomIn();
private:
	int countIterations(Vector2f corrd);
	void iterationsToRGB(size_t count, Unit8& r, Unit8& g,Unit8& b);
	Vector2f mapPixelToCoords(Vector2i mousePixel);
	VertexArray m_Array(Points);
	State m_state;
	Vector2f m_mouseLoationc;
	Vector2i m_pixel_size;
	Vector2f m_plane_center;
	Vector2f m_plane_size;
	int m_zoomCount;
	float m_aspetcRatio;
}
