#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80049A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049A68: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80049A6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049A70: ldc1        $f6, 0x23C0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X23C0);
    // 0x80049A74: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80049A78: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80049A7C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80049A80: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80049A84: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80049A88: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80049A8C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80049A90: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80049A94: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80049A98: bgezl       $a2, L_80049AB4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80049A9C: div.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
            goto L_80049AB4;
    }
    goto skip_0;
    // 0x80049A9C: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    skip_0:
    // 0x80049AA0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80049AA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80049AA8: nop

    // 0x80049AAC: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x80049AB0: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
L_80049AB4:
    // 0x80049AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049AB8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80049ABC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80049AC0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80049AC4: nop

    // 0x80049AC8: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80049ACC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80049AD0: nop

    // 0x80049AD4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80049AD8: beql        $v0, $zero, L_80049B34
    if (ctx->r2 == 0) {
        // 0x80049ADC: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80049B34;
    }
    goto skip_1;
    // 0x80049ADC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80049AE0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80049AE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80049AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049AEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80049AF0: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x80049AF4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80049AF8: nop

    // 0x80049AFC: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80049B00: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80049B04: nop

    // 0x80049B08: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80049B0C: bnel        $v0, $zero, L_80049B28
    if (ctx->r2 != 0) {
        // 0x80049B10: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80049B28;
    }
    goto skip_2;
    // 0x80049B10: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x80049B14: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80049B18: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80049B1C: jr          $ra
    // 0x80049B20: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x80049B20: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80049B24: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_80049B28:
    // 0x80049B28: jr          $ra
    // 0x80049B2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80049B2C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80049B30: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80049B34:
    // 0x80049B34: nop

    // 0x80049B38: bltzl       $v0, L_80049B28
    if (SIGNED(ctx->r2) < 0) {
        // 0x80049B3C: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80049B28;
    }
    goto skip_3;
    // 0x80049B3C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_3:
    // 0x80049B40: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80049B44: jr          $ra
    // 0x80049B48: nop

    return;
    // 0x80049B48: nop

;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035680: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80035684: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80035688: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8003568C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80035690: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80035694: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80035698: beq         $at, $zero, L_80035700
    if (ctx->r1 == 0) {
        // 0x8003569C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80035700;
    }
    // 0x8003569C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800356A0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800356A4: bne         $at, $zero, L_800356F8
    if (ctx->r1 != 0) {
        // 0x800356A8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800356F8;
    }
    // 0x800356A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800356AC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800356B0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800356B4: addiu       $v1, $v1, 0x1B40
    ctx->r3 = ADD32(ctx->r3, 0X1B40);
    // 0x800356B8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800356BC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800356C0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800356C4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800356C8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800356CC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800356D0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800356D4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800356D8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800356DC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800356E0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800356E4: nop

    // 0x800356E8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800356EC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800356F0: jr          $ra
    // 0x800356F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800356F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800356F8:
    // 0x800356F8: jr          $ra
    // 0x800356FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800356FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_80035700:
    // 0x80035700: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x80035704: beq         $at, $zero, L_80035818
    if (ctx->r1 == 0) {
        // 0x80035708: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80035818;
    }
    // 0x80035708: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8003570C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80035710: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035714: ldc1        $f10, 0x1B68($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1B68);
    // 0x80035718: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8003571C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80035720: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80035724: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035728: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003572C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80035730: nop

    // 0x80035734: bc1fl       L_80035764
    if (!c1cs) {
        // 0x80035738: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80035764;
    }
    goto skip_0;
    // 0x80035738: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8003573C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80035740: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80035744: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80035748: nop

    // 0x8003574C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80035750: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80035754: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80035758: b           L_80035780
    // 0x8003575C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80035780;
    // 0x8003575C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80035760: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80035764:
    // 0x80035764: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80035768: nop

    // 0x8003576C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80035770: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80035774: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80035778: nop

    // 0x8003577C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80035780:
    // 0x80035780: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035784: ldc1        $f18, 0x1B70($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1B70);
    // 0x80035788: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x8003578C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035790: ldc1        $f6, 0x1B78($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1B78);
    // 0x80035794: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x80035798: addiu       $v1, $v1, 0x1B40
    ctx->r3 = ADD32(ctx->r3, 0X1B40);
    // 0x8003579C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800357A0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800357A4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800357A8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800357AC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800357B0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800357B4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800357B8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800357BC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800357C0: nop

    // 0x800357C4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800357C8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800357CC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800357D0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800357D4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800357D8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800357DC: bne         $t9, $zero, L_800357FC
    if (ctx->r25 != 0) {
        // 0x800357E0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800357FC;
    }
    // 0x800357E0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800357E4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800357E8: nop

    // 0x800357EC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800357F0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800357F4: jr          $ra
    // 0x800357F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800357F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800357FC:
    // 0x800357FC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80035800: nop

    // 0x80035804: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80035808: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8003580C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80035810: jr          $ra
    // 0x80035814: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80035814: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80035818:
    // 0x80035818: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x8003581C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035820: bc1t        L_80035834
    if (c1cs) {
        // 0x80035824: nop
    
            goto L_80035834;
    }
    // 0x80035824: nop

    // 0x80035828: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003582C: jr          $ra
    // 0x80035830: lwc1        $f0, 0x1F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1F10);
    return;
    // 0x80035830: lwc1        $f0, 0x1F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1F10);
L_80035834:
    // 0x80035834: lwc1        $f0, 0x1B80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1B80);
    // 0x80035838: jr          $ra
    // 0x8003583C: nop

    return;
    // 0x8003583C: nop

;}
RECOMP_FUNC void func_800258F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800258F8: bltz        $a0, L_80025920
    if (SIGNED(ctx->r4) < 0) {
        // 0x800258FC: slti        $at, $a0, 0x47
        ctx->r1 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
            goto L_80025920;
    }
    // 0x800258FC: slti        $at, $a0, 0x47
    ctx->r1 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // 0x80025900: beq         $at, $zero, L_80025920
    if (ctx->r1 == 0) {
        // 0x80025904: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80025920;
    }
    // 0x80025904: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80025908: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002590C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80025910: lw          $t7, 0x39E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X39E4);
    // 0x80025914: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80025918: jr          $ra
    // 0x8002591C: sw          $t7, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->r15;
    return;
    // 0x8002591C: sw          $t7, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->r15;
L_80025920:
    // 0x80025920: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80025924: lw          $t8, 0x39E4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39E4);
    // 0x80025928: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002592C: sw          $t8, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->r24;
    // 0x80025930: jr          $ra
    // 0x80025934: nop

    return;
    // 0x80025934: nop

;}
RECOMP_FUNC void func_80031300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031300: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80031304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003130C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80031310: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80031314: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031318: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8003131C: sh          $zero, 0x2878($at)
    MEM_H(0X2878, ctx->r1) = 0;
    // 0x80031320: addiu       $a0, $a0, 0x2A88
    ctx->r4 = ADD32(ctx->r4, 0X2A88);
    // 0x80031324: addiu       $v0, $v0, 0x2A38
    ctx->r2 = ADD32(ctx->r2, 0X2A38);
    // 0x80031328: addiu       $v1, $zero, -0x80
    ctx->r3 = ADD32(0, -0X80);
L_8003132C:
    // 0x8003132C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80031330: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80031334: bne         $at, $zero, L_8003132C
    if (ctx->r1 != 0) {
        // 0x80031338: sb          $v1, -0x2($v0)
        MEM_B(-0X2, ctx->r2) = ctx->r3;
            goto L_8003132C;
    }
    // 0x80031338: sb          $v1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r3;
    // 0x8003133C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80031340: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80031344: addiu       $v1, $v1, 0x2AC0
    ctx->r3 = ADD32(ctx->r3, 0X2AC0);
    // 0x80031348: addiu       $v0, $v0, 0x2AA8
    ctx->r2 = ADD32(ctx->r2, 0X2AA8);
L_8003134C:
    // 0x8003134C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80031350: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80031354: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80031358: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8003135C: bne         $at, $zero, L_8003134C
    if (ctx->r1 != 0) {
        // 0x80031360: sb          $zero, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = 0;
            goto L_8003134C;
    }
    // 0x80031360: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x80031364: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80031368: addiu       $s0, $s0, 0x2AA0
    ctx->r16 = ADD32(ctx->r16, 0X2AA0);
    // 0x8003136C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031370: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    // 0x80031374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80031378: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003137C: jal         0x80033F10
    // 0x80031380: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80031380: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_0:
    // 0x80031384: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80031388: addiu       $a1, $a1, 0x2880
    ctx->r5 = ADD32(ctx->r5, 0X2880);
    // 0x8003138C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80031390: jal         0x80033FB0
    // 0x80031394: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80031394: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80031398: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8003139C: addiu       $s0, $s0, 0x2A90
    ctx->r16 = ADD32(ctx->r16, 0X2A90);
    // 0x800313A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800313A4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800313A8: addiu       $a1, $a1, 0x2A88
    ctx->r5 = ADD32(ctx->r5, 0X2A88);
    // 0x800313AC: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    // 0x800313B0: jal         0x8003A7E0
    // 0x800313B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800313B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800313B8: jal         0x8003ABA0
    // 0x800313BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    osContSetCh_recomp(rdram, ctx);
        goto after_3;
    // 0x800313BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x800313C0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800313C4: addiu       $a1, $a1, 0x2870
    ctx->r5 = ADD32(ctx->r5, 0X2870);
    // 0x800313C8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800313CC: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    // 0x800313D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800313D4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800313D8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800313DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800313E0: lbu         $t0, 0x2A88($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X2A88);
    // 0x800313E4: addiu       $v0, $v0, 0x2A38
    ctx->r2 = ADD32(ctx->r2, 0X2A38);
    // 0x800313E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800313EC: addiu       $t3, $zero, -0x3
    ctx->r11 = ADD32(0, -0X3);
    // 0x800313F0: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x800313F4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800313F8:
    // 0x800313F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800313FC: sllv        $t7, $t6, $a0
    ctx->r15 = S32(ctx->r14 << (ctx->r4 & 31));
    // 0x80031400: and         $t8, $t0, $t7
    ctx->r24 = ctx->r8 & ctx->r15;
    // 0x80031404: beq         $t8, $zero, L_80031490
    if (ctx->r24 == 0) {
        // 0x80031408: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80031490;
    }
    // 0x80031408: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8003140C: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x80031410: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x80031414: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x80031418: beql        $t6, $zero, L_8003142C
    if (ctx->r14 == 0) {
        // 0x8003141C: lhu         $t7, 0x0($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X0);
            goto L_8003142C;
    }
    goto skip_0;
    // 0x8003141C: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    skip_0:
    // 0x80031420: b           L_80031494
    // 0x80031424: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
        goto L_80031494;
    // 0x80031424: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // 0x80031428: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
L_8003142C:
    // 0x8003142C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80031430: beql        $t8, $zero, L_80031444
    if (ctx->r24 == 0) {
        // 0x80031434: lb          $t9, 0x0($a1)
        ctx->r25 = MEM_B(ctx->r5, 0X0);
            goto L_80031444;
    }
    goto skip_1;
    // 0x80031434: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    skip_1:
    // 0x80031438: b           L_80031494
    // 0x8003143C: sb          $t2, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r10;
        goto L_80031494;
    // 0x8003143C: sb          $t2, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r10;
    // 0x80031440: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
L_80031444:
    // 0x80031444: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80031448: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003144C: bnel        $a3, $t9, L_8003145C
    if (ctx->r7 != ctx->r25) {
        // 0x80031450: lbu         $t5, 0x2($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X2);
            goto L_8003145C;
    }
    goto skip_2;
    // 0x80031450: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    skip_2:
    // 0x80031454: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x80031458: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
L_8003145C:
    // 0x8003145C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80031460: beql        $t6, $zero, L_8003147C
    if (ctx->r14 == 0) {
        // 0x80031464: lb          $t9, 0x0($a1)
        ctx->r25 = MEM_B(ctx->r5, 0X0);
            goto L_8003147C;
    }
    goto skip_3;
    // 0x80031464: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    skip_3:
    // 0x80031468: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8003146C: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x80031470: b           L_80031494
    // 0x80031474: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
        goto L_80031494;
    // 0x80031474: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80031478: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
L_8003147C:
    // 0x8003147C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80031480: bnel        $a0, $t9, L_80031498
    if (ctx->r4 != ctx->r25) {
        // 0x80031484: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80031498;
    }
    goto skip_4;
    // 0x80031484: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x80031488: b           L_80031494
    // 0x8003148C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_80031494;
    // 0x8003148C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80031490:
    // 0x80031490: sb          $t3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r11;
L_80031494:
    // 0x80031494: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80031498:
    // 0x80031498: bne         $a0, $t1, L_800313F8
    if (ctx->r4 != ctx->r9) {
        // 0x8003149C: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800313F8;
    }
    // 0x8003149C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800314A0: bne         $a2, $zero, L_800314B0
    if (ctx->r6 != 0) {
        // 0x800314A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800314B0;
    }
    // 0x800314A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800314A8: b           L_800314B4
    // 0x800314AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800314B4;
    // 0x800314AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800314B0:
    // 0x800314B0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800314B4:
    // 0x800314B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800314B8: jr          $ra
    // 0x800314BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800314BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void nnScExecuteGraphics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80000A84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80000A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80000A8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000A90: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80000A94: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80000A98: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80000A9C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80000AA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80000AA4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80000AA8: addiu       $s5, $s0, 0x3C
    ctx->r21 = ADD32(ctx->r16, 0X3C);
    // 0x80000AAC: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x80000AB0: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
    // 0x80000AB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000AB8:
    // 0x80000AB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000ABC: jal         0x80034020
    // 0x80000AC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80000AC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000AC8: jal         0x80000BB4
    // 0x80000ACC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    nnScWaitTaskReady(rdram, ctx);
        goto after_1;
    // 0x80000ACC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80000AD0: lw          $t6, 0x670($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X670);
    // 0x80000AD4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80000AD8: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x80000ADC: beq         $t6, $zero, L_80000AF4
    if (ctx->r14 == 0) {
        // 0x80000AE0: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80000AF4;
    }
    // 0x80000AE0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000AE4: sw          $t7, 0x674($s0)
    MEM_W(0X674, ctx->r16) = ctx->r15;
    // 0x80000AE8: jal         0x80034020
    // 0x80000AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80000AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000AF0: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
L_80000AF4:
    // 0x80000AF4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80000AF8: addiu       $s1, $s0, 0xAC
    ctx->r17 = ADD32(ctx->r16, 0XAC);
    // 0x80000AFC: addiu       $s2, $s0, 0xE4
    ctx->r18 = ADD32(ctx->r16, 0XE4);
    // 0x80000B00: sw          $t8, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = ctx->r24;
    // 0x80000B04: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80000B08: jal         0x8003452C
    // 0x80000B0C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_3;
    // 0x80000B0C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x80000B10: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80000B14: jal         0x80034694
    // 0x80000B18: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_4;
    // 0x80000B18: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x80000B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000B20: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000B24: jal         0x80034020
    // 0x80000B28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80000B28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80000B2C: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    // 0x80000B30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80000B34: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000B38: jal         0x80034020
    // 0x80000B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80000B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80000B40: lw          $t9, 0x678($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X678);
    // 0x80000B44: beql        $t9, $zero, L_80000B5C
    if (ctx->r25 == 0) {
        // 0x80000B48: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_80000B5C;
    }
    goto skip_0;
    // 0x80000B48: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80000B4C: jal         0x800346E0
    // 0x80000B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_7;
    // 0x80000B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80000B54: sw          $zero, 0x678($s0)
    MEM_W(0X678, ctx->r16) = 0;
    // 0x80000B58: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_80000B5C:
    // 0x80000B5C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80000B60: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x80000B64: beql        $t2, $zero, L_80000B78
    if (ctx->r10 == 0) {
        // 0x80000B68: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80000B78;
    }
    goto skip_1;
    // 0x80000B68: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x80000B6C: jal         0x80034750
    // 0x80000B70: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_8;
    // 0x80000B70: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    after_8:
    // 0x80000B74: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80000B78:
    // 0x80000B78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80000B7C: lw          $a0, 0x50($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X50);
    // 0x80000B80: jal         0x80034200
    // 0x80000B84: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80000B84: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    after_9:
    // 0x80000B88: b           L_80000AB8
    // 0x80000B8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000AB8;
    // 0x80000B8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80000B90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000B94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80000B98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80000B9C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80000BA0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80000BA4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80000BA8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80000BAC: jr          $ra
    // 0x80000BB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80000BB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void nnScRemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000082C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80000830: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80000834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000838: lw          $v1, 0x668($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X668);
    // 0x8000083C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80000840: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80000844: jal         0x80034160
    // 0x80000848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80000848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000084C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80000850: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80000854: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80000858: beq         $v1, $zero, L_80000898
    if (ctx->r3 == 0) {
        // 0x8000085C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80000898;
    }
    // 0x8000085C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80000860:
    // 0x80000860: bnel        $v1, $a1, L_8000088C
    if (ctx->r3 != ctx->r5) {
        // 0x80000864: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8000088C;
    }
    goto skip_0;
    // 0x80000864: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    skip_0:
    // 0x80000868: beq         $a2, $zero, L_8000087C
    if (ctx->r6 == 0) {
        // 0x8000086C: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_8000087C;
    }
    // 0x8000086C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80000870: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80000874: b           L_80000898
    // 0x80000878: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_80000898;
    // 0x80000878: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_8000087C:
    // 0x8000087C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80000880: b           L_80000898
    // 0x80000884: sw          $t8, 0x668($t9)
    MEM_W(0X668, ctx->r25) = ctx->r24;
        goto L_80000898;
    // 0x80000884: sw          $t8, 0x668($t9)
    MEM_W(0X668, ctx->r25) = ctx->r24;
    // 0x80000888: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8000088C:
    // 0x8000088C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80000890: bne         $v1, $zero, L_80000860
    if (ctx->r3 != 0) {
        // 0x80000894: nop
    
            goto L_80000860;
    }
    // 0x80000894: nop

L_80000898:
    // 0x80000898: jal         0x80034160
    // 0x8000089C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8000089C: nop

    after_1:
    // 0x800008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800008A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800008A8: jr          $ra
    // 0x800008AC: nop

    return;
    // 0x800008AC: nop

;}
RECOMP_FUNC void func_801033B8_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801033B8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x801033BC: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x801033C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801033C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801033C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801033CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801033D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801033D4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801033D8: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x801033DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801033E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801033E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801033E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801033EC: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x801033F0: lui         $t2, 0xFFFC
    ctx->r10 = S32(0XFFFC << 16);
    // 0x801033F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801033F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801033FC: ori         $t2, $t2, 0xFA7D
    ctx->r10 = ctx->r10 | 0XFA7D;
    // 0x80103400: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80103404: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80103408: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8010340C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103410: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x80103414: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x80103418: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8010341C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80103420: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x80103424: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x80103428: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8010342C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80103430: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103434: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80103438: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8010343C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103440: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103444: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x80103448: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010344C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80103450: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80103454: jal         0x80103DB8
    // 0x80103458: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_80103DB8_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x80103458: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x8010345C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80103460: addiu       $v1, $v1, 0x6200
    ctx->r3 = ADD32(ctx->r3, 0X6200);
    // 0x80103464: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80103468: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8010346C: addiu       $a1, $a1, 0x6224
    ctx->r5 = ADD32(ctx->r5, 0X6224);
    // 0x80103470: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80103474: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80103478: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8010347C: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x80103480: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80103484: beq         $a0, $zero, L_801034A8
    if (ctx->r4 == 0) {
        // 0x80103488: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801034A8;
    }
    // 0x80103488: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010348C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80103490: beq         $v0, $at, L_801034D8
    if (ctx->r2 == ctx->r1) {
        // 0x80103494: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801034D8;
    }
    // 0x80103494: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80103498: beql        $v0, $at, L_801034FC
    if (ctx->r2 == ctx->r1) {
        // 0x8010349C: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_801034FC;
    }
    goto skip_0;
    // 0x8010349C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x801034A0: b           L_80103518
    // 0x801034A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103518;
    // 0x801034A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801034A8:
    // 0x801034A8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801034AC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801034B0: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x801034B4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x801034B8: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x801034BC: bne         $at, $zero, L_80103514
    if (ctx->r1 != 0) {
        // 0x801034C0: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_80103514;
    }
    // 0x801034C0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x801034C4: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x801034C8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801034CC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801034D0: b           L_80103514
    // 0x801034D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80103514;
    // 0x801034D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801034D8:
    // 0x801034D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801034DC: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x801034E0: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x801034E4: bnel        $t9, $zero, L_80103518
    if (ctx->r25 != 0) {
        // 0x801034E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103518;
    }
    goto skip_1;
    // 0x801034E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801034EC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x801034F0: b           L_80103514
    // 0x801034F4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_80103514;
    // 0x801034F4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801034F8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_801034FC:
    // 0x801034FC: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x80103500: bgez        $t4, L_80103514
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80103504: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_80103514;
    }
    // 0x80103504: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103508: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8010350C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80103510: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80103514:
    // 0x80103514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103518:
    // 0x80103518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010351C: jr          $ra
    // 0x80103520: nop

    return;
    // 0x80103520: nop

;}
RECOMP_FUNC void func_8001B0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B0D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001B0D4: addiu       $v0, $v0, -0x7BD8
    ctx->r2 = ADD32(ctx->r2, -0X7BD8);
    // 0x8001B0D8: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
L_8001B0DC:
    // 0x8001B0DC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001B0E0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8001B0E4: sh          $zero, 0x40($v0)
    MEM_H(0X40, ctx->r2) = 0;
    // 0x8001B0E8: sh          $zero, 0x80($v0)
    MEM_H(0X80, ctx->r2) = 0;
    // 0x8001B0EC: sh          $zero, 0xC0($v0)
    MEM_H(0XC0, ctx->r2) = 0;
    // 0x8001B0F0: bne         $v1, $zero, L_8001B0DC
    if (ctx->r3 != 0) {
        // 0x8001B0F4: addiu       $v0, $v0, 0x100
        ctx->r2 = ADD32(ctx->r2, 0X100);
            goto L_8001B0DC;
    }
    // 0x8001B0F4: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x8001B0F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B0FC: sw          $zero, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = 0;
    // 0x8001B100: jr          $ra
    // 0x8001B104: nop

    return;
    // 0x8001B104: nop

;}
RECOMP_FUNC void func_80102074_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102074: addiu       $sp, $sp, -0x648
    ctx->r29 = ADD32(ctx->r29, -0X648);
    // 0x80102078: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8010207C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80102080: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80102084: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80102088: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010208C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80102090: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80102094: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80102098: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010209C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801020A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801020A4: sw          $a0, 0x648($sp)
    MEM_W(0X648, ctx->r29) = ctx->r4;
    // 0x801020A8: addiu       $v1, $v1, 0x6250
    ctx->r3 = ADD32(ctx->r3, 0X6250);
    // 0x801020AC: addiu       $v0, $sp, 0x138
    ctx->r2 = ADD32(ctx->r29, 0X138);
    // 0x801020B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_801020B4:
    // 0x801020B4: sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
    // 0x801020B8: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x801020BC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x801020C0: slti        $at, $a3, 0x96
    ctx->r1 = SIGNED(ctx->r7) < 0X96 ? 1 : 0;
    // 0x801020C4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801020C8: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x801020CC: bne         $at, $zero, L_801020B4
    if (ctx->r1 != 0) {
        // 0x801020D0: sw          $t6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->r14;
            goto L_801020B4;
    }
    // 0x801020D0: sw          $t6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r14;
    // 0x801020D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801020D8: addiu       $t0, $zero, 0x95
    ctx->r8 = ADD32(0, 0X95);
    // 0x801020DC: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x801020E0: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
L_801020E4:
    // 0x801020E4: blez        $a2, L_80102138
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801020E8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80102138;
    }
    // 0x801020E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801020EC: addiu       $v0, $sp, 0x138
    ctx->r2 = ADD32(ctx->r29, 0X138);
L_801020F0:
    // 0x801020F0: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x801020F4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801020F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801020FC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80102100: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x80102104: beq         $at, $zero, L_80102130
    if (ctx->r1 == 0) {
        // 0x80102108: nop
    
            goto L_80102130;
    }
    // 0x80102108: nop

    // 0x8010210C: lw          $at, 0x0($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X0);
    // 0x80102110: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80102114: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80102118: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x8010211C: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80102120: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80102124: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102128: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8010212C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80102130:
    // 0x80102130: bne         $a0, $a2, L_801020F0
    if (ctx->r4 != ctx->r6) {
        // 0x80102134: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801020F0;
    }
    // 0x80102134: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80102138:
    // 0x80102138: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8010213C: slti        $at, $a3, 0x95
    ctx->r1 = SIGNED(ctx->r7) < 0X95 ? 1 : 0;
    // 0x80102140: bnel        $at, $zero, L_801020E4
    if (ctx->r1 != 0) {
        // 0x80102144: subu        $a2, $t0, $a3
        ctx->r6 = SUB32(ctx->r8, ctx->r7);
            goto L_801020E4;
    }
    goto skip_0;
    // 0x80102144: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
    skip_0:
    // 0x80102148: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8010214C: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x80102150: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102154: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x80102158: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x8010215C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102160: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102164: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102168: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8010216C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102170: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x80102174: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x80102178: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010217C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102180: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x80102184: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102188: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8010218C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102190: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80102194: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x80102198: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8010219C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801021A0: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x801021A4: addiu       $t8, $sp, 0x138
    ctx->r24 = ADD32(ctx->r29, 0X138);
    // 0x801021A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801021AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801021B0: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x801021B4: lui         $fp, 0xE600
    ctx->r30 = S32(0XE600 << 16);
    // 0x801021B8: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
L_801021BC:
    // 0x801021BC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x801021C0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x801021C4: addiu       $t4, $t4, 0x6250
    ctx->r12 = ADD32(ctx->r12, 0X6250);
    // 0x801021C8: lhu         $s3, 0x4($t9)
    ctx->r19 = MEM_HU(ctx->r25, 0X4);
    // 0x801021CC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x801021D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801021D4: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x801021D8: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x801021DC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x801021E0: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x801021E4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801021E8: lw          $t6, 0x648($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X648);
    // 0x801021EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801021F0: sll         $t5, $v1, 0
    ctx->r13 = S32(ctx->r3 << 0);
    // 0x801021F4: bgezl       $t5, L_80103098
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801021F8: lw          $t3, 0x5C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X5C);
            goto L_80103098;
    }
    goto skip_1;
    // 0x801021F8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x801021FC: bne         $t6, $at, L_80102218
    if (ctx->r14 != ctx->r1) {
        // 0x80102200: lw          $t8, 0x648($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X648);
            goto L_80102218;
    }
    // 0x80102200: lw          $t8, 0x648($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X648);
    // 0x80102204: sll         $t7, $v1, 8
    ctx->r15 = S32(ctx->r3 << 8);
    // 0x80102208: bltzl       $t7, L_80102228
    if (SIGNED(ctx->r15) < 0) {
        // 0x8010220C: andi        $t3, $v1, 0x800
        ctx->r11 = ctx->r3 & 0X800;
            goto L_80102228;
    }
    goto skip_2;
    // 0x8010220C: andi        $t3, $v1, 0x800
    ctx->r11 = ctx->r3 & 0X800;
    skip_2:
    // 0x80102210: b           L_80103098
    // 0x80102214: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
        goto L_80103098;
    // 0x80102214: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
L_80102218:
    // 0x80102218: bne         $t8, $zero, L_80102224
    if (ctx->r24 != 0) {
        // 0x8010221C: sll         $t9, $v1, 8
        ctx->r25 = S32(ctx->r3 << 8);
            goto L_80102224;
    }
    // 0x8010221C: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x80102220: bltz        $t9, L_80103094
    if (SIGNED(ctx->r25) < 0) {
        // 0x80102224: andi        $t3, $v1, 0x800
        ctx->r11 = ctx->r3 & 0X800;
            goto L_80103094;
    }
L_80102224:
    // 0x80102224: andi        $t3, $v1, 0x800
    ctx->r11 = ctx->r3 & 0X800;
