#include "Interface.hpp"
#include <iostream>

Interface::Interface(int argc, char *args[])
{
    data_filename = "solar_system.txt"; //default input file
    output_filename = "result.txt";     //default output file
    method = "euler";
    tend = 1000;

    option = atoi(args[1]);

    if (argc < 2 || (option != 3 && argc < 3))
    {
        throw string("incorrect number of arguments.");
    }

    if (argc >= 3)
    {
        if (option == 3)
        {
            output_filename = args[2];
        }
        else
        {
            data_filename = args[2];
        }
    }

    if (argc >= 4)
    {
        if (option == 3) //solar system
        {
            tend = atoi(args[3]);
        }
        else
        {
            output_filename = args[3];
        }
    }

    if (argc >= 5)
    {
        if (option == 3) //solar system
        {
            method = args[4];
        }
        else
            tend = atoi(args[4]);
    }

    if (argc >= 6)
    {
        method = args[5];
    }

    if (option < 0 || option > 3)
    {
        throw string("invalid option.");
    }
}

int Interface::getOption()
{
    return option;
}

int Interface::getTend()
{
    return tend;
}

string Interface::getData_filename()
{
    return data_filename;
}

string Interface::getOutput_filename()
{
    return output_filename;
}

string Interface::getMethod()
{
    return method;
}