#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#include "../Particle2f.h"

using namespace std;

int main()
{
    std::vector<Particle2f> planets = {
        Particle2f({300, 300}, {0 , 0.4}, 5, 0, 15),
        Particle2f({500, 300}, {0 , -2}, 1, 0, 10),
    };

    float dt = 0.05;
    float g = 300;

    // create the window
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        for(size_t i=1; i<planets.size(); i++) {
            for(size_t j=0; j<i ; j++) {
                applyGravitationnalForce(planets[i], planets[j], g, dt);
            }
        }

        for(auto& planet : planets) {
            planet.move(dt);
        }

        for(auto& planet : planets)
        {
            sf::CircleShape shape;
            shape.setPosition(planet.pos);
            shape.setRadius(planet.radius);

            window.draw(shape);
        }


        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}