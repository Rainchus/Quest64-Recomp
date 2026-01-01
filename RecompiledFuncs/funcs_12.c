#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80019918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019918: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001991C: ldc1        $f14, 0x15B0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X15B0);
    // 0x80019920: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80019924: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80019928: lwc1        $f2, 0x34($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8001992C: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80019930: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80019934: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80019938: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001993C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80019940: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80019944: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80019948: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x8001994C: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80019950: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x80019954: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80019958: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8001995C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80019960: mul.d       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80019964: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80019968: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001996C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80019970: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80019974: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80019978: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x8001997C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80019980: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x80019984: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80019988: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x8001998C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80019990: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x80019994: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80019998: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001999C: ldc1        $f18, 0x15B8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X15B8);
    // 0x800199A0: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800199A4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800199A8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800199AC: beq         $at, $zero, L_800199C8
    if (ctx->r1 == 0) {
        // 0x800199B0: swc1        $f6, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
            goto L_800199C8;
    }
    // 0x800199B0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x800199B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800199B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800199BC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800199C0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800199C4: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
L_800199C8:
    // 0x800199C8: lbu         $t6, 0x3C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3C);
    // 0x800199CC: addiu       $t8, $t8, -0x42E4
    ctx->r24 = ADD32(ctx->r24, -0X42E4);
    // 0x800199D0: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800199D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800199D8: beq         $t9, $zero, L_80019A2C
    if (ctx->r25 == 0) {
        // 0x800199DC: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_80019A2C;
    }
    // 0x800199DC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800199E0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800199E4: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x800199E8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800199EC: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x800199F0: addiu       $t0, $a0, 0x8
    ctx->r8 = ADD32(ctx->r4, 0X8);
    // 0x800199F4: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800199F8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800199FC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80019A00: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x80019A04: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80019A08: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80019A0C: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80019A10: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80019A14: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80019A18: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80019A1C: ori         $t3, $t2, 0xDC
    ctx->r11 = ctx->r10 | 0XDC;
    // 0x80019A20: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x80019A24: jr          $ra
    // 0x80019A28: nop

    return;
    // 0x80019A28: nop

L_80019A2C:
    // 0x80019A2C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80019A30: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80019A34: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80019A38: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80019A3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80019A40: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80019A44: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80019A48: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x80019A4C: sll         $t1, $t8, 24
    ctx->r9 = S32(ctx->r24 << 24);
    // 0x80019A50: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80019A54: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80019A58: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80019A5C: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x80019A60: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x80019A64: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80019A68: jr          $ra
    // 0x80019A6C: nop

    return;
    // 0x80019A6C: nop

;}
RECOMP_FUNC void func_8000B7DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B7DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000B7E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000B7E4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8000B7E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B7EC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000B7F0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000B7F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000B7F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000B7FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8000B800: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8000B804: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000B808: lui         $t8, 0x803B
    ctx->r24 = S32(0X803B << 16);
    // 0x8000B80C: addiu       $t8, $t8, -0x60E0
    ctx->r24 = ADD32(ctx->r24, -0X60E0);
    // 0x8000B810: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000B814: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000B818: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000B81C: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x8000B820: lh          $t9, 0x2($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X2);
    // 0x8000B824: addiu       $s1, $s0, 0x24
    ctx->r17 = ADD32(ctx->r16, 0X24);
    // 0x8000B828: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000B82C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000B830: sh          $t9, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r25;
    // 0x8000B834: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8000B838: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8000B83C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000B840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000B844: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000B848: jal         0x8001D8B0
    // 0x8000B84C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x8000B84C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8000B850: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8000B854: addiu       $t2, $s0, 0x90
    ctx->r10 = ADD32(ctx->r16, 0X90);
    // 0x8000B858: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000B85C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8000B860: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8000B864: sw          $s2, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r18;
    // 0x8000B868: sw          $t2, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->r10;
    // 0x8000B86C: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x8000B870: sw          $s2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r18;
    // 0x8000B874: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    // 0x8000B878: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8000B87C: lhu         $t4, 0x6($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6);
    // 0x8000B880: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8000B884: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8000B888: sh          $t4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r12;
    // 0x8000B88C: lhu         $t5, 0xC($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XC);
    // 0x8000B890: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8000B894: bgez        $t5, L_8000B8A8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000B898: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000B8A8;
    }
    // 0x8000B898: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000B89C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000B8A0: nop

    // 0x8000B8A4: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_8000B8A8:
    // 0x8000B8A8: jal         0x80034F60
    // 0x8000B8AC: nop

    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x8000B8AC: nop

    after_1:
    // 0x8000B8B0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000B8B4: ldc1        $f18, 0x11D0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X11D0);
    // 0x8000B8B8: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8000B8BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000B8C0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000B8C4: ldc1        $f6, 0x11D8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X11D8);
    // 0x8000B8C8: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8000B8CC: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x8000B8D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B8D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000B8D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B8DC: addiu       $v0, $v0, -0x2EF0
    ctx->r2 = ADD32(ctx->r2, -0X2EF0);
    // 0x8000B8E0: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8000B8E4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000B8E8: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x8000B8EC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000B8F0: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8000B8F4: lhu         $t7, 0x2A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2A);
    // 0x8000B8F8: sh          $t7, 0x114($s0)
    MEM_H(0X114, ctx->r16) = ctx->r15;
    // 0x8000B8FC: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x8000B900: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x8000B904: sh          $t9, 0x116($s0)
    MEM_H(0X116, ctx->r16) = ctx->r25;
    // 0x8000B908: lw          $t0, 0x64($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X64);
    // 0x8000B90C: lhu         $t1, 0xE($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XE);
    // 0x8000B910: swc1        $f16, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f16.u32l;
    // 0x8000B914: sh          $t1, 0x118($s0)
    MEM_H(0X118, ctx->r16) = ctx->r9;
    // 0x8000B918: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8000B91C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8000B920: jal         0x8000EE60
    // 0x8000B924: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_8000EE60(rdram, ctx);
        goto after_2;
    // 0x8000B924: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8000B928: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B92C: addiu       $v0, $v0, -0x2EF0
    ctx->r2 = ADD32(ctx->r2, -0X2EF0);
    // 0x8000B930: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000B934: lui         $t2, 0x803B
    ctx->r10 = S32(0X803B << 16);
    // 0x8000B938: addiu       $t2, $t2, -0x5F58
    ctx->r10 = ADD32(ctx->r10, -0X5F58);
    // 0x8000B93C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x8000B940: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000B944: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x8000B948: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000B94C: bne         $s2, $t2, L_8000B980
    if (ctx->r18 != ctx->r10) {
        // 0x8000B950: swc1        $f6, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
            goto L_8000B980;
    }
    // 0x8000B950: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8000B954: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
    // 0x8000B958: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8000B95C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000B960: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8000B964: sh          $t4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r12;
    // 0x8000B968: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000B96C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000B970: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000B974: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8000B978: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8000B97C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_8000B980:
    // 0x8000B980: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000B984: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8000B988: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000B98C: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x8000B990: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000B994: addiu       $t6, $t6, -0x5F58
    ctx->r14 = ADD32(ctx->r14, -0X5F58);
    // 0x8000B998: ori         $t8, $t5, 0x4
    ctx->r24 = ctx->r13 | 0X4;
    // 0x8000B99C: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x8000B9A0: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000B9A4: swc1        $f10, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f10.u32l;
    // 0x8000B9A8: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000B9AC: sh          $t5, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = ctx->r13;
    // 0x8000B9B0: sh          $zero, 0x60($s1)
    MEM_H(0X60, ctx->r17) = 0;
    // 0x8000B9B4: bne         $s2, $t6, L_8000B9C0
    if (ctx->r18 != ctx->r14) {
        // 0x8000B9B8: swc1        $f16, 0x34($s1)
        MEM_W(0X34, ctx->r17) = ctx->f16.u32l;
            goto L_8000B9C0;
    }
    // 0x8000B9B8: swc1        $f16, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f16.u32l;
    // 0x8000B9BC: sh          $t8, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = ctx->r24;
L_8000B9C0:
    // 0x8000B9C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B9C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B9C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000B9CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9D0: jr          $ra
    // 0x8000B9D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000B9D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800187F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800187F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800187FC: ldc1        $f16, 0x1538($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1538);
    // 0x80018800: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80018804: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80018808: lwc1        $f2, 0x34($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8001880C: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80018810: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80018814: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80018818: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001881C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80018820: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80018824: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018828: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001882C: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x80018830: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80018834: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80018838: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8001883C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018840: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80018844: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80018848: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001884C: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x80018850: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80018854: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80018858: ldc1        $f4, 0x1540($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1540);
    // 0x8001885C: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80018860: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018864: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80018868: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001886C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80018870: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80018874: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80018878: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x8001887C: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80018880: lwc1        $f14, -0x3190($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X3190);
    // 0x80018884: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x80018888: swc1        $f14, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f14.u32l;
    // 0x8001888C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80018890: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80018894: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80018898: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8001889C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800188A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800188A4: lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X0);
    // 0x800188A8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800188AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800188B0: lbu         $t2, -0x3160($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X3160);
    // 0x800188B4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800188B8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800188BC: jr          $ra
    // 0x800188C0: nop

    return;
    // 0x800188C0: nop

;}
RECOMP_FUNC void func_80038E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E70: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80038E74: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80038E78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80038E7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038E80: bgez        $a2, L_80038E94
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80038E84: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80038E94;
    }
    // 0x80038E84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80038E88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038E8C: nop

    // 0x80038E90: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80038E94:
    // 0x80038E94: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80038E98: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80038E9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80038EA0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80038EA4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80038EA8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80038EAC: bgez        $t7, L_80038EC0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80038EB0: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80038EC0;
    }
    // 0x80038EB0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80038EB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038EB8: nop

    // 0x80038EBC: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80038EC0:
    // 0x80038EC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038EC4: ldc1        $f18, 0x1E58($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1E58);
    // 0x80038EC8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80038ECC: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80038ED0: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80038ED4: jr          $ra
    // 0x80038ED8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x80038ED8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void func_8002D614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D61C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002D620: lb          $t6, -0x2D6($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2D6);
    // 0x8002D624: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002D628: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002D62C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002D630: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8002D634: lbu         $a1, -0x2CF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2CF);
    // 0x8002D638: jal         0x8003195C
    // 0x8002D63C: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_8003195C(rdram, ctx);
        goto after_0;
    // 0x8002D63C: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_0:
    // 0x8002D640: beq         $v0, $zero, L_8002D6E0
    if (ctx->r2 == 0) {
        // 0x8002D644: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8002D6E0;
    }
    // 0x8002D644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D648: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D64C: jal         0x80031BB0
    // 0x8002D650: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    func_80031BB0(rdram, ctx);
        goto after_1;
    // 0x8002D650: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    after_1:
    // 0x8002D654: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8002D658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D65C: beq         $v1, $at, L_8002D68C
    if (ctx->r3 == ctx->r1) {
        // 0x8002D660: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002D68C;
    }
    // 0x8002D660: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D664: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D668: beq         $v1, $at, L_8002D6A8
    if (ctx->r3 == ctx->r1) {
        // 0x8002D66C: addiu       $t2, $zero, 0xC
        ctx->r10 = ADD32(0, 0XC);
            goto L_8002D6A8;
    }
    // 0x8002D66C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8002D670: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8002D674: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D678: sb          $t8, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r24;
    // 0x8002D67C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D680: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002D684: b           L_8002D6BC
    // 0x8002D688: sb          $t9, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r25;
        goto L_8002D6BC;
    // 0x8002D688: sb          $t9, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r25;
L_8002D68C:
    // 0x8002D68C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8002D690: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D694: sb          $t0, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r8;
    // 0x8002D698: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D69C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002D6A0: b           L_8002D6BC
    // 0x8002D6A4: sb          $t1, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r9;
        goto L_8002D6BC;
    // 0x8002D6A4: sb          $t1, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r9;
L_8002D6A8:
    // 0x8002D6A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D6AC: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
    // 0x8002D6B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D6B4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002D6B8: sb          $t3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r11;
L_8002D6BC:
    // 0x8002D6BC: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D6C0: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D6C4: andi        $t6, $t4, 0xFFF8
    ctx->r14 = ctx->r12 & 0XFFF8;
    // 0x8002D6C8: ori         $t8, $t6, 0x5
    ctx->r24 = ctx->r14 | 0X5;
    // 0x8002D6CC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002D6D0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8002D6D4: andi        $t9, $t8, 0xDFFF
    ctx->r25 = ctx->r24 & 0XDFFF;
    // 0x8002D6D8: b           L_8002D738
    // 0x8002D6DC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
        goto L_8002D738;
    // 0x8002D6DC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8002D6E0:
    // 0x8002D6E0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D6E4: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D6E8: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D6EC: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x8002D6F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D6F4: andi        $t2, $t0, 0xFFF8
    ctx->r10 = ctx->r8 & 0XFFF8;
    // 0x8002D6F8: ori         $t4, $t2, 0x5
    ctx->r12 = ctx->r10 | 0X5;
    // 0x8002D6FC: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x8002D700: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8002D704: andi        $t5, $t4, 0xDFFF
    ctx->r13 = ctx->r12 & 0XDFFF;
    // 0x8002D708: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8002D70C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002D710: lb          $t9, -0x2D6($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2D6);
    // 0x8002D714: sb          $t6, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r14;
    // 0x8002D718: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D71C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002D720: sb          $t7, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r15;
    // 0x8002D724: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D728: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8002D72C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8002D730: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002D734: sb          $t8, -0x2CF($at)
    MEM_B(-0X2CF, ctx->r1) = ctx->r24;
L_8002D738:
    // 0x8002D738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D740: jr          $ra
    // 0x8002D744: nop

    return;
    // 0x8002D744: nop

;}
RECOMP_FUNC void func_80049778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049778: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8004977C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80049780: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80049784: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80049788: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8004978C: beq         $t7, $zero, L_800497BC
    if (ctx->r15 == 0) {
        // 0x80049790: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800497BC;
    }
    // 0x80049790: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80049794: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_80049798:
    // 0x80049798: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8004979C: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x800497A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800497A4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800497A8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800497AC: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x800497B0: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800497B4: bne         $t7, $zero, L_80049798
    if (ctx->r15 != 0) {
        // 0x800497B8: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_80049798;
    }
    // 0x800497B8: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_800497BC:
    // 0x800497BC: jr          $ra
    // 0x800497C0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800497C0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_80010564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010564: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80010568: addiu       $t0, $t0, 0x5B68
    ctx->r8 = ADD32(ctx->r8, 0X5B68);
    // 0x8001056C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80010570: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80010574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010578: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8001057C: bnel        $v0, $at, L_80010614
    if (ctx->r2 != ctx->r1) {
        // 0x80010580: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_80010614;
    }
    goto skip_0;
    // 0x80010580: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80010584: lw          $at, 0x4($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X4);
    // 0x80010588: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001058C: addiu       $a2, $a2, 0x5B74
    ctx->r6 = ADD32(ctx->r6, 0X5B74);
    // 0x80010590: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80010594: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80010598: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8001059C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800105A0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800105A4: lw          $at, 0xC($v1)
    ctx->r1 = MEM_W(ctx->r3, 0XC);
    // 0x800105A8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x800105AC: lw          $at, 0x10($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X10);
    // 0x800105B0: sw          $at, -0x18($a2)
    MEM_W(-0X18, ctx->r6) = ctx->r1;
    // 0x800105B4: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x800105B8: sw          $t9, -0x14($a2)
    MEM_W(-0X14, ctx->r6) = ctx->r25;
    // 0x800105BC: lw          $at, 0x18($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X18);
    // 0x800105C0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800105C4: addiu       $t9, $t9, 0x5BC8
    ctx->r25 = ADD32(ctx->r25, 0X5BC8);
    // 0x800105C8: sw          $at, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->r1;
    // 0x800105CC: lw          $at, 0x1C($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X1C);
    // 0x800105D0: sw          $at, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r1;
    // 0x800105D4: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x800105D8: sw          $t6, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r14;
    // 0x800105DC: lw          $at, 0x24($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X24);
    // 0x800105E0: sw          $at, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r1;
    // 0x800105E4: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x800105E8: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x800105EC: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800105F0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800105F4: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x800105F8: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
    // 0x800105FC: lw          $at, 0x34($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X34);
    // 0x80010600: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80010604: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80010608: jr          $ra
    // 0x8001060C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    return;
    // 0x8001060C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80010610: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_80010614:
    // 0x80010614: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80010618: bnel        $at, $zero, L_80010638
    if (ctx->r1 != 0) {
        // 0x8001061C: lw          $a2, -0x3C($v1)
        ctx->r6 = MEM_W(ctx->r3, -0X3C);
            goto L_80010638;
    }
    goto skip_1;
    // 0x8001061C: lw          $a2, -0x3C($v1)
    ctx->r6 = MEM_W(ctx->r3, -0X3C);
    skip_1:
    // 0x80010620: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
L_80010624:
    // 0x80010624: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x80010628: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001062C: beql        $at, $zero, L_80010624
    if (ctx->r1 == 0) {
        // 0x80010630: lw          $a1, 0x3C($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X3C);
            goto L_80010624;
    }
    goto skip_2;
    // 0x80010630: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    skip_2:
    // 0x80010634: lw          $a2, -0x3C($v1)
    ctx->r6 = MEM_W(ctx->r3, -0X3C);
L_80010638:
    // 0x80010638: addiu       $t3, $v1, -0x38
    ctx->r11 = ADD32(ctx->r3, -0X38);
    // 0x8001063C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80010640: subu        $t0, $a1, $a2
    ctx->r8 = SUB32(ctx->r5, ctx->r6);
    // 0x80010644: subu        $t1, $a3, $a2
    ctx->r9 = SUB32(ctx->r7, ctx->r6);
    // 0x80010648: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8001064C: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010650: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80010654: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80010658: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8001065C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80010660: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80010664: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80010668: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001066C: addiu       $a2, $a2, 0x5B74
    ctx->r6 = ADD32(ctx->r6, 0X5B74);
    // 0x80010670: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // 0x80010674: mflo        $t8
    ctx->r24 = lo;
    // 0x80010678: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8001067C: addiu       $t4, $t4, 0x24
    ctx->r12 = ADD32(ctx->r12, 0X24);
    // 0x80010680: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010684: mflo        $t9
    ctx->r25 = lo;
    // 0x80010688: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001068C: nop

    // 0x80010690: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x80010694: bne         $t0, $zero, L_800106A0
    if (ctx->r8 != 0) {
        // 0x80010698: nop
    
            goto L_800106A0;
    }
    // 0x80010698: nop

    // 0x8001069C: break       7
    do_break(2147550876);
L_800106A0:
    // 0x800106A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800106A4: bne         $t0, $at, L_800106B8
    if (ctx->r8 != ctx->r1) {
        // 0x800106A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800106B8;
    }
    // 0x800106A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800106AC: bne         $t6, $at, L_800106B8
    if (ctx->r14 != ctx->r1) {
        // 0x800106B0: nop
    
            goto L_800106B8;
    }
    // 0x800106B0: nop

    // 0x800106B4: break       6
    do_break(2147550900);
L_800106B8:
    // 0x800106B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800106BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800106C0: sw          $t7, 0x5B68($at)
    MEM_W(0X5B68, ctx->r1) = ctx->r15;
    // 0x800106C4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800106C8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800106CC: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800106D0: mflo        $t8
    ctx->r24 = lo;
    // 0x800106D4: nop

    // 0x800106D8: nop

    // 0x800106DC: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800106E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800106E4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800106E8: nop

    // 0x800106EC: div         $zero, $t7, $t0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r8)));
    // 0x800106F0: bne         $t0, $zero, L_800106FC
    if (ctx->r8 != 0) {
        // 0x800106F4: nop
    
            goto L_800106FC;
    }
    // 0x800106F4: nop

    // 0x800106F8: break       7
    do_break(2147550968);
L_800106FC:
    // 0x800106FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010700: bne         $t0, $at, L_80010714
    if (ctx->r8 != ctx->r1) {
        // 0x80010704: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010714;
    }
    // 0x80010704: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010708: bne         $t7, $at, L_80010714
    if (ctx->r15 != ctx->r1) {
        // 0x8001070C: nop
    
            goto L_80010714;
    }
    // 0x8001070C: nop

    // 0x80010710: break       6
    do_break(2147550992);
L_80010714:
    // 0x80010714: mflo        $t5
    ctx->r13 = lo;
    // 0x80010718: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001071C: sw          $t5, 0x5B6C($at)
    MEM_W(0X5B6C, ctx->r1) = ctx->r13;
    // 0x80010720: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x80010724: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80010728: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001072C: mflo        $t8
    ctx->r24 = lo;
    // 0x80010730: nop

    // 0x80010734: nop

    // 0x80010738: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001073C: mflo        $t7
    ctx->r15 = lo;
    // 0x80010740: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x80010744: nop

    // 0x80010748: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x8001074C: bne         $t0, $zero, L_80010758
    if (ctx->r8 != 0) {
        // 0x80010750: nop
    
            goto L_80010758;
    }
    // 0x80010750: nop

    // 0x80010754: break       7
    do_break(2147551060);
L_80010758:
    // 0x80010758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001075C: bne         $t0, $at, L_80010770
    if (ctx->r8 != ctx->r1) {
        // 0x80010760: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010770;
    }
    // 0x80010760: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010764: bne         $t5, $at, L_80010770
    if (ctx->r13 != ctx->r1) {
        // 0x80010768: nop
    
            goto L_80010770;
    }
    // 0x80010768: nop

    // 0x8001076C: break       6
    do_break(2147551084);
L_80010770:
    // 0x80010770: mflo        $t9
    ctx->r25 = lo;
    // 0x80010774: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010778: sw          $t9, 0x5B70($at)
    MEM_W(0X5B70, ctx->r1) = ctx->r25;
    // 0x8001077C: lw          $t6, -0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X18);
    // 0x80010780: lw          $t7, -0x18($t4)
    ctx->r15 = MEM_W(ctx->r12, -0X18);
    // 0x80010784: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010788: mflo        $t8
    ctx->r24 = lo;
    // 0x8001078C: nop

    // 0x80010790: nop

    // 0x80010794: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010798: mflo        $t5
    ctx->r13 = lo;
    // 0x8001079C: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800107A0: nop

    // 0x800107A4: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x800107A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800107AC: sw          $t6, -0x18($a2)
    MEM_W(-0X18, ctx->r6) = ctx->r14;
    // 0x800107B0: lw          $t7, -0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X14);
    // 0x800107B4: lw          $t5, -0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X14);
    // 0x800107B8: bne         $t0, $zero, L_800107C4
    if (ctx->r8 != 0) {
        // 0x800107BC: nop
    
            goto L_800107C4;
    }
    // 0x800107BC: nop

    // 0x800107C0: break       7
    do_break(2147551168);
L_800107C4:
    // 0x800107C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800107C8: bne         $t0, $at, L_800107DC
    if (ctx->r8 != ctx->r1) {
        // 0x800107CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800107DC;
    }
    // 0x800107CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800107D0: bne         $t9, $at, L_800107DC
    if (ctx->r25 != ctx->r1) {
        // 0x800107D4: nop
    
            goto L_800107DC;
    }
    // 0x800107D4: nop

    // 0x800107D8: break       6
    do_break(2147551192);
L_800107DC:
    // 0x800107DC: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800107E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800107E4: nop

    // 0x800107E8: nop

    // 0x800107EC: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800107F0: mflo        $t9
    ctx->r25 = lo;
    // 0x800107F4: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800107F8: nop

    // 0x800107FC: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x80010800: mflo        $t7
    ctx->r15 = lo;
    // 0x80010804: sw          $t7, -0x14($a2)
    MEM_W(-0X14, ctx->r6) = ctx->r15;
    // 0x80010808: lw          $t5, -0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X10);
    // 0x8001080C: lw          $t9, -0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, -0X10);
    // 0x80010810: bne         $t0, $zero, L_8001081C
    if (ctx->r8 != 0) {
        // 0x80010814: nop
    
            goto L_8001081C;
    }
    // 0x80010814: nop

    // 0x80010818: break       7
    do_break(2147551256);
L_8001081C:
    // 0x8001081C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010820: bne         $t0, $at, L_80010834
    if (ctx->r8 != ctx->r1) {
        // 0x80010824: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010834;
    }
    // 0x80010824: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010828: bne         $t6, $at, L_80010834
    if (ctx->r14 != ctx->r1) {
        // 0x8001082C: nop
    
            goto L_80010834;
    }
    // 0x8001082C: nop

    // 0x80010830: break       6
    do_break(2147551280);
L_80010834:
    // 0x80010834: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010838: mflo        $t8
    ctx->r24 = lo;
    // 0x8001083C: nop

    // 0x80010840: nop

    // 0x80010844: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010848: mflo        $t6
    ctx->r14 = lo;
    // 0x8001084C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80010850: nop

    // 0x80010854: div         $zero, $t7, $t0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r8)));
    // 0x80010858: mflo        $t5
    ctx->r13 = lo;
    // 0x8001085C: sw          $t5, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->r13;
    // 0x80010860: lw          $t9, -0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, -0XC);
    // 0x80010864: lw          $t6, -0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, -0XC);
    // 0x80010868: bne         $t0, $zero, L_80010874
    if (ctx->r8 != 0) {
        // 0x8001086C: nop
    
            goto L_80010874;
    }
    // 0x8001086C: nop

    // 0x80010870: break       7
    do_break(2147551344);
L_80010874:
    // 0x80010874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010878: bne         $t0, $at, L_8001088C
    if (ctx->r8 != ctx->r1) {
        // 0x8001087C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001088C;
    }
    // 0x8001087C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010880: bne         $t7, $at, L_8001088C
    if (ctx->r15 != ctx->r1) {
        // 0x80010884: nop
    
            goto L_8001088C;
    }
    // 0x80010884: nop

    // 0x80010888: break       6
    do_break(2147551368);
L_8001088C:
    // 0x8001088C: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010890: mflo        $t8
    ctx->r24 = lo;
    // 0x80010894: nop

    // 0x80010898: nop

    // 0x8001089C: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800108A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800108A4: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x800108A8: nop

    // 0x800108AC: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x800108B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800108B4: sw          $t9, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r25;
    // 0x800108B8: lw          $t6, -0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X8);
    // 0x800108BC: lw          $t7, -0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, -0X8);
    // 0x800108C0: bne         $t0, $zero, L_800108CC
    if (ctx->r8 != 0) {
        // 0x800108C4: nop
    
            goto L_800108CC;
    }
    // 0x800108C4: nop

    // 0x800108C8: break       7
    do_break(2147551432);
L_800108CC:
    // 0x800108CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800108D0: bne         $t0, $at, L_800108E4
    if (ctx->r8 != ctx->r1) {
        // 0x800108D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800108E4;
    }
    // 0x800108D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800108D8: bne         $t5, $at, L_800108E4
    if (ctx->r13 != ctx->r1) {
        // 0x800108DC: nop
    
            goto L_800108E4;
    }
    // 0x800108DC: nop

    // 0x800108E0: break       6
    do_break(2147551456);
L_800108E4:
    // 0x800108E4: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800108E8: mflo        $t8
    ctx->r24 = lo;
    // 0x800108EC: nop

    // 0x800108F0: nop

    // 0x800108F4: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800108F8: mflo        $t5
    ctx->r13 = lo;
    // 0x800108FC: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80010900: nop

    // 0x80010904: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x80010908: mflo        $t6
    ctx->r14 = lo;
    // 0x8001090C: sw          $t6, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r14;
    // 0x80010910: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80010914: lw          $t5, -0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X4);
    // 0x80010918: bne         $t0, $zero, L_80010924
    if (ctx->r8 != 0) {
        // 0x8001091C: nop
    
            goto L_80010924;
    }
    // 0x8001091C: nop

    // 0x80010920: break       7
    do_break(2147551520);
L_80010924:
    // 0x80010924: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010928: bne         $t0, $at, L_8001093C
    if (ctx->r8 != ctx->r1) {
        // 0x8001092C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001093C;
    }
    // 0x8001092C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010930: bne         $t9, $at, L_8001093C
    if (ctx->r25 != ctx->r1) {
        // 0x80010934: nop
    
            goto L_8001093C;
    }
    // 0x80010934: nop

    // 0x80010938: break       6
    do_break(2147551544);
L_8001093C:
    // 0x8001093C: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010940: mflo        $t8
    ctx->r24 = lo;
    // 0x80010944: nop

    // 0x80010948: nop

    // 0x8001094C: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010950: mflo        $t9
    ctx->r25 = lo;
    // 0x80010954: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80010958: nop

    // 0x8001095C: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x80010960: mflo        $t7
    ctx->r15 = lo;
    // 0x80010964: sw          $t7, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r15;
    // 0x80010968: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8001096C: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80010970: bne         $t0, $zero, L_8001097C
    if (ctx->r8 != 0) {
        // 0x80010974: nop
    
            goto L_8001097C;
    }
    // 0x80010974: nop

    // 0x80010978: break       7
    do_break(2147551608);
L_8001097C:
    // 0x8001097C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010980: bne         $t0, $at, L_80010994
    if (ctx->r8 != ctx->r1) {
        // 0x80010984: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010994;
    }
    // 0x80010984: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010988: bne         $t6, $at, L_80010994
    if (ctx->r14 != ctx->r1) {
        // 0x8001098C: nop
    
            goto L_80010994;
    }
    // 0x8001098C: nop

    // 0x80010990: break       6
    do_break(2147551632);
L_80010994:
    // 0x80010994: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010998: mflo        $t8
    ctx->r24 = lo;
    // 0x8001099C: nop

    // 0x800109A0: nop

    // 0x800109A4: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800109A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800109AC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800109B0: nop

    // 0x800109B4: div         $zero, $t7, $t0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r8)));
    // 0x800109B8: mflo        $t5
    ctx->r13 = lo;
    // 0x800109BC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800109C0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800109C4: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x800109C8: bne         $t0, $zero, L_800109D4
    if (ctx->r8 != 0) {
        // 0x800109CC: nop
    
            goto L_800109D4;
    }
    // 0x800109CC: nop

    // 0x800109D0: break       7
    do_break(2147551696);
L_800109D4:
    // 0x800109D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800109D8: bne         $t0, $at, L_800109EC
    if (ctx->r8 != ctx->r1) {
        // 0x800109DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800109EC;
    }
    // 0x800109DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800109E0: bne         $t7, $at, L_800109EC
    if (ctx->r15 != ctx->r1) {
        // 0x800109E4: nop
    
            goto L_800109EC;
    }
    // 0x800109E4: nop

    // 0x800109E8: break       6
    do_break(2147551720);
L_800109EC:
    // 0x800109EC: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800109F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800109F4: nop

    // 0x800109F8: nop

    // 0x800109FC: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010A00: mflo        $t7
    ctx->r15 = lo;
    // 0x80010A04: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x80010A08: nop

    // 0x80010A0C: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x80010A10: mflo        $t9
    ctx->r25 = lo;
    // 0x80010A14: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80010A18: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80010A1C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x80010A20: bne         $t0, $zero, L_80010A2C
    if (ctx->r8 != 0) {
        // 0x80010A24: nop
    
            goto L_80010A2C;
    }
    // 0x80010A24: nop

    // 0x80010A28: break       7
    do_break(2147551784);
L_80010A2C:
    // 0x80010A2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010A30: bne         $t0, $at, L_80010A44
    if (ctx->r8 != ctx->r1) {
        // 0x80010A34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010A44;
    }
    // 0x80010A34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010A38: bne         $t5, $at, L_80010A44
    if (ctx->r13 != ctx->r1) {
        // 0x80010A3C: nop
    
            goto L_80010A44;
    }
    // 0x80010A3C: nop

    // 0x80010A40: break       6
    do_break(2147551808);
L_80010A44:
    // 0x80010A44: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010A48: addiu       $v0, $v1, -0x3C
    ctx->r2 = ADD32(ctx->r3, -0X3C);
    // 0x80010A4C: mflo        $t8
    ctx->r24 = lo;
    // 0x80010A50: nop

    // 0x80010A54: nop

    // 0x80010A58: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010A5C: mflo        $t5
    ctx->r13 = lo;
    // 0x80010A60: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80010A64: nop

    // 0x80010A68: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x80010A6C: mflo        $t6
    ctx->r14 = lo;
    // 0x80010A70: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x80010A74: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x80010A78: lw          $t5, 0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X34);
    // 0x80010A7C: bne         $t0, $zero, L_80010A88
    if (ctx->r8 != 0) {
        // 0x80010A80: nop
    
            goto L_80010A88;
    }
    // 0x80010A80: nop

    // 0x80010A84: break       7
    do_break(2147551876);
L_80010A88:
    // 0x80010A88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010A8C: bne         $t0, $at, L_80010AA0
    if (ctx->r8 != ctx->r1) {
        // 0x80010A90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010AA0;
    }
    // 0x80010A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010A94: bne         $t9, $at, L_80010AA0
    if (ctx->r25 != ctx->r1) {
        // 0x80010A98: nop
    
            goto L_80010AA0;
    }
    // 0x80010A98: nop

    // 0x80010A9C: break       6
    do_break(2147551900);
L_80010AA0:
    // 0x80010AA0: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010AA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80010AA8: nop

    // 0x80010AAC: nop

    // 0x80010AB0: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010AB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80010AB8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80010ABC: nop

    // 0x80010AC0: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x80010AC4: bne         $t0, $zero, L_80010AD0
    if (ctx->r8 != 0) {
        // 0x80010AC8: nop
    
            goto L_80010AD0;
    }
    // 0x80010AC8: nop

    // 0x80010ACC: break       7
    do_break(2147551948);
L_80010AD0:
    // 0x80010AD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010AD4: bne         $t0, $at, L_80010AE8
    if (ctx->r8 != ctx->r1) {
        // 0x80010AD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010AE8;
    }
    // 0x80010AD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010ADC: bne         $t6, $at, L_80010AE8
    if (ctx->r14 != ctx->r1) {
        // 0x80010AE0: nop
    
            goto L_80010AE8;
    }
    // 0x80010AE0: nop

    // 0x80010AE4: break       6
    do_break(2147551972);
L_80010AE8:
    // 0x80010AE8: mflo        $t7
    ctx->r15 = lo;
    // 0x80010AEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010AF0: sw          $t7, 0x5BC8($at)
    MEM_W(0X5BC8, ctx->r1) = ctx->r15;
    // 0x80010AF4: lw          $t5, 0x38($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X38);
    // 0x80010AF8: lw          $t9, 0x38($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X38);
    // 0x80010AFC: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010B00: mflo        $t8
    ctx->r24 = lo;
    // 0x80010B04: nop

    // 0x80010B08: nop

    // 0x80010B0C: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010B10: mflo        $t6
    ctx->r14 = lo;
    // 0x80010B14: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80010B18: nop

    // 0x80010B1C: div         $zero, $t7, $t0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r8)));
    // 0x80010B20: bne         $t0, $zero, L_80010B2C
    if (ctx->r8 != 0) {
        // 0x80010B24: nop
    
            goto L_80010B2C;
    }
    // 0x80010B24: nop

    // 0x80010B28: break       7
    do_break(2147552040);
L_80010B2C:
    // 0x80010B2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010B30: bne         $t0, $at, L_80010B44
    if (ctx->r8 != ctx->r1) {
        // 0x80010B34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010B44;
    }
    // 0x80010B34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010B38: bne         $t7, $at, L_80010B44
    if (ctx->r15 != ctx->r1) {
        // 0x80010B3C: nop
    
            goto L_80010B44;
    }
    // 0x80010B3C: nop

    // 0x80010B40: break       6
    do_break(2147552064);
L_80010B44:
    // 0x80010B44: mflo        $t5
    ctx->r13 = lo;
    // 0x80010B48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010B4C: sw          $t5, 0x5BCC($at)
    MEM_W(0X5BCC, ctx->r1) = ctx->r13;
    // 0x80010B50: jr          $ra
    // 0x80010B54: nop

    return;
    // 0x80010B54: nop

