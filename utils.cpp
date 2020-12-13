#ifndef UTILS
#define UTILS

#include "utils.hpp"
#include "RandomNumberGenerator.hpp"
#include "Particle.hpp"
#include "Interface.hpp"
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

using namespace std;

/* randomly generate the initial conditions
   mass kg, radius m, number of charges(integer), positions m, velocities m/s
 */
void generateRandomData(ostream &out, double mass_range, double radius_range, int charges_range, double coord_range, double speed_range,
                        int min_nparticles, int max_nparticles)
{
    random_device rd;

    RandomNumberGenerator rg(rd());
    int n = rg.u32_gen(min_nparticles, max_nparticles); // n is the number of particles

    out << n << endl;

    for (int i = 0; i < n; i++)
    {
        double m = rg.double_gen(mass_range / 1e10, mass_range);
        out << m << endl;
        double r = rg.double_gen(radius_range / 1e5, radius_range);
        out << r << endl;
        double q = rg.u32_gen(-charges_range, charges_range);
        out << q << endl;
        double x = rg.double_gen(-coord_range, coord_range);
        double y = rg.double_gen(-coord_range, coord_range);
        double z = rg.double_gen(-coord_range, coord_range);
        out << x << ' ' << y << ' ' << z << ' ' << endl;
        double xp = rg.double_gen(-speed_range, speed_range);
        double yp = rg.double_gen(-speed_range, speed_range);
        double zp = rg.double_gen(-speed_range, speed_range);
        out << xp << ' ' << yp << ' ' << zp << ' ' << endl;
    }
}

#endif // UTILS
