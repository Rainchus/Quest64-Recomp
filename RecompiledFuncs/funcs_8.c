#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8000A284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A284: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000A288: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000A28C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000A290: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000A294: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000A298: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000A29C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8000A2A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000A2A4: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x8000A2A8: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x8000A2AC: beq         $t6, $zero, L_8000A2F8
    if (ctx->r14 == 0) {
        // 0x8000A2B0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8000A2F8;
    }
    // 0x8000A2B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000A2B4: lhu         $t7, 0x90($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X90);
    // 0x8000A2B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000A2BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A2C0: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8000A2C4: beq         $t8, $zero, L_8000A2F8
    if (ctx->r24 == 0) {
        // 0x8000A2C8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8000A2F8;
    }
    // 0x8000A2C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000A2CC: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8000A2D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A2D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A2D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000A2DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8000A2E0: jal         0x8001D8B0
    // 0x8000A2E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x8000A2E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8000A2E8: jal         0x8001D358
    // 0x8000A2EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_1;
    // 0x8000A2EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8000A2F0: b           L_8000A3E0
    // 0x8000A2F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8000A3E0;
    // 0x8000A2F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000A2F8:
    // 0x8000A2F8: beq         $v0, $zero, L_8000A30C
    if (ctx->r2 == 0) {
        // 0x8000A2FC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8000A30C;
    }
    // 0x8000A2FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A300: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8000A304: b           L_8000A314
    // 0x8000A308: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
        goto L_8000A314;
    // 0x8000A308: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8000A30C:
    // 0x8000A30C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8000A310: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
L_8000A314:
    // 0x8000A314: lhu         $t4, 0x8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X8);
    // 0x8000A318: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8000A31C: lhu         $t3, 0x4($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X4);
    // 0x8000A320: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x8000A324: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
    // 0x8000A328: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8000A32C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A330: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8000A334: sh          $t6, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r14;
    // 0x8000A338: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000A33C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000A340: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000A344: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000A348: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A34C: jal         0x80023210
    // 0x8000A350: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80023210(rdram, ctx);
        goto after_2;
    // 0x8000A350: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8000A354: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8000A358: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x8000A35C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000A364: bne         $v0, $at, L_8000A374
    if (ctx->r2 != ctx->r1) {
        // 0x8000A368: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8000A374;
    }
    // 0x8000A368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000A36C: b           L_8000A378
    // 0x8000A370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8000A378;
    // 0x8000A370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8000A374:
    // 0x8000A374: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000A378:
    // 0x8000A378: lh          $a1, 0x8($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X8);
    // 0x8000A37C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000A380: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000A384: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000A388: jal         0x8001D8B0
    // 0x8000A38C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8001D8B0(rdram, ctx);
        goto after_3;
    // 0x8000A38C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8000A390: lhu         $a0, 0x4($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X4);
    // 0x8000A394: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000A398: jal         0x800140EC
    // 0x8000A39C: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    func_800140EC(rdram, ctx);
        goto after_4;
    // 0x8000A39C: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    after_4:
    // 0x8000A3A0: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8000A3A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A3A8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8000A3AC: bne         $t9, $zero, L_8000A3B8
    if (ctx->r25 != 0) {
        // 0x8000A3B0: nop
    
            goto L_8000A3B8;
    }
    // 0x8000A3B0: nop

    // 0x8000A3B4: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
L_8000A3B8:
    // 0x8000A3B8: lhu         $t1, -0x3A6E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X3A6E);
    // 0x8000A3BC: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x8000A3C0: beql        $t2, $zero, L_8000A3E0
    if (ctx->r10 == 0) {
        // 0x8000A3C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000A3E0;
    }
    goto skip_0;
    // 0x8000A3C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8000A3C8: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x8000A3CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000A3D0: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x8000A3D4: jal         0x8000B2C8
    // 0x8000A3D8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8000B2C8(rdram, ctx);
        goto after_5;
    // 0x8000A3D8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_5:
    // 0x8000A3DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000A3E0:
    // 0x8000A3E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000A3E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000A3E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000A3EC: jr          $ra
    // 0x8000A3F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000A3F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800497C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800497C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800497C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800497CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800497D0: jal         0x80049778
    // 0x800497D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_80049778(rdram, ctx);
        goto after_0;
    // 0x800497D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x800497D8: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x800497DC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800497E0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800497E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800497E8: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x800497EC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800497F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800497F4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800497F8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800497FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80049800: bne         $a0, $at, L_800498C0
    if (ctx->r4 != ctx->r1) {
        // 0x80049804: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_800498C0;
    }
    // 0x80049804: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80049808: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x8004980C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80049810: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80049814: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x80049818: bne         $v0, $at, L_80049888
    if (ctx->r2 != ctx->r1) {
        // 0x8004981C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80049888;
    }
    // 0x8004981C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80049820: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80049824: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x80049828: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8004982C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x80049830: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x80049834: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80049838: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004983C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80049840: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x80049844: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x80049848: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8004984C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80049850: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80049854: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80049858: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x8004985C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80049860: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80049864: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80049868: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8004986C: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x80049870: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80049874: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80049878: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8004987C: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x80049880: b           L_800498B8
    // 0x80049884: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_800498B8;
    // 0x80049884: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_80049888:
    // 0x80049888: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8004988C: bne         $v0, $at, L_800498B8
    if (ctx->r2 != ctx->r1) {
        // 0x80049890: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_800498B8;
    }
    // 0x80049890: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80049894: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x80049898: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8004989C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800498A0: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800498A4: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800498A8: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800498AC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800498B0: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800498B4: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800498B8:
    // 0x800498B8: b           L_80049938
    // 0x800498BC: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_80049938;
    // 0x800498BC: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_800498C0:
    // 0x800498C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800498C4: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800498C8: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800498CC: beq         $t6, $zero, L_800498F4
    if (ctx->r14 == 0) {
        // 0x800498D0: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_800498F4;
    }
    // 0x800498D0: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800498D4: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800498D8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800498DC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800498E0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800498E4: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800498E8: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800498EC: b           L_80049900
    // 0x800498F0: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_80049900;
    // 0x800498F0: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_800498F4:
    // 0x800498F4: lh          $t8, 0x1A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1A);
    // 0x800498F8: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800498FC: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_80049900:
    // 0x80049900: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x80049904: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x80049908: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x8004990C: beq         $t9, $at, L_80049934
    if (ctx->r25 == ctx->r1) {
        // 0x80049910: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_80049934;
    }
    // 0x80049910: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x80049914: beql        $t9, $at, L_80049938
    if (ctx->r25 == ctx->r1) {
        // 0x80049918: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_80049938;
    }
    goto skip_0;
    // 0x80049918: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x8004991C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80049920: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80049924: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80049928: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8004992C: b           L_80049938
    // 0x80049930: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_80049938;
    // 0x80049930: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_80049934:
    // 0x80049934: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_80049938:
    // 0x80049938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004993C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049940: jr          $ra
    // 0x80049944: nop

    return;
    // 0x80049944: nop

;}
RECOMP_FUNC void func_800080E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080E8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800080EC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800080F0: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800080F4: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800080F8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800080FC: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80008100: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80008104: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80008108: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000810C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80008110: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80008114: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80008118: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000811C: lw          $t6, 0x4F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F18);
    // 0x80008120: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80008124: addiu       $s3, $s3, -0x431C
    ctx->r19 = ADD32(ctx->r19, -0X431C);
    // 0x80008128: lw          $v0, 0x38($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X38);
    // 0x8000812C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80008130: beql        $v0, $zero, L_80008260
    if (ctx->r2 == 0) {
        // 0x80008134: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80008260;
    }
    goto skip_0;
    // 0x80008134: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80008138: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x8000813C: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x80008140: addiu       $s0, $s0, -0x42D0
    ctx->r16 = ADD32(ctx->r16, -0X42D0);
    // 0x80008144: beq         $s2, $zero, L_8000825C
    if (ctx->r18 == 0) {
        // 0x80008148: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_8000825C;
    }
    // 0x80008148: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8000814C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80008150: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80008154: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80008158: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000815C: addiu       $s4, $s4, 0x4EE8
    ctx->r20 = ADD32(ctx->r20, 0X4EE8);
    // 0x80008160: addiu       $s7, $zero, 0x1000
    ctx->r23 = ADD32(0, 0X1000);
    // 0x80008164: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x80008168: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8000816C:
    // 0x8000816C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80008170: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80008174: bnel        $t7, $t8, L_80008254
    if (ctx->r15 != ctx->r24) {
        // 0x80008178: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80008254;
    }
    goto skip_1;
    // 0x80008178: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x8000817C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80008180: sh          $s5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r21;
    // 0x80008184: sw          $s1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r17;
    // 0x80008188: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8000818C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80008190: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80008194: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80008198: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8000819C: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800081A0: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800081A4: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800081A8: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x800081AC: swc1        $f20, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f20.u32l;
    // 0x800081B0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800081B4: lwc1        $f10, 0x28($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800081B8: swc1        $f22, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f22.u32l;
    // 0x800081BC: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x800081C0: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x800081C4: jal         0x8000EE60
    // 0x800081C8: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_8000EE60(rdram, ctx);
        goto after_0;
    // 0x800081C8: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_0:
    // 0x800081CC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800081D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800081D4: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800081D8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x800081DC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800081E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800081E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800081E8: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x800081EC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800081F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800081F4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x800081F8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800081FC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80008200: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80008204: jal         0x8001D8B0
    // 0x80008208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x80008208: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8000820C: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80008210: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80008214: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80008218: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8000821C: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80008220: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80008224: lbu         $t0, 0x5($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X5);
    // 0x80008228: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8000822C: beql        $t1, $zero, L_80008240
    if (ctx->r9 == 0) {
        // 0x80008230: sh          $zero, 0x74($s0)
        MEM_H(0X74, ctx->r16) = 0;
            goto L_80008240;
    }
    goto skip_2;
    // 0x80008230: sh          $zero, 0x74($s0)
    MEM_H(0X74, ctx->r16) = 0;
    skip_2:
    // 0x80008234: b           L_80008240
    // 0x80008238: sh          $s7, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r23;
        goto L_80008240;
    // 0x80008238: sh          $s7, 0x74($s0)
    MEM_H(0X74, ctx->r16) = ctx->r23;
    // 0x8000823C: sh          $zero, 0x74($s0)
    MEM_H(0X74, ctx->r16) = 0;
L_80008240:
    // 0x80008240: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80008244: addiu       $s0, $s0, 0x84
    ctx->r16 = ADD32(ctx->r16, 0X84);
    // 0x80008248: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000824C: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80008250: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80008254:
    // 0x80008254: bne         $s2, $zero, L_8000816C
    if (ctx->r18 != 0) {
        // 0x80008258: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_8000816C;
    }
    // 0x80008258: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
L_8000825C:
    // 0x8000825C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80008260:
    // 0x80008260: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80008264: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80008268: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000826C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80008270: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80008274: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80008278: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8000827C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80008280: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80008284: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80008288: jr          $ra
    // 0x8000828C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8000828C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80049768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049768: jr          $ra
    // 0x8004976C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x8004976C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80023BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023BD0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80023BD4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80023BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80023BE0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80023BE4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80023BE8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80023BEC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80023BF0: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x80023BF4: jal         0x80023A08
    // 0x80023BF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80023A08(rdram, ctx);
        goto after_0;
    // 0x80023BF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80023BFC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80023C00: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x80023C04: jal         0x80035200
    // 0x80023C08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80023C08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80023C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023C14: jr          $ra
    // 0x80023C18: nop

    return;
    // 0x80023C18: nop

;}
RECOMP_FUNC void func_80018BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BF0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018BF4: ldc1        $f0, 0x1578($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1578);
    // 0x80018BF8: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80018BFC: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80018C00: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80018C04: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80018C08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018C0C: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80018C10: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80018C14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80018C18: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80018C1C: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80018C20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018C24: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80018C28: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x80018C2C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80018C30: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80018C34: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80018C38: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x80018C3C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018C40: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018C44: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x80018C48: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018C4C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80018C50: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80018C54: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x80018C58: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80018C5C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80018C60: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x80018C64: swc1        $f16, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f16.u32l;
    // 0x80018C68: lw          $v0, 0x5BBC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5BBC);
    // 0x80018C6C: lw          $v1, 0x5BC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5BC0);
    // 0x80018C70: lw          $a1, 0x5BC4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5BC4);
    // 0x80018C74: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80018C78: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80018C7C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80018C80: bne         $at, $zero, L_80018C8C
    if (ctx->r1 != 0) {
        // 0x80018C84: addiu       $a1, $a1, 0x40
        ctx->r5 = ADD32(ctx->r5, 0X40);
            goto L_80018C8C;
    }
    // 0x80018C84: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80018C88: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80018C8C:
    // 0x80018C8C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80018C90: bnel        $at, $zero, L_80018CA0
    if (ctx->r1 != 0) {
        // 0x80018C94: slti        $at, $a1, 0x100
        ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
            goto L_80018CA0;
    }
    goto skip_0;
    // 0x80018C94: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    skip_0:
    // 0x80018C98: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80018C9C: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
L_80018CA0:
    // 0x80018CA0: bne         $at, $zero, L_80018CAC
    if (ctx->r1 != 0) {
        // 0x80018CA4: nop
    
            goto L_80018CAC;
    }
    // 0x80018CA4: nop

    // 0x80018CA8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80018CAC:
    // 0x80018CAC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x80018CB0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80018CB4: sll         $t3, $v0, 24
    ctx->r11 = S32(ctx->r2 << 24);
    // 0x80018CB8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80018CBC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80018CC0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80018CC4: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80018CC8: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x80018CCC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80018CD0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80018CD4: lbu         $t1, -0x3114($t9)
    ctx->r9 = MEM_BU(ctx->r25, -0X3114);
    // 0x80018CD8: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80018CDC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80018CE0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80018CE4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80018CE8: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x80018CEC: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80018CF0: jr          $ra
    // 0x80018CF4: nop

    return;
    // 0x80018CF4: nop

;}
RECOMP_FUNC void func_800410CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800410CC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800410D0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800410D4: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800410D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800410DC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800410E0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800410E4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800410E8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800410EC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800410F0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800410F4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800410F8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800410FC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80041100: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80041104: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80041108: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8004110C: bne         $a2, $zero, L_8004111C
    if (ctx->r6 != 0) {
        // 0x80041110: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8004111C;
    }
    // 0x80041110: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80041114: b           L_8004153C
    // 0x80041118: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_8004153C;
    // 0x80041118: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_8004111C:
    // 0x8004111C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x80041120: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80041124: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80041128: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8004112C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80041130: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x80041134: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80041138: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8004113C: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x80041140: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80041144: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80041148: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x8004114C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x80041150: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041154: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80041158: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8004115C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80041160: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x80041164: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x80041168: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8004116C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x80041170: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x80041174: beq         $t1, $zero, L_80041188
    if (ctx->r9 == 0) {
        // 0x80041178: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_80041188;
    }
    // 0x80041178: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8004117C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x80041180: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x80041184: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_80041188:
    // 0x80041188: beq         $t1, $zero, L_80041198
    if (ctx->r9 == 0) {
        // 0x8004118C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80041198;
    }
    // 0x8004118C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80041190: b           L_80041198
    // 0x80041194: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_80041198;
    // 0x80041194: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_80041198:
    // 0x80041198: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x8004119C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800411A0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800411A4: beq         $v1, $zero, L_800411B4
    if (ctx->r3 == 0) {
        // 0x800411A8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800411B4;
    }
    // 0x800411A8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800411AC: b           L_800411B4
    // 0x800411B0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800411B4;
    // 0x800411B0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800411B4:
    // 0x800411B4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800411B8: bgez        $a0, L_800411C4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800411BC: nop
    
            goto L_800411C4;
    }
    // 0x800411BC: nop

    // 0x800411C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800411C4:
    // 0x800411C4: beq         $t1, $zero, L_800413CC
    if (ctx->r9 == 0) {
        // 0x800411C8: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800413CC;
    }
    // 0x800411C8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800411CC: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800411D0: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800411D4: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800411D8: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800411DC: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800411E0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800411E4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800411E8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800411EC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800411F0: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800411F4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800411F8: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800411FC: jal         0x80040FA0
    // 0x80041200: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_80040FA0(rdram, ctx);
        goto after_0;
    // 0x80041200: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x80041204: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x80041208: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8004120C: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80041210: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x80041214: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80041218: beq         $v1, $zero, L_80041234
    if (ctx->r3 == 0) {
        // 0x8004121C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80041234;
    }
    // 0x8004121C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80041220: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80041224: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80041228: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8004122C: b           L_80041240
    // 0x80041230: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_80041240;
    // 0x80041230: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_80041234:
    // 0x80041234: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80041238: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x8004123C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_80041240:
    // 0x80041240: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x80041244: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x80041248: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004124C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80041250: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x80041254: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80041258: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x8004125C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80041260: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80041264: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80041268: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x8004126C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x80041270: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x80041274: beq         $at, $zero, L_8004139C
    if (ctx->r1 == 0) {
        // 0x80041278: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_8004139C;
    }
    // 0x80041278: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x8004127C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_80041280:
    // 0x80041280: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x80041284: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x80041288: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x8004128C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x80041290: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80041294: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x80041298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004129C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800412A0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800412A4: beq         $v0, $at, L_800412B8
    if (ctx->r2 == ctx->r1) {
        // 0x800412A8: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800412B8;
    }
    // 0x800412A8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800412AC: beq         $v0, $zero, L_800412B8
    if (ctx->r2 == 0) {
        // 0x800412B0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800412B8;
    }
    // 0x800412B0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800412B4: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800412B8:
    // 0x800412B8: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800412BC: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800412C0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800412C4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800412C8: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800412CC: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800412D0: beq         $at, $zero, L_800412E0
    if (ctx->r1 == 0) {
        // 0x800412D4: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800412E0;
    }
    // 0x800412D4: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800412D8: b           L_800412E4
    // 0x800412DC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800412E4;
    // 0x800412DC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800412E0:
    // 0x800412E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800412E4:
    // 0x800412E4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800412E8: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800412EC: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800412F0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800412F4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800412F8: bgez        $a0, L_80041304
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800412FC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80041304;
    }
    // 0x800412FC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80041300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80041304:
    // 0x80041304: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x80041308: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8004130C: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x80041310: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80041314: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80041318: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x8004131C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80041320: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80041324: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80041328: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x8004132C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x80041330: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80041334: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80041338: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8004133C: jal         0x80040FA0
    // 0x80041340: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_80040FA0(rdram, ctx);
        goto after_1;
    // 0x80041340: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x80041344: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x80041348: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8004134C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80041350: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80041354: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80041358: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x8004135C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80041360: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80041364: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80041368: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8004136C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80041370: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x80041374: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80041378: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8004137C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80041380: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80041384: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80041388: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8004138C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80041390: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80041394: bne         $at, $zero, L_80041280
    if (ctx->r1 != 0) {
        // 0x80041398: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_80041280;
    }
    // 0x80041398: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_8004139C:
    // 0x8004139C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800413A0: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800413A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800413A8: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800413AC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800413B0: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800413B4: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800413B8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800413BC: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800413C0: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800413C4: b           L_8004153C
    // 0x800413C8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_8004153C;
    // 0x800413C8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800413CC:
    // 0x800413CC: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800413D0: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800413D4: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800413D8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800413DC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800413E0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800413E4: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800413E8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800413EC: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800413F0: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800413F4: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800413F8: bgez        $v1, L_80041404
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800413FC: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_80041404;
    }
    // 0x800413FC: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x80041400: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80041404:
    // 0x80041404: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80041408: mflo        $v0
    ctx->r2 = lo;
    // 0x8004140C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80041410: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x80041414: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80041418: beq         $at, $zero, L_80041424
    if (ctx->r1 == 0) {
        // 0x8004141C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_80041424;
    }
    // 0x8004141C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80041420: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_80041424:
    // 0x80041424: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x80041428: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x8004142C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80041430: beq         $at, $zero, L_800414E0
    if (ctx->r1 == 0) {
        // 0x80041434: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800414E0;
    }
    // 0x80041434: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x80041438: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x8004143C: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x80041440: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041444: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x80041448: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8004144C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80041450: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x80041454: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x80041458: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8004145C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80041460: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x80041464: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80041468: jal         0x80040FA0
    // 0x8004146C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_80040FA0(rdram, ctx);
        goto after_2;
    // 0x8004146C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x80041470: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x80041474: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80041478: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8004147C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x80041480: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80041484: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80041488: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8004148C: beq         $v1, $zero, L_800414A8
    if (ctx->r3 == 0) {
        // 0x80041490: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800414A8;
    }
    // 0x80041490: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80041494: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x80041498: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8004149C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800414A0: b           L_800414B4
    // 0x800414A4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800414B4;
    // 0x800414A4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800414A8:
    // 0x800414A8: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800414AC: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800414B0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800414B4:
    // 0x800414B4: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800414B8: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800414BC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800414C0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800414C4: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800414C8: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800414CC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800414D0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800414D4: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800414D8: b           L_800414E8
    // 0x800414DC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800414E8;
    // 0x800414DC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800414E0:
    // 0x800414E0: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800414E4: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800414E8:
    // 0x800414E8: beq         $a0, $zero, L_80041538
    if (ctx->r4 == 0) {
        // 0x800414EC: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80041538;
    }
    // 0x800414EC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800414F0: beq         $t5, $zero, L_80041508
    if (ctx->r13 == 0) {
        // 0x800414F4: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_80041508;
    }
    // 0x800414F4: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800414F8: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800414FC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80041500: b           L_8004150C
    // 0x80041504: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8004150C;
    // 0x80041504: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80041508:
    // 0x80041508: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004150C:
    // 0x8004150C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80041510: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80041514: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80041518: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8004151C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80041520: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80041524: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80041528: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8004152C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80041530: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80041534: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_80041538:
    // 0x80041538: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8004153C:
    // 0x8004153C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80041540: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80041544: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80041548: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8004154C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80041550: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80041554: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80041558: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8004155C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80041560: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80041564: jr          $ra
    // 0x80041568: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80041568: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8004156C: nop

