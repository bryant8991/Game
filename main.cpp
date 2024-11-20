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
	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
           cout << "ERROR"<< endl;
	}

	Text text;
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(36);

return 0;
}
