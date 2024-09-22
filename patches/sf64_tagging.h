#ifndef SF64_TAGGING
#define SF64_TAGGING

/* For dynamic actors */
#define TAG_ADDRESS(ptr) ((u32) (ptr) & 0x0FFFFFFF)
#define TAG_ADDRESS_SKEL(ptr) ((u32) ((ptr) << 16) & 0x0FFF0000)

/* 
    X    XXX    XX     XX
    TYPE  ID  INDEX  CUSTOM
*/
#define TAG_OBJ(ptr) (((((ptr)->obj.id) << 16) & 0x0FFF0000) | ((((ptr)->index) << 8) & 0x0000FF00))

/* Actor Types */
#define TAG_ACTOR(actor) ((u32) (0x10000000 | (TAG_OBJ(actor))))
#define TAG_ACTOR_EVENT(actor) ((u32) (0x20000000 | (TAG_OBJ(actor))))
#define TAG_BOSS(boss) ((u32) (0x30000000 | (TAG_OBJ(boss))))
#define TAG_SCENERY(scenery) ((u32) (0x40000000 | (TAG_OBJ(scenery))))
#define TAG_SCENERY_360(scenery360) ((u32) (0x50000000 | (TAG_ADDRESS(scenery360))))
#define TAG_EFFECT(effect) ((u32) (0x60000000 | (TAG_OBJ(effect))))
#define TAG_ITEM(item) ((u32) (0x70000000 | (TAG_OBJ(item))))
#define TAG_LIMB(limb) ((u32) (0x80000000 | (TAG_ADDRESS(limb))))
#define TAG_ACTOR_SKEL(limb) ((u32) (0x90000000 | (TAG_OBJ(limb))))

/* Derivatives */
#define TAG_ACTOR_EVENT_COMMON(actor) (TAG_ACTOR_EVENT(actor) + 1)
#define TAG_FACE (0x100)
#define TAG_CS_GREAT_FOX (0x200)

/* Map */
#define TAG_PLANET_SHADOW (0x90000000)
#define TAG_PLANET_ANIM (TAG_PLANET_SHADOW + PLANET_MAX)
#define TAG_PLANET_ANIM_2 (TAG_PLANET_ANIM + PLANET_MAX)
#define TAG_PLANET_METEOR (TAG_PLANET_SHADOW + PLANET_MAX)
#define TAG_PLANET_EXPLOSIONS (TAG_PLANET_METEOR + 0x100)

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

#endif
