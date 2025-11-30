#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

void playermove(RectangleShape& player, const Vector2f& moveRec, float dt)
{
    float time = 0.f;
    float time_player = 0.f;
    float speed = 325.f; // пикселей в секунду

    sf::Vector2f dir(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dir.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dir.x += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dir.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dir.y += 1.f;

    if (dir.x != 0.f || dir.y != 0.f)
    {
        float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if (len != 0.f) dir /= len;
        player.move(dir * speed * dt);
    }

}