L_80102228:
    // 0x80102228: beq         $t3, $zero, L_8010224C
    if (ctx->r11 == 0) {
        // 0x8010222C: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8010224C;
    }
    // 0x8010222C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80102230: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80102234: jal         0x80101A5C
    // 0x80102238: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    func_80101A5C_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x80102238: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_0:
    // 0x8010223C: beq         $v0, $zero, L_8010224C
    if (ctx->r2 == 0) {
        // 0x80102240: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8010224C;
    }
    // 0x80102240: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80102244: and         $t4, $s1, $at
    ctx->r12 = ctx->r17 & ctx->r1;
    // 0x80102248: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_8010224C:
    // 0x8010224C: andi        $t5, $s1, 0x4000
    ctx->r13 = ctx->r17 & 0X4000;
    // 0x80102250: beq         $t5, $zero, L_80102270
    if (ctx->r13 == 0) {
        // 0x80102254: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80102270;
    }
    // 0x80102254: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80102258: jal         0x80101D0C
    // 0x8010225C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80101D0C_ovl_intro(rdram, ctx);
        goto after_1;
    // 0x8010225C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80102260: beq         $v0, $zero, L_80102270
    if (ctx->r2 == 0) {
        // 0x80102264: addiu       $at, $zero, -0x4001
        ctx->r1 = ADD32(0, -0X4001);
            goto L_80102270;
    }
    // 0x80102264: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80102268: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x8010226C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80102270:
    // 0x80102270: andi        $t7, $s1, 0x8000
    ctx->r15 = ctx->r17 & 0X8000;
    // 0x80102274: beq         $t7, $zero, L_80102298
    if (ctx->r15 == 0) {
        // 0x80102278: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80102298;
    }
    // 0x80102278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010227C: jal         0x80101E8C
    // 0x80102280: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80101E8C_ovl_intro(rdram, ctx);
        goto after_2;
    // 0x80102280: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80102284: beq         $v0, $zero, L_80102298
    if (ctx->r2 == 0) {
        // 0x80102288: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80102298;
    }
    // 0x80102288: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8010228C: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80102290: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x80102294: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_80102298:
    // 0x80102298: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x8010229C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801022A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801022A4: sw          $t9, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r25;
    // 0x801022A8: lh          $t3, 0x6($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X6);
    // 0x801022AC: sw          $t3, 0x610($sp)
    MEM_W(0X610, ctx->r29) = ctx->r11;
    // 0x801022B0: lh          $t4, 0xC($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XC);
    // 0x801022B4: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x801022B8: sw          $t4, 0x614($sp)
    MEM_W(0X614, ctx->r29) = ctx->r12;
    // 0x801022BC: lh          $t5, 0xE($s2)
    ctx->r13 = MEM_H(ctx->r18, 0XE);
    // 0x801022C0: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x801022C4: sw          $t5, 0x618($sp)
    MEM_W(0X618, ctx->r29) = ctx->r13;
    // 0x801022C8: lh          $t6, 0x8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X8);
    // 0x801022CC: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x801022D0: sw          $t6, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r14;
    // 0x801022D4: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x801022D8: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x801022DC: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
    // 0x801022E0: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x801022E4: lw          $t7, 0x618($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X618);
    // 0x801022E8: sw          $t8, 0x624($sp)
    MEM_W(0X624, ctx->r29) = ctx->r24;
    // 0x801022EC: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x801022F0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x801022F4: sw          $t3, 0x62C($sp)
    MEM_W(0X62C, ctx->r29) = ctx->r11;
    // 0x801022F8: sw          $t9, 0x628($sp)
    MEM_W(0X628, ctx->r29) = ctx->r25;
    // 0x801022FC: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80102300: sw          $t4, 0x630($sp)
    MEM_W(0X630, ctx->r29) = ctx->r12;
    // 0x80102304: sw          $t6, 0x634($sp)
    MEM_W(0X634, ctx->r29) = ctx->r14;
    // 0x80102308: bgez        $t9, L_8010232C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8010230C: sw          $t8, 0x638($sp)
        MEM_W(0X638, ctx->r29) = ctx->r24;
            goto L_8010232C;
    }
    // 0x8010230C: sw          $t8, 0x638($sp)
    MEM_W(0X638, ctx->r29) = ctx->r24;
    // 0x80102310: jal         0x80101558
    // 0x80102314: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    func_80101558_ovl_intro(rdram, ctx);
        goto after_3;
    // 0x80102314: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    after_3:
    // 0x80102318: beq         $v0, $zero, L_8010232C
    if (ctx->r2 == 0) {
        // 0x8010231C: lui         $at, 0xDFFF
        ctx->r1 = S32(0XDFFF << 16);
            goto L_8010232C;
    }
    // 0x8010231C: lui         $at, 0xDFFF
    ctx->r1 = S32(0XDFFF << 16);
    // 0x80102320: ori         $at, $at, 0xFEFF
    ctx->r1 = ctx->r1 | 0XFEFF;
    // 0x80102324: and         $t3, $s1, $at
    ctx->r11 = ctx->r17 & ctx->r1;
    // 0x80102328: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_8010232C:
    // 0x8010232C: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80102330: bgez        $t4, L_80102358
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80102334: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80102358;
    }
    // 0x80102334: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80102338: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010233C: jal         0x801016BC
    // 0x80102340: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    func_801016BC_ovl_intro(rdram, ctx);
        goto after_4;
    // 0x80102340: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    after_4:
    // 0x80102344: beq         $v0, $zero, L_80102358
    if (ctx->r2 == 0) {
        // 0x80102348: lui         $at, 0xBFFF
        ctx->r1 = S32(0XBFFF << 16);
            goto L_80102358;
    }
    // 0x80102348: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8010234C: ori         $at, $at, 0xFBFF
    ctx->r1 = ctx->r1 | 0XFBFF;
    // 0x80102350: and         $t5, $s1, $at
    ctx->r13 = ctx->r17 & ctx->r1;
    // 0x80102354: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_80102358:
    // 0x80102358: andi        $t6, $s1, 0x10
    ctx->r14 = ctx->r17 & 0X10;
    // 0x8010235C: beq         $t6, $zero, L_80102384
    if (ctx->r14 == 0) {
        // 0x80102360: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80102384;
    }
    // 0x80102360: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80102364: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80102368: jal         0x80101854
    // 0x8010236C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101854_ovl_intro(rdram, ctx);
        goto after_5;
    // 0x8010236C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80102370: beq         $v0, $zero, L_80102384
    if (ctx->r2 == 0) {
        // 0x80102374: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_80102384;
    }
    // 0x80102374: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80102378: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x8010237C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80102380: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80102384:
    // 0x80102384: andi        $t8, $s1, 0x20
    ctx->r24 = ctx->r17 & 0X20;
    // 0x80102388: beq         $t8, $zero, L_801023B4
    if (ctx->r24 == 0) {
        // 0x8010238C: ori         $t9, $s4, 0x20
        ctx->r25 = ctx->r20 | 0X20;
            goto L_801023B4;
    }
    // 0x8010238C: ori         $t9, $s4, 0x20
    ctx->r25 = ctx->r20 | 0X20;
    // 0x80102390: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x80102394: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80102398: jal         0x80101854
    // 0x8010239C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101854_ovl_intro(rdram, ctx);
        goto after_6;
    // 0x8010239C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x801023A0: beq         $v0, $zero, L_801023B4
    if (ctx->r2 == 0) {
        // 0x801023A4: addiu       $at, $zero, -0x21
        ctx->r1 = ADD32(0, -0X21);
            goto L_801023B4;
    }
    // 0x801023A4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x801023A8: and         $t3, $s1, $at
    ctx->r11 = ctx->r17 & ctx->r1;
    // 0x801023AC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x801023B0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_801023B4:
    // 0x801023B4: andi        $t4, $s1, 0x40
    ctx->r12 = ctx->r17 & 0X40;
    // 0x801023B8: beq         $t4, $zero, L_801023E4
    if (ctx->r12 == 0) {
        // 0x801023BC: ori         $t5, $s4, 0x40
        ctx->r13 = ctx->r20 | 0X40;
            goto L_801023E4;
    }
    // 0x801023BC: ori         $t5, $s4, 0x40
    ctx->r13 = ctx->r20 | 0X40;
    // 0x801023C0: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x801023C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801023C8: jal         0x80101958
    // 0x801023CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101958_ovl_intro(rdram, ctx);
        goto after_7;
    // 0x801023CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x801023D0: beq         $v0, $zero, L_801023E4
    if (ctx->r2 == 0) {
        // 0x801023D4: addiu       $at, $zero, -0x41
        ctx->r1 = ADD32(0, -0X41);
            goto L_801023E4;
    }
    // 0x801023D4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x801023D8: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x801023DC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x801023E0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_801023E4:
    // 0x801023E4: andi        $t7, $s1, 0x80
    ctx->r15 = ctx->r17 & 0X80;
    // 0x801023E8: beq         $t7, $zero, L_80102414
    if (ctx->r15 == 0) {
        // 0x801023EC: ori         $t8, $s4, 0x80
        ctx->r24 = ctx->r20 | 0X80;
            goto L_80102414;
    }
    // 0x801023EC: ori         $t8, $s4, 0x80
    ctx->r24 = ctx->r20 | 0X80;
    // 0x801023F0: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x801023F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801023F8: jal         0x80101958
    // 0x801023FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101958_ovl_intro(rdram, ctx);
        goto after_8;
    // 0x801023FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80102400: beq         $v0, $zero, L_80102414
    if (ctx->r2 == 0) {
        // 0x80102404: addiu       $at, $zero, -0x81
        ctx->r1 = ADD32(0, -0X81);
            goto L_80102414;
    }
    // 0x80102404: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80102408: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x8010240C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80102410: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80102414:
    // 0x80102414: andi        $t3, $s1, 0x1000
    ctx->r11 = ctx->r17 & 0X1000;
    // 0x80102418: beql        $t3, $zero, L_8010243C
    if (ctx->r11 == 0) {
        // 0x8010241C: sll         $t5, $s1, 3
        ctx->r13 = S32(ctx->r17 << 3);
            goto L_8010243C;
    }
    goto skip_3;
    // 0x8010241C: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    skip_3:
    // 0x80102420: jal         0x8010200C
    // 0x80102424: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010200C_ovl_intro(rdram, ctx);
        goto after_9;
    // 0x80102424: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80102428: beq         $v0, $zero, L_80102438
    if (ctx->r2 == 0) {
        // 0x8010242C: addiu       $at, $zero, -0x1001
        ctx->r1 = ADD32(0, -0X1001);
            goto L_80102438;
    }
    // 0x8010242C: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80102430: and         $t4, $s1, $at
    ctx->r12 = ctx->r17 & ctx->r1;
    // 0x80102434: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80102438:
    // 0x80102438: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
L_8010243C:
    // 0x8010243C: bgez        $t5, L_80102468
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80102440: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_80102468;
    }
    // 0x80102440: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80102444: jal         0x8010200C
    // 0x80102448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010200C_ovl_intro(rdram, ctx);
        goto after_10;
    // 0x80102448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x8010244C: beq         $v0, $zero, L_80102460
    if (ctx->r2 == 0) {
        // 0x80102450: lui         $at, 0xEFFF
        ctx->r1 = S32(0XEFFF << 16);
            goto L_80102460;
    }
    // 0x80102450: lui         $at, 0xEFFF
    ctx->r1 = S32(0XEFFF << 16);
    // 0x80102454: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80102458: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x8010245C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80102460:
    // 0x80102460: b           L_80103094
    // 0x80102464: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80103094;
    // 0x80102464: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80102468:
    // 0x80102468: lw          $a1, 0x6220($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6220);
    // 0x8010246C: lw          $t7, 0x60C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60C);
    // 0x80102470: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80102474: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80102478: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010247C: beql        $at, $zero, L_801024DC
    if (ctx->r1 == 0) {
        // 0x80102480: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_801024DC;
    }
    goto skip_4;
    // 0x80102480: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_4:
    // 0x80102484: lw          $v0, 0x6224($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6224);
    // 0x80102488: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8010248C: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80102490: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80102494: beql        $at, $zero, L_801024DC
    if (ctx->r1 == 0) {
        // 0x80102498: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_801024DC;
    }
    goto skip_5;
    // 0x80102498: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_5:
    // 0x8010249C: lw          $t9, 0x6228($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6228);
    // 0x801024A0: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x801024A4: lw          $t7, 0x620($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X620);
    // 0x801024A8: addu        $t3, $a1, $t9
    ctx->r11 = ADD32(ctx->r5, ctx->r25);
    // 0x801024AC: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801024B0: beq         $at, $zero, L_801024D8
    if (ctx->r1 == 0) {
        // 0x801024B4: lui         $t6, 0x8016
        ctx->r14 = S32(0X8016 << 16);
            goto L_801024D8;
    }
    // 0x801024B4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801024B8: lw          $t6, 0x622C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X622C);
    // 0x801024BC: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x801024C0: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x801024C4: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801024C8: beql        $at, $zero, L_801024DC
    if (ctx->r1 == 0) {
        // 0x801024CC: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_801024DC;
    }
    goto skip_6;
    // 0x801024CC: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_6:
    // 0x801024D0: b           L_80103094
    // 0x801024D4: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80103094;
    // 0x801024D4: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_801024D8:
    // 0x801024D8: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
L_801024DC:
    // 0x801024DC: lw          $t5, 0x61C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X61C);
    // 0x801024E0: lw          $t6, 0x610($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X610);
    // 0x801024E4: lw          $t8, 0x620($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X620);
    // 0x801024E8: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x801024EC: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801024F0: bne         $at, $zero, L_80102510
    if (ctx->r1 != 0) {
        // 0x801024F4: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_80102510;
    }
    // 0x801024F4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801024F8: lw          $v0, 0x6224($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6224);
    // 0x801024FC: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80102500: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80102504: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80102508: beq         $at, $zero, L_80102518
    if (ctx->r1 == 0) {
        // 0x8010250C: nop
    
            goto L_80102518;
    }
    // 0x8010250C: nop

L_80102510:
    // 0x80102510: b           L_80103094
    // 0x80102514: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80103094;
    // 0x80102514: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80102518:
    // 0x80102518: lw          $t7, 0x6228($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6228);
    // 0x8010251C: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80102520: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80102524: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x80102528: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8010252C: bne         $at, $zero, L_8010254C
    if (ctx->r1 != 0) {
        // 0x80102530: nop
    
            goto L_8010254C;
    }
    // 0x80102530: nop

    // 0x80102534: lw          $t4, 0x622C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X622C);
    // 0x80102538: lw          $t3, 0x610($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X610);
    // 0x8010253C: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x80102540: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80102544: beql        $at, $zero, L_80102558
    if (ctx->r1 == 0) {
        // 0x80102548: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80102558;
    }
    goto skip_7;
    // 0x80102548: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_7:
L_8010254C:
    // 0x8010254C: b           L_80103094
    // 0x80102550: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_80103094;
    // 0x80102550: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x80102554: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_80102558:
    // 0x80102558: beq         $at, $zero, L_80102568
    if (ctx->r1 == 0) {
        // 0x8010255C: lw          $t5, 0x60C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60C);
            goto L_80102568;
    }
    // 0x8010255C: lw          $t5, 0x60C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60C);
    // 0x80102560: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x80102564: sw          $t6, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r14;
L_80102568:
    // 0x80102568: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8010256C: beq         $at, $zero, L_8010257C
    if (ctx->r1 == 0) {
        // 0x80102570: lw          $t8, 0x610($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X610);
            goto L_8010257C;
    }
    // 0x80102570: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80102574: subu        $t7, $a0, $t8
    ctx->r15 = SUB32(ctx->r4, ctx->r24);
    // 0x80102578: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
L_8010257C:
    // 0x8010257C: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80102580: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80102584: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80102588: beq         $at, $zero, L_801025B8
    if (ctx->r1 == 0) {
        // 0x8010258C: addu        $t3, $t4, $t9
        ctx->r11 = ADD32(ctx->r12, ctx->r25);
            goto L_801025B8;
    }
    // 0x8010258C: addu        $t3, $t4, $t9
    ctx->r11 = ADD32(ctx->r12, ctx->r25);
    // 0x80102590: subu        $t5, $t3, $a1
    ctx->r13 = SUB32(ctx->r11, ctx->r5);
    // 0x80102594: lw          $t4, 0x634($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X634);
    // 0x80102598: sw          $t5, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r13;
    // 0x8010259C: lh          $t6, 0xC($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XC);
    // 0x801025A0: subu        $t8, $a1, $t9
    ctx->r24 = SUB32(ctx->r5, ctx->r25);
    // 0x801025A4: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x801025A8: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x801025AC: sw          $t3, 0x634($sp)
    MEM_W(0X634, ctx->r29) = ctx->r11;
    // 0x801025B0: sw          $a1, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r5;
    // 0x801025B4: sw          $t6, 0x614($sp)
    MEM_W(0X614, ctx->r29) = ctx->r14;
L_801025B8:
    // 0x801025B8: lh          $t5, 0x6($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X6);
    // 0x801025BC: lw          $t6, 0x620($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X620);
    // 0x801025C0: lw          $t9, 0x610($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X610);
    // 0x801025C4: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801025C8: beq         $at, $zero, L_801025F8
    if (ctx->r1 == 0) {
        // 0x801025CC: addu        $t8, $t6, $t9
        ctx->r24 = ADD32(ctx->r14, ctx->r25);
            goto L_801025F8;
    }
    // 0x801025CC: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x801025D0: subu        $t7, $t8, $v0
    ctx->r15 = SUB32(ctx->r24, ctx->r2);
    // 0x801025D4: lw          $t6, 0x638($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X638);
    // 0x801025D8: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
    // 0x801025DC: lh          $t4, 0xE($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XE);
    // 0x801025E0: subu        $t3, $v0, $t9
    ctx->r11 = SUB32(ctx->r2, ctx->r25);
    // 0x801025E4: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x801025E8: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x801025EC: sw          $t8, 0x638($sp)
    MEM_W(0X638, ctx->r29) = ctx->r24;
    // 0x801025F0: sw          $v0, 0x610($sp)
    MEM_W(0X610, ctx->r29) = ctx->r2;
    // 0x801025F4: sw          $t4, 0x618($sp)
    MEM_W(0X618, ctx->r29) = ctx->r12;
L_801025F8:
    // 0x801025F8: bne         $s4, $zero, L_80102614
    if (ctx->r20 != 0) {
        // 0x801025FC: andi        $t9, $s4, 0x30
        ctx->r25 = ctx->r20 & 0X30;
            goto L_80102614;
    }
    // 0x801025FC: andi        $t9, $s4, 0x30
    ctx->r25 = ctx->r20 & 0X30;
    // 0x80102600: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80102604: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80102608: sw          $t7, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r15;
    // 0x8010260C: b           L_80102648
    // 0x80102610: sw          $t4, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r12;
        goto L_80102648;
    // 0x80102610: sw          $t4, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r12;
L_80102614:
    // 0x80102614: beq         $t9, $zero, L_80102630
    if (ctx->r25 == 0) {
        // 0x80102618: andi        $t6, $s4, 0xC0
        ctx->r14 = ctx->r20 & 0XC0;
            goto L_80102630;
    }
    // 0x80102618: andi        $t6, $s4, 0xC0
    ctx->r14 = ctx->r20 & 0XC0;
    // 0x8010261C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80102620: sw          $t3, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r11;
    // 0x80102624: lh          $t5, 0x4E($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X4E);
    // 0x80102628: b           L_80102648
    // 0x8010262C: sw          $t5, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r13;
        goto L_80102648;
    // 0x8010262C: sw          $t5, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r13;
L_80102630:
    // 0x80102630: beql        $t6, $zero, L_8010264C
    if (ctx->r14 == 0) {
        // 0x80102634: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8010264C;
    }
    goto skip_8;
    // 0x80102634: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x80102638: lh          $t8, 0x4E($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4E);
    // 0x8010263C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80102640: sw          $t7, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r15;
    // 0x80102644: sw          $t8, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r24;
L_80102648:
    // 0x80102648: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8010264C:
    // 0x8010264C: andi        $t9, $s1, 0xF0
    ctx->r25 = ctx->r17 & 0XF0;
    // 0x80102650: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80102654: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102658: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8010265C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102660: bne         $t9, $zero, L_80102670
    if (ctx->r25 != 0) {
        // 0x80102664: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_80102670;
    }
    // 0x80102664: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102668: beq         $s6, $zero, L_801026D0
    if (ctx->r22 == 0) {
        // 0x8010266C: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_801026D0;
    }
    // 0x8010266C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
L_80102670:
    // 0x80102670: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102674: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80102678: addiu       $t6, $t6, 0x62B0
    ctx->r14 = ADD32(ctx->r14, 0X62B0);
    // 0x8010267C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102680: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102684: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102688: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8010268C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102690: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80102694: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102698: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8010269C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801026A0: lw          $v1, 0x640($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X640);
    // 0x801026A4: lw          $t7, 0x63C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X63C);
    // 0x801026A8: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x801026AC: sll         $t9, $t4, 24
    ctx->r25 = S32(ctx->r12 << 24);
    // 0x801026B0: sll         $t3, $t4, 16
    ctx->r11 = S32(ctx->r12 << 16);
    // 0x801026B4: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x801026B8: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x801026BC: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x801026C0: andi        $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 & 0XFF;
    // 0x801026C4: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x801026C8: b           L_801026EC
    // 0x801026CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_801026EC;
    // 0x801026CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_801026D0:
    // 0x801026D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801026D4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801026D8: addiu       $t6, $t6, 0x6298
    ctx->r14 = ADD32(ctx->r14, 0X6298);
    // 0x801026DC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801026E0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801026E4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801026E8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_801026EC:
    // 0x801026EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801026F0: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x801026F4: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x801026F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801026FC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102700: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102704: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102708: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8010270C: and         $t4, $t8, $at
    ctx->r12 = ctx->r24 & ctx->r1;
    // 0x80102710: beql        $t4, $zero, L_80102C0C
    if (ctx->r12 == 0) {
        // 0x80102714: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80102C0C;
    }
    goto skip_9;
    // 0x80102714: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x80102718: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010271C: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x80102720: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x80102724: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102728: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8010272C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102730: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102734: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80102738: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8010273C: bgez        $t6, L_8010299C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80102740: sll         $t8, $v1, 5
        ctx->r24 = S32(ctx->r3 << 5);
            goto L_8010299C;
    }
    // 0x80102740: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x80102744: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102748: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8010274C: lui         $t3, 0xE800
    ctx->r11 = S32(0XE800 << 16);
    // 0x80102750: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102754: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102758: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010275C: lw          $t4, 0x14($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14);
    // 0x80102760: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80102764: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80102768: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8010276C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102770: lui         $t4, 0xF000
    ctx->r12 = S32(0XF000 << 16);
    // 0x80102774: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80102778: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010277C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102780: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102784: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102788: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010278C: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x80102790: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80102794: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102798: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8010279C: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x801027A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801027A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801027A8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801027AC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801027B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801027B4: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801027B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801027BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801027C0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801027C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801027C8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801027CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801027D0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801027D4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801027D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801027DC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801027E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801027E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801027E8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801027EC: lh          $t6, 0x10($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X10);
    // 0x801027F0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801027F4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801027F8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x801027FC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102800: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80102804: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102808: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010280C: lw          $t6, 0x624($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X624);
    // 0x80102810: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80102814: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102818: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8010281C: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x80102820: addiu       $t4, $t8, 0x7
    ctx->r12 = ADD32(ctx->r24, 0X7);
    // 0x80102824: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102828: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8010282C: sra         $t9, $t4, 3
    ctx->r25 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80102830: andi        $t3, $t9, 0x1FF
    ctx->r11 = ctx->r25 & 0X1FF;
    // 0x80102834: sll         $t6, $t3, 9
    ctx->r14 = S32(ctx->r11 << 9);
    // 0x80102838: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8010283C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102840: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80102844: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102848: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8010284C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102850: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102854: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102858: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8010285C: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x80102860: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102864: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x80102868: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8010286C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102870: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102874: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x80102878: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x8010287C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80102880: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x80102884: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80102888: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x8010288C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102890: lw          $t6, 0x624($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X624);
    // 0x80102894: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x80102898: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8010289C: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x801028A0: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x801028A4: lw          $t5, 0x628($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X628);
    // 0x801028A8: lw          $t6, 0x618($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X618);
    // 0x801028AC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x801028B0: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x801028B4: sll         $t9, $t4, 12
    ctx->r25 = S32(ctx->r12 << 12);
    // 0x801028B8: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x801028BC: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x801028C0: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x801028C4: or          $t3, $t9, $s5
    ctx->r11 = ctx->r25 | ctx->r21;
    // 0x801028C8: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x801028CC: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x801028D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801028D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801028D8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801028DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801028E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801028E4: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801028E8: lw          $t4, 0x624($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X624);
    // 0x801028EC: lw          $t7, 0x614($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X614);
    // 0x801028F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801028F4: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x801028F8: subu        $t9, $t3, $t7
    ctx->r25 = SUB32(ctx->r11, ctx->r15);
    // 0x801028FC: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x80102900: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102904: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102908: sra         $t5, $t6, 3
    ctx->r13 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8010290C: andi        $t8, $t5, 0x1FF
    ctx->r24 = ctx->r13 & 0X1FF;
    // 0x80102910: sll         $t4, $t8, 9
    ctx->r12 = S32(ctx->r24 << 9);
    // 0x80102914: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x80102918: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8010291C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102920: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x80102924: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102928: lw          $t3, 0x618($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X618);
    // 0x8010292C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80102930: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102934: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102938: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8010293C: sll         $t8, $t5, 12
    ctx->r24 = S32(ctx->r13 << 12);
    // 0x80102940: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102944: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80102948: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8010294C: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80102950: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x80102954: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102958: lw          $t8, 0x624($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X624);
    // 0x8010295C: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80102960: addu        $t3, $t5, $t8
    ctx->r11 = ADD32(ctx->r13, ctx->r24);
    // 0x80102964: lw          $t8, 0x628($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X628);
    // 0x80102968: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x8010296C: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80102970: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102974: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x80102978: addu        $t3, $t5, $t8
    ctx->r11 = ADD32(ctx->r13, ctx->r24);
    // 0x8010297C: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80102980: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102984: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80102988: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8010298C: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80102990: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102994: b           L_80102DE8
    // 0x80102998: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
        goto L_80102DE8;
    // 0x80102998: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_8010299C:
    // 0x8010299C: bgezl       $t8, L_80102DEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801029A0: lui         $at, 0x6
        ctx->r1 = S32(0X6 << 16);
            goto L_80102DEC;
    }
    goto skip_10;
    // 0x801029A0: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    skip_10:
    // 0x801029A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801029A8: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801029AC: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x801029B0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801029B4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801029B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801029BC: lw          $t4, 0x14($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14);
    // 0x801029C0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801029C4: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x801029C8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801029CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801029D0: lui         $t4, 0xF000
    ctx->r12 = S32(0XF000 << 16);
    // 0x801029D4: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x801029D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801029DC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801029E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801029E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801029E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801029EC: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x801029F0: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x801029F4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801029F8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801029FC: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80102A00: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102A04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102A08: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102A0C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102A10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102A14: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80102A18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102A1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102A20: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102A24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102A28: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102A2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102A30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102A34: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102A38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102A3C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102A40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102A44: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102A48: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102A4C: lh          $t8, 0x10($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X10);
    // 0x80102A50: sra         $t3, $t8, 1
    ctx->r11 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80102A54: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80102A58: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x80102A5C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x80102A60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102A64: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80102A68: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102A6C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102A70: lw          $t3, 0x624($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X624);
    // 0x80102A74: lw          $t8, 0x614($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X614);
    // 0x80102A78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102A7C: addu        $t7, $t8, $t3
    ctx->r15 = ADD32(ctx->r24, ctx->r11);
    // 0x80102A80: subu        $t4, $t7, $t8
    ctx->r12 = SUB32(ctx->r15, ctx->r24);
    // 0x80102A84: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80102A88: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102A8C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102A90: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x80102A94: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80102A98: andi        $t3, $t5, 0x1FF
    ctx->r11 = ctx->r13 & 0X1FF;
    // 0x80102A9C: sll         $t7, $t3, 9
    ctx->r15 = S32(ctx->r11 << 9);
    // 0x80102AA0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80102AA4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102AA8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80102AAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102AB0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80102AB4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102AB8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102ABC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102AC0: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80102AC4: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x80102AC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102ACC: lw          $t4, 0x618($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X618);
    // 0x80102AD0: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80102AD4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102AD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102ADC: andi        $t3, $t5, 0xFFF
    ctx->r11 = ctx->r13 & 0XFFF;
    // 0x80102AE0: sll         $t7, $t3, 12
    ctx->r15 = S32(ctx->r11 << 12);
    // 0x80102AE4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80102AE8: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80102AEC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80102AF0: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x80102AF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80102AF8: lw          $t7, 0x624($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X624);
    // 0x80102AFC: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x80102B00: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80102B04: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x80102B08: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80102B0C: lw          $t4, 0x628($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X628);
    // 0x80102B10: lw          $t7, 0x618($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X618);
    // 0x80102B14: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80102B18: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80102B1C: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x80102B20: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80102B24: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80102B28: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80102B2C: or          $t3, $t5, $s5
    ctx->r11 = ctx->r13 | ctx->r21;
    // 0x80102B30: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80102B34: or          $t7, $t3, $t5
    ctx->r15 = ctx->r11 | ctx->r13;
    // 0x80102B38: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102B3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102B40: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102B44: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102B48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102B4C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102B50: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102B54: lw          $t8, 0x614($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X614);
    // 0x80102B58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102B5C: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80102B60: subu        $t5, $t3, $t8
    ctx->r13 = SUB32(ctx->r11, ctx->r24);
    // 0x80102B64: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80102B68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102B6C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102B70: addiu       $t4, $t7, 0x7
    ctx->r12 = ADD32(ctx->r15, 0X7);
    // 0x80102B74: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80102B78: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x80102B7C: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x80102B80: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x80102B84: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102B88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102B8C: lw          $t7, 0x614($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X614);
    // 0x80102B90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102B94: lw          $t8, 0x618($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X618);
    // 0x80102B98: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102B9C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102BA0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102BA4: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80102BA8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80102BAC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102BB0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80102BB4: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80102BB8: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80102BBC: or          $t4, $t3, $t7
    ctx->r12 = ctx->r11 | ctx->r15;
    // 0x80102BC0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102BC4: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102BC8: lw          $t6, 0x614($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X614);
    // 0x80102BCC: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80102BD0: lw          $t9, 0x628($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X628);
    // 0x80102BD4: lw          $t6, 0x618($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X618);
    // 0x80102BD8: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x80102BDC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x80102BE0: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80102BE4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80102BE8: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x80102BEC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x80102BF0: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x80102BF4: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80102BF8: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x80102BFC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102C00: b           L_80102DE8
    // 0x80102C04: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
        goto L_80102DE8;
    // 0x80102C04: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80102C08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80102C0C:
    // 0x80102C0C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80102C10: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x80102C14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102C18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102C1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102C20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102C24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102C28: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80102C2C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102C30: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102C34: lh          $t3, 0x10($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X10);
    // 0x80102C38: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80102C3C: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x80102C40: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80102C44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102C48: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80102C4C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80102C50: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102C54: lw          $t3, 0x624($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X624);
    // 0x80102C58: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80102C5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102C60: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80102C64: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x80102C68: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80102C6C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102C70: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102C74: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x80102C78: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80102C7C: andi        $t3, $t8, 0x1FF
    ctx->r11 = ctx->r24 & 0X1FF;
    // 0x80102C80: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80102C84: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80102C88: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80102C8C: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80102C90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102C94: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80102C98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102C9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102CA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102CA4: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80102CA8: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x80102CAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102CB0: lw          $t7, 0x618($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X618);
    // 0x80102CB4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80102CB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102CBC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102CC0: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x80102CC4: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80102CC8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80102CCC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80102CD0: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80102CD4: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x80102CD8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102CDC: lw          $t4, 0x624($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X624);
    // 0x80102CE0: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x80102CE4: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80102CE8: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x80102CEC: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80102CF0: lw          $t7, 0x628($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X628);
    // 0x80102CF4: lw          $t4, 0x618($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X618);
    // 0x80102CF8: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80102CFC: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x80102D00: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80102D04: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80102D08: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x80102D0C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80102D10: or          $t3, $t8, $s5
    ctx->r11 = ctx->r24 | ctx->r21;
    // 0x80102D14: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80102D18: or          $t4, $t3, $t8
    ctx->r12 = ctx->r11 | ctx->r24;
    // 0x80102D1C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80102D20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102D24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102D28: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102D2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D30: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102D34: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102D38: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80102D3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102D40: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x80102D44: subu        $t8, $t3, $t5
    ctx->r24 = SUB32(ctx->r11, ctx->r13);
    // 0x80102D48: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x80102D4C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102D50: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102D54: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x80102D58: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80102D5C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x80102D60: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x80102D64: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x80102D68: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80102D6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D70: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x80102D74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102D78: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x80102D7C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80102D80: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102D84: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102D88: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80102D8C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80102D90: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102D94: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80102D98: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x80102D9C: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80102DA0: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x80102DA4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102DA8: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102DAC: lw          $t6, 0x614($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X614);
    // 0x80102DB0: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80102DB4: lw          $t9, 0x628($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X628);
    // 0x80102DB8: lw          $t6, 0x618($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X618);
    // 0x80102DBC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80102DC0: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80102DC4: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80102DC8: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80102DCC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80102DD0: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80102DD4: sll         $t7, $t4, 12
    ctx->r15 = S32(ctx->r12 << 12);
    // 0x80102DD8: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80102DDC: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x80102DE0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102DE4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80102DE8:
    // 0x80102DE8: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
