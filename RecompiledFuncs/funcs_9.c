#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80100B14_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100B14: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80100B18: addiu       $a2, $a2, -0x4D04
    ctx->r6 = ADD32(ctx->r6, -0X4D04);
    // 0x80100B1C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80100B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100B28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100B2C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80100B30: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80100B34: addiu       $t8, $t8, 0x3138
    ctx->r24 = ADD32(ctx->r24, 0X3138);
    // 0x80100B38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80100B3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100B40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80100B44: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80100B48: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x80100B4C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80100B50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100B54: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80100B58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80100B5C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80100B60: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80100B64: jal         0x80100BA0
    // 0x80100B68: lw          $a0, -0x52BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X52BC);
    func_80100BA0_ovl_title(rdram, ctx);
        goto after_0;
    // 0x80100B68: lw          $a0, -0x52BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X52BC);
    after_0:
    // 0x80100B6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80100B70: addiu       $v0, $v0, -0x52CC
    ctx->r2 = ADD32(ctx->r2, -0X52CC);
    // 0x80100B74: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80100B78: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80100B7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100B80: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80100B84: bne         $t3, $zero, L_80100B90
    if (ctx->r11 != 0) {
        // 0x80100B88: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_80100B90;
    }
    // 0x80100B88: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80100B8C: sw          $t5, -0x52BC($at)
    MEM_W(-0X52BC, ctx->r1) = ctx->r13;
L_80100B90:
    // 0x80100B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100B98: jr          $ra
    // 0x80100B9C: nop

    return;
    // 0x80100B9C: nop

;}
RECOMP_FUNC void func_80012358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012358: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8001235C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80012360: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80012364: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80012368: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8001236C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80012370: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80012374: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80012378: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8001237C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80012380: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80012384: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80012388: lw          $s1, 0x6A00($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X6A00);
    // 0x8001238C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80012390: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80012394: beq         $s1, $zero, L_8001246C
    if (ctx->r17 == 0) {
        // 0x80012398: addiu       $s0, $s0, 0x6A08
        ctx->r16 = ADD32(ctx->r16, 0X6A08);
            goto L_8001246C;
    }
    // 0x80012398: addiu       $s0, $s0, 0x6A08
    ctx->r16 = ADD32(ctx->r16, 0X6A08);
    // 0x8001239C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800123A0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800123A4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800123A8: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800123AC: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x800123B0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800123B4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800123B8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800123BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800123C0: addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
L_800123C4:
    // 0x800123C4: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
    // 0x800123C8: bnel        $t6, $zero, L_80012464
    if (ctx->r14 != 0) {
        // 0x800123CC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80012464;
    }
    goto skip_0;
    // 0x800123CC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x800123D0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800123D4: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800123D8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800123DC: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800123E0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800123E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800123E8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800123EC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800123F0: nop

    // 0x800123F4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800123F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800123FC: c.lt.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl < ctx->f24.fl;
    // 0x80012400: nop

    // 0x80012404: bc1f        L_80012460
    if (!c1cs) {
        // 0x80012408: nop
    
            goto L_80012460;
    }
    // 0x80012408: nop

    // 0x8001240C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80012410: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80012414: jal         0x800232F4
    // 0x80012418: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80012418: lwc1        $f12, 0x10($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X10);
    after_0:
    // 0x8001241C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80012420: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80012424: c.le.s      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.fl <= ctx->f6.fl;
    // 0x80012428: nop

    // 0x8001242C: bc1fl       L_80012464
    if (!c1cs) {
        // 0x80012430: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80012464;
    }
    goto skip_1;
    // 0x80012430: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80012434: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80012438: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x8001243C: nop

    // 0x80012440: bc1fl       L_80012464
    if (!c1cs) {
        // 0x80012444: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80012464;
    }
    goto skip_2;
    // 0x80012444: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80012448: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x8001244C: nop

    // 0x80012450: bc1fl       L_80012464
    if (!c1cs) {
        // 0x80012454: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80012464;
    }
    goto skip_3;
    // 0x80012454: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x80012458: b           L_8001246C
    // 0x8001245C: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
        goto L_8001246C;
    // 0x8001245C: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
L_80012460:
    // 0x80012460: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80012464:
    // 0x80012464: bne         $s1, $zero, L_800123C4
    if (ctx->r17 != 0) {
        // 0x80012468: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800123C4;
    }
    // 0x80012468: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_8001246C:
    // 0x8001246C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80012470: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80012474: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80012478: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8001247C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80012480: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80012484: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80012488: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8001248C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80012490: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80012494: jr          $ra
    // 0x80012498: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80012498: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800370C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800370C0: jr          $ra
    // 0x800370C4: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
    return;
    // 0x800370C4: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
    // 0x800370C8: nop

    // 0x800370CC: nop

;}
RECOMP_FUNC void func_800347E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800347E0: nop

    // 0x800347E4: nop

    // 0x800347E8: nop

    // 0x800347EC: nop

    // 0x800347F0: nop

    // 0x800347F4: nop

    // 0x800347F8: nop

    // 0x800347FC: nop

    // 0x80034800: nop

    // 0x80034804: nop

    // 0x80034808: nop

    // 0x8003480C: nop

    // 0x80034810: nop

    // 0x80034814: nop

    // 0x80034818: nop

    // 0x8003481C: nop

    // 0x80034820: nop

    // 0x80034824: nop

    // 0x80034828: nop

    // 0x8003482C: nop

    // 0x80034830: nop

    // 0x80034834: nop

    // 0x80034838: nop

    // 0x8003483C: nop

;}
RECOMP_FUNC void func_800436EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436EC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800436F0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800436F4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800436F8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800436FC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80043700: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80043704: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80043708: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8004370C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80043710: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80043714: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80043718: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004371C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80043720: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80043724: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80043728: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_8004372C:
    // 0x8004372C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x80043730: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x80043734: beq         $at, $zero, L_80043CBC
    if (ctx->r1 == 0) {
        // 0x80043738: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80043CBC;
    }
    // 0x80043738: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004373C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80043740: addu        $at, $at, $t7
    gpr jr_addend_80043748 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80043744: lw          $t7, 0x22B8($at)
    ctx->r15 = ADD32(ctx->r1, 0X22B8);
    // 0x80043748: jr          $t7
    // 0x8004374C: nop

    switch (jr_addend_80043748 >> 2) {
        case 0: goto L_80043750; break;
        case 1: goto L_80043CBC; break;
        case 2: goto L_80043A64; break;
        case 3: goto L_80043CBC; break;
        case 4: goto L_80043CBC; break;
        case 5: goto L_8004381C; break;
        case 6: goto L_80043868; break;
        case 7: goto L_80043A84; break;
        case 8: goto L_80043CBC; break;
        case 9: goto L_800437FC; break;
        case 10: goto L_80043BBC; break;
        case 11: goto L_80043C24; break;
        case 12: goto L_80043C40; break;
        case 13: goto L_80043C5C; break;
        case 14: goto L_80043CAC; break;
        case 15: goto L_80043A98; break;
        case 16: goto L_80043ABC; break;
        case 17: goto L_80043B2C; break;
        case 18: goto L_80043CBC; break;
        case 19: goto L_80043CBC; break;
        case 20: goto L_80043CBC; break;
        case 21: goto L_80043CBC; break;
        case 22: goto L_800438CC; break;
        case 23: goto L_800439DC; break;
        default: switch_error(__func__, 0x80043748, 0x800722B8);
    }
    // 0x8004374C: nop

L_80043750:
    // 0x80043750: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x80043754: beql        $a0, $zero, L_80043CC0
    if (ctx->r4 == 0) {
        // 0x80043758: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80043CC0;
    }
    goto skip_0;
    // 0x80043758: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8004375C: jal         0x800497C4
    // 0x80043760: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_800497C4(rdram, ctx);
        goto after_0;
    // 0x80043760: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_0:
    // 0x80043764: lh          $v0, 0x88($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X88);
    // 0x80043768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004376C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80043770: beq         $v0, $at, L_80043798
    if (ctx->r2 == ctx->r1) {
        // 0x80043774: addiu       $a0, $sp, 0x88
        ctx->r4 = ADD32(ctx->r29, 0X88);
            goto L_80043798;
    }
    // 0x80043774: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80043778: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004377C: beq         $v0, $at, L_800437BC
    if (ctx->r2 == ctx->r1) {
        // 0x80043780: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800437BC;
    }
    // 0x80043780: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80043784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80043788: beq         $v0, $at, L_800437D4
    if (ctx->r2 == ctx->r1) {
        // 0x8004378C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800437D4;
    }
    // 0x8004378C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80043790: b           L_80043CC0
    // 0x80043794: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043794: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043798:
    // 0x80043798: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x8004379C: jal         0x80042ECC
    // 0x800437A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80042ECC(rdram, ctx);
        goto after_1;
    // 0x800437A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x800437A4: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x800437A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800437AC: jal         0x80042B50
    // 0x800437B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80042B50(rdram, ctx);
        goto after_2;
    // 0x800437B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800437B4: b           L_80043CC0
    // 0x800437B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x800437B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800437BC:
    // 0x800437BC: jal         0x80042C2C
    // 0x800437C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_80042C2C(rdram, ctx);
        goto after_3;
    // 0x800437C0: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_3:
    // 0x800437C4: jal         0x80042B50
    // 0x800437C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80042B50(rdram, ctx);
        goto after_4;
    // 0x800437C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800437CC: b           L_80043CC0
    // 0x800437D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x800437D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800437D4:
    // 0x800437D4: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x800437D8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800437DC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800437E0: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x800437E4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800437E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800437EC: jal         0x8003FE6C
    // 0x800437F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800437F0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x800437F4: b           L_80043CC0
    // 0x800437F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x800437F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800437FC:
    // 0x800437FC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80043800: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x80043804: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x80043808: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8004380C: jal         0x8003FE6C
    // 0x80043810: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x80043810: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_6:
    // 0x80043814: b           L_80043CC0
    // 0x80043818: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043818: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8004381C:
    // 0x8004381C: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x80043820: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80043824: jal         0x80044060
    // 0x80043828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80044060(rdram, ctx);
        goto after_7;
    // 0x80043828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8004382C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80043830: jal         0x800440E0
    // 0x80043834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800440E0(rdram, ctx);
        goto after_8;
    // 0x80043834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80043838: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8004383C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043840: lbu         $t7, 0x37($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X37);
    // 0x80043844: beql        $t7, $zero, L_80043858
    if (ctx->r15 == 0) {
        // 0x80043848: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80043858;
    }
    goto skip_1;
    // 0x80043848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x8004384C: jal         0x80043D10
    // 0x80043850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80043D10(rdram, ctx);
        goto after_9;
    // 0x80043850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80043854: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80043858:
    // 0x80043858: jal         0x80042AE0
    // 0x8004385C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042AE0(rdram, ctx);
        goto after_10;
    // 0x8004385C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x80043860: b           L_80043CC0
    // 0x80043864: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043864: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043868:
    // 0x80043868: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x8004386C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80043870: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80043874: lbu         $t8, 0x34($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X34);
    // 0x80043878: bnel        $t8, $zero, L_80043888
    if (ctx->r24 != 0) {
        // 0x8004387C: lbu         $t6, 0x44($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X44);
            goto L_80043888;
    }
    goto skip_2;
    // 0x8004387C: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    skip_2:
    // 0x80043880: sb          $t9, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r25;
    // 0x80043884: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
L_80043888:
    // 0x80043888: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x8004388C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043890: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    // 0x80043894: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x80043898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8004389C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x800438A0: jal         0x80042884
    // 0x800438A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    func_80042884(rdram, ctx);
        goto after_11;
    // 0x800438A4: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    after_11:
    // 0x800438A8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800438AC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800438B0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800438B4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800438B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800438BC: jal         0x80044190
    // 0x800438C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80044190(rdram, ctx);
        goto after_12;
    // 0x800438C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_12:
    // 0x800438C4: b           L_80043CC0
    // 0x800438C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x800438C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800438CC:
    // 0x800438CC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800438D0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800438D4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800438D8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800438DC: jalr        $t9
    // 0x800438E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800438E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x800438E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800438E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800438EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800438F0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800438F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800438F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800438FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80043900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043904: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80043908: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004390C: nop

    // 0x80043910: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80043914: beql        $t7, $zero, L_80043964
    if (ctx->r15 == 0) {
        // 0x80043918: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80043964;
    }
    goto skip_3;
    // 0x80043918: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8004391C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043920: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80043924: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80043928: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004392C: nop

    // 0x80043930: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80043934: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80043938: nop

    // 0x8004393C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80043940: bne         $t7, $zero, L_80043958
    if (ctx->r15 != 0) {
        // 0x80043944: nop
    
            goto L_80043958;
    }
    // 0x80043944: nop

    // 0x80043948: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8004394C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80043950: b           L_80043970
    // 0x80043954: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80043970;
    // 0x80043954: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80043958:
    // 0x80043958: b           L_80043970
    // 0x8004395C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80043970;
    // 0x8004395C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80043960: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80043964:
    // 0x80043964: nop

    // 0x80043968: bltz        $t7, L_80043958
    if (SIGNED(ctx->r15) < 0) {
        // 0x8004396C: nop
    
            goto L_80043958;
    }
    // 0x8004396C: nop

L_80043970:
    // 0x80043970: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80043974: jal         0x80042884
    // 0x80043978: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    func_80042884(rdram, ctx);
        goto after_14;
    // 0x80043978: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_14:
    // 0x8004397C: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x80043980: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80043984: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80043988: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004398C: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x80043990: bltz        $a0, L_800439A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043994: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800439A0;
    }
    // 0x80043994: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80043998: b           L_800439A4
    // 0x8004399C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800439A4;
    // 0x8004399C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800439A0:
    // 0x800439A0: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800439A4:
    // 0x800439A4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800439A8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800439AC: jal         0x80044190
    // 0x800439B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_15;
    // 0x800439B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_15:
    // 0x800439B4: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x800439B8: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x800439BC: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x800439C0: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x800439C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800439C8: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800439CC: jal         0x8003FE6C
    // 0x800439D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_16;
    // 0x800439D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x800439D4: b           L_80043CC0
    // 0x800439D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x800439D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800439DC:
    // 0x800439DC: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x800439E0: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x800439E4: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800439E8: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800439EC: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x800439F0: jalr        $t9
    // 0x800439F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x800439F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x800439F8: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800439FC: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80043A00: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x80043A04: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x80043A08: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80043A0C: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x80043A10: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80043A14: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043A18: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80043A1C: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80043A20: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80043A24: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80043A28: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80043A2C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80043A30: jal         0x80044230
    // 0x80043A34: nop

    func_80044230(rdram, ctx);
        goto after_18;
    // 0x80043A34: nop

    after_18:
    // 0x80043A38: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x80043A3C: sh          $t9, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r25;
    // 0x80043A40: sw          $s1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r17;
    // 0x80043A44: sw          $s4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r20;
    // 0x80043A48: sb          $s0, 0xC8($sp)
    MEM_B(0XC8, ctx->r29) = ctx->r16;
    // 0x80043A4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043A50: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x80043A54: jal         0x8003FE6C
    // 0x80043A58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_19;
    // 0x80043A58: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x80043A5C: b           L_80043CC0
    // 0x80043A60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043A60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043A64:
    // 0x80043A64: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80043A68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80043A6C: sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // 0x80043A70: jal         0x80042ECC
    // 0x80043A74: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_80042ECC(rdram, ctx);
        goto after_20;
    // 0x80043A74: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_20:
    // 0x80043A78: lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD0);
    // 0x80043A7C: b           L_80043CBC
    // 0x80043A80: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_80043CBC;
    // 0x80043A80: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80043A84:
    // 0x80043A84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80043A88: jal         0x80042C2C
    // 0x80043A8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80042C2C(rdram, ctx);
        goto after_21;
    // 0x80043A8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_21:
    // 0x80043A90: b           L_80043CC0
    // 0x80043A94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043A94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043A98:
    // 0x80043A98: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80043A9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043AA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80043AA4: beq         $t7, $at, L_80043CBC
    if (ctx->r15 == ctx->r1) {
        // 0x80043AA8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80043CBC;
    }
    // 0x80043AA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043AAC: jal         0x80042B50
    // 0x80043AB0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    func_80042B50(rdram, ctx);
        goto after_22;
    // 0x80043AB0: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    after_22:
    // 0x80043AB4: b           L_80043CC0
    // 0x80043AB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043AB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043ABC:
    // 0x80043ABC: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x80043AC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043AC4: bnel        $t6, $at, L_80043CC0
    if (ctx->r14 != ctx->r1) {
        // 0x80043AC8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80043CC0;
    }
    goto skip_4;
    // 0x80043AC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_4:
    // 0x80043ACC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80043AD0: beq         $s1, $zero, L_80043B20
    if (ctx->r17 == 0) {
        // 0x80043AD4: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80043B20;
    }
    // 0x80043AD4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80043AD8:
    // 0x80043AD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80043ADC: jal         0x80044060
    // 0x80043AE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_80044060(rdram, ctx);
        goto after_23;
    // 0x80043AE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_23:
    // 0x80043AE4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80043AE8: jal         0x800440E0
    // 0x80043AEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800440E0(rdram, ctx);
        goto after_24;
    // 0x80043AEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x80043AF0: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x80043AF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043AF8: beql        $t9, $zero, L_80043B0C
    if (ctx->r25 == 0) {
        // 0x80043AFC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80043B0C;
    }
    goto skip_5;
    // 0x80043AFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_5:
    // 0x80043B00: jal         0x80043D10
    // 0x80043B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80043D10(rdram, ctx);
        goto after_25;
    // 0x80043B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_25:
    // 0x80043B08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80043B0C:
    // 0x80043B0C: jal         0x80042AE0
    // 0x80043B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042AE0(rdram, ctx);
        goto after_26;
    // 0x80043B10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_26:
    // 0x80043B14: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80043B18: bnel        $s1, $zero, L_80043AD8
    if (ctx->r17 != 0) {
        // 0x80043B1C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80043AD8;
    }
    goto skip_6;
    // 0x80043B1C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_6:
L_80043B20:
    // 0x80043B20: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // 0x80043B24: b           L_80043CBC
    // 0x80043B28: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_80043CBC;
    // 0x80043B28: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_80043B2C:
    // 0x80043B2C: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80043B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043B34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043B38: bnel        $t7, $at, L_80043CC0
    if (ctx->r15 != ctx->r1) {
        // 0x80043B3C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80043CC0;
    }
    goto skip_7;
    // 0x80043B3C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_7:
    // 0x80043B40: jal         0x8003FD50
    // 0x80043B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003FD50(rdram, ctx);
        goto after_27;
    // 0x80043B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80043B48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043B4C: jal         0x8003FD50
    // 0x80043B50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8003FD50(rdram, ctx);
        goto after_28;
    // 0x80043B50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x80043B54: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80043B58: beq         $s1, $zero, L_80043B90
    if (ctx->r17 == 0) {
        // 0x80043B5C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80043B90;
    }
    // 0x80043B5C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80043B60:
    // 0x80043B60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80043B64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043B68: jal         0x80042A38
    // 0x80043B6C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_80042A38(rdram, ctx);
        goto after_29;
    // 0x80043B6C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_29:
    // 0x80043B70: beq         $v0, $zero, L_80043B84
    if (ctx->r2 == 0) {
        // 0x80043B74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80043B84;
    }
    // 0x80043B74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043B78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80043B7C: jal         0x8004290C
    // 0x80043B80: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_8004290C(rdram, ctx);
        goto after_30;
    // 0x80043B80: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_30:
L_80043B84:
    // 0x80043B84: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80043B88: bnel        $s1, $zero, L_80043B60
    if (ctx->r17 != 0) {
        // 0x80043B8C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80043B60;
    }
    goto skip_8;
    // 0x80043B8C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_8:
L_80043B90:
    // 0x80043B90: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80043B94: sw          $t8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r24;
    // 0x80043B98: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80043B9C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80043BA0: sh          $t6, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r14;
    // 0x80043BA4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80043BA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043BAC: jal         0x8003FE6C
    // 0x80043BB0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    alEvtqPostEvent(rdram, ctx);
        goto after_31;
    // 0x80043BB0: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_31:
    // 0x80043BB4: b           L_80043CC0
    // 0x80043BB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043BB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043BBC:
    // 0x80043BBC: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80043BC0: lh          $t9, 0x3C($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3C);
    // 0x80043BC4: beq         $s1, $zero, L_80043CBC
    if (ctx->r17 == 0) {
        // 0x80043BC8: sh          $t9, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r25;
            goto L_80043CBC;
    }
    // 0x80043BC8: sh          $t9, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r25;
    // 0x80043BCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80043BD0:
    // 0x80043BD0: jal         0x80042884
    // 0x80043BD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042884(rdram, ctx);
        goto after_32;
    // 0x80043BD4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_32:
    // 0x80043BD8: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x80043BDC: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x80043BE0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80043BE4: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80043BE8: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x80043BEC: bltz        $a0, L_80043BFC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043BF0: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80043BFC;
    }
    // 0x80043BF0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80043BF4: b           L_80043C00
    // 0x80043BF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80043C00;
    // 0x80043BF8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80043BFC:
    // 0x80043BFC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80043C00:
    // 0x80043C00: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80043C04: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80043C08: jal         0x80044190
    // 0x80043C0C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_33;
    // 0x80043C0C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_33:
    // 0x80043C10: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80043C14: bnel        $s1, $zero, L_80043BD0
    if (ctx->r17 != 0) {
        // 0x80043C18: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80043BD0;
    }
    goto skip_9;
    // 0x80043C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_9:
    // 0x80043C1C: b           L_80043CC0
    // 0x80043C20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043C20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043C24:
    // 0x80043C24: lw          $t6, 0x3C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X3C);
    // 0x80043C28: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80043C2C: lw          $t7, 0x44($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X44);
    // 0x80043C30: sw          $t6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r14;
    // 0x80043C34: sw          $t9, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r25;
    // 0x80043C38: b           L_80043CBC
    // 0x80043C3C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
        goto L_80043CBC;
    // 0x80043C3C: sw          $t7, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r15;
L_80043C40:
    // 0x80043C40: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x80043C44: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x80043C48: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x80043C4C: sll         $t9, $s0, 4
    ctx->r25 = S32(ctx->r16 << 4);
    // 0x80043C50: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80043C54: b           L_80043CBC
    // 0x80043C58: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_80043CBC;
    // 0x80043C58: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_80043C5C:
    // 0x80043C5C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80043C60: addiu       $t7, $zero, 0x1E8
    ctx->r15 = ADD32(0, 0X1E8);
    // 0x80043C64: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80043C68: beq         $a1, $zero, L_80043C8C
    if (ctx->r5 == 0) {
        // 0x80043C6C: sw          $a1, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r5;
            goto L_80043C8C;
    }
    // 0x80043C6C: sw          $a1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r5;
    // 0x80043C70: lwc1        $f6, 0x2318($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2318);
    // 0x80043C74: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80043C78: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80043C7C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80043C80: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80043C84: b           L_80043C90
    // 0x80043C88: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
        goto L_80043C90;
    // 0x80043C88: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
L_80043C8C:
    // 0x80043C8C: sw          $t7, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r15;
L_80043C90:
    // 0x80043C90: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x80043C94: beql        $a1, $zero, L_80043CC0
    if (ctx->r5 == 0) {
        // 0x80043C98: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80043CC0;
    }
    goto skip_10;
    // 0x80043C98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x80043C9C: jal         0x800427A4
    // 0x80043CA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800427A4(rdram, ctx);
        goto after_34;
    // 0x80043CA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x80043CA4: b           L_80043CC0
    // 0x80043CA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80043CC0;
    // 0x80043CA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043CAC:
    // 0x80043CAC: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80043CB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80043CB4: jal         0x800427A4
    // 0x80043CB8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    func_800427A4(rdram, ctx);
        goto after_35;
    // 0x80043CB8: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_35:
L_80043CBC:
    // 0x80043CBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80043CC0:
    // 0x80043CC0: jal         0x8003FF90
    // 0x80043CC4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_8003FF90(rdram, ctx);
        goto after_36;
    // 0x80043CC4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_36:
    // 0x80043CC8: beq         $v0, $zero, L_8004372C
    if (ctx->r2 == 0) {
        // 0x80043CCC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_8004372C;
    }
    // 0x80043CCC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80043CD0: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x80043CD4: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x80043CD8: sw          $t9, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r25;
    // 0x80043CDC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80043CE0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80043CE4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80043CE8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80043CEC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80043CF0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80043CF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80043CF8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80043CFC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80043D00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80043D04: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80043D08: jr          $ra
    // 0x80043D0C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80043D0C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80101284_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101284: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80101288: bltz        $t6, L_80101298
    if (SIGNED(ctx->r14) < 0) {
        // 0x8010128C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80101298;
    }
    // 0x8010128C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80101290: jr          $ra
    // 0x80101294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80101294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101298:
    // 0x80101298: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8010129C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801012A0: addiu       $t8, $t8, 0x6FE8
    ctx->r24 = ADD32(ctx->r24, 0X6FE8);
    // 0x801012A4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801012A8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801012AC: lh          $t4, 0x2A($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2A);
    // 0x801012B0: lh          $t5, 0x26($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X26);
    // 0x801012B4: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x801012B8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801012BC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801012C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801012C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801012C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801012CC: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x801012D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801012D4: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x801012D8: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x801012DC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801012E0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801012E4: div.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801012E8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801012EC: nop

    // 0x801012F0: bc1fl       L_80101300
    if (!c1cs) {
        // 0x801012F4: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80101300;
    }
    goto skip_0;
    // 0x801012F4: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x801012F8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x801012FC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
L_80101300:
    // 0x80101300: lh          $t7, 0x2C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2C);
    // 0x80101304: lh          $t8, 0x28($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X28);
    // 0x80101308: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8010130C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80101310: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80101314: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80101318: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x8010131C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80101320: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80101324: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101328: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8010132C: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80101330: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80101334: div.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80101338: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010133C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80101340: nop

    // 0x80101344: bc1fl       L_80101354
    if (!c1cs) {
        // 0x80101348: lwc1        $f8, 0x20($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
            goto L_80101354;
    }
    goto skip_1;
    // 0x80101348: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    skip_1:
    // 0x8010134C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101350: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
L_80101354:
    // 0x80101354: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80101358: lh          $t2, 0x2A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2A);
    // 0x8010135C: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80101360: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80101364: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x80101368: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8010136C: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80101370: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80101374: beq         $at, $zero, L_80101384
    if (ctx->r1 == 0) {
        // 0x80101378: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80101384;
    }
    // 0x80101378: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8010137C: b           L_80101388
    // 0x80101380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80101388;
    // 0x80101380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101384:
    // 0x80101384: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80101388:
    // 0x80101388: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x8010138C: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80101390: ori         $t4, $v0, 0x4
    ctx->r12 = ctx->r2 | 0X4;
    // 0x80101394: ori         $t5, $v0, 0x8
    ctx->r13 = ctx->r2 | 0X8;
    // 0x80101398: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010139C: beql        $at, $zero, L_801013B0
    if (ctx->r1 == 0) {
        // 0x801013A0: negu        $a3, $a2
        ctx->r7 = SUB32(0, ctx->r6);
            goto L_801013B0;
    }
    goto skip_2;
    // 0x801013A0: negu        $a3, $a2
    ctx->r7 = SUB32(0, ctx->r6);
    skip_2:
    // 0x801013A4: b           L_801013B4
    // 0x801013A8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_801013B4;
    // 0x801013A8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x801013AC: negu        $a3, $a2
    ctx->r7 = SUB32(0, ctx->r6);
L_801013B0:
    // 0x801013B0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_801013B4:
    // 0x801013B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801013B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801013BC: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801013C0: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x801013C4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x801013C8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801013CC: addu        $t7, $t1, $a3
    ctx->r15 = ADD32(ctx->r9, ctx->r7);
    // 0x801013D0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x801013D4: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x801013D8: bc1f        L_801013F4
    if (!c1cs) {
        // 0x801013DC: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_801013F4;
    }
    // 0x801013DC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x801013E0: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x801013E4: nop

    // 0x801013E8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801013EC: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801013F0: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
L_801013F4:
    // 0x801013F4: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801013F8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801013FC: nop

    // 0x80101400: bc1fl       L_80101420
    if (!c1cs) {
        // 0x80101404: lh          $t8, 0x24($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X24);
            goto L_80101420;
    }
    goto skip_3;
    // 0x80101404: lh          $t8, 0x24($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x80101408: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x8010140C: nop

    // 0x80101410: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80101414: sub.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80101418: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x8010141C: lh          $t8, 0x24($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X24);
