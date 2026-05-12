#ifndef HAMMING_H
#define HAMMING_H

#include <stddef.h>

char* hamming_encode_full(const char *bin,
                          size_t inlen,
                          size_t *outlen);

char* hamming_decode_full(char *bin,
                          size_t len,
                          size_t *outlen);

#endif
