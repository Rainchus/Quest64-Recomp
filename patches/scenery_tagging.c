#include "patches.h"

#if 1

typedef struct Scenery2 {
    /* 0x00 */ Object obj;
    /* 0x1C */ ObjectInfo info;
    /* 0x40 */ s32 index;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 state;
    /* 0x4C */ s32 timer_4C;
    /* 0x50 */ s8 dmgType;
    /* 0x54 */ s32 dmgPart;
    /* 0x58 */ Vec3f effectVel;
    /* 0x64 */ Vec3f vel;
    /* 0x70 */ f32 sfxSource[3];
    /* 0x7C */ bool skipRot;
} Scenery2; // size = 0x80

extern Gfx aCoBuilding5DL[];
extern Gfx aCoBuilding6DL[];
extern Gfx aCoBuilding7DL[];
extern Gfx aCoBuilding8DL[];
extern Gfx aCoBuilding9DL[];
extern Gfx aCoBuilding10DL[];
extern Gfx D_CO_60199D0[];

void func_edisplay_8005D008(Object* obj, s32 drawType);
void Object_SetCullDirection(s32);
void Recomp_CoBuilding_Draw(Scenery2* this);

RECOMP_PATCH void Scenery_Draw(Scenery* this, s32 cullDir) {
    this->obj.pos.y += gCameraShakeY;
    func_edisplay_8005D008(&this->obj, this->info.drawType);
    this->obj.pos.y -= gCameraShakeY;

    if (this->info.drawType == 0) {
        if ((this->obj.id == OBJ_SCENERY_CO_TOWER) || (this->obj.id == OBJ_SCENERY_CO_ROCKWALL) ||
            (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_4) || (this->obj.id == OBJ_SCENERY_VE1_WALL_3)) {
            RCP_SetupDL_57(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);

            if (cullDir < 0) {
                Object_ApplyWaterDistortion();
            }
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedSkipRot(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                            G_EX_EDIT_ALLOW);
            gSPDisplayList(gMasterDisp++, this->info.dList);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

            RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
        } else {
            if (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_3) {
                if (cullDir < 0) {
                    return; // weird control flow
                }
                RCP_SetupDL_60(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            }

            Object_SetCullDirection(cullDir);

            if (cullDir < 0) {
                Object_ApplyWaterDistortion();
            }

            // @recomp: Intercepting specific actors.
            switch (this->obj.id) {
                case OBJ_SCENERY_CO_BUILDING_5:
                case OBJ_SCENERY_CO_BUILDING_6:
                case OBJ_SCENERY_CO_BUILDING_7:
                case OBJ_SCENERY_CO_BUILDING_8:
                    Recomp_CoBuilding_Draw((Scenery2*) this);
                    return;

                default:
                    // @recomp Tag the transform.
                    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW,
                                                   G_EX_EDIT_ALLOW);
                    break;
            }
            gSPDisplayList(gMasterDisp++, this->info.dList);

            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);

            if (this->obj.id == OBJ_SCENERY_CO_HIGHWAY_3) {
                RCP_SetupDL_29(gFogRed, gFogGreen, gFogBlue, gFogAlpha, gFogNear, gFogFar);
            }
        }
    } else if (this->info.draw != NULL) {
        Object_SetCullDirection(cullDir);
        this->info.draw(&this->obj);
    }
}

RECOMP_PATCH void CoBuilding9_Draw(CoBuilding9* this) {
    Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -95.0f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    gSPDisplayList(gMasterDisp++, aCoBuilding9DL);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void CoBuilding10_Draw(CoBuilding10* this) {
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    // @recomp ReplaceaCoBuilding10DL for aCoBuilding9DL, a full model of the same building.
    gSPDisplayList(gMasterDisp++, aCoBuilding9DL);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Corneria_CoBuildingOnFire_Draw(CoBuildingOnFire* this) {
    gSPClearGeometryMode(gMasterDisp++, G_CULL_BACK);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    gSPDisplayList(gMasterDisp++, D_CO_60199D0);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    gSPSetGeometryMode(gMasterDisp++, G_CULL_BACK);
}

// @recomp: Replacement draw function for OBJ_SCENERY_CO_BUILDING_8
void Recomp_CoBuilding_Draw(Scenery2* this) {
    f32 prevRot;

    if (this->skipRot) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedSkipRot(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    } else {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_SCENERY(this), G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    }

    prevRot = this->obj.rot.y;

    if (gPlayer[0].cam.eye.x < this->obj.pos.x) {
        this->obj.rot.y = 271.0f;
    } else {
        this->obj.rot.y = 0.0f;
    }

    this->skipRot = prevRot != this->obj.rot.y;

    switch (this->obj.id) {
        case OBJ_SCENERY_CO_BUILDING_5:
            gSPDisplayList(gMasterDisp++, aCoBuilding5DL);
            break;
        case OBJ_SCENERY_CO_BUILDING_6:
            gSPDisplayList(gMasterDisp++, aCoBuilding6DL);
            break;
        case OBJ_SCENERY_CO_BUILDING_7:
            gSPDisplayList(gMasterDisp++, aCoBuilding7DL);
            break;
        case OBJ_SCENERY_CO_BUILDING_8:
            gSPDisplayList(gMasterDisp++, aCoBuilding8DL);
            break;
    }
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    gSPClearGeometryMode(gMasterDisp++, G_TEXTURE_GEN);
}

RECOMP_PATCH void SceneryRotateTowardsCamera(Scenery* this) {
    switch (this->obj.id) {
        case OBJ_SCENERY_CO_BUILDING_5:
        case OBJ_SCENERY_CO_BUILDING_6:
        case OBJ_SCENERY_CO_BUILDING_7:
        case OBJ_SCENERY_CO_BUILDING_8:
        case OBJ_SCENERY_CO_BUILDING_10:
            return;
    }

    if (gPlayer[0].cam.eye.x < this->obj.pos.x) {
        this->obj.rot.y = 271.0f;
    } else {
        this->obj.rot.y = 0.0f;
    }
}

#endif