L_80101420:
    // 0x80101420: lw          $t9, 0x38($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X38);
    // 0x80101424: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80101428: bne         $at, $zero, L_80101440
    if (ctx->r1 != 0) {
        // 0x8010142C: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80101440;
    }
    // 0x8010142C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80101430: lh          $t2, 0x2A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2A);
    // 0x80101434: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80101438: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x8010143C: sh          $t3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r11;
L_80101440:
    // 0x80101440: beq         $t4, $zero, L_80101464
    if (ctx->r12 == 0) {
        // 0x80101444: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_80101464;
    }
    // 0x80101444: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x80101448: lh          $a0, 0x2A($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2A);
    // 0x8010144C: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80101450: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80101454: bne         $at, $zero, L_80101484
    if (ctx->r1 != 0) {
        // 0x80101458: nop
    
            goto L_80101484;
    }
    // 0x80101458: nop

    // 0x8010145C: b           L_80101484
    // 0x80101460: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
        goto L_80101484;
    // 0x80101460: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
L_80101464:
    // 0x80101464: beq         $t6, $zero, L_80101484
    if (ctx->r14 == 0) {
        // 0x80101468: nop
    
            goto L_80101484;
    }
    // 0x80101468: nop

    // 0x8010146C: lh          $a0, 0x2A($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2A);
    // 0x80101470: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80101474: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80101478: bne         $at, $zero, L_80101484
    if (ctx->r1 != 0) {
        // 0x8010147C: nop
    
            goto L_80101484;
    }
    // 0x8010147C: nop

    // 0x80101480: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
L_80101484:
    // 0x80101484: beq         $t8, $zero, L_801014A8
    if (ctx->r24 == 0) {
        // 0x80101488: nop
    
            goto L_801014A8;
    }
    // 0x80101488: nop

    // 0x8010148C: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101490: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80101494: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101498: bnel        $at, $zero, L_801014CC
    if (ctx->r1 != 0) {
        // 0x8010149C: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_801014CC;
    }
    goto skip_4;
    // 0x8010149C: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x801014A0: b           L_801014C8
    // 0x801014A4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
        goto L_801014C8;
    // 0x801014A4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_801014A8:
    // 0x801014A8: beql        $t2, $zero, L_801014CC
    if (ctx->r10 == 0) {
        // 0x801014AC: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_801014CC;
    }
    goto skip_5;
    // 0x801014AC: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_5:
    // 0x801014B0: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x801014B4: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x801014B8: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801014BC: bnel        $at, $zero, L_801014CC
    if (ctx->r1 != 0) {
        // 0x801014C0: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_801014CC;
    }
    goto skip_6;
    // 0x801014C0: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_6:
    // 0x801014C4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_801014C8:
    // 0x801014C8: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
L_801014CC:
    // 0x801014CC: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    // 0x801014D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801014D4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801014D8: bne         $at, $zero, L_801014F8
    if (ctx->r1 != 0) {
        // 0x801014DC: nop
    
            goto L_801014F8;
    }
    // 0x801014DC: nop

    // 0x801014E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801014E4: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x801014E8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801014EC: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801014F0: jr          $ra
    // 0x801014F4: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x801014F4: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_801014F8:
    // 0x801014F8: jr          $ra
    // 0x801014FC: nop

    return;
    // 0x801014FC: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042500: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80042504: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80042508: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004250C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80042510: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80042514: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80042518: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004251C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80042520: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80042524: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80042528: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8004252C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80042530: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80042534: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80042538: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x8004253C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80042540: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80042544: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80042548: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8004254C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x80042550: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80042554: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80042558: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8004255C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80042560: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80042564: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80042568: blez        $t8, L_800425AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004256C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_800425AC;
    }
    // 0x8004256C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x80042570: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80042574:
    // 0x80042574: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80042578: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8004257C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80042580: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80042584: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80042588: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8004258C: jalr        $t9
    // 0x80042590: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80042590: nop

    after_0:
    // 0x80042594: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x80042598: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004259C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800425A0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800425A4: bne         $at, $zero, L_80042574
    if (ctx->r1 != 0) {
        // 0x800425A8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80042574;
    }
    // 0x800425A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800425AC:
    // 0x800425AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800425B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800425B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800425B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800425BC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800425C0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800425C4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800425C8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800425CC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800425D0: jr          $ra
    // 0x800425D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800425D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80006604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006608: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000660C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80006610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006614: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80006618: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000661C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006620: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80006624: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80006628: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000662C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006630: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80006634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006638: jal         0x8001D8B0
    // 0x8000663C: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x8000663C: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    after_0:
    // 0x80006640: jal         0x80006720
    // 0x80006644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80006720(rdram, ctx);
        goto after_1;
    // 0x80006644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80006648: lh          $t8, 0x52($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X52);
    // 0x8000664C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80006650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006654: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80006658: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8000665C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006660: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80006664: jal         0x8001D924
    // 0x80006668: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    func_8001D924(rdram, ctx);
        goto after_2;
    // 0x80006668: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x8000666C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80006670: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80006674: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x80006678: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x8000667C: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x80006680: lhu         $t3, 0x60($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X60);
    // 0x80006684: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80006688: sh          $t4, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r12;
    // 0x8000668C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006690: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006694: jr          $ra
    // 0x80006698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80014840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014840: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014844: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014848: addiu       $v0, $v0, 0x7170
    ctx->r2 = ADD32(ctx->r2, 0X7170);
    // 0x8001484C: addiu       $v1, $v1, 0x6F18
    ctx->r3 = ADD32(ctx->r3, 0X6F18);
L_80014850:
    // 0x80014850: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x80014854: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80014858: bne         $at, $zero, L_80014850
    if (ctx->r1 != 0) {
        // 0x8001485C: sh          $zero, -0x38($v1)
        MEM_H(-0X38, ctx->r3) = 0;
            goto L_80014850;
    }
    // 0x8001485C: sh          $zero, -0x38($v1)
    MEM_H(-0X38, ctx->r3) = 0;
    // 0x80014860: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014864: sh          $zero, 0x7170($at)
    MEM_H(0X7170, ctx->r1) = 0;
    // 0x80014868: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001486C: sh          $zero, 0x7188($at)
    MEM_H(0X7188, ctx->r1) = 0;
    // 0x80014870: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014874: sh          $zero, 0x71A0($at)
    MEM_H(0X71A0, ctx->r1) = 0;
    // 0x80014878: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001487C: sh          $zero, 0x71B8($at)
    MEM_H(0X71B8, ctx->r1) = 0;
    // 0x80014880: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014884: sw          $zero, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = 0;
    // 0x80014888: jr          $ra
    // 0x8001488C: nop

    return;
    // 0x8001488C: nop

;}
RECOMP_FUNC void func_80100970_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100970: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80100974: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80100978: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8010097C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80100980: addiu       $v0, $v0, 0x6FE8
    ctx->r2 = ADD32(ctx->r2, 0X6FE8);
    // 0x80100984: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80100988: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8010098C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80100990:
    // 0x80100990: sh          $zero, 0x80($v0)
    MEM_H(0X80, ctx->r2) = 0;
    // 0x80100994: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x80100998: lh          $t7, 0x80($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X80);
    // 0x8010099C: lh          $t6, 0x30($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X30);
    // 0x801009A0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x801009A4: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
    // 0x801009A8: sh          $zero, 0x54($v0)
    MEM_H(0X54, ctx->r2) = 0;
    // 0x801009AC: sh          $zero, 0x56($v0)
    MEM_H(0X56, ctx->r2) = 0;
    // 0x801009B0: sh          $zero, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = 0;
    // 0x801009B4: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x801009B8: sh          $zero, 0x58($v0)
    MEM_H(0X58, ctx->r2) = 0;
    // 0x801009BC: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
    // 0x801009C0: sh          $zero, 0x60($v0)
    MEM_H(0X60, ctx->r2) = 0;
    // 0x801009C4: sh          $zero, 0x62($v0)
    MEM_H(0X62, ctx->r2) = 0;
    // 0x801009C8: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x801009CC: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x801009D0: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x801009D4: sh          $a0, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r4;
    // 0x801009D8: sh          $zero, 0x82($v0)
    MEM_H(0X82, ctx->r2) = 0;
    // 0x801009DC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x801009E0: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x801009E4: sh          $zero, 0x74($v0)
    MEM_H(0X74, ctx->r2) = 0;
    // 0x801009E8: sh          $zero, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = 0;
    // 0x801009EC: sh          $zero, 0x7C($v0)
    MEM_H(0X7C, ctx->r2) = 0;
    // 0x801009F0: sh          $zero, 0x76($v0)
    MEM_H(0X76, ctx->r2) = 0;
    // 0x801009F4: sh          $zero, 0x78($v0)
    MEM_H(0X78, ctx->r2) = 0;
    // 0x801009F8: sh          $zero, 0x84($v0)
    MEM_H(0X84, ctx->r2) = 0;
    // 0x801009FC: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x80100A00: swc1        $f2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f2.u32l;
    // 0x80100A04: sh          $zero, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = 0;
    // 0x80100A08: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x80100A0C: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x80100A10: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x80100A14: sw          $zero, -0xA0($v0)
    MEM_W(-0XA0, ctx->r2) = 0;
    // 0x80100A18: sh          $zero, -0x9C($v0)
    MEM_H(-0X9C, ctx->r2) = 0;
    // 0x80100A1C: sh          $zero, -0x9A($v0)
    MEM_H(-0X9A, ctx->r2) = 0;
    // 0x80100A20: sh          $zero, -0x94($v0)
    MEM_H(-0X94, ctx->r2) = 0;
    // 0x80100A24: sh          $zero, -0x92($v0)
    MEM_H(-0X92, ctx->r2) = 0;
    // 0x80100A28: sh          $zero, -0x98($v0)
    MEM_H(-0X98, ctx->r2) = 0;
    // 0x80100A2C: sh          $zero, -0x96($v0)
    MEM_H(-0X96, ctx->r2) = 0;
    // 0x80100A30: sh          $zero, -0x90($v0)
    MEM_H(-0X90, ctx->r2) = 0;
    // 0x80100A34: sh          $zero, -0x8E($v0)
    MEM_H(-0X8E, ctx->r2) = 0;
    // 0x80100A38: sw          $zero, -0x8C($v0)
    MEM_W(-0X8C, ctx->r2) = 0;
    // 0x80100A3C: sw          $zero, -0x88($v0)
    MEM_W(-0X88, ctx->r2) = 0;
    // 0x80100A40: swc1        $f0, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80100A44: sh          $a0, -0x52($v0)
    MEM_H(-0X52, ctx->r2) = ctx->r4;
    // 0x80100A48: sh          $zero, -0x6E($v0)
    MEM_H(-0X6E, ctx->r2) = 0;
    // 0x80100A4C: swc1        $f0, -0x84($v0)
    MEM_W(-0X84, ctx->r2) = ctx->f0.u32l;
    // 0x80100A50: swc1        $f0, -0x80($v0)
    MEM_W(-0X80, ctx->r2) = ctx->f0.u32l;
    // 0x80100A54: sh          $zero, -0x7C($v0)
    MEM_H(-0X7C, ctx->r2) = 0;
    // 0x80100A58: sh          $zero, -0x76($v0)
    MEM_H(-0X76, ctx->r2) = 0;
    // 0x80100A5C: sh          $zero, -0x74($v0)
    MEM_H(-0X74, ctx->r2) = 0;
    // 0x80100A60: sh          $zero, -0x7A($v0)
    MEM_H(-0X7A, ctx->r2) = 0;
    // 0x80100A64: sh          $zero, -0x78($v0)
    MEM_H(-0X78, ctx->r2) = 0;
    // 0x80100A68: sh          $zero, -0x6C($v0)
    MEM_H(-0X6C, ctx->r2) = 0;
    // 0x80100A6C: swc1        $f0, -0x60($v0)
    MEM_W(-0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80100A70: swc1        $f2, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80100A74: sh          $zero, -0x54($v0)
    MEM_H(-0X54, ctx->r2) = 0;
    // 0x80100A78: sw          $zero, -0x68($v0)
    MEM_W(-0X68, ctx->r2) = 0;
    // 0x80100A7C: sw          $zero, -0x64($v0)
    MEM_W(-0X64, ctx->r2) = 0;
    // 0x80100A80: sh          $t7, -0x22($v0)
    MEM_H(-0X22, ctx->r2) = ctx->r15;
    // 0x80100A84: bne         $v1, $a1, L_80100990
    if (ctx->r3 != ctx->r5) {
        // 0x80100A88: sh          $t6, -0x72($v0)
        MEM_H(-0X72, ctx->r2) = ctx->r14;
            goto L_80100990;
    }
    // 0x80100A88: sh          $t6, -0x72($v0)
    MEM_H(-0X72, ctx->r2) = ctx->r14;
    // 0x80100A8C: jr          $ra
    // 0x80100A90: nop

    return;
    // 0x80100A90: nop

;}
RECOMP_FUNC void func_80020988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020988: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8002098C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80020990: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80020994: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80020998: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002099C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800209A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800209A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800209A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800209AC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800209B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800209B4: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800209B8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x800209BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800209C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800209C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800209C8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800209CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800209D0: lui         $t9, 0x803A
    ctx->r25 = S32(0X803A << 16);
    // 0x800209D4: addiu       $t9, $t9, 0x2960
    ctx->r25 = ADD32(ctx->r25, 0X2960);
    // 0x800209D8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800209DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800209E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800209E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800209E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800209EC: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x800209F0: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x800209F4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800209F8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800209FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020A00: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80020A04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020A08: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x80020A0C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80020A10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020A14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80020A18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80020A1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80020A20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020A24: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80020A28: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80020A2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020A30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80020A34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020A38: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80020A3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020A40: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80020A44: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80020A48: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80020A4C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80020A50: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80020A54: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80020A58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020A5C: addiu       $s0, $s0, -0x3998
    ctx->r16 = ADD32(ctx->r16, -0X3998);
    // 0x80020A60: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80020A64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80020A68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80020A6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020A70: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80020A74: lui         $s4, 0x803A
    ctx->r20 = S32(0X803A << 16);
    // 0x80020A78: addiu       $s4, $s4, 0x6F70
    ctx->r20 = ADD32(ctx->r20, 0X6F70);
    // 0x80020A7C: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80020A80: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_80020A84:
    // 0x80020A84: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x80020A88: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80020A8C: beql        $t9, $zero, L_80020B24
    if (ctx->r25 == 0) {
        // 0x80020A90: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80020B24;
    }
    goto skip_0;
    // 0x80020A90: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x80020A94: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80020A98: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80020A9C: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80020AA0: beq         $v0, $zero, L_80020AC0
    if (ctx->r2 == 0) {
        // 0x80020AA4: lwc1        $f0, 0x10($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80020AC0;
    }
    // 0x80020AA4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80020AA8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020AAC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020AB0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020AB4: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80020AB8: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80020ABC: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80020AC0:
    // 0x80020AC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80020AC4: jal         0x8002413C
    // 0x80020AC8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x80020AC8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x80020ACC: lhu         $v0, 0x1A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1A);
    // 0x80020AD0: lhu         $a3, 0x18($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X18);
    // 0x80020AD4: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80020AD8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80020ADC: lhu         $t7, 0x14($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X14);
    // 0x80020AE0: sra         $t5, $a3, 1
    ctx->r13 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80020AE4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80020AE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80020AEC: lhu         $t8, 0x16($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X16);
    // 0x80020AF0: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x80020AF4: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80020AF8: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80020AFC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80020B00: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80020B04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80020B08: subu        $a2, $t6, $v0
    ctx->r6 = SUB32(ctx->r14, ctx->r2);
    // 0x80020B0C: jal         0x800210FC
    // 0x80020B10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x80020B10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x80020B14: lhu         $t5, 0x0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X0);
    // 0x80020B18: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80020B1C: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80020B20: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80020B24:
    // 0x80020B24: bne         $s1, $zero, L_80020A84
    if (ctx->r17 != 0) {
        // 0x80020B28: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80020A84;
    }
    // 0x80020B28: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80020B2C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80020B30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80020B34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80020B38: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80020B3C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80020B40: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80020B44: jr          $ra
    // 0x80020B48: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80020B48: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800195E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800195E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800195E4: ldc1        $f14, 0x1598($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1598);
    // 0x800195E8: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800195EC: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800195F0: lwc1        $f2, 0x34($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800195F4: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800195F8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800195FC: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80019600: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80019604: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80019608: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8001960C: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80019610: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x80019614: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80019618: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8001961C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80019620: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80019624: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80019628: mul.d       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8001962C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80019630: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80019634: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80019638: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001963C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80019640: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x80019644: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80019648: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x8001964C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80019650: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80019654: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80019658: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8001965C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80019660: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x80019664: ldc1        $f18, 0x15A0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X15A0);
    // 0x80019668: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001966C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80019670: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80019674: beq         $at, $zero, L_80019690
    if (ctx->r1 == 0) {
        // 0x80019678: swc1        $f6, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
            goto L_80019690;
    }
    // 0x80019678: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8001967C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019680: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019684: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80019688: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8001968C: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
L_80019690:
    // 0x80019690: lbu         $t6, 0x3C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3C);
    // 0x80019694: addiu       $t8, $t8, -0x42E4
    ctx->r24 = ADD32(ctx->r24, -0X42E4);
    // 0x80019698: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8001969C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800196A0: beq         $t9, $zero, L_800196F4
    if (ctx->r25 == 0) {
        // 0x800196A4: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_800196F4;
    }
    // 0x800196A4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800196A8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800196AC: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x800196B0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800196B4: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x800196B8: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
    // 0x800196BC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800196C0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800196C4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800196C8: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x800196CC: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x800196D0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800196D4: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800196D8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800196DC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800196E0: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800196E4: ori         $t3, $t2, 0xDC
    ctx->r11 = ctx->r10 | 0XDC;
    // 0x800196E8: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800196EC: jr          $ra
    // 0x800196F0: nop

    return;
    // 0x800196F0: nop

L_800196F4:
    // 0x800196F4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800196F8: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800196FC: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80019700: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80019704: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80019708: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8001970C: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80019710: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x80019714: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x80019718: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8001971C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80019720: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80019724: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x80019728: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x8001972C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80019730: jr          $ra
    // 0x80019734: nop

    return;
    // 0x80019734: nop

;}
RECOMP_FUNC void func_8001B448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B448: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8001B44C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8001B450: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001B454: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    // 0x8001B458: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001B45C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001B460: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8001B464: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8001B468: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8001B46C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001B470: sw          $a1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r5;
    // 0x8001B474: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001B478: addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // 0x8001B47C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001B480:
    // 0x8001B480: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x8001B484: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001B488: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001B48C: beql        $at, $zero, L_8001B4AC
    if (ctx->r1 == 0) {
        // 0x8001B490: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8001B4AC;
    }
    goto skip_0;
    // 0x8001B490: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8001B494: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001B498: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x8001B49C: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x8001B4A0: bne         $at, $zero, L_8001B480
    if (ctx->r1 != 0) {
        // 0x8001B4A4: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_8001B480;
    }
    // 0x8001B4A4: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8001B4A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8001B4AC:
    // 0x8001B4AC: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x8001B4B0: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8001B4B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B4B8:
    // 0x8001B4B8: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B4BC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8001B4C0: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001B4C4: beql        $at, $zero, L_8001B4E4
    if (ctx->r1 == 0) {
        // 0x8001B4C8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B4E4;
    }
    goto skip_1;
    // 0x8001B4C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8001B4CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B4D0: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001B4D4: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x8001B4D8: bne         $at, $zero, L_8001B4B8
    if (ctx->r1 != 0) {
        // 0x8001B4DC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8001B4B8;
    }
    // 0x8001B4DC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8001B4E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B4E4:
    // 0x8001B4E4: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001B4E8: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x8001B4EC: beq         $at, $zero, L_8001C540
    if (ctx->r1 == 0) {
        // 0x8001B4F0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8001C540;
    }
    // 0x8001B4F0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8001B4F4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001B4F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001B4FC: addu        $at, $at, $t7
    gpr jr_addend_8001B504 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001B500: lw          $t7, 0x15F0($at)
    ctx->r15 = ADD32(ctx->r1, 0X15F0);
    // 0x8001B504: jr          $t7
    // 0x8001B508: nop

    switch (jr_addend_8001B504 >> 2) {
        case 0: goto L_8001B50C; break;
        case 1: goto L_8001B70C; break;
        case 2: goto L_8001B910; break;
        case 3: goto L_8001BB1C; break;
        case 4: goto L_8001BD28; break;
        case 5: goto L_8001BF2C; break;
        case 6: goto L_8001C130; break;
        case 7: goto L_8001C338; break;
        default: switch_error(__func__, 0x8001B504, 0x800715F0);
    }
    // 0x8001B508: nop

L_8001B50C:
    // 0x8001B50C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001B510: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001B514: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B518: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8001B51C: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001B520: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B524: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B528: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B52C: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x8001B530: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8001B534: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001B538: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001B53C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001B540: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001B544: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x8001B548: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8001B54C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001B550: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8001B554: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001B558: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001B55C: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x8001B560: andi        $t9, $t4, 0x3
    ctx->r25 = ctx->r12 & 0X3;
    // 0x8001B564: sll         $t4, $t9, 18
    ctx->r12 = S32(ctx->r25 << 18);
    // 0x8001B568: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8001B56C: andi        $t8, $s1, 0x3
    ctx->r24 = ctx->r17 & 0X3;
    // 0x8001B570: sll         $s1, $t8, 8
    ctx->r17 = S32(ctx->r24 << 8);
    // 0x8001B574: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8001B578: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x8001B57C: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x8001B580: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8001B584: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x8001B588: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8001B58C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001B590: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8001B594: sll         $a1, $s0, 1
    ctx->r5 = S32(ctx->r16 << 1);
    // 0x8001B598: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8001B59C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001B5A0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001B5A4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001B5A8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B5AC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001B5B0: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8001B5B4: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001B5B8: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x8001B5BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B5C0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8001B5C4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001B5C8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001B5CC: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001B5D0: beq         $at, $zero, L_8001B5E0
    if (ctx->r1 == 0) {
        // 0x8001B5D4: nop
    
            goto L_8001B5E0;
    }
    // 0x8001B5D4: nop

    // 0x8001B5D8: b           L_8001B5E0
    // 0x8001B5DC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001B5E0;
    // 0x8001B5DC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001B5E0:
    // 0x8001B5E0: bgez        $a1, L_8001B5F0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8001B5E4: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8001B5F0;
    }
    // 0x8001B5E4: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8001B5E8: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8001B5EC: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8001B5F0:
    // 0x8001B5F0: bgtz        $v0, L_8001B600
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B5F4: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001B600;
    }
    // 0x8001B5F4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001B5F8: b           L_8001B600
    // 0x8001B5FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001B600;
    // 0x8001B5FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001B600:
    // 0x8001B600: bgtz        $v0, L_8001B610
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B604: addiu       $t7, $t1, 0x7FF
        ctx->r15 = ADD32(ctx->r9, 0X7FF);
            goto L_8001B610;
    }
    // 0x8001B604: addiu       $t7, $t1, 0x7FF
    ctx->r15 = ADD32(ctx->r9, 0X7FF);
    // 0x8001B608: b           L_8001B614
    // 0x8001B60C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001B614;
    // 0x8001B60C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001B610:
    // 0x8001B610: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001B614:
    // 0x8001B614: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x8001B618: bne         $v1, $zero, L_8001B624
    if (ctx->r3 != 0) {
        // 0x8001B61C: nop
    
            goto L_8001B624;
    }
    // 0x8001B61C: nop

    // 0x8001B620: break       7
    do_break(2147595808);
L_8001B624:
    // 0x8001B624: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B628: bne         $v1, $at, L_8001B63C
    if (ctx->r3 != ctx->r1) {
        // 0x8001B62C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B63C;
    }
    // 0x8001B62C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B630: bne         $t7, $at, L_8001B63C
    if (ctx->r15 != ctx->r1) {
        // 0x8001B634: nop
    
            goto L_8001B63C;
    }
    // 0x8001B634: nop

    // 0x8001B638: break       6
    do_break(2147595832);
L_8001B63C:
    // 0x8001B63C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B640: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8001B644: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001B648: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x8001B64C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8001B650: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8001B654: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001B658: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8001B65C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B660: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8001B664: addiu       $t9, $a1, 0x7
    ctx->r25 = ADD32(ctx->r5, 0X7);
    // 0x8001B668: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001B66C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001B670: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001B674: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001B678: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B67C: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8001B680: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8001B684: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B688: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B68C: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8001B690: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x8001B694: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8001B698: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8001B69C: or          $t6, $t7, $s1
    ctx->r14 = ctx->r15 | ctx->r17;
    // 0x8001B6A0: or          $t8, $t6, $s2
    ctx->r24 = ctx->r14 | ctx->r18;
    // 0x8001B6A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001B6A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B6AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B6B0: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8001B6B4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001B6B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001B6BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B6C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8001B6C4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8001B6C8: addiu       $t6, $s3, -0x1
    ctx->r14 = ADD32(ctx->r19, -0X1);
    // 0x8001B6CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B6D0: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8001B6D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001B6D8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8001B6DC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001B6E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001B6E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B6E8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8001B6EC: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x8001B6F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B6F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B6F8: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // 0x8001B6FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001B700: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B704: b           L_8001C544
    // 0x8001B708: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001B708: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001B70C:
    // 0x8001B70C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001B710: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001B714: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001B718: lui         $t8, 0xFD18
    ctx->r24 = S32(0XFD18 << 16);
    // 0x8001B71C: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001B720: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001B724: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001B728: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001B72C: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001B730: lui         $t6, 0xF518
    ctx->r14 = S32(0XF518 << 16);
    // 0x8001B734: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001B738: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001B73C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001B740: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001B744: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001B748: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001B74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B750: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001B754: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001B758: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001B75C: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001B760: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001B764: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001B768: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001B76C: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001B770: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001B774: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001B778: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001B77C: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001B780: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001B784: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001B788: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001B78C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001B790: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001B794: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8001B798: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001B79C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B7A0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001B7A4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001B7A8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B7AC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001B7B0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001B7B4: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001B7B8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8001B7BC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B7C0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001B7C4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001B7C8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001B7CC: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001B7D0: beq         $at, $zero, L_8001B7E0
    if (ctx->r1 == 0) {
        // 0x8001B7D4: nop
    
            goto L_8001B7E0;
    }
    // 0x8001B7D4: nop

    // 0x8001B7D8: b           L_8001B7E0
    // 0x8001B7DC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001B7E0;
    // 0x8001B7DC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001B7E0:
    // 0x8001B7E0: bgez        $v0, L_8001B7F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B7E4: sra         $t9, $v0, 3
        ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8001B7F0;
    }
    // 0x8001B7E4: sra         $t9, $v0, 3
    ctx->r25 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8001B7E8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8001B7EC: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8001B7F0:
    // 0x8001B7F0: bgtz        $t9, L_8001B800
    if (SIGNED(ctx->r25) > 0) {
        // 0x8001B7F4: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8001B800;
    }
    // 0x8001B7F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001B7F8: b           L_8001B804
    // 0x8001B7FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001B804;
    // 0x8001B7FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001B800:
    // 0x8001B800: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8001B804:
    // 0x8001B804: bgtz        $v0, L_8001B814
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B808: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001B814;
    }
    // 0x8001B808: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001B80C: b           L_8001B818
    // 0x8001B810: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001B818;
    // 0x8001B810: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001B814:
    // 0x8001B814: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001B818:
    // 0x8001B818: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001B81C: bne         $v1, $zero, L_8001B828
    if (ctx->r3 != 0) {
        // 0x8001B820: nop
    
            goto L_8001B828;
    }
    // 0x8001B820: nop

    // 0x8001B824: break       7
    do_break(2147596324);
L_8001B828:
    // 0x8001B828: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B82C: bne         $v1, $at, L_8001B840
    if (ctx->r3 != ctx->r1) {
        // 0x8001B830: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B840;
    }
    // 0x8001B830: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B834: bne         $t6, $at, L_8001B840
    if (ctx->r14 != ctx->r1) {
        // 0x8001B838: nop
    
            goto L_8001B840;
    }
    // 0x8001B838: nop

    // 0x8001B83C: break       6
    do_break(2147596348);
