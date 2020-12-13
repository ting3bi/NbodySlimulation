#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

#include <cstdint>

class RandomNumberGenerator
{
private:
    uint64_t s;
    uint64_t w;
    uint64_t x;

public:
    //call the seed in the constructor, have a boolean variable, function
    RandomNumberGenerator(uint64_t s_in, uint64_t w_in = 0, uint64_t x_in = 0) : s{s_in}, w{w_in}, x{x_in} {}
    void set_seed(bool on = true);

    // random number generator using middle square weyl sequence, int is number of particles
    uint32_t u32_gen(uint32_t min, uint32_t max);

    // random generate initial values, min is the minimum value of a parameter and max is maximum value
    double double_gen(double min, double max);
};

#endif // RANDOM_NUMBER_GENERATOR_H
