#ifndef NOISE_H
#define NOISE_H

#include <stddef.h>

double rand_double();

void add_noise(char *bits,
               size_t len,
               double probability);

#endif
