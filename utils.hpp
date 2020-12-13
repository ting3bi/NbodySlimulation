#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

/* randomly generate the initial conditions
   mass kg, radius m, number of charges(integer) positions m, velocities m/s 
 */
void generateRandomData(ostream &out, double mass_range, double radius_range, int charges_range, double coord_range, double speed_range,
                        int min_nparticles, int max_nparticles);

#endif // UTILS_H
