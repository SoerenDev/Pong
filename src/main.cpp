#include <SFML/Graphics.hpp>
#include <iostream>

const int LENGHT = 1000;
const int HEIGHT = 800;

int main()
{
    sf::Vector2f pos = {100, 100};
    sf::Vector2f speed = {10, 10};
    sf::RenderWindow window(sf::VideoMode(LENGHT, HEIGHT), "Player");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::White);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time delta = clock.getElapsedTime();
        double deltatime = delta.asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (shape.getPosition().x <= 0 && speed.x < 0 || shape.getPosition().x >= LENGHT - 35 && speed.x > 0)
        {
            speed.x = -speed.x;
        }
        if (shape.getPosition().y <= 0 && speed.y < 0 || shape.getPosition().y >= HEIGHT - 35 && speed.y > 0)
        {
            speed.y = -speed.y;
        }

        pos.x += speed.x * deltatime;
        pos.y += speed.y * deltatime;
        shape.setPosition(pos);
        window.clear();
        window.draw(shape);
        window.display();
        std::cout << "x:" << shape.getOrigin().x << "y: " << shape.getPosition().y << std::endl;
    }

    return 0;
}