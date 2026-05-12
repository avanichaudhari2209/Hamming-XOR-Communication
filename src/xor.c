#include <string.h>

#include "xor.h"

void xor_binary(char *bin,
                size_t len,
                const char *key) {

    size_t keylen = strlen(key);

    for (size_t i = 0; i < len; i++) {

        bin[i] =
            (bin[i] == key[i % keylen])
            ? '0' : '1';
    }
}
