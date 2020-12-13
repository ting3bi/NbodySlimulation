#if !defined(NBODY_SOLVER_H)
#define NBODY_SOLVER_H

#include "NBodyProblem.hpp"
#include <ostream>

using namespace std;

class NBodySolver
{
public:
    // using the odesolver to solve the nbody problems
    static void solve(const double h, const int tend, NBodyProblem &nbody, ostream &out, string method);
};

#endif // NBODY_SOLVER_H
