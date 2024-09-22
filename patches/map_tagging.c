#include "patches.h"
#include "fox_map.h"

extern PlanetId sCurrentPlanetId;
extern Planet sPlanets[15];
extern s32 sMapState;
extern s32 D_menu_801CD95C;
extern Vec3f sPlanetPositions[15];
extern f32 D_menu_801CEA18[15];
extern f32 D_menu_801CEEBC;
extern f32 D_menu_801CEEC0;
extern s32 D_menu_801CEB58[3][10];
extern s32 D_menu_801CEBD0[3][10];
extern f32 D_menu_801CEC48[3][10];
extern f32 D_menu_801CECC0[3][10];
extern f32 D_menu_801CED38[3][10];
extern f32 D_menu_801CEDB0[3][10];
extern f32 D_menu_801CEE28[3][10];
extern bool sPlanetExplosions[EXPLOSIONS_MAX];
extern Matrix D_menu_801CDA60[15];

void Map_SolarRays_Draw(PlanetId);
void Map_VenomCloud2_Draw(PlanetId planetId);
void Map_PlanetShadow_Draw(PlanetId planetId);
void Map_PlanetMedal_Draw(PlanetId planetId);
void Map_PlanetExplosions_Draw(PlanetId, PlanetExplosions);
void Map_PlanetCleared_Draw(PlanetId planetId);
void Map_PlanetAnim2(PlanetId planetId);
void Map_PlanetAnim(PlanetId planetId);
void Map_Titania_DrawRings1(PlanetId planetId);
void Map_Titania_DrawRings2(PlanetId planetId);
void Map_VenomCloud_Draw(f32* zAngle, f32 next, f32 scale);
void Map_PlanetCleared2_Draw(PlanetId planetId);
s32 Map_CheckPlanetMedal(PlanetId planetId);

RECOMP_PATCH void Map_Planet_Draw(PlanetId planetId) {
    s32 mask;
    PlanetStatus planetStatus;

    if ((sPlanets[planetId].alpha == 0) && (planetId != sCurrentPlanetId)) {
        return;
    }

    if ((planetId == sCurrentPlanetId) && (sMapState == MAP_ZOOM_PLANET) && (D_menu_801CD95C != 0)) {
        mask = 0x00000001;
    } else {
        mask = 0xFFFFFFFF;
    }

    planetStatus = Map_CheckPlanetMedal(planetId);
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PLANET_ANIM + planetId, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);
    Map_PlanetAnim2(planetId);
    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    Map_PlanetCleared2_Draw(planetId);
    Matrix_Push(&gGfxMatrix);

    if ((gGameFrameCount & mask) != 0) {
        if (planetId == PLANET_TITANIA) {
            Map_Titania_DrawRings1(planetId);
        }

        if ((planetStatus == PLANET_CLEARED) && (sPlanetPositions[planetId].z > D_menu_801CEA18[planetId]) &&
            (planetId != PLANET_AREA_6) && (planetId != PLANET_BOLSE)) {
            Map_PlanetCleared_Draw(planetId);
        }

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, (TAG_PLANET_ANIM_2) + planetId, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);
        Map_PlanetAnim(planetId);
        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

        if (planetId == PLANET_SOLAR) {
            Map_SolarRays_Draw(planetId);
        }

        if (sPlanets[planetId].anim == PL_ANIM_SPIN) {
            if (planetId != PLANET_VENOM) {
                if ((planetId != PLANET_AQUAS) && (planetId != PLANET_TITANIA)) {
                    Map_VenomCloud2_Draw(planetId);
                }
                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PLANET_SHADOW + planetId, G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);
                Map_PlanetShadow_Draw(planetId);
                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
            if (planetId == PLANET_VENOM) {
                Map_VenomCloud_Draw(&D_menu_801CEEBC, +0.1f, 3.1f);
                Map_VenomCloud_Draw(&D_menu_801CEEC0, -0.1f, 2.9f);
            }
        }

        if (planetId == PLANET_TITANIA) {
            Map_Titania_DrawRings2(planetId);
        }

        if ((planetId == PLANET_CORNERIA) && sPlanetExplosions[EXPLOSIONS_CORNERIA]) {
            Map_PlanetExplosions_Draw(PLANET_CORNERIA, EXPLOSIONS_CORNERIA);
        }

        if ((planetId == PLANET_KATINA) && sPlanetExplosions[EXPLOSIONS_KATINA]) {
            Map_PlanetExplosions_Draw(PLANET_KATINA, EXPLOSIONS_KATINA);
        }

        if ((planetId == PLANET_SECTOR_Y) && sPlanetExplosions[EXPLOSIONS_SECTOR_Y]) {
            Map_PlanetExplosions_Draw(PLANET_SECTOR_Y, EXPLOSIONS_SECTOR_Y);
        }

        if ((planetStatus == PLANET_CLEARED) && (sPlanetPositions[planetId].z <= D_menu_801CEA18[planetId]) &&
            (planetId != PLANET_AREA_6) && (planetId != PLANET_BOLSE)) {
            Map_PlanetCleared_Draw(planetId);
        }

        if ((planetStatus == PLANET_CLEARED) && ((planetId == PLANET_AREA_6) || (planetId == PLANET_BOLSE))) {
            Map_PlanetCleared_Draw(planetId);
        }

        if (planetStatus == PLANET_MEDAL) {
            Map_PlanetMedal_Draw(planetId);
        }
    }
    Matrix_Pop(&gGfxMatrix);
}

extern ObjPosition sMapMeteors[42];
extern Gfx* sMapPlanets[15];

void Map_CamMatrixRot(void);

