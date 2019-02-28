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
    sf::CircleShape ball;
    ball.setRadius(RADIUS);
    ball.setFillColor(sf::Color::White);
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

        if (ball.getPosition().x <= RADIUS && speed.x < 0 || ball.getPosition().x >= LENGHT - RADIUS && speed.x > 0)
        {
            speed.x = -speed.x*1.01;
        }
        if (ball.getPosition().y <= RADIUS && speed.y < 0 || ball.getPosition().y >= HEIGHT - RADIUS && speed.y > 0)
        {
            speed.y = -speed.y*1.01;
        }

        pos.x += speed.x * deltatime;
        pos.y += speed.y * deltatime;
        ball.setPosition(pos);
        ball.setOrigin(RADIUS,RADIUS);
        window.clear();
        window.draw(ball);
        window.display();
        //std::cout << "x:" << ball.getPosition().x << "y: " << ball.getPosition().y << std::endl;
        std::cout << speed.x << std::endl;
    }

    return 0;
}