#include <stdlib.h>
#include <string.h>

#include "hamming.h"

void hamming_encode4(const char data[4],
                     char out[7]) {

    int d1 = data[0] - '0';
    int d2 = data[1] - '0';
    int d3 = data[2] - '0';
    int d4 = data[3] - '0';

    int p1 = d1 ^ d2 ^ d4;
    int p2 = d1 ^ d3 ^ d4;
    int p3 = d2 ^ d3 ^ d4;

    out[0] = p1 + '0';
    out[1] = p2 + '0';
    out[2] = d1 + '0';
    out[3] = p3 + '0';
    out[4] = d2 + '0';
    out[5] = d3 + '0';
    out[6] = d4 + '0';
}

char* hamming_encode_full(const char *bin,
                          size_t inlen,
                          size_t *outlen) {

    size_t pad =
        (4 - (inlen % 4)) % 4;

    size_t total = inlen + pad;

    char *padded =
        (char*)calloc(total + 1, 1);

    memcpy(padded, bin, inlen);

    for (size_t i = inlen; i < total; i++)
        padded[i] = '0';

    char *out =
        (char*)malloc((total / 4) * 7 + 1);

    size_t k = 0;

    for (size_t i = 0; i < total; i += 4) {

        char temp[7];

        hamming_encode4(&padded[i], temp);

        for (int j = 0; j < 7; j++) {

            out[k++] = temp[j];
        }
    }

    out[k] = '\0';

    *outlen = k;

    free(padded);

    return out;
}

char* hamming_decode_full(char *bin,
                          size_t len,
                          size_t *outlen) {

    char *out =
        (char*)malloc((len / 7) * 4 + 1);

    size_t k = 0;

    for (size_t i = 0; i < len; i += 7) {

        char b[7];

        memcpy(b, &bin[i], 7);

        int p1 = b[0] - '0';
        int p2 = b[1] - '0';
        int d1 = b[2] - '0';
        int p3 = b[3] - '0';
        int d2 = b[4] - '0';
        int d3 = b[5] - '0';
        int d4 = b[6] - '0';

        int s1 = p1 ^ d1 ^ d2 ^ d4;
        int s2 = p2 ^ d1 ^ d3 ^ d4;
        int s3 = p3 ^ d2 ^ d3 ^ d4;

        int syndrome =
            (s3 << 2) | (s2 << 1) | s1;

        if (syndrome != 0) {

            int pos = syndrome - 1;

            b[pos] =
                (b[pos] == '1')
                ? '0' : '1';
        }

        out[k++] = b[2];
        out[k++] = b[4];
        out[k++] = b[5];
        out[k++] = b[6];
    }

    out[k] = '\0';

    *outlen = k;

    return out;
}