;}
RECOMP_FUNC void func_80008EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008EF8: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80008EFC: addiu       $a3, $a3, -0x2F44
    ctx->r7 = ADD32(ctx->r7, -0X2F44);
    // 0x80008F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008F04: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80008F08: lw          $t6, 0x4F1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F1C);
    // 0x80008F0C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80008F10: addiu       $t9, $t9, 0x4160
    ctx->r25 = ADD32(ctx->r25, 0X4160);
    // 0x80008F14: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x80008F18: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008F1C: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x80008F20: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80008F24: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80008F28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80008F2C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80008F30: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80008F34: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80008F38: addiu       $a1, $a1, -0x1910
    ctx->r5 = ADD32(ctx->r5, -0X1910);
    // 0x80008F3C: sw          $t1, -0x2F58($at)
    MEM_W(-0X2F58, ctx->r1) = ctx->r9;
    // 0x80008F40: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x80008F44: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008F48: sw          $t2, -0x2F54($at)
    MEM_W(-0X2F54, ctx->r1) = ctx->r10;
    // 0x80008F4C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80008F50: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80008F54: jal         0x80024260
    // 0x80008F58: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80008F58: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    after_0:
    // 0x80008F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008F64: jr          $ra
    // 0x80008F68: nop

    return;
    // 0x80008F68: nop

;}
RECOMP_FUNC void func_8000B300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B300: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000B304: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000B308: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000B30C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000B310: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000B314: lw          $t6, -0x2F3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F3C);
    // 0x8000B318: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000B31C: beql        $t6, $zero, L_8000B504
    if (ctx->r14 == 0) {
        // 0x8000B320: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8000B504;
    }
    goto skip_0;
    // 0x8000B320: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8000B324: lhu         $t7, -0x2F40($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2F40);
    // 0x8000B328: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B32C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000B330: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000B334: sh          $t8, -0x2F40($at)
    MEM_H(-0X2F40, ctx->r1) = ctx->r24;
    // 0x8000B338: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x8000B33C: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x8000B340: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8000B344: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000B348: beq         $at, $zero, L_8000B500
    if (ctx->r1 == 0) {
        // 0x8000B34C: addiu       $s0, $s0, -0x2F30
        ctx->r16 = ADD32(ctx->r16, -0X2F30);
            goto L_8000B500;
    }
    // 0x8000B34C: addiu       $s0, $s0, -0x2F30
    ctx->r16 = ADD32(ctx->r16, -0X2F30);
    // 0x8000B350: lhu         $t1, 0x2($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X2);
    // 0x8000B354: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x8000B358: addiu       $t3, $t3, 0x4690
    ctx->r11 = ADD32(ctx->r11, 0X4690);
    // 0x8000B35C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8000B360: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8000B364: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x8000B368: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8000B36C: addiu       $t7, $t7, 0x1B90
    ctx->r15 = ADD32(ctx->r15, 0X1B90);
    // 0x8000B370: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000B374: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8000B378: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8000B37C: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8000B380: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8000B384: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000B388: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B38C: lw          $v0, -0x2F34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F34);
    // 0x8000B390: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8000B394: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000B398: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000B39C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8000B3A0: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000B3A4: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000B3A8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8000B3AC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8000B3B0: jal         0x800232F4
    // 0x8000B3B4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x8000B3B4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8000B3B8: lhu         $t8, 0x4($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X4);
    // 0x8000B3BC: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8000B3C0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8000B3C4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8000B3C8: beq         $t9, $zero, L_8000B3E8
    if (ctx->r25 == 0) {
        // 0x8000B3CC: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8000B3E8;
    }
    // 0x8000B3CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B3D0: lwc1        $f2, -0x4534($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8000B3D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B3D8: lwc1        $f12, -0x4530($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x8000B3DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B3E0: b           L_8000B3F4
    // 0x8000B3E4: lwc1        $f14, -0x452C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X452C);
        goto L_8000B3F4;
    // 0x8000B3E4: lwc1        $f14, -0x452C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X452C);
L_8000B3E8:
    // 0x8000B3E8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000B3EC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000B3F0: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
L_8000B3F4:
    // 0x8000B3F4: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8000B3F8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000B3FC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000B400: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000B404: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8000B408: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000B40C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000B410: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000B414: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8000B418: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8000B41C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000B420: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8000B424: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8000B428: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8000B42C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8000B430: lw          $t0, -0x2F38($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2F38);
    // 0x8000B434: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8000B438: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x8000B43C: lhu         $a3, 0x0($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X0);
    // 0x8000B440: andi        $t2, $a3, 0x8000
    ctx->r10 = ctx->r7 & 0X8000;
    // 0x8000B444: beq         $t2, $zero, L_8000B47C
    if (ctx->r10 == 0) {
        // 0x8000B448: sra         $a0, $a3, 8
        ctx->r4 = S32(SIGNED(ctx->r7) >> 8);
            goto L_8000B47C;
    }
    // 0x8000B448: sra         $a0, $a3, 8
    ctx->r4 = S32(SIGNED(ctx->r7) >> 8);
    // 0x8000B44C: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x8000B450: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000B454: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x8000B458: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8000B45C: lw          $t5, 0x1B14($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B14);
    // 0x8000B460: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8000B464: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8000B468: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000B46C: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    // 0x8000B470: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8000B474: b           L_8000B484
    // 0x8000B478: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_8000B484;
    // 0x8000B478: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_8000B47C:
    // 0x8000B47C: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8000B480: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_8000B484:
    // 0x8000B484: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x8000B488: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8000B48C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8000B490: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000B494: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000B498: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B49C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8000B4A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B4A4: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8000B4A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8000B4AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000B4B0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8000B4B4: jal         0x800177F8
    // 0x8000B4B8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800177F8(rdram, ctx);
        goto after_1;
    // 0x8000B4B8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x8000B4BC: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8000B4C0: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8000B4C4: beql        $t8, $zero, L_8000B4DC
    if (ctx->r24 == 0) {
        // 0x8000B4C8: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_8000B4DC;
    }
    goto skip_1;
    // 0x8000B4C8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    skip_1:
    // 0x8000B4CC: jal         0x80013F20
    // 0x8000B4D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80013F20(rdram, ctx);
        goto after_2;
    // 0x8000B4D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8000B4D4: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8000B4D8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
L_8000B4DC:
    // 0x8000B4DC: beq         $t9, $zero, L_8000B4F0
    if (ctx->r25 == 0) {
        // 0x8000B4E0: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_8000B4F0;
    }
    // 0x8000B4E0: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000B4E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B4E8: b           L_8000B500
    // 0x8000B4EC: sw          $zero, -0x2F3C($at)
    MEM_W(-0X2F3C, ctx->r1) = 0;
        goto L_8000B500;
    // 0x8000B4EC: sw          $zero, -0x2F3C($at)
    MEM_W(-0X2F3C, ctx->r1) = 0;
L_8000B4F0:
    // 0x8000B4F0: lw          $t0, -0x2F3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2F3C);
    // 0x8000B4F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B4F8: addiu       $t1, $t0, 0x18
    ctx->r9 = ADD32(ctx->r8, 0X18);
    // 0x8000B4FC: sw          $t1, -0x2F3C($at)
    MEM_W(-0X2F3C, ctx->r1) = ctx->r9;
L_8000B500:
    // 0x8000B500: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000B504:
    // 0x8000B504: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B508: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8000B50C: jr          $ra
    // 0x8000B510: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000B510: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8000B514: nop

    // 0x8000B518: nop

    // 0x8000B51C: nop

;}
RECOMP_FUNC void func_8001E25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E25C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E260: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001E264: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001E268: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001E26C: addiu       $t1, $t1, -0x4D08
    ctx->r9 = ADD32(ctx->r9, -0X4D08);
    // 0x8001E270: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001E274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E278: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001E27C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001E280: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x8001E284: lui         $t8, 0x200
    ctx->r24 = S32(0X200 << 16);
    // 0x8001E288: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001E28C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8001E290: addiu       $t8, $t8, 0x40
    ctx->r24 = ADD32(ctx->r24, 0X40);
    // 0x8001E294: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8001E298: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001E29C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001E2A0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001E2A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001E2A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001E2AC: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8001E2B0: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    // 0x8001E2B4: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8001E2B8: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x8001E2BC: jal         0x80036198
    // 0x8001E2C0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    guTranslate(rdram, ctx);
        goto after_0;
    // 0x8001E2C0: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    after_0:
    // 0x8001E2C4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8001E2C8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001E2CC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001E2D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001E2D4: addiu       $t1, $t1, -0x4D08
    ctx->r9 = ADD32(ctx->r9, -0X4D08);
    // 0x8001E2D8: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001E2DC: addiu       $a2, $a2, -0x2D4C
    ctx->r6 = ADD32(ctx->r6, -0X2D4C);
    // 0x8001E2E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001E2E4: lui         $t5, 0x101
    ctx->r13 = S32(0X101 << 16);
    // 0x8001E2E8: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x8001E2EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8001E2F0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8001E2F4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001E2F8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E2FC: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x8001E300: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x8001E304: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8001E308: addiu       $t8, $t7, 0xC0
    ctx->r24 = ADD32(ctx->r15, 0XC0);
    // 0x8001E30C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001E310: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001E314: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8001E318: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8001E31C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8001E320: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001E324: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8001E328: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001E32C: lui         $t7, 0x803A
    ctx->r15 = S32(0X803A << 16);
    // 0x8001E330: addiu       $t7, $t7, 0x6FC0
    ctx->r15 = ADD32(ctx->r15, 0X6FC0);
    // 0x8001E334: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001E338: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8001E33C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001E340: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001E344: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x8001E348: addiu       $a0, $a0, -0x2D44
    ctx->r4 = ADD32(ctx->r4, -0X2D44);
    // 0x8001E34C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8001E350: beq         $a1, $zero, L_8001E40C
    if (ctx->r5 == 0) {
        // 0x8001E354: nop
    
            goto L_8001E40C;
    }
    // 0x8001E354: nop

    // 0x8001E358: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001E35C: beq         $v1, $zero, L_8001E36C
    if (ctx->r3 == 0) {
        // 0x8001E360: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8001E36C;
    }
    // 0x8001E360: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8001E364: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001E368: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8001E36C:
    // 0x8001E36C: subu        $v0, $a3, $v1
    ctx->r2 = SUB32(ctx->r7, ctx->r3);
    // 0x8001E370: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E374: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001E378: addiu       $t0, $t0, -0x39A0
    ctx->r8 = ADD32(ctx->r8, -0X39A0);
    // 0x8001E37C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001E380: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E384: mflo        $v0
    ctx->r2 = lo;
    // 0x8001E388: sra         $t2, $v0, 1
    ctx->r10 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001E38C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8001E390: lw          $t9, -0x4D1C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D1C);
    // 0x8001E394: sw          $v0, -0x399C($at)
    MEM_W(-0X399C, ctx->r1) = ctx->r2;
    // 0x8001E398: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E39C: andi        $t3, $t9, 0x480
    ctx->r11 = ctx->r25 & 0X480;
    // 0x8001E3A0: bnel        $t3, $zero, L_8001E4DC
    if (ctx->r11 != 0) {
        // 0x8001E3A4: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_8001E4DC;
    }
    goto skip_0;
    // 0x8001E3A4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8001E3A8: lwc1        $f4, -0x451C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X451C);
    // 0x8001E3AC: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001E3B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E3B4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8001E3B8: addiu       $v0, $v0, -0x2D48
    ctx->r2 = ADD32(ctx->r2, -0X2D48);
    // 0x8001E3BC: bc1f        L_8001E404
    if (!c1cs) {
        // 0x8001E3C0: nop
    
            goto L_8001E404;
    }
    // 0x8001E3C0: nop

    // 0x8001E3C4: lwc1        $f6, -0x4514($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4514);
    // 0x8001E3C8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8001E3CC: nop

    // 0x8001E3D0: bc1f        L_8001E404
    if (!c1cs) {
        // 0x8001E3D4: nop
    
            goto L_8001E404;
    }
    // 0x8001E3D4: nop

    // 0x8001E3D8: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001E3DC: addiu       $v0, $v0, -0x2D48
    ctx->r2 = ADD32(ctx->r2, -0X2D48);
    // 0x8001E3E0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001E3E4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001E3E8: slti        $at, $t5, 0x1F
    ctx->r1 = SIGNED(ctx->r13) < 0X1F ? 1 : 0;
    // 0x8001E3EC: bne         $at, $zero, L_8001E4D8
    if (ctx->r1 != 0) {
        // 0x8001E3F0: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_8001E4D8;
    }
    // 0x8001E3F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001E3F4: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8001E3F8: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8001E3FC: b           L_8001E4D8
    // 0x8001E400: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8001E4D8;
    // 0x8001E400: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8001E404:
    // 0x8001E404: b           L_8001E4D8
    // 0x8001E408: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8001E4D8;
    // 0x8001E408: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8001E40C:
    // 0x8001E40C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8001E410: addiu       $a0, $a0, -0x2D44
    ctx->r4 = ADD32(ctx->r4, -0X2D44);
    // 0x8001E414: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001E418: beq         $v1, $zero, L_8001E428
    if (ctx->r3 == 0) {
        // 0x8001E41C: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8001E428;
    }
    // 0x8001E41C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8001E420: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001E424: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8001E428:
    // 0x8001E428: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E42C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001E430: addiu       $t0, $t0, -0x39A0
    ctx->r8 = ADD32(ctx->r8, -0X39A0);
    // 0x8001E434: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001E438: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E43C: mflo        $v0
    ctx->r2 = lo;
    // 0x8001E440: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001E444: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8001E448: lhu         $t2, -0x3A6E($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3A6E);
    // 0x8001E44C: sw          $v0, -0x399C($at)
    MEM_W(-0X399C, ctx->r1) = ctx->r2;
    // 0x8001E450: andi        $t9, $t2, 0x1
    ctx->r25 = ctx->r10 & 0X1;
    // 0x8001E454: bne         $t9, $zero, L_8001E4D8
    if (ctx->r25 != 0) {
        // 0x8001E458: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_8001E4D8;
    }
    // 0x8001E458: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001E45C: lw          $t3, -0x4D1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4D1C);
    // 0x8001E460: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E464: andi        $t4, $t3, 0x480
    ctx->r12 = ctx->r11 & 0X480;
    // 0x8001E468: bnel        $t4, $zero, L_8001E4DC
    if (ctx->r12 != 0) {
        // 0x8001E46C: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_8001E4DC;
    }
    goto skip_1;
    // 0x8001E46C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x8001E470: lwc1        $f8, -0x451C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X451C);
    // 0x8001E474: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001E478: addiu       $v0, $v0, -0x2D48
    ctx->r2 = ADD32(ctx->r2, -0X2D48);
    // 0x8001E47C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8001E480: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E484: bc1fl       L_8001E4A4
    if (!c1cs) {
        // 0x8001E488: lw          $t5, 0x0($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X0);
            goto L_8001E4A4;
    }
    goto skip_2;
    // 0x8001E488: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x8001E48C: lwc1        $f10, -0x4514($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4514);
    // 0x8001E490: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8001E494: nop

    // 0x8001E498: bc1t        L_8001E4CC
    if (c1cs) {
        // 0x8001E49C: nop
    
            goto L_8001E4CC;
    }
    // 0x8001E49C: nop

    // 0x8001E4A0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
L_8001E4A4:
    // 0x8001E4A4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8001E4A8: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8001E4AC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001E4B0: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x8001E4B4: bne         $at, $zero, L_8001E4D8
    if (ctx->r1 != 0) {
        // 0x8001E4B8: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8001E4D8;
    }
    // 0x8001E4B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001E4BC: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8001E4C0: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8001E4C4: b           L_8001E4D8
    // 0x8001E4C8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8001E4D8;
    // 0x8001E4C8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8001E4CC:
    // 0x8001E4CC: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001E4D0: addiu       $v0, $v0, -0x2D48
    ctx->r2 = ADD32(ctx->r2, -0X2D48);
    // 0x8001E4D4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8001E4D8:
    // 0x8001E4D8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
