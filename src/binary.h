#ifndef BINARY_H
#define BINARY_H

#include <stddef.h>

char* text_to_binary(const char *text, size_t *bitlen);

char* binary_to_text(const char *bin,
                     size_t bitlen);

#endif
