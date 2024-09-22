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
extern f32 D_menu_801CDA10;
extern f32 D_menu_801CDA0C;
extern ObjPosition sMapArea6Ships[4];
extern s32 D_menu_801CD97C;
extern f32 sCursorYpos;
extern f32 D_menu_801CEAB0;
extern f32 D_menu_801CEAAC;
extern s32 D_menu_801CEEA8;
extern Vec3f D_menu_801CEEB0;
extern f32 D_menu_801AFFF4;
extern f32 D_menu_801AFFFC;
extern Matrix D_menu_801CDE20[15];

void Map_PathPlanetMedal_Draw(f32 x, f32 y, f32 z);
void Map_SolarRays_Draw(PlanetId);
void Map_VenomCloud2_Draw(PlanetId planetId);
void Map_PlanetShadow_Draw(PlanetId planetId);
void Map_PlanetMedal_Draw(PlanetId planetId);
void Map_PlanetExplosions_Draw(s32, PlanetExplosions);
void Map_PlanetCleared_Draw(PlanetId planetId);
void Map_PlanetAnim2(PlanetId planetId);
void Map_PlanetAnim(PlanetId planetId);
void Map_Titania_DrawRings1(PlanetId planetId);
void Map_Titania_DrawRings2(PlanetId planetId);
void Map_VenomCloud_Draw(f32* zAngle, f32 next, f32 scale);
void Map_PlanetCleared2_Draw(PlanetId planetId);
s32 Map_CheckPlanetMedal(PlanetId planetId);

#if 1

RECOMP_PATCH void Map_Planet_Draw(PlanetId planetId) __attribute__((optnone)) {
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
    Map_PlanetAnim2(planetId);
    Map_PlanetCleared2_Draw(planetId);
    Matrix_Push(&gGfxMatrix);

    if ((gGameFrameCount & mask) != 0) {
        if (planetId == PLANET_TITANIA) {
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_TITANIA_RINGS, G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);
            Map_Titania_DrawRings1(planetId);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
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
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, (TAG_SOLAR_RAYS) + planetId, G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);
            Map_SolarRays_Draw(planetId);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
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
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_TITANIA_RINGS + 1, G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);
            Map_Titania_DrawRings2(planetId);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
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
            // @recomp Tag the transform.
            gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_MEDAL + planetId, G_EX_PUSH, G_MTX_MODELVIEW,
                                           G_EX_EDIT_ALLOW);
            Map_PlanetMedal_Draw(planetId);
            // @recomp Pop the transform id.
            gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
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

// Workaround to fix compiler mips generation (Thanks clang...)
s32 checkIfPlanetIdNotEq9(s32 planetId) __attribute__((optnone)) {
    if (planetId != 9) {
        return 5;
    } else {
        return 10;
    }
}

bool checkExplosionInKatina(s32 explosionIdx) __attribute__((optnone)) {
    if (explosionIdx == EXPLOSIONS_KATINA) {
        return true;
    } else {
        return false;
    }
}