;}
RECOMP_FUNC void func_80049D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049D50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80049D54: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80049D58: jr          $ra
    // 0x80049D5C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x80049D5C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_800278B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800278B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800278B4: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x800278B8: addiu       $v0, $v0, -0x600
    ctx->r2 = ADD32(ctx->r2, -0X600);
    // 0x800278BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800278C0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800278C4: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800278C8: addiu       $t7, $t7, -0x710
    ctx->r15 = ADD32(ctx->r15, -0X710);
    // 0x800278CC: lwr         $at, 0x2($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X2);
    // 0x800278D0: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800278D4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800278D8: swr         $at, 0x2($t6)
    do_swr(rdram, 0X2, ctx->r14, ctx->r1);
    // 0x800278DC: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x800278E0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800278E4: addiu       $t8, $zero, 0x6C
    ctx->r24 = ADD32(0, 0X6C);
    // 0x800278E8: subu        $t9, $t5, $t4
    ctx->r25 = SUB32(ctx->r13, ctx->r12);
    // 0x800278EC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800278F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800278F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800278F8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x800278FC: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80027900: jal         0x80029B58
    // 0x80027904: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_80029B58(rdram, ctx);
        goto after_0;
    // 0x80027904: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x80027908: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002790C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80027910: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027914: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027918: addiu       $a2, $zero, 0x8B
    ctx->r6 = ADD32(0, 0X8B);
    // 0x8002791C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80027920: jal         0x80029B58
    // 0x80027924: addiu       $a1, $a1, 0x2B
    ctx->r5 = ADD32(ctx->r5, 0X2B);
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x80027924: addiu       $a1, $a1, 0x2B
    ctx->r5 = ADD32(ctx->r5, 0X2B);
    after_1:
    // 0x80027928: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002792C: addiu       $t7, $zero, 0x68
    ctx->r15 = ADD32(0, 0X68);
    // 0x80027930: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027934: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027938: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x8002793C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80027940: jal         0x80029B58
    // 0x80027944: addiu       $a1, $a1, 0x119
    ctx->r5 = ADD32(ctx->r5, 0X119);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x80027944: addiu       $a1, $a1, 0x119
    ctx->r5 = ADD32(ctx->r5, 0X119);
    after_2:
    // 0x80027948: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002794C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80027950: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027954: addiu       $a1, $a1, 0x27
    ctx->r5 = ADD32(ctx->r5, 0X27);
    // 0x80027958: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8002795C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027960: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80027964: jal         0x80029B58
    // 0x80027968: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x80027968: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_3:
    // 0x8002796C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80027970: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80027974: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027978: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8002797C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x80027980: jal         0x80029B58
    // 0x80027984: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x80027984: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_4:
    // 0x80027988: addiu       $t4, $zero, 0x6D
    ctx->r12 = ADD32(0, 0X6D);
    // 0x8002798C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027990: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027994: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027998: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8002799C: jal         0x80029B58
    // 0x800279A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x800279A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800279A4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800279A8: addiu       $t9, $zero, 0x6D
    ctx->r25 = ADD32(0, 0X6D);
    // 0x800279AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800279B0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800279B4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x800279B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800279BC: jal         0x80029B58
    // 0x800279C0: addiu       $a1, $a1, 0x118
    ctx->r5 = ADD32(ctx->r5, 0X118);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x800279C0: addiu       $a1, $a1, 0x118
    ctx->r5 = ADD32(ctx->r5, 0X118);
    after_6:
    // 0x800279C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800279C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800279CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800279D0: addiu       $a1, $a1, 0x29
    ctx->r5 = ADD32(ctx->r5, 0X29);
    // 0x800279D4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800279D8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800279DC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x800279E0: jal         0x80029B58
    // 0x800279E4: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x800279E4: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    after_7:
    // 0x800279E8: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x800279EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800279F0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800279F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800279F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800279FC: jal         0x80029B58
    // 0x80027A00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x80027A00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80027A04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80027A08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027A0C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80027A10: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027A14: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80027A18: jal         0x80029B58
    // 0x80027A1C: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x80027A1C: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    after_9:
    // 0x80027A20: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A24: addiu       $t3, $zero, 0x69
    ctx->r11 = ADD32(0, 0X69);
    // 0x80027A28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027A2C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80027A30: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80027A34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80027A38: jal         0x80029B58
    // 0x80027A3C: addiu       $a1, $a1, 0x116
    ctx->r5 = ADD32(ctx->r5, 0X116);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x80027A3C: addiu       $a1, $a1, 0x116
    ctx->r5 = ADD32(ctx->r5, 0X116);
    after_10:
    // 0x80027A40: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A44: addiu       $t5, $zero, 0x6C
    ctx->r13 = ADD32(0, 0X6C);
    // 0x80027A48: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80027A4C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80027A50: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80027A54: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    // 0x80027A58: jal         0x80029B58
    // 0x80027A5C: addiu       $a1, $a1, 0x3A
    ctx->r5 = ADD32(ctx->r5, 0X3A);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x80027A5C: addiu       $a1, $a1, 0x3A
    ctx->r5 = ADD32(ctx->r5, 0X3A);
    after_11:
    // 0x80027A60: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A64: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80027A68: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027A6C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x80027A70: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    // 0x80027A74: addiu       $a3, $zero, 0xA7
    ctx->r7 = ADD32(0, 0XA7);
    // 0x80027A78: jal         0x80029B58
    // 0x80027A7C: addiu       $a1, $a1, 0x5D
    ctx->r5 = ADD32(ctx->r5, 0X5D);
    func_80029B58(rdram, ctx);
        goto after_12;
    // 0x80027A7C: addiu       $a1, $a1, 0x5D
    ctx->r5 = ADD32(ctx->r5, 0X5D);
    after_12:
    // 0x80027A80: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A84: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80027A88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027A8C: addiu       $a1, $a1, 0x8D
    ctx->r5 = ADD32(ctx->r5, 0X8D);
    // 0x80027A90: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80027A94: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80027A98: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80027A9C: jal         0x80029B58
    // 0x80027AA0: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    func_80029B58(rdram, ctx);
        goto after_13;
    // 0x80027AA0: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    after_13:
    // 0x80027AA4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80027AA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027AAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027AB0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80027AB4: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    // 0x80027AB8: jal         0x80029B58
    // 0x80027ABC: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    func_80029B58(rdram, ctx);
        goto after_14;
    // 0x80027ABC: addiu       $a3, $zero, 0x54
    ctx->r7 = ADD32(0, 0X54);
    after_14:
    // 0x80027AC0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027AC4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80027AC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027ACC: addiu       $a1, $a1, 0xEA
    ctx->r5 = ADD32(ctx->r5, 0XEA);
    // 0x80027AD0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80027AD4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x80027AD8: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    // 0x80027ADC: jal         0x80029B58
    // 0x80027AE0: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80029B58(rdram, ctx);
        goto after_15;
    // 0x80027AE0: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_15:
    // 0x80027AE4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027AE8: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80027AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027AF0: addiu       $a1, $a1, 0x6C
    ctx->r5 = ADD32(ctx->r5, 0X6C);
    // 0x80027AF4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80027AF8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80027AFC: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // 0x80027B00: jal         0x80029B58
    // 0x80027B04: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_80029B58(rdram, ctx);
        goto after_16;
    // 0x80027B04: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_16:
    // 0x80027B08: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80027B0C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027B10: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x80027B14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027B18: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // 0x80027B1C: jal         0x80029B58
    // 0x80027B20: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80029B58(rdram, ctx);
        goto after_17;
    // 0x80027B20: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_17:
    // 0x80027B24: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80027B28: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80027B2C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80027B30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80027B34: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x80027B38: jal         0x80029B58
    // 0x80027B3C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x80027B3C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_18:
    // 0x80027B40: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027B44: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80027B48: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027B4C: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x80027B50: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x80027B54: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    // 0x80027B58: jal         0x80029B58
    // 0x80027B5C: addiu       $a1, $a1, 0x31
    ctx->r5 = ADD32(ctx->r5, 0X31);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x80027B5C: addiu       $a1, $a1, 0x31
    ctx->r5 = ADD32(ctx->r5, 0X31);
    after_19:
    // 0x80027B60: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027B64: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80027B68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027B6C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x80027B70: addiu       $a2, $zero, 0x65
    ctx->r6 = ADD32(0, 0X65);
    // 0x80027B74: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80027B78: jal         0x80029B58
    // 0x80027B7C: addiu       $a1, $a1, 0x35
    ctx->r5 = ADD32(ctx->r5, 0X35);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x80027B7C: addiu       $a1, $a1, 0x35
    ctx->r5 = ADD32(ctx->r5, 0X35);
    after_20:
    // 0x80027B80: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027B84: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80027B88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027B8C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80027B90: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80027B94: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80027B98: jal         0x80029B58
    // 0x80027B9C: addiu       $a1, $a1, 0x45
    ctx->r5 = ADD32(ctx->r5, 0X45);
    func_80029B58(rdram, ctx);
        goto after_21;
    // 0x80027B9C: addiu       $a1, $a1, 0x45
    ctx->r5 = ADD32(ctx->r5, 0X45);
    after_21:
    // 0x80027BA0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027BA4: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80027BA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027BAC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80027BB0: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80027BB4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80027BB8: jal         0x80029B58
    // 0x80027BBC: addiu       $a1, $a1, 0xF3
    ctx->r5 = ADD32(ctx->r5, 0XF3);
    func_80029B58(rdram, ctx);
        goto after_22;
    // 0x80027BBC: addiu       $a1, $a1, 0xF3
    ctx->r5 = ADD32(ctx->r5, 0XF3);
    after_22:
    // 0x80027BC0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80027BC4: lw          $t1, -0x2F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2F0);
    // 0x80027BC8: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80027BCC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80027BD0: sra         $t7, $t1, 2
    ctx->r15 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80027BD4: andi        $t3, $t7, 0xF
    ctx->r11 = ctx->r15 & 0XF;
    // 0x80027BD8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80027BDC: lb          $t1, -0xF40($at)
    ctx->r9 = MEM_B(ctx->r1, -0XF40);
    // 0x80027BE0: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80027BE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027BE8: addu        $a1, $t5, $t1
    ctx->r5 = ADD32(ctx->r13, ctx->r9);
    // 0x80027BEC: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    // 0x80027BF0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80027BF4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80027BF8: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80027BFC: jal         0x80029B58
    // 0x80027C00: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    func_80029B58(rdram, ctx);
        goto after_23;
    // 0x80027C00: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_23:
    // 0x80027C04: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80027C08: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80027C0C: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80027C10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027C14: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    // 0x80027C18: addiu       $a1, $a1, 0xFB
    ctx->r5 = ADD32(ctx->r5, 0XFB);
    // 0x80027C1C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80027C20: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80027C24: jal         0x80029B58
    // 0x80027C28: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_24;
    // 0x80027C28: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_24:
    // 0x80027C2C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027C30: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80027C34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027C38: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80027C3C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80027C40: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x80027C44: jal         0x80029B58
    // 0x80027C48: addiu       $a1, $a1, 0x77
    ctx->r5 = ADD32(ctx->r5, 0X77);
    func_80029B58(rdram, ctx);
        goto after_25;
    // 0x80027C48: addiu       $a1, $a1, 0x77
    ctx->r5 = ADD32(ctx->r5, 0X77);
    after_25:
    // 0x80027C4C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027C50: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80027C54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027C58: addiu       $a1, $a1, 0x8E
    ctx->r5 = ADD32(ctx->r5, 0X8E);
    // 0x80027C5C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80027C60: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x80027C64: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x80027C68: jal         0x80029B58
    // 0x80027C6C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    func_80029B58(rdram, ctx);
        goto after_26;
    // 0x80027C6C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_26:
    // 0x80027C70: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80027C74: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027C78: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027C7C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x80027C80: addiu       $a2, $zero, 0x6D
    ctx->r6 = ADD32(0, 0X6D);
    // 0x80027C84: jal         0x80029B58
    // 0x80027C88: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    func_80029B58(rdram, ctx);
        goto after_27;
    // 0x80027C88: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_27:
    // 0x80027C8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027C90: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80027C94: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80027C98: addiu       $a1, $a1, 0xB3
    ctx->r5 = ADD32(ctx->r5, 0XB3);
    // 0x80027C9C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80027CA0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80027CA4: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x80027CA8: jal         0x80029B58
    // 0x80027CAC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_28;
    // 0x80027CAC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_28:
    // 0x80027CB0: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80027CB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80027CB8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027CBC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80027CC0: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80027CC4: jal         0x80029B58
    // 0x80027CC8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_29;
    // 0x80027CC8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_29:
    // 0x80027CCC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027CD0: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80027CD4: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80027CD8: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80027CDC: addiu       $t7, $t7, -0x6EC
    ctx->r15 = ADD32(ctx->r15, -0X6EC);
    // 0x80027CE0: andi        $t9, $a3, 0x200
    ctx->r25 = ctx->r7 & 0X200;
    // 0x80027CE4: beq         $t9, $zero, L_80027DAC
    if (ctx->r25 == 0) {
        // 0x80027CE8: lui         $t8, 0x8006
        ctx->r24 = S32(0X8006 << 16);
            goto L_80027DAC;
    }
    // 0x80027CE8: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80027CEC: andi        $v0, $a3, 0x100
    ctx->r2 = ctx->r7 & 0X100;
    // 0x80027CF0: beq         $v0, $zero, L_80027D0C
    if (ctx->r2 == 0) {
        // 0x80027CF4: lui         $t8, 0x8006
        ctx->r24 = S32(0X8006 << 16);
            goto L_80027D0C;
    }
    // 0x80027CF4: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80027CF8: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80027CFC: beq         $v0, $at, L_80027D5C
    if (ctx->r2 == ctx->r1) {
        // 0x80027D00: lui         $t8, 0x8006
        ctx->r24 = S32(0X8006 << 16);
            goto L_80027D5C;
    }
    // 0x80027D00: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80027D04: b           L_80027E38
    // 0x80027D08: andi        $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 & 0X2000;
        goto L_80027E38;
    // 0x80027D08: andi        $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 & 0X2000;
L_80027D0C:
    // 0x80027D0C: lb          $t8, -0xFF0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0XFF0);
    // 0x80027D10: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80027D14: addiu       $t7, $t7, -0x6EC
    ctx->r15 = ADD32(ctx->r15, -0X6EC);
    // 0x80027D18: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80027D1C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80027D20: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80027D24: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80027D28: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80027D2C: addu        $a0, $sp, $t3
    ctx->r4 = ADD32(ctx->r29, ctx->r11);
    // 0x80027D30: lbu         $a0, 0x38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X38);
    // 0x80027D34: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80027D38: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027D3C: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80027D40: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80027D44: jal         0x80029B58
    // 0x80027D48: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    func_80029B58(rdram, ctx);
        goto after_30;
    // 0x80027D48: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    after_30:
    // 0x80027D4C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027D50: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80027D54: b           L_80027E34
    // 0x80027D58: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
        goto L_80027E34;
    // 0x80027D58: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
L_80027D5C:
    // 0x80027D5C: lb          $t8, -0x600($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X600);
    // 0x80027D60: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80027D64: addiu       $t7, $t7, -0x70C
    ctx->r15 = ADD32(ctx->r15, -0X70C);
    // 0x80027D68: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80027D6C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80027D70: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80027D74: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80027D78: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80027D7C: addu        $a0, $sp, $t3
    ctx->r4 = ADD32(ctx->r29, ctx->r11);
    // 0x80027D80: lbu         $a0, 0x38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X38);
    // 0x80027D84: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80027D88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027D8C: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x80027D90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80027D94: jal         0x80029B58
    // 0x80027D98: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    func_80029B58(rdram, ctx);
        goto after_31;
    // 0x80027D98: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    after_31:
    // 0x80027D9C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027DA0: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80027DA4: b           L_80027E34
    // 0x80027DA8: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
        goto L_80027E34;
    // 0x80027DA8: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
L_80027DAC:
    // 0x80027DAC: lb          $t8, -0xFF0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0XFF0);
    // 0x80027DB0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80027DB4: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80027DB8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80027DBC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80027DC0: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80027DC4: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80027DC8: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80027DCC: addu        $a0, $sp, $t3
    ctx->r4 = ADD32(ctx->r29, ctx->r11);
    // 0x80027DD0: lbu         $a0, 0x38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X38);
    // 0x80027DD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027DD8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80027DDC: jal         0x80029B58
    // 0x80027DE0: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    func_80029B58(rdram, ctx);
        goto after_32;
    // 0x80027DE0: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    after_32:
    // 0x80027DE4: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80027DE8: lb          $t8, -0x600($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X600);
    // 0x80027DEC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80027DF0: addiu       $t7, $t7, -0x70C
    ctx->r15 = ADD32(ctx->r15, -0X70C);
    // 0x80027DF4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80027DF8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80027DFC: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80027E00: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80027E04: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80027E08: addu        $a0, $sp, $t3
    ctx->r4 = ADD32(ctx->r29, ctx->r11);
    // 0x80027E0C: lbu         $a0, 0x38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X38);
    // 0x80027E10: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80027E14: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027E18: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x80027E1C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80027E20: jal         0x80029B58
    // 0x80027E24: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    func_80029B58(rdram, ctx);
        goto after_33;
    // 0x80027E24: addu        $a1, $t5, $t4
    ctx->r5 = ADD32(ctx->r13, ctx->r12);
    after_33:
    // 0x80027E28: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027E2C: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80027E30: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
L_80027E34:
    // 0x80027E34: andi        $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 & 0X2000;
L_80027E38:
    // 0x80027E38: beq         $t8, $zero, L_80027E58
    if (ctx->r24 == 0) {
        // 0x80027E3C: lui         $v0, 0x8006
        ctx->r2 = S32(0X8006 << 16);
            goto L_80027E58;
    }
    // 0x80027E3C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80027E40: addiu       $v0, $v0, -0x600
    ctx->r2 = ADD32(ctx->r2, -0X600);
    // 0x80027E44: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80027E48: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80027E4C: subu        $t3, $t7, $t6
    ctx->r11 = SUB32(ctx->r15, ctx->r14);
    // 0x80027E50: b           L_80028614
    // 0x80027E54: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
        goto L_80028614;
    // 0x80027E54: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80027E58:
    // 0x80027E58: andi        $t5, $a3, 0x800
    ctx->r13 = ctx->r7 & 0X800;
    // 0x80027E5C: bne         $t5, $zero, L_80027F40
    if (ctx->r13 != 0) {
        // 0x80027E60: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80027F40;
    }
    // 0x80027E60: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80027E64: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x80027E68: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80027E6C: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x80027E70: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80027E74: beq         $at, $zero, L_80027E90
    if (ctx->r1 == 0) {
        // 0x80027E78: ori         $t8, $a3, 0x2000
        ctx->r24 = ctx->r7 | 0X2000;
            goto L_80027E90;
    }
    // 0x80027E78: ori         $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 | 0X2000;
    // 0x80027E7C: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x80027E80: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80027E84: andi        $t4, $v1, 0x10
    ctx->r12 = ctx->r3 & 0X10;
    // 0x80027E88: beq         $t4, $zero, L_80027EC8
    if (ctx->r12 == 0) {
        // 0x80027E8C: nop
    
            goto L_80027EC8;
    }
    // 0x80027E8C: nop

L_80027E90:
    // 0x80027E90: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027E94: sw          $t9, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r25;
    // 0x80027E98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027E9C: sw          $zero, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = 0;
    // 0x80027EA0: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80027EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80027EAC: jal         0x800268D4
    // 0x80027EB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_34;
    // 0x80027EB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_34:
    // 0x80027EB4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027EB8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80027EBC: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x80027EC0: b           L_80027F10
    // 0x80027EC4: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
        goto L_80027F10;
    // 0x80027EC4: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
L_80027EC8:
    // 0x80027EC8: bne         $at, $zero, L_80027ED4
    if (ctx->r1 != 0) {
        // 0x80027ECC: andi        $t7, $v1, 0x2000
        ctx->r15 = ctx->r3 & 0X2000;
            goto L_80027ED4;
    }
    // 0x80027ECC: andi        $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 & 0X2000;
    // 0x80027ED0: beq         $t7, $zero, L_80027F10
    if (ctx->r15 == 0) {
        // 0x80027ED4: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80027F10;
    }
L_80027ED4:
    // 0x80027ED4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027ED8: sw          $zero, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = 0;
    // 0x80027EDC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027EE0: addiu       $t6, $zero, -0x140
    ctx->r14 = ADD32(0, -0X140);
    // 0x80027EE4: sw          $t6, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r14;
    // 0x80027EE8: ori         $t3, $a3, 0x3000
    ctx->r11 = ctx->r7 | 0X3000;
    // 0x80027EEC: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80027EF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80027EF8: jal         0x800268D4
    // 0x80027EFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_35;
    // 0x80027EFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_35:
    // 0x80027F00: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80027F04: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80027F08: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x80027F0C: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
L_80027F10:
    // 0x80027F10: andi        $t5, $v1, 0x8000
    ctx->r13 = ctx->r3 & 0X8000;
    // 0x80027F14: beq         $t5, $zero, L_800285FC
    if (ctx->r13 == 0) {
        // 0x80027F18: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800285FC;
    }
    // 0x80027F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027F1C: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x80027F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80027F24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80027F28: ori         $t8, $t4, 0x800
    ctx->r24 = ctx->r12 | 0X800;
    // 0x80027F2C: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80027F30: jal         0x800268D4
    // 0x80027F34: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    func_800268D4(rdram, ctx);
        goto after_36;
    // 0x80027F34: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    after_36:
    // 0x80027F38: b           L_800285FC
    // 0x80027F3C: nop

        goto L_800285FC;
    // 0x80027F3C: nop

L_80027F40:
    // 0x80027F40: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80027F44: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x80027F48: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x80027F4C: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x80027F50: beq         $t6, $zero, L_80027F98
    if (ctx->r14 == 0) {
        // 0x80027F54: nop
    
            goto L_80027F98;
    }
    // 0x80027F54: nop

    // 0x80027F58: bne         $a0, $zero, L_80027F98
    if (ctx->r4 != 0) {
        // 0x80027F5C: andi        $t5, $a3, 0xFEFF
        ctx->r13 = ctx->r7 & 0XFEFF;
            goto L_80027F98;
    }
    // 0x80027F5C: andi        $t5, $a3, 0xFEFF
    ctx->r13 = ctx->r7 & 0XFEFF;
    // 0x80027F60: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x80027F64: andi        $t4, $t5, 0xF7FF
    ctx->r12 = ctx->r13 & 0XF7FF;
    // 0x80027F68: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80027F6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027F70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80027F74: jal         0x800268D4
    // 0x80027F78: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_37;
    // 0x80027F78: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_37:
    // 0x80027F7C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80027F80: addiu       $v0, $v0, -0x600
    ctx->r2 = ADD32(ctx->r2, -0X600);
    // 0x80027F84: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80027F88: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80027F8C: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x80027F90: b           L_80028614
    // 0x80027F94: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_80028614;
    // 0x80027F94: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80027F98:
    // 0x80027F98: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80027F9C: lw          $t1, -0x2F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2F0);
    // 0x80027FA0: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80027FA4: andi        $t6, $a3, 0x100
    ctx->r14 = ctx->r7 & 0X100;
    // 0x80027FA8: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80027FAC: andi        $t5, $t3, 0xF
    ctx->r13 = ctx->r11 & 0XF;
    // 0x80027FB0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80027FB4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80027FB8: beq         $a0, $zero, L_8002814C
    if (ctx->r4 == 0) {
        // 0x80027FBC: lb          $t1, -0xF40($at)
        ctx->r9 = MEM_B(ctx->r1, -0XF40);
            goto L_8002814C;
    }
    // 0x80027FBC: lb          $t1, -0xF40($at)
    ctx->r9 = MEM_B(ctx->r1, -0XF40);
    // 0x80027FC0: beq         $t6, $zero, L_80027FDC
    if (ctx->r14 == 0) {
        // 0x80027FC4: lui         $t2, 0x8009
        ctx->r10 = S32(0X8009 << 16);
            goto L_80027FDC;
    }
    // 0x80027FC4: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80027FC8: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80027FCC: beq         $t6, $at, L_80028094
    if (ctx->r14 == ctx->r1) {
        // 0x80027FD0: lui         $t2, 0x8009
        ctx->r10 = S32(0X8009 << 16);
            goto L_80028094;
    }
    // 0x80027FD0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80027FD4: b           L_8002814C
    // 0x80027FD8: nop

        goto L_8002814C;
    // 0x80027FD8: nop

L_80027FDC:
    // 0x80027FDC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80027FE0: lb          $t8, -0x600($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X600);
    // 0x80027FE4: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80027FE8: addiu       $t7, $t7, -0x70C
    ctx->r15 = ADD32(ctx->r15, -0X70C);
    // 0x80027FEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80027FF0: addu        $v1, $t9, $t7
    ctx->r3 = ADD32(ctx->r25, ctx->r15);
    // 0x80027FF4: lw          $t2, -0x2EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EC);
    // 0x80027FF8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80027FFC: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028000: bne         $at, $zero, L_8002814C
    if (ctx->r1 != 0) {
        // 0x80028004: slt         $at, $v0, $t2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002814C;
    }
    // 0x80028004: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80028008: bne         $at, $zero, L_8002814C
    if (ctx->r1 != 0) {
        // 0x8002800C: andi        $t3, $a3, 0xFDFF
        ctx->r11 = ctx->r7 & 0XFDFF;
            goto L_8002814C;
    }
    // 0x8002800C: andi        $t3, $a3, 0xFDFF
    ctx->r11 = ctx->r7 & 0XFDFF;
    // 0x80028010: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80028014: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80028018: andi        $t5, $t3, 0xFBFF
    ctx->r13 = ctx->r11 & 0XFBFF;
    // 0x8002801C: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x80028020: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80028024: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x80028028: addu        $t8, $sp, $t4
    ctx->r24 = ADD32(ctx->r29, ctx->r12);
    // 0x8002802C: lbu         $t8, 0x38($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X38);
    // 0x80028030: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80028034: beq         $at, $zero, L_8002807C
    if (ctx->r1 == 0) {
        // 0x80028038: sw          $t8, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r24;
            goto L_8002807C;
    }
    // 0x80028038: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8002803C: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80028040: bne         $at, $zero, L_8002807C
    if (ctx->r1 != 0) {
        // 0x80028044: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8002807C;
    }
    // 0x80028044: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80028048: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8002804C: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80028050: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80028054: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x80028058: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002805C: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x80028060: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80028064: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80028068: jal         0x80029B58
    // 0x8002806C: addu        $a1, $t2, $t9
    ctx->r5 = ADD32(ctx->r10, ctx->r25);
    func_80029B58(rdram, ctx);
        goto after_38;
    // 0x8002806C: addu        $a1, $t2, $t9
    ctx->r5 = ADD32(ctx->r10, ctx->r25);
    after_38:
    // 0x80028070: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80028074: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80028078: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_8002807C:
    // 0x8002807C: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80028080: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x80028084: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80028088: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8002808C: b           L_8002814C
    // 0x80028090: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
        goto L_8002814C;
    // 0x80028090: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
L_80028094:
    // 0x80028094: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80028098: lb          $t3, -0xFF0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0XFF0);
    // 0x8002809C: lui         $t4, 0x8006
    ctx->r12 = S32(0X8006 << 16);
    // 0x800280A0: addiu       $t4, $t4, -0x6EC
    ctx->r12 = ADD32(ctx->r12, -0X6EC);
    // 0x800280A4: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800280A8: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x800280AC: lw          $t2, -0x2EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EC);
    // 0x800280B0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800280B4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800280B8: bne         $at, $zero, L_8002814C
    if (ctx->r1 != 0) {
        // 0x800280BC: slt         $at, $v0, $t2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8002814C;
    }
    // 0x800280BC: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800280C0: bne         $at, $zero, L_8002814C
    if (ctx->r1 != 0) {
        // 0x800280C4: andi        $t9, $a3, 0xFDFF
        ctx->r25 = ctx->r7 & 0XFDFF;
            goto L_8002814C;
    }
    // 0x800280C4: andi        $t9, $a3, 0xFDFF
    ctx->r25 = ctx->r7 & 0XFDFF;
    // 0x800280C8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800280CC: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800280D0: andi        $t7, $t9, 0xFBFF
    ctx->r15 = ctx->r25 & 0XFBFF;
    // 0x800280D4: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x800280D8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800280DC: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x800280E0: addu        $t3, $sp, $t6
    ctx->r11 = ADD32(ctx->r29, ctx->r14);
    // 0x800280E4: lbu         $t3, 0x38($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X38);
    // 0x800280E8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800280EC: beq         $at, $zero, L_80028134
    if (ctx->r1 == 0) {
        // 0x800280F0: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_80028134;
    }
    // 0x800280F0: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800280F4: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x800280F8: bne         $at, $zero, L_80028134
    if (ctx->r1 != 0) {
        // 0x800280FC: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80028134;
    }
    // 0x800280FC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80028100: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80028104: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80028108: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002810C: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x80028110: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80028114: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x80028118: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8002811C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80028120: jal         0x80029B58
    // 0x80028124: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    func_80029B58(rdram, ctx);
        goto after_39;
    // 0x80028124: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    after_39:
    // 0x80028128: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002812C: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80028130: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80028134:
    // 0x80028134: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80028138: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x8002813C: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80028140: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80028144: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80028148: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
L_8002814C:
    // 0x8002814C: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80028150: bne         $a0, $zero, L_8002841C
    if (ctx->r4 != 0) {
        // 0x80028154: lw          $t2, -0x2EC($t2)
        ctx->r10 = MEM_W(ctx->r10, -0X2EC);
            goto L_8002841C;
    }
    // 0x80028154: lw          $t2, -0x2EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EC);
    // 0x80028158: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002815C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80028160: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80028164: beq         $t7, $zero, L_8002817C
    if (ctx->r15 == 0) {
        // 0x80028168: nop
    
            goto L_8002817C;
    }
    // 0x80028168: nop

    // 0x8002816C: beq         $t7, $at, L_800282C8
    if (ctx->r15 == ctx->r1) {
        // 0x80028170: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800282C8;
    }
    // 0x80028170: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80028174: b           L_8002841C
    // 0x80028178: nop

        goto L_8002841C;
    // 0x80028178: nop

L_8002817C:
    // 0x8002817C: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x80028180: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x80028184: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80028188: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8002818C: bne         $at, $zero, L_800281A0
    if (ctx->r1 != 0) {
        // 0x80028190: andi        $t3, $a3, 0x400
        ctx->r11 = ctx->r7 & 0X400;
            goto L_800281A0;
    }
    // 0x80028190: andi        $t3, $a3, 0x400
    ctx->r11 = ctx->r7 & 0X400;
    // 0x80028194: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80028198: bne         $at, $zero, L_800281F0
    if (ctx->r1 != 0) {
        // 0x8002819C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800281F0;
    }
    // 0x8002819C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_800281A0:
    // 0x800281A0: bne         $t3, $zero, L_8002841C
    if (ctx->r11 != 0) {
        // 0x800281A4: andi        $t4, $a3, 0xFEFF
        ctx->r12 = ctx->r7 & 0XFEFF;
            goto L_8002841C;
    }
    // 0x800281A4: andi        $t4, $a3, 0xFEFF
    ctx->r12 = ctx->r7 & 0XFEFF;
    // 0x800281A8: ori         $t9, $t4, 0x100
    ctx->r25 = ctx->r12 | 0X100;
    // 0x800281AC: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x800281B0: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800281B4: ori         $t7, $t9, 0x400
    ctx->r15 = ctx->r25 | 0X400;
    // 0x800281B8: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x800281BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800281C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800281C4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800281C8: jal         0x800268D4
    // 0x800281CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    func_800268D4(rdram, ctx);
        goto after_40;
    // 0x800281CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_40:
    // 0x800281D0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800281D4: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x800281D8: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x800281DC: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800281E0: lw          $t2, -0x2EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EC);
    // 0x800281E4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800281E8: b           L_8002841C
    // 0x800281EC: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
        goto L_8002841C;
    // 0x800281EC: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
L_800281F0:
    // 0x800281F0: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x800281F4: andi        $t6, $a3, 0x400
    ctx->r14 = ctx->r7 & 0X400;
    // 0x800281F8: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x800281FC: beql        $at, $zero, L_80028258
    if (ctx->r1 == 0) {
        // 0x80028200: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_80028258;
    }
    goto skip_0;
    // 0x80028200: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    skip_0:
    // 0x80028204: bne         $t6, $zero, L_8002841C
    if (ctx->r14 != 0) {
        // 0x80028208: lui         $v0, 0x8006
        ctx->r2 = S32(0X8006 << 16);
            goto L_8002841C;
    }
    // 0x80028208: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8002820C: lb          $v0, -0x600($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X600);
    // 0x80028210: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80028214: lui         $t4, 0x8006
    ctx->r12 = S32(0X8006 << 16);
    // 0x80028218: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8002821C: sb          $t5, -0x600($at)
    MEM_B(-0X600, ctx->r1) = ctx->r13;
    // 0x80028220: lb          $t4, -0x600($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X600);
    // 0x80028224: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80028228: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8002822C: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80028230: bgez        $t4, L_80028240
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80028234: lh          $t2, -0x70C($t2)
        ctx->r10 = MEM_H(ctx->r10, -0X70C);
            goto L_80028240;
    }
    // 0x80028234: lh          $t2, -0x70C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X70C);
    // 0x80028238: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002823C: sb          $zero, -0x600($at)
    MEM_B(-0X600, ctx->r1) = 0;
L_80028240:
    // 0x80028240: ori         $t8, $a3, 0x600
    ctx->r24 = ctx->r7 | 0X600;
    // 0x80028244: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x80028248: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x8002824C: b           L_8002841C
    // 0x80028250: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
        goto L_8002841C;
    // 0x80028250: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80028254: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
L_80028258:
    // 0x80028258: bne         $at, $zero, L_800282B4
    if (ctx->r1 != 0) {
        // 0x8002825C: andi        $t9, $a3, 0x400
        ctx->r25 = ctx->r7 & 0X400;
            goto L_800282B4;
    }
    // 0x8002825C: andi        $t9, $a3, 0x400
    ctx->r25 = ctx->r7 & 0X400;
    // 0x80028260: bne         $t9, $zero, L_800282AC
    if (ctx->r25 != 0) {
        // 0x80028264: lui         $v1, 0x8006
        ctx->r3 = S32(0X8006 << 16);
            goto L_800282AC;
    }
    // 0x80028264: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x80028268: addiu       $v1, $v1, -0x600
    ctx->r3 = ADD32(ctx->r3, -0X600);
    // 0x8002826C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80028270: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80028274: ori         $t4, $a3, 0x600
    ctx->r12 = ctx->r7 | 0X600;
    // 0x80028278: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002827C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80028280: lh          $t2, -0x70C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X70C);
    // 0x80028284: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80028288: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8002828C: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x80028290: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x80028294: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80028298: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8002829C: bne         $at, $zero, L_800282A8
    if (ctx->r1 != 0) {
        // 0x800282A0: andi        $a0, $a3, 0x200
        ctx->r4 = ctx->r7 & 0X200;
            goto L_800282A8;
    }
    // 0x800282A0: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x800282A4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_800282A8:
    // 0x800282A8: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
L_800282AC:
    // 0x800282AC: b           L_8002841C
    // 0x800282B0: nop

        goto L_8002841C;
    // 0x800282B0: nop

L_800282B4:
    // 0x800282B4: andi        $t8, $a3, 0xFBFF
    ctx->r24 = ctx->r7 & 0XFBFF;
    // 0x800282B8: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x800282BC: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x800282C0: b           L_8002841C
    // 0x800282C4: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
        goto L_8002841C;
    // 0x800282C4: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
L_800282C8:
    // 0x800282C8: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x800282CC: addiu       $t9, $zero, 0x65
    ctx->r25 = ADD32(0, 0X65);
    // 0x800282D0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800282D4: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800282D8: bne         $at, $zero, L_800282EC
    if (ctx->r1 != 0) {
        // 0x800282DC: andi        $t7, $a3, 0x400
        ctx->r15 = ctx->r7 & 0X400;
            goto L_800282EC;
    }
    // 0x800282DC: andi        $t7, $a3, 0x400
    ctx->r15 = ctx->r7 & 0X400;
    // 0x800282E0: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800282E4: bne         $at, $zero, L_80028338
    if (ctx->r1 != 0) {
        // 0x800282E8: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80028338;
    }
    // 0x800282E8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_800282EC:
    // 0x800282EC: bne         $t7, $zero, L_8002841C
    if (ctx->r15 != 0) {
        // 0x800282F0: andi        $t5, $a3, 0xFEFF
        ctx->r13 = ctx->r7 & 0XFEFF;
            goto L_8002841C;
    }
    // 0x800282F0: andi        $t5, $a3, 0xFEFF
    ctx->r13 = ctx->r7 & 0XFEFF;
    // 0x800282F4: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x800282F8: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x800282FC: ori         $t4, $t5, 0x400
    ctx->r12 = ctx->r13 | 0X400;
    // 0x80028300: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80028304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002830C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80028310: jal         0x800268D4
    // 0x80028314: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    func_800268D4(rdram, ctx);
        goto after_41;
    // 0x80028314: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_41:
    // 0x80028318: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002831C: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80028320: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80028324: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80028328: lw          $t2, -0x2EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2EC);
    // 0x8002832C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80028330: b           L_8002841C
    // 0x80028334: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
        goto L_8002841C;
    // 0x80028334: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
L_80028338:
    // 0x80028338: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x8002833C: andi        $t8, $a3, 0x400
    ctx->r24 = ctx->r7 & 0X400;
    // 0x80028340: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80028344: beql        $at, $zero, L_800283A8
    if (ctx->r1 == 0) {
        // 0x80028348: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_800283A8;
    }
    goto skip_1;
    // 0x80028348: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    skip_1:
    // 0x8002834C: bne         $t8, $zero, L_8002841C
    if (ctx->r24 != 0) {
        // 0x80028350: lui         $v0, 0x8006
        ctx->r2 = S32(0X8006 << 16);
            goto L_8002841C;
    }
    // 0x80028350: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80028354: lb          $v0, -0xFF0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XFF0);
    // 0x80028358: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002835C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80028360: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80028364: sb          $t7, -0xFF0($at)
    MEM_B(-0XFF0, ctx->r1) = ctx->r15;
    // 0x80028368: lb          $t6, -0xFF0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0XFF0);
    // 0x8002836C: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80028370: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80028374: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80028378: bgez        $t6, L_80028388
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002837C: lh          $t2, -0x6EC($t2)
        ctx->r10 = MEM_H(ctx->r10, -0X6EC);
            goto L_80028388;
    }
    // 0x8002837C: lh          $t2, -0x6EC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6EC);
    // 0x80028380: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80028384: sb          $zero, -0xFF0($at)
    MEM_B(-0XFF0, ctx->r1) = 0;
L_80028388:
    // 0x80028388: ori         $t5, $a3, 0x400
    ctx->r13 = ctx->r7 | 0X400;
    // 0x8002838C: ori         $t4, $t5, 0x200
    ctx->r12 = ctx->r13 | 0X200;
    // 0x80028390: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x80028394: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x80028398: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x8002839C: b           L_8002841C
    // 0x800283A0: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
        goto L_8002841C;
    // 0x800283A0: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x800283A4: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
L_800283A8:
    // 0x800283A8: bne         $at, $zero, L_8002840C
    if (ctx->r1 != 0) {
        // 0x800283AC: andi        $t8, $a3, 0x400
        ctx->r24 = ctx->r7 & 0X400;
            goto L_8002840C;
    }
    // 0x800283AC: andi        $t8, $a3, 0x400
    ctx->r24 = ctx->r7 & 0X400;
    // 0x800283B0: bne         $t8, $zero, L_80028404
    if (ctx->r24 != 0) {
        // 0x800283B4: lui         $v1, 0x8006
        ctx->r3 = S32(0X8006 << 16);
            goto L_80028404;
    }
    // 0x800283B4: lui         $v1, 0x8006
    ctx->r3 = S32(0X8006 << 16);
    // 0x800283B8: addiu       $v1, $v1, -0xFF0
    ctx->r3 = ADD32(ctx->r3, -0XFF0);
    // 0x800283BC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800283C0: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x800283C4: ori         $t4, $a3, 0x400
    ctx->r12 = ctx->r7 | 0X400;
    // 0x800283C8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800283CC: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800283D0: lh          $t2, -0x6EC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6EC);
    // 0x800283D4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800283D8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800283DC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800283E0: ori         $t8, $t4, 0x200
    ctx->r24 = ctx->r12 | 0X200;
    // 0x800283E4: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x800283E8: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800283EC: bne         $at, $zero, L_800283FC
    if (ctx->r1 != 0) {
        // 0x800283F0: andi        $a0, $a3, 0x200
        ctx->r4 = ctx->r7 & 0X200;
            goto L_800283FC;
    }
    // 0x800283F0: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x800283F4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800283F8: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_800283FC:
    // 0x800283FC: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80028400: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
L_80028404:
    // 0x80028404: b           L_8002841C
    // 0x80028408: nop

        goto L_8002841C;
    // 0x80028408: nop

L_8002840C:
    // 0x8002840C: andi        $t9, $a3, 0xFBFF
    ctx->r25 = ctx->r7 & 0XFBFF;
    // 0x80028410: andi        $a3, $t9, 0xFFFF
    ctx->r7 = ctx->r25 & 0XFFFF;
    // 0x80028414: andi        $a0, $a3, 0x200
    ctx->r4 = ctx->r7 & 0X200;
    // 0x80028418: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_8002841C:
    // 0x8002841C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80028420: beq         $a0, $zero, L_800285D8
    if (ctx->r4 == 0) {
        // 0x80028424: sw          $t2, -0x2EC($at)
        MEM_W(-0X2EC, ctx->r1) = ctx->r10;
            goto L_800285D8;
    }
    // 0x80028424: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x80028428: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002842C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80028430: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x80028434: beq         $t7, $zero, L_80028454
    if (ctx->r15 == 0) {
        // 0x80028438: addiu       $a2, $zero, 0x39
        ctx->r6 = ADD32(0, 0X39);
            goto L_80028454;
    }
    // 0x80028438: addiu       $a2, $zero, 0x39
    ctx->r6 = ADD32(0, 0X39);
    // 0x8002843C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80028440: beq         $t7, $at, L_80028514
    if (ctx->r15 == ctx->r1) {
        // 0x80028444: lui         $t3, 0x8006
        ctx->r11 = S32(0X8006 << 16);
            goto L_80028514;
    }
    // 0x80028444: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x80028448: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002844C: b           L_800285D8
    // 0x80028450: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
        goto L_800285D8;
    // 0x80028450: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