RECOMP_PATCH void Map_MeteoMeteors_Draw(void) {
    s32 i;
    s32 mask;

    if ((sPlanets[PLANET_METEO].alpha != 0) || (sCurrentPlanetId == PLANET_METEO)) {
        if ((sCurrentPlanetId == PLANET_METEO) && (sMapState == MAP_ZOOM_PLANET) && (D_menu_801CD95C != 0)) {
            mask = 0x00000001;
        } else {
            mask = 0xFFFFFFFF;
        }

        if ((sMapState == MAP_IDLE) || ((sCurrentPlanetId == PLANET_METEO) && (sMapState != MAP_GAME_OVER))) {
            RCP_SetupDL(&gMasterDisp, SETUPDL_53);
        } else {
            RCP_SetupDL(&gMasterDisp, SETUPDL_64);
            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, sPlanets[PLANET_METEO].alpha);
        }

        if ((gGameFrameCount & mask) != 0) {
            for (i = 0; i < ARRAY_COUNT(sMapMeteors); i++) {
                Matrix_Push(&gGfxMatrix);

                Matrix_RotateY(gGfxMatrix, M_DTOR * sMapMeteors[i].angle, MTXF_APPLY);
                Matrix_Translate(gGfxMatrix, sMapMeteors[i].x, sMapMeteors[i].y, 0.0f, MTXF_APPLY);
                Matrix_RotateY(gGfxMatrix, M_DTOR * -sMapMeteors[i].angle, MTXF_APPLY);

                Map_CamMatrixRot();

                Matrix_Scale(gGfxMatrix, sMapMeteors[i].scale, sMapMeteors[i].scale, sMapMeteors[i].scale, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                // @recomp Tag the transform.
                gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PLANET_METEOR + i, G_EX_PUSH, G_MTX_MODELVIEW,
                                               G_EX_EDIT_ALLOW);

                gSPDisplayList(gMasterDisp++, sMapPlanets[PLANET_METEO]);

                Matrix_Pop(&gGfxMatrix);

                // @recomp Pop the transform id.
                gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
            }
        }
    }
}

#if 0

RECOMP_PATCH void Map_PlanetExplosions_Draw(PlanetId planetId, PlanetExplosions explosionIdx) {
    s32 i;
    s32 temp2;
    f32 temp;

    if (sPlanets[planetId].alpha == 0) {
        return;
    }

    if (!sPlanetExplosions[explosionIdx]) {
        return;
    }

    temp2 = 10;
    if (planetId != PLANET_CORNERIA) {
        temp2 = 5;
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_67);

    gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 0);

    for (i = 0; i < temp2; i++) {
        switch (D_menu_801CEB58[explosionIdx][i]) {
            case 0:
                D_menu_801CEC48[explosionIdx][i] += 0.1f;
                if (D_menu_801CEC48[explosionIdx][i] >= D_menu_801CECC0[explosionIdx][i]) {
                    D_menu_801CEC48[explosionIdx][i] = D_menu_801CECC0[explosionIdx][i];
                    D_menu_801CEB58[explosionIdx][i] = 1;
                }
                break;

            case 1:
                D_menu_801CEE28[explosionIdx][i]--;
                if (D_menu_801CEE28[explosionIdx][i] <= 0) {
                    D_menu_801CEB58[explosionIdx][i] = 2;
                }
                break;

            case 2:
                D_menu_801CEBD0[explosionIdx][i] -= 48;
                if (D_menu_801CEBD0[explosionIdx][i] < 0) {
                    D_menu_801CEBD0[explosionIdx][i] = 0;
                    D_menu_801CEB58[explosionIdx][i] = 3;
                }
                break;

            case 3:
                D_menu_801CEB58[explosionIdx][i] = RAND_INT(3.0f);
                D_menu_801CEBD0[explosionIdx][i] = 255;
                D_menu_801CEC48[explosionIdx][i] = 0.0f;
                D_menu_801CECC0[explosionIdx][i] = 0.5f + RAND_FLOAT(0.3f);
                D_menu_801CEE28[explosionIdx][i] = 1 + RAND_INT(4.0f);

                temp = 110.0f;
                if (explosionIdx == EXPLOSIONS_KATINA) {
                    temp = 50.0f;
                }

                D_menu_801CED38[explosionIdx][i] = temp + RAND_INT(30.0f);
                D_menu_801CEDB0[explosionIdx][i] = -10.0f + RAND_FLOAT(-60.0f);
                break;
        }

        if ((D_menu_801CECC0[explosionIdx][i] == 0.0f) || (D_menu_801CEBD0[explosionIdx][i] == 0)) {
            continue;
        }

        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 200, 200, D_menu_801CEBD0[explosionIdx][i]);

        Matrix_Push(&gGfxMatrix);

        Matrix_Mult(gGfxMatrix, &D_menu_801CDA60[planetId], MTXF_APPLY);
        Matrix_RotateZ(gGfxMatrix, M_DTOR * D_menu_801CEDB0[explosionIdx][i], MTXF_APPLY);
        Matrix_Translate(gGfxMatrix, 0.0f, D_menu_801CED38[explosionIdx][i], 0.0f, MTXF_APPLY);
        Matrix_Scale(gGfxMatrix, D_menu_801CEC48[explosionIdx][i], D_menu_801CEC48[explosionIdx][i],
                     D_menu_801CEC48[explosionIdx][i], MTXF_APPLY);

        Matrix_SetGfxMtx(&gMasterDisp);

        gSPDisplayList(gMasterDisp++, aMapPlanetExplosionDL);

        Matrix_Pop(&gGfxMatrix);
    }
}
#endif