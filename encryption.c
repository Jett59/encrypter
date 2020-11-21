#include <stdlib.h>
#include "key.h"
#include "usefulMacros.h"

ubyte encryptByte(ubyte byte, Key key)
{
    return byte ^ key.bytes[key.bytePos];
}
ubyte* encryptBytes (ubyte* bytes, size_t numberOfBytes, Key key)
{
    ubyte* result = malloc(numberOfBytes*sizeof(ubyte));
    size_t i;
    for(i = 0; i < numberOfBytes; i++)
    {
        if(key.bytePos < key.maxBytePos)
        {
            *result = encryptByte(bytes[i], key);
            result++;
            key.bytePos++;
        }
        else
        {
            key.bytePos = 0;
        }       
    }
    return result;
}