#include "NBodyProblem.hpp"
#include <cmath>
#include <string>
#include <cstdint>
#include "Vector3D.hpp"
#include "Vector.hpp"

using namespace std;

const string RK4 = "rk4";
const string EULER = "euler";

NBodyProblem::NBodyProblem(vector<Particle> &particles, const double G, const double k, const double e)
{
  this->particles = particles;
  this->G = G;
  this->k = k;
  this->e = e;

  for (size_t i = 0; i < particles.size(); ++i)
  {
    this->masses.push_back(particles.at(i).getMass());
    this->charges.push_back(particles.at(i).getCharges());
    this->radiuses.push_back(particles.at(i).getRadius());

    Vector3D position = particles[i].getPosition();
    Vector3D velocity = particles[i].getVelocity();

    this->y.push_back(position.getX());
    this->y.push_back(position.getY());
    this->y.push_back(position.getZ());
    this->y.push_back(velocity.getX());
    this->y.push_back(velocity.getY());
    this->y.push_back(velocity.getZ());
  }
}

vector<double> NBodyProblem::getY()
{
  return this->y;
}

void NBodyProblem::setY(vector<double> &y)
{
  this->y = y;
  vector<Vector3D> positions = getPositions();
  vector<Vector3D> velocities = getVelocities();

  for (size_t i = 0; i < y.size() / 6; ++i)
  {
    this->particles[i].setPosition(positions[i]);
    this->particles[i].setVelocity(velocities[i]);
  }
}

vector<Vector3D> NBodyProblem::getPositions()
{
  vector<Vector3D> positions;
  for (size_t i = 0; i < y.size() / 6; ++i)
  {
    positions.push_back(Vector3D(y[6 * i], y[6 * i + 1], y[6 * i + 2]));
  }

  return positions;
}

vector<Vector3D> NBodyProblem::getVelocities()
{
  vector<Vector3D> velocities;
  for (size_t i = 0; i < y.size() / 6; ++i)
  {
    velocities.push_back(Vector3D(y[6 * i + 3], y[6 * i + 4], y[6 * i + 5]));
  }
  return velocities;
}

vector<Particle> &NBodyProblem::getParticles()
{
  return particles;
}

// collision detection
bool NBodyProblem::isCollision()
{
  for (size_t i = 0; i < y.size(); i++)
  {
    for (size_t j = i + 1; j < y.size() / 6; j++)
    {
      const double xI = y[6 * i];
      const double yI = y[6 * i + 1];
      const double zI = y[6 * i + 2];
      const double xJ = y[6 * j];
      const double yJ = y[6 * j + 1];
      const double zJ = y[6 * j + 2];
      const double rI = radiuses[i];
      const double rJ = radiuses[j];
      double dx = xI - xJ;
      dx *= dx;
      double dy = yI - yJ;
      dy *= dy;
      double dz = zI - zJ;
      dz *= dz;
      const double distance = sqrt(dx + dy + dz);

      if (distance <= rI + rJ)
      {
        return true;
      }
    }
  }
  return false;
}

Vector3D NBodyProblem::computeForce(int q, const vector<double> &positions)
{
  // Computes force for particle q
  // Vector F is the force applied on each particle along  x y z directions
  Vector3D F;
  Vector3D Fg(0, 0, 0);         // gravitational force
  Vector3D Fc(0, 0, 0);         // coulomb's force
  Vector3D sqsk;                //sqsk is the distance along each direction between particle q and particle k
  int n = positions.size() / 3; // number of particles

  // sum up the forces applied on each particle
  for (int k = 0; k < n; k++)
  {
    if (k == q) //when k=q, no force applied.
      continue;

    // distance between 2 particles along each of directions
    double x = positions[3 * q] - positions[3 * k];
    double y = positions[3 * q + 1] - positions[3 * k + 1];
    double z = positions[3 * q + 2] - positions[3 * k + 2];

    sqsk.setX(x);
    sqsk.setY(y);
    sqsk.setZ(z);

    double t = x * x + y * y + z * z;
    t *= sqrt(t); // t is the distance between two particles |sq-sk|

    sqsk = sqsk / t;

    Fg = Fg + (sqsk * masses[k]);
    Fc = Fc + (sqsk * charges[k] * e * charges[q] * e);
  }
  Fg = Fg * (-G);
  Fc = (Fc / masses[q]) * (-k);

  return Fg + Fc;
}

/*
  the differential equations:
  [s', v'] = f(t, v, s)

  f(t, v, s) = [v(t), ]
  [s_(n+1), v_(n+1)] = [s_(n+1), v_(n+1)] + 1/6 * h * (k1 + 2*k2 + 2*k3 + k4)
  t_(n+1) = t_n + h
  the system is
  s_q' = v_q
  v_q' = a_q where a is F_q/m_q
*/

vector<double> NBodyProblem::fcn(const vector<double> &yData)
{
  // y contains (position,velocity) for particle 0, 1, 2,
  //cout << yData << endl;
  // extract positions from y vector
  int nparticles = yData.size() / 6;
  vector<double> positions(nparticles * 3, 0);
  vector<double> charges(nparticles, 0);

  for (int q = 0; q < nparticles; q++)
  {
    // y contains xq,yq,zq,vxq,vyq,vzq....
    //positions -> xq,yq,zq,
    positions[3 * q] = yData[6 * q];
    positions[3 * q + 1] = yData[6 * q + 1];
    positions[3 * q + 2] = yData[6 * q + 2];
  }

  // construct the differential equations
  vector<double> yp(yData.size(), 0);
  for (int q = 0; q < nparticles; q++)
  {
    /*
     y[6*q], y[6*q+1],y[6*q+2] positions, position_prime=velocity
     y[6*q+3], y[6*q+4],y[6*q+5] velocities, velocity_prime=force
    */
    yp[6 * q] = yData[6 * q + 3];
    yp[6 * q + 1] = yData[6 * q + 4];
    yp[6 * q + 2] = yData[6 * q + 5];

    Vector3D F = computeForce(q, positions);

    yp[6 * q + 3] = F.getX();
    yp[6 * q + 4] = F.getY();
    yp[6 * q + 5] = F.getZ();
  }
  //cout << yp << endl;
  return yp;
}
