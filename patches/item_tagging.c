
#include "patches.h"

extern Gfx D_101A570[];
extern Gfx D_1019CA0[];
extern Gfx D_1016870[];
extern Gfx aItemBombDL[];
extern Gfx D_1022E80[];
extern Gfx D_1019820[];
extern Gfx D_101A8E0[];
extern Gfx aCheckpointCenterDL[];
extern Gfx aCheckpointArrowDL[];
extern Gfx D_blue_marine_3005980[];

RECOMP_PATCH void ItemCheckpoint_Draw(ItemCheckpoint* this) {
    s32 i;

    if (((gGameFrameCount & 0x18) != 0) && (this->state == 0)) {
        Matrix_Push(&gGfxMatrix);
        RCP_SetupDL(&gMasterDisp, SETUPDL_64);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 0, 255);
        Matrix_Scale(gGfxMatrix, 3.2f, 3.2f, 3.2f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gDPSetTextureFilter(gMasterDisp++, G_TF_POINT);
        gSPDisplayList(gMasterDisp++, aCheckpointCenterDL);
        gDPSetTextureFilter(gMasterDisp++, G_TF_BILERP);
        Matrix_Pop(&gGfxMatrix);
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    gSPTexture(gMasterDisp++, 2000, 2000, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
    Matrix_RotateZ(gGfxMatrix, this->unk_58 * M_DTOR, MTXF_APPLY);

    for (i = 0; i < 8; i++) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, (TAG_ITEM(this) | 0x10) + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);
        Matrix_Push(&gGfxMatrix);
        Matrix_RotateZ(gGfxMatrix, i * 45.0f * M_DTOR, MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 2.0f * this->width, 0.0f, 0.0f, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, (gGameFrameCount + (i * 110.0f)) * M_DTOR * 7.2f * this->unk_54, MTXF_APPLY);
        Graphics_SetScaleMtx(2.0f * this->unk_50);
        gSPDisplayList(gMasterDisp++, aCheckpointArrowDL);
        Matrix_Pop(&gGfxMatrix);
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
}

#if 0

RECOMP_PATCH void ItemSilverRing_Draw(ItemSilverRing* this) {
    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    gSPTexture(gMasterDisp++, 3000, 0, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    Graphics_SetScaleMtx(this->width);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    gSPDisplayList(gMasterDisp++, D_101A570);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
}

RECOMP_PATCH void ItemSilverStar_Draw(ItemSilverStar* this) {
    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    gSPTexture(gMasterDisp++, 3000, 0, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    Graphics_SetScaleMtx(this->width);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    gSPDisplayList(gMasterDisp++, D_1019CA0);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
}

RECOMP_PATCH void ItemGoldRing_Draw(ItemGoldRing* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    gSPTexture(gMasterDisp++, 1900, 1700, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    Graphics_SetScaleMtx(this->width);
    gSPDisplayList(gMasterDisp++, D_1016870);
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void ItemBomb_Draw(ItemBomb* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    if (gCurrentLevel == LEVEL_AQUAS) {
        Graphics_SetScaleMtx(this->width);
        gSPDisplayList(gMasterDisp++, D_blue_marine_3005980);
    } else {
        Graphics_SetScaleMtx(this->width * 0.1f);
        RCP_SetupDL(&gMasterDisp, SETUPDL_29);
        gSPTexture(gMasterDisp++, 2000, 2000, 0, G_TX_RENDERTILE, G_ON);
        gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
        gSPDisplayList(gMasterDisp++, aItemBombDL);
        gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
        RCP_SetupDL(&gMasterDisp, SETUPDL_27);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
        gSPDisplayList(gMasterDisp++, D_1022E80);
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void ItemLasers_Draw(ItemLasers* this) {
    Graphics_SetScaleMtx(this->width * 0.1f);
    RCP_SetupDL(&gMasterDisp, SETUPDL_29);
    gSPTexture(gMasterDisp++, 2000, 2000, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, D_1019820);
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
    RCP_SetupDL(&gMasterDisp, SETUPDL_27);
    gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, 255);
    gSPDisplayList(gMasterDisp++, D_101A8E0);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void ItemMeteoWarp_Draw(ItemMeteoWarp* this) {
    s32 i;

    this->obj.rot.y = (Math_Atan2F(gPlayer[gPlayerNum].cam.eye.x - this->obj.pos.x,
                                   gPlayer[gPlayerNum].cam.eye.z - (this->obj.pos.z + gPathProgress)) *
                       180.0f) /
                      M_PI;
    if (this->state != 0) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_41);
        gDPSetPrimColor(gMasterDisp++, 0x00, 0x00, 255, 255, 255, this->unk_44);
    } else {
        RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
    }

    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK | G_LIGHTING);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_ITEM(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    for (i = 0; i < 7; i++) {
        Matrix_Push(&gGfxMatrix);
        Matrix_RotateZ(gGfxMatrix, (i * 360.0f / 7.0f) * M_DTOR, MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 0.0f, this->width, 0.0f, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
        gSPDisplayList(gMasterDisp++, D_102FE80);
        Matrix_Pop(&gGfxMatrix);
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK | G_LIGHTING);
}
#endif