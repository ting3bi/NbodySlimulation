#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

using namespace std;

class Interface
{
    int tend = 1000;
    int option;             //1: is randomly generate the initial conditions, 2: user input the file, 3: simulate the solar system
    string data_filename;   //default input file
    string output_filename; //default output file
    string method;

public:
    Interface(int argc, char *args[]);
    int getOption();
    int getTend();
    string getData_filename();
    string getOutput_filename();
    string getMethod(); // 2 methods are provided
};

#endif // INTERFACE_H
