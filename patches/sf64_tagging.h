#ifndef SF64_TAGGING
#define SF64_TAGGING

/* For dynamic actors */
#define TAG_ADDRESS(ptr) ((u32) (ptr) & 0x0FFFFFFF)

/*
    X    XXX    XX     XX
    TYPE  ID  INDEX  CUSTOM
*/
#define TAG_OBJ(ptr) (((((ptr)->obj.id) << 16) & 0x0FFF0000) | ((((ptr)->index) << 8) & 0x0000FF00))

/* Actor Types */
#define TAG_ACTOR(actor) ((u32) (0x10000000 | (TAG_OBJ(actor))))
#define TAG_ACTOR_EVENT(actor) ((u32) (0x20000000 | (TAG_OBJ(actor))))
#define TAG_ACTOR_EVENT_COMMON(actor) ((u32) (0x90000000 | (TAG_OBJ(actor))))
#define TAG_BOSS(boss) ((u32) (0x30000000 | (TAG_OBJ(boss))))
#define TAG_SCENERY(scenery) ((u32) (0x40000000 | (TAG_OBJ(scenery))))
#define TAG_SCENERY_360(scenery360) ((u32) (0x50000000 | (TAG_ADDRESS(scenery360))))
#define TAG_EFFECT(effect) ((u32) (0x60000000 | (TAG_OBJ(effect))))
#define TAG_ITEM(item) ((u32) (0x70000000 | (TAG_OBJ(item))))

/* Skeletons */
#define TAG_LIMB_ADDRESS(ptr, data) ((((u32) (ptr) << 16) & 0xFFFF0000) | ((u32) (data) & 0x0000FFFF))
#define TAG_LIMB(limb, data) ((u32) (0x80000000 | (TAG_LIMB_ADDRESS(limb, data))))

/* Others */
#define TAG_ARWING_SKEL(arwing) (0xB0000000 | (((u32) (arwing) << 16) & 0x0FFF0000))
#define TAG_FACE (0x100)
#define TAG_CS_GREAT_FOX (0x200)
#define TAG_PLAYER_TRAIL (0x300)
#define TAG_TEAM_ARROW (0x400)
#define TAG_VEHICLE (0x500)
#define TAG_TEXTURED_LINE (0x600)
#define TAG_ (0x700)

/* Map */
#define TAG_PLANET_SHADOW (0xA0000000)
#define TAG_PLANET_ANIM (0xA0000020)
#define TAG_PLANET_METEOR (0xA0000040)
#define TAG_PLANET_EXPLOSIONS (0xA000006A)
#define TAG_TITANIA_RINGS (0xA0002010)
#define TAG_MEDAL (0xA0002012)
#define TAG_AREA6_SHIPS (0xA0002021)
#define TAG_ARWING (0xA0002022)
#define TAG_PATH_PLANET (0xA0002023)
#define TAG_VENOM_CLOUD_1 (0xA0002025)
#define TAG_VENOM_CLOUD_2 (0xA0002026)
#define TAG_PLANET_CLEARED_MARK (0xA000203F)
#define TAG_CORNERIA_EXPLOSION (0xA000204E)
#define TAG_SOLAR_RAYS (0xA0002050)
#define TAG_SOLAR_RAYS (0xA0002050)
#define TAG_PATH_PLANET_MEDAL (0xA0002060)
#define TAG_CURSOR (0xA0002070)
#define TAG_PEPPER_FACE (0xA0002071)
#define TAG_WARP (0xA0002080)

/* Ground */
#define TAG_GROUND (0xB0000000)
#define TAG_GROUND_CO_ON_RAILS (TAG_GROUND + 0x100)

#define ACTOR_TRANSFORM_LIMB_COUNT 256
#define ACTOR_TRANSFORM_ID_COUNT (ACTOR_TRANSFORM_LIMB_COUNT * 2) // One ID for each limb and another for each post-draw
#define ACTOR_TRANSFORM_ID_START 0x1000000U

// Use 16 bits of compiler-inserted padding to hold the scenery transform ID.
// offset 0x46 in Scenery360
#define scenery360IdByte0(scenery360) ((u8*) (scenery360))[0x46]
// offset 0x47 in Scenery360
#define scenery360IdByte1(scenery360) ((u8*) (scenery360))[0x47]

u32 create_scenery360_transform_id(void);

static inline u32 scenery360_transform_id(Scenery360* scenery360) {
    u32 scenery360_id = (scenery360IdByte0(scenery360) << 0) | (scenery360IdByte1(scenery360) << 8);

    return (scenery360_id * ACTOR_TRANSFORM_ID_COUNT) + ACTOR_TRANSFORM_ID_START;
}

void Animation_DrawLimbOriginal(s32 mode, Limb* limb, Limb** skeleton, Vec3f* jointTable,
                                OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* data);

void Animation_DrawSkeletonOriginal(s32 mode, Limb** skeletonSegment, Vec3f* jointTable,
                                    OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* data,
                                    Matrix* transform);

void Animation_DrawLimbArwing(s32 mode, Limb* limb, Limb** skeleton, Vec3f* jointTable,
                              OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* data);

void Animation_DrawSkeletonArwing(s32 mode, Limb** skeletonSegment, Vec3f* jointTable,
                                  OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* data,
                                  Matrix* transform);
#endif
