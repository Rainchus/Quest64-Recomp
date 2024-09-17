#define RECOMP_PATCH __attribute__((section(".recomp_patch")))
#define __sinf __sinf_recomp
#define __cosf __cosf_recomp

#if 1

#include "patches.h"

extern s32 sPauseScreenIwork[10];

typedef struct {
    s32 unk_0;
    s32 unk_4;
} StickInput;

RECOMP_PATCH bool Option_Input_MoveCursor_Y(s32* arg0, s32 arg1, bool arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                                            s32 arg7, StickInput* stick) {
    s32 axis;
    s32 x;
    s32 y;
    s32 temp;
    bool ret = false;

    if (arg1 == 0) {
        return ret;
    }

    temp = *arg0;

    x = gControllerPress[arg7].stick_x;
    y = -gControllerPress[arg7].stick_y;

    if (arg2 == true) {
        axis = y;
        if ((x > 40) || (x < -40)) {
            return ret;
        }
    } else {
        axis = x;
        if ((y > 40) || (y < -40)) {
            return ret;
        }
    }

    if ((axis < arg4) && (axis > -arg4)) {
        axis = 0;
    }

    if (!(stick->unk_4)) {
        if (axis != 0) {
            if (axis > 0) {
                (*arg0)++;
                if (*arg0 > arg1) {
                    if (arg3 == 0) {
                        *arg0 = 0;
                    } else {
                        *arg0 = arg1;
                    }
                }
            }

            if (axis < 0) {
                (*arg0)--;
                if (*arg0 < 0) {
                    if (arg3 == 0) {
                        *arg0 = arg1;
                    } else {
                        *arg0 = 0;
                    }
                }
            }

            stick->unk_4 = arg5 + stick->unk_0;
            if (stick->unk_0 > 0) {
                stick->unk_0 -= arg6;
            }
        } else {
            stick->unk_4 = 0;
            stick->unk_0 = arg6;
        }
    }

    if (((gControllerPress[0].button & D_JPAD) || (gControllerPress[0].button & U_JPAD)) && (arg2 == true)) {
        if (gControllerPress[0].button & D_JPAD) {
            (*arg0)++;
            if (*arg0 > arg1) {
                if (arg3 == 0) {
                    *arg0 = 0;
                } else {
                    *arg0 = arg1;
                }
            }
        }

        if (gControllerPress[0].button & U_JPAD) {
            (*arg0)--;
            if (*arg0 < 0) {
                if (arg3 == 0) {
                    *arg0 = arg1;
                } else {
                    *arg0 = 0;
                }
            }
        }

        stick->unk_4 = arg5 + stick->unk_0;
        if (stick->unk_0 > 0) {
            stick->unk_0 -= arg6;
        }
    } else if (((gControllerPress[0].button & L_JPAD) || (gControllerPress[0].button & R_JPAD)) && (arg2 == false)) {
        if (gControllerPress[0].button & L_JPAD) {
            (*arg0)++;
            if (*arg0 > arg1) {
                if (arg3 == 0) {
                    *arg0 = 0;
                } else {
                    *arg0 = arg1;
                }
            }
        }

        if (gControllerPress[0].button & R_JPAD) {
            (*arg0)--;
            if (*arg0 < 0) {
                if (arg3 == 0) {
                    *arg0 = arg1;
                } else {
                    *arg0 = 0;
                }
            }
        }

        stick->unk_4 = arg5 + stick->unk_0;
        if (stick->unk_0 > 0) {
            stick->unk_0 -= arg6;
        }
    }

    if (stick->unk_4 > 0) {
        stick->unk_4--;
    }

    if (temp != *arg0) {
        ret = true;
    }

    return ret;
}

