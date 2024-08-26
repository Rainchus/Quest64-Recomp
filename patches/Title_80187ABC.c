// Controller detection bypass
#define RECOMP_EXPORT __attribute__((section(".recomp_export")))
#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define RECOMP_FORCE_PATCH __attribute__((section(".recomp_force_patch")))

extern unsigned char gControllerPlugged[4];

RECOMP_PATCH int Title_80187ABC(void) {
    int ret = -1;
    int i;

    gControllerPlugged[0] = 1;

    for (i = 0; i < 4; i++) {
        if (gControllerPlugged[i] == 1) {
            ret = i;
            break;
        }
    }

    return ret;
}