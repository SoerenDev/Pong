#include <SFML/Graphics.hpp>
#include <iostream>

const int LENGHT = 1000;
const int HEIGHT = 800;
const int RADIUS = 20;

int main()
{
    sf::Vector2f pos = {30, 30};
    sf::Vector2f speed = {300, 300};
    sf::RenderWindow window(sf::VideoMode(LENGHT, HEIGHT), "Player");
    sf::CircleShape shape;
    shape.setRadius(RADIUS);
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

        if (shape.getPosition().x <= RADIUS && speed.x < 0 || shape.getPosition().x >= LENGHT - RADIUS && speed.x > 0)
        {
            speed.x = -speed.x*1.01;
        }
        if (shape.getPosition().y <= RADIUS && speed.y < 0 || shape.getPosition().y >= HEIGHT - RADIUS && speed.y > 0)
        {
            speed.y = -speed.y*1.01;
        }

        pos.x += speed.x * deltatime;
        pos.y += speed.y * deltatime;
        shape.setPosition(pos);
        shape.setOrigin(RADIUS,RADIUS);
        window.clear();
        window.draw(shape);
        window.display();
        //std::cout << "x:" << shape.getPosition().x << "y: " << shape.getPosition().y << std::endl;
        std::cout << speed.x << std::endl;
    }

    return 0;
}