L_8001E4DC:
    // 0x8001E4DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E4E0: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
    // 0x8001E4E4: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x8001E4E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E4EC: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x8001E4F0: sw          $t3, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r11;
    // 0x8001E4F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E4F8: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x8001E4FC: andi        $t5, $v0, 0xC00
    ctx->r13 = ctx->r2 & 0XC00;
    // 0x8001E500: sw          $t4, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r12;
    // 0x8001E504: bne         $t5, $zero, L_8001E528
    if (ctx->r13 != 0) {
        // 0x8001E508: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8001E528;
    }
    // 0x8001E508: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8001E50C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E510: jal         0x8001E7FC
    // 0x8001E514: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_8001E7FC(rdram, ctx);
        goto after_1;
    // 0x8001E514: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_1:
    // 0x8001E518: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E51C: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
    // 0x8001E520: andi        $t6, $v0, 0xC00
    ctx->r14 = ctx->r2 & 0XC00;
    // 0x8001E524: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8001E528:
    // 0x8001E528: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8001E52C: lw          $t7, -0x399C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X399C);
    // 0x8001E530: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8001E534: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E538: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8001E53C: sw          $t9, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r25;
    // 0x8001E540: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E544: addiu       $t2, $zero, 0xC5
    ctx->r10 = ADD32(0, 0XC5);
    // 0x8001E548: bne         $v0, $zero, L_8001E55C
    if (ctx->r2 != 0) {
        // 0x8001E54C: sw          $t2, -0x39B4($at)
        MEM_W(-0X39B4, ctx->r1) = ctx->r10;
            goto L_8001E55C;
    }
    // 0x8001E54C: sw          $t2, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r10;
    // 0x8001E550: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E554: jal         0x8001EBDC
    // 0x8001E558: lw          $a0, -0x4538($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4538);
    func_8001EBDC(rdram, ctx);
        goto after_2;
    // 0x8001E558: lw          $a0, -0x4538($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4538);
    after_2:
L_8001E55C:
    // 0x8001E55C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001E560: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001E564: lhu         $t4, 0x4EE0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X4EE0);
    // 0x8001E568: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x8001E56C: andi        $t5, $t4, 0xD
    ctx->r13 = ctx->r12 & 0XD;
    // 0x8001E570: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8001E574: beq         $t5, $zero, L_8001E5B0
    if (ctx->r13 == 0) {
        // 0x8001E578: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8001E5B0;
    }
    // 0x8001E578: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8001E57C: bne         $t3, $zero, L_8001E5B0
    if (ctx->r11 != 0) {
        // 0x8001E580: lui         $t6, 0x8008
        ctx->r14 = S32(0X8008 << 16);
            goto L_8001E5B0;
    }
    // 0x8001E580: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001E584: lw          $t6, 0x4F1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F1C);
    // 0x8001E588: lhu         $t8, 0x14($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X14);
    // 0x8001E58C: andi        $t7, $t8, 0x8
    ctx->r15 = ctx->r24 & 0X8;
    // 0x8001E590: bne         $t7, $zero, L_8001E5B0
    if (ctx->r15 != 0) {
        // 0x8001E594: nop
    
            goto L_8001E5B0;
    }
    // 0x8001E594: nop

    // 0x8001E598: jal         0x8001EA84
    // 0x8001E59C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8001EA84(rdram, ctx);
        goto after_3;
    // 0x8001E59C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8001E5A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001E5A4: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x8001E5A8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8001E5AC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8001E5B0:
    // 0x8001E5B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E5B4: sw          $zero, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = 0;
    // 0x8001E5B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E5BC: beq         $v0, $zero, L_8001E5F4
    if (ctx->r2 == 0) {
        // 0x8001E5C0: sw          $zero, -0x39B8($at)
        MEM_W(-0X39B8, ctx->r1) = 0;
            goto L_8001E5F4;
    }
    // 0x8001E5C0: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    // 0x8001E5C4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001E5C8: addiu       $v0, $v0, -0x39D0
    ctx->r2 = ADD32(ctx->r2, -0X39D0);
    // 0x8001E5CC: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E5D0: beq         $t2, $zero, L_8001E5F4
    if (ctx->r10 == 0) {
        // 0x8001E5D4: nop
    
            goto L_8001E5F4;
    }
    // 0x8001E5D4: nop

    // 0x8001E5D8: jal         0x800203D0
    // 0x8001E5DC: nop

    func_800203D0(rdram, ctx);
        goto after_4;
    // 0x8001E5DC: nop

    after_4:
    // 0x8001E5E0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001E5E4: addiu       $v0, $v0, -0x39D0
    ctx->r2 = ADD32(ctx->r2, -0X39D0);
    // 0x8001E5E8: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E5EC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8001E5F0: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_8001E5F4:
    // 0x8001E5F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E5F8: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
    // 0x8001E5FC: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x8001E600: beq         $t5, $zero, L_8001E618
    if (ctx->r13 == 0) {
        // 0x8001E604: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8001E618;
    }
    // 0x8001E604: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E608: jal         0x8001ED5C
    // 0x8001E60C: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_8001ED5C(rdram, ctx);
        goto after_5;
    // 0x8001E60C: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_5:
    // 0x8001E610: b           L_8001E62C
    // 0x8001E614: nop

        goto L_8001E62C;
    // 0x8001E614: nop

L_8001E618:
    // 0x8001E618: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x8001E61C: beq         $t6, $zero, L_8001E62C
    if (ctx->r14 == 0) {
        // 0x8001E620: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8001E62C;
    }
    // 0x8001E620: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E624: jal         0x8001F3DC
    // 0x8001E628: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_8001F3DC(rdram, ctx);
        goto after_6;
    // 0x8001E628: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_6:
L_8001E62C:
    // 0x8001E62C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E630: sw          $zero, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = 0;
    // 0x8001E634: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E638: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001E63C: lhu         $t9, -0x3A6E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A6E);
    // 0x8001E640: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    // 0x8001E644: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E648: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8001E64C: sw          $t8, -0x39A8($at)
    MEM_W(-0X39A8, ctx->r1) = ctx->r24;
    // 0x8001E650: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E654: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8001E658: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8001E65C: beq         $t2, $zero, L_8001E758
    if (ctx->r10 == 0) {
        // 0x8001E660: sw          $t7, -0x39A4($at)
        MEM_W(-0X39A4, ctx->r1) = ctx->r15;
            goto L_8001E758;
    }
    // 0x8001E660: sw          $t7, -0x39A4($at)
    MEM_W(-0X39A4, ctx->r1) = ctx->r15;
    // 0x8001E664: jal         0x80020988
    // 0x8001E668: nop

    func_80020988(rdram, ctx);
        goto after_7;
    // 0x8001E668: nop

    after_7:
    // 0x8001E66C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001E670: lhu         $t3, -0x3A6E($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X3A6E);
    // 0x8001E674: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E678: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8001E67C: bne         $t4, $zero, L_8001E6C8
    if (ctx->r12 != 0) {
        // 0x8001E680: nop
    
            goto L_8001E6C8;
    }
    // 0x8001E680: nop

    // 0x8001E684: lhu         $v0, -0x4546($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4546);
    // 0x8001E688: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001E68C: beq         $v0, $zero, L_8001E6C8
    if (ctx->r2 == 0) {
        // 0x8001E690: nop
    
            goto L_8001E6C8;
    }
    // 0x8001E690: nop

    // 0x8001E694: lhu         $t5, -0x44D4($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X44D4);
    // 0x8001E698: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001E69C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001E6A0: bne         $t6, $zero, L_8001E6C8
    if (ctx->r14 != 0) {
        // 0x8001E6A4: nop
    
            goto L_8001E6C8;
    }
    // 0x8001E6A4: nop

    // 0x8001E6A8: lw          $t8, 0x6F10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6F10);
    // 0x8001E6AC: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8001E6B0: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8001E6B4: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x8001E6B8: bne         $t7, $zero, L_8001E6C8
    if (ctx->r15 != 0) {
        // 0x8001E6BC: nop
    
            goto L_8001E6C8;
    }
    // 0x8001E6BC: nop

    // 0x8001E6C0: jal         0x8001FA60
    // 0x8001E6C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_8001FA60(rdram, ctx);
        goto after_8;
    // 0x8001E6C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_8:
L_8001E6C8:
    // 0x8001E6C8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001E6CC: lhu         $t2, -0x4540($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4540);
    // 0x8001E6D0: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001E6D4: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x8001E6D8: beq         $t3, $zero, L_8001E6F8
    if (ctx->r11 == 0) {
        // 0x8001E6DC: nop
    
            goto L_8001E6F8;
    }
    // 0x8001E6DC: nop

    // 0x8001E6E0: lw          $t4, -0x4D1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4D1C);
    // 0x8001E6E4: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x8001E6E8: bne         $t5, $zero, L_8001E6F8
    if (ctx->r13 != 0) {
        // 0x8001E6EC: nop
    
            goto L_8001E6F8;
    }
    // 0x8001E6EC: nop

    // 0x8001E6F0: jal         0x8001FB94
    // 0x8001E6F4: nop

    func_8001FB94(rdram, ctx);
        goto after_9;
    // 0x8001E6F4: nop

    after_9:
L_8001E6F8:
    // 0x8001E6F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E6FC: jal         0x8001FEEC
    // 0x8001E700: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_8001FEEC(rdram, ctx);
        goto after_10;
    // 0x8001E700: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_10:
    // 0x8001E704: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E708: lw          $v0, -0x3670($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3670);
    // 0x8001E70C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001E710: addiu       $v1, $v1, -0x3668
    ctx->r3 = ADD32(ctx->r3, -0X3668);
    // 0x8001E714: beql        $v0, $zero, L_8001E7F0
    if (ctx->r2 == 0) {
        // 0x8001E718: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E7F0;
    }
    goto skip_3;
    // 0x8001E718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_8001E71C:
    // 0x8001E71C: lh          $t6, 0x74($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X74);
    // 0x8001E720: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E724: addiu       $a0, $v1, 0x24
    ctx->r4 = ADD32(ctx->r3, 0X24);
    // 0x8001E728: beq         $t6, $at, L_8001E748
    if (ctx->r14 == ctx->r1) {
        // 0x8001E72C: nop
    
            goto L_8001E748;
    }
    // 0x8001E72C: nop

    // 0x8001E730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001E734: jal         0x8001FEEC
    // 0x8001E738: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8001FEEC(rdram, ctx);
        goto after_11;
    // 0x8001E738: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_11:
    // 0x8001E73C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001E740: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E744: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001E748:
    // 0x8001E748: bne         $v0, $zero, L_8001E71C
    if (ctx->r2 != 0) {
        // 0x8001E74C: addiu       $v1, $v1, 0x128
        ctx->r3 = ADD32(ctx->r3, 0X128);
            goto L_8001E71C;
    }
    // 0x8001E74C: addiu       $v1, $v1, 0x128
    ctx->r3 = ADD32(ctx->r3, 0X128);
    // 0x8001E750: b           L_8001E7F0
    // 0x8001E754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E7F0;
    // 0x8001E754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E758:
    // 0x8001E758: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001E75C: lw          $t8, -0x458C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X458C);
    // 0x8001E760: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001E764: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001E768: beq         $t8, $zero, L_8001E790
    if (ctx->r24 == 0) {
        // 0x8001E76C: nop
    
            goto L_8001E790;
    }
    // 0x8001E76C: nop

    // 0x8001E770: lw          $t7, -0x4D1C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D1C);
    // 0x8001E774: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x8001E778: bne         $t9, $zero, L_8001E790
    if (ctx->r25 != 0) {
        // 0x8001E77C: nop
    
            goto L_8001E790;
    }
    // 0x8001E77C: nop

    // 0x8001E780: jal         0x8001F818
    // 0x8001E784: nop

    func_8001F818(rdram, ctx);
        goto after_12;
    // 0x8001E784: nop

    after_12:
    // 0x8001E788: b           L_8001E7F0
    // 0x8001E78C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E7F0;
    // 0x8001E78C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E790:
    // 0x8001E790: lw          $t2, -0x4588($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4588);
    // 0x8001E794: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001E798: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001E79C: beq         $t2, $zero, L_8001E7C4
    if (ctx->r10 == 0) {
        // 0x8001E7A0: nop
    
            goto L_8001E7C4;
    }
    // 0x8001E7A0: nop

    // 0x8001E7A4: lw          $t3, -0x4D1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4D1C);
    // 0x8001E7A8: andi        $t4, $t3, 0xB
    ctx->r12 = ctx->r11 & 0XB;
    // 0x8001E7AC: bne         $t4, $zero, L_8001E7C4
    if (ctx->r12 != 0) {
        // 0x8001E7B0: nop
    
            goto L_8001E7C4;
    }
    // 0x8001E7B0: nop

    // 0x8001E7B4: jal         0x8001F900
    // 0x8001E7B8: nop

    func_8001F900(rdram, ctx);
        goto after_13;
    // 0x8001E7B8: nop

    after_13:
    // 0x8001E7BC: b           L_8001E7F0
    // 0x8001E7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E7F0;
    // 0x8001E7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E7C4:
    // 0x8001E7C4: lw          $t5, -0x4584($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4584);
    // 0x8001E7C8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001E7CC: beql        $t5, $zero, L_8001E7F0
    if (ctx->r13 == 0) {
        // 0x8001E7D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E7F0;
    }
    goto skip_4;
    // 0x8001E7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8001E7D4: lw          $t6, -0x4D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D1C);
    // 0x8001E7D8: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x8001E7DC: bnel        $t8, $zero, L_8001E7F0
    if (ctx->r24 != 0) {
        // 0x8001E7E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E7F0;
    }
    goto skip_5;
    // 0x8001E7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8001E7E4: jal         0x8001F9B0
    // 0x8001E7E8: nop

    func_8001F9B0(rdram, ctx);
        goto after_14;
    // 0x8001E7E8: nop

    after_14:
    // 0x8001E7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E7F0:
    // 0x8001E7F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001E7F4: jr          $ra
    // 0x8001E7F8: nop

    return;
    // 0x8001E7F8: nop

;}
RECOMP_FUNC void func_8000BB68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BB6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BB70: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000BB74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000BB78: bne         $a1, $at, L_8000BCB4
    if (ctx->r5 != ctx->r1) {
        // 0x8000BB7C: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8000BCB4;
    }
    // 0x8000BB7C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000BB80: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8000BB84: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BB88: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BB8C: lw          $v0, -0x5428($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5428);
    // 0x8000BB90: addiu       $v1, $v1, -0x3690
    ctx->r3 = ADD32(ctx->r3, -0X3690);
    // 0x8000BB94: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
L_8000BB98:
    // 0x8000BB98: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BB9C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000BBA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BBA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000BBA8: bne         $a0, $zero, L_8000BB98
    if (ctx->r4 != 0) {
        // 0x8000BBAC: sb          $t7, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r15;
            goto L_8000BB98;
    }
    // 0x8000BBAC: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x8000BBB0: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8000BBB4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BBB8: addiu       $v0, $v0, -0x554C
    ctx->r2 = ADD32(ctx->r2, -0X554C);
    // 0x8000BBBC: addiu       $v1, $v1, -0x3A90
    ctx->r3 = ADD32(ctx->r3, -0X3A90);
    // 0x8000BBC0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
L_8000BBC4:
    // 0x8000BBC4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BBC8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8000BBCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000BBD0: sb          $t8, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r24;
    // 0x8000BBD4: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8000BBD8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000BBDC: sb          $t9, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r25;
    // 0x8000BBE0: lbu         $t0, -0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X2);
    // 0x8000BBE4: sb          $t0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r8;
    // 0x8000BBE8: lbu         $t1, -0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X1);
    // 0x8000BBEC: bne         $a0, $zero, L_8000BBC4
    if (ctx->r4 != 0) {
        // 0x8000BBF0: sb          $t1, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r9;
            goto L_8000BBC4;
    }
    // 0x8000BBF0: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x8000BBF4: jal         0x8002E768
    // 0x8000BBF8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002E768(rdram, ctx);
        goto after_0;
    // 0x8000BBF8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8000BBFC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000BC00: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000BC04: addiu       $a0, $a0, -0x4D1C
    ctx->r4 = ADD32(ctx->r4, -0X4D1C);
    // 0x8000BC08: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8000BC0C: lhu         $t2, 0x8($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X8);
    // 0x8000BC10: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8000BC14: addiu       $t6, $zero, 0x31
    ctx->r14 = ADD32(0, 0X31);
    // 0x8000BC18: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8000BC1C: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x8000BC20: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x8000BC24: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000BC28: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC2C: sw          $t6, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r14;
    // 0x8000BC30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC34: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8000BC38: sh          $t7, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = ctx->r15;
    // 0x8000BC3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC40: addiu       $t8, $zero, 0x2F
    ctx->r24 = ADD32(0, 0X2F);
    // 0x8000BC44: sh          $t8, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r24;
    // 0x8000BC48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC4C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8000BC50: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BC54: sh          $t9, -0x4D18($at)
    MEM_H(-0X4D18, ctx->r1) = ctx->r25;
    // 0x8000BC58: addiu       $v1, $v1, 0x5368
    ctx->r3 = ADD32(ctx->r3, 0X5368);
    // 0x8000BC5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000BC60: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x8000BC64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000BC68: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8000BC6C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8000BC70: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8000BC74: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8000BC78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC7C: swc1        $f4, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f4.u32l;
    // 0x8000BC80: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8000BC84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000BC88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BC8C: addiu       $t3, $zero, 0x108
    ctx->r11 = ADD32(0, 0X108);
    // 0x8000BC90: swc1        $f6, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f6.u32l;
    // 0x8000BC94: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000BC98: lwc1        $f8, 0x11E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X11E0);
    // 0x8000BC9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BCA0: swc1        $f8, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f8.u32l;
    // 0x8000BCA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000BCA8: sw          $t3, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r11;
    // 0x8000BCAC: b           L_8000BCF4
    // 0x8000BCB0: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
        goto L_8000BCF4;
    // 0x8000BCB0: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_8000BCB4:
    // 0x8000BCB4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BCB8: sll         $t5, $a1, 1
    ctx->r13 = S32(ctx->r5 << 1);
    // 0x8000BCBC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8000BCC0: addiu       $v1, $v1, -0x4580
    ctx->r3 = ADD32(ctx->r3, -0X4580);
    // 0x8000BCC4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8000BCC8: lhu         $t6, -0x3D40($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3D40);
    // 0x8000BCCC: lhu         $t4, 0x6($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X6);
    // 0x8000BCD0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8000BCD4: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x8000BCD8: slti        $at, $v0, 0x1F5
    ctx->r1 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8000BCDC: bne         $at, $zero, L_8000BCF0
    if (ctx->r1 != 0) {
        // 0x8000BCE0: sh          $t7, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r15;
            goto L_8000BCF0;
    }
    // 0x8000BCE0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x8000BCE4: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8000BCE8: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x8000BCEC: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
L_8000BCF0:
    // 0x8000BCF0: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_8000BCF4:
    // 0x8000BCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BCF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000BCFC: jr          $ra
    // 0x8000BD00: nop

    return;
    // 0x8000BD00: nop

    // 0x8000BD04: nop

    // 0x8000BD08: nop

    // 0x8000BD0C: nop

