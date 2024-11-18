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

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
	
	vector<Vector2f> vertices;
	vector<Vector2f> points;
	Font font;
if (!font.loadFromFile("arial.ttf"))
{
    cout <<  "ERROR"<< endl;
}

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
		    if (event.type == sf::Event::MouseButtonPressed)
		    {
			Text text;
			text.setFont(font);
			text.setString("Pick 3 points to begin!");
			text.setColor(sf::Color::White);
			text.setCharacterSize(12);
			window.draw(text);
			text.setString("Pick one last point!");
			window.draw(text);

			if (event.mouseButton.button == sf::Mouse::Left)
			{
			    std::cout << "the left button was pressed" << std::endl;
			    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
			    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			    

			    if(vertices.size() < 3)
			    {
				vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			    else if(points.size() == 0)
			    {
				///fourth click
				///push back to points vector
				std::cout << "Pick a point" << endl;
				points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
			    }
			}
		    }
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
	
		if(points.size() > 0)
		{
		    ///generate more point(s)
		    ///select random vertex
		    ///calculate midpoint between random vertex and the last point in the vector
		    ///push back the newly generated coord.
		    int randomPoint = rand() % 3;
		    for(int long i = 1000000; i > 0; i--)
		    {
		   	 float newX = (points.back().x + vertices[randomPoint].x) / 2;
		   	 float newY = (points.back().y + vertices[randomPoint].y) / 2;
		   	 points.push_back(Vector2f(newX,newY));
		    }
		}

		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for(size_t i = 0; i < vertices.size(); i++)
		{
		    RectangleShape rect(Vector2f(10,10));
		    rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
		    
		   if(i == 0)
		   {
		    rect.setFillColor(Color::Blue);
		    window.draw(rect);
		   }
		   else if(i == 1)
		   {
		    rect.setFillColor(Color::Red);
		    window.draw(rect);
		   }
		   else
		   {
		    rect.setFillColor(Color::White);
		    window.draw(rect);
		   }
		}

		for(size_t i = 0; i < points.size(); i++)
		{
		    CircleShape cir(1);
		    cir.setPosition(points[i]);
		  
		    if(i % 2 == 0)
		    cir.setFillColor(Color::Red);
		    else
		    cir.setFillColor(Color::Green);
		   
		    
		    window.draw(cir);
		}
		window.display();
	}
}