#if 1
RECOMP_PATCH void Map_PlanetExplosions_Draw(s32 planetId, PlanetExplosions explosionIdx) {
    s32 i;
    f32 temp;

    if (sPlanets[planetId].alpha == 0) {
        return;
    }

    if (!sPlanetExplosions[explosionIdx]) {
        return;
    }

    RCP_SetupDL(&gMasterDisp, SETUPDL_67);

    gDPSetEnvColor(gMasterDisp++, 255, 0, 0, 0);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedSkipAll(gMasterDisp++, TAG_PLANET_EXPLOSIONS, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    for (i = 0; i < checkIfPlanetIdNotEq9(planetId); i++) {
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

                if (checkExplosionInKatina(explosionIdx)) {
                    temp = 50.0f;
                } else {
                    temp = 110.0f;
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

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}
#endif

RECOMP_PATCH void Map_Area6Ships_Draw(void) {
    Vec3f src;
    Vec3f dest;
    f32 x1;
    f32 y1;
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 mask;
    static f32 D_menu_801B6A80 = -22.0f;

    if ((sPlanets[PLANET_AREA_6].alpha == 0) && (sCurrentPlanetId != PLANET_AREA_6)) {
        return;
    }

    if ((sCurrentPlanetId == PLANET_AREA_6) && (sMapState == MAP_ZOOM_PLANET) && (D_menu_801CD95C != 0)) {
        mask = 0x00000001;
    } else {
        mask = 0xFFFFFFFF;
    }

    if ((sMapState == MAP_IDLE) || (sCurrentPlanetId == PLANET_AREA_6)) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_23);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_46);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, sPlanets[PLANET_AREA_6].alpha);
    }

    dest.x = 0.0f;
    dest.y = 0.0f;
    dest.z = 0.0f;

    if ((gGameFrameCount & mask) != 0) {

        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_AREA6_SHIPS, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);
        for (i = 0; i < ARRAY_COUNT(sMapArea6Ships); i++) {
            Matrix_Push(&gGfxMatrix);

            Matrix_RotateY(gGfxMatrix, M_DTOR * sMapArea6Ships[i].angle, MTXF_APPLY);
            Matrix_Translate(gGfxMatrix, sMapArea6Ships[i].x, sMapArea6Ships[i].y, 0.0f, MTXF_APPLY);
            Matrix_RotateY(gGfxMatrix, M_DTOR * -(sMapArea6Ships[i].angle), MTXF_APPLY);

            Map_CamMatrixRot();

            Matrix_RotateY(gGfxMatrix, M_DTOR * D_menu_801B6A80, MTXF_APPLY);
            Matrix_Scale(gGfxMatrix, sMapArea6Ships[i].scale, sMapArea6Ships[i].scale, sMapArea6Ships[i].scale,
                         MTXF_APPLY);

            Matrix_SetGfxMtx(&gMasterDisp);

            Matrix_MultVec3f(gGfxMatrix, &dest, &src);

            x = sPlanetPositions[PLANET_SOLAR].x - src.x;
            y = sPlanetPositions[PLANET_SOLAR].y - src.y;
            z = sPlanetPositions[PLANET_SOLAR].z - src.z;

            x1 = Math_Atan2F(y, sqrtf(SQ(x) + SQ(z)));
            y1 = -Math_Atan2F(x, z);

            dest.x = 0.0f;
            dest.y = 0.0f;
            dest.z = 100.0f;

            Matrix_RotateY(gCalcMatrix, M_DTOR * (-D_menu_801CDA10 - y1), MTXF_NEW);
            Matrix_RotateX(gCalcMatrix, M_DTOR * (-D_menu_801CDA0C - x1), MTXF_APPLY);

            Matrix_MultVec3f(gCalcMatrix, &dest, &src);
            Lights_SetOneLight(&gMasterDisp, src.x, src.y, src.z, 80, 80, 60, 0, 0, 0);

            gSPDisplayList(gMasterDisp++, aMapArea6ShipDL);

            Matrix_Pop(&gGfxMatrix);
        }

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}

RECOMP_PATCH void Map_Arwing_Draw(s32 index) {
    f32 dirX;
    f32 dirY;
    f32 dirZ;
    Vec3f dest;
    Vec3f src;
    f32 x1;
    f32 y1;
    f32 x;
    f32 y;
    f32 z;

    src.x = 0.0f;
    src.y = 0.0f;
    src.z = 0.0f;

    if (D_menu_801CEEA8 == 255) {
        RCP_SetupDL(&gMasterDisp, SETUPDL_23);
    } else {
        RCP_SetupDL(&gMasterDisp, SETUPDL_46);
        gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, D_menu_801CEEA8);
    }

    Matrix_Push(&gGfxMatrix);

    Matrix_Translate(gGfxMatrix, D_menu_801CEEB0.x, D_menu_801CEEB0.y, D_menu_801CEEB0.z, MTXF_APPLY);

    Matrix_RotateY(gGfxMatrix, gTexturedLines[index].yRot, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, M_DTOR * -90.0f, MTXF_APPLY);
    Matrix_RotateX(gGfxMatrix, gTexturedLines[index].xRot, MTXF_APPLY);

    Matrix_Scale(gGfxMatrix, 0.8f, 0.8f, 0.8f, MTXF_APPLY);

    Matrix_SetGfxMtx(&gMasterDisp);

    Matrix_MultVec3f(gGfxMatrix, &src, &dest);

    x = sPlanetPositions[PLANET_SOLAR].x - dest.x;
    y = sPlanetPositions[PLANET_SOLAR].y - dest.y;
    z = sPlanetPositions[PLANET_SOLAR].z - dest.z;

    x1 = Math_Atan2F(y, sqrtf(SQ(x) + SQ(z)));
    y1 = -Math_Atan2F(x, z);

    src.x = 0.0f;
    src.y = 0.0f;
    src.z = 10.0f;

    Matrix_RotateY(gCalcMatrix, M_DTOR * (-D_menu_801CDA10 - y1), MTXF_NEW);
    Matrix_RotateX(gCalcMatrix, M_DTOR * (-D_menu_801CDA0C - x1), MTXF_APPLY);
    Matrix_MultVec3f(gCalcMatrix, &src, &dest);

    dirX = dest.x;
    dirY = dest.y;
    dirZ = dest.z;

    Lights_SetOneLight(&gMasterDisp, dirX, dirY, dirZ, 50, 50, 40, 0, 0, 0);

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedSkipAll(gMasterDisp++, TAG_ARWING, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    gSPDisplayList(gMasterDisp++, aMapArwingDL);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    Matrix_Pop(&gGfxMatrix);
}

