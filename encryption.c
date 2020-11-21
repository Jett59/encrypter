#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "key.h"
#include "usefulMacros.h"

ubyte encryptByte(ubyte byte, Key key)
{
    return byte ^ *(key.bytes+key.bytePos);
}
ubyte* encryptBytes (ubyte* bytes, size_t numberOfBytes, Key key)
{
    ubyte* result = malloc((numberOfBytes+1)*sizeof(ubyte));
    void* resultAnchor = (void*)result;
    size_t i;
    for(i = 0; i < numberOfBytes; i++)
    {
        if(key.bytePos < key.maxBytePos)
        {
            *result = encryptByte(bytes[i], key);
            printf("encrypted byte: %d\n", *result);
            result++;
            key.bytePos++;
        }
        else
        {
            key.bytePos = 0;
            i--;
        }       
    }
    result++;
    *result = 0;
    result = (ubyte*)resultAnchor;
    return result;
}

//test
int main (int argc, char* argv[])
{
    Key key;
    key.bytes = argv[1];
    key.maxBytePos = strlen(argv[0])-1;
    key.bytePos = 0;
    printf("encrypting text %s using key %s\n", (ubyte*)argv[2], (ubyte*)argv[1]);
    ubyte* encryptedData = encryptBytes(argv[2], strlen(argv[2]), key);
    printf("encryptted data: %s\n", encryptedData);
    ubyte* decryptedBytes = encryptBytes(encryptedData, strlen(argv[2]), key);
    printf("decrypted data: %s\n", decryptedBytes);
    free(encryptedData);
    free(decryptedBytes);
    exit(0);
}