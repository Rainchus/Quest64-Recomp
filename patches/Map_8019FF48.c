#define RECOMP_PATCH __attribute__((section(".recomp_patch")))

#include "../lib/sf64decomp/include/PR/ultratypes.h"
#include "../lib/sf64decomp/include/PR/gbi.h"
#include "../lib/sf64decomp/include/context.h"
#include "../lib/sf64decomp/include/sf64math.h"
#include "../lib/sf64decomp/include/fox_map.h"
#include "../lib/sf64decomp/include/PR/os_cont.h"

extern s32 D_menu_801CD944;
extern f32 D_menu_801CD9FC;
extern f32 D_menu_801CDA00;
extern f32 D_menu_801CDA04;
extern f32 D_menu_801CDA08;
extern f32 D_menu_801CD9F4;
extern f32 D_menu_801CD9F8;
extern f32 D_menu_801CD9FC;
extern f32 D_menu_801CDA0C;
extern f32 D_menu_801CDA18;
extern f32 D_menu_801CDA14;
extern f32 D_menu_801CDA10;
extern f32 D_menu_801CDA1C;

void Map_801AD718(f32, f32, f32, f32 *, f32 *, f32 *, f32, f32, f32);
void Map_801A6694(void);
void Map_801A68E4(void);
void Map_801A6A24(void);
void Map_801A0954(void);
void Map_801A1528(void);
void Map_801AD11C(void);
void Map_801A1C14(void);
void Map_801A5E80(void);
void Map_801A2B8C(void);
void Map_801A4AE8(void);
void Map_801A36A8(void);

void Camera_SetStarfieldPos(f32, f32, f32, f32, f32, f32);
void Map_LevelSelect(void);
void RCP_SetupDL(Gfx **gfxP, s16 i);
int recomp_printf(const char *fmt, ...);
extern PlanetId sPlanetList[15];
extern PlanetId sCurrentPlanetId;
extern OSContPad gControllerPress[4];
extern s32 D_menu_801B8280;
extern s32 D_menu_801CD968;
extern s32 D_menu_801CD944;
extern s32 D_menu_801CD948;

void Map_801A61B4(LevelId level);
void Map_801A6368(void);
void Map_801A914C(void);
void Map_801A6628(void);

RECOMP_PATCH void Map_8019FF48(void)
{

    Map_801A6694();
    Map_801A68E4();
    Map_801A6A24();

    switch (D_menu_801CD944)
    {
    case 0:
        Map_801A0954();
        gStarfieldScrollX += 0.09f;
        break;

    case 1:
        Map_801A1528();
        D_menu_801CDA1C += 0.03f;
        break;

    case 3:
        Map_801AD11C();
        D_menu_801CDA1C += 0.03f;
        break;

    case 2:
        Map_801A1C14();
        break;

    case 4:
        Map_801A5E80();
        break;

    case 5:
        Map_801A2B8C();
        break;

    case 6:
        Map_801A4AE8();
        break;

    case 7:
        Map_801A36A8();
        break;

    default:
        break;
    }

    if ((D_menu_801CD944 == 0) || (D_menu_801CD944 == 1) || (D_menu_801CD944 == 7) || (D_menu_801CD944 == 3))
    {
        Map_801AD718(D_menu_801CDA00, D_menu_801CDA04, D_menu_801CDA08, &D_menu_801CD9F4, &D_menu_801CD9F8,
                     &D_menu_801CD9FC, D_menu_801CDA14, D_menu_801CDA0C + D_menu_801CDA18,
                     D_menu_801CDA10 + D_menu_801CDA1C);
        Camera_SetStarfieldPos(D_menu_801CD9F4, D_menu_801CD9F8, D_menu_801CD9FC, D_menu_801CDA00, D_menu_801CDA04,
                               D_menu_801CDA08);
    }
    gGameFrameCount++;

    Map_LevelSelect();
}