L_80028454:
    // 0x80028454: lb          $t6, -0x600($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X600);
    // 0x80028458: addiu       $t5, $t5, -0x70C
    ctx->r13 = ADD32(ctx->r13, -0X70C);
    // 0x8002845C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80028460: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80028464: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80028468: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8002846C: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x80028470: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80028474: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028478: beq         $at, $zero, L_800284A4
    if (ctx->r1 == 0) {
        // 0x8002847C: addu        $a1, $t2, $t4
        ctx->r5 = ADD32(ctx->r10, ctx->r12);
            goto L_800284A4;
    }
    // 0x8002847C: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x80028480: lh          $t9, -0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X2);
    // 0x80028484: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80028488: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002848C: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x80028490: lbu         $t7, 0x38($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X38);
    // 0x80028494: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028498: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x8002849C: b           L_800284F4
    // 0x800284A0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_800284F4;
    // 0x800284A0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_800284A4:
    // 0x800284A4: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800284A8: beq         $at, $zero, L_800284D4
    if (ctx->r1 == 0) {
        // 0x800284AC: nop
    
            goto L_800284D4;
    }
    // 0x800284AC: nop

    // 0x800284B0: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800284B4: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800284B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800284BC: addu        $t3, $sp, $t6
    ctx->r11 = ADD32(ctx->r29, ctx->r14);
    // 0x800284C0: lbu         $t3, 0x38($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X38);
    // 0x800284C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800284C8: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x800284CC: b           L_800284F4
    // 0x800284D0: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_800284F4;
    // 0x800284D0: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_800284D4:
    // 0x800284D4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800284D8: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x800284DC: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x800284E0: andi        $t5, $a3, 0xFBFF
    ctx->r13 = ctx->r7 & 0XFBFF;
    // 0x800284E4: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x800284E8: addu        $t8, $sp, $t4
    ctx->r24 = ADD32(ctx->r29, ctx->r12);
    // 0x800284EC: lbu         $t8, 0x38($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X38);
    // 0x800284F0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_800284F4:
    // 0x800284F4: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800284F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800284FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80028500: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80028504: jal         0x80029B58
    // 0x80028508: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    func_80029B58(rdram, ctx);
        goto after_42;
    // 0x80028508: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_42:
    // 0x8002850C: b           L_800285D8
    // 0x80028510: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
        goto L_800285D8;
    // 0x80028510: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80028514:
    // 0x80028514: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80028518: lb          $t7, -0xFF0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0XFF0);
    // 0x8002851C: addiu       $t3, $t3, -0x6EC
    ctx->r11 = ADD32(ctx->r11, -0X6EC);
    // 0x80028520: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80028524: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80028528: addu        $v1, $t6, $t3
    ctx->r3 = ADD32(ctx->r14, ctx->r11);
    // 0x8002852C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80028530: addiu       $t4, $zero, 0x65
    ctx->r12 = ADD32(0, 0X65);
    // 0x80028534: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x80028538: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002853C: beq         $at, $zero, L_80028568
    if (ctx->r1 == 0) {
        // 0x80028540: addu        $a1, $t2, $t5
        ctx->r5 = ADD32(ctx->r10, ctx->r13);
            goto L_80028568;
    }
    // 0x80028540: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    // 0x80028544: lh          $t8, -0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X2);
    // 0x80028548: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002854C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80028550: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80028554: lbu         $t9, 0x38($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X38);
    // 0x80028558: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002855C: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x80028560: b           L_800285B8
    // 0x80028564: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
        goto L_800285B8;
    // 0x80028564: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80028568:
    // 0x80028568: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002856C: beq         $at, $zero, L_80028598
    if (ctx->r1 == 0) {
        // 0x80028570: nop
    
            goto L_80028598;
    }
    // 0x80028570: nop

    // 0x80028574: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x80028578: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x8002857C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80028580: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x80028584: lbu         $t6, 0x38($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X38);
    // 0x80028588: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002858C: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x80028590: b           L_800285B8
    // 0x80028594: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
        goto L_800285B8;
    // 0x80028594: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_80028598:
    // 0x80028598: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002859C: sw          $t2, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = ctx->r10;
    // 0x800285A0: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x800285A4: andi        $t3, $a3, 0xFBFF
    ctx->r11 = ctx->r7 & 0XFBFF;
    // 0x800285A8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x800285AC: addu        $t4, $sp, $t5
    ctx->r12 = ADD32(ctx->r29, ctx->r13);
    // 0x800285B0: lbu         $t4, 0x38($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X38);
    // 0x800285B4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_800285B8:
    // 0x800285B8: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800285BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800285C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800285C4: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x800285C8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800285CC: jal         0x80029B58
    // 0x800285D0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    func_80029B58(rdram, ctx);
        goto after_43;
    // 0x800285D0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_43:
    // 0x800285D4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_800285D8:
    // 0x800285D8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800285DC: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x800285E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800285E4: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    // 0x800285E8: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    // 0x800285EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800285F0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800285F4: jal         0x80029B58
    // 0x800285F8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80029B58(rdram, ctx);
        goto after_44;
    // 0x800285F8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_44:
L_800285FC:
    // 0x800285FC: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80028600: addiu       $v0, $v0, -0x600
    ctx->r2 = ADD32(ctx->r2, -0X600);
    // 0x80028604: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80028608: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8002860C: subu        $t5, $t3, $t6
    ctx->r13 = SUB32(ctx->r11, ctx->r14);
    // 0x80028610: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
L_80028614:
    // 0x80028614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028618: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002861C: jr          $ra
    // 0x80028620: nop

    return;
    // 0x80028620: nop

;}
RECOMP_FUNC void guOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035994: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035998: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8003599C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800359A0: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800359A4: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800359A8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800359AC: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800359B0: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800359B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800359B8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800359BC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800359C0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800359C4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800359C8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800359CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800359D0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800359D4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800359D8: jal         0x80035840
    // 0x800359DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrthoF(rdram, ctx);
        goto after_0;
    // 0x800359DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800359E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800359E4: jal         0x80035200
    // 0x800359E8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800359E8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800359EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800359F0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800359F4: jr          $ra
    // 0x800359F8: nop

    return;
    // 0x800359F8: nop

    // 0x800359FC: nop

;}
RECOMP_FUNC void func_80101180_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101180: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101184: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101188: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8010118C: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80101190: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101194: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101198: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8010119C: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x801011A0: bltzl       $t9, L_801011B4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801011A4: lw          $v1, 0x38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X38);
            goto L_801011B4;
    }
    goto skip_0;
    // 0x801011A4: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x801011A8: jr          $ra
    // 0x801011AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801011AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801011B0: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
L_801011B4:
    // 0x801011B4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801011B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801011BC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801011C0: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801011C4: lhu         $t0, 0x32($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X32);
    // 0x801011C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801011CC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801011D0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801011D4: sh          $t1, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r9;
    // 0x801011D8: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801011DC: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x801011E0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801011E4: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x801011E8: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801011EC: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x801011F0: nop

    // 0x801011F4: bc1tl       L_80101208
    if (c1cs) {
        // 0x801011F8: swc1        $f12, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
            goto L_80101208;
    }
    goto skip_1;
    // 0x801011F8: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x801011FC: bne         $at, $zero, L_8010120C
    if (ctx->r1 != 0) {
        // 0x80101200: nop
    
            goto L_8010120C;
    }
    // 0x80101200: nop

    // 0x80101204: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
L_80101208:
    // 0x80101208: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
L_8010120C:
    // 0x8010120C: bnel        $a1, $zero, L_80101228
    if (ctx->r5 != 0) {
        // 0x80101210: sub.s       $f18, $f12, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80101228;
    }
    goto skip_2;
    // 0x80101210: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x80101214: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80101218: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8010121C: b           L_80101238
    // 0x80101220: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
        goto L_80101238;
    // 0x80101220: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
    // 0x80101224: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
L_80101228:
    // 0x80101228: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010122C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80101230: nop

    // 0x80101234: sh          $t6, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r14;
L_80101238:
    // 0x80101238: lhu         $t7, 0x32($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X32);
    // 0x8010123C: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x80101240: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80101244: bnel        $at, $zero, L_8010127C
    if (ctx->r1 != 0) {
        // 0x80101248: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010127C;
    }
    goto skip_3;
    // 0x80101248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8010124C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80101250: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80101254: bne         $a1, $zero, L_8010126C
    if (ctx->r5 != 0) {
        // 0x80101258: swc1        $f6, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
            goto L_8010126C;
    }
    // 0x80101258: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x8010125C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80101260: sh          $t9, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r25;
    // 0x80101264: jr          $ra
    // 0x80101268: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101268: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8010126C:
    // 0x8010126C: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x80101270: jr          $ra
    // 0x80101274: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101274: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010127C:
    // 0x8010127C: jr          $ra
    // 0x80101280: nop

    return;
    // 0x80101280: nop

;}
RECOMP_FUNC void func_80023360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023360: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023364: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80023368: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002336C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80023370: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80023374: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023378: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8002337C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80023380: jal         0x80035680
    // 0x80023384: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023384: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80023388: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8002338C: jal         0x800361F0
    // 0x80023390: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80023390: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80023394: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80023398: jal         0x80035680
    // 0x8002339C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002339C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x800233A0: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800233A4: jal         0x800361F0
    // 0x800233A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800233A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800233AC: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800233B0: jal         0x80035680
    // 0x800233B4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800233B4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800233B8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800233BC: jal         0x800361F0
    // 0x800233C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800233C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800233C4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800233C8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800233CC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800233D0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800233D4: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800233D8: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800233DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800233E0: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800233E4: nop

    // 0x800233E8: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800233EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800233F0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800233F4: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x800233F8: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800233FC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80023400: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80023404: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80023408: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8002340C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023410: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80023414: nop

    // 0x80023418: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8002341C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023420: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023424: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80023428: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002342C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80023430: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80023434: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023438: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8002343C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023440: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023444: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80023448: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8002344C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023450: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023454: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80023458: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002345C: nop

    // 0x80023460: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80023464: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80023468: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002346C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80023470: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023474: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023478: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002347C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80023480: nop

    // 0x80023484: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80023488: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002348C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023490: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80023494: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x80023498: mul.s       $f6, $f20, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8002349C: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800234A0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800234A4: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800234A8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800234AC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800234B0: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800234B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800234B8: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800234BC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x800234C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800234C4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800234C8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800234CC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x800234D0: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800234D4: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x800234D8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800234DC: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800234E0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800234E4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x800234E8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x800234EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800234F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800234F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800234F8: jr          $ra
    // 0x800234FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800234FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80026488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026488: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002648C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80026490: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80026494: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80026498: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002649C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800264A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800264A4: lui         $s0, 0x8005
    ctx->r16 = S32(0X8005 << 16);
    // 0x800264A8: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800264AC: lui         $s4, 0x8005
    ctx->r20 = S32(0X8005 << 16);
    // 0x800264B0: addiu       $s4, $s4, 0x39BC
    ctx->r20 = ADD32(ctx->r20, 0X39BC);
    // 0x800264B4: addiu       $s1, $s1, 0x39A8
    ctx->r17 = ADD32(ctx->r17, 0X39A8);
    // 0x800264B8: addiu       $s0, $s0, 0x3994
    ctx->r16 = ADD32(ctx->r16, 0X3994);
    // 0x800264BC: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x800264C0: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
L_800264C4:
    // 0x800264C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800264C8: beql        $a0, $s2, L_800264DC
    if (ctx->r4 == ctx->r18) {
        // 0x800264CC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800264DC;
    }
    goto skip_0;
    // 0x800264CC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x800264D0: jal         0x8002568C
    // 0x800264D4: nop

    func_8002568C(rdram, ctx);
        goto after_0;
    // 0x800264D4: nop

    after_0:
    // 0x800264D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800264DC:
    // 0x800264DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800264E0: sw          $zero, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = 0;
    // 0x800264E4: bne         $s1, $s4, L_800264C4
    if (ctx->r17 != ctx->r20) {
        // 0x800264E8: sw          $s3, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r19;
            goto L_800264C4;
    }
    // 0x800264E8: sw          $s3, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r19;
    // 0x800264EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800264F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800264F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800264F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800264FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80026500: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80026504: jr          $ra
    // 0x80026508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80026508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800156D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800156D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800156D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800156D8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800156DC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800156E0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800156E4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800156E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800156EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800156F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800156F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800156F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800156FC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80015700: addiu       $s0, $s0, 0x7170
    ctx->r16 = ADD32(ctx->r16, 0X7170);
    // 0x80015704: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
L_80015708:
    // 0x80015708: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x8001570C: beql        $t6, $zero, L_80015768
    if (ctx->r14 == 0) {
        // 0x80015710: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_80015768;
    }
    goto skip_0;
    // 0x80015710: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    skip_0:
    // 0x80015714: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x80015718: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001571C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80015720: bne         $t9, $zero, L_80015764
    if (ctx->r25 != 0) {
        // 0x80015724: sh          $t8, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r24;
            goto L_80015764;
    }
    // 0x80015724: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x80015728: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x8001572C: lhu         $t2, 0x4($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X4);
    // 0x80015730: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80015734: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80015738: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001573C: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80015740: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x80015744: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x80015748: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8001574C: jal         0x80014A98
    // 0x80015750: lhu         $a3, 0xC($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0XC);
    func_80014A98(rdram, ctx);
        goto after_0;
    // 0x80015750: lhu         $a3, 0xC($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0XC);
    after_0:
    // 0x80015754: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x80015758: lhu         $t5, 0x22($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X22);
    // 0x8001575C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80015760: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_80015764:
    // 0x80015764: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_80015768:
    // 0x80015768: bne         $s7, $zero, L_80015708
    if (ctx->r23 != 0) {
        // 0x8001576C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80015708;
    }
    // 0x8001576C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80015770: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80015774: addiu       $s2, $s2, 0x6F18
    ctx->r18 = ADD32(ctx->r18, 0X6F18);
    // 0x80015778: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001577C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80015780: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_80015784:
    // 0x80015784: lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X4);
    // 0x80015788: beql        $v0, $zero, L_80015A9C
    if (ctx->r2 == 0) {
        // 0x8001578C: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80015A9C;
    }
    goto skip_1;
    // 0x8001578C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_1:
    // 0x80015790: lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X8);
    // 0x80015794: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80015798: beq         $v1, $zero, L_800157A8
    if (ctx->r3 == 0) {
        // 0x8001579C: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800157A8;
    }
    // 0x8001579C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800157A0: b           L_800159D0
    // 0x800157A4: sh          $t7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r15;
        goto L_800159D0;
    // 0x800157A4: sh          $t7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r15;
L_800157A8:
    // 0x800157A8: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x800157AC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800157B0: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x800157B4: lhu         $t0, 0x12($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X12);
    // 0x800157B8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x800157BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800157C0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800157C4: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x800157C8: lw          $t9, -0x32FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X32FC);
    // 0x800157CC: jalr        $t9
    // 0x800157D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800157D0: nop

    after_1:
    // 0x800157D4: lw          $t2, 0x2C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X2C);
    // 0x800157D8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x800157DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800157E0: lhu         $t3, 0x16($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X16);
    // 0x800157E4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800157E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800157EC: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x800157F0: lw          $t9, -0x32F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X32F0);
    // 0x800157F4: jalr        $t9
    // 0x800157F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800157F8: nop

    after_2:
    // 0x800157FC: beq         $v0, $zero, L_800159D0
    if (ctx->r2 == 0) {
        // 0x80015800: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800159D0;
    }
    // 0x80015800: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80015804: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80015808: jal         0x8001829C
    // 0x8001580C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001829C(rdram, ctx);
        goto after_3;
    // 0x8001580C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80015810: lw          $t5, 0x68($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X68);
    // 0x80015814: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015818: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8001581C: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80015820: beq         $t7, $zero, L_8001583C
    if (ctx->r15 == 0) {
        // 0x80015824: nop
    
            goto L_8001583C;
    }
    // 0x80015824: nop

    // 0x80015828: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x8001582C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80015830: lhu         $t0, 0x18($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X18);
    // 0x80015834: bnel        $t0, $at, L_8001596C
    if (ctx->r8 != ctx->r1) {
        // 0x80015838: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8001596C;
    }
    goto skip_2;
    // 0x80015838: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_8001583C:
    // 0x8001583C: jal         0x800183C4
    // 0x80015840: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800183C4(rdram, ctx);
        goto after_4;
    // 0x80015840: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80015844: beql        $v0, $zero, L_8001589C
    if (ctx->r2 == 0) {
        // 0x80015848: lw          $t3, 0x2C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X2C);
            goto L_8001589C;
    }
    goto skip_3;
    // 0x80015848: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
    skip_3:
    // 0x8001584C: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x80015850: bnel        $s5, $a0, L_8001586C
    if (ctx->r21 != ctx->r4) {
        // 0x80015854: lhu         $t1, 0x5E($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X5E);
            goto L_8001586C;
    }
    goto skip_4;
    // 0x80015854: lhu         $t1, 0x5E($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X5E);
    skip_4:
    // 0x80015858: jal         0x800208B8
    // 0x8001585C: nop

    func_800208B8(rdram, ctx);
        goto after_5;
    // 0x8001585C: nop

    after_5:
    // 0x80015860: b           L_8001596C
    // 0x80015864: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8001596C;
    // 0x80015864: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015868: lhu         $t1, 0x5E($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X5E);
L_8001586C:
    // 0x8001586C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80015870: beq         $t2, $zero, L_80015888
    if (ctx->r10 == 0) {
        // 0x80015874: nop
    
            goto L_80015888;
    }
    // 0x80015874: nop

    // 0x80015878: jal         0x8000B110
    // 0x8001587C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000B110(rdram, ctx);
        goto after_6;
    // 0x8001587C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80015880: b           L_8001596C
    // 0x80015884: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8001596C;
    // 0x80015884: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80015888:
    // 0x80015888: jal         0x80006F6C
    // 0x8001588C: nop

    func_80006F6C(rdram, ctx);
        goto after_7;
    // 0x8001588C: nop

    after_7:
    // 0x80015890: b           L_8001596C
    // 0x80015894: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8001596C;
    // 0x80015894: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015898: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
L_8001589C:
    // 0x8001589C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800158A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800158A4: lhu         $t4, 0x10($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X10);
    // 0x800158A8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800158AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800158B0: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x800158B4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800158B8: lw          $t9, -0x32E4($at)
    ctx->r25 = MEM_W(ctx->r1, -0X32E4);
    // 0x800158BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800158C0: jalr        $t9
    // 0x800158C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800158C4: nop

    after_8:
    // 0x800158C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800158CC: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
L_800158D0:
    // 0x800158D0: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x800158D4: lbu         $t6, 0x32($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X32);
    // 0x800158D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800158DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800158E0: beql        $t6, $zero, L_80015938
    if (ctx->r14 == 0) {
        // 0x800158E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80015938;
    }
    goto skip_5;
    // 0x800158E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x800158E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800158EC: jal         0x80018484
    // 0x800158F0: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    func_80018484(rdram, ctx);
        goto after_9;
    // 0x800158F0: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    after_9:
    // 0x800158F4: beq         $v0, $zero, L_80015934
    if (ctx->r2 == 0) {
        // 0x800158F8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80015934;
    }
    // 0x800158F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800158FC: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80015900: addiu       $t8, $t8, -0x32BC
    ctx->r24 = ADD32(ctx->r24, -0X32BC);
    // 0x80015904: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80015908: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8001590C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80015910: jal         0x80018524
    // 0x80015914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80018524(rdram, ctx);
        goto after_10;
    // 0x80015914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x80015918: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    // 0x8001591C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80015920: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80015924: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80015928: jalr        $t9
    // 0x8001592C: lbu         $a0, 0x32($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X32);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8001592C: lbu         $a0, 0x32($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X32);
    after_11:
    // 0x80015930: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80015934:
    // 0x80015934: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80015938:
    // 0x80015938: bne         $s0, $s6, L_800158D0
    if (ctx->r16 != ctx->r22) {
        // 0x8001593C: lw          $v0, 0x2C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X2C);
            goto L_800158D0;
    }
    // 0x8001593C: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    // 0x80015940: lhu         $t2, 0x10($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X10);
    // 0x80015944: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80015948: bnel        $t2, $at, L_8001596C
    if (ctx->r10 != ctx->r1) {
        // 0x8001594C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8001596C;
    }
    goto skip_6;
    // 0x8001594C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
    // 0x80015950: beql        $s4, $zero, L_8001596C
    if (ctx->r20 == 0) {
        // 0x80015954: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8001596C;
    }
    goto skip_7;
    // 0x80015954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_7:
    // 0x80015958: bnel        $s3, $zero, L_8001596C
    if (ctx->r19 != 0) {
        // 0x8001595C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8001596C;
    }
    goto skip_8;
    // 0x8001595C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_8:
    // 0x80015960: jal         0x800208B8
    // 0x80015964: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800208B8(rdram, ctx);
        goto after_12;
    // 0x80015964: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x80015968: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8001596C:
    // 0x8001596C: jal         0x80017D04
    // 0x80015970: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80017D04(rdram, ctx);
        goto after_13;
    // 0x80015970: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_13:
    // 0x80015974: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
    // 0x80015978: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x8001597C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80015980: bnel        $t5, $zero, L_800159C8
    if (ctx->r13 != 0) {
        // 0x80015984: lhu         $t9, 0xA($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0XA);
            goto L_800159C8;
    }
    goto skip_9;
    // 0x80015984: lhu         $t9, 0xA($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0XA);
    skip_9:
    // 0x80015988: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x8001598C: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x80015990: beql        $v0, $zero, L_800159D4
    if (ctx->r2 == 0) {
        // 0x80015994: lw          $v0, 0x34($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X34);
            goto L_800159D4;
    }
    goto skip_10;
    // 0x80015994: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    skip_10:
    // 0x80015998: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8001599C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800159A0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800159A4: beql        $t7, $zero, L_800159D4
    if (ctx->r15 == 0) {
        // 0x800159A8: lw          $v0, 0x34($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X34);
            goto L_800159D4;
    }
    goto skip_11;
    // 0x800159A8: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    skip_11:
    // 0x800159AC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800159B0: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x800159B4: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x800159B8: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x800159BC: b           L_800159D0
    // 0x800159C0: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
        goto L_800159D0;
    // 0x800159C0: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x800159C4: lhu         $t9, 0xA($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0XA);
L_800159C8:
    // 0x800159C8: ori         $t2, $t9, 0x2
    ctx->r10 = ctx->r25 | 0X2;
    // 0x800159CC: sh          $t2, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r10;
L_800159D0:
    // 0x800159D0: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
L_800159D4:
    // 0x800159D4: beql        $v0, $zero, L_80015A5C
    if (ctx->r2 == 0) {
        // 0x800159D8: lw          $v0, 0x30($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X30);
            goto L_80015A5C;
    }
    goto skip_12;
    // 0x800159D8: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    skip_12:
    // 0x800159DC: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800159E0: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800159E4: lw          $t3, 0x34($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X34);
    // 0x800159E8: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800159EC: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x800159F0: lw          $t4, 0x34($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X34);
    // 0x800159F4: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800159F8: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x800159FC: lw          $t5, 0x34($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X34);
    // 0x80015A00: lwc1        $f10, 0x18($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80015A04: swc1        $f10, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f10.u32l;
    // 0x80015A08: lw          $t6, 0x34($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X34);
    // 0x80015A0C: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x80015A10: swc1        $f16, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f16.u32l;
    // 0x80015A14: lw          $t7, 0x34($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X34);
    // 0x80015A18: lwc1        $f18, 0x20($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80015A1C: swc1        $f18, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f18.u32l;
    // 0x80015A20: lhu         $t8, 0x4($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X4);
    // 0x80015A24: bnel        $t8, $zero, L_80015A5C
    if (ctx->r24 != 0) {
        // 0x80015A28: lw          $v0, 0x30($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X30);
            goto L_80015A5C;
    }
    goto skip_13;
    // 0x80015A28: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    skip_13:
    // 0x80015A2C: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80015A30: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80015A34: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x80015A38: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80015A3C: beql        $t1, $zero, L_80015A5C
    if (ctx->r9 == 0) {
        // 0x80015A40: lw          $v0, 0x30($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X30);
            goto L_80015A5C;
    }
    goto skip_14;
    // 0x80015A40: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    skip_14:
    // 0x80015A44: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80015A48: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80015A4C: lhu         $t2, 0x8($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X8);
    // 0x80015A50: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80015A54: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x80015A58: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
L_80015A5C:
    // 0x80015A5C: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x80015A60: bltzl       $t4, L_80015A9C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80015A64: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80015A9C;
    }
    goto skip_15;
    // 0x80015A64: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_15:
    // 0x80015A68: lhu         $s0, 0x12($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X12);
    // 0x80015A6C: lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X6);
    // 0x80015A70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015A74: sra         $t5, $s0, 8
    ctx->r13 = S32(SIGNED(ctx->r16) >> 8);
    // 0x80015A78: sltu        $at, $v1, $t5
    ctx->r1 = ctx->r3 < ctx->r13 ? 1 : 0;
    // 0x80015A7C: bne         $at, $zero, L_80015A94
    if (ctx->r1 != 0) {
        // 0x80015A80: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_80015A94;
    }
    // 0x80015A80: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80015A84: jal         0x80017BD4
    // 0x80015A88: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    func_80017BD4(rdram, ctx);
        goto after_14;
    // 0x80015A88: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    after_14:
    // 0x80015A8C: b           L_80015A98
    // 0x80015A90: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
        goto L_80015A98;
    // 0x80015A90: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
L_80015A94:
    // 0x80015A94: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
L_80015A98:
    // 0x80015A98: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80015A9C:
    // 0x80015A9C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80015AA0: bne         $s7, $at, L_80015784
    if (ctx->r23 != ctx->r1) {
        // 0x80015AA4: addiu       $s2, $s2, 0x3C
        ctx->r18 = ADD32(ctx->r18, 0X3C);
            goto L_80015784;
    }
    // 0x80015AA4: addiu       $s2, $s2, 0x3C
    ctx->r18 = ADD32(ctx->r18, 0X3C);
    // 0x80015AA8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015AAC: addiu       $v1, $v1, 0x6F10
    ctx->r3 = ADD32(ctx->r3, 0X6F10);
    // 0x80015AB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80015AB4: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80015AB8: beql        $t7, $zero, L_80015AE4
    if (ctx->r15 == 0) {
        // 0x80015ABC: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_80015AE4;
    }
    goto skip_16;
    // 0x80015ABC: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    skip_16:
    // 0x80015AC0: bne         $fp, $zero, L_80015AE0
    if (ctx->r30 != 0) {
        // 0x80015AC4: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80015AE0;
    }
    // 0x80015AC4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015AC8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015ACC: addiu       $v0, $v0, 0x6F14
    ctx->r2 = ADD32(ctx->r2, 0X6F14);
    // 0x80015AD0: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80015AD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80015AD8: b           L_80015B20
    // 0x80015ADC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_80015B20;
    // 0x80015ADC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80015AE0:
    // 0x80015AE0: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
L_80015AE4:
    // 0x80015AE4: beq         $t1, $zero, L_80015B20
    if (ctx->r9 == 0) {
        // 0x80015AE8: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80015B20;
    }
    // 0x80015AE8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015AEC: addiu       $v0, $v0, 0x6F14
    ctx->r2 = ADD32(ctx->r2, 0X6F14);
    // 0x80015AF0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80015AF4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015AF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80015AFC: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80015B00: bne         $t2, $zero, L_80015B20
    if (ctx->r10 != 0) {
        // 0x80015B04: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_80015B20;
    }
    // 0x80015B04: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80015B08: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80015B0C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80015B10: addiu       $a3, $a3, -0x4108
    ctx->r7 = ADD32(ctx->r7, -0X4108);
    // 0x80015B14: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    // 0x80015B18: jal         0x800111A4
    // 0x80015B1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800111A4(rdram, ctx);
        goto after_15;
    // 0x80015B1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_15:
L_80015B20:
    // 0x80015B20: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80015B24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015B28: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80015B2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80015B30: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80015B34: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80015B38: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80015B3C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80015B40: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80015B44: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80015B48: jr          $ra
    // 0x80015B4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80015B4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800120C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800120C0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800120C4: addiu       $a2, $a2, -0x3A90
    ctx->r6 = ADD32(ctx->r6, -0X3A90);
    // 0x800120C8: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x800120CC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800120D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800120D4: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x800120D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800120DC: lw          $v0, -0x66AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X66AC);
    // 0x800120E0: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x800120E4: sb          $a3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r7;
    // 0x800120E8: sb          $t7, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r15;
    // 0x800120EC: sb          $a3, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r7;
    // 0x800120F0: sb          $a3, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r7;
    // 0x800120F4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800120F8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800120FC: addiu       $v1, $v1, -0x3A8C
    ctx->r3 = ADD32(ctx->r3, -0X3A8C);
    // 0x80012100: beq         $t0, $a1, L_80012120
    if (ctx->r8 == ctx->r5) {
        // 0x80012104: lui         $a0, 0x8005
        ctx->r4 = S32(0X8005 << 16);
            goto L_80012120;
    }
    // 0x80012104: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80012108: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
L_8001210C:
    // 0x8001210C: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80012110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80012114: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80012118: bnel        $t0, $a1, L_8001210C
    if (ctx->r8 != ctx->r5) {
        // 0x8001211C: sb          $a1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r5;
            goto L_8001210C;
    }
    goto skip_0;
    // 0x8001211C: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    skip_0:
L_80012120:
    // 0x80012120: addiu       $v0, $a0, -0x3BA0
    ctx->r2 = ADD32(ctx->r4, -0X3BA0);
    // 0x80012124: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80012128: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8001212C: addiu       $t9, $t9, -0x3BA0
    ctx->r25 = ADD32(ctx->r25, -0X3BA0);
    // 0x80012130: beql        $t0, $t8, L_80012158
    if (ctx->r8 == ctx->r24) {
        // 0x80012134: lbu         $t1, 0x0($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X0);
            goto L_80012158;
    }
    goto skip_1;
    // 0x80012134: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    skip_1:
    // 0x80012138: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    // 0x8001213C: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
L_80012140:
    // 0x80012140: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80012144: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80012148: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001214C: bnel        $t0, $a1, L_80012140
    if (ctx->r8 != ctx->r5) {
        // 0x80012150: sb          $a1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r5;
            goto L_80012140;
    }
    goto skip_2;
    // 0x80012150: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    skip_2:
    // 0x80012154: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
L_80012158:
    // 0x80012158: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8001215C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012160: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80012164: sb          $t2, -0x3690($at)
    MEM_B(-0X3690, ctx->r1) = ctx->r10;
    // 0x80012168: jr          $ra
    // 0x8001216C: nop

    return;
    // 0x8001216C: nop

;}
RECOMP_FUNC void func_80011768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011768: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001176C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80011770: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80011774: sb          $t6, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r14;
    // 0x80011778: lw          $t7, -0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X8);
    // 0x8001177C: sb          $t7, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r15;
    // 0x80011780: lw          $t8, -0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X4);
    // 0x80011784: sb          $t8, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r24;
    // 0x80011788: lb          $v0, 0x3($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X3);
    // 0x8001178C: sb          $v0, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r2;
    // 0x80011790: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x80011794: lb          $v0, 0x7($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X7);
    // 0x80011798: sb          $v0, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r2;
    // 0x8001179C: sb          $v0, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r2;
    // 0x800117A0: lb          $v0, 0xB($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XB);
    // 0x800117A4: sb          $v0, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r2;
    // 0x800117A8: sb          $v0, 0x32($a0)
    MEM_B(0X32, ctx->r4) = ctx->r2;
    // 0x800117AC: lbu         $v0, -0x15($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X15);
    // 0x800117B0: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x800117B4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800117B8: lbu         $v0, -0x11($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X11);
    // 0x800117BC: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x800117C0: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x800117C4: lbu         $v0, -0xD($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0XD);
    // 0x800117C8: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x800117CC: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x800117D0: lbu         $v0, -0x9($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X9);
    // 0x800117D4: sb          $v0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r2;
    // 0x800117D8: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x800117DC: lbu         $v0, -0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X5);
    // 0x800117E0: sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // 0x800117E4: sb          $v0, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r2;
    // 0x800117E8: lbu         $v0, -0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X1);
    // 0x800117EC: sb          $v0, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r2;
    // 0x800117F0: sb          $v0, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r2;
    // 0x800117F4: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x800117F8: sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // 0x800117FC: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // 0x80011800: lbu         $v0, 0x7($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X7);
    // 0x80011804: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x80011808: sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    // 0x8001180C: lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB);
    // 0x80011810: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x80011814: sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
    // 0x80011818: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x8001181C: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
    // 0x80011820: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80011824: lbu         $v0, 0x7($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X7);
    // 0x80011828: sb          $v0, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r2;
    // 0x8001182C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80011830: lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB);
    // 0x80011834: sb          $v0, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r2;
    // 0x80011838: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x8001183C: jr          $ra
    // 0x80011840: nop

    return;
    // 0x80011840: nop

    // 0x80011844: nop

    // 0x80011848: nop

    // 0x8001184C: nop

;}
RECOMP_FUNC void func_80018D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018D34: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80018D38: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80018D3C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018D40: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80018D44: bne         $t6, $zero, L_80018D60
    if (ctx->r14 != 0) {
        // 0x80018D48: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80018D60;
    }
    // 0x80018D48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80018D4C: sra         $t7, $v1, 2
    ctx->r15 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80018D50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80018D54: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80018D58: lw          $t9, -0x30A4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X30A4);
    // 0x80018D5C: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
L_80018D60:
    // 0x80018D60: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80018D64: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80018D68: lwc1        $f0, -0x3098($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3098);
    // 0x80018D6C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80018D70: addiu       $a2, $a2, -0x4D04
    ctx->r6 = ADD32(ctx->r6, -0X4D04);
    // 0x80018D74: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80018D78: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80018D7C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80018D80: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80018D84: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80018D88: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x80018D8C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80018D90: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80018D94: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x80018D98: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80018D9C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80018DA0: lbu         $t5, -0x3068($t4)
    ctx->r13 = MEM_BU(ctx->r12, -0X3068);
    // 0x80018DA4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80018DA8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80018DAC: jr          $ra
    // 0x80018DB0: nop

    return;
    // 0x80018DB0: nop

;}
RECOMP_FUNC void func_80009588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009588: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000958C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80009590: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009594: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009598: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8000959C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800095A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800095A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800095A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800095AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800095B0: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x800095B4: jal         0x8000A3F4
    // 0x800095B8: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    func_8000A3F4(rdram, ctx);
        goto after_0;
    // 0x800095B8: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    after_0:
    // 0x800095BC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800095C0: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x800095C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800095C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800095CC: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x800095D0: beq         $t7, $zero, L_80009600
    if (ctx->r15 == 0) {
        // 0x800095D4: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_80009600;
    }
    // 0x800095D4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800095D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800095DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800095E0: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    // 0x800095E4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800095E8: lwc1        $f6, 0x1158($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1158);
    // 0x800095EC: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800095F0: jal         0x800232F4
    // 0x800095F4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x800095F4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    after_1:
    // 0x800095F8: b           L_80009608
    // 0x800095FC: nop

        goto L_80009608;
    // 0x800095FC: nop

L_80009600:
    // 0x80009600: jal         0x8000A7D8
    // 0x80009604: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_2;
    // 0x80009604: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_2:
L_80009608:
    // 0x80009608: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000960C: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009610: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009614: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009618: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000961C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009620: jal         0x8000A508
    // 0x80009624: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_3;
    // 0x80009624: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80009628: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8000962C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80009630: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80009634: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80009638: bnel        $t0, $zero, L_80009808
    if (ctx->r8 != 0) {
        // 0x8000963C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009808;
    }
    goto skip_0;
    // 0x8000963C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80009640: lhu         $t1, 0x4($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4);
    // 0x80009644: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x80009648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000964C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80009650: beq         $t3, $zero, L_80009750
    if (ctx->r11 == 0) {
        // 0x80009654: sh          $t2, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r10;
            goto L_80009750;
    }
    // 0x80009654: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80009658: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000965C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80009660: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80009664: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80009668: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000966C: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80009670: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80009674: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80009678: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000967C: nop

    // 0x80009680: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009684: jal         0x80034F60
    // 0x80009688: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_4;
    // 0x80009688: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x8000968C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80009690: lw          $t4, -0x44D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X44D0);
    // 0x80009694: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80009698: lwc1        $f10, -0x4510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x8000969C: lwc1        $f8, 0x18($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800096A0: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800096A4: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800096A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800096AC: lwc1        $f18, 0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800096B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800096B4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800096B8: sub.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800096BC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800096C0: nop

    // 0x800096C4: bc1fl       L_800096E0
    if (!c1cs) {
        // 0x800096C8: lhu         $t5, 0x4($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X4);
            goto L_800096E0;
    }
    goto skip_1;
    // 0x800096C8: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    skip_1:
    // 0x800096CC: jal         0x8000A284
    // 0x800096D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A284(rdram, ctx);
        goto after_5;
    // 0x800096D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800096D4: b           L_80009808
    // 0x800096D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009808;
    // 0x800096D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800096DC: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
L_800096E0:
    // 0x800096E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800096E4: beq         $t5, $zero, L_80009700
    if (ctx->r13 == 0) {
        // 0x800096E8: nop
    
            goto L_80009700;
    }
    // 0x800096E8: nop

    // 0x800096EC: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x800096F0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800096F4: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800096F8: beq         $t7, $zero, L_80009710
    if (ctx->r15 == 0) {
        // 0x800096FC: nop
    
            goto L_80009710;
    }
    // 0x800096FC: nop

L_80009700:
    // 0x80009700: jal         0x8000A284
    // 0x80009704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A284(rdram, ctx);
        goto after_6;
    // 0x80009704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80009708: b           L_80009808
    // 0x8000970C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009808;
    // 0x8000970C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009710:
    // 0x80009710: lhu         $t8, -0x3A6E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3A6E);
    // 0x80009714: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80009718: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000971C: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80009720: beql        $t9, $zero, L_80009738
    if (ctx->r25 == 0) {
        // 0x80009724: lh          $t3, 0xE($t2)
        ctx->r11 = MEM_H(ctx->r10, 0XE);
            goto L_80009738;
    }
    goto skip_2;
    // 0x80009724: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
    skip_2:
    // 0x80009728: lh          $t1, 0xE($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XE);
    // 0x8000972C: b           L_80009804
    // 0x80009730: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
        goto L_80009804;
    // 0x80009730: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80009734: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
L_80009738:
    // 0x80009738: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8000973C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80009740: mflo        $t4
    ctx->r12 = lo;
    // 0x80009744: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x80009748: b           L_80009808
    // 0x8000974C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009808;
    // 0x8000974C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009750:
    // 0x80009750: jal         0x8000A008
    // 0x80009754: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A008(rdram, ctx);
        goto after_7;
    // 0x80009754: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80009758: beq         $v0, $zero, L_80009774
    if (ctx->r2 == 0) {
        // 0x8000975C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80009774;
    }
    // 0x8000975C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80009760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009764: jal         0x8000A284
    // 0x80009768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A284(rdram, ctx);
        goto after_8;
    // 0x80009768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x8000976C: b           L_80009808
    // 0x80009770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009808;
    // 0x80009770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009774:
    // 0x80009774: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x80009778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000977C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009780: beq         $t5, $zero, L_8000979C
    if (ctx->r13 == 0) {
        // 0x80009784: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8000979C;
    }
    // 0x80009784: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009788: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x8000978C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80009790: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80009794: beq         $t7, $zero, L_800097C8
    if (ctx->r15 == 0) {
        // 0x80009798: nop
    
            goto L_800097C8;
    }
    // 0x80009798: nop

L_8000979C:
    // 0x8000979C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800097A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800097A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800097A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800097AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800097B0: jal         0x8001D8B0
    // 0x800097B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_9;
    // 0x800097B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x800097B8: jal         0x8001D358
    // 0x800097BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_10;
    // 0x800097BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800097C0: b           L_80009808
    // 0x800097C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009808;
    // 0x800097C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800097C8:
    // 0x800097C8: lhu         $t0, -0x3A6E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X3A6E);
    // 0x800097CC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800097D0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800097D4: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x800097D8: beql        $t1, $zero, L_800097F0
    if (ctx->r9 == 0) {
        // 0x800097DC: lh          $t5, 0xE($t4)
        ctx->r13 = MEM_H(ctx->r12, 0XE);
            goto L_800097F0;
    }
    goto skip_3;
    // 0x800097DC: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    skip_3:
    // 0x800097E0: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
    // 0x800097E4: b           L_80009804
    // 0x800097E8: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_80009804;
    // 0x800097E8: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x800097EC: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
