#include <SFML/Graphics.hpp>

#include "AssetManager.hpp"

int main()
{
  //create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  //run the program as long as the window is open
  while(window.isOpen())
  {
    //check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
        
    while(window.pollEvent(event))
    {
      //"close requested" event: we close the window
      if(event.type == sf::Event::Closed)
        window.close();
    }

    AssetManager::Instance().LoadContent();

    const sf::Texture woot = AssetManager::Instance().GetTexture(0);
    sf::Sprite sprite(woot);

    //clear the window with black color
    window.clear(sf::Color::Black);

    //draw everything here...
    window.draw(sprite);

    //end the current frame
    window.display();
  }
}