;}
RECOMP_FUNC void get_rand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022FD0: beq         $a0, $zero, L_8002301C
    if (ctx->r4 == 0) {
        // 0x80022FD4: lui         $v1, 0x8005
        ctx->r3 = S32(0X8005 << 16);
            goto L_8002301C;
    }
    // 0x80022FD4: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80022FD8: addiu       $v1, $v1, -0x28B8
    ctx->r3 = ADD32(ctx->r3, -0X28B8);
    // 0x80022FDC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80022FE0: lui         $at, 0x41C6
    ctx->r1 = S32(0X41C6 << 16);
    // 0x80022FE4: ori         $at, $at, 0x4E6D
    ctx->r1 = ctx->r1 | 0X4E6D;
    // 0x80022FE8: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022FEC: mflo        $t7
    ctx->r15 = lo;
    // 0x80022FF0: addiu       $t8, $t7, 0x3039
    ctx->r24 = ADD32(ctx->r15, 0X3039);
    // 0x80022FF4: srl         $t0, $t8, 16
    ctx->r8 = S32(U32(ctx->r24) >> 16);
    // 0x80022FF8: divu        $zero, $t0, $a0
    lo = S32(U32(ctx->r8) / U32(ctx->r4)); hi = S32(U32(ctx->r8) % U32(ctx->r4));
    // 0x80022FFC: mfhi        $v0
    ctx->r2 = hi;
    // 0x80023000: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80023004: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80023008: bne         $a0, $zero, L_80023014
    if (ctx->r4 != 0) {
        // 0x8002300C: nop
    
            goto L_80023014;
    }
    // 0x8002300C: nop

    // 0x80023010: break       7
    do_break(2147627024);
L_80023014:
    // 0x80023014: jr          $ra
    // 0x80023018: nop

    return;
    // 0x80023018: nop

L_8002301C:
    // 0x8002301C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80023020: jr          $ra
    // 0x80023024: nop

    return;
    // 0x80023024: nop

;}
RECOMP_FUNC void func_8000E2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E2C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E2C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E2C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E2CC: lh          $t6, 0x14($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X14);
    // 0x8000E2D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000E2D4: sh          $t7, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r15;
    // 0x8000E2D8: lh          $t8, 0x14($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X14);
    // 0x8000E2DC: bnel        $t8, $zero, L_8000E344
    if (ctx->r24 != 0) {
        // 0x8000E2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E344;
    }
    goto skip_0;
    // 0x8000E2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000E2E4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000E2E8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E2EC: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000E2F0: swc1        $f4, -0x3C44($at)
    MEM_W(-0X3C44, ctx->r1) = ctx->f4.u32l;
    // 0x8000E2F4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000E2F8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E2FC: addiu       $a0, $a0, -0x3C5C
    ctx->r4 = ADD32(ctx->r4, -0X3C5C);
    // 0x8000E300: swc1        $f6, -0x3C40($at)
    MEM_W(-0X3C40, ctx->r1) = ctx->f6.u32l;
    // 0x8000E304: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8000E308: swc1        $f8, -0x3C3C($at)
    MEM_W(-0X3C3C, ctx->r1) = ctx->f8.u32l;
    // 0x8000E30C: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000E310: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E314: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E318: swc1        $f10, -0x3C30($at)
    MEM_W(-0X3C30, ctx->r1) = ctx->f10.u32l;
    // 0x8000E31C: lwc1        $f16, -0x3C30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3C30);
    // 0x8000E320: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E324: jal         0x8001B108
    // 0x8000E328: swc1        $f16, -0x3C34($at)
    MEM_W(-0X3C34, ctx->r1) = ctx->f16.u32l;
    func_8001B108(rdram, ctx);
        goto after_0;
    // 0x8000E328: swc1        $f16, -0x3C34($at)
    MEM_W(-0X3C34, ctx->r1) = ctx->f16.u32l;
    after_0:
    // 0x8000E32C: jal         0x80022FD0
    // 0x8000E330: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x8000E330: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_1:
    // 0x8000E334: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000E338: addiu       $t9, $v0, 0x96
    ctx->r25 = ADD32(ctx->r2, 0X96);
    // 0x8000E33C: sh          $t9, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r25;
    // 0x8000E340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E344:
    // 0x8000E344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E348: jr          $ra
    // 0x8000E34C: nop

    return;
    // 0x8000E34C: nop

;}
RECOMP_FUNC void alSndpStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039960: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039968: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8003996C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039970: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x80039974: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80039978: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8003997C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80039980: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80039984: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80039988: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8003998C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80039990: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80039994: jal         0x8003FE6C
    // 0x80039998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80039998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8003999C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800399A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800399A4: jr          $ra
    // 0x800399A8: nop

    return;
    // 0x800399A8: nop

;}
RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800370D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800370D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800370D8: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800370DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800370E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800370E4: bnel        $t6, $at, L_80037134
    if (ctx->r14 != ctx->r1) {
        // 0x800370E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037134;
    }
    goto skip_0;
    // 0x800370E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800370EC: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x800370F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800370F4: beql        $a0, $zero, L_80037134
    if (ctx->r4 == 0) {
        // 0x800370F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037134;
    }
    goto skip_1;
    // 0x800370F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800370FC: jal         0x80038EDC
    // 0x80037100: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80038EDC(rdram, ctx);
        goto after_0;
    // 0x80037100: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80037104: beq         $v0, $zero, L_80037130
    if (ctx->r2 == 0) {
        // 0x80037108: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80037130;
    }
    // 0x80037108: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8003710C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80037110: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80037114: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80037118: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x8003711C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80037120: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037124: mflo        $a2
    ctx->r6 = lo;
    // 0x80037128: jal         0x8003FE6C
    // 0x8003712C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x8003712C: nop

    after_1:
L_80037130:
    // 0x80037130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037134:
    // 0x80037134: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80037138: jr          $ra
    // 0x8003713C: nop

    return;
    // 0x8003713C: nop

;}
RECOMP_FUNC void func_8001E7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001E800: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001E804: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001E808: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001E80C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001E810: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001E814: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8001E818: lw          $s0, 0x64($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X64);
    // 0x8001E81C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8001E820: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8001E824: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8001E828: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8001E82C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8001E830: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8001E834: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001E838: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8001E83C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001E840: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001E844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001E84C: jal         0x800210FC
    // 0x8001E850: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x8001E850: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    after_0:
    // 0x8001E854: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001E858: addiu       $t2, $zero, 0x12
    ctx->r10 = ADD32(0, 0X12);
    // 0x8001E85C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8001E860: addiu       $t4, $zero, 0x38
    ctx->r12 = ADD32(0, 0X38);
    // 0x8001E864: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8001E868: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8001E86C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8001E870: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8001E874: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8001E878: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8001E87C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001E880: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001E884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E888: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8001E88C: jal         0x800210FC
    // 0x8001E890: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x8001E890: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    after_1:
    // 0x8001E894: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    // 0x8001E898: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x8001E89C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001E8A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001E8A4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001E8A8: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x8001E8AC: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E8B0: bne         $t9, $zero, L_8001E8BC
    if (ctx->r25 != 0) {
        // 0x8001E8B4: nop
    
            goto L_8001E8BC;
    }
    // 0x8001E8B4: nop

    // 0x8001E8B8: break       7
    do_break(2147608760);
L_8001E8BC:
    // 0x8001E8BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E8C0: bne         $t9, $at, L_8001E8D4
    if (ctx->r25 != ctx->r1) {
        // 0x8001E8C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E8D4;
    }
    // 0x8001E8C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E8C8: bne         $t8, $at, L_8001E8D4
    if (ctx->r24 != ctx->r1) {
        // 0x8001E8CC: nop
    
            goto L_8001E8D4;
    }
    // 0x8001E8CC: nop

    // 0x8001E8D0: break       6
    do_break(2147608784);
L_8001E8D4:
    // 0x8001E8D4: beql        $a3, $zero, L_8001E91C
    if (ctx->r7 == 0) {
        // 0x8001E8D8: lhu         $t5, 0x8($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X8);
            goto L_8001E91C;
    }
    goto skip_0;
    // 0x8001E8D8: lhu         $t5, 0x8($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X8);
    skip_0:
    // 0x8001E8DC: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001E8E0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8001E8E4: addiu       $t1, $zero, 0x5E
    ctx->r9 = ADD32(0, 0X5E);
    // 0x8001E8E8: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
    // 0x8001E8EC: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x8001E8F0: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8001E8F4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8001E8F8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8001E8FC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8001E900: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001E904: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8001E908: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001E90C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8001E910: jal         0x800210FC
    // 0x8001E914: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x8001E914: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8001E918: lhu         $t5, 0x8($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X8);
L_8001E91C:
    // 0x8001E91C: lhu         $t7, 0xA($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XA);
    // 0x8001E920: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001E924: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8001E928: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8001E92C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001E930: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8001E934: mflo        $a3
    ctx->r7 = lo;
    // 0x8001E938: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001E93C: bne         $t7, $zero, L_8001E948
    if (ctx->r15 != 0) {
        // 0x8001E940: nop
    
            goto L_8001E948;
    }
    // 0x8001E940: nop

    // 0x8001E944: break       7
    do_break(2147608900);
L_8001E948:
    // 0x8001E948: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E94C: bne         $t7, $at, L_8001E960
    if (ctx->r15 != ctx->r1) {
        // 0x8001E950: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001E960;
    }
    // 0x8001E950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E954: bne         $t6, $at, L_8001E960
    if (ctx->r14 != ctx->r1) {
        // 0x8001E958: nop
    
            goto L_8001E960;
    }
    // 0x8001E958: nop

    // 0x8001E95C: break       6
    do_break(2147608924);
L_8001E960:
    // 0x8001E960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8001E964: beq         $a3, $zero, L_8001E998
    if (ctx->r7 == 0) {
        // 0x8001E968: addiu       $a2, $zero, 0x15
        ctx->r6 = ADD32(0, 0X15);
            goto L_8001E998;
    }
    // 0x8001E968: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8001E96C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8001E970: addiu       $t9, $zero, 0x5E
    ctx->r25 = ADD32(0, 0X5E);
    // 0x8001E974: addiu       $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
    // 0x8001E978: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8001E97C: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8001E980: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8001E984: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8001E988: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8001E98C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8001E990: jal         0x800210FC
    // 0x8001E994: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800210FC(rdram, ctx);
        goto after_3;
    // 0x8001E994: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
L_8001E998:
    // 0x8001E998: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001E99C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8001E9A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001E9A4: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001E9A8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8001E9AC: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8001E9B0: jal         0x80020E2C
    // 0x8001E9B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_80020E2C(rdram, ctx);
        goto after_4;
    // 0x8001E9B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_4:
    // 0x8001E9B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001E9BC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8001E9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001E9C4: jal         0x80020D4C
    // 0x8001E9C8: lhu         $a3, 0x4($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X4);
    func_80020D4C(rdram, ctx);
        goto after_5;
    // 0x8001E9C8: lhu         $a3, 0x4($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X4);
    after_5:
    // 0x8001E9CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E9D0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8001E9D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001E9D8: jal         0x80020D4C
    // 0x8001E9DC: lhu         $a3, 0x6($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X6);
    func_80020D4C(rdram, ctx);
        goto after_6;
    // 0x8001E9DC: lhu         $a3, 0x6($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X6);
    after_6:
    // 0x8001E9E0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001E9E4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8001E9E8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8001E9EC: jal         0x80020D4C
    // 0x8001E9F0: lhu         $a3, 0x8($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X8);
    func_80020D4C(rdram, ctx);
        goto after_7;
    // 0x8001E9F0: lhu         $a3, 0x8($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X8);
    after_7:
    // 0x8001E9F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E9F8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8001E9FC: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8001EA00: jal         0x80020D4C
    // 0x8001EA04: lhu         $a3, 0xA($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0XA);
    func_80020D4C(rdram, ctx);
        goto after_8;
    // 0x8001EA04: lhu         $a3, 0xA($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0XA);
    after_8:
    // 0x8001EA08: addiu       $t4, $zero, 0x70
    ctx->r12 = ADD32(0, 0X70);
    // 0x8001EA0C: addiu       $t5, $zero, 0x1D
    ctx->r13 = ADD32(0, 0X1D);
    // 0x8001EA10: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8001EA14: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001EA18: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001EA1C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001EA20: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001EA24: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8001EA28: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x8001EA2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EA30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001EA34: jal         0x80020F8C
    // 0x8001EA38: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_80020F8C(rdram, ctx);
        goto after_9;
    // 0x8001EA38: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_9:
    // 0x8001EA3C: addiu       $t8, $zero, 0x70
    ctx->r24 = ADD32(0, 0X70);
    // 0x8001EA40: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x8001EA44: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8001EA48: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8001EA4C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8001EA50: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8001EA54: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8001EA58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EA5C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x8001EA60: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8001EA64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8001EA68: jal         0x80020F8C
    // 0x8001EA6C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_80020F8C(rdram, ctx);
        goto after_10;
    // 0x8001EA6C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_10:
    // 0x8001EA70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001EA74: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001EA78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001EA7C: jr          $ra
    // 0x8001EA80: nop

    return;
    // 0x8001EA80: nop

;}
RECOMP_FUNC void func_800396D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800396D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800396D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800396DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800396E0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800396E4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800396E8: addiu       $t8, $zero, 0x3E80
    ctx->r24 = ADD32(0, 0X3E80);
    // 0x800396EC: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800396F0: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x800396F4: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800396F8: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800396FC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80039700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80039704: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80039708: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8003970C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80039710: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80039714: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80039718: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8003971C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039724: jal         0x80036660
    // 0x80039728: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80039728: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8003972C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80039730: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80039734: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80039738: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8003973C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80039740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039744: beq         $t2, $zero, L_80039768
    if (ctx->r10 == 0) {
        // 0x80039748: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80039768;
    }
    // 0x80039748: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003974C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_80039750:
    // 0x80039750: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80039754: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80039758: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8003975C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80039760: bnel        $at, $zero, L_80039750
    if (ctx->r1 != 0) {
        // 0x80039764: sw          $zero, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = 0;
            goto L_80039750;
    }
    goto skip_0;
    // 0x80039764: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    skip_0:
L_80039768:
    // 0x80039768: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8003976C: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80039770: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80039774: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80039778: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003977C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80039780: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80039784: jal         0x80036660
    // 0x80039788: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80039788: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8003978C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80039790: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80039794: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80039798: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8003979C: jal         0x8004001C
    // 0x800397A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004001C(rdram, ctx);
        goto after_2;
    // 0x800397A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x800397A4: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800397A8: lw          $a0, 0x990($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X990);
    // 0x800397AC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800397B0: addiu       $t7, $t7, -0x6E74
    ctx->r15 = ADD32(ctx->r15, -0X6E74);
    // 0x800397B4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800397B8: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800397BC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800397C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800397C4: jal         0x80044010
    // 0x800397C8: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    func_80044010(rdram, ctx);
        goto after_3;
    // 0x800397C8: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    after_3:
    // 0x800397CC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800397D0: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x800397D4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x800397D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800397DC: jal         0x8003FE6C
    // 0x800397E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800397E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x800397E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800397E8: jal         0x8003FF90
    // 0x800397EC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_8003FF90(rdram, ctx);
        goto after_5;
    // 0x800397EC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x800397F0: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x800397F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800397F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800397FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80039800: jr          $ra
    // 0x80039804: nop

    return;
    // 0x80039804: nop

    // 0x80039808: nop

    // 0x8003980C: nop

;}
RECOMP_FUNC void func_80025938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002593C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025940: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80025944: lw          $t6, 0x398C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X398C);
    // 0x80025948: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002594C: bne         $t6, $zero, L_80025960
    if (ctx->r14 != 0) {
        // 0x80025950: nop
    
            goto L_80025960;
    }
    // 0x80025950: nop

    // 0x80025954: lw          $t7, 0x3990($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3990);
    // 0x80025958: beq         $t7, $zero, L_80025968
    if (ctx->r15 == 0) {
        // 0x8002595C: nop
    
            goto L_80025968;
    }
    // 0x8002595C: nop

L_80025960:
    // 0x80025960: b           L_80025974
    // 0x80025964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80025974;
    // 0x80025964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80025968:
    // 0x80025968: jal         0x80025984
    // 0x8002596C: nop

    func_80025984(rdram, ctx);
        goto after_0;
    // 0x8002596C: nop

    after_0:
    // 0x80025970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80025974:
    // 0x80025974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002597C: jr          $ra
    // 0x80025980: nop

    return;
    // 0x80025980: nop

;}
RECOMP_FUNC void func_800248C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800248C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800248CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800248D0: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800248D4: addiu       $s1, $s1, -0x968
    ctx->r17 = ADD32(ctx->r17, -0X968);
    // 0x800248D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800248DC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800248E0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800248E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800248E8: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x800248EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800248F0: beql        $s0, $zero, L_8002494C
    if (ctx->r16 == 0) {
        // 0x800248F4: lw          $s0, 0x8($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X8);
            goto L_8002494C;
    }
    goto skip_0;
    // 0x800248F4: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x800248F8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_800248FC:
    // 0x800248FC: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x80024900: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80024904: bne         $at, $zero, L_80024948
    if (ctx->r1 != 0) {
        // 0x80024908: addiu       $v1, $v0, 0x500
        ctx->r3 = ADD32(ctx->r2, 0X500);
            goto L_80024948;
    }
    // 0x80024908: addiu       $v1, $v0, 0x500
    ctx->r3 = ADD32(ctx->r2, 0X500);
    // 0x8002490C: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80024910: bne         $at, $zero, L_8002493C
    if (ctx->r1 != 0) {
        // 0x80024914: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_8002493C;
    }
    // 0x80024914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80024918: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8002491C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80024920: lw          $t7, 0x38F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38F8);
    // 0x80024924: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80024928: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x8002492C: jal         0x80034DD0
    // 0x80024930: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80024930: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x80024934: b           L_80024A38
    // 0x80024938: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80024A38;
    // 0x80024938: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002493C:
    // 0x8002493C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80024940: bnel        $s0, $zero, L_800248FC
    if (ctx->r16 != 0) {
        // 0x80024944: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_800248FC;
    }
    goto skip_1;
    // 0x80024944: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_80024948:
    // 0x80024948: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
L_8002494C:
    // 0x8002494C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80024950: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80024954: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80024958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002495C: jal         0x80036820
    // 0x80024960: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x80024960: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    after_1:
    // 0x80024964: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80024968: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002496C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024970: beq         $a2, $zero, L_80024988
    if (ctx->r6 == 0) {
        // 0x80024974: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80024988;
    }
    // 0x80024974: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80024978: jal         0x80036850
    // 0x8002497C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x8002497C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_2:
    // 0x80024980: b           L_800249B4
    // 0x80024984: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
        goto L_800249B4;
    // 0x80024984: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
L_80024988:
    // 0x80024988: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8002498C: beql        $v0, $zero, L_800249AC
    if (ctx->r2 == 0) {
        // 0x80024990: sw          $s0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r16;
            goto L_800249AC;
    }
    goto skip_2;
    // 0x80024990: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    skip_2:
    // 0x80024994: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x80024998: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8002499C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800249A0: b           L_800249B4
    // 0x800249A4: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
        goto L_800249B4;
    // 0x800249A4: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800249A8: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
