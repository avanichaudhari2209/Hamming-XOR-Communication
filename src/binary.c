#include <stdlib.h>
#include <string.h>

#include "binary.h"

char* text_to_binary(const char *text,
                     size_t *bitlen) {

    size_t n = strlen(text);

    *bitlen = n * 8;

    char *bin =
        (char*)malloc(*bitlen + 1);

    char *p = bin;

    for (size_t i = 0; i < n; i++) {

        unsigned char ch = text[i];

        for (int b = 7; b >= 0; b--) {

            *p++ =
                ((ch >> b) & 1)
                ? '1' : '0';
        }
    }

    *p = '\0';

    return bin;
}

char* binary_to_text(const char *bin,
                     size_t bitlen) {

    size_t bytes = bitlen / 8;

    char *text =
        (char*)malloc(bytes + 1);

    for (size_t i = 0; i < bytes; i++) {

        unsigned char val = 0;

        for (int b = 0; b < 8; b++) {

            val =
                (val << 1)
                | (bin[i * 8 + b] - '0');
        }

        text[i] = val;
    }

    text[bytes] = '\0';

    return text;
}
