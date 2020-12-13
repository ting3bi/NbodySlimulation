#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include "Particle.hpp"

using namespace std;

vector<double> operator+(const vector<double> &a, const vector<double> &b); // append vector b after a
vector<double> operator+(const vector<double> &a, const double &k);         // insert a constant at the end of vector a
vector<double> operator/(const vector<double> &a, const double &k);         // every entry of a is divided by k
vector<double> operator*(const vector<double> &v, const double &k);         // multiply every entry of a with k
ostream &operator<<(ostream &out, const vector<double> &v);                 // output the vector
ostream &operator<<(ostream &out, const vector<Particle> &v);               // output the vector for particles
#endif                                                                      // VECTOR_H
