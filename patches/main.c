#include "patches.h"

int dummy = 1;
int dummyBSS;

extern s32 osPfsReadWriteFile_recomp(OSPfs *, s32, u8, int, int, u8 *);
extern s32 osPfsInitPak_recomp(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsFileState_recomp(OSPfs *, s32, OSPfsState *);
extern s32 osPfsFreeBlocks_recomp(OSPfs *, s32 *);

typedef struct Unk {
    s8 unk_00;
    s8 unk_01;
} Unk;

#define UNK_SIZE_0 0x20
#define UNK_SIZE_1 0x10
#define INVENTORY_SIZE 151
#define UNK_SIZE_2 1

typedef struct Unk4 {
    u8 unk_00[UNK_SIZE_0];
    u8 unk_20[UNK_SIZE_1];
    u8 unk_30[INVENTORY_SIZE];
    u8 unk_C7[UNK_SIZE_2];
} Unk4; //sizeof 0xC8

typedef struct PlayerMainStats {
  /*0x00*/ u16 unk0;
  /*0x02*/ s16 unk2;
  /*0x04*/ u16 currHP;
  /*0x06*/ u16 maxHP;
  /*0x08*/ u16 currMP;
  /*0x0A*/ u16 maxMP;
  /*0x0C*/ u16 agi;
  /*0x0E*/ u16 def;
  /*0x10*/ s32 exp;
  /*0x14*/ s32 stone; //unused currency. Name derived from beta screenshots. 
  /*0x18*/ f32 collisionSize;
  /*0x1C*/ f32 unk1C; //height? 160.0f by default. Lowering it makes numbers appear lower when brian takes damage, and rocks come out of his chest. 
  /*0x20*/ f32 unk20; //also affects collision size. May be zCollisionSize and the above are X and Y.
  /*0x24*/ u8 elements[4];
  /*0x28*/ u16 HPXP;
  /*0x2A*/ u16 MPXP;
  /*0x2C*/ u16 agiXP;
  /*0x2E*/ u16 defXP;
  /*0x30*/ u8 HPLevel;
  /*0x31*/ u8 MPLevel;
  /*0x32*/ u8 agiLevel;
  /*0x33*/ u8 defLevel;
  /*0x34*/ u8 spiritLevel;
  /*0x35*/ u8 unk35;
  /*0x36*/ u8 unk36;
  /*0x37*/ u8 unk37;
} PlayerMainStats;

typedef struct SaveData {
  /* 0x00 */ PlayerMainStats playerStats;
  /* 0x38 */ u16 unk38;                           /* inferred */
  /* 0x3A */ u16 curDay;                           /* inferred */
  /* 0x3C */ s32 nextMap;                           /* inferred */
  /* 0x40 */ s32 nextSubMap;                           /* inferred */
  /* 0x44 */ s32 unk44;                           /* inferred */
  /* 0x48 */ s32 unk48;                           /* inferred */
  /* 0x4C */ s32 unk4C;                           /* inferred */
  /* 0x50 */ s32 unk50;                           /* inferred */
  /* 0x54 */ s32 unk54;                           /* inferred */
  /* 0x58 */ s32 unk58;                           /* inferred */
  /* 0x5C */ u16 unk5C;                           /* inferred */
  /* 0x5E */ u16 unk5E;                           /* inferred */
  /* 0x60 */ u16 unk_60;
  /* 0x60 */ s8 unk_62;
  /* 0x60 */ s8 unk_63;
} SaveData;

typedef struct Unk3 {
  /* 0x00 */ s16 unk_00;
  /* 0x02 */ s8 unk_02[0x10];
  /* 0x12 */ char unk_12[1];
  /* 0x13 */ u8 unk_13;
} Unk3;

extern Unk3 D_80092A38[4];
extern s32 D_80084EFC;
extern s32 D_80084F00;
extern s32 D_80084F04;
extern s32 D_80084F08;
extern s32 D_80084F0C;
extern s8 D_8005FA00;
extern s8 D_8005F010;
extern Unk4 D_80090398;
extern Unk4 D_800904E0;
extern u8 D_800869D8[UNK_SIZE_0];
extern u8 D_80086AE8[UNK_SIZE_1];
extern u8 D_8007D19C[UNK_SIZE_2];
extern Gfx D_8005FAA0[];
extern u16 D_8008FD0C;
extern u16 D_8008FD20;
extern u8 D_8008FD22;
extern s32 D_8008FD24;
extern s8 D_8008FD29;
extern s8 D_8008FD2A;
extern Unk D_8008FD30[16];
extern SaveData D_8008FD58[16];
extern SaveData D_80090460;
extern s8 gCurrControllerNum;
extern u8 D_8008FD28;
extern s8 D_8008FD2B;
extern u8 D_8008FD2C;
extern u8 D_8008FD23;
extern u16 gGameMode;
extern u8 D_8005FB40[];

void func_8002E234(u32 arg0);
s32 func_80031890(s32 arg0, u8 arg1);
s32 func_80031A44(s8, s8, s32, s32, u8*);
s32 osMotorInit(OSMesgQueue* mq, OSPfs* pfs, int channel);
s32 func_80031574(s32);
s32 func_80031BB0(s32);
void func_8002B6F0(void);
void func_8002B8C4(void);
void func_8002BCA0(void);
void func_8002C818(s32);
void func_8002D5D4(void);
void func_8002D614(void);
void func_8002D748(void);
void func_8002D8BC(void);
void func_8002DBE0(void);
void func_8002DFD0(void);
void func_8002DD18(void);
s32 func_8003195C(s8, u8);
void func_8002DF6C(void);
s32 func_80031C0C(u8* str0, u8* str1, s32 size);

RECOMP_PATCH s32 func_800319E0(s32 pfsIndex, s32 file_no, s32 offset, s32 nbytes, u8* data_buffer) {
    recomp_printf("func_800319E0 called");
	return osPfsReadWriteFile_recomp(&gPFS[pfsIndex], file_no, PFS_READ, offset, nbytes, data_buffer);
}


RECOMP_PATCH void func_8002DD18(void) {
    Unk* temp_v0;
    s32 var_a1;
    s32 var_fp;
    s32 i;

    recomp_printf("func_8002DD18 called");

    var_fp = 0;
    
    //17 not 16?
    for (i = 0; i < 16; i++) { //patch to 16
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
        if (D_8008FD30[i].unk_00 >= 0) {
            var_a1 = func_800319E0(gCurrControllerNum, D_8008FD30[i].unk_00, 0, 0x80, &D_80090460);
            volatile u32* src = (u32*)&D_80090460;
            volatile u32* dst = (u32*)&D_8008FD58[i];
            s32 j;

            for (j = 0; j < sizeof(SaveData) / 4; j++) {
                dst[j] = src[j];
            }
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

RECOMP_PATCH void func_8002B8C4(void) {
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 var_a0_2;

    recomp_printf("func_8002B8C4 called\n");

    sp1C = D_8008FD0C & 0xC;
    if (D_8008FD20 & 0x1000) {
        temp_v0 = osPfsInitPak_recomp(&gSIMessageQ, &gPFS[gCurrControllerNum], gCurrControllerNum);
        if (temp_v0 == 2) {
            temp_v0 = 0;
        } else if (temp_v0 == 0xA) {
            if (osMotorInit(&gSIMessageQ, &gPFS[gCurrControllerNum], gCurrControllerNum) == 0) {
                temp_v0 = 1;
            } else {
                temp_v0 = 0xA;
            }
        }
        sp18 = temp_v0;
        D_8008FD20 &= ~0x1000;
    }
    var_a0_2 = sp18;
    if (var_a0_2 == 0) {
        var_a0_2 = func_80031574(gCurrControllerNum);
    }
    if (var_a0_2 != 0) {
        D_8008FD24 = var_a0_2;
        if (-func_80031BB0(var_a0_2) == 1) {
            if (sp1C == 4) {
                D_8008FD22 = 0xD;
                D_8008FD29 = 0xA;
            } else {
                D_8008FD22 = 8;
                D_8008FD29 = 0xA;
            }
        } else {
            D_8008FD22 = 0x11;
            D_8008FD29 = 0xA;
        }
        
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        return;
    }
    recomp_printf("sp1C is %d\n", sp1C);
    recomp_printf("D_8008FD2C is %d\n", D_8008FD2C);
    recomp_printf("D_80092A38[gCurrControllerNum].unk_00 is %08X\n", D_80092A38[gCurrControllerNum].unk_00);
    //D_80092A38[gCurrControllerNum].unk_00 |= 0x4001; //hack, set these bits
    if (sp1C == 4) {
        if (D_80092A38[gCurrControllerNum].unk_13 < 2) {
            if (D_80092A38[gCurrControllerNum].unk_00 & 0x4000) {
                D_8008FD22 = 0x15;
            } else {
                D_8008FD22 = 0x14;
            }
            D_8008FD29 = 0xA;
            D_8008FD20 &= ~7;
            D_8008FD20 |= 5;
            return;
        }
        if (D_80092A38[gCurrControllerNum].unk_00 & 0x2000) {
            if (D_80092A38[gCurrControllerNum].unk_00 & 0x4000) {
                D_8008FD22 = 0x15;
                D_8008FD2A = 0;
                D_8008FD20 &= ~0x20;
            } else {
                D_8008FD22 = 0x14;
            }
            D_8008FD29 = 0xA;
            D_8008FD20 &= ~7;
            D_8008FD20 |= 5;
            return;
        }
    } else if ((D_8008FD2C != 0) && ((D_80092A38[gCurrControllerNum].unk_13 < 2) || (D_80092A38[gCurrControllerNum].unk_00 & 0x2000)) ) {
        D_8008FD22 = 0x18;
        D_8008FD29 = 0xA;
        func_8002DD18();
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        D_8008FD2A = 0;
        D_8008FD20 &= ~0x20;
        return;
    } else if (!(D_80092A38[gCurrControllerNum].unk_00 & 0x4000)) {
        if (sp1C == 0) {
            D_8008FD22 = 9;
            D_8008FD29 = 0xA;
        } else {
            D_8008FD22 = 0xA;
            D_8008FD29 = 0xA;
        }
        D_8008FD20 &= ~7;
        D_8008FD20 |= 5;
        return;
    }
    func_8002DD18();
    D_8008FD20 &= ~7;
    D_8008FD20 = D_8008FD20;
    D_8008FD2A = 0;
    D_8008FD20 &= ~0x20;
}

RECOMP_PATCH s32 func_80031574(s32 arg0) {
    s32 i;
    char pad[0x10];
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 temp;
    OSPfsState sp4C;
 
    
    var_s4 = 0;
    var_s6 = 0;
    D_80092A38[arg0].unk_13 = 0xFF;
    D_80092A38[arg0].unk_00 = 0;

    for (i = 0; i < 16; i++) {
        D_80092A38[arg0].unk_02[i] = -1;
    }

    var_s5 = osPfsInitPak_recomp(&gSIMessageQ, &gPFS[arg0], arg0);
    if (var_s5 != 0) {
        if (var_s5 == 0xA) {
            var_s5 = (osMotorInit(&gSIMessageQ, &gPFS[arg0], arg0) == 0) ? 1 : 10;
        }
        return var_s5;
    }
    for (i = 0; i < 16; i++) {
        var_s5 = osPfsFileState_recomp(&gPFS[arg0], i, &sp4C);
        if (var_s5 == 0) {
            recomp_printf("game_code is: %08X\n", sp4C.game_code);
            recomp_printf("company_code is: %08X\n", sp4C.company_code);

            //2A2E1E2C 2D161400 00000000 00000000
            recomp_printf("game_name is: %08X\n", sp4C.game_name[0]);
            recomp_printf("game_name is: %08X\n", sp4C.game_name[4]);
            recomp_printf("game_name is: %08X\n", sp4C.game_name[8]);
            recomp_printf("game_name is: %08X\n", sp4C.game_name[12]);

            if ((sp4C.game_code == 0x4E455445) && (sp4C.company_code == 0x3738)) {
                if (1) { //TODO: this fixes a bug in recomp with sp4C.game_name being wrong, so let's just not check it
                // if (func_80031C0C(D_8005FB40, sp4C.game_name, 0x10) == 0) {
                    D_80092A38[arg0].unk_02[i] = sp4C.ext_name[0];
                    D_80092A38[arg0].unk_00 |= 0x4000;
                    var_s4 += 1;
                    var_s6 += 1;
                } else {
                    D_80092A38[arg0].unk_02[i] = 0x7F;
                    var_s6 += 1;
                }
            } else {
                D_80092A38[arg0].unk_02[i] = 0x7F;
                var_s6 += 1;
            }
            continue;
        }
        
        if (var_s5 == 5) {
            D_80092A38[arg0].unk_02[i] = -1;
            var_s5 = 0;
        } else {
            break;
        }
    }
    
    if (var_s5 == 0) {
        D_80092A38[arg0].unk_00 &= ~0x0F;
        D_80092A38[arg0].unk_00 |= var_s4;
        if (var_s4 >= 0x10) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
        if (var_s6 >= 0x10) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
        osPfsFreeBlocks_recomp(&gPFS[arg0], &i);
        D_80092A38[arg0].unk_13 = i / 256;
        if ((i / 256) < 2) {
            D_80092A38[arg0].unk_00 |= 0x2000;
        }
    }        
    
    return var_s5;
}

/*initializes devices such as the rumble pak and the controller pak and returns an error ID if there is one.*/
//RECOMP_PATCH s32 initPFSPaks(s32 arg0, s32 arg1) {
//    s32 con_error;
//    u32 cont;
//
//    cont = gCurrControllerNum;
//
//    if (arg1 == 0xA) {
//        if (osMotorInit(&gSIMessageQ, &gPFS[cont], cont) != 0) {
//            con_error = osPfsInitPak_recomp(&gSIMessageQ, &gPFS[cont], cont);
//            if ((con_error != PFS_ERR_DEVICE) && (con_error != PFS_ERR_NOPACK) && (con_error != PFS_ERR_NEW_PACK)) {
//                //con_error = __osGetID(&gPFS[cont]);
//            }
//        } else {
//            con_error = 4;
//        }
//    } else {
//        con_error = osPfsInitPak_recomp(&gSIMessageQ, &gPFS[cont], cont);
//    }
//
//    return con_error;
//}