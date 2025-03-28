#ifndef __RECOMP_FUNCS_H__
#define __RECOMP_FUNCS_H__

#include "patch_helpers.h"

DECLARE_FUNC(void, recomp_load_overlays, u32 rom, void* ram, u32 size);
DECLARE_FUNC(void, recomp_puts, const char* data, u32 size);
DECLARE_FUNC(void, recomp_exit);

#endif
