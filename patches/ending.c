#include "patches.h"

typedef struct AssetInfo {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ Vec3f unk_24;
    /* 0x30 */ Vec3f unk_30;
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f unk_54;
    /* 0x60 */ Color_RGBA32 fog;
    /* 0x64 */ s16 fogNear;
    /* 0x66 */ s16 fogFar;
    /* 0x68 */ Color_RGBA32 env;
    /* 0x6C */ Color_RGBA32 prim;
    /* 0x70 */ u8 unk_70;
    /* 0x71 */ u8 unk_71;
} AssetInfo; // size = 0x72

typedef struct {
    /* 0x00 */ Animation* anim;
    /* 0x04 */ Limb** skeleton;
    /* 0x08 */ s16 setupDL;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f rot;
    /* 0x24 */ Vec3f scale;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ Color_RGBA32 prim;
} UnkStruct_196D08; // size = 0x40

extern UnkStruct_196D08 D_ending_80196D08[10];
extern Vec3f D_ending_80198600[300];

// Team shadows in the ending
RECOMP_PATCH void Ending_801876A4(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        Matrix_Push(&gGfxMatrix);

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ADDRESS(aTeamShadowDL) + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        RCP_SetupDL(&gMasterDisp, SETUPDL_62);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 240);
        Matrix_Translate(gGfxMatrix, D_ending_80196D08[i].pos.x, D_ending_80196D08[i].pos.y, D_ending_80196D08[i].pos.z,
                         MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, D_ending_80196D08[i].scale.x + 4.0f, D_ending_80196D08[i].scale.y + 4.0f,
                     D_ending_80196D08[i].scale.z + 4.0f, MTXF_APPLY);
        Matrix_RotateY(gGfxMatrix, D_ending_80196D08[i].rot.y * M_DTOR, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, (D_ending_80196D08[i].rot.x + 5.0f) * M_DTOR, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, D_ending_80196D08[i].rot.z * M_DTOR, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, aTeamShadowDL);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        Matrix_Pop(&gGfxMatrix);
    }
}

#if DEBUG_ENDING == 1
extern bool sLevelStartState;
extern s32 sWipeHeight;

RECOMP_PATCH void Title_NextState_OptionMenu(void) {
    if (gControllerLock == 0) {
        switch (sLevelStartState) {
            case 0: // Wait for input
                if (((gControllerPress[gMainController].button & START_BUTTON) ||
                     (gControllerPress[gMainController].button & A_BUTTON)) &&
                    !sLevelStartState) {
                    AUDIO_PLAY_SFX(NA_SE_DECIDE, gDefaultSfxSource, 4);
                    SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_BGM, 30);
                    SEQCMD_STOP_SEQUENCE(SEQ_PLAYER_FANFARE, 30);
                    sWipeHeight = 0;
                    sLevelStartState = true;
                }
                break;

            case 1: // Go to the Option Menu
                if (sWipeHeight < 120) {
                    sWipeHeight += 18;
                } else {
                    gGameState = GSTATE_ENDING;
                    gNextGameStateTimer = 2;
                    gOptionMenuStatus = OPTION_WAIT;
                    gDrawMode = DRAW_NONE;
                    gStarCount = 0;
                    sLevelStartState = false;
                    sWipeHeight = 0;
                    gControllerLock = 3;
                }
                break;
        }
    }
}
#endif

RECOMP_PATCH void Ending_80191C7C(u32 arg0, AssetInfo* asset) {
    f32 temp;

    RCP_SetupDL(&gMasterDisp, asset->unk_08);

    gSPFogPosition(gMasterDisp++, asset->fogNear, asset->fogFar);
    gDPSetFogColor(gMasterDisp++, asset->fog.r, asset->fog.g, asset->fog.b, 0);
    gDPSetEnvColor(gMasterDisp++, asset->env.r, asset->env.g, asset->env.b, asset->env.a);
    gDPSetPrimColor(gMasterDisp++, 0, 0, asset->prim.r, asset->prim.g, asset->prim.b, asset->prim.a);

    Matrix_Translate(gGfxMatrix, asset->unk_18.x + (arg0 - asset->unk_0C) * asset->unk_3C.x,
                     asset->unk_18.y + (arg0 - asset->unk_0C) * asset->unk_3C.y,
                     asset->unk_18.z + (arg0 - asset->unk_0C) * asset->unk_3C.z, MTXF_APPLY);

    Matrix_Scale(gGfxMatrix, asset->unk_30.x, asset->unk_30.y, asset->unk_30.z, MTXF_APPLY);

    temp = __sinf(arg0 * 0.1f + asset->unk_70);

    Matrix_RotateY(gGfxMatrix,
                   M_DTOR * (asset->unk_24.y + temp * asset->unk_54.y + (arg0 - asset->unk_0C) * asset->unk_48.y),
                   MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix,
                   M_DTOR * (asset->unk_24.x + temp * asset->unk_54.x + (arg0 - asset->unk_0C) * asset->unk_48.x),
                   MTXF_APPLY);
    Matrix_RotateZ(gGfxMatrix,
                   M_DTOR * (asset->unk_24.z + temp * asset->unk_54.z + (arg0 - asset->unk_0C) * asset->unk_48.z),
                   MTXF_APPLY);

    Matrix_SetGfxMtx(&gMasterDisp);

    Animation_GetFrameData(asset->unk_00,
                           (u32) ((arg0 + asset->unk_70) * asset->unk_14) % Animation_GetFrameCount(asset->unk_00),
                           D_ending_80198600);
    Animation_DrawSkeleton(0, asset->unk_04, D_ending_80198600, NULL, NULL, NULL, &gIdentityMatrix);
}