L_80102DEC:
    // 0x80102DEC: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x80102DF0: beq         $t9, $zero, L_80102FC0
    if (ctx->r25 == 0) {
        // 0x80102DF4: sll         $t5, $v1, 14
        ctx->r13 = S32(ctx->r3 << 14);
            goto L_80102FC0;
    }
    // 0x80102DF4: sll         $t5, $v1, 14
    ctx->r13 = S32(ctx->r3 << 14);
    // 0x80102DF8: bgez        $t5, L_80102ED8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80102DFC: addiu       $t8, $zero, -0x400
        ctx->r24 = ADD32(0, -0X400);
            goto L_80102ED8;
    }
    // 0x80102DFC: addiu       $t8, $zero, -0x400
    ctx->r24 = ADD32(0, -0X400);
    // 0x80102E00: lw          $t7, 0x60C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60C);
    // 0x80102E04: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80102E08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102E0C: sw          $t8, 0x62C($sp)
    MEM_W(0X62C, ctx->r29) = ctx->r24;
    // 0x80102E10: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80102E14: lw          $t4, 0x620($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X620);
    // 0x80102E18: lw          $t7, 0x610($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X610);
    // 0x80102E1C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80102E20: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80102E24: sll         $t8, $t5, 12
    ctx->r24 = S32(ctx->r13 << 12);
    // 0x80102E28: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102E2C: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80102E30: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80102E34: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102E38: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102E3C: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x80102E40: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80102E44: or          $t8, $t3, $t5
    ctx->r24 = ctx->r11 | ctx->r13;
    // 0x80102E48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102E4C: lw          $t7, 0x60C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60C);
    // 0x80102E50: lw          $t3, 0x610($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X610);
    // 0x80102E54: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102E58: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80102E5C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80102E60: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x80102E64: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80102E68: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80102E6C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102E70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102E74: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80102E78: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80102E7C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102E80: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102E84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102E88: lw          $t5, 0x624($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X624);
    // 0x80102E8C: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x80102E90: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80102E94: lw          $t3, 0x638($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X638);
    // 0x80102E98: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80102E9C: sll         $t6, $t4, 21
    ctx->r14 = S32(ctx->r12 << 21);
    // 0x80102EA0: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x80102EA4: or          $t9, $t6, $t5
    ctx->r25 = ctx->r14 | ctx->r13;
    // 0x80102EA8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102EAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102EB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102EB4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102EB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102EBC: lw          $t9, 0x630($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X630);
    // 0x80102EC0: lw          $t6, 0x62C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X62C);
    // 0x80102EC4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80102EC8: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x80102ECC: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x80102ED0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102ED4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80102ED8:
    // 0x80102ED8: sll         $t4, $v1, 13
    ctx->r12 = S32(ctx->r3 << 13);
    // 0x80102EDC: bgez        $t4, L_80103084
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80102EE0: addiu       $t3, $zero, -0x400
        ctx->r11 = ADD32(0, -0X400);
            goto L_80103084;
    }
    // 0x80102EE0: addiu       $t3, $zero, -0x400
    ctx->r11 = ADD32(0, -0X400);
    // 0x80102EE4: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80102EE8: lw          $t5, 0x61C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X61C);
    // 0x80102EEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102EF0: sw          $t3, 0x630($sp)
    MEM_W(0X630, ctx->r29) = ctx->r11;
    // 0x80102EF4: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80102EF8: lw          $t5, 0x620($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X620);
    // 0x80102EFC: lw          $t9, 0x610($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X610);
    // 0x80102F00: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80102F04: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x80102F08: sll         $t3, $t4, 12
    ctx->r11 = S32(ctx->r12 << 12);
    // 0x80102F0C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102F10: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80102F14: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80102F18: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102F1C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102F20: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x80102F24: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x80102F28: or          $t3, $t6, $t4
    ctx->r11 = ctx->r14 | ctx->r12;
    // 0x80102F2C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102F30: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80102F34: lw          $t6, 0x610($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X610);
    // 0x80102F38: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80102F3C: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x80102F40: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80102F44: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x80102F48: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80102F4C: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80102F50: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102F54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102F58: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80102F5C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102F60: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102F64: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102F68: lw          $t4, 0x628($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X628);
    // 0x80102F6C: lw          $t6, 0x618($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X618);
    // 0x80102F70: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80102F74: lw          $t6, 0x634($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X634);
    // 0x80102F78: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x80102F7C: sll         $t9, $t3, 5
    ctx->r25 = S32(ctx->r11 << 5);
    // 0x80102F80: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80102F84: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80102F88: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80102F8C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102F90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102F94: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80102F98: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102F9C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102FA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102FA4: lw          $t7, 0x630($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X630);
    // 0x80102FA8: lw          $t6, 0x62C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X62C);
    // 0x80102FAC: andi        $t3, $t7, 0xFFFF
    ctx->r11 = ctx->r15 & 0XFFFF;
    // 0x80102FB0: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80102FB4: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x80102FB8: b           L_80103084
    // 0x80102FBC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80103084;
    // 0x80102FBC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80102FC0:
    // 0x80102FC0: lw          $t6, 0x60C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60C);
    // 0x80102FC4: lw          $t5, 0x61C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X61C);
    // 0x80102FC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102FCC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102FD0: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80102FD4: lw          $t5, 0x620($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X620);
    // 0x80102FD8: lw          $t6, 0x610($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X610);
    // 0x80102FDC: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102FE0: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x80102FE4: sll         $t9, $t3, 12
    ctx->r25 = S32(ctx->r11 << 12);
    // 0x80102FE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102FEC: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80102FF0: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80102FF4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102FF8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80102FFC: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x80103000: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80103004: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103008: lw          $t6, 0x60C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60C);
    // 0x8010300C: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80103010: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80103014: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80103018: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8010301C: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80103020: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x80103024: or          $t6, $t4, $t9
    ctx->r14 = ctx->r12 | ctx->r25;
    // 0x80103028: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010302C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80103030: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80103034: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80103038: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8010303C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80103040: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103044: lw          $t9, 0x638($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X638);
    // 0x80103048: lw          $t3, 0x634($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X634);
    // 0x8010304C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80103050: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80103054: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x80103058: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8010305C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80103060: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103064: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80103068: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010306C: lw          $t6, 0x630($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X630);
    // 0x80103070: lw          $t9, 0x62C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X62C);
    // 0x80103074: andi        $t5, $t6, 0xFFFF
    ctx->r13 = ctx->r14 & 0XFFFF;
    // 0x80103078: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x8010307C: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80103080: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80103084:
    // 0x80103084: beq         $s6, $zero, L_80103090
    if (ctx->r22 == 0) {
        // 0x80103088: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_80103090;
    }
    // 0x80103088: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8010308C: sh          $t8, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r24;
L_80103090:
    // 0x80103090: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80103094:
    // 0x80103094: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
L_80103098:
    // 0x80103098: addiu       $t6, $sp, 0x5E8
    ctx->r14 = ADD32(ctx->r29, 0X5E8);
    // 0x8010309C: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x801030A0: bne         $t9, $t6, L_801021BC
    if (ctx->r25 != ctx->r14) {
        // 0x801030A4: sw          $t9, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r25;
            goto L_801021BC;
    }
    // 0x801030A4: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x801030A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801030AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801030B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801030B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801030B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801030BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801030C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801030C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801030C8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801030CC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801030D0: jr          $ra
    // 0x801030D4: addiu       $sp, $sp, 0x648
    ctx->r29 = ADD32(ctx->r29, 0X648);
    return;
    // 0x801030D4: addiu       $sp, $sp, 0x648
    ctx->r29 = ADD32(ctx->r29, 0X648);
    // 0x801030D8: nop

    // 0x801030DC: nop

;}
RECOMP_FUNC void func_80010150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010154: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80010158: addiu       $a3, $a3, -0x3BAC
    ctx->r7 = ADD32(ctx->r7, -0X3BAC);
    // 0x8001015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010160: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80010164: lw          $t6, -0x3BAC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3BAC);
    // 0x80010168: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001016C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80010170: addiu       $t0, $t0, 0x59D0
    ctx->r8 = ADD32(ctx->r8, 0X59D0);
    // 0x80010174: sw          $t6, 0x5384($at)
    MEM_W(0X5384, ctx->r1) = ctx->r14;
    // 0x80010178: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001017C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80010180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80010184: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80010188: beq         $at, $zero, L_800101B0
    if (ctx->r1 == 0) {
        // 0x8001018C: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_800101B0;
    }
    // 0x8001018C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80010190: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80010194:
    // 0x80010194: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    // 0x80010198: beq         $a0, $zero, L_800101B0
    if (ctx->r4 == 0) {
        // 0x8001019C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800101B0;
    }
    // 0x8001019C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800101A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800101A4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800101A8: bnel        $at, $zero, L_80010194
    if (ctx->r1 != 0) {
        // 0x800101AC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80010194;
    }
    goto skip_0;
    // 0x800101AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800101B0:
    // 0x800101B0: bgez        $a0, L_800101D0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800101B4: addiu       $t3, $t3, 0x14D8
        ctx->r11 = ADD32(ctx->r11, 0X14D8);
            goto L_800101D0;
    }
    // 0x800101B4: addiu       $t3, $t3, 0x14D8
    ctx->r11 = ADD32(ctx->r11, 0X14D8);
    // 0x800101B8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800101BC: addiu       $a2, $a2, 0x5380
    ctx->r6 = ADD32(ctx->r6, 0X5380);
    // 0x800101C0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800101C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800101C8: b           L_800101DC
    // 0x800101CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_800101DC;
    // 0x800101CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800101D0:
    // 0x800101D0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800101D4: addiu       $a2, $a2, 0x5380
    ctx->r6 = ADD32(ctx->r6, 0X5380);
    // 0x800101D8: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800101DC:
    // 0x800101DC: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800101E0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800101E4: addiu       $v1, $v1, 0x12D8
    ctx->r3 = ADD32(ctx->r3, 0X12D8);
    // 0x800101E8: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x800101EC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800101F0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_800101F4:
    // 0x800101F4: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x800101F8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800101FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80010200: sh          $t4, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r12;
    // 0x80010204: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x80010208: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001020C: sh          $t5, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r13;
    // 0x80010210: lhu         $t6, -0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, -0X4);
    // 0x80010214: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x80010218: lhu         $t7, -0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, -0X2);
    // 0x8001021C: bne         $a0, $zero, L_800101F4
    if (ctx->r4 != 0) {
        // 0x80010220: sh          $t7, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r15;
            goto L_800101F4;
    }
    // 0x80010220: sh          $t7, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r15;
    // 0x80010224: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010228: sw          $zero, 0x538C($at)
    MEM_W(0X538C, ctx->r1) = 0;
    // 0x8001022C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80010230: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80010234: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80010238: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001023C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80010240: bne         $at, $zero, L_8001024C
    if (ctx->r1 != 0) {
        // 0x80010244: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8001024C;
    }
    // 0x80010244: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80010248: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8001024C:
    // 0x8001024C: lhu         $t2, 0x4F12($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X4F12);
    // 0x80010250: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80010254: beq         $t3, $zero, L_80010278
    if (ctx->r11 == 0) {
        // 0x80010258: nop
    
            goto L_80010278;
    }
    // 0x80010258: nop

    // 0x8001025C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80010260: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010264: lw          $t5, 0x59D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X59D4);
    // 0x80010268: sw          $t4, 0x59D8($at)
    MEM_W(0X59D8, ctx->r1) = ctx->r12;
    // 0x8001026C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010270: b           L_800102B0
    // 0x80010274: sw          $t5, 0x59DC($at)
    MEM_W(0X59DC, ctx->r1) = ctx->r13;
        goto L_800102B0;
    // 0x80010274: sw          $t5, 0x59DC($at)
    MEM_W(0X59DC, ctx->r1) = ctx->r13;
L_80010278:
    // 0x80010278: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001027C: lw          $v0, 0x59E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59E4);
    // 0x80010280: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010284: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80010288: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001028C: sw          $zero, 0x59D8($at)
    MEM_W(0X59D8, ctx->r1) = 0;
    // 0x80010290: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80010294: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80010298: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001029C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x800102A0: lw          $t9, -0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X3C);
    // 0x800102A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800102A8: addiu       $v1, $v1, -0x3C
    ctx->r3 = ADD32(ctx->r3, -0X3C);
    // 0x800102AC: sw          $t9, 0x59DC($at)
    MEM_W(0X59DC, ctx->r1) = ctx->r25;
L_800102B0:
    // 0x800102B0: jal         0x800110D0
    // 0x800102B4: nop

    func_800110D0(rdram, ctx);
        goto after_0;
    // 0x800102B4: nop

    after_0:
    // 0x800102B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800102BC: sh          $zero, 0x5388($at)
    MEM_H(0X5388, ctx->r1) = 0;
    // 0x800102C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800102C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800102C8: jr          $ra
    // 0x800102CC: nop

    return;
    // 0x800102CC: nop

;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038404: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80038408: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003840C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80038410: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80038414: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80038418: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003841C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80038420: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80038424: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x80038428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003842C: bne         $t6, $at, L_800384E8
    if (ctx->r14 != ctx->r1) {
        // 0x80038430: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800384E8;
    }
    // 0x80038430: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80038434: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80038438: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003843C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80038440: blez        $t7, L_800384E8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80038444: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800384E8;
    }
    // 0x80038444: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80038448: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_8003844C:
    // 0x8003844C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80038450: beq         $t9, $zero, L_800384D0
    if (ctx->r25 == 0) {
        // 0x80038454: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800384D0;
    }
    // 0x80038454: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x80038458: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x8003845C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x80038460: bnel        $t6, $zero, L_800384D4
    if (ctx->r14 != 0) {
        // 0x80038464: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800384D4;
    }
    goto skip_0;
    // 0x80038464: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x80038468: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8003846C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x80038470: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80038474: beq         $v0, $zero, L_8003848C
    if (ctx->r2 == 0) {
        // 0x80038478: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_8003848C;
    }
    // 0x80038478: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x8003847C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x80038480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80038484: jal         0x80038310
    // 0x80038488: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_80038310(rdram, ctx);
        goto after_0;
    // 0x80038488: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_8003848C:
    // 0x8003848C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x80038490: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80038494: blezl       $t8, L_800384D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80038498: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800384D4;
    }
    goto skip_1;
    // 0x80038498: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x8003849C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800384A0:
    // 0x800384A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800384A4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800384A8: beq         $a0, $zero, L_800384B8
    if (ctx->r4 == 0) {
        // 0x800384AC: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800384B8;
    }
    // 0x800384AC: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800384B0: jal         0x80038310
    // 0x800384B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_80038310(rdram, ctx);
        goto after_1;
    // 0x800384B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800384B8:
    // 0x800384B8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800384BC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800384C0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800384C4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800384C8: bnel        $at, $zero, L_800384A0
    if (ctx->r1 != 0) {
        // 0x800384CC: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800384A0;
    }
    goto skip_2;
    // 0x800384CC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800384D0:
    // 0x800384D0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800384D4:
    // 0x800384D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800384D8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800384DC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800384E0: bnel        $at, $zero, L_8003844C
    if (ctx->r1 != 0) {
        // 0x800384E4: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_8003844C;
    }
    goto skip_3;
    // 0x800384E4: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800384E8:
    // 0x800384E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800384EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800384F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800384F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800384F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800384FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80038500: jr          $ra
    // 0x80038504: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80038504: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000BD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000BD14: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000BD18: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000BD1C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000BD20: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000BD24: addiu       $s3, $s3, 0x4F18
    ctx->r19 = ADD32(ctx->r19, 0X4F18);
    // 0x8000BD28: addiu       $s1, $s1, 0x4EE4
    ctx->r17 = ADD32(ctx->r17, 0X4EE4);
    // 0x8000BD2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000BD30: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000BD34: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000BD38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000BD3C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000BD40: lw          $v0, 0x4EEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EEC);
    // 0x8000BD44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000BD48: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8000BD4C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8000BD50: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8000BD54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000BD58: addiu       $t7, $t7, 0x4F10
    ctx->r15 = ADD32(ctx->r15, 0X4F10);
    // 0x8000BD5C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000BD60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BD64: beq         $a0, $at, L_8000BEB4
    if (ctx->r4 == ctx->r1) {
        // 0x8000BD68: sw          $t8, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r24;
            goto L_8000BEB4;
    }
    // 0x8000BD68: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8000BD6C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8000BD70: bne         $v0, $at, L_8000BDBC
    if (ctx->r2 != ctx->r1) {
        // 0x8000BD74: lui         $t9, 0x8008
        ctx->r25 = S32(0X8008 << 16);
            goto L_8000BDBC;
    }
    // 0x8000BD74: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000BD78: lw          $t9, 0x4EE8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4EE8);
    // 0x8000BD7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000BD80: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BD84: bne         $t9, $at, L_8000BEB4
    if (ctx->r25 != ctx->r1) {
        // 0x8000BD88: nop
    
            goto L_8000BEB4;
    }
    // 0x8000BD88: nop

    // 0x8000BD8C: lw          $v1, 0x4EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4EF0);
    // 0x8000BD90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BD94: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000BD98: bne         $v1, $zero, L_8000BEB4
    if (ctx->r3 != 0) {
        // 0x8000BD9C: nop
    
            goto L_8000BEB4;
    }
    // 0x8000BD9C: nop

    // 0x8000BDA0: sw          $v0, 0x4EF8($at)
    MEM_W(0X4EF8, ctx->r1) = ctx->r2;
    // 0x8000BDA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BDA8: lw          $t0, 0x5370($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5370);
    // 0x8000BDAC: sw          $v1, 0x4EFC($at)
    MEM_W(0X4EFC, ctx->r1) = ctx->r3;
    // 0x8000BDB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BDB4: b           L_8000BEB4
    // 0x8000BDB8: sw          $t0, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r8;
        goto L_8000BEB4;
    // 0x8000BDB8: sw          $t0, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r8;
L_8000BDBC:
    // 0x8000BDBC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000BDC0: bne         $v0, $at, L_8000BDF4
    if (ctx->r2 != ctx->r1) {
        // 0x8000BDC4: lui         $s2, 0x8008
        ctx->r18 = S32(0X8008 << 16);
            goto L_8000BDF4;
    }
    // 0x8000BDC4: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000BDC8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000BDCC: lw          $t1, 0x4EF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4EF0);
    // 0x8000BDD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BDD4: sw          $v0, 0x4EF8($at)
    MEM_W(0X4EF8, ctx->r1) = ctx->r2;
    // 0x8000BDD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BDDC: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000BDE0: lw          $t2, 0x5370($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5370);
    // 0x8000BDE4: sw          $t1, 0x4EFC($at)
    MEM_W(0X4EFC, ctx->r1) = ctx->r9;
    // 0x8000BDE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BDEC: b           L_8000BEB4
    // 0x8000BDF0: sw          $t2, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r10;
        goto L_8000BEB4;
    // 0x8000BDF0: sw          $t2, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r10;
L_8000BDF4:
    // 0x8000BDF4: addiu       $s2, $s2, 0x4EE0
    ctx->r18 = ADD32(ctx->r18, 0X4EE0);
    // 0x8000BDF8: lhu         $t3, 0x0($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X0);
    // 0x8000BDFC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8000BE00: beq         $t4, $zero, L_8000BE48
    if (ctx->r12 == 0) {
        // 0x8000BE04: nop
    
            goto L_8000BE48;
    }
    // 0x8000BE04: nop

    // 0x8000BE08: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8000BE0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BE10: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000BE14: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000BE18: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000BE1C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8000BE20: beq         $t7, $zero, L_8000BE48
    if (ctx->r15 == 0) {
        // 0x8000BE24: nop
    
            goto L_8000BE48;
    }
    // 0x8000BE24: nop

    // 0x8000BE28: lw          $t8, 0x4EF0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4EF0);
    // 0x8000BE2C: sw          $v0, 0x4EF8($at)
    MEM_W(0X4EF8, ctx->r1) = ctx->r2;
    // 0x8000BE30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BE34: lw          $t9, 0x5370($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5370);
    // 0x8000BE38: sw          $t8, 0x4EFC($at)
    MEM_W(0X4EFC, ctx->r1) = ctx->r24;
    // 0x8000BE3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BE40: b           L_8000BEB4
    // 0x8000BE44: sw          $t9, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r25;
        goto L_8000BEB4;
    // 0x8000BE44: sw          $t9, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r25;
L_8000BE48:
    // 0x8000BE48: beq         $a0, $v0, L_8000BEB4
    if (ctx->r4 == ctx->r2) {
        // 0x8000BE4C: nop
    
            goto L_8000BEB4;
    }
    // 0x8000BE4C: nop

    // 0x8000BE50: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8000BE54: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BE58: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000BE5C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000BE60: addiu       $a1, $a1, 0x4F08
    ctx->r5 = ADD32(ctx->r5, 0X4F08);
    // 0x8000BE64: addiu       $v1, $v1, 0x4F04
    ctx->r3 = ADD32(ctx->r3, 0X4F04);
    // 0x8000BE68: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8000BE6C: beq         $t2, $zero, L_8000BEB4
    if (ctx->r10 == 0) {
        // 0x8000BE70: lui         $a2, 0x8008
        ctx->r6 = S32(0X8008 << 16);
            goto L_8000BEB4;
    }
    // 0x8000BE70: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000BE74: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000BE78: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8000BE7C: lw          $t3, 0x4EF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4EF0);
    // 0x8000BE80: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000BE84: addiu       $a2, $a2, 0x4F0C
    ctx->r6 = ADD32(ctx->r6, 0X4F0C);
    // 0x8000BE88: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8000BE8C: lw          $t4, 0x5370($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5370);
    // 0x8000BE90: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8000BE94: bne         $v0, $at, L_8000BEB4
    if (ctx->r2 != ctx->r1) {
        // 0x8000BE98: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_8000BEB4;
    }
    // 0x8000BE98: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8000BE9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000BEA0: bne         $t3, $at, L_8000BEB4
    if (ctx->r11 != ctx->r1) {
        // 0x8000BEA4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8000BEB4;
    }
    // 0x8000BEA4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8000BEA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000BEAC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000BEB0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8000BEB4:
    // 0x8000BEB4: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000BEB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BEBC: bne         $a0, $at, L_8000BF20
    if (ctx->r4 != ctx->r1) {
        // 0x8000BEC0: addiu       $s2, $s2, 0x4EE0
        ctx->r18 = ADD32(ctx->r18, 0X4EE0);
            goto L_8000BF20;
    }
    // 0x8000BEC0: addiu       $s2, $s2, 0x4EE0
    ctx->r18 = ADD32(ctx->r18, 0X4EE0);
    // 0x8000BEC4: lui         $a0, 0x7
    ctx->r4 = S32(0X7 << 16);
    // 0x8000BEC8: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8000BECC: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    // 0x8000BED0: addiu       $t9, $t9, 0x7360
    ctx->r25 = ADD32(ctx->r25, 0X7360);
    // 0x8000BED4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8000BED8: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x8000BEDC: jal         0x80024260
    // 0x8000BEE0: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x8000BEE0: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    after_0:
    // 0x8000BEE4: lui         $a0, 0xD9
    ctx->r4 = S32(0XD9 << 16);
    // 0x8000BEE8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000BEEC: addiu       $a1, $a1, 0x20D8
    ctx->r5 = ADD32(ctx->r5, 0X20D8);
    // 0x8000BEF0: addiu       $a0, $a0, -0x7B10
    ctx->r4 = ADD32(ctx->r4, -0X7B10);
    // 0x8000BEF4: jal         0x80024260
    // 0x8000BEF8: addiu       $a2, $zero, 0x600
    ctx->r6 = ADD32(0, 0X600);
    dma_write(rdram, ctx);
        goto after_1;
    // 0x8000BEF8: addiu       $a2, $zero, 0x600
    ctx->r6 = ADD32(0, 0X600);
    after_1:
    // 0x8000BEFC: lui         $a0, 0xD9
    ctx->r4 = S32(0XD9 << 16);
    // 0x8000BF00: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000BF04: addiu       $a1, $a1, 0x26D8
    ctx->r5 = ADD32(ctx->r5, 0X26D8);
    // 0x8000BF08: addiu       $a0, $a0, -0x7510
    ctx->r4 = ADD32(ctx->r4, -0X7510);
    // 0x8000BF0C: jal         0x80024260
    // 0x8000BF10: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    dma_write(rdram, ctx);
        goto after_2;
    // 0x8000BF10: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_2:
    // 0x8000BF14: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000BF18: lw          $v0, 0x4EEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EEC);
    // 0x8000BF1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_8000BF20:
    // 0x8000BF20: beq         $v0, $a0, L_8000C004
    if (ctx->r2 == ctx->r4) {
        // 0x8000BF24: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8000C004;
    }
    // 0x8000BF24: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BF28: sw          $a0, 0x4EF4($at)
    MEM_W(0X4EF4, ctx->r1) = ctx->r4;
    // 0x8000BF2C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8000BF30: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000BF34: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x8000BF38: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // 0x8000BF3C: andi        $t1, $v1, 0x7
    ctx->r9 = ctx->r3 & 0X7;
    // 0x8000BF40: beq         $t1, $zero, L_8000BFAC
    if (ctx->r9 == 0) {
        // 0x8000BF44: sh          $t0, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r8;
            goto L_8000BFAC;
    }
    // 0x8000BF44: sh          $t0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r8;
    // 0x8000BF48: andi        $t2, $v1, 0x2
    ctx->r10 = ctx->r3 & 0X2;
    // 0x8000BF4C: beq         $t2, $zero, L_8000BF74
    if (ctx->r10 == 0) {
        // 0x8000BF50: lui         $a0, 0x8
        ctx->r4 = S32(0X8 << 16);
            goto L_8000BF74;
    }
    // 0x8000BF50: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x8000BF54: lui         $t3, 0xD
    ctx->r11 = S32(0XD << 16);
    // 0x8000BF58: addiu       $a0, $a0, 0x7360
    ctx->r4 = ADD32(ctx->r4, 0X7360);
    // 0x8000BF5C: addiu       $t3, $t3, -0x50B0
    ctx->r11 = ADD32(ctx->r11, -0X50B0);
    // 0x8000BF60: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8000BF64: addiu       $a1, $a1, -0x200
    ctx->r5 = ADD32(ctx->r5, -0X200);
    // 0x8000BF68: jal         0x80024260
    // 0x8000BF6C: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    dma_write(rdram, ctx);
        goto after_3;
    // 0x8000BF6C: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    after_3:
    // 0x8000BF70: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_8000BF74:
    // 0x8000BF74: lw          $t4, 0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X3C);
    // 0x8000BF78: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8000BF7C: addiu       $t7, $t7, 0x58A0
    ctx->r15 = ADD32(ctx->r15, 0X58A0);
    // 0x8000BF80: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000BF84: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8000BF88: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000BF8C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000BF90: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8000BF94: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8000BF98: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000BF9C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8000BFA0: jal         0x80024260
    // 0x8000BFA4: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    dma_write(rdram, ctx);
        goto after_4;
    // 0x8000BFA4: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    after_4:
    // 0x8000BFA8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_8000BFAC:
    // 0x8000BFAC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000BFB0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000BFB4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8000BFB8: jal         0x80024260
    // 0x8000BFBC: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    dma_write(rdram, ctx);
        goto after_5;
    // 0x8000BFBC: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    after_5:
    // 0x8000BFC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000BFC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000BFC8: lui         $a0, 0x3E
    ctx->r4 = S32(0X3E << 16);
    // 0x8000BFCC: beq         $v0, $at, L_8000BFEC
    if (ctx->r2 == ctx->r1) {
        // 0x8000BFD0: addiu       $a0, $a0, 0x3200
        ctx->r4 = ADD32(ctx->r4, 0X3200);
            goto L_8000BFEC;
    }
    // 0x8000BFD0: addiu       $a0, $a0, 0x3200
    ctx->r4 = ADD32(ctx->r4, 0X3200);
    // 0x8000BFD4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000BFD8: beq         $v0, $at, L_8000BFEC
    if (ctx->r2 == ctx->r1) {
        // 0x8000BFDC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8000BFEC;
    }
    // 0x8000BFDC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000BFE0: beq         $v0, $at, L_8000BFEC
    if (ctx->r2 == ctx->r1) {
        // 0x8000BFE4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8000BFEC;
    }
    // 0x8000BFE4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8000BFE8: bne         $v0, $at, L_8000C004
    if (ctx->r2 != ctx->r1) {
        // 0x8000BFEC: lui         $t9, 0x3F
        ctx->r25 = S32(0X3F << 16);
            goto L_8000C004;
    }
L_8000BFEC:
    // 0x8000BFEC: lui         $t9, 0x3F
    ctx->r25 = S32(0X3F << 16);
    // 0x8000BFF0: addiu       $t9, $t9, 0x3D10
    ctx->r25 = ADD32(ctx->r25, 0X3D10);
    // 0x8000BFF4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8000BFF8: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x8000BFFC: jal         0x80024260
    // 0x8000C000: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    dma_write(rdram, ctx);
        goto after_6;
    // 0x8000C000: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    after_6:
L_8000C004:
    // 0x8000C004: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000C008: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C00C: addiu       $s1, $zero, 0x65
    ctx->r17 = ADD32(0, 0X65);
    // 0x8000C010: addiu       $v0, $v0, 0x27A0
    ctx->r2 = ADD32(ctx->r2, 0X27A0);
    // 0x8000C014: addiu       $v1, $v1, 0x27A2
    ctx->r3 = ADD32(ctx->r3, 0X27A2);
