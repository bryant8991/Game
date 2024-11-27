// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main();
{
	// Create a video mode object
	//VideoMode vm(1920, 1080);
	// Create and open a window for the game
	int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);

	RenderWindow window(vm, "Mandelbrot!!", Style::Default);

	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
           cout << "ERROR"<< endl;
	}
	ComplexPlane h(pixelWidth, pixelHight); 
	Text text;
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(36);
	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == Event::Closed)
		    {
					// Quit the game when the window is closed
					window.close();
		    }
		}
	}

return 0;
}
