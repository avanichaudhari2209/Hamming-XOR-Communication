# Hamming-XOR-Communication

A C-based communication system that simulates secure and reliable data transmission using XOR encryption and Hamming (7,4) error correction.

The project converts text into binary data, encrypts it using XOR, encodes it using Hamming code, transmits it through a noisy channel, corrects single-bit errors, and reconstructs the original message at the receiver side.

## Features

- Text to binary conversion
- XOR-based encryption and decryption
- Hamming (7,4) encoding and decoding
- Noisy channel simulation
- Single-bit error detection and correction
- Recovery of original transmitted message

## Project Structure

```text
hamming-xor-communication/
│
├── src/
│   ├── main.c
│   ├── binary.c
│   ├── binary.h
│   ├── xor.c
│   ├── xor.h
│   ├── hamming.c
│   ├── hamming.h
│   ├── noise.c
│   └── noise.h
│
├── README.md
├── Makefile
└── .gitignore
```

## Compilation

```bash
make
```

## Run

```bash
make run
```

## Example

```text
Enter Message: HELLO
Enter 8-bit XOR Key: 10101010
Enter Noise Probability: 0.02
```

Program Output:

- Original Binary
- Encrypted Binary
- Encoded Message
- Transmitted Message
- Corrected Binary
- Final Decoded Message

## Technologies Used

- C Programming
- Hamming (7,4) Error Correction
- XOR Encryption
- GCC Compiler

## Notes

- Hamming (7,4) can correct only single-bit errors.
- Higher noise probability may corrupt the transmitted data.
- Recommended noise probability: 0.01 – 0.02
