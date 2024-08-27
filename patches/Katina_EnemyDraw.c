#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "gfx.h"
#include "macros.h"
#include "sf64thread.h"
#include "sf64object.h"
#include "context.h"
#include "patches.h"

#define KA_ACTOR_LOW_POLY (23)
#define KA_ACTOR_IWORK_8 (8)
#define EG_RED (0)


extern Gfx aKaEnemy1DL[];
extern Gfx aKaCornerianFighterDL[];

void Actor_DrawEngineGlow(Actor*, EngineGlowColor);


// @recomp Disable LOD on Katina enemies
RECOMP_PATCH void Katina_EnemyDraw(ActorAllRange *this)
{
    s32 pad3[3];
    f32 angle;
    Vec3f D_i4_8019F4A8 = {0.0f, 0.0f, 0.0f};
    Vec3f pad[30];

    this->iwork[KA_ACTOR_LOW_POLY] = false;

    if ((this->iwork[KA_ACTOR_IWORK_8] != 0) && (this->aiType < AI360_GREAT_FOX))
    {
        angle = SIN_DEG(this->iwork[KA_ACTOR_IWORK_8] * 400.0f) * this->iwork[KA_ACTOR_IWORK_8];
        Matrix_RotateY(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_RotateX(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, M_DTOR * angle, MTXF_APPLY);
        Matrix_SetGfxMtx(&gMasterDisp);
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_29);

    if ((this->timer_0C6 % 2) == 0)
    {
        gSPFogPosition(gMasterDisp++, gFogNear, 1005);
    }

    switch (this->animFrame)
    {
    case 0:
        gSPDisplayList(gMasterDisp++, aKaEnemy1DL);
        break;

    case 1:
        gSPDisplayList(gMasterDisp++, aKaCornerianFighterDL);
        Matrix_Translate(gGfxMatrix, 0.0f, 0.0f, -60.0f, MTXF_APPLY);
        Actor_DrawEngineGlow(this, EG_RED);
        break;
    }
}