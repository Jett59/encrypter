#include "key.h"

ubyte encryptBit(ubyte bit, Key key)
{
    ubyte keyBit = key.bytes[key.bytePos] & (1 << key.bitPos);
    return keyBit & bit;
}
ubyte encryptByte(ubyte byte, Key key)
{
    ubyte result = 0;
    for(key.bitPos = 7; key.bitPos >= 0; key.bitPos--)
    {
        result = result | (encryptBit(byte & (1 << key.bitPos), key) << key.bitPos);
    }
    return result;
}