L_800097F0:
    // 0x800097F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800097F4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800097F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800097FC: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x80009800: nop

L_80009804:
    // 0x80009804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009808:
    // 0x80009808: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000980C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80009810: jr          $ra
    // 0x80009814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80003B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003B60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80003B64: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80003B68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80003B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003B70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80003B74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80003B78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80003B7C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80003B80: lb          $t6, 0x2871($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2871);
    // 0x80003B84: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80003B88: lb          $t7, 0x2872($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X2872);
    // 0x80003B8C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80003B90: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80003B94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80003B98: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80003B9C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80003BA0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80003BA4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80003BA8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80003BAC: bc1f        L_80003BD8
    if (!c1cs) {
        // 0x80003BB0: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80003BD8;
    }
    // 0x80003BB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80003BB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003BB8: nop

    // 0x80003BBC: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80003BC0: nop

    // 0x80003BC4: bc1fl       L_80003BDC
    if (!c1cs) {
        // 0x80003BC8: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80003BDC;
    }
    goto skip_0;
    // 0x80003BC8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_0:
    // 0x80003BCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003BD0: nop

    // 0x80003BD4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_80003BD8:
    // 0x80003BD8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80003BDC:
    // 0x80003BDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003BE0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80003BE4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80003BE8: bc1fl       L_80003C10
    if (!c1cs) {
        // 0x80003BEC: c.eq.s      $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
            goto L_80003C10;
    }
    goto skip_1;
    // 0x80003BEC: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    skip_1:
    // 0x80003BF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80003BF4: nop

    // 0x80003BF8: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x80003BFC: nop

    // 0x80003C00: bc1fl       L_80003C10
    if (!c1cs) {
        // 0x80003C04: c.eq.s      $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
            goto L_80003C10;
    }
    goto skip_2;
    // 0x80003C04: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    skip_2:
    // 0x80003C08: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003C0C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
L_80003C10:
    // 0x80003C10: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003C14: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80003C18: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80003C1C: bc1f        L_80003C34
    if (!c1cs) {
        // 0x80003C20: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80003C34;
    }
    // 0x80003C20: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003C24: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80003C28: nop

    // 0x80003C2C: bc1t        L_80003C5C
    if (c1cs) {
        // 0x80003C30: nop
    
            goto L_80003C5C;
    }
    // 0x80003C30: nop

L_80003C34:
    // 0x80003C34: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80003C38: swc1        $f14, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80003C3C: jal         0x800232F4
    // 0x80003C40: lwc1        $f12, 0x6DE8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6DE8);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80003C40: lwc1        $f12, 0x6DE8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6DE8);
    after_0:
    // 0x80003C44: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003C48: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80003C4C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80003C50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003C54: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80003C58: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_80003C5C:
    // 0x80003C5C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80003C60: lw          $t8, -0x39C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39C8);
    // 0x80003C64: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003C68: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80003C6C: beq         $t8, $zero, L_80003C84
    if (ctx->r24 == 0) {
        // 0x80003C70: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80003C84;
    }
    // 0x80003C70: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80003C74: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003C78: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80003C7C: b           L_80003CE4
    // 0x80003C80: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
        goto L_80003CE4;
    // 0x80003C80: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
L_80003C84:
    // 0x80003C84: lw          $t9, -0x39C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X39C4);
    // 0x80003C88: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003C8C: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
    // 0x80003C90: beql        $t9, $zero, L_80003CB0
    if (ctx->r25 == 0) {
        // 0x80003C94: lw          $t0, 0x0($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X0);
            goto L_80003CB0;
    }
    goto skip_3;
    // 0x80003C94: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x80003C98: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003C9C: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
    // 0x80003CA0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003CA4: b           L_80003CE4
    // 0x80003CA8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_80003CE4;
    // 0x80003CA8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80003CAC: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_80003CB0:
    // 0x80003CB0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80003CB4: andi        $t1, $t0, 0x300F
    ctx->r9 = ctx->r8 & 0X300F;
    // 0x80003CB8: beql        $t1, $zero, L_80003CD0
    if (ctx->r9 == 0) {
        // 0x80003CBC: lhu         $t3, 0x80($t2)
        ctx->r11 = MEM_HU(ctx->r10, 0X80);
            goto L_80003CD0;
    }
    goto skip_4;
    // 0x80003CBC: lhu         $t3, 0x80($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X80);
    skip_4:
    // 0x80003CC0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003CC4: b           L_80003CE4
    // 0x80003CC8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_80003CE4;
    // 0x80003CC8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80003CCC: lhu         $t3, 0x80($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X80);
L_80003CD0:
    // 0x80003CD0: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x80003CD4: beq         $t4, $zero, L_80003CE4
    if (ctx->r12 == 0) {
        // 0x80003CD8: nop
    
            goto L_80003CE4;
    }
    // 0x80003CD8: nop

    // 0x80003CDC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003CE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_80003CE4:
    // 0x80003CE4: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80003CE8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80003CEC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003CF0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80003CF4: beq         $t5, $zero, L_80003D10
    if (ctx->r13 == 0) {
        // 0x80003CF8: andi        $t6, $v0, 0x202
        ctx->r14 = ctx->r2 & 0X202;
            goto L_80003D10;
    }
    // 0x80003CF8: andi        $t6, $v0, 0x202
    ctx->r14 = ctx->r2 & 0X202;
    // 0x80003CFC: beq         $t6, $zero, L_80003D10
    if (ctx->r14 == 0) {
        // 0x80003D00: nop
    
            goto L_80003D10;
    }
    // 0x80003D00: nop

    // 0x80003D04: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003D08: b           L_80003D24
    // 0x80003D0C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_80003D24;
    // 0x80003D0C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_80003D10:
    // 0x80003D10: lhu         $t7, -0x3A6C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3A6C);
    // 0x80003D14: beql        $t7, $zero, L_80003D28
    if (ctx->r15 == 0) {
        // 0x80003D18: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80003D28;
    }
    goto skip_5;
    // 0x80003D18: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80003D1C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80003D20: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_80003D24:
    // 0x80003D24: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80003D28:
    // 0x80003D28: addiu       $a0, $a0, -0x43DC
    ctx->r4 = ADD32(ctx->r4, -0X43DC);
    // 0x80003D2C: lhu         $v0, 0x8($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X8);
    // 0x80003D30: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80003D34: beq         $t9, $zero, L_80003D9C
    if (ctx->r25 == 0) {
        // 0x80003D38: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_80003D9C;
    }
    // 0x80003D38: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80003D3C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80003D40: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80003D44: beq         $v1, $zero, L_80003D68
    if (ctx->r3 == 0) {
        // 0x80003D48: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80003D68;
    }
    // 0x80003D48: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80003D4C: bne         $t0, $zero, L_80003DFC
    if (ctx->r8 != 0) {
        // 0x80003D50: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_80003DFC;
    }
    // 0x80003D50: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80003D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003D58: jal         0x8002E768
    // 0x80003D5C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_8002E768(rdram, ctx);
        goto after_1;
    // 0x80003D5C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80003D60: b           L_80003DFC
    // 0x80003D64: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
        goto L_80003DFC;
    // 0x80003D64: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
L_80003D68:
    // 0x80003D68: lw          $t2, 0x5C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5C0);
    // 0x80003D6C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80003D70: bne         $t2, $zero, L_80003DFC
    if (ctx->r10 != 0) {
        // 0x80003D74: andi        $t3, $v0, 0xFFFE
        ctx->r11 = ctx->r2 & 0XFFFE;
            goto L_80003DFC;
    }
    // 0x80003D74: andi        $t3, $v0, 0xFFFE
    ctx->r11 = ctx->r2 & 0XFFFE;
    // 0x80003D78: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x80003D7C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80003D80: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80003D84: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80003D88: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80003D8C: jal         0x8001C8C4
    // 0x80003D90: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    func_8001C8C4(rdram, ctx);
        goto after_2;
    // 0x80003D90: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    after_2:
    // 0x80003D94: b           L_80003DFC
    // 0x80003D98: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
        goto L_80003DFC;
    // 0x80003D98: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
L_80003D9C:
    // 0x80003D9C: beq         $t7, $zero, L_80003DD0
    if (ctx->r15 == 0) {
        // 0x80003DA0: andi        $t3, $v0, 0x10
        ctx->r11 = ctx->r2 & 0X10;
            goto L_80003DD0;
    }
    // 0x80003DA0: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x80003DA4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80003DA8: lw          $t8, 0x5C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C0);
    // 0x80003DAC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80003DB0: bne         $t8, $zero, L_80003DFC
    if (ctx->r24 != 0) {
        // 0x80003DB4: andi        $t9, $v0, 0xFFFD
        ctx->r25 = ctx->r2 & 0XFFFD;
            goto L_80003DFC;
    }
    // 0x80003DB4: andi        $t9, $v0, 0xFFFD
    ctx->r25 = ctx->r2 & 0XFFFD;
    // 0x80003DB8: sh          $t9, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r25;
    // 0x80003DBC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80003DC0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80003DC4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80003DC8: b           L_80003DFC
    // 0x80003DCC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_80003DFC;
    // 0x80003DCC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80003DD0:
    // 0x80003DD0: beq         $t3, $zero, L_80003DFC
    if (ctx->r11 == 0) {
        // 0x80003DD4: lui         $t4, 0x8009
        ctx->r12 = S32(0X8009 << 16);
            goto L_80003DFC;
    }
    // 0x80003DD4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80003DD8: lw          $t4, 0x5C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5C0);
    // 0x80003DDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80003DE0: bne         $t4, $zero, L_80003DFC
    if (ctx->r12 != 0) {
        // 0x80003DE4: andi        $t5, $v0, 0xFFEF
        ctx->r13 = ctx->r2 & 0XFFEF;
            goto L_80003DFC;
    }
    // 0x80003DE4: andi        $t5, $v0, 0xFFEF
    ctx->r13 = ctx->r2 & 0XFFEF;
    // 0x80003DE8: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
    // 0x80003DEC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80003DF0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80003DF4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80003DF8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_80003DFC:
    // 0x80003DFC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80003E00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003E04: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80003E08: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x80003E0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80003E10: beq         $v0, $at, L_80003E38
    if (ctx->r2 == ctx->r1) {
        // 0x80003E14: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80003E38;
    }
    // 0x80003E14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003E18: bne         $v0, $at, L_80003E48
    if (ctx->r2 != ctx->r1) {
        // 0x80003E1C: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80003E48;
    }
    // 0x80003E1C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80003E20: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80003E24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80003E28: jal         0x8000534C
    // 0x80003E2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8000534C(rdram, ctx);
        goto after_3;
    // 0x80003E2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80003E30: b           L_80003E58
    // 0x80003E34: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
        goto L_80003E58;
    // 0x80003E34: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
L_80003E38:
    // 0x80003E38: jal         0x80004E58
    // 0x80003E3C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80004E58(rdram, ctx);
        goto after_4;
    // 0x80003E3C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80003E40: b           L_80003E58
    // 0x80003E44: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
        goto L_80003E58;
    // 0x80003E44: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
L_80003E48:
    // 0x80003E48: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80003E4C: jal         0x80004D30
    // 0x80003E50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80004D30(rdram, ctx);
        goto after_5;
    // 0x80003E50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80003E54: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
L_80003E58:
    // 0x80003E58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80003E5C: jal         0x80005748
    // 0x80003E60: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80005748(rdram, ctx);
        goto after_6;
    // 0x80003E60: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80003E64: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80003E68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003E70: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80003E74: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80003E78: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80003E7C: bne         $t1, $at, L_80003F34
    if (ctx->r9 != ctx->r1) {
        // 0x80003E80: addiu       $v0, $v0, -0x43D8
        ctx->r2 = ADD32(ctx->r2, -0X43D8);
            goto L_80003F34;
    }
    // 0x80003E80: addiu       $v0, $v0, -0x43D8
    ctx->r2 = ADD32(ctx->r2, -0X43D8);
    // 0x80003E84: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x80003E88: lhu         $t4, 0x58($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X58);
    // 0x80003E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003E90: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80003E94: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80003E98: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80003E9C: slti        $at, $t6, 0x97
    ctx->r1 = SIGNED(ctx->r14) < 0X97 ? 1 : 0;
    // 0x80003EA0: bne         $at, $zero, L_80003EBC
    if (ctx->r1 != 0) {
        // 0x80003EA4: sh          $t5, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r13;
            goto L_80003EBC;
    }
    // 0x80003EA4: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x80003EA8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80003EAC: jal         0x800268D4
    // 0x80003EB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_7;
    // 0x80003EB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x80003EB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003EB8: nop

L_80003EBC:
    // 0x80003EBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80003EC0: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
    // 0x80003EC4: beq         $v0, $zero, L_80003F34
    if (ctx->r2 == 0) {
        // 0x80003EC8: andi        $t8, $v0, 0x3
        ctx->r24 = ctx->r2 & 0X3;
            goto L_80003F34;
    }
    // 0x80003EC8: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80003ECC: bne         $t8, $zero, L_80003F28
    if (ctx->r24 != 0) {
        // 0x80003ED0: lui         $a0, 0x8005
        ctx->r4 = S32(0X8005 << 16);
            goto L_80003F28;
    }
    // 0x80003ED0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80003ED4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80003ED8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80003EDC: addiu       $a0, $a0, -0x31D0
    ctx->r4 = ADD32(ctx->r4, -0X31D0);
    // 0x80003EE0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80003EE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80003EEC: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80003EF0: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80003EF4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80003EF8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80003EFC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80003F00: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x80003F04: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80003F08: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80003F0C: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x80003F10: lwc1        $f10, 0xF48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XF48);
    // 0x80003F14: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80003F18: jal         0x8001B108
    // 0x80003F1C: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    func_8001B108(rdram, ctx);
        goto after_8;
    // 0x80003F1C: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    after_8:
    // 0x80003F20: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80003F24: lhu         $v0, 0x4($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X4);
L_80003F28:
    // 0x80003F28: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80003F2C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80003F30: sh          $t2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r10;
L_80003F34:
    // 0x80003F34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80003F38: jal         0x8000600C
    // 0x80003F3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8000600C(rdram, ctx);
        goto after_9;
    // 0x80003F3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80003F40: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80003F44: jal         0x800074A0
    // 0x80003F48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800074A0(rdram, ctx);
        goto after_10;
    // 0x80003F48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80003F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003F54: jr          $ra
    // 0x80003F58: nop

    return;
    // 0x80003F58: nop

;}
RECOMP_FUNC void func_800102D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800102D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800102D4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800102D8: addiu       $t0, $t0, 0x59D8
    ctx->r8 = ADD32(ctx->r8, 0X59D8);
    // 0x800102DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800102E0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800102E4: lw          $a1, 0x59E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X59E4);
    // 0x800102E8: jal         0x80010564
    // 0x800102EC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_80010564(rdram, ctx);
        goto after_0;
    // 0x800102EC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_0:
    // 0x800102F0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800102F4: addiu       $v0, $v0, 0x538C
    ctx->r2 = ADD32(ctx->r2, 0X538C);
    // 0x800102F8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800102FC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80010300: addiu       $t0, $t0, 0x59D8
    ctx->r8 = ADD32(ctx->r8, 0X59D8);
    // 0x80010304: beq         $a0, $zero, L_80010338
    if (ctx->r4 == 0) {
        // 0x80010308: lui         $a3, 0x8008
        ctx->r7 = S32(0X8008 << 16);
            goto L_80010338;
    }
    // 0x80010308: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001030C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80010310: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80010314: bgez        $t6, L_80010324
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80010318: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80010324;
    }
    // 0x80010318: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001031C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80010320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80010324:
    // 0x80010324: jal         0x80010EC4
    // 0x80010328: nop

    func_80010EC4(rdram, ctx);
        goto after_1;
    // 0x80010328: nop

    after_1:
    // 0x8001032C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80010330: b           L_800103D0
    // 0x80010334: addiu       $t0, $t0, 0x59D8
    ctx->r8 = ADD32(ctx->r8, 0X59D8);
        goto L_800103D0;
    // 0x80010334: addiu       $t0, $t0, 0x59D8
    ctx->r8 = ADD32(ctx->r8, 0X59D8);
L_80010338:
    // 0x80010338: addiu       $a3, $a3, 0x5380
    ctx->r7 = ADD32(ctx->r7, 0X5380);
    // 0x8001033C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80010340: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80010344: addiu       $t8, $t8, -0x3BD0
    ctx->r24 = ADD32(ctx->r24, -0X3BD0);
    // 0x80010348: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001034C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80010350: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80010354: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80010358: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001035C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80010360: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80010364: bne         $at, $zero, L_800103D0
    if (ctx->r1 != 0) {
        // 0x80010368: nop
    
            goto L_800103D0;
    }
    // 0x80010368: nop

    // 0x8001036C: bne         $a0, $zero, L_80010384
    if (ctx->r4 != 0) {
        // 0x80010370: lui         $t1, 0x8008
        ctx->r9 = S32(0X8008 << 16);
            goto L_80010384;
    }
    // 0x80010370: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80010374: lw          $t1, 0x5384($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5384);
    // 0x80010378: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001037C: beq         $at, $zero, L_800103D0
    if (ctx->r1 == 0) {
        // 0x80010380: nop
    
            goto L_800103D0;
    }
    // 0x80010380: nop

L_80010384:
    // 0x80010384: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x80010388: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001038C: addiu       $t5, $t5, 0x14D8
    ctx->r13 = ADD32(ctx->r13, 0X14D8);
    // 0x80010390: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80010394: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x80010398: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8001039C: addiu       $a2, $a2, 0x12D8
    ctx->r6 = ADD32(ctx->r6, 0X12D8);
    // 0x800103A0: jal         0x80010E70
    // 0x800103A4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_80010E70(rdram, ctx);
        goto after_2;
    // 0x800103A4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_2:
    // 0x800103A8: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800103AC: addiu       $a3, $a3, 0x5380
    ctx->r7 = ADD32(ctx->r7, 0X5380);
    // 0x800103B0: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800103B4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800103B8: addiu       $t0, $t0, 0x59D8
    ctx->r8 = ADD32(ctx->r8, 0X59D8);
    // 0x800103BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800103C0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800103C4: bne         $at, $zero, L_800103D0
    if (ctx->r1 != 0) {
        // 0x800103C8: sw          $t7, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r15;
            goto L_800103D0;
    }
    // 0x800103C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800103CC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800103D0:
    // 0x800103D0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800103D4: lhu         $t9, 0x4EE0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X4EE0);
    // 0x800103D8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800103DC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800103E0: andi        $t1, $t9, 0x5
    ctx->r9 = ctx->r25 & 0X5;
    // 0x800103E4: beq         $t1, $zero, L_80010478
    if (ctx->r9 == 0) {
        // 0x800103E8: nop
    
            goto L_80010478;
    }
    // 0x800103E8: nop

    // 0x800103EC: lhu         $t2, -0x3A6E($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3A6E);
    // 0x800103F0: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x800103F4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800103F8: bne         $t3, $zero, L_800104BC
    if (ctx->r11 != 0) {
        // 0x800103FC: nop
    
            goto L_800104BC;
    }
    // 0x800103FC: nop

    // 0x80010400: lw          $t4, -0x4D1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4D1C);
    // 0x80010404: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80010408: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8001040C: bne         $t5, $zero, L_800104BC
    if (ctx->r13 != 0) {
        // 0x80010410: nop
    
            goto L_800104BC;
    }
    // 0x80010410: nop

    // 0x80010414: lw          $t6, -0x39C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39C8);
    // 0x80010418: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001041C: addiu       $v0, $v0, 0x59D0
    ctx->r2 = ADD32(ctx->r2, 0X59D0);
    // 0x80010420: bne         $t6, $zero, L_800104BC
    if (ctx->r14 != 0) {
        // 0x80010424: nop
    
            goto L_800104BC;
    }
    // 0x80010424: nop

    // 0x80010428: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8001042C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010430: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80010434: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80010438: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001043C: lw          $a0, 0x59D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X59D4);
    // 0x80010440: addiu       $a2, $a2, 0x59E0
    ctx->r6 = ADD32(ctx->r6, 0X59E0);
    // 0x80010444: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010448: bnel        $at, $zero, L_80010470
    if (ctx->r1 != 0) {
        // 0x8001044C: lw          $t2, 0x0($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X0);
            goto L_80010470;
    }
    goto skip_0;
    // 0x8001044C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80010450: lhu         $a1, 0x0($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X0);
    // 0x80010454: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x80010458: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001045C: slti        $at, $a1, 0x3E7
    ctx->r1 = SIGNED(ctx->r5) < 0X3E7 ? 1 : 0;
    // 0x80010460: beq         $at, $zero, L_8001046C
    if (ctx->r1 == 0) {
        // 0x80010464: addiu       $t1, $a1, 0x1
        ctx->r9 = ADD32(ctx->r5, 0X1);
            goto L_8001046C;
    }
    // 0x80010464: addiu       $t1, $a1, 0x1
    ctx->r9 = ADD32(ctx->r5, 0X1);
    // 0x80010468: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
L_8001046C:
    // 0x8001046C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_80010470:
    // 0x80010470: b           L_800104BC
    // 0x80010474: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
        goto L_800104BC;
    // 0x80010474: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80010478:
    // 0x80010478: lhu         $t3, 0x4F12($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X4F12);
    // 0x8001047C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80010480: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80010484: beq         $t4, $zero, L_800104BC
    if (ctx->r12 == 0) {
        // 0x80010488: nop
    
            goto L_800104BC;
    }
    // 0x80010488: nop

    // 0x8001048C: lw          $t5, -0x39C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X39C8);
    // 0x80010490: bne         $t5, $zero, L_800104BC
    if (ctx->r13 != 0) {
        // 0x80010494: nop
    
            goto L_800104BC;
    }
    // 0x80010494: nop

    // 0x80010498: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8001049C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800104A0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800104A4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800104A8: lw          $v1, 0x59DC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X59DC);
    // 0x800104AC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800104B0: bne         $at, $zero, L_800104BC
    if (ctx->r1 != 0) {
        // 0x800104B4: subu        $t8, $t7, $v1
        ctx->r24 = SUB32(ctx->r15, ctx->r3);
            goto L_800104BC;
    }
    // 0x800104B4: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x800104B8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800104BC:
    // 0x800104BC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800104C0: addiu       $v1, $v1, 0x5388
    ctx->r3 = ADD32(ctx->r3, 0X5388);
    // 0x800104C4: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x800104C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800104CC: addiu       $a0, $a0, 0x59E2
    ctx->r4 = ADD32(ctx->r4, 0X59E2);
    // 0x800104D0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800104D4: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800104D8: slti        $at, $t2, 0x709
    ctx->r1 = SIGNED(ctx->r10) < 0X709 ? 1 : 0;
    // 0x800104DC: bne         $at, $zero, L_80010500
    if (ctx->r1 != 0) {
        // 0x800104E0: sh          $t1, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r9;
            goto L_80010500;
    }
    // 0x800104E0: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x800104E4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800104E8: ori         $at, $zero, 0xEA23
    ctx->r1 = 0 | 0XEA23;
    // 0x800104EC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800104F0: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800104F4: beq         $at, $zero, L_80010500
    if (ctx->r1 == 0) {
        // 0x800104F8: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80010500;
    }
    // 0x800104F8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800104FC: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
L_80010500:
    // 0x80010500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010508: jr          $ra
    // 0x8001050C: nop

    return;
    // 0x8001050C: nop

;}
RECOMP_FUNC void func_80101500_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101500: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101504: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101508: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8010150C: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80101510: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101514: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101518: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8010151C: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80101520: sh          $a1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r5;
    // 0x80101524: sh          $a2, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r6;
    // 0x80101528: sh          $t8, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r24;
    // 0x8010152C: jr          $ra
    // 0x80101530: sh          $t9, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r25;
    return;
    // 0x80101530: sh          $t9, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_800267F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800267F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800267FC: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x80026800: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026804: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x80026808: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002680C: addiu       $v0, $v0, -0x33F
    ctx->r2 = ADD32(ctx->r2, -0X33F);
    // 0x80026810: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80026814: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80026818: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x8002681C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026820: addiu       $v1, $v1, -0x33E
    ctx->r3 = ADD32(ctx->r3, -0X33E);
    // 0x80026824: beq         $a0, $t9, L_80026844
    if (ctx->r4 == ctx->r25) {
        // 0x80026828: nop
    
            goto L_80026844;
    }
    // 0x80026828: nop

    // 0x8002682C: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x80026830: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80026834: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026838: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8002683C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x80026840: sh          $a1, -0x33C($at)
    MEM_H(-0X33C, ctx->r1) = ctx->r5;
L_80026844:
    // 0x80026844: jr          $ra
    // 0x80026848: nop

    return;
    // 0x80026848: nop

;}
RECOMP_FUNC void func_800020B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800020B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800020BC: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x800020C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800020C4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800020C8: addiu       $s6, $s6, -0x4CB8
    ctx->r22 = ADD32(ctx->r22, -0X4CB8);
    // 0x800020CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800020D0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800020D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800020D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800020DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800020E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800020E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800020E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800020EC: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x800020F0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800020F4: lhu         $t6, -0x4D20($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4D20);
    // 0x800020F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800020FC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80002100: bne         $s3, $t6, L_800021F8
    if (ctx->r19 != ctx->r14) {
        // 0x80002104: sb          $zero, -0x2F2($at)
        MEM_B(-0X2F2, ctx->r1) = 0;
            goto L_800021F8;
    }
    // 0x80002104: sb          $zero, -0x2F2($at)
    MEM_B(-0X2F2, ctx->r1) = 0;
    // 0x80002108: lui         $s7, 0x8030
    ctx->r23 = S32(0X8030 << 16);
    // 0x8000210C: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80002110: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80002114: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002118: addiu       $s4, $s4, -0x4D0C
    ctx->r20 = ADD32(ctx->r20, -0X4D0C);
    // 0x8000211C: addiu       $s7, $s7, 0x1000
    ctx->r23 = ADD32(ctx->r23, 0X1000);
    // 0x80002120: ori         $fp, $zero, 0xD150
    ctx->r30 = 0 | 0XD150;
    // 0x80002124: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80002128: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_8000212C:
    // 0x8000212C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002130: jal         0x800314C0
    // 0x80002134: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_800314C0(rdram, ctx);
        goto after_0;
    // 0x80002134: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_0:
    // 0x80002138: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000213C: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    // 0x80002140: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80002144: multu       $t7, $fp
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002148: mflo        $t8
    ctx->r24 = lo;
    // 0x8000214C: addu        $a0, $s7, $t8
    ctx->r4 = ADD32(ctx->r23, ctx->r24);
    // 0x80002150: jal         0x800011DC
    // 0x80002154: nop

    func_800011DC(rdram, ctx);
        goto after_1;
    // 0x80002154: nop

    after_1:
    // 0x80002158: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000215C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002160: mflo        $t0
    ctx->r8 = lo;
    // 0x80002164: addu        $s5, $s7, $t0
    ctx->r21 = ADD32(ctx->r23, ctx->r8);
    // 0x80002168: jal         0x80026658
    // 0x8000216C: nop

    func_80026658(rdram, ctx);
        goto after_2;
    // 0x8000216C: nop

    after_2:
    // 0x80002170: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80002174: bne         $v0, $zero, L_800021A8
    if (ctx->r2 != 0) {
        // 0x80002178: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_800021A8;
    }
    // 0x80002178: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8000217C: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x80002180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002184:
    // 0x80002184: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002188: jal         0x80034020
    // 0x8000218C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8000218C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x80002190: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80002194: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80002198: bnel        $s2, $t3, L_80002184
    if (ctx->r18 != ctx->r11) {
        // 0x8000219C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002184;
    }
    goto skip_0;
    // 0x8000219C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800021A0: b           L_800021C8
    // 0x800021A4: nop

        goto L_800021C8;
    // 0x800021A4: nop

L_800021A8:
    // 0x800021A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800021AC:
    // 0x800021AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800021B0: jal         0x80034020
    // 0x800021B4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800021B4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x800021B8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800021BC: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800021C0: bnel        $s3, $t5, L_800021AC
    if (ctx->r19 != ctx->r13) {
        // 0x800021C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800021AC;
    }
    goto skip_1;
    // 0x800021C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800021C8:
    // 0x800021C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800021CC: lw          $a0, -0x4628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4628);
    // 0x800021D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800021D4: jal         0x80034200
    // 0x800021D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800021D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x800021DC: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800021E0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800021E4: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x800021E8: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800021EC: lhu         $t8, -0x4D20($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4D20);
    // 0x800021F0: beq         $s3, $t8, L_8000212C
    if (ctx->r19 == ctx->r24) {
        // 0x800021F4: nop
    
            goto L_8000212C;
    }
    // 0x800021F4: nop

L_800021F8:
    // 0x800021F8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800021FC: lb          $t9, -0x2F2($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2F2);
    // 0x80002200: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80002204: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002208: beq         $t9, $zero, L_80002224
    if (ctx->r25 == 0) {
        // 0x8000220C: addiu       $s1, $sp, 0x4C
        ctx->r17 = ADD32(ctx->r29, 0X4C);
            goto L_80002224;
    }
    // 0x8000220C: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80002210: jal         0x80002EA0
    // 0x80002214: nop

    func_80002EA0(rdram, ctx);
        goto after_6;
    // 0x80002214: nop

    after_6:
    // 0x80002218: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000221C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002220: sh          $t0, -0x4D18($at)
    MEM_H(-0X4D18, ctx->r1) = ctx->r8;
L_80002224:
    // 0x80002224: jal         0x80026A04
    // 0x80002228: nop

    func_80026A04(rdram, ctx);
        goto after_7;
    // 0x80002228: nop

    after_7:
    // 0x8000222C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002230:
    // 0x80002230: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002234: jal         0x80034020
    // 0x80002238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80002238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8000223C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80002240: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80002244: bnel        $s3, $t2, L_80002230
    if (ctx->r19 != ctx->r10) {
        // 0x80002248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002230;
    }
    goto skip_2;
    // 0x80002248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8000224C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002254: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002258: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000225C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002260: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002264: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002268: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000226C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002270: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002274: jr          $ra
    // 0x80002278: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002278: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80009D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009D7C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80009D80: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009D84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80009D88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80009D8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009D90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009D94: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x80009D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009D9C: beql        $v0, $zero, L_80009DC0
    if (ctx->r2 == 0) {
        // 0x80009DA0: lw          $t6, 0x1C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1C);
            goto L_80009DC0;
    }
    goto skip_0;
    // 0x80009DA0: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80009DA4: beq         $v0, $at, L_80009EC4
    if (ctx->r2 == ctx->r1) {
        // 0x80009DA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009EC4;
    }
    // 0x80009DA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009DAC: beql        $v0, $at, L_80009F38
    if (ctx->r2 == ctx->r1) {
        // 0x80009DB0: lw          $t8, 0x1C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1C);
            goto L_80009F38;
    }
    goto skip_1;
    // 0x80009DB0: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x80009DB4: b           L_80009FF8
    // 0x80009DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009FF8;
    // 0x80009DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009DBC: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
L_80009DC0:
    // 0x80009DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009DC4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009DC8: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80009DCC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80009DD0: beql        $t8, $zero, L_80009E04
    if (ctx->r24 == 0) {
        // 0x80009DD4: lh          $t9, 0x2($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X2);
            goto L_80009E04;
    }
    goto skip_2;
    // 0x80009DD4: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x80009DD8: jal         0x8000A7D8
    // 0x80009DDC: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_0;
    // 0x80009DDC: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_0:
    // 0x80009DE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009DE4: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009DE8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009DEC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009DF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009DF8: jal         0x8000A508
    // 0x80009DFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_1;
    // 0x80009DFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80009E00: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
L_80009E04:
    // 0x80009E04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009E08: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80009E0C: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x80009E10: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80009E14: bnel        $t1, $zero, L_80009FF8
    if (ctx->r9 != 0) {
        // 0x80009E18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009FF8;
    }
    goto skip_3;
    // 0x80009E18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80009E1C: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x80009E20: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80009E24: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80009E28: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80009E2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80009E30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80009E34: and         $t3, $a1, $at
    ctx->r11 = ctx->r5 & ctx->r1;
    // 0x80009E38: jal         0x80014A98
    // 0x80009E3C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_80014A98(rdram, ctx);
        goto after_2;
    // 0x80009E3C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x80009E40: lhu         $t4, 0x6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6);
    // 0x80009E44: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80009E48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009E4C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80009E50: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x80009E54: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80009E58: bnel        $t6, $at, L_80009E90
    if (ctx->r14 != ctx->r1) {
        // 0x80009E5C: lhu         $t4, 0x6($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X6);
            goto L_80009E90;
    }
    goto skip_4;
    // 0x80009E5C: lhu         $t4, 0x6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6);
    skip_4:
    // 0x80009E60: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80009E64: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80009E68: lhu         $t2, 0x4($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X4);
    // 0x80009E6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80009E70: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80009E74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009E78: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80009E7C: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80009E80: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80009E84: b           L_80009EA0
    // 0x80009E88: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_80009EA0;
    // 0x80009E88: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80009E8C: lhu         $t4, 0x6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6);
L_80009E90:
    // 0x80009E90: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80009E94: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x80009E98: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x80009E9C: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_80009EA0:
    // 0x80009EA0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80009EA4: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80009EA8: bgtz        $t8, L_80009EB4
    if (SIGNED(ctx->r24) > 0) {
        // 0x80009EAC: nop
    
            goto L_80009EB4;
    }
    // 0x80009EAC: nop

    // 0x80009EB0: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
L_80009EB4:
    // 0x80009EB4: jal         0x8001D358
    // 0x80009EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_3;
    // 0x80009EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80009EBC: b           L_80009FF8
    // 0x80009EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009FF8;
    // 0x80009EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009EC4:
    // 0x80009EC4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80009EC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009ECC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009ED0: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x80009ED4: andi        $t1, $t0, 0xA
    ctx->r9 = ctx->r8 & 0XA;
    // 0x80009ED8: beql        $t1, $zero, L_80009F0C
    if (ctx->r9 == 0) {
        // 0x80009EDC: lh          $t2, 0x2($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X2);
            goto L_80009F0C;
    }
    goto skip_5;
    // 0x80009EDC: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x80009EE0: jal         0x8000A7D8
    // 0x80009EE4: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_4;
    // 0x80009EE4: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_4:
    // 0x80009EE8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009EEC: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009EF0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009EF4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009EF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009EFC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009F00: jal         0x8000A508
    // 0x80009F04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_5;
    // 0x80009F04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80009F08: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
L_80009F0C:
    // 0x80009F0C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80009F10: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80009F14: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80009F18: bnel        $t4, $zero, L_80009FF8
    if (ctx->r12 != 0) {
        // 0x80009F1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009FF8;
    }
    goto skip_6;
    // 0x80009F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80009F20: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80009F24: lhu         $t5, 0x60($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X60);
    // 0x80009F28: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80009F2C: b           L_80009FF4
    // 0x80009F30: sh          $t6, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r14;
        goto L_80009FF4;
    // 0x80009F30: sh          $t6, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r14;
    // 0x80009F34: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
L_80009F38:
    // 0x80009F38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009F3C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009F40: lhu         $t7, 0x2($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X2);
    // 0x80009F44: andi        $t9, $t7, 0xA
    ctx->r25 = ctx->r15 & 0XA;
    // 0x80009F48: beql        $t9, $zero, L_80009F7C
    if (ctx->r25 == 0) {
        // 0x80009F4C: lh          $t0, 0x2($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X2);
            goto L_80009F7C;
    }
    goto skip_7;
    // 0x80009F4C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    skip_7:
    // 0x80009F50: jal         0x8000A7D8
    // 0x80009F54: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_6;
    // 0x80009F54: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_6:
    // 0x80009F58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009F5C: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009F60: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009F64: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009F6C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009F70: jal         0x8000A508
    // 0x80009F74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_7;
    // 0x80009F74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x80009F78: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
L_80009F7C:
    // 0x80009F7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009F80: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80009F84: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80009F88: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80009F8C: bne         $v0, $zero, L_80009FE8
    if (ctx->r2 != 0) {
        // 0x80009F90: nop
    
            goto L_80009FE8;
    }
    // 0x80009F90: nop

    // 0x80009F94: lhu         $t2, 0x6($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6);
    // 0x80009F98: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80009F9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80009FA0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80009FA4: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x80009FA8: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x80009FAC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80009FB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80009FB4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80009FB8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80009FBC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80009FC0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x80009FC4: lh          $t7, 0x2($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X2);
    // 0x80009FC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009FCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80009FD0: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80009FD4: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x80009FD8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80009FDC: jal         0x8001D8B0
    // 0x80009FE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8001D8B0(rdram, ctx);
        goto after_8;
    // 0x80009FE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x80009FE4: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
L_80009FE8:
    // 0x80009FE8: bgtz        $v0, L_80009FF4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80009FEC: addiu       $t1, $zero, 0xF
        ctx->r9 = ADD32(0, 0XF);
            goto L_80009FF4;
    }
    // 0x80009FEC: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80009FF0: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
L_80009FF4:
    // 0x80009FF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009FF8:
    // 0x80009FF8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80009FFC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000A000: jr          $ra
    // 0x8000A004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000A004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002371C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002371C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023724: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80023728: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8002372C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80023730: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80023734: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023738: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002373C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80023740: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80023744: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80023748: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002374C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80023750: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80023754: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80023758: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8002375C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80023760: jal         0x80034F60
    // 0x80023764: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80023764: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80023768: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002376C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80023770: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80023774: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x80023778: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002377C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80023780: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80023784: bc1f        L_8002379C
    if (!c1cs) {
        // 0x80023788: lwc1        $f10, 0x58($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
            goto L_8002379C;
    }
    // 0x80023788: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002378C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023790: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80023794: b           L_800237A4
    // 0x80023798: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
        goto L_800237A4;
    // 0x80023798: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_8002379C:
    // 0x8002379C: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800237A0: div.s       $f20, $f16, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
L_800237A4:
    // 0x800237A4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800237A8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800237AC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800237B0: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800237B4: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800237B8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800237BC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800237C0: jal         0x80034F60
    // 0x800237C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x800237C4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x800237C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800237CC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800237D0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800237D4: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x800237D8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800237E0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800237E4: bc1f        L_800237F8
    if (!c1cs) {
        // 0x800237E8: neg.s       $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
            goto L_800237F8;
    }
    // 0x800237E8: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x800237EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800237F0: b           L_80023804
    // 0x800237F4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80023804;
    // 0x800237F4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800237F8:
    // 0x800237F8: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x800237FC: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80023800: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
