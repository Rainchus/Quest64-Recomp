#include "patches.h"

extern Gfx aOrbDL[];

RECOMP_PATCH void Katina_LaserEnergyParticlesDraw(Effect358* this) {
    RCP_SetupDL(&gMasterDisp, SETUPDL_67);

    gDPSetPrimColor(gMasterDisp++, 0, 0, 48, 48, 255, this->unk_44);
    gDPSetEnvColor(gMasterDisp++, 0, 0, 0, this->unk_44);

    Matrix_Scale(gGfxMatrix, 0.4f, 0.4f, 0.4f, MTXF_APPLY);
    Matrix_SetGfxMtx(&gMasterDisp);
   // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_EFFECT + this->index, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
    gSPDisplayList(gMasterDisp++, aOrbDL);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    RCP_SetupDL(&gMasterDisp, SETUPDL_64);
}