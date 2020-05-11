#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

struct Particle2f
{
    sf::Vector2f pos, vel;
    float mass, charge, radius;

    Particle2f(const sf::Vector2f& pos_, const sf::Vector2f vel_ = sf::Vector2f(), float mass_ = 1, float charge_ = 0, float radius_ = 0)
    :pos(pos_)
    ,vel(vel_)
    ,mass(mass_)
    ,charge(charge_)
    ,radius(radius_)
    {}

    void move(float dt) {
        pos += vel * dt;
    }

    void applyForce(const sf::Vector2f& force, float dt) {
        vel += force * (dt / mass);
    }
};

void applyGravitationnalForce(Particle2f& a, Particle2f& b, float g, float dt)
{
    sf::Vector2f diff = b.pos - a.pos;
    float length = hypotf(diff.x, diff.y);
    sf::Vector2f force = diff * a.mass * b.mass * g / length / length / length;

    a.applyForce( force, dt);
    b.applyForce(-force, dt);
}

void applyElasticForce(Particle2f&a, Particle2f& b, float distance, float k, float dt)
{
    sf::Vector2f diff = b.pos - a.pos;
    float length = hypotf(diff.x, diff.y);
    
    sf::Vector2f force = diff / length * (length-distance) * k;

    b.applyForce(-force, dt);
    a.applyForce( force, dt);
}