L_800249AC:
    // 0x800249AC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800249B0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800249B4:
    // 0x800249B4: andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
    // 0x800249B8: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800249BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800249C0: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x800249C4: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x800249C8: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800249CC: lw          $t2, 0x38F8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X38F8);
    // 0x800249D0: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800249D4: addiu       $t0, $t0, 0x38F4
    ctx->r8 = ADD32(ctx->r8, 0X38F4);
    // 0x800249D8: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x800249DC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800249E0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800249E4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800249E8: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800249EC: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800249F0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800249F4: addiu       $t6, $t6, -0xD90
    ctx->r14 = ADD32(ctx->r14, -0XD90);
    // 0x800249F8: addiu       $t4, $t4, -0xD58
    ctx->r12 = ADD32(ctx->r12, -0XD58);
    // 0x800249FC: addiu       $t5, $zero, 0x500
    ctx->r13 = ADD32(0, 0X500);
    // 0x80024A00: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80024A04: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80024A08: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80024A0C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80024A10: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80024A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024A18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024A1C: jal         0x80036510
    // 0x80024A20: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x80024A20: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x80024A24: jal         0x80034DD0
    // 0x80024A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80024A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80024A2C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80024A30: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80024A34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80024A38:
    // 0x80024A38: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80024A3C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80024A40: jr          $ra
    // 0x80024A44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80024A44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8002FB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB30: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002FB34: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002FB38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002FB3C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002FB40: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002FB44: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002FB48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002FB4C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8002FB50: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8002FB54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002FB58: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8002FB5C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002FB60: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002FB64: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002FB68: addiu       $t7, $t7, 0x5E0
    ctx->r15 = ADD32(ctx->r15, 0X5E0);
    // 0x8002FB6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002FB70: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x8002FB74: lh          $v1, 0x8($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X8);
    // 0x8002FB78: lh          $t8, 0x4($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4);
    // 0x8002FB7C: lh          $a1, 0xA($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XA);
    // 0x8002FB80: lh          $t4, 0x6($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X6);
    // 0x8002FB84: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8002FB88: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002FB8C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002FB90: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8002FB94: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x8002FB98: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x8002FB9C: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8002FBA0: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8002FBA4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002FBA8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002FBAC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002FBB0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8002FBB4: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8002FBB8: beq         $t9, $zero, L_8002FC14
    if (ctx->r25 == 0) {
        // 0x8002FBBC: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_8002FC14;
    }
    // 0x8002FBBC: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8002FBC0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8002FBC4: divu        $zero, $v1, $a0
    lo = S32(U32(ctx->r3) / U32(ctx->r4)); hi = S32(U32(ctx->r3) % U32(ctx->r4));
    // 0x8002FBC8: mflo        $s0
    ctx->r16 = lo;
    // 0x8002FBCC: lh          $v0, 0xC($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XC);
    // 0x8002FBD0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002FBD4: bne         $a0, $zero, L_8002FBE0
    if (ctx->r4 != 0) {
        // 0x8002FBD8: nop
    
            goto L_8002FBE0;
    }
    // 0x8002FBD8: nop

    // 0x8002FBDC: break       7
    do_break(2147679196);
L_8002FBE0:
    // 0x8002FBE0: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FBE4: mflo        $s0
    ctx->r16 = lo;
    // 0x8002FBE8: nop

    // 0x8002FBEC: nop

    // 0x8002FBF0: divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // 0x8002FBF4: mflo        $s1
    ctx->r17 = lo;
    // 0x8002FBF8: bne         $a0, $zero, L_8002FC04
    if (ctx->r4 != 0) {
        // 0x8002FBFC: nop
    
            goto L_8002FC04;
    }
    // 0x8002FBFC: nop

    // 0x8002FC00: break       7
    do_break(2147679232);
L_8002FC04:
    // 0x8002FC04: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FC08: mflo        $s1
    ctx->r17 = lo;
    // 0x8002FC0C: b           L_8002FC74
    // 0x8002FC10: sra         $t4, $s0, 1
    ctx->r12 = S32(SIGNED(ctx->r16) >> 1);
        goto L_8002FC74;
    // 0x8002FC10: sra         $t4, $s0, 1
    ctx->r12 = S32(SIGNED(ctx->r16) >> 1);
L_8002FC14:
    // 0x8002FC14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8002FC18: divu        $zero, $v1, $a0
    lo = S32(U32(ctx->r3) / U32(ctx->r4)); hi = S32(U32(ctx->r3) % U32(ctx->r4));
    // 0x8002FC1C: lh          $t2, 0xC($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XC);
    // 0x8002FC20: mflo        $s0
    ctx->r16 = lo;
    // 0x8002FC24: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002FC28: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x8002FC2C: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FC30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002FC34: bne         $a0, $zero, L_8002FC40
    if (ctx->r4 != 0) {
        // 0x8002FC38: nop
    
            goto L_8002FC40;
    }
    // 0x8002FC38: nop

    // 0x8002FC3C: break       7
    do_break(2147679292);
L_8002FC40:
    // 0x8002FC40: mflo        $s0
    ctx->r16 = lo;
    // 0x8002FC44: nop

    // 0x8002FC48: nop

    // 0x8002FC4C: divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // 0x8002FC50: mflo        $s1
    ctx->r17 = lo;
    // 0x8002FC54: bne         $a0, $zero, L_8002FC60
    if (ctx->r4 != 0) {
        // 0x8002FC58: nop
    
            goto L_8002FC60;
    }
    // 0x8002FC58: nop

    // 0x8002FC5C: break       7
    do_break(2147679324);
L_8002FC60:
    // 0x8002FC60: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FC64: mflo        $s1
    ctx->r17 = lo;
    // 0x8002FC68: nop

    // 0x8002FC6C: nop

    // 0x8002FC70: sra         $t4, $s0, 1
    ctx->r12 = S32(SIGNED(ctx->r16) >> 1);
L_8002FC74:
    // 0x8002FC74: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8002FC78: subu        $s4, $t1, $t5
    ctx->r20 = SUB32(ctx->r9, ctx->r13);
    // 0x8002FC7C: subu        $s3, $t0, $t4
    ctx->r19 = SUB32(ctx->r8, ctx->r12);
    // 0x8002FC80: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002FC84: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8002FC88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002FC8C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002FC90: jal         0x800307D8
    // 0x8002FC94: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800307D8(rdram, ctx);
        goto after_0;
    // 0x8002FC94: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // 0x8002FC98: addu        $a1, $s3, $s0
    ctx->r5 = ADD32(ctx->r19, ctx->r16);
    // 0x8002FC9C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8002FCA0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FCA4: addiu       $a2, $s4, 0x3
    ctx->r6 = ADD32(ctx->r20, 0X3);
    // 0x8002FCA8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8002FCAC: jal         0x800307D8
    // 0x8002FCB0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800307D8(rdram, ctx);
        goto after_1;
    // 0x8002FCB0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x8002FCB4: addu        $a2, $s4, $s1
    ctx->r6 = ADD32(ctx->r20, ctx->r17);
    // 0x8002FCB8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002FCBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002FCC0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8002FCC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FCC8: addiu       $a1, $s3, 0x3
    ctx->r5 = ADD32(ctx->r19, 0X3);
    // 0x8002FCCC: jal         0x800307D8
    // 0x8002FCD0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800307D8(rdram, ctx);
        goto after_2;
    // 0x8002FCD0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x8002FCD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002FCD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002FCDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FCE0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002FCE4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8002FCE8: jal         0x800307D8
    // 0x8002FCEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800307D8(rdram, ctx);
        goto after_3;
    // 0x8002FCEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x8002FCF0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FCF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002FCF8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002FCFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FD00: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002FD04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002FD08: jal         0x800307D8
    // 0x8002FD0C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_800307D8(rdram, ctx);
        goto after_4;
    // 0x8002FD0C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_4:
    // 0x8002FD10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FD14: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8002FD18: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8002FD1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002FD20: jal         0x800307D8
    // 0x8002FD24: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800307D8(rdram, ctx);
        goto after_5;
    // 0x8002FD24: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // 0x8002FD28: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002FD2C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FD30: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8002FD34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002FD38: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8002FD3C: jal         0x800307D8
    // 0x8002FD40: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800307D8(rdram, ctx);
        goto after_6;
    // 0x8002FD40: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_6:
    // 0x8002FD44: lh          $t9, 0xC($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XC);
    // 0x8002FD48: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002FD4C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8002FD50: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x8002FD54: sh          $t3, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r11;
    // 0x8002FD58: lh          $t4, 0xC($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XC);
    // 0x8002FD5C: sltu        $at, $t2, $t4
    ctx->r1 = ctx->r10 < ctx->r12 ? 1 : 0;
    // 0x8002FD60: beql        $at, $zero, L_8002FD70
    if (ctx->r1 == 0) {
        // 0x8002FD64: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8002FD70;
    }
    goto skip_0;
    // 0x8002FD64: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x8002FD68: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8002FD6C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_8002FD70:
    // 0x8002FD70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002FD74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002FD78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002FD7C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002FD80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FD84: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002FD88: jr          $ra
    // 0x8002FD8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002FD8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80008CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CF4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80008CF8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80008CFC: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80008D00: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80008D04: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x80008D08: addiu       $s6, $s6, -0x2F74
    ctx->r22 = ADD32(ctx->r22, -0X2F74);
    // 0x80008D0C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80008D10: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80008D14: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80008D18: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80008D1C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80008D20: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80008D24: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80008D28: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80008D2C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80008D30: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80008D34: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80008D38: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80008D3C: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x80008D40: addiu       $s4, $s4, -0x2F70
    ctx->r20 = ADD32(ctx->r20, -0X2F70);
    // 0x80008D44: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80008D48: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80008D4C: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x80008D50: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80008D54: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80008D58: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x80008D5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80008D60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80008D64: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80008D68: lw          $s3, -0x3670($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X3670);
    // 0x80008D6C: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80008D70: addiu       $s2, $s2, -0x3668
    ctx->r18 = ADD32(ctx->r18, -0X3668);
    // 0x80008D74: beq         $s3, $zero, L_80008EC0
    if (ctx->r19 == 0) {
        // 0x80008D78: lui         $fp, 0x8008
        ctx->r30 = S32(0X8008 << 16);
            goto L_80008EC0;
    }
    // 0x80008D78: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80008D7C: addiu       $fp, $fp, -0x2F58
    ctx->r30 = ADD32(ctx->r30, -0X2F58);
    // 0x80008D80: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x80008D84: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_80008D88:
    // 0x80008D88: lh          $t9, 0x74($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X74);
    // 0x80008D8C: addiu       $s0, $s2, 0x24
    ctx->r16 = ADD32(ctx->r18, 0X24);
    // 0x80008D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008D94: beq         $s7, $t9, L_80008EB8
    if (ctx->r23 == ctx->r25) {
        // 0x80008D98: nop
    
            goto L_80008EB8;
    }
    // 0x80008D98: nop

    // 0x80008D9C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80008DA0: lh          $t1, 0x50($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X50);
    // 0x80008DA4: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x80008DA8: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x80008DAC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008DB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80008DB4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80008DB8: lw          $s1, 0x0($t3)
    ctx->r17 = MEM_W(ctx->r11, 0X0);
    // 0x80008DBC: bne         $t4, $at, L_80008E00
    if (ctx->r12 != ctx->r1) {
        // 0x80008DC0: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80008E00;
    }
    // 0x80008DC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80008DC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008DC8: lwc1        $f2, -0x4530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x80008DCC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80008DD0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80008DD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80008DD8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80008DDC: bc1fl       L_80008DF0
    if (!c1cs) {
        // 0x80008DE0: add.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_80008DF0;
    }
    goto skip_0;
    // 0x80008DE0: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
    // 0x80008DE4: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x80008DE8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008DEC: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
L_80008DF0:
    // 0x80008DF0: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
    // 0x80008DF4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80008DF8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008DFC: swc1        $f10, 0x94($t5)
    MEM_W(0X94, ctx->r13) = ctx->f10.u32l;
L_80008E00:
    // 0x80008E00: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x80008E04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80008E08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80008E0C: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008E10: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80008E14: mflo        $t7
    ctx->r15 = lo;
    // 0x80008E18: addu        $a2, $t7, $s1
    ctx->r6 = ADD32(ctx->r15, ctx->r17);
    // 0x80008E1C: jal         0x8001DB38
    // 0x80008E20: nop

    func_8001DB38(rdram, ctx);
        goto after_0;
    // 0x80008E20: nop

    after_0:
    // 0x80008E24: lh          $t8, 0x52($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X52);
    // 0x80008E28: lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X58);
    // 0x80008E2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80008E30: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80008E34: mflo        $t9
    ctx->r25 = lo;
    // 0x80008E38: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x80008E3C: jal         0x8001E0AC
    // 0x80008E40: nop

    func_8001E0AC(rdram, ctx);
        goto after_1;
    // 0x80008E40: nop

    after_1:
    // 0x80008E44: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80008E48: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x80008E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008E50: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x80008E54: beql        $t0, $at, L_80008EA4
    if (ctx->r8 == ctx->r1) {
        // 0x80008E58: sw          $s0, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r16;
            goto L_80008EA4;
    }
    goto skip_1;
    // 0x80008E58: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    skip_1:
    // 0x80008E5C: lhu         $t2, 0x62($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X62);
    // 0x80008E60: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x80008E64: bnel        $t3, $zero, L_80008EA4
    if (ctx->r11 != 0) {
        // 0x80008E68: sw          $s0, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r16;
            goto L_80008EA4;
    }
    goto skip_2;
    // 0x80008E68: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    skip_2:
    // 0x80008E6C: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80008E70: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008E74: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80008E78: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80008E7C: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x80008E80: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80008E84: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80008E88: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80008E8C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80008E90: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80008E94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80008E98: jal         0x80011860
    // 0x80008E9C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_80011860(rdram, ctx);
        goto after_2;
    // 0x80008E9C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80008EA0: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
L_80008EA4:
    // 0x80008EA4: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x80008EA8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80008EAC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80008EB0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80008EB4: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
L_80008EB8:
    // 0x80008EB8: bne         $s3, $zero, L_80008D88
    if (ctx->r19 != 0) {
        // 0x80008EBC: addiu       $s2, $s2, 0x128
        ctx->r18 = ADD32(ctx->r18, 0X128);
            goto L_80008D88;
    }
    // 0x80008EBC: addiu       $s2, $s2, 0x128
    ctx->r18 = ADD32(ctx->r18, 0X128);
L_80008EC0:
    // 0x80008EC0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80008EC4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80008EC8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80008ECC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80008ED0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80008ED4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80008ED8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80008EDC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80008EE0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80008EE4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80008EE8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80008EEC: jr          $ra
    // 0x80008EF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80008EF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80049178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049178: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x8004917C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049180: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80049184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049188: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8004918C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80049190: beq         $at, $zero, L_800493C0
    if (ctx->r1 == 0) {
        // 0x80049194: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_800493C0;
    }
    // 0x80049194: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80049198: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004919C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800491A0: addu        $at, $at, $t6
    gpr jr_addend_800491A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800491A4: lw          $t6, 0x2390($at)
    ctx->r14 = ADD32(ctx->r1, 0X2390);
    // 0x800491A8: jr          $t6
    // 0x800491AC: nop

    switch (jr_addend_800491A8 >> 2) {
        case 0: goto L_800491B0; break;
        case 1: goto L_800491E4; break;
        case 2: goto L_80049244; break;
        case 3: goto L_80049218; break;
        case 4: goto L_80049270; break;
        case 5: goto L_8004929C; break;
        case 6: goto L_80049304; break;
        case 7: goto L_8004937C; break;
        default: switch_error(__func__, 0x800491A8, 0x80072390);
    }
    // 0x800491AC: nop

L_800491B0:
    // 0x800491B0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800491B4: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x800491B8: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800491BC: bgez        $v1, L_800491CC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800491C0: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800491CC;
    }
    // 0x800491C0: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800491C4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800491C8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800491CC:
    // 0x800491CC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800491D0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800491D4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800491D8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800491DC: b           L_800493C0
    // 0x800491E0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_800493C0;
    // 0x800491E0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_800491E4:
    // 0x800491E4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800491E8: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x800491EC: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x800491F0: bgez        $v1, L_80049200
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800491F4: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80049200;
    }
    // 0x800491F4: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800491F8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800491FC: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80049200:
    // 0x80049200: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80049204: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80049208: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8004920C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80049210: b           L_800493C0
    // 0x80049214: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_800493C0;
    // 0x80049214: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_80049218:
    // 0x80049218: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8004921C: bgez        $v1, L_8004922C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80049220: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8004922C;
    }
    // 0x80049220: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80049224: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80049228: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8004922C:
    // 0x8004922C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80049230: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80049234: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80049238: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8004923C: b           L_800493C0
    // 0x80049240: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_800493C0;
    // 0x80049240: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_80049244:
    // 0x80049244: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x80049248: bgez        $v1, L_80049258
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004924C: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80049258;
    }
    // 0x8004924C: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80049250: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80049254: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_80049258:
    // 0x80049258: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8004925C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80049260: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80049264: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80049268: b           L_800493C0
    // 0x8004926C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_800493C0;
    // 0x8004926C: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_80049270:
    // 0x80049270: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80049274: bgez        $v1, L_80049284
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80049278: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80049284;
    }
    // 0x80049278: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004927C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80049280: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_80049284:
    // 0x80049284: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80049288: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8004928C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80049290: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80049294: b           L_800493C0
    // 0x80049298: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_800493C0;
    // 0x80049298: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_8004929C:
    // 0x8004929C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800492A0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800492A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800492A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800492AC: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x800492B0: lw          $t2, 0x990($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X990);
    // 0x800492B4: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800492B8: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x800492BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800492C0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800492C4: nop

    // 0x800492C8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800492CC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800492D0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800492D4: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x800492D8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800492DC: bgez        $v1, L_800492EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800492E0: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800492EC;
    }
    // 0x800492E0: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800492E4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800492E8: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800492EC:
    // 0x800492EC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800492F0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800492F4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800492F8: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x800492FC: b           L_800493C0
    // 0x80049300: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_800493C0;
    // 0x80049300: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_80049304:
    // 0x80049304: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80049308: bgez        $v1, L_80049318
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004930C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80049318;
    }
    // 0x8004930C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80049310: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80049314: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80049318:
    // 0x80049318: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8004931C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80049320: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80049324: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80049328: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8004932C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80049330: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80049334: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80049338: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x8004933C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80049340: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80049344: bgez        $t6, L_8004935C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80049348: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_8004935C;
    }
    // 0x80049348: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8004934C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80049350: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80049354: nop

    // 0x80049358: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_8004935C:
    // 0x8004935C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049360: ldc1        $f10, 0x23B0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X23B0);
    // 0x80049364: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80049368: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8004936C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80049370: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80049374: b           L_800493C0
    // 0x80049378: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_800493C0;
    // 0x80049378: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_8004937C:
    // 0x8004937C: bgez        $v1, L_8004938C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80049380: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8004938C;
    }
    // 0x80049380: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80049384: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80049388: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8004938C:
    // 0x8004938C: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x80049390: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80049394: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80049398: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004939C: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x800493A0: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x800493A4: beql        $a1, $zero, L_800493C4
    if (ctx->r5 == 0) {
        // 0x800493A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800493C4;
    }
    goto skip_0;
    // 0x800493A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800493AC: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800493B0: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800493B4: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800493B8: jal         0x80040350
    // 0x800493BC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x800493BC: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
