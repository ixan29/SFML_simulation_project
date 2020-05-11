#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#include <cmath>
#include "../Particle2f.h"

using namespace std;

int main()
{
    Particle2f left  ({100,300}, {0,0}, 1);
    Particle2f right ({1100,300}, {0,0}, 1);

    const int numParticles = 500;
    sf::Vector2f diff = (right.pos-left.pos) / (float)numParticles;
    float distance = hypotf(diff.x, diff.y);

    std::vector<Particle2f> particles;
    particles.reserve(numParticles);

    particles.push_back(left);

    for(float i=1; i<numParticles; i++) {
        particles.push_back(
            Particle2f(left.pos+diff*i, {0,0}, 1)
        );
    }

    particles.push_back(right);

    float dt = 0.05;
    float k = 30;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1200, 600), "My window");

    float count=0;
    particles.front().pos.y += 1;
    particles.back().pos.y -= 1;

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

        count++;

        if(particles.front().pos.y>300)
        {
            particles.front().pos.y = 300 + 200 * sin(count/200);

            if(particles.front().pos.y < 300) {
                particles.front().pos.y = 300;
            }
        }

        if(particles.back().pos.y<300)
        {
            particles.back().pos.y = 300 - 200 * sin(count/100);

            if(particles.back().pos.y > 300) {
                particles.back().pos.y = 300;
            }
        }

        for(size_t i=0; i<particles.size()-1; i++) {
            applyElasticForce(particles[i], particles[i+1], 0, k, dt);
        }

        for(size_t i=1; i<particles.size()-1; i++) {
            particles[i].move(dt);
        }

        for(size_t i=0; i<particles.size(); i++) {
            sf::CircleShape circle;
            circle.setPosition(particles[i].pos);
            circle.setRadius(distance/2);
            window.draw(circle);
        }

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}