L_8000C018:
    // 0x8000C018: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8000C01C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000C020: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8000C024: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8000C028: bne         $s1, $zero, L_8000C018
    if (ctx->r17 != 0) {
        // 0x8000C02C: sh          $t0, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r8;
            goto L_8000C018;
    }
    // 0x8000C02C: sh          $t0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r8;
    // 0x8000C030: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000C034: lw          $t1, 0x4EF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4EF0);
    // 0x8000C038: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C03C: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000C040: sw          $t1, 0x4EE8($at)
    MEM_W(0X4EE8, ctx->r1) = ctx->r9;
    // 0x8000C044: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8000C048: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8000C04C: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8000C050: lw          $t2, 0x18($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18);
    // 0x8000C054: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8000C058: addiu       $s2, $s2, 0x4F1C
    ctx->r18 = ADD32(ctx->r18, 0X4F1C);
    // 0x8000C05C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000C060: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8000C064: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x8000C068: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C06C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C070: sw          $t5, 0x4F28($at)
    MEM_W(0X4F28, ctx->r1) = ctx->r13;
    // 0x8000C074: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8000C078: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8000C07C: addiu       $a1, $a1, 0x4F20
    ctx->r5 = ADD32(ctx->r5, 0X4F20);
    // 0x8000C080: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8000C084: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000C088: addiu       $a2, $a2, 0x59E4
    ctx->r6 = ADD32(ctx->r6, 0X59E4);
    // 0x8000C08C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000C090: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000C094: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000C098: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000C09C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000C0A0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x8000C0A4: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8000C0A8: lhu         $t1, 0x2($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2);
    // 0x8000C0AC: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x8000C0B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C0B4: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8000C0B8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8000C0BC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8000C0C0: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8000C0C4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000C0C8: addiu       $s1, $s1, 0x4F14
    ctx->r17 = ADD32(ctx->r17, 0X4F14);
    // 0x8000C0CC: sw          $t4, 0x4F24($at)
    MEM_W(0X4F24, ctx->r1) = ctx->r12;
    // 0x8000C0D0: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x8000C0D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C0D8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C0DC: sw          $t5, 0x4F2C($at)
    MEM_W(0X4F2C, ctx->r1) = ctx->r13;
    // 0x8000C0E0: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x8000C0E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C0E8: lui         $s0, 0x8006
    ctx->r16 = S32(0X8006 << 16);
    // 0x8000C0EC: sw          $t7, 0x4F30($at)
    MEM_W(0X4F30, ctx->r1) = ctx->r15;
    // 0x8000C0F0: lhu         $t6, 0x14($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X14);
    // 0x8000C0F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C0F8: addiu       $s0, $s0, -0x1058
    ctx->r16 = ADD32(ctx->r16, -0X1058);
    // 0x8000C0FC: sh          $t6, 0x4F10($at)
    MEM_H(0X4F10, ctx->r1) = ctx->r14;
    // 0x8000C100: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000C104: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C108: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x8000C10C: lhu         $t8, 0x18($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X18);
    // 0x8000C110: addiu       $a1, $a1, 0x14D8
    ctx->r5 = ADD32(ctx->r5, 0X14D8);
    // 0x8000C114: sh          $t8, 0x4F12($at)
    MEM_H(0X4F12, ctx->r1) = ctx->r24;
    // 0x8000C118: lw          $a3, 0x1C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X1C);
    // 0x8000C11C: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x8000C120: andi        $t1, $a3, 0xFFFF
    ctx->r9 = ctx->r7 & 0XFFFF;
    // 0x8000C124: beq         $a3, $t9, L_8000C168
    if (ctx->r7 == ctx->r25) {
        // 0x8000C128: sll         $t0, $t1, 3
        ctx->r8 = S32(ctx->r9 << 3);
            goto L_8000C168;
    }
    // 0x8000C128: sll         $t0, $t1, 3
    ctx->r8 = S32(ctx->r9 << 3);
    // 0x8000C12C: addu        $t2, $s0, $t0
    ctx->r10 = ADD32(ctx->r16, ctx->r8);
    // 0x8000C130: sh          $a3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r7;
    // 0x8000C134: jal         0x80024260
    // 0x8000C138: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    dma_write(rdram, ctx);
        goto after_7;
    // 0x8000C138: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_7:
    // 0x8000C13C: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
    // 0x8000C140: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C144: addiu       $a1, $a1, -0x2D28
    ctx->r5 = ADD32(ctx->r5, -0X2D28);
    // 0x8000C148: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8000C14C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8000C150: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8000C154: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    // 0x8000C158: jal         0x80024260
    // 0x8000C15C: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    dma_write(rdram, ctx);
        goto after_8;
    // 0x8000C15C: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_8:
    // 0x8000C160: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000C164: lw          $a0, 0x4F20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4F20);
L_8000C168:
    // 0x8000C168: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C16C: lw          $v1, 0x5370($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5370);
    // 0x8000C170: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C174: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000C178: beq         $v1, $at, L_8000C1C8
    if (ctx->r3 == ctx->r1) {
        // 0x8000C17C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8000C1C8;
    }
    // 0x8000C17C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000C180: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8000C184: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8000C188: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8000C18C: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x8000C190: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000C194: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C198: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8000C19C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000C1A0: swc1        $f4, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f4.u32l;
    // 0x8000C1A4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000C1A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C1AC: swc1        $f6, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f6.u32l;
    // 0x8000C1B0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000C1B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C1B8: swc1        $f8, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f8.u32l;
    // 0x8000C1BC: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8000C1C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C1C4: sw          $t9, -0x45B0($at)
    MEM_W(-0X45B0, ctx->r1) = ctx->r25;
L_8000C1C8:
    // 0x8000C1C8: lhu         $s1, 0x0($a0)
    ctx->r17 = MEM_HU(ctx->r4, 0X0);
    // 0x8000C1CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C1D0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000C1D4: lw          $s0, 0x4F24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4F24);
    // 0x8000C1D8: sw          $zero, 0x4F38($at)
    MEM_W(0X4F38, ctx->r1) = 0;
    // 0x8000C1DC: beq         $s1, $zero, L_8000C2C0
    if (ctx->r17 == 0) {
        // 0x8000C1E0: addiu       $s2, $s2, 0x4260
        ctx->r18 = ADD32(ctx->r18, 0X4260);
            goto L_8000C2C0;
    }
    // 0x8000C1E0: addiu       $s2, $s2, 0x4260
    ctx->r18 = ADD32(ctx->r18, 0X4260);
    // 0x8000C1E4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000C1E8: addiu       $s3, $s3, 0x2C28
    ctx->r19 = ADD32(ctx->r19, 0X2C28);
L_8000C1EC:
    // 0x8000C1EC: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x8000C1F0: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x8000C1F4: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x8000C1F8: beql        $t1, $zero, L_8000C224
    if (ctx->r9 == 0) {
        // 0x8000C1FC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_8000C224;
    }
    goto skip_0;
    // 0x8000C1FC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    skip_0:
    // 0x8000C200: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000C204: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000C208: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8000C20C: jal         0x8000EE60
    // 0x8000C210: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8000EE60(rdram, ctx);
        goto after_9;
    // 0x8000C210: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_9:
    // 0x8000C214: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8000C218: lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X16);
    // 0x8000C21C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8000C220: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_8000C224:
    // 0x8000C224: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8000C228: bnel        $v1, $at, L_8000C264
    if (ctx->r3 != ctx->r1) {
        // 0x8000C22C: addiu       $at, $zero, 0x83
        ctx->r1 = ADD32(0, 0X83);
            goto L_8000C264;
    }
    goto skip_1;
    // 0x8000C22C: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    skip_1:
    // 0x8000C230: lwc1        $f16, 0xC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000C234: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x8000C238: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000C23C: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x8000C240: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000C244: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000C248: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8000C24C: swc1        $f18, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->f18.u32l;
    // 0x8000C250: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000C254: swc1        $f4, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f4.u32l;
    // 0x8000C258: b           L_8000C2B4
    // 0x8000C25C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8000C2B4;
    // 0x8000C25C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8000C260: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
L_8000C264:
    // 0x8000C264: bnel        $v1, $at, L_8000C278
    if (ctx->r3 != ctx->r1) {
        // 0x8000C268: addiu       $at, $zero, 0x84
        ctx->r1 = ADD32(0, 0X84);
            goto L_8000C278;
    }
    goto skip_2;
    // 0x8000C268: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    skip_2:
    // 0x8000C26C: b           L_8000C2B4
    // 0x8000C270: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
        goto L_8000C2B4;
    // 0x8000C270: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x8000C274: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
L_8000C278:
    // 0x8000C278: bnel        $v1, $at, L_8000C298
    if (ctx->r3 != ctx->r1) {
        // 0x8000C27C: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_8000C298;
    }
    goto skip_3;
    // 0x8000C27C: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    skip_3:
    // 0x8000C280: jal         0x80022FD0
    // 0x8000C284: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    get_rand(rdram, ctx);
        goto after_10;
    // 0x8000C284: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_10:
    // 0x8000C288: addiu       $t0, $v0, 0x96
    ctx->r8 = ADD32(ctx->r2, 0X96);
    // 0x8000C28C: b           L_8000C2B4
    // 0x8000C290: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
        goto L_8000C2B4;
    // 0x8000C290: sh          $t0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r8;
    // 0x8000C294: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
L_8000C298:
    // 0x8000C298: bne         $at, $zero, L_8000C2B4
    if (ctx->r1 != 0) {
        // 0x8000C29C: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8000C2B4;
    }
    // 0x8000C29C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8000C2A0: beql        $at, $zero, L_8000C2B8
    if (ctx->r1 == 0) {
        // 0x8000C2A4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8000C2B8;
    }
    goto skip_4;
    // 0x8000C2A4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_4:
    // 0x8000C2A8: jal         0x80022FD0
    // 0x8000C2AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    get_rand(rdram, ctx);
        goto after_11;
    // 0x8000C2AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8000C2B0: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
L_8000C2B4:
    // 0x8000C2B4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8000C2B8:
    // 0x8000C2B8: bne         $s1, $zero, L_8000C1EC
    if (ctx->r17 != 0) {
        // 0x8000C2BC: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_8000C1EC;
    }
    // 0x8000C2BC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_8000C2C0:
    // 0x8000C2C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000C2C4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C2C8: addiu       $v1, $v1, 0x2C80
    ctx->r3 = ADD32(ctx->r3, 0X2C80);
    // 0x8000C2CC: addiu       $v0, $v0, 0x2C70
    ctx->r2 = ADD32(ctx->r2, 0X2C70);
L_8000C2D0:
    // 0x8000C2D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000C2D4: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000C2D8: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x8000C2DC: bne         $at, $zero, L_8000C2D0
    if (ctx->r1 != 0) {
        // 0x8000C2E0: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_8000C2D0;
    }
    // 0x8000C2E0: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
    // 0x8000C2E4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000C2E8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C2EC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000C2F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C2F4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000C2F8: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000C2FC: addiu       $v0, $v0, -0x3D08
    ctx->r2 = ADD32(ctx->r2, -0X3D08);
    // 0x8000C300: addiu       $a3, $a3, 0x2C58
    ctx->r7 = ADD32(ctx->r7, 0X2C58);
    // 0x8000C304: addiu       $v1, $v1, 0x2958
    ctx->r3 = ADD32(ctx->r3, 0X2958);
    // 0x8000C308: addiu       $a2, $a2, 0x2940
    ctx->r6 = ADD32(ctx->r6, 0X2940);
    // 0x8000C30C: addiu       $a1, $a1, 0x2928
    ctx->r5 = ADD32(ctx->r5, 0X2928);
    // 0x8000C310: addiu       $a0, $a0, 0x2910
    ctx->r4 = ADD32(ctx->r4, 0X2910);
L_8000C314:
    // 0x8000C314: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x8000C318: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8000C31C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8000C320: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8000C324: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x8000C328: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8000C32C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8000C330: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x8000C334: lw          $at, 0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X10);
    // 0x8000C338: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x8000C33C: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8000C340: sw          $at, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r1;
    // 0x8000C344: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x8000C348: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    // 0x8000C34C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8000C350: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8000C354: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x8000C358: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8000C35C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000C360: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8000C364: lw          $at, 0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X10);
    // 0x8000C368: sw          $t5, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r13;
    // 0x8000C36C: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8000C370: sw          $at, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r1;
    // 0x8000C374: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x8000C378: sw          $t5, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r13;
    // 0x8000C37C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8000C380: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x8000C384: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x8000C388: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8000C38C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8000C390: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
    // 0x8000C394: lw          $at, 0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X10);
    // 0x8000C398: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x8000C39C: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8000C3A0: sw          $at, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r1;
    // 0x8000C3A4: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x8000C3A8: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x8000C3AC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000C3B0: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x8000C3B4: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x8000C3B8: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8000C3BC: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x8000C3C0: sw          $at, -0x58($v1)
    MEM_W(-0X58, ctx->r3) = ctx->r1;
    // 0x8000C3C4: sw          $t9, -0x54($v1)
    MEM_W(-0X54, ctx->r3) = ctx->r25;
    // 0x8000C3C8: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8000C3CC: lw          $at, 0x10($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X10);
    // 0x8000C3D0: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // 0x8000C3D4: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x8000C3D8: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    // 0x8000C3DC: sw          $t9, -0x4C($v1)
    MEM_W(-0X4C, ctx->r3) = ctx->r25;
    // 0x8000C3E0: bne         $v1, $a3, L_8000C314
    if (ctx->r3 != ctx->r7) {
        // 0x8000C3E4: sw          $at, -0x50($v1)
        MEM_W(-0X50, ctx->r3) = ctx->r1;
            goto L_8000C314;
    }
    // 0x8000C3E4: sw          $at, -0x50($v1)
    MEM_W(-0X50, ctx->r3) = ctx->r1;
    // 0x8000C3E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000C3EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C3F0: jal         0x8000DB10
    // 0x8000C3F4: sw          $t1, 0x2908($at)
    MEM_W(0X2908, ctx->r1) = ctx->r9;
    func_8000DB10(rdram, ctx);
        goto after_12;
    // 0x8000C3F4: sw          $t1, 0x2908($at)
    MEM_W(0X2908, ctx->r1) = ctx->r9;
    after_12:
    // 0x8000C3F8: jal         0x8000E3C4
    // 0x8000C3FC: nop

    func_8000E3C4(rdram, ctx);
        goto after_13;
    // 0x8000C3FC: nop

    after_13:
    // 0x8000C400: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8000C404: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C408: sw          $t0, 0x4EDC($at)
    MEM_W(0X4EDC, ctx->r1) = ctx->r8;
    // 0x8000C40C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000C410: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000C414: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000C418: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000C41C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C420: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000C424: jr          $ra
    // 0x8000C428: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000C428: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80025040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80025048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002504C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80025050: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80025054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80025058: addiu       $a2, $a2, -0xDC0
    ctx->r6 = ADD32(ctx->r6, -0XDC0);
    // 0x8002505C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80025064: jal         0x80036660
    // 0x80025068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80025068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8002506C: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80025070: addiu       $v1, $v1, 0x38F0
    ctx->r3 = ADD32(ctx->r3, 0X38F0);
    // 0x80025074: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80025078: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002507C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025080: jal         0x80024690
    // 0x80025084: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80024690(rdram, ctx);
        goto after_1;
    // 0x80025084: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80025088: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002508C: lw          $t7, 0x38F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38F0);
    // 0x80025090: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80025094: addiu       $a2, $a2, -0xDC0
    ctx->r6 = ADD32(ctx->r6, -0XDC0);
    // 0x80025098: lh          $v0, 0x2($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2);
    // 0x8002509C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800250A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800250A4: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800250A8: addiu       $v0, $t8, 0x4
    ctx->r2 = ADD32(ctx->r24, 0X4);
    // 0x800250AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800250B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800250B4: jal         0x80036660
    // 0x800250B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800250B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800250BC: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800250C0: addiu       $v1, $v1, 0x38F0
    ctx->r3 = ADD32(ctx->r3, 0X38F0);
    // 0x800250C4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800250C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800250CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800250D0: jal         0x80024690
    // 0x800250D4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80024690(rdram, ctx);
        goto after_3;
    // 0x800250D4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800250D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800250DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800250E0: jr          $ra
    // 0x800250E4: nop

    return;
    // 0x800250E4: nop

;}
RECOMP_FUNC void func_8002387C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002387C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80023880: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80023884: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80023888: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002388C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80023890: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80023894: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023898: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002389C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800238A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800238A4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800238A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800238AC: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x800238B0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800238B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800238B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800238BC: jal         0x8002371C
    // 0x800238C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_8002371C(rdram, ctx);
        goto after_0;
    // 0x800238C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800238C4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800238C8: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x800238CC: jal         0x80035200
    // 0x800238D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800238D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800238D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800238D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800238DC: jr          $ra
    // 0x800238E0: nop

    return;
    // 0x800238E0: nop

;}
RECOMP_FUNC void func_8002413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002413C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80024140: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024144: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80024148: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8002414C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80024150: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80024154: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80024158: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8002415C: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80024160: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80024164: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80024168: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002416C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80024170: addiu       $a0, $a0, 0x6E88
    ctx->r4 = ADD32(ctx->r4, 0X6E88);
    // 0x80024174: jal         0x80035470
    // 0x80024178: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_80035470(rdram, ctx);
        goto after_0;
    // 0x80024178: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8002417C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80024180: lwc1        $f6, 0x6ECC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6ECC);
    // 0x80024184: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80024188: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002418C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80024190: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80024194: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80024198: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8002419C: bc1f        L_800241A8
    if (!c1cs) {
        // 0x800241A0: nop
    
            goto L_800241A8;
    }
    // 0x800241A0: nop

    // 0x800241A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800241A8:
    // 0x800241A8: beql        $v1, $zero, L_80024244
    if (ctx->r3 == 0) {
        // 0x800241AC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80024244;
    }
    goto skip_0;
    // 0x800241AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800241B0: lwc1        $f10, 0x6ED4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6ED4);
    // 0x800241B4: lui         $at, 0x4064
    ctx->r1 = S32(0X4064 << 16);
    // 0x800241B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800241BC: mul.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800241C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800241C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800241C8: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800241CC: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800241D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800241D4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800241D8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800241DC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800241E0: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x800241E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800241E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800241EC: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800241F0: mul.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800241F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800241F8: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800241FC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80024200: nop

    // 0x80024204: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80024208: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8002420C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80024210: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80024214: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80024218: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8002421C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80024220: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80024224: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80024228: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8002422C: nop

    // 0x80024230: addiu       $t6, $t5, 0x78
    ctx->r14 = ADD32(ctx->r13, 0X78);
    // 0x80024234: bc1f        L_80024240
    if (!c1cs) {
        // 0x80024238: sw          $t6, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r14;
            goto L_80024240;
    }
    // 0x80024238: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002423C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80024240:
    // 0x80024240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80024244:
    // 0x80024244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024248: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002424C: jr          $ra
    // 0x80024250: nop

    return;
    // 0x80024250: nop

    // 0x80024254: nop

    // 0x80024258: nop

    // 0x8002425C: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049E60: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x80049E64: mflo        $v0
    ctx->r2 = lo;
    // 0x80049E68: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80049E6C: bne         $a2, $zero, L_80049E78
    if (ctx->r6 != 0) {
        // 0x80049E70: nop
    
            goto L_80049E78;
    }
    // 0x80049E70: nop

    // 0x80049E74: break       7
    do_break(2147786356);
L_80049E78:
    // 0x80049E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80049E7C: bne         $a2, $at, L_80049E90
    if (ctx->r6 != ctx->r1) {
        // 0x80049E80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80049E90;
    }
    // 0x80049E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80049E84: bne         $a1, $at, L_80049E90
    if (ctx->r5 != ctx->r1) {
        // 0x80049E88: nop
    
            goto L_80049E90;
    }
    // 0x80049E88: nop

    // 0x80049E8C: break       6
    do_break(2147786380);
L_80049E90:
    // 0x80049E90: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049E94: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80049E98: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x80049E9C: mflo        $t6
    ctx->r14 = lo;
    // 0x80049EA0: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80049EA4: bgez        $v0, L_80049EC8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80049EA8: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80049EC8;
    }
    // 0x80049EA8: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80049EAC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80049EB0: blez        $v1, L_80049EC8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80049EB4: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80049EC8;
    }
    // 0x80049EB4: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80049EB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80049EBC: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80049EC0: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80049EC4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_80049EC8:
    // 0x80049EC8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80049ECC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80049ED0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80049ED4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80049ED8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80049EDC: jr          $ra
    // 0x80049EE0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x80049EE0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_80018918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018918: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001891C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018920: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80018924: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80018928: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001892C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018930: lw          $v0, -0x4D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D0C);
    // 0x80018934: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018938: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001893C: beq         $v0, $zero, L_80018950
    if (ctx->r2 == 0) {
        // 0x80018940: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80018950;
    }
    // 0x80018940: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80018944: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018948: b           L_80018954
    // 0x8001894C: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
        goto L_80018954;
    // 0x8001894C: addiu       $a1, $a1, 0x7250
    ctx->r5 = ADD32(ctx->r5, 0X7250);
L_80018950:
    // 0x80018950: addiu       $a1, $a1, 0x7310
    ctx->r5 = ADD32(ctx->r5, 0X7310);
L_80018954:
    // 0x80018954: beq         $v0, $zero, L_80018968
    if (ctx->r2 == 0) {
        // 0x80018958: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_80018968;
    }
    // 0x80018958: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001895C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018960: b           L_8001896C
    // 0x80018964: addiu       $v1, $v1, 0x7310
    ctx->r3 = ADD32(ctx->r3, 0X7310);
        goto L_8001896C;
    // 0x80018964: addiu       $v1, $v1, 0x7310
    ctx->r3 = ADD32(ctx->r3, 0X7310);
L_80018968:
    // 0x80018968: addiu       $v1, $v1, 0x7250
    ctx->r3 = ADD32(ctx->r3, 0X7250);
L_8001896C:
    // 0x8001896C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018970: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80018974: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018978: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001897C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80018980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80018984: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80018988: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001898C: jal         0x80023210
    // 0x80018990: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80018990: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80018994: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018998: ldc1        $f14, 0x1548($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1548);
    // 0x8001899C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800189A0: lwc1        $f16, 0x6DEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6DEC);
    // 0x800189A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800189A8: ldc1        $f8, 0x1550($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1550);
    // 0x800189AC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800189B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800189B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800189B8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800189BC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800189C0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800189C4: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x800189C8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800189CC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800189D0: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x800189D4: nop

    // 0x800189D8: bc1fl       L_800189F8
    if (!c1cs) {
        // 0x800189DC: c.lt.d      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
            goto L_800189F8;
    }
    goto skip_0;
    // 0x800189DC: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    skip_0:
    // 0x800189E0: ldc1        $f10, 0x1558($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1558);
    // 0x800189E4: add.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f2.d + ctx->f10.d;
    // 0x800189E8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x800189EC: b           L_80018A14
    // 0x800189F0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_80018A14;
    // 0x800189F0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800189F4: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
L_800189F8:
    // 0x800189F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800189FC: bc1f        L_80018A14
    if (!c1cs) {
        // 0x80018A00: nop
    
            goto L_80018A14;
    }
    // 0x80018A00: nop

    // 0x80018A04: ldc1        $f18, 0x1560($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1560);
    // 0x80018A08: sub.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d - ctx->f18.d;
    // 0x80018A0C: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80018A10: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80018A14:
    // 0x80018A14: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018A18: ldc1        $f6, 0x1568($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1568);
    // 0x80018A1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018A20: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80018A24: nop

    // 0x80018A28: bc1fl       L_80018B08
    if (!c1cs) {
        // 0x80018A2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018B08;
    }
    goto skip_1;
    // 0x80018A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80018A30: ldc1        $f8, 0x1570($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1570);
    // 0x80018A34: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80018A38: addiu       $a2, $a2, 0x7200
    ctx->r6 = ADD32(ctx->r6, 0X7200);
    // 0x80018A3C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x80018A40: nop

    // 0x80018A44: bc1fl       L_80018B08
    if (!c1cs) {
        // 0x80018A48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018B08;
    }
    goto skip_2;
    // 0x80018A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80018A4C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80018A50: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018A54: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80018A58: beq         $at, $zero, L_80018B04
    if (ctx->r1 == 0) {
        // 0x80018A5C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80018B04;
    }
    // 0x80018A5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80018A60: lw          $v0, 0x7208($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7208);
    // 0x80018A64: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80018A68: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80018A6C: beq         $v0, $zero, L_80018A98
    if (ctx->r2 == 0) {
        // 0x80018A70: addu        $a1, $a1, $t6
        ctx->r5 = ADD32(ctx->r5, ctx->r14);
            goto L_80018A98;
    }
    // 0x80018A70: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80018A74: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x80018A78: beq         $a3, $t7, L_80018A98
    if (ctx->r7 == ctx->r15) {
        // 0x80018A7C: nop
    
            goto L_80018A98;
    }
    // 0x80018A7C: nop

    // 0x80018A80: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80018A84:
    // 0x80018A84: beq         $v0, $zero, L_80018A98
    if (ctx->r2 == 0) {
        // 0x80018A88: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80018A98;
    }
    // 0x80018A88: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80018A8C: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x80018A90: bnel        $a3, $t8, L_80018A84
    if (ctx->r7 != ctx->r24) {
        // 0x80018A94: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80018A84;
    }
    goto skip_3;
    // 0x80018A94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_3:
L_80018A98:
    // 0x80018A98: beq         $v0, $zero, L_80018AAC
    if (ctx->r2 == 0) {
        // 0x80018A9C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80018AAC;
    }
    // 0x80018A9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80018AA0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80018AA4: b           L_80018AD4
    // 0x80018AA8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_80018AD4;
    // 0x80018AA8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_80018AAC:
    // 0x80018AAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80018AB0: jal         0x80022FD0
    // 0x80018AB4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x80018AB4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80018AB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80018ABC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80018AC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80018AC4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80018AC8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80018ACC: addiu       $a2, $a2, 0x7200
    ctx->r6 = ADD32(ctx->r6, 0X7200);
    // 0x80018AD0: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80018AD4:
    // 0x80018AD4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018AD8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80018ADC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80018AE0: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x80018AE4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80018AE8: swc1        $f18, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f18.u32l;
    // 0x80018AEC: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018AF0: sw          $a3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r7;
    // 0x80018AF4: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80018AF8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80018AFC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80018B00: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80018B04:
    // 0x80018B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018B08:
    // 0x80018B08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80018B0C: jr          $ra
    // 0x80018B10: nop

    return;
    // 0x80018B10: nop

;}
RECOMP_FUNC void func_800150C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800150C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800150CC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800150D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800150D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800150D8: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x800150DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800150E0: nop

    // 0x800150E4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800150E8: lw          $t6, 0x64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X64);
    // 0x800150EC: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800150F0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x800150F4: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x800150F8: lwc1        $f16, 0x1C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800150FC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80015100: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015104: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80015108: lwc1        $f12, 0x10($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001510C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015110: jal         0x800232F4
    // 0x80015114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80015114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80015118: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001511C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015120: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015124: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80015128: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001512C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015134: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015138: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8001513C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80015140: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015144: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015148: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8001514C: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80015150: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80015154: bnel        $t8, $at, L_8001518C
    if (ctx->r24 != ctx->r1) {
        // 0x80015158: lwc1        $f6, 0x1C($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_8001518C;
    }
    goto skip_0;
    // 0x80015158: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x8001515C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80015160: lwc1        $f6, 0x24($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015164: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80015168: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8001516C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015170: lwc1        $f10, 0x94($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X94);
    // 0x80015174: lwc1        $f18, 0x1C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80015178: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001517C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80015180: b           L_800151C4
    // 0x80015184: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
        goto L_800151C4;
    // 0x80015184: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80015188: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
L_8001518C:
    // 0x8001518C: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015190: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80015194: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80015198: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001519C: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800151A0: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x800151A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800151A8: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800151AC: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800151B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800151B4: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x800151B8: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x800151BC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800151C0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_800151C4:
    // 0x800151C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800151C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800151CC: jr          $ra
    // 0x800151D0: nop

    return;
    // 0x800151D0: nop

;}
RECOMP_FUNC void func_8000B170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B170: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000B174: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000B178: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x8000B17C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000B180: addiu       $t0, $t0, -0x2F30
    ctx->r8 = ADD32(ctx->r8, -0X2F30);
    // 0x8000B184: addiu       $v1, $v1, 0x4690
    ctx->r3 = ADD32(ctx->r3, 0X4690);
    // 0x8000B188: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000B18C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000B190: lwc1        $f4, 0x148($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X148);
    // 0x8000B194: lwc1        $f6, 0x14C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14C);
    // 0x8000B198: lh          $t6, 0x140($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X140);
    // 0x8000B19C: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8000B1A0: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8000B1A4: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8000B1A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000B1AC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8000B1B0: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x8000B1B4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8000B1B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B1BC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8000B1C0: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8000B1C4: addiu       $t8, $t8, 0x1B90
    ctx->r24 = ADD32(ctx->r24, 0X1B90);
    // 0x8000B1C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B1CC: bne         $t9, $at, L_8000B1E0
    if (ctx->r25 != ctx->r1) {
        // 0x8000B1D0: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_8000B1E0;
    }
    // 0x8000B1D0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8000B1D4: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x8000B1D8: b           L_8000B214
    // 0x8000B1DC: lwc1        $f2, 0x94($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X94);
        goto L_8000B214;
    // 0x8000B1DC: lwc1        $f2, 0x94($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X94);
L_8000B1E0:
    // 0x8000B1E0: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B1E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000B1E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8000B1EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000B1F0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8000B1F4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8000B1F8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000B1FC: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000B200: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000B204: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000B208: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8000B20C: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8000B210: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_8000B214:
    // 0x8000B214: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000B218: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8000B21C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000B220: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000B224: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000B228: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x8000B22C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8000B230: lhu         $a1, 0x47D4($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X47D4);
    // 0x8000B234: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8000B238: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000B23C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000B240: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8000B244: lhu         $a0, 0x47D2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X47D2);
    // 0x8000B248: jal         0x800177F8
    // 0x8000B24C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x8000B24C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8000B250: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8000B254: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8000B258: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000B25C: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B260: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8000B264: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8000B268: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B26C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000B270: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000B274: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000B278: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B27C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000B280: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8000B284: add.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8000B288: ldc1        $f18, 0x11C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X11C0);
    // 0x8000B28C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8000B290: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8000B294: mul.d       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000B298: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8000B29C: jal         0x80019354
    // 0x8000B2A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80019354(rdram, ctx);
        goto after_1;
    // 0x8000B2A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8000B2A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000B2A8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000B2AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000B2B0: jr          $ra
    // 0x8000B2B4: nop

    return;
    // 0x8000B2B4: nop

;}
RECOMP_FUNC void func_8000B520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B520: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B524: sb          $zero, -0x2E64($at)
    MEM_B(-0X2E64, ctx->r1) = 0;
    // 0x8000B528: jr          $ra
    // 0x8000B52C: nop

    return;
    // 0x8000B52C: nop

;}
RECOMP_FUNC void func_80042D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80042D64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80042D68: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80042D6C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x80042D70: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80042D74: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80042D78: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x80042D7C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80042D80: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80042D84: beq         $v1, $zero, L_80042DC8
    if (ctx->r3 == 0) {
        // 0x80042D88: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80042DC8;
    }
    // 0x80042D88: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80042D8C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80042D90: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x80042D94: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80042D98: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80042D9C: bnel        $t0, $zero, L_80042DB0
    if (ctx->r8 != 0) {
        // 0x80042DA0: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_80042DB0;
    }
    goto skip_0;
    // 0x80042DA0: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_0:
    // 0x80042DA4: b           L_80042DB4
    // 0x80042DA8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_80042DB4;
    // 0x80042DA8: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x80042DAC: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_80042DB0:
    // 0x80042DB0: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