L_800493C0:
    // 0x800493C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800493C4:
    // 0x800493C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800493C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800493CC: jr          $ra
    // 0x800493D0: nop

    return;
    // 0x800493D0: nop

;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048A40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80048A44: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80048A48: blez        $a2, L_80048AAC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80048A4C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80048AAC;
    }
    // 0x80048A4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80048A50: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80048A54: beq         $a1, $zero, L_80048A7C
    if (ctx->r5 == 0) {
        // 0x80048A58: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80048A7C;
    }
    // 0x80048A58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80048A5C:
    // 0x80048A5C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80048A60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80048A64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048A68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80048A6C: bne         $a0, $a3, L_80048A5C
    if (ctx->r4 != ctx->r7) {
        // 0x80048A70: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_80048A5C;
    }
    // 0x80048A70: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x80048A74: beq         $a3, $a2, L_80048AAC
    if (ctx->r7 == ctx->r6) {
        // 0x80048A78: nop
    
            goto L_80048AAC;
    }
    // 0x80048A78: nop

L_80048A7C:
    // 0x80048A7C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80048A80: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80048A84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80048A88: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x80048A8C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80048A90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80048A94: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80048A98: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80048A9C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x80048AA0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x80048AA4: bne         $a3, $a2, L_80048A7C
    if (ctx->r7 != ctx->r6) {
        // 0x80048AA8: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_80048A7C;
    }
    // 0x80048AA8: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_80048AAC:
    // 0x80048AAC: jr          $ra
    // 0x80048AB0: nop

    return;
    // 0x80048AB0: nop

;}
RECOMP_FUNC void func_80030E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030E10: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80030E14: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80030E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030E1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80030E20: beq         $t0, $t6, L_80030E48
    if (ctx->r8 == ctx->r14) {
        // 0x80030E24: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80030E48;
    }
    // 0x80030E24: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80030E28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80030E2C: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
L_80030E30:
    // 0x80030E30: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80030E34: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x80030E38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030E3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80030E40: bne         $t0, $a3, L_80030E30
    if (ctx->r8 != ctx->r7) {
        // 0x80030E44: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80030E30;
    }
    // 0x80030E44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80030E48:
    // 0x80030E48: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x80030E4C: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80030E50: jr          $ra
    // 0x80030E54: nop

    return;
    // 0x80030E54: nop

;}
RECOMP_FUNC void func_80015B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B50: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80015B54: lhu         $t6, 0x6F1C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X6F1C);
    // 0x80015B58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015B5C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80015B60: bne         $t6, $zero, L_80015B80
    if (ctx->r14 != 0) {
        // 0x80015B64: addiu       $v0, $v0, 0x6F18
        ctx->r2 = ADD32(ctx->r2, 0X6F18);
            goto L_80015B80;
    }
    // 0x80015B64: addiu       $v0, $v0, 0x6F18
    ctx->r2 = ADD32(ctx->r2, 0X6F18);
    // 0x80015B68: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80015B6C:
    // 0x80015B6C: beq         $v1, $zero, L_80015B80
    if (ctx->r3 == 0) {
        // 0x80015B70: addiu       $v0, $v0, 0x3C
        ctx->r2 = ADD32(ctx->r2, 0X3C);
            goto L_80015B80;
    }
    // 0x80015B70: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x80015B74: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x80015B78: beql        $t7, $zero, L_80015B6C
    if (ctx->r15 == 0) {
        // 0x80015B7C: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80015B6C;
    }
    goto skip_0;
    // 0x80015B7C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
L_80015B80:
    // 0x80015B80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015B84: jr          $ra
    // 0x80015B88: nop

    return;
    // 0x80015B88: nop

;}
RECOMP_FUNC void func_80042B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042B50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80042B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042B58: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80042B5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042B60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80042B64: bne         $t6, $at, L_80042C1C
    if (ctx->r14 != ctx->r1) {
        // 0x80042B68: lw          $a2, 0x18($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X18);
            goto L_80042C1C;
    }
    // 0x80042B68: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80042B6C: beq         $a2, $zero, L_80042C1C
    if (ctx->r6 == 0) {
        // 0x80042B70: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80042C1C;
    }
    // 0x80042B70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80042B74: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80042B78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80042B7C: jal         0x80049BA0
    // 0x80042B80: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80049BA0(rdram, ctx);
        goto after_0;
    // 0x80042B80: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80042B84: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80042B88: beq         $v0, $zero, L_80042C1C
    if (ctx->r2 == 0) {
        // 0x80042B8C: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_80042C1C;
    }
    // 0x80042B8C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80042B90: lw          $t7, 0x84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X84);
    // 0x80042B94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80042B98: beql        $t7, $zero, L_80042BFC
    if (ctx->r15 == 0) {
        // 0x80042B9C: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_80042BFC;
    }
    goto skip_0;
    // 0x80042B9C: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x80042BA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80042BA4: jal         0x80049768
    // 0x80042BA8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80049768(rdram, ctx);
        goto after_1;
    // 0x80042BA8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x80042BAC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80042BB0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80042BB4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80042BB8: lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X80);
    // 0x80042BBC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80042BC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80042BC4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80042BC8: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80042BCC: bnel        $at, $zero, L_80042BFC
    if (ctx->r1 != 0) {
        // 0x80042BD0: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_80042BFC;
    }
    goto skip_1;
    // 0x80042BD0: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x80042BD4: lw          $a1, 0x7C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X7C);
    // 0x80042BD8: jal         0x8004974C
    // 0x80042BDC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8004974C(rdram, ctx);
        goto after_2;
    // 0x80042BDC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x80042BE0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80042BE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80042BE8: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x80042BEC: beq         $v0, $at, L_80042BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80042BF0: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80042BF8;
    }
    // 0x80042BF0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80042BF4: sw          $t2, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r10;
L_80042BF8:
    // 0x80042BF8: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_80042BFC:
    // 0x80042BFC: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    // 0x80042C00: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80042C04: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80042C08: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80042C0C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042C10: mflo        $a2
    ctx->r6 = lo;
    // 0x80042C14: jal         0x8003FE6C
    // 0x80042C18: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80042C18: nop

    after_3:
L_80042C1C:
    // 0x80042C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042C20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80042C24: jr          $ra
    // 0x80042C28: nop

    return;
    // 0x80042C28: nop

;}
RECOMP_FUNC void nnScCreateScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000534: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000053C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000540: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80000544: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000548: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000054C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80000550: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    // 0x80000554: sw          $zero, 0x670($s0)
    MEM_W(0X670, ctx->r16) = 0;
    // 0x80000558: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
    // 0x8000055C: sw          $zero, 0x668($s0)
    MEM_W(0X668, ctx->r16) = 0;
    // 0x80000560: sw          $t6, 0x678($s0)
    MEM_W(0X678, ctx->r16) = ctx->r14;
    // 0x80000564: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80000568: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8000056C: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x80000570: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80000574: addiu       $a1, $s0, 0x8C
    ctx->r5 = ADD32(ctx->r16, 0X8C);
    // 0x80000578: jal         0x80033F10
    // 0x8000057C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000057C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80000580: addiu       $a0, $s0, 0xAC
    ctx->r4 = ADD32(ctx->r16, 0XAC);
    // 0x80000584: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80000588: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8000058C: jal         0x80033F10
    // 0x80000590: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80000590: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80000594: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80000598: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8000059C: addiu       $a1, $s0, 0xFC
    ctx->r5 = ADD32(ctx->r16, 0XFC);
    // 0x800005A0: jal         0x80033F10
    // 0x800005A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800005A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800005A8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x800005AC: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x800005B0: jal         0x80033F10
    // 0x800005B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800005B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800005B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x800005BC: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x800005C0: jal         0x80033F10
    // 0x800005C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800005C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x800005C8: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x800005CC: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x800005D0: jal         0x80033F10
    // 0x800005D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800005D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800005D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800005DC: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x800005E0: jal         0x80033F40
    // 0x800005E4: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    osViSetEvent_recomp(rdram, ctx);
        goto after_6;
    // 0x800005E4: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    after_6:
    // 0x800005E8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800005EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800005F0: jal         0x80033FB0
    // 0x800005F4: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800005F4: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_7:
    // 0x800005F8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800005FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80000600: jal         0x80033FB0
    // 0x80000604: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80000604: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_8:
    // 0x80000608: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8000060C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80000610: jal         0x80033FB0
    // 0x80000614: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80000614: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_9:
    // 0x80000618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000061C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000620: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80000624: jr          $ra
    // 0x80000628: nop

    return;
    // 0x80000628: nop

;}
RECOMP_FUNC void func_8000A7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A7E0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000A7E4: lh          $t7, 0x50($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X50);
    // 0x8000A7E8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000A7EC: lw          $t6, -0x2F58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F58);
    // 0x8000A7F0: lh          $t0, 0x52($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X52);
    // 0x8000A7F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000A7F8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000A7FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000A800: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000A804: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8000A808: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000A80C: lw          $a2, 0x24($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X24);
    // 0x8000A810: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8000A814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000A818: jal         0x8001D924
    // 0x8000A81C: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    func_8001D924(rdram, ctx);
        goto after_0;
    // 0x8000A81C: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    after_0:
    // 0x8000A820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A824: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A828: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8000A82C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000A830: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8000A834: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8000A838: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x8000A83C: jal         0x800232F4
    // 0x8000A840: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x8000A840: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    after_1:
    // 0x8000A844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A84C: jr          $ra
    // 0x8000A850: nop

    return;
    // 0x8000A850: nop

;}
RECOMP_FUNC void func_8001EA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EA84: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001EA88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001EA8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001EA90: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001EA94: addiu       $t6, $zero, 0x104
    ctx->r14 = ADD32(0, 0X104);
    // 0x8001EA98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EA9C: sw          $t6, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r14;
    // 0x8001EAA0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001EAA4: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8001EAA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8001EAAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001EAB0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001EAB4: sw          $t7, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r15;
    // 0x8001EAB8: lw          $a3, 0x6DEC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6DEC);
    // 0x8001EABC: jal         0x80023570
    // 0x8001EAC0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_80023570(rdram, ctx);
        goto after_0;
    // 0x8001EAC0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8001EAC4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001EAC8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8001EACC: lw          $t8, -0x39B8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39B8);
    // 0x8001EAD0: lw          $t3, -0x39B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X39B4);
    // 0x8001EAD4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001EAD8: addiu       $t9, $t8, 0x11
    ctx->r25 = ADD32(ctx->r24, 0X11);
    // 0x8001EADC: addiu       $t4, $t3, 0x11
    ctx->r12 = ADD32(ctx->r11, 0X11);
    // 0x8001EAE0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001EAE4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8001EAE8: addiu       $t2, $t2, -0x4D08
    ctx->r10 = ADD32(ctx->r10, -0X4D08);
    // 0x8001EAEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001EAF0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8001EAF4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8001EAF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001EAFC: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8001EB00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EB04: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x8001EB08: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8001EB0C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x8001EB10: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001EB14: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8001EB18: jal         0x80035200
    // 0x8001EB1C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8001EB1C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8001EB20: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001EB24: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001EB28: addiu       $t2, $t2, -0x4D08
    ctx->r10 = ADD32(ctx->r10, -0X4D08);
    // 0x8001EB2C: addiu       $t1, $t1, -0x4D04
    ctx->r9 = ADD32(ctx->r9, -0X4D04);
    // 0x8001EB30: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8001EB34: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8001EB38: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x8001EB3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001EB40: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8001EB44: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001EB48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001EB4C: lui         $t5, 0x200
    ctx->r13 = S32(0X200 << 16);
    // 0x8001EB50: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x8001EB54: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8001EB58: addiu       $t6, $t4, 0xC0
    ctx->r14 = ADD32(ctx->r12, 0XC0);
    // 0x8001EB5C: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8001EB60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001EB64: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8001EB68: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8001EB6C: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001EB70: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001EB74: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8001EB78: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8001EB7C: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8001EB80: addiu       $t6, $t6, -0x7160
    ctx->r14 = ADD32(ctx->r14, -0X7160);
    // 0x8001EB84: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8001EB88: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8001EB8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001EB90: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001EB94: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x8001EB98: addiu       $t7, $zero, 0x93
    ctx->r15 = ADD32(0, 0X93);
    // 0x8001EB9C: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001EBA0: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EBA4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001EBA8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001EBAC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001EBB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001EBB4: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001EBB8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8001EBBC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8001EBC0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x8001EBC4: jal         0x800210FC
    // 0x8001EBC8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x8001EBC8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x8001EBCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EBD0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001EBD4: jr          $ra
    // 0x8001EBD8: nop

    return;
    // 0x8001EBD8: nop

;}
RECOMP_FUNC void func_8001EBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EBDC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EBE0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8001EBE4: lui         $s0, 0x803A
    ctx->r16 = S32(0X803A << 16);
    // 0x8001EBE8: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8001EBEC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001EBF0: addiu       $s0, $s0, 0x6F40
    ctx->r16 = ADD32(ctx->r16, 0X6F40);
    // 0x8001EBF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001EBF8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8001EBFC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8001EC00: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8001EC04: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8001EC08: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8001EC0C: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EC10: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8001EC14: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8001EC18: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8001EC1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8001EC20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001EC24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001EC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EC2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EC30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EC34: jal         0x800210FC
    // 0x8001EC38: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x8001EC38: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x8001EC3C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8001EC40: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x8001EC44: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8001EC48: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8001EC4C: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8001EC50: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8001EC54: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8001EC58: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8001EC5C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8001EC60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001EC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001EC68: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8001EC6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EC70: jal         0x800210FC
    // 0x8001EC74: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x8001EC74: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x8001EC78: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8001EC7C: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x8001EC80: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8001EC84: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001EC88: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8001EC8C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8001EC90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8001EC94: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8001EC98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001EC9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001ECA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001ECA4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8001ECA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001ECAC: jal         0x800210FC
    // 0x8001ECB0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x8001ECB0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_2:
    // 0x8001ECB4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8001ECB8: addiu       $t2, $zero, 0x44
    ctx->r10 = ADD32(0, 0X44);
    // 0x8001ECBC: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8001ECC0: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8001ECC4: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8001ECC8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8001ECCC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8001ECD0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8001ECD4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8001ECD8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001ECDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001ECE0: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x8001ECE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001ECE8: jal         0x800210FC
    // 0x8001ECEC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800210FC(rdram, ctx);
        goto after_3;
    // 0x8001ECEC: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_3:
    // 0x8001ECF0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8001ECF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001ECF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001ECFC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8001ED00: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8001ED04: jal         0x80020E2C
    // 0x8001ED08: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_80020E2C(rdram, ctx);
        goto after_4;
    // 0x8001ED08: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_4:
    // 0x8001ED0C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8001ED10: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8001ED14: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8001ED18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001ED1C:
    // 0x8001ED1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001ED20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001ED24: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8001ED28: jal         0x80020D4C
    // 0x8001ED2C: lbu         $a3, 0x24($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X24);
    func_80020D4C(rdram, ctx);
        goto after_5;
    // 0x8001ED2C: lbu         $a3, 0x24($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X24);
    after_5:
    // 0x8001ED30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001ED34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001ED38: bne         $s1, $s3, L_8001ED1C
    if (ctx->r17 != ctx->r19) {
        // 0x8001ED3C: addiu       $s0, $s0, 0x16
        ctx->r16 = ADD32(ctx->r16, 0X16);
            goto L_8001ED1C;
    }
    // 0x8001ED3C: addiu       $s0, $s0, 0x16
    ctx->r16 = ADD32(ctx->r16, 0X16);
    // 0x8001ED40: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001ED44: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8001ED48: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8001ED4C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8001ED50: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8001ED54: jr          $ra
    // 0x8001ED58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001ED58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80100BE8_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100BE8: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80100BEC: lw          $t6, 0x6FE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FE8);
    // 0x80100BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80100BF4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80100BF8: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80100BFC: bgez        $t7, L_80100C08
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80100C00: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_80100C08;
    }
    // 0x80100C00: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80100C04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80100C08:
    // 0x80100C08: addiu       $v0, $v0, 0x7038
    ctx->r2 = ADD32(ctx->r2, 0X7038);
    // 0x80100C0C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80100C10: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100C14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80100C18: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80100C1C: beq         $t9, $zero, L_80100C28
    if (ctx->r25 == 0) {
        // 0x80100C20: addiu       $a2, $zero, 0x96
        ctx->r6 = ADD32(0, 0X96);
            goto L_80100C28;
    }
    // 0x80100C20: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80100C24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80100C28:
    // 0x80100C28: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80100C2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80100C30: and         $t1, $t0, $a1
    ctx->r9 = ctx->r8 & ctx->r5;
    // 0x80100C34: beql        $t1, $zero, L_80100C44
    if (ctx->r9 == 0) {
        // 0x80100C38: lw          $t2, 0x50($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X50);
            goto L_80100C44;
    }
    goto skip_0;
    // 0x80100C38: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x80100C3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100C40: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
L_80100C44:
    // 0x80100C44: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100C48: and         $t3, $t2, $a1
    ctx->r11 = ctx->r10 & ctx->r5;
    // 0x80100C4C: beql        $t3, $zero, L_80100C5C
    if (ctx->r11 == 0) {
        // 0x80100C50: lw          $t4, 0x50($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X50);
            goto L_80100C5C;
    }
    goto skip_1;
    // 0x80100C50: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x80100C54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100C58: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
L_80100C5C:
    // 0x80100C5C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100C60: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x80100C64: beql        $t5, $zero, L_80100C74
    if (ctx->r13 == 0) {
        // 0x80100C68: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_80100C74;
    }
    goto skip_2;
    // 0x80100C68: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x80100C6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100C70: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
L_80100C74:
    // 0x80100C74: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100C78: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x80100C7C: beq         $t7, $zero, L_80100C88
    if (ctx->r15 == 0) {
        // 0x80100C80: nop
    
            goto L_80100C88;
    }
    // 0x80100C80: nop

    // 0x80100C84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80100C88:
    // 0x80100C88: bne         $v1, $a2, L_80100C28
    if (ctx->r3 != ctx->r6) {
        // 0x80100C8C: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80100C28;
    }
    // 0x80100C8C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100C90: jr          $ra
    // 0x80100C94: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80100C94: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80012740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012740: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80012744: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80012748: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001274C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80012750: addiu       $t8, $t8, 0x6AE8
    ctx->r24 = ADD32(ctx->r24, 0X6AE8);
    // 0x80012754: sra         $t7, $a0, 3
    ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80012758: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8001275C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80012760: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80012764: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80012768: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001276C: lbu         $t1, -0x28C0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X28C0);
    // 0x80012770: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80012774: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80012778: jr          $ra
    // 0x8001277C: nop

    return;
    // 0x8001277C: nop