L_8001B840:
    // 0x8001B840: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B844: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001B848: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001B84C: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001B850: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001B854: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001B858: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001B85C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8001B860: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B864: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001B868: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x8001B86C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001B870: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001B874: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001B878: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B87C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B880: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8001B884: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001B888: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B88C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B890: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001B894: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001B898: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001B89C: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8001B8A0: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001B8A4: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001B8A8: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001B8AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001B8B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001B8B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B8B8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001B8BC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001B8C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001B8C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001B8C8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001B8CC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001B8D0: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001B8D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B8D8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001B8DC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001B8E0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001B8E4: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001B8E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001B8EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B8F0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001B8F4: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001B8F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001B8FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001B900: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001B904: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B908: b           L_8001C544
    // 0x8001B90C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001B90C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001B910:
    // 0x8001B910: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001B914: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001B918: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001B91C: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8001B920: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001B924: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001B928: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001B92C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001B930: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001B934: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x8001B938: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001B93C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001B940: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001B944: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001B948: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001B94C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001B950: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B954: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001B958: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001B95C: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001B960: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001B964: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001B968: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001B96C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001B970: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001B974: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001B978: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001B97C: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001B980: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001B984: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001B988: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001B98C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001B990: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001B994: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001B998: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8001B99C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001B9A0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001B9A4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001B9A8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001B9AC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B9B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001B9B4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001B9B8: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001B9BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B9C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001B9C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B9C8: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x8001B9CC: mflo        $t1
    ctx->r9 = lo;
    // 0x8001B9D0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001B9D4: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001B9D8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8001B9DC: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001B9E0: beq         $at, $zero, L_8001B9F0
    if (ctx->r1 == 0) {
        // 0x8001B9E4: nop
    
            goto L_8001B9F0;
    }
    // 0x8001B9E4: nop

    // 0x8001B9E8: b           L_8001B9F0
    // 0x8001B9EC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001B9F0;
    // 0x8001B9EC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001B9F0:
    // 0x8001B9F0: bgez        $t2, L_8001BA00
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001B9F4: sra         $v0, $t2, 3
        ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8001BA00;
    }
    // 0x8001B9F4: sra         $v0, $t2, 3
    ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8001B9F8: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8001B9FC: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8001BA00:
    // 0x8001BA00: bgtz        $v0, L_8001BA10
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BA04: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001BA10;
    }
    // 0x8001BA04: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001BA08: b           L_8001BA10
    // 0x8001BA0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001BA10;
    // 0x8001BA0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001BA10:
    // 0x8001BA10: bgtz        $v0, L_8001BA20
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BA14: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001BA20;
    }
    // 0x8001BA14: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001BA18: b           L_8001BA24
    // 0x8001BA1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001BA24;
    // 0x8001BA1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BA20:
    // 0x8001BA20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BA24:
    // 0x8001BA24: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001BA28: bne         $v1, $zero, L_8001BA34
    if (ctx->r3 != 0) {
        // 0x8001BA2C: nop
    
            goto L_8001BA34;
    }
    // 0x8001BA2C: nop

    // 0x8001BA30: break       7
    do_break(2147596848);
L_8001BA34:
    // 0x8001BA34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BA38: bne         $v1, $at, L_8001BA4C
    if (ctx->r3 != ctx->r1) {
        // 0x8001BA3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BA4C;
    }
    // 0x8001BA3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BA40: bne         $t6, $at, L_8001BA4C
    if (ctx->r14 != ctx->r1) {
        // 0x8001BA44: nop
    
            goto L_8001BA4C;
    }
    // 0x8001BA44: nop

    // 0x8001BA48: break       6
    do_break(2147596872);
L_8001BA4C:
    // 0x8001BA4C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001BA50: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001BA54: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001BA58: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001BA5C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8001BA60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BA64: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001BA68: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001BA6C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8001BA70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BA74: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8001BA78: addiu       $t6, $t2, 0x7
    ctx->r14 = ADD32(ctx->r10, 0X7);
    // 0x8001BA7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001BA80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BA84: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BA88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001BA8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BA90: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001BA94: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001BA98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001BA9C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001BAA0: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001BAA4: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001BAA8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8001BAAC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001BAB0: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001BAB4: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001BAB8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001BABC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001BAC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BAC4: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001BAC8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BACC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001BAD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAD4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BAD8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001BADC: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001BAE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BAE4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001BAE8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BAEC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BAF0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001BAF4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001BAF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BAFC: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001BB00: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001BB04: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001BB08: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001BB0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BB10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BB14: b           L_8001C544
    // 0x8001BB18: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001BB18: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001BB1C:
    // 0x8001BB1C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001BB20: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001BB24: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001BB28: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8001BB2C: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001BB30: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001BB34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BB38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001BB3C: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001BB40: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8001BB44: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001BB48: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001BB4C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001BB50: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BB54: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001BB58: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001BB5C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BB60: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001BB64: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001BB68: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001BB6C: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001BB70: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001BB74: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001BB78: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001BB7C: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001BB80: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001BB84: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001BB88: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001BB8C: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001BB90: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001BB94: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001BB98: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001BB9C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001BBA0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001BBA4: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8001BBA8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001BBAC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BBB0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001BBB4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001BBB8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BBBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BBC0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001BBC4: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001BBC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001BBCC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001BBD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001BBD4: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8001BBD8: mflo        $t1
    ctx->r9 = lo;
    // 0x8001BBDC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001BBE0: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001BBE4: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8001BBE8: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001BBEC: beq         $at, $zero, L_8001BBFC
    if (ctx->r1 == 0) {
        // 0x8001BBF0: nop
    
            goto L_8001BBFC;
    }
    // 0x8001BBF0: nop

    // 0x8001BBF4: b           L_8001BBFC
    // 0x8001BBF8: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001BBFC;
    // 0x8001BBF8: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001BBFC:
    // 0x8001BBFC: bgez        $t2, L_8001BC0C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001BC00: sra         $v0, $t2, 3
        ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8001BC0C;
    }
    // 0x8001BC00: sra         $v0, $t2, 3
    ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8001BC04: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8001BC08: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8001BC0C:
    // 0x8001BC0C: bgtz        $v0, L_8001BC1C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BC10: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001BC1C;
    }
    // 0x8001BC10: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001BC14: b           L_8001BC1C
    // 0x8001BC18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001BC1C;
    // 0x8001BC18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001BC1C:
    // 0x8001BC1C: bgtz        $v0, L_8001BC2C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BC20: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001BC2C;
    }
    // 0x8001BC20: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001BC24: b           L_8001BC30
    // 0x8001BC28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001BC30;
    // 0x8001BC28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BC2C:
    // 0x8001BC2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BC30:
    // 0x8001BC30: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001BC34: bne         $v1, $zero, L_8001BC40
    if (ctx->r3 != 0) {
        // 0x8001BC38: nop
    
            goto L_8001BC40;
    }
    // 0x8001BC38: nop

    // 0x8001BC3C: break       7
    do_break(2147597372);
L_8001BC40:
    // 0x8001BC40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BC44: bne         $v1, $at, L_8001BC58
    if (ctx->r3 != ctx->r1) {
        // 0x8001BC48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BC58;
    }
    // 0x8001BC48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BC4C: bne         $t6, $at, L_8001BC58
    if (ctx->r14 != ctx->r1) {
        // 0x8001BC50: nop
    
            goto L_8001BC58;
    }
    // 0x8001BC50: nop

    // 0x8001BC54: break       6
    do_break(2147597396);
L_8001BC58:
    // 0x8001BC58: mflo        $t8
    ctx->r24 = lo;
    // 0x8001BC5C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001BC60: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001BC64: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001BC68: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8001BC6C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BC70: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001BC74: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001BC78: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8001BC7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BC80: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8001BC84: addiu       $t6, $t2, 0x7
    ctx->r14 = ADD32(ctx->r10, 0X7);
    // 0x8001BC88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001BC8C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BC90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BC94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001BC98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BC9C: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001BCA0: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001BCA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001BCA8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001BCAC: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001BCB0: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001BCB4: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8001BCB8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001BCBC: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001BCC0: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001BCC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001BCC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001BCCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BCD0: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001BCD4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BCD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001BCDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BCE0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BCE4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001BCE8: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001BCEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BCF0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001BCF4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BCF8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BCFC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001BD00: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001BD04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BD08: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001BD0C: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001BD10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001BD14: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001BD18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BD1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BD20: b           L_8001C544
    // 0x8001BD24: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001BD24: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001BD28:
    // 0x8001BD28: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001BD2C: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001BD30: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001BD34: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8001BD38: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001BD3C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001BD40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BD44: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001BD48: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001BD4C: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x8001BD50: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001BD54: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001BD58: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001BD5C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BD60: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001BD64: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001BD68: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BD6C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001BD70: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001BD74: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001BD78: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001BD7C: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001BD80: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001BD84: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001BD88: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001BD8C: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001BD90: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001BD94: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001BD98: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001BD9C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001BDA0: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001BDA4: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001BDA8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001BDAC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001BDB0: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001BDB4: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001BDB8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BDBC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001BDC0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001BDC4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BDC8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001BDCC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001BDD0: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8001BDD4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001BDD8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001BDDC: mflo        $t1
    ctx->r9 = lo;
    // 0x8001BDE0: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x8001BDE4: sra         $t9, $t1, 2
    ctx->r25 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8001BDE8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8001BDEC: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001BDF0: beq         $at, $zero, L_8001BE00
    if (ctx->r1 == 0) {
        // 0x8001BDF4: nop
    
            goto L_8001BE00;
    }
    // 0x8001BDF4: nop

    // 0x8001BDF8: b           L_8001BE00
    // 0x8001BDFC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001BE00;
    // 0x8001BDFC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001BE00:
    // 0x8001BE00: bgez        $s0, L_8001BE10
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001BE04: sra         $v0, $s0, 4
        ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
            goto L_8001BE10;
    }
    // 0x8001BE04: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8001BE08: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x8001BE0C: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_8001BE10:
    // 0x8001BE10: bgtz        $v0, L_8001BE20
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BE14: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001BE20;
    }
    // 0x8001BE14: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001BE18: b           L_8001BE20
    // 0x8001BE1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001BE20;
    // 0x8001BE1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001BE20:
    // 0x8001BE20: bgtz        $v0, L_8001BE30
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001BE24: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001BE30;
    }
    // 0x8001BE24: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001BE28: b           L_8001BE34
    // 0x8001BE2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001BE34;
    // 0x8001BE2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BE30:
    // 0x8001BE30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001BE34:
    // 0x8001BE34: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001BE38: bne         $v1, $zero, L_8001BE44
    if (ctx->r3 != 0) {
        // 0x8001BE3C: nop
    
            goto L_8001BE44;
    }
    // 0x8001BE3C: nop

    // 0x8001BE40: break       7
    do_break(2147597888);
L_8001BE44:
    // 0x8001BE44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BE48: bne         $v1, $at, L_8001BE5C
    if (ctx->r3 != ctx->r1) {
        // 0x8001BE4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BE5C;
    }
    // 0x8001BE4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BE50: bne         $t6, $at, L_8001BE5C
    if (ctx->r14 != ctx->r1) {
        // 0x8001BE54: nop
    
            goto L_8001BE5C;
    }
    // 0x8001BE54: nop

    // 0x8001BE58: break       6
    do_break(2147597912);
L_8001BE5C:
    // 0x8001BE5C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001BE60: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001BE64: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BE68: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001BE6C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001BE70: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001BE74: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001BE78: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8001BE7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BE80: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001BE84: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001BE88: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001BE8C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BE90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BE94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BE98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BE9C: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8001BEA0: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001BEA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001BEA8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001BEAC: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001BEB0: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001BEB4: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001BEB8: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8001BEBC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001BEC0: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001BEC4: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001BEC8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001BECC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001BED0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BED4: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001BED8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BEDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001BEE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BEE4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BEE8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001BEEC: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001BEF0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BEF4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001BEF8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001BEFC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001BF00: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001BF04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001BF08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001BF0C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001BF10: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001BF14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001BF18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001BF1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001BF20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001BF24: b           L_8001C544
    // 0x8001BF28: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001BF28: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001BF2C:
    // 0x8001BF2C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001BF30: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001BF34: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001BF38: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8001BF3C: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001BF40: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001BF44: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BF48: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001BF4C: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001BF50: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8001BF54: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001BF58: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001BF5C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001BF60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001BF64: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001BF68: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001BF6C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BF70: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001BF74: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001BF78: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001BF7C: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001BF80: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001BF84: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001BF88: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001BF8C: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001BF90: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001BF94: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001BF98: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001BF9C: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001BFA0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001BFA4: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001BFA8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001BFAC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001BFB0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001BFB4: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001BFB8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001BFBC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001BFC0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001BFC4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001BFC8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BFCC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001BFD0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001BFD4: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8001BFD8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001BFDC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001BFE0: mflo        $t1
    ctx->r9 = lo;
    // 0x8001BFE4: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x8001BFE8: sra         $t9, $t1, 2
    ctx->r25 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8001BFEC: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8001BFF0: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001BFF4: beq         $at, $zero, L_8001C004
    if (ctx->r1 == 0) {
        // 0x8001BFF8: nop
    
            goto L_8001C004;
    }
    // 0x8001BFF8: nop

    // 0x8001BFFC: b           L_8001C004
    // 0x8001C000: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001C004;
    // 0x8001C000: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001C004:
    // 0x8001C004: bgez        $s0, L_8001C014
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C008: sra         $v0, $s0, 4
        ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
            goto L_8001C014;
    }
    // 0x8001C008: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8001C00C: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x8001C010: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_8001C014:
    // 0x8001C014: bgtz        $v0, L_8001C024
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C018: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001C024;
    }
    // 0x8001C018: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C01C: b           L_8001C024
    // 0x8001C020: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001C024;
    // 0x8001C020: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001C024:
    // 0x8001C024: bgtz        $v0, L_8001C034
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C028: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001C034;
    }
    // 0x8001C028: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001C02C: b           L_8001C038
    // 0x8001C030: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001C038;
    // 0x8001C030: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001C034:
    // 0x8001C034: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001C038:
    // 0x8001C038: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001C03C: bne         $v1, $zero, L_8001C048
    if (ctx->r3 != 0) {
        // 0x8001C040: nop
    
            goto L_8001C048;
    }
    // 0x8001C040: nop

    // 0x8001C044: break       7
    do_break(2147598404);
L_8001C048:
    // 0x8001C048: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001C04C: bne         $v1, $at, L_8001C060
    if (ctx->r3 != ctx->r1) {
        // 0x8001C050: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001C060;
    }
    // 0x8001C050: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C054: bne         $t6, $at, L_8001C060
    if (ctx->r14 != ctx->r1) {
        // 0x8001C058: nop
    
            goto L_8001C060;
    }
    // 0x8001C058: nop

    // 0x8001C05C: break       6
    do_break(2147598428);
L_8001C060:
    // 0x8001C060: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C064: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001C068: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001C06C: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001C070: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001C074: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001C078: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001C07C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8001C080: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C084: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001C088: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C08C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001C090: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C094: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001C098: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C09C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C0A0: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8001C0A4: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001C0A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001C0AC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001C0B0: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001C0B4: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001C0B8: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001C0BC: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8001C0C0: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001C0C4: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001C0C8: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001C0CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001C0D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001C0D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C0D8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001C0DC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001C0E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001C0E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C0E8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001C0EC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001C0F0: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001C0F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C0F8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001C0FC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001C100: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001C104: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C108: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001C10C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C110: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001C114: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001C118: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001C11C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001C124: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C128: b           L_8001C544
    // 0x8001C12C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001C12C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001C130:
    // 0x8001C130: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C134: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001C138: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001C13C: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8001C140: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001C144: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8001C148: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C14C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001C150: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8001C154: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8001C158: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001C15C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001C160: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001C164: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001C168: sll         $t7, $s2, 4
    ctx->r15 = S32(ctx->r18 << 4);
    // 0x8001C16C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8001C170: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001C174: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8001C178: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001C17C: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001C180: sll         $t9, $t5, 14
    ctx->r25 = S32(ctx->r13 << 14);
    // 0x8001C184: andi        $t8, $t4, 0x3
    ctx->r24 = ctx->r12 & 0X3;
    // 0x8001C188: sll         $t4, $t8, 18
    ctx->r12 = S32(ctx->r24 << 18);
    // 0x8001C18C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8001C190: andi        $t6, $s1, 0x3
    ctx->r14 = ctx->r17 & 0X3;
    // 0x8001C194: sll         $s1, $t6, 8
    ctx->r17 = S32(ctx->r14 << 8);
    // 0x8001C198: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8001C19C: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8001C1A0: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8001C1A4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8001C1A8: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x8001C1AC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8001C1B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001C1B4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001C1B8: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001C1BC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8001C1C0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001C1C4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001C1C8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8001C1CC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C1D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001C1D4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8001C1D8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8001C1DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001C1E0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001C1E4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C1E8: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x8001C1EC: sra         $t9, $t1, 2
    ctx->r25 = S32(SIGNED(ctx->r9) >> 2);
    // 0x8001C1F0: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8001C1F4: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001C1F8: beq         $at, $zero, L_8001C208
    if (ctx->r1 == 0) {
        // 0x8001C1FC: nop
    
            goto L_8001C208;
    }
    // 0x8001C1FC: nop

    // 0x8001C200: b           L_8001C208
    // 0x8001C204: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001C208;
    // 0x8001C204: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001C208:
    // 0x8001C208: bgez        $s0, L_8001C218
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8001C20C: sra         $v0, $s0, 4
        ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
            goto L_8001C218;
    }
    // 0x8001C20C: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8001C210: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x8001C214: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_8001C218:
    // 0x8001C218: bgtz        $v0, L_8001C228
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C21C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001C228;
    }
    // 0x8001C21C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C220: b           L_8001C228
    // 0x8001C224: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001C228;
    // 0x8001C224: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001C228:
    // 0x8001C228: bgtz        $v0, L_8001C238
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C22C: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8001C238;
    }
    // 0x8001C22C: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8001C230: b           L_8001C23C
    // 0x8001C234: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001C23C;
    // 0x8001C234: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001C238:
    // 0x8001C238: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001C23C:
    // 0x8001C23C: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x8001C240: bne         $v1, $zero, L_8001C24C
    if (ctx->r3 != 0) {
        // 0x8001C244: nop
    
            goto L_8001C24C;
    }
    // 0x8001C244: nop

    // 0x8001C248: break       7
    do_break(2147598920);
L_8001C24C:
    // 0x8001C24C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001C250: bne         $v1, $at, L_8001C264
    if (ctx->r3 != ctx->r1) {
        // 0x8001C254: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001C264;
    }
    // 0x8001C254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C258: bne         $t6, $at, L_8001C264
    if (ctx->r14 != ctx->r1) {
        // 0x8001C25C: nop
    
            goto L_8001C264;
    }
    // 0x8001C25C: nop

    // 0x8001C260: break       6
    do_break(2147598944);
L_8001C264:
    // 0x8001C264: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C268: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001C26C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001C270: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8001C274: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001C278: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001C27C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8001C280: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8001C284: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C288: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001C28C: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8001C290: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001C294: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C298: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001C29C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C2A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C2A4: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8001C2A8: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8001C2AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001C2B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001C2B4: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8001C2B8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8001C2BC: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8001C2C0: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8001C2C4: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8001C2C8: or          $t8, $t9, $s1
    ctx->r24 = ctx->r25 | ctx->r17;
    // 0x8001C2CC: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8001C2D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001C2D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001C2D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C2DC: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8001C2E0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001C2E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001C2E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C2EC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001C2F0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001C2F4: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x8001C2F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C2FC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8001C300: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001C304: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001C308: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C30C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001C310: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C314: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001C318: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001C31C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001C320: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C324: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8001C328: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001C32C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C330: b           L_8001C544
    // 0x8001C334: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_8001C544;
    // 0x8001C334: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001C338:
    // 0x8001C338: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C33C: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001C340: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001C344: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8001C348: andi        $t5, $v1, 0xF
    ctx->r13 = ctx->r3 & 0XF;
    // 0x8001C34C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8001C350: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001C354: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8001C358: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
    // 0x8001C35C: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8001C360: andi        $s2, $t0, 0xF
    ctx->r18 = ctx->r8 & 0XF;
    // 0x8001C364: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8001C368: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001C36C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001C370: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x8001C374: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8001C378: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C37C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8001C380: lbu         $t4, 0x127($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X127);
    // 0x8001C384: lbu         $s1, 0x123($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0X123);
    // 0x8001C388: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x8001C38C: andi        $t7, $t4, 0x3
    ctx->r15 = ctx->r12 & 0X3;
    // 0x8001C390: sll         $t4, $t7, 18
    ctx->r12 = S32(ctx->r15 << 18);
    // 0x8001C394: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8001C398: andi        $t8, $s1, 0x3
    ctx->r24 = ctx->r17 & 0X3;
    // 0x8001C39C: sll         $s1, $t8, 8
    ctx->r17 = S32(ctx->r24 << 8);
    // 0x8001C3A0: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8001C3A4: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x8001C3A8: or          $t7, $t8, $s1
    ctx->r15 = ctx->r24 | ctx->r17;
    // 0x8001C3AC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8001C3B0: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x8001C3B4: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8001C3B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8001C3BC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8001C3C0: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8001C3C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8001C3C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C3CC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001C3D0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001C3D4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C3D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C3DC: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8001C3E0: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8001C3E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001C3E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C3EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001C3F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001C3F4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C3F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001C3FC: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001C400: addiu       $t1, $t6, -0x1
    ctx->r9 = ADD32(ctx->r14, -0X1);
    // 0x8001C404: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8001C408: beq         $at, $zero, L_8001C418
    if (ctx->r1 == 0) {
        // 0x8001C40C: nop
    
            goto L_8001C418;
    }
    // 0x8001C40C: nop

    // 0x8001C410: b           L_8001C418
    // 0x8001C414: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8001C418;
    // 0x8001C414: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8001C418:
    // 0x8001C418: bgez        $t2, L_8001C428
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001C41C: sra         $v0, $t2, 3
        ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
            goto L_8001C428;
    }
    // 0x8001C41C: sra         $v0, $t2, 3
    ctx->r2 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8001C420: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x8001C424: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8001C428:
    // 0x8001C428: bgtz        $v0, L_8001C438
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C42C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8001C438;
    }
    // 0x8001C42C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8001C430: b           L_8001C438
    // 0x8001C434: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001C438;
    // 0x8001C434: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001C438:
    // 0x8001C438: bgtz        $v0, L_8001C448
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001C43C: addiu       $t8, $t1, 0x7FF
        ctx->r24 = ADD32(ctx->r9, 0X7FF);
            goto L_8001C448;
    }
    // 0x8001C43C: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8001C440: b           L_8001C44C
    // 0x8001C444: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8001C44C;
    // 0x8001C444: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001C448:
    // 0x8001C448: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001C44C:
    // 0x8001C44C: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x8001C450: bne         $v1, $zero, L_8001C45C
    if (ctx->r3 != 0) {
        // 0x8001C454: nop
    
            goto L_8001C45C;
    }
    // 0x8001C454: nop

    // 0x8001C458: break       7
    do_break(2147599448);
L_8001C45C:
    // 0x8001C45C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001C460: bne         $v1, $at, L_8001C474
    if (ctx->r3 != ctx->r1) {
        // 0x8001C464: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001C474;
    }
    // 0x8001C464: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001C468: bne         $t8, $at, L_8001C474
    if (ctx->r24 != ctx->r1) {
        // 0x8001C46C: nop
    
            goto L_8001C474;
    }
    // 0x8001C46C: nop

    // 0x8001C470: break       6
    do_break(2147599472);
L_8001C474:
    // 0x8001C474: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C478: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8001C47C: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x8001C480: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8001C484: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C488: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001C48C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8001C490: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8001C494: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8001C498: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C49C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8001C4A0: addiu       $t8, $t2, 0x7
    ctx->r24 = ADD32(ctx->r10, 0X7);
    // 0x8001C4A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001C4A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001C4AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001C4B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001C4B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C4B8: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8001C4BC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8001C4C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001C4C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001C4C8: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8001C4CC: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8001C4D0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8001C4D4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8001C4D8: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x8001C4DC: or          $t9, $t7, $s2
    ctx->r25 = ctx->r15 | ctx->r18;
    // 0x8001C4E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001C4E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001C4E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C4EC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8001C4F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001C4F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001C4F8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001C4FC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8001C500: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8001C504: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    // 0x8001C508: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001C50C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8001C510: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001C514: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8001C518: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001C51C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001C520: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001C524: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8001C528: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x8001C52C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001C530: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001C534: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8001C538: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001C53C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8001C540:
    // 0x8001C540: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_8001C544:
    // 0x8001C544: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001C548: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8001C54C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001C550: jr          $ra
    // 0x8001C554: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x8001C554: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    // 0x8001C558: nop

    // 0x8001C55C: nop

;}
RECOMP_FUNC void func_80032560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032568: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003256C: jal         0x80032020
    // 0x80032570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80032020(rdram, ctx);
        goto after_0;
    // 0x80032570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80032574: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x80032578: jal         0x80031CF0
    // 0x8003257C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80031CF0(rdram, ctx);
        goto after_1;
    // 0x8003257C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80032580: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80032584: jal         0x80031F1C
    // 0x80032588: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    func_80031F1C(rdram, ctx);
        goto after_2;
    // 0x80032588: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    after_2:
    // 0x8003258C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80032590: jal         0x80031FBC
    // 0x80032594: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80031FBC(rdram, ctx);
        goto after_3;
    // 0x80032594: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80032598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003259C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800325A0: jr          $ra
    // 0x800325A4: nop

    return;
    // 0x800325A4: nop

;}
RECOMP_FUNC void func_8004290C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004290C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80042910: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80042914: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80042918: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004291C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80042920: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80042924: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80042928: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004292C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042930: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80042934: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x80042938: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8004293C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80042940: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x80042944: bnel        $t6, $zero, L_800429B0
    if (ctx->r14 != 0) {
        // 0x80042948: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800429B0;
    }
    goto skip_0;
    // 0x80042948: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x8004294C: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80042950: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x80042954: beql        $s0, $zero, L_800429B0
    if (ctx->r16 == 0) {
        // 0x80042958: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800429B0;
    }
    goto skip_1;
    // 0x80042958: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_8004295C:
    // 0x8004295C: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80042960: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80042964: bne         $s3, $t7, L_800429A4
    if (ctx->r19 != ctx->r15) {
        // 0x80042968: nop
    
            goto L_800429A4;
    }
    // 0x80042968: nop

    // 0x8004296C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80042970: bne         $s5, $t8, L_800429A4
    if (ctx->r21 != ctx->r24) {
        // 0x80042974: nop
    
            goto L_800429A4;
    }
    // 0x80042974: nop

    // 0x80042978: beq         $s1, $zero, L_80042990
    if (ctx->r17 == 0) {
        // 0x8004297C: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_80042990;
    }
    // 0x8004297C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x80042980: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80042984: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80042988: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8004298C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_80042990:
    // 0x80042990: jal         0x80036820
    // 0x80042994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x80042994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80042998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004299C: jal         0x80036850
    // 0x800429A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x800429A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_800429A4:
    // 0x800429A4: bne         $s1, $zero, L_8004295C
    if (ctx->r17 != 0) {
        // 0x800429A8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8004295C;
    }
    // 0x800429A8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800429AC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_800429B0:
    // 0x800429B0: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x800429B4: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x800429B8: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x800429BC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800429C0: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x800429C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800429C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800429CC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800429D0: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x800429D4: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800429D8: jal         0x80049D50
    // 0x800429DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    func_80049D50(rdram, ctx);
        goto after_2;
    // 0x800429DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x800429E0: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x800429E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800429E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800429EC: jal         0x80044190
    // 0x800429F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    func_80044190(rdram, ctx);
        goto after_3;
    // 0x800429F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x800429F4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800429F8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x800429FC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80042A00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80042A04: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80042A08: jal         0x8003FE6C
    // 0x80042A0C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x80042A0C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x80042A10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80042A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042A18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80042A1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042A20: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80042A24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80042A28: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80042A2C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80042A30: jr          $ra
    // 0x80042A34: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80042A34: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8001CACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CACC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001CAD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CAD4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001CAD8: lhu         $v0, -0x3A74($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A74);
    // 0x8001CADC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001CAE0: addiu       $t9, $t9, -0x3668
    ctx->r25 = ADD32(ctx->r25, -0X3668);
    // 0x8001CAE4: beq         $v0, $zero, L_8001CB00
    if (ctx->r2 == 0) {
        // 0x8001CAE8: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8001CB00;
    }
    // 0x8001CAE8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001CAEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CAF0: beq         $v0, $at, L_8001CDBC
    if (ctx->r2 == ctx->r1) {
        // 0x8001CAF4: nop
    
            goto L_8001CDBC;
    }
    // 0x8001CAF4: nop

    // 0x8001CAF8: b           L_8001CFDC
    // 0x8001CAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001CFDC;
    // 0x8001CAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001CB00:
    // 0x8001CB00: lhu         $t6, -0x3A70($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A70);
    // 0x8001CB04: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CB08: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001CB0C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8001CB10: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001CB14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001CB18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001CB1C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001CB20: addiu       $t8, $t7, 0x24
    ctx->r24 = ADD32(ctx->r15, 0X24);
    // 0x8001CB24: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001CB28: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001CB2C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001CB30: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001CB34: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001CB38: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8001CB3C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001CB40: jal         0x80023210
    // 0x8001CB44: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x8001CB44: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8001CB48: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8001CB4C: jal         0x80022FD0
    // 0x8001CB50: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x8001CB50: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8001CB54: sltiu       $at, $v0, 0x33
    ctx->r1 = ctx->r2 < 0X33 ? 1 : 0;
    // 0x8001CB58: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001CB5C: bne         $at, $zero, L_8001CBC4
    if (ctx->r1 != 0) {
        // 0x8001CB60: lwc1        $f14, 0x1C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8001CBC4;
    }
    // 0x8001CB60: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CB64: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CB68: ldc1        $f16, 0x1620($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1620);
    // 0x8001CB6C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x8001CB70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CB74: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x8001CB78: ldc1        $f8, 0x1628($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1628);
    // 0x8001CB7C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CB80: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8001CB84: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8001CB88: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8001CB8C: nop

    // 0x8001CB90: bc1fl       L_8001CBAC
    if (!c1cs) {
        // 0x8001CB94: c.lt.d      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
            goto L_8001CBAC;
    }
    goto skip_0;
    // 0x8001CB94: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    skip_0:
    // 0x8001CB98: ldc1        $f12, 0x1630($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1630);
    // 0x8001CB9C: add.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d + ctx->f12.d;
    // 0x8001CBA0: b           L_8001CBC4
    // 0x8001CBA4: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
        goto L_8001CBC4;
    // 0x8001CBA4: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001CBA8: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
