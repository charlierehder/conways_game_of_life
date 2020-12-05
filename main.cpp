#include <SFML/Graphics.hpp>
#include "parser.hpp"


int main()
{
    Environment *env = fileToEnv("test_file.txt");
    int width = env->_width;
    int height = env->_height;
    int x_scale = 1000 / width;
    int y_scale = 1000 / height;

    // initialize the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Big Dick Plays?");

    // initialize each cell in the window
    sf::RectangleShape** shapes = new sf::RectangleShape*[width];
    for (int i = 0; i < width; i++) {
        shapes[i] = new sf::RectangleShape[height];
        for (int j = 0; j < height; j++) {
            shapes[i][j] = sf::RectangleShape(sf::Vector2f(x_scale, y_scale));
            shapes[i][j].setPosition(i*x_scale, j*y_scale);
            shapes[i][j].setFillColor(sf::Color(228,228,219)); 
        }
    }

    sf::Time refreshDelay = sf::seconds(0.5);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(91,91,91));


        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (env->_cells[i][j]) {
                    window.draw(shapes[i][j]);
                }
            }
        }

        window.display();

        env->updateEnvironment();

        sf::sleep(refreshDelay);
    }

    return 0;
}