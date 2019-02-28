#include <SFML/Graphics.hpp>
#include <iostream>

const int LENGHT = 1000;
const int HEIGHT = 800;
const int SIZE = 30;

int main()
{
    sf::Vector2f pos = {30, 30};
    sf::Vector2f speed = {300, 300};
    sf::RenderWindow window(sf::VideoMode(LENGHT, HEIGHT), "Player");
    sf::RectangleShape ball;
    ball.setSize(sf::Vector2f(SIZE,SIZE));
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

        if (ball.getPosition().x <= SIZE/2 && speed.x < 0 || ball.getPosition().x >= LENGHT - SIZE/2 && speed.x > 0)
        {
            speed.x = -speed.x*1.01;
        }
        if (ball.getPosition().y <= SIZE/2 && speed.y < 0 || ball.getPosition().y >= HEIGHT - SIZE/2 && speed.y > 0)
        {
            speed.y = -speed.y*1.01;
        }

        pos.x += speed.x * deltatime;
        pos.y += speed.y * deltatime;
        ball.setPosition(pos);
        ball.setOrigin(SIZE/2,SIZE/2);
        window.clear();
        window.draw(ball);
        window.display();
        //std::cout << "x:" << ball.getPosition().x << "y: " << ball.getPosition().y << std::endl;
        std::cout << speed.x << std::endl;
    }

    return 0;
}