L_8001CBAC:
    // 0x8001CBAC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CBB0: bc1f        L_8001CBC4
    if (!c1cs) {
        // 0x8001CBB4: nop
    
            goto L_8001CBC4;
    }
    // 0x8001CBB4: nop

    // 0x8001CBB8: ldc1        $f12, 0x1638($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1638);
    // 0x8001CBBC: sub.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f0.d - ctx->f12.d;
    // 0x8001CBC0: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_8001CBC4:
    // 0x8001CBC4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CBC8: ldc1        $f12, 0x1640($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1640);
    // 0x8001CBCC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CBD0: ldc1        $f16, 0x1648($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1648);
    // 0x8001CBD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CBD8: ldc1        $f8, 0x1650($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1650);
    // 0x8001CBDC: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8001CBE0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CBE4: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8001CBE8: ldc1        $f4, 0x1658($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1658);
    // 0x8001CBEC: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001CBF0: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8001CBF4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8001CBF8: nop

    // 0x8001CBFC: bc1fl       L_8001CC14
    if (!c1cs) {
        // 0x8001CC00: c.lt.d      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
            goto L_8001CC14;
    }
    goto skip_1;
    // 0x8001CC00: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    skip_1:
    // 0x8001CC04: add.d       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f0.d + ctx->f12.d;
    // 0x8001CC08: b           L_8001CC28
    // 0x8001CC0C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
        goto L_8001CC28;
    // 0x8001CC0C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8001CC10: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
L_8001CC14:
    // 0x8001CC14: nop

    // 0x8001CC18: bc1fl       L_8001CC2C
    if (!c1cs) {
        // 0x8001CC1C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8001CC2C;
    }
    goto skip_2;
    // 0x8001CC1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x8001CC20: sub.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f0.d - ctx->f12.d;
    // 0x8001CC24: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_8001CC28:
    // 0x8001CC28: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8001CC2C:
    // 0x8001CC2C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CC30: addiu       $a1, $a1, -0x3A80
    ctx->r5 = ADD32(ctx->r5, -0X3A80);
    // 0x8001CC34: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8001CC38: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8001CC3C: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001CC40: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001CC44: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001CC48: nop

    // 0x8001CC4C: bc1fl       L_8001CC84
    if (!c1cs) {
        // 0x8001CC50: lwc1        $f4, 0x24($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
            goto L_8001CC84;
    }
    goto skip_3;
    // 0x8001CC50: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    skip_3:
    // 0x8001CC54: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8001CC58: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8001CC5C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001CC60: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001CC64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001CC68: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8001CC6C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8001CC70: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x8001CC74: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8001CC78: b           L_8001CCA8
    // 0x8001CC7C: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
        goto L_8001CCA8;
    // 0x8001CC7C: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8001CC80: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
L_8001CC84:
    // 0x8001CC84: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8001CC88: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001CC8C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001CC90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001CC94: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8001CC98: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8001CC9C: add.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d + ctx->f18.d;
    // 0x8001CCA0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001CCA4: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
L_8001CCA8:
    // 0x8001CCA8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CCAC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8001CCB0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001CCB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001CCB8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001CCBC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CCC0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001CCC4: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8001CCC8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8001CCCC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8001CCD0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001CCD4: jal         0x800232F4
    // 0x8001CCD8: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x8001CCD8: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x8001CCDC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001CCE0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CCE4: addiu       $a1, $a1, -0x3A80
    ctx->r5 = ADD32(ctx->r5, -0X3A80);
    // 0x8001CCE8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001CCEC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001CCF0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CCF4: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8001CCF8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001CCFC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CD00: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8001CD04: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001CD08: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8001CD0C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001CD10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001CD14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001CD18: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001CD1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001CD20: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CD24: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001CD28: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8001CD2C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001CD30: addiu       $a0, $a0, -0x3A72
    ctx->r4 = ADD32(ctx->r4, -0X3A72);
    // 0x8001CD34: addiu       $a1, $a1, -0x3A74
    ctx->r5 = ADD32(ctx->r5, -0X3A74);
    // 0x8001CD38: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001CD3C: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x8001CD40: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8001CD44: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8001CD48: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001CD4C: lwc1        $f0, -0x4530($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x8001CD50: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8001CD54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CD58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001CD5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CD60: bc1fl       L_8001CD70
    if (!c1cs) {
        // 0x8001CD64: swc1        $f16, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
            goto L_8001CD70;
    }
    goto skip_4;
    // 0x8001CD64: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    skip_4:
    // 0x8001CD68: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8001CD6C: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
L_8001CD70:
    // 0x8001CD70: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8001CD74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001CD78: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
    // 0x8001CD7C: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x8001CD80: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8001CD84: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x8001CD88: sw          $v1, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r3;
    // 0x8001CD8C: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x8001CD90: lwc1        $f4, 0x1660($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1660);
    // 0x8001CD94: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001CD98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001CD9C: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x8001CDA0: swc1        $f6, 0x6EF0($at)
    MEM_W(0X6EF0, ctx->r1) = ctx->f6.u32l;
    // 0x8001CDA4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x8001CDA8: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8001CDAC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x8001CDB0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001CDB4: b           L_8001CFD8
    // 0x8001CDB8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
        goto L_8001CFD8;
    // 0x8001CDB8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
L_8001CDBC:
    // 0x8001CDBC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001CDC0: addiu       $a0, $a0, -0x3A72
    ctx->r4 = ADD32(ctx->r4, -0X3A72);
    // 0x8001CDC4: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8001CDC8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8001CDCC: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8001CDD0: bne         $t5, $zero, L_8001CFD8
    if (ctx->r13 != 0) {
        // 0x8001CDD4: sh          $t4, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r12;
            goto L_8001CFD8;
    }
    // 0x8001CDD4: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8001CDD8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001CDDC: addiu       $v0, $v0, -0x3A6E
    ctx->r2 = ADD32(ctx->r2, -0X3A6E);
    // 0x8001CDE0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8001CDE4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001CDE8: andi        $t7, $t6, 0xFDFF
    ctx->r15 = ctx->r14 & 0XFDFF;
    // 0x8001CDEC: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001CDF0: jal         0x80013F5C
    // 0x8001CDF4: lw          $a0, 0x6ED8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED8);
    func_80013F5C(rdram, ctx);
        goto after_3;
    // 0x8001CDF4: lw          $a0, 0x6ED8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED8);
    after_3:
    // 0x8001CDF8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CDFC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001CE00: lwc1        $f8, -0x3A64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x8001CE04: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001CE08: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001CE0C: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001CE10: lwc1        $f4, -0x3A60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x8001CE14: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001CE18: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001CE1C: jal         0x80023210
    // 0x8001CE20: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_80023210(rdram, ctx);
        goto after_4;
    // 0x8001CE20: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_4:
    // 0x8001CE24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CE28: ldc1        $f16, 0x1668($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1668);
    // 0x8001CE2C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8001CE30: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CE34: add.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d + ctx->f16.d;
    // 0x8001CE38: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CE3C: addiu       $a1, $a1, -0x3A80
    ctx->r5 = ADD32(ctx->r5, -0X3A80);
    // 0x8001CE40: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001CE44: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x8001CE48: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x8001CE4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001CE50: bc1f        L_8001CE6C
    if (!c1cs) {
        // 0x8001CE54: nop
    
            goto L_8001CE6C;
    }
    // 0x8001CE54: nop

    // 0x8001CE58: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CE5C: ldc1        $f12, 0x1670($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1670);
    // 0x8001CE60: sub.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f2.d - ctx->f12.d;
    // 0x8001CE64: b           L_8001CE90
    // 0x8001CE68: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
        goto L_8001CE90;
    // 0x8001CE68: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_8001CE6C:
    // 0x8001CE6C: ldc1        $f6, 0x1678($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1678);
    // 0x8001CE70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CE74: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x8001CE78: nop

    // 0x8001CE7C: bc1fl       L_8001CE94
    if (!c1cs) {
        // 0x8001CE80: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8001CE94;
    }
    goto skip_5;
    // 0x8001CE80: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_5:
    // 0x8001CE84: ldc1        $f12, 0x1680($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1680);
    // 0x8001CE88: add.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f2.d + ctx->f12.d;
    // 0x8001CE8C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_8001CE90:
    // 0x8001CE90: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_8001CE94:
    // 0x8001CE94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CE98: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8001CE9C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8001CEA0: jal         0x800232F4
    // 0x8001CEA4: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_5;
    // 0x8001CEA4: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    after_5:
    // 0x8001CEA8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001CEAC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CEB0: addiu       $a1, $a1, -0x3A80
    ctx->r5 = ADD32(ctx->r5, -0X3A80);
    // 0x8001CEB4: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x8001CEB8: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8001CEBC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001CEC0: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8001CEC4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8001CEC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001CECC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001CED0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8001CED4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CED8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8001CEDC: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8001CEE0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8001CEE4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8001CEE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001CEEC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001CEF0: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8001CEF4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8001CEF8: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x8001CEFC: lhu         $t9, 0x8($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X8);
    // 0x8001CF00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001CF04: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8001CF08: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8001CF0C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8001CF10: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8001CF14: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
    // 0x8001CF18: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8001CF1C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001CF20: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x8001CF24: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8001CF28: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001CF2C: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
    // 0x8001CF30: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
    // 0x8001CF34: lhu         $t1, -0x3A6E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X3A6E);
    // 0x8001CF38: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001CF3C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001CF40: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x8001CF44: beq         $t2, $zero, L_8001CF80
    if (ctx->r10 == 0) {
        // 0x8001CF48: addiu       $t7, $t7, -0x4534
        ctx->r15 = ADD32(ctx->r15, -0X4534);
            goto L_8001CF80;
    }
    // 0x8001CF48: addiu       $t7, $t7, -0x4534
    ctx->r15 = ADD32(ctx->r15, -0X4534);
    // 0x8001CF4C: lw          $t3, -0x3A90($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3A90);
    // 0x8001CF50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001CF54: bne         $t3, $at, L_8001CF80
    if (ctx->r11 != ctx->r1) {
        // 0x8001CF58: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8001CF80;
    }
    // 0x8001CF58: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8001CF5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001CF60: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8001CF64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001CF68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001CF6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CF70: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8001CF74: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8001CF78: b           L_8001CFC0
    // 0x8001CF7C: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
        goto L_8001CFC0;
    // 0x8001CF7C: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
L_8001CF80:
    // 0x8001CF80: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001CF84: lw          $t4, 0x4EE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4EE4);
    // 0x8001CF88: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8001CF8C: addiu       $t6, $t6, -0x2F60
    ctx->r14 = ADD32(ctx->r14, -0X2F60);
    // 0x8001CF90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8001CF94: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8001CF98: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8001CF9C: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8001CFA0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001CFA4: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8001CFA8: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8001CFAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001CFB0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001CFB4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001CFB8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8001CFBC: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
L_8001CFC0:
    // 0x8001CFC0: sw          $t7, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r15;
    // 0x8001CFC4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CFC8: lwc1        $f8, 0x1688($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1688);
    // 0x8001CFCC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001CFD0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x8001CFD4: swc1        $f16, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = ctx->f16.u32l;
L_8001CFD8:
    // 0x8001CFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001CFDC:
    // 0x8001CFDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001CFE0: jr          $ra
    // 0x8001CFE4: nop

    return;
    // 0x8001CFE4: nop

;}
RECOMP_FUNC void func_80030EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030EA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80030EA4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80030EA8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80030EAC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80030EB0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80030EB4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80030EB8: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80030EBC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80030EC0: lui         $s6, 0xE700
    ctx->r22 = S32(0XE700 << 16);
    // 0x80030EC4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80030EC8: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80030ECC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80030ED0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80030ED4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80030ED8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80030EDC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80030EE0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80030EE4: or          $t4, $s7, $zero
    ctx->r12 = ctx->r23 | 0;
    // 0x80030EE8: or          $t5, $a1, $zero
    ctx->r13 = ctx->r5 | 0;
    // 0x80030EEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030EF0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80030EF4: addiu       $ra, $zero, 0x20
    ctx->r31 = ADD32(0, 0X20);
    // 0x80030EF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030EFC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030F00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030F04: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80030F08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030F0C: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x80030F10: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80030F14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030F18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030F1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030F20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030F24: lbu         $a3, 0x0($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X0);
    // 0x80030F28: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80030F2C: lui         $s4, 0x700
    ctx->r20 = S32(0X700 << 16);
    // 0x80030F30: beq         $fp, $a3, L_80031294
    if (ctx->r30 == ctx->r7) {
        // 0x80030F34: lui         $s3, 0x8009
        ctx->r19 = S32(0X8009 << 16);
            goto L_80031294;
    }
    // 0x80030F34: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80030F38: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80030F3C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80030F40: addiu       $s0, $s0, 0x2860
    ctx->r16 = ADD32(ctx->r16, 0X2860);
    // 0x80030F44: addiu       $s2, $s2, -0x570
    ctx->r18 = ADD32(ctx->r18, -0X570);
    // 0x80030F48: addiu       $s3, $s3, 0x2864
    ctx->r19 = ADD32(ctx->r19, 0X2864);
    // 0x80030F4C: andi        $t6, $a3, 0x80
    ctx->r14 = ctx->r7 & 0X80;
L_80030F50:
    // 0x80030F50: beq         $t6, $zero, L_8003118C
    if (ctx->r14 == 0) {
        // 0x80030F54: andi        $v0, $a3, 0x60
        ctx->r2 = ctx->r7 & 0X60;
            goto L_8003118C;
    }
    // 0x80030F54: andi        $v0, $a3, 0x60
    ctx->r2 = ctx->r7 & 0X60;
    // 0x80030F58: beq         $v0, $zero, L_80030F80
    if (ctx->r2 == 0) {
        // 0x80030F5C: andi        $t3, $a3, 0x1F
        ctx->r11 = ctx->r7 & 0X1F;
            goto L_80030F80;
    }
    // 0x80030F5C: andi        $t3, $a3, 0x1F
    ctx->r11 = ctx->r7 & 0X1F;
    // 0x80030F60: beq         $v0, $ra, L_80031064
    if (ctx->r2 == ctx->r31) {
        // 0x80030F64: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80031064;
    }
    // 0x80030F64: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80030F68: beq         $v0, $at, L_80031110
    if (ctx->r2 == ctx->r1) {
        // 0x80030F6C: addiu       $at, $zero, 0x60
        ctx->r1 = ADD32(0, 0X60);
            goto L_80031110;
    }
    // 0x80030F6C: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x80030F70: beq         $v0, $at, L_8003112C
    if (ctx->r2 == ctx->r1) {
        // 0x80030F74: nop
    
            goto L_8003112C;
    }
    // 0x80030F74: nop

    // 0x80030F78: b           L_80031288
    // 0x80030F7C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
        goto L_80031288;
    // 0x80030F7C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
L_80030F80:
    // 0x80030F80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030F84: sll         $t9, $t3, 5
    ctx->r25 = S32(ctx->r11 << 5);
    // 0x80030F88: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x80030F8C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80030F90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030F94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030F98: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x80030F9C: lui         $t6, 0x8032
    ctx->r14 = S32(0X8032 << 16);
    // 0x80030FA0: addiu       $t6, $t6, 0x32A0
    ctx->r14 = ADD32(ctx->r14, 0X32A0);
    // 0x80030FA4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80030FA8: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x80030FAC: ori         $t8, $t8, 0x97
    ctx->r24 = ctx->r24 | 0X97;
    // 0x80030FB0: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80030FB4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80030FB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030FBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030FC0: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x80030FC4: ori         $t9, $t9, 0x2600
    ctx->r25 = ctx->r25 | 0X2600;
    // 0x80030FC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80030FCC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80030FD0: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80030FD4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030FD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030FDC: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x80030FE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030FE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030FE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030FEC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80030FF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030FF4: lui         $t9, 0x725
    ctx->r25 = S32(0X725 << 16);
    // 0x80030FF8: ori         $t9, $t9, 0xE030
    ctx->r25 = ctx->r25 | 0XE030;
    // 0x80030FFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80031000: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80031004: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80031008: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003100C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031010: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80031014: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80031018: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003101C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80031020: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031024: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80031028: ori         $t8, $t8, 0x2600
    ctx->r24 = ctx->r24 | 0X2600;
    // 0x8003102C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80031030: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80031034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80031038: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003103C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031040: lui         $t7, 0x4B
    ctx->r15 = S32(0X4B << 16);
    // 0x80031044: ori         $t7, $t7, 0xC030
    ctx->r15 = ctx->r15 | 0XC030;
    // 0x80031048: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003104C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80031050: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80031054: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80031058: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003105C: b           L_80031288
    // 0x80031060: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
        goto L_80031288;
    // 0x80031060: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
L_80031064:
    // 0x80031064: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031068: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8003106C: sll         $t7, $t3, 5
    ctx->r15 = S32(ctx->r11 << 5);
    // 0x80031070: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80031074: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80031078: lui         $t8, 0x8033
    ctx->r24 = S32(0X8033 << 16);
    // 0x8003107C: addiu       $t8, $t8, 0x1A30
    ctx->r24 = ADD32(ctx->r24, 0X1A30);
    // 0x80031080: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80031084: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031088: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003108C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031090: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80031094: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80031098: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003109C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800310A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800310A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800310A8: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x800310AC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800310B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800310B4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800310B8: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x800310BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800310C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800310C4: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x800310C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800310CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800310D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800310D4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800310D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800310DC: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x800310E0: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800310E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800310E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800310EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800310F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800310F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800310F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800310FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80031100: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80031104: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80031108: b           L_80031288
    // 0x8003110C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
        goto L_80031288;
    // 0x8003110C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
L_80031110:
    // 0x80031110: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80031114: beq         $at, $zero, L_80031124
    if (ctx->r1 == 0) {
        // 0x80031118: nop
    
            goto L_80031124;
    }
    // 0x80031118: nop

    // 0x8003111C: b           L_80031284
    // 0x80031120: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_80031284;
    // 0x80031120: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80031124:
    // 0x80031124: b           L_80031284
    // 0x80031128: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
        goto L_80031284;
    // 0x80031128: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
L_8003112C:
    // 0x8003112C: beq         $t3, $zero, L_80031170
    if (ctx->r11 == 0) {
        // 0x80031130: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80031170;
    }
    // 0x80031130: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80031134: beq         $t3, $at, L_80031284
    if (ctx->r11 == ctx->r1) {
        // 0x80031138: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80031284;
    }
    // 0x80031138: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8003113C: beq         $t3, $at, L_80031284
    if (ctx->r11 == ctx->r1) {
        // 0x80031140: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80031284;
    }
    // 0x80031140: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80031144: bne         $t3, $at, L_80031284
    if (ctx->r11 != ctx->r1) {
        // 0x80031148: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80031284;
    }
    // 0x80031148: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003114C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031150: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80031154: addiu       $t9, $t9, -0x560
    ctx->r25 = ADD32(ctx->r25, -0X560);
    // 0x80031158: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003115C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80031160: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80031164: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80031168: b           L_80031288
    // 0x8003116C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
        goto L_80031288;
    // 0x8003116C: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
L_80031170:
    // 0x80031170: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80031174: or          $t4, $s7, $zero
    ctx->r12 = ctx->r23 | 0;
    // 0x80031178: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8003117C: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80031180: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80031184: b           L_80031284
    // 0x80031188: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
        goto L_80031284;
    // 0x80031188: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
L_8003118C:
    // 0x8003118C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80031190: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80031194: andi        $t3, $a3, 0x7F
    ctx->r11 = ctx->r7 & 0X7F;
    // 0x80031198: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8003119C: bne         $a3, $at, L_800311B8
    if (ctx->r7 != ctx->r1) {
        // 0x800311A0: addu        $t0, $s2, $t7
        ctx->r8 = ADD32(ctx->r18, ctx->r15);
            goto L_800311B8;
    }
    // 0x800311A0: addu        $t0, $s2, $t7
    ctx->r8 = ADD32(ctx->r18, ctx->r15);
    // 0x800311A4: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x800311A8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800311AC: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800311B0: b           L_80031284
    // 0x800311B4: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
        goto L_80031284;
    // 0x800311B4: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
L_800311B8:
    // 0x800311B8: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x800311BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800311C0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800311C4: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800311C8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800311CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800311D0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800311D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800311D8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800311DC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800311E0: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x800311E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800311E8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800311EC: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800311F0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800311F4: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x800311F8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800311FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80031200: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80031204: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80031208: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8003120C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80031210: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80031214: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031218: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8003121C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80031220: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80031224: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80031228: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8003122C: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80031230: addu        $t7, $s2, $t8
    ctx->r15 = ADD32(ctx->r18, ctx->r24);
    // 0x80031234: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80031238: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8003123C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80031240: mflo        $t7
    ctx->r15 = lo;
    // 0x80031244: sll         $t6, $t7, 21
    ctx->r14 = S32(ctx->r15 << 21);
    // 0x80031248: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8003124C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031250: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80031254: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80031258: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003125C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80031260: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80031264: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80031268: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8003126C: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80031270: addu        $t8, $s2, $t9
    ctx->r24 = ADD32(ctx->r18, ctx->r25);
    // 0x80031274: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80031278: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003127C: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80031280: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
L_80031284:
    // 0x80031284: lbu         $a3, 0x1($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X1);
L_80031288:
    // 0x80031288: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003128C: bnel        $fp, $a3, L_80030F50
    if (ctx->r30 != ctx->r7) {
        // 0x80031290: andi        $t6, $a3, 0x80
        ctx->r14 = ctx->r7 & 0X80;
            goto L_80030F50;
    }
    goto skip_0;
    // 0x80031290: andi        $t6, $a3, 0x80
    ctx->r14 = ctx->r7 & 0X80;
    skip_0:
L_80031294:
    // 0x80031294: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031298: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003129C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800312A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800312A4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x800312A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800312AC: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800312B0: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x800312B4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800312B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800312BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800312C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800312C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800312C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800312CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800312D0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800312D4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800312D8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800312DC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800312E0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800312E4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800312E8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800312EC: jr          $ra
    // 0x800312F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800312F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800312F4: nop

    // 0x800312F8: nop

    // 0x800312FC: nop

;}
RECOMP_FUNC void func_80000450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000045C: jal         0x80033850
    // 0x80000460: nop

    __osInitialize_common_recomp(rdram, ctx);
        goto after_0;
    // 0x80000460: nop

    after_0:
    // 0x80000464: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80000468: addiu       $t6, $t6, 0x61F0
    ctx->r14 = ADD32(ctx->r14, 0X61F0);
    // 0x8000046C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80000470: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80000478: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000047C: addiu       $a2, $a2, 0x4B0
    ctx->r6 = ADD32(ctx->r6, 0X4B0);
    // 0x80000480: addiu       $a0, $a0, 0x4E90
    ctx->r4 = ADD32(ctx->r4, 0X4E90);
    // 0x80000484: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80000488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000048C: jal         0x80033AE0
    // 0x80000490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80000490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80000494: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80000498: jal         0x80033C30
    // 0x8000049C: addiu       $a0, $a0, 0x4E90
    ctx->r4 = ADD32(ctx->r4, 0X4E90);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000049C: addiu       $a0, $a0, 0x4E90
    ctx->r4 = ADD32(ctx->r4, 0X4E90);
    after_2:
    // 0x800004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800004A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800004A8: jr          $ra
    // 0x800004AC: nop

    return;
    // 0x800004AC: nop

;}
RECOMP_FUNC void func_80008F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008F6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80008F70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80008F74: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80008F78: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80008F7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80008F80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80008F84: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80008F88: addiu       $s0, $s0, -0x3668
    ctx->r16 = ADD32(ctx->r16, -0X3668);
    // 0x80008F8C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x80008F90: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_80008F94:
    // 0x80008F94: lh          $t6, 0x74($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X74);
    // 0x80008F98: addiu       $s2, $s0, 0x24
    ctx->r18 = ADD32(ctx->r16, 0X24);
    // 0x80008F9C: beql        $s3, $t6, L_80008FB4
    if (ctx->r19 == ctx->r14) {
        // 0x80008FA0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80008FB4;
    }
    goto skip_0;
    // 0x80008FA0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x80008FA4: jal         0x800202E4
    // 0x80008FA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800202E4(rdram, ctx);
        goto after_0;
    // 0x80008FA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80008FAC: sh          $s3, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r19;
    // 0x80008FB0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80008FB4:
    // 0x80008FB4: bne         $s1, $zero, L_80008F94
    if (ctx->r17 != 0) {
        // 0x80008FB8: addiu       $s0, $s0, 0x128
        ctx->r16 = ADD32(ctx->r16, 0X128);
            goto L_80008F94;
    }
    // 0x80008FB8: addiu       $s0, $s0, 0x128
    ctx->r16 = ADD32(ctx->r16, 0X128);
    // 0x80008FBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008FC0: sw          $zero, -0x3670($at)
    MEM_W(-0X3670, ctx->r1) = 0;
    // 0x80008FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80008FC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80008FCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80008FD0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80008FD4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80008FD8: jr          $ra
    // 0x80008FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80008FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80014434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014438: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001443C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80014440: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80014444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014448: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001444C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80014450: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80014454: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80014458: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001445C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80014460: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014464: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80014468: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    // 0x8001446C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80014470: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80014474: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80014478: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001447C: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80014480: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x80014484: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80014488: lwc1        $f16, 0x64($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64);
    // 0x8001448C: sw          $a2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r6;
    // 0x80014490: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80014494: swc1        $f10, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f10.u32l;
    // 0x80014498: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    // 0x8001449C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800144A0: beql        $v1, $zero, L_800144C0
    if (ctx->r3 == 0) {
        // 0x800144A4: swc1        $f0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
            goto L_800144C0;
    }
    goto skip_0;
    // 0x800144A4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    skip_0:
    // 0x800144A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800144AC: beql        $v1, $at, L_80014560
    if (ctx->r3 == ctx->r1) {
        // 0x800144B0: lwc1        $f6, 0x4($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
            goto L_80014560;
    }
    goto skip_1;
    // 0x800144B0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x800144B4: b           L_80014578
    // 0x800144B8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
        goto L_80014578;
    // 0x800144B8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x800144BC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800144C0:
    // 0x800144C0: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800144C4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800144C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800144CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800144D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800144D4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800144D8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800144DC: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800144E0: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800144E4: ldc1        $f4, 0x1430($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1430);
    // 0x800144E8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800144EC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800144F0: ldc1        $f8, 0x1438($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1438);
    // 0x800144F4: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x800144F8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800144FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80014500: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80014504: jal         0x800232F4
    // 0x80014508: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80014508: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_0:
    // 0x8001450C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80014510: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014514: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80014518: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001451C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014520: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014524: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80014528: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001452C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80014530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80014534: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80014538: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8001453C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80014540: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80014544: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x80014548: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001454C: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80014550: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80014554: b           L_80014574
    // 0x80014558: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
        goto L_80014574;
    // 0x80014558: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8001455C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