L_80023804:
    // 0x80023804: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80023808: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8002380C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80023810: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80023814: swc1        $f20, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f20.u32l;
    // 0x80023818: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8002381C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80023820: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80023824: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x80023828: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8002382C: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80023830: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x80023834: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
    // 0x80023838: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x8002383C: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80023840: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x80023844: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80023848: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002384C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023850: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023854: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80023858: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002385C: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x80023860: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80023864: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80023868: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x8002386C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023870: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80023874: jr          $ra
    // 0x80023878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002DBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002DBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DBE8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8002DBEC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002DBF0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002DBF4: lw          $a2, -0x2DC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2DC);
    // 0x8002DBF8: lb          $a1, -0x2D6($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2D6);
    // 0x8002DBFC: jal         0x8003A7BC
    // 0x8002DC00: addiu       $a0, $a0, 0x1750
    ctx->r4 = ADD32(ctx->r4, 0X1750);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002DC00: addiu       $a0, $a0, 0x1750
    ctx->r4 = ADD32(ctx->r4, 0X1750);
    after_0:
    // 0x8002DC04: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002DC08: lb          $t6, -0x2D6($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2D6);
    // 0x8002DC0C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002DC10: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002DC14: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002DC18: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8002DC1C: lb          $a0, -0x2D0($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X2D0);
    // 0x8002DC20: jal         0x80031ACC
    // 0x8002DC24: lw          $a1, -0x2DC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2DC);
    initPFSPaks(rdram, ctx);
        goto after_1;
    // 0x8002DC24: lw          $a1, -0x2DC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2DC);
    after_1:
    // 0x8002DC28: beq         $v0, $zero, L_8002DCC8
    if (ctx->r2 == 0) {
        // 0x8002DC2C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8002DCC8;
    }
    // 0x8002DC2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DC30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC34: jal         0x80031BB0
    // 0x8002DC38: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x8002DC38: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    after_2:
    // 0x8002DC3C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8002DC40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DC44: beq         $v1, $at, L_8002DC74
    if (ctx->r3 == ctx->r1) {
        // 0x8002DC48: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002DC74;
    }
    // 0x8002DC48: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002DC4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002DC50: beq         $v1, $at, L_8002DC90
    if (ctx->r3 == ctx->r1) {
        // 0x8002DC54: addiu       $t2, $zero, 0x10
        ctx->r10 = ADD32(0, 0X10);
            goto L_8002DC90;
    }
    // 0x8002DC54: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8002DC58: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8002DC5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC60: sb          $t8, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r24;
    // 0x8002DC64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC68: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002DC6C: b           L_8002DCA4
    // 0x8002DC70: sb          $t9, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r25;
        goto L_8002DCA4;
    // 0x8002DC70: sb          $t9, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r25;
L_8002DC74:
    // 0x8002DC74: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8002DC78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC7C: sb          $t0, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r8;
    // 0x8002DC80: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC84: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002DC88: b           L_8002DCA4
    // 0x8002DC8C: sb          $t1, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r9;
        goto L_8002DCA4;
    // 0x8002DC8C: sb          $t1, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r9;
L_8002DC90:
    // 0x8002DC90: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC94: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
    // 0x8002DC98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DC9C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002DCA0: sb          $t3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r11;
L_8002DCA4:
    // 0x8002DCA4: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002DCA8: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x8002DCAC: andi        $t6, $t4, 0xFFF8
    ctx->r14 = ctx->r12 & 0XFFF8;
    // 0x8002DCB0: andi        $t8, $t6, 0xBFFF
    ctx->r24 = ctx->r14 & 0XBFFF;
    // 0x8002DCB4: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002DCB8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8002DCBC: ori         $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 | 0X1000;
    // 0x8002DCC0: b           L_8002DD08
    // 0x8002DCC4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
        goto L_8002DD08;
    // 0x8002DCC4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8002DCC8:
    // 0x8002DCC8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002DCCC: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002DCD0: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8002DCD4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002DCD8: addiu       $v1, $v1, -0x2D4
    ctx->r3 = ADD32(ctx->r3, -0X2D4);
    // 0x8002DCDC: andi        $t2, $t0, 0xDFFF
    ctx->r10 = ctx->r8 & 0XDFFF;
    // 0x8002DCE0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8002DCE4: andi        $t4, $t2, 0xFFF8
    ctx->r12 = ctx->r10 & 0XFFF8;
    // 0x8002DCE8: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x8002DCEC: andi        $t6, $t4, 0xBFFF
    ctx->r14 = ctx->r12 & 0XBFFF;
    // 0x8002DCF0: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8002DCF4: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002DCF8: ori         $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 | 0X1000;
    // 0x8002DCFC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002DD00: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8002DD04: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_8002DD08:
    // 0x8002DD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002DD10: jr          $ra
    // 0x8002DD14: nop

    return;
    // 0x8002DD14: nop

;}
RECOMP_FUNC void func_80011850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011850: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011854: sw          $zero, 0x62D0($at)
    MEM_W(0X62D0, ctx->r1) = 0;
    // 0x80011858: jr          $ra
    // 0x8001185C: nop

    return;
    // 0x8001185C: nop

;}
RECOMP_FUNC void func_8000E588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E588: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000E58C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E590: addiu       $v1, $v1, -0x2D30
    ctx->r3 = ADD32(ctx->r3, -0X2D30);
    // 0x8000E594: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8000E598: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8000E59C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8000E5A0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8000E5A4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8000E5A8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8000E5AC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8000E5B0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8000E5B4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8000E5B8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8000E5BC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8000E5C0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8000E5C4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000E5C8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8000E5CC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000E5D0: lw          $t6, -0x2D2C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D2C);
    // 0x8000E5D4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000E5D8: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000E5DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000E5E0: lw          $t7, -0x4D0C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D0C);
    // 0x8000E5E4: addiu       $s1, $s1, 0x4180
    ctx->r17 = ADD32(ctx->r17, 0X4180);
    // 0x8000E5E8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E5EC: beq         $t7, $zero, L_8000E600
    if (ctx->r15 == 0) {
        // 0x8000E5F0: lui         $fp, 0x600
        ctx->r30 = S32(0X600 << 16);
            goto L_8000E600;
    }
    // 0x8000E5F0: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x8000E5F4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000E5F8: b           L_8000E600
    // 0x8000E5FC: addiu       $s1, $s1, 0x4098
    ctx->r17 = ADD32(ctx->r17, 0X4098);
        goto L_8000E600;
    // 0x8000E5FC: addiu       $s1, $s1, 0x4098
    ctx->r17 = ADD32(ctx->r17, 0X4098);
L_8000E600:
    // 0x8000E600: lw          $s4, 0x0($v1)
    ctx->r20 = MEM_W(ctx->r3, 0X0);
    // 0x8000E604: lui         $s7, 0x200
    ctx->r23 = S32(0X200 << 16);
    // 0x8000E608: addiu       $s7, $s7, 0x0
    ctx->r23 = ADD32(ctx->r23, 0X0);
    // 0x8000E60C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8000E610: beq         $s4, $zero, L_8000E738
    if (ctx->r20 == 0) {
        // 0x8000E614: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_8000E738;
    }
    // 0x8000E614: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8000E618: ldc1        $f22, 0x1248($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X1248);
    // 0x8000E61C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E620: lui         $s6, 0x102
    ctx->r22 = S32(0X102 << 16);
    // 0x8000E624: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8000E628: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000E62C: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000E630: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8000E634: addiu       $s2, $s2, -0x4D08
    ctx->r18 = ADD32(ctx->r18, -0X4D08);
    // 0x8000E638: addiu       $s3, $s3, -0x4D04
    ctx->r19 = ADD32(ctx->r19, -0X4D04);
    // 0x8000E63C: addiu       $s5, $s5, 0x4F34
    ctx->r21 = ADD32(ctx->r21, 0X4F34);
    // 0x8000E640: ori         $s6, $s6, 0x40
    ctx->r22 = ctx->r22 | 0X40;
    // 0x8000E644: ldc1        $f20, 0x1250($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1250);
L_8000E648:
    // 0x8000E648: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8000E64C: beql        $t8, $zero, L_8000E72C
    if (ctx->r24 == 0) {
        // 0x8000E650: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8000E72C;
    }
    goto skip_0;
    // 0x8000E650: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    skip_0:
    // 0x8000E654: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000E658: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000E65C: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
    // 0x8000E660: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000E664: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000E668: sub.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = ctx->f6.d - ctx->f20.d;
    // 0x8000E66C: mul.d       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f22.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f22.d);
    // 0x8000E670: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8000E674: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000E678: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8000E67C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x8000E680: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000E684: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8000E688: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8000E68C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8000E690: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000E694: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8000E698: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x8000E69C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8000E6A0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000E6A4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8000E6A8: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x8000E6AC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8000E6B0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000E6B4: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000E6B8: jal         0x80023500
    // 0x8000E6BC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_80023500(rdram, ctx);
        goto after_0;
    // 0x8000E6BC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8000E6C0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000E6C4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8000E6C8: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x8000E6CC: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000E6D0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000E6D4: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8000E6D8: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x8000E6DC: addiu       $t6, $t5, 0xC0
    ctx->r14 = ADD32(ctx->r13, 0XC0);
    // 0x8000E6E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000E6E4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8000E6E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000E6EC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000E6F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000E6F4: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000E6F8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8000E6FC: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x8000E700: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8000E704: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x8000E708: lw          $t9, 0x4F28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4F28);
    // 0x8000E70C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8000E710: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8000E714: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8000E718: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000E71C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8000E720: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000E724: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x8000E728: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8000E72C:
    // 0x8000E72C: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x8000E730: bne         $s4, $zero, L_8000E648
    if (ctx->r20 != 0) {
        // 0x8000E734: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_8000E648;
    }
    // 0x8000E734: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_8000E738:
    // 0x8000E738: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8000E73C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000E740: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8000E744: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8000E748: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8000E74C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8000E750: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8000E754: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8000E758: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8000E75C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8000E760: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8000E764: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8000E768: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8000E76C: jr          $ra
    // 0x8000E770: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000E770: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80004E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E58: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004E5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004E60: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x80004E64: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80004E68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80004E6C: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80004E70: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80004E74: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80004E78: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80004E7C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80004E80: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80004E84: jal         0x80034F60
    // 0x80004E88: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80004E88: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80004E8C: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80004E90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80004E94: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80004E98: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80004E9C: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x80004EA0: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80004EA4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80004EA8: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80004EAC: bc1f        L_80004EC4
    if (!c1cs) {
        // 0x80004EB0: nop
    
            goto L_80004EC4;
    }
    // 0x80004EB0: nop

    // 0x80004EB4: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x80004EB8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004EBC: bc1tl       L_800051D8
    if (c1cs) {
        // 0x80004EC0: lwc1        $f10, 0x18($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
            goto L_800051D8;
    }
    goto skip_0;
    // 0x80004EC0: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    skip_0:
L_80004EC4:
    // 0x80004EC4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80004EC8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80004ECC: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80004ED0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80004ED4: jal         0x80034F60
    // 0x80004ED8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80004ED8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80004EDC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004EE0: ldc1        $f6, 0xFD8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0XFD8);
    // 0x80004EE4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80004EE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004EEC: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80004EF0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80004EF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004EF8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80004EFC: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80004F00: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80004F04: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80004F08: cvt.d.s     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f12.d = CVT_D_S(ctx->f16.fl);
    // 0x80004F0C: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80004F10: nop

    // 0x80004F14: bc1fl       L_80004F4C
    if (!c1cs) {
        // 0x80004F18: lwc1        $f12, 0x58($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80004F4C;
    }
    goto skip_1;
    // 0x80004F18: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x80004F1C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80004F20: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x80004F24: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x80004F28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80004F30: add.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f2.d + ctx->f2.d;
    // 0x80004F34: div.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x80004F38: div.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f12.d);
    // 0x80004F3C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80004F40: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80004F44: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80004F48: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
L_80004F4C:
    // 0x80004F4C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80004F50: jal         0x80023210
    // 0x80004F54: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_80023210(rdram, ctx);
        goto after_2;
    // 0x80004F54: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80004F58: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80004F5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004F60: ldc1        $f4, 0xFE0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0XFE0);
    // 0x80004F64: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80004F68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80004F6C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80004F70: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80004F74: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80004F78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004F7C: sub.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80004F80: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80004F84: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80004F88: nop

    // 0x80004F8C: bc1f        L_80004FAC
    if (!c1cs) {
        // 0x80004F90: nop
    
            goto L_80004FAC;
    }
    // 0x80004F90: nop

    // 0x80004F94: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004F98: ldc1        $f6, 0xFE8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0XFE8);
    // 0x80004F9C: sub.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d - ctx->f6.d;
    // 0x80004FA0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80004FA4: b           L_80004FD4
    // 0x80004FA8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_80004FD4;
    // 0x80004FA8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80004FAC:
    // 0x80004FAC: ldc1        $f10, 0xFF0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0XFF0);
    // 0x80004FB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004FB4: c.lt.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d < ctx->f10.d;
    // 0x80004FB8: nop

    // 0x80004FBC: bc1f        L_80004FD4
    if (!c1cs) {
        // 0x80004FC0: nop
    
            goto L_80004FD4;
    }
    // 0x80004FC0: nop

    // 0x80004FC4: ldc1        $f4, 0xFF8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0XFF8);
    // 0x80004FC8: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x80004FCC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80004FD0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80004FD4:
    // 0x80004FD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004FD8: ldc1        $f8, 0x1000($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1000);
    // 0x80004FDC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004FE0: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80004FE4: nop

    // 0x80004FE8: bc1f        L_80005000
    if (!c1cs) {
        // 0x80004FEC: nop
    
            goto L_80005000;
    }
    // 0x80004FEC: nop

    // 0x80004FF0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004FF4: lwc1        $f12, 0x1008($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1008);
    // 0x80004FF8: b           L_80005020
    // 0x80004FFC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_80005020;
    // 0x80004FFC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80005000:
    // 0x80005000: ldc1        $f10, 0x1010($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1010);
    // 0x80005004: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005008: c.lt.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d < ctx->f10.d;
    // 0x8000500C: nop

    // 0x80005010: bc1fl       L_80005024
    if (!c1cs) {
        // 0x80005014: c.le.s      $f18, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
            goto L_80005024;
    }
    goto skip_2;
    // 0x80005014: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    skip_2:
    // 0x80005018: lwc1        $f12, 0x1018($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1018);
    // 0x8000501C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80005020:
    // 0x80005020: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
L_80005024:
    // 0x80005024: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005028: bc1fl       L_8000503C
    if (!c1cs) {
        // 0x8000502C: neg.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
            goto L_8000503C;
    }
    goto skip_3;
    // 0x8000502C: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    skip_3:
    // 0x80005030: b           L_8000503C
    // 0x80005034: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_8000503C;
    // 0x80005034: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80005038: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
L_8000503C:
    // 0x8000503C: ldc1        $f6, 0x1020($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1020);
    // 0x80005040: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80005044: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005048: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8000504C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80005050: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005054: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80005058: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8000505C: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x80005060: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005064: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80005068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000506C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80005070: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80005074: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005078: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000507C: mul.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x80005080: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80005084: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80005088: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x8000508C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005090: ldc1        $f10, 0x1028($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1028);
    // 0x80005094: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005098: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8000509C: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x800050A0: nop

    // 0x800050A4: bc1f        L_800050C4
    if (!c1cs) {
        // 0x800050A8: nop
    
            goto L_800050C4;
    }
    // 0x800050A8: nop

    // 0x800050AC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800050B0: ldc1        $f8, 0x1030($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1030);
    // 0x800050B4: sub.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d - ctx->f8.d;
    // 0x800050B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800050BC: b           L_800050EC
    // 0x800050C0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_800050EC;
    // 0x800050C0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_800050C4:
    // 0x800050C4: ldc1        $f10, 0x1038($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1038);
    // 0x800050C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800050CC: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800050D0: nop

    // 0x800050D4: bc1fl       L_800050F0
    if (!c1cs) {
        // 0x800050D8: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800050F0;
    }
    goto skip_4;
    // 0x800050D8: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x800050DC: ldc1        $f8, 0x1040($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1040);
    // 0x800050E0: add.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d + ctx->f8.d;
    // 0x800050E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800050E8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_800050EC:
    // 0x800050EC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_800050F0:
    // 0x800050F0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800050F4: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x800050F8: sub.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800050FC: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80005100: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005104: ldc1        $f4, 0x1048($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1048);
    // 0x80005108: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8000510C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80005110: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80005114: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80005118: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8000511C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80005120: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005124: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80005128: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8000512C: jal         0x800232F4
    // 0x80005130: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_3;
    // 0x80005130: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_3:
    // 0x80005134: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80005138: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8000513C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80005140: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80005144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005148: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000514C: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80005150: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80005154: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005158: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000515C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80005160: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005164: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x80005168: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000516C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80005170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005174: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80005178: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000517C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80005180: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005184: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80005188: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8000518C: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80005190: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005198: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8000519C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800051A0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800051A4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800051A8: bc1t        L_800051C4
    if (c1cs) {
        // 0x800051AC: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_800051C4;
    }
    // 0x800051AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800051B0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800051B4: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800051B8: nop

    // 0x800051BC: bc1fl       L_800052FC
    if (!c1cs) {
        // 0x800051C0: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_800052FC;
    }
    goto skip_5;
    // 0x800051C0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    skip_5:
L_800051C4:
    // 0x800051C4: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800051C8: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x800051CC: b           L_800052F8
    // 0x800051D0: sh          $zero, -0x43D8($at)
    MEM_H(-0X43D8, ctx->r1) = 0;
        goto L_800052F8;
    // 0x800051D0: sh          $zero, -0x43D8($at)
    MEM_H(-0X43D8, ctx->r1) = 0;
    // 0x800051D4: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
L_800051D8:
    // 0x800051D8: ldc1        $f12, 0x1050($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1050);
    // 0x800051DC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800051E0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800051E4: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800051E8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800051EC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800051F0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800051F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800051F8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800051FC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80005200: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x80005204: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80005208: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8000520C: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80005210: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80005214: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80005218: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8000521C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80005220: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80005224: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80005228: bc1f        L_800052AC
    if (!c1cs) {
        // 0x8000522C: swc1        $f4, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
            goto L_800052AC;
    }
    // 0x8000522C: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80005230: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005234: ldc1        $f0, 0x1058($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1058);
    // 0x80005238: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x8000523C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80005240: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80005244: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80005248: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8000524C: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80005250: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x80005254: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80005258: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000525C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80005260: mul.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80005264: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005268: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000526C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005270: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80005274: mul.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80005278: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x8000527C: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80005280: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80005284: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80005288: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000528C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80005290: jal         0x800186B4
    // 0x80005294: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_800186B4(rdram, ctx);
        goto after_4;
    // 0x80005294: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_4:
    // 0x80005298: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000529C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800052A0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800052A4: b           L_800052F8
    // 0x800052A8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
        goto L_800052F8;
    // 0x800052A8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
L_800052AC:
    // 0x800052AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800052B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800052B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800052B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800052BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800052C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800052C4: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800052C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800052CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800052D0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800052D4: ldc1        $f8, 0x1060($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1060);
    // 0x800052D8: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800052DC: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x800052E0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800052E4: bc1fl       L_800052FC
    if (!c1cs) {
        // 0x800052E8: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_800052FC;
    }
    goto skip_6;
    // 0x800052E8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x800052EC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800052F0: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800052F4: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
L_800052F8:
    // 0x800052F8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
L_800052FC:
    // 0x800052FC: lh          $t7, 0x52($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X52);
    // 0x80005300: beql        $t6, $t7, L_8000533C
    if (ctx->r14 == ctx->r15) {
        // 0x80005304: sh          $a2, 0x58($a0)
        MEM_H(0X58, ctx->r4) = ctx->r6;
            goto L_8000533C;
    }
    goto skip_7;
    // 0x80005304: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
    skip_7:
    // 0x80005308: lh          $t8, 0x5A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X5A);
    // 0x8000530C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80005310: beql        $t6, $t8, L_8000533C
    if (ctx->r14 == ctx->r24) {
        // 0x80005314: sh          $a2, 0x58($a0)
        MEM_H(0X58, ctx->r4) = ctx->r6;
            goto L_8000533C;
    }
    goto skip_8;
    // 0x80005314: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
    skip_8:
    // 0x80005318: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8000531C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80005320: jal         0x8001D8B0
    // 0x80005324: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    func_8001D8B0(rdram, ctx);
        goto after_5;
    // 0x80005324: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_5:
    // 0x80005328: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000532C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80005330: b           L_8000533C
    // 0x80005334: sh          $t9, 0x54($a0)
    MEM_H(0X54, ctx->r4) = ctx->r25;
        goto L_8000533C;
    // 0x80005334: sh          $t9, 0x54($a0)
    MEM_H(0X54, ctx->r4) = ctx->r25;
    // 0x80005338: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
L_8000533C:
    // 0x8000533C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005340: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80005344: jr          $ra
    // 0x80005348: nop

    return;
    // 0x80005348: nop

;}
RECOMP_FUNC void func_80008C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008C20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008C24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80008C28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80008C2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80008C30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80008C34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80008C38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008C3C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80008C40: lw          $s1, -0x3670($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X3670);
    // 0x80008C44: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80008C48: beq         $s1, $zero, L_80008CB8
    if (ctx->r17 == 0) {
        // 0x80008C4C: nop
    
            goto L_80008CB8;
    }
    // 0x80008C4C: nop

    // 0x80008C50: beq         $s1, $zero, L_80008CB8
    if (ctx->r17 == 0) {
        // 0x80008C54: addiu       $s0, $s0, -0x3668
        ctx->r16 = ADD32(ctx->r16, -0X3668);
            goto L_80008CB8;
    }
    // 0x80008C54: addiu       $s0, $s0, -0x3668
    ctx->r16 = ADD32(ctx->r16, -0X3668);
    // 0x80008C58: lui         $s4, 0x8005
    ctx->r20 = S32(0X8005 << 16);
    // 0x80008C5C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80008C60: addiu       $s3, $s3, -0x2F58
    ctx->r19 = ADD32(ctx->r19, -0X2F58);
    // 0x80008C64: addiu       $s4, $s4, -0x3D70
    ctx->r20 = ADD32(ctx->r20, -0X3D70);
    // 0x80008C68: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80008C6C:
    // 0x80008C6C: lh          $t6, 0x74($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X74);
    // 0x80008C70: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80008C74: beq         $s2, $t6, L_80008CB0
    if (ctx->r18 == ctx->r14) {
        // 0x80008C78: nop
    
            goto L_80008CB0;
    }
    // 0x80008C78: nop

    // 0x80008C7C: lh          $t8, 0x50($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X50);
    // 0x80008C80: lhu         $t1, 0x0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X0);
    // 0x80008C84: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80008C88: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80008C8C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80008C90: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x80008C94: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80008C98: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80008C9C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80008CA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80008CA4: jalr        $t9
    // 0x80008CA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80008CA8: nop

    after_0:
    // 0x80008CAC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80008CB0:
    // 0x80008CB0: bne         $s1, $zero, L_80008C6C
    if (ctx->r17 != 0) {
        // 0x80008CB4: addiu       $s0, $s0, 0x128
        ctx->r16 = ADD32(ctx->r16, 0X128);
            goto L_80008C6C;
    }
    // 0x80008CB4: addiu       $s0, $s0, 0x128
    ctx->r16 = ADD32(ctx->r16, 0X128);
L_80008CB8:
    // 0x80008CB8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80008CBC: lhu         $t4, -0x3A6E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X3A6E);
    // 0x80008CC0: andi        $t5, $t4, 0x100
    ctx->r13 = ctx->r12 & 0X100;
    // 0x80008CC4: beql        $t5, $zero, L_80008CD8
    if (ctx->r13 == 0) {
        // 0x80008CC8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80008CD8;
    }
    goto skip_0;
    // 0x80008CC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80008CCC: jal         0x8000B300
    // 0x80008CD0: nop

    func_8000B300(rdram, ctx);
        goto after_1;
    // 0x80008CD0: nop

    after_1:
    // 0x80008CD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80008CD8:
    // 0x80008CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008CDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80008CE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80008CE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80008CE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80008CEC: jr          $ra
    // 0x80008CF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80008CF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403F0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800403F4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800403F8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800403FC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80040400: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80040404: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80040408: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004040C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80040410: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80040414: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80040418: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8004041C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80040420: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80040424: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80040428: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8004042C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80040430: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80040434: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80040438: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8004043C: addiu       $a2, $a2, -0x6C2C
    ctx->r6 = ADD32(ctx->r6, -0X6C2C);
    // 0x80040440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040444: jal         0x80048AC0
    // 0x80040448: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80040448: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x8004044C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80040450: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80040454: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80040458: addiu       $t6, $t6, -0x6C14
    ctx->r14 = ADD32(ctx->r14, -0X6C14);
    // 0x8004045C: addiu       $t7, $t7, -0x6E88
    ctx->r15 = ADD32(ctx->r15, -0X6E88);
    // 0x80040460: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x80040464: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x80040468: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x8004046C: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80040470: addiu       $s3, $s3, 0xC58
    ctx->r19 = ADD32(ctx->r19, 0XC58);
    // 0x80040474: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80040478: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x8004047C: beq         $at, $zero, L_800404DC
    if (ctx->r1 == 0) {
        // 0x80040480: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800404DC;
    }
    // 0x80040480: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80040484: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80040488: addu        $at, $at, $t9
    gpr jr_addend_80040490 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8004048C: lw          $t9, 0x2020($at)
    ctx->r25 = ADD32(ctx->r1, 0X2020);
    // 0x80040490: jr          $t9
    // 0x80040494: nop

    switch (jr_addend_80040490 >> 2) {
        case 0: goto L_80040498; break;
        case 1: goto L_800404A4; break;
        case 2: goto L_800404BC; break;
        case 3: goto L_800404C8; break;
        case 4: goto L_800404B0; break;
        case 5: goto L_800404D4; break;
        default: switch_error(__func__, 0x80040490, 0x80072020);
    }
    // 0x80040494: nop

L_80040498:
    // 0x80040498: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x8004049C: b           L_800404DC
    // 0x800404A0: addiu       $s3, $s3, 0xAF0
    ctx->r19 = ADD32(ctx->r19, 0XAF0);
        goto L_800404DC;
    // 0x800404A0: addiu       $s3, $s3, 0xAF0
    ctx->r19 = ADD32(ctx->r19, 0XAF0);
L_800404A4:
    // 0x800404A4: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x800404A8: b           L_800404DC
    // 0x800404AC: addiu       $s3, $s3, 0xB58
    ctx->r19 = ADD32(ctx->r19, 0XB58);
        goto L_800404DC;
    // 0x800404AC: addiu       $s3, $s3, 0xB58
    ctx->r19 = ADD32(ctx->r19, 0XB58);
L_800404B0:
    // 0x800404B0: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x800404B4: b           L_800404DC
    // 0x800404B8: addiu       $s3, $s3, 0xBE0
    ctx->r19 = ADD32(ctx->r19, 0XBE0);
        goto L_800404DC;
    // 0x800404B8: addiu       $s3, $s3, 0xBE0
    ctx->r19 = ADD32(ctx->r19, 0XBE0);
L_800404BC:
    // 0x800404BC: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x800404C0: b           L_800404DC
    // 0x800404C4: addiu       $s3, $s3, 0xC08
    ctx->r19 = ADD32(ctx->r19, 0XC08);
        goto L_800404DC;
    // 0x800404C4: addiu       $s3, $s3, 0xC08
    ctx->r19 = ADD32(ctx->r19, 0XC08);
L_800404C8:
    // 0x800404C8: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x800404CC: b           L_800404DC
    // 0x800404D0: addiu       $s3, $s3, 0xC30
    ctx->r19 = ADD32(ctx->r19, 0XC30);
        goto L_800404DC;
    // 0x800404D0: addiu       $s3, $s3, 0xC30
    ctx->r19 = ADD32(ctx->r19, 0XC30);
L_800404D4:
    // 0x800404D4: b           L_800404DC
    // 0x800404D8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_800404DC;
    // 0x800404D8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_800404DC:
    // 0x800404DC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800404E0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x800404E4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800404E8: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x800404EC: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x800404F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800404F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800404F8: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800404FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80040500: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80040504: jal         0x80036660
    // 0x80040508: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80040508: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x8004050C: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x80040510: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x80040514: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80040518: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004051C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040524: jal         0x80036660
    // 0x80040528: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80040528: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x8004052C: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x80040530: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x80040534: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x80040538: beq         $t4, $zero, L_8004056C
    if (ctx->r12 == 0) {
        // 0x8004053C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004056C;
    }
    // 0x8004053C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040540: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_80040544:
    // 0x80040544: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80040548: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004054C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80040550: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x80040554: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x80040558: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8004055C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80040560: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80040564: bnel        $at, $zero, L_80040544
    if (ctx->r1 != 0) {
        // 0x80040568: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_80040544;
    }
    goto skip_0;
    // 0x80040568: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_8004056C:
    // 0x8004056C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x80040570: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80040574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040578: blez        $t0, L_800407EC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004057C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800407EC;
    }
    // 0x8004057C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80040580: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80040584: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80040588: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8004058C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80040590: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80040594: ldc1        $f20, 0x2038($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X2038);
    // 0x80040598: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_8004059C:
    // 0x8004059C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800405A0: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800405A4: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x800405A8: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800405AC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800405B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800405B4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x800405B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800405BC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800405C0: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x800405C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800405C8: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800405CC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800405D0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800405D4: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800405D8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800405DC: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800405E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800405E4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800405E8: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x800405EC: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800405F0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800405F4: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x800405F8: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x800405FC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80040600: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x80040604: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80040608: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004060C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x80040610: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x80040614: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80040618: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x8004061C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x80040620: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80040624: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80040628: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x8004062C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80040630: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80040634: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80040638: beq         $v0, $zero, L_8004073C
    if (ctx->r2 == 0) {
        // 0x8004063C: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_8004073C;
    }
    // 0x8004063C: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x80040640: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80040644: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80040648: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8004064C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040650: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80040654: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80040658: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x8004065C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80040660: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80040664: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80040668: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8004066C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80040670: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80040674: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80040678: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8004067C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80040680: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80040684: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80040688: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8004068C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80040690: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80040694: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80040698: bgez        $t0, L_800406B0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004069C: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_800406B0;
    }
    // 0x8004069C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800406A0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800406A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800406A8: nop

    // 0x800406AC: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800406B0:
    // 0x800406B0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800406B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800406B8: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800406BC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800406C0: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x800406C4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800406C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800406CC: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x800406D0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800406D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800406D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800406DC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800406E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800406E4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800406E8: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x800406EC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800406F0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800406F4: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x800406F8: jal         0x80036660
    // 0x800406FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800406FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80040700: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80040704: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80040708: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004070C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040714: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80040718: jal         0x80036660
    // 0x8004071C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8004071C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x80040720: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80040724: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x80040728: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8004072C: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x80040730: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80040734: b           L_80040748
    // 0x80040738: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_80040748;
    // 0x80040738: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_8004073C:
    // 0x8004073C: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80040740: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80040744: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_80040748:
    // 0x80040748: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8004074C: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x80040750: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80040754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004075C: beq         $t3, $zero, L_800407C4
    if (ctx->r11 == 0) {
        // 0x80040760: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800407C4;
    }
    // 0x80040760: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80040764: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x80040768: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004076C: jal         0x80036660
    // 0x80040770: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80040770: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x80040774: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80040778: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8004077C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80040780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040788: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8004078C: jal         0x80036660
    // 0x80040790: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x80040790: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x80040794: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80040798: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004079C: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800407A0: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x800407A4: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800407A8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800407AC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800407B0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800407B4: jal         0x80040350
    // 0x800407B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x800407B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x800407BC: b           L_800407D8
    // 0x800407C0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_800407D8;
    // 0x800407C0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800407C4:
    // 0x800407C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800407C8: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800407CC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800407D0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800407D4: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800407D8:
    // 0x800407D8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800407DC: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x800407E0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800407E4: bne         $at, $zero, L_8004059C
    if (ctx->r1 != 0) {
        // 0x800407E8: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_8004059C;
    }
    // 0x800407E8: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_800407EC:
    // 0x800407EC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800407F0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800407F4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800407F8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800407FC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80040800: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80040804: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80040808: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8004080C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80040810: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80040814: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80040818: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8004081C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80040820: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80040824: jr          $ra
    // 0x80040828: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80040828: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8004082C: nop

;}
RECOMP_FUNC void func_80023210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023214: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80023218: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002321C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80023220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023224: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80023228: nop

    // 0x8002322C: bc1fl       L_80023264
    if (!c1cs) {
        // 0x80023230: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80023264;
    }
    goto skip_0;
    // 0x80023230: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_0:
    // 0x80023234: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80023238: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002323C: bc1f        L_80023254
    if (!c1cs) {
        // 0x80023240: nop
    
            goto L_80023254;
    }
    // 0x80023240: nop

    // 0x80023244: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80023248: ldc1        $f4, 0x16E0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X16E0);
    // 0x8002324C: b           L_800232DC
    // 0x80023250: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
        goto L_800232DC;
    // 0x80023250: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80023254:
    // 0x80023254: ldc1        $f6, 0x16E8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X16E8);
    // 0x80023258: b           L_800232DC
    // 0x8002325C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
        goto L_800232DC;
    // 0x8002325C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80023260: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80023264:
    // 0x80023264: nop

    // 0x80023268: bc1fl       L_80023284
    if (!c1cs) {
        // 0x8002326C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80023284;
    }
    goto skip_1;
    // 0x8002326C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_1:
    // 0x80023270: jal         0x80023028
    // 0x80023274: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    calc_arctan_in_radians(rdram, ctx);
        goto after_0;
    // 0x80023274: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_0:
    // 0x80023278: b           L_800232DC
    // 0x8002327C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800232DC;
    // 0x8002327C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80023280: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80023284:
    // 0x80023284: nop

    // 0x80023288: bc1f        L_800232C0
    if (!c1cs) {
        // 0x8002328C: nop
    
            goto L_800232C0;
    }
    // 0x8002328C: nop

    // 0x80023290: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80023294: nop

    // 0x80023298: bc1f        L_800232C0
    if (!c1cs) {
        // 0x8002329C: nop
    
            goto L_800232C0;
    }
    // 0x8002329C: nop

    // 0x800232A0: jal         0x80023028
    // 0x800232A4: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    calc_arctan_in_radians(rdram, ctx);
        goto after_1;
    // 0x800232A4: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_1:
    // 0x800232A8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800232AC: ldc1        $f10, 0x16F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X16F0);
    // 0x800232B0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800232B4: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x800232B8: b           L_800232DC
    // 0x800232BC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
        goto L_800232DC;
    // 0x800232BC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
L_800232C0:
    // 0x800232C0: jal         0x80023028
    // 0x800232C4: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    calc_arctan_in_radians(rdram, ctx);
        goto after_2;
    // 0x800232C4: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_2:
    // 0x800232C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800232CC: ldc1        $f4, 0x16F8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X16F8);
    // 0x800232D0: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800232D4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800232D8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_800232DC:
    // 0x800232DC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800232E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800232E4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800232E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800232EC: jr          $ra
    // 0x800232F0: nop

    return;
    // 0x800232F0: nop

;}
RECOMP_FUNC void func_80015370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015378: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001537C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80015380: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015384: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015388: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001538C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015390: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80015394: jal         0x80022FD0
    // 0x80015398: swc1        $f4, 0x71D0($at)
    MEM_W(0X71D0, ctx->r1) = ctx->f4.u32l;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x80015398: swc1        $f4, 0x71D0($at)
    MEM_W(0X71D0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x8001539C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800153A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800153A4: bgez        $v0, L_800153BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800153A8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800153BC;
    }
    // 0x800153A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800153AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800153B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800153B4: nop

    // 0x800153B8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800153BC:
    // 0x800153BC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x800153C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800153C4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800153C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800153CC: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800153D0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800153D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800153D8: jal         0x80022FD0
    // 0x800153DC: swc1        $f6, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->f6.u32l;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x800153DC: swc1        $f6, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->f6.u32l;
    after_1:
    // 0x800153E0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800153E4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800153E8: ldc1        $f0, 0x1490($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1490);
    // 0x800153EC: bgez        $v0, L_80015404
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800153F0: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80015404;
    }
    // 0x800153F0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800153F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800153F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800153FC: nop

    // 0x80015400: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_80015404:
    // 0x80015404: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80015408: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001540C: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80015410: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80015414: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015418: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001541C: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015420: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80015424: sub.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d - ctx->f0.d;
    // 0x80015428: jal         0x800232F4
    // 0x8001542C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x8001542C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_2:
    // 0x80015430: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80015434: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015438: addiu       $v1, $v1, 0x71D0
    ctx->r3 = ADD32(ctx->r3, 0X71D0);
    // 0x8001543C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80015440: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80015444: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80015448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001544C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80015450: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x80015454: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80015458: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001545C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80015460: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x80015464: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80015468: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8001546C: bnel        $t6, $at, L_800154A4
    if (ctx->r14 != ctx->r1) {
        // 0x80015470: lwc1        $f18, 0x1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800154A4;
    }
    goto skip_0;
    // 0x80015470: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x80015474: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80015478: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8001547C: lw          $t7, 0x68($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X68);
    // 0x80015480: lw          $t8, 0x2C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X2C);
    // 0x80015484: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80015488: lwc1        $f6, 0x94($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X94);
    // 0x8001548C: lwc1        $f16, 0x1C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80015490: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015494: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015498: b           L_800154DC
    // 0x8001549C: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
        goto L_800154DC;
    // 0x8001549C: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x800154A0: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
L_800154A4:
    // 0x800154A4: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800154A8: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800154AC: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800154B0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800154B4: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x800154B8: lw          $t9, 0x2C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X2C);
    // 0x800154BC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800154C0: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800154C4: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800154C8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800154CC: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800154D0: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x800154D4: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x800154D8: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
L_800154DC:
    // 0x800154DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800154E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800154E4: jr          $ra
    // 0x800154E8: nop

    return;
    // 0x800154E8: nop

;}
RECOMP_FUNC void func_80003F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003F9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80003FA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80003FA4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80003FA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80003FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003FB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80003FB4: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
    // 0x80003FB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80003FBC: jal         0x80005748
    // 0x80003FC0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80005748(rdram, ctx);
        goto after_0;
    // 0x80003FC0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80003FC4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80003FC8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80003FCC: ldc1        $f0, 0xF50($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0XF50);
    // 0x80003FD0: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80003FD4: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80003FD8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80003FDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80003FE0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80003FE4: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80003FE8: nop

    // 0x80003FEC: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80003FF0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80003FF4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80003FF8: swc1        $f10, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f10.u32l;
    // 0x80003FFC: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    // 0x80004000: lhu         $t6, 0x4($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X4);
    // 0x80004004: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004008: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000400C: bne         $t8, $zero, L_80004030
    if (ctx->r24 != 0) {
        // 0x80004010: sh          $t7, 0x4($a2)
        MEM_H(0X4, ctx->r6) = ctx->r15;
            goto L_80004030;
    }
    // 0x80004010: sh          $t7, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r15;
    // 0x80004014: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80004018: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8000401C: lhu         $t9, 0x60($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X60);
    // 0x80004020: swc1        $f18, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f18.u32l;
    // 0x80004024: swc1        $f18, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f18.u32l;
    // 0x80004028: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8000402C: sh          $t0, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r8;
L_80004030:
    // 0x80004030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004038: jr          $ra
    // 0x8000403C: nop

    return;
    // 0x8000403C: nop

;}
RECOMP_FUNC void func_80025984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002598C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80025990: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025994: sw          $a2, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r6;
    // 0x80025998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002599C: bne         $a2, $at, L_80025A34
    if (ctx->r6 != ctx->r1) {
        // 0x800259A0: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_80025A34;
    }
    // 0x800259A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800259A4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800259A8: lw          $t6, 0x3980($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3980);
    // 0x800259AC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800259B0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800259B4: bne         $t6, $at, L_800259D4
    if (ctx->r14 != ctx->r1) {
        // 0x800259B8: nop
    
            goto L_800259D4;
    }
    // 0x800259B8: nop

    // 0x800259BC: jal         0x800263A8
    // 0x800259C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800263A8(rdram, ctx);
        goto after_0;
    // 0x800259C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800259C4: beql        $v0, $zero, L_800259F8
    if (ctx->r2 == 0) {
        // 0x800259C8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800259F8;
    }
    goto skip_0;
    // 0x800259C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_0:
    // 0x800259CC: b           L_80025B30
    // 0x800259D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80025B30;
    // 0x800259D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800259D4:
    // 0x800259D4: lw          $t7, -0x640($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X640);
    // 0x800259D8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800259DC: beql        $t7, $zero, L_800259F8
    if (ctx->r15 == 0) {
        // 0x800259E0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800259F8;
    }
    goto skip_1;
    // 0x800259E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_1:
    // 0x800259E4: jal         0x800390C0
    // 0x800259E8: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    func_800390C0(rdram, ctx);
        goto after_1;
    // 0x800259E8: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    after_1:
    // 0x800259EC: b           L_80025B30
    // 0x800259F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80025B30;
    // 0x800259F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800259F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800259F8:
    // 0x800259F8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800259FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025A00: sw          $t8, 0x3978($at)
    MEM_W(0X3978, ctx->r1) = ctx->r24;
    // 0x80025A04: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    // 0x80025A08: jal         0x800368E0
    // 0x80025A0C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800368E0(rdram, ctx);
        goto after_2;
    // 0x80025A0C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_2:
    // 0x80025A10: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80025A14: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025A18: sw          $t9, 0x3988($at)
    MEM_W(0X3988, ctx->r1) = ctx->r25;
    // 0x80025A1C: jal         0x80025364
    // 0x80025A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80025364(rdram, ctx);
        goto after_3;
    // 0x80025A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80025A24: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80025A28: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025A2C: b           L_80025B2C
    // 0x80025A30: sw          $t0, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r8;
        goto L_80025B2C;
    // 0x80025A30: sw          $t0, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r8;
