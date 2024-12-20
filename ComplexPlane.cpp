#include "ComplexPlane.h"
//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size.x = pixelWidth;
	m_pixel_size.y = pixelHeight;
	m_aspectRatio = pixelHeight / pixelWidth;
	m_plane_center.x = 0;
	m_plane_center.y = 0;
	m_plane_size =  {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio};
	m_zoomCount = 0;
	m_state = State::CALCULATING;
	m_Array.setPrimitiveType(Points);
	m_Array.resize(pixelWidth* pixelHeight);
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_Array);
}

void ComplexPlane::updateRender()
{
	if(m_state == State::CALCULATING)
	{
		int pixelHeight = m_pixel_size.y;
		int pixelWidth = m_pixel_size.x;
		for(int i = 0; i < pixelHeight;i++)
		{
			for(int j = 0; j < pixelWidth; j++)
			{
				m_Array[j + i * pixelWidth].position = {(float)j,(float)i};
				
				Vector2i pos;
				pos.x = j;
				pos.y = i;
				int iterations = countIterations(mapPixelToCoords(pos));
				Uint8 r, g, b;
				iterationsToRGB(iterations, r, g, b);
				
				m_Array[j + i * pixelWidth].color = {r, g, b};
			}
		}
	}
	m_state = State::DISPLAYING;
}

void ComplexPlane::zoomIn()
{
	m_zoomCount++;
	Vector2f newLoc;
	
	newLoc.y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	newLoc.x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	
	m_plane_size.x = newLoc.x;
	m_plane_size.y = newLoc.y;

	m_state = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	Vector2f newLoc;
	
	newLoc.y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	newLoc.x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	
	m_plane_size.x = newLoc.x;
	m_plane_size.y = newLoc.y;

	m_state = State::CALCULATING;

}

void ComplexPlane::setCenter(Vector2i mousePixel)
{
	Vector2f currMouseLocation = mapPixelToCoords(mousePixel);
	
	m_plane_center.x = currMouseLocation.x;
	m_plane_center.y = currMouseLocation.y;
	
	m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
	Vector2f currLocation = mapPixelToCoords(mousePixel);
	m_mouseLoationc.x = currLocation.x;
	m_mouseLoationc.y = currLocation.y;
}

void ComplexPlane::loadText(Text& text)
{
	istringstream strm;
	strm.str("Mandelbrot set\nCenter: (0,0)\nCurser: (test)\nLeft click zoom-in\n Right click zoom-out");
}

int ComplexPlane::countIterations(Vector2f coord)
{
	complex<double> c (coord.x, coord.y);
	complex<double> z  = c;
        size_t i = 0;

        while(abs(z) < 2.0 && i < 64)
        {
	        z = z*z + c;
	        //cout << "z_" << i << "= " << z << endl;
	        //cout << "|z| = " << abs(c) << endl;
	        i++;
	}
	return i;
}

void ComplexPlane::iterationsToRGB(int count, Uint8& r, Uint8& g, Uint8& b)
{
	if(count <= 16)
	{
		r=0;
		g=0;
		b=0;
	}
	else if(count <= 32)
	{
		r=26;
		g=42;
		b=71;
	}
	else if(count <= 48)
	{
		r =160;
		g= 39;
		b=158;
	}
	else
	{
		r =201;
		g=38;
		b=63;
	}
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
	Vector2f newCorrd;
	newCorrd.x = ((mousePixel.x - 0)/ static_cast<float>(1920-0)) * m_plane_size.x+ (m_plane_center.x / 2.0f);
	newCorrd.y = ((mousePixel.y -1080) / static_cast<float>(0-1080)) * m_plane_size.y +(m_plane_center.y / 2.0f);
	return newCorrd;
}