L_80014560:
    // 0x80014560: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80014564: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80014568: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8001456C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80014570: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_80014574:
    // 0x80014574: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
L_80014578:
    // 0x80014578: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8001457C: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80014580: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x80014584: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x80014588: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8001458C: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x80014590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014594: jr          $ra
    // 0x80014598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001C8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C8C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C8C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C8CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C8D0: lw          $v0, -0x2E60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2E60);
    // 0x8001C8D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001C8D8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001C8DC: bne         $v0, $at, L_8001C8FC
    if (ctx->r2 != ctx->r1) {
        // 0x8001C8E0: addiu       $v1, $v1, -0x2F58
        ctx->r3 = ADD32(ctx->r3, -0X2F58);
            goto L_8001C8FC;
    }
    // 0x8001C8E0: addiu       $v1, $v1, -0x2F58
    ctx->r3 = ADD32(ctx->r3, -0X2F58);
    // 0x8001C8E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C8E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C8EC: swc1        $f0, -0x3A64($at)
    MEM_W(-0X3A64, ctx->r1) = ctx->f0.u32l;
    // 0x8001C8F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C8F4: b           L_8001C91C
    // 0x8001C8F8: swc1        $f0, -0x3A60($at)
    MEM_W(-0X3A60, ctx->r1) = ctx->f0.u32l;
        goto L_8001C91C;
    // 0x8001C8F8: swc1        $f0, -0x3A60($at)
    MEM_W(-0X3A60, ctx->r1) = ctx->f0.u32l;
L_8001C8FC:
    // 0x8001C8FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C900: lwc1        $f4, -0x2E34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E34);
    // 0x8001C904: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C908: swc1        $f4, -0x3A64($at)
    MEM_W(-0X3A64, ctx->r1) = ctx->f4.u32l;
    // 0x8001C90C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C910: lwc1        $f6, -0x2E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E2C);
    // 0x8001C914: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C918: swc1        $f6, -0x3A60($at)
    MEM_W(-0X3A60, ctx->r1) = ctx->f6.u32l;
L_8001C91C:
    // 0x8001C91C: addiu       $t6, $zero, 0x305
    ctx->r14 = ADD32(0, 0X305);
    // 0x8001C920: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C924: sh          $t6, -0x3A6E($at)
    MEM_H(-0X3A6E, ctx->r1) = ctx->r14;
    // 0x8001C928: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C92C: sh          $zero, -0x3A6A($at)
    MEM_H(-0X3A6A, ctx->r1) = 0;
    // 0x8001C930: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C934: sh          $zero, -0x3A6C($at)
    MEM_H(-0X3A6C, ctx->r1) = 0;
    // 0x8001C938: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001C93C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001C940: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C944: addiu       $t0, $t0, -0x2F54
    ctx->r8 = ADD32(ctx->r8, -0X2F54);
    // 0x8001C948: sw          $t7, -0x3A98($at)
    MEM_W(-0X3A98, ctx->r1) = ctx->r15;
    // 0x8001C94C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8001C950: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C954: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x8001C958: sw          $t8, -0x3A94($at)
    MEM_W(-0X3A94, ctx->r1) = ctx->r24;
    // 0x8001C95C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C960: sw          $v0, -0x3A90($at)
    MEM_W(-0X3A90, ctx->r1) = ctx->r2;
    // 0x8001C964: lui         $t1, 0x803B
    ctx->r9 = S32(0X803B << 16);
    // 0x8001C968: addiu       $t9, $t9, -0x5E9C
    ctx->r25 = ADD32(ctx->r25, -0X5E9C);
    // 0x8001C96C: addiu       $t1, $t1, -0x5448
    ctx->r9 = ADD32(ctx->r9, -0X5448);
    // 0x8001C970: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001C974: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8001C978: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001C97C: addiu       $t2, $t2, -0x3668
    ctx->r10 = ADD32(ctx->r10, -0X3668);
    // 0x8001C980: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001C984: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001C988: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001C98C: lw          $a3, -0x2E24($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2E24);
    // 0x8001C990: lw          $a2, -0x3A60($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3A60);
    // 0x8001C994: lw          $a1, -0x3A64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A64);
    // 0x8001C998: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001C99C: jal         0x8000B7DC
    // 0x8001C9A0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    func_8000B7DC(rdram, ctx);
        goto after_0;
    // 0x8001C9A0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    after_0:
    // 0x8001C9A4: jal         0x8000B2B8
    // 0x8001C9A8: nop

    func_8000B2B8(rdram, ctx);
        goto after_1;
    // 0x8001C9A8: nop

    after_1:
    // 0x8001C9AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C9B0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C9B4: sw          $zero, -0x2E60($at)
    MEM_W(-0X2E60, ctx->r1) = 0;
    // 0x8001C9B8: addiu       $v0, $v0, -0x3670
    ctx->r2 = ADD32(ctx->r2, -0X3670);
    // 0x8001C9BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001C9C0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001C9C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C9C8: jal         0x80009260
    // 0x8001C9CC: sh          $t3, -0x3A66($at)
    MEM_H(-0X3A66, ctx->r1) = ctx->r11;
    func_80009260(rdram, ctx);
        goto after_2;
    // 0x8001C9CC: sh          $t3, -0x3A66($at)
    MEM_H(-0X3A66, ctx->r1) = ctx->r11;
    after_2:
    // 0x8001C9D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C9D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C9D8: sw          $v0, -0x3AA8($at)
    MEM_W(-0X3AA8, ctx->r1) = ctx->r2;
    // 0x8001C9DC: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001C9E0: addiu       $t5, $t5, -0x3644
    ctx->r13 = ADD32(ctx->r13, -0X3644);
    // 0x8001C9E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C9E8: sw          $t5, -0x3AC8($at)
    MEM_W(-0X3AC8, ctx->r1) = ctx->r13;
    // 0x8001C9EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C9F0: sh          $v0, -0x3A74($at)
    MEM_H(-0X3A74, ctx->r1) = ctx->r2;
    // 0x8001C9F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C9F8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001C9FC: lhu         $t6, -0x3A66($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A66);
    // 0x8001CA00: sh          $v0, -0x3A72($at)
    MEM_H(-0X3A72, ctx->r1) = ctx->r2;
    // 0x8001CA04: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001CA08: sh          $zero, -0x3A70($at)
    MEM_H(-0X3A70, ctx->r1) = 0;
    // 0x8001CA0C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001CA10: lw          $t8, -0x3A90($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3A90);
    // 0x8001CA14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001CA18: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001CA1C: sh          $t7, -0x3A68($at)
    MEM_H(-0X3A68, ctx->r1) = ctx->r15;
    // 0x8001CA20: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001CA24: beq         $t8, $at, L_8001CA34
    if (ctx->r24 == ctx->r1) {
        // 0x8001CA28: addiu       $v0, $zero, 0x29
        ctx->r2 = ADD32(0, 0X29);
            goto L_8001CA34;
    }
    // 0x8001CA28: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x8001CA2C: b           L_8001CA34
    // 0x8001CA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CA34;
    // 0x8001CA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001CA34:
    // 0x8001CA34: sll         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2 << 24);
    // 0x8001CA38: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001CA3C: jal         0x800267B8
    // 0x8001CA40: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    UpdateBGM(rdram, ctx);
        goto after_3;
    // 0x8001CA40: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x8001CA44: jal         0x80003A1C
    // 0x8001CA48: nop

    func_80003A1C(rdram, ctx);
        goto after_4;
    // 0x8001CA48: nop

    after_4:
    // 0x8001CA4C: jal         0x80020888
    // 0x8001CA50: nop

    func_80020888(rdram, ctx);
        goto after_5;
    // 0x8001CA50: nop

    after_5:
    // 0x8001CA54: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001CA58: lw          $t1, -0x3A90($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3A90);
    // 0x8001CA5C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8001CA60: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001CA64: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001CA68: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8001CA6C: lwc1        $f8, -0x2D74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2D74);
    // 0x8001CA70: addiu       $v0, $v0, -0x3BCC
    ctx->r2 = ADD32(ctx->r2, -0X3BCC);
    // 0x8001CA74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001CA78: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8001CA7C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001CA80: ldc1        $f18, 0x1618($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1618);
    // 0x8001CA84: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001CA88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001CA8C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001CA90: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8001CA94: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8001CA98: lw          $a3, -0x3A60($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3A60);
    // 0x8001CA9C: lw          $a2, -0x2E30($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2E30);
    // 0x8001CAA0: lw          $a1, -0x3A64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A64);
    // 0x8001CAA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001CAA8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001CAAC: jal         0x80019A98
    // 0x8001CAB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80019A98(rdram, ctx);
        goto after_6;
    // 0x8001CAB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8001CAB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001CAB8: sh          $v0, -0x3AA4($at)
    MEM_H(-0X3AA4, ctx->r1) = ctx->r2;
    // 0x8001CABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CAC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CAC4: jr          $ra
    // 0x8001CAC8: nop

    return;
    // 0x8001CAC8: nop

;}
RECOMP_FUNC void func_80017998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017998: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001799C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800179A0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800179A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800179A8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800179AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800179B0: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x800179B4: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x800179B8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800179BC: bltzl       $v0, L_80017AB0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800179C0: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_80017AB0;
    }
    goto skip_0;
    // 0x800179C0: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    skip_0:
    // 0x800179C4: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800179C8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800179CC: addiu       $t1, $t1, 0x71D0
    ctx->r9 = ADD32(ctx->r9, 0X71D0);
    // 0x800179D0: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800179D4: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800179D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800179DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800179E0: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x800179E4: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800179E8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800179EC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800179F0: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x800179F4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800179F8: addiu       $t7, $t7, 0x1B90
    ctx->r15 = ADD32(ctx->r15, 0X1B90);
    // 0x800179FC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80017A00: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80017A04: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80017A08: bc1fl       L_80017A28
    if (!c1cs) {
        // 0x80017A0C: lwc1        $f14, 0x20($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80017A28;
    }
    goto skip_1;
    // 0x80017A0C: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80017A10: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80017A14: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80017A18: nop

    // 0x80017A1C: bc1tl       L_80017A50
    if (c1cs) {
        // 0x80017A20: lwc1        $f2, 0x10($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
            goto L_80017A50;
    }
    goto skip_2;
    // 0x80017A20: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    skip_2:
    // 0x80017A24: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
L_80017A28:
    // 0x80017A28: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80017A2C: jal         0x80023210
    // 0x80017A30: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80017A30: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80017A34: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80017A38: addiu       $t1, $t1, 0x71D0
    ctx->r9 = ADD32(ctx->r9, 0X71D0);
    // 0x80017A3C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80017A40: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80017A44: b           L_80017A50
    // 0x80017A48: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80017A50;
    // 0x80017A48: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80017A4C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
L_80017A50:
    // 0x80017A50: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80017A54: lhu         $a0, 0x2($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X2);
    // 0x80017A58: lhu         $a1, 0x4($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X4);
    // 0x80017A5C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80017A60: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x80017A64: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80017A68: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80017A6C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80017A70: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80017A74: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80017A78: jal         0x800177F8
    // 0x80017A7C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800177F8(rdram, ctx);
        goto after_1;
    // 0x80017A7C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80017A80: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80017A84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80017A88: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80017A8C: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80017A90: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80017A94: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80017A98: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
    // 0x80017A9C: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80017AA0: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80017AA4: b           L_80017AB0
    // 0x80017AA8: swc1        $f6, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f6.u32l;
        goto L_80017AB0;
    // 0x80017AA8: swc1        $f6, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f6.u32l;
    // 0x80017AAC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
L_80017AB0:
    // 0x80017AB0: lhu         $t3, 0x0($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X0);
    // 0x80017AB4: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x80017AB8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80017ABC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80017AC0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80017AC4: lw          $t5, 0x38F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X38F4);
    // 0x80017AC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017ACC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017AD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017AD4: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x80017AD8: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80017ADC: beql        $a0, $zero, L_80017BAC
    if (ctx->r4 == 0) {
        // 0x80017AE0: lb          $a1, 0x40($t0)
        ctx->r5 = MEM_B(ctx->r8, 0X40);
            goto L_80017BAC;
    }
    goto skip_3;
    // 0x80017AE0: lb          $a1, 0x40($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X40);
    skip_3:
    // 0x80017AE4: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x80017AE8: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80017AEC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80017AF0: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80017AF4: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x80017AF8: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80017AFC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80017B00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017B04: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80017B08: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80017B0C: nop

    // 0x80017B10: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80017B14: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80017B18: beq         $a0, $at, L_80017B34
    if (ctx->r4 == ctx->r1) {
        // 0x80017B1C: add.s       $f14, $f4, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
            goto L_80017B34;
    }
    // 0x80017B1C: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80017B20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017B24: beq         $a0, $at, L_80017B74
    if (ctx->r4 == ctx->r1) {
        // 0x80017B28: nop
    
            goto L_80017B74;
    }
    // 0x80017B28: nop

    // 0x80017B2C: b           L_80017BAC
    // 0x80017B30: lb          $a1, 0x40($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X40);
        goto L_80017BAC;
    // 0x80017B30: lb          $a1, 0x40($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X40);
L_80017B34:
    // 0x80017B34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017B38: ldc1        $f18, 0x14F0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X14F0);
    // 0x80017B3C: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x80017B40: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80017B44: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80017B48: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80017B4C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x80017B50: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80017B54: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80017B58: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80017B5C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80017B60: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80017B64: jal         0x80019354
    // 0x80017B68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80019354(rdram, ctx);
        goto after_2;
    // 0x80017B68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80017B6C: b           L_80017BA8
    // 0x80017B70: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_80017BA8;
    // 0x80017B70: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80017B74:
    // 0x80017B74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017B78: ldc1        $f10, 0x14F8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X14F8);
    // 0x80017B7C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80017B80: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80017B84: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80017B88: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80017B8C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80017B90: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80017B94: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80017B98: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80017B9C: jal         0x80019738
    // 0x80017BA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80019738(rdram, ctx);
        goto after_3;
    // 0x80017BA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80017BA4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80017BA8:
    // 0x80017BA8: lb          $a1, 0x40($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X40);
L_80017BAC:
    // 0x80017BAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80017BB0: bltzl       $a1, L_80017BC4
    if (SIGNED(ctx->r5) < 0) {
        // 0x80017BB4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80017BC4;
    }
    goto skip_4;
    // 0x80017BB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80017BB8: jal         0x800268D4
    // 0x80017BBC: lbu         $a0, 0x41($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X41);
    func_800268D4(rdram, ctx);
        goto after_4;
    // 0x80017BBC: lbu         $a0, 0x41($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X41);
    after_4:
    // 0x80017BC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80017BC4:
    // 0x80017BC4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80017BC8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80017BCC: jr          $ra
    // 0x80017BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80017BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80000EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80000EF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80000EF4: addiu       $t6, $zero, 0x160
    ctx->r14 = ADD32(0, 0X160);
    // 0x80000EF8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000EFC: sw          $t6, -0x4D1C($at)
    MEM_W(-0X4D1C, ctx->r1) = ctx->r14;
    // 0x80000F00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F04: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80000F08: sh          $t7, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r15;
    // 0x80000F0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F10: sw          $v0, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = ctx->r2;
    // 0x80000F14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F18: sw          $v0, 0x4EF8($at)
    MEM_W(0X4EF8, ctx->r1) = ctx->r2;
    // 0x80000F1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F20: sw          $v0, 0x4F04($at)
    MEM_W(0X4F04, ctx->r1) = ctx->r2;
    // 0x80000F24: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F28: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80000F2C: sh          $t8, 0x4F14($at)
    MEM_H(0X4F14, ctx->r1) = ctx->r24;
    // 0x80000F30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F34: swc1        $f0, 0x6E44($at)
    MEM_W(0X6E44, ctx->r1) = ctx->f0.u32l;
    // 0x80000F38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F3C: sh          $zero, 0x59E2($at)
    MEM_H(0X59E2, ctx->r1) = 0;
    // 0x80000F40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F44: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80000F48: sw          $t9, 0x4EEC($at)
    MEM_W(0X4EEC, ctx->r1) = ctx->r25;
    // 0x80000F4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F50: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x80000F54: sw          $t0, 0x4EF0($at)
    MEM_W(0X4EF0, ctx->r1) = ctx->r8;
    // 0x80000F58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F5C: sw          $v0, 0x5370($at)
    MEM_W(0X5370, ctx->r1) = ctx->r2;
    // 0x80000F60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F64: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x80000F68: sh          $t1, -0x45A0($at)
    MEM_H(-0X45A0, ctx->r1) = ctx->r9;
    // 0x80000F6C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F70: addiu       $t2, $zero, 0x11
    ctx->r10 = ADD32(0, 0X11);
    // 0x80000F74: sh          $t2, -0x459E($at)
    MEM_H(-0X459E, ctx->r1) = ctx->r10;
    // 0x80000F78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F7C: sh          $zero, -0x459C($at)
    MEM_H(-0X459C, ctx->r1) = 0;
    // 0x80000F80: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x80000F84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000F88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F8C: addiu       $t3, $zero, 0x108
    ctx->r11 = ADD32(0, 0X108);
    // 0x80000F90: swc1        $f4, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f4.u32l;
    // 0x80000F94: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000F98: swc1        $f0, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f0.u32l;
    // 0x80000F9C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80000FA0: lwc1        $f6, 0xF04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF04);
    // 0x80000FA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FA8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80000FAC: swc1        $f6, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f6.u32l;
    // 0x80000FB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FB4: sw          $t3, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r11;
    // 0x80000FB8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FBC: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x80000FC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FC4: sh          $t4, -0x4D18($at)
    MEM_H(-0X4D18, ctx->r1) = ctx->r12;
    // 0x80000FC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FCC: sh          $zero, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = 0;
    // 0x80000FD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FD4: sb          $zero, -0x4CBC($at)
    MEM_B(-0X4CBC, ctx->r1) = 0;
    // 0x80000FD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000FDC: sb          $zero, -0x4CBB($at)
    MEM_B(-0X4CBB, ctx->r1) = 0;
    // 0x80000FE0: jr          $ra
    // 0x80000FE4: nop

    return;
    // 0x80000FE4: nop

;}
RECOMP_FUNC void func_8000A508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A50C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000A510: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8000A514: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A518: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000A51C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000A520: beql        $a0, $zero, L_8000A5E8
    if (ctx->r4 == 0) {
        // 0x8000A524: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8000A5E8;
    }
    goto skip_0;
    // 0x8000A524: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8000A528: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A52C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000A530: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A534: lwc1        $f10, -0x3A5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x8000A538: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A53C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000A540: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A544: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A548: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A54C: lwc1        $f10, -0x3BD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3BD0);
    // 0x8000A550: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A554: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000A558: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8000A55C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A560: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000A564: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8000A568: jal         0x80034F60
    // 0x8000A56C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000A56C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8000A570: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8000A574: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000A578: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000A57C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000A580: lwc1        $f10, 0x120($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X120);
    // 0x8000A584: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000A588: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000A58C: nop

    // 0x8000A590: bc1fl       L_8000A5E8
    if (!c1cs) {
        // 0x8000A594: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8000A5E8;
    }
    goto skip_1;
    // 0x8000A594: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8000A598: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8000A59C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A5A0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A5A4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000A5A8: lwc1        $f4, -0x3A5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x8000A5AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A5B0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000A5B4: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8000A5B8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000A5BC: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000A5C0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8000A5C4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A5C8: lwc1        $f8, -0x3BD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3BD0);
    // 0x8000A5CC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000A5D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000A5D4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8000A5D8: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8000A5DC: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8000A5E0: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8000A5E4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_8000A5E8:
    // 0x8000A5E8: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000A5EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A5F0: lwc1        $f10, -0x3A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x8000A5F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A5F8: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000A5FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A600: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A604: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A608: lwc1        $f10, -0x3A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x8000A60C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A610: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000A614: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8000A618: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A61C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000A620: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8000A624: jal         0x80034F60
    // 0x8000A628: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x8000A628: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8000A62C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A630: lwc1        $f18, -0x3BCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3BCC);
    // 0x8000A634: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000A638: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000A63C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8000A640: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000A644: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8000A648: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8000A64C: bc1f        L_8000A6C8
    if (!c1cs) {
        // 0x8000A650: nop
    
            goto L_8000A6C8;
    }
    // 0x8000A650: nop

    // 0x8000A654: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8000A658: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000A65C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8000A660: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x8000A664: sub.d       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f8.d - ctx->f10.d;
    // 0x8000A668: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A66C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A670: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8000A674: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8000A678: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8000A67C: lwc1        $f10, -0x3A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x8000A680: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000A684: div.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x8000A688: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x8000A68C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8000A690: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8000A694: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8000A698: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8000A69C: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x8000A6A0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8000A6A4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A6A8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8000A6AC: div.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f12.d);
    // 0x8000A6B0: lwc1        $f10, -0x3A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x8000A6B4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8000A6B8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8000A6BC: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8000A6C0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8000A6C4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
L_8000A6C8:
    // 0x8000A6C8: jal         0x8000A854
    // 0x8000A6CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8000A854(rdram, ctx);
        goto after_2;
    // 0x8000A6CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8000A6D0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6D4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A6D8: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x8000A6DC: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8000A6E0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8000A6E4: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x8000A6E8: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8000A6EC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6F0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000A6F4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8000A6F8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8000A6FC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8000A700: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000A704: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8000A708: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8000A70C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8000A710: bnel        $t8, $zero, L_8000A72C
    if (ctx->r24 != 0) {
        // 0x8000A714: lwc1        $f8, 0x18($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
            goto L_8000A72C;
    }
    goto skip_2;
    // 0x8000A714: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x8000A718: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000A71C: beql        $t0, $zero, L_8000A72C
    if (ctx->r8 == 0) {
        // 0x8000A720: lwc1        $f8, 0x18($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
            goto L_8000A72C;
    }
    goto skip_3;
    // 0x8000A720: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    skip_3:
    // 0x8000A724: addiu       $a3, $zero, 0xA01
    ctx->r7 = ADD32(0, 0XA01);
    // 0x8000A728: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
L_8000A72C:
    // 0x8000A72C: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8000A730: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A734: addiu       $v0, $v0, -0x2F20
    ctx->r2 = ADD32(ctx->r2, -0X2F20);
    // 0x8000A738: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000A73C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8000A740: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8000A744: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000A748: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000A74C: jal         0x8000EE60
    // 0x8000A750: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8000EE60(rdram, ctx);
        goto after_3;
    // 0x8000A750: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x8000A754: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A758: addiu       $v0, $v0, -0x2F20
    ctx->r2 = ADD32(ctx->r2, -0X2F20);
    // 0x8000A75C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000A760: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8000A764: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8000A768: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000A76C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8000A770: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000A774: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8000A778: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8000A77C: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8000A780: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8000A784: beql        $t3, $zero, L_8000A7AC
    if (ctx->r11 == 0) {
        // 0x8000A788: lwc1        $f10, 0xC($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8000A7AC;
    }
    goto skip_4;
    // 0x8000A788: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    skip_4:
    // 0x8000A78C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000A790: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000A794: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000A798: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8000A79C: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x8000A7A0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8000A7A4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8000A7A8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
L_8000A7AC:
    // 0x8000A7AC: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8000A7B0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000A7B4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8000A7B8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000A7BC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8000A7C0: lhu         $t4, 0x18($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X18);
    // 0x8000A7C4: sh          $t4, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r12;
    // 0x8000A7C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A7CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000A7D0: jr          $ra
    // 0x8000A7D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000A7D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80048AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048AE0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80048AE4: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80048AE8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80048AEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80048AF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80048AF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048AF8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80048AFC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80048B00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048B04: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80048B08: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80048B0C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80048B10: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80048B14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048B18: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80048B1C: nop

    // 0x80048B20: bc1fl       L_80048B48
    if (!c1cs) {
        // 0x80048B24: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_80048B48;
    }
    goto skip_0;
    // 0x80048B24: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x80048B28: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048B2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048B30: nop

    // 0x80048B34: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x80048B38: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80048B3C: b           L_80048B4C
    // 0x80048B40: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_80048B4C;
    // 0x80048B40: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80048B44: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_80048B48:
    // 0x80048B48: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_80048B4C:
    // 0x80048B4C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80048B50: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80048B54: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048B58: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80048B5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048B60: bc1fl       L_80048B70
    if (!c1cs) {
        // 0x80048B64: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_80048B70;
    }
    goto skip_1;
    // 0x80048B64: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x80048B68: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80048B6C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_80048B70:
    // 0x80048B70: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80048B74: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x80048B78: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80048B7C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80048B80: jr          $ra
    // 0x80048B84: nop

    return;
    // 0x80048B84: nop

;}
RECOMP_FUNC void func_80042860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042860: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80042864: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80042868: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x8004286C: bltz        $v1, L_8004287C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80042870: nop
    
            goto L_8004287C;
    }
    // 0x80042870: nop

    // 0x80042874: jr          $ra
    // 0x80042878: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80042878: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004287C:
    // 0x8004287C: jr          $ra
    // 0x80042880: nop

    return;
    // 0x80042880: nop

;}
RECOMP_FUNC void func_80015B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B8C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80015B90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80015B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80015B98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80015B9C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80015BA0: addiu       $t7, $t7, -0x3258
    ctx->r15 = ADD32(ctx->r15, -0X3258);
    // 0x80015BA4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80015BA8: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80015BAC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80015BB0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80015BB4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80015BB8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80015BBC: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80015BC0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80015BC4: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80015BC8: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80015BCC: addiu       $t2, $t2, -0x3244
    ctx->r10 = ADD32(ctx->r10, -0X3244);
    // 0x80015BD0: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80015BD4: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80015BD8: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80015BDC: addiu       $t1, $sp, 0x3C
    ctx->r9 = ADD32(ctx->r29, 0X3C);
    // 0x80015BE0: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80015BE4: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80015BE8: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80015BEC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80015BF0: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80015BF4: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80015BF8: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80015BFC: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x80015C00: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x80015C04: lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XA);
    // 0x80015C08: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80015C0C: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80015C10: bnel        $t9, $zero, L_80015FD8
    if (ctx->r25 != 0) {
        // 0x80015C14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015FD8;
    }
    goto skip_0;
    // 0x80015C14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80015C18: beq         $v0, $zero, L_80015E88
    if (ctx->r2 == 0) {
        // 0x80015C1C: andi        $t8, $v1, 0x2
        ctx->r24 = ctx->r3 & 0X2;
            goto L_80015E88;
    }
    // 0x80015C1C: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80015C20: bnel        $t8, $zero, L_80015C3C
    if (ctx->r24 != 0) {
        // 0x80015C24: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80015C3C;
    }
    goto skip_1;
    // 0x80015C24: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x80015C28: lh          $t6, 0x50($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X50);
    // 0x80015C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80015C30: bnel        $t6, $at, L_80015C50
    if (ctx->r14 != ctx->r1) {
        // 0x80015C34: lw          $v1, 0x64($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X64);
            goto L_80015C50;
    }
    goto skip_2;
    // 0x80015C34: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    skip_2:
    // 0x80015C38: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80015C3C:
    // 0x80015C3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80015C40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80015C44: b           L_80015D30
    // 0x80015C48: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
        goto L_80015D30;
    // 0x80015C48: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80015C4C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