L_80025A34:
    // 0x80025A34: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025A38: sw          $zero, 0x3978($at)
    MEM_W(0X3978, ctx->r1) = 0;
    // 0x80025A3C: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    // 0x80025A40: jal         0x800390C0
    // 0x80025A44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800390C0(rdram, ctx);
        goto after_4;
    // 0x80025A44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80025A48: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80025A4C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80025A50: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80025A54: slti        $at, $a2, 0x50
    ctx->r1 = SIGNED(ctx->r6) < 0X50 ? 1 : 0;
    // 0x80025A58: bne         $at, $zero, L_80025ACC
    if (ctx->r1 != 0) {
        // 0x80025A5C: nop
    
            goto L_80025ACC;
    }
    // 0x80025A5C: nop

    // 0x80025A60: lw          $t1, 0x3980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3980);
    // 0x80025A64: addiu       $v0, $a2, -0x50
    ctx->r2 = ADD32(ctx->r6, -0X50);
    // 0x80025A68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80025A6C: beq         $v0, $t1, L_80025A84
    if (ctx->r2 == ctx->r9) {
        // 0x80025A70: nop
    
            goto L_80025A84;
    }
    // 0x80025A70: nop

    // 0x80025A74: jal         0x800263A8
    // 0x80025A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800263A8(rdram, ctx);
        goto after_5;
    // 0x80025A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80025A7C: bnel        $v0, $zero, L_80025B30
    if (ctx->r2 != 0) {
        // 0x80025A80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80025B30;
    }
    goto skip_2;
    // 0x80025A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80025A84:
    // 0x80025A84: jal         0x80025364
    // 0x80025A88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80025364(rdram, ctx);
        goto after_6;
    // 0x80025A88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80025A8C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025A90: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    // 0x80025A94: jal         0x800368E0
    // 0x80025A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800368E0(rdram, ctx);
        goto after_7;
    // 0x80025A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80025A9C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025AA0: sw          $zero, 0x3984($at)
    MEM_W(0X3984, ctx->r1) = 0;
    // 0x80025AA4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80025AA8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025AAC: addiu       $t2, $zero, 0x100
    ctx->r10 = ADD32(0, 0X100);
    // 0x80025AB0: sw          $t2, 0x3990($at)
    MEM_W(0X3990, ctx->r1) = ctx->r10;
    // 0x80025AB4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025AB8: sw          $t3, 0x3980($at)
    MEM_W(0X3980, ctx->r1) = ctx->r11;
    // 0x80025ABC: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025AC0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80025AC4: b           L_80025B2C
    // 0x80025AC8: sw          $t4, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r12;
        goto L_80025B2C;
    // 0x80025AC8: sw          $t4, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r12;
L_80025ACC:
    // 0x80025ACC: lw          $t5, 0x3980($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3980);
    // 0x80025AD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80025AD4: beql        $a2, $t5, L_80025AF0
    if (ctx->r6 == ctx->r13) {
        // 0x80025AD8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80025AF0;
    }
    goto skip_3;
    // 0x80025AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_3:
    // 0x80025ADC: jal         0x800263A8
    // 0x80025AE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800263A8(rdram, ctx);
        goto after_8;
    // 0x80025AE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x80025AE4: bne         $v0, $zero, L_80025B2C
    if (ctx->r2 != 0) {
        // 0x80025AE8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80025B2C;
    }
    // 0x80025AE8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80025AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80025AF0:
    // 0x80025AF0: jal         0x80025364
    // 0x80025AF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80025364(rdram, ctx);
        goto after_9;
    // 0x80025AF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_9:
    // 0x80025AF8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025AFC: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    // 0x80025B00: jal         0x800368E0
    // 0x80025B04: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800368E0(rdram, ctx);
        goto after_10;
    // 0x80025B04: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_10:
    // 0x80025B08: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80025B0C: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x80025B10: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B14: sw          $t6, 0x3984($at)
    MEM_W(0X3984, ctx->r1) = ctx->r14;
    // 0x80025B18: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B1C: sw          $a2, 0x3980($at)
    MEM_W(0X3980, ctx->r1) = ctx->r6;
    // 0x80025B20: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B24: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80025B28: sw          $t7, 0x397C($at)
    MEM_W(0X397C, ctx->r1) = ctx->r15;
L_80025B2C:
    // 0x80025B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025B30:
    // 0x80025B30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025B34: jr          $ra
    // 0x80025B38: nop

    return;
    // 0x80025B38: nop

;}
RECOMP_FUNC void func_80008FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008FE4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80008FE8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80008FEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80008FF0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80008FF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80008FF8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80008FFC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80009000: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80009004: lw          $t6, -0x2F44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F44);
    // 0x80009008: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000900C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80009010: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80009014: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80009018: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8000901C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80009020: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x80009024: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x80009028: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000902C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009030: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x80009034: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80009038: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8000903C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80009040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009048: jal         0x8001D8B0
    // 0x8000904C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x8000904C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80009050: jal         0x80022FD0
    // 0x80009054: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x80009054: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80009058: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000905C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80009060: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    // 0x80009064: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80009068: addiu       $t3, $a0, 0x90
    ctx->r11 = ADD32(ctx->r4, 0X90);
    // 0x8000906C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009070: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80009074: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80009078: sw          $t3, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r11;
    // 0x8000907C: sw          $v1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r3;
    // 0x80009080: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80009084: sw          $v1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r3;
    // 0x80009088: lhu         $t4, 0x6($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X6);
    // 0x8000908C: sh          $t4, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r12;
    // 0x80009090: lhu         $t5, 0x6($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X6);
    // 0x80009094: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80009098: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x8000909C: sh          $t5, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r13;
    // 0x800090A0: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x800090A4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800090A8: bgez        $t6, L_800090BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800090AC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800090BC;
    }
    // 0x800090AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800090B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800090B4: nop

    // 0x800090B8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800090BC:
    // 0x800090BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800090C0: ldc1        $f4, 0x1150($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1150);
    // 0x800090C4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800090C8: lui         $at, 0x4031
    ctx->r1 = S32(0X4031 << 16);
    // 0x800090CC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800090D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800090D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800090D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800090DC: addiu       $v0, $v0, -0x2F20
    ctx->r2 = ADD32(ctx->r2, -0X2F20);
    // 0x800090E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800090E4: addiu       $a3, $zero, 0xA01
    ctx->r7 = ADD32(0, 0XA01);
    // 0x800090E8: add.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d + ctx->f8.d;
    // 0x800090EC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800090F0: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800090F4: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x800090F8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800090FC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009100: lwc1        $f18, 0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80009104: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80009108: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8000910C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80009110: jal         0x8000EE60
    // 0x80009114: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    func_8000EE60(rdram, ctx);
        goto after_2;
    // 0x80009114: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x80009118: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000911C: addiu       $v0, $v0, -0x2F20
    ctx->r2 = ADD32(ctx->r2, -0X2F20);
    // 0x80009120: lhu         $t8, 0x18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X18);
    // 0x80009124: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80009128: andi        $t7, $t8, 0x8000
    ctx->r15 = ctx->r24 & 0X8000;
    // 0x8000912C: beql        $t7, $zero, L_800091C0
    if (ctx->r15 == 0) {
        // 0x80009130: lwc1        $f18, 0x0($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800091C0;
    }
    goto skip_0;
    // 0x80009130: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80009134: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80009138: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000913C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80009140: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80009144: bne         $t0, $zero, L_800091B4
    if (ctx->r8 != 0) {
        // 0x80009148: nop
    
            goto L_800091B4;
    }
    // 0x80009148: nop

    // 0x8000914C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009150: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80009154: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009158: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8000915C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009160: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80009164: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80009168: addiu       $a3, $zero, 0xA01
    ctx->r7 = ADD32(0, 0XA01);
    // 0x8000916C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80009170: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80009174: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80009178: add.d       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f16.d + ctx->f0.d;
    // 0x8000917C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80009180: jal         0x8000EE60
    // 0x80009184: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    func_8000EE60(rdram, ctx);
        goto after_3;
    // 0x80009184: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_3:
    // 0x80009188: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000918C: addiu       $v0, $v0, -0x2F20
    ctx->r2 = ADD32(ctx->r2, -0X2F20);
    // 0x80009190: lhu         $t1, 0x18($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X18);
    // 0x80009194: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80009198: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000919C: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800091A0: beql        $t2, $zero, L_800091C0
    if (ctx->r10 == 0) {
        // 0x800091A4: lwc1        $f18, 0x0($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800091C0;
    }
    goto skip_1;
    // 0x800091A4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800091A8: lwc1        $f16, -0x4530($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x800091AC: b           L_800091BC
    // 0x800091B0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_800091BC;
    // 0x800091B0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_800091B4:
    // 0x800091B4: lwc1        $f10, -0x4530($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x800091B8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_800091BC:
    // 0x800091BC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
L_800091C0:
    // 0x800091C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800091C4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800091C8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800091CC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800091D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800091D4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800091D8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800091DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800091E0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800091E4: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800091E8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800091EC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800091F0: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x800091F4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800091F8: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x800091FC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80009200: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80009204: lhu         $t3, 0x18($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X18);
    // 0x80009208: sh          $t4, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r12;
    // 0x8000920C: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x80009210: sh          $t3, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r11;
    // 0x80009214: lw          $t5, 0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X20);
    // 0x80009218: sh          $zero, 0x90($a0)
    MEM_H(0X90, ctx->r4) = 0;
    // 0x8000921C: sh          $zero, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = 0;
    // 0x80009220: lhu         $t6, 0x2A($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2A);
    // 0x80009224: sh          $t8, 0x11A($a0)
    MEM_H(0X11A, ctx->r4) = ctx->r24;
    // 0x80009228: sh          $t6, 0x114($a0)
    MEM_H(0X114, ctx->r4) = ctx->r14;
    // 0x8000922C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80009230: lhu         $t9, 0xC($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0XC);
    // 0x80009234: sh          $t9, 0x116($a0)
    MEM_H(0X116, ctx->r4) = ctx->r25;
    // 0x80009238: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8000923C: lhu         $t1, 0xE($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XE);
    // 0x80009240: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
    // 0x80009244: sh          $t1, 0x118($a0)
    MEM_H(0X118, ctx->r4) = ctx->r9;
    // 0x80009248: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000924C: swc1        $f6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f6.u32l;
    // 0x80009250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009254: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80009258: jr          $ra
    // 0x8000925C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000925C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80000404: lui         $t1, 0x2
    ctx->r9 = S32(0X2 << 16);
    // 0x80000408: addiu       $t0, $t0, 0x2E90
    ctx->r8 = ADD32(ctx->r8, 0X2E90);
    // 0x8000040C: ori         $t1, $t1, 0x39C0
    ctx->r9 = ctx->r9 | 0X39C0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80000428: lui         $sp, 0x8007
    ctx->r29 = S32(0X8007 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x450
    ctx->r10 = ADD32(ctx->r10, 0X450);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, 0x4E90
    ctx->r29 = ADD32(ctx->r29, 0X4E90);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, 0x4E90
    ctx->r29 = ADD32(ctx->r29, 0X4E90);
    // 0x80000438: nop

    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

;}
RECOMP_FUNC void func_80021214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021214: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80021218: lbu         $t6, -0x2FF3($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2FF3);
    // 0x8002121C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021220: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80021224: beq         $t6, $at, L_80021234
    if (ctx->r14 == ctx->r1) {
        // 0x80021228: nop
    
            goto L_80021234;
    }
    // 0x80021228: nop

    // 0x8002122C: b           L_80021234
    // 0x80021230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80021234;
    // 0x80021230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80021234:
    // 0x80021234: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80021238: jr          $ra
    // 0x8002123C: nop

    return;
    // 0x8002123C: nop

;}
RECOMP_FUNC void func_80013F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013F20: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80013F24: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80013F28: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F2C: addiu       $t9, $t9, -0x3350
    ctx->r25 = ADD32(ctx->r25, -0X3350);
    // 0x80013F30: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80013F34: sw          $t6, 0x6C2C($at)
    MEM_W(0X6C2C, ctx->r1) = ctx->r14;
    // 0x80013F38: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80013F3C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013F40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F44: swc1        $f4, 0x6C30($at)
    MEM_W(0X6C30, ctx->r1) = ctx->f4.u32l;
    // 0x80013F48: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80013F4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F50: swc1        $f6, 0x6C34($at)
    MEM_W(0X6C34, ctx->r1) = ctx->f6.u32l;
    // 0x80013F54: jr          $ra
    // 0x80013F58: nop

    return;
    // 0x80013F58: nop

;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038190: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80038194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038198: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003819C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800381A0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800381A4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800381A8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800381AC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800381B0: lw          $t6, 0x990($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X990);
    // 0x800381B4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800381B8: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800381BC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800381C0: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x800381C4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800381C8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800381CC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800381D0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800381D4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800381D8: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x800381DC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800381E0: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800381E4: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x800381E8: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800381EC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800381F0: sw          $t1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r9;
    // 0x800381F4: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x800381F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800381FC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80038200: sw          $t2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r10;
    // 0x80038204: lw          $t3, 0x18($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X18);
    // 0x80038208: sh          $t4, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r12;
    // 0x8003820C: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x80038210: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80038214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038218: sb          $t5, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r13;
    // 0x8003821C: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80038220: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80038224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038228: jal         0x80036660
    // 0x8003822C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8003822C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80038230: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80038234: jal         0x80043E14
    // 0x80038238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80043E14(rdram, ctx);
        goto after_1;
    // 0x80038238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003823C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80038240: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x80038244: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80038248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003824C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038250: jal         0x80036660
    // 0x80038254: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80038254: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80038258: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x8003825C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80038260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038268: blez        $t8, L_80038298
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003826C: addiu       $t1, $zero, 0x1C
        ctx->r9 = ADD32(0, 0X1C);
            goto L_80038298;
    }
    // 0x8003826C: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80038270: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80038274: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_80038278:
    // 0x80038278: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003827C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80038280: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x80038284: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80038288: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x8003828C: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80038290: bnel        $at, $zero, L_80038278
    if (ctx->r1 != 0) {
        // 0x80038294: lw          $t9, 0x6C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X6C);
            goto L_80038278;
    }
    goto skip_0;
    // 0x80038294: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_80038298:
    // 0x80038298: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x8003829C: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800382A0: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800382A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800382A8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800382AC: jal         0x80036660
    // 0x800382B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800382B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800382B4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800382B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800382BC: jal         0x8004001C
    // 0x800382C0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    func_8004001C(rdram, ctx);
        goto after_4;
    // 0x800382C0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x800382C4: lui         $t2, 0x8003
    ctx->r10 = S32(0X8003 << 16);
    // 0x800382C8: addiu       $t2, $t2, 0x7B7C
    ctx->r10 = ADD32(ctx->r10, 0X7B7C);
    // 0x800382CC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800382D0: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800382D4: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800382D8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800382DC: lw          $a0, 0x990($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X990);
    // 0x800382E0: jal         0x80044010
    // 0x800382E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80044010(rdram, ctx);
        goto after_5;
    // 0x800382E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800382E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800382EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800382F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800382F4: jr          $ra
    // 0x800382F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800382F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800382FC: nop

;}
RECOMP_FUNC void func_8003734C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003734C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80037350: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80037354: lbu         $s6, 0x8($t0)
    ctx->r22 = MEM_BU(ctx->r8, 0X8);
    // 0x80037358: lbu         $s4, 0x9($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0X9);
    // 0x8003735C: lbu         $s1, 0xA($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0XA);
    // 0x80037360: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x80037364: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x80037368: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x8003736C: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x80037370: beq         $at, $zero, L_80037B64
    if (ctx->r1 == 0) {
        // 0x80037374: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80037B64;
    }
    // 0x80037374: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80037378: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003737C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037380: addu        $at, $at, $t7
    gpr jr_addend_80037388 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80037384: lw          $t7, 0x1C10($at)
    ctx->r15 = ADD32(ctx->r1, 0X1C10);
    // 0x80037388: jr          $t7
    // 0x8003738C: nop

    switch (jr_addend_80037388 >> 2) {
        case 0: goto L_80037730; break;
        case 1: goto L_80037B64; break;
        case 2: goto L_80037B64; break;
        case 3: goto L_80037B64; break;
        case 4: goto L_80037B64; break;
        case 5: goto L_80037B64; break;
        case 6: goto L_80037B64; break;
        case 7: goto L_80037B64; break;
        case 8: goto L_80037B64; break;
        case 9: goto L_80037B64; break;
        case 10: goto L_80037B64; break;
        case 11: goto L_80037B64; break;
        case 12: goto L_80037B64; break;
        case 13: goto L_80037B64; break;
        case 14: goto L_80037B64; break;
        case 15: goto L_80037B64; break;
        case 16: goto L_80037390; break;
        case 17: goto L_80037B64; break;
        case 18: goto L_80037B64; break;
        case 19: goto L_80037B64; break;
        case 20: goto L_80037B64; break;
        case 21: goto L_80037B64; break;
        case 22: goto L_80037B64; break;
        case 23: goto L_80037B64; break;
        case 24: goto L_80037B64; break;
        case 25: goto L_80037B64; break;
        case 26: goto L_80037B64; break;
        case 27: goto L_80037B64; break;
        case 28: goto L_80037B64; break;
        case 29: goto L_80037B64; break;
        case 30: goto L_80037B64; break;
        case 31: goto L_80037B64; break;
        case 32: goto L_80037788; break;
        case 33: goto L_80037B64; break;
        case 34: goto L_80037B64; break;
        case 35: goto L_80037B64; break;
        case 36: goto L_80037B64; break;
        case 37: goto L_80037B64; break;
        case 38: goto L_80037B64; break;
        case 39: goto L_80037B64; break;
        case 40: goto L_80037B64; break;
        case 41: goto L_80037B64; break;
        case 42: goto L_80037B64; break;
        case 43: goto L_80037B64; break;
        case 44: goto L_80037B64; break;
        case 45: goto L_80037B64; break;
        case 46: goto L_80037B64; break;
        case 47: goto L_80037B64; break;
        case 48: goto L_80037860; break;
        case 49: goto L_80037B64; break;
        case 50: goto L_80037B64; break;
        case 51: goto L_80037B64; break;
        case 52: goto L_80037B64; break;
        case 53: goto L_80037B64; break;
        case 54: goto L_80037B64; break;
        case 55: goto L_80037B64; break;
        case 56: goto L_80037B64; break;
        case 57: goto L_80037B64; break;
        case 58: goto L_80037B64; break;
        case 59: goto L_80037B64; break;
        case 60: goto L_80037B64; break;
        case 61: goto L_80037B64; break;
        case 62: goto L_80037B64; break;
        case 63: goto L_80037B64; break;
        case 64: goto L_80037A98; break;
        case 65: goto L_80037B64; break;
        case 66: goto L_80037B64; break;
        case 67: goto L_80037B64; break;
        case 68: goto L_80037B64; break;
        case 69: goto L_80037B64; break;
        case 70: goto L_80037B64; break;
        case 71: goto L_80037B64; break;
        case 72: goto L_80037B64; break;
        case 73: goto L_80037B64; break;
        case 74: goto L_80037B64; break;
        case 75: goto L_80037B64; break;
        case 76: goto L_80037B64; break;
        case 77: goto L_80037B64; break;
        case 78: goto L_80037B64; break;
        case 79: goto L_80037B64; break;
        case 80: goto L_800377EC; break;
        case 81: goto L_80037B64; break;
        case 82: goto L_80037B64; break;
        case 83: goto L_80037B64; break;
        case 84: goto L_80037B64; break;
        case 85: goto L_80037B64; break;
        case 86: goto L_80037B64; break;
        case 87: goto L_80037B64; break;
        case 88: goto L_80037B64; break;
        case 89: goto L_80037B64; break;
        case 90: goto L_80037B64; break;
        case 91: goto L_80037B64; break;
        case 92: goto L_80037B64; break;
        case 93: goto L_80037B64; break;
        case 94: goto L_80037B64; break;
        case 95: goto L_80037B64; break;
        case 96: goto L_80037ACC; break;
        default: switch_error(__func__, 0x80037388, 0x80071C10);
    }
    // 0x8003738C: nop

L_80037390:
    // 0x80037390: beql        $s1, $zero, L_80037734
    if (ctx->r17 == 0) {
        // 0x80037394: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80037734;
    }
    goto skip_0;
    // 0x80037394: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80037398: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x8003739C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800373A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800373A4: bne         $t8, $at, L_80037B64
    if (ctx->r24 != ctx->r1) {
        // 0x800373A8: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_80037B64;
    }
    // 0x800373A8: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800373AC: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800373B0: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800373B4: jal         0x80042DD0
    // 0x800373B8: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    func_80042DD0(rdram, ctx);
        goto after_0;
    // 0x800373B8: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
    // 0x800373BC: beq         $v0, $zero, L_80037B64
    if (ctx->r2 == 0) {
        // 0x800373C0: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_80037B64;
    }
    // 0x800373C0: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800373C4: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800373C8: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800373CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800373D0: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800373D4: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800373D8: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800373DC: sb          $zero, 0x78($sp)
    MEM_B(0X78, ctx->r29) = 0;
    // 0x800373E0: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800373E4: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800373E8: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800373EC: jal         0x80042D60
    // 0x800373F0: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    func_80042D60(rdram, ctx);
        goto after_1;
    // 0x800373F0: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_1:
    // 0x800373F4: beq         $v0, $zero, L_80037B64
    if (ctx->r2 == 0) {
        // 0x800373F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80037B64;
    }
    // 0x800373F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800373FC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037400: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80037404: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80037408: jal         0x800443A8
    // 0x8003740C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_800443A8(rdram, ctx);
        goto after_2;
    // 0x8003740C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x80037410: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x80037414: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80037418: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x8003741C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80037420: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x80037424: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x80037428: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8003742C: bnel        $at, $zero, L_80037440
    if (ctx->r1 != 0) {
        // 0x80037430: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_80037440;
    }
    goto skip_1;
    // 0x80037430: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x80037434: b           L_80037440
    // 0x80037438: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80037440;
    // 0x80037438: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x8003743C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80037440:
    // 0x80037440: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x80037444: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80037448: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x8003744C: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x80037450: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80037454: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80037458: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003745C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80037460: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80037464: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80037468: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8003746C: jal         0x800444F0
    // 0x80037470: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x80037470: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x80037474: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80037478: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8003747C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80037480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037484: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x80037488: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x8003748C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80037490: lw          $t7, 0x1C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X1C);
    // 0x80037494: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80037498: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x8003749C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800374A0: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800374A4: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x800374A8: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800374AC: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x800374B0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800374B4: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x800374B8: beql        $a2, $zero, L_80037524
    if (ctx->r6 == 0) {
        // 0x800374BC: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80037524;
    }
    goto skip_2;
    // 0x800374BC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800374C0: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800374C4: beql        $v0, $zero, L_80037524
    if (ctx->r2 == 0) {
        // 0x800374C8: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_80037524;
    }
    goto skip_3;
    // 0x800374C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x800374CC: lbu         $t9, 0x6($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6);
    // 0x800374D0: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x800374D4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800374D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800374DC: lbu         $t6, 0x7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X7);
    // 0x800374E0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800374E4: jalr        $v0
    // 0x800374E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800374E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x800374EC: beq         $v0, $zero, L_80037520
    if (ctx->r2 == 0) {
        // 0x800374F0: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_80037520;
    }
    // 0x800374F0: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800374F4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800374F8: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800374FC: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x80037500: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x80037504: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80037508: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8003750C: jal         0x8003FE6C
    // 0x80037510: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x80037510: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_5:
    // 0x80037514: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80037518: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x8003751C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80037520:
    // 0x80037520: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_80037524:
    // 0x80037524: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037528: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003752C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80037530: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80037534: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037538: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003753C: nop

    // 0x80037540: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80037544: beql        $t7, $zero, L_80037594
    if (ctx->r15 == 0) {
        // 0x80037548: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_80037594;
    }
    goto skip_4;
    // 0x80037548: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x8003754C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037550: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037554: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80037558: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003755C: nop

    // 0x80037560: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037564: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80037568: nop

    // 0x8003756C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80037570: bne         $t7, $zero, L_80037588
    if (ctx->r15 != 0) {
        // 0x80037574: nop
    
            goto L_80037588;
    }
    // 0x80037574: nop

    // 0x80037578: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8003757C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80037580: b           L_800375A0
    // 0x80037584: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800375A0;
    // 0x80037584: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80037588:
    // 0x80037588: b           L_800375A0
    // 0x8003758C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800375A0;
    // 0x8003758C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80037590: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_80037594:
    // 0x80037594: nop

    // 0x80037598: bltz        $t7, L_80037588
    if (SIGNED(ctx->r15) < 0) {
        // 0x8003759C: nop
    
            goto L_80037588;
    }
    // 0x8003759C: nop

L_800375A0:
    // 0x800375A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800375A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800375A8: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800375AC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800375B0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800375B4: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x800375B8: addiu       $s5, $s2, 0x48
    ctx->r21 = ADD32(ctx->r18, 0X48);
    // 0x800375BC: beql        $a2, $zero, L_8003762C
    if (ctx->r6 == 0) {
        // 0x800375C0: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8003762C;
    }
    goto skip_5;
    // 0x800375C0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_5:
    // 0x800375C4: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800375C8: beql        $v0, $zero, L_8003762C
    if (ctx->r2 == 0) {
        // 0x800375CC: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8003762C;
    }
    goto skip_6;
    // 0x800375CC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    skip_6:
    // 0x800375D0: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800375D4: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x800375D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800375DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800375E0: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x800375E4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800375E8: jalr        $v0
    // 0x800375EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800375EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x800375F0: beq         $v0, $zero, L_80037628
    if (ctx->r2 == 0) {
        // 0x800375F4: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_80037628;
    }
    // 0x800375F4: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800375F8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800375FC: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x80037600: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x80037604: sb          $s6, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r22;
    // 0x80037608: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003760C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80037610: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80037614: jal         0x8003FE6C
    // 0x80037618: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x80037618: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_7:
    // 0x8003761C: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80037620: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x80037624: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_80037628:
    // 0x80037628: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_8003762C:
    // 0x8003762C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80037630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037634: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80037638: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x8003763C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80037640: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80037644: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x80037648: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003764C: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x80037650: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80037654: nop

    // 0x80037658: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8003765C: jal         0x80042CA4
    // 0x80037660: nop

    func_80042CA4(rdram, ctx);
        goto after_8;
    // 0x80037660: nop

    after_8:
    // 0x80037664: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x80037668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003766C: jal         0x80042884
    // 0x80037670: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042884(rdram, ctx);
        goto after_9;
    // 0x80037670: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80037674: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80037678: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8003767C: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x80037680: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x80037684: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80037688: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003768C: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x80037690: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80037694: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80037698: jal         0x80044540
    // 0x8003769C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    func_80044540(rdram, ctx);
        goto after_10;
    // 0x8003769C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800376A0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800376A4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800376A8: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800376AC: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800376B0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800376B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800376B8: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800376BC: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800376C0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800376C4: sb          $t7, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r15;
    // 0x800376C8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800376CC: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800376D0: jal         0x8003FE6C
    // 0x800376D4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800376D4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_11:
    // 0x800376D8: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800376DC: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x800376E0: ori         $t9, $s6, 0x80
    ctx->r25 = ctx->r22 | 0X80;
    // 0x800376E4: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800376E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800376EC: beql        $t8, $zero, L_80037B68
    if (ctx->r24 == 0) {
        // 0x800376F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_7;
    // 0x800376F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800376F4: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800376F8: sb          $t9, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r25;
    // 0x800376FC: sb          $s4, 0x95($sp)
    MEM_B(0X95, ctx->r29) = ctx->r20;
    // 0x80037700: sb          $zero, 0x96($sp)
    MEM_B(0X96, ctx->r29) = 0;
    // 0x80037704: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80037708: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x8003770C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80037710: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80037714: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037718: mflo        $s3
    ctx->r19 = lo;
    // 0x8003771C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80037720: jal         0x8003FE6C
    // 0x80037724: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x80037724: nop

    after_12:
    // 0x80037728: b           L_80037B68
    // 0x8003772C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x8003772C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037730:
    // 0x80037730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80037734:
    // 0x80037734: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x80037738: jal         0x80042CEC
    // 0x8003773C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_80042CEC(rdram, ctx);
        goto after_13;
    // 0x8003773C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_13:
    // 0x80037740: beq         $v0, $zero, L_80037B64
    if (ctx->r2 == 0) {
        // 0x80037744: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80037B64;
    }
    // 0x80037744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80037748: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x8003774C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80037750: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80037754: bne         $s6, $t7, L_80037764
    if (ctx->r22 != ctx->r15) {
        // 0x80037758: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80037764;
    }
    // 0x80037758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003775C: b           L_80037B64
    // 0x80037760: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_80037B64;
    // 0x80037760: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_80037764:
    // 0x80037764: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80037768: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8003776C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80037770: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80037774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037778: jal         0x8004290C
    // 0x8003777C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    func_8004290C(rdram, ctx);
        goto after_14;
    // 0x8003777C: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_14:
    // 0x80037780: b           L_80037B68
    // 0x80037784: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037784: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037788:
    // 0x80037788: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003778C: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x80037790: jal         0x80042CEC
    // 0x80037794: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_80042CEC(rdram, ctx);
        goto after_15;
    // 0x80037794: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_15:
    // 0x80037798: beq         $v0, $zero, L_80037B64
    if (ctx->r2 == 0) {
        // 0x8003779C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80037B64;
    }
    // 0x8003779C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800377A0: sb          $s1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r17;
    // 0x800377A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800377A8: jal         0x80042884
    // 0x800377AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042884(rdram, ctx);
        goto after_16;
    // 0x800377AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800377B0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800377B4: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800377B8: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800377BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800377C0: jal         0x80042860
    // 0x800377C4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_80042860(rdram, ctx);
        goto after_17;
    // 0x800377C4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_17:
    // 0x800377C8: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800377CC: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800377D0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800377D4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800377D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800377DC: jal         0x80044190
    // 0x800377E0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_18;
    // 0x800377E0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x800377E4: b           L_80037B68
    // 0x800377E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x800377E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800377EC:
    // 0x800377EC: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800377F0: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x800377F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_8;
    // 0x800377F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800377F8: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800377FC: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_80037800:
    // 0x80037800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037804: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80037808: bnel        $s3, $t6, L_80037850
    if (ctx->r19 != ctx->r14) {
        // 0x8003780C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037850;
    }
    goto skip_9;
    // 0x8003780C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_9:
    // 0x80037810: jal         0x80042884
    // 0x80037814: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    func_80042884(rdram, ctx);
        goto after_19;
    // 0x80037814: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_19:
    // 0x80037818: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8003781C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80037820: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80037824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037828: jal         0x80042860
    // 0x8003782C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_80042860(rdram, ctx);
        goto after_20;
    // 0x8003782C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_20:
    // 0x80037830: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80037834: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80037838: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8003783C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037844: jal         0x80044190
    // 0x80037848: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_21;
    // 0x80037848: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x8003784C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80037850:
    // 0x80037850: bnel        $s0, $zero, L_80037800
    if (ctx->r16 != 0) {
        // 0x80037854: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_80037800;
    }
    goto skip_10;
    // 0x80037854: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_10:
    // 0x80037858: b           L_80037B68
    // 0x8003785C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x8003785C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037860:
    // 0x80037860: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80037864: beq         $s4, $at, L_800378F4
    if (ctx->r20 == ctx->r1) {
        // 0x80037868: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_800378F4;
    }
    // 0x80037868: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8003786C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80037870: beq         $v0, $at, L_80037898
    if (ctx->r2 == ctx->r1) {
        // 0x80037874: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80037898;
    }
    // 0x80037874: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80037878: beq         $v0, $at, L_80037984
    if (ctx->r2 == ctx->r1) {
        // 0x8003787C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80037984;
    }
    // 0x8003787C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80037880: beq         $v0, $at, L_80037998
    if (ctx->r2 == ctx->r1) {
        // 0x80037884: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_80037998;
    }
    // 0x80037884: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80037888: beql        $v0, $at, L_80037A4C
    if (ctx->r2 == ctx->r1) {
        // 0x8003788C: lw          $t9, 0x60($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X60);
            goto L_80037A4C;
    }
    goto skip_11;
    // 0x8003788C: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    skip_11:
    // 0x80037890: b           L_80037B68
    // 0x80037894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037898:
    // 0x80037898: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x8003789C: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800378A0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800378A4: sb          $s1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r17;
    // 0x800378A8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800378AC: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x800378B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_12;
    // 0x800378B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x800378B4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800378B8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800378BC:
    // 0x800378BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800378C0: bnel        $s3, $t7, L_800378E4
    if (ctx->r19 != ctx->r15) {
        // 0x800378C4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800378E4;
    }
    goto skip_13;
    // 0x800378C4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800378C8: jal         0x80042CA4
    // 0x800378CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042CA4(rdram, ctx);
        goto after_22;
    // 0x800378CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x800378D0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800378D4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800378D8: jal         0x80044630
    // 0x800378DC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_80044630(rdram, ctx);
        goto after_23;
    // 0x800378DC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_23:
    // 0x800378E0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800378E4:
    // 0x800378E4: bnel        $s0, $zero, L_800378BC
    if (ctx->r16 != 0) {
        // 0x800378E8: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800378BC;
    }
    goto skip_14;
    // 0x800378E8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x800378EC: b           L_80037B68
    // 0x800378F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x800378F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800378F4:
    // 0x800378F4: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800378F8: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800378FC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80037900: sb          $s1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r17;
    // 0x80037904: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80037908: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x8003790C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_15;
    // 0x8003790C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x80037910: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80037914: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80037918: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_8003791C:
    // 0x8003791C: bnel        $s3, $t7, L_80037974
    if (ctx->r19 != ctx->r15) {
        // 0x80037920: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037974;
    }
    goto skip_16;
    // 0x80037920: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x80037924: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x80037928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003792C: beql        $s4, $t9, L_80037974
    if (ctx->r20 == ctx->r25) {
        // 0x80037930: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037974;
    }
    goto skip_17;
    // 0x80037930: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x80037934: jal         0x80042884
    // 0x80037938: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042884(rdram, ctx);
        goto after_24;
    // 0x80037938: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x8003793C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80037940: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80037944: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80037948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003794C: jal         0x80042860
    // 0x80037950: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_80042860(rdram, ctx);
        goto after_25;
    // 0x80037950: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x80037954: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80037958: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8003795C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80037960: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037964: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037968: jal         0x80044190
    // 0x8003796C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_26;
    // 0x8003796C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x80037970: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80037974:
    // 0x80037974: bnel        $s0, $zero, L_8003791C
    if (ctx->r16 != 0) {
        // 0x80037978: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_8003791C;
    }
    goto skip_18;
    // 0x80037978: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x8003797C: b           L_80037B68
    // 0x80037980: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037980: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037984:
    // 0x80037984: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x80037988: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x8003798C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80037990: b           L_80037B64
    // 0x80037994: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
        goto L_80037B64;
    // 0x80037994: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
L_80037998:
    // 0x80037998: lw          $t8, 0x60($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X60);
    // 0x8003799C: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x800379A0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800379A4: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x800379A8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800379AC: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x800379B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_19;
    // 0x800379B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x800379B4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800379B8: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800379BC: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800379C0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800379C4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800379C8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800379CC: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800379D0:
    // 0x800379D0: bnel        $s3, $t6, L_80037A38
    if (ctx->r19 != ctx->r14) {
        // 0x800379D4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037A38;
    }
    goto skip_20;
    // 0x800379D4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x800379D8: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800379DC: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800379E0: beql        $s4, $v0, L_80037A38
    if (ctx->r20 == ctx->r2) {
        // 0x800379E4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037A38;
    }
    goto skip_21;
    // 0x800379E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x800379E8: bne         $at, $zero, L_80037A00
    if (ctx->r1 != 0) {
        // 0x800379EC: nop
    
            goto L_80037A00;
    }
    // 0x800379EC: nop

    // 0x800379F0: bnel        $v0, $zero, L_80037A38
    if (ctx->r2 != 0) {
        // 0x800379F4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037A38;
    }
    goto skip_22;
    // 0x800379F4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x800379F8: b           L_80037A34
    // 0x800379FC: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80037A34;
    // 0x800379FC: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_80037A00:
    // 0x80037A00: bne         $s6, $v0, L_80037A10
    if (ctx->r22 != ctx->r2) {
        // 0x80037A04: nop
    
            goto L_80037A10;
    }
    // 0x80037A04: nop

    // 0x80037A08: b           L_80037A34
    // 0x80037A0C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_80037A34;
    // 0x80037A0C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80037A10:
    // 0x80037A10: bnel        $s7, $v0, L_80037A38
    if (ctx->r23 != ctx->r2) {
        // 0x80037A14: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037A38;
    }
    goto skip_23;
    // 0x80037A14: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x80037A18: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80037A1C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80037A20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80037A24: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80037A28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037A2C: jal         0x8004290C
    // 0x80037A30: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    func_8004290C(rdram, ctx);
        goto after_27;
    // 0x80037A30: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    after_27:
L_80037A34:
    // 0x80037A34: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80037A38:
    // 0x80037A38: bnel        $s0, $zero, L_800379D0
    if (ctx->r16 != 0) {
        // 0x80037A3C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800379D0;
    }
    goto skip_24;
    // 0x80037A3C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x80037A40: b           L_80037B68
    // 0x80037A44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037A44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80037A48: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
L_80037A4C:
    // 0x80037A4C: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x80037A50: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80037A54: sb          $s1, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r17;
    // 0x80037A58: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80037A5C: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x80037A60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_25;
    // 0x80037A60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x80037A64: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80037A68: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_80037A6C:
    // 0x80037A6C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037A70: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x80037A74: bnel        $s3, $t7, L_80037A88
    if (ctx->r19 != ctx->r15) {
        // 0x80037A78: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037A88;
    }
    goto skip_26;
    // 0x80037A78: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x80037A7C: jal         0x800446C0
    // 0x80037A80: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_800446C0(rdram, ctx);
        goto after_28;
    // 0x80037A80: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x80037A84: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80037A88:
    // 0x80037A88: bnel        $s0, $zero, L_80037A6C
    if (ctx->r16 != 0) {
        // 0x80037A8C: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_80037A6C;
    }
    goto skip_27;
    // 0x80037A8C: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x80037A90: b           L_80037B68
    // 0x80037A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037A98:
    // 0x80037A98: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x80037A9C: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80037AA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80037AA4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80037AA8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80037AAC: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80037AB0: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80037AB4: beql        $at, $zero, L_80037B68
    if (ctx->r1 == 0) {
        // 0x80037AB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_28;
    // 0x80037AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x80037ABC: jal         0x800426D0
    // 0x80037AC0: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    func_800426D0(rdram, ctx);
        goto after_29;
    // 0x80037AC0: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    after_29:
    // 0x80037AC4: b           L_80037B68
    // 0x80037AC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037B68;
    // 0x80037AC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037ACC:
    // 0x80037ACC: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x80037AD0: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x80037AD4: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x80037AD8: addu        $t9, $t7, $fp
    ctx->r25 = ADD32(ctx->r15, ctx->r30);
    // 0x80037ADC: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x80037AE0: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x80037AE4: addiu       $t9, $t7, -0x2000
    ctx->r25 = ADD32(ctx->r15, -0X2000);
    // 0x80037AE8: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037AEC: mflo        $a0
    ctx->r4 = lo;
    // 0x80037AF0: bgez        $a0, L_80037B00
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80037AF4: sra         $t8, $a0, 13
        ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
            goto L_80037B00;
    }
    // 0x80037AF4: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80037AF8: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x80037AFC: sra         $t8, $at, 13
    ctx->r24 = S32(SIGNED(ctx->r1) >> 13);
L_80037B00:
    // 0x80037B00: jal         0x800444F0
    // 0x80037B04: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_30;
    // 0x80037B04: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_30:
    // 0x80037B08: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x80037B0C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80037B10: addu        $t6, $t7, $fp
    ctx->r14 = ADD32(ctx->r15, ctx->r30);
    // 0x80037B14: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x80037B18: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80037B1C: beql        $s0, $zero, L_80037B68
    if (ctx->r16 == 0) {
        // 0x80037B20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80037B68;
    }
    goto skip_29;
    // 0x80037B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x80037B24: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80037B28: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_80037B2C:
    // 0x80037B2C: bnel        $s3, $t9, L_80037B5C
    if (ctx->r19 != ctx->r25) {
        // 0x80037B30: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80037B5C;
    }
    goto skip_30;
    // 0x80037B30: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x80037B34: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80037B38: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80037B3C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037B40: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80037B44: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80037B48: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80037B4C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80037B50: jal         0x80044230
    // 0x80037B54: nop

    func_80044230(rdram, ctx);
        goto after_31;
    // 0x80037B54: nop

    after_31:
    // 0x80037B58: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80037B5C:
    // 0x80037B5C: bnel        $s0, $zero, L_80037B2C
    if (ctx->r16 != 0) {
        // 0x80037B60: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_80037B2C;
    }
    goto skip_31;
    // 0x80037B60: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_80037B64:
    // 0x80037B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037B68:
    // 0x80037B68: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x80037B6C: jr          $ra
    // 0x80037B70: nop

    return;
    // 0x80037B70: nop

    // 0x80037B74: jr          $ra
    // 0x80037B78: nop

    return;
    // 0x80037B78: nop

;}
RECOMP_FUNC void func_8002DFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DFD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DFD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DFD8: addiu       $t6, $zero, 0xAB
    ctx->r14 = ADD32(0, 0XAB);
    // 0x8002DFDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002DFE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002DFE4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8002DFE8: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x8002DFEC: jal         0x80029B58
    // 0x8002DFF0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_80029B58(rdram, ctx);
        goto after_0;
    // 0x8002DFF0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_0:
    // 0x8002DFF4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002DFF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002DFFC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E000: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8002E004: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x8002E008: jal         0x80029B58
    // 0x8002E00C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x8002E00C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_1:
    // 0x8002E010: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x8002E014: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002E018: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E01C: addiu       $a1, $zero, 0x105
    ctx->r5 = ADD32(0, 0X105);
    // 0x8002E020: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8002E024: jal         0x80029B58
    // 0x8002E028: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x8002E028: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8002E02C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002E030: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002E034: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E038: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x8002E03C: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8002E040: jal         0x80029B58
    // 0x8002E044: addiu       $a3, $zero, 0xCA
    ctx->r7 = ADD32(0, 0XCA);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x8002E044: addiu       $a3, $zero, 0xCA
    ctx->r7 = ADD32(0, 0XCA);
    after_3:
    // 0x8002E048: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002E04C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002E050: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E054: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x8002E058: addiu       $a2, $zero, 0xCD
    ctx->r6 = ADD32(0, 0XCD);
    // 0x8002E05C: jal         0x80029B58
    // 0x8002E060: addiu       $a3, $zero, 0xCA
    ctx->r7 = ADD32(0, 0XCA);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x8002E060: addiu       $a3, $zero, 0xCA
    ctx->r7 = ADD32(0, 0XCA);
    after_4:
    // 0x8002E064: addiu       $t1, $zero, 0xAD
    ctx->r9 = ADD32(0, 0XAD);
    // 0x8002E068: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002E06C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E070: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x8002E074: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8002E078: jal         0x80029B58
    // 0x8002E07C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x8002E07C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8002E080: addiu       $t2, $zero, 0xAD
    ctx->r10 = ADD32(0, 0XAD);
    // 0x8002E084: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002E088: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002E08C: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x8002E090: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8002E094: jal         0x80029B58
    // 0x8002E098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x8002E098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x8002E09C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002E0A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002E0A4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002E0A8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x8002E0AC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x8002E0B0: jal         0x80029B58
    // 0x8002E0B4: addiu       $a3, $zero, 0xC5
    ctx->r7 = ADD32(0, 0XC5);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x8002E0B4: addiu       $a3, $zero, 0xC5
    ctx->r7 = ADD32(0, 0XC5);
    after_7:
    // 0x8002E0B8: addiu       $t4, $zero, 0xA8
    ctx->r12 = ADD32(0, 0XA8);
    // 0x8002E0BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002E0C0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002E0C4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x8002E0C8: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x8002E0CC: jal         0x80029B58
    // 0x8002E0D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x8002E0D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8002E0D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002E0D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002E0DC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002E0E0: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x8002E0E4: addiu       $a2, $zero, 0xCB
    ctx->r6 = ADD32(0, 0XCB);
    // 0x8002E0E8: jal         0x80029B58
    // 0x8002E0EC: addiu       $a3, $zero, 0xC6
    ctx->r7 = ADD32(0, 0XC6);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x8002E0EC: addiu       $a3, $zero, 0xC6
    ctx->r7 = ADD32(0, 0XC6);
    after_9:
    // 0x8002E0F0: addiu       $t6, $zero, 0xA9
    ctx->r14 = ADD32(0, 0XA9);
    // 0x8002E0F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002E0F8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002E0FC: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x8002E100: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x8002E104: jal         0x80029B58
    // 0x8002E108: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x8002E108: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x8002E10C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8002E110: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002E114: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8002E118: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8002E11C: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x8002E120: jal         0x80029B58
    // 0x8002E124: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x8002E124: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    after_11:
    // 0x8002E128: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8002E12C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002E130: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8002E134: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8002E138: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x8002E13C: jal         0x80029B58
    // 0x8002E140: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    func_80029B58(rdram, ctx);
        goto after_12;
    // 0x8002E140: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    after_12:
    // 0x8002E144: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002E148: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002E14C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8002E150: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8002E154: addiu       $a2, $zero, 0x7B
    ctx->r6 = ADD32(0, 0X7B);
    // 0x8002E158: jal         0x80029B58
    // 0x8002E15C: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    func_80029B58(rdram, ctx);
        goto after_13;
    // 0x8002E15C: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    after_13:
    // 0x8002E160: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002E164: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002E168: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8002E16C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8002E170: addiu       $a2, $zero, 0x91
    ctx->r6 = ADD32(0, 0X91);
    // 0x8002E174: jal         0x80029B58
    // 0x8002E178: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    func_80029B58(rdram, ctx);
        goto after_14;
    // 0x8002E178: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    after_14:
    // 0x8002E17C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8002E180: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002E184: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x8002E188: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x8002E18C: addiu       $a2, $zero, 0x67
    ctx->r6 = ADD32(0, 0X67);
    // 0x8002E190: jal         0x80029B58
    // 0x8002E194: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    func_80029B58(rdram, ctx);
        goto after_15;
    // 0x8002E194: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    after_15:
    // 0x8002E198: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8002E19C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002E1A0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x8002E1A4: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x8002E1A8: addiu       $a2, $zero, 0xB5
    ctx->r6 = ADD32(0, 0XB5);
    // 0x8002E1AC: jal         0x80029B58
    // 0x8002E1B0: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    func_80029B58(rdram, ctx);
        goto after_16;
    // 0x8002E1B0: addiu       $a3, $zero, 0x7C
    ctx->r7 = ADD32(0, 0X7C);
    after_16:
    // 0x8002E1B4: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x8002E1B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002E1BC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8002E1C0: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8002E1C4: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8002E1C8: jal         0x80029B58
    // 0x8002E1CC: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_80029B58(rdram, ctx);
        goto after_17;
    // 0x8002E1CC: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_17:
    // 0x8002E1D0: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002E1D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002E1D8: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x8002E1DC: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x8002E1E0: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8002E1E4: jal         0x80029B58
    // 0x8002E1E8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x8002E1E8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_18:
    // 0x8002E1EC: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x8002E1F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002E1F4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8002E1F8: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8002E1FC: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x8002E200: jal         0x80029B58
    // 0x8002E204: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x8002E204: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_19:
    // 0x8002E208: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002E20C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002E210: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x8002E214: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x8002E218: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x8002E21C: jal         0x80029B58
    // 0x8002E220: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x8002E220: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_20:
    // 0x8002E224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E22C: jr          $ra
    // 0x8002E230: nop

    return;
    // 0x8002E230: nop

