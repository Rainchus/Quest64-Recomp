#ifndef SF64_TAGGING
#define SF64_TAGGING

/* Actor Types */
#define TAG_ACTOR (0x10000)
#define TAG_ACTOR_EVENT (0x20000)
#define TAG_BOSS (0x30000)
#define TAG_EFFECT (0x40000)
#define TAG_ITEM (0x50000)

/* Derivatives */
#define TAG_ACTOR_EVENT_COMMON (TAG_ACTOR_EVENT + 0x10500)
#define TAG_FACE (0x100)

/* Map */
#define TAG_PLANET_SHADOW (0x200)
#define TAG_PLANET_ANIM (TAG_PLANET_SHADOW + PLANET_MAX)
#define TAG_PLANET_ANIM_2 (TAG_PLANET_ANIM + PLANET_MAX)
#define TAG_PLANET_METEOR (TAG_PLANET_SHADOW + PLANET_MAX)

#define ACTOR_TRANSFORM_LIMB_COUNT 256
#define ACTOR_TRANSFORM_ID_COUNT (ACTOR_TRANSFORM_LIMB_COUNT * 2) // One ID for each limb and another for each post-draw
#define ACTOR_TRANSFORM_ID_START 0x1000000U

// Use 16 bits of compiler-inserted padding to hold the scenery transform ID.
// offset 0x46 in Scenery360
#define scenery360IdByte0(scenery360) ((u8*)(scenery360))[0x46]
// offset 0x47 in Scenery360
#define scenery360IdByte1(scenery360) ((u8*)(scenery360))[0x47]

u32 create_scenery360_transform_id(void);

static inline u32 scenery360_transform_id(Scenery360* scenery360) {
    u32 scenery360_id = 
        (scenery360IdByte0(scenery360) <<  0) |
        (scenery360IdByte1(scenery360) <<  8);

    return (scenery360_id * ACTOR_TRANSFORM_ID_COUNT) + ACTOR_TRANSFORM_ID_START;
}

#endif