L_80015C50:
    // 0x80015C50: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80015C54: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015C58: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80015C5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015C60: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80015C64: bnel        $t7, $at, L_80015C84
    if (ctx->r15 != ctx->r1) {
        // 0x80015C68: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80015C84;
    }
    goto skip_3;
    // 0x80015C68: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_3:
    // 0x80015C6C: lw          $t0, 0x68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X68);
    // 0x80015C70: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015C74: lwc1        $f8, 0x94($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X94);
    // 0x80015C78: b           L_80015CBC
    // 0x80015C7C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_80015CBC;
    // 0x80015C7C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80015C80: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
L_80015C84:
    // 0x80015C84: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80015C88: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015C8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80015C90: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015C94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015C98: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80015C9C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80015CA0: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80015CA4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80015CA8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015CAC: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x80015CB0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80015CB4: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x80015CB8: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
L_80015CBC:
    // 0x80015CBC: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80015CC0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80015CC4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80015CC8: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80015CCC: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015CD0: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80015CD4: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x80015CD8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015CDC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80015CE0: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x80015CE4: jal         0x80034F60
    // 0x80015CE8: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80015CE8: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_0:
    // 0x80015CEC: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x80015CF0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015CF4: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015CF8: lhu         $t3, 0x28($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X28);
    // 0x80015CFC: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015D00: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80015D04: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80015D08: lwc1        $f2, 0x50($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X50);
    // 0x80015D0C: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80015D10: nop

    // 0x80015D14: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80015D18: nop

    // 0x80015D1C: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80015D20: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80015D24: div.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80015D28: div.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80015D2C: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
L_80015D30:
    // 0x80015D30: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80015D34: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80015D38: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015D3C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015D40: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80015D44: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015D48: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80015D4C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x80015D50: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x80015D54: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80015D58: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80015D5C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80015D60: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80015D64: jal         0x80034F60
    // 0x80015D68: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80015D68: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80015D6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015D70: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80015D74: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015D78: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80015D7C: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015D80: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015D84: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80015D88: bc1t        L_80015DD0
    if (c1cs) {
        // 0x80015D8C: nop
    
            goto L_80015DD0;
    }
    // 0x80015D8C: nop

    // 0x80015D90: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80015D94: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80015D98: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80015D9C: div.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80015DA0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80015DA4: div.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f2.d);
    // 0x80015DA8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80015DAC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80015DB0: add.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80015DB4: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80015DB8: div.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f2.d);
    // 0x80015DBC: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80015DC0: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80015DC4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80015DC8: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80015DCC: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_80015DD0:
    // 0x80015DD0: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80015DD4: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x80015DD8: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x80015DDC: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80015DE0: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015DE4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015DE8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015DEC: jal         0x80034F60
    // 0x80015DF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80015DF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80015DF4: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x80015DF8: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015DFC: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015E00: lhu         $t9, 0x2E($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X2E);
    // 0x80015E04: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015E08: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80015E0C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80015E10: addu        $t6, $sp, $t8
    ctx->r14 = ADD32(ctx->r29, ctx->r24);
    // 0x80015E14: lwc1        $f2, 0x3C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x80015E18: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80015E1C: ldc1        $f12, 0x1498($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1498);
    // 0x80015E20: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80015E24: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80015E28: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80015E2C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80015E30: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80015E34: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80015E38: mul.d       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80015E3C: div.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80015E40: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80015E44: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80015E48: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80015E4C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80015E50: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80015E54: mul.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80015E58: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80015E5C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80015E60: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x80015E64: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80015E68: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80015E6C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80015E70: mul.d       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80015E74: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x80015E78: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80015E7C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80015E80: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80015E84: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80015E88:
    // 0x80015E88: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80015E8C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80015E90: addiu       $t3, $t3, 0x71E0
    ctx->r11 = ADD32(ctx->r11, 0X71E0);
    // 0x80015E94: lhu         $t7, 0x2A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2A);
    // 0x80015E98: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80015E9C: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x80015EA0: beql        $t0, $zero, L_80015ECC
    if (ctx->r8 == 0) {
        // 0x80015EA4: lwc1        $f8, 0xC($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80015ECC;
    }
    goto skip_4;
    // 0x80015EA4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x80015EA8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80015EAC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80015EB0: ldc1        $f10, 0x14A0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X14A0);
    // 0x80015EB4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80015EB8: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80015EBC: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80015EC0: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80015EC4: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80015EC8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
L_80015ECC:
    // 0x80015ECC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80015ED0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015ED4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80015ED8: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80015EDC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80015EE0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80015EE4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80015EE8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80015EEC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80015EF0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015EF4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80015EF8: lhu         $t4, 0x14($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X14);
    // 0x80015EFC: beql        $t4, $zero, L_80015FD8
    if (ctx->r12 == 0) {
        // 0x80015F00: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015FD8;
    }
    goto skip_5;
    // 0x80015F00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80015F04: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015F08: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015F0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80015F10: jal         0x8000EE60
    // 0x80015F14: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8000EE60(rdram, ctx);
        goto after_3;
    // 0x80015F14: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x80015F18: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x80015F1C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015F20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015F24: lhu         $v0, 0x14($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X14);
    // 0x80015F28: addiu       $v1, $v1, 0x71E0
    ctx->r3 = ADD32(ctx->r3, 0X71E0);
    // 0x80015F2C: beq         $v0, $at, L_80015F44
    if (ctx->r2 == ctx->r1) {
        // 0x80015F30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80015F44;
    }
    // 0x80015F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80015F34: beql        $v0, $at, L_80015FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80015F38: lwc1        $f4, 0x4($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80015FD0;
    }
    goto skip_6;
    // 0x80015F38: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    skip_6:
    // 0x80015F3C: b           L_80015FD8
    // 0x80015F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80015FD8;
    // 0x80015F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80015F44:
    // 0x80015F44: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015F48: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80015F4C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80015F50: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80015F54: nop

    // 0x80015F58: bc1fl       L_80015FD8
    if (!c1cs) {
        // 0x80015F5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015FD8;
    }
    goto skip_7;
    // 0x80015F5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80015F60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015F64: lhu         $t2, 0xA($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XA);
    // 0x80015F68: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80015F6C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80015F70: ori         $t5, $t2, 0x1
    ctx->r13 = ctx->r10 | 0X1;
    // 0x80015F74: sh          $t5, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r13;
    // 0x80015F78: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80015F7C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80015F80: beq         $v0, $zero, L_80015FA0
    if (ctx->r2 == 0) {
        // 0x80015F84: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_80015FA0;
    }
    // 0x80015F84: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80015F88: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80015F8C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80015F90: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80015F94: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x80015F98: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80015F9C: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
L_80015FA0:
    // 0x80015FA0: jal         0x80013F20
    // 0x80015FA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80013F20(rdram, ctx);
        goto after_4;
    // 0x80015FA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80015FA8: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80015FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80015FB0: lh          $t4, 0x20($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X20);
    // 0x80015FB4: bltzl       $t4, L_80015FD8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80015FB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015FD8;
    }
    goto skip_8;
    // 0x80015FB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80015FBC: jal         0x80017FA0
    // 0x80015FC0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    func_80017FA0(rdram, ctx);
        goto after_5;
    // 0x80015FC0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_5:
    // 0x80015FC4: b           L_80015FD8
    // 0x80015FC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80015FD8;
    // 0x80015FC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80015FCC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
L_80015FD0:
    // 0x80015FD0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80015FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80015FD8:
    // 0x80015FD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80015FDC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80015FE0: jr          $ra
    // 0x80015FE4: nop

    return;
    // 0x80015FE4: nop

;}
RECOMP_FUNC void func_8002A0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0B8: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8002A0BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A0C0: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002A0C4: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002A0C8: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002A0CC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002A0D0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002A0D4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002A0D8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002A0DC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A0E0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A0E4: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x8002A0E8: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x8002A0EC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002A0F0: addiu       $t7, $t7, -0x6D4
    ctx->r15 = ADD32(ctx->r15, -0X6D4);
    // 0x8002A0F4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002A0F8: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8002A0FC: addiu       $t6, $sp, 0xFC
    ctx->r14 = ADD32(ctx->r29, 0XFC);
    // 0x8002A100: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002A104: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8002A108: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8002A10C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002A110: addiu       $t8, $sp, 0xDC
    ctx->r24 = ADD32(ctx->r29, 0XDC);
    // 0x8002A114: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8002A118: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8002A11C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002A120: addiu       $t6, $t6, -0x6C4
    ctx->r14 = ADD32(ctx->r14, -0X6C4);
    // 0x8002A124: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8002A128: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8002A12C: addiu       $t7, $sp, 0xFC
    ctx->r15 = ADD32(ctx->r29, 0XFC);
    // 0x8002A130: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8002A134: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8002A138: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8002A13C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8002A140: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002A144: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
    // 0x8002A148: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x8002A14C: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x8002A150: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x8002A154: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002A158: sw          $at, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r1;
    // 0x8002A15C: sw          $t9, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r25;
    // 0x8002A160: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x8002A164: lw          $at, 0x18($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X18);
    // 0x8002A168: sw          $t9, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r25;
    // 0x8002A16C: sw          $at, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r1;
    // 0x8002A170: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8002A174: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
L_8002A178:
    // 0x8002A178: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8002A17C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A180: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8002A184: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8002A188: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A18C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A190: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A194: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8002A198: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A19C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x8002A1A0: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x8002A1A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A1A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A1AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A1B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A1B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A1B8: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8002A1BC: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x8002A1C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A1C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A1C8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8002A1CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A1D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A1D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A1D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002A1DC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8002A1E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A1E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A1E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A1EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8002A1F0: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x8002A1F4: beq         $t8, $at, L_8002A224
    if (ctx->r24 == ctx->r1) {
        // 0x8002A1F8: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8002A224;
    }
    // 0x8002A1F8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002A1FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A200: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002A204: addiu       $t7, $t7, -0xDD8
    ctx->r15 = ADD32(ctx->r15, -0XDD8);
    // 0x8002A208: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A20C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A210: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8002A214: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A218: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A21C: b           L_8002A260
    // 0x8002A220: nop

        goto L_8002A260;
    // 0x8002A220: nop

L_8002A224:
    // 0x8002A224: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A228: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8002A22C: addiu       $t9, $t9, -0xDC0
    ctx->r25 = ADD32(ctx->r25, -0XDC0);
    // 0x8002A230: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A234: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A238: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8002A23C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A240: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A244: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A248: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8002A24C: addiu       $t6, $zero, -0x80
    ctx->r14 = ADD32(0, -0X80);
    // 0x8002A250: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A254: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A258: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A25C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8002A260:
    // 0x8002A260: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A264: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A268: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A26C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A270: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002A274: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A278: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8002A27C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A280: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A284: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002A288: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002A28C: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8002A290: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A294: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A298: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8002A29C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8002A2A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A2A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A2A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A2AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002A2B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A2B4: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8002A2B8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8002A2BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A2C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A2C4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A2C8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A2CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A2D0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8002A2D4: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8002A2D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A2DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A2E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A2E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A2E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A2EC: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8002A2F0: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8002A2F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A2F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A2FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002A300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A304: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A308: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A30C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A310: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A314: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002A318: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
L_8002A31C:
    // 0x8002A31C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002A320: sw          $zero, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = 0;
    // 0x8002A324: beq         $t9, $at, L_8002A35C
    if (ctx->r25 == ctx->r1) {
        // 0x8002A328: lw          $t4, 0x11C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X11C);
            goto L_8002A35C;
    }
    // 0x8002A328: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8002A32C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A330: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002A334: beq         $t9, $at, L_8002A39C
    if (ctx->r25 == ctx->r1) {
        // 0x8002A338: sw          $zero, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = 0;
            goto L_8002A39C;
    }
    // 0x8002A338: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x8002A33C: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8002A340: addiu       $s4, $zero, 0x52
    ctx->r20 = ADD32(0, 0X52);
    // 0x8002A344: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
    // 0x8002A348: addiu       $s7, $zero, 0x32
    ctx->r23 = ADD32(0, 0X32);
    // 0x8002A34C: addiu       $s5, $zero, 0x19
    ctx->r21 = ADD32(0, 0X19);
    // 0x8002A350: addiu       $ra, $zero, 0x32
    ctx->r31 = ADD32(0, 0X32);
    // 0x8002A354: b           L_8002A3B8
    // 0x8002A358: addiu       $t4, $t4, 0x87
    ctx->r12 = ADD32(ctx->r12, 0X87);
        goto L_8002A3B8;
    // 0x8002A358: addiu       $t4, $t4, 0x87
    ctx->r12 = ADD32(ctx->r12, 0X87);
L_8002A35C:
    // 0x8002A35C: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x8002A360: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8002A364: addiu       $t4, $t4, 0x87
    ctx->r12 = ADD32(ctx->r12, 0X87);
    // 0x8002A368: bgez        $t7, L_8002A378
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002A36C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8002A378;
    }
    // 0x8002A36C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8002A370: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8002A374: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8002A378:
    // 0x8002A378: subu        $fp, $t6, $t8
    ctx->r30 = SUB32(ctx->r14, ctx->r24);
    // 0x8002A37C: sll         $t9, $fp, 5
    ctx->r25 = S32(ctx->r30 << 5);
    // 0x8002A380: addiu       $s4, $fp, 0x52
    ctx->r20 = ADD32(ctx->r30, 0X52);
    // 0x8002A384: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
    // 0x8002A388: addiu       $s7, $zero, 0x32
    ctx->r23 = ADD32(0, 0X32);
    // 0x8002A38C: addiu       $s5, $zero, 0x19
    ctx->r21 = ADD32(0, 0X19);
    // 0x8002A390: addiu       $ra, $zero, 0x32
    ctx->r31 = ADD32(0, 0X32);
    // 0x8002A394: b           L_8002A3B8
    // 0x8002A398: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
        goto L_8002A3B8;
    // 0x8002A398: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
L_8002A39C:
    // 0x8002A39C: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8002A3A0: addiu       $s4, $zero, 0x4F
    ctx->r20 = ADD32(0, 0X4F);
    // 0x8002A3A4: addiu       $s0, $zero, 0x1C
    ctx->r16 = ADD32(0, 0X1C);
    // 0x8002A3A8: addiu       $s7, $zero, 0x38
    ctx->r23 = ADD32(0, 0X38);
    // 0x8002A3AC: addiu       $s5, $zero, 0x1C
    ctx->r21 = ADD32(0, 0X1C);
    // 0x8002A3B0: addiu       $ra, $zero, 0x38
    ctx->r31 = ADD32(0, 0X38);
    // 0x8002A3B4: addiu       $t4, $t4, 0x84
    ctx->r12 = ADD32(ctx->r12, 0X84);
L_8002A3B8:
    // 0x8002A3B8: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A3BC: addiu       $a1, $s5, -0x1
    ctx->r5 = ADD32(ctx->r21, -0X1);
    // 0x8002A3C0: sll         $s2, $a1, 2
    ctx->r18 = S32(ctx->r5 << 2);
    // 0x8002A3C4: addiu       $a3, $s5, 0x7
    ctx->r7 = ADD32(ctx->r21, 0X7);
    // 0x8002A3C8: sll         $s1, $fp, 2
    ctx->r17 = S32(ctx->r30 << 2);
    // 0x8002A3CC: addiu       $s3, $ra, -0x1
    ctx->r19 = ADD32(ctx->r31, -0X1);
    // 0x8002A3D0: mflo        $t7
    ctx->r15 = lo;
    // 0x8002A3D4: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8002A3D8: bgez        $t4, L_8002A3F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002A3DC: addu        $t6, $t4, $s0
        ctx->r14 = ADD32(ctx->r12, ctx->r16);
            goto L_8002A3F8;
    }
    // 0x8002A3DC: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x8002A3E0: bltz        $t6, L_8002A3F8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8002A3E4: negu        $v0, $t4
        ctx->r2 = SUB32(0, ctx->r12);
            goto L_8002A3F8;
    }
    // 0x8002A3E4: negu        $v0, $t4
    ctx->r2 = SUB32(0, ctx->r12);
    // 0x8002A3E8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x8002A3EC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002A3F0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x8002A3F4: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
L_8002A3F8:
    // 0x8002A3F8: slti        $at, $t4, 0x141
    ctx->r1 = SIGNED(ctx->r12) < 0X141 ? 1 : 0;
    // 0x8002A3FC: bne         $at, $zero, L_8002A40C
    if (ctx->r1 != 0) {
        // 0x8002A400: addu        $t5, $t4, $s0
        ctx->r13 = ADD32(ctx->r12, ctx->r16);
            goto L_8002A40C;
    }
    // 0x8002A400: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8002A404: b           L_8002A420
    // 0x8002A408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002A420;
    // 0x8002A408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002A40C:
    // 0x8002A40C: slti        $at, $t5, 0x141
    ctx->r1 = SIGNED(ctx->r13) < 0X141 ? 1 : 0;
    // 0x8002A410: bne         $at, $zero, L_8002A420
    if (ctx->r1 != 0) {
        // 0x8002A414: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002A420;
    }
    // 0x8002A414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A418: subu        $s0, $s0, $t5
    ctx->r16 = SUB32(ctx->r16, ctx->r13);
    // 0x8002A41C: addiu       $s0, $s0, 0x140
    ctx->r16 = ADD32(ctx->r16, 0X140);
L_8002A420:
    // 0x8002A420: bgtz        $s0, L_8002A42C
    if (SIGNED(ctx->r16) > 0) {
        // 0x8002A424: andi        $t7, $a1, 0xFFF
        ctx->r15 = ctx->r5 & 0XFFF;
            goto L_8002A42C;
    }
    // 0x8002A424: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x8002A428: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002A42C:
    // 0x8002A42C: bltzl       $v0, L_8002A5F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002A430: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8002A5F8;
    }
    goto skip_0;
    // 0x8002A430: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_0:
    // 0x8002A434: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A438: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8002A43C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8002A440: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A444: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A448: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A44C: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x8002A450: sll         $t7, $s6, 2
    ctx->r15 = S32(ctx->r22 << 2);
    // 0x8002A454: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8002A458: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8002A45C: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8002A460: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x8002A464: lw          $t8, 0xDC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XDC);
    // 0x8002A468: sra         $t7, $a3, 3
    ctx->r15 = S32(SIGNED(ctx->r7) >> 3);
    // 0x8002A46C: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8002A470: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002A474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A478: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8002A47C: or          $a3, $t8, $at
    ctx->r7 = ctx->r24 | ctx->r1;
    // 0x8002A480: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A484: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A488: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8002A48C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A490: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8002A494: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A498: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8002A49C: andi        $t7, $s1, 0xFFF
    ctx->r15 = ctx->r17 & 0XFFF;
    // 0x8002A4A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A4A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A4A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A4AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002A4B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A4B4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8002A4B8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8002A4BC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8002A4C0: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x8002A4C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A4C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A4CC: sll         $s2, $t8, 12
    ctx->r18 = S32(ctx->r24 << 12);
    // 0x8002A4D0: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8002A4D4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8002A4D8: or          $t8, $s2, $at
    ctx->r24 = ctx->r18 | ctx->r1;
    // 0x8002A4DC: andi        $s3, $t7, 0xFFF
    ctx->r19 = ctx->r15 & 0XFFF;
    // 0x8002A4E0: or          $t9, $t8, $s3
    ctx->r25 = ctx->r24 | ctx->r19;
    // 0x8002A4E4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A4E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A4EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A4F0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8002A4F4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8002A4F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A4FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A500: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A504: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A508: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A50C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8002A510: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A514: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A518: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A51C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8002A520: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A524: or          $t7, $s1, $at
    ctx->r15 = ctx->r17 | ctx->r1;
    // 0x8002A528: or          $t6, $s2, $s3
    ctx->r14 = ctx->r18 | ctx->r19;
    // 0x8002A52C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A530: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A534: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A538: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A53C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A540: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8002A544: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8002A548: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8002A54C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A550: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A554: addu        $t9, $s4, $s7
    ctx->r25 = ADD32(ctx->r20, ctx->r23);
    // 0x8002A558: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8002A55C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8002A560: subu        $t7, $t9, $fp
    ctx->r15 = SUB32(ctx->r25, ctx->r30);
    // 0x8002A564: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8002A568: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8002A56C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8002A570: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002A574: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8002A578: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A57C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8002A580: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8002A584: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8002A588: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8002A58C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002A590: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A594: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8002A598: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A59C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A5A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A5A4: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8002A5A8: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8002A5AC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002A5B0: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8002A5B4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8002A5B8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002A5BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A5C0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8002A5C4: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x8002A5C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A5CC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A5D0: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8002A5D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A5D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A5DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A5E0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8002A5E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A5E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A5EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A5F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A5F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8002A5F8:
    // 0x8002A5F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002A5FC: bnel        $s6, $at, L_8002A31C
    if (ctx->r22 != ctx->r1) {
        // 0x8002A600: lw          $t9, 0x114($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X114);
            goto L_8002A31C;
    }
    goto skip_1;
    // 0x8002A600: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
    skip_1:
    // 0x8002A604: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002A608: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x8002A60C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002A610: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x8002A614: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A618: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x8002A61C: bne         $v0, $at, L_8002A178
    if (ctx->r2 != ctx->r1) {
        // 0x8002A620: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8002A178;
    }
    // 0x8002A620: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002A624: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002A628: addiu       $v0, $v0, -0x2F4
    ctx->r2 = ADD32(ctx->r2, -0X2F4);
    // 0x8002A62C: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x8002A630: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8002A634: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8002A638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A63C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A640: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A644: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002A648: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002A64C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002A650: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A654: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002A658: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002A65C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002A660: jr          $ra
    // 0x8002A664: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8002A664: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_800175B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800175B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800175BC: lw          $v0, 0x68($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X68);
    // 0x800175C0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800175C4: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x800175C8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800175CC: jr          $ra
    // 0x800175D0: nop

    return;
    // 0x800175D0: nop

;}
RECOMP_FUNC void func_80030D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030D70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80030D74: sh          $zero, 0x2852($at)
    MEM_H(0X2852, ctx->r1) = 0;
    // 0x80030D78: jr          $ra
    // 0x80030D7C: nop

    return;
    // 0x80030D7C: nop

;}
RECOMP_FUNC void func_80004260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004264: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004268: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000426C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80004270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004278: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000427C: swc1        $f0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f0.u32l;
    // 0x80004280: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
    // 0x80004284: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80004288: lw          $t6, 0x5C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C0);
    // 0x8000428C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80004290: bnel        $t6, $zero, L_800043B8
    if (ctx->r14 != 0) {
        // 0x80004294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800043B8;
    }
    goto skip_0;
    // 0x80004294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80004298: lw          $a0, -0x458C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X458C);
    // 0x8000429C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800042A0: jal         0x80008948
    // 0x800042A4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80008948(rdram, ctx);
        goto after_0;
    // 0x800042A4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800042A8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800042AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800042B0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800042B4: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x800042B8: lhu         $t7, 0x60($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X60);
    // 0x800042BC: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x800042C0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800042C4: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x800042C8: sh          $t8, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r24;
    // 0x800042CC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800042D0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800042D4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800042D8: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x800042DC: beq         $t1, $zero, L_80004388
    if (ctx->r9 == 0) {
        // 0x800042E0: sw          $t0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r8;
            goto L_80004388;
    }
    // 0x800042E0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800042E4: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800042E8: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x800042EC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800042F0: lw          $t3, -0x458C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X458C);
    // 0x800042F4: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800042F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800042FC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80004300: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80004304: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80004308: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8000430C: lw          $t5, -0x4250($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4250);
    // 0x80004310: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80004314: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80004318: bne         $t6, $at, L_800043AC
    if (ctx->r14 != ctx->r1) {
        // 0x8000431C: nop
    
            goto L_800043AC;
    }
    // 0x8000431C: nop

    // 0x80004320: lw          $t7, 0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C4);
    // 0x80004324: ori         $t9, $t2, 0x480
    ctx->r25 = ctx->r10 | 0X480;
    // 0x80004328: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x8000432C: bne         $t7, $zero, L_800043AC
    if (ctx->r15 != 0) {
        // 0x80004330: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_800043AC;
    }
    // 0x80004330: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004334: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80004338: sw          $t0, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r8;
    // 0x8000433C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80004340: lw          $t2, 0x4EE4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4EE4);
    // 0x80004344: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004348: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8000434C: sh          $t1, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r9;
    // 0x80004350: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80004354: lw          $t3, 0x4EE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4EE8);
    // 0x80004358: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000435C: sh          $t2, -0x45A0($at)
    MEM_H(-0X45A0, ctx->r1) = ctx->r10;
    // 0x80004360: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004364: sh          $t3, -0x459E($at)
    MEM_H(-0X459E, ctx->r1) = ctx->r11;
    // 0x80004368: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8000436C: addiu       $t5, $zero, 0x41
    ctx->r13 = ADD32(0, 0X41);
    // 0x80004370: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x80004374: sh          $t5, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r13;
    // 0x80004378: lhu         $t6, 0x60($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X60);
    // 0x8000437C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80004380: b           L_800043AC
    // 0x80004384: sh          $t7, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r15;
        goto L_800043AC;
    // 0x80004384: sh          $t7, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r15;
L_80004388:
    // 0x80004388: lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X8);
    // 0x8000438C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80004390: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80004394: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x80004398: beq         $t8, $zero, L_800043AC
    if (ctx->r24 == 0) {
        // 0x8000439C: andi        $t9, $v0, 0xFFBF
        ctx->r25 = ctx->r2 & 0XFFBF;
            goto L_800043AC;
    }
    // 0x8000439C: andi        $t9, $v0, 0xFFBF
    ctx->r25 = ctx->r2 & 0XFFBF;
    // 0x800043A0: sh          $t9, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r25;
    // 0x800043A4: jal         0x800268D4
    // 0x800043A8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_1;
    // 0x800043A8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
L_800043AC:
    // 0x800043AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800043B0: sw          $zero, -0x458C($at)
    MEM_W(-0X458C, ctx->r1) = 0;
    // 0x800043B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800043B8:
    // 0x800043B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800043BC: jr          $ra
    // 0x800043C0: nop

    return;
    // 0x800043C0: nop

;}
RECOMP_FUNC void func_80101534_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101534: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80101538: bltz        $t6, L_80101548
    if (SIGNED(ctx->r14) < 0) {
        // 0x8010153C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80101548;
    }
    // 0x8010153C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80101540: jr          $ra
    // 0x80101544: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101544: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101548:
    // 0x80101548: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8010154C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80101550: addiu       $t8, $t8, 0x6FE8
    ctx->r24 = ADD32(ctx->r24, 0X6FE8);
    // 0x80101554: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80101558: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8010155C: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101560: lh          $t1, 0x26($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X26);
    // 0x80101564: lw          $t2, 0x38($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X38);
    // 0x80101568: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8010156C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80101570: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80101574: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101578: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x8010157C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80101580: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80101584: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80101588: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x8010158C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80101590: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80101594: div.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80101598: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8010159C: nop

    // 0x801015A0: bc1fl       L_801015B0
    if (!c1cs) {
        // 0x801015A4: lwc1        $f6, 0x1C($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_801015B0;
    }
    goto skip_0;
    // 0x801015A4: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x801015A8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x801015AC: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
L_801015B0:
    // 0x801015B0: lh          $a2, 0x4($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X4);
    // 0x801015B4: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801015B8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801015BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801015C0: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
    // 0x801015C4: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801015C8: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801015CC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801015D0: beq         $at, $zero, L_801015E0
    if (ctx->r1 == 0) {
        // 0x801015D4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_801015E0;
    }
    // 0x801015D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801015D8: b           L_801015E4
    // 0x801015DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801015E4;
    // 0x801015DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801015E0:
    // 0x801015E0: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_801015E4:
    // 0x801015E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801015E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801015EC: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x801015F0: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x801015F4: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x801015F8: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801015FC: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x80101600: bc1fl       L_80101620
    if (!c1cs) {
        // 0x80101604: lh          $t5, 0x24($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X24);
            goto L_80101620;
    }
    goto skip_1;
    // 0x80101604: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    skip_1:
    // 0x80101608: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8010160C: nop

    // 0x80101610: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101614: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80101618: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x8010161C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
L_80101620:
    // 0x80101620: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80101624: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80101628: bne         $at, $zero, L_80101638
    if (ctx->r1 != 0) {
        // 0x8010162C: nop
    
            goto L_80101638;
    }
    // 0x8010162C: nop

    // 0x80101630: lh          $t7, 0x2A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2A);
    // 0x80101634: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
