#include "patches.h"

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