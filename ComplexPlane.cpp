#include "ComplexPlane.h"


ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size.push_back(pixelWidth, pixelHeight);
	m_aspectRatio = pixelHeight / pixelWidth;
	m_plane_center{0,0};
	m_plane_size =  {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio};
	m_zoomCount = 0;
	State = State::CALCULATING;
	m_Array.resize(pixelWidth* pixelHeight);
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
}

void complexPlane::updateRender()
{
	if(m_state == State::CALCULATING)
	{
		int pixelHeight = m_pixel_size.y;
		int pixelWidth = m_pixel_size.x;
		for(int i = 0; i < pixelHeight;i++)
		{
			for(int j = 0; j < pixelWidth; j++)
			{
				m_vArray[j + i * pixelWidth].position = {(float)j,(float)i};
				
				Vector2i pos;
				pos.push_back(j,i);
				int iterations = countIterations(mapPixelToCoords(pos));
				
			}
		}
	}
}
