#include "Particle.hpp"

Particle::Particle()
{
    mass = 0;
    charges = 0;
    radius = 0;
}

Particle::Particle(const Particle &other) : mass{other.mass}, charges{other.charges}, radius{other.radius}, position{other.position}, velocity{other.velocity}
{
}

Vector3D Particle::getPosition()
{
    return position;
}

Vector3D Particle::getVelocity()
{
    return velocity;
}

void Particle::setMass(double mass)
{
    this->mass = mass;
}

void Particle::setCharges(double charges)
{
    this->charges = charges;
}
void Particle::setRadius(double radius)
{
    this->radius = radius;
}

void Particle::setPosition(const Vector3D &position)
{
    this->position = position;
}
void Particle::setVelocity(const Vector3D &velocity)
{
    this->velocity = velocity;
}
istream &operator>>(istream &in, Particle &particle)
{
    in >> particle.mass >> particle.charges >> particle.radius >> particle.position >> particle.velocity;
    return in;
}

ostream &operator<<(ostream &out, const Particle &particle)
{
    out << particle.position << ' ' << particle.velocity;

    return out;
}
