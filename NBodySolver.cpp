#include "NBodySolver.hpp"
#include "ODESolver.hpp"
#include <vector>
#include "Vector.hpp"

using namespace std;

void NBodySolver::solve(const double h, const int tend, NBodyProblem &nbody, ostream &out, string method)
{
    vector<Particle> particles = nbody.getParticles();

    out << particles << endl;

    //out << setw(8) << i * h << endl;

    for (int i = 0; i < tend / h; ++i)
    {
        if (method == "euler")
        {
            ODESolver::euler(nbody, h);
        }
        else
        {
            ODESolver::rk4(nbody, h);
        }

        particles = nbody.getParticles();

        out << particles << endl;
    }
}