L_80042DB4:
    // 0x80042DB4: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x80042DB8: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x80042DBC: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x80042DC0: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x80042DC4: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
L_80042DC8:
    // 0x80042DC8: jr          $ra
    // 0x80042DCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80042DCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800203D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800203D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800203D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800203D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800203DC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800203E0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800203E4: addiu       $s1, $s1, -0x2F78
    ctx->r17 = ADD32(ctx->r17, -0X2F78);
    // 0x800203E8: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x800203EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800203F0: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800203F4: addiu       $t6, $zero, 0xB5
    ctx->r14 = ADD32(0, 0XB5);
    // 0x800203F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800203FC: sw          $t6, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r14;
    // 0x80020400: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80020404: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80020408: sw          $t7, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r15;
    // 0x8002040C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020410: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x80020414: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80020418: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002041C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020420: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80020424: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020428: lui         $t4, 0x803A
    ctx->r12 = S32(0X803A << 16);
    // 0x8002042C: addiu       $t4, $t4, -0x2670
    ctx->r12 = ADD32(ctx->r12, -0X2670);
    // 0x80020430: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020434: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80020438: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8002043C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80020440: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020444: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80020448: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8002044C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80020450: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80020454: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020458: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002045C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020460: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80020464: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80020468: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002046C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80020470: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80020474: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020478: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002047C: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80020480: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80020484: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80020488: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8002048C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020490: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80020494: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020498: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8002049C: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x800204A0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800204A4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800204A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800204AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800204B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800204B4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800204B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800204BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800204C0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800204C4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800204C8: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x800204CC: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x800204D0: lhu         $t3, 0x90($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X90);
    // 0x800204D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800204D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800204DC: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x800204E0: beq         $t4, $zero, L_800205F0
    if (ctx->r12 == 0) {
        // 0x800204E4: addiu       $a3, $zero, 0x6E
        ctx->r7 = ADD32(0, 0X6E);
            goto L_800205F0;
    }
    // 0x800204E4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    // 0x800204E8: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x800204EC: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x800204F0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800204F4: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x800204F8: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800204FC: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80020500: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80020504: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80020508: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002050C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80020510: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80020514: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x80020518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002051C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020520: jal         0x800210FC
    // 0x80020524: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x80020524: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_0:
    // 0x80020528: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8002052C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80020530: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80020534: addiu       $t5, $zero, 0x2C
    ctx->r13 = ADD32(0, 0X2C);
    // 0x80020538: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8002053C: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80020540: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80020544: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80020548: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8002054C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80020550: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80020554: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x80020558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002055C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80020560: jal         0x800210FC
    // 0x80020564: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x80020564: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_1:
    // 0x80020568: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8002056C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80020570: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80020574: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x80020578: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8002057C: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x80020580: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80020584: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80020588: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8002058C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80020590: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80020594: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x80020598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002059C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800205A0: jal         0x800210FC
    // 0x800205A4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x800205A4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_2:
    // 0x800205A8: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x800205AC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800205B0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800205B4: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x800205B8: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x800205BC: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x800205C0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800205C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800205C8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800205CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800205D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800205D4: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x800205D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800205DC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800205E0: jal         0x800210FC
    // 0x800205E4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_3;
    // 0x800205E4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_3:
    // 0x800205E8: b           L_800206A0
    // 0x800205EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
        goto L_800206A0;
    // 0x800205EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_800205F0:
    // 0x800205F0: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x800205F4: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x800205F8: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x800205FC: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80020600: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80020604: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80020608: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8002060C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80020610: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80020614: jal         0x800210FC
    // 0x80020618: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800210FC(rdram, ctx);
        goto after_4;
    // 0x80020618: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x8002061C: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x80020620: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80020624: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80020628: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x8002062C: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x80020630: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80020634: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80020638: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8002063C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80020640: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80020644: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80020648: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8002064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020650: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80020654: jal         0x800210FC
    // 0x80020658: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_5;
    // 0x80020658: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_5:
    // 0x8002065C: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x80020660: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80020664: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80020668: addiu       $t9, $zero, 0x4E
    ctx->r25 = ADD32(0, 0X4E);
    // 0x8002066C: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80020670: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80020674: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80020678: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8002067C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80020680: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80020684: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80020688: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8002068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020690: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80020694: jal         0x800210FC
    // 0x80020698: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_6;
    // 0x80020698: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_6:
    // 0x8002069C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_800206A0:
    // 0x800206A0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800206A4: lw          $t5, -0x2F54($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2F54);
    // 0x800206A8: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800206AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800206B0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x800206B4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800206B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800206BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800206C0: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800206C4: jal         0x80020B4C
    // 0x800206C8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    func_80020B4C(rdram, ctx);
        goto after_7;
    // 0x800206C8: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    after_7:
    // 0x800206CC: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x800206D0: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800206D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800206D8: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x800206DC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800206E0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x800206E4: jal         0x80020E2C
    // 0x800206E8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_80020E2C(rdram, ctx);
        goto after_8;
    // 0x800206E8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_8:
    // 0x800206EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800206F0: lui         $t8, 0x803A
    ctx->r24 = S32(0X803A << 16);
    // 0x800206F4: addiu       $t8, $t8, -0x6550
    ctx->r24 = ADD32(ctx->r24, -0X6550);
    // 0x800206F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800206FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80020700: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80020704: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80020708: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002070C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020710: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80020714: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x80020718: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002071C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80020720: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020724: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80020728: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002072C: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x80020730: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80020734: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80020738: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8002073C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80020740: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80020744: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020748: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8002074C: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80020750: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80020754: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80020758: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002075C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020760: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020764: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x80020768: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x8002076C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80020770: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80020774: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80020778: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002077C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80020780: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80020784: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80020788: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8002078C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80020790: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020794: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80020798: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002079C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800207A0: lhu         $t7, 0x90($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X90);
    // 0x800207A4: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800207A8: beql        $t8, $zero, L_80020878
    if (ctx->r24 == 0) {
        // 0x800207AC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80020878;
    }
    goto skip_0;
    // 0x800207AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800207B0: lw          $t5, 0x20($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X20);
    // 0x800207B4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x800207B8: jal         0x80020D4C
    // 0x800207BC: lhu         $a3, 0x6($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X6);
    func_80020D4C(rdram, ctx);
        goto after_9;
    // 0x800207BC: lhu         $a3, 0x6($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X6);
    after_9:
    // 0x800207C0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800207C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800207C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800207CC: lw          $t3, 0x20($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X20);
    // 0x800207D0: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x800207D4: jal         0x80020D4C
    // 0x800207D8: lhu         $a3, 0xE($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0XE);
    func_80020D4C(rdram, ctx);
        goto after_10;
    // 0x800207D8: lhu         $a3, 0xE($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0XE);
    after_10:
    // 0x800207DC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800207E0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800207E4: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x800207E8: lw          $t6, 0x20($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X20);
    // 0x800207EC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x800207F0: jal         0x80020D4C
    // 0x800207F4: lhu         $a3, 0x2A($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X2A);
    func_80020D4C(rdram, ctx);
        goto after_11;
    // 0x800207F4: lhu         $a3, 0x2A($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X2A);
    after_11:
    // 0x800207F8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800207FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80020800: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80020804: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80020808: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8002080C: jal         0x80020D4C
    // 0x80020810: lhu         $a3, 0xC($t8)
    ctx->r7 = MEM_HU(ctx->r24, 0XC);
    func_80020D4C(rdram, ctx);
        goto after_12;
    // 0x80020810: lhu         $a3, 0xC($t8)
    ctx->r7 = MEM_HU(ctx->r24, 0XC);
    after_12:
    // 0x80020814: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80020818: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002081C: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x80020820: lw          $t9, 0x20($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X20);
    // 0x80020824: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x80020828: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x8002082C: lhu         $v0, 0x26($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X26);
    // 0x80020830: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80020834: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80020838: beq         $v0, $at, L_80020874
    if (ctx->r2 == ctx->r1) {
        // 0x8002083C: addiu       $t3, $zero, 0xC
        ctx->r11 = ADD32(0, 0XC);
            goto L_80020874;
    }
    // 0x8002083C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80020840: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80020844: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80020848: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002084C: addiu       $t6, $t4, 0x20
    ctx->r14 = ADD32(ctx->r12, 0X20);
    // 0x80020850: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80020854: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80020858: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8002085C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80020860: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80020864: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80020868: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002086C: jal         0x800210FC
    // 0x80020870: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800210FC(rdram, ctx);
        goto after_13;
    // 0x80020870: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_13:
L_80020874:
    // 0x80020874: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80020878:
    // 0x80020878: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8002087C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80020880: jr          $ra
    // 0x80020884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80020884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80019324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019324: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80019328: addiu       $v0, $v0, 0x74E8
    ctx->r2 = ADD32(ctx->r2, 0X74E8);
    // 0x8001932C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80019330:
    // 0x80019330: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80019334: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80019338: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8001933C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80019340: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x80019344: bne         $v1, $zero, L_80019330
    if (ctx->r3 != 0) {
        // 0x80019348: addiu       $v0, $v0, 0x60
        ctx->r2 = ADD32(ctx->r2, 0X60);
            goto L_80019330;
    }
    // 0x80019348: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x8001934C: jr          $ra
    // 0x80019350: nop

    return;
    // 0x80019350: nop

;}
RECOMP_FUNC void func_80005C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C6C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80005C70: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80005C74: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80005C78: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80005C7C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80005C80: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80005C84: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80005C88: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80005C8C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80005C90: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80005C94: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80005C98: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80005C9C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80005CA0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80005CA4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80005CA8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80005CAC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80005CB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80005CB4: lwc1        $f24, 0x28($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80005CB8: lwc1        $f22, 0x24($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80005CBC: lwc1        $f20, 0x0($s5)
    ctx->f20.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80005CC0: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80005CC4: mul.s       $f30, $f24, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80005CC8: lwc1        $f22, 0x0($s6)
    ctx->f22.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80005CCC: lwc1        $f24, 0x8($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80005CD0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80005CD4: lw          $s1, -0x2F74($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X2F74);
    // 0x80005CD8: add.s       $f26, $f20, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80005CDC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80005CE0: beq         $s1, $zero, L_80005DCC
    if (ctx->r17 == 0) {
        // 0x80005CE4: add.s       $f28, $f22, $f24
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f28.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_80005DCC;
    }
    // 0x80005CE4: add.s       $f28, $f22, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f28.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x80005CE8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80005CEC: beq         $s1, $zero, L_80005DCC
    if (ctx->r17 == 0) {
        // 0x80005CF0: addiu       $s2, $s2, -0x2F70
        ctx->r18 = ADD32(ctx->r18, -0X2F70);
            goto L_80005DCC;
    }
    // 0x80005CF0: addiu       $s2, $s2, -0x2F70
    ctx->r18 = ADD32(ctx->r18, -0X2F70);
    // 0x80005CF4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_80005CF8:
    // 0x80005CF8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80005CFC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80005D00: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80005D04: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005D08: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005D0C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80005D10: sub.s       $f20, $f26, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x80005D14: sub.s       $f22, $f28, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f6.fl;
    // 0x80005D18: add.s       $f24, $f16, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x80005D1C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80005D20: nop

    // 0x80005D24: bc1f        L_80005DBC
    if (!c1cs) {
        // 0x80005D28: nop
    
            goto L_80005DBC;
    }
    // 0x80005D28: nop

    // 0x80005D2C: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80005D30: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80005D34: nop

    // 0x80005D38: bc1f        L_80005DBC
    if (!c1cs) {
        // 0x80005D3C: nop
    
            goto L_80005DBC;
    }
    // 0x80005D3C: nop

    // 0x80005D40: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x80005D44: nop

    // 0x80005D48: bc1f        L_80005DBC
    if (!c1cs) {
        // 0x80005D4C: nop
    
            goto L_80005DBC;
    }
    // 0x80005D4C: nop

    // 0x80005D50: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005D54: nop

    // 0x80005D58: bc1f        L_80005DBC
    if (!c1cs) {
        // 0x80005D5C: nop
    
            goto L_80005DBC;
    }
    // 0x80005D5C: nop

    // 0x80005D60: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80005D64: nop

    // 0x80005D68: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80005D6C: jal         0x80034F60
    // 0x80005D70: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80005D70: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80005D74: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80005D78: nop

    // 0x80005D7C: bc1f        L_80005DBC
    if (!c1cs) {
        // 0x80005D80: nop
    
            goto L_80005DBC;
    }
    // 0x80005D80: nop

    // 0x80005D84: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80005D88: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005D8C: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80005D90: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80005D94: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80005D98: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80005D9C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80005DA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80005DA4: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x80005DA8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005DAC: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80005DB0: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80005DB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005DB8: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_80005DBC:
    // 0x80005DBC: bne         $s4, $zero, L_80005DCC
    if (ctx->r20 != 0) {
        // 0x80005DC0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80005DCC;
    }
    // 0x80005DC0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80005DC4: bnel        $s1, $zero, L_80005CF8
    if (ctx->r17 != 0) {
        // 0x80005DC8: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_80005CF8;
    }
    goto skip_0;
    // 0x80005DC8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_80005DCC:
    // 0x80005DCC: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80005DD0: lw          $s1, -0x4318($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4318);
    // 0x80005DD4: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80005DD8: beq         $s1, $zero, L_80005EC8
    if (ctx->r17 == 0) {
        // 0x80005DDC: nop
    
            goto L_80005EC8;
    }
    // 0x80005DDC: nop

    // 0x80005DE0: bne         $s4, $zero, L_80005EC8
    if (ctx->r20 != 0) {
        // 0x80005DE4: addiu       $s2, $s2, -0x4310
        ctx->r18 = ADD32(ctx->r18, -0X4310);
            goto L_80005EC8;
    }
    // 0x80005DE4: addiu       $s2, $s2, -0x4310
    ctx->r18 = ADD32(ctx->r18, -0X4310);
    // 0x80005DE8: beq         $s1, $zero, L_80005EC8
    if (ctx->r17 == 0) {
        // 0x80005DEC: nop
    
            goto L_80005EC8;
    }
    // 0x80005DEC: nop

    // 0x80005DF0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_80005DF4:
    // 0x80005DF4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80005DF8: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80005DFC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80005E00: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005E04: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005E08: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80005E0C: sub.s       $f20, $f26, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x80005E10: sub.s       $f22, $f28, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f16.fl;
    // 0x80005E14: add.s       $f24, $f6, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x80005E18: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80005E1C: nop

    // 0x80005E20: bc1f        L_80005EB8
    if (!c1cs) {
        // 0x80005E24: nop
    
            goto L_80005EB8;
    }
    // 0x80005E24: nop

    // 0x80005E28: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80005E2C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80005E30: nop

    // 0x80005E34: bc1f        L_80005EB8
    if (!c1cs) {
        // 0x80005E38: nop
    
            goto L_80005EB8;
    }
    // 0x80005E38: nop

    // 0x80005E3C: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x80005E40: nop

    // 0x80005E44: bc1f        L_80005EB8
    if (!c1cs) {
        // 0x80005E48: nop
    
            goto L_80005EB8;
    }
    // 0x80005E48: nop

    // 0x80005E4C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005E50: nop

    // 0x80005E54: bc1f        L_80005EB8
    if (!c1cs) {
        // 0x80005E58: nop
    
            goto L_80005EB8;
    }
    // 0x80005E58: nop

    // 0x80005E5C: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80005E60: nop

    // 0x80005E64: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80005E68: jal         0x80034F60
    // 0x80005E6C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80005E6C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80005E70: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80005E74: nop

    // 0x80005E78: bc1f        L_80005EB8
    if (!c1cs) {
        // 0x80005E7C: nop
    
            goto L_80005EB8;
    }
    // 0x80005E7C: nop

    // 0x80005E80: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80005E84: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005E88: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80005E8C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80005E90: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80005E94: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80005E98: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80005E9C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80005EA0: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x80005EA4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005EA8: lwc1        $f16, 0x8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80005EAC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80005EB0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80005EB4: swc1        $f18, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f18.u32l;
L_80005EB8:
    // 0x80005EB8: bne         $s4, $zero, L_80005EC8
    if (ctx->r20 != 0) {
        // 0x80005EBC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80005EC8;
    }
    // 0x80005EBC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80005EC0: bnel        $s1, $zero, L_80005DF4
    if (ctx->r17 != 0) {
        // 0x80005EC4: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_80005DF4;
    }
    goto skip_1;
    // 0x80005EC4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80005EC8:
    // 0x80005EC8: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80005ECC: lw          $s1, 0x4F38($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4F38);
    // 0x80005ED0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80005ED4: beql        $s1, $zero, L_80005FD0
    if (ctx->r17 == 0) {
        // 0x80005ED8: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80005FD0;
    }
    goto skip_2;
    // 0x80005ED8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x80005EDC: bne         $s4, $zero, L_80005FCC
    if (ctx->r20 != 0) {
        // 0x80005EE0: addiu       $s2, $s2, 0x4F40
        ctx->r18 = ADD32(ctx->r18, 0X4F40);
            goto L_80005FCC;
    }
    // 0x80005EE0: addiu       $s2, $s2, 0x4F40
    ctx->r18 = ADD32(ctx->r18, 0X4F40);
    // 0x80005EE4: beql        $s1, $zero, L_80005FD0
    if (ctx->r17 == 0) {
        // 0x80005EE8: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80005FD0;
    }
    goto skip_3;
    // 0x80005EE8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x80005EEC: cvt.d.s     $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f14.d = CVT_D_S(ctx->f30.fl);
    // 0x80005EF0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_80005EF4:
    // 0x80005EF4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80005EF8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80005EFC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005F00: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005F04: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80005F08: sub.s       $f20, $f26, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x80005F0C: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80005F10: sub.s       $f22, $f28, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f28.fl - ctx->f6.fl;
    // 0x80005F14: add.d       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f14.d + ctx->f10.d;
    // 0x80005F18: cvt.s.d     $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f24.fl = CVT_S_D(ctx->f16.d);
    // 0x80005F1C: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x80005F20: nop

    // 0x80005F24: bc1f        L_80005FBC
    if (!c1cs) {
        // 0x80005F28: nop
    
            goto L_80005FBC;
    }
    // 0x80005F28: nop

    // 0x80005F2C: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80005F30: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80005F34: nop

    // 0x80005F38: bc1f        L_80005FBC
    if (!c1cs) {
        // 0x80005F3C: nop
    
            goto L_80005FBC;
    }
    // 0x80005F3C: nop

    // 0x80005F40: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x80005F44: nop

    // 0x80005F48: bc1f        L_80005FBC
    if (!c1cs) {
        // 0x80005F4C: nop
    
            goto L_80005FBC;
    }
    // 0x80005F4C: nop

    // 0x80005F50: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005F54: nop

    // 0x80005F58: bc1f        L_80005FBC
    if (!c1cs) {
        // 0x80005F5C: nop
    
            goto L_80005FBC;
    }
    // 0x80005F5C: nop

    // 0x80005F60: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80005F64: sdc1        $f14, 0x68($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X68, ctx->r29);
    // 0x80005F68: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80005F6C: jal         0x80034F60
    // 0x80005F70: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80005F70: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_2:
    // 0x80005F74: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80005F78: ldc1        $f14, 0x68($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X68);
    // 0x80005F7C: bc1f        L_80005FBC
    if (!c1cs) {
        // 0x80005F80: nop
    
            goto L_80005FBC;
    }
    // 0x80005F80: nop

    // 0x80005F84: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80005F88: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005F8C: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80005F90: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80005F94: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80005F98: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80005F9C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80005FA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80005FA4: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x80005FA8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005FAC: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80005FB0: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80005FB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005FB8: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_80005FBC:
    // 0x80005FBC: bne         $s4, $zero, L_80005FCC
    if (ctx->r20 != 0) {
        // 0x80005FC0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80005FCC;
    }
    // 0x80005FC0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80005FC4: bnel        $s1, $zero, L_80005EF4
    if (ctx->r17 != 0) {
        // 0x80005FC8: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_80005EF4;
    }
    goto skip_4;
    // 0x80005FC8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_4:
L_80005FCC:
    // 0x80005FCC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80005FD0:
    // 0x80005FD0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80005FD4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80005FD8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80005FDC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80005FE0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80005FE4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80005FE8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80005FEC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80005FF0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80005FF4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80005FF8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80005FFC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80006000: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80006004: jr          $ra
    // 0x80006008: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80006008: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80024690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    load_overlays(ctx->r4, ctx->r5, ctx->r6);
    // 0x80024690: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80024694: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024698: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8002469C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800246A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800246A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800246A8: jal         0x80036460
    // 0x800246AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800246AC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800246B0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800246B4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800246B8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800246BC: addiu       $t8, $t8, -0xD78
    ctx->r24 = ADD32(ctx->r24, -0XD78);
    // 0x800246C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800246C4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800246C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800246CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800246D0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800246D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800246D8: jal         0x80036510
    // 0x800246DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x800246DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800246E0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800246E4: addiu       $a0, $a0, -0xD78
    ctx->r4 = ADD32(ctx->r4, -0XD78);
    // 0x800246E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800246EC: jal         0x80034020
    // 0x800246F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800246F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800246F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800246F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800246FC: jr          $ra
    // 0x80024700: nop

    return;
    // 0x80024700: nop

;}
RECOMP_FUNC void func_80014720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014720: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80014724: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80014728: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8001472C: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x80014730: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80014734: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80014738: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8001473C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80014740: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80014744: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80014748: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001474C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014750: lw          $v0, -0x4318($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4318);
    // 0x80014754: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80014758: beq         $v0, $zero, L_80014808
    if (ctx->r2 == 0) {
        // 0x8001475C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80014808;
    }
    // 0x8001475C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80014760: beq         $v0, $zero, L_80014808
    if (ctx->r2 == 0) {
        // 0x80014764: addiu       $s2, $s2, -0x4310
        ctx->r18 = ADD32(ctx->r18, -0X4310);
            goto L_80014808;
    }
    // 0x80014764: addiu       $s2, $s2, -0x4310
    ctx->r18 = ADD32(ctx->r18, -0X4310);
    // 0x80014768: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8001476C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80014770: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80014774: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80014778: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001477C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80014780: nop

    // 0x80014784: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_80014788:
    // 0x80014788: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001478C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80014790: sub.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80014794: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80014798: c.lt.d      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.d < ctx->f22.d;
    // 0x8001479C: nop

    // 0x800147A0: bc1fl       L_80014800
    if (!c1cs) {
        // 0x800147A4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80014800;
    }
    goto skip_0;
    // 0x800147A4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x800147A8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800147AC: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800147B0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800147B4: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800147B8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800147BC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800147C0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800147C4: nop

    // 0x800147C8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800147CC: jal         0x80034F60
    // 0x800147D0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x800147D0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800147D4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800147D8: c.lt.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d < ctx->f20.d;
    // 0x800147DC: nop

    // 0x800147E0: bc1fl       L_80014800
    if (!c1cs) {
        // 0x800147E4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80014800;
    }
    goto skip_1;
    // 0x800147E4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x800147E8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800147EC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800147F0: add.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = ctx->f16.d + ctx->f20.d;
    // 0x800147F4: b           L_80014808
    // 0x800147F8: cvt.s.d     $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f24.fl = CVT_S_D(ctx->f18.d);
        goto L_80014808;
    // 0x800147F8: cvt.s.d     $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f24.fl = CVT_S_D(ctx->f18.d);
    // 0x800147FC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80014800:
    // 0x80014800: bnel        $s1, $zero, L_80014788
    if (ctx->r17 != 0) {
        // 0x80014804: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_80014788;
    }
    goto skip_2;
    // 0x80014804: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_2:
L_80014808:
    // 0x80014808: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
    // 0x8001480C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80014810: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80014814: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80014818: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8001481C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80014820: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80014824: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80014828: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8001482C: jr          $ra
    // 0x80014830: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80014830: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80014834: nop

    // 0x80014838: nop

    // 0x8001483C: nop

;}
RECOMP_FUNC void func_8001D924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D924: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001D928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D92C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001D930: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D938: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8001D93C: lhu         $t0, 0x54($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X54);
    // 0x8001D940: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x8001D944: blez        $v1, L_8001D974
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001D948: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001D974;
    }
    // 0x8001D948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001D94C: lb          $t6, 0x14($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X14);
    // 0x8001D950: beql        $t6, $zero, L_8001D978
    if (ctx->r14 == 0) {
        // 0x8001D954: lhu         $a2, 0x6($a3)
        ctx->r6 = MEM_HU(ctx->r7, 0X6);
            goto L_8001D978;
    }
    goto skip_0;
    // 0x8001D954: lhu         $a2, 0x6($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X6);
    skip_0:
    // 0x8001D958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001D95C:
    // 0x8001D95C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001D960: beq         $at, $zero, L_8001D974
    if (ctx->r1 == 0) {
        // 0x8001D964: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_8001D974;
    }
    // 0x8001D964: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8001D968: lb          $t7, 0x14($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X14);
    // 0x8001D96C: bnel        $t7, $zero, L_8001D95C
    if (ctx->r15 != 0) {
        // 0x8001D970: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001D95C;
    }
    goto skip_1;
    // 0x8001D970: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
L_8001D974:
    // 0x8001D974: lhu         $a2, 0x6($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X6);
L_8001D978:
    // 0x8001D978: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001D97C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8001D980: beql        $a2, $zero, L_8001D9C0
    if (ctx->r6 == 0) {
        // 0x8001D984: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001D9C0;
    }
    goto skip_2;
    // 0x8001D984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    skip_2:
    // 0x8001D988: div         $zero, $t0, $a2
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r6)));
    // 0x8001D98C: bne         $a2, $zero, L_8001D998
    if (ctx->r6 != 0) {
        // 0x8001D990: nop
    
            goto L_8001D998;
    }
    // 0x8001D990: nop

    // 0x8001D994: break       7
    do_break(2147604884);
L_8001D998:
    // 0x8001D998: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001D99C: bne         $a2, $at, L_8001D9B0
    if (ctx->r6 != ctx->r1) {
        // 0x8001D9A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001D9B0;
    }
    // 0x8001D9A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001D9A4: bne         $t0, $at, L_8001D9B0
    if (ctx->r8 != ctx->r1) {
        // 0x8001D9A8: nop
    
            goto L_8001D9B0;
    }
    // 0x8001D9A8: nop

    // 0x8001D9AC: break       6
    do_break(2147604908);
L_8001D9B0:
    // 0x8001D9B0: mfhi        $a2
    ctx->r6 = hi;
    // 0x8001D9B4: b           L_8001D9C4
    // 0x8001D9B8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
        goto L_8001D9C4;
    // 0x8001D9B8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8001D9BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001D9C0:
    // 0x8001D9C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
L_8001D9C4:
    // 0x8001D9C4: jal         0x80022B40
    // 0x8001D9C8: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    func_80022B40(rdram, ctx);
        goto after_0;
    // 0x8001D9C8: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8001D9CC: lhu         $v0, 0x60($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X60);
    // 0x8001D9D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8001D9D4: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001D9D8: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x8001D9DC: beq         $t8, $zero, L_8001DA84
    if (ctx->r24 == 0) {
        // 0x8001D9E0: andi        $t2, $v0, 0x400
        ctx->r10 = ctx->r2 & 0X400;
            goto L_8001DA84;
    }
    // 0x8001D9E0: andi        $t2, $v0, 0x400
    ctx->r10 = ctx->r2 & 0X400;
    // 0x8001D9E4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001D9E8: lhu         $a2, 0x6($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X6);
    // 0x8001D9EC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001D9F0: lhu         $t9, 0x32($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X32);
    // 0x8001D9F4: beql        $a2, $t9, L_8001DA10
    if (ctx->r6 == ctx->r25) {
        // 0x8001D9F8: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8001DA10;
    }
    goto skip_3;
    // 0x8001D9F8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x8001D9FC: lhu         $t1, 0x66($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X66);
L_8001DA00:
    // 0x8001DA00: addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    // 0x8001DA04: bnel        $a2, $t1, L_8001DA00
    if (ctx->r6 != ctx->r9) {
        // 0x8001DA08: lhu         $t1, 0x66($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X66);
            goto L_8001DA00;
    }
    goto skip_4;
    // 0x8001DA08: lhu         $t1, 0x66($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X66);
    skip_4:
    // 0x8001DA0C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_8001DA10:
    // 0x8001DA10: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001DA14: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001DA18: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001DA1C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001DA20: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DA24: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001DA28: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001DA2C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x8001DA30: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001DA34: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8001DA38: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001DA3C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001DA40: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001DA44: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x8001DA48: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001DA4C: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8001DA50: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DA54: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001DA58: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x8001DA5C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001DA60: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DA64: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x8001DA68: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001DA6C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DA70: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8001DA74: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001DA78: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DA7C: b           L_8001DB24
    // 0x8001DA80: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
        goto L_8001DB24;
    // 0x8001DA80: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_8001DA84:
    // 0x8001DA84: beq         $t2, $zero, L_8001DAC8
    if (ctx->r10 == 0) {
        // 0x8001DA88: lwc1        $f10, 0x2C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8001DAC8;
    }
    // 0x8001DA88: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001DA8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DA90: nop

    // 0x8001DA94: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8001DA98: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8001DA9C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8001DAA0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001DAA4: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DAA8: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x8001DAAC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001DAB0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DAB4: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8001DAB8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001DABC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DAC0: b           L_8001DB24
    // 0x8001DAC4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
        goto L_8001DB24;
    // 0x8001DAC4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_8001DAC8:
    // 0x8001DAC8: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DACC: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001DAD0: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001DAD4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001DAD8: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x8001DADC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001DAE0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DAE4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001DAE8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001DAEC: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8001DAF0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001DAF4: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DAF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001DAFC: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x8001DB00: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001DB04: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DB08: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x8001DB0C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001DB10: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DB14: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8001DB18: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001DB1C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DB20: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_8001DB24:
    // 0x8001DB24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DB28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DB2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001DB30: jr          $ra
    // 0x8001DB34: nop

    return;
    // 0x8001DB34: nop

