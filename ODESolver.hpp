#if !defined(ODE_SOLVER_H)
#define ODE_SOLVER_H
#include "ODEProblem.hpp"

class ODESolver
{
public:
    static void euler(ODEProblem &odeproblem, double step_size);
    static void rk4(ODEProblem &odeproblem, double step_size);
};

#endif // ODE_SOLVER_H
