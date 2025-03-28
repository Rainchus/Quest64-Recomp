#include "patches.h"
#include "misc_funcs.h"

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_arg __builtin_va_arg
#define va_end __builtin_va_end

int dummyData = 1;
int dummyBss;

void dummyFunc(void)
{
    return;
}

typedef unsigned int size_t;
typedef char *outfun(char*,const char*,size_t);

int _Printf(outfun prout, char *arg, const char *fmt, va_list args);

char* proutPrintf(char* dst, const char* fmt, size_t size) {
    recomp_puts(fmt, size);
    return (void*)1;
}

int recomp_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int ret = _Printf(&proutPrintf, NULL, fmt, args);

    va_end(args);

    return ret;
}
