#include "key.h"

ubyte encryptByte(ubyte byte, Key key)
{
    return byte ^ key.bytes[key.bytePos];
}