;}
RECOMP_FUNC void func_80036A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036A18: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80036A1C: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X990);
    // 0x80036A20: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80036A24: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80036A28: jr          $ra
    // 0x80036A2C: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x80036A2C: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_8000A854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A854: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8000A858: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8000A85C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8000A860: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8000A864: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A868: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8000A86C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000A870: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000A874: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8000A878: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8000A87C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8000A880: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8000A884: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8000A888: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8000A88C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8000A890: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8000A894: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8000A898: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000A89C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000A8A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000A8A4: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8000A8A8: lwc1        $f10, 0x8($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8000A8AC: lwc1        $f16, 0x28($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8000A8B0: lwc1        $f18, 0x24($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X24);
    // 0x8000A8B4: add.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000A8B8: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8000A8BC: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000A8C0: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8000A8C4: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8000A8C8: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8000A8CC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000A8D0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000A8D4: add.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A8D8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000A8DC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000A8E0: sub.s       $f20, $f28, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x8000A8E4: add.s       $f24, $f16, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8000A8E8: sub.s       $f22, $f30, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f6.fl;
    // 0x8000A8EC: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8000A8F0: nop

    // 0x8000A8F4: bc1f        L_8000A994
    if (!c1cs) {
        // 0x8000A8F8: nop
    
            goto L_8000A994;
    }
    // 0x8000A8F8: nop

    // 0x8000A8FC: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x8000A900: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000A904: nop

    // 0x8000A908: bc1f        L_8000A994
    if (!c1cs) {
        // 0x8000A90C: nop
    
            goto L_8000A994;
    }
    // 0x8000A90C: nop

    // 0x8000A910: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x8000A914: nop

    // 0x8000A918: bc1f        L_8000A994
    if (!c1cs) {
        // 0x8000A91C: nop
    
            goto L_8000A994;
    }
    // 0x8000A91C: nop

    // 0x8000A920: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8000A924: nop

    // 0x8000A928: bc1f        L_8000A994
    if (!c1cs) {
        // 0x8000A92C: nop
    
            goto L_8000A994;
    }
    // 0x8000A92C: nop

    // 0x8000A930: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000A934: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8000A938: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8000A93C: jal         0x80034F60
    // 0x8000A940: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000A940: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8000A944: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8000A948: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000A94C: bc1f        L_8000A994
    if (!c1cs) {
        // 0x8000A950: nop
    
            goto L_8000A994;
    }
    // 0x8000A950: nop

    // 0x8000A954: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8000A958: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000A95C: lwc1        $f6, -0x4534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8000A960: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8000A964: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000A968: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000A96C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8000A970: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8000A974: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8000A978: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A97C: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x8000A980: lwc1        $f18, -0x452C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x8000A984: lwc1        $f6, 0x8($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8000A988: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8000A98C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000A990: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_8000A994:
    // 0x8000A994: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000A998: lw          $s1, -0x2F74($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X2F74);
    // 0x8000A99C: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000A9A0: beq         $s1, $zero, L_8000AAB0
    if (ctx->r17 == 0) {
        // 0x8000A9A4: nop
    
            goto L_8000AAB0;
    }
    // 0x8000A9A4: nop

    // 0x8000A9A8: bne         $s3, $zero, L_8000AAB0
    if (ctx->r19 != 0) {
        // 0x8000A9AC: addiu       $s2, $s2, -0x2F70
        ctx->r18 = ADD32(ctx->r18, -0X2F70);
            goto L_8000AAB0;
    }
    // 0x8000A9AC: addiu       $s2, $s2, -0x2F70
    ctx->r18 = ADD32(ctx->r18, -0X2F70);
    // 0x8000A9B0: beq         $s1, $zero, L_8000AAB0
    if (ctx->r17 == 0) {
        // 0x8000A9B4: nop
    
            goto L_8000AAB0;
    }
    // 0x8000A9B4: nop

    // 0x8000A9B8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8000A9BC: nop

    // 0x8000A9C0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_8000A9C4:
    // 0x8000A9C4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8000A9C8: beq         $s0, $s4, L_8000AAA0
    if (ctx->r16 == ctx->r20) {
        // 0x8000A9CC: nop
    
            goto L_8000AAA0;
    }
    // 0x8000A9CC: nop

    // 0x8000A9D0: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8000A9D4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8000A9D8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A9DC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A9E0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000A9E4: sub.s       $f20, $f28, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f10.fl;
    // 0x8000A9E8: sub.s       $f22, $f30, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8000A9EC: add.s       $f24, $f6, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8000A9F0: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8000A9F4: nop

    // 0x8000A9F8: bc1f        L_8000AAA0
    if (!c1cs) {
        // 0x8000A9FC: nop
    
            goto L_8000AAA0;
    }
    // 0x8000A9FC: nop

    // 0x8000AA00: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x8000AA04: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000AA08: nop

    // 0x8000AA0C: bc1f        L_8000AAA0
    if (!c1cs) {
        // 0x8000AA10: nop
    
            goto L_8000AAA0;
    }
    // 0x8000AA10: nop

    // 0x8000AA14: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x8000AA18: nop

    // 0x8000AA1C: bc1f        L_8000AAA0
    if (!c1cs) {
        // 0x8000AA20: nop
    
            goto L_8000AAA0;
    }
    // 0x8000AA20: nop

    // 0x8000AA24: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8000AA28: nop

    // 0x8000AA2C: bc1f        L_8000AAA0
    if (!c1cs) {
        // 0x8000AA30: nop
    
            goto L_8000AAA0;
    }
    // 0x8000AA30: nop

    // 0x8000AA34: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000AA38: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8000AA3C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8000AA40: jal         0x80034F60
    // 0x8000AA44: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x8000AA44: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8000AA48: c.eq.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl == ctx->f26.fl;
    // 0x8000AA4C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000AA50: bc1t        L_8000AAA0
    if (c1cs) {
        // 0x8000AA54: nop
    
            goto L_8000AAA0;
    }
    // 0x8000AA54: nop

    // 0x8000AA58: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8000AA5C: nop

    // 0x8000AA60: bc1f        L_8000AAA0
    if (!c1cs) {
        // 0x8000AA64: nop
    
            goto L_8000AAA0;
    }
    // 0x8000AA64: nop

    // 0x8000AA68: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8000AA6C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000AA70: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8000AA74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000AA78: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8000AA7C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8000AA80: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8000AA84: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000AA88: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x8000AA8C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000AA90: lwc1        $f16, 0x8($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8000AA94: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8000AA98: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000AA9C: swc1        $f18, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f18.u32l;
L_8000AAA0:
    // 0x8000AAA0: bne         $s3, $zero, L_8000AAB0
    if (ctx->r19 != 0) {
        // 0x8000AAA4: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8000AAB0;
    }
    // 0x8000AAA4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000AAA8: bnel        $s1, $zero, L_8000A9C4
    if (ctx->r17 != 0) {
        // 0x8000AAAC: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_8000A9C4;
    }
    goto skip_0;
    // 0x8000AAAC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8000AAB0:
    // 0x8000AAB0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000AAB4: lw          $s1, 0x4F38($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4F38);
    // 0x8000AAB8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000AABC: beql        $s1, $zero, L_8000ABB8
    if (ctx->r17 == 0) {
        // 0x8000AAC0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8000ABB8;
    }
    goto skip_1;
    // 0x8000AAC0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x8000AAC4: bne         $s3, $zero, L_8000ABB4
    if (ctx->r19 != 0) {
        // 0x8000AAC8: addiu       $s2, $s2, 0x4F40
        ctx->r18 = ADD32(ctx->r18, 0X4F40);
            goto L_8000ABB4;
    }
    // 0x8000AAC8: addiu       $s2, $s2, 0x4F40
    ctx->r18 = ADD32(ctx->r18, 0X4F40);
    // 0x8000AACC: beql        $s1, $zero, L_8000ABB8
    if (ctx->r17 == 0) {
        // 0x8000AAD0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8000ABB8;
    }
    goto skip_2;
    // 0x8000AAD0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x8000AAD4: cvt.d.s     $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f26.d = CVT_D_S(ctx->f14.fl);
    // 0x8000AAD8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_8000AADC:
    // 0x8000AADC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8000AAE0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000AAE4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000AAE8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000AAEC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8000AAF0: sub.s       $f20, $f28, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x8000AAF4: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8000AAF8: sub.s       $f22, $f30, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f6.fl;
    // 0x8000AAFC: add.d       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f26.d + ctx->f10.d;
    // 0x8000AB00: cvt.s.d     $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f24.fl = CVT_S_D(ctx->f16.d);
    // 0x8000AB04: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8000AB08: nop

    // 0x8000AB0C: bc1f        L_8000ABA4
    if (!c1cs) {
        // 0x8000AB10: nop
    
            goto L_8000ABA4;
    }
    // 0x8000AB10: nop

    // 0x8000AB14: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x8000AB18: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000AB1C: nop

    // 0x8000AB20: bc1f        L_8000ABA4
    if (!c1cs) {
        // 0x8000AB24: nop
    
            goto L_8000ABA4;
    }
    // 0x8000AB24: nop

    // 0x8000AB28: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x8000AB2C: nop

    // 0x8000AB30: bc1f        L_8000ABA4
    if (!c1cs) {
        // 0x8000AB34: nop
    
            goto L_8000ABA4;
    }
    // 0x8000AB34: nop

    // 0x8000AB38: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8000AB3C: nop

    // 0x8000AB40: bc1f        L_8000ABA4
    if (!c1cs) {
        // 0x8000AB44: nop
    
            goto L_8000ABA4;
    }
    // 0x8000AB44: nop

    // 0x8000AB48: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000AB4C: nop

    // 0x8000AB50: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8000AB54: jal         0x80034F60
    // 0x8000AB58: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x8000AB58: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_2:
    // 0x8000AB5C: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8000AB60: nop

    // 0x8000AB64: bc1f        L_8000ABA4
    if (!c1cs) {
        // 0x8000AB68: nop
    
            goto L_8000ABA4;
    }
    // 0x8000AB68: nop

    // 0x8000AB6C: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8000AB70: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000AB74: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8000AB78: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000AB7C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8000AB80: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8000AB84: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8000AB88: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000AB8C: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x8000AB90: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000AB94: lwc1        $f6, 0x8($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8000AB98: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8000AB9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000ABA0: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_8000ABA4:
    // 0x8000ABA4: bne         $s3, $zero, L_8000ABB4
    if (ctx->r19 != 0) {
        // 0x8000ABA8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8000ABB4;
    }
    // 0x8000ABA8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000ABAC: bnel        $s1, $zero, L_8000AADC
    if (ctx->r17 != 0) {
        // 0x8000ABB0: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_8000AADC;
    }
    goto skip_3;
    // 0x8000ABB0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_8000ABB4:
    // 0x8000ABB4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8000ABB8:
    // 0x8000ABB8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000ABBC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000ABC0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8000ABC4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8000ABC8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8000ABCC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8000ABD0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8000ABD4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8000ABD8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8000ABDC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8000ABE0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8000ABE4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8000ABE8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8000ABEC: jr          $ra
    // 0x8000ABF0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8000ABF0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800303E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800303E8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800303EC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800303F0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x800303F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800303F8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800303FC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80030400: addiu       $t7, $t7, -0x5F8
    ctx->r15 = ADD32(ctx->r15, -0X5F8);
    // 0x80030404: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80030408: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8003040C: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x80030410: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80030414: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80030418: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8003041C: addiu       $t6, $t6, -0x5F0
    ctx->r14 = ADD32(ctx->r14, -0X5F0);
    // 0x80030420: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80030424: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80030428: addiu       $t8, $sp, 0x5C
    ctx->r24 = ADD32(ctx->r29, 0X5C);
    // 0x8003042C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80030430: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80030434: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80030438: addiu       $t8, $t8, -0x5E8
    ctx->r24 = ADD32(ctx->r24, -0X5E8);
    // 0x8003043C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80030440: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80030444: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x80030448: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8003044C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80030450: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030454: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80030458: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003045C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030460: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030464: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030468: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003046C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80030470: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80030474: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80030478: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003047C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80030480: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030484: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030488: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8003048C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80030490: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030494: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030498: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003049C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800304A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800304A4: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x800304A8: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800304AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800304B0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800304B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800304B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800304BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800304C0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800304C4: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800304C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800304CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800304D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800304D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800304D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800304DC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x800304E0: addiu       $t8, $t8, -0x480
    ctx->r24 = ADD32(ctx->r24, -0X480);
    // 0x800304E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800304E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800304EC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800304F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800304F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800304F8: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x800304FC: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80030500: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80030504: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80030508: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003050C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80030510: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030514: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80030518: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8003051C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030520: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030524: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030528: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003052C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030530: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80030534: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80030538: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003053C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030540: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030544: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030548: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003054C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80030550: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80030554: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80030558: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003055C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80030560: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030564: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030568: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8003056C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030570: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030574: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030578: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003057C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80030580: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80030584: addiu       $t7, $t7, 0x5E0
    ctx->r15 = ADD32(ctx->r15, 0X5E0);
    // 0x80030588: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8003058C: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80030590: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80030594: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80030598: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003059C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800305A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800305A4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800305A8: lh          $t8, 0xC($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XC);
    // 0x800305AC: lh          $t7, 0x6($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X6);
    // 0x800305B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800305B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800305B8: sh          $t9, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r25;
    // 0x800305BC: lh          $t2, 0xC($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XC);
    // 0x800305C0: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x800305C4: lh          $t8, 0x8($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X8);
    // 0x800305C8: sra         $t6, $t2, 1
    ctx->r14 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800305CC: andi        $t2, $t6, 0x7
    ctx->r10 = ctx->r14 & 0X7;
    // 0x800305D0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800305D4: lh          $t6, 0xA($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XA);
    // 0x800305D8: addu        $t8, $sp, $t2
    ctx->r24 = ADD32(ctx->r29, ctx->r10);
    // 0x800305DC: lbu         $t8, 0x54($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X54);
    // 0x800305E0: addu        $a3, $sp, $t2
    ctx->r7 = ADD32(ctx->r29, ctx->r10);
    // 0x800305E4: lbu         $a3, 0x5C($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X5C);
    // 0x800305E8: addiu       $a1, $a1, -0xB
    ctx->r5 = ADD32(ctx->r5, -0XB);
    // 0x800305EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800305F0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800305F4: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800305F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800305FC: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80030600: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80030604: jal         0x800307D8
    // 0x80030608: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    func_800307D8(rdram, ctx);
        goto after_0;
    // 0x80030608: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    after_0:
    // 0x8003060C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80030610: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80030614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80030618: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x8003061C: lh          $t7, 0x4($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X4);
    // 0x80030620: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x80030624: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x80030628: addu        $v0, $sp, $t2
    ctx->r2 = ADD32(ctx->r29, ctx->r10);
    // 0x8003062C: lbu         $v0, 0x64($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X64);
    // 0x80030630: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80030634: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80030638: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    // 0x8003063C: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
    // 0x80030640: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80030644: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80030648: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8003064C: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x80030650: jal         0x800307D8
    // 0x80030654: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    func_800307D8(rdram, ctx);
        goto after_1;
    // 0x80030654: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    after_1:
    // 0x80030658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003065C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80030660: jr          $ra
    // 0x80030664: nop

    return;
    // 0x80030664: nop

;}
RECOMP_FUNC void func_80043E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80043E18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043E1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043E20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043E28: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x80043E2C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80043E30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80043E34: blez        $t6, L_80043E6C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80043E38: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80043E6C;
    }
    // 0x80043E38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80043E3C: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_80043E40:
    // 0x80043E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043E44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80043E48: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80043E4C: jal         0x80042724
    // 0x80043E50: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    func_80042724(rdram, ctx);
        goto after_0;
    // 0x80043E50: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x80043E54: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x80043E58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80043E5C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80043E60: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043E64: bnel        $at, $zero, L_80043E40
    if (ctx->r1 != 0) {
        // 0x80043E68: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_80043E40;
    }
    goto skip_0;
    // 0x80043E68: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_0:
L_80043E6C:
    // 0x80043E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80043E70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043E74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043E78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043E7C: jr          $ra
    // 0x80043E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80043E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80013F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013F5C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80013F60: lhu         $t6, 0x6DC8($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X6DC8);
    // 0x80013F64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F68: sw          $a0, 0x6ED8($at)
    MEM_W(0X6ED8, ctx->r1) = ctx->r4;
    // 0x80013F6C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x80013F70: beq         $t7, $zero, L_80013F88
    if (ctx->r15 == 0) {
        // 0x80013F74: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_80013F88;
    }
    // 0x80013F74: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013F78: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80013F7C: lw          $t8, 0x6B80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B80);
    // 0x80013F80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F84: sw          $t8, 0x6E40($at)
    MEM_W(0X6E40, ctx->r1) = ctx->r24;
L_80013F88:
    // 0x80013F88: addiu       $a1, $a1, 0x6EDC
    ctx->r5 = ADD32(ctx->r5, 0X6EDC);
    // 0x80013F8C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80013F90: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80013F94: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80013F98: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80013F9C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80013FA0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80013FA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013FA8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80013FAC: sw          $t1, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = ctx->r9;
    // 0x80013FB0: lw          $t2, 0x6DC0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6DC0);
    // 0x80013FB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013FB8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80013FBC: beq         $t2, $zero, L_80014004
    if (ctx->r10 == 0) {
        // 0x80013FC0: nop
    
            goto L_80014004;
    }
    // 0x80013FC0: nop

    // 0x80013FC4: beq         $t2, $at, L_80014004
    if (ctx->r10 == ctx->r1) {
        // 0x80013FC8: nop
    
            goto L_80014004;
    }
    // 0x80013FC8: nop

    // 0x80013FCC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80013FD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013FD4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80013FD8: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80013FDC: swc1        $f4, 0x6DCC($at)
    MEM_W(0X6DCC, ctx->r1) = ctx->f4.u32l;
    // 0x80013FE0: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80013FE4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013FE8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80013FEC: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80013FF0: swc1        $f6, 0x6DD0($at)
    MEM_W(0X6DD0, ctx->r1) = ctx->f6.u32l;
    // 0x80013FF4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013FF8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80013FFC: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80014000: swc1        $f8, 0x6DD4($at)
    MEM_W(0X6DD4, ctx->r1) = ctx->f8.u32l;
L_80014004:
    // 0x80014004: lhu         $t9, 0x6DC8($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X6DC8);
    // 0x80014008: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001400C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80014010: andi        $t0, $t9, 0xFFAF
    ctx->r8 = ctx->r25 & 0XFFAF;
    // 0x80014014: sh          $t0, 0x6DC8($at)
    MEM_H(0X6DC8, ctx->r1) = ctx->r8;
    // 0x80014018: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8001401C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014020: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80014024: lwc1        $f10, 0x18($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80014028: swc1        $f10, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = ctx->f10.u32l;
    // 0x8001402C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80014030: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014034: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80014038: lwc1        $f16, 0x14($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8001403C: swc1        $f16, 0x6E18($at)
    MEM_W(0X6E18, ctx->r1) = ctx->f16.u32l;
    // 0x80014040: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80014044: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80014048: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8001404C: swc1        $f18, 0x6E1C($at)
    MEM_W(0X6E1C, ctx->r1) = ctx->f18.u32l;
    // 0x80014050: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80014054: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014058: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8001405C: lwc1        $f4, 0x24($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X24);
    // 0x80014060: swc1        $f4, 0x6E28($at)
    MEM_W(0X6E28, ctx->r1) = ctx->f4.u32l;
    // 0x80014064: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80014068: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8001406C: lwc1        $f6, 0x28($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X28);
    // 0x80014070: swc1        $f6, 0x6E2C($at)
    MEM_W(0X6E2C, ctx->r1) = ctx->f6.u32l;
    // 0x80014074: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80014078: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001407C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80014080: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80014084: swc1        $f8, 0x6E20($at)
    MEM_W(0X6E20, ctx->r1) = ctx->f8.u32l;
    // 0x80014088: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8001408C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80014090: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80014094: swc1        $f10, 0x6E24($at)
    MEM_W(0X6E24, ctx->r1) = ctx->f10.u32l;
    // 0x80014098: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8001409C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140A0: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800140A4: lwc1        $f16, 0x2C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800140A8: swc1        $f16, 0x6EC8($at)
    MEM_W(0X6EC8, ctx->r1) = ctx->f16.u32l;
    // 0x800140AC: lwc1        $f18, 0x30($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800140B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140B4: swc1        $f18, 0x6ECC($at)
    MEM_W(0X6ECC, ctx->r1) = ctx->f18.u32l;
    // 0x800140B8: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x800140BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140C0: swc1        $f4, 0x6ED0($at)
    MEM_W(0X6ED0, ctx->r1) = ctx->f4.u32l;
    // 0x800140C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140C8: swc1        $f2, 0x6E08($at)
    MEM_W(0X6E08, ctx->r1) = ctx->f2.u32l;
    // 0x800140CC: lwc1        $f0, 0x6E08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E08);
    // 0x800140D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140D4: swc1        $f0, 0x6E04($at)
    MEM_W(0X6E04, ctx->r1) = ctx->f0.u32l;
    // 0x800140D8: swc1        $f0, 0x6E00($at)
    MEM_W(0X6E00, ctx->r1) = ctx->f0.u32l;
    // 0x800140DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140E0: swc1        $f2, 0x6DFC($at)
    MEM_W(0X6DFC, ctx->r1) = ctx->f2.u32l;
    // 0x800140E4: jr          $ra
    // 0x800140E8: nop

    return;
    // 0x800140E8: nop

;}
RECOMP_FUNC void func_8002650C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002650C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026514: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80026518: lw          $a0, 0x39A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39A4);
    // 0x8002651C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80026520: beq         $a0, $at, L_80026530
    if (ctx->r4 == ctx->r1) {
        // 0x80026524: nop
    
            goto L_80026530;
    }
    // 0x80026524: nop

    // 0x80026528: jal         0x8002568C
    // 0x8002652C: nop

    func_8002568C(rdram, ctx);
        goto after_0;
    // 0x8002652C: nop

    after_0:
L_80026530:
    // 0x80026530: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80026534: sw          $zero, 0x39B8($at)
    MEM_W(0X39B8, ctx->r1) = 0;
    // 0x80026538: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002653C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80026540: sw          $t6, 0x39A4($at)
    MEM_W(0X39A4, ctx->r1) = ctx->r14;
    // 0x80026544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002654C: jr          $ra
    // 0x80026550: nop

    return;
    // 0x80026550: nop

;}
RECOMP_FUNC void func_80019738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019738: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8001973C: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80019740: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80019744: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80019748: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8001974C: mtc1        $a1, $f28
    ctx->f28.u32l = ctx->r5;
    // 0x80019750: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x80019754: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80019758: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x8001975C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80019760: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80019764: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80019768: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8001976C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80019770: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80019774: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80019778: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8001977C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80019780: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80019784: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x80019788: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8001978C: addiu       $t6, $t6, -0x3010
    ctx->r14 = ADD32(ctx->r14, -0X3010);
    // 0x80019790: addiu       $t9, $t6, 0x3C
    ctx->r25 = ADD32(ctx->r14, 0X3C);
    // 0x80019794: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
L_80019798:
    // 0x80019798: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8001979C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800197A0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800197A4: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x800197A8: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x800197AC: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x800197B0: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x800197B4: bne         $t6, $t9, L_80019798
    if (ctx->r14 != ctx->r25) {
        // 0x800197B8: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80019798;
    }
    // 0x800197B8: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x800197BC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800197C0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800197C4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800197C8: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800197CC: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x800197D0: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800197D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800197D8: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x800197DC: ldc1        $f20, 0x15A8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X15A8);
    // 0x800197E0: lwc1        $f26, 0x118($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800197E4: addiu       $s6, $sp, 0xF8
    ctx->r22 = ADD32(ctx->r29, 0XF8);
    // 0x800197E8: addiu       $s5, $sp, 0xFC
    ctx->r21 = ADD32(ctx->r29, 0XFC);
    // 0x800197EC: addiu       $s4, $sp, 0x100
    ctx->r20 = ADD32(ctx->r29, 0X100);
    // 0x800197F0: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
L_800197F4:
    // 0x800197F4: jal         0x80022FD0
    // 0x800197F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x800197F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x800197FC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80019800: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019804: bgez        $v0, L_80019818
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019808: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80019818;
    }
    // 0x80019808: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001980C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019810: nop

    // 0x80019814: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80019818:
    // 0x80019818: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8001981C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80019820: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80019824: div.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f22.d);
    // 0x80019828: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001982C: jal         0x80022FD0
    // 0x80019830: swc1        $f4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x80019830: swc1        $f4, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80019834: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80019838: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001983C: bgez        $v0, L_80019850
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019840: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80019850;
    }
    // 0x80019840: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019848: nop

    // 0x8001984C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80019850:
    // 0x80019850: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80019854: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80019858: mul.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x8001985C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80019860: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x80019864: div.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f22.d);
    // 0x80019868: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001986C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80019870: jal         0x80023570
    // 0x80019874: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    func_80023570(rdram, ctx);
        goto after_2;
    // 0x80019874: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80019878: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8001987C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80019880: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80019884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80019888: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8001988C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80019890: jal         0x80035470
    // 0x80019894: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    func_80035470(rdram, ctx);
        goto after_3;
    // 0x80019894: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_3:
    // 0x80019898: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8001989C: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800198A0: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800198A4: lwc1        $f6, 0xF8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800198A8: swc1        $f28, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f28.u32l;
    // 0x800198AC: swc1        $f30, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f30.u32l;
    // 0x800198B0: sb          $s2, 0xB4($sp)
    MEM_B(0XB4, ctx->r29) = ctx->r18;
    // 0x800198B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800198B8: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x800198BC: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800198C0: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800198C4: jal         0x8001B108
    // 0x800198C8: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    func_8001B108(rdram, ctx);
        goto after_4;
    // 0x800198C8: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800198CC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800198D0: bne         $s0, $zero, L_800197F4
    if (ctx->r16 != 0) {
        // 0x800198D4: nop
    
            goto L_800197F4;
    }
    // 0x800198D4: nop

    // 0x800198D8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x800198DC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800198E0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800198E4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800198E8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800198EC: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800198F0: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x800198F4: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800198F8: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800198FC: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80019900: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80019904: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80019908: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8001990C: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80019910: jr          $ra
    // 0x80019914: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x80019914: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80021524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021524: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80021528: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002152C: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80021530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80021534: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80021538: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002153C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80021540: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80021544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021548: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002154C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021550: lui         $t8, 0x803B
    ctx->r24 = S32(0X803B << 16);
    // 0x80021554: addiu       $t8, $t8, -0x70F0
    ctx->r24 = ADD32(ctx->r24, -0X70F0);
    // 0x80021558: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8002155C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021560: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80021564: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021568: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8002156C: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80021570: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x80021574: addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // 0x80021578: jal         0x8002263C
    // 0x8002157C: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    func_8002263C(rdram, ctx);
        goto after_0;
    // 0x8002157C: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    after_0:
    // 0x80021580: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80021584: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80021588: addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    // 0x8002158C: jal         0x8002263C
    // 0x80021590: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    func_8002263C(rdram, ctx);
        goto after_1;
    // 0x80021590: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    after_1:
    // 0x80021594: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80021598: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x8002159C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800215A0: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x800215A4: addiu       $t7, $t7, -0x6F70
    ctx->r15 = ADD32(ctx->r15, -0X6F70);
    // 0x800215A8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800215AC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800215B0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800215B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800215B8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800215BC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800215C0: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x800215C4: addiu       $t6, $t6, -0x6F18
    ctx->r14 = ADD32(ctx->r14, -0X6F18);
    // 0x800215C8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800215CC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800215D0: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800215D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800215D8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800215DC: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800215E0: lb          $s1, 0x2871($s1)
    ctx->r17 = MEM_B(ctx->r17, 0X2871);
    // 0x800215E4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800215E8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800215EC: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x800215F0: bnel        $at, $zero, L_80021604
    if (ctx->r1 != 0) {
        // 0x800215F4: slti        $at, $s1, -0x5
        ctx->r1 = SIGNED(ctx->r17) < -0X5 ? 1 : 0;
            goto L_80021604;
    }
    goto skip_0;
    // 0x800215F4: slti        $at, $s1, -0x5
    ctx->r1 = SIGNED(ctx->r17) < -0X5 ? 1 : 0;
    skip_0:
    // 0x800215F8: b           L_80021618
    // 0x800215FC: addiu       $s1, $s1, -0x5
    ctx->r17 = ADD32(ctx->r17, -0X5);
        goto L_80021618;
    // 0x800215FC: addiu       $s1, $s1, -0x5
    ctx->r17 = ADD32(ctx->r17, -0X5);
    // 0x80021600: slti        $at, $s1, -0x5
    ctx->r1 = SIGNED(ctx->r17) < -0X5 ? 1 : 0;
L_80021604:
    // 0x80021604: beql        $at, $zero, L_80021618
    if (ctx->r1 == 0) {
        // 0x80021608: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80021618;
    }
    goto skip_1;
    // 0x80021608: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_1:
    // 0x8002160C: b           L_80021618
    // 0x80021610: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
        goto L_80021618;
    // 0x80021610: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x80021614: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80021618:
    // 0x80021618: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
    // 0x8002161C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80021620: addiu       $t7, $t7, -0x3088
    ctx->r15 = ADD32(ctx->r15, -0X3088);
    // 0x80021624: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x80021628: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8002162C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80021630: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80021634: beq         $t1, $t8, L_80021654
    if (ctx->r9 == ctx->r24) {
        // 0x80021638: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_80021654;
    }
    // 0x80021638: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8002163C: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
L_80021640:
    // 0x80021640: beq         $t4, $zero, L_80021654
    if (ctx->r12 == 0) {
        // 0x80021644: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80021654;
    }
    // 0x80021644: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80021648: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8002164C: bnel        $t1, $t9, L_80021640
    if (ctx->r9 != ctx->r25) {
        // 0x80021650: addiu       $t4, $t4, -0x1
        ctx->r12 = ADD32(ctx->r12, -0X1);
            goto L_80021640;
    }
    goto skip_2;
    // 0x80021650: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    skip_2:
L_80021654:
    // 0x80021654: subu        $v1, $t2, $t4
    ctx->r3 = SUB32(ctx->r10, ctx->r12);
    // 0x80021658: beq         $v1, $zero, L_80022228
    if (ctx->r3 == 0) {
        // 0x8002165C: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_80022228;
    }
    // 0x8002165C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80021660: beq         $s1, $zero, L_800217BC
    if (ctx->r17 == 0) {
        // 0x80021664: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800217BC;
    }
    // 0x80021664: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021668: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002166C: addiu       $a0, $a0, -0x3898
    ctx->r4 = ADD32(ctx->r4, -0X3898);
    // 0x80021670: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80021674: beq         $v0, $zero, L_8002168C
    if (ctx->r2 == 0) {
        // 0x80021678: xor         $t6, $s1, $v0
        ctx->r14 = ctx->r17 ^ ctx->r2;
            goto L_8002168C;
    }
    // 0x80021678: xor         $t6, $s1, $v0
    ctx->r14 = ctx->r17 ^ ctx->r2;
    // 0x8002167C: bgez        $t6, L_8002168C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021680: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_8002168C;
    }
    // 0x80021680: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80021684: b           L_800217A0
    // 0x80021688: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800217A0;
    // 0x80021688: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8002168C:
    // 0x8002168C: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x80021690: slti        $at, $t7, 0xFB
    ctx->r1 = SIGNED(ctx->r15) < 0XFB ? 1 : 0;
    // 0x80021694: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80021698: bne         $at, $zero, L_80021724
    if (ctx->r1 != 0) {
        // 0x8002169C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80021724;
    }
    // 0x8002169C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800216A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800216A4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800216A8: lw          $t8, -0x389C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X389C);
    // 0x800216AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800216B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800216B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800216B8: sw          $t9, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r25;
    // 0x800216BC: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216C0: bne         $at, $zero, L_8002171C
    if (ctx->r1 != 0) {
        // 0x800216C4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8002171C;
    }
    // 0x800216C4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x800216C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800216CC: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x800216D0: sw          $t6, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r14;
    // 0x800216D4: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x800216D8: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800216DC: beq         $at, $zero, L_8002171C
    if (ctx->r1 == 0) {
        // 0x800216E0: addiu       $t9, $t5, 0x1
        ctx->r25 = ADD32(ctx->r13, 0X1);
            goto L_8002171C;
    }
    // 0x800216E0: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x800216E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800216E8: sw          $t9, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r25;
    // 0x800216EC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800216F0: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
    // 0x800216F4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800216F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800216FC: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80021700: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80021704: lbu         $t7, -0x3089($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3089);
    // 0x80021708: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8002170C: bne         $t1, $t7, L_8002171C
    if (ctx->r9 != ctx->r15) {
        // 0x80021710: nop
    
            goto L_8002171C;
    }
    // 0x80021710: nop

    // 0x80021714: sw          $t8, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r24;
    // 0x80021718: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8002171C:
    // 0x8002171C: b           L_80021770
    // 0x80021720: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
        goto L_80021770;
    // 0x80021720: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
