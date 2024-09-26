#include "patches.h"

#include "misc_funcs.h"

// #define va_end(__list)
// #define va_start(vp, parmN) (vp = ((va_list)&parmN + sizeof(parmN)))
// 
// typedef unsigned int   size_t;
// typedef char *va_list;
// typedef void* (*PrintCallback)(void*, const char*, size_t);

// int _Printf(PrintCallback pfn, void* arg, const char* fmt, va_list ap);
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

