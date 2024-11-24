#include "ComplexPlane.h"


ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
m_pixel_size.push_back(pixelWidth, pixelHeight);
m_aspectRatio = pixelHeight / pixelWidth;
m_plane_center{0,0};
m_plane_size =  {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio};
m_zoomCount = 0;
 
}
