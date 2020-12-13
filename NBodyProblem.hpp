#ifndef N_BODY_PROBLEM_H
#define N_BODY_PROBLEM_H

#include <vector>
#include <iostream>
#include "Particle.hpp"
#include "ODEProblem.hpp"
#include <vector>

using namespace std;

class NBodyProblem : public ODEProblem
{
private:
  double G; // gravitational constant
  double k; // coulomb's constant
  double e; // elementary charge

  vector<Particle> particles; // the vector contains all informations of particles
  vector<double> masses;      // vector for masses of all particles
  vector<double> radiuses;    //vector for radiuses of all particles
  vector<double> charges;     // charges of all particles
  vector<double> y;           // vector {x1, y1, z1, vx1, vy1, vz1, x2, y2, z2, vx2, vy2, vz2,....}

  /* collisions detection by comparing the distance between
     centers of 2 particle with the sum of radias of two particles*/
  bool isCollision();

public:
  // read input files and get the initial values
  // constructor of NBodyProblem
  NBodyProblem(vector<Particle> &particles, const double G, const double k, const double e);
  ~NBodyProblem() {} // destrctor

  // differential equations for the nbody problem, s' = v', v' = F/m
  vector<double> fcn(const vector<double> &yData);
  vector<double> getY();
  void setY(vector<double> &y);
  vector<Vector3D> getPositions();
  vector<Vector3D> getVelocities();
  vector<Particle> &getParticles();
  Vector3D computeForce(int q, const vector<double> &positions); // force for computing F/m
};

#endif // N_BODY_SOLVER_H
