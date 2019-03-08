#include <SFML/Graphics.hpp>
#include <iostream>

const int LENGHT = 1000;
const int HEIGHT = 800;
const int SIZE = 30;
const sf::Vector2f PLAYER_SIZE = {100, 30};

int main()
{
    sf::RenderWindow window(sf::VideoMode(LENGHT, HEIGHT), "Player");

    sf::Vector2f pos = {30, 30};
    sf::Vector2f speed = {300, 300};
    sf::RectangleShape ball;
    ball.setSize(sf::Vector2f(SIZE, SIZE));
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(SIZE / 2, SIZE / 2);

    sf::RectangleShape player;
    player.setSize(PLAYER_SIZE);
    sf::Vector2f PlayerPosition = {LENGHT / 2, HEIGHT * 0.9};
    player.setOrigin(PLAYER_SIZE.x / 2, PLAYER_SIZE.y / 2);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && PlayerPosition.x <= LENGHT - PLAYER_SIZE.x / 2)
        {
            PlayerPosition.x += 700 * deltatime;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && PlayerPosition.x >= PLAYER_SIZE.x / 2)
        {
            PlayerPosition.x -= 700 * deltatime;
        }

        if (ball.getPosition().x <= SIZE / 2 && speed.x < 0 || ball.getPosition().x >= LENGHT - SIZE / 2 && speed.x > 0)
        {
            speed.x = -speed.x * 1.01;
        }
        if (ball.getPosition().y <= SIZE / 2 && speed.y < 0 || player.getGlobalBounds().intersects(ball.getGlobalBounds()) && speed.y > 0)
        {
            speed.y = -speed.y * 1.01;
        }
        if (ball.getPosition().y > HEIGHT + SIZE * 2)
        {
            window.close();
        }

        pos.x += speed.x * deltatime;
        pos.y += speed.y * deltatime;
        ball.setPosition(pos);
        player.setPosition(PlayerPosition);
        window.clear();
        window.draw(ball);
        window.draw(player);
        window.display();

    }

    return 0;
}