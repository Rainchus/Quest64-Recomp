#include "recomp.h"

gpr get_entrypoint_address() { return (gpr)(int32_t)0x80000400u; }

const char* get_rom_name() { return "quest64.z64"; }