L_80101638:
    // 0x80101638: beq         $t8, $zero, L_8010165C
    if (ctx->r24 == 0) {
        // 0x8010163C: nop
    
            goto L_8010165C;
    }
    // 0x8010163C: nop

    // 0x80101640: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101644: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80101648: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010164C: bnel        $at, $zero, L_80101680
    if (ctx->r1 != 0) {
        // 0x80101650: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101680;
    }
    goto skip_2;
    // 0x80101650: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_2:
    // 0x80101654: b           L_8010167C
    // 0x80101658: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
        goto L_8010167C;
    // 0x80101658: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_8010165C:
    // 0x8010165C: beql        $t0, $zero, L_80101680
    if (ctx->r8 == 0) {
        // 0x80101660: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101680;
    }
    goto skip_3;
    // 0x80101660: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x80101664: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101668: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x8010166C: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80101670: bnel        $at, $zero, L_80101680
    if (ctx->r1 != 0) {
        // 0x80101674: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101680;
    }
    goto skip_4;
    // 0x80101674: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x80101678: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_8010167C:
    // 0x8010167C: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
L_80101680:
    // 0x80101680: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101688: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010168C: bne         $at, $zero, L_801016AC
    if (ctx->r1 != 0) {
        // 0x80101690: nop
    
            goto L_801016AC;
    }
    // 0x80101690: nop

    // 0x80101694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101698: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x8010169C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801016A0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801016A4: jr          $ra
    // 0x801016A8: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x801016A8: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_801016AC:
    // 0x801016AC: jr          $ra
    // 0x801016B0: nop

    return;
    // 0x801016B0: nop

;}
RECOMP_FUNC void func_80018278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018278: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x8001827C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80018280: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80018284: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80018288: lhu         $t7, -0x328C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X328C);
    // 0x8001828C: lhu         $t9, 0x8C($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8C);
    // 0x80018290: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    // 0x80018294: jr          $ra
    // 0x80018298: nop

    return;
    // 0x80018298: nop

;}
RECOMP_FUNC void func_80103690_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80103694: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80103698: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8010369C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801036A0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x801036A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801036A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801036AC: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x801036B0: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x801036B4: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x801036B8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x801036BC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x801036C0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x801036C4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x801036C8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x801036CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801036D0: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x801036D4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801036D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801036DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801036E0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x801036E4: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x801036E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801036EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801036F0: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x801036F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801036F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801036FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103700: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80103704: addiu       $t8, $t8, 0x48
    ctx->r24 = ADD32(ctx->r24, 0X48);
    // 0x80103708: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010370C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103710: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80103714: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103718: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010371C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103720: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80103724: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80103728: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010372C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103730: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103734: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103738: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010373C: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
    // 0x80103740: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80103744: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103748: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010374C: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80103750: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103754: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103758: lui         $s7, 0xE600
    ctx->r23 = S32(0XE600 << 16);
    // 0x8010375C: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80103760: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103764: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103768: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010376C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80103770: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103774: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80103778: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8010377C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103780: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103784: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103788: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010378C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103790: lui         $s4, 0x8016
    ctx->r20 = S32(0X8016 << 16);
    // 0x80103794: lui         $fp, 0xFD48
    ctx->r30 = S32(0XFD48 << 16);
    // 0x80103798: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010379C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801037A0: lui         $ra, 0xF548
    ctx->r31 = S32(0XF548 << 16);
    // 0x801037A4: ori         $ra, $ra, 0x1A00
    ctx->r31 = ctx->r31 | 0X1A00;
    // 0x801037A8: ori         $fp, $fp, 0x67
    ctx->r30 = ctx->r30 | 0X67;
    // 0x801037AC: addiu       $s4, $s4, -0x710
    ctx->r20 = ADD32(ctx->r20, -0X710);
    // 0x801037B0: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
    // 0x801037B4: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x801037B8: addiu       $s2, $zero, 0x6F
    ctx->r18 = ADD32(0, 0X6F);
    // 0x801037BC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x801037C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801037C4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_801037C8:
    // 0x801037C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801037CC: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x801037D0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801037D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801037D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801037DC: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x801037E0: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801037E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801037E8: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x801037EC: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x801037F0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801037F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801037F8: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x801037FC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80103800: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103804: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80103808: lui         $at, 0x719
    ctx->r1 = S32(0X719 << 16);
    // 0x8010380C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103810: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103814: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103818: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8010381C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103820: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80103824: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80103828: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010382C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103830: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80103834: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80103838: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010383C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103840: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80103844: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80103848: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010384C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103850: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103854: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80103858: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010385C: ori         $t8, $t8, 0x1A00
    ctx->r24 = ctx->r24 | 0X1A00;
    // 0x80103860: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80103864: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103868: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010386C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103870: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103874: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103878: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x8010387C: lui         $at, 0x32
    ctx->r1 = S32(0X32 << 16);
    // 0x80103880: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103884: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103888: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8010388C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103890: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103894: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103898: lui         $at, 0xE441
    ctx->r1 = S32(0XE441 << 16);
    // 0x8010389C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x801038A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801038A4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801038A8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801038AC: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801038B0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801038B4: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x801038B8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801038BC: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x801038C0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801038C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801038C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801038CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801038D0: sll         $t9, $t5, 5
    ctx->r25 = S32(ctx->r13 << 5);
    // 0x801038D4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x801038D8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801038DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801038E0: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x801038E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801038E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801038EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801038F0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801038F4: addiu       $at, $zero, 0x8A
    ctx->r1 = ADD32(0, 0X8A);
    // 0x801038F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801038FC: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x80103900: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103904: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80103908: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8010390C: addiu       $t5, $t5, 0x9
    ctx->r13 = ADD32(ctx->r13, 0X9);
    // 0x80103910: addiu       $s2, $s2, 0x9
    ctx->r18 = ADD32(ctx->r18, 0X9);
    // 0x80103914: addiu       $s1, $s1, 0x9
    ctx->r17 = ADD32(ctx->r17, 0X9);
    // 0x80103918: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010391C: bne         $s0, $at, L_801037C8
    if (ctx->r16 != ctx->r1) {
        // 0x80103920: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_801037C8;
    }
    // 0x80103920: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80103924: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80103928: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8010392C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80103930: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80103934: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80103938: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8010393C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80103940: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80103944: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80103948: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8010394C: jr          $ra
    // 0x80103950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80103950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000B110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B118: jal         0x800208B8
    // 0x8000B11C: nop

    func_800208B8(rdram, ctx);
        goto after_0;
    // 0x8000B11C: nop

    after_0:
    // 0x8000B120: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B124: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8000B128: jal         0x800268D4
    // 0x8000B12C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_1;
    // 0x8000B12C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
    // 0x8000B130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B138: jr          $ra
    // 0x8000B13C: nop

    return;
    // 0x8000B13C: nop

;}
RECOMP_FUNC void func_80036A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036A30: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80036A34: lw          $v0, 0x990($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X990);
    // 0x80036A38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036A3C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x80036A40: beq         $a0, $zero, L_80036A58
    if (ctx->r4 == 0) {
        // 0x80036A44: nop
    
            goto L_80036A58;
    }
    // 0x80036A44: nop

    // 0x80036A48: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80036A4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80036A50: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80036A54: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80036A58:
    // 0x80036A58: jr          $ra
    // 0x80036A5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80036A5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80042DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042DD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80042DD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80042DD8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80042DDC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x80042DE0: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80042DE4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80042DE8: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x80042DEC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80042DF0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80042DF4: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80042DF8: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x80042DFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80042E00: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x80042E04: blez        $t0, L_80042EC0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80042E08: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_80042EC0;
    }
    // 0x80042E08: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_80042E0C:
    // 0x80042E0C: bgez        $a1, L_80042E1C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80042E10: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80042E1C;
    }
    // 0x80042E10: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80042E14: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x80042E18: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80042E1C:
    // 0x80042E1C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80042E20: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80042E24: lw          $a3, 0xC($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC);
    // 0x80042E28: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80042E2C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x80042E30: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x80042E34: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80042E38: bnel        $at, $zero, L_80042E80
    if (ctx->r1 != 0) {
        // 0x80042E3C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80042E80;
    }
    goto skip_0;
    // 0x80042E3C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x80042E40: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x80042E44: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80042E48: bnel        $at, $zero, L_80042E80
    if (ctx->r1 != 0) {
        // 0x80042E4C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80042E80;
    }
    goto skip_1;
    // 0x80042E4C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x80042E50: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80042E54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80042E58: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80042E5C: bnel        $at, $zero, L_80042E80
    if (ctx->r1 != 0) {
        // 0x80042E60: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80042E80;
    }
    goto skip_2;
    // 0x80042E60: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x80042E64: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80042E68: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80042E6C: bnel        $at, $zero, L_80042E80
    if (ctx->r1 != 0) {
        // 0x80042E70: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80042E80;
    }
    goto skip_3;
    // 0x80042E70: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x80042E74: jr          $ra
    // 0x80042E78: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80042E78: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80042E7C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_80042E80:
    // 0x80042E80: bne         $at, $zero, L_80042EA8
    if (ctx->r1 != 0) {
        // 0x80042E84: nop
    
            goto L_80042EA8;
    }
    // 0x80042E84: nop

    // 0x80042E88: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80042E8C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80042E90: beql        $at, $zero, L_80042EB4
    if (ctx->r1 == 0) {
        // 0x80042E94: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80042EB4;
    }
    goto skip_4;
    // 0x80042E94: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x80042E98: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x80042E9C: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80042EA0: bnel        $at, $zero, L_80042EB4
    if (ctx->r1 != 0) {
        // 0x80042EA4: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80042EB4;
    }
    goto skip_5;
    // 0x80042EA4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_80042EA8:
    // 0x80042EA8: b           L_80042EB4
    // 0x80042EAC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_80042EB4;
    // 0x80042EAC: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80042EB0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_80042EB4:
    // 0x80042EB4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80042EB8: beql        $at, $zero, L_80042E0C
    if (ctx->r1 == 0) {
        // 0x80042EBC: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_80042E0C;
    }
    goto skip_6;
    // 0x80042EBC: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_80042EC0:
    // 0x80042EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042EC4: jr          $ra
    // 0x80042EC8: nop

    return;
    // 0x80042EC8: nop

;}
RECOMP_FUNC void func_800118D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800118D4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800118D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800118DC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800118E0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800118E4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800118E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800118EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800118F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800118F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800118F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800118FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011900: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x80011904: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80011908: lw          $s4, 0x62D0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X62D0);
    // 0x8001190C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80011910: addiu       $s0, $s0, 0x5BD0
    ctx->r16 = ADD32(ctx->r16, 0X5BD0);
    // 0x80011914: beq         $s4, $zero, L_800119F4
    if (ctx->r20 == 0) {
        // 0x80011918: lui         $s1, 0x8008
        ctx->r17 = S32(0X8008 << 16);
            goto L_800119F4;
    }
    // 0x80011918: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001191C: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x80011920: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80011924: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80011928: addiu       $t8, $t8, 0x270
    ctx->r24 = ADD32(ctx->r24, 0X270);
    // 0x8001192C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80011930: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80011934: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80011938: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001193C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80011940: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80011944: lui         $t0, 0xBC00
    ctx->r8 = S32(0XBC00 << 16);
    // 0x80011948: ori         $t0, $t0, 0x8
    ctx->r8 = ctx->r8 | 0X8;
    // 0x8001194C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80011950: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80011954: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80011958: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001195C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80011960: lh          $t1, -0x4CE8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CE8);
    // 0x80011964: lh          $a1, -0x4CE6($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4CE6);
    // 0x80011968: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8001196C: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x80011970: subu        $a2, $t1, $a1
    ctx->r6 = SUB32(ctx->r9, ctx->r5);
    // 0x80011974: div         $zero, $t2, $a2
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r6)));
    // 0x80011978: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8001197C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80011980: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80011984: mflo        $t3
    ctx->r11 = lo;
    // 0x80011988: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8001198C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80011990: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80011994: mflo        $t9
    ctx->r25 = lo;
    // 0x80011998: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8001199C: or          $t1, $t5, $t0
    ctx->r9 = ctx->r13 | ctx->r8;
    // 0x800119A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800119A4: bne         $a2, $zero, L_800119B0
    if (ctx->r6 != 0) {
        // 0x800119A8: nop
    
            goto L_800119B0;
    }
    // 0x800119A8: nop

    // 0x800119AC: break       7
    do_break(2147555756);
L_800119B0:
    // 0x800119B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800119B4: bne         $a2, $at, L_800119C8
    if (ctx->r6 != ctx->r1) {
        // 0x800119B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800119C8;
    }
    // 0x800119B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800119BC: bne         $t2, $at, L_800119C8
    if (ctx->r10 != ctx->r1) {
        // 0x800119C0: nop
    
            goto L_800119C8;
    }
    // 0x800119C0: nop

    // 0x800119C4: break       6
    do_break(2147555780);
L_800119C8:
    // 0x800119C8: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x800119CC: bne         $a2, $zero, L_800119D8
    if (ctx->r6 != 0) {
        // 0x800119D0: nop
    
            goto L_800119D8;
    }
    // 0x800119D0: nop

    // 0x800119D4: break       7
    do_break(2147555796);
L_800119D8:
    // 0x800119D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800119DC: bne         $a2, $at, L_800119F0
    if (ctx->r6 != ctx->r1) {
        // 0x800119E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800119F0;
    }
    // 0x800119E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800119E4: bne         $t8, $at, L_800119F0
    if (ctx->r24 != ctx->r1) {
        // 0x800119E8: nop
    
            goto L_800119F0;
    }
    // 0x800119E8: nop

    // 0x800119EC: break       6
    do_break(2147555820);
L_800119F0:
    // 0x800119F0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
L_800119F4:
    // 0x800119F4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800119F8: beq         $s4, $zero, L_80011B04
    if (ctx->r20 == 0) {
        // 0x800119FC: addiu       $s1, $s1, -0x4D04
        ctx->r17 = ADD32(ctx->r17, -0X4D04);
            goto L_80011B04;
    }
    // 0x800119FC: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x80011A00: lui         $s5, 0x100
    ctx->r21 = S32(0X100 << 16);
    // 0x80011A04: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80011A08: lui         $s7, 0x200
    ctx->r23 = S32(0X200 << 16);
    // 0x80011A0C: lui         $s6, 0x102
    ctx->r22 = S32(0X102 << 16);
    // 0x80011A10: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80011A14: addiu       $s2, $s2, -0x4D08
    ctx->r18 = ADD32(ctx->r18, -0X4D08);
    // 0x80011A18: ori         $s6, $s6, 0x40
    ctx->r22 = ctx->r22 | 0X40;
    // 0x80011A1C: addiu       $s7, $s7, 0x0
    ctx->r23 = ADD32(ctx->r23, 0X0);
    // 0x80011A20: ori         $fp, $fp, 0x103F
    ctx->r30 = ctx->r30 | 0X103F;
    // 0x80011A24: addiu       $s5, $s5, 0x230
    ctx->r21 = ADD32(ctx->r21, 0X230);
    // 0x80011A28: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
L_80011A2C:
    // 0x80011A2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011A30: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80011A34: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80011A38: jal         0x80023A08
    // 0x80011A3C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_80023A08(rdram, ctx);
        goto after_0;
    // 0x80011A3C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_0:
    // 0x80011A40: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80011A44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011A48: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80011A4C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80011A50: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x80011A54: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80011A58: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80011A5C: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80011A60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80011A64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80011A68: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80011A6C: jal         0x80023DF4
    // 0x80011A70: nop

    func_80023DF4(rdram, ctx);
        goto after_1;
    // 0x80011A70: nop

    after_1:
    // 0x80011A74: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80011A78: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80011A7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011A80: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80011A84: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x80011A88: jal         0x80035200
    // 0x80011A8C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_2;
    // 0x80011A8C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_2:
    // 0x80011A90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80011A94: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x80011A98: ori         $t4, $t4, 0x204
    ctx->r12 = ctx->r12 | 0X204;
    // 0x80011A9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011AA0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80011AA4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80011AA8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80011AAC: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80011AB0: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x80011AB4: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x80011AB8: addiu       $t5, $t9, 0xC0
    ctx->r13 = ADD32(ctx->r25, 0XC0);
    // 0x80011ABC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80011AC0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80011AC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80011AC8: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80011ACC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80011AD0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80011AD4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80011AD8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80011ADC: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80011AE0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80011AE4: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80011AE8: ori         $t6, $t6, 0x604
    ctx->r14 = ctx->r14 | 0X604;
    // 0x80011AEC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80011AF0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80011AF4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80011AF8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80011AFC: bne         $s4, $zero, L_80011A2C
    if (ctx->r20 != 0) {
        // 0x80011B00: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80011A2C;
    }
    // 0x80011B00: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_80011B04:
    // 0x80011B04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80011B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011B0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011B10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011B14: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011B18: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011B1C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011B20: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011B24: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80011B28: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80011B2C: jr          $ra
    // 0x80011B30: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80011B30: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x80011B34: nop

    // 0x80011B38: nop

    // 0x80011B3C: nop

;}
RECOMP_FUNC void func_80031CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031CB4: lui         $a0, 0xE2
    ctx->r4 = S32(0XE2 << 16);
    // 0x80031CB8: addiu       $a0, $a0, 0x7840
    ctx->r4 = ADD32(ctx->r4, 0X7840);
    // 0x80031CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031CC0: lui         $t6, 0xE8
    ctx->r14 = S32(0XE8 << 16);
    // 0x80031CC4: addiu       $t6, $t6, -0x1800
    ctx->r14 = ADD32(ctx->r14, -0X1800);
    // 0x80031CC8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80031CCC: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80031CD0: jal         0x80024260
    // 0x80031CD4: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80031CD4: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x80031CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031CE0: jr          $ra
    // 0x80031CE4: nop

    return;
    // 0x80031CE4: nop

    // 0x80031CE8: nop

    // 0x80031CEC: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047CE0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80047CE4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80047CE8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80047CEC: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80047CF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80047CF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80047CF8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80047CFC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80047D00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80047D04: bne         $v1, $v0, L_80047D18
    if (ctx->r3 != ctx->r2) {
        // 0x80047D08: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80047D18;
    }
    // 0x80047D08: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80047D0C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80047D10: b           L_80047D20
    // 0x80047D14: addiu       $s3, $s3, 0xED4
    ctx->r19 = ADD32(ctx->r19, 0XED4);
        goto L_80047D20;
    // 0x80047D14: addiu       $s3, $s3, 0xED4
    ctx->r19 = ADD32(ctx->r19, 0XED4);
L_80047D18:
    // 0x80047D18: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80047D1C: addiu       $s3, $s3, 0xEC0
    ctx->r19 = ADD32(ctx->r19, 0XEC0);
L_80047D20:
    // 0x80047D20: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80047D24: bne         $v0, $at, L_80047D34
    if (ctx->r2 != ctx->r1) {
        // 0x80047D28: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80047D34;
    }
    // 0x80047D28: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80047D2C: b           L_80047D54
    // 0x80047D30: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80047D54;
    // 0x80047D30: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80047D34:
    // 0x80047D34: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80047D38: beq         $v0, $at, L_80047D50
    if (ctx->r2 == ctx->r1) {
        // 0x80047D3C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80047D50;
    }
    // 0x80047D3C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80047D40: beq         $v1, $v0, L_80047D50
    if (ctx->r3 == ctx->r2) {
        // 0x80047D44: nop
    
            goto L_80047D50;
    }
    // 0x80047D44: nop

    // 0x80047D48: b           L_80047D50
    // 0x80047D4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80047D50;
    // 0x80047D4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80047D50:
    // 0x80047D50: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80047D54:
    // 0x80047D54: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80047D58: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80047D5C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80047D60: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80047D64: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80047D68: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80047D6C: beq         $v0, $at, L_80047D80
    if (ctx->r2 == ctx->r1) {
        // 0x80047D70: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80047D80;
    }
    // 0x80047D70: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80047D74: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80047D78: bnel        $v0, $at, L_80047DBC
    if (ctx->r2 != ctx->r1) {
        // 0x80047D7C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80047DBC;
    }
    goto skip_0;
    // 0x80047D7C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80047D80:
    // 0x80047D80: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80047D84: bgtzl       $t4, L_80047DBC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80047D88: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80047DBC;
    }
    goto skip_1;
    // 0x80047D88: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80047D8C: bltz        $t4, L_80047D9C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80047D90: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80047D9C;
    }
    // 0x80047D90: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80047D94: b           L_80047DBC
    // 0x80047D98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_80047DBC;
    // 0x80047D98: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80047D9C:
    // 0x80047D9C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80047DA0: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80047DA4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80047DA8: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x80047DAC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80047DB0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80047DB4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80047DB8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80047DBC:
    // 0x80047DBC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80047DC0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80047DC4: bne         $t2, $zero, L_80047DE0
    if (ctx->r10 != 0) {
        // 0x80047DC8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80047DE0;
    }
    // 0x80047DC8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80047DCC: bnel        $t3, $zero, L_80047DE4
    if (ctx->r11 != 0) {
        // 0x80047DD0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80047DE4;
    }
    goto skip_2;
    // 0x80047DD0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80047DD4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80047DD8: beql        $t4, $zero, L_80047E1C
    if (ctx->r12 == 0) {
        // 0x80047DDC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_80047E1C;
    }
    goto skip_3;
    // 0x80047DDC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80047DE0:
    // 0x80047DE0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80047DE4:
    // 0x80047DE4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80047DE8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80047DEC: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80047DF0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80047DF4: jal         0x80039AFC
    // 0x80047DF8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80047DF8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x80047DFC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80047E00: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80047E04: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80047E08: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80047E0C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80047E10: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80047E14: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80047E18: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_80047E1C:
    // 0x80047E1C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80047E20: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80047E24: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80047E28: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80047E2C: jal         0x80039B38
    // 0x80047E30: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80047E30: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80047E34: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80047E38: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x80047E3C: bltz        $v0, L_80047EEC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80047E40: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80047EEC;
    }
    // 0x80047E40: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80047E44: bgtz        $v0, L_80047E54
    if (SIGNED(ctx->r2) > 0) {
        // 0x80047E48: nop
    
            goto L_80047E54;
    }
    // 0x80047E48: nop

    // 0x80047E4C: beql        $v1, $zero, L_80047EF0
    if (ctx->r3 == 0) {
        // 0x80047E50: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80047EF0;
    }
    goto skip_4;
    // 0x80047E50: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_80047E54:
    // 0x80047E54: blez        $s0, L_80047EEC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80047E58: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_80047EEC;
    }
    // 0x80047E58: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80047E5C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80047E60: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80047E64: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80047E68: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80047E6C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80047E70: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80047E74: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80047E78:
    // 0x80047E78: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80047E7C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80047E80: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80047E84: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80047E88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80047E8C: jal         0x80049D60
    // 0x80047E90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80047E90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80047E94: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047E98: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80047E9C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80047EA0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80047EA4: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80047EA8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80047EAC: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80047EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047EB4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80047EB8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80047EBC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80047EC0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80047EC4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80047EC8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80047ECC: bltz        $t8, L_80047EEC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80047ED0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_80047EEC;
    }
    // 0x80047ED0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80047ED4: bgtz        $t8, L_80047EE4
    if (SIGNED(ctx->r24) > 0) {
        // 0x80047ED8: nop
    
            goto L_80047EE4;
    }
    // 0x80047ED8: nop

    // 0x80047EDC: beql        $t9, $zero, L_80047EF0
    if (ctx->r25 == 0) {
        // 0x80047EE0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80047EF0;
    }
    goto skip_5;
    // 0x80047EE0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80047EE4:
    // 0x80047EE4: bgtzl       $s0, L_80047E78
    if (SIGNED(ctx->r16) > 0) {
        // 0x80047EE8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80047E78;
    }
    goto skip_6;
    // 0x80047EE8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_80047EEC:
    // 0x80047EEC: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80047EF0:
    // 0x80047EF0: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80047EF4: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80047EF8: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80047EFC: jal         0x8003FB20
    // 0x80047F00: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80047F00: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80047F04: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80047F08: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x80047F0C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80047F10: beq         $at, $zero, L_80047F1C
    if (ctx->r1 == 0) {
        // 0x80047F14: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_80047F1C;
    }
    // 0x80047F14: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80047F18: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_80047F1C:
    // 0x80047F1C: bgezl       $a0, L_80047F60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80047F20: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80047F60;
    }
    goto skip_7;
    // 0x80047F20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80047F24: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80047F28: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80047F2C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80047F30: bnel        $t7, $at, L_80047F60
    if (ctx->r15 != ctx->r1) {
        // 0x80047F34: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80047F60;
    }
    goto skip_8;
    // 0x80047F34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80047F38: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80047F3C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80047F40: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80047F44: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80047F48: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x80047F4C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x80047F50: blez        $s0, L_80047F5C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80047F54: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_80047F5C;
    }
    // 0x80047F54: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x80047F58: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_80047F5C:
    // 0x80047F5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80047F60:
    // 0x80047F60: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80047F64: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80047F68: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80047F6C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80047F70: jr          $ra
    // 0x80047F74: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80047F74: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800427A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800427A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800427A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800427AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800427B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800427B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800427B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800427BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800427C0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800427C4: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
L_800427C8:
    // 0x800427C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800427CC: beql        $s1, $zero, L_800427C8
    if (ctx->r17 == 0) {
        // 0x800427D0: lw          $s1, 0xC($v0)
        ctx->r17 = MEM_W(ctx->r2, 0XC);
            goto L_800427C8;
    }
    goto skip_0;
    // 0x800427D0: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x800427D4: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x800427D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800427DC: blez        $t6, L_80042810
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800427E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80042810;
    }
    // 0x800427E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800427E4:
    // 0x800427E4: jal         0x80042724
    // 0x800427E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042724(rdram, ctx);
        goto after_0;
    // 0x800427E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800427EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800427F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800427F4: jal         0x800426D0
    // 0x800427F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800426D0(rdram, ctx);
        goto after_1;
    // 0x800427F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800427FC: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x80042800: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80042804: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80042808: bnel        $at, $zero, L_800427E4
    if (ctx->r1 != 0) {
        // 0x8004280C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800427E4;
    }
    goto skip_1;
    // 0x8004280C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80042810:
    // 0x80042810: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80042814: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80042818: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8004281C: beql        $t9, $zero, L_80042844
    if (ctx->r25 == 0) {
        // 0x80042820: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042844;
    }
    goto skip_2;
    // 0x80042820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80042824: jal         0x80042724
    // 0x80042828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042724(rdram, ctx);
        goto after_2;
    // 0x80042828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004282C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80042830: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80042834: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80042838: jal         0x800426D0
    // 0x8004283C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    func_800426D0(rdram, ctx);
        goto after_3;
    // 0x8004283C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x80042840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80042844:
    // 0x80042844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042848: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004284C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80042850: jr          $ra
    // 0x80042854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80042854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800238E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238E4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800238E8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800238EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800238F0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800238F4: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800238F8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800238FC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80023900: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80023904: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80023908: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002390C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80023910: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80023914: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80023918: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8002391C: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80023920: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80023924: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80023928: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002392C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80023930: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80023934: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80023938: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8002393C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80023940: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x80023944: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80023948: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8002394C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80023950: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80023954: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80023958: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002395C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80023960: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80023964: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80023968: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x8002396C: jr          $ra
    // 0x80023970: nop

    return;
    // 0x80023970: nop

;}
RECOMP_FUNC void func_80012220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012220: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80012224: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80012228: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8001222C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80012230: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80012234: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80012238: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001223C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80012240: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012244: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80012248: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001224C: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
    // 0x80012250: addiu       $v0, $v0, -0x3AF0
    ctx->r2 = ADD32(ctx->r2, -0X3AF0);
    // 0x80012254: lw          $v1, 0x4EE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4EE4);
    // 0x80012258: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8001225C:
    // 0x8001225C: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80012260: bnel        $v1, $t6, L_8001227C
    if (ctx->r3 != ctx->r14) {
        // 0x80012264: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8001227C;
    }
    goto skip_0;
    // 0x80012264: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80012268: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8001226C: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x80012270: beql        $t7, $t8, L_8001228C
    if (ctx->r15 == ctx->r24) {
        // 0x80012274: sltiu       $at, $s2, 0x2B
        ctx->r1 = ctx->r18 < 0X2B ? 1 : 0;
            goto L_8001228C;
    }
    goto skip_1;
    // 0x80012274: sltiu       $at, $s2, 0x2B
    ctx->r1 = ctx->r18 < 0X2B ? 1 : 0;
    skip_1:
    // 0x80012278: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8001227C:
    // 0x8001227C: sltiu       $at, $s2, 0x2B
    ctx->r1 = ctx->r18 < 0X2B ? 1 : 0;
    // 0x80012280: bne         $at, $zero, L_8001225C
    if (ctx->r1 != 0) {
        // 0x80012284: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8001225C;
    }
    // 0x80012284: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80012288: sltiu       $at, $s2, 0x2B
    ctx->r1 = ctx->r18 < 0X2B ? 1 : 0;
