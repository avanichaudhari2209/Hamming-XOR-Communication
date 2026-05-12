#include <stdlib.h>

#include "noise.h"

double rand_double() {

    return (double)rand() / RAND_MAX;
}

void add_noise(char *bits,
               size_t len,
               double probability) {

    for (size_t i = 0; i < len; i++) {

        if (rand_double() < probability) {

            bits[i] =
                (bits[i] == '1')
                ? '0' : '1';
        }
    }
}