;}
RECOMP_FUNC void func_8001205C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001205C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012068: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001206C: jal         0x800121B0
    // 0x80012070: lhu         $a0, 0x62($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X62);
    func_800121B0(rdram, ctx);
        goto after_0;
    // 0x80012070: lhu         $a0, 0x62($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X62);
    after_0:
    // 0x80012074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80012078: ori         $t7, $zero, 0x805B
    ctx->r15 = 0 | 0X805B;
    // 0x8001207C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80012080: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012084: sh          $t7, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r15;
    // 0x80012088: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8001208C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80012090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80012094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80012098: jal         0x8001D8B0
    // 0x8001209C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x8001209C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x800120A0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x800120A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800120A8: jal         0x800268D4
    // 0x800120AC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x800120AC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_2:
    // 0x800120B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800120B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800120B8: jr          $ra
    // 0x800120BC: nop

    return;
    // 0x800120BC: nop

;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800424D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800424D4: bne         $a1, $at, L_800424F8
    if (ctx->r5 != ctx->r1) {
        // 0x800424D8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800424F8;
    }
    // 0x800424D8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800424DC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800424E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800424E4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800424E8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800424EC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800424F0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800424F4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800424F8:
    // 0x800424F8: jr          $ra
    // 0x800424FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800424FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80036D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036D00: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80036D04: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80036D08: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80036D0C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80036D10: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80036D14: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80036D18: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80036D1C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80036D20: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80036D24: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80036D28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80036D2C: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x80036D30: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80036D34: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80036D38: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80036D3C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80036D40: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x80036D44: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x80036D48: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80036D4C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x80036D50: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x80036D54: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80036D58: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80036D5C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80036D60: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x80036D64: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80036D68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80036D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036D74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80036D78: jal         0x80036660
    // 0x80036D7C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80036D7C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x80036D80: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80036D84: jal         0x80040090
    // 0x80036D88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x80036D88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80036D8C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80036D90: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80036D94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D98: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x80036D9C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80036DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036DA4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80036DA8: jal         0x80036660
    // 0x80036DAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80036DAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80036DB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80036DB4: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x80036DB8: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x80036DBC: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80036DC0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80036DC4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80036DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036DD0: jal         0x80036660
    // 0x80036DD4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80036DD4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x80036DD8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80036DDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80036DE0: jal         0x80040128
    // 0x80036DE4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x80036DE4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x80036DE8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80036DEC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80036DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036DF8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80036DFC: jal         0x80036660
    // 0x80036E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80036E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80036E04: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x80036E08: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80036E0C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80036E10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80036E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036E1C: jal         0x80036660
    // 0x80036E20: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x80036E20: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x80036E24: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80036E28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80036E2C: jal         0x800400D4
    // 0x80036E30: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alMainBusNew(rdram, ctx);
        goto after_7;
    // 0x80036E30: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x80036E34: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x80036E38: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80036E3C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80036E40: beq         $t7, $zero, L_80036E5C
    if (ctx->r15 == 0) {
        // 0x80036E44: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80036E5C;
    }
    // 0x80036E44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80036E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036E4C: jal         0x80040830
    // 0x80036E50: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_80040830(rdram, ctx);
        goto after_8;
    // 0x80036E50: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x80036E54: b           L_80036E6C
    // 0x80036E58: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_80036E6C;
    // 0x80036E58: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_80036E5C:
    // 0x80036E5C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80036E60: jal         0x800408D0
    // 0x80036E64: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    func_800408D0(rdram, ctx);
        goto after_9;
    // 0x80036E64: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x80036E68: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_80036E6C:
    // 0x80036E6C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x80036E70: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x80036E74: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x80036E78: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x80036E7C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x80036E80: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80036E84: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x80036E88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80036E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036E94: jal         0x80036660
    // 0x80036E98: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x80036E98: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x80036E9C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x80036EA0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80036EA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80036EA8: blez        $t9, L_80036F68
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80036EAC: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_80036F68;
    }
    // 0x80036EAC: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80036EB0: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x80036EB4: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x80036EB8: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x80036EBC: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_80036EC0:
    // 0x80036EC0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80036EC4: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x80036EC8: jal         0x80036850
    // 0x80036ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036850(rdram, ctx);
        goto after_11;
    // 0x80036ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80036ED0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80036ED4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x80036ED8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036EDC: jal         0x80040204
    // 0x80036EE0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_12;
    // 0x80036EE0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x80036EE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80036EEC: jal         0x80040A20
    // 0x80036EF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80040A20(rdram, ctx);
        goto after_13;
    // 0x80036EF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80036EF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80036EF8: jal         0x8004017C
    // 0x80036EFC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_14;
    // 0x80036EFC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x80036F00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80036F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80036F08: jal         0x80041570
    // 0x80036F0C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80041570(rdram, ctx);
        goto after_15;
    // 0x80036F0C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x80036F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036F14: jal         0x800402AC
    // 0x80036F18: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_16;
    // 0x80036F18: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x80036F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80036F24: jal         0x80041984
    // 0x80036F28: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80041984(rdram, ctx);
        goto after_17;
    // 0x80036F28: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x80036F2C: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80036F30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80036F34: jal         0x800424D0
    // 0x80036F38: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_18;
    // 0x80036F38: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x80036F3C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x80036F40: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x80036F44: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x80036F48: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80036F4C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x80036F50: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80036F54: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x80036F58: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x80036F5C: bne         $at, $zero, L_80036EC0
    if (ctx->r1 != 0) {
        // 0x80036F60: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_80036EC0;
    }
    // 0x80036F60: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x80036F64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80036F68:
    // 0x80036F68: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80036F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80036F70: jal         0x800425E0
    // 0x80036F74: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    func_800425E0(rdram, ctx);
        goto after_19;
    // 0x80036F74: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x80036F78: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x80036F7C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80036F80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80036F84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036F8C: jal         0x80036660
    // 0x80036F90: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_20;
    // 0x80036F90: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x80036F94: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x80036F98: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x80036F9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80036FA0: blezl       $t3, L_80036FD0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80036FA4: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_80036FD0;
    }
    goto skip_0;
    // 0x80036FA4: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x80036FA8: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_80036FAC:
    // 0x80036FAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80036FB0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80036FB4: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x80036FB8: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x80036FBC: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80036FC0: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80036FC4: bnel        $at, $zero, L_80036FAC
    if (ctx->r1 != 0) {
        // 0x80036FC8: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_80036FAC;
    }
    goto skip_1;
    // 0x80036FC8: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x80036FCC: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_80036FD0:
    // 0x80036FD0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80036FD4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80036FD8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80036FDC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80036FE0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80036FE4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80036FE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80036FEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80036FF0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80036FF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80036FF8: jr          $ra
    // 0x80036FFC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80036FFC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80009818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009818: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000981C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80009820: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009828: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000982C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009830: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009834: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009838: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    // 0x8000983C: jal         0x8000A7D8
    // 0x80009840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000A7D8(rdram, ctx);
        goto after_0;
    // 0x80009840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80009844: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009848: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x8000984C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009850: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009854: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009858: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8000985C: jal         0x8000A508
    // 0x80009860: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_8000A508(rdram, ctx);
        goto after_1;
    // 0x80009860: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x80009864: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x80009868: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000986C: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x80009870: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80009874: bnel        $t8, $zero, L_80009924
    if (ctx->r24 != 0) {
        // 0x80009878: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009924;
    }
    goto skip_0;
    // 0x80009878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000987C: lhu         $t9, 0xA($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XA);
    // 0x80009880: bnel        $t9, $zero, L_80009914
    if (ctx->r25 != 0) {
        // 0x80009884: sh          $zero, 0x0($s1)
        MEM_H(0X0, ctx->r17) = 0;
            goto L_80009914;
    }
    goto skip_1;
    // 0x80009884: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    skip_1:
    // 0x80009888: jal         0x800202E4
    // 0x8000988C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800202E4(rdram, ctx);
        goto after_2;
    // 0x8000988C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80009890: jal         0x8000B170
    // 0x80009894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000B170(rdram, ctx);
        goto after_3;
    // 0x80009894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80009898: lhu         $t1, 0x60($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X60);
    // 0x8000989C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800098A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800098A4: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x800098A8: addiu       $v0, $v0, -0x3670
    ctx->r2 = ADD32(ctx->r2, -0X3670);
    // 0x800098AC: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x800098B0: sh          $t2, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r10;
    // 0x800098B4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800098B8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800098BC: addiu       $v1, $v1, -0x4598
    ctx->r3 = ADD32(ctx->r3, -0X4598);
    // 0x800098C0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800098C4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800098C8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x800098CC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800098D0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800098D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800098D8: addiu       $a3, $a3, -0x4594
    ctx->r7 = ADD32(ctx->r7, -0X4594);
    // 0x800098DC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800098E0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800098E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800098E8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x800098EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800098F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800098F4: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x800098F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800098FC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80009900: jal         0x800268D4
    // 0x80009904: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    func_800268D4(rdram, ctx);
        goto after_4;
    // 0x80009904: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    after_4:
    // 0x80009908: b           L_80009924
    // 0x8000990C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009924;
    // 0x8000990C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009910: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_80009914:
    // 0x80009914: lhu         $t3, 0x60($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X60);
    // 0x80009918: andi        $t4, $t3, 0xFFFC
    ctx->r12 = ctx->r11 & 0XFFFC;
    // 0x8000991C: sh          $t4, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r12;
    // 0x80009920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009924:
    // 0x80009924: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80009928: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000992C: jr          $ra
    // 0x80009930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80025E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025E10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025E14: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80025E18: addiu       $s0, $s0, -0x6D4
    ctx->r16 = ADD32(ctx->r16, -0X6D4);
    // 0x80025E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80025E20: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80025E24: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025E28: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x80025E2C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80025E30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025E34: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x80025E38: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80025E3C: lw          $t6, 0x3994($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3994);
    // 0x80025E40: ori         $at, $zero, 0xFFFD
    ctx->r1 = 0 | 0XFFFD;
    // 0x80025E44: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80025E48: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80025E4C: bne         $t1, $v1, L_80025E64
    if (ctx->r9 != ctx->r3) {
        // 0x80025E50: nop
    
            goto L_80025E64;
    }
    // 0x80025E50: nop

    // 0x80025E54: jal         0x8002568C
    // 0x80025E58: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8002568C(rdram, ctx);
        goto after_0;
    // 0x80025E58: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80025E5C: b           L_80026204
    // 0x80025E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80026204;
    // 0x80025E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80025E64:
    // 0x80025E64: bne         $v1, $at, L_80025E84
    if (ctx->r3 != ctx->r1) {
        // 0x80025E68: lui         $t2, 0x8009
        ctx->r10 = S32(0X8009 << 16);
            goto L_80025E84;
    }
    // 0x80025E68: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025E6C: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80025E70: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x80025E74: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80025E78: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80025E7C: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80025E80: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80025E84:
    // 0x80025E84: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025E88: ori         $at, $zero, 0xFFFE
    ctx->r1 = 0 | 0XFFFE;
    // 0x80025E8C: bne         $v1, $at, L_80025EA8
    if (ctx->r3 != ctx->r1) {
        // 0x80025E90: addiu       $t2, $t2, -0x6D0
        ctx->r10 = ADD32(ctx->r10, -0X6D0);
            goto L_80025EA8;
    }
    // 0x80025E90: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80025E94: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80025E98: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80025E9C: addiu       $v0, $t8, 0x4
    ctx->r2 = ADD32(ctx->r24, 0X4);
    // 0x80025EA0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80025EA4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80025EA8:
    // 0x80025EA8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025EAC: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x80025EB0: sw          $v1, 0x39A8($at)
    MEM_W(0X39A8, ctx->r1) = ctx->r3;
    // 0x80025EB4: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x80025EB8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80025EBC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80025EC0: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80025EC4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80025EC8: beq         $t1, $t5, L_80025F2C
    if (ctx->r9 == ctx->r13) {
        // 0x80025ECC: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_80025F2C;
    }
    // 0x80025ECC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80025ED0: lw          $t6, -0x974($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X974);
    // 0x80025ED4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80025ED8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025EDC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80025EE0: lh          $a1, 0x0($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X0);
    // 0x80025EE4: jal         0x800398B0
    // 0x80025EE8: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_1;
    // 0x80025EE8: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_1:
    // 0x80025EEC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80025EF0: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025EF4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025EF8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80025EFC: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x80025F00: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80025F04: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80025F08: jal         0x800399B0
    // 0x80025F0C: lw          $a1, -0x28B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X28B0);
    func_800399B0(rdram, ctx);
        goto after_2;
    // 0x80025F0C: lw          $a1, -0x28B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X28B0);
    after_2:
    // 0x80025F10: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025F14: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x80025F18: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025F1C: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80025F20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025F24: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80025F28: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
L_80025F2C:
    // 0x80025F2C: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x80025F30: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80025F34: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80025F38: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80025F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80025F40: beq         $t1, $v1, L_80025FE4
    if (ctx->r9 == ctx->r3) {
        // 0x80025F44: addu        $a2, $a2, $a3
        ctx->r6 = ADD32(ctx->r6, ctx->r7);
            goto L_80025FE4;
    }
    // 0x80025F44: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80025F48: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80025F4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80025F50: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80025F54: lw          $a2, 0x39BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X39BC);
    // 0x80025F58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80025F5C: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x80025F60: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80025F64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80025F68: sw          $v1, -0x6C8($at)
    MEM_W(-0X6C8, ctx->r1) = ctx->r3;
    // 0x80025F6C: beq         $a2, $zero, L_80025F88
    if (ctx->r6 == 0) {
        // 0x80025F70: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_80025F88;
    }
    // 0x80025F70: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80025F74: srl         $t8, $v1, 8
    ctx->r24 = S32(U32(ctx->r3) >> 8);
    // 0x80025F78: multu       $a2, $t8
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025F7C: mflo        $v0
    ctx->r2 = lo;
    // 0x80025F80: nop

    // 0x80025F84: nop

L_80025F88:
    // 0x80025F88: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80025F8C: lw          $t9, -0x974($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X974);
    // 0x80025F90: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025F94: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x80025F98: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80025F9C: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    // 0x80025FA0: jal         0x800398B0
    // 0x80025FA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800398B0(rdram, ctx);
        goto after_3;
    // 0x80025FA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80025FA8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80025FAC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025FB0: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x80025FB4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80025FB8: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80025FBC: jal         0x80039A10
    // 0x80025FC0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    alSndpSetVol(rdram, ctx);
        goto after_4;
    // 0x80025FC0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_4:
    // 0x80025FC4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025FC8: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x80025FCC: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025FD0: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80025FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025FD8: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80025FDC: b           L_8002606C
    // 0x80025FE0: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
        goto L_8002606C;
    // 0x80025FE0: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
L_80025FE4:
    // 0x80025FE4: lw          $a2, 0x39BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X39BC);
    // 0x80025FE8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80025FEC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025FF0: beql        $a2, $zero, L_80026070
    if (ctx->r6 == 0) {
        // 0x80025FF4: addiu       $t4, $v0, 0x4
        ctx->r12 = ADD32(ctx->r2, 0X4);
            goto L_80026070;
    }
    goto skip_0;
    // 0x80025FF4: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x80025FF8: lw          $v1, -0x6C8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6C8);
    // 0x80025FFC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80026000: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80026004: srl         $t5, $v1, 8
    ctx->r13 = S32(U32(ctx->r3) >> 8);
    // 0x80026008: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002600C: lw          $t7, -0x974($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X974);
    // 0x80026010: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80026014: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026018: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002601C: lh          $a1, 0x0($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X0);
    // 0x80026020: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x80026024: mflo        $v0
    ctx->r2 = lo;
    // 0x80026028: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002602C: jal         0x800398B0
    // 0x80026030: nop

    func_800398B0(rdram, ctx);
        goto after_5;
    // 0x80026030: nop

    after_5:
    // 0x80026034: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80026038: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002603C: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x80026040: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80026044: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026048: jal         0x80039A10
    // 0x8002604C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    alSndpSetVol(rdram, ctx);
        goto after_6;
    // 0x8002604C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x80026050: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026054: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x80026058: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002605C: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80026060: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80026064: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80026068: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
L_8002606C:
    // 0x8002606C: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
L_80026070:
    // 0x80026070: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80026074: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80026078: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002607C: addu        $t7, $t7, $a3
    ctx->r15 = ADD32(ctx->r15, ctx->r7);
    // 0x80026080: beq         $t1, $t6, L_800260E0
    if (ctx->r9 == ctx->r14) {
        // 0x80026084: nop
    
            goto L_800260E0;
    }
    // 0x80026084: nop

    // 0x80026088: lw          $t7, 0x39D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X39D0);
    // 0x8002608C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80026090: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80026094: bne         $t7, $at, L_800260E0
    if (ctx->r15 != ctx->r1) {
        // 0x80026098: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800260E0;
    }
    // 0x80026098: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002609C: lw          $t8, -0x974($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X974);
    // 0x800260A0: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800260A4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800260A8: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800260AC: lh          $a1, 0x0($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X0);
    // 0x800260B0: jal         0x800398B0
    // 0x800260B4: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_7;
    // 0x800260B4: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_7:
    // 0x800260B8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800260BC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800260C0: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    // 0x800260C4: jal         0x80039A70
    // 0x800260C8: lbu         $a1, 0x3($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X3);
    func_80039A70(rdram, ctx);
        goto after_8;
    // 0x800260C8: lbu         $a1, 0x3($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X3);
    after_8:
    // 0x800260CC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800260D0: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x800260D4: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800260D8: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x800260DC: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
L_800260E0:
    // 0x800260E0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800260E4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800260E8: lw          $t6, 0x39D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X39D0);
    // 0x800260EC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800260F0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800260F4: beq         $t6, $at, L_8002614C
    if (ctx->r14 == ctx->r1) {
        // 0x800260F8: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8002614C;
    }
    // 0x800260F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800260FC: lw          $t7, -0x974($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X974);
    // 0x80026100: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80026104: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026108: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x8002610C: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    // 0x80026110: jal         0x800398B0
    // 0x80026114: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_9;
    // 0x80026114: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_9:
    // 0x80026118: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002611C: lw          $t4, -0x6CC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6CC);
    // 0x80026120: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80026124: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026128: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002612C: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80026130: lbu         $a1, 0x39D3($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X39D3);
    // 0x80026134: jal         0x80039A70
    // 0x80026138: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_80039A70(rdram, ctx);
        goto after_10;
    // 0x80026138: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_10:
    // 0x8002613C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026140: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80026144: addiu       $t2, $t2, -0x6D0
    ctx->r10 = ADD32(ctx->r10, -0X6D0);
    // 0x80026148: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
L_8002614C:
    // 0x8002614C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80026150: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x80026154: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80026158: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x8002615C: beq         $at, $zero, L_80026200
    if (ctx->r1 == 0) {
        // 0x80026160: sw          $t9, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r25;
            goto L_80026200;
    }
    // 0x80026160: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80026164: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80026168: addu        $at, $at, $t7
    gpr jr_addend_80026170 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8002616C: lw          $t7, 0x1714($at)
    ctx->r15 = ADD32(ctx->r1, 0X1714);
    // 0x80026170: jr          $t7
    // 0x80026174: nop

    switch (jr_addend_80026170 >> 2) {
        case 0: goto L_80026178; break;
        case 1: goto L_80026194; break;
        case 2: goto L_800261B0; break;
        case 3: goto L_800261CC; break;
        case 4: goto L_800261E8; break;
        default: switch_error(__func__, 0x80026170, 0x80071714);
    }
    // 0x80026174: nop