;}
RECOMP_FUNC void func_8001CFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CFEC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001CFF0: addiu       $a2, $a2, -0x3A6E
    ctx->r6 = ADD32(ctx->r6, -0X3A6E);
    // 0x8001CFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CFF8: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x8001CFFC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D000: addiu       $a0, $a0, -0x3A6C
    ctx->r4 = ADD32(ctx->r4, -0X3A6C);
    // 0x8001D004: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8001D008: beql        $t6, $zero, L_8001D34C
    if (ctx->r14 == 0) {
        // 0x8001D00C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001D34C;
    }
    goto skip_0;
    // 0x8001D00C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001D010: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8001D014: beq         $v0, $zero, L_8001D024
    if (ctx->r2 == 0) {
        // 0x8001D018: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8001D024;
    }
    // 0x8001D018: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8001D01C: b           L_8001D348
    // 0x8001D020: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
        goto L_8001D348;
    // 0x8001D020: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_8001D024:
    // 0x8001D024: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8001D028: beq         $t8, $zero, L_8001D06C
    if (ctx->r24 == 0) {
        // 0x8001D02C: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8001D06C;
    }
    // 0x8001D02C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001D030: lhu         $t9, -0x3A68($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A68);
    // 0x8001D034: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001D038: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001D03C: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8001D040: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001D044: lhu         $t3, -0x2F50($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2F50);
    // 0x8001D048: addiu       $t6, $t6, -0x3668
    ctx->r14 = ADD32(ctx->r14, -0X3668);
    // 0x8001D04C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8001D050: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001D054: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001D058: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001D05C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001D060: addiu       $t5, $t4, 0x24
    ctx->r13 = ADD32(ctx->r12, 0X24);
    // 0x8001D064: b           L_8001D074
    // 0x8001D068: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
        goto L_8001D074;
    // 0x8001D068: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
L_8001D06C:
    // 0x8001D06C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001D070: addiu       $t0, $t0, -0x4534
    ctx->r8 = ADD32(ctx->r8, -0X4534);
L_8001D074:
    // 0x8001D074: lhu         $t7, 0x60($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X60);
    // 0x8001D078: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8001D07C: bne         $t8, $zero, L_8001D348
    if (ctx->r24 != 0) {
        // 0x8001D080: lui         $t9, 0x8008
        ctx->r25 = S32(0X8008 << 16);
            goto L_8001D348;
    }
    // 0x8001D080: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001D084: lw          $t9, -0x3670($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3670);
    // 0x8001D088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D08C: andi        $t2, $v1, 0x400
    ctx->r10 = ctx->r3 & 0X400;
    // 0x8001D090: beq         $t9, $zero, L_8001D0A0
    if (ctx->r25 == 0) {
        // 0x8001D094: ori         $t4, $v1, 0x8
        ctx->r12 = ctx->r3 | 0X8;
            goto L_8001D0A0;
    }
    // 0x8001D094: ori         $t4, $v1, 0x8
    ctx->r12 = ctx->r3 | 0X8;
    // 0x8001D098: beq         $t2, $zero, L_8001D134
    if (ctx->r10 == 0) {
        // 0x8001D09C: andi        $t9, $v1, 0x10
        ctx->r25 = ctx->r3 & 0X10;
            goto L_8001D134;
    }
    // 0x8001D09C: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
L_8001D0A0:
    // 0x8001D0A0: andi        $t5, $t4, 0x100
    ctx->r13 = ctx->r12 & 0X100;
    // 0x8001D0A4: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x8001D0A8: beq         $t5, $zero, L_8001D108
    if (ctx->r13 == 0) {
        // 0x8001D0AC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001D108;
    }
    // 0x8001D0AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001D0B0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D0B4: lw          $a0, -0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3A90);
    // 0x8001D0B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D0BC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8001D0C0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8001D0C4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001D0C8: jal         0x8000BA0C
    // 0x8001D0CC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8000BA0C(rdram, ctx);
        goto after_0;
    // 0x8001D0CC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8001D0D0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D0D4: lw          $a0, -0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3A90);
    // 0x8001D0D8: jal         0x8000BB68
    // 0x8001D0DC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_8000BB68(rdram, ctx);
        goto after_1;
    // 0x8001D0DC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_1:
    // 0x8001D0E0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001D0E4: lw          $t7, -0x3A98($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A98);
    // 0x8001D0E8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001D0EC: lw          $t8, -0x3A94($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3A94);
    // 0x8001D0F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D0F4: sw          $t7, -0x2F58($at)
    MEM_W(-0X2F58, ctx->r1) = ctx->r15;
    // 0x8001D0F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D0FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D100: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001D104: sw          $t8, -0x2F54($at)
    MEM_W(-0X2F54, ctx->r1) = ctx->r24;
L_8001D108:
    // 0x8001D108: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001D10C: jal         0x8001D828
    // 0x8001D110: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8001D828(rdram, ctx);
        goto after_2;
    // 0x8001D110: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_2:
    // 0x8001D114: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001D118: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D11C: sw          $v0, -0x4590($at)
    MEM_W(-0X4590, ctx->r1) = ctx->r2;
    // 0x8001D120: addiu       $a2, $a2, -0x3A6E
    ctx->r6 = ADD32(ctx->r6, -0X3A6E);
    // 0x8001D124: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x8001D128: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D12C: b           L_8001D16C
    // 0x8001D130: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_8001D16C;
    // 0x8001D130: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8001D134:
    // 0x8001D134: beq         $t9, $zero, L_8001D144
    if (ctx->r25 == 0) {
        // 0x8001D138: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_8001D144;
    }
    // 0x8001D138: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x8001D13C: b           L_8001D16C
    // 0x8001D140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8001D16C;
    // 0x8001D140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8001D144:
    // 0x8001D144: bne         $t2, $zero, L_8001D16C
    if (ctx->r10 != 0) {
        // 0x8001D148: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_8001D16C;
    }
    // 0x8001D148: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001D14C: lhu         $t3, -0x4540($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4540);
    // 0x8001D150: ori         $t5, $v1, 0x10
    ctx->r13 = ctx->r3 | 0X10;
    // 0x8001D154: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x8001D158: beq         $t4, $zero, L_8001D16C
    if (ctx->r12 == 0) {
        // 0x8001D15C: nop
    
            goto L_8001D16C;
    }
    // 0x8001D15C: nop

    // 0x8001D160: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x8001D164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001D168: andi        $v1, $t5, 0xFFFF
    ctx->r3 = ctx->r13 & 0XFFFF;
L_8001D16C:
    // 0x8001D16C: beq         $a1, $zero, L_8001D200
    if (ctx->r5 == 0) {
        // 0x8001D170: andi        $v0, $v1, 0xFFFB
        ctx->r2 = ctx->r3 & 0XFFFB;
            goto L_8001D200;
    }
    // 0x8001D170: andi        $v0, $v1, 0xFFFB
    ctx->r2 = ctx->r3 & 0XFFFB;
    // 0x8001D174: andi        $t6, $v1, 0xFFFE
    ctx->r14 = ctx->r3 & 0XFFFE;
    // 0x8001D178: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8001D17C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D180: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D184: sh          $zero, -0x39D0($at)
    MEM_H(-0X39D0, ctx->r1) = 0;
    // 0x8001D188: jal         0x80019CA4
    // 0x8001D18C: lhu         $a0, -0x3AA4($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3AA4);
    func_80019CA4(rdram, ctx);
        goto after_3;
    // 0x8001D18C: lhu         $a0, -0x3AA4($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3AA4);
    after_3:
    // 0x8001D190: jal         0x80008F6C
    // 0x8001D194: nop

    func_80008F6C(rdram, ctx);
        goto after_4;
    // 0x8001D194: nop

    after_4:
    // 0x8001D198: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001D19C: jal         0x800143C0
    // 0x8001D1A0: lw          $a0, 0x6ED8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED8);
    func_800143C0(rdram, ctx);
        goto after_5;
    // 0x8001D1A0: lw          $a0, 0x6ED8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED8);
    after_5:
    // 0x8001D1A4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001D1A8: addiu       $a2, $a2, -0x3A6E
    ctx->r6 = ADD32(ctx->r6, -0X3A6E);
    // 0x8001D1AC: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x8001D1B0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001D1B4: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8001D1B8: andi        $t7, $v1, 0x100
    ctx->r15 = ctx->r3 & 0X100;
    // 0x8001D1BC: beq         $t7, $zero, L_8001D1CC
    if (ctx->r15 == 0) {
        // 0x8001D1C0: andi        $t8, $v1, 0xFEFF
        ctx->r24 = ctx->r3 & 0XFEFF;
            goto L_8001D1CC;
    }
    // 0x8001D1C0: andi        $t8, $v1, 0xFEFF
    ctx->r24 = ctx->r3 & 0XFEFF;
    // 0x8001D1C4: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8001D1C8: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
L_8001D1CC:
    // 0x8001D1CC: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x8001D1D0: beq         $t9, $zero, L_8001D1F0
    if (ctx->r25 == 0) {
        // 0x8001D1D4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001D1F0;
    }
    // 0x8001D1D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001D1D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001D1DC: lw          $a0, 0x4EE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EE4);
    // 0x8001D1E0: jal         0x8002684C
    // 0x8001D1E4: lw          $a1, 0x4EE8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4EE8);
    func_8002684C(rdram, ctx);
        goto after_6;
    // 0x8001D1E4: lw          $a1, 0x4EE8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4EE8);
    after_6:
    // 0x8001D1E8: b           L_8001D34C
    // 0x8001D1EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D34C;
    // 0x8001D1EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D1F0:
    // 0x8001D1F0: jal         0x800267F8
    // 0x8001D1F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800267F8(rdram, ctx);
        goto after_7;
    // 0x8001D1F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x8001D1F8: b           L_8001D34C
    // 0x8001D1FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001D34C;
    // 0x8001D1FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D200:
    // 0x8001D200: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8001D204: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8001D208: beq         $t3, $zero, L_8001D22C
    if (ctx->r11 == 0) {
        // 0x8001D20C: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8001D22C;
    }
    // 0x8001D20C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8001D210: jal         0x8000932C
    // 0x8001D214: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_8000932C(rdram, ctx);
        goto after_8;
    // 0x8001D214: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_8:
    // 0x8001D218: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001D21C: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x8001D220: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001D224: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8001D228: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8001D22C:
    // 0x8001D22C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001D230: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001D234: addiu       $v1, $v1, -0x3A5C
    ctx->r3 = ADD32(ctx->r3, -0X3A5C);
    // 0x8001D238: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8001D23C: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8001D240: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001D244: addiu       $t1, $t1, -0x3BD0
    ctx->r9 = ADD32(ctx->r9, -0X3BD0);
    // 0x8001D248: beq         $v0, $zero, L_8001D28C
    if (ctx->r2 == 0) {
        // 0x8001D24C: swc1        $f6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
            goto L_8001D28C;
    }
    // 0x8001D24C: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8001D250: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001D254: lhu         $t5, -0x3A68($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X3A68);
    // 0x8001D258: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001D25C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D260: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8001D264: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001D268: lhu         $t7, -0x2F50($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2F50);
    // 0x8001D26C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001D270: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001D274: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001D278: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001D27C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001D280: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001D284: b           L_8001D294
    // 0x8001D288: lwc1        $f0, -0x3658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3658);
        goto L_8001D294;
    // 0x8001D288: lwc1        $f0, -0x3658($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3658);
L_8001D28C:
    // 0x8001D28C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D290: lwc1        $f0, -0x453C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X453C);
L_8001D294:
    // 0x8001D294: beq         $v0, $zero, L_8001D2DC
    if (ctx->r2 == 0) {
        // 0x8001D298: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8001D2DC;
    }
    // 0x8001D298: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D29C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001D2A0: lhu         $t9, -0x3A68($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A68);
    // 0x8001D2A4: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001D2A8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001D2AC: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8001D2B0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001D2B4: lhu         $t3, -0x2F50($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2F50);
    // 0x8001D2B8: addiu       $t6, $t6, -0x3668
    ctx->r14 = ADD32(ctx->r14, -0X3668);
    // 0x8001D2BC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8001D2C0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001D2C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001D2C8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001D2CC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001D2D0: addiu       $t5, $t4, 0x24
    ctx->r13 = ADD32(ctx->r12, 0X24);
    // 0x8001D2D4: b           L_8001D2E4
    // 0x8001D2D8: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
        goto L_8001D2E4;
    // 0x8001D2D8: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
L_8001D2DC:
    // 0x8001D2DC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001D2E0: addiu       $t0, $t0, -0x4534
    ctx->r8 = ADD32(ctx->r8, -0X4534);
L_8001D2E4:
    // 0x8001D2E4: lw          $t7, 0x68($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X68);
    // 0x8001D2E8: lw          $t8, 0x64($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X64);
    // 0x8001D2EC: lwc1        $f16, 0x24($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8001D2F0: lwc1        $f8, 0x90($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X90);
    // 0x8001D2F4: lwc1        $f10, 0x18($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8001D2F8: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001D2FC: nop

    // 0x8001D300: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001D304: beq         $v0, $zero, L_8001D314
    if (ctx->r2 == 0) {
        // 0x8001D308: add.s       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
            goto L_8001D314;
    }
    // 0x8001D308: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8001D30C: b           L_8001D318
    // 0x8001D310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001D318;
    // 0x8001D310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001D314:
    // 0x8001D314: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001D318:
    // 0x8001D318: ldc1        $f6, 0x1690($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1690);
    // 0x8001D31C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8001D320: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8001D324: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8001D328: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001D32C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8001D330: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8001D334: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8001D338: jal         0x80019A98
    // 0x8001D33C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80019A98(rdram, ctx);
        goto after_9;
    // 0x8001D33C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8001D340: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D344: sh          $v0, -0x3AA2($at)
    MEM_H(-0X3AA2, ctx->r1) = ctx->r2;
L_8001D348:
    // 0x8001D348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001D34C:
    // 0x8001D34C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D350: jr          $ra
    // 0x8001D354: nop

    return;
    // 0x8001D354: nop

;}
RECOMP_FUNC void func_800186B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800186B4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800186B8: lw          $t6, 0x7210($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7210);
    // 0x800186BC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800186C0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800186C4: beq         $t6, $zero, L_800186E4
    if (ctx->r14 == 0) {
        // 0x800186C8: addiu       $v1, $v1, 0x7210
        ctx->r3 = ADD32(ctx->r3, 0X7210);
            goto L_800186E4;
    }
    // 0x800186C8: addiu       $v1, $v1, 0x7210
    ctx->r3 = ADD32(ctx->r3, 0X7210);
    // 0x800186CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800186D0:
    // 0x800186D0: beq         $v0, $zero, L_800186E4
    if (ctx->r2 == 0) {
        // 0x800186D4: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800186E4;
    }
    // 0x800186D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800186D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800186DC: bnel        $t7, $zero, L_800186D0
    if (ctx->r15 != 0) {
        // 0x800186E0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800186D0;
    }
    goto skip_0;
    // 0x800186E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_800186E4:
    // 0x800186E4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800186E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800186EC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800186F0: jr          $ra
    // 0x800186F4: nop

    return;
    // 0x800186F4: nop

;}
RECOMP_FUNC void func_8010189C_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010189C: addiu       $sp, $sp, -0x648
    ctx->r29 = ADD32(ctx->r29, -0X648);
    // 0x801018A0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x801018A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801018A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801018AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801018B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801018B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801018B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801018BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801018C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801018C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801018C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801018CC: sw          $a0, 0x648($sp)
    MEM_W(0X648, ctx->r29) = ctx->r4;
    // 0x801018D0: addiu       $v1, $v1, 0x6FE8
    ctx->r3 = ADD32(ctx->r3, 0X6FE8);
    // 0x801018D4: addiu       $v0, $sp, 0x138
    ctx->r2 = ADD32(ctx->r29, 0X138);
    // 0x801018D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_801018DC:
    // 0x801018DC: sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
    // 0x801018E0: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x801018E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x801018E8: slti        $at, $a3, 0x96
    ctx->r1 = SIGNED(ctx->r7) < 0X96 ? 1 : 0;
    // 0x801018EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801018F0: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x801018F4: bne         $at, $zero, L_801018DC
    if (ctx->r1 != 0) {
        // 0x801018F8: sw          $t6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->r14;
            goto L_801018DC;
    }
    // 0x801018F8: sw          $t6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r14;
    // 0x801018FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80101900: addiu       $t0, $zero, 0x95
    ctx->r8 = ADD32(0, 0X95);
    // 0x80101904: addiu       $a1, $sp, 0x130
    ctx->r5 = ADD32(ctx->r29, 0X130);
    // 0x80101908: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
L_8010190C:
    // 0x8010190C: blez        $a2, L_80101960
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80101910: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80101960;
    }
    // 0x80101910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80101914: addiu       $v0, $sp, 0x138
    ctx->r2 = ADD32(ctx->r29, 0X138);
L_80101918:
    // 0x80101918: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8010191C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101920: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101924: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80101928: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x8010192C: beq         $at, $zero, L_80101958
    if (ctx->r1 == 0) {
        // 0x80101930: nop
    
            goto L_80101958;
    }
    // 0x80101930: nop

    // 0x80101934: lw          $at, 0x0($v1)
    ctx->r1 = MEM_W(ctx->r3, 0X0);
    // 0x80101938: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8010193C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80101940: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80101944: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80101948: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x8010194C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80101950: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80101954: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80101958:
    // 0x80101958: bne         $a0, $a2, L_80101918
    if (ctx->r4 != ctx->r6) {
        // 0x8010195C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80101918;
    }
    // 0x8010195C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80101960:
    // 0x80101960: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80101964: slti        $at, $a3, 0x95
    ctx->r1 = SIGNED(ctx->r7) < 0X95 ? 1 : 0;
    // 0x80101968: bnel        $at, $zero, L_8010190C
    if (ctx->r1 != 0) {
        // 0x8010196C: subu        $a2, $t0, $a3
        ctx->r6 = SUB32(ctx->r8, ctx->r7);
            goto L_8010190C;
    }
    goto skip_0;
    // 0x8010196C: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
    skip_0:
    // 0x80101970: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80101974: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x80101978: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010197C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80101980: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x80101984: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101988: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8010198C: ori         $t3, $t3, 0x4240
    ctx->r11 = ctx->r11 | 0X4240;
    // 0x80101990: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80101994: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101998: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8010199C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801019A0: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x801019A4: ori         $t5, $t5, 0xC02
    ctx->r13 = ctx->r13 | 0XC02;
    // 0x801019A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801019AC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801019B0: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x801019B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801019B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801019BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801019C0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x801019C4: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x801019C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801019CC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801019D0: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x801019D4: addiu       $fp, $sp, 0x138
    ctx->r30 = ADD32(ctx->r29, 0X138);
    // 0x801019D8: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x801019DC: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
    // 0x801019E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801019E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801019E8: lhu         $s3, 0x4($fp)
    ctx->r19 = MEM_HU(ctx->r30, 0X4);
L_801019EC:
    // 0x801019EC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x801019F0: addiu       $t4, $t4, 0x6FE8
    ctx->r12 = ADD32(ctx->r12, 0X6FE8);
    // 0x801019F4: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x801019F8: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x801019FC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80101A00: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x80101A04: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80101A08: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80101A0C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80101A10: sll         $t5, $a2, 0
    ctx->r13 = S32(ctx->r6 << 0);
    // 0x80101A14: bgez        $t5, L_8010289C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80101A18: lw          $t6, 0x648($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X648);
            goto L_8010289C;
    }
    // 0x80101A18: lw          $t6, 0x648($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X648);
    // 0x80101A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80101A20: bne         $t6, $at, L_80101A3C
    if (ctx->r14 != ctx->r1) {
        // 0x80101A24: lw          $t8, 0x648($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X648);
            goto L_80101A3C;
    }
    // 0x80101A24: lw          $t8, 0x648($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X648);
    // 0x80101A28: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x80101A2C: bltzl       $t7, L_80101A4C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80101A30: andi        $t3, $a2, 0x800
        ctx->r11 = ctx->r6 & 0X800;
            goto L_80101A4C;
    }
    goto skip_1;
    // 0x80101A30: andi        $t3, $a2, 0x800
    ctx->r11 = ctx->r6 & 0X800;
    skip_1:
    // 0x80101A34: b           L_801028A0
    // 0x80101A38: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
        goto L_801028A0;
    // 0x80101A38: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
L_80101A3C:
    // 0x80101A3C: bne         $t8, $zero, L_80101A48
    if (ctx->r24 != 0) {
        // 0x80101A40: sll         $t9, $a2, 8
        ctx->r25 = S32(ctx->r6 << 8);
            goto L_80101A48;
    }
    // 0x80101A40: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x80101A44: bltz        $t9, L_8010289C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80101A48: andi        $t3, $a2, 0x800
        ctx->r11 = ctx->r6 & 0X800;
            goto L_8010289C;
    }
L_80101A48:
    // 0x80101A48: andi        $t3, $a2, 0x800
    ctx->r11 = ctx->r6 & 0X800;
L_80101A4C:
    // 0x80101A4C: beq         $t3, $zero, L_80101A70
    if (ctx->r11 == 0) {
        // 0x80101A50: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_80101A70;
    }
    // 0x80101A50: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80101A54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101A58: jal         0x80101284
    // 0x80101A5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80101284_ovl_ending(rdram, ctx);
        goto after_0;
    // 0x80101A5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80101A60: beq         $v0, $zero, L_80101A70
    if (ctx->r2 == 0) {
        // 0x80101A64: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_80101A70;
    }
    // 0x80101A64: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80101A68: and         $t4, $s1, $at
    ctx->r12 = ctx->r17 & ctx->r1;
    // 0x80101A6C: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80101A70:
    // 0x80101A70: andi        $t5, $s1, 0x4000
    ctx->r13 = ctx->r17 & 0X4000;
    // 0x80101A74: beq         $t5, $zero, L_80101A94
    if (ctx->r13 == 0) {
        // 0x80101A78: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80101A94;
    }
    // 0x80101A78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101A7C: jal         0x80101534
    // 0x80101A80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80101534_ovl_ending(rdram, ctx);
        goto after_1;
    // 0x80101A80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80101A84: beq         $v0, $zero, L_80101A94
    if (ctx->r2 == 0) {
        // 0x80101A88: addiu       $at, $zero, -0x4001
        ctx->r1 = ADD32(0, -0X4001);
            goto L_80101A94;
    }
    // 0x80101A88: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80101A8C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x80101A90: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80101A94:
    // 0x80101A94: andi        $t7, $s1, 0x8000
    ctx->r15 = ctx->r17 & 0X8000;
    // 0x80101A98: beq         $t7, $zero, L_80101ABC
    if (ctx->r15 == 0) {
        // 0x80101A9C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80101ABC;
    }
    // 0x80101A9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101AA0: jal         0x801016B4
    // 0x80101AA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_801016B4_ovl_ending(rdram, ctx);
        goto after_2;
    // 0x80101AA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80101AA8: beq         $v0, $zero, L_80101ABC
    if (ctx->r2 == 0) {
        // 0x80101AAC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80101ABC;
    }
    // 0x80101AAC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80101AB0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80101AB4: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x80101AB8: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
L_80101ABC:
    // 0x80101ABC: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x80101AC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101AC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80101AC8: sw          $t9, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r25;
    // 0x80101ACC: lh          $t3, 0x6($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X6);
    // 0x80101AD0: sw          $t3, 0x610($sp)
    MEM_W(0X610, ctx->r29) = ctx->r11;
    // 0x80101AD4: lh          $t4, 0xC($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XC);
    // 0x80101AD8: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80101ADC: sw          $t4, 0x614($sp)
    MEM_W(0X614, ctx->r29) = ctx->r12;
    // 0x80101AE0: lh          $t5, 0xE($s2)
    ctx->r13 = MEM_H(ctx->r18, 0XE);
    // 0x80101AE4: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80101AE8: sw          $t5, 0x618($sp)
    MEM_W(0X618, ctx->r29) = ctx->r13;
    // 0x80101AEC: lh          $t6, 0x8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X8);
    // 0x80101AF0: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80101AF4: sw          $t6, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r14;
    // 0x80101AF8: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x80101AFC: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80101B00: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
    // 0x80101B04: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x80101B08: lw          $t7, 0x618($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X618);
    // 0x80101B0C: sw          $t8, 0x624($sp)
    MEM_W(0X624, ctx->r29) = ctx->r24;
    // 0x80101B10: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x80101B14: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80101B18: sw          $t3, 0x62C($sp)
    MEM_W(0X62C, ctx->r29) = ctx->r11;
    // 0x80101B1C: sw          $t9, 0x628($sp)
    MEM_W(0X628, ctx->r29) = ctx->r25;
    // 0x80101B20: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80101B24: sw          $t4, 0x630($sp)
    MEM_W(0X630, ctx->r29) = ctx->r12;
    // 0x80101B28: sw          $t6, 0x634($sp)
    MEM_W(0X634, ctx->r29) = ctx->r14;
    // 0x80101B2C: bgez        $t9, L_80101B50
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80101B30: sw          $t8, 0x638($sp)
        MEM_W(0X638, ctx->r29) = ctx->r24;
            goto L_80101B50;
    }
    // 0x80101B30: sw          $t8, 0x638($sp)
    MEM_W(0X638, ctx->r29) = ctx->r24;
    // 0x80101B34: jal         0x80100D80
    // 0x80101B38: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    func_80100D80_ovl_ending(rdram, ctx);
        goto after_3;
    // 0x80101B38: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    after_3:
    // 0x80101B3C: beq         $v0, $zero, L_80101B50
    if (ctx->r2 == 0) {
        // 0x80101B40: lui         $at, 0xDFFF
        ctx->r1 = S32(0XDFFF << 16);
            goto L_80101B50;
    }
    // 0x80101B40: lui         $at, 0xDFFF
    ctx->r1 = S32(0XDFFF << 16);
    // 0x80101B44: ori         $at, $at, 0xFEFF
    ctx->r1 = ctx->r1 | 0XFEFF;
    // 0x80101B48: and         $t3, $s1, $at
    ctx->r11 = ctx->r17 & ctx->r1;
    // 0x80101B4C: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80101B50:
    // 0x80101B50: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80101B54: bgez        $t4, L_80101B7C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80101B58: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80101B7C;
    }
    // 0x80101B58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101B5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80101B60: jal         0x80100EE4
    // 0x80101B64: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    func_80100EE4_ovl_ending(rdram, ctx);
        goto after_4;
    // 0x80101B64: addiu       $a2, $sp, 0x60C
    ctx->r6 = ADD32(ctx->r29, 0X60C);
    after_4:
    // 0x80101B68: beq         $v0, $zero, L_80101B7C
    if (ctx->r2 == 0) {
        // 0x80101B6C: lui         $at, 0xBFFF
        ctx->r1 = S32(0XBFFF << 16);
            goto L_80101B7C;
    }
    // 0x80101B6C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x80101B70: ori         $at, $at, 0xFBFF
    ctx->r1 = ctx->r1 | 0XFBFF;
    // 0x80101B74: and         $t5, $s1, $at
    ctx->r13 = ctx->r17 & ctx->r1;
    // 0x80101B78: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_80101B7C:
    // 0x80101B7C: andi        $t6, $s1, 0x10
    ctx->r14 = ctx->r17 & 0X10;
    // 0x80101B80: beq         $t6, $zero, L_80101BA8
    if (ctx->r14 == 0) {
        // 0x80101B84: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80101BA8;
    }
    // 0x80101B84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101B88: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80101B8C: jal         0x8010107C
    // 0x80101B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010107C_ovl_ending(rdram, ctx);
        goto after_5;
    // 0x80101B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80101B94: beq         $v0, $zero, L_80101BA8
    if (ctx->r2 == 0) {
        // 0x80101B98: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_80101BA8;
    }
    // 0x80101B98: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80101B9C: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x80101BA0: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80101BA4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80101BA8:
    // 0x80101BA8: andi        $t8, $s1, 0x20
    ctx->r24 = ctx->r17 & 0X20;
    // 0x80101BAC: beq         $t8, $zero, L_80101BD8
    if (ctx->r24 == 0) {
        // 0x80101BB0: ori         $t9, $s4, 0x20
        ctx->r25 = ctx->r20 | 0X20;
            goto L_80101BD8;
    }
    // 0x80101BB0: ori         $t9, $s4, 0x20
    ctx->r25 = ctx->r20 | 0X20;
    // 0x80101BB4: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x80101BB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101BBC: jal         0x8010107C
    // 0x80101BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010107C_ovl_ending(rdram, ctx);
        goto after_6;
    // 0x80101BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80101BC4: beq         $v0, $zero, L_80101BD8
    if (ctx->r2 == 0) {
        // 0x80101BC8: addiu       $at, $zero, -0x21
        ctx->r1 = ADD32(0, -0X21);
            goto L_80101BD8;
    }
    // 0x80101BC8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80101BCC: and         $t3, $s1, $at
    ctx->r11 = ctx->r17 & ctx->r1;
    // 0x80101BD0: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80101BD4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80101BD8:
    // 0x80101BD8: andi        $t4, $s1, 0x40
    ctx->r12 = ctx->r17 & 0X40;
    // 0x80101BDC: beq         $t4, $zero, L_80101C08
    if (ctx->r12 == 0) {
        // 0x80101BE0: ori         $t5, $s4, 0x40
        ctx->r13 = ctx->r20 | 0X40;
            goto L_80101C08;
    }
    // 0x80101BE0: ori         $t5, $s4, 0x40
    ctx->r13 = ctx->r20 | 0X40;
    // 0x80101BE4: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x80101BE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101BEC: jal         0x80101180
    // 0x80101BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101180_ovl_ending(rdram, ctx);
        goto after_7;
    // 0x80101BF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80101BF4: beq         $v0, $zero, L_80101C08
    if (ctx->r2 == 0) {
        // 0x80101BF8: addiu       $at, $zero, -0x41
        ctx->r1 = ADD32(0, -0X41);
            goto L_80101C08;
    }
    // 0x80101BF8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80101BFC: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x80101C00: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80101C04: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80101C08:
    // 0x80101C08: andi        $t7, $s1, 0x80
    ctx->r15 = ctx->r17 & 0X80;
    // 0x80101C0C: beq         $t7, $zero, L_80101C38
    if (ctx->r15 == 0) {
        // 0x80101C10: ori         $t8, $s4, 0x80
        ctx->r24 = ctx->r20 | 0X80;
            goto L_80101C38;
    }
    // 0x80101C10: ori         $t8, $s4, 0x80
    ctx->r24 = ctx->r20 | 0X80;
    // 0x80101C14: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80101C18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80101C1C: jal         0x80101180
    // 0x80101C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101180_ovl_ending(rdram, ctx);
        goto after_8;
    // 0x80101C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80101C24: beq         $v0, $zero, L_80101C38
    if (ctx->r2 == 0) {
        // 0x80101C28: addiu       $at, $zero, -0x81
        ctx->r1 = ADD32(0, -0X81);
            goto L_80101C38;
    }
    // 0x80101C28: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80101C2C: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x80101C30: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80101C34: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80101C38:
    // 0x80101C38: andi        $t3, $s1, 0x1000
    ctx->r11 = ctx->r17 & 0X1000;
    // 0x80101C3C: beql        $t3, $zero, L_80101C60
    if (ctx->r11 == 0) {
        // 0x80101C40: sll         $t5, $s1, 3
        ctx->r13 = S32(ctx->r17 << 3);
            goto L_80101C60;
    }
    goto skip_2;
    // 0x80101C40: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    skip_2:
    // 0x80101C44: jal         0x80101834
    // 0x80101C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101834_ovl_ending(rdram, ctx);
        goto after_9;
    // 0x80101C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80101C4C: beq         $v0, $zero, L_80101C5C
    if (ctx->r2 == 0) {
        // 0x80101C50: addiu       $at, $zero, -0x1001
        ctx->r1 = ADD32(0, -0X1001);
            goto L_80101C5C;
    }
    // 0x80101C50: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80101C54: and         $t4, $s1, $at
    ctx->r12 = ctx->r17 & ctx->r1;
    // 0x80101C58: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80101C5C:
    // 0x80101C5C: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