RECOMP_PATCH s32 HUD_PauseScreenInput(void) {
    s32 var_v1 = 0;
    f32 y = gInputPress->stick_y;

    if ((y != 0.0f) && (sPauseScreenIwork[4] != 0)) {
        return 0;
    }

    sPauseScreenIwork[4] = 0;

    if (fabsf(y) < 30.0f) {
        y = 0.0f;
    }

    if (y != 0.0f) {
        if (sPauseScreenIwork[2] == 0) {
            if (y > 0) {
                var_v1 = 1;
            } else {
                var_v1 = -1;
            }
            sPauseScreenIwork[2] = 1;
        } else {
            sPauseScreenIwork[2] = 0;
        }
    } else {
        if ((gControllerPress[0].button & D_JPAD) || (gControllerPress[0].button & U_JPAD)) {
            if (sPauseScreenIwork[2] == 0) {
                if (gControllerPress[0].button & U_JPAD) {
                    var_v1 = 1;
                } else {
                    var_v1 = -1;
                }
                sPauseScreenIwork[2] = 1;
            }
        } else {
            sPauseScreenIwork[2] = 0;
        }
    }
    return var_v1;
}

RECOMP_PATCH bool Option_Input_Sound_X(f32* arg0, f32 arg1, f32 arg2, StickInput* arg3) {
    f32 var_fv1;
    f32 temp2;
    bool var_a2 = false;
    f32 temp = *arg0;
    s32 stickX = +gControllerPress[gMainController].stick_x;
    s32 stickY = -gControllerPress[gMainController].stick_y;
    static int holdTimer = 0;

    if (gControllerHold[gMainController].button & (L_JPAD | R_JPAD)) {
        holdTimer++;
    } else {
        holdTimer = 0;
    }

    if ((stickY > 10) || (stickY < -10)) {
        return 0;
    }

    if ((stickX < 10) && (stickX > -10)) {
        stickX = 0;
    } else if (stickX < 0) {
        stickX += 10;
    } else {
        stickX -= 10;
    }

    if (arg3->unk_4 == 0) {
        if (stickX != 0) {
            var_fv1 = stickX / 20.0f;
            arg3->unk_4 = arg3->unk_0;

            if (arg3->unk_0 != 0) {
                arg3->unk_0 -= 7;
            }

            if (arg3->unk_4 != 0) {
                if (stickX > 0) {
                    var_fv1 = 1.0f;
                } else {
                    var_fv1 = -1.0f;
                }
            }

            *arg0 += var_fv1;

            if (arg2 < *arg0) {
                *arg0 = arg2;
            }
            if (*arg0 < arg1) {
                *arg0 = arg1;
            }
        } else {
            arg3->unk_4 = 0;
            arg3->unk_0 = 7;
        }
    }

    if (gControllerPress[gMainController].button & R_JPAD) {
        stickX += 10;
    } else if (gControllerPress[gMainController].button & L_JPAD) {
        stickX -= 10;
    }

    if (holdTimer > 15) {
        if (gControllerHold[gMainController].button & L_JPAD) {
            var_fv1 = -1.0f;
        } else if (gControllerHold[gMainController].button & R_JPAD) {
            var_fv1 = 1.0f;
        }
        *arg0 += var_fv1;

        if (arg2 < *arg0) {
            *arg0 = arg2;
        }
        if (*arg0 < arg1) {
            *arg0 = arg1;
        }
    }

    if (gControllerPress[gMainController].button & L_JPAD) {
        var_fv1 = -1.0f;
        *arg0 += var_fv1;
        if (arg2 < *arg0) {
            *arg0 = arg2;
        }
        if (*arg0 < arg1) {
            *arg0 = arg1;
        }
    } else if (gControllerPress[gMainController].button & R_JPAD) {
        var_fv1 = 1.0f;
        *arg0 += var_fv1;
        if (arg2 < *arg0) {
            *arg0 = arg2;
        }
        if (*arg0 < arg1) {
            *arg0 = arg1;
        }
    }

    if (arg3->unk_4 > 0) {
        arg3->unk_4--;
    }

    temp2 = *arg0;

    if ((s32) temp2 != (s32) temp) {
        AUDIO_PLAY_SFX(NA_SE_COUNT_UP, gDefaultSfxSource, 4);
        var_a2 = true;
    }

    return var_a2;
}

#endif
