#include "RandomNumberGenerator.hpp"
#include <cstdlib>

uint32_t RandomNumberGenerator::u32_gen(uint32_t min, uint32_t max)
{
    x *= x;
    x += (w += s);
    x = (x >> 32) | (x << 32);
    return min + x % (max - min);
}

double RandomNumberGenerator::double_gen(double min, double max)
{
    return min + (max - min) * rand() / double(RAND_MAX);
}
