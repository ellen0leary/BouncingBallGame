
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 900), "Bouncing Ball");
    
    //Player class and sprite
    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(190, 800);

    Player player;
    player.move.setPos(190, 800);

    //Platforms
    sf::RectangleShape rect(sf::Vector2f(60, 10));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(100, 600);

    Platform platform;
    platform.move.setPos(100, 600);


    bool spacePressed = false;
    int movementTime = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                std::cout << "Key Pressed" << std::endl;
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "space Pressed" << std::endl;
                    movementTime = 200;
                }
            }
        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //move left
        player.move.moveLeft();
                }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //move right
        player.move.moveRight();
        }

        if (movementTime > 0) {
            player.move.move();
            circle.setPosition(player.move.getXPosition(), player.move.getYPosition());
            platform.move.gravity();
            rect.setPosition(platform.move.getXPosition(), platform.move.getYPosition());
            movementTime--;
        }
        player.move.gravity();
        circle.setPosition(player.move.getXPosition(), player.move.getYPosition());

        window.clear();
        window.draw(circle);
        window.draw(rect);
        window.display();
    }

    return 0;
}


//player
//enemy
//plateforms
    //static
    // falling
    //boost
//items

//poisisitoin - movement
// collider