L_8001228C:
    // 0x8001228C: beq         $at, $zero, L_8001232C
    if (ctx->r1 == 0) {
        // 0x80012290: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_8001232C;
    }
    // 0x80012290: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012294: lhu         $s2, 0x4($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X4);
    // 0x80012298: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001229C: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x800122A0: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800122A4: lw          $s1, 0x8($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X8);
    // 0x800122A8: addiu       $s0, $s0, 0x6A08
    ctx->r16 = ADD32(ctx->r16, 0X6A08);
    // 0x800122AC: beq         $s2, $zero, L_80012334
    if (ctx->r18 == 0) {
        // 0x800122B0: sw          $s2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r18;
            goto L_80012334;
    }
    // 0x800122B0: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x800122B4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x800122B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800122BC: addiu       $s3, $s3, 0x6AC8
    ctx->r19 = ADD32(ctx->r19, 0X6AC8);
    // 0x800122C0: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800122C4:
    // 0x800122C4: sh          $s4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r20;
    // 0x800122C8: jal         0x80012700
    // 0x800122CC: lbu         $a0, 0x8($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X8);
    func_80012700(rdram, ctx);
        goto after_0;
    // 0x800122CC: lbu         $a0, 0x8($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X8);
    after_0:
    // 0x800122D0: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // 0x800122D4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800122D8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800122DC: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x800122E0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800122E4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800122E8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800122EC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800122F0: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800122F4: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800122F8: jal         0x8000EE60
    // 0x800122FC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8000EE60(rdram, ctx);
        goto after_1;
    // 0x800122FC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x80012300: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80012304: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x80012308: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8001230C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80012310: lbu         $t0, 0x8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8);
    // 0x80012314: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80012318: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8001231C: bne         $s2, $zero, L_800122C4
    if (ctx->r18 != 0) {
        // 0x80012320: sb          $t0, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = ctx->r8;
            goto L_800122C4;
    }
    // 0x80012320: sb          $t0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r8;
    // 0x80012324: b           L_80012338
    // 0x80012328: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80012338;
    // 0x80012328: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8001232C:
    // 0x8001232C: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x80012330: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80012334:
    // 0x80012334: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80012338:
    // 0x80012338: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001233C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80012340: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80012344: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80012348: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8001234C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80012350: jr          $ra
    // 0x80012354: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80012354: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80017094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001709C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800170A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800170A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800170A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800170AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800170B0: lw          $v0, 0x68($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X68);
    // 0x800170B4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800170B8: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800170BC: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800170C0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800170C4: jal         0x8001FCF8
    // 0x800170C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x800170C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800170CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800170D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800170D4: jr          $ra
    // 0x800170D8: nop

    return;
    // 0x800170D8: nop

;}
RECOMP_FUNC void func_8001ED5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED5C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001ED60: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8001ED64: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001ED68: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001ED6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001ED70: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001ED74: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8001ED78: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8001ED7C: addiu       $t7, $t7, -0x2D00
    ctx->r15 = ADD32(ctx->r15, -0X2D00);
    // 0x8001ED80: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8001ED84: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8001ED88: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8001ED8C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8001ED90: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8001ED94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ED98: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8001ED9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EDA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001EDA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001EDA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EDAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001EDB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EDB4: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001EDB8: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x8001EDBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001EDC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001EDC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EDC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001EDCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EDD0: lui         $t7, 0x803A
    ctx->r15 = S32(0X803A << 16);
    // 0x8001EDD4: addiu       $t7, $t7, -0x2670
    ctx->r15 = ADD32(ctx->r15, -0X2670);
    // 0x8001EDD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001EDDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001EDE0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8001EDE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001EDE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001EDEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EDF0: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8001EDF4: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8001EDF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001EDFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001EE00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EE04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001EE08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EE0C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8001EE10: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8001EE14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001EE18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001EE1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001EE20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001EE24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EE28: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8001EE2C: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8001EE30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001EE34: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001EE38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EE3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001EE40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EE44: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8001EE48: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8001EE4C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001EE50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001EE54: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001EE58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001EE5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001EE60: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8001EE64: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8001EE68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001EE6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001EE70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EE74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001EE78: sw          $t9, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r25;
    // 0x8001EE7C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EE80: addiu       $t8, $zero, 0x3E
    ctx->r24 = ADD32(0, 0X3E);
    // 0x8001EE84: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8001EE88: sw          $t8, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r24;
    // 0x8001EE8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001EE90: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8001EE94: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001EE98: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    // 0x8001EE9C: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001EEA0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8001EEA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001EEA8: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8001EEAC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001EEB0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001EEB4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8001EEB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EEC0: jal         0x800210FC
    // 0x8001EEC4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x8001EEC4: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    after_0:
    // 0x8001EEC8: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8001EECC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EED0: sw          $t7, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r15;
    // 0x8001EED4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EED8: addiu       $t9, $zero, 0x94
    ctx->r25 = ADD32(0, 0X94);
    // 0x8001EEDC: lui         $s0, 0x803A
    ctx->r16 = S32(0X803A << 16);
    // 0x8001EEE0: sw          $t9, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r25;
    // 0x8001EEE4: addiu       $s0, $s0, 0x6F60
    ctx->r16 = ADD32(ctx->r16, 0X6F60);
    // 0x8001EEE8: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EEEC: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EEF0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8001EEF4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8001EEF8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001EEFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EF00: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EF04: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EF0C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x8001EF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EF14: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    // 0x8001EF18: jal         0x800210FC
    // 0x8001EF1C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x8001EF1C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8001EF20: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8001EF24: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8001EF28: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EF2C: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EF30: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EF34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EF38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001EF3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EF44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EF48: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8001EF4C: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    // 0x8001EF50: jal         0x800210FC
    // 0x8001EF54: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x8001EF54: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x8001EF58: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8001EF5C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8001EF60: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EF64: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EF68: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EF6C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EF70: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001EF74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EF7C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8001EF80: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8001EF84: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    // 0x8001EF88: jal         0x800210FC
    // 0x8001EF8C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_3;
    // 0x8001EF8C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
    // 0x8001EF90: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8001EF94: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8001EF98: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EF9C: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EFA0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EFA4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EFA8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001EFAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EFB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EFB4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x8001EFB8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8001EFBC: addiu       $a3, $zero, 0x6E
    ctx->r7 = ADD32(0, 0X6E);
    // 0x8001EFC0: jal         0x800210FC
    // 0x8001EFC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_4;
    // 0x8001EFC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
    // 0x8001EFC8: addiu       $t8, $zero, 0x24
    ctx->r24 = ADD32(0, 0X24);
    // 0x8001EFCC: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x8001EFD0: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EFD4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EFD8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EFDC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EFE0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001EFE4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EFEC: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8001EFF0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8001EFF4: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    // 0x8001EFF8: jal         0x800210FC
    // 0x8001EFFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_5;
    // 0x8001EFFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_5:
    // 0x8001F000: lhu         $t8, 0x11C($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F004: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x8001F008: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F00C: beq         $t8, $zero, L_8001F0B0
    if (ctx->r24 == 0) {
        // 0x8001F010: addiu       $t7, $zero, 0x3E
        ctx->r15 = ADD32(0, 0X3E);
            goto L_8001F0B0;
    }
    // 0x8001F010: addiu       $t7, $zero, 0x3E
    ctx->r15 = ADD32(0, 0X3E);
    // 0x8001F014: sw          $t6, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r14;
    // 0x8001F018: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F01C: sw          $t7, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r15;
    // 0x8001F020: lhu         $a0, 0x11C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F024: jal         0x80014890
    // 0x8001F028: addiu       $a1, $s1, 0x119
    ctx->r5 = ADD32(ctx->r17, 0X119);
    func_80014890(rdram, ctx);
        goto after_6;
    // 0x8001F028: addiu       $a1, $s1, 0x119
    ctx->r5 = ADD32(ctx->r17, 0X119);
    after_6:
    // 0x8001F02C: lw          $t9, 0x10($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X10);
    // 0x8001F030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F034: lhu         $a1, 0x8($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F038: jal         0x800149D0
    // 0x8001F03C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800149D0(rdram, ctx);
        goto after_7;
    // 0x8001F03C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_7:
    // 0x8001F040: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8001F044: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001F048: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001F04C: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8001F050: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x8001F054: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001F058: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8001F05C: lw          $t9, 0x690($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X690);
    // 0x8001F060: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001F064: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001F068: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8001F06C: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8001F070: bne         $t9, $zero, L_8001F0B0
    if (ctx->r25 != 0) {
        // 0x8001F074: lw          $a3, 0x0($t6)
        ctx->r7 = MEM_W(ctx->r14, 0X0);
            goto L_8001F0B0;
    }
    // 0x8001F074: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x8001F078: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F07C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001F080: jal         0x80020D18
    // 0x8001F084: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    func_80020D18(rdram, ctx);
        goto after_8;
    // 0x8001F084: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    after_8:
    // 0x8001F088: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x8001F08C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001F090: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8001F094: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x8001F098: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8001F09C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F0A0: lbu         $a2, 0x60($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X60);
    // 0x8001F0A4: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x8001F0A8: jal         0x80020B4C
    // 0x8001F0AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80020B4C(rdram, ctx);
        goto after_9;
    // 0x8001F0AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
L_8001F0B0:
    // 0x8001F0B0: lhu         $t7, 0x11C($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F0B4: addiu       $t9, $zero, 0x24
    ctx->r25 = ADD32(0, 0X24);
    // 0x8001F0B8: addiu       $t6, $zero, 0x94
    ctx->r14 = ADD32(0, 0X94);
    // 0x8001F0BC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8001F0C0: beq         $at, $zero, L_8001F3C8
    if (ctx->r1 == 0) {
        // 0x8001F0C4: addiu       $a1, $sp, 0x68
        ctx->r5 = ADD32(ctx->r29, 0X68);
            goto L_8001F3C8;
    }
    // 0x8001F0C4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8001F0C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F0CC: sw          $t9, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r25;
    // 0x8001F0D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F0D4: sw          $t6, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r14;
    // 0x8001F0D8: lhu         $t8, 0x11C($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F0DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F0E0: beq         $t8, $zero, L_8001F110
    if (ctx->r24 == 0) {
        // 0x8001F0E4: addiu       $s0, $sp, 0x68
        ctx->r16 = ADD32(ctx->r29, 0X68);
            goto L_8001F110;
    }
    // 0x8001F0E4: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8001F0E8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8001F0EC: lbu         $t7, 0x119($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X119);
L_8001F0F0:
    // 0x8001F0F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001F0F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F0F8: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x8001F0FC: lhu         $t9, 0x11C($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001F104: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8001F108: bnel        $at, $zero, L_8001F0F0
    if (ctx->r1 != 0) {
        // 0x8001F10C: lbu         $t7, 0x119($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X119);
            goto L_8001F0F0;
    }
    goto skip_0;
    // 0x8001F10C: lbu         $t7, 0x119($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X119);
    skip_0:
L_8001F110:
    // 0x8001F110: addu        $s0, $a1, $v0
    ctx->r16 = ADD32(ctx->r5, ctx->r2);
    // 0x8001F114: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8001F118: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001F11C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001F120: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001F124: jal         0x80014890
    // 0x8001F128: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    func_80014890(rdram, ctx);
        goto after_10;
    // 0x8001F128: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_10:
    // 0x8001F12C: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x8001F130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F134: lhu         $a1, 0x8($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X8);
    // 0x8001F138: jal         0x800149D0
    // 0x8001F13C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800149D0(rdram, ctx);
        goto after_11;
    // 0x8001F13C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_11:
    // 0x8001F140: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8001F144: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001F148: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001F14C: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8001F150: andi        $t7, $a0, 0xF
    ctx->r15 = ctx->r4 & 0XF;
    // 0x8001F154: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001F158: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8001F15C: lw          $t8, 0x690($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X690);
    // 0x8001F160: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001F164: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8001F168: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001F16C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8001F170: beq         $t8, $zero, L_8001F18C
    if (ctx->r24 == 0) {
        // 0x8001F174: lw          $a3, 0x0($t9)
        ctx->r7 = MEM_W(ctx->r25, 0X0);
            goto L_8001F18C;
    }
    // 0x8001F174: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8001F178: lhu         $t7, 0x11C($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F17C: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8001F180: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001F184: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x8001F188: lw          $a3, -0x2D40($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2D40);
L_8001F18C:
    // 0x8001F18C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F190: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001F194: jal         0x80020D18
    // 0x8001F198: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    func_80020D18(rdram, ctx);
        goto after_12;
    // 0x8001F198: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    after_12:
    // 0x8001F19C: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x8001F1A0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001F1A4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001F1A8: addiu       $t8, $zero, 0x7C
    ctx->r24 = ADD32(0, 0X7C);
    // 0x8001F1AC: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8001F1B0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F1B4: lbu         $a2, 0x60($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X60);
    // 0x8001F1B8: subu        $a0, $t8, $t6
    ctx->r4 = SUB32(ctx->r24, ctx->r14);
    // 0x8001F1BC: jal         0x80020B4C
    // 0x8001F1C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80020B4C(rdram, ctx);
        goto after_13;
    // 0x8001F1C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8001F1C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001F1C8: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8001F1CC: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    // 0x8001F1D0: jal         0x80014890
    // 0x8001F1D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80014890(rdram, ctx);
        goto after_14;
    // 0x8001F1D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_14:
    // 0x8001F1D8: lw          $t9, 0x10($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X10);
    // 0x8001F1DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F1E0: lhu         $a1, 0x8($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F1E4: jal         0x800149D0
    // 0x8001F1E8: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800149D0(rdram, ctx);
        goto after_15;
    // 0x8001F1E8: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_15:
    // 0x8001F1EC: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8001F1F0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001F1F4: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001F1F8: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8001F1FC: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x8001F200: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001F204: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8001F208: lw          $t9, 0x690($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X690);
    // 0x8001F20C: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001F210: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001F214: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8001F218: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8001F21C: beq         $t9, $zero, L_8001F238
    if (ctx->r25 == 0) {
        // 0x8001F220: lw          $a3, 0x0($t6)
        ctx->r7 = MEM_W(ctx->r14, 0X0);
            goto L_8001F238;
    }
    // 0x8001F220: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x8001F224: lhu         $t8, 0x11C($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F228: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8001F22C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8001F230: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x8001F234: lw          $a3, -0x2D40($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2D40);
L_8001F238:
    // 0x8001F238: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F23C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001F240: jal         0x80020D18
    // 0x8001F244: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    func_80020D18(rdram, ctx);
        goto after_16;
    // 0x8001F244: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    after_16:
    // 0x8001F248: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x8001F24C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8001F250: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8001F254: addiu       $t9, $zero, 0x37
    ctx->r25 = ADD32(0, 0X37);
    // 0x8001F258: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8001F25C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F260: lbu         $a2, 0x60($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X60);
    // 0x8001F264: subu        $a0, $t9, $t7
    ctx->r4 = SUB32(ctx->r25, ctx->r15);
    // 0x8001F268: jal         0x80020B4C
    // 0x8001F26C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80020B4C(rdram, ctx);
        goto after_17;
    // 0x8001F26C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_17:
    // 0x8001F270: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001F274: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8001F278: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    // 0x8001F27C: jal         0x80014890
    // 0x8001F280: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80014890(rdram, ctx);
        goto after_18;
    // 0x8001F280: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_18:
    // 0x8001F284: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
    // 0x8001F288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F28C: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
    // 0x8001F290: jal         0x800149D0
    // 0x8001F294: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800149D0(rdram, ctx);
        goto after_19;
    // 0x8001F294: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_19:
    // 0x8001F298: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8001F29C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001F2A0: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001F2A4: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8001F2A8: andi        $t9, $a0, 0xF
    ctx->r25 = ctx->r4 & 0XF;
    // 0x8001F2AC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8001F2B0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8001F2B4: lw          $t6, 0x690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X690);
    // 0x8001F2B8: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8001F2BC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001F2C0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8001F2C4: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8001F2C8: beq         $t6, $zero, L_8001F2E4
    if (ctx->r14 == 0) {
        // 0x8001F2CC: lw          $a3, 0x0($t7)
        ctx->r7 = MEM_W(ctx->r15, 0X0);
            goto L_8001F2E4;
    }
    // 0x8001F2CC: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8001F2D0: lhu         $t9, 0x11C($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F2D4: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8001F2D8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8001F2DC: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8001F2E0: lw          $a3, -0x2D40($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2D40);
L_8001F2E4:
    // 0x8001F2E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F2E8: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001F2EC: jal         0x80020D18
    // 0x8001F2F0: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    func_80020D18(rdram, ctx);
        goto after_20;
    // 0x8001F2F0: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    after_20:
    // 0x8001F2F4: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x8001F2F8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001F2FC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8001F300: addiu       $t6, $zero, 0x7C
    ctx->r14 = ADD32(0, 0X7C);
    // 0x8001F304: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8001F308: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F30C: lbu         $a2, 0x60($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X60);
    // 0x8001F310: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x8001F314: jal         0x80020B4C
    // 0x8001F318: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_80020B4C(rdram, ctx);
        goto after_21;
    // 0x8001F318: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_21:
    // 0x8001F31C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8001F320: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8001F324: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    // 0x8001F328: jal         0x80014890
    // 0x8001F32C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80014890(rdram, ctx);
        goto after_22;
    // 0x8001F32C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_22:
    // 0x8001F330: lw          $t7, 0x10($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X10);
    // 0x8001F334: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001F338: lhu         $a1, 0x8($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X8);
    // 0x8001F33C: jal         0x800149D0
    // 0x8001F340: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800149D0(rdram, ctx);
        goto after_23;
    // 0x8001F340: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_23:
    // 0x8001F344: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8001F348: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001F34C: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001F350: srl         $a0, $v1, 8
    ctx->r4 = S32(U32(ctx->r3) >> 8);
    // 0x8001F354: andi        $t6, $a0, 0xF
    ctx->r14 = ctx->r4 & 0XF;
    // 0x8001F358: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8001F35C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x8001F360: lw          $t7, 0x690($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X690);
    // 0x8001F364: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x8001F368: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8001F36C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8001F370: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8001F374: beq         $t7, $zero, L_8001F390
    if (ctx->r15 == 0) {
        // 0x8001F378: lw          $a3, 0x0($t8)
        ctx->r7 = MEM_W(ctx->r24, 0X0);
            goto L_8001F390;
    }
    // 0x8001F378: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x8001F37C: lhu         $t6, 0x11C($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X11C);
    // 0x8001F380: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x8001F384: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001F388: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x8001F38C: lw          $a3, -0x2D40($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2D40);
L_8001F390:
    // 0x8001F390: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001F394: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001F398: jal         0x80020D18
    // 0x8001F39C: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    func_80020D18(rdram, ctx);
        goto after_24;
    // 0x8001F39C: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    after_24:
    // 0x8001F3A0: lbu         $t0, 0x6B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X6B);
    // 0x8001F3A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001F3A8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8001F3AC: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8001F3B0: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8001F3B4: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F3B8: lbu         $a2, 0x60($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X60);
    // 0x8001F3BC: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x8001F3C0: jal         0x80020B4C
    // 0x8001F3C4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80020B4C(rdram, ctx);
        goto after_25;
    // 0x8001F3C4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_25:
L_8001F3C8:
    // 0x8001F3C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001F3CC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F3D0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8001F3D4: jr          $ra
    // 0x8001F3D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001F3D8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80007F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F18: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80007F1C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80007F20: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80007F24: addiu       $fp, $fp, -0x4318
    ctx->r30 = ADD32(ctx->r30, -0X4318);
    // 0x80007F28: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80007F2C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80007F30: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80007F34: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80007F38: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80007F3C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80007F40: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80007F44: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80007F48: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80007F4C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80007F50: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80007F54: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80007F58: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80007F5C: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x80007F60: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80007F64: lw          $s3, -0x431C($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X431C);
    // 0x80007F68: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80007F6C: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80007F70: addiu       $s1, $s1, -0x42D0
    ctx->r17 = ADD32(ctx->r17, -0X42D0);
    // 0x80007F74: beq         $s3, $zero, L_800080AC
    if (ctx->r19 == 0) {
        // 0x80007F78: addiu       $s4, $s4, -0x4310
        ctx->r20 = ADD32(ctx->r20, -0X4310);
            goto L_800080AC;
    }
    // 0x80007F78: addiu       $s4, $s4, -0x4310
    ctx->r20 = ADD32(ctx->r20, -0X4310);
    // 0x80007F7C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80007F80: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80007F84: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007F88: lwc1        $f22, 0x1124($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X1124);
    // 0x80007F8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007F90: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80007F94: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80007F98: addiu       $s5, $s5, -0x4548
    ctx->r21 = ADD32(ctx->r21, -0X4548);
    // 0x80007F9C: addiu       $s6, $s6, -0x4D04
    ctx->r22 = ADD32(ctx->r22, -0X4D04);
    // 0x80007FA0: lwc1        $f20, 0x1128($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1128);
    // 0x80007FA4: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
L_80007FA8:
    // 0x80007FA8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80007FAC: lwc1        $f6, 0x14($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X14);
    // 0x80007FB0: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80007FB4: lwc1        $f10, 0x1C($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x80007FB8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007FBC: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80007FC0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80007FC4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80007FC8: nop

    // 0x80007FCC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80007FD0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80007FD4: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80007FD8: nop

    // 0x80007FDC: bc1f        L_800080A0
    if (!c1cs) {
        // 0x80007FE0: nop
    
            goto L_800080A0;
    }
    // 0x80007FE0: nop

    // 0x80007FE4: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    // 0x80007FE8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80007FEC: bc1f        L_80007FFC
    if (!c1cs) {
        // 0x80007FF0: nop
    
            goto L_80007FFC;
    }
    // 0x80007FF0: nop

    // 0x80007FF4: b           L_80007FFC
    // 0x80007FF8: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
        goto L_80007FFC;
    // 0x80007FF8: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
L_80007FFC:
    // 0x80007FFC: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x80008000: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80008004: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x80008008: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000800C: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x80008010: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80008014: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008018: lh          $t9, 0x52($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X52);
    // 0x8000801C: lw          $t8, 0x80($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X80);
    // 0x80008020: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008024: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008028: lw          $s2, 0x10($t8)
    ctx->r18 = MEM_W(ctx->r24, 0X10);
    // 0x8000802C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80008030: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80008034: mflo        $t1
    ctx->r9 = lo;
    // 0x80008038: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    // 0x8000803C: jal         0x8001DB38
    // 0x80008040: nop

    func_8001DB38(rdram, ctx);
        goto after_0;
    // 0x80008040: nop

    after_0:
    // 0x80008044: lh          $t2, 0x52($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X52);
    // 0x80008048: lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X58);
    // 0x8000804C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80008050: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008054: mflo        $t3
    ctx->r11 = lo;
    // 0x80008058: addu        $a2, $t3, $s2
    ctx->r6 = ADD32(ctx->r11, ctx->r18);
    // 0x8000805C: jal         0x8001E0AC
    // 0x80008060: nop

    func_8001E0AC(rdram, ctx);
        goto after_1;
    // 0x80008060: nop

    after_1:
    // 0x80008064: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80008068: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000806C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008070: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80008074: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x80008078: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000807C: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80008080: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80008084: jal         0x80011860
    // 0x80008088: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80011860(rdram, ctx);
        goto after_2;
    // 0x80008088: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8000808C: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x80008090: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80008094: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80008098: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000809C: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
L_800080A0:
    // 0x800080A0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800080A4: bne         $s3, $zero, L_80007FA8
    if (ctx->r19 != 0) {
        // 0x800080A8: addiu       $s1, $s1, 0x84
        ctx->r17 = ADD32(ctx->r17, 0X84);
            goto L_80007FA8;
    }
    // 0x800080A8: addiu       $s1, $s1, 0x84
    ctx->r17 = ADD32(ctx->r17, 0X84);
L_800080AC:
    // 0x800080AC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800080B0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800080B4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800080B8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800080BC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800080C0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800080C4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800080C8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800080CC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800080D0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800080D4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800080D8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800080DC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800080E0: jr          $ra
    // 0x800080E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800080E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8001F900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F900: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F904: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001F908: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001F90C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001F910: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001F914: lui         $at, 0x4026
    ctx->r1 = S32(0X4026 << 16);
    // 0x8001F918: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001F91C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001F920: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001F924: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8001F928: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8001F92C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F930: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001F934: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8001F938: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F93C: jal         0x8002413C
    // 0x8001F940: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001F940: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8001F944: beq         $v0, $zero, L_8001F9A0
    if (ctx->r2 == 0) {
        // 0x8001F948: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_8001F9A0;
    }
    // 0x8001F948: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001F94C: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001F950: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001F954: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x8001F958: addiu       $t9, $t9, -0x7380
    ctx->r25 = ADD32(ctx->r25, -0X7380);
    // 0x8001F95C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8001F960: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001F964: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8001F968: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001F96C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8001F970: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001F974: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8001F978: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8001F97C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8001F980: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8001F984: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001F988: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8001F98C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8001F990: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001F994: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001F998: jal         0x80020F8C
    // 0x8001F99C: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x8001F99C: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    after_1:
L_8001F9A0:
    // 0x8001F9A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001F9A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001F9A8: jr          $ra
    // 0x8001F9AC: nop

    return;
    // 0x8001F9AC: nop

;}
RECOMP_FUNC void func_80101818_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101818: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010181C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101820: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101824: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x80101828: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8010182C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101830: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80101834: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80101838: lh          $t1, 0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X6);
    // 0x8010183C: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x80101840: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80101844: sh          $t0, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r8;
    // 0x80101848: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8010184C: jr          $ra
    // 0x80101850: sh          $t3, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r11;
    return;
    // 0x80101850: sh          $t3, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_800143C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800143C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800143C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800143C8: jal         0x80013F5C
    // 0x800143CC: nop

    func_80013F5C(rdram, ctx);
        goto after_0;
    // 0x800143CC: nop

    after_0:
    // 0x800143D0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800143D4: addiu       $v1, $v1, 0x6DC0
    ctx->r3 = ADD32(ctx->r3, 0X6DC0);
    // 0x800143D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800143DC: addiu       $v0, $v0, 0x6EE0
    ctx->r2 = ADD32(ctx->r2, 0X6EE0);
    // 0x800143E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800143E4: lhu         $t8, 0x8($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X8);
    // 0x800143E8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800143EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800143F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800143F4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800143F8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800143FC: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x80014400: lwc1        $f4, 0x1428($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1428);
    // 0x80014404: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014408: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001440C: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80014410: lwc1        $f6, 0x142C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X142C);
    // 0x80014414: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80014418: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001441C: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
    // 0x80014420: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80014424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001442C: jr          $ra
    // 0x80014430: nop

    return;
    // 0x80014430: nop

;}
RECOMP_FUNC void func_80008290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80008294: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80008298: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000829C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800082A0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800082A4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800082A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800082AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800082B0: jal         0x8000835C
    // 0x800082B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8000835C(rdram, ctx);
        goto after_0;
    // 0x800082B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800082B8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800082BC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800082C0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800082C4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800082C8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800082CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800082D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800082D4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800082D8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800082DC: addiu       $v0, $v0, -0x4338
    ctx->r2 = ADD32(ctx->r2, -0X4338);
    // 0x800082E0: addiu       $a3, $zero, 0xA01
    ctx->r7 = ADD32(0, 0XA01);
    // 0x800082E4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800082E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800082EC: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x800082F0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800082F4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800082F8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800082FC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80008300: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80008304: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008308: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000830C: jal         0x8000EE60
    // 0x80008310: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8000EE60(rdram, ctx);
        goto after_1;
    // 0x80008310: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80008314: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80008318: addiu       $v0, $v0, -0x4338
    ctx->r2 = ADD32(ctx->r2, -0X4338);
    // 0x8000831C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008320: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80008324: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80008328: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8000832C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80008330: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80008334: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80008338: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8000833C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80008340: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x80008344: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80008348: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x8000834C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80008350: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008354: jr          $ra
    // 0x80008358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80008358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