L_80021724:
    // 0x80021724: slti        $at, $v0, -0xFA
    ctx->r1 = SIGNED(ctx->r2) < -0XFA ? 1 : 0;
    // 0x80021728: beq         $at, $zero, L_80021770
    if (ctx->r1 == 0) {
        // 0x8002172C: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_80021770;
    }
    // 0x8002172C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80021730: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80021734: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80021738: lw          $t9, -0x389C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X389C);
    // 0x8002173C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80021740: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80021744: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80021748: bgez        $t6, L_80021770
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002174C: sw          $t6, -0x389C($at)
        MEM_W(-0X389C, ctx->r1) = ctx->r14;
            goto L_80021770;
    }
    // 0x8002174C: sw          $t6, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r14;
    // 0x80021750: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80021754: blez        $t5, L_8002176C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80021758: sw          $zero, -0x389C($at)
        MEM_W(-0X389C, ctx->r1) = 0;
            goto L_8002176C;
    }
    // 0x80021758: sw          $zero, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = 0;
    // 0x8002175C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80021760: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80021764: b           L_80021770
    // 0x80021768: sw          $t7, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r15;
        goto L_80021770;
    // 0x80021768: sw          $t7, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r15;
L_8002176C:
    // 0x8002176C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80021770:
    // 0x80021770: beq         $a2, $zero, L_800217A0
    if (ctx->r6 == 0) {
        // 0x80021774: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800217A0;
    }
    // 0x80021774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021778: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002177C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80021780: sw          $t0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r8;
    // 0x80021784: jal         0x800268D4
    // 0x80021788: sw          $t4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r12;
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x80021788: sw          $t4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r12;
    after_2:
    // 0x8002178C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80021790: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80021794: lw          $t4, 0x144($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X144);
    // 0x80021798: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8002179C: lw          $t0, 0x13C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X13C);
L_800217A0:
    // 0x800217A0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800217A4: lw          $t8, -0x38A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X38A0);
    // 0x800217A8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800217AC: addiu       $t9, $t9, -0x3088
    ctx->r25 = ADD32(ctx->r25, -0X3088);
    // 0x800217B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800217B4: b           L_800217D0
    // 0x800217B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_800217D0;
    // 0x800217B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_800217BC:
    // 0x800217BC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800217C0: addiu       $a0, $a0, -0x3898
    ctx->r4 = ADD32(ctx->r4, -0X3898);
    // 0x800217C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800217C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800217CC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
L_800217D0:
    // 0x800217D0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800217D4: addiu       $t5, $sp, 0x114
    ctx->r13 = ADD32(ctx->r29, 0X114);
    // 0x800217D8: addiu       $v1, $v1, -0x3890
    ctx->r3 = ADD32(ctx->r3, -0X3890);
L_800217DC:
    // 0x800217DC: beq         $t0, $zero, L_8002180C
    if (ctx->r8 == 0) {
        // 0x800217E0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8002180C;
    }
    // 0x800217E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800217E4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800217E8: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800217EC: beq         $a0, $t6, L_8002180C
    if (ctx->r4 == ctx->r14) {
        // 0x800217F0: nop
    
            goto L_8002180C;
    }
    // 0x800217F0: nop

    // 0x800217F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800217F8:
    // 0x800217F8: beq         $v0, $zero, L_8002180C
    if (ctx->r2 == 0) {
        // 0x800217FC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8002180C;
    }
    // 0x800217FC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80021800: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x80021804: bnel        $a0, $t7, L_800217F8
    if (ctx->r4 != ctx->r15) {
        // 0x80021808: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800217F8;
    }
    goto skip_3;
    // 0x80021808: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_3:
L_8002180C:
    // 0x8002180C: bne         $v0, $zero, L_80021834
    if (ctx->r2 != 0) {
        // 0x80021810: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80021834;
    }
    // 0x80021810: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80021814: subu        $t8, $t2, $t4
    ctx->r24 = SUB32(ctx->r10, ctx->r12);
    // 0x80021818: sb          $t8, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r24;
    // 0x8002181C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80021820: lw          $t9, -0x38A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X38A0);
    // 0x80021824: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80021828: addiu       $t6, $t6, -0x3088
    ctx->r14 = ADD32(ctx->r14, -0X3088);
    // 0x8002182C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80021830: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_80021834:
    // 0x80021834: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80021838: bne         $t4, $zero, L_800217DC
    if (ctx->r12 != 0) {
        // 0x8002183C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800217DC;
    }
    // 0x8002183C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80021840: sw          $t0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r8;
    // 0x80021844: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80021848: addiu       $s1, $zero, 0x1AC
    ctx->r17 = ADD32(0, 0X1AC);
    // 0x8002184C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80021850: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021854: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x80021858: addiu       $t9, $t9, -0x6EC0
    ctx->r25 = ADD32(ctx->r25, -0X6EC0);
    // 0x8002185C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021860: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021864: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80021868: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002186C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021870: beq         $a1, $zero, L_80021C34
    if (ctx->r5 == 0) {
        // 0x80021874: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80021C34;
    }
    // 0x80021874: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80021878: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x8002187C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021880: subu        $ra, $a1, $t4
    ctx->r31 = SUB32(ctx->r5, ctx->r12);
    // 0x80021884: beq         $t0, $at, L_80021C34
    if (ctx->r8 == ctx->r1) {
        // 0x80021888: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80021C34;
    }
    // 0x80021888: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8002188C: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x80021890: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x80021894: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
L_80021898:
    // 0x80021898: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002189C: lbu         $t6, -0x3890($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3890);
    // 0x800218A0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800218A4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800218A8: beq         $a0, $t6, L_800218C8
    if (ctx->r4 == ctx->r14) {
        // 0x800218AC: addiu       $v1, $v1, -0x3890
        ctx->r3 = ADD32(ctx->r3, -0X3890);
            goto L_800218C8;
    }
    // 0x800218AC: addiu       $v1, $v1, -0x3890
    ctx->r3 = ADD32(ctx->r3, -0X3890);
    // 0x800218B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800218B4:
    // 0x800218B4: beq         $v0, $zero, L_800218C8
    if (ctx->r2 == 0) {
        // 0x800218B8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800218C8;
    }
    // 0x800218B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800218BC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800218C0: bnel        $a0, $t7, L_800218B4
    if (ctx->r4 != ctx->r15) {
        // 0x800218C4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800218B4;
    }
    goto skip_4;
    // 0x800218C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_4:
L_800218C8:
    // 0x800218C8: bne         $v0, $zero, L_80021944
    if (ctx->r2 != 0) {
        // 0x800218CC: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_80021944;
    }
    // 0x800218CC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800218D0: lbu         $v0, -0x1($t5)
    ctx->r2 = MEM_BU(ctx->r13, -0X1);
    // 0x800218D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800218D8: lui         $t7, 0xD4
    ctx->r15 = S32(0XD4 << 16);
    // 0x800218DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800218E0: sb          $t0, -0x3890($at)
    MEM_B(-0X3890, ctx->r1) = ctx->r8;
    // 0x800218E4: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800218E8: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x800218EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800218F0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800218F4: addiu       $t6, $t9, 0x400
    ctx->r14 = ADD32(ctx->r25, 0X400);
    // 0x800218F8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800218FC: addiu       $t9, $t9, -0x3888
    ctx->r25 = ADD32(ctx->r25, -0X3888);
    // 0x80021900: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x80021904: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80021908: addiu       $t7, $t7, -0x41C0
    ctx->r15 = ADD32(ctx->r15, -0X41C0);
    // 0x8002190C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80021910: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021914: sw          $t5, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r13;
    // 0x80021918: sw          $t4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r12;
    // 0x8002191C: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x80021920: jal         0x80024260
    // 0x80021924: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    dma_write(rdram, ctx);
        goto after_3;
    // 0x80021924: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_3:
    // 0x80021928: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002192C: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80021930: lw          $a3, 0x124($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X124);
    // 0x80021934: lw          $t4, 0x144($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X144);
    // 0x80021938: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x8002193C: b           L_80021958
    // 0x80021940: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80021958;
    // 0x80021940: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80021944:
    // 0x80021944: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x80021948: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002194C: addiu       $t8, $t8, -0x3888
    ctx->r24 = ADD32(ctx->r24, -0X3888);
    // 0x80021950: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x80021954: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
L_80021958:
    // 0x80021958: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8002195C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80021960: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80021964: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021968: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8002196C: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x80021970: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021974: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021978: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8002197C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80021980: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021984: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021988: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x8002198C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021990: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021994: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80021998: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002199C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800219A0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800219A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800219A8: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x800219AC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800219B0: lui         $t8, 0x707
    ctx->r24 = S32(0X707 << 16);
    // 0x800219B4: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x800219B8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800219BC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800219C0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800219C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800219C8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800219CC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800219D0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800219D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800219D8: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x800219DC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800219E0: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x800219E4: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x800219E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800219EC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800219F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800219F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800219F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800219FC: lui         $t6, 0x3
    ctx->r14 = S32(0X3 << 16);
    // 0x80021A00: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x80021A04: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021A08: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021A0C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80021A10: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021A14: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021A18: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80021A1C: lw          $t7, -0x389C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X389C);
    // 0x80021A20: bne         $t7, $ra, L_80021AE8
    if (ctx->r15 != ctx->r31) {
        // 0x80021A24: nop
    
            goto L_80021AE8;
    }
    // 0x80021A24: nop

    // 0x80021A28: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021A2C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80021A30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80021A34: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021A38: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021A3C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021A40: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021A44: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021A48: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x80021A4C: addiu       $t9, $t9, -0x53E0
    ctx->r25 = ADD32(ctx->r25, -0X53E0);
    // 0x80021A50: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021A54: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021A58: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80021A5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021A60: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021A64: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021A68: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80021A6C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021A70: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021A74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021A78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021A7C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021A80: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80021A84: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80021A88: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021A8C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021A90: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x80021A94: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021A98: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021A9C: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80021AA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021AA4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021AA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021AAC: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x80021AB0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021AB4: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x80021AB8: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80021ABC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021AC0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021AC4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021AC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021ACC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021AD0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021AD4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021AD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021ADC: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80021AE0: b           L_80021BAC
    // 0x80021AE4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80021BAC;
    // 0x80021AE4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80021AE8:
    // 0x80021AE8: beq         $s2, $zero, L_80021BAC
    if (ctx->r18 == 0) {
        // 0x80021AEC: lui         $t8, 0xFB00
        ctx->r24 = S32(0XFB00 << 16);
            goto L_80021BAC;
    }
    // 0x80021AEC: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80021AF0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021AF4: lui         $t9, 0x7F7F
    ctx->r25 = S32(0X7F7F << 16);
    // 0x80021AF8: ori         $t9, $t9, 0x7FFF
    ctx->r25 = ctx->r25 | 0X7FFF;
    // 0x80021AFC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021B00: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021B04: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021B08: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021B0C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B10: lui         $t8, 0x803B
    ctx->r24 = S32(0X803B << 16);
    // 0x80021B14: addiu       $t8, $t8, -0x51E0
    ctx->r24 = ADD32(ctx->r24, -0X51E0);
    // 0x80021B18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021B1C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021B20: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80021B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021B28: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021B2C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B30: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80021B34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80021B38: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021B3C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021B40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021B44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021B48: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B4C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80021B50: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80021B54: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021B58: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021B5C: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x80021B60: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021B64: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B68: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80021B6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021B70: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021B74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021B78: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x80021B7C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B80: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x80021B84: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80021B88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021B8C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021B90: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021B94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021B98: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021B9C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021BA0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021BA4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021BA8: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
L_80021BAC:
    // 0x80021BAC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021BB0: addiu       $t7, $s1, 0x40
    ctx->r15 = ADD32(ctx->r17, 0X40);
    // 0x80021BB4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80021BB8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021BBC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021BC0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80021BC4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80021BC8: andi        $t8, $s1, 0xFFF
    ctx->r24 = ctx->r17 & 0XFFF;
    // 0x80021BCC: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80021BD0: ori         $t7, $t6, 0x224
    ctx->r15 = ctx->r14 | 0X224;
    // 0x80021BD4: ori         $t6, $t9, 0x1E4
    ctx->r14 = ctx->r25 | 0X1E4;
    // 0x80021BD8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021BDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021BE0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021BE4: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80021BE8: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80021BEC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021BF0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021BF4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021BF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021BFC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021C00: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80021C04: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80021C08: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021C0C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021C10: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80021C14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021C18: addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    // 0x80021C1C: beq         $t4, $zero, L_80021C34
    if (ctx->r12 == 0) {
        // 0x80021C20: addiu       $ra, $ra, 0x1
        ctx->r31 = ADD32(ctx->r31, 0X1);
            goto L_80021C34;
    }
    // 0x80021C20: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80021C24: lbu         $t0, 0x0($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X0);
    // 0x80021C28: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021C2C: bne         $t0, $at, L_80021898
    if (ctx->r8 != ctx->r1) {
        // 0x80021C30: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80021898;
    }
    // 0x80021C30: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_80021C34:
    // 0x80021C34: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80021C38: lw          $s1, -0x389C($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X389C);
    // 0x80021C3C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80021C40: lhu         $t9, -0x2B60($a0)
    ctx->r25 = MEM_HU(ctx->r4, -0X2B60);
    // 0x80021C44: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x80021C48: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80021C4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80021C50: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
    // 0x80021C54: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x80021C58: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x80021C5C: addiu       $s1, $t8, 0x1D4
    ctx->r17 = ADD32(ctx->r24, 0X1D4);
    // 0x80021C60: jal         0x80035190
    // 0x80021C64: andi        $a0, $t9, 0x7FFF
    ctx->r4 = ctx->r25 & 0X7FFF;
    func_80035190(rdram, ctx);
        goto after_4;
    // 0x80021C64: andi        $a0, $t9, 0x7FFF
    ctx->r4 = ctx->r25 & 0X7FFF;
    after_4:
    // 0x80021C68: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80021C6C: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80021C70: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021C74: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x80021C78: addiu       $t9, $t9, -0x7088
    ctx->r25 = ADD32(ctx->r25, -0X7088);
    // 0x80021C7C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021C80: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021C84: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80021C88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021C8C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021C90: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021C94: sra         $t7, $v0, 11
    ctx->r15 = S32(SIGNED(ctx->r2) >> 11);
    // 0x80021C98: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x80021C9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021CA0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021CA4: addiu       $t6, $s1, 0x30
    ctx->r14 = ADD32(ctx->r17, 0X30);
    // 0x80021CA8: addiu       $t9, $zero, 0x1C8
    ctx->r25 = ADD32(0, 0X1C8);
    // 0x80021CAC: subu        $a0, $t9, $t8
    ctx->r4 = SUB32(ctx->r25, ctx->r24);
    // 0x80021CB0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80021CB4: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80021CB8: addiu       $t6, $a0, 0x30
    ctx->r14 = ADD32(ctx->r4, 0X30);
    // 0x80021CBC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80021CC0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80021CC4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80021CC8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80021CCC: andi        $t6, $s1, 0xFFF
    ctx->r14 = ctx->r17 & 0XFFF;
    // 0x80021CD0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80021CD4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x80021CD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021CDC: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80021CE0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021CE4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021CE8: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80021CEC: lui         $t7, 0x9C0
    ctx->r15 = S32(0X9C0 << 16);
    // 0x80021CF0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021CF4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021CF8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80021CFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021D00: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021D04: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80021D08: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80021D0C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021D10: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021D14: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80021D18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021D1C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021D20: lw          $t7, 0x13C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X13C);
    // 0x80021D24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80021D28: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80021D2C: bnel        $t7, $at, L_80022010
    if (ctx->r15 != ctx->r1) {
        // 0x80021D30: lw          $v1, 0x0($t3)
        ctx->r3 = MEM_W(ctx->r11, 0X0);
            goto L_80022010;
    }
    goto skip_5;
    // 0x80021D30: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    skip_5:
    // 0x80021D34: lhu         $a0, -0x2B60($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2B60);
    // 0x80021D38: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80021D3C: jal         0x80035190
    // 0x80021D40: andi        $a0, $t6, 0x7FFF
    ctx->r4 = ctx->r14 & 0X7FFF;
    func_80035190(rdram, ctx);
        goto after_5;
    // 0x80021D40: andi        $a0, $t6, 0x7FFF
    ctx->r4 = ctx->r14 & 0X7FFF;
    after_5:
    // 0x80021D44: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80021D48: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x80021D4C: ori         $t4, $t4, 0x1000
    ctx->r12 = ctx->r12 | 0X1000;
    // 0x80021D50: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80021D54: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021D58: lui         $t9, 0xFD48
    ctx->r25 = S32(0XFD48 << 16);
    // 0x80021D5C: lui         $t6, 0x803A
    ctx->r14 = S32(0X803A << 16);
    // 0x80021D60: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021D64: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021D68: addiu       $t6, $t6, -0x6350
    ctx->r14 = ADD32(ctx->r14, -0X6350);
    // 0x80021D6C: ori         $t9, $t9, 0xAF
    ctx->r25 = ctx->r25 | 0XAF;
    // 0x80021D70: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021D74: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021D78: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021D7C: lui         $t6, 0xF416
    ctx->r14 = S32(0XF416 << 16);
    // 0x80021D80: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80021D84: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021D88: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021D8C: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x80021D90: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80021D94: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021D98: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80021D9C: sra         $a0, $v0, 13
    ctx->r4 = S32(SIGNED(ctx->r2) >> 13);
    // 0x80021DA0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021DA4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021DA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021DAC: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x80021DB0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021DB4: lui         $t8, 0x724
    ctx->r24 = S32(0X724 << 16);
    // 0x80021DB8: ori         $t8, $t8, 0x8034
    ctx->r24 = ctx->r24 | 0X8034;
    // 0x80021DBC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021DC0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021DC4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021DC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021DCC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021DD0: lui         $t8, 0xF216
    ctx->r24 = S32(0XF216 << 16);
    // 0x80021DD4: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x80021DD8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021DDC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021DE0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021DE4: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80021DE8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021DEC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80021DF0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021DF4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021DF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80021DFC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80021E00: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021E04: lui         $t7, 0x24
    ctx->r15 = S32(0X24 << 16);
    // 0x80021E08: ori         $t7, $t7, 0x8034
    ctx->r15 = ctx->r15 | 0X8034;
    // 0x80021E0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021E10: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021E14: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80021E18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021E1C: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
    // 0x80021E20: lui         $t6, 0xE423
    ctx->r14 = S32(0XE423 << 16);
    // 0x80021E24: ori         $t6, $t6, 0x4244
    ctx->r14 = ctx->r14 | 0X4244;
    // 0x80021E28: beq         $t5, $zero, L_80021F14
    if (ctx->r13 == 0) {
        // 0x80021E2C: nop
    
            goto L_80021F14;
    }
    // 0x80021E2C: nop

    // 0x80021E30: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021E34: lui         $t8, 0x21
    ctx->r24 = S32(0X21 << 16);
    // 0x80021E38: ori         $t8, $t8, 0x8228
    ctx->r24 = ctx->r24 | 0X8228;
    // 0x80021E3C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021E40: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021E44: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021E48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021E4C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021E50: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80021E54: lui         $t6, 0xE00
    ctx->r14 = S32(0XE00 << 16);
    // 0x80021E58: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021E5C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021E60: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021E64: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021E68: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021E6C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80021E70: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80021E74: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021E78: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021E7C: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80021E80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021E84: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021E88: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021E8C: addiu       $t8, $zero, 0x85
    ctx->r24 = ADD32(0, 0X85);
    // 0x80021E90: subu        $t7, $t8, $a0
    ctx->r15 = SUB32(ctx->r24, ctx->r4);
    // 0x80021E94: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021E98: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021E9C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80021EA0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80021EA4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80021EA8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80021EAC: ori         $t9, $t7, 0x24C
    ctx->r25 = ctx->r15 | 0X24C;
    // 0x80021EB0: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x80021EB4: subu        $t8, $t6, $a0
    ctx->r24 = SUB32(ctx->r14, ctx->r4);
    // 0x80021EB8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80021EBC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021EC0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80021EC4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80021EC8: ori         $t8, $t6, 0x220
    ctx->r24 = ctx->r14 | 0X220;
    // 0x80021ECC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021ED0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021ED4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80021ED8: lui         $t6, 0xEE0
    ctx->r14 = S32(0XEE0 << 16);
    // 0x80021EDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021EE0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021EE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021EE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021EEC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021EF0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80021EF4: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80021EF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021EFC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021F00: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80021F04: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021F08: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021F0C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80021F10: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
L_80021F14:
    // 0x80021F14: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80021F18: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80021F1C: lbu         $t6, -0x3080($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3080);
    // 0x80021F20: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021F24: lui         $t7, 0xE436
    ctx->r15 = S32(0XE436 << 16);
    // 0x80021F28: beq         $t6, $at, L_8002200C
    if (ctx->r14 == ctx->r1) {
        // 0x80021F2C: ori         $t7, $t7, 0x4244
        ctx->r15 = ctx->r15 | 0X4244;
            goto L_8002200C;
    }
    // 0x80021F2C: ori         $t7, $t7, 0x4244
    ctx->r15 = ctx->r15 | 0X4244;
    // 0x80021F30: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021F34: lui         $t9, 0x34
    ctx->r25 = S32(0X34 << 16);
    // 0x80021F38: ori         $t9, $t9, 0x8228
    ctx->r25 = ctx->r25 | 0X8228;
    // 0x80021F3C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021F40: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80021F44: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80021F48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021F4C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021F50: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80021F54: lui         $t7, 0xE00
    ctx->r15 = S32(0XE00 << 16);
    // 0x80021F58: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80021F5C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80021F60: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80021F64: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80021F68: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021F6C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80021F70: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80021F74: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80021F78: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80021F7C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80021F80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021F84: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021F88: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021F8C: sra         $a0, $v0, 13
    ctx->r4 = S32(SIGNED(ctx->r2) >> 13);
    // 0x80021F90: addiu       $t9, $a0, 0xE8
    ctx->r25 = ADD32(ctx->r4, 0XE8);
    // 0x80021F94: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80021F98: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021F9C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021FA0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80021FA4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80021FA8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80021FAC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80021FB0: ori         $t6, $t9, 0x24C
    ctx->r14 = ctx->r25 | 0X24C;
    // 0x80021FB4: addiu       $t8, $a0, 0xDA
    ctx->r24 = ADD32(ctx->r4, 0XDA);
    // 0x80021FB8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80021FBC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80021FC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80021FC4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80021FC8: ori         $t8, $t6, 0x220
    ctx->r24 = ctx->r14 | 0X220;
    // 0x80021FCC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80021FD0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021FD4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80021FD8: lui         $t6, 0x10A0
    ctx->r14 = S32(0X10A0 << 16);
    // 0x80021FDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021FE0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80021FE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021FE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80021FEC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80021FF0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80021FF4: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80021FF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80021FFC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80022000: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80022004: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80022008: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8002200C:
    // 0x8002200C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
L_80022010:
    // 0x80022010: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x80022014: addiu       $t7, $t7, 0x388
    ctx->r15 = ADD32(ctx->r15, 0X388);
    // 0x80022018: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8002201C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80022020: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80022024: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80022028: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8002202C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80022030: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80022034: lw          $t6, -0x389C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X389C);
    // 0x80022038: lw          $t9, -0x38A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X38A0);
    // 0x8002203C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80022040: lui         $a2, 0x803B
    ctx->r6 = S32(0X803B << 16);
    // 0x80022044: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80022048: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8002204C: lbu         $t7, -0x3088($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3088);
    // 0x80022050: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    // 0x80022054: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80022058: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8002205C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80022060: jal         0x80030EA0
    // 0x80022064: lw          $a2, -0x66AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X66AC);
    func_80030EA0(rdram, ctx);
        goto after_6;
    // 0x80022064: lw          $a2, -0x66AC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X66AC);
    after_6:
    // 0x80022068: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002206C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80022070: lw          $t8, -0x389C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X389C);
    // 0x80022074: lw          $t6, -0x38A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X38A0);
    // 0x80022078: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002207C: lui         $a2, 0x803B
    ctx->r6 = S32(0X803B << 16);
    // 0x80022080: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80022084: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80022088: lbu         $t9, -0x3088($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X3088);
    // 0x8002208C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80022090: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80022094: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80022098: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8002209C: jal         0x80030EA0
    // 0x800220A0: lw          $a2, -0x662C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X662C);
    func_80030EA0(rdram, ctx);
        goto after_7;
    // 0x800220A0: lw          $a2, -0x662C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X662C);
    after_7:
    // 0x800220A4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800220A8: lhu         $t8, 0x2876($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2876);
    // 0x800220AC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800220B0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800220B4: andi        $t7, $t8, 0xA000
    ctx->r15 = ctx->r24 & 0XA000;
    // 0x800220B8: beq         $t7, $zero, L_80022214
    if (ctx->r15 == 0) {
        // 0x800220BC: nop
    
            goto L_80022214;
    }
    // 0x800220BC: nop

    // 0x800220C0: lw          $t9, -0x38A0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X38A0);
    // 0x800220C4: lw          $t6, -0x389C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X389C);
    // 0x800220C8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800220CC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800220D0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800220D4: jal         0x800212E4
    // 0x800220D8: lbu         $a0, -0x3088($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3088);
    func_800212E4(rdram, ctx);
        goto after_8;
    // 0x800220D8: lbu         $a0, -0x3088($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3088);
    after_8:
    // 0x800220DC: beq         $v0, $zero, L_80022214
    if (ctx->r2 == 0) {
        // 0x800220E0: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_80022214;
    }
    // 0x800220E0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800220E4: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
    // 0x800220E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800220EC: lw          $v0, -0x389C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X389C);
    // 0x800220F0: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800220F4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800220F8: subu        $t4, $t6, $v0
    ctx->r12 = SUB32(ctx->r14, ctx->r2);
    // 0x800220FC: addiu       $t9, $t9, -0x3088
    ctx->r25 = ADD32(ctx->r25, -0X3088);
    // 0x80022100: addiu       $t4, $t4, 0x95
    ctx->r12 = ADD32(ctx->r12, 0X95);
    // 0x80022104: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x80022108: beq         $t4, $zero, L_80022168
    if (ctx->r12 == 0) {
        // 0x8002210C: addu        $a3, $t7, $t9
        ctx->r7 = ADD32(ctx->r15, ctx->r25);
            goto L_80022168;
    }
    // 0x8002210C: addu        $a3, $t7, $t9
    ctx->r7 = ADD32(ctx->r15, ctx->r25);
    // 0x80022110: andi        $v1, $t4, 0x3
    ctx->r3 = ctx->r12 & 0X3;
    // 0x80022114: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80022118: beq         $v1, $zero, L_8002213C
    if (ctx->r3 == 0) {
        // 0x8002211C: addu        $v0, $v1, $t4
        ctx->r2 = ADD32(ctx->r3, ctx->r12);
            goto L_8002213C;
    }
    // 0x8002211C: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
L_80022120:
    // 0x80022120: lbu         $t8, 0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1);
    // 0x80022124: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80022128: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002212C: bne         $v0, $t4, L_80022120
    if (ctx->r2 != ctx->r12) {
        // 0x80022130: sb          $t8, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r24;
            goto L_80022120;
    }
    // 0x80022130: sb          $t8, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r24;
    // 0x80022134: beq         $t4, $zero, L_80022168
    if (ctx->r12 == 0) {
        // 0x80022138: nop
    
            goto L_80022168;
    }
    // 0x80022138: nop

L_8002213C:
    // 0x8002213C: lbu         $t7, 0x1($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1);
    // 0x80022140: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x80022144: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x80022148: lbu         $t8, 0x4($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4);
    // 0x8002214C: addiu       $t4, $t4, -0x4
    ctx->r12 = ADD32(ctx->r12, -0X4);
    // 0x80022150: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80022154: sb          $t7, -0x4($a3)
    MEM_B(-0X4, ctx->r7) = ctx->r15;
    // 0x80022158: sb          $t9, -0x3($a3)
    MEM_B(-0X3, ctx->r7) = ctx->r25;
    // 0x8002215C: sb          $t6, -0x2($a3)
    MEM_B(-0X2, ctx->r7) = ctx->r14;
    // 0x80022160: bne         $t4, $zero, L_8002213C
    if (ctx->r12 != 0) {
        // 0x80022164: sb          $t8, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r24;
            goto L_8002213C;
    }
    // 0x80022164: sb          $t8, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r24;
L_80022168:
    // 0x80022168: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002216C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80022170: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x80022174: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x80022178: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002217C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80022180: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80022184: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80022188: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002218C: addiu       $a2, $a2, -0x2ABC
    ctx->r6 = ADD32(ctx->r6, -0X2ABC);
    // 0x80022190: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80022194: jal         0x80022B08
    // 0x80022198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80022B08(rdram, ctx);
        goto after_9;
    // 0x80022198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8002219C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800221A0: lw          $t5, -0x38A0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38A0);
    // 0x800221A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800221A8: lw          $v0, -0x389C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X389C);
    // 0x800221AC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800221B0: addiu       $t8, $t8, -0x3088
    ctx->r24 = ADD32(ctx->r24, -0X3088);
    // 0x800221B4: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    // 0x800221B8: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800221BC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800221C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800221C4: bnel        $t9, $at, L_800221F8
    if (ctx->r25 != ctx->r1) {
        // 0x800221C8: lbu         $t7, 0x7($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X7);
            goto L_800221F8;
    }
    goto skip_6;
    // 0x800221C8: lbu         $t7, 0x7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X7);
    skip_6:
    // 0x800221CC: blez        $t5, L_800221E0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800221D0: addiu       $t6, $t5, -0x1
        ctx->r14 = ADD32(ctx->r13, -0X1);
            goto L_800221E0;
    }
    // 0x800221D0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800221D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800221D8: b           L_80022214
    // 0x800221DC: sw          $t6, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r14;
        goto L_80022214;
    // 0x800221DC: sw          $t6, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r14;
