#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    system("chcp 1251>nul");
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 900, 800 }), "SFML window");
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        // Ну типо да ввыаыа
        window.clear();
        window.display();
        
    }
}