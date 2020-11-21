#include "encryption.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* keyFile = fopen(argv[1], "r");
    ubyte buf [MAX_ENCRYPTION_KEY_SIZE] = {0};
    size_t keySize = fread(buf, sizeof(buf[0]), MAX_ENCRYPTION_KEY_SIZE, keyFile);
    fclose(keyFile);
    Key key;
    key.bytePos = 0;
    key.bytes = buf;
    key.maxBytePos = keySize-1;
    FILE* inputFile = fopen(argv[2], "r");
    fseek(inputFile, 0L, SEEK_END);
    size_t inputSize = ftell(inputFile);
    rewind(inputFile);
    ubyte* inputBuffer = malloc(inputSize*sizeof(ubyte));
    fread(inputBuffer, sizeof(ubyte), inputSize, inputFile);
    fclose(inputFile);
    ubyte* encryptedBytes = encryptBytes(inputBuffer, inputSize*sizeof(ubyte), key);
    for(size_t i = 0; i < inputSize; i++)
    {
        putc(*(encryptedBytes+i), stdout);
    }
}