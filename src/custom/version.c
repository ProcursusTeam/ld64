#include "configure.h"

#define VAL(x) #x
#define STRINGIFY(x) VAL(x)

const char ldVersionString[] = "@(#)PROGRAM:ld  PROJECT:ld64-" STRINGIFY(LD64_VERSION_NUM) "\n";
