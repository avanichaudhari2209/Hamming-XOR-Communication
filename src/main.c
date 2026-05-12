#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "binary.h"
#include "xor.h"
#include "hamming.h"
#include "noise.h"

int main() {

    srand((unsigned)time(NULL));

    char message[1024];

    printf("Enter Message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    char key[16];

    printf("Enter 8-bit XOR Key (example 10101010): ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) != 8) {

        printf("Invalid key. Using default key 10101010\n");

        strcpy(key, "10101010");
    }

    double noise;

    printf("Enter Noise Probability (0.0 - 1.0): ");
    scanf("%lf", &noise);

    if (noise > 0.02) {

        printf("\nWARNING:\n");
        printf("Hamming(7,4) corrects only single-bit errors.\n");
        printf("Higher noise may corrupt output.\n");
    }

    size_t original_bitlen;

    char *binary =
        text_to_binary(message, &original_bitlen);

    printf("\nOriginal Binary:\n%s\n", binary);

    xor_binary(binary, original_bitlen, key);

    printf("\nEncrypted Binary:\n%s\n", binary);

    size_t encoded_len;

    char *encoded =
        hamming_encode_full(binary,
                            original_bitlen,
                            &encoded_len);

    printf("\nEncoded Message:\n%s\n", encoded);

    char *transmitted =
        (char*)malloc(encoded_len + 1);

    strcpy(transmitted, encoded);

    add_noise(transmitted,
              encoded_len,
              noise);

    printf("\nTransmitted Message:\n%s\n",
           transmitted);

    size_t decoded_len;

    char *decoded =
        hamming_decode_full(transmitted,
                            encoded_len,
                            &decoded_len);

    decoded[original_bitlen] = '\0';

    printf("\nCorrected Binary:\n%s\n", decoded);

    xor_binary(decoded,
               original_bitlen,
               key);

    printf("\nDecrypted Binary:\n%s\n", decoded);

    char *final_text =
        binary_to_text(decoded,
                       original_bitlen);

    printf("\nFINAL DECODED MESSAGE:\n%s\n",
           final_text);

    free(binary);
    free(encoded);
    free(transmitted);
    free(decoded);
    free(final_text);

    return 0;
}