RECOMP_PATCH void Map_PathPlanet_Draw(s32 missionIdx, f32 x, f32 y, PlanetId planetId) __attribute__((optnone)) {
    s32 mask = 0xFFFFFFFF;

    if ((gGameState == GSTATE_MAP) && (planetId == sCurrentPlanetId)) {
        mask = 0x00000010;
    }

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedSkipAll(gMasterDisp++, TAG_PATH_PLANET, G_EX_PUSH, G_MTX_MODELVIEW, G_EX_EDIT_ALLOW);

    switch (planetId) {
        case PLANET_SOLAR:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_67);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 240, 0, 0, 255);
                gDPSetEnvColor(gMasterDisp++, 31, 0, 0, 0);

                Matrix_Push(&gGfxMatrix);
                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * (sPlanets[planetId].orbit.tilt), MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.11f, 0.11f, 0.11f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 128);
                gDPSetEnvColor(gMasterDisp++, 31, 0, 0, 0);

                Matrix_Scale(gGfxMatrix, 0.8f, 0.8f, 0.8f, MTXF_APPLY);
                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                Matrix_Pop(&gGfxMatrix);
            }
            break;

        case PLANET_METEO:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_62);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, x - 0.4f, y + 0.9f, 0.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * sPlanets[planetId].orbit.tilt, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.1f, 0.1f, 0.1f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                Matrix_Translate(gGfxMatrix, 18.0f, -20.0f, 0.0f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);
                Matrix_Pop(&gGfxMatrix);
            }
            break;

        case PLANET_SECTOR_X:
        case PLANET_SECTOR_Y:
        case PLANET_SECTOR_Z:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_62);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 144);

                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * sPlanets[planetId].orbit.tilt, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.09f, 0.09f, 0.09f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                Matrix_Pop(&gGfxMatrix);
            }
            break;

        case PLANET_BOLSE:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_23);

                Lights_SetOneLight(&gMasterDisp, 0, 0, 100, 50, 50, 40, 100, 100, 100);

                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_RotateX(gGfxMatrix, M_DTOR * 20.0f, MTXF_APPLY);
                Matrix_RotateY(gGfxMatrix, M_DTOR * D_menu_801AFFF4, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * sPlanets[planetId].orbit.tilt, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.004f, 0.004f, 0.004f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                Matrix_Pop(&gGfxMatrix);
            }
            break;

        case PLANET_AREA_6:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_23);

                Lights_SetOneLight(&gMasterDisp, 0, 0, 100, 50, 50, 40, 100, 100, 100);

                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_RotateX(gGfxMatrix, M_DTOR * 20.0f, MTXF_APPLY);
                Matrix_RotateY(gGfxMatrix, M_DTOR * D_menu_801AFFFC, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * sPlanets[planetId].orbit.tilt, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.003f, 0.003f, 0.003f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                Matrix_Pop(&gGfxMatrix);
            }
            break;

        default:
            if ((gGameFrameCount & mask) != 0) {
                RCP_SetupDL(&gMasterDisp, SETUPDL_62);

                gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);

                Matrix_Push(&gGfxMatrix);

                Matrix_Translate(gGfxMatrix, x, y, 0.0f, MTXF_APPLY);
                Matrix_RotateZ(gGfxMatrix, M_DTOR * sPlanets[planetId].orbit.tilt, MTXF_APPLY);
                Matrix_Scale(gGfxMatrix, 0.1f, 0.1f, 0.1f, MTXF_APPLY);

                Matrix_SetGfxMtx(&gMasterDisp);

                gSPDisplayList(gMasterDisp++, sMapPlanets[sPlanets[planetId].id]);

                if (sPlanets[planetId].anim == PL_ANIM_SPIN) {
                    if (planetId != PLANET_VENOM && planetId != PLANET_AQUAS) {
                        Matrix_SetGfxMtx(&gMasterDisp);
                        if (planetId == PLANET_MACBETH) {
                            gDPSetPrimColor(gMasterDisp++, 0, 0, 64, 64, 64, 255);
                        } else {
                            gDPSetPrimColor(gMasterDisp++, 0, 0, 255, 255, 255, 255);
                        }
                        gSPDisplayList(gMasterDisp++, gMapVenomCloudDL);
                    }
                    Matrix_Scale(gGfxMatrix, 1.6f, 1.6f, 1.6f, MTXF_APPLY);
                    Matrix_SetGfxMtx(&gMasterDisp);
                    gSPDisplayList(gMasterDisp++, D_MAP_605C230);
                }
                Matrix_Pop(&gGfxMatrix);
            }
            break;
    }

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);

    if (gMissionMedal[missionIdx] != 0) {
        // @recomp Tag the transform.
        gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_PATH_PLANET_MEDAL, G_EX_PUSH, G_MTX_MODELVIEW,
                                       G_EX_EDIT_ALLOW);

        Map_PathPlanetMedal_Draw(x, y, 0.0f);

        // @recomp Pop the transform id.
        gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
    }
}
/*
RECOMP_PATCH void Map_VenomCloud_Draw(f32* zAngle, f32 next, f32 scale) {
    s32 alpha = sPlanets[PLANET_VENOM].alpha;

    if (sPlanets[PLANET_VENOM].alpha > 128) {
        alpha = 128;
    }
    
    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_VENOM_CLOUD_1, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_67);

    gDPSetPrimColor(gMasterDisp++, 0, 0, 63, 95, 30, alpha);
    gDPSetEnvColor(gMasterDisp++, 0, 0, 0, 0);

    Matrix_Push(&gGfxMatrix);

    Matrix_Copy(gGfxMatrix, &D_menu_801CDE20[PLANET_VENOM]);
    Matrix_RotateZ(gGfxMatrix, M_DTOR * (*zAngle), MTXF_APPLY);
    Matrix_Scale(gGfxMatrix, scale, scale, scale, MTXF_APPLY);

    Matrix_SetGfxMtx(&gMasterDisp);

    gSPDisplayList(gMasterDisp++, aMapVenomCloudDL);

    Matrix_Pop(&gGfxMatrix);

    *zAngle += next;

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}

RECOMP_PATCH void Map_VenomCloud2_Draw(PlanetId planetId) {
    s32 r;
    s32 g;
    s32 b;

    r = g = b = 255;

    if (planetId == PLANET_MACBETH) {
        r = g = b = 64;
    }

    // @recomp Tag the transform.
    gEXMatrixGroupDecomposedNormal(gMasterDisp++, TAG_VENOM_CLOUD_2, G_EX_PUSH, G_MTX_MODELVIEW,
                                   G_EX_EDIT_ALLOW);

    RCP_SetupDL(&gMasterDisp, SETUPDL_64);

    gDPSetPrimColor(gMasterDisp++, 0, 0, r, g, b, sPlanets[planetId].alpha);

    Matrix_Push(&gGfxMatrix);
    Matrix_Copy(gGfxMatrix, &D_menu_801CDE20[planetId]);
    Matrix_SetGfxMtx(&gMasterDisp);

    gSPDisplayList(gMasterDisp++, gMapVenomCloudDL);

    Matrix_Pop(&gGfxMatrix);

    // @recomp Pop the transform id.
    gEXPopMatrixGroup(gMasterDisp++, G_MTX_MODELVIEW);
}
*/

#endif