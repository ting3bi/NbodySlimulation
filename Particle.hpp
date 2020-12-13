#if !defined(PARTICLE_H)
#define PARTICLE_H
#include "Vector3D.hpp"
#include <iostream>

using namespace std;

class Particle
{
    double mass;
    double charges;
    double radius;
    Vector3D position;
    Vector3D velocity;

public:
    Particle();
    Particle(const Particle &other); // copy constructor
    double getMass() const { return mass; };
    double getCharges() const { return charges; };
    double getRadius() const { return radius; };
    Vector3D getPosition();
    Vector3D getVelocity();

    void setMass(double mass);
    void setCharges(double charges);
    void setRadius(double radius);
    void setPosition(const Vector3D &position);
    void setVelocity(const Vector3D &velocity);

    friend istream &operator>>(istream &in, Particle &particle);
    friend ostream &operator<<(ostream &out, const Particle &particle);
};

istream &operator>>(istream &in, Particle &particle);
ostream &operator<<(ostream &out, const Particle &particle);

#endif // PARTICLE_H
