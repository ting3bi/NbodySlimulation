/*
   All input files should in this format:
   total number of particles
   mass of particle 1 (kg)
   radius of particle 1 (m)
   number of charges of particles 1(integer)
   x   y   z  (cartesian coordinates in m)
   vx  vy  vz (velocity also each direction in m/s)
   mass of particle 2
   radius of particle 2
   number of charges of particles 1(integer)
   x   y   z  (cartesian coordinates in m)
   vx  vy  vz (velocity also each direction in m/s)
   repeat for each particle
*/

#include <iostream>
#include <string>
#include <fstream>
#include "NBodyProblem.hpp"
#include "NBodySolver.hpp"
#include "utils.hpp"
#include "Interface.hpp"
#include "Particle.hpp"

using namespace std;

/*

        option 1: randomly generate the number of particles and all initial values, then
                    write the initial values and results into files.

                    ./main <option> <data_filename> [output_filename=results.txt] [tend=1000] [method = euler]

        option 2: user inputs the file and results will be written into a file.

                    ./main <option> <data_filename> [output_filename=results.txt] [tend=1000] [method = euler]

        option 3: the solar system will be simulated and the result will be write into a file.
                  The solar system includes the sun, the eight planets and the pluto.
                  The sun is at the origins, and the initial positions of other planets are at y axis and initial
                  velocities are along x-axis except jupiter. The jupiter are set at x-axis and the velocity is
                  along y axis.

                    ./main <option> [output_filename=results.txt] [tend=1000] [method = euler]

  */

int main(int argc, char *args[])
{
    const double mass_range = 3.14e30;
    const double radius_range = 7e8;
    const double charges_range = 200;
    const double coord_range = 8e8;
    const double speed_range = 40000;
    const int min_nparticles = 200;
    const int max_nparticles = 2000;
    const double G = 1;   //G is gravitational constant in m^3*kg^-1*s^-2
    const double h = 0.1; //timesize
    const double k = 8.988e9;
    const double e = 1.6e-19;          // unit C (Coulomb)
    vector<Particle> particles;        // define a vector contains particles
    string filename_in = "rgbody.txt"; // the random generated initial conditions will be
    string filename_out = "result.txt";

    int n;
    try
    {
        Interface interface(argc, args);
        if (interface.getOption() == 1)
        {
            ofstream data_out(interface.getData_filename());
            if (!data_out)
            {
                perror("Error opening data output file");
                return -1;
            }
            generateRandomData(data_out, mass_range, radius_range, charges_range, coord_range, speed_range, min_nparticles, max_nparticles); // the range of each parameter
            data_out.close();
        }

        //read the initial values from a file
        ifstream data_in(interface.getData_filename());
        if (!data_in)
        {
            perror("Error opening data input file");
            return -1;
        }

        // output the result into a file
        ofstream output_out(interface.getOutput_filename());
        if (!output_out)
        {
            perror("Error opening output file");
            return -1;
        }

        // read input initial values
        data_in >> n;

        for (int i = 0; i < n; ++i)
        {
            Particle particle;
            data_in >> particle;
            particles.push_back(particle);
        }

        NBodyProblem nbody(particles, G, k, e);

        //solving the Nbody problem using the given method
        NBodySolver::solve(h, interface.getTend(), nbody, output_out, interface.getMethod());

        // close all files
        data_in.close();
        output_out.close();
    }
    catch (const string &e)
    {
        cerr << "Invalid input: " << e << endl;

        // if the the input is invalid, README.MD file will be printed in the terminal
        ifstream readMe("README.md");
        if (!readMe)
        {
            perror("Error opening data input file");
            return -1;
        }

        string s;
        while (getline(readMe, s))
            cout << s << endl;
        readMe.close();

        exit(1);
    }
}
