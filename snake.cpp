#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

const int BLOCK_SIZE = 20;
const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game");
    sf::CircleShape food(BLOCK_SIZE / 2);
    food.setFillColor(sf::Color::Red);
    sf::RectangleShape snake(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    snake.setFillColor(sf::Color::Blue);
    std::vector<sf::RectangleShape> snakeBody;
    snakeBody.push_back(snake);
    int directionX = 1, directionY = 0;
    int foodX = (WIDTH / BLOCK_SIZE) / 2 * BLOCK_SIZE;
    int foodY = (HEIGHT / BLOCK_SIZE) / 2 * BLOCK_SIZE;
    food.setPosition(foodX, foodY);
    sf::Clock clock;
    int score = 0;
    int highScore = 0;

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("/Users/lilyeli/Desktop/PlaywriteNL-VariableFont_wght.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
    }

    // Create the text objects
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(10, 40);

    sf::Text statusText;
    statusText.setFont(font);
    statusText.setCharacterSize(24);
    statusText.setFillColor(sf::Color::White);
    statusText.setPosition(10, 70);

    // Get the player's name
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    sf::Text nameText;
    nameText.setFont(font);
    nameText.setCharacterSize(24);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition(10, 100);
    nameText.setString("Player: " + playerName);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && directionY != 1)
                    directionX = 0, directionY = -1;
                else if (event.key.code == sf::Keyboard::Down && directionY != -1)
                    directionX = 0, directionY = 1;
                else if (event.key.code == sf::Keyboard::Left && directionX != 1)
                    directionX = -1, directionY = 0;
                else if (event.key.code == sf::Keyboard::Right && directionX != -1)
                    directionX = 1, directionY = 0;
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 0.1f) {
            sf::Vector2f newPosition = snakeBody[0].getPosition();
            newPosition.x += directionX * BLOCK_SIZE;
            newPosition.y += directionY * BLOCK_SIZE;

            if (newPosition.x < 0 || newPosition.x >= WIDTH ||
                newPosition.y < 0 || newPosition.y >= HEIGHT) {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }

            for (int i = snakeBody.size() - 1; i > 0; --i)
                snakeBody[i].setPosition(snakeBody[i - 1].getPosition());

            snakeBody[0].setPosition(newPosition);

            if (snakeBody[0].getPosition() == food.getPosition()) {
                sf::RectangleShape newPart(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                newPart.setFillColor(sf::Color::Blue);
                snakeBody.push_back(newPart);
                foodX = std::rand() % (WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
                foodY = std::rand() % (HEIGHT / BLOCK_SIZE) * BLOCK_SIZE;
                food.setPosition(foodX, foodY);

                // Increment the score
                ++score;

                // Update the high score
                if (score > highScore) {
                    highScore = score;
                }

                // Update the score text
                scoreText.setString("Score: " + std::to_string(score));
                highScoreText.setString("High Score: " + std::to_string(highScore));
            }

            clock.restart();
        }

        window.clear();
        for (const auto& part : snakeBody)
            window.draw(part);
        window.draw(food);
        window.draw(scoreText); // Draw the score text
        window.draw(highScoreText); // Draw the high score text
        window.draw(statusText); // Draw the status text
        window.draw(nameText); // Draw the player's name
        window.display();
    }

    return 0;
}
