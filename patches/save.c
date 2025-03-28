#include "patches.h"
#include "misc_funcs.h"

typedef struct Unk {
    s8 unk_00;
    s8 unk_01;
} Unk;

typedef struct Unk2 {
    char unk_00[0x60];
    s32 unk_60;
} Unk2;

typedef struct Unk3 {
    s16 unk_00;
    s8 unk_02[0x10];
    char unk_12[1];
    u8 unk_13;
} Unk3;

s32 func_800319E0(s8, s8, s32, s32, void*);                /* extern */
s32 func_80031BB0(s32);                             /* extern */
extern u16 D_8008FD0C;
extern u16 D_8008FD20;
extern s8 D_8008FD22;
extern s32 D_8008FD24;
extern s8 D_8008FD29;
extern s8 D_8008FD2A;
extern Unk D_8008FD30[16];
extern Unk2 D_8008FD58[16];
extern Unk2 D_80090460;
extern Unk3 D_80092A38[4];
extern s8 gCurrControllerNum;

void save_read(void* rdram_address, u32 offset, u32 count);

RECOMP_PATCH void func_8002DD18(void) {
    Unk* temp_v0;
    s32 var_a1;
    s32 var_fp;
    s32 i;
    u8 byte;

    var_fp = 0;
    
    //17 not 16?
    for (i = 0; i < 17; i++) {
        D_8008FD30[i].unk_00 = -1;
        D_8008FD30[i].unk_01 = -1;
    }

    var_a1 = 0;
    for (i = 0; i < 16; i++) {
        if ((D_80092A38[gCurrControllerNum].unk_02[i] != 0x7F) && (D_80092A38[gCurrControllerNum].unk_02[i] >= 0)) {
            temp_v0 = &D_8008FD30[var_a1];
            temp_v0->unk_00 = i;
            temp_v0->unk_01 = D_80092A38[gCurrControllerNum].unk_02[i];
            var_a1 += 1;
        }        
    }
    
    if (D_8008FD0C & 4) {
        if ((D_80092A38[gCurrControllerNum].unk_13 >= 2) && !(D_80092A38[gCurrControllerNum].unk_00 & 0x2000)) {
            D_8008FD30[var_a1].unk_00 = -2;
        }
    }
    D_8008FD2A = 0;

    for (i = 0; i < 16; i++) {
        //if slot index is greater than or equal to 0
        save_read(&byte, 0, 1);
        
        if (byte >= 0) {
            var_a1 = func_800319E0(gCurrControllerNum, i, 0, 0x80, &D_80090460);
            D_8008FD58[i] = D_80090460;
            if (var_a1 != 0) {
                D_8008FD24 = var_fp;
                var_fp = -func_80031BB0(var_fp);
                if (var_fp == 1) {
                    D_8008FD22 = 8;
                    D_8008FD29 = 0xA;
                } else {
                    D_8008FD22 = 0x11;
                    D_8008FD29 = 0xA;
                }
                
                D_8008FD20 &= ~7;
                D_8008FD20 |= 5;
            }
        }   
    }
}