L_800221E0:
    // 0x800221E0: blez        $v0, L_80022214
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800221E4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80022214;
    }
    // 0x800221E4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800221E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800221EC: b           L_80022214
    // 0x800221F0: sw          $t8, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r24;
        goto L_80022214;
    // 0x800221F0: sw          $t8, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r24;
    // 0x800221F4: lbu         $t7, 0x7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X7);
L_800221F8:
    // 0x800221F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800221FC: bne         $t7, $at, L_80022214
    if (ctx->r15 != ctx->r1) {
        // 0x80022200: nop
    
            goto L_80022214;
    }
    // 0x80022200: nop

    // 0x80022204: blez        $t5, L_80022214
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80022208: addiu       $t9, $t5, -0x1
        ctx->r25 = ADD32(ctx->r13, -0X1);
            goto L_80022214;
    }
    // 0x80022208: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8002220C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80022210: sw          $t9, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r25;
L_80022214:
    // 0x80022214: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80022218: lhu         $t6, -0x2B60($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2B60);
    // 0x8002221C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80022220: addiu       $t8, $t6, 0x300
    ctx->r24 = ADD32(ctx->r14, 0X300);
    // 0x80022224: sh          $t8, -0x2B60($at)
    MEM_H(-0X2B60, ctx->r1) = ctx->r24;
L_80022228:
    // 0x80022228: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002222C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80022230: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80022234: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022238: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002223C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80022240: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80022244: jr          $ra
    // 0x80022248: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80022248: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_800213D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800213D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800213DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800213E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800213E4: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800213E8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800213EC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800213F0: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x800213F4: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x800213F8: addiu       $t7, $t7, -0x6E10
    ctx->r15 = ADD32(ctx->r15, -0X6E10);
    // 0x800213FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80021400: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80021404: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x80021408: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8002140C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80021410: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80021414: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80021418: lw          $t9, -0x2B70($at)
    ctx->r25 = MEM_W(ctx->r1, -0X2B70);
    // 0x8002141C: jalr        $t9
    // 0x80021420: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80021420: nop

    after_0:
    // 0x80021424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002142C: jr          $ra
    // 0x80021430: nop

    return;
    // 0x80021430: nop

;}
RECOMP_FUNC void func_800193B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800193B4: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x800193B8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800193BC: addiu       $s3, $sp, 0x74
    ctx->r19 = ADD32(ctx->r29, 0X74);
    // 0x800193C0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800193C4: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800193C8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800193CC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800193D0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800193D4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800193D8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800193DC: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800193E0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800193E4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800193E8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800193EC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800193F0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800193F4: addiu       $t6, $t6, -0x3050
    ctx->r14 = ADD32(ctx->r14, -0X3050);
    // 0x800193F8: addiu       $t9, $t6, 0x3C
    ctx->r25 = ADD32(ctx->r14, 0X3C);
    // 0x800193FC: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
L_80019400:
    // 0x80019400: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80019404: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80019408: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8001940C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80019410: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80019414: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x80019418: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8001941C: bne         $t6, $t9, L_80019400
    if (ctx->r14 != ctx->r25) {
        // 0x80019420: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80019400;
    }
    // 0x80019420: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80019424: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80019428: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001942C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80019430: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80019434: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x80019438: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x8001943C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80019440: ldc1        $f24, 0x1588($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X1588);
    // 0x80019444: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80019448: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8001944C: addiu       $s0, $s0, 0x74E8
    ctx->r16 = ADD32(ctx->r16, 0X74E8);
    // 0x80019450: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80019454: ldc1        $f20, 0x1590($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1590);
    // 0x80019458: addiu       $s6, $sp, 0x100
    ctx->r22 = ADD32(ctx->r29, 0X100);
    // 0x8001945C: addiu       $s5, $sp, 0x104
    ctx->r21 = ADD32(ctx->r29, 0X104);
    // 0x80019460: addiu       $s4, $sp, 0x108
    ctx->r20 = ADD32(ctx->r29, 0X108);
    // 0x80019464: addiu       $s2, $sp, 0xB8
    ctx->r18 = ADD32(ctx->r29, 0XB8);
L_80019468:
    // 0x80019468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8001946C: beq         $v1, $zero, L_80019598
    if (ctx->r3 == 0) {
        // 0x80019470: andi        $t1, $v1, 0x1
        ctx->r9 = ctx->r3 & 0X1;
            goto L_80019598;
    }
    // 0x80019470: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x80019474: beql        $t1, $zero, L_80019594
    if (ctx->r9 == 0) {
        // 0x80019478: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80019594;
    }
    goto skip_0;
    // 0x80019478: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8001947C: jal         0x80022FD0
    // 0x80019480: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x80019480: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80019484: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80019488: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001948C: bgez        $v0, L_800194A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019490: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800194A0;
    }
    // 0x80019490: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019498: nop

    // 0x8001949C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800194A0:
    // 0x800194A0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800194A4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800194A8: mul.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x800194AC: div.d       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f26.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f26.d);
    // 0x800194B0: jal         0x80022FD0
    // 0x800194B4: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x800194B4: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
    after_1:
    // 0x800194B8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800194BC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800194C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800194C4: bgez        $v0, L_800194DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800194C8: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800194DC;
    }
    // 0x800194C8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800194CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800194D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800194D4: nop

    // 0x800194D8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800194DC:
    // 0x800194DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800194E0: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x800194E4: mul.d       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f24.d);
    // 0x800194E8: div.d       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f26.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f26.d);
    // 0x800194EC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800194F0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800194F4: jal         0x80023570
    // 0x800194F8: nop

    func_80023570(rdram, ctx);
        goto after_2;
    // 0x800194F8: nop

    after_2:
    // 0x800194FC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80019500: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x80019504: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80019508: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8001950C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80019510: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80019514: jal         0x80035470
    // 0x80019518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80035470(rdram, ctx);
        goto after_3;
    // 0x80019518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8001951C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80019520: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80019524: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80019528: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001952C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019530: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80019534: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80019538: lwc1        $f10, 0x100($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8001953C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80019540: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80019544: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80019548: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8001954C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80019550: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80019554: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x80019558: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x8001955C: mul.d       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x80019560: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80019564: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80019568: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x8001956C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80019570: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80019574: mul.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f20.d);
    // 0x80019578: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8001957C: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x80019580: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80019584: jal         0x8001B108
    // 0x80019588: sb          $t2, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r10;
    func_8001B108(rdram, ctx);
        goto after_4;
    // 0x80019588: sb          $t2, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r10;
    after_4:
    // 0x8001958C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80019590: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
L_80019594:
    // 0x80019594: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80019598:
    // 0x80019598: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8001959C: bne         $s1, $zero, L_80019468
    if (ctx->r17 != 0) {
        // 0x800195A0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80019468;
    }
    // 0x800195A0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800195A4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800195A8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800195AC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800195B0: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800195B4: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x800195B8: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x800195BC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800195C0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800195C4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800195C8: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800195CC: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800195D0: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800195D4: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800195D8: jr          $ra
    // 0x800195DC: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x800195DC: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void guLookAtReflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800360D0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800360D4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800360D8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800360DC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800360E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800360E4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800360E8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800360EC: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800360F0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800360F4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800360F8: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800360FC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80036100: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80036104: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80036108: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8003610C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80036110: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80036114: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80036118: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8003611C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80036120: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80036124: jal         0x80035C90
    // 0x80036128: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    guLookAtReflectF(rdram, ctx);
        goto after_0;
    // 0x80036128: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8003612C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80036130: jal         0x80035200
    // 0x80036134: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80036134: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x80036138: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003613C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80036140: jr          $ra
    // 0x80036144: nop

    return;
    // 0x80036144: nop

    // 0x80036148: nop

    // 0x8003614C: nop

;}
RECOMP_FUNC void func_800163E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800163E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800163EC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800163F0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800163F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800163F8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800163FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80016400: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80016404: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016408: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001640C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016410: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80016414: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80016418: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x8001641C: lhu         $t6, 0x5E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X5E);
    // 0x80016420: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80016424: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016428: bne         $t7, $zero, L_80016448
    if (ctx->r15 != 0) {
        // 0x8001642C: nop
    
            goto L_80016448;
    }
    // 0x8001642C: nop

    // 0x80016430: jal         0x80018278
    // 0x80016434: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80018278(rdram, ctx);
        goto after_0;
    // 0x80016434: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80016438: beql        $v0, $zero, L_800164BC
    if (ctx->r2 == 0) {
        // 0x8001643C: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800164BC;
    }
    goto skip_0;
    // 0x8001643C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    skip_0:
    // 0x80016440: b           L_800164B8
    // 0x80016444: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800164B8;
    // 0x80016444: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80016448:
    // 0x80016448: beq         $v0, $zero, L_80016460
    if (ctx->r2 == 0) {
        // 0x8001644C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80016460;
    }
    // 0x8001644C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80016450: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80016454: jal         0x80018278
    // 0x80016458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80018278(rdram, ctx);
        goto after_1;
    // 0x80016458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8001645C: beq         $v0, $zero, L_800164B8
    if (ctx->r2 == 0) {
        // 0x80016460: lui         $s2, 0x8008
        ctx->r18 = S32(0X8008 << 16);
            goto L_800164B8;
    }
L_80016460:
    // 0x80016460: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80016464: lw          $s2, -0x3670($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X3670);
    // 0x80016468: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001646C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80016470: beq         $s2, $zero, L_800164B8
    if (ctx->r18 == 0) {
        // 0x80016474: addiu       $s0, $s0, -0x3668
        ctx->r16 = ADD32(ctx->r16, -0X3668);
            goto L_800164B8;
    }
    // 0x80016474: addiu       $s0, $s0, -0x3668
    ctx->r16 = ADD32(ctx->r16, -0X3668);
    // 0x80016478: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8001647C: addiu       $s5, $s5, 0x71DC
    ctx->r21 = ADD32(ctx->r21, 0X71DC);
    // 0x80016480: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80016484:
    // 0x80016484: lh          $t8, 0x74($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X74);
    // 0x80016488: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001648C: addiu       $s1, $s0, 0x24
    ctx->r17 = ADD32(ctx->r16, 0X24);
    // 0x80016490: beq         $s4, $t8, L_800164B0
    if (ctx->r20 == ctx->r24) {
        // 0x80016494: nop
    
            goto L_800164B0;
    }
    // 0x80016494: nop

    // 0x80016498: jal         0x80018278
    // 0x8001649C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80018278(rdram, ctx);
        goto after_2;
    // 0x8001649C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800164A0: bne         $v0, $zero, L_800164B0
    if (ctx->r2 != 0) {
        // 0x800164A4: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800164B0;
    }
    // 0x800164A4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800164A8: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800164AC: sw          $s0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r16;
L_800164B0:
    // 0x800164B0: bne         $s2, $zero, L_80016484
    if (ctx->r18 != 0) {
        // 0x800164B4: addiu       $s0, $s0, 0x128
        ctx->r16 = ADD32(ctx->r16, 0X128);
            goto L_80016484;
    }
    // 0x800164B4: addiu       $s0, $s0, 0x128
    ctx->r16 = ADD32(ctx->r16, 0X128);
L_800164B8:
    // 0x800164B8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800164BC:
    // 0x800164BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800164C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800164C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800164C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800164CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800164D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800164D4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800164D8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800164DC: jr          $ra
    // 0x800164E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800164E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80016F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F88: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80016F8C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80016F90: addiu       $t9, $t9, -0x4534
    ctx->r25 = ADD32(ctx->r25, -0X4534);
    // 0x80016F94: lhu         $t7, 0x5E($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X5E);
    // 0x80016F98: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016F9C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80016FA0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80016FA4: beq         $t8, $zero, L_80016FB4
    if (ctx->r24 == 0) {
        // 0x80016FA8: nop
    
            goto L_80016FB4;
    }
    // 0x80016FA8: nop

    // 0x80016FAC: jr          $ra
    // 0x80016FB0: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    return;
    // 0x80016FB0: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
L_80016FB4:
    // 0x80016FB4: lh          $t0, -0x35F4($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X35F4);
    // 0x80016FB8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80016FBC: addiu       $v0, $v0, -0x3668
    ctx->r2 = ADD32(ctx->r2, -0X3668);
    // 0x80016FC0: bne         $a1, $t0, L_80016FE0
    if (ctx->r5 != ctx->r8) {
        // 0x80016FC4: addiu       $v1, $zero, 0x6
        ctx->r3 = ADD32(0, 0X6);
            goto L_80016FE0;
    }
    // 0x80016FC4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80016FC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80016FCC:
    // 0x80016FCC: beq         $v1, $zero, L_80016FE0
    if (ctx->r3 == 0) {
        // 0x80016FD0: addiu       $v0, $v0, 0x128
        ctx->r2 = ADD32(ctx->r2, 0X128);
            goto L_80016FE0;
    }
    // 0x80016FD0: addiu       $v0, $v0, 0x128
    ctx->r2 = ADD32(ctx->r2, 0X128);
    // 0x80016FD4: lh          $t1, 0x74($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X74);
    // 0x80016FD8: beql        $a1, $t1, L_80016FCC
    if (ctx->r5 == ctx->r9) {
        // 0x80016FDC: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80016FCC;
    }
    goto skip_0;
    // 0x80016FDC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
L_80016FE0:
    // 0x80016FE0: beq         $v1, $zero, L_80016FF0
    if (ctx->r3 == 0) {
        // 0x80016FE4: addiu       $t2, $v0, 0x24
        ctx->r10 = ADD32(ctx->r2, 0X24);
            goto L_80016FF0;
    }
    // 0x80016FE4: addiu       $t2, $v0, 0x24
    ctx->r10 = ADD32(ctx->r2, 0X24);
    // 0x80016FE8: jr          $ra
    // 0x80016FEC: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    return;
    // 0x80016FEC: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
L_80016FF0:
    // 0x80016FF0: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80016FF4: jr          $ra
    // 0x80016FF8: nop

    return;
    // 0x80016FF8: nop

;}
RECOMP_FUNC void func_80023570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023570: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023574: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80023578: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002357C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80023580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80023584: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023588: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8002358C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80023590: jal         0x80035680
    // 0x80023594: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023594: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80023598: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8002359C: jal         0x800361F0
    // 0x800235A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800235A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x800235A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800235A8: jal         0x80035680
    // 0x800235AC: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800235AC: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x800235B0: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800235B4: jal         0x800361F0
    // 0x800235B8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800235B8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800235BC: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800235C0: jal         0x80035680
    // 0x800235C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800235C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800235C8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800235CC: jal         0x800361F0
    // 0x800235D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800235D0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800235D4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800235D8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800235DC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800235E0: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800235E4: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800235E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800235EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800235F0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800235F4: nop

    // 0x800235F8: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800235FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023600: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80023604: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80023608: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8002360C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80023610: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80023614: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023618: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8002361C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80023620: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80023624: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80023628: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002362C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80023630: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023634: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80023638: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002363C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023640: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80023644: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80023648: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002364C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80023650: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80023654: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80023658: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8002365C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80023660: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023664: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023668: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002366C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80023670: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80023674: nop

    // 0x80023678: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002367C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023680: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80023684: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80023688: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002368C: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80023690: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023698: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8002369C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800236A0: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x800236A4: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800236A8: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x800236AC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x800236B0: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x800236B4: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x800236B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800236BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800236C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800236C4: jr          $ra
    // 0x800236C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800236C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80013C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013C84: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80013C88: addiu       $v0, $v0, 0x6EE0
    ctx->r2 = ADD32(ctx->r2, 0X6EE0);
    // 0x80013C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013C90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80013C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013C98: beq         $a1, $zero, L_80013CB0
    if (ctx->r5 == 0) {
        // 0x80013C9C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80013CB0;
    }
    // 0x80013C9C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80013CA0: beql        $v1, $at, L_80013CE4
    if (ctx->r3 == ctx->r1) {
        // 0x80013CA4: lw          $t3, 0x4($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X4);
            goto L_80013CE4;
    }
    goto skip_0;
    // 0x80013CA4: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80013CA8: b           L_80013D18
    // 0x80013CAC: nop

        goto L_80013D18;
    // 0x80013CAC: nop

L_80013CB0:
    // 0x80013CB0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80013CB4: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x80013CB8: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80013CBC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80013CC0: bne         $t7, $zero, L_80013D18
    if (ctx->r15 != 0) {
        // 0x80013CC4: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_80013D18;
    }
    // 0x80013CC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80013CC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80013CCC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80013CD0: lhu         $t1, 0x8($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X8);
    // 0x80013CD4: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80013CD8: b           L_80013D18
    // 0x80013CDC: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
        goto L_80013D18;
    // 0x80013CDC: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
    // 0x80013CE0: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
L_80013CE4:
    // 0x80013CE4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80013CE8: bne         $t4, $zero, L_80013D18
    if (ctx->r12 != 0) {
        // 0x80013CEC: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_80013D18;
    }
    // 0x80013CEC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80013CF0: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80013CF4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80013CF8: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x80013CFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80013D00: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x80013D04: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
    // 0x80013D08: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80013D0C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80013D10: swc1        $f4, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f4.u32l;
    // 0x80013D14: swc1        $f6, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f6.u32l;
L_80013D18:
    // 0x80013D18: jal         0x80013008
    // 0x80013D1C: nop

    func_80013008(rdram, ctx);
        goto after_0;
    // 0x80013D1C: nop

    after_0:
    // 0x80013D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013D28: jr          $ra
    // 0x80013D2C: nop

    return;
    // 0x80013D2C: nop

;}
RECOMP_FUNC void func_80101004_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101004: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80101008: lw          $v0, -0x4CC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC0);
    // 0x8010100C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80101010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80101014: beq         $v0, $zero, L_80101074
    if (ctx->r2 == 0) {
        // 0x80101018: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80101074;
    }
    // 0x80101018: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010101C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80101020: addiu       $a1, $a1, -0x4CC8
    ctx->r5 = ADD32(ctx->r5, -0X4CC8);
L_80101024:
    // 0x80101024: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x80101028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010102C: beql        $a2, $zero, L_80101068
    if (ctx->r6 == 0) {
        // 0x80101030: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80101068;
    }
    goto skip_0;
    // 0x80101030: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80101034: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_80101038:
    // 0x80101038: lh          $t6, 0x22($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X22);
    // 0x8010103C: bnel        $a3, $t6, L_80101058
    if (ctx->r7 != ctx->r14) {
        // 0x80101040: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80101058;
    }
    goto skip_1;
    // 0x80101040: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x80101044: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80101048: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010104C: jr          $ra
    // 0x80101050: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    return;
    // 0x80101050: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x80101054: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80101058:
    // 0x80101058: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x8010105C: bne         $at, $zero, L_80101038
    if (ctx->r1 != 0) {
        // 0x80101060: addiu       $t0, $t0, 0x28
        ctx->r8 = ADD32(ctx->r8, 0X28);
            goto L_80101038;
    }
    // 0x80101060: addiu       $t0, $t0, 0x28
    ctx->r8 = ADD32(ctx->r8, 0X28);
    // 0x80101064: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80101068:
    // 0x80101068: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8010106C: bne         $at, $zero, L_80101024
    if (ctx->r1 != 0) {
        // 0x80101070: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80101024;
    }
    // 0x80101070: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80101074:
    // 0x80101074: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80101078: jr          $ra
    // 0x8010107C: nop

    return;
    // 0x8010107C: nop

;}
RECOMP_FUNC void func_8002233C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002233C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80022340: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80022344: jr          $ra
    // 0x80022348: nop

    return;
    // 0x80022348: nop

;}
RECOMP_FUNC void func_8000669C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000669C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800066A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800066A4: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x800066A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800066AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800066B0: lh          $t6, 0x64($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X64);
    // 0x800066B4: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800066B8: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x800066BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800066C0: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800066C4: lw          $v1, 0x3D00($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3D00);
    // 0x800066C8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800066CC: lhu         $t1, 0x74($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X74);
    // 0x800066D0: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x800066D4: sb          $t8, 0x118($v0)
    MEM_B(0X118, ctx->r2) = ctx->r24;
    // 0x800066D8: lh          $t0, 0x116($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X116);
    // 0x800066DC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800066E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800066E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800066E8: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800066EC: sh          $t2, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r10;
    // 0x800066F0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800066F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800066F8: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800066FC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80006700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006704: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x80006708: jal         0x8001D8B0
    // 0x8000670C: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x8000670C: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x80006710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006718: jr          $ra
    // 0x8000671C: nop

    return;
    // 0x8000671C: nop

;}
RECOMP_FUNC void func_800265F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800265F0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800265F4: addiu       $a0, $a0, -0x33F
    ctx->r4 = ADD32(ctx->r4, -0X33F);
    // 0x800265F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800265FC: sh          $zero, -0x33E($at)
    MEM_H(-0X33E, ctx->r1) = 0;
    // 0x80026600: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026604: sh          $zero, -0x33C($at)
    MEM_H(-0X33C, ctx->r1) = 0;
    // 0x80026608: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002660C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80026610: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x80026614: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026618: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8002661C: sb          $t7, -0x340($at)
    MEM_B(-0X340, ctx->r1) = ctx->r15;
    // 0x80026620: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026624: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026628: sb          $t8, -0x33A($at)
    MEM_B(-0X33A, ctx->r1) = ctx->r24;
    // 0x8002662C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80026630: addiu       $v1, $v1, -0x338
    ctx->r3 = ADD32(ctx->r3, -0X338);
L_80026634:
    // 0x80026634: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80026638: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8002663C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80026640: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
    // 0x80026644: sb          $zero, 0x9($v1)
    MEM_B(0X9, ctx->r3) = 0;
    // 0x80026648: bne         $v0, $zero, L_80026634
    if (ctx->r2 != 0) {
        // 0x8002664C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80026634;
    }
    // 0x8002664C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80026650: jr          $ra
    // 0x80026654: nop

    return;
    // 0x80026654: nop

;}
RECOMP_FUNC void func_801030E0_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801030E0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x801030E4: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x801030E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801030EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801030F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801030F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801030F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801030FC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80103100: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x80103104: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80103108: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010310C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103110: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103114: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80103118: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8010311C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103120: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103124: ori         $t2, $t2, 0x4240
    ctx->r10 = ctx->r10 | 0X4240;
    // 0x80103128: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8010312C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80103130: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80103134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103138: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x8010313C: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x80103140: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80103144: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80103148: ori         $t5, $t5, 0xFA7D
    ctx->r13 = ctx->r13 | 0XFA7D;
    // 0x8010314C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x80103150: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80103154: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80103158: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010315C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80103160: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80103164: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103168: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010316C: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x80103170: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103174: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80103178: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8010317C: jal         0x80103690
    // 0x80103180: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_80103690_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x80103180: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x80103184: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80103188: addiu       $v1, $v1, 0x6200
    ctx->r3 = ADD32(ctx->r3, 0X6200);
    // 0x8010318C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80103190: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80103194: addiu       $a1, $a1, 0x6224
    ctx->r5 = ADD32(ctx->r5, 0X6224);
    // 0x80103198: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8010319C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x801031A0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801031A4: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x801031A8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801031AC: beq         $a0, $zero, L_801031D0
    if (ctx->r4 == 0) {
        // 0x801031B0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801031D0;
    }
    // 0x801031B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801031B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801031B8: beq         $v0, $at, L_80103200
    if (ctx->r2 == ctx->r1) {
        // 0x801031BC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80103200;
    }
    // 0x801031BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801031C0: beql        $v0, $at, L_80103224
    if (ctx->r2 == ctx->r1) {
        // 0x801031C4: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_80103224;
    }
    goto skip_0;
    // 0x801031C4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x801031C8: b           L_80103240
    // 0x801031CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103240;
    // 0x801031CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801031D0:
    // 0x801031D0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x801031D4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801031D8: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x801031DC: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x801031E0: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x801031E4: bne         $at, $zero, L_8010323C
    if (ctx->r1 != 0) {
        // 0x801031E8: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_8010323C;
    }
    // 0x801031E8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x801031EC: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x801031F0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801031F4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801031F8: b           L_8010323C
    // 0x801031FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8010323C;
    // 0x801031FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80103200:
    // 0x80103200: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80103204: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x80103208: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8010320C: bnel        $t9, $zero, L_80103240
    if (ctx->r25 != 0) {
        // 0x80103210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103240;
    }
    goto skip_1;
    // 0x80103210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80103214: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80103218: b           L_8010323C
    // 0x8010321C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_8010323C;
    // 0x8010321C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80103220: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_80103224:
    // 0x80103224: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x80103228: bgez        $t4, L_8010323C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8010322C: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_8010323C;
    }
    // 0x8010322C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103230: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80103234: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80103238: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8010323C:
    // 0x8010323C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103240:
    // 0x80103240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103244: jr          $ra
    // 0x80103248: nop

    return;
    // 0x80103248: nop

;}
RECOMP_FUNC void func_800185F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800185F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800185F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800185F8: jal         0x80018684
    // 0x800185FC: nop

    func_80018684(rdram, ctx);
        goto after_0;
    // 0x800185FC: nop

    after_0:
    // 0x80018600: jal         0x800188C4
    // 0x80018604: nop

    func_800188C4(rdram, ctx);
        goto after_1;
    // 0x80018604: nop

    after_1:
    // 0x80018608: jal         0x80019324
    // 0x8001860C: nop

    func_80019324(rdram, ctx);
        goto after_2;
    // 0x8001860C: nop

    after_2:
    // 0x80018610: jal         0x80018DB4
    // 0x80018614: nop

    func_80018DB4(rdram, ctx);
        goto after_3;
    // 0x80018614: nop

    after_3:
    // 0x80018618: jal         0x8001A238
    // 0x8001861C: nop

    func_8001A238(rdram, ctx);
        goto after_4;
    // 0x8001861C: nop

    after_4:
    // 0x80018620: jal         0x80019A70
    // 0x80018624: nop

    func_80019A70(rdram, ctx);
        goto after_5;
    // 0x80018624: nop

    after_5:
    // 0x80018628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001862C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018630: jr          $ra
    // 0x80018634: nop

    return;
    // 0x80018634: nop

;}
RECOMP_FUNC void func_801016BC_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801016BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801016C0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x801016C4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801016C8: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x801016CC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801016D0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801016D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801016D8: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x801016DC: bltzl       $t9, L_801016F0
    if (SIGNED(ctx->r25) < 0) {
        // 0x801016E0: lhu         $t0, 0x4C($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X4C);
            goto L_801016F0;
    }
    goto skip_0;
    // 0x801016E0: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    skip_0:
    // 0x801016E4: jr          $ra
    // 0x801016E8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x801016E8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801016EC: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
L_801016F0:
    // 0x801016F0: andi        $a0, $a1, 0x400
    ctx->r4 = ctx->r5 & 0X400;
    // 0x801016F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801016F8: beq         $a0, $zero, L_80101768
    if (ctx->r4 == 0) {
        // 0x801016FC: sh          $t1, 0x4C($v1)
        MEM_H(0X4C, ctx->r3) = ctx->r9;
            goto L_80101768;
    }
    // 0x801016FC: sh          $t1, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r9;
    // 0x80101700: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x80101704: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80101708: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8010170C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80101710: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80101714: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x80101718: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010171C: slt         $at, $t4, $a3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80101720: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80101724: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80101728: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8010172C: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x80101730: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80101734: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80101738: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8010173C: nop

    // 0x80101740: subu        $v0, $a1, $t3
    ctx->r2 = SUB32(ctx->r5, ctx->r11);
    // 0x80101744: blezl       $v0, L_80101758
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80101748: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80101758;
    }
    goto skip_1;
    // 0x80101748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8010174C: bnel        $at, $zero, L_8010175C
    if (ctx->r1 != 0) {
        // 0x80101750: lh          $t5, 0x2E($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X2E);
            goto L_8010175C;
    }
    goto skip_2;
    // 0x80101750: lh          $t5, 0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2E);
    skip_2:
    // 0x80101754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101758:
    // 0x80101758: lh          $t5, 0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2E);
L_8010175C:
    // 0x8010175C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80101760: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80101764: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80101768:
    // 0x80101768: bnel        $a0, $zero, L_801017DC
    if (ctx->r4 != 0) {
        // 0x8010176C: lhu         $t2, 0x4C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X4C);
            goto L_801017DC;
    }
    goto skip_3;
    // 0x8010176C: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
    skip_3:
    // 0x80101770: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x80101774: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80101778: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8010177C: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80101780: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80101784: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80101788: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010178C: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80101790: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80101794: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80101798: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8010179C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801017A0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x801017A4: nop

    // 0x801017A8: subu        $v0, $a0, $t8
    ctx->r2 = SUB32(ctx->r4, ctx->r24);
    // 0x801017AC: blezl       $v0, L_801017C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801017B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801017C8;
    }
    goto skip_4;
    // 0x801017B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x801017B4: lhu         $t9, 0x4C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4C);
    // 0x801017B8: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801017BC: bnel        $at, $zero, L_801017CC
    if (ctx->r1 != 0) {
        // 0x801017C0: lh          $t0, 0x30($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X30);
            goto L_801017CC;
    }
    goto skip_5;
    // 0x801017C0: lh          $t0, 0x30($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X30);
    skip_5:
    // 0x801017C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801017C8:
    // 0x801017C8: lh          $t0, 0x30($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X30);
L_801017CC:
    // 0x801017CC: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x801017D0: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x801017D4: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x801017D8: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
L_801017DC:
    // 0x801017DC: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x801017E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801017E4: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801017E8: bne         $at, $zero, L_80101810
    if (ctx->r1 != 0) {
        // 0x801017EC: nop
    
            goto L_80101810;
    }
    // 0x801017EC: nop

    // 0x801017F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801017F4: sh          $zero, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = 0;
    // 0x801017F8: sh          $zero, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = 0;
    // 0x801017FC: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x80101800: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101804: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80101808: jr          $ra
    // 0x8010180C: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x8010180C: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
L_80101810:
    // 0x80101810: jr          $ra
    // 0x80101814: nop

    return;
    // 0x80101814: nop

;}
RECOMP_FUNC void func_800228E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800228E4: sh          $zero, -0x2FE0($at)
    MEM_H(-0X2FE0, ctx->r1) = 0;
    // 0x800228E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800228EC: sw          $zero, -0x2FDC($at)
    MEM_W(-0X2FDC, ctx->r1) = 0;
    // 0x800228F0: jr          $ra
    // 0x800228F4: nop

    return;
    // 0x800228F4: nop

;}
