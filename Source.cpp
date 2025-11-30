#include "Header1.h"
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), L"Нахуй ты смотришь ?");

    Texture TextureInfoPanel;
    TextureInfoPanel.loadFromFile("image/прогресс.png");
    RectangleShape GameInfoPanel(Vector2f(1280, 113));
    GameInfoPanel.setTexture(&TextureInfoPanel);
    GameInfoPanel.setPosition(Vector2f(0, 0));

    ////////////////////////////////////////////////////////////////////////////
    Texture Background;
    Background.loadFromFile("image/космос.png");
    RectangleShape gamingBack(Vector2f(1280, 720));
    gamingBack.setTexture(&Background);

    RectangleShape gamingBack2(Vector2f(1280, 720));
    gamingBack2.setTexture(&Background);
    gamingBack2.setPosition(Vector2f(1280, 0));
    ////////////////////////////////////////////////////////////////////////////
    Vector2f pos;
    Clock clock;
    float time=0.f, time_player = 0.f, time_back = 0.f;
    ////////////////////////////////////////////////////////////////////////////
    //корабль
    Vector2f moveRec;
    Texture shatl;
    shatl.loadFromFile("image/корабл.png");
    RectangleShape player(Vector2f(65,45));
    player.setTexture(&shatl);
    player.setPosition(Vector2f(80, 380));
    //////////////////////////////////////////////////////////
    bool left = false, right = false, up = false, down = false;//местоположение игрока
    //////////////////////////////////////////////////////////
    while (window.isOpen())
    {
        time = clock.getElapsedTime().asMicroseconds();

        // вычисляем dt в секундах на основе существующего использования clock
        float dt = time / 1000000.f; // учтите: time == 0 здесь, лучше передавать dt в функцию

        time_player = time / 2000.f;
        time_back = time / 6000.f;
        clock.restart();

        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
           
        }
        ///////////////////////////////////////////////////
        gamingBack.move({ -0.2f * time_back, 0.f });
        pos = gamingBack.getPosition();
        if (pos.x < -1280.f)
            gamingBack.setPosition({ 1280.f, pos.y });
                                                                 /////backscreen
        gamingBack2.move({ -0.2f * time_back, 0 });
        pos = gamingBack2.getPosition();
        if (pos.x < -1280.f)
            gamingBack2.setPosition({ 1280.f, pos.y });
        ////////////////////////////////////////////////////
        player.move(moveRec);
        pos = player.getPosition();
        if (pos.x > 1200.f)player.setPosition({ 1200.f,pos.y });
        if (pos.x < 50.f)player.setPosition({ 50.f,pos.y });
        if (pos.y > 670.f)player.setPosition({ pos.x,670 });
        if (pos.y < 120.f)player.setPosition({ pos.x,120 });
                                                                                /////////////выход за границы
        if ((pos.x > 1200) && (pos.y < 120)) player.setPosition({ 1200.f, 120.f });
        if ((pos.x > 1200) && (pos.y > 670)) player.setPosition({ 1200.f, 670.f });
        if ((pos.x < 50) && (pos.y < 120)) player.setPosition({ 50.f, 120.f });
        if ((pos.x < 50) && (pos.y > 670)) player.setPosition({ 50.f, 670.f });

        ////////////////////////////////////////////////////
        playermove(player, moveRec, dt);
        window.clear();
        window.draw(gamingBack2);
        window.draw(gamingBack);
        window.draw(GameInfoPanel);
        window.draw(player); 
        window.display();
    }
}
