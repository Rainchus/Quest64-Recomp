#include "patches.h"

#define BRIAN_LIMB_TAG(limb_index) \
    (0x42524941 | ((limb_index) << 8)) // 'BRIA' + limb index

#define MODEL_TAG(model_id, instance) \
    ((model_id) | ((instance) << 16))
    
int dummy = 1;
int dummyBSS;

extern s32 osPfsReadWriteFile_recomp(OSPfs *, s32, u8, int, int, u8 *);
extern s32 osPfsInitPak_recomp(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsFileState_recomp(OSPfs *, s32, OSPfsState *);
extern s32 osPfsFreeBlocks_recomp(OSPfs *, s32 *);

typedef float MtxF_t[4][4];
typedef union {
    MtxF_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

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

void func_8001E138(f32 (*)[4], void*);                 /* extern */
void func_80023C1C(f32 (*)[4], f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
void func_80023E80(f32 (*)[4], f32 (*)[4], f32 (*)[4]);                      /* extern */

typedef struct Unk5 {
    char unk_00[0x0C];
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
} Unk5; //sizeof 0x18

typedef struct Unk6 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} Unk6; //sizeof 0x24                                       /* size = 0x20 */

typedef struct Unk8 {
    /* 0x00 */ char unk_00[6];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ char unk_08[12];
    /* 0x14 */ s8 unk_14;                            /* inferred */
    /* 0x15 */ s8 unk_15;
    /* 0x16 */ u8 unk_16;                            /* inferred */
    /* 0x17 */ char unk_17[1];
    /* 0x18 */ s32* unk_18;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ char unk_1E[2];
} Unk8; //sizeof 0x20

typedef struct Unk9 {
    s16 unk_00;
    char unk_02[6];
    s32* unk_08;
} Unk9;

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32  z;
} Vec3f;

extern Unk5 D_80086DC0;
extern Vec3f D_8008C5B0[];
extern s32 D_8008C5E0;
extern f32 D_8008C5E8[4][4];
extern Gfx* gMasterGfxPos;
extern Mtx D_2000000[];
void func_80022B40(void* arg0, f32* arg1, s32 arg2);   /* extern */
void func_8002371C(f32 (*)[4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80023DF4(f32 (*)[4], f32 arg1, f32 arg2, f32 arg3);
extern s32 D_8007B2F8;


                                      /* extern */
void func_80023C1C(f32 (*)[4], f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
void func_80023E80(f32 (*)[4], f32 (*)[4], f32 (*)[4]);                      /* extern */

//void func_8001DC78(MtxF*, Vec3f, s32, s32, s32, s32, void*, void*, s32);

RECOMP_PATCH void func_8001DC78(f32 arg0[4][4], Vec3f arg1, s32 arg4, s32 arg5, s32 arg6, s32 arg7, Unk9* arg8,
                                Unk8* arg9, Mtx* arg10) {
    s32* temp_a1;
    s32* temp_a2_2;
    s32 temp_a2;
    Unk8* temp_s2;
    f32 spA0[4][4];
    Unk6 sp7C;
    s32 i;

    temp_s2 = arg9 + arg5;
    temp_a2 = temp_s2->unk_06;
    if (temp_a2 != 0) {
        temp_a2 = arg6 % temp_a2;
    } else {
        temp_a2 = 0;
    }
    func_80022B40(temp_s2, &sp7C, temp_a2);
    if (temp_s2->unk_14 == 0) {
        if (arg4 & 1) {
            sp7C.unk_08 = sp7C.unk_00 = 0;
        }
        if (arg4 & 2) {
            sp7C.unk_04 = 0;
        }
    }
    func_80023C1C(spA0, sp7C.unk_00, sp7C.unk_04, sp7C.unk_08, sp7C.unk_10, sp7C.unk_0C, sp7C.unk_14, sp7C.unk_18,
                  sp7C.unk_1C, sp7C.unk_20);
    func_8001E138(spA0, temp_s2);
    arg1.x *= sp7C.unk_18;
    arg1.y *= sp7C.unk_1C;
    arg1.z *= sp7C.unk_20;
    if (temp_s2->unk_16 & 1) {
        func_80023E80(arg0, spA0, spA0);
        func_8002371C(D_8008C5E8, spA0[3][0], spA0[3][1], spA0[3][2], D_80086DC0.unk_0C, D_80086DC0.unk_10,
                      D_80086DC0.unk_14);
        func_80023DF4(D_8008C5E8, arg1.x, arg1.y, arg1.z);
        guMtxF2L(D_8008C5E8, arg10 + 3 + D_8007B2F8);
    } else {
        func_80023E80(arg0, spA0, spA0);
        guMtxF2L(spA0, arg10 + 3 + D_8007B2F8);
    }
    gSPMatrix(gMasterGfxPos++, D_2000000 + 3 + D_8007B2F8++, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (temp_s2->unk_16 & 2) {
        D_8008C5B0[D_8008C5E0].x = spA0[3][0];
        D_8008C5B0[D_8008C5E0].y = spA0[3][1];
        D_8008C5B0[D_8008C5E0++].z = spA0[3][2];
    }

    if (temp_a1) {}

    temp_a2_2 = temp_s2->unk_18;
    temp_a1 = arg8->unk_08;
    if (temp_a2_2 == 0) {
        i = temp_s2->unk_15;
        if (i != -1) {
            if (temp_a1[i] != 0) {
                gSPDisplayList(gMasterGfxPos++, temp_a1[i]);
            }
        }
    } else {
        gSPDisplayList(gMasterGfxPos++, temp_a1[temp_a2_2[arg7 % temp_s2->unk_1C]]);
    }
    for (i = 0; i < arg8->unk_00; i++) {
        if ((arg5 + 1) == arg9[i].unk_14) {
            func_8001DC78(spA0, arg1, arg4, i, arg6, arg7, arg8, arg9, arg10);
        }
    }
}

//RECOMP_PATCH s32 func_80031574(s32 arg0) {
//    s32 i;
//    char pad[0x10];
//    s32 var_s4;
//    s32 var_s5;
//    s32 var_s6;
//    s32 temp;
//    OSPfsState sp4C;
// 
//    
//    var_s4 = 0;
//    var_s6 = 0;
//    D_80092A38[arg0].unk_13 = 0xFF;
//    D_80092A38[arg0].unk_00 = 0;
//
//    for (i = 0; i < 16; i++) {
//        D_80092A38[arg0].unk_02[i] = -1;
//    }
//
//    var_s5 = osPfsInitPak_recomp(&gSIMessageQ, &gPFS[arg0], arg0);
//    if (var_s5 != 0) {
//        if (var_s5 == 0xA) {
//            var_s5 = (osMotorInit(&gSIMessageQ, &gPFS[arg0], arg0) == 0) ? 1 : 10;
//        }
//        return var_s5;
//    }
//    for (i = 0; i < 16; i++) {
//        var_s5 = osPfsFileState_recomp(&gPFS[arg0], i, &sp4C);
//        if (var_s5 == 0) {
//            recomp_printf("game_code is: %08X\n", sp4C.game_code);
//            recomp_printf("company_code is: %08X\n", sp4C.company_code);
//
//            //2A2E1E2C 2D161400 00000000 00000000
//            recomp_printf("game_name is: %08X\n", sp4C.game_name[0]);
//            recomp_printf("game_name is: %08X\n", sp4C.game_name[4]);
//            recomp_printf("game_name is: %08X\n", sp4C.game_name[8]);
//            recomp_printf("game_name is: %08X\n", sp4C.game_name[12]);
//
//            if ((sp4C.game_code == 0x4E455445) && (sp4C.company_code == 0x3738)) {
//                if (1) { //TODO: this fixes a bug in recomp with sp4C.game_name being wrong, so let's just not check it
//                // if (func_80031C0C(D_8005FB40, sp4C.game_name, 0x10) == 0) {
//                    D_80092A38[arg0].unk_02[i] = sp4C.ext_name[0];
//                    D_80092A38[arg0].unk_00 |= 0x4000;
//                    var_s4 += 1;
//                    var_s6 += 1;
//                } else {
//                    D_80092A38[arg0].unk_02[i] = 0x7F;
//                    var_s6 += 1;
//                }
//            } else {
//                D_80092A38[arg0].unk_02[i] = 0x7F;
//                var_s6 += 1;
//            }
//            continue;
//        }
//        
//        if (var_s5 == 5) {
//            D_80092A38[arg0].unk_02[i] = -1;
//            var_s5 = 0;
//        } else {
//            break;
//        }
//    }
//    
//    if (var_s5 == 0) {
//        D_80092A38[arg0].unk_00 &= ~0x0F;
//        D_80092A38[arg0].unk_00 |= var_s4;
//        if (var_s4 >= 0x10) {
//            D_80092A38[arg0].unk_00 |= 0x2000;
//        }
//        if (var_s6 >= 0x10) {
//            D_80092A38[arg0].unk_00 |= 0x2000;
//        }
//        osPfsFreeBlocks_recomp(&gPFS[arg0], &i);
//        D_80092A38[arg0].unk_13 = i / 256;
//        if ((i / 256) < 2) {
//            D_80092A38[arg0].unk_00 |= 0x2000;
//        }
//    }        
//    
//    return var_s5;
//}

struct Struct_800011DC_arg0_sub {
    /* 0x0058 */ Mtx unk_58[1];
    /* 0x0098 */ char unk_98[0x8148 - 0x98];
    /* 0x8148 */ Gfx unk_8148[1];
    /* 0x8150 */ char unk_8150[0xD14C - 0x8150];
    /* 0xD14C */ u16* unk_D14C;
};

struct Struct_800011DC_arg0 {
    /* 0x0000 */ char unk_00[0x40];
    /* 0x0040 */ Gfx* unk_40;
    /* 0x0044 */ s32 unk_44;
    /* 0x0048 */ char unk_48[0x10];
    /* 0x0058 */ struct Struct_800011DC_arg0_sub unk_58;
};

void* testing(struct Struct_800011DC_arg0* arg0) {
    //recomp_printf("arg0->unk_58.unk_8148 is: %08X\n", arg0->unk_58.unk_8148);
    gMasterGfxPos = &arg0->unk_58.unk_8148[0];
    gEXEnable(gMasterGfxPos++); // @recomp
    gEXSetRefreshRate(gMasterGfxPos++, 60 / 2);
    // recomp_printf("arg0 is: %08X\n", arg0);

    return arg0;
}