#ifndef __INCLUDE_ENCRYPTION_HEADER
#define __INCLUDE_ENCRYPTION_HEADER
#include <stdlib.h>
#include "key.h"
#define MAX_ENCRYPTION_KEY_SIZE 256
ubyte encryptByte(ubyte byte, Key key);
ubyte* encryptBytes(ubyte* bytes, size_t numberOfBytes, Key key);
#endif