L_80101C60:
    // 0x80101C60: bgez        $t5, L_80101C8C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80101C64: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_80101C8C;
    }
    // 0x80101C64: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80101C68: jal         0x80101834
    // 0x80101C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101834_ovl_ending(rdram, ctx);
        goto after_10;
    // 0x80101C6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80101C70: beq         $v0, $zero, L_80101C84
    if (ctx->r2 == 0) {
        // 0x80101C74: lui         $at, 0xEFFF
        ctx->r1 = S32(0XEFFF << 16);
            goto L_80101C84;
    }
    // 0x80101C74: lui         $at, 0xEFFF
    ctx->r1 = S32(0XEFFF << 16);
    // 0x80101C78: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80101C7C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x80101C80: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
L_80101C84:
    // 0x80101C84: b           L_8010289C
    // 0x80101C88: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_8010289C;
    // 0x80101C88: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80101C8C:
    // 0x80101C8C: lw          $a1, 0x6FC0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6FC0);
    // 0x80101C90: lw          $t7, 0x60C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60C);
    // 0x80101C94: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80101C98: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80101C9C: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80101CA0: beql        $at, $zero, L_80101D00
    if (ctx->r1 == 0) {
        // 0x80101CA4: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_80101D00;
    }
    goto skip_3;
    // 0x80101CA4: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_3:
    // 0x80101CA8: lw          $v0, 0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80101CAC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80101CB0: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80101CB4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101CB8: beql        $at, $zero, L_80101D00
    if (ctx->r1 == 0) {
        // 0x80101CBC: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_80101D00;
    }
    goto skip_4;
    // 0x80101CBC: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_4:
    // 0x80101CC0: lw          $t9, 0x6FC8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FC8);
    // 0x80101CC4: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80101CC8: lw          $t7, 0x620($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X620);
    // 0x80101CCC: addu        $t3, $a1, $t9
    ctx->r11 = ADD32(ctx->r5, ctx->r25);
    // 0x80101CD0: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80101CD4: beq         $at, $zero, L_80101CFC
    if (ctx->r1 == 0) {
        // 0x80101CD8: lui         $t6, 0x8015
        ctx->r14 = S32(0X8015 << 16);
            goto L_80101CFC;
    }
    // 0x80101CD8: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80101CDC: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80101CE0: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x80101CE4: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x80101CE8: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80101CEC: beql        $at, $zero, L_80101D00
    if (ctx->r1 == 0) {
        // 0x80101CF0: lw          $t3, 0x60C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60C);
            goto L_80101D00;
    }
    goto skip_5;
    // 0x80101CF0: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
    skip_5:
    // 0x80101CF4: b           L_8010289C
    // 0x80101CF8: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_8010289C;
    // 0x80101CF8: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80101CFC:
    // 0x80101CFC: lw          $t3, 0x60C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60C);
L_80101D00:
    // 0x80101D00: lw          $t5, 0x61C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X61C);
    // 0x80101D04: lw          $t6, 0x610($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X610);
    // 0x80101D08: lw          $t8, 0x620($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X620);
    // 0x80101D0C: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x80101D10: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80101D14: bne         $at, $zero, L_80101D34
    if (ctx->r1 != 0) {
        // 0x80101D18: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_80101D34;
    }
    // 0x80101D18: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80101D1C: lw          $v0, 0x6FC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC4);
    // 0x80101D20: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80101D24: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80101D28: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101D2C: beq         $at, $zero, L_80101D3C
    if (ctx->r1 == 0) {
        // 0x80101D30: nop
    
            goto L_80101D3C;
    }
    // 0x80101D30: nop

L_80101D34:
    // 0x80101D34: b           L_8010289C
    // 0x80101D38: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_8010289C;
    // 0x80101D38: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_80101D3C:
    // 0x80101D3C: lw          $t7, 0x6FC8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FC8);
    // 0x80101D40: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80101D44: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80101D48: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x80101D4C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80101D50: bne         $at, $zero, L_80101D70
    if (ctx->r1 != 0) {
        // 0x80101D54: nop
    
            goto L_80101D70;
    }
    // 0x80101D54: nop

    // 0x80101D58: lw          $t4, 0x6FCC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6FCC);
    // 0x80101D5C: lw          $t3, 0x610($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X610);
    // 0x80101D60: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x80101D64: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101D68: beql        $at, $zero, L_80101D7C
    if (ctx->r1 == 0) {
        // 0x80101D6C: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80101D7C;
    }
    goto skip_6;
    // 0x80101D6C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_6:
L_80101D70:
    // 0x80101D70: b           L_8010289C
    // 0x80101D74: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
        goto L_8010289C;
    // 0x80101D74: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x80101D78: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_80101D7C:
    // 0x80101D7C: beq         $at, $zero, L_80101D8C
    if (ctx->r1 == 0) {
        // 0x80101D80: lw          $t5, 0x60C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X60C);
            goto L_80101D8C;
    }
    // 0x80101D80: lw          $t5, 0x60C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60C);
    // 0x80101D84: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x80101D88: sw          $t6, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r14;
L_80101D8C:
    // 0x80101D8C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80101D90: beq         $at, $zero, L_80101DA0
    if (ctx->r1 == 0) {
        // 0x80101D94: lw          $t8, 0x610($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X610);
            goto L_80101DA0;
    }
    // 0x80101D94: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80101D98: subu        $t7, $a0, $t8
    ctx->r15 = SUB32(ctx->r4, ctx->r24);
    // 0x80101D9C: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
L_80101DA0:
    // 0x80101DA0: lw          $t9, 0x60C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60C);
    // 0x80101DA4: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80101DA8: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80101DAC: beq         $at, $zero, L_80101DDC
    if (ctx->r1 == 0) {
        // 0x80101DB0: addu        $t3, $t4, $t9
        ctx->r11 = ADD32(ctx->r12, ctx->r25);
            goto L_80101DDC;
    }
    // 0x80101DB0: addu        $t3, $t4, $t9
    ctx->r11 = ADD32(ctx->r12, ctx->r25);
    // 0x80101DB4: subu        $t5, $t3, $a1
    ctx->r13 = SUB32(ctx->r11, ctx->r5);
    // 0x80101DB8: lw          $t4, 0x634($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X634);
    // 0x80101DBC: sw          $t5, 0x61C($sp)
    MEM_W(0X61C, ctx->r29) = ctx->r13;
    // 0x80101DC0: lh          $t6, 0xC($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XC);
    // 0x80101DC4: subu        $t8, $a1, $t9
    ctx->r24 = SUB32(ctx->r5, ctx->r25);
    // 0x80101DC8: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80101DCC: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x80101DD0: sw          $t3, 0x634($sp)
    MEM_W(0X634, ctx->r29) = ctx->r11;
    // 0x80101DD4: sw          $a1, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r5;
    // 0x80101DD8: sw          $t6, 0x614($sp)
    MEM_W(0X614, ctx->r29) = ctx->r14;
L_80101DDC:
    // 0x80101DDC: lh          $t5, 0x6($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X6);
    // 0x80101DE0: lw          $t6, 0x620($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X620);
    // 0x80101DE4: lw          $t9, 0x610($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X610);
    // 0x80101DE8: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101DEC: beq         $at, $zero, L_80101E1C
    if (ctx->r1 == 0) {
        // 0x80101DF0: addu        $t8, $t6, $t9
        ctx->r24 = ADD32(ctx->r14, ctx->r25);
            goto L_80101E1C;
    }
    // 0x80101DF0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80101DF4: subu        $t7, $t8, $v0
    ctx->r15 = SUB32(ctx->r24, ctx->r2);
    // 0x80101DF8: lw          $t6, 0x638($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X638);
    // 0x80101DFC: sw          $t7, 0x620($sp)
    MEM_W(0X620, ctx->r29) = ctx->r15;
    // 0x80101E00: lh          $t4, 0xE($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XE);
    // 0x80101E04: subu        $t3, $v0, $t9
    ctx->r11 = SUB32(ctx->r2, ctx->r25);
    // 0x80101E08: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x80101E0C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80101E10: sw          $t8, 0x638($sp)
    MEM_W(0X638, ctx->r29) = ctx->r24;
    // 0x80101E14: sw          $v0, 0x610($sp)
    MEM_W(0X610, ctx->r29) = ctx->r2;
    // 0x80101E18: sw          $t4, 0x618($sp)
    MEM_W(0X618, ctx->r29) = ctx->r12;
L_80101E1C:
    // 0x80101E1C: bne         $s4, $zero, L_80101E38
    if (ctx->r20 != 0) {
        // 0x80101E20: andi        $t9, $s4, 0x30
        ctx->r25 = ctx->r20 & 0X30;
            goto L_80101E38;
    }
    // 0x80101E20: andi        $t9, $s4, 0x30
    ctx->r25 = ctx->r20 & 0X30;
    // 0x80101E24: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80101E28: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80101E2C: sw          $t7, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r15;
    // 0x80101E30: b           L_80101E6C
    // 0x80101E34: sw          $t4, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r12;
        goto L_80101E6C;
    // 0x80101E34: sw          $t4, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r12;
L_80101E38:
    // 0x80101E38: beq         $t9, $zero, L_80101E54
    if (ctx->r25 == 0) {
        // 0x80101E3C: andi        $t6, $s4, 0xC0
        ctx->r14 = ctx->r20 & 0XC0;
            goto L_80101E54;
    }
    // 0x80101E3C: andi        $t6, $s4, 0xC0
    ctx->r14 = ctx->r20 & 0XC0;
    // 0x80101E40: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80101E44: sw          $t3, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r11;
    // 0x80101E48: lh          $t5, 0x4E($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X4E);
    // 0x80101E4C: b           L_80101E6C
    // 0x80101E50: sw          $t5, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r13;
        goto L_80101E6C;
    // 0x80101E50: sw          $t5, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r13;
L_80101E54:
    // 0x80101E54: beql        $t6, $zero, L_80101E70
    if (ctx->r14 == 0) {
        // 0x80101E58: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80101E70;
    }
    goto skip_7;
    // 0x80101E58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_7:
    // 0x80101E5C: lh          $t8, 0x4E($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4E);
    // 0x80101E60: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80101E64: sw          $t7, 0x63C($sp)
    MEM_W(0X63C, ctx->r29) = ctx->r15;
    // 0x80101E68: sw          $t8, 0x640($sp)
    MEM_W(0X640, ctx->r29) = ctx->r24;
L_80101E6C:
    // 0x80101E6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80101E70:
    // 0x80101E70: andi        $t9, $s1, 0xF0
    ctx->r25 = ctx->r17 & 0XF0;
    // 0x80101E74: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80101E78: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80101E7C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80101E80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101E84: bne         $t9, $zero, L_80101E94
    if (ctx->r25 != 0) {
        // 0x80101E88: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_80101E94;
    }
    // 0x80101E88: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80101E8C: beq         $s5, $zero, L_80101EF4
    if (ctx->r21 == 0) {
        // 0x80101E90: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_80101EF4;
    }
    // 0x80101E90: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
L_80101E94:
    // 0x80101E94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101E98: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80101E9C: addiu       $t6, $t6, 0x3658
    ctx->r14 = ADD32(ctx->r14, 0X3658);
    // 0x80101EA0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80101EA4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80101EA8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101EAC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80101EB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101EB4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80101EB8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101EBC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80101EC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101EC4: lw          $v1, 0x640($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X640);
    // 0x80101EC8: lw          $t7, 0x63C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X63C);
    // 0x80101ECC: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x80101ED0: sll         $t9, $t4, 24
    ctx->r25 = S32(ctx->r12 << 24);
    // 0x80101ED4: sll         $t3, $t4, 16
    ctx->r11 = S32(ctx->r12 << 16);
    // 0x80101ED8: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x80101EDC: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x80101EE0: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80101EE4: andi        $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 & 0XFF;
    // 0x80101EE8: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x80101EEC: b           L_80101F10
    // 0x80101EF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80101F10;
    // 0x80101EF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80101EF4:
    // 0x80101EF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101EF8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80101EFC: addiu       $t6, $t6, 0x3628
    ctx->r14 = ADD32(ctx->r14, 0X3628);
    // 0x80101F00: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80101F04: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80101F08: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101F0C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80101F10:
    // 0x80101F10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101F14: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80101F18: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101F1C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80101F20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101F24: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80101F28: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80101F2C: and         $t8, $a2, $at
    ctx->r24 = ctx->r6 & ctx->r1;
    // 0x80101F30: beq         $t8, $zero, L_80102414
    if (ctx->r24 == 0) {
        // 0x80101F34: sll         $t4, $a2, 4
        ctx->r12 = S32(ctx->r6 << 4);
            goto L_80102414;
    }
    // 0x80101F34: sll         $t4, $a2, 4
    ctx->r12 = S32(ctx->r6 << 4);
    // 0x80101F38: bgez        $t4, L_801021A0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80101F3C: sll         $t6, $a2, 5
        ctx->r14 = S32(ctx->r6 << 5);
            goto L_801021A0;
    }
    // 0x80101F3C: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x80101F40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101F44: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x80101F48: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80101F4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101F50: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80101F54: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80101F58: lw          $t5, 0x14($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X14);
    // 0x80101F5C: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x80101F60: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x80101F64: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80101F68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101F6C: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80101F70: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80101F74: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101F78: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80101F7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101F80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101F84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101F88: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80101F8C: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80101F90: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101F94: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80101F98: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80101F9C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80101FA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101FA4: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80101FA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101FAC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80101FB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101FB4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80101FB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101FBC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80101FC0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80101FC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101FC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101FD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101FD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80101FD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101FDC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80101FE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80101FE4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80101FE8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80101FEC: lh          $t9, 0x10($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X10);
    // 0x80101FF0: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80101FF4: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80101FF8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80101FFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102000: lw          $t7, 0x18($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X18);
    // 0x80102004: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102008: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010200C: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102010: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x80102014: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102018: addu        $t3, $t4, $t9
    ctx->r11 = ADD32(ctx->r12, ctx->r25);
    // 0x8010201C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80102020: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x80102024: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102028: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8010202C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80102030: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80102034: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80102038: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x8010203C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102040: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80102044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102048: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8010204C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80102050: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102054: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102058: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010205C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80102060: lw          $t7, 0x614($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X614);
    // 0x80102064: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102068: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x8010206C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80102070: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102074: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102078: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8010207C: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x80102080: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80102084: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80102088: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8010208C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80102090: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102094: lw          $t3, 0x624($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X624);
    // 0x80102098: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x8010209C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x801020A0: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x801020A4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801020A8: lw          $t5, 0x628($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X628);
    // 0x801020AC: lw          $t3, 0x618($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X618);
    // 0x801020B0: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x801020B4: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x801020B8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x801020BC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801020C0: addiu       $t4, $t6, -0x1
    ctx->r12 = ADD32(ctx->r14, -0X1);
    // 0x801020C4: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x801020C8: or          $t9, $t8, $s6
    ctx->r25 = ctx->r24 | ctx->r22;
    // 0x801020CC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801020D0: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x801020D4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801020D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801020DC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801020E0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801020E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801020E8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801020EC: lw          $t7, 0x624($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X624);
    // 0x801020F0: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x801020F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801020F8: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x801020FC: subu        $t8, $t9, $t4
    ctx->r24 = SUB32(ctx->r25, ctx->r12);
    // 0x80102100: addiu       $t3, $t8, 0x7
    ctx->r11 = ADD32(ctx->r24, 0X7);
    // 0x80102104: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102108: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8010210C: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80102110: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80102114: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80102118: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8010211C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102124: lw          $t8, 0x614($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X614);
    // 0x80102128: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010212C: lw          $t9, 0x618($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X618);
    // 0x80102130: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80102134: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102138: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8010213C: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x80102140: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80102144: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102148: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8010214C: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80102150: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80102154: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x80102158: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8010215C: lw          $t6, 0x624($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X624);
    // 0x80102160: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x80102164: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80102168: lw          $t6, 0x628($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X628);
    // 0x8010216C: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x80102170: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80102174: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80102178: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8010217C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80102180: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80102184: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80102188: sll         $t3, $t8, 12
    ctx->r11 = S32(ctx->r24 << 12);
    // 0x8010218C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80102190: or          $t5, $t3, $t8
    ctx->r13 = ctx->r11 | ctx->r24;
    // 0x80102194: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102198: b           L_801025F8
    // 0x8010219C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
        goto L_801025F8;
    // 0x8010219C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_801021A0:
    // 0x801021A0: bgezl       $t6, L_801025FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801021A4: lui         $at, 0x6
        ctx->r1 = S32(0X6 << 16);
            goto L_801025FC;
    }
    goto skip_8;
    // 0x801021A4: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    skip_8:
    // 0x801021A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801021AC: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x801021B0: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x801021B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801021B8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801021BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801021C0: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x801021C4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x801021C8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x801021CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801021D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801021D4: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x801021D8: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x801021DC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801021E0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801021E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801021E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801021EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801021F0: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x801021F4: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x801021F8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801021FC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102200: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80102204: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102208: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010220C: lui         $t3, 0xF000
    ctx->r11 = S32(0XF000 << 16);
    // 0x80102210: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102214: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102218: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010221C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102220: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102224: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102228: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8010222C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102230: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102234: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102238: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8010223C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80102240: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102244: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102248: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010224C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102250: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102254: lh          $t9, 0x10($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X10);
    // 0x80102258: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8010225C: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x80102260: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x80102264: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x80102268: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010226C: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x80102270: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102274: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102278: lw          $t4, 0x624($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X624);
    // 0x8010227C: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x80102280: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102284: addu        $t7, $t9, $t4
    ctx->r15 = ADD32(ctx->r25, ctx->r12);
    // 0x80102288: subu        $t3, $t7, $t9
    ctx->r11 = SUB32(ctx->r15, ctx->r25);
    // 0x8010228C: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80102290: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102294: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102298: addiu       $t5, $t8, 0x7
    ctx->r13 = ADD32(ctx->r24, 0X7);
    // 0x8010229C: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x801022A0: andi        $t4, $t6, 0x1FF
    ctx->r12 = ctx->r14 & 0X1FF;
    // 0x801022A4: sll         $t7, $t4, 9
    ctx->r15 = S32(ctx->r12 << 9);
    // 0x801022A8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x801022AC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801022B0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x801022B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801022B8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x801022BC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801022C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801022C4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801022C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801022CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801022D0: lw          $t6, 0x614($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X614);
    // 0x801022D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801022D8: lw          $t8, 0x618($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X618);
    // 0x801022DC: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x801022E0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801022E4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801022E8: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x801022EC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x801022F0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x801022F4: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x801022F8: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x801022FC: or          $t4, $t3, $t6
    ctx->r12 = ctx->r11 | ctx->r14;
    // 0x80102300: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102304: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x80102308: lw          $t7, 0x614($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X614);
    // 0x8010230C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80102310: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80102314: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x80102318: lw          $t8, 0x628($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X628);
    // 0x8010231C: lw          $t9, 0x618($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X618);
    // 0x80102320: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80102324: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x80102328: sll         $t4, $t6, 12
    ctx->r12 = S32(ctx->r14 << 12);
    // 0x8010232C: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x80102330: addiu       $t3, $t5, -0x1
    ctx->r11 = ADD32(ctx->r13, -0X1);
    // 0x80102334: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80102338: or          $t7, $t4, $s6
    ctx->r15 = ctx->r12 | ctx->r22;
    // 0x8010233C: andi        $t4, $t6, 0xFFF
    ctx->r12 = ctx->r14 & 0XFFF;
    // 0x80102340: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x80102344: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102348: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010234C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102350: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102354: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102358: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8010235C: lw          $t6, 0x624($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X624);
    // 0x80102360: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x80102364: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102368: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8010236C: subu        $t4, $t7, $t3
    ctx->r12 = SUB32(ctx->r15, ctx->r11);
    // 0x80102370: sra         $t9, $t4, 1
    ctx->r25 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80102374: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102378: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8010237C: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80102380: sra         $t5, $t8, 3
    ctx->r13 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80102384: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80102388: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8010238C: or          $t3, $t7, $at
    ctx->r11 = ctx->r15 | ctx->r1;
    // 0x80102390: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102394: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102398: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x8010239C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801023A0: lw          $t3, 0x618($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X618);
    // 0x801023A4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801023A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801023AC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801023B0: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x801023B4: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x801023B8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801023BC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801023C0: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x801023C4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801023C8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x801023CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801023D0: lw          $t6, 0x624($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X624);
    // 0x801023D4: lw          $t5, 0x614($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X614);
    // 0x801023D8: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x801023DC: lw          $t6, 0x628($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X628);
    // 0x801023E0: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x801023E4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801023E8: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x801023EC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x801023F0: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x801023F4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801023F8: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x801023FC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80102400: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80102404: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x80102408: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8010240C: b           L_801025F8
    // 0x80102410: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
        goto L_801025F8;
    // 0x80102410: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_80102414:
    // 0x80102414: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102418: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8010241C: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x80102420: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102424: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102428: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010242C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80102430: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102434: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x80102438: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8010243C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102440: lh          $t7, 0x10($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X10);
    // 0x80102444: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80102448: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8010244C: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x80102450: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80102454: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x80102458: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8010245C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102460: lw          $t7, 0x624($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X624);
    // 0x80102464: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x80102468: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010246C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80102470: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x80102474: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80102478: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8010247C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102480: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x80102484: sra         $t3, $t6, 3
    ctx->r11 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80102488: andi        $t7, $t3, 0x1FF
    ctx->r15 = ctx->r11 & 0X1FF;
    // 0x8010248C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80102490: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80102494: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102498: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8010249C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801024A0: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x801024A4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801024A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801024AC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801024B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801024B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801024B8: lw          $t3, 0x614($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X614);
    // 0x801024BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801024C0: lw          $t5, 0x618($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X618);
    // 0x801024C4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x801024C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801024CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801024D0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801024D4: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x801024D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801024DC: andi        $t3, $t6, 0xFFF
    ctx->r11 = ctx->r14 & 0XFFF;
    // 0x801024E0: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x801024E4: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x801024E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801024EC: lw          $t4, 0x624($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X624);
    // 0x801024F0: lw          $t8, 0x614($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X614);
    // 0x801024F4: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x801024F8: addu        $t5, $t8, $t4
    ctx->r13 = ADD32(ctx->r24, ctx->r12);
    // 0x801024FC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80102500: lw          $t5, 0x628($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X628);
    // 0x80102504: lw          $t4, 0x618($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X618);
    // 0x80102508: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8010250C: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x80102510: sll         $t7, $t3, 12
    ctx->r15 = S32(ctx->r11 << 12);
    // 0x80102514: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80102518: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8010251C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80102520: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x80102524: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80102528: or          $t4, $t8, $t7
    ctx->r12 = ctx->r24 | ctx->r15;
    // 0x8010252C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80102530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102534: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102538: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8010253C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102540: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102544: lw          $t3, 0x624($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X624);
    // 0x80102548: lw          $t9, 0x614($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X614);
    // 0x8010254C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102550: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x80102554: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x80102558: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x8010255C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102560: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80102564: addiu       $t5, $t4, 0x7
    ctx->r13 = ADD32(ctx->r12, 0X7);
    // 0x80102568: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8010256C: andi        $t3, $t6, 0x1FF
    ctx->r11 = ctx->r14 & 0X1FF;
    // 0x80102570: sll         $t8, $t3, 9
    ctx->r24 = S32(ctx->r11 << 9);
    // 0x80102574: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80102578: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010257C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102580: lw          $t4, 0x614($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X614);
    // 0x80102584: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102588: lw          $t9, 0x618($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X618);
    // 0x8010258C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80102590: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102594: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102598: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8010259C: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x801025A0: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801025A4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x801025A8: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x801025AC: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x801025B0: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x801025B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801025B8: lw          $t3, 0x624($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X624);
    // 0x801025BC: lw          $t6, 0x614($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X614);
    // 0x801025C0: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x801025C4: lw          $t3, 0x628($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X628);
    // 0x801025C8: lw          $t6, 0x618($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X618);
    // 0x801025CC: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x801025D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801025D4: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x801025D8: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x801025DC: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x801025E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801025E4: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x801025E8: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x801025EC: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x801025F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801025F4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_801025F8:
    // 0x801025F8: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
L_801025FC:
    // 0x801025FC: and         $t3, $a2, $at
    ctx->r11 = ctx->r6 & ctx->r1;
    // 0x80102600: beq         $t3, $zero, L_801027C8
    if (ctx->r11 == 0) {
        // 0x80102604: sll         $t9, $a2, 14
        ctx->r25 = S32(ctx->r6 << 14);
            goto L_801027C8;
    }
    // 0x80102604: sll         $t9, $a2, 14
    ctx->r25 = S32(ctx->r6 << 14);
    // 0x80102608: bgez        $t9, L_801026EC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8010260C: addiu       $t4, $zero, -0x400
        ctx->r12 = ADD32(0, -0X400);
            goto L_801026EC;
    }
    // 0x8010260C: addiu       $t4, $zero, -0x400
    ctx->r12 = ADD32(0, -0X400);
    // 0x80102610: lw          $t5, 0x60C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60C);
    // 0x80102614: lw          $t4, 0x61C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X61C);
    // 0x80102618: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010261C: addiu       $t7, $zero, -0x400
    ctx->r15 = ADD32(0, -0X400);
    // 0x80102620: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80102624: lw          $t4, 0x620($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X620);
    // 0x80102628: lw          $t5, 0x610($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X610);
    // 0x8010262C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80102630: sw          $t7, 0x62C($sp)
    MEM_W(0X62C, ctx->r29) = ctx->r15;
    // 0x80102634: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80102638: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8010263C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102640: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80102644: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80102648: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8010264C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102650: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80102654: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80102658: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8010265C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102660: lw          $t5, 0x60C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60C);
    // 0x80102664: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80102668: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8010266C: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80102670: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80102674: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80102678: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x8010267C: or          $t5, $t3, $t7
    ctx->r13 = ctx->r11 | ctx->r15;
    // 0x80102680: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102684: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102688: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8010268C: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x80102690: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80102694: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80102698: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010269C: lw          $t9, 0x624($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X624);
    // 0x801026A0: lw          $t8, 0x614($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X614);
    // 0x801026A4: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x801026A8: lw          $t8, 0x638($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X638);
    // 0x801026AC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801026B0: sll         $t6, $t4, 21
    ctx->r14 = S32(ctx->r12 << 21);
    // 0x801026B4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x801026B8: or          $t3, $t6, $t9
    ctx->r11 = ctx->r14 | ctx->r25;
    // 0x801026BC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801026C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801026C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801026C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801026CC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801026D0: lw          $t3, 0x630($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X630);
    // 0x801026D4: lw          $t6, 0x62C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X62C);
    // 0x801026D8: andi        $t7, $t3, 0xFFFF
    ctx->r15 = ctx->r11 & 0XFFFF;
    // 0x801026DC: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x801026E0: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x801026E4: b           L_8010288C
    // 0x801026E8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8010288C;
    // 0x801026E8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_801026EC:
    // 0x801026EC: lw          $t6, 0x60C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60C);
    // 0x801026F0: lw          $t3, 0x61C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X61C);
    // 0x801026F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801026F8: sw          $t4, 0x630($sp)
    MEM_W(0X630, ctx->r29) = ctx->r12;
    // 0x801026FC: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80102700: lw          $t3, 0x620($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X620);
    // 0x80102704: lw          $t6, 0x610($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X610);
    // 0x80102708: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8010270C: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x80102710: sll         $t4, $t5, 12
    ctx->r12 = S32(ctx->r13 << 12);
    // 0x80102714: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102718: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x8010271C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80102720: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80102724: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102728: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x8010272C: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x80102730: or          $t4, $t8, $t5
    ctx->r12 = ctx->r24 | ctx->r13;
    // 0x80102734: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80102738: lw          $t6, 0x60C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60C);
    // 0x8010273C: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x80102740: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80102744: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80102748: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8010274C: andi        $t4, $t5, 0xFFF
    ctx->r12 = ctx->r13 & 0XFFF;
    // 0x80102750: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80102754: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x80102758: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010275C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102760: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80102764: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102768: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8010276C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102770: lw          $t5, 0x628($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X628);
    // 0x80102774: lw          $t8, 0x618($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X618);
    // 0x80102778: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x8010277C: lw          $t8, 0x634($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X634);
    // 0x80102780: addiu       $t4, $t7, -0x1
    ctx->r12 = ADD32(ctx->r15, -0X1);
    // 0x80102784: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x80102788: andi        $t3, $t6, 0xFFFF
    ctx->r11 = ctx->r14 & 0XFFFF;
    // 0x8010278C: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80102790: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x80102794: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102798: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010279C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x801027A0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801027A4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801027A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801027AC: lw          $t7, 0x630($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X630);
    // 0x801027B0: lw          $t8, 0x62C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X62C);
    // 0x801027B4: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x801027B8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x801027BC: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x801027C0: b           L_8010288C
    // 0x801027C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8010288C;
    // 0x801027C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_801027C8:
    // 0x801027C8: lw          $t8, 0x60C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60C);
    // 0x801027CC: lw          $t3, 0x61C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X61C);
    // 0x801027D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801027D4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x801027D8: addu        $t7, $t8, $t3
    ctx->r15 = ADD32(ctx->r24, ctx->r11);
    // 0x801027DC: lw          $t3, 0x620($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X620);
    // 0x801027E0: lw          $t8, 0x610($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X610);
    // 0x801027E4: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x801027E8: andi        $t4, $t5, 0xFFF
    ctx->r12 = ctx->r13 & 0XFFF;
    // 0x801027EC: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x801027F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801027F4: addu        $t7, $t8, $t3
    ctx->r15 = ADD32(ctx->r24, ctx->r11);
    // 0x801027F8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x801027FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80102800: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80102804: andi        $t4, $t5, 0xFFF
    ctx->r12 = ctx->r13 & 0XFFF;
    // 0x80102808: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x8010280C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102810: lw          $t8, 0x60C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60C);
    // 0x80102814: lw          $t9, 0x610($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X610);
    // 0x80102818: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8010281C: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80102820: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80102824: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80102828: sll         $t5, $t7, 12
    ctx->r13 = S32(ctx->r15 << 12);
    // 0x8010282C: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80102830: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102834: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102838: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8010283C: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80102840: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80102844: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80102848: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010284C: lw          $t6, 0x638($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X638);
    // 0x80102850: lw          $t4, 0x634($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X634);
    // 0x80102854: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80102858: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8010285C: or          $t3, $t5, $t8
    ctx->r11 = ctx->r13 | ctx->r24;
    // 0x80102860: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80102864: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80102868: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010286C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80102870: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102874: lw          $t8, 0x630($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X630);
    // 0x80102878: lw          $t6, 0x62C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X62C);
    // 0x8010287C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80102880: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x80102884: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x80102888: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8010288C:
    // 0x8010288C: beq         $s5, $zero, L_80102898
    if (ctx->r21 == 0) {
        // 0x80102890: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80102898;
    }
    // 0x80102890: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80102894: sh          $t9, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r25;
L_80102898:
    // 0x80102898: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
L_8010289C:
    // 0x8010289C: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
L_801028A0:
    // 0x801028A0: addiu       $t4, $sp, 0x5E8
    ctx->r12 = ADD32(ctx->r29, 0X5E8);
    // 0x801028A4: bnel        $fp, $t4, L_801019EC
    if (ctx->r30 != ctx->r12) {
        // 0x801028A8: lhu         $s3, 0x4($fp)
        ctx->r19 = MEM_HU(ctx->r30, 0X4);
            goto L_801019EC;
    }
    goto skip_9;
    // 0x801028A8: lhu         $s3, 0x4($fp)
    ctx->r19 = MEM_HU(ctx->r30, 0X4);
    skip_9:
    // 0x801028AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801028B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801028B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801028B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801028BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801028C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801028C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801028C8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801028CC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801028D0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801028D4: jr          $ra
    // 0x801028D8: addiu       $sp, $sp, 0x648
    ctx->r29 = ADD32(ctx->r29, 0X648);
    return;
    // 0x801028D8: addiu       $sp, $sp, 0x648
    ctx->r29 = ADD32(ctx->r29, 0X648);
;}
RECOMP_FUNC void func_80003F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003F5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003F60: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80003F64: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80003F68: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80003F6C: lhu         $t6, 0x4($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X4);
    // 0x80003F70: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80003F74: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80003F78: bne         $t8, $zero, L_80003F90
    if (ctx->r24 != 0) {
        // 0x80003F7C: sh          $t7, 0x4($a1)
        MEM_H(0X4, ctx->r5) = ctx->r15;
            goto L_80003F90;
    }
    // 0x80003F7C: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x80003F80: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80003F84: lhu         $t9, 0x60($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X60);
    // 0x80003F88: andi        $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 & 0XFFFC;
    // 0x80003F8C: sh          $t0, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r8;
L_80003F90:
    // 0x80003F90: jr          $ra
    // 0x80003F94: nop

    return;
    // 0x80003F94: nop

;}
RECOMP_FUNC void func_800186F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800186F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800186FC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80018700: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80018704: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80018708: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8001870C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80018710: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80018714: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80018718: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8001871C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80018720: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018724: lwc1        $f26, 0x1530($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X1530);
    // 0x80018728: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001872C: lwc1        $f24, 0x1534($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X1534);
    // 0x80018730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018734: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80018738: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8001873C: lui         $s0, 0x8005
    ctx->r16 = S32(0X8005 << 16);
    // 0x80018740: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80018744: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80018748: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x8001874C: addiu       $s1, $s1, 0x7210
    ctx->r17 = ADD32(ctx->r17, 0X7210);
    // 0x80018750: addiu       $s0, $s0, -0x31D0
    ctx->r16 = ADD32(ctx->r16, -0X31D0);
    // 0x80018754: addiu       $s2, $s2, -0x7C10
    ctx->r18 = ADD32(ctx->r18, -0X7C10);
L_80018758:
    // 0x80018758: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001875C: beq         $v0, $zero, L_800187C0
    if (ctx->r2 == 0) {
        // 0x80018760: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800187C0;
    }
    // 0x80018760: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80018764: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80018768: beq         $t8, $zero, L_800187C0
    if (ctx->r24 == 0) {
        // 0x8001876C: sw          $t6, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r14;
            goto L_800187C0;
    }
    // 0x8001876C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80018770: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80018774: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018778: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001877C: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80018780: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80018784: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80018788: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8001878C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80018790: swc1        $f22, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f22.u32l;
    // 0x80018794: swc1        $f24, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f24.u32l;
    // 0x80018798: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8001879C: jal         0x800232F4
    // 0x800187A0: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x800187A0: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x800187A4: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800187A8: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800187AC: swc1        $f26, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f26.u32l;
    // 0x800187B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800187B4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x800187B8: jal         0x8001B108
    // 0x800187BC: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    func_8001B108(rdram, ctx);
        goto after_1;
    // 0x800187BC: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    after_1:
L_800187C0:
    // 0x800187C0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800187C4: bne         $s3, $zero, L_80018758
    if (ctx->r19 != 0) {
        // 0x800187C8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80018758;
    }
    // 0x800187C8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800187CC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800187D0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800187D4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800187D8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800187DC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800187E0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800187E4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800187E8: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800187EC: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800187F0: jr          $ra
    // 0x800187F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800187F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80042AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042AE0: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80042AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042AE8: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x80042AEC: beq         $v1, $zero, L_80042B48
    if (ctx->r3 == 0) {
        // 0x80042AF0: nop
    
            goto L_80042B48;
    }
    // 0x80042AF0: nop

L_80042AF4:
    // 0x80042AF4: bnel        $v1, $a2, L_80042B3C
    if (ctx->r3 != ctx->r6) {
        // 0x80042AF8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80042B3C;
    }
    goto skip_0;
    // 0x80042AF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80042AFC: beql        $v0, $zero, L_80042B14
    if (ctx->r2 == 0) {
        // 0x80042B00: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_80042B14;
    }
    goto skip_1;
    // 0x80042B00: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80042B04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80042B08: b           L_80042B18
    // 0x80042B0C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80042B18;
    // 0x80042B0C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80042B10: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_80042B14:
    // 0x80042B14: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_80042B18:
    // 0x80042B18: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x80042B1C: bnel        $v1, $t8, L_80042B2C
    if (ctx->r3 != ctx->r24) {
        // 0x80042B20: lw          $t9, 0x6C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X6C);
            goto L_80042B2C;
    }
    goto skip_2;
    // 0x80042B20: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    skip_2:
    // 0x80042B24: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x80042B28: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
L_80042B2C:
    // 0x80042B2C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80042B30: jr          $ra
    // 0x80042B34: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    return;
    // 0x80042B34: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x80042B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80042B3C:
    // 0x80042B3C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80042B40: bne         $v1, $zero, L_80042AF4
    if (ctx->r3 != 0) {
        // 0x80042B44: nop
    
            goto L_80042AF4;
    }
    // 0x80042B44: nop

L_80042B48:
    // 0x80042B48: jr          $ra
    // 0x80042B4C: nop

    return;
    // 0x80042B4C: nop

;}
RECOMP_FUNC void func_800121B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800121B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800121B4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800121B8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800121BC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800121C0: addiu       $t8, $t8, 0x69D8
    ctx->r24 = ADD32(ctx->r24, 0X69D8);
    // 0x800121C4: sra         $t7, $a0, 3
    ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800121C8: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x800121CC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x800121D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800121D4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800121D8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800121DC: lbu         $t1, -0x28C0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X28C0);
    // 0x800121E0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800121E4: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x800121E8: jr          $ra
    // 0x800121EC: nop

    return;
    // 0x800121EC: nop

;}
RECOMP_FUNC void func_800164E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800164E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800164E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800164EC: lhu         $t6, 0xA($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA);
    // 0x800164F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800164F4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800164F8: beql        $t7, $zero, L_80016510
    if (ctx->r15 == 0) {
        // 0x800164FC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80016510;
    }
    goto skip_0;
    // 0x800164FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80016500: jal         0x8001613C
    // 0x80016504: nop

    func_8001613C(rdram, ctx);
        goto after_0;
    // 0x80016504: nop

    after_0:
    // 0x80016508: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001650C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80016510:
    // 0x80016510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016518: jr          $ra
    // 0x8001651C: nop

    return;
    // 0x8001651C: nop

;}
