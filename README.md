# N Body Simulation

## Requirements

- c++17

## Compilation

```
g++ -std=c++17 -Wall -Wextra -Wpedantic  -c *.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic *.o -o nbody
```

## Run

Option 1: randomly generate the number of particles and all initial values, then write the initial values and results into files.

```
./nbody <1> <data_filename> [output_filename=result.txt] [tend=1000] [method=euler]
```

Option 2: user inputs the file and results will be written into a file.

```
./nbody <2> <data_filename> [output_filename=result.txt] [tend=1000] [method=euler]
```

Option 3: the solar system will be simulated and the result will be write into a file. The solar system includes the sun, the eight planets and the pluto. The sun is at the origins, and the initial positions of other planets are at y axis and initial velocities are along x-axis except jupiter. The jupiter are set at x-axis and the velocity is along y axis. The charges of each of planets are zero.

```
./nbody <3> [output_filename=result.txt] [tend=1000] [method=euler]
```

## Tend and Method
The tend is the time defined by user, the whole time for the simulation, the default step-size defined is 0.1. The methods provided are Euler method and runge-kutta 4 which may be chosen by the user.

## Output Format
x1 y1 z1 vx1 vy1 vz1 ........ xn yn zn vxn vyn vzn
particle i position: (xi, yi, zi), velocity: (vxi, vyi, vzi)


## Generate Plot
Use gnuplot to generate a plot:

```
splot "result.txt" using 1:2:3 with lines,\
"result.txt" using 7:8:9 with lines,\
....
"result.txt" using 6n+1:6n+2:6n+3 with lines
```
where n is the number of particles