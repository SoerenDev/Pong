#include <SFML/Graphics.hpp>

const int LENGHT = 1000;
const int HEIGHT = 800;
const int SIZE = 30;
const sf::Vector2f PLAYER_SIZE(100.f,30.f);

double deltatime;
sf::Vector2f playerPosition;
sf::RectangleShape player;
sf::RectangleShape ball;
sf::Vector2f speed(300.f,300.f);
sf::Vector2f pos(30.f,30.f);
sf::RenderWindow window(sf::VideoMode(LENGHT, HEIGHT), "Player");

void player_movement();
void ball_movement();
void game_over();
void ball_physics();
void draw();

int main()
{
  
    ball.setSize(sf::Vector2f(SIZE, SIZE));
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(SIZE / 2, SIZE / 2);
   
    player.setSize(PLAYER_SIZE);
    playerPosition = {LENGHT / 2, HEIGHT * 0.9};
    player.setOrigin(PLAYER_SIZE.x / 2, PLAYER_SIZE.y / 2);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time delta = clock.getElapsedTime();
        deltatime = delta.asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        player_movement();

        ball_movement();

        game_over();

        ball_physics(); 
        
        draw();
    
    }

    return 0;
}

void draw() {
    window.clear();
    window.draw(ball);
    window.draw(player);
    window.display();
}

void ball_physics() {

    pos.x += speed.x * deltatime;
    pos.y += speed.y * deltatime;
    ball.setPosition(pos);

}

void game_over() {

    if (ball.getPosition().y > HEIGHT + SIZE * 2)
    {
        window.close();
    }

}

void player_movement() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerPosition.x <= LENGHT - PLAYER_SIZE.x / 2)
    {
        playerPosition.x += 700 * deltatime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerPosition.x >= PLAYER_SIZE.x / 2)
    {
        playerPosition.x -= 700 * deltatime;
    }
    
    player.setPosition(playerPosition);

}

void ball_movement() {

    if (ball.getPosition().x <= SIZE / 2 && speed.x < 0 || ball.getPosition().x >= LENGHT - SIZE / 2 && speed.x > 0)
    {
        speed.x = -speed.x * 1.01;
    }

    if (ball.getPosition().y <= SIZE / 2 && speed.y < 0 || player.getGlobalBounds().intersects(ball.getGlobalBounds()) && speed.y > 0)
    {
        speed.y = -speed.y * 1.01;
    }

}