L_80026178:
    // 0x80026178: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8002617C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026180: sw          $t8, -0x6B4($at)
    MEM_W(-0X6B4, ctx->r1) = ctx->r24;
    // 0x80026184: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80026188: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002618C: b           L_80026200
    // 0x80026190: sw          $t3, -0x6A0($at)
    MEM_W(-0X6A0, ctx->r1) = ctx->r11;
        goto L_80026200;
    // 0x80026190: sw          $t3, -0x6A0($at)
    MEM_W(-0X6A0, ctx->r1) = ctx->r11;
L_80026194:
    // 0x80026194: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80026198: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002619C: sw          $t4, -0x6B0($at)
    MEM_W(-0X6B0, ctx->r1) = ctx->r12;
    // 0x800261A0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800261A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261A8: b           L_80026200
    // 0x800261AC: sw          $t5, -0x69C($at)
    MEM_W(-0X69C, ctx->r1) = ctx->r13;
        goto L_80026200;
    // 0x800261AC: sw          $t5, -0x69C($at)
    MEM_W(-0X69C, ctx->r1) = ctx->r13;
L_800261B0:
    // 0x800261B0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800261B4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261B8: sw          $t6, -0x6AC($at)
    MEM_W(-0X6AC, ctx->r1) = ctx->r14;
    // 0x800261BC: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800261C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261C4: b           L_80026200
    // 0x800261C8: sw          $t9, -0x698($at)
    MEM_W(-0X698, ctx->r1) = ctx->r25;
        goto L_80026200;
    // 0x800261C8: sw          $t9, -0x698($at)
    MEM_W(-0X698, ctx->r1) = ctx->r25;
L_800261CC:
    // 0x800261CC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800261D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261D4: sw          $t7, -0x6A8($at)
    MEM_W(-0X6A8, ctx->r1) = ctx->r15;
    // 0x800261D8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800261DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261E0: b           L_80026200
    // 0x800261E4: sw          $t8, -0x694($at)
    MEM_W(-0X694, ctx->r1) = ctx->r24;
        goto L_80026200;
    // 0x800261E4: sw          $t8, -0x694($at)
    MEM_W(-0X694, ctx->r1) = ctx->r24;
L_800261E8:
    // 0x800261E8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800261EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261F0: sw          $t3, -0x6A4($at)
    MEM_W(-0X6A4, ctx->r1) = ctx->r11;
    // 0x800261F4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800261F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800261FC: sw          $t4, -0x690($at)
    MEM_W(-0X690, ctx->r1) = ctx->r12;
L_80026200:
    // 0x80026200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026204:
    // 0x80026204: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002620C: jr          $ra
    // 0x80026210: nop

    return;
    // 0x80026210: nop

;}
RECOMP_FUNC void func_80042614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042614: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004261C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042620: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80042624: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80042628: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004262C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80042630: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80042634: jalr        $t9
    // 0x80042638: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80042638: nop

    after_0:
    // 0x8004263C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80042640: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80042644: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x80042648: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8004264C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80042650: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x80042654: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x80042658: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x8004265C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80042660: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80042664: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80042668: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8004266C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x80042670: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80042674: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x80042678: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8004267C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x80042680: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80042684: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80042688: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8004268C: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x80042690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042698: jr          $ra
    // 0x8004269C: nop

    return;
    // 0x8004269C: nop

;}
RECOMP_FUNC void func_80026214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002621C: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80026220: lw          $v1, 0x3978($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3978);
    // 0x80026224: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80026228: addiu       $t7, $t7, 0x3984
    ctx->r15 = ADD32(ctx->r15, 0X3984);
    // 0x8002622C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80026230: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80026234: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80026238: lw          $t9, 0x398C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X398C);
    // 0x8002623C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80026240: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80026244: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80026248: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8002624C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80026250: bltz        $t0, L_80026270
    if (SIGNED(ctx->r8) < 0) {
        // 0x80026254: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_80026270;
    }
    // 0x80026254: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80026258: lw          $t1, 0x3974($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3974);
    // 0x8002625C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80026260: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80026264: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80026268: beq         $at, $zero, L_800262B4
    if (ctx->r1 == 0) {
        // 0x8002626C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800262B4;
    }
    // 0x8002626C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
L_80026270:
    // 0x80026270: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80026274: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80026278: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002627C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80026280: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80026284: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80026288: lw          $t2, 0x3974($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3974);
    // 0x8002628C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80026290: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80026294: addiu       $t5, $t5, -0x688
    ctx->r13 = ADD32(ctx->r13, -0X688);
    // 0x80026298: addiu       $t4, $t3, 0x1C
    ctx->r12 = ADD32(ctx->r11, 0X1C);
    // 0x8002629C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x800262A0: jal         0x800390C0
    // 0x800262A4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    func_800390C0(rdram, ctx);
        goto after_0;
    // 0x800262A4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x800262A8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800262AC: b           L_800262E4
    // 0x800262B0: sw          $zero, 0x398C($at)
    MEM_W(0X398C, ctx->r1) = 0;
        goto L_800262E4;
    // 0x800262B0: sw          $zero, 0x398C($at)
    MEM_W(0X398C, ctx->r1) = 0;
L_800262B4:
    // 0x800262B4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800262B8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800262BC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800262C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800262C4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800262C8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800262CC: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800262D0: addiu       $t8, $t8, -0x688
    ctx->r24 = ADD32(ctx->r24, -0X688);
    // 0x800262D4: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x800262D8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800262DC: jal         0x800368E0
    // 0x800262E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800368E0(rdram, ctx);
        goto after_1;
    // 0x800262E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
L_800262E4:
    // 0x800262E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800262E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800262EC: jr          $ra
    // 0x800262F0: nop

    return;
    // 0x800262F0: nop

;}
RECOMP_FUNC void func_80021240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021240: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80021244: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80021248: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002124C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021250: addiu       $t7, $v0, 0x95
    ctx->r15 = ADD32(ctx->r2, 0X95);
    // 0x80021254: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80021258: addiu       $t8, $t8, -0x3088
    ctx->r24 = ADD32(ctx->r24, -0X3088);
    // 0x8002125C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80021260: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80021264: addiu       $v0, $v0, -0x3089
    ctx->r2 = ADD32(ctx->r2, -0X3089);
    // 0x80021268: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8002126C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80021270: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
L_80021274:
    // 0x80021274: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80021278: bne         $a1, $t9, L_80021284
    if (ctx->r5 != ctx->r25) {
        // 0x8002127C: nop
    
            goto L_80021284;
    }
    // 0x8002127C: nop

    // 0x80021280: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80021284:
    // 0x80021284: beql        $a2, $v0, L_80021298
    if (ctx->r6 == ctx->r2) {
        // 0x80021288: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80021298;
    }
    goto skip_0;
    // 0x80021288: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8002128C: beql        $v1, $zero, L_80021274
    if (ctx->r3 == 0) {
        // 0x80021290: lbu         $t9, 0x0($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X0);
            goto L_80021274;
    }
    goto skip_1;
    // 0x80021290: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    skip_1:
    // 0x80021294: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80021298:
    // 0x80021298: jr          $ra
    // 0x8002129C: nop

    return;
    // 0x8002129C: nop

;}
RECOMP_FUNC void func_800069FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800069FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006A00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80006A08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80006A0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80006A10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80006A14: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80006A18: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80006A1C: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80006A20: sh          $t8, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r24;
    // 0x80006A24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80006A28: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80006A2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80006A30: lhu         $t0, 0x60($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X60);
    // 0x80006A34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80006A38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80006A3C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80006A40: sh          $t1, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r9;
    // 0x80006A44: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80006A48: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80006A4C: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80006A50: jal         0x8001D8B0
    // 0x80006A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80006A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80006A58: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x80006A5C: jal         0x800140EC
    // 0x80006A60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800140EC(rdram, ctx);
        goto after_1;
    // 0x80006A60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80006A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006A6C: jr          $ra
    // 0x80006A70: nop

    return;
    // 0x80006A70: nop

;}
RECOMP_FUNC void func_80012700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80012704: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80012708: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001270C: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x80012710: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80012714: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80012718: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001271C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80012720: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80012724: lbu         $t8, -0x28C0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X28C0);
    // 0x80012728: lbu         $t0, 0x6AE8($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X6AE8);
    // 0x8001272C: and         $v0, $t8, $t0
    ctx->r2 = ctx->r24 & ctx->r8;
    // 0x80012730: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x80012734: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80012738: jr          $ra
    // 0x8001273C: nop

    return;
    // 0x8001273C: nop

;}
RECOMP_FUNC void func_801008A8_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801008A8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x801008AC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x801008B0: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x801008B4: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x801008B8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x801008BC: addiu       $t3, $t3, 0x6FE8
    ctx->r11 = ADD32(ctx->r11, 0X6FE8);
    // 0x801008C0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x801008C4: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x801008C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801008CC: lh          $t4, 0x12($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X12);
    // 0x801008D0: lh          $t5, 0x16($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X16);
    // 0x801008D4: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x801008D8: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x801008DC: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    // 0x801008E0: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x801008E4: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x801008E8: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x801008EC: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x801008F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801008F4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801008F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x801008FC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80100900: lh          $t5, 0x30($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X30);
    // 0x80100904: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80100908: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8010090C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80100910: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80100914: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80100918: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x8010091C: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    // 0x80100920: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x80100924: sh          $t2, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r10;
    // 0x80100928: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x8010092C: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80100930: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80100934: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80100938: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8010093C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80100940: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80100944: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80100948: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8010094C: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x80100950: sh          $t8, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r24;
    // 0x80100954: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x80100958: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x8010095C: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
    // 0x80100960: sw          $t3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r11;
    // 0x80100964: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
    // 0x80100968: jr          $ra
    // 0x8010096C: sh          $t5, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r13;
    return;
    // 0x8010096C: sh          $t5, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80010E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010E70: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010E74: addiu       $v1, $v1, 0x5390
    ctx->r3 = ADD32(ctx->r3, 0X5390);
    // 0x80010E78: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80010E7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010E80: sw          $a0, 0x538C($at)
    MEM_W(0X538C, ctx->r1) = ctx->r4;
    // 0x80010E84: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010E88: sw          $a1, 0x5394($at)
    MEM_W(0X5394, ctx->r1) = ctx->r5;
    // 0x80010E8C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010E90: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010E94: sw          $a2, 0x5398($at)
    MEM_W(0X5398, ctx->r1) = ctx->r6;
    // 0x80010E98: addiu       $v0, $v0, 0x53A0
    ctx->r2 = ADD32(ctx->r2, 0X53A0);
    // 0x80010E9C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80010EA0:
    // 0x80010EA0: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x80010EA4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80010EA8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80010EAC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80010EB0: sh          $t7, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r15;
    // 0x80010EB4: bne         $a3, $zero, L_80010EA0
    if (ctx->r7 != 0) {
        // 0x80010EB8: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80010EA0;
    }
    // 0x80010EB8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80010EBC: jr          $ra
    // 0x80010EC0: nop

    return;
    // 0x80010EC0: nop

;}
RECOMP_FUNC void func_80013A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80013A18: jr          $ra
    // 0x80013A1C: nop

    return;
    // 0x80013A1C: nop

;}
RECOMP_FUNC void func_80044060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004406C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80044070: beql        $t6, $zero, L_800440CC
    if (ctx->r14 == 0) {
        // 0x80044074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800440CC;
    }
    goto skip_0;
    // 0x80044074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80044078: jal         0x80036A30
    // 0x8004407C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x8004407C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044080: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044084: beq         $v0, $zero, L_800440C8
    if (ctx->r2 == 0) {
        // 0x80044088: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800440C8;
    }
    // 0x80044088: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004408C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044090: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80044094: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80044098: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8004409C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800440A0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800440A4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800440A8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800440AC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800440B0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800440B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800440B8: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800440BC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800440C0: jalr        $t9
    // 0x800440C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800440C4: nop

    after_1:
L_800440C8:
    // 0x800440C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800440CC:
    // 0x800440CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800440D0: jr          $ra
    // 0x800440D4: nop

    return;
    // 0x800440D4: nop

    // 0x800440D8: nop

    // 0x800440DC: nop

;}
RECOMP_FUNC void func_8010008C_E278CC_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010008C: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80100090: lw          $a3, 0x35A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X35A8);
    // 0x80100094: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80100098: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8010009C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x801000A0: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    // 0x801000A4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801000A8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801000AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801000B0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x801000B4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x801000B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801000BC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801000C0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x801000C4: addiu       $t9, $t9, -0x6138
    ctx->r25 = ADD32(ctx->r25, -0X6138);
    // 0x801000C8: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x801000CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801000D0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801000D4: sw          $t7, 0x3B08($at)
    MEM_W(0X3B08, ctx->r1) = ctx->r15;
    // 0x801000D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801000DC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801000E0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801000E8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801000EC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x801000F0: addiu       $t3, $t3, 0x35D0
    ctx->r11 = ADD32(ctx->r11, 0X35D0);
    // 0x801000F4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801000F8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801000FC: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80100100: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100104: jal         0x80100184
    // 0x80100108: sw          $t6, 0x35A8($at)
    MEM_W(0X35A8, ctx->r1) = ctx->r14;
    func_80100184_ovl_ending(rdram, ctx);
        goto after_0;
    // 0x80100108: sw          $t6, 0x35A8($at)
    MEM_W(0X35A8, ctx->r1) = ctx->r14;
    after_0:
    // 0x8010010C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80100110: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80100114: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80100118: lw          $a3, 0x35A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X35A8);
    // 0x8010011C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80100120: lui         $t4, 0xB800
    ctx->r12 = S32(0XB800 << 16);
    // 0x80100124: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80100128: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8010012C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80100130: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80100134: lw          $t5, 0x3B08($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3B08);
    // 0x80100138: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x8010013C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80100140: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x80100144: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80100148: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8010014C: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x80100150: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80100154: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80100158: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010015C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80100160: addiu       $t9, $t9, -0x6138
    ctx->r25 = ADD32(ctx->r25, -0X6138);
    // 0x80100164: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80100168: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8010016C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80100170: sw          $t0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r8;
    // 0x80100174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010017C: jr          $ra
    // 0x80100180: nop

    return;
    // 0x80100180: nop

;}
RECOMP_FUNC void func_80041ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041ECC: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x80041ED0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80041ED4: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x80041ED8: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80041EDC: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80041EE0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80041EE4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041EE8: bne         $t9, $zero, L_80041EF8
    if (ctx->r25 != 0) {
        // 0x80041EEC: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_80041EF8;
    }
    // 0x80041EEC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80041EF0: jr          $ra
    // 0x80041EF4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80041EF4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80041EF8:
    // 0x80041EF8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80041EFC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80041F00: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80041F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041F08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041F0C: bgez        $a2, L_80041F24
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80041F10: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80041F24;
    }
    // 0x80041F10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041F14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041F18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041F1C: nop

    // 0x80041F20: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80041F24:
    // 0x80041F24: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80041F28: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80041F2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80041F30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041F34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80041F38: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80041F3C: div.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80041F40: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
L_80041F44:
    // 0x80041F44: beq         $t7, $zero, L_80041F54
    if (ctx->r15 == 0) {
        // 0x80041F48: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80041F54;
    }
    // 0x80041F48: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80041F4C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80041F50: nop

L_80041F54:
    // 0x80041F54: beq         $t8, $zero, L_80041F6C
    if (ctx->r24 == 0) {
        // 0x80041F58: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_80041F6C;
    }
    // 0x80041F58: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80041F5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80041F60: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041F64: bnel        $v0, $v1, L_80041F44
    if (ctx->r2 != ctx->r3) {
        // 0x80041F68: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_80041F44;
    }
    goto skip_0;
    // 0x80041F68: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_0:
L_80041F6C:
    // 0x80041F6C: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80041F70: nop

    // 0x80041F74: jr          $ra
    // 0x80041F78: nop

    return;
    // 0x80041F78: nop

;}
RECOMP_FUNC void func_8002D5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D5D4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D5D8: addiu       $v0, $v0, -0x2D7
    ctx->r2 = ADD32(ctx->r2, -0X2D7);
    // 0x8002D5DC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8002D5E0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8002D5E4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8002D5E8: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8002D5EC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D5F0: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D5F4: bgez        $t8, L_8002D60C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002D5F8: nop
    
            goto L_8002D60C;
    }
    // 0x8002D5F8: nop

    // 0x8002D5FC: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D600: andi        $t1, $t9, 0xFFF8
    ctx->r9 = ctx->r25 & 0XFFF8;
    // 0x8002D604: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x8002D608: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_8002D60C:
    // 0x8002D60C: jr          $ra
    // 0x8002D610: nop

    return;
    // 0x8002D610: nop

;}
RECOMP_FUNC void func_80042A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042A38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042A40: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x80042A44: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80042A48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80042A4C: beq         $a3, $zero, L_80042ACC
    if (ctx->r7 == 0) {
        // 0x80042A50: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80042ACC;
    }
    // 0x80042A50: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80042A54: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_80042A58:
    // 0x80042A58: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    // 0x80042A5C: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x80042A60: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80042A64: bne         $a0, $t6, L_80042AC4
    if (ctx->r4 != ctx->r14) {
        // 0x80042A68: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_80042AC4;
    }
    // 0x80042A68: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80042A6C: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x80042A70: bne         $a1, $t7, L_80042AC4
    if (ctx->r5 != ctx->r15) {
        // 0x80042A74: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80042AC4;
    }
    // 0x80042A74: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80042A78: beq         $at, $zero, L_80042ABC
    if (ctx->r1 == 0) {
        // 0x80042A7C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80042ABC;
    }
    // 0x80042A7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80042A80: beql        $v0, $zero, L_80042A98
    if (ctx->r2 == 0) {
        // 0x80042A84: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80042A98;
    }
    goto skip_0;
    // 0x80042A84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x80042A88: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80042A8C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80042A90: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80042A94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_80042A98:
    // 0x80042A98: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x80042A9C: jal         0x80036820
    // 0x80042AA0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x80042AA0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x80042AA4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80042AA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80042AAC: jal         0x80036850
    // 0x80042AB0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x80042AB0: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    after_1:
    // 0x80042AB4: b           L_80042ACC
    // 0x80042AB8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_80042ACC;
    // 0x80042AB8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_80042ABC:
    // 0x80042ABC: b           L_80042ACC
    // 0x80042AC0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80042ACC;
    // 0x80042AC0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80042AC4:
    // 0x80042AC4: bne         $v0, $zero, L_80042A58
    if (ctx->r2 != 0) {
        // 0x80042AC8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80042A58;
    }
    // 0x80042AC8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80042ACC:
    // 0x80042ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042AD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80042AD4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80042AD8: jr          $ra
    // 0x80042ADC: nop

    return;
    // 0x80042ADC: nop

;}
