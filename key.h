#ifndef __INCLUDE_KEY_HEADER
#define __INCLUDE_KEY_HEADER  1
#ifndef __DEFINE_UBYTE
#define __DEFINE_UBYTE
typedef unsigned char ubyte;
#endif
typedef struct Key {
    ubyte bytes[32];
    ubyte bytePos;
    ubyte bitPos;
} Key;
#endif