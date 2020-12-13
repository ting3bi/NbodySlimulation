#include "ODESolver.hpp"
#include "Vector.hpp"

using namespace std;

/* time independent Euler is
   yi = yim1+ h*f(yim1)
   y0 initial positions and velocities
   y1 = y0+ h*fcn(y0, masses, G)
   y2 = y1 + h*fcn(y0, masses, G)
 */
void ODESolver::euler(ODEProblem &odeproblem, double h)
{
    vector<double> y = odeproblem.getY();
    vector<double> yp = odeproblem.fcn(y);

    y = y + (yp * h);

    odeproblem.setY(y); // update vector y used for the next time step
}

/* the time independent RK4 Method is
   k1 = y_i
   k2 = y_i + h/2*k1
   k3 = y_i + h/2*k2
   k4 = y_i + h*k3
   y_i+1 = y_i + h/6*(k1 + 2*k2 + k3 + k4)
*/
void ODESolver::rk4(ODEProblem &odeproblem, double h)
{
    vector<double> k1, k2, k3, k4, k;
    vector<double> y = odeproblem.getY();
    vector<double> yp = odeproblem.fcn(y);

    k1 = odeproblem.fcn(yp);
    k2 = odeproblem.fcn(yp + (k1 * (h / 2)));
    k3 = odeproblem.fcn(yp + (k2 * (h / 2)));
    k4 = odeproblem.fcn(yp + (k3 * h));
    k = k1 + (k2 * 2) + (k3 * 2) + k4;

    y = y + (k * (h / 6));

    odeproblem.setY(y); // update vector y used for the next time step
}
