#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80012170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012170: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80012174: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80012178: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001217C: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x80012180: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80012184: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80012188: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001218C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80012190: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80012194: lbu         $t8, -0x28C0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X28C0);
    // 0x80012198: lbu         $t0, 0x69D8($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X69D8);
    // 0x8001219C: and         $v0, $t8, $t0
    ctx->r2 = ctx->r24 & ctx->r8;
    // 0x800121A0: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x800121A4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800121A8: jr          $ra
    // 0x800121AC: nop

    return;
    // 0x800121AC: nop

;}
RECOMP_FUNC void func_80100D80_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100D80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80100D84: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80100D88: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80100D8C: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80100D90: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80100D94: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80100D98: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80100D9C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80100DA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80100DA4: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x80100DA8: bltz        $t9, L_80100DB8
    if (SIGNED(ctx->r25) < 0) {
        // 0x80100DAC: andi        $a2, $a3, 0x100
        ctx->r6 = ctx->r7 & 0X100;
            goto L_80100DB8;
    }
    // 0x80100DAC: andi        $a2, $a3, 0x100
    ctx->r6 = ctx->r7 & 0X100;
    // 0x80100DB0: jr          $ra
    // 0x80100DB4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80100DB4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80100DB8:
    // 0x80100DB8: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    // 0x80100DBC: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x80100DC0: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x80100DC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80100DC8: beq         $a2, $zero, L_80100E34
    if (ctx->r6 == 0) {
        // 0x80100DCC: sh          $t1, 0x4C($v1)
        MEM_H(0X4C, ctx->r3) = ctx->r9;
            goto L_80100E34;
    }
    // 0x80100DCC: sh          $t1, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r9;
    // 0x80100DD0: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80100DD4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80100DD8: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80100DDC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80100DE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80100DE4: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x80100DE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80100DEC: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80100DF0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80100DF4: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x80100DF8: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80100DFC: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80100E00: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80100E04: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80100E08: nop

    // 0x80100E0C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80100E10: beq         $at, $zero, L_80100E20
    if (ctx->r1 == 0) {
        // 0x80100E14: slt         $at, $t3, $a3
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80100E20;
    }
    // 0x80100E14: slt         $at, $t3, $a3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80100E18: bnel        $at, $zero, L_80100E28
    if (ctx->r1 != 0) {
        // 0x80100E1C: lh          $t4, 0x2E($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2E);
            goto L_80100E28;
    }
    goto skip_0;
    // 0x80100E1C: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
    skip_0:
L_80100E20:
    // 0x80100E20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80100E24: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
L_80100E28:
    // 0x80100E28: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x80100E2C: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80100E30: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_80100E34:
    // 0x80100E34: bnel        $a2, $zero, L_80100EA8
    if (ctx->r6 != 0) {
        // 0x80100E38: lhu         $t2, 0x4C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X4C);
            goto L_80100EA8;
    }
    goto skip_1;
    // 0x80100E38: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
    skip_1:
    // 0x80100E3C: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80100E40: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x80100E44: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80100E48: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80100E4C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80100E50: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80100E54: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80100E58: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80100E5C: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80100E60: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80100E64: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80100E68: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80100E6C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80100E70: nop

    // 0x80100E74: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80100E78: beql        $at, $zero, L_80100E94
    if (ctx->r1 == 0) {
        // 0x80100E7C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80100E94;
    }
    goto skip_2;
    // 0x80100E7C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_2:
    // 0x80100E80: lhu         $t8, 0x4C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4C);
    // 0x80100E84: slt         $at, $t8, $a3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80100E88: bnel        $at, $zero, L_80100E98
    if (ctx->r1 != 0) {
        // 0x80100E8C: lh          $t9, 0x30($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X30);
            goto L_80100E98;
    }
    goto skip_3;
    // 0x80100E8C: lh          $t9, 0x30($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X30);
    skip_3:
    // 0x80100E90: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80100E94:
    // 0x80100E94: lh          $t9, 0x30($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X30);
L_80100E98:
    // 0x80100E98: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    // 0x80100E9C: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x80100EA0: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80100EA4: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
L_80100EA8:
    // 0x80100EA8: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80100EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100EB0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80100EB4: bne         $at, $zero, L_80100EDC
    if (ctx->r1 != 0) {
        // 0x80100EB8: nop
    
            goto L_80100EDC;
    }
    // 0x80100EB8: nop

    // 0x80100EBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80100EC0: sh          $zero, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = 0;
    // 0x80100EC4: sh          $zero, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = 0;
    // 0x80100EC8: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x80100ECC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80100ED0: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80100ED4: jr          $ra
    // 0x80100ED8: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80100ED8: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
L_80100EDC:
    // 0x80100EDC: jr          $ra
    // 0x80100EE0: nop

    return;
    // 0x80100EE0: nop

;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D430: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8003D434: bne         $at, $zero, L_8003D4AC
    if (ctx->r1 != 0) {
        // 0x8003D438: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8003D4AC;
    }
    // 0x8003D438: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8003D43C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8003D440: beq         $v1, $zero, L_8003D450
    if (ctx->r3 == 0) {
        // 0x8003D444: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8003D450;
    }
    // 0x8003D444: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8003D448: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8003D44C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8003D450:
    // 0x8003D450: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8003D454: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8003D458: beq         $a3, $zero, L_8003D48C
    if (ctx->r7 == 0) {
        // 0x8003D45C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8003D48C;
    }
    // 0x8003D45C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8003D460: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8003D464:
    // 0x8003D464: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8003D468: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8003D46C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x8003D470: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x8003D474: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x8003D478: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8003D47C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8003D480: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8003D484: bne         $a0, $a3, L_8003D464
    if (ctx->r4 != ctx->r7) {
        // 0x8003D488: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8003D464;
    }
    // 0x8003D488: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8003D48C:
    // 0x8003D48C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003D490: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8003D494: beq         $a3, $zero, L_8003D4AC
    if (ctx->r7 == 0) {
        // 0x8003D498: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8003D4AC;
    }
    // 0x8003D498: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8003D49C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8003D4A0:
    // 0x8003D4A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003D4A4: bne         $a0, $a3, L_8003D4A0
    if (ctx->r4 != ctx->r7) {
        // 0x8003D4A8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8003D4A0;
    }
    // 0x8003D4A8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8003D4AC:
    // 0x8003D4AC: blez        $a1, L_8003D4C4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8003D4B0: nop
    
            goto L_8003D4C4;
    }
    // 0x8003D4B0: nop

    // 0x8003D4B4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8003D4B8:
    // 0x8003D4B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003D4BC: bne         $a0, $a1, L_8003D4B8
    if (ctx->r4 != ctx->r5) {
        // 0x8003D4C0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8003D4B8;
    }
    // 0x8003D4C0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8003D4C4:
    // 0x8003D4C4: jr          $ra
    // 0x8003D4C8: nop

    return;
    // 0x8003D4C8: nop

    // 0x8003D4CC: nop

;}
RECOMP_FUNC void func_8002E234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E234: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002E238: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002E23C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002E240: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8002E244: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002E248: addiu       $t7, $t7, -0x2A8
    ctx->r15 = ADD32(ctx->r15, -0X2A8);
    // 0x8002E24C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002E250: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8002E254: addiu       $t8, $t8, -0x4580
    ctx->r24 = ADD32(ctx->r24, -0X4580);
    // 0x8002E258: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8002E25C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8002E260: addiu       $t1, $t8, 0x30
    ctx->r9 = ADD32(ctx->r24, 0X30);
L_8002E264:
    // 0x8002E264: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8002E268: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8002E26C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8002E270: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x8002E274: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x8002E278: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x8002E27C: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x8002E280: bne         $t8, $t1, L_8002E264
    if (ctx->r24 != ctx->r9) {
        // 0x8002E284: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_8002E264;
    }
    // 0x8002E284: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x8002E288: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8002E28C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002E290: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8002E294: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8002E298: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x8002E29C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002E2A0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8002E2A4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8002E2A8: lhu         $t3, 0x59E2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X59E2);
    // 0x8002E2AC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8002E2B0: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8002E2B4: sh          $t3, 0x38($a2)
    MEM_H(0X38, ctx->r6) = ctx->r11;
    // 0x8002E2B8: lhu         $t4, 0x59E0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X59E0);
    // 0x8002E2BC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8002E2C0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002E2C4: sh          $t4, 0x3A($a2)
    MEM_H(0X3A, ctx->r6) = ctx->r12;
    // 0x8002E2C8: lw          $t5, 0x4EE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4EE4);
    // 0x8002E2CC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8002E2D0: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002E2D4: sw          $t5, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r13;
    // 0x8002E2D8: lw          $t6, 0x4EE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4EE8);
    // 0x8002E2DC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002E2E0: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8002E2E4: sw          $t6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r14;
    // 0x8002E2E8: lw          $t7, 0x4EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4EF8);
    // 0x8002E2EC: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002E2F0: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002E2F4: sw          $t7, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r15;
    // 0x8002E2F8: lw          $t0, 0x4EFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4EFC);
    // 0x8002E2FC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002E300: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E304: sw          $t0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r8;
    // 0x8002E308: lw          $t9, 0x4F00($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4F00);
    // 0x8002E30C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E310: addiu       $v0, $v0, 0x398
    ctx->r2 = ADD32(ctx->r2, 0X398);
    // 0x8002E314: sw          $t9, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r25;
    // 0x8002E318: lw          $t1, 0x4F04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4F04);
    // 0x8002E31C: addiu       $v1, $v1, 0x69D8
    ctx->r3 = ADD32(ctx->r3, 0X69D8);
    // 0x8002E320: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8002E324: sw          $t1, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r9;
    // 0x8002E328: lw          $t8, 0x4F08($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F08);
    // 0x8002E32C: sw          $t8, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r24;
    // 0x8002E330: lw          $t2, 0x4F0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4F0C);
    // 0x8002E334: sw          $t2, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r10;
    // 0x8002E338: lhu         $t3, -0x45A0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X45A0);
    // 0x8002E33C: sh          $t3, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r11;
    // 0x8002E340: lhu         $t4, -0x459E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X459E);
    // 0x8002E344: sh          $t4, 0x5E($a2)
    MEM_H(0X5E, ctx->r6) = ctx->r12;
    // 0x8002E348: lhu         $t5, -0x459C($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X459C);
    // 0x8002E34C: sh          $t5, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r13;
    // 0x8002E350: lb          $t6, -0x600($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X600);
    // 0x8002E354: sb          $t6, 0x62($a2)
    MEM_B(0X62, ctx->r6) = ctx->r14;
    // 0x8002E358: lb          $t7, -0xFF0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0XFF0);
    // 0x8002E35C: sb          $t7, 0x63($a2)
    MEM_B(0X63, ctx->r6) = ctx->r15;
L_8002E360:
    // 0x8002E360: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E364: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E368: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E36C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E370: bne         $a1, $zero, L_8002E360
    if (ctx->r5 != 0) {
        // 0x8002E374: sb          $t0, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r8;
            goto L_8002E360;
    }
    // 0x8002E374: sb          $t0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r8;
    // 0x8002E378: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E37C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E380: addiu       $v0, $v0, 0x3B8
    ctx->r2 = ADD32(ctx->r2, 0X3B8);
    // 0x8002E384: addiu       $v1, $v1, 0x6AE8
    ctx->r3 = ADD32(ctx->r3, 0X6AE8);
    // 0x8002E388: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_8002E38C:
    // 0x8002E38C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E390: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E394: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E398: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E39C: bne         $a1, $zero, L_8002E38C
    if (ctx->r5 != 0) {
        // 0x8002E3A0: sb          $t9, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r25;
            goto L_8002E38C;
    }
    // 0x8002E3A0: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
    // 0x8002E3A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E3A8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002E3AC: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, 0X3C8);
    // 0x8002E3B0: addiu       $v1, $v1, -0x3088
    ctx->r3 = ADD32(ctx->r3, -0X3088);
    // 0x8002E3B4: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
L_8002E3B8:
    // 0x8002E3B8: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E3BC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E3C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E3C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E3C8: bne         $a1, $zero, L_8002E3B8
    if (ctx->r5 != 0) {
        // 0x8002E3CC: sb          $t1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r9;
            goto L_8002E3B8;
    }
    // 0x8002E3CC: sb          $t1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r9;
    // 0x8002E3D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E3D4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E3D8: addiu       $v0, $v0, 0x45F
    ctx->r2 = ADD32(ctx->r2, 0X45F);
    // 0x8002E3DC: addiu       $v1, $v1, -0x2E64
    ctx->r3 = ADD32(ctx->r3, -0X2E64);
    // 0x8002E3E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002E3E4:
    // 0x8002E3E4: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E3E8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E3EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E3F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E3F4: bne         $a1, $zero, L_8002E3E4
    if (ctx->r5 != 0) {
        // 0x8002E3F8: sb          $t8, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r24;
            goto L_8002E3E4;
    }
    // 0x8002E3F8: sb          $t8, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r24;
    // 0x8002E3FC: jr          $ra
    // 0x8002E400: nop

    return;
    // 0x8002E400: nop

;}
RECOMP_FUNC void func_80014890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014890: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014894: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80014898: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001489C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800148A0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800148A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800148A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800148AC: beq         $a0, $zero, L_80014924
    if (ctx->r4 == 0) {
        // 0x800148B0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80014924;
    }
    // 0x800148B0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800148B4: andi        $t2, $a0, 0x3
    ctx->r10 = ctx->r4 & 0X3;
    // 0x800148B8: beq         $t2, $zero, L_800148E8
    if (ctx->r10 == 0) {
        // 0x800148BC: or          $t1, $t2, $zero
        ctx->r9 = ctx->r10 | 0;
            goto L_800148E8;
    }
    // 0x800148BC: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x800148C0: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x800148C4: addu        $a0, $zero, $t7
    ctx->r4 = ADD32(0, ctx->r15);
    // 0x800148C8: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
L_800148CC:
    // 0x800148CC: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x800148D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800148D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800148D8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800148DC: bne         $t1, $a2, L_800148CC
    if (ctx->r9 != ctx->r6) {
        // 0x800148E0: sb          $t8, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r24;
            goto L_800148CC;
    }
    // 0x800148E0: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
    // 0x800148E4: beq         $a2, $a3, L_80014924
    if (ctx->r6 == ctx->r7) {
        // 0x800148E8: addiu       $t9, $sp, 0x1C
        ctx->r25 = ADD32(ctx->r29, 0X1C);
            goto L_80014924;
    }
L_800148E8:
    // 0x800148E8: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x800148EC: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x800148F0: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x800148F4: addu        $t0, $a1, $a2
    ctx->r8 = ADD32(ctx->r5, ctx->r6);
L_800148F8:
    // 0x800148F8: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800148FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80014900: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80014904: sb          $t3, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r11;
    // 0x80014908: lbu         $t4, -0x3($t0)
    ctx->r12 = MEM_BU(ctx->r8, -0X3);
    // 0x8001490C: sb          $t4, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r12;
    // 0x80014910: lbu         $t5, -0x2($t0)
    ctx->r13 = MEM_BU(ctx->r8, -0X2);
    // 0x80014914: sb          $t5, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r13;
    // 0x80014918: lbu         $t6, -0x1($t0)
    ctx->r14 = MEM_BU(ctx->r8, -0X1);
    // 0x8001491C: bne         $a0, $t1, L_800148F8
    if (ctx->r4 != ctx->r9) {
        // 0x80014920: sb          $t6, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r14;
            goto L_800148F8;
    }
    // 0x80014920: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
L_80014924:
    // 0x80014924: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80014928: bne         $at, $zero, L_8001494C
    if (ctx->r1 != 0) {
        // 0x8001492C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8001494C;
    }
    // 0x8001492C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80014930: lbu         $a0, 0x1E($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1E);
    // 0x80014934: lbu         $a1, 0x1D($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1D);
    // 0x80014938: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001493C: beq         $at, $zero, L_8001494C
    if (ctx->r1 == 0) {
        // 0x80014940: nop
    
            goto L_8001494C;
    }
    // 0x80014940: nop

    // 0x80014944: sb          $a1, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r5;
    // 0x80014948: sb          $a0, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r4;
L_8001494C:
    // 0x8001494C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80014950: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80014954: lw          $a0, 0x1B14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1B14);
    // 0x80014958: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_8001495C:
    // 0x8001495C: lhu         $a1, 0x4($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X4);
    // 0x80014960: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80014964: bnel        $a1, $v0, L_800149AC
    if (ctx->r5 != ctx->r2) {
        // 0x80014968: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800149AC;
    }
    goto skip_0;
    // 0x80014968: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_0:
    // 0x8001496C: beq         $a1, $zero, L_800149A0
    if (ctx->r5 == 0) {
        // 0x80014970: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_800149A0;
    }
    // 0x80014970: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80014974: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80014978: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
L_8001497C:
    // 0x8001497C: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80014980: lbu         $t9, 0x6($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X6);
    // 0x80014984: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014988: bne         $t8, $t9, L_800149A0
    if (ctx->r24 != ctx->r25) {
        // 0x8001498C: nop
    
            goto L_800149A0;
    }
    // 0x8001498C: nop

    // 0x80014990: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80014994: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x80014998: bne         $at, $zero, L_8001497C
    if (ctx->r1 != 0) {
        // 0x8001499C: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001497C;
    }
    // 0x8001499C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800149A0:
    // 0x800149A0: beq         $a3, $t0, L_800149B4
    if (ctx->r7 == ctx->r8) {
        // 0x800149A4: nop
    
            goto L_800149B4;
    }
    // 0x800149A4: nop

    // 0x800149A8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800149AC:
    // 0x800149AC: bne         $a2, $zero, L_8001495C
    if (ctx->r6 != 0) {
        // 0x800149B0: addiu       $a0, $a0, 0x44
        ctx->r4 = ADD32(ctx->r4, 0X44);
            goto L_8001495C;
    }
    // 0x800149B0: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_800149B4:
    // 0x800149B4: bne         $a2, $zero, L_800149C0
    if (ctx->r6 != 0) {
        // 0x800149B8: sll         $t3, $v1, 8
        ctx->r11 = S32(ctx->r3 << 8);
            goto L_800149C0;
    }
    // 0x800149B8: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x800149BC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_800149C0:
    // 0x800149C0: subu        $v0, $t3, $a2
    ctx->r2 = SUB32(ctx->r11, ctx->r6);
    // 0x800149C4: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800149C8: jr          $ra
    // 0x800149CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800149CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800111A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800111A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800111AC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800111B0: addiu       $t7, $t7, 0x59E8
    ctx->r15 = ADD32(ctx->r15, 0X59E8);
    // 0x800111B4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800111B8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800111BC: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x800111C0: sw          $a2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r6;
    // 0x800111C4: sw          $a2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r6;
    // 0x800111C8: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
    // 0x800111CC: sw          $a3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r7;
    // 0x800111D0: jr          $ra
    // 0x800111D4: nop

    return;
    // 0x800111D4: nop

;}
RECOMP_FUNC void func_80012780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012780: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80012788: lui         $at, 0xC2EE
    ctx->r1 = S32(0XC2EE << 16);
    // 0x8001278C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012790: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80012794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012798: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8001279C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800127A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800127A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800127A8: lui         $a0, 0x8030
    ctx->r4 = S32(0X8030 << 16);
    // 0x800127AC: addiu       $a0, $a0, 0x1098
    ctx->r4 = ADD32(ctx->r4, 0X1098);
    // 0x800127B0: lui         $a1, 0xC31F
    ctx->r5 = S32(0XC31F << 16);
    // 0x800127B4: lui         $a2, 0x431F
    ctx->r6 = S32(0X431F << 16);
    // 0x800127B8: lui         $a3, 0x42EE
    ctx->r7 = S32(0X42EE << 16);
    // 0x800127BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800127C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800127C4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800127C8: jal         0x80035994
    // 0x800127CC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrtho(rdram, ctx);
        goto after_0;
    // 0x800127CC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800127D0: lui         $at, 0xC2EE
    ctx->r1 = S32(0XC2EE << 16);
    // 0x800127D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800127D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800127DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800127E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800127E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800127E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800127EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800127F0: lui         $a0, 0x8031
    ctx->r4 = S32(0X8031 << 16);
    // 0x800127F4: addiu       $a0, $a0, -0x1E18
    ctx->r4 = ADD32(ctx->r4, -0X1E18);
    // 0x800127F8: lui         $a1, 0xC31F
    ctx->r5 = S32(0XC31F << 16);
    // 0x800127FC: lui         $a2, 0x431F
    ctx->r6 = S32(0X431F << 16);
    // 0x80012800: lui         $a3, 0x42EE
    ctx->r7 = S32(0X42EE << 16);
    // 0x80012804: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80012808: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8001280C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80012810: jal         0x80035994
    // 0x80012814: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    guOrtho(rdram, ctx);
        goto after_1;
    // 0x80012814: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80012818: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001281C: lw          $t6, 0x5370($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5370);
    // 0x80012820: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80012824: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012828: bgez        $t6, L_8001283C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001282C: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_8001283C;
    }
    // 0x8001282C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80012830: lwc1        $f8, 0x1310($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1310);
    // 0x80012834: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012838: swc1        $f8, 0x6E44($at)
    MEM_W(0X6E44, ctx->r1) = ctx->f8.u32l;
L_8001283C:
    // 0x8001283C: lhu         $t7, -0x44D2($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X44D2);
    // 0x80012840: addiu       $a1, $a1, 0x6ED8
    ctx->r5 = ADD32(ctx->r5, 0X6ED8);
    // 0x80012844: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012848: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8001284C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80012850: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80012854: lw          $v1, 0x4F18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4F18);
    // 0x80012858: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001285C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80012860: lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X24);
    // 0x80012864: addiu       $a2, $a2, 0x6EDC
    ctx->r6 = ADD32(ctx->r6, 0X6EDC);
    // 0x80012868: addiu       $t6, $t6, -0x3410
    ctx->r14 = ADD32(ctx->r14, -0X3410);
    // 0x8001286C: beq         $a0, $zero, L_800128AC
    if (ctx->r4 == 0) {
        // 0x80012870: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800128AC;
    }
    // 0x80012870: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80012874: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012878: lw          $v0, 0x4EE8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE8);
    // 0x8001287C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012880: addiu       $a2, $a2, 0x6EDC
    ctx->r6 = ADD32(ctx->r6, 0X6EDC);
    // 0x80012884: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80012888: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8001288C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80012890: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012894: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80012898: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x8001289C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800128A0: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800128A4: b           L_800128B8
    // 0x800128A8: sw          $t5, 0x6B88($at)
    MEM_W(0X6B88, ctx->r1) = ctx->r13;
        goto L_800128B8;
    // 0x800128A8: sw          $t5, 0x6B88($at)
    MEM_W(0X6B88, ctx->r1) = ctx->r13;
L_800128AC:
    // 0x800128AC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800128B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800128B4: sw          $t7, 0x6B88($at)
    MEM_W(0X6B88, ctx->r1) = ctx->r15;
L_800128B8:
    // 0x800128B8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800128BC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800128C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800128C4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800128C8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800128CC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800128D0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800128D4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800128D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800128DC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800128E0: sw          $t1, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = ctx->r9;
    // 0x800128E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800128E8: sh          $t2, 0x6DC8($at)
    MEM_H(0X6DC8, ctx->r1) = ctx->r10;
    // 0x800128EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800128F0: sw          $zero, 0x6DC4($at)
    MEM_W(0X6DC4, ctx->r1) = 0;
    // 0x800128F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800128F8: addiu       $t3, $t3, -0x4534
    ctx->r11 = ADD32(ctx->r11, -0X4534);
    // 0x800128FC: sw          $t3, 0x6E40($at)
    MEM_W(0X6E40, ctx->r1) = ctx->r11;
    // 0x80012900: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80012904: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012908: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001290C: swc1        $f10, 0x6E20($at)
    MEM_W(0X6E20, ctx->r1) = ctx->f10.u32l;
    // 0x80012910: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80012914: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012918: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001291C: swc1        $f16, 0x6E24($at)
    MEM_W(0X6E24, ctx->r1) = ctx->f16.u32l;
    // 0x80012920: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80012924: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012928: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x8001292C: swc1        $f18, 0x6E28($at)
    MEM_W(0X6E28, ctx->r1) = ctx->f18.u32l;
    // 0x80012930: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80012934: swc1        $f4, 0x6E2C($at)
    MEM_W(0X6E2C, ctx->r1) = ctx->f4.u32l;
    // 0x80012938: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001293C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012940: swc1        $f6, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = ctx->f6.u32l;
    // 0x80012944: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012948: swc1        $f0, 0x6E10($at)
    MEM_W(0X6E10, ctx->r1) = ctx->f0.u32l;
    // 0x8001294C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80012950: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012954: swc1        $f8, 0x6E18($at)
    MEM_W(0X6E18, ctx->r1) = ctx->f8.u32l;
    // 0x80012958: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001295C: swc1        $f10, 0x6E1C($at)
    MEM_W(0X6E1C, ctx->r1) = ctx->f10.u32l;
    // 0x80012960: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80012964: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012968: beql        $v1, $zero, L_80012984
    if (ctx->r3 == 0) {
        // 0x8001296C: swc1        $f0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
            goto L_80012984;
    }
    goto skip_0;
    // 0x8001296C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    skip_0:
    // 0x80012970: beq         $v1, $at, L_80012A28
    if (ctx->r3 == ctx->r1) {
        // 0x80012974: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012A28;
    }
    // 0x80012974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012978: bne         $v1, $at, L_80012A50
    if (ctx->r3 != ctx->r1) {
        // 0x8001297C: nop
    
            goto L_80012A50;
    }
    // 0x8001297C: nop

    // 0x80012980: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_80012984:
    // 0x80012984: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012988: lwc1        $f16, 0x6E0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E0C);
    // 0x8001298C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012990: ldc1        $f4, 0x1318($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1318);
    // 0x80012994: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80012998: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001299C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800129A0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800129A4: swc1        $f8, 0x6B94($at)
    MEM_W(0X6B94, ctx->r1) = ctx->f8.u32l;
    // 0x800129A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129AC: lwc1        $f10, -0x4530($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x800129B0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800129B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800129BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800129C0: swc1        $f18, 0x6DD0($at)
    MEM_W(0X6DD0, ctx->r1) = ctx->f18.u32l;
    // 0x800129C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129C8: lwc1        $f4, 0x6E44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E44);
    // 0x800129CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129D0: lwc1        $f6, -0x45B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X45B8);
    // 0x800129D4: jal         0x800232F4
    // 0x800129D8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x800129D8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x800129DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800129E0: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800129E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129E8: lwc1        $f8, -0x4534($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x800129EC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800129F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800129F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800129F8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800129FC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80012A00: swc1        $f16, 0x6DCC($at)
    MEM_W(0X6DCC, ctx->r1) = ctx->f16.u32l;
    // 0x80012A04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A08: lwc1        $f18, -0x452C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x80012A0C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80012A10: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A14: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80012A18: swc1        $f6, 0x6DD4($at)
    MEM_W(0X6DD4, ctx->r1) = ctx->f6.u32l;
    // 0x80012A1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A20: b           L_80012A50
    // 0x80012A24: swc1        $f0, 0x6E14($at)
    MEM_W(0X6E14, ctx->r1) = ctx->f0.u32l;
        goto L_80012A50;
    // 0x80012A24: swc1        $f0, 0x6E14($at)
    MEM_W(0X6E14, ctx->r1) = ctx->f0.u32l;
L_80012A28:
    // 0x80012A28: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80012A2C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A30: swc1        $f8, 0x6DCC($at)
    MEM_W(0X6DCC, ctx->r1) = ctx->f8.u32l;
    // 0x80012A34: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80012A38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A3C: swc1        $f10, 0x6DD0($at)
    MEM_W(0X6DD0, ctx->r1) = ctx->f10.u32l;
    // 0x80012A40: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80012A44: swc1        $f16, 0x6DD4($at)
    MEM_W(0X6DD4, ctx->r1) = ctx->f16.u32l;
    // 0x80012A48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A4C: swc1        $f0, 0x6E14($at)
    MEM_W(0X6E14, ctx->r1) = ctx->f0.u32l;
L_80012A50:
    // 0x80012A50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A54: swc1        $f0, 0x6DE4($at)
    MEM_W(0X6DE4, ctx->r1) = ctx->f0.u32l;
    // 0x80012A58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A5C: swc1        $f0, 0x6DEC($at)
    MEM_W(0X6DEC, ctx->r1) = ctx->f0.u32l;
    // 0x80012A60: swc1        $f0, 0x6DE8($at)
    MEM_W(0X6DE8, ctx->r1) = ctx->f0.u32l;
    // 0x80012A64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A68: lwc1        $f18, -0x4534($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x80012A6C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A70: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012A74: swc1        $f18, 0x6DD8($at)
    MEM_W(0X6DD8, ctx->r1) = ctx->f18.u32l;
    // 0x80012A78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A7C: lwc1        $f4, -0x4530($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x80012A80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A84: lwc1        $f6, 0x6E1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E1C);
    // 0x80012A88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012A8C: addiu       $v1, $v1, 0x6EC8
    ctx->r3 = ADD32(ctx->r3, 0X6EC8);
    // 0x80012A90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80012A94: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80012A98: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80012A9C: swc1        $f8, 0x6DDC($at)
    MEM_W(0X6DDC, ctx->r1) = ctx->f8.u32l;
    // 0x80012AA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AA4: lwc1        $f10, -0x452C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x80012AA8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AAC: swc1        $f10, 0x6DE0($at)
    MEM_W(0X6DE0, ctx->r1) = ctx->f10.u32l;
    // 0x80012AB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AB4: swc1        $f0, 0x6DF0($at)
    MEM_W(0X6DF0, ctx->r1) = ctx->f0.u32l;
    // 0x80012AB8: swc1        $f0, 0x6DF4($at)
    MEM_W(0X6DF4, ctx->r1) = ctx->f0.u32l;
    // 0x80012ABC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AC0: swc1        $f0, 0x6DF8($at)
    MEM_W(0X6DF8, ctx->r1) = ctx->f0.u32l;
    // 0x80012AC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AC8: swc1        $f0, 0x6E08($at)
    MEM_W(0X6E08, ctx->r1) = ctx->f0.u32l;
    // 0x80012ACC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AD0: swc1        $f0, 0x6E04($at)
    MEM_W(0X6E04, ctx->r1) = ctx->f0.u32l;
    // 0x80012AD4: swc1        $f0, 0x6E00($at)
    MEM_W(0X6E00, ctx->r1) = ctx->f0.u32l;
    // 0x80012AD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012ADC: swc1        $f0, 0x6DFC($at)
    MEM_W(0X6DFC, ctx->r1) = ctx->f0.u32l;
    // 0x80012AE0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012AE4: lwc1        $f16, 0x1320($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1320);
    // 0x80012AE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AEC: swc1        $f16, 0x6E30($at)
    MEM_W(0X6E30, ctx->r1) = ctx->f16.u32l;
    // 0x80012AF0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012AF4: lwc1        $f2, 0x1324($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1324);
    // 0x80012AF8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012AFC: swc1        $f2, 0x6E34($at)
    MEM_W(0X6E34, ctx->r1) = ctx->f2.u32l;
    // 0x80012B00: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012B04: lwc1        $f18, 0x1328($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1328);
    // 0x80012B08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B0C: swc1        $f2, 0x6E3C($at)
    MEM_W(0X6E3C, ctx->r1) = ctx->f2.u32l;
    // 0x80012B10: swc1        $f18, 0x6E38($at)
    MEM_W(0X6E38, ctx->r1) = ctx->f18.u32l;
    // 0x80012B14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B18: sw          $zero, 0x6C2C($at)
    MEM_W(0X6C2C, ctx->r1) = 0;
    // 0x80012B1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B20: sh          $zero, 0x6BBC($at)
    MEM_H(0X6BBC, ctx->r1) = 0;
    // 0x80012B24: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80012B28: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B2C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80012B30: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80012B34: lhu         $t4, -0x4D18($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4D18);
    // 0x80012B38: swc1        $f6, 0x6ECC($at)
    MEM_W(0X6ECC, ctx->r1) = ctx->f6.u32l;
    // 0x80012B3C: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80012B40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B44: swc1        $f8, 0x6ED0($at)
    MEM_W(0X6ED0, ctx->r1) = ctx->f8.u32l;
    // 0x80012B48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80012B4C: bne         $t4, $at, L_80012BC8
    if (ctx->r12 != ctx->r1) {
        // 0x80012B50: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80012BC8;
    }
    // 0x80012B50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B54: sw          $t5, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = ctx->r13;
    // 0x80012B58: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012B5C: lwc1        $f10, 0x132C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X132C);
    // 0x80012B60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B64: swc1        $f10, 0x6DCC($at)
    MEM_W(0X6DCC, ctx->r1) = ctx->f10.u32l;
    // 0x80012B68: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80012B6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80012B70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B74: swc1        $f16, 0x6DD0($at)
    MEM_W(0X6DD0, ctx->r1) = ctx->f16.u32l;
    // 0x80012B78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012B7C: lwc1        $f18, 0x1330($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1330);
    // 0x80012B80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B84: swc1        $f18, 0x6DD4($at)
    MEM_W(0X6DD4, ctx->r1) = ctx->f18.u32l;
    // 0x80012B88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012B8C: lwc1        $f4, 0x1334($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1334);
    // 0x80012B90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012B94: swc1        $f4, 0x6DD8($at)
    MEM_W(0X6DD8, ctx->r1) = ctx->f4.u32l;
    // 0x80012B98: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80012B9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012BA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012BA4: swc1        $f6, 0x6DDC($at)
    MEM_W(0X6DDC, ctx->r1) = ctx->f6.u32l;
    // 0x80012BA8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012BAC: lwc1        $f8, 0x1338($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1338);
    // 0x80012BB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012BB4: swc1        $f8, 0x6DE0($at)
    MEM_W(0X6DE0, ctx->r1) = ctx->f8.u32l;
    // 0x80012BB8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80012BBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012BC0: nop

    // 0x80012BC4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_80012BC8:
    // 0x80012BC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012BCC: swc1        $f0, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = ctx->f0.u32l;
    // 0x80012BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80012BD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80012BD8: jr          $ra
    // 0x80012BDC: nop

    return;
    // 0x80012BDC: nop

;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FB4C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8003FB50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8003FB54: beq         $t6, $zero, L_8003FB6C
    if (ctx->r14 == 0) {
        // 0x8003FB58: nop
    
            goto L_8003FB6C;
    }
    // 0x8003FB58: nop

    // 0x8003FB5C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_8003FB60:
    // 0x8003FB60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003FB64: bnel        $t7, $zero, L_8003FB60
    if (ctx->r15 != 0) {
        // 0x8003FB68: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_8003FB60;
    }
    goto skip_0;
    // 0x8003FB68: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_8003FB6C:
    // 0x8003FB6C: jr          $ra
    // 0x8003FB70: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x8003FB70: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void func_8002234C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002234C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80022350: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80022354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022358: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002235C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80022360: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80022364: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80022368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002236C: lh          $a3, 0x4($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X4);
    // 0x80022370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022374: beql        $a3, $zero, L_800223B4
    if (ctx->r7 == 0) {
        // 0x80022378: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_800223B4;
    }
    goto skip_0;
    // 0x80022378: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8002237C: lhu         $t0, 0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4);
    // 0x80022380: lhu         $t7, 0x6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X6);
    // 0x80022384: subu        $v0, $t7, $t0
    ctx->r2 = SUB32(ctx->r15, ctx->r8);
    // 0x80022388: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x8002238C: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022390: beql        $at, $zero, L_800223A0
    if (ctx->r1 == 0) {
        // 0x80022394: addu        $t9, $t0, $a2
        ctx->r25 = ADD32(ctx->r8, ctx->r6);
            goto L_800223A0;
    }
    goto skip_1;
    // 0x80022394: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    skip_1:
    // 0x80022398: andi        $a2, $a3, 0xFFFF
    ctx->r6 = ctx->r7 & 0XFFFF;
    // 0x8002239C: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_800223A0:
    // 0x800223A0: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x800223A4: jal         0x80018DF4
    // 0x800223A8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80018DF4(rdram, ctx);
        goto after_0;
    // 0x800223A8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x800223AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800223B0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_800223B4:
    // 0x800223B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800223B8: lh          $a0, 0x6($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X6);
    // 0x800223BC: beq         $a0, $zero, L_800223F4
    if (ctx->r4 == 0) {
        // 0x800223C0: nop
    
            goto L_800223F4;
    }
    // 0x800223C0: nop

    // 0x800223C4: lhu         $a3, 0x8($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X8);
    // 0x800223C8: lhu         $t2, 0xA($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XA);
    // 0x800223CC: subu        $v0, $t2, $a3
    ctx->r2 = SUB32(ctx->r10, ctx->r7);
    // 0x800223D0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x800223D4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800223D8: beql        $at, $zero, L_800223E8
    if (ctx->r1 == 0) {
        // 0x800223DC: addu        $t4, $a3, $a2
        ctx->r12 = ADD32(ctx->r7, ctx->r6);
            goto L_800223E8;
    }
    goto skip_2;
    // 0x800223DC: addu        $t4, $a3, $a2
    ctx->r12 = ADD32(ctx->r7, ctx->r6);
    skip_2:
    // 0x800223E0: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x800223E4: addu        $t4, $a3, $a2
    ctx->r12 = ADD32(ctx->r7, ctx->r6);
L_800223E8:
    // 0x800223E8: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
    // 0x800223EC: jal         0x80018DF4
    // 0x800223F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80018DF4(rdram, ctx);
        goto after_1;
    // 0x800223F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800223F4:
    // 0x800223F4: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x800223F8: addiu       $v0, $v0, -0x6598
    ctx->r2 = ADD32(ctx->r2, -0X6598);
    // 0x800223FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80022400: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022404: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022408: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002240C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022410: addiu       $v1, $v1, -0x2FF0
    ctx->r3 = ADD32(ctx->r3, -0X2FF0);
    // 0x80022414: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x80022418: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8002241C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80022420: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80022424: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80022428: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8002242C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80022430: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80022434: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x80022438: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002243C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022440: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80022444: addiu       $t7, $t7, -0x65AC
    ctx->r15 = ADD32(ctx->r15, -0X65AC);
    // 0x80022448: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8002244C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80022450: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022454: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80022458: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x8002245C: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x80022460: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80022464: jal         0x800177F8
    // 0x80022468: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800177F8(rdram, ctx);
        goto after_2;
    // 0x80022468: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8002246C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022470: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80022474: jal         0x800268D4
    // 0x80022478: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x80022478: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_3:
    // 0x8002247C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80022480: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80022484: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80022488: jr          $ra
    // 0x8002248C: nop

    return;
    // 0x8002248C: nop

;}
RECOMP_FUNC void func_80011B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011B40: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011B44: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80011B48: addiu       $v0, $v0, 0x69F8
    ctx->r2 = ADD32(ctx->r2, 0X69F8);
    // 0x80011B4C: addiu       $v1, $v1, 0x69D8
    ctx->r3 = ADD32(ctx->r3, 0X69D8);
L_80011B50:
    // 0x80011B50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80011B54: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80011B58: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x80011B5C: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80011B60: bne         $v1, $v0, L_80011B50
    if (ctx->r3 != ctx->r2) {
        // 0x80011B64: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80011B50;
    }
    // 0x80011B64: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80011B68: jr          $ra
    // 0x80011B6C: nop

    return;
    // 0x80011B6C: nop

;}
RECOMP_FUNC void func_8001817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001817C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018180: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018184: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80018188: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001818C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018190: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x80018194: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80018198: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_8001819C:
    // 0x8001819C: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800181A0: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // 0x800181A4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x800181A8: beql        $t7, $zero, L_80018264
    if (ctx->r15 == 0) {
        // 0x800181AC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80018264;
    }
    goto skip_0;
    // 0x800181AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800181B0: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x800181B4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800181B8: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800181BC: bne         $t2, $zero, L_80018260
    if (ctx->r10 != 0) {
        // 0x800181C0: sb          $t9, 0x2($a2)
        MEM_B(0X2, ctx->r6) = ctx->r25;
            goto L_80018260;
    }
    // 0x800181C0: sb          $t9, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r25;
    // 0x800181C4: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x800181C8: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x800181CC: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x800181D0: xor         $t4, $t3, $v1
    ctx->r12 = ctx->r11 ^ ctx->r3;
    // 0x800181D4: beq         $t5, $zero, L_800181EC
    if (ctx->r13 == 0) {
        // 0x800181D8: sh          $t4, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r12;
            goto L_800181EC;
    }
    // 0x800181D8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x800181DC: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x800181E0: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x800181E4: b           L_80018260
    // 0x800181E8: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
        goto L_80018260;
    // 0x800181E8: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_800181EC:
    // 0x800181EC: beq         $t7, $zero, L_80018200
    if (ctx->r15 == 0) {
        // 0x800181F0: andi        $t9, $v1, 0x10
        ctx->r25 = ctx->r3 & 0X10;
            goto L_80018200;
    }
    // 0x800181F0: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x800181F4: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x800181F8: b           L_80018260
    // 0x800181FC: sh          $t0, 0x8A($t8)
    MEM_H(0X8A, ctx->r24) = ctx->r8;
        goto L_80018260;
    // 0x800181FC: sh          $t0, 0x8A($t8)
    MEM_H(0X8A, ctx->r24) = ctx->r8;
L_80018200:
    // 0x80018200: beq         $t9, $zero, L_80018214
    if (ctx->r25 == 0) {
        // 0x80018204: andi        $t3, $v1, 0x20
        ctx->r11 = ctx->r3 & 0X20;
            goto L_80018214;
    }
    // 0x80018204: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x80018208: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8001820C: b           L_80018260
    // 0x80018210: swc1        $f0, 0x90($t2)
    MEM_W(0X90, ctx->r10) = ctx->f0.u32l;
        goto L_80018260;
    // 0x80018210: swc1        $f0, 0x90($t2)
    MEM_W(0X90, ctx->r10) = ctx->f0.u32l;
L_80018214:
    // 0x80018214: beq         $t3, $zero, L_80018230
    if (ctx->r11 == 0) {
        // 0x80018218: andi        $t7, $v1, 0x400
        ctx->r15 = ctx->r3 & 0X400;
            goto L_80018230;
    }
    // 0x80018218: andi        $t7, $v1, 0x400
    ctx->r15 = ctx->r3 & 0X400;
    // 0x8001821C: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    // 0x80018220: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80018224: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x80018228: b           L_80018260
    // 0x8001822C: sh          $t5, 0x86($t6)
    MEM_H(0X86, ctx->r14) = ctx->r13;
        goto L_80018260;
    // 0x8001822C: sh          $t5, 0x86($t6)
    MEM_H(0X86, ctx->r14) = ctx->r13;
L_80018230:
    // 0x80018230: beq         $t7, $zero, L_8001824C
    if (ctx->r15 == 0) {
        // 0x80018234: andi        $t3, $v1, 0x8
        ctx->r11 = ctx->r3 & 0X8;
            goto L_8001824C;
    }
    // 0x80018234: andi        $t3, $v1, 0x8
    ctx->r11 = ctx->r3 & 0X8;
    // 0x80018238: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x8001823C: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x80018240: lhu         $t9, 0xE($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XE);
    // 0x80018244: b           L_80018260
    // 0x80018248: sh          $t9, 0x88($t2)
    MEM_H(0X88, ctx->r10) = ctx->r25;
        goto L_80018260;
    // 0x80018248: sh          $t9, 0x88($t2)
    MEM_H(0X88, ctx->r10) = ctx->r25;
L_8001824C:
    // 0x8001824C: beql        $t3, $zero, L_80018264
    if (ctx->r11 == 0) {
        // 0x80018250: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80018264;
    }
    goto skip_1;
    // 0x80018250: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80018254: lhu         $t4, 0x60($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X60);
    // 0x80018258: and         $t5, $t4, $t1
    ctx->r13 = ctx->r12 & ctx->r9;
    // 0x8001825C: sh          $t5, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r13;
L_80018260:
    // 0x80018260: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80018264:
    // 0x80018264: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80018268: bne         $a1, $a3, L_8001819C
    if (ctx->r5 != ctx->r7) {
        // 0x8001826C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8001819C;
    }
    // 0x8001826C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80018270: jr          $ra
    // 0x80018274: nop

    return;
    // 0x80018274: nop

;}
RECOMP_FUNC void func_8001737C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001737C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017384: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80017388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001738C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80017390: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80017394: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80017398: bne         $t7, $zero, L_800173C8
    if (ctx->r15 != 0) {
        // 0x8001739C: nop
    
            goto L_800173C8;
    }
    // 0x8001739C: nop

    // 0x800173A0: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800173A4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800173A8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800173AC: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x800173B0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800173B4: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800173B8: jal         0x8001FCF8
    // 0x800173BC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x800173BC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x800173C0: b           L_800173D4
    // 0x800173C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800173D4;
    // 0x800173C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800173C8:
    // 0x800173C8: jal         0x800208B8
    // 0x800173CC: nop

    func_800208B8(rdram, ctx);
        goto after_1;
    // 0x800173CC: nop

    after_1:
    // 0x800173D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800173D4:
    // 0x800173D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800173D8: jr          $ra
    // 0x800173DC: nop

    return;
    // 0x800173DC: nop

;}
RECOMP_FUNC void func_80025364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025364: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002536C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80025370: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80025374: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025378: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8002537C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80025380: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80025384: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80025388: addiu       $t7, $t7, -0x688
    ctx->r15 = ADD32(ctx->r15, -0X688);
    // 0x8002538C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025390: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80025394: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x80025398: addiu       $a2, $v0, 0x98
    ctx->r6 = ADD32(ctx->r2, 0X98);
    // 0x8002539C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800253A0: beql        $t8, $zero, L_800253B4
    if (ctx->r24 == 0) {
        // 0x800253A4: lw          $a1, 0x190($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X190);
            goto L_800253B4;
    }
    goto skip_0;
    // 0x800253A4: lw          $a1, 0x190($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X190);
    skip_0:
    // 0x800253A8: b           L_800253E0
    // 0x800253AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800253E0;
    // 0x800253AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800253B0: lw          $a1, 0x190($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X190);
L_800253B4:
    // 0x800253B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800253B8: jal         0x80038AEC
    // 0x800253BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80038AEC(rdram, ctx);
        goto after_0;
    // 0x800253BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800253C0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800253C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800253C8: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x800253CC: jal         0x80039050
    // 0x800253D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80039050(rdram, ctx);
        goto after_1;
    // 0x800253D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800253D4: jal         0x80039090
    // 0x800253D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80039090(rdram, ctx);
        goto after_2;
    // 0x800253D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800253DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800253E0:
    // 0x800253E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800253E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800253E8: jr          $ra
    // 0x800253EC: nop

    return;
    // 0x800253EC: nop

;}
RECOMP_FUNC void func_800073CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800073D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800073D4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800073D8: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x800073DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800073E0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800073E4: beql        $t7, $zero, L_80007494
    if (ctx->r15 == 0) {
        // 0x800073E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80007494;
    }
    goto skip_0;
    // 0x800073E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800073EC: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800073F0: lwc1        $f6, -0x3A5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x800073F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800073F8: lwc1        $f10, -0x3BD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3BD0);
    // 0x800073FC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007400: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80007404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80007408: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000740C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80007410: nop

    // 0x80007414: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80007418: jal         0x80034F60
    // 0x8000741C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000741C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x80007420: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80007424: addiu       $v1, $v1, -0x4360
    ctx->r3 = ADD32(ctx->r3, -0X4360);
    // 0x80007428: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000742C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80007430: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80007434: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80007438: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000743C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80007440: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80007444: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80007448: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x8000744C: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80007450: nop

    // 0x80007454: bc1fl       L_80007494
    if (!c1cs) {
        // 0x80007458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80007494;
    }
    goto skip_1;
    // 0x80007458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000745C: sub.d       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f2.d - ctx->f12.d;
L_80007460:
    // 0x80007460: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80007464: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80007468: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8000746C: lhu         $t8, 0x2C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2C);
    // 0x80007470: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007474: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x80007478: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8000747C: cvt.d.s     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f2.d = CVT_D_S(ctx->f18.fl);
    // 0x80007480: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80007484: nop

    // 0x80007488: bc1tl       L_80007460
    if (c1cs) {
        // 0x8000748C: sub.d       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f2.d - ctx->f12.d;
            goto L_80007460;
    }
    goto skip_2;
    // 0x8000748C: sub.d       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f2.d - ctx->f12.d;
    skip_2:
    // 0x80007490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007494:
    // 0x80007494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007498: jr          $ra
    // 0x8000749C: nop

    return;
    // 0x8000749C: nop

;}
RECOMP_FUNC void func_800307D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800307D8: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800307DC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800307E0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800307E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800307E8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800307EC: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x800307F0: sw          $a3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r7;
    // 0x800307F4: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x800307F8: addiu       $t7, $t7, -0x5E0
    ctx->r15 = ADD32(ctx->r15, -0X5E0);
    // 0x800307FC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80030800: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80030804: addiu       $t6, $sp, 0xBC
    ctx->r14 = ADD32(ctx->r29, 0XBC);
    // 0x80030808: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8003080C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80030810: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80030814: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80030818: addiu       $t8, $sp, 0x5C
    ctx->r24 = ADD32(ctx->r29, 0X5C);
    // 0x8003081C: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x80030820: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80030824: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80030828: addiu       $t6, $t6, -0x5D0
    ctx->r14 = ADD32(ctx->r14, -0X5D0);
    // 0x8003082C: addiu       $t9, $t6, 0x60
    ctx->r25 = ADD32(ctx->r14, 0X60);
L_80030830:
    // 0x80030830: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80030834: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80030838: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8003083C: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x80030840: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80030844: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x80030848: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8003084C: bne         $t6, $t9, L_80030830
    if (ctx->r14 != ctx->r25) {
        // 0x80030850: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_80030830;
    }
    // 0x80030850: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x80030854: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80030858: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8003085C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80030860: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80030864: bne         $at, $zero, L_80030874
    if (ctx->r1 != 0) {
        // 0x80030868: lui         $t4, 0xE700
        ctx->r12 = S32(0XE700 << 16);
            goto L_80030874;
    }
    // 0x80030868: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8003086C: b           L_80030878
    // 0x80030870: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
        goto L_80030878;
    // 0x80030870: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80030874:
    // 0x80030874: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
L_80030878:
    // 0x80030878: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8003087C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030880: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80030884: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x80030888: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003088C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80030890: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030894: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80030898: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003089C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800308A0: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x800308A4: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x800308A8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800308AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800308B0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800308B4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800308B8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800308BC: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x800308C0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800308C4: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800308C8: addu        $t6, $sp, $t9
    ctx->r14 = ADD32(ctx->r29, ctx->r25);
    // 0x800308CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800308D0: lw          $t6, 0xBC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XBC);
    // 0x800308D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800308D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800308DC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800308E0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800308E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800308E8: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800308EC: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800308F0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800308F4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800308F8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800308FC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80030900: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030904: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80030908: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x8003090C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80030910: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x80030914: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x80030918: andi        $t8, $t6, 0x3
    ctx->r24 = ctx->r14 & 0X3;
    // 0x8003091C: sll         $t7, $t8, 18
    ctx->r15 = S32(ctx->r24 << 18);
    // 0x80030920: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80030924: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80030928: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8003092C: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x80030930: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80030934: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80030938: andi        $t6, $t9, 0x3
    ctx->r14 = ctx->r25 & 0X3;
    // 0x8003093C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80030940: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80030944: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030948: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003094C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80030950: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030954: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030958: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003095C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030960: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030964: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x80030968: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003096C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030970: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030974: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80030978: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8003097C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80030980: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80030984: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80030988: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8003098C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80030990: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80030994: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80030998: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8003099C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800309A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800309A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800309A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800309AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800309B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800309B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800309B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800309BC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800309C0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800309C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800309C8: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800309CC: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800309D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800309D4: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x800309D8: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800309DC: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800309E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800309E4: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800309E8: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x800309EC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800309F0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800309F4: andi        $t8, $t9, 0x3
    ctx->r24 = ctx->r25 & 0X3;
    // 0x800309F8: sll         $t6, $t8, 18
    ctx->r14 = S32(ctx->r24 << 18);
    // 0x800309FC: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80030A00: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80030A04: andi        $t7, $t8, 0xF
    ctx->r15 = ctx->r24 & 0XF;
    // 0x80030A08: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x80030A0C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80030A10: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80030A14: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x80030A18: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80030A1C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80030A20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80030A24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030A28: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80030A2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80030A30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80030A34: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030A38: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80030A3C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80030A40: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80030A44: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80030A48: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80030A4C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80030A50: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80030A54: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80030A58: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80030A5C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80030A60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030A64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030A68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030A6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030A70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030A74: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80030A78: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80030A7C: bnel        $t8, $zero, L_80030B3C
    if (ctx->r24 != 0) {
        // 0x80030A80: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80030B3C;
    }
    goto skip_0;
    // 0x80030A80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80030A84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030A88: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80030A8C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80030A90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030A94: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x80030A98: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80030A9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030AA0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80030AA4: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80030AA8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80030AAC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80030AB0: addu        $t7, $s1, $t8
    ctx->r15 = ADD32(ctx->r17, ctx->r24);
    // 0x80030AB4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80030AB8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80030ABC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80030AC0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80030AC4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80030AC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030ACC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80030AD0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80030AD4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80030AD8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80030ADC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80030AE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030AE4: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80030AE8: andi        $t9, $s1, 0xF
    ctx->r25 = ctx->r17 & 0XF;
    // 0x80030AEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030AF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030AF4: andi        $t7, $s0, 0xF
    ctx->r15 = ctx->r16 & 0XF;
    // 0x80030AF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030AFC: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80030B00: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x80030B04: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80030B08: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80030B0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030B10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030B14: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80030B18: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80030B1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030B20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030B24: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80030B28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030B2C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80030B30: b           L_80030BD0
    // 0x80030B34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_80030BD0;
    // 0x80030B34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030B38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80030B3C:
    // 0x80030B3C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80030B40: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80030B44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80030B48: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x80030B4C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80030B50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80030B54: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80030B58: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80030B5C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80030B60: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80030B64: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x80030B68: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80030B6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80030B70: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80030B74: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80030B78: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80030B7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030B80: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80030B84: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80030B88: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80030B8C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80030B90: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80030B94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030B98: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80030B9C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80030BA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80030BA4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80030BA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030BAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030BB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030BB4: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80030BB8: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80030BBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030BC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030BC4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80030BC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80030BCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80030BD0:
    // 0x80030BD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80030BD4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030BD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030BDC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80030BE0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80030BE4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80030BE8: jr          $ra
    // 0x80030BEC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80030BEC: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8002E628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E628: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002E62C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8002E630: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002E634: bne         $a1, $zero, L_8002E680
    if (ctx->r5 != 0) {
        // 0x8002E638: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_8002E680;
    }
    // 0x8002E638: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002E63C: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8002E640: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8002E644: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002E648: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8002E64C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002E650: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8002E654: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002E658: addiu       $t8, $t8, 0x5E0
    ctx->r24 = ADD32(ctx->r24, 0X5E0);
    // 0x8002E65C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002E660: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002E664: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8002E668: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8002E66C: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8002E670: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x8002E674: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002E678: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x8002E67C: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
L_8002E680:
    // 0x8002E680: sll         $t1, $a0, 4
    ctx->r9 = S32(ctx->r4 << 4);
    // 0x8002E684: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8002E688: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002E68C: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8002E690: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002E694: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8002E698: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002E69C: addiu       $t2, $t2, 0x5E0
    ctx->r10 = ADD32(ctx->r10, 0X5E0);
    // 0x8002E6A0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002E6A4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8002E6A8: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x8002E6AC: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8002E6B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002E6B4: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8002E6B8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002E6BC: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8002E6C0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002E6C4: addiu       $t5, $t5, 0x5E0
    ctx->r13 = ADD32(ctx->r13, 0X5E0);
    // 0x8002E6C8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002E6CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002E6D0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8002E6D4: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x8002E6D8: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x8002E6DC: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x8002E6E0: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x8002E6E4: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x8002E6E8: sb          $a3, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r7;
    // 0x8002E6EC: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x8002E6F0: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
    // 0x8002E6F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002E6F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002E6FC:
    // 0x8002E6FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E700: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8002E704: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002E708: bne         $at, $zero, L_8002E6FC
    if (ctx->r1 != 0) {
        // 0x8002E70C: sb          $a3, 0x16($a2)
        MEM_B(0X16, ctx->r6) = ctx->r7;
            goto L_8002E6FC;
    }
    // 0x8002E70C: sb          $a3, 0x16($a2)
    MEM_B(0X16, ctx->r6) = ctx->r7;
    // 0x8002E710: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002E714: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002E718:
    // 0x8002E718: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E71C: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x8002E720: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002E724: sb          $a3, 0x9B($a2)
    MEM_B(0X9B, ctx->r6) = ctx->r7;
    // 0x8002E728: bne         $at, $zero, L_8002E718
    if (ctx->r1 != 0) {
        // 0x8002E72C: sb          $a3, 0x49B($a2)
        MEM_B(0X49B, ctx->r6) = ctx->r7;
            goto L_8002E718;
    }
    // 0x8002E72C: sb          $a3, 0x49B($a2)
    MEM_B(0X49B, ctx->r6) = ctx->r7;
    // 0x8002E730: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x8002E734: sh          $zero, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = 0;
    // 0x8002E738: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x8002E73C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002E740: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8002E744:
    // 0x8002E744: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E748: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E74C: sb          $a3, 0x53($a0)
    MEM_B(0X53, ctx->r4) = ctx->r7;
    // 0x8002E750: sb          $a3, 0x6B($a0)
    MEM_B(0X6B, ctx->r4) = ctx->r7;
    // 0x8002E754: sb          $a3, 0x83($a0)
    MEM_B(0X83, ctx->r4) = ctx->r7;
    // 0x8002E758: bne         $v1, $v0, L_8002E744
    if (ctx->r3 != ctx->r2) {
        // 0x8002E75C: sb          $a3, 0x3B($a0)
        MEM_B(0X3B, ctx->r4) = ctx->r7;
            goto L_8002E744;
    }
    // 0x8002E75C: sb          $a3, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r7;
    // 0x8002E760: jr          $ra
    // 0x8002E764: nop

    return;
    // 0x8002E764: nop

;}
RECOMP_FUNC void func_80011100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011100: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80011104: lw          $t6, 0x5B38($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5B38);
    // 0x80011108: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001110C: addiu       $v1, $v1, 0x5B38
    ctx->r3 = ADD32(ctx->r3, 0X5B38);
    // 0x80011110: beq         $t6, $zero, L_80011130
    if (ctx->r14 == 0) {
        // 0x80011114: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80011130;
    }
    // 0x80011114: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80011118: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8001111C:
    // 0x8001111C: beq         $a0, $zero, L_80011130
    if (ctx->r4 == 0) {
        // 0x80011120: addiu       $v1, $v1, -0x30
        ctx->r3 = ADD32(ctx->r3, -0X30);
            goto L_80011130;
    }
    // 0x80011120: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x80011124: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80011128: bnel        $t7, $zero, L_8001111C
    if (ctx->r15 != 0) {
        // 0x8001112C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8001111C;
    }
    goto skip_0;
    // 0x8001112C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_0:
L_80011130:
    // 0x80011130: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80011134: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80011138: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001113C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80011140: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80011144: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80011148: jr          $ra
    // 0x8001114C: nop

    return;
    // 0x8001114C: nop

;}
RECOMP_FUNC void func_8002A668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A668: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8002A66C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002A670: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8002A674: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002A678: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002A67C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002A680: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002A684: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x8002A688: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x8002A68C: addiu       $s3, $s3, -0x2F4
    ctx->r19 = ADD32(ctx->r19, -0X2F4);
    // 0x8002A690: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A694: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002A698: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002A69C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002A6A0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002A6A4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A6A8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A6AC: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002A6B0: addiu       $t7, $t7, -0x6A4
    ctx->r15 = ADD32(ctx->r15, -0X6A4);
    // 0x8002A6B4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002A6B8: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8002A6BC: addiu       $t6, $sp, 0xD8
    ctx->r14 = ADD32(ctx->r29, 0XD8);
    // 0x8002A6C0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002A6C4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8002A6C8: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8002A6CC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002A6D0: addiu       $t8, $sp, 0xC8
    ctx->r24 = ADD32(ctx->r29, 0XC8);
    // 0x8002A6D4: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8002A6D8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8002A6DC: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002A6E0: addiu       $t6, $t6, -0x694
    ctx->r14 = ADD32(ctx->r14, -0X694);
    // 0x8002A6E4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8002A6E8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8002A6EC: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x8002A6F0: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8002A6F4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8002A6F8: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8002A6FC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8002A700: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x8002A704: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
    // 0x8002A708: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x8002A70C: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8002A710: addiu       $t8, $t8, -0x684
    ctx->r24 = ADD32(ctx->r24, -0X684);
    // 0x8002A714: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8002A718: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002A71C: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x8002A720: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8002A724: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8002A728: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8002A72C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x8002A730: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8002A734: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x8002A738: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8002A73C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A740: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x8002A744: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x8002A748: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A74C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A750: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A754: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002A758: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A75C: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8002A760: addiu       $t9, $t9, 0x4D58
    ctx->r25 = ADD32(ctx->r25, 0X4D58);
    // 0x8002A764: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A768: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A76C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A770: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002A774: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A778: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8002A77C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8002A780: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A784: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A788: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A78C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A790: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A794: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8002A798: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8002A79C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A7A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A7A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A7A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A7AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A7B0: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8002A7B4: lui         $ra, 0x1
    ctx->r31 = S32(0X1 << 16);
    // 0x8002A7B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A7BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A7C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A7C4: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8002A7C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A7CC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8002A7D0: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8002A7D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A7D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A7DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A7E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A7E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A7E8: ori         $ra, $ra, 0x4160
    ctx->r31 = ctx->r31 | 0X4160;
    // 0x8002A7EC: lui         $fp, 0x70F
    ctx->r30 = S32(0X70F << 16);
    // 0x8002A7F0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A7F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A7F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A7FC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002A800: lhu         $t8, 0x0($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X0);
    // 0x8002A804: lui         $s6, 0x701
    ctx->r22 = S32(0X701 << 16);
    // 0x8002A808: lui         $s5, 0xFD48
    ctx->r21 = S32(0XFD48 << 16);
    // 0x8002A80C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8002A810: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    // 0x8002A814: lui         $s3, 0xF548
    ctx->r19 = S32(0XF548 << 16);
    // 0x8002A818: ori         $s3, $s3, 0x1000
    ctx->r19 = ctx->r19 | 0X1000;
    // 0x8002A81C: ori         $s5, $s5, 0x3F
    ctx->r21 = ctx->r21 | 0X3F;
    // 0x8002A820: ori         $s6, $s6, 0x4160
    ctx->r22 = ctx->r22 | 0X4160;
    // 0x8002A824: ori         $fp, $fp, 0xC000
    ctx->r30 = ctx->r30 | 0XC000;
    // 0x8002A828: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
L_8002A82C:
    // 0x8002A82C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A830: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002A834: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A838: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A83C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8002A840: lw          $t7, -0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X4);
    // 0x8002A844: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A848: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A84C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A850: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A854: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8002A858: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002A85C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A860: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A864: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A868: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A86C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8002A870: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A874: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A878: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A87C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8002A880: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8002A884: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002A888: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002A88C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8002A890: or          $t7, $t6, $fp
    ctx->r15 = ctx->r14 | ctx->r30;
    // 0x8002A894: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A898: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A89C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A8A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A8A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A8A8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002A8AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A8B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A8B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A8B8: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8002A8BC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002A8C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A8C4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8002A8C8: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8002A8CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A8D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A8D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A8D8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8002A8DC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8002A8E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002A8E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002A8E8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002A8EC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8002A8F0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002A8F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002A8F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A8FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002A900: lui         $at, 0xE44A
    ctx->r1 = S32(0XE44A << 16);
    // 0x8002A904: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A908: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8002A90C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002A910: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A914: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8002A918: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8002A91C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002A920: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x8002A924: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8002A928: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002A92C: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8002A930: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002A934: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A938: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002A93C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A940: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8002A944: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8002A948: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A94C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A950: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A954: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A958: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A95C: lui         $t6, 0x4A8
    ctx->r14 = S32(0X4A8 << 16);
    // 0x8002A960: ori         $t6, $t6, 0x4E6
    ctx->r14 = ctx->r14 | 0X4E6;
    // 0x8002A964: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A968: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A96C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002A970: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A974: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A978: addiu       $t9, $sp, 0xD8
    ctx->r25 = ADD32(ctx->r29, 0XD8);
    // 0x8002A97C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002A980: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002A984: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A988: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002A98C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002A990: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002A994: sltu        $at, $a0, $t9
    ctx->r1 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x8002A998: bne         $at, $zero, L_8002A82C
    if (ctx->r1 != 0) {
        // 0x8002A99C: addu        $t5, $t5, $t8
        ctx->r13 = ADD32(ctx->r13, ctx->r24);
            goto L_8002A82C;
    }
    // 0x8002A99C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8002A9A0: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8002A9A4: addiu       $s0, $sp, 0xC4
    ctx->r16 = ADD32(ctx->r29, 0XC4);
    // 0x8002A9A8: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x8002A9AC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
L_8002A9B0:
    // 0x8002A9B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A9B4: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x8002A9B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A9BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002A9C0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8002A9C4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8002A9C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A9CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A9D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A9D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A9D8: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8002A9DC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002A9E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A9E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A9E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A9EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A9F0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8002A9F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A9F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002A9FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002AA00: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8002AA04: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8002AA08: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002AA0C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002AA10: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8002AA14: or          $t7, $t6, $fp
    ctx->r15 = ctx->r14 | ctx->r30;
    // 0x8002AA18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002AA1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AA20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002AA24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002AA28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AA2C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002AA30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AA34: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AA38: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AA3C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8002AA40: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002AA44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AA48: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8002AA4C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8002AA50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002AA54: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002AA58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002AA5C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8002AA60: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8002AA64: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002AA68: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002AA6C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8002AA70: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002AA74: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002AA78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AA7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002AA80: lui         $at, 0xE44A
    ctx->r1 = S32(0XE44A << 16);
    // 0x8002AA84: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AA88: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8002AA8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002AA90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AA94: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8002AA98: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8002AA9C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002AAA0: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x8002AAA4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8002AAA8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002AAAC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8002AAB0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002AAB4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002AAB8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002AABC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AAC0: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8002AAC4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8002AAC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002AACC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002AAD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002AAD4: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8002AAD8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002AADC: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8002AAE0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002AAE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002AAE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AAEC: lui         $t6, 0x4A8
    ctx->r14 = S32(0X4A8 << 16);
    // 0x8002AAF0: ori         $t6, $t6, 0xFB1A
    ctx->r14 = ctx->r14 | 0XFB1A;
    // 0x8002AAF4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002AAF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002AAFC: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8002AB00: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002AB04: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002AB08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AB0C: addiu       $t9, $sp, 0xC8
    ctx->r25 = ADD32(ctx->r29, 0XC8);
    // 0x8002AB10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002AB14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002AB18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AB1C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002AB20: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002AB24: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8002AB28: sltu        $at, $a0, $t9
    ctx->r1 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x8002AB2C: beq         $at, $zero, L_8002A9B0
    if (ctx->r1 == 0) {
        // 0x8002AB30: addu        $t5, $t5, $t8
        ctx->r13 = ADD32(ctx->r13, ctx->r24);
            goto L_8002A9B0;
    }
    // 0x8002AB30: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8002AB34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AB38: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002AB3C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002AB40: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002AB44: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002AB48: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002AB4C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB50: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002AB54: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002AB58: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002AB5C: jr          $ra
    // 0x8002AB60: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8002AB60: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80006F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006F70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006F74: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80006F78: lhu         $t6, -0x4548($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4548);
    // 0x80006F7C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80006F80: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80006F84: beql        $t6, $at, L_80007024
    if (ctx->r14 == ctx->r1) {
        // 0x80006F88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80007024;
    }
    goto skip_0;
    // 0x80006F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80006F8C: lw          $t7, -0x4538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4538);
    // 0x80006F90: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80006F94: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80006F98: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x80006F9C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80006FA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006FA4: beq         $t8, $zero, L_80007020
    if (ctx->r24 == 0) {
        // 0x80006FA8: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_80007020;
    }
    // 0x80006FA8: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80006FAC: lh          $t9, -0x44E4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X44E4);
    // 0x80006FB0: sh          $t1, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r9;
    // 0x80006FB4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006FB8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80006FBC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80006FC0: lw          $v0, 0x3D00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D00);
    // 0x80006FC4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80006FC8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80006FCC: lh          $t2, 0x56($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X56);
    // 0x80006FD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006FD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80006FD8: sh          $t2, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r10;
    // 0x80006FDC: lhu         $t3, -0x44D4($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X44D4);
    // 0x80006FE0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006FE4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80006FE8: ori         $t4, $t3, 0x3
    ctx->r12 = ctx->r11 | 0X3;
    // 0x80006FEC: sh          $t4, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r12;
    // 0x80006FF0: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80006FF4: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80006FF8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80006FFC: jal         0x8001D8B0
    // 0x80007000: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80007000: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80007004: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007008: jal         0x800208B8
    // 0x8000700C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_800208B8(rdram, ctx);
        goto after_1;
    // 0x8000700C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_1:
    // 0x80007010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007014: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80007018: jal         0x800268D4
    // 0x8000701C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x8000701C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_2:
L_80007020:
    // 0x80007020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80007024:
    // 0x80007024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007028: jr          $ra
    // 0x8000702C: nop

    return;
    // 0x8000702C: nop

;}
RECOMP_FUNC void func_8000496C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000496C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004970: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80004974: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80004978: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000497C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80004980: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004984: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80004988: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x8000498C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004990: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80004994: beq         $t6, $zero, L_80004A68
    if (ctx->r14 == 0) {
        // 0x80004998: lui         $t3, 0x8009
        ctx->r11 = S32(0X8009 << 16);
            goto L_80004A68;
    }
    // 0x80004998: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8000499C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800049A0: jal         0x800056D0
    // 0x800049A4: addiu       $a2, $a2, -0x43D0
    ctx->r6 = ADD32(ctx->r6, -0X43D0);
    func_800056D0(rdram, ctx);
        goto after_0;
    // 0x800049A4: addiu       $a2, $a2, -0x43D0
    ctx->r6 = ADD32(ctx->r6, -0X43D0);
    after_0:
    // 0x800049A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800049AC: addiu       $v0, $v0, -0x43D0
    ctx->r2 = ADD32(ctx->r2, -0X43D0);
    // 0x800049B0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800049B4: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    // 0x800049B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800049BC: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x800049C0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800049C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800049C8: jal         0x80005748
    // 0x800049CC: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    func_80005748(rdram, ctx);
        goto after_1;
    // 0x800049CC: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x800049D0: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800049D4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800049D8: bnel        $v0, $at, L_80004A24
    if (ctx->r2 != ctx->r1) {
        // 0x800049DC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80004A24;
    }
    goto skip_0;
    // 0x800049DC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x800049E0: jal         0x800120C0
    // 0x800049E4: lbu         $a0, 0x118($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X118);
    func_800120C0(rdram, ctx);
        goto after_2;
    // 0x800049E4: lbu         $a0, 0x118($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X118);
    after_2:
    // 0x800049E8: jal         0x8002E768
    // 0x800049EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002E768(rdram, ctx);
        goto after_3;
    // 0x800049EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800049F0: jal         0x800212A0
    // 0x800049F4: lbu         $a0, 0x118($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X118);
    func_800212A0(rdram, ctx);
        goto after_4;
    // 0x800049F4: lbu         $a0, 0x118($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X118);
    after_4:
    // 0x800049F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800049FC: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x80004A00: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80004A04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80004A08: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80004A0C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80004A10: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80004A14: jal         0x800268D4
    // 0x80004A18: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_5;
    // 0x80004A18: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_5:
    // 0x80004A1C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x80004A20: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_80004A24:
    // 0x80004A24: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80004A28: bne         $t0, $zero, L_80004AA4
    if (ctx->r8 != 0) {
        // 0x80004A2C: sh          $t9, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r25;
            goto L_80004AA4;
    }
    // 0x80004A2C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80004A30: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80004A34: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004A38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004A3C: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x80004A40: lw          $a1, -0x43D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43D4);
    // 0x80004A44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80004A48: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80004A4C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80004A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004A58: jal         0x8001D8B0
    // 0x80004A5C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_6;
    // 0x80004A5C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_6:
    // 0x80004A60: b           L_80004AA8
    // 0x80004A64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80004AA8;
    // 0x80004A64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80004A68:
    // 0x80004A68: lw          $t3, 0x5C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5C0);
    // 0x80004A6C: bnel        $t3, $zero, L_80004AA8
    if (ctx->r11 != 0) {
        // 0x80004A70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80004AA8;
    }
    goto skip_1;
    // 0x80004A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80004A74: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80004A78: lhu         $t4, 0x60($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X60);
    // 0x80004A7C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004A80: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x80004A84: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80004A88: sh          $t5, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r13;
    // 0x80004A8C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80004A90: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80004A94: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80004A98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80004A9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004AA0: sw          $zero, -0x458C($at)
    MEM_W(-0X458C, ctx->r1) = 0;
L_80004AA4:
    // 0x80004AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80004AA8:
    // 0x80004AA8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80004AAC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80004AB0: jr          $ra
    // 0x80004AB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004AB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004793C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80009378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009378: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000937C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80009380: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009384: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80009388: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000938C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009390: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009394: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009398: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    // 0x8000939C: jal         0x8000A7D8
    // 0x800093A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000A7D8(rdram, ctx);
        goto after_0;
    // 0x800093A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800093A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800093A8: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x800093AC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800093B0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800093B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800093B8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800093BC: jal         0x8000A508
    // 0x800093C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_1;
    // 0x800093C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x800093C4: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x800093C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800093CC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800093D0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800093D4: beql        $t7, $zero, L_80009578
    if (ctx->r15 == 0) {
        // 0x800093D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009578;
    }
    goto skip_0;
    // 0x800093D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800093DC: sw          $s0, -0x2F78($at)
    MEM_W(-0X2F78, ctx->r1) = ctx->r16;
    // 0x800093E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800093E4: sh          $t8, -0x39D0($at)
    MEM_H(-0X39D0, ctx->r1) = ctx->r24;
    // 0x800093E8: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
    // 0x800093EC: lhu         $t1, 0x90($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X90);
    // 0x800093F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800093F4: andi        $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 & 0XFFFC;
    // 0x800093F8: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x800093FC: beq         $t2, $zero, L_80009414
    if (ctx->r10 == 0) {
        // 0x80009400: sh          $t0, 0x8($s0)
        MEM_H(0X8, ctx->r16) = ctx->r8;
            goto L_80009414;
    }
    // 0x80009400: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x80009404: jal         0x8001D358
    // 0x80009408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_2;
    // 0x80009408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8000940C: b           L_80009578
    // 0x80009410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009578;
    // 0x80009410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009414:
    // 0x80009414: jal         0x8000A008
    // 0x80009418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A008(rdram, ctx);
        goto after_3;
    // 0x80009418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8000941C: beq         $v0, $zero, L_800094E0
    if (ctx->r2 == 0) {
        // 0x80009420: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800094E0;
    }
    // 0x80009420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80009424: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
    // 0x80009428: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000942C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80009430: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80009434: bne         $t4, $zero, L_80009450
    if (ctx->r12 != 0) {
        // 0x80009438: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_80009450;
    }
    // 0x80009438: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8000943C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009440: jal         0x8000A284
    // 0x80009444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000A284(rdram, ctx);
        goto after_4;
    // 0x80009444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80009448: b           L_80009578
    // 0x8000944C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009578;
    // 0x8000944C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009450:
    // 0x80009450: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x80009454: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x80009458: lhu         $t7, -0x3A6E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3A6E);
    // 0x8000945C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80009460: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80009464: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x80009468: beq         $t8, $zero, L_800094A8
    if (ctx->r24 == 0) {
        // 0x8000946C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800094A8;
    }
    // 0x8000946C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009470: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80009474: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80009478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000947C: lh          $t0, 0xE($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XE);
    // 0x80009480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80009488: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x8000948C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80009490: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80009494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009498: jal         0x8001D8B0
    // 0x8000949C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_5;
    // 0x8000949C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800094A0: b           L_80009578
    // 0x800094A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009578;
    // 0x800094A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800094A8:
    // 0x800094A8: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x800094AC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800094B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800094B4: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800094B8: mflo        $t5
    ctx->r13 = lo;
    // 0x800094BC: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x800094C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800094C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800094C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800094CC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800094D0: jal         0x8001D8B0
    // 0x800094D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_6;
    // 0x800094D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800094D8: b           L_80009578
    // 0x800094DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009578;
    // 0x800094DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800094E0:
    // 0x800094E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800094E4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800094E8: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800094EC: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x800094F0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800094F4: lhu         $t0, -0x3A6E($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X3A6E);
    // 0x800094F8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800094FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80009500: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x80009504: beq         $t1, $zero, L_80009544
    if (ctx->r9 == 0) {
        // 0x80009508: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009544;
    }
    // 0x80009508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000950C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80009510: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80009514: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80009518: lh          $t3, 0xE($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XE);
    // 0x8000951C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80009524: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80009528: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000952C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80009530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009534: jal         0x8001D8B0
    // 0x80009538: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_7;
    // 0x80009538: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8000953C: b           L_80009578
    // 0x80009540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009578;
    // 0x80009540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009544:
    // 0x80009544: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80009548: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8000954C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80009550: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80009554: mflo        $t8
    ctx->r24 = lo;
    // 0x80009558: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8000955C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80009560: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80009564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80009568: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8000956C: jal         0x8001D8B0
    // 0x80009570: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_8;
    // 0x80009570: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80009574: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009578:
    // 0x80009578: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000957C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80009580: jr          $ra
    // 0x80009584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80040BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040BF4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80040BF8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80040BFC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80040C00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80040C04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040C08: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80040C0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80040C10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80040C14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80040C18: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80040C1C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80040C20: bne         $a2, $zero, L_80040C30
    if (ctx->r6 != 0) {
        // 0x80040C24: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_80040C30;
    }
    // 0x80040C24: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x80040C28: b           L_80040F84
    // 0x80040C2C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80040F84;
    // 0x80040C2C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80040C30:
    // 0x80040C30: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80040C34: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80040C38: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x80040C3C: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x80040C40: beql        $at, $zero, L_80040E54
    if (ctx->r1 == 0) {
        // 0x80040C44: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_80040E54;
    }
    goto skip_0;
    // 0x80040C44: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x80040C48: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80040C4C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x80040C50: beql        $t7, $zero, L_80040E54
    if (ctx->r15 == 0) {
        // 0x80040C54: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_80040E54;
    }
    goto skip_1;
    // 0x80040C54: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x80040C58: blez        $s2, L_80040CD4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80040C5C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_80040CD4;
    }
    // 0x80040C5C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x80040C60: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x80040C64: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80040C68: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x80040C6C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80040C70: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80040C74: jalr        $t9
    // 0x80040C78: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80040C78: nop

    after_0:
    // 0x80040C7C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80040C80: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x80040C84: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80040C88: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x80040C8C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x80040C90: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x80040C94: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x80040C98: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80040C9C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80040CA0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80040CA4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80040CA8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80040CAC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80040CB0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80040CB4: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x80040CB8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80040CBC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80040CC0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80040CC4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x80040CC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80040CCC: b           L_80040CD8
    // 0x80040CD0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80040CD8;
    // 0x80040CD0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80040CD4:
    // 0x80040CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80040CD8:
    // 0x80040CD8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80040CDC: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80040CE0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80040CE4: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x80040CE8: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80040CEC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80040CF0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80040CF4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80040CF8: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x80040CFC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80040D00: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x80040D04: beq         $at, $zero, L_80040E2C
    if (ctx->r1 == 0) {
        // 0x80040D08: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_80040E2C;
    }
    // 0x80040D08: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x80040D0C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_80040D10:
    // 0x80040D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80040D14: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80040D18: beq         $v0, $at, L_80040D2C
    if (ctx->r2 == ctx->r1) {
        // 0x80040D1C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_80040D2C;
    }
    // 0x80040D1C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x80040D20: beq         $v0, $zero, L_80040D2C
    if (ctx->r2 == 0) {
        // 0x80040D24: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80040D2C;
    }
    // 0x80040D24: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80040D28: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_80040D2C:
    // 0x80040D2C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x80040D30: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80040D34: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x80040D38: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x80040D3C: beq         $at, $zero, L_80040D4C
    if (ctx->r1 == 0) {
        // 0x80040D40: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80040D4C;
    }
    // 0x80040D40: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80040D44: b           L_80040D4C
    // 0x80040D48: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_80040D4C;
    // 0x80040D48: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_80040D4C:
    // 0x80040D4C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x80040D50: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80040D54: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80040D58: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80040D5C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80040D60: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x80040D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80040D68: jalr        $t9
    // 0x80040D6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80040D6C: nop

    after_1:
    // 0x80040D70: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80040D74: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x80040D78: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80040D7C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x80040D80: beq         $v1, $zero, L_80040D94
    if (ctx->r3 == 0) {
        // 0x80040D84: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_80040D94;
    }
    // 0x80040D84: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x80040D88: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80040D8C: b           L_80040D98
    // 0x80040D90: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_80040D98;
    // 0x80040D90: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_80040D94:
    // 0x80040D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80040D98:
    // 0x80040D98: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x80040D9C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x80040DA0: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x80040DA4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80040DA8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80040DAC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80040DB0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x80040DB4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80040DB8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x80040DBC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80040DC0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80040DC4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80040DC8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80040DCC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x80040DD0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80040DD4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80040DD8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80040DDC: bne         $a1, $zero, L_80040DE8
    if (ctx->r5 != 0) {
        // 0x80040DE0: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_80040DE8;
    }
    // 0x80040DE0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80040DE4: beq         $a2, $zero, L_80040E20
    if (ctx->r6 == 0) {
        // 0x80040DE8: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_80040E20;
    }
L_80040DE8:
    // 0x80040DE8: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x80040DEC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80040DF0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80040DF4: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80040DF8: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80040DFC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80040E00: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80040E04: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x80040E08: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80040E0C: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x80040E10: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x80040E14: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80040E18: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80040E1C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80040E20:
    // 0x80040E20: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80040E24: bnel        $at, $zero, L_80040D10
    if (ctx->r1 != 0) {
        // 0x80040E28: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_80040D10;
    }
    goto skip_2;
    // 0x80040E28: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_80040E2C:
    // 0x80040E2C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x80040E30: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80040E34: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x80040E38: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x80040E3C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80040E40: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x80040E44: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x80040E48: b           L_80040F84
    // 0x80040E4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80040F84;
    // 0x80040E4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80040E50: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_80040E54:
    // 0x80040E54: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x80040E58: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x80040E5C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80040E60: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80040E64: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x80040E68: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x80040E6C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x80040E70: bgezl       $s2, L_80040E80
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80040E74: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80040E80;
    }
    goto skip_3;
    // 0x80040E74: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x80040E78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80040E7C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_80040E80:
    // 0x80040E80: beql        $at, $zero, L_80040E90
    if (ctx->r1 == 0) {
        // 0x80040E84: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_80040E90;
    }
    goto skip_4;
    // 0x80040E84: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x80040E88: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80040E8C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_80040E90:
    // 0x80040E90: beql        $at, $zero, L_80040F44
    if (ctx->r1 == 0) {
        // 0x80040E94: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_80040F44;
    }
    goto skip_5;
    // 0x80040E94: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x80040E98: blez        $s3, L_80040F18
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80040E9C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80040F18;
    }
    // 0x80040E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80040EA0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80040EA4: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x80040EA8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80040EAC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x80040EB0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80040EB4: jalr        $t9
    // 0x80040EB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80040EB8: nop

    after_2:
    // 0x80040EBC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80040EC0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80040EC4: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x80040EC8: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x80040ECC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80040ED0: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x80040ED4: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x80040ED8: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x80040EDC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80040EE0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80040EE4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80040EE8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80040EEC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80040EF0: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x80040EF4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80040EF8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x80040EFC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80040F00: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80040F04: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80040F08: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80040F0C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80040F10: b           L_80040F18
    // 0x80040F14: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80040F18;
    // 0x80040F14: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80040F18:
    // 0x80040F18: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x80040F1C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80040F20: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x80040F24: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x80040F28: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80040F2C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x80040F30: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x80040F34: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x80040F38: b           L_80040F44
    // 0x80040F3C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_80040F44;
    // 0x80040F3C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x80040F40: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_80040F44:
    // 0x80040F44: beq         $s2, $zero, L_80040F80
    if (ctx->r18 == 0) {
        // 0x80040F48: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_80040F80;
    }
    // 0x80040F48: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x80040F4C: bgez        $v1, L_80040F58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80040F50: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80040F58;
    }
    // 0x80040F50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80040F54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80040F58:
    // 0x80040F58: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x80040F5C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80040F60: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80040F64: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80040F68: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80040F6C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80040F70: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x80040F74: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80040F78: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80040F7C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80040F80:
    // 0x80040F80: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80040F84:
    // 0x80040F84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80040F88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80040F8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80040F90: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80040F94: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80040F98: jr          $ra
    // 0x80040F9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80040F9C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800493D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800493D8: bne         $a1, $at, L_800493E4
    if (ctx->r5 != ctx->r1) {
        // 0x800493DC: nop
    
            goto L_800493E4;
    }
    // 0x800493DC: nop

    // 0x800493E0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800493E4:
    // 0x800493E4: jr          $ra
    // 0x800493E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800493E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8000FCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCBC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000FCC0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000FCC4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000FCC8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000FCCC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000FCD0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000FCD4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000FCD8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000FCDC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000FCE0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000FCE4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000FCE8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000FCEC: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x8000FCF0: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8000FCF4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000FCF8: lw          $fp, 0xC($s3)
    ctx->r30 = MEM_W(ctx->r19, 0XC);
    // 0x8000FCFC: lw          $s7, 0x8($s3)
    ctx->r23 = MEM_W(ctx->r19, 0X8);
    // 0x8000FD00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000FD04: beq         $fp, $zero, L_8000FD98
    if (ctx->r30 == 0) {
        // 0x8000FD08: lui         $s6, 0x8008
        ctx->r22 = S32(0X8008 << 16);
            goto L_8000FD98;
    }
    // 0x8000FD08: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8000FD0C: addiu       $s6, $s6, 0x5340
    ctx->r22 = ADD32(ctx->r22, 0X5340);
    // 0x8000FD10: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x8000FD14: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8000FD18:
    // 0x8000FD18: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8000FD1C: lw          $s1, 0x4($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X4);
    // 0x8000FD20: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x8000FD24: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000FD28: beq         $s1, $zero, L_8000FD8C
    if (ctx->r17 == 0) {
        // 0x8000FD2C: addu        $s0, $t6, $t8
        ctx->r16 = ADD32(ctx->r14, ctx->r24);
            goto L_8000FD8C;
    }
    // 0x8000FD2C: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
L_8000FD30:
    // 0x8000FD30: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000FD34: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8000FD38: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8000FD3C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000FD40: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x8000FD44: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000FD48: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000FD4C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8000FD50: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x8000FD54: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000FD58: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000FD5C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8000FD60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000FD64: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000FD68: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000FD6C: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x8000FD70: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8000FD74: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8000FD78: jal         0x8000F6A4
    // 0x8000FD7C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_8000F6A4(rdram, ctx);
        goto after_0;
    // 0x8000FD7C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8000FD80: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000FD84: bne         $s1, $zero, L_8000FD30
    if (ctx->r17 != 0) {
        // 0x8000FD88: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8000FD30;
    }
    // 0x8000FD88: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_8000FD8C:
    // 0x8000FD8C: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // 0x8000FD90: bne         $fp, $zero, L_8000FD18
    if (ctx->r30 != 0) {
        // 0x8000FD94: addiu       $s7, $s7, 0x8
        ctx->r23 = ADD32(ctx->r23, 0X8);
            goto L_8000FD18;
    }
    // 0x8000FD94: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
L_8000FD98:
    // 0x8000FD98: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000FD9C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8000FDA0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000FDA4: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x8000FDA8: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000FDAC: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x8000FDB0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000FDB4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000FDB8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FDBC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000FDC0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000FDC4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000FDC8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FDCC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000FDD0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000FDD4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000FDD8: jr          $ra
    // 0x8000FDDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000FDDC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8001613C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001613C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80016140: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80016144: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80016148: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001614C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80016150: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80016154: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80016158: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001615C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80016160: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80016164: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80016168: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001616C: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x80016170: beql        $a2, $zero, L_800163B8
    if (ctx->r6 == 0) {
        // 0x80016174: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_800163B8;
    }
    goto skip_0;
    // 0x80016174: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    skip_0:
    // 0x80016178: lhu         $t6, 0x5E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X5E);
    // 0x8001617C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016180: addiu       $t8, $t8, -0x4534
    ctx->r24 = ADD32(ctx->r24, -0X4534);
    // 0x80016184: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016188: bne         $t7, $zero, L_80016274
    if (ctx->r15 != 0) {
        // 0x8001618C: lui         $s3, 0x8008
        ctx->r19 = S32(0X8008 << 16);
            goto L_80016274;
    }
    // 0x8001618C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80016190: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80016194: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80016198: jal         0x80018278
    // 0x8001619C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80018278(rdram, ctx);
        goto after_0;
    // 0x8001619C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800161A0: beq         $v0, $zero, L_800161B0
    if (ctx->r2 == 0) {
        // 0x800161A4: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800161B0;
    }
    // 0x800161A4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800161A8: b           L_800163B8
    // 0x800161AC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
        goto L_800163B8;
    // 0x800161AC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800161B0:
    // 0x800161B0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800161B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800161B8: lwc1        $f4, -0x4534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x800161BC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800161C0: lw          $t9, -0x44D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X44D0);
    // 0x800161C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800161C8: lwc1        $f8, -0x452C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x800161CC: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800161D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800161D4: lwc1        $f18, -0x4510($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x800161D8: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800161DC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800161E0: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800161E4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800161E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800161EC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800161F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800161F4: lwc1        $f10, -0x4530($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x800161F8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800161FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80016200: mul.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x80016204: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80016208: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001620C: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x80016210: sub.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d - ctx->f6.d;
    // 0x80016214: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80016218: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x8001621C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016220: nop

    // 0x80016224: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016228: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001622C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016230: jal         0x80034F60
    // 0x80016234: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80016234: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_1:
    // 0x80016238: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001623C: lw          $t0, -0x44D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X44D0);
    // 0x80016240: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016244: lwc1        $f16, -0x4510($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80016248: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8001624C: lw          $t1, 0x2C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X2C);
    // 0x80016250: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80016254: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80016258: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001625C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80016260: nop

    // 0x80016264: bc1fl       L_800163BC
    if (!c1cs) {
        // 0x80016268: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_800163BC;
    }
    goto skip_1;
    // 0x80016268: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x8001626C: b           L_800163B8
    // 0x80016270: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
        goto L_800163B8;
    // 0x80016270: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80016274:
    // 0x80016274: lw          $s3, -0x3670($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X3670);
    // 0x80016278: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001627C: addiu       $s2, $s2, -0x3668
    ctx->r18 = ADD32(ctx->r18, -0X3668);
    // 0x80016280: beq         $s3, $zero, L_8001639C
    if (ctx->r19 == 0) {
        // 0x80016284: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8001639C;
    }
    // 0x80016284: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80016288: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8001628C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80016290: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80016294: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80016298:
    // 0x80016298: lh          $t2, 0x74($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X74);
    // 0x8001629C: addiu       $s0, $s2, 0x24
    ctx->r16 = ADD32(ctx->r18, 0X24);
    // 0x800162A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800162A4: beq         $s4, $t2, L_80016394
    if (ctx->r20 == ctx->r10) {
        // 0x800162A8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80016394;
    }
    // 0x800162A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800162AC: jal         0x80018278
    // 0x800162B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    func_80018278(rdram, ctx);
        goto after_2;
    // 0x800162B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_2:
    // 0x800162B4: bnel        $v0, $zero, L_80016394
    if (ctx->r2 != 0) {
        // 0x800162B8: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80016394;
    }
    goto skip_2;
    // 0x800162B8: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_2:
    // 0x800162BC: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x800162C0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800162C4: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800162C8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800162CC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800162D0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800162D4: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800162D8: beq         $v0, $zero, L_800162F4
    if (ctx->r2 == 0) {
        // 0x800162DC: sub.s       $f14, $f16, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
            goto L_800162F4;
    }
    // 0x800162DC: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800162E0: beql        $v0, $s5, L_80016330
    if (ctx->r2 == ctx->r21) {
        // 0x800162E4: lw          $t3, 0x68($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X68);
            goto L_80016330;
    }
    goto skip_3;
    // 0x800162E4: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    skip_3:
    // 0x800162E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800162EC: b           L_80016348
    // 0x800162F0: nop

        goto L_80016348;
    // 0x800162F0: nop

L_800162F4:
    // 0x800162F4: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800162F8: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800162FC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80016300: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80016304: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80016308: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8001630C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80016310: mul.d       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80016314: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016318: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x8001631C: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80016320: mul.d       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x80016324: b           L_80016348
    // 0x80016328: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80016348;
    // 0x80016328: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8001632C: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
L_80016330:
    // 0x80016330: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80016334: lwc1        $f16, 0x94($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X94);
    // 0x80016338: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8001633C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80016340: mul.d       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x80016344: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_80016348:
    // 0x80016348: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001634C: nop

    // 0x80016350: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016354: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80016358: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001635C: jal         0x80034F60
    // 0x80016360: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_3;
    // 0x80016360: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_3:
    // 0x80016364: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80016368: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001636C: lw          $t5, 0x2C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X2C);
    // 0x80016370: lwc1        $f10, 0x18($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80016374: lwc1        $f16, 0x1C($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80016378: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001637C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80016380: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80016384: nop

    // 0x80016388: bc1t        L_8001639C
    if (c1cs) {
        // 0x8001638C: nop
    
            goto L_8001639C;
    }
    // 0x8001638C: nop

    // 0x80016390: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80016394:
    // 0x80016394: bne         $s3, $zero, L_80016298
    if (ctx->r19 != 0) {
        // 0x80016398: addiu       $s2, $s2, 0x128
        ctx->r18 = ADD32(ctx->r18, 0X128);
            goto L_80016298;
    }
    // 0x80016398: addiu       $s2, $s2, 0x128
    ctx->r18 = ADD32(ctx->r18, 0X128);
L_8001639C:
    // 0x8001639C: bne         $s3, $zero, L_800163AC
    if (ctx->r19 != 0) {
        // 0x800163A0: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_800163AC;
    }
    // 0x800163A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800163A4: b           L_800163B8
    // 0x800163A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
        goto L_800163B8;
    // 0x800163A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800163AC:
    // 0x800163AC: b           L_800163B8
    // 0x800163B0: sw          $s2, 0x71DC($at)
    MEM_W(0X71DC, ctx->r1) = ctx->r18;
        goto L_800163B8;
    // 0x800163B0: sw          $s2, 0x71DC($at)
    MEM_W(0X71DC, ctx->r1) = ctx->r18;
    // 0x800163B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800163B8:
    // 0x800163B8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800163BC:
    // 0x800163BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800163C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800163C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800163C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800163CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800163D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800163D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800163D8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800163DC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800163E0: jr          $ra
    // 0x800163E4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800163E4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800442C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800442C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800442C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800442C8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800442CC: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800442D0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800442D4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800442D8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800442DC: beq         $a3, $zero, L_80044314
    if (ctx->r7 == 0) {
        // 0x800442E0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80044314;
    }
    // 0x800442E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800442E4: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800442E8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800442EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800442F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800442F4: jal         0x80036820
    // 0x800442F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x800442F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800442FC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80044300: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80044304: jal         0x80036850
    // 0x80044308: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x80044308: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x8004430C: b           L_80044394
    // 0x80044310: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80044394;
    // 0x80044310: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80044314:
    // 0x80044314: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x80044318: beq         $a3, $zero, L_8004434C
    if (ctx->r7 == 0) {
        // 0x8004431C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8004434C;
    }
    // 0x8004431C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80044320: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80044324: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80044328: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8004432C: jal         0x80036820
    // 0x80044330: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80036820(rdram, ctx);
        goto after_2;
    // 0x80044330: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80044334: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80044338: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8004433C: jal         0x80036850
    // 0x80044340: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    func_80036850(rdram, ctx);
        goto after_3;
    // 0x80044340: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x80044344: b           L_80044394
    // 0x80044348: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80044394;
    // 0x80044348: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8004434C:
    // 0x8004434C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x80044350: beql        $a3, $zero, L_80044398
    if (ctx->r7 == 0) {
        // 0x80044354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044398;
    }
    goto skip_0;
    // 0x80044354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80044358: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_8004435C:
    // 0x8004435C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x80044360: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80044364: bnel        $at, $zero, L_8004438C
    if (ctx->r1 != 0) {
        // 0x80044368: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_8004438C;
    }
    goto skip_1;
    // 0x80044368: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x8004436C: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x80044370: bnel        $t1, $zero, L_8004438C
    if (ctx->r9 != 0) {
        // 0x80044374: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_8004438C;
    }
    goto skip_2;
    // 0x80044374: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x80044378: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8004437C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x80044380: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80044384: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x80044388: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_8004438C:
    // 0x8004438C: bnel        $a3, $zero, L_8004435C
    if (ctx->r7 != 0) {
        // 0x80044390: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_8004435C;
    }
    goto skip_3;
    // 0x80044390: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_80044394:
    // 0x80044394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044398:
    // 0x80044398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004439C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800443A0: jr          $ra
    // 0x800443A4: nop

    return;
    // 0x800443A4: nop

;}
RECOMP_FUNC void func_80041984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004198C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041990: beq         $a1, $v0, L_80041A30
    if (ctx->r5 == ctx->r2) {
        // 0x80041994: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80041A30;
    }
    // 0x80041994: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80041998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004199C: beq         $a1, $at, L_800419BC
    if (ctx->r5 == ctx->r1) {
        // 0x800419A0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800419BC;
    }
    // 0x800419A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800419A4: beq         $a1, $at, L_800419DC
    if (ctx->r5 == ctx->r1) {
        // 0x800419A8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800419DC;
    }
    // 0x800419A8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800419AC: beql        $a1, $at, L_80041A0C
    if (ctx->r5 == ctx->r1) {
        // 0x800419B0: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_80041A0C;
    }
    goto skip_0;
    // 0x800419B0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800419B4: b           L_80041A3C
    // 0x800419B8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_80041A3C;
    // 0x800419B8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800419BC:
    // 0x800419BC: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x800419C0: beql        $v0, $zero, L_800419D4
    if (ctx->r2 == 0) {
        // 0x800419C4: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_800419D4;
    }
    goto skip_1;
    // 0x800419C4: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x800419C8: b           L_800419D4
    // 0x800419CC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800419D4;
    // 0x800419CC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800419D0: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_800419D4:
    // 0x800419D4: b           L_80041A50
    // 0x800419D8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_80041A50;
    // 0x800419D8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_800419DC:
    // 0x800419DC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800419E0: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x800419E4: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x800419E8: beq         $a0, $zero, L_80041A50
    if (ctx->r4 == 0) {
        // 0x800419EC: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_80041A50;
    }
    // 0x800419EC: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x800419F0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800419F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800419F8: jalr        $t9
    // 0x800419FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800419FC: nop

    after_0:
    // 0x80041A00: b           L_80041A54
    // 0x80041A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80041A54;
    // 0x80041A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041A08: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80041A0C:
    // 0x80041A0C: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x80041A10: beql        $a0, $zero, L_80041A54
    if (ctx->r4 == 0) {
        // 0x80041A14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80041A54;
    }
    goto skip_2;
    // 0x80041A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80041A18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80041A1C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80041A20: jalr        $t9
    // 0x80041A24: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80041A24: nop

    after_1:
    // 0x80041A28: b           L_80041A54
    // 0x80041A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80041A54;
    // 0x80041A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80041A30:
    // 0x80041A30: b           L_80041A50
    // 0x80041A34: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_80041A50;
    // 0x80041A34: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80041A38: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80041A3C:
    // 0x80041A3C: beql        $a0, $zero, L_80041A54
    if (ctx->r4 == 0) {
        // 0x80041A40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80041A54;
    }
    goto skip_3;
    // 0x80041A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80041A44: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80041A48: jalr        $t9
    // 0x80041A4C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80041A4C: nop

    after_2:
L_80041A50:
    // 0x80041A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80041A54:
    // 0x80041A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041A5C: jr          $ra
    // 0x80041A60: nop

    return;
    // 0x80041A60: nop

;}
RECOMP_FUNC void guTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036198: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8003619C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800361A0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800361A4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800361A8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800361AC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800361B0: jal         0x80035300
    // 0x800361B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800361B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800361B8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800361BC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800361C0: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800361C4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800361C8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800361CC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800361D0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800361D4: jal         0x80035200
    // 0x800361D8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800361D8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800361DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800361E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800361E4: jr          $ra
    // 0x800361E8: nop

    return;
    // 0x800361E8: nop

    // 0x800361EC: nop

;}
RECOMP_FUNC void func_80017BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017BD4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80017BD8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80017BDC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80017BE0: addiu       $t0, $t0, 0x71D0
    ctx->r8 = ADD32(ctx->r8, 0X71D0);
    // 0x80017BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80017BE8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80017BEC: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80017BF0: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80017BF4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80017BF8: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80017BFC: lh          $t6, 0x10($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X10);
    // 0x80017C00: addiu       $t8, $t8, 0x1B90
    ctx->r24 = ADD32(ctx->r24, 0X1B90);
    // 0x80017C04: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80017C08: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80017C0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017C10: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017C14: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x80017C18: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80017C1C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80017C20: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80017C24: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80017C28: lhu         $t9, 0x14($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X14);
    // 0x80017C2C: andi        $t3, $t9, 0x10
    ctx->r11 = ctx->r25 & 0X10;
    // 0x80017C30: beq         $t3, $zero, L_80017C84
    if (ctx->r11 == 0) {
        // 0x80017C34: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_80017C84;
    }
    // 0x80017C34: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80017C38: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x80017C3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80017C40: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80017C44: bgez        $t4, L_80017C5C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80017C48: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_80017C5C;
    }
    // 0x80017C48: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80017C4C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017C50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017C54: nop

    // 0x80017C58: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_80017C5C:
    // 0x80017C5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017C60: ldc1        $f4, 0x1500($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1500);
    // 0x80017C64: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80017C68: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80017C6C: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80017C70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017C74: nop

    // 0x80017C78: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80017C7C: b           L_80017C88
    // 0x80017C80: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80017C88;
    // 0x80017C80: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80017C84:
    // 0x80017C84: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
L_80017C88:
    // 0x80017C88: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80017C8C: lhu         $a0, 0x12($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X12);
    // 0x80017C90: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80017C94: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x80017C98: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80017C9C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80017CA0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80017CA4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80017CA8: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80017CAC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80017CB0: lhu         $a1, 0x3A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3A);
    // 0x80017CB4: jal         0x800177F8
    // 0x80017CB8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x80017CB8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x80017CBC: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80017CC0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80017CC4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80017CC8: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80017CCC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80017CD0: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80017CD4: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80017CD8: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80017CDC: lb          $a1, 0x46($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X46);
    // 0x80017CE0: bltzl       $a1, L_80017CF4
    if (SIGNED(ctx->r5) < 0) {
        // 0x80017CE4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80017CF4;
    }
    goto skip_0;
    // 0x80017CE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80017CE8: jal         0x800268D4
    // 0x80017CEC: lbu         $a0, 0x47($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X47);
    func_800268D4(rdram, ctx);
        goto after_1;
    // 0x80017CEC: lbu         $a0, 0x47($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X47);
    after_1:
    // 0x80017CF0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80017CF4:
    // 0x80017CF4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80017CF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80017CFC: jr          $ra
    // 0x80017D00: nop

    return;
    // 0x80017D00: nop

;}
RECOMP_FUNC void func_80016BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016BF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016BF8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80016BFC: lhu         $t6, 0x5E($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X5E);
    // 0x80016C00: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80016C04: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016C08: beql        $t7, $zero, L_80016C84
    if (ctx->r15 == 0) {
        // 0x80016C0C: lw          $t7, 0x64($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X64);
            goto L_80016C84;
    }
    goto skip_0;
    // 0x80016C0C: lw          $t7, 0x64($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X64);
    skip_0:
    // 0x80016C10: lhu         $t8, -0x3A6E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3A6E);
    // 0x80016C14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80016C18: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80016C1C: bne         $t9, $zero, L_80016C70
    if (ctx->r25 != 0) {
        // 0x80016C20: nop
    
            goto L_80016C70;
    }
    // 0x80016C20: nop

    // 0x80016C24: jal         0x800202E4
    // 0x80016C28: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800202E4(rdram, ctx);
        goto after_0;
    // 0x80016C28: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80016C2C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C30: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016C34: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80016C38: lhu         $t1, 0x60($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X60);
    // 0x80016C3C: addiu       $v1, $v1, -0x3670
    ctx->r3 = ADD32(ctx->r3, -0X3670);
    // 0x80016C40: sh          $t0, 0x50($a3)
    MEM_H(0X50, ctx->r7) = ctx->r8;
    // 0x80016C44: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80016C48: sh          $t2, 0x60($a3)
    MEM_H(0X60, ctx->r7) = ctx->r10;
    // 0x80016C4C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80016C50: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016C54: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80016C58: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80016C5C: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x80016C60: lhu         $t5, 0x2A($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2A);
    // 0x80016C64: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80016C68: b           L_80016CA0
    // 0x80016C6C: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
        goto L_80016CA0;
    // 0x80016C6C: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
L_80016C70:
    // 0x80016C70: jal         0x800208B8
    // 0x80016C74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800208B8(rdram, ctx);
        goto after_1;
    // 0x80016C74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80016C78: b           L_80016CA4
    // 0x80016C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80016CA4;
    // 0x80016C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016C80: lw          $t7, 0x64($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X64);
L_80016C84:
    // 0x80016C84: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80016C88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80016C8C: lhu         $a0, 0x4($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X4);
    // 0x80016C90: lw          $a2, 0x24($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X24);
    // 0x80016C94: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80016C98: jal         0x80006BEC
    // 0x80016C9C: andi        $a0, $t8, 0xFFFF
    ctx->r4 = ctx->r24 & 0XFFFF;
    func_80006BEC(rdram, ctx);
        goto after_2;
    // 0x80016C9C: andi        $a0, $t8, 0xFFFF
    ctx->r4 = ctx->r24 & 0XFFFF;
    after_2:
L_80016CA0:
    // 0x80016CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016CA4:
    // 0x80016CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016CA8: jr          $ra
    // 0x80016CAC: nop

    return;
    // 0x80016CAC: nop

;}
RECOMP_FUNC void func_80026D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026D1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80026D20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026D24: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80026D28: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
    // 0x80026D2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026D30: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80026D34: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80026D38: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80026D3C: andi        $t6, $a0, 0x1000
    ctx->r14 = ctx->r4 & 0X1000;
    // 0x80026D40: beq         $t6, $zero, L_80026D80
    if (ctx->r14 == 0) {
        // 0x80026D44: addiu       $a1, $v0, -0x2FC
        ctx->r5 = ADD32(ctx->r2, -0X2FC);
            goto L_80026D80;
    }
    // 0x80026D44: addiu       $a1, $v0, -0x2FC
    ctx->r5 = ADD32(ctx->r2, -0X2FC);
    // 0x80026D48: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80026D4C: addiu       $a2, $v0, -0x2FC
    ctx->r6 = ADD32(ctx->r2, -0X2FC);
    // 0x80026D50: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80026D54: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026D58: addiu       $a1, $v1, -0x2F8
    ctx->r5 = ADD32(ctx->r3, -0X2F8);
    // 0x80026D5C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80026D60: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80026D64: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80026D68: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80026D6C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80026D70: bne         $t0, $zero, L_80026DAC
    if (ctx->r8 != 0) {
        // 0x80026D74: sw          $t0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r8;
            goto L_80026DAC;
    }
    // 0x80026D74: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80026D78: b           L_80026DAC
    // 0x80026D7C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
        goto L_80026DAC;
    // 0x80026D7C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80026D80:
    // 0x80026D80: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80026D84: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026D88: addiu       $a2, $v1, -0x2F8
    ctx->r6 = ADD32(ctx->r3, -0X2F8);
    // 0x80026D8C: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x80026D90: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80026D94: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80026D98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80026D9C: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x80026DA0: bne         $t4, $zero, L_80026DAC
    if (ctx->r12 != 0) {
        // 0x80026DA4: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_80026DAC;
    }
    // 0x80026DA4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80026DA8: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_80026DAC:
    // 0x80026DAC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80026DB0: beq         $v0, $zero, L_80026DD8
    if (ctx->r2 == 0) {
        // 0x80026DB4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80026DD8;
    }
    // 0x80026DB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026DB8: beq         $v0, $at, L_80026E1C
    if (ctx->r2 == ctx->r1) {
        // 0x80026DBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80026E1C;
    }
    // 0x80026DBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80026DC0: beq         $v0, $at, L_80026E60
    if (ctx->r2 == ctx->r1) {
        // 0x80026DC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80026E60;
    }
    // 0x80026DC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80026DC8: beql        $v0, $at, L_80026EA8
    if (ctx->r2 == ctx->r1) {
        // 0x80026DCC: lw          $a0, 0x0($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X0);
            goto L_80026EA8;
    }
    goto skip_0;
    // 0x80026DCC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x80026DD0: b           L_80026EE8
    // 0x80026DD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
        goto L_80026EE8;
    // 0x80026DD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80026DD8:
    // 0x80026DD8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80026DDC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80026DE0: jal         0x80026F34
    // 0x80026DE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80026F34(rdram, ctx);
        goto after_0;
    // 0x80026DE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80026DE8: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    // 0x80026DEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026DF0: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x80026DF4: beq         $t0, $zero, L_80026E0C
    if (ctx->r8 == 0) {
        // 0x80026DF8: nop
    
            goto L_80026E0C;
    }
    // 0x80026DF8: nop

    // 0x80026DFC: jal         0x80029448
    // 0x80026E00: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80029448(rdram, ctx);
        goto after_1;
    // 0x80026E00: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_1:
    // 0x80026E04: b           L_80026E14
    // 0x80026E08: nop

        goto L_80026E14;
    // 0x80026E08: nop

L_80026E0C:
    // 0x80026E0C: jal         0x800278B0
    // 0x80026E10: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_800278B0(rdram, ctx);
        goto after_2;
    // 0x80026E10: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_2:
L_80026E14:
    // 0x80026E14: b           L_80026EE4
    // 0x80026E18: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80026EE4;
    // 0x80026E18: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80026E1C:
    // 0x80026E1C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80026E20: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80026E24: jal         0x800278B0
    // 0x80026E28: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800278B0(rdram, ctx);
        goto after_3;
    // 0x80026E28: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80026E2C: lhu         $t1, 0x0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X0);
    // 0x80026E30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026E34: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x80026E38: beq         $t2, $zero, L_80026E50
    if (ctx->r10 == 0) {
        // 0x80026E3C: nop
    
            goto L_80026E50;
    }
    // 0x80026E3C: nop

    // 0x80026E40: jal         0x80026F34
    // 0x80026E44: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80026F34(rdram, ctx);
        goto after_4;
    // 0x80026E44: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_4:
    // 0x80026E48: b           L_80026E58
    // 0x80026E4C: nop

        goto L_80026E58;
    // 0x80026E4C: nop

L_80026E50:
    // 0x80026E50: jal         0x80028624
    // 0x80026E54: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80028624(rdram, ctx);
        goto after_5;
    // 0x80026E54: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_5:
L_80026E58:
    // 0x80026E58: b           L_80026EE4
    // 0x80026E5C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80026EE4;
    // 0x80026E5C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80026E60:
    // 0x80026E60: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80026E64: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80026E68: jal         0x80028624
    // 0x80026E6C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80028624(rdram, ctx);
        goto after_6;
    // 0x80026E6C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x80026E70: lhu         $t3, 0x0($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X0);
    // 0x80026E74: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026E78: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x80026E7C: beq         $t4, $zero, L_80026E94
    if (ctx->r12 == 0) {
        // 0x80026E80: nop
    
            goto L_80026E94;
    }
    // 0x80026E80: nop

    // 0x80026E84: jal         0x800278B0
    // 0x80026E88: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_800278B0(rdram, ctx);
        goto after_7;
    // 0x80026E88: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_7:
    // 0x80026E8C: b           L_80026E9C
    // 0x80026E90: nop

        goto L_80026E9C;
    // 0x80026E90: nop

L_80026E94:
    // 0x80026E94: jal         0x80029448
    // 0x80026E98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80029448(rdram, ctx);
        goto after_8;
    // 0x80026E98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_8:
L_80026E9C:
    // 0x80026E9C: b           L_80026EE4
    // 0x80026EA0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80026EE4;
    // 0x80026EA0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80026EA4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
L_80026EA8:
    // 0x80026EA8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80026EAC: jal         0x80029448
    // 0x80026EB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80029448(rdram, ctx);
        goto after_9;
    // 0x80026EB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_9:
    // 0x80026EB4: lhu         $t5, 0x0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X0);
    // 0x80026EB8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026EBC: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x80026EC0: beq         $t6, $zero, L_80026ED8
    if (ctx->r14 == 0) {
        // 0x80026EC4: nop
    
            goto L_80026ED8;
    }
    // 0x80026EC4: nop

    // 0x80026EC8: jal         0x80028624
    // 0x80026ECC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80028624(rdram, ctx);
        goto after_10;
    // 0x80026ECC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_10:
    // 0x80026ED0: b           L_80026EE4
    // 0x80026ED4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80026EE4;
    // 0x80026ED4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80026ED8:
    // 0x80026ED8: jal         0x80026F34
    // 0x80026EDC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80026F34(rdram, ctx);
        goto after_11;
    // 0x80026EDC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_11:
    // 0x80026EE0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80026EE4:
    // 0x80026EE4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80026EE8:
    // 0x80026EE8: beql        $t7, $zero, L_80026F24
    if (ctx->r15 == 0) {
        // 0x80026EEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026F24;
    }
    goto skip_1;
    // 0x80026EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80026EF0: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x80026EF4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80026EF8: andi        $t0, $t8, 0xDFFF
    ctx->r8 = ctx->r24 & 0XDFFF;
    // 0x80026EFC: andi        $t3, $t0, 0xEFFF
    ctx->r11 = ctx->r8 & 0XEFFF;
    // 0x80026F00: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80026F04: andi        $t5, $t3, 0xFFFC
    ctx->r13 = ctx->r11 & 0XFFFC;
    // 0x80026F08: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80026F0C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x80026F10: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80026F14: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x80026F18: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80026F1C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80026F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026F24:
    // 0x80026F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026F28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80026F2C: jr          $ra
    // 0x80026F30: nop

    return;
    // 0x80026F30: nop

;}
RECOMP_FUNC void func_8000EB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EB30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000EB34: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000EB38: addiu       $v0, $v0, -0x3C08
    ctx->r2 = ADD32(ctx->r2, -0X3C08);
    // 0x8000EB3C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8000EB40: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8000EB44: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8000EB48: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8000EB4C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8000EB50: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x8000EB54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000EB58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EB5C: beq         $v1, $t6, L_8000EBA8
    if (ctx->r3 == ctx->r14) {
        // 0x8000EB60: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_8000EBA8;
    }
    // 0x8000EB60: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8000EB64: lw          $v0, 0x59D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59D0);
    // 0x8000EB68: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
L_8000EB6C:
    // 0x8000EB6C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000EB70: bnel        $at, $zero, L_8000EB9C
    if (ctx->r1 != 0) {
        // 0x8000EB74: lhu         $t9, 0xE($a1)
        ctx->r25 = MEM_HU(ctx->r5, 0XE);
            goto L_8000EB9C;
    }
    goto skip_0;
    // 0x8000EB74: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    skip_0:
    // 0x8000EB78: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8000EB7C: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000EB80: beql        $at, $zero, L_8000EB9C
    if (ctx->r1 == 0) {
        // 0x8000EB84: lhu         $t9, 0xE($a1)
        ctx->r25 = MEM_HU(ctx->r5, 0XE);
            goto L_8000EB9C;
    }
    goto skip_1;
    // 0x8000EB84: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    skip_1:
    // 0x8000EB88: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    // 0x8000EB8C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EB90: b           L_8000EBA8
    // 0x8000EB94: sw          $a0, -0x3C14($at)
    MEM_W(-0X3C14, ctx->r1) = ctx->r4;
        goto L_8000EBA8;
    // 0x8000EB94: sw          $a0, -0x3C14($at)
    MEM_W(-0X3C14, ctx->r1) = ctx->r4;
    // 0x8000EB98: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
L_8000EB9C:
    // 0x8000EB9C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8000EBA0: bnel        $v1, $t9, L_8000EB6C
    if (ctx->r3 != ctx->r25) {
        // 0x8000EBA4: lw          $t7, 0x0($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X0);
            goto L_8000EB6C;
    }
    goto skip_2;
    // 0x8000EBA4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    skip_2:
L_8000EBA8:
    // 0x8000EBA8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000EBAC: lw          $a0, -0x3C14($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3C14);
    // 0x8000EBB0: lw          $a2, -0x3C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3C0C);
    // 0x8000EBB4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000EBB8: addiu       $a3, $a3, 0x20D8
    ctx->r7 = ADD32(ctx->r7, 0X20D8);
    // 0x8000EBBC: beq         $a0, $a2, L_8000EC08
    if (ctx->r4 == ctx->r6) {
        // 0x8000EBC0: lui         $v0, 0x8005
        ctx->r2 = S32(0X8005 << 16);
            goto L_8000EC08;
    }
    // 0x8000EBC0: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000EBC4: sll         $t7, $a2, 9
    ctx->r15 = S32(ctx->r6 << 9);
    // 0x8000EBC8: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8000EBCC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EBD0: sw          $t8, 0x3C88($at)
    MEM_W(0X3C88, ctx->r1) = ctx->r24;
    // 0x8000EBD4: sll         $t6, $a0, 9
    ctx->r14 = S32(ctx->r4 << 9);
    // 0x8000EBD8: lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X4);
    // 0x8000EBDC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8000EBE0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EBE4: sw          $t7, 0x4090($at)
    MEM_W(0X4090, ctx->r1) = ctx->r15;
    // 0x8000EBE8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000EBEC: addiu       $t8, $t8, 0x1CD8
    ctx->r24 = ADD32(ctx->r24, 0X1CD8);
    // 0x8000EBF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EBF4: sw          $t8, 0x4178($at)
    MEM_W(0X4178, ctx->r1) = ctx->r24;
    // 0x8000EBF8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EBFC: sw          $v1, -0x3C10($at)
    MEM_W(-0X3C10, ctx->r1) = ctx->r3;
    // 0x8000EC00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EC04: sw          $v1, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r3;
L_8000EC08:
    // 0x8000EC08: lw          $v0, -0x3C10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3C10);
    // 0x8000EC0C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000EC10: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x8000EC14: beq         $v0, $zero, L_8000EDAC
    if (ctx->r2 == 0) {
        // 0x8000EC18: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_8000EDAC;
    }
    // 0x8000EC18: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000EC1C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000EC20: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000EC24: lw          $a1, 0x4178($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4178);
    // 0x8000EC28: lw          $a2, 0x3C88($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3C88);
    // 0x8000EC2C: lw          $a3, 0x4090($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4090);
    // 0x8000EC30: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8000EC34: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_8000EC38:
    // 0x8000EC38: lhu         $t1, 0x0($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X0);
    // 0x8000EC3C: lhu         $s1, 0x0($a3)
    ctx->r17 = MEM_HU(ctx->r7, 0X0);
    // 0x8000EC40: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000EC44: andi        $t3, $t1, 0xF800
    ctx->r11 = ctx->r9 & 0XF800;
    // 0x8000EC48: sra         $t9, $t3, 11
    ctx->r25 = S32(SIGNED(ctx->r11) >> 11);
    // 0x8000EC4C: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x8000EC50: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EC54: andi        $t5, $t1, 0x3E
    ctx->r13 = ctx->r9 & 0X3E;
    // 0x8000EC58: sra         $t9, $t5, 1
    ctx->r25 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8000EC5C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8000EC60: andi        $s2, $s1, 0x7C0
    ctx->r18 = ctx->r17 & 0X7C0;
    // 0x8000EC64: sra         $t9, $s2, 6
    ctx->r25 = S32(SIGNED(ctx->r18) >> 6);
    // 0x8000EC68: andi        $t4, $t1, 0x7C0
    ctx->r12 = ctx->r9 & 0X7C0;
    // 0x8000EC6C: sra         $t7, $t4, 6
    ctx->r15 = S32(SIGNED(ctx->r12) >> 6);
    // 0x8000EC70: andi        $s2, $t9, 0xFFFF
    ctx->r18 = ctx->r25 & 0XFFFF;
    // 0x8000EC74: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x8000EC78: mflo        $t9
    ctx->r25 = lo;
    // 0x8000EC7C: andi        $s0, $s1, 0xF800
    ctx->r16 = ctx->r17 & 0XF800;
    // 0x8000EC80: sra         $t7, $s0, 11
    ctx->r15 = S32(SIGNED(ctx->r16) >> 11);
    // 0x8000EC84: andi        $s0, $t7, 0xFFFF
    ctx->r16 = ctx->r15 & 0XFFFF;
    // 0x8000EC88: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EC8C: andi        $s3, $s1, 0x3E
    ctx->r19 = ctx->r17 & 0X3E;
    // 0x8000EC90: sra         $t7, $s3, 1
    ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
    // 0x8000EC94: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000EC98: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x8000EC9C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x8000ECA0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8000ECA4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8000ECA8: mflo        $t6
    ctx->r14 = lo;
    // 0x8000ECAC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8000ECB0: nop

    // 0x8000ECB4: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x8000ECB8: mflo        $t8
    ctx->r24 = lo;
    // 0x8000ECBC: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x8000ECC0: bne         $v1, $zero, L_8000ECCC
    if (ctx->r3 != 0) {
        // 0x8000ECC4: nop
    
            goto L_8000ECCC;
    }
    // 0x8000ECC4: nop

    // 0x8000ECC8: break       7
    do_break(2147544264);
L_8000ECCC:
    // 0x8000ECCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000ECD0: bne         $v1, $at, L_8000ECE4
    if (ctx->r3 != ctx->r1) {
        // 0x8000ECD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000ECE4;
    }
    // 0x8000ECD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000ECD8: bne         $t7, $at, L_8000ECE4
    if (ctx->r15 != ctx->r1) {
        // 0x8000ECDC: nop
    
            goto L_8000ECE4;
    }
    // 0x8000ECDC: nop

    // 0x8000ECE0: break       6
    do_break(2147544288);
L_8000ECE4:
    // 0x8000ECE4: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ECE8: mflo        $t6
    ctx->r14 = lo;
    // 0x8000ECEC: nop

    // 0x8000ECF0: nop

    // 0x8000ECF4: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ECF8: mflo        $t7
    ctx->r15 = lo;
    // 0x8000ECFC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000ED00: nop

    // 0x8000ED04: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x8000ED08: mflo        $t6
    ctx->r14 = lo;
    // 0x8000ED0C: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8000ED10: bne         $v1, $zero, L_8000ED1C
    if (ctx->r3 != 0) {
        // 0x8000ED14: nop
    
            goto L_8000ED1C;
    }
    // 0x8000ED14: nop

    // 0x8000ED18: break       7
    do_break(2147544344);
L_8000ED1C:
    // 0x8000ED1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000ED20: bne         $v1, $at, L_8000ED34
    if (ctx->r3 != ctx->r1) {
        // 0x8000ED24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000ED34;
    }
    // 0x8000ED24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000ED28: bne         $t8, $at, L_8000ED34
    if (ctx->r24 != ctx->r1) {
        // 0x8000ED2C: nop
    
            goto L_8000ED34;
    }
    // 0x8000ED2C: nop

    // 0x8000ED30: break       6
    do_break(2147544368);
L_8000ED34:
    // 0x8000ED34: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED38: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8000ED3C: mflo        $t6
    ctx->r14 = lo;
    // 0x8000ED40: nop

    // 0x8000ED44: nop

    // 0x8000ED48: multu       $s3, $t0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000ED4C: mflo        $t9
    ctx->r25 = lo;
    // 0x8000ED50: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8000ED54: nop

    // 0x8000ED58: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x8000ED5C: mflo        $t6
    ctx->r14 = lo;
    // 0x8000ED60: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8000ED64: bne         $v1, $zero, L_8000ED70
    if (ctx->r3 != 0) {
        // 0x8000ED68: nop
    
            goto L_8000ED70;
    }
    // 0x8000ED68: nop

    // 0x8000ED6C: break       7
    do_break(2147544428);
L_8000ED70:
    // 0x8000ED70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000ED74: bne         $v1, $at, L_8000ED88
    if (ctx->r3 != ctx->r1) {
        // 0x8000ED78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000ED88;
    }
    // 0x8000ED78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000ED7C: bne         $t7, $at, L_8000ED88
    if (ctx->r15 != ctx->r1) {
        // 0x8000ED80: nop
    
            goto L_8000ED88;
    }
    // 0x8000ED80: nop

    // 0x8000ED84: break       6
    do_break(2147544452);
L_8000ED88:
    // 0x8000ED88: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8000ED8C: sh          $t7, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r15;
    // 0x8000ED90: bne         $t2, $zero, L_8000EC38
    if (ctx->r10 != 0) {
        // 0x8000ED94: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_8000EC38;
    }
    // 0x8000ED94: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x8000ED98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000ED9C: sw          $v1, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r3;
    // 0x8000EDA0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EDA4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8000EDA8: sw          $v0, -0x3C10($at)
    MEM_W(-0X3C10, ctx->r1) = ctx->r2;
L_8000EDAC:
    // 0x8000EDAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000EDB0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EDB4: sw          $a0, -0x3C14($at)
    MEM_W(-0X3C14, ctx->r1) = ctx->r4;
    // 0x8000EDB8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EDBC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8000EDC0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8000EDC4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8000EDC8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8000EDCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000EDD0: jr          $ra
    // 0x8000EDD4: sw          $a2, -0x3C0C($at)
    MEM_W(-0X3C0C, ctx->r1) = ctx->r6;
    return;
    // 0x8000EDD4: sw          $a2, -0x3C0C($at)
    MEM_W(-0X3C0C, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void func_80049730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049730: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80049734: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80049738: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x8004973C: sh          $t7, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r15;
    // 0x80049740: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80049744: jr          $ra
    // 0x80049748: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    return;
    // 0x80049748: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_801051B4_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801051B4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x801051B8: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x801051BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801051C0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801051C4: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x801051C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801051CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801051D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801051D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801051D8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801051DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801051E0: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x801051E4: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x801051E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801051EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801051F0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x801051F4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801051F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801051FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105200: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x80105204: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80105208: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010520C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105210: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80105214: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x80105218: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010521C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105220: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105224: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80105228: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8010522C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105230: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105234: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80105238: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x8010523C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105240: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105244: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105248: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8010524C: addiu       $t8, $t8, -0x3148
    ctx->r24 = ADD32(ctx->r24, -0X3148);
    // 0x80105250: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105254: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105258: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8010525C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105260: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105264: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105268: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8010526C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80105270: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105274: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105278: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010527C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105280: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105284: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80105288: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8010528C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105290: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105294: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105298: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010529C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052A0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x801052A4: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x801052A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801052AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801052B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801052B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801052B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052BC: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x801052C0: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x801052C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801052C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801052CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801052D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801052D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052D8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801052DC: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x801052E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801052E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801052E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801052EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801052F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052F4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801052F8: addiu       $t7, $t7, -0x4388
    ctx->r15 = ADD32(ctx->r15, -0X4388);
    // 0x801052FC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105300: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105304: ori         $t6, $t6, 0x57
    ctx->r14 = ctx->r14 | 0X57;
    // 0x80105308: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010530C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105310: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105314: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x80105318: ori         $t9, $t9, 0x1600
    ctx->r25 = ctx->r25 | 0X1600;
    // 0x8010531C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105320: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105324: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80105328: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010532C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105330: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105334: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80105338: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8010533C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105340: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105344: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105348: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010534C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105350: lui         $t7, 0x716
    ctx->r15 = S32(0X716 << 16);
    // 0x80105354: ori         $t7, $t7, 0x34
    ctx->r15 = ctx->r15 | 0X34;
    // 0x80105358: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010535C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105360: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105364: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105368: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010536C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80105370: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x80105374: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105378: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8010537C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105380: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105384: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105388: ori         $t7, $t7, 0x1600
    ctx->r15 = ctx->r15 | 0X1600;
    // 0x8010538C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80105390: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105394: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105398: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010539C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801053A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801053A4: lui         $t6, 0x2C
    ctx->r14 = S32(0X2C << 16);
    // 0x801053A8: ori         $t6, $t6, 0x34
    ctx->r14 = ctx->r14 | 0X34;
    // 0x801053AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801053B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801053B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801053B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801053BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801053C0: lui         $t9, 0x12
    ctx->r25 = S32(0X12 << 16);
    // 0x801053C4: lui         $t8, 0xE43E
    ctx->r24 = S32(0XE43E << 16);
    // 0x801053C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801053CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801053D0: ori         $t8, $t8, 0x1FC
    ctx->r24 = ctx->r24 | 0X1FC;
    // 0x801053D4: ori         $t9, $t9, 0x1C8
    ctx->r25 = ctx->r25 | 0X1C8;
    // 0x801053D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801053DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801053E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801053E4: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x801053E8: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x801053EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801053F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801053F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801053F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801053FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105400: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80105404: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80105408: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010540C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105410: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105414: jr          $ra
    // 0x80105418: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    return;
    // 0x80105418: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_800212E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800212E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800212E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800212EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800212F0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800212F4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800212F8: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x800212FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80021300: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80021304: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80021308: beq         $t6, $zero, L_8002133C
    if (ctx->r14 == 0) {
        // 0x8002130C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8002133C;
    }
    // 0x8002130C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80021310: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021314: lui         $a3, 0x803B
    ctx->r7 = S32(0X803B << 16);
    // 0x80021318: addiu       $a3, $a3, -0x6E10
    ctx->r7 = ADD32(ctx->r7, -0X6E10);
    // 0x8002131C: mflo        $t7
    ctx->r15 = lo;
    // 0x80021320: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80021324: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80021328: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x8002132C: beq         $t1, $zero, L_8002133C
    if (ctx->r9 == 0) {
        // 0x80021330: nop
    
            goto L_8002133C;
    }
    // 0x80021330: nop

    // 0x80021334: b           L_8002136C
    // 0x80021338: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002136C;
    // 0x80021338: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002133C:
    // 0x8002133C: lui         $a3, 0x803B
    ctx->r7 = S32(0X803B << 16);
    // 0x80021340: addiu       $a3, $a3, -0x6E10
    ctx->r7 = ADD32(ctx->r7, -0X6E10);
    // 0x80021344: bne         $v0, $zero, L_8002136C
    if (ctx->r2 != 0) {
        // 0x80021348: addiu       $t0, $zero, 0xC
        ctx->r8 = ADD32(0, 0XC);
            goto L_8002136C;
    }
    // 0x80021348: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8002134C: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021350: mflo        $t2
    ctx->r10 = lo;
    // 0x80021354: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x80021358: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8002135C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80021360: beq         $t5, $zero, L_8002136C
    if (ctx->r13 == 0) {
        // 0x80021364: nop
    
            goto L_8002136C;
    }
    // 0x80021364: nop

    // 0x80021368: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002136C:
    // 0x8002136C: beq         $v1, $zero, L_800213B0
    if (ctx->r3 == 0) {
        // 0x80021370: nop
    
            goto L_800213B0;
    }
    // 0x80021370: nop

    // 0x80021374: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021378: sb          $a2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r6;
    // 0x8002137C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80021380: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80021384: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80021388: mflo        $t6
    ctx->r14 = lo;
    // 0x8002138C: addu        $a1, $a3, $t6
    ctx->r5 = ADD32(ctx->r7, ctx->r14);
    // 0x80021390: lhu         $t7, 0x2($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X2);
    // 0x80021394: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80021398: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002139C: lw          $t9, -0x2B80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2B80);
    // 0x800213A0: jalr        $t9
    // 0x800213A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800213A4: nop

    after_0:
    // 0x800213A8: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x800213AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800213B0:
    // 0x800213B0: beq         $v1, $zero, L_800213C4
    if (ctx->r3 == 0) {
        // 0x800213B4: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_800213C4;
    }
    // 0x800213B4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800213B8: jal         0x8000669C
    // 0x800213BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8000669C(rdram, ctx);
        goto after_1;
    // 0x800213BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x800213C0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800213C4:
    // 0x800213C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800213C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800213CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800213D0: jr          $ra
    // 0x800213D4: nop

    return;
    // 0x800213D4: nop

;}
RECOMP_FUNC void guPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035120: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035124: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80035128: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8003512C: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80035130: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035134: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035138: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8003513C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80035140: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80035144: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80035148: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8003514C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80035150: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80035154: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80035158: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8003515C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80035160: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80035164: jal         0x80034F70
    // 0x80035168: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guPositionF(rdram, ctx);
        goto after_0;
    // 0x80035168: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8003516C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80035170: jal         0x80035200
    // 0x80035174: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80035174: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80035178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003517C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80035180: jr          $ra
    // 0x80035184: nop

    return;
    // 0x80035184: nop

;}
RECOMP_FUNC void func_80014E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014E80: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80014E84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014E88: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80014E8C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80014E90: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80014E94: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80014E98: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80014E9C: bnel        $t6, $at, L_80014EC8
    if (ctx->r14 != ctx->r1) {
        // 0x80014EA0: lwc1        $f6, 0x4($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
            goto L_80014EC8;
    }
    goto skip_0;
    // 0x80014EA0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80014EA4: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80014EA8: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80014EAC: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x80014EB0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80014EB4: lwc1        $f18, 0x94($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X94);
    // 0x80014EB8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80014EBC: jr          $ra
    // 0x80014EC0: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80014EC0: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80014EC4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
L_80014EC8:
    // 0x80014EC8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80014ECC: jr          $ra
    // 0x80014ED0: nop

    return;
    // 0x80014ED0: nop

;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800402AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800402B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800402B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800402B8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800402BC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800402C0: addiu       $a2, $a2, 0x1984
    ctx->r6 = ADD32(ctx->r6, 0X1984);
    // 0x800402C4: addiu       $a1, $a1, 0x1F7C
    ctx->r5 = ADD32(ctx->r5, 0X1F7C);
    // 0x800402C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800402CC: jal         0x80048AC0
    // 0x800402D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800402D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800402D4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800402D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800402DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800402E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800402E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800402E8: jal         0x80036660
    // 0x800402EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800402EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800402F0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800402F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800402F8: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800402FC: sw          $v1, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r3;
    // 0x80040300: sw          $zero, 0x48($t0)
    MEM_W(0X48, ctx->r8) = 0;
    // 0x80040304: sh          $v1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r3;
    // 0x80040308: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x8004030C: sh          $v1, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r3;
    // 0x80040310: sh          $v1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r3;
    // 0x80040314: sh          $v1, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r3;
    // 0x80040318: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x8004031C: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x80040320: sh          $v1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r3;
    // 0x80040324: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x80040328: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x8004032C: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x80040330: sh          $zero, 0x18($t0)
    MEM_H(0X18, ctx->r8) = 0;
    // 0x80040334: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x80040338: sw          $zero, 0x40($t0)
    MEM_W(0X40, ctx->r8) = 0;
    // 0x8004033C: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x80040340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80040344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040348: jr          $ra
    // 0x8004034C: nop

    return;
    // 0x8004034C: nop

;}
RECOMP_FUNC void func_80013698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013698: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001369C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800136A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800136A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800136A8: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x800136AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800136B0: jal         0x80013D30
    // 0x800136B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80013D30(rdram, ctx);
        goto after_0;
    // 0x800136B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x800136B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800136BC: jal         0x80013D3C
    // 0x800136C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80013D3C(rdram, ctx);
        goto after_1;
    // 0x800136C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800136C4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800136C8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800136CC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800136D0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800136D4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800136D8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800136DC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800136E0: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800136E4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800136E8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800136EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800136F0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800136F4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800136F8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800136FC: jal         0x80034F60
    // 0x80013700: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80013700: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80013704: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80013708: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001370C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80013710: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x80013714: nop

    // 0x80013718: bc1f        L_80013730
    if (!c1cs) {
        // 0x8001371C: nop
    
            goto L_80013730;
    }
    // 0x8001371C: nop

    // 0x80013720: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80013724: nop

    // 0x80013728: bc1tl       L_80013744
    if (c1cs) {
        // 0x8001372C: lwc1        $f12, 0x34($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80013744;
    }
    goto skip_0;
    // 0x8001372C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80013730:
    // 0x80013730: jal         0x80023210
    // 0x80013734: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    func_80023210(rdram, ctx);
        goto after_3;
    // 0x80013734: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80013738: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001373C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80013740: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
L_80013744:
    // 0x80013744: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80013748: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x8001374C: nop

    // 0x80013750: bc1f        L_80013768
    if (!c1cs) {
        // 0x80013754: nop
    
            goto L_80013768;
    }
    // 0x80013754: nop

    // 0x80013758: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x8001375C: nop

    // 0x80013760: bc1tl       L_8001377C
    if (c1cs) {
        // 0x80013764: lwc1        $f12, 0x60($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
            goto L_8001377C;
    }
    goto skip_1;
    // 0x80013764: lwc1        $f12, 0x60($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
    skip_1:
L_80013768:
    // 0x80013768: jal         0x80023210
    // 0x8001376C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    func_80023210(rdram, ctx);
        goto after_4;
    // 0x8001376C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80013770: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013774: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80013778: lwc1        $f12, 0x60($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
L_8001377C:
    // 0x8001377C: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
    // 0x80013780: nop

    // 0x80013784: bc1fl       L_800137A4
    if (!c1cs) {
        // 0x80013788: lwc1        $f0, 0x24($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
            goto L_800137A4;
    }
    goto skip_2;
    // 0x80013788: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x8001378C: lwc1        $f4, 0x64($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80013790: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80013794: nop

    // 0x80013798: bc1tl       L_80013838
    if (c1cs) {
        // 0x8001379C: lwc1        $f2, 0x68($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
            goto L_80013838;
    }
    goto skip_3;
    // 0x8001379C: lwc1        $f2, 0x68($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
    skip_3:
    // 0x800137A0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_800137A4:
    // 0x800137A4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800137A8: nop

    // 0x800137AC: bc1fl       L_800137F0
    if (!c1cs) {
        // 0x800137B0: lwc1        $f12, 0x64($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
            goto L_800137F0;
    }
    goto skip_4;
    // 0x800137B0: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
    skip_4:
    // 0x800137B4: jal         0x800361F0
    // 0x800137B8: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800137B8: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    after_5:
    // 0x800137BC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800137C0: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800137C4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800137C8: jal         0x80035680
    // 0x800137CC: lwc1        $f12, 0x60($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x800137CC: lwc1        $f12, 0x60($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X60);
    after_6:
    // 0x800137D0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800137D4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800137D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800137DC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800137E0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800137E4: b           L_80013834
    // 0x800137E8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
        goto L_80013834;
    // 0x800137E8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800137EC: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
L_800137F0:
    // 0x800137F0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800137F4: nop

    // 0x800137F8: bc1fl       L_80013838
    if (!c1cs) {
        // 0x800137FC: lwc1        $f2, 0x68($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
            goto L_80013838;
    }
    goto skip_5;
    // 0x800137FC: lwc1        $f2, 0x68($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
    skip_5:
    // 0x80013800: jal         0x800361F0
    // 0x80013804: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x80013804: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    after_7:
    // 0x80013808: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001380C: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013810: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80013814: jal         0x80035680
    // 0x80013818: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x80013818: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
    after_8:
    // 0x8001381C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80013820: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013824: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013828: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001382C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80013830: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_80013834:
    // 0x80013834: lwc1        $f2, 0x68($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
L_80013838:
    // 0x80013838: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8001383C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80013840: nop

    // 0x80013844: bc1fl       L_80013914
    if (!c1cs) {
        // 0x80013848: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80013914;
    }
    goto skip_6;
    // 0x80013848: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_6:
    // 0x8001384C: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80013850: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80013854: nop

    // 0x80013858: bc1fl       L_800138B4
    if (!c1cs) {
        // 0x8001385C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_800138B4;
    }
    goto skip_7;
    // 0x8001385C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_7:
    // 0x80013860: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x80013864: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80013868: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001386C: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80013870: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80013874: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x80013878: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x8001387C: jal         0x800232F4
    // 0x80013880: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_9;
    // 0x80013880: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_9:
    // 0x80013884: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013888: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x8001388C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80013890: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80013894: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80013898: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001389C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x800138A0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800138A4: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800138A8: b           L_800139FC
    // 0x800138AC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
        goto L_800139FC;
    // 0x800138AC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800138B0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_800138B4:
    // 0x800138B4: nop

    // 0x800138B8: bc1fl       L_80013A00
    if (!c1cs) {
        // 0x800138BC: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80013A00;
    }
    goto skip_8;
    // 0x800138BC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_8:
    // 0x800138C0: swc1        $f14, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f14.u32l;
    // 0x800138C4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800138C8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800138CC: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800138D0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800138D4: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800138D8: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800138DC: jal         0x800232F4
    // 0x800138E0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_10;
    // 0x800138E0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_10:
    // 0x800138E4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800138E8: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800138EC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800138F0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800138F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800138F8: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800138FC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80013900: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80013904: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013908: b           L_800139FC
    // 0x8001390C: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
        goto L_800139FC;
    // 0x8001390C: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x80013910: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80013914:
    // 0x80013914: nop

    // 0x80013918: bc1fl       L_80013A00
    if (!c1cs) {
        // 0x8001391C: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80013A00;
    }
    goto skip_9;
    // 0x8001391C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_9:
    // 0x80013920: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80013924: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80013928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001392C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013930: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80013934: nop

    // 0x80013938: bc1fl       L_800139A4
    if (!c1cs) {
        // 0x8001393C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800139A4;
    }
    goto skip_10;
    // 0x8001393C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_10:
    // 0x80013940: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80013944: nop

    // 0x80013948: bc1fl       L_80013A00
    if (!c1cs) {
        // 0x8001394C: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80013A00;
    }
    goto skip_11;
    // 0x8001394C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_11:
    // 0x80013950: swc1        $f14, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f14.u32l;
    // 0x80013954: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80013958: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001395C: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80013960: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80013964: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x80013968: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x8001396C: jal         0x800232F4
    // 0x80013970: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_11;
    // 0x80013970: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_11:
    // 0x80013974: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013978: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x8001397C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80013980: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80013984: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80013988: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8001398C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80013990: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80013994: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013998: b           L_800139FC
    // 0x8001399C: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
        goto L_800139FC;
    // 0x8001399C: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x800139A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800139A4:
    // 0x800139A4: nop

    // 0x800139A8: bc1fl       L_80013A00
    if (!c1cs) {
        // 0x800139AC: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80013A00;
    }
    goto skip_12;
    // 0x800139AC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_12:
    // 0x800139B0: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x800139B4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800139B8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800139BC: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800139C0: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800139C4: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800139C8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800139CC: jal         0x800232F4
    // 0x800139D0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_12;
    // 0x800139D0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_12:
    // 0x800139D4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800139D8: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800139DC: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800139E0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800139E4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800139E8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800139EC: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800139F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800139F4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800139F8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_800139FC:
    // 0x800139FC: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
L_80013A00:
    // 0x80013A00: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80013A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013A08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013A0C: jr          $ra
    // 0x80013A10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013A10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000BA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BA0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000BA10: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000BA14: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000BA18: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000BA1C: addiu       $t8, $t8, -0x2E64
    ctx->r24 = ADD32(ctx->r24, -0X2E64);
    // 0x8000BA20: sra         $t7, $a0, 3
    ctx->r15 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8000BA24: andi        $t0, $a0, 0x7
    ctx->r8 = ctx->r4 & 0X7;
    // 0x8000BA28: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8000BA2C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8000BA30: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8000BA34: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BA38: lbu         $t1, -0x28C0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X28C0);
    // 0x8000BA3C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8000BA40: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x8000BA44: jr          $ra
    // 0x8000BA48: nop

    return;
    // 0x8000BA48: nop

;}
RECOMP_FUNC void func_8001F818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F818: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F81C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001F820: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001F824: lw          $t6, -0x458C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X458C);
    // 0x8001F828: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001F82C: addiu       $t9, $t9, -0x42D0
    ctx->r25 = ADD32(ctx->r25, -0X42D0);
    // 0x8001F830: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8001F834: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001F838: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001F83C: addiu       $t8, $t7, -0x70
    ctx->r24 = ADD32(ctx->r15, -0X70);
    // 0x8001F840: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001F844: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001F848: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x8001F84C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001F850: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001F854: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001F858: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001F85C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8001F860: addiu       $t2, $t2, -0x39BC
    ctx->r10 = ADD32(ctx->r10, -0X39BC);
    // 0x8001F864: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001F868: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8001F86C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001F870: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F874: jal         0x8002413C
    // 0x8001F878: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001F878: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8001F87C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8001F880: beq         $v0, $zero, L_8001F8E8
    if (ctx->r2 == 0) {
        // 0x8001F884: addiu       $t1, $t1, -0x39BC
        ctx->r9 = ADD32(ctx->r9, -0X39BC);
            goto L_8001F8E8;
    }
    // 0x8001F884: addiu       $t1, $t1, -0x39BC
    ctx->r9 = ADD32(ctx->r9, -0X39BC);
    // 0x8001F888: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001F88C: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001F890: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001F894: lui         $t5, 0x803B
    ctx->r13 = S32(0X803B << 16);
    // 0x8001F898: addiu       $t5, $t5, -0x7470
    ctx->r13 = ADD32(ctx->r13, -0X7470);
    // 0x8001F89C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8001F8A0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8001F8A4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8001F8A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8001F8AC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8001F8B0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8001F8B4: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8001F8B8: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x8001F8BC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001F8C0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001F8C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001F8C8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8001F8CC: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x8001F8D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001F8D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001F8D8: jal         0x80020F8C
    // 0x8001F8DC: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x8001F8DC: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    after_1:
    // 0x8001F8E0: b           L_8001F8F4
    // 0x8001F8E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001F8F4;
    // 0x8001F8E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001F8E8:
    // 0x8001F8E8: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x8001F8EC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8001F8F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001F8F4:
    // 0x8001F8F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001F8F8: jr          $ra
    // 0x8001F8FC: nop

    return;
    // 0x8001F8FC: nop

;}
RECOMP_FUNC void static_5_80038310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038310: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x80038314: bne         $t6, $zero, L_800383F4
    if (ctx->r14 != 0) {
        // 0x80038318: nop
    
            goto L_800383F4;
    }
    // 0x80038318: nop

    // 0x8003831C: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x80038320: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80038324: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x80038328: blez        $t7, L_800383F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003832C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800383F4;
    }
    // 0x8003832C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038330: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80038334: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80038338: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_8003833C:
    // 0x8003833C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80038340: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x80038344: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x80038348: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8003834C: bnel        $t6, $zero, L_800383E0
    if (ctx->r14 != 0) {
        // 0x80038350: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800383E0;
    }
    goto skip_0;
    // 0x80038350: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x80038354: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80038358: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x8003835C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80038360: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80038364: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x80038368: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x8003836C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x80038370: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x80038374: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80038378: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8003837C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x80038380: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80038384: bnel        $t9, $zero, L_800383E0
    if (ctx->r25 != 0) {
        // 0x80038388: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800383E0;
    }
    goto skip_1;
    // 0x80038388: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x8003838C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80038390: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x80038394: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x80038398: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8003839C: bne         $a2, $zero, L_800383C4
    if (ctx->r6 != 0) {
        // 0x800383A0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800383C4;
    }
    // 0x800383A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800383A4: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800383A8: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800383AC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800383B0: beq         $a2, $zero, L_800383DC
    if (ctx->r6 == 0) {
        // 0x800383B4: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800383DC;
    }
    // 0x800383B4: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800383B8: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800383BC: b           L_800383DC
    // 0x800383C0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800383DC;
    // 0x800383C0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800383C4:
    // 0x800383C4: bnel        $t2, $a2, L_800383E0
    if (ctx->r10 != ctx->r6) {
        // 0x800383C8: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800383E0;
    }
    goto skip_2;
    // 0x800383C8: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800383CC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800383D0: beq         $a2, $zero, L_800383DC
    if (ctx->r6 == 0) {
        // 0x800383D4: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800383DC;
    }
    // 0x800383D4: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800383D8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800383DC:
    // 0x800383DC: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800383E0:
    // 0x800383E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800383E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800383E8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800383EC: bnel        $at, $zero, L_8003833C
    if (ctx->r1 != 0) {
        // 0x800383F0: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_8003833C;
    }
    goto skip_3;
    // 0x800383F0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800383F4:
    // 0x800383F4: jr          $ra
    // 0x800383F8: nop

    return;
    // 0x800383F8: nop

    // 0x800383FC: jr          $ra
    // 0x80038400: nop

    return;
    // 0x80038400: nop

;}
RECOMP_FUNC void static_5_8003EE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EE60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EE64: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8003EE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EE6C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8003EE70: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x8003EE74: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8003EE78: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003EE7C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8003EE80: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8003EE84: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8003EE88: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8003EE8C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8003EE90: bne         $at, $zero, L_8003EEBC
    if (ctx->r1 != 0) {
        // 0x8003EE94: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8003EEBC;
    }
    // 0x8003EE94: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8003EE98: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x8003EE9C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x8003EEA0: beq         $at, $zero, L_8003F4A8
    if (ctx->r1 == 0) {
        // 0x8003EEA4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8003F4A8;
    }
    // 0x8003EEA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003EEA8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003EEAC: addu        $at, $at, $t7
    gpr jr_addend_8003EEB4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003EEB0: lw          $t7, 0x1F44($at)
    ctx->r15 = ADD32(ctx->r1, 0X1F44);
    // 0x8003EEB4: jr          $t7
    // 0x8003EEB8: nop

    switch (jr_addend_8003EEB4 >> 2) {
        case 0: goto L_8003F1C8; break;
        case 1: goto L_8003F4A8; break;
        case 2: goto L_8003F1C8; break;
        case 3: goto L_8003F4A8; break;
        case 4: goto L_8003F4A8; break;
        case 5: goto L_8003F4A8; break;
        case 6: goto L_8003F4A8; break;
        case 7: goto L_8003F4A8; break;
        case 8: goto L_8003F4A8; break;
        case 9: goto L_8003F4A8; break;
        case 10: goto L_8003F4A8; break;
        case 11: goto L_8003F4A8; break;
        case 12: goto L_8003F4A8; break;
        case 13: goto L_8003F4A8; break;
        case 14: goto L_8003F4A8; break;
        case 15: goto L_8003F4A8; break;
        case 16: goto L_8003F4A8; break;
        case 17: goto L_8003F4A8; break;
        case 18: goto L_8003F4A8; break;
        case 19: goto L_8003F078; break;
        case 20: goto L_8003F4A8; break;
        case 21: goto L_8003F4A8; break;
        case 22: goto L_8003F4A8; break;
        case 23: goto L_8003F4A8; break;
        case 24: goto L_8003F4A8; break;
        case 25: goto L_8003F4A8; break;
        case 26: goto L_8003F4A8; break;
        case 27: goto L_8003F4A8; break;
        case 28: goto L_8003F4A8; break;
        case 29: goto L_8003F4A8; break;
        case 30: goto L_8003EED0; break;
        case 31: goto L_8003EF08; break;
        case 32: goto L_8003F1C8; break;
        case 33: goto L_8003F1C8; break;
        case 34: goto L_8003F1C8; break;
        case 35: goto L_8003F4A8; break;
        case 36: goto L_8003EF08; break;
        case 37: goto L_8003F4A8; break;
        case 38: goto L_8003F4A8; break;
        case 39: goto L_8003F4A8; break;
        case 40: goto L_8003F4A8; break;
        case 41: goto L_8003F32C; break;
        case 42: goto L_8003F078; break;
        case 43: goto L_8003F3FC; break;
        case 44: goto L_8003F4A8; break;
        case 45: goto L_8003F4A8; break;
        case 46: goto L_8003F444; break;
        case 47: goto L_8003F4A8; break;
        case 48: goto L_8003F078; break;
        case 49: goto L_8003F4A8; break;
        case 50: goto L_8003F4A8; break;
        case 51: goto L_8003F078; break;
        default: switch_error(__func__, 0x8003EEB4, 0x80071F44);
    }
    // 0x8003EEB8: nop

L_8003EEBC:
    // 0x8003EEBC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8003EEC0: beql        $v1, $at, L_8003F48C
    if (ctx->r3 == ctx->r1) {
        // 0x8003EEC4: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8003F48C;
    }
    goto skip_0;
    // 0x8003EEC4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8003EEC8: b           L_8003F4AC
    // 0x8003EECC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_8003F4AC;
    // 0x8003EECC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_8003EED0:
    // 0x8003EED0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8003EED4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003EED8: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x8003EEDC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x8003EEE0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8003EEE4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8003EEE8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003EEEC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8003EEF0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8003EEF4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8003EEF8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003EEFC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8003EF00: b           L_8003F4C0
    // 0x8003EF04: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_8003F4C0;
    // 0x8003EF04: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_8003EF08:
    // 0x8003EF08: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003EF0C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8003EF10: bnel        $v0, $at, L_8003EF48
    if (ctx->r2 != ctx->r1) {
        // 0x8003EF14: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8003EF48;
    }
    goto skip_1;
    // 0x8003EF14: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x8003EF18: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8003EF1C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003EF20: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x8003EF24: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003EF28: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8003EF2C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003EF30: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x8003EF34: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8003EF38: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003EF3C: b           L_8003EFA4
    // 0x8003EF40: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_8003EFA4;
    // 0x8003EF40: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8003EF44: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8003EF48:
    // 0x8003EF48: bnel        $v0, $at, L_8003EF80
    if (ctx->r2 != ctx->r1) {
        // 0x8003EF4C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8003EF80;
    }
    goto skip_2;
    // 0x8003EF4C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x8003EF50: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8003EF54: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8003EF58: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x8003EF5C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003EF60: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003EF64: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8003EF68: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x8003EF6C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x8003EF70: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003EF74: b           L_8003EFA4
    // 0x8003EF78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_8003EFA4;
    // 0x8003EF78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8003EF7C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8003EF80:
    // 0x8003EF80: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003EF84: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x8003EF88: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8003EF8C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8003EF90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8003EF94: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8003EF98: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8003EF9C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003EFA0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_8003EFA4:
    // 0x8003EFA4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x8003EFA8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003EFAC: bnel        $t7, $at, L_8003EFD0
    if (ctx->r15 != ctx->r1) {
        // 0x8003EFB0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8003EFD0;
    }
    goto skip_3;
    // 0x8003EFB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8003EFB4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8003EFB8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8003EFBC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003EFC0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8003EFC4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003EFC8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8003EFCC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8003EFD0:
    // 0x8003EFD0: bgtzl       $t6, L_8003F00C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8003EFD4: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8003F00C;
    }
    goto skip_4;
    // 0x8003EFD4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x8003EFD8: bltzl       $t6, L_8003EFEC
    if (SIGNED(ctx->r14) < 0) {
        // 0x8003EFDC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8003EFEC;
    }
    goto skip_5;
    // 0x8003EFDC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x8003EFE0: b           L_8003F00C
    // 0x8003EFE4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_8003F00C;
    // 0x8003EFE4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x8003EFE8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8003EFEC:
    // 0x8003EFEC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8003EFF0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8003EFF4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8003EFF8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003EFFC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8003F000: b           L_8003F05C
    // 0x8003F004: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_8003F05C;
    // 0x8003F004: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8003F008: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8003F00C:
    // 0x8003F00C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8003F010: beq         $t8, $zero, L_8003F038
    if (ctx->r24 == 0) {
        // 0x8003F014: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8003F038;
    }
    // 0x8003F014: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8003F018: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003F01C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x8003F020: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x8003F024: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8003F028: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003F02C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8003F030: b           L_8003F05C
    // 0x8003F034: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_8003F05C;
    // 0x8003F034: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_8003F038:
    // 0x8003F038: beql        $t6, $zero, L_8003F060
    if (ctx->r14 == 0) {
        // 0x8003F03C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8003F060;
    }
    goto skip_6;
    // 0x8003F03C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x8003F040: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003F044: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8003F048: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8003F04C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8003F050: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003F054: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8003F058: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8003F05C:
    // 0x8003F05C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8003F060:
    // 0x8003F060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F064: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x8003F068: jal         0x80047CE0
    // 0x8003F06C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x8003F06C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x8003F070: b           L_8003F4C4
    // 0x8003F074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003F4C4;
    // 0x8003F074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003F078:
    // 0x8003F078: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003F07C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8003F080: bnel        $v0, $at, L_8003F0B8
    if (ctx->r2 != ctx->r1) {
        // 0x8003F084: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8003F0B8;
    }
    goto skip_7;
    // 0x8003F084: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x8003F088: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8003F08C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F090: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x8003F094: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8003F098: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x8003F09C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8003F0A0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x8003F0A4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x8003F0A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003F0AC: b           L_8003F114
    // 0x8003F0B0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_8003F114;
    // 0x8003F0B0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8003F0B4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8003F0B8:
    // 0x8003F0B8: bnel        $v0, $at, L_8003F0F0
    if (ctx->r2 != ctx->r1) {
        // 0x8003F0BC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_8003F0F0;
    }
    goto skip_8;
    // 0x8003F0BC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x8003F0C0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8003F0C4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8003F0C8: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8003F0CC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8003F0D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8003F0D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8003F0D8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8003F0DC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8003F0E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8003F0E4: b           L_8003F114
    // 0x8003F0E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8003F114;
    // 0x8003F0E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003F0EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_8003F0F0:
    // 0x8003F0F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F0F4: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8003F0F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003F0FC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8003F100: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8003F104: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x8003F108: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8003F10C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003F110: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_8003F114:
    // 0x8003F114: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003F118: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003F11C: bne         $v0, $at, L_8003F13C
    if (ctx->r2 != ctx->r1) {
        // 0x8003F120: nop
    
            goto L_8003F13C;
    }
    // 0x8003F120: nop

    // 0x8003F124: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8003F128: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8003F12C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003F130: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8003F134: b           L_8003F154
    // 0x8003F138: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_8003F154;
    // 0x8003F138: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8003F13C:
    // 0x8003F13C: bnel        $v0, $zero, L_8003F158
    if (ctx->r2 != 0) {
        // 0x8003F140: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_8003F158;
    }
    goto skip_9;
    // 0x8003F140: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x8003F144: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8003F148: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8003F14C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003F150: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8003F154:
    // 0x8003F154: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_8003F158:
    // 0x8003F158: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x8003F15C: beql        $t6, $zero, L_8003F1B0
    if (ctx->r14 == 0) {
        // 0x8003F160: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8003F1B0;
    }
    goto skip_10;
    // 0x8003F160: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x8003F164: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8003F168: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x8003F16C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8003F170: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x8003F174: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x8003F178: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003F17C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8003F180: beq         $v1, $at, L_8003F194
    if (ctx->r3 == ctx->r1) {
        // 0x8003F184: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_8003F194;
    }
    // 0x8003F184: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8003F188: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8003F18C: bnel        $v1, $at, L_8003F1B0
    if (ctx->r3 != ctx->r1) {
        // 0x8003F190: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8003F1B0;
    }
    goto skip_11;
    // 0x8003F190: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_8003F194:
    // 0x8003F194: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003F198: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8003F19C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x8003F1A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003F1A4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8003F1A8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8003F1AC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8003F1B0:
    // 0x8003F1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F1B4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x8003F1B8: jal         0x80047CE0
    // 0x8003F1BC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x8003F1BC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x8003F1C0: b           L_8003F4C4
    // 0x8003F1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003F4C4;
    // 0x8003F1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003F1C8:
    // 0x8003F1C8: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x8003F1CC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8003F1D0: bnel        $t6, $at, L_8003F238
    if (ctx->r14 != ctx->r1) {
        // 0x8003F1D4: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_8003F238;
    }
    goto skip_12;
    // 0x8003F1D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x8003F1D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003F1DC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8003F1E0: beq         $t9, $zero, L_8003F1F8
    if (ctx->r25 == 0) {
        // 0x8003F1E4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003F1F8;
    }
    // 0x8003F1E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003F1E8: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x8003F1EC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8003F1F0: b           L_8003F228
    // 0x8003F1F4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_8003F228;
    // 0x8003F1F4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_8003F1F8:
    // 0x8003F1F8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8003F1FC: beq         $t7, $zero, L_8003F214
    if (ctx->r15 == 0) {
        // 0x8003F200: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_8003F214;
    }
    // 0x8003F200: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x8003F204: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x8003F208: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003F20C: b           L_8003F224
    // 0x8003F210: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_8003F224;
    // 0x8003F210: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_8003F214:
    // 0x8003F214: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8003F218: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8003F21C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x8003F220: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_8003F224:
    // 0x8003F224: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003F228:
    // 0x8003F228: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x8003F22C: b           L_8003F28C
    // 0x8003F230: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_8003F28C;
    // 0x8003F230: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x8003F234: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_8003F238:
    // 0x8003F238: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8003F23C: beq         $t6, $zero, L_8003F254
    if (ctx->r14 == 0) {
        // 0x8003F240: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003F254;
    }
    // 0x8003F240: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003F244: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x8003F248: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8003F24C: b           L_8003F284
    // 0x8003F250: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_8003F284;
    // 0x8003F250: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_8003F254:
    // 0x8003F254: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8003F258: beq         $t8, $zero, L_8003F270
    if (ctx->r24 == 0) {
        // 0x8003F25C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_8003F270;
    }
    // 0x8003F25C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x8003F260: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x8003F264: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8003F268: b           L_8003F280
    // 0x8003F26C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_8003F280;
    // 0x8003F26C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_8003F270:
    // 0x8003F270: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8003F274: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x8003F278: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x8003F27C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_8003F280:
    // 0x8003F280: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003F284:
    // 0x8003F284: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x8003F288: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_8003F28C:
    // 0x8003F28C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x8003F290: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x8003F294: beql        $t6, $zero, L_8003F2C0
    if (ctx->r14 == 0) {
        // 0x8003F298: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8003F2C0;
    }
    goto skip_13;
    // 0x8003F298: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x8003F29C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003F2A0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x8003F2A4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8003F2A8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8003F2AC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003F2B0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8003F2B4: b           L_8003F310
    // 0x8003F2B8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_8003F310;
    // 0x8003F2B8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x8003F2BC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8003F2C0:
    // 0x8003F2C0: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8003F2C4: beq         $t9, $zero, L_8003F2EC
    if (ctx->r25 == 0) {
        // 0x8003F2C8: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_8003F2EC;
    }
    // 0x8003F2C8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8003F2CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003F2D0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x8003F2D4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8003F2D8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8003F2DC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8003F2E0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8003F2E4: b           L_8003F310
    // 0x8003F2E8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_8003F310;
    // 0x8003F2E8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_8003F2EC:
    // 0x8003F2EC: beql        $t7, $zero, L_8003F314
    if (ctx->r15 == 0) {
        // 0x8003F2F0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8003F314;
    }
    goto skip_14;
    // 0x8003F2F0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x8003F2F4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8003F2F8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8003F2FC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8003F300: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8003F304: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003F308: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8003F30C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_8003F310:
    // 0x8003F310: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8003F314:
    // 0x8003F314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F318: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x8003F31C: jal         0x800484F0
    // 0x8003F320: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x8003F320: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x8003F324: b           L_8003F4C4
    // 0x8003F328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003F4C4;
    // 0x8003F328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003F32C:
    // 0x8003F32C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003F330: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003F334: bnel        $v0, $at, L_8003F368
    if (ctx->r2 != ctx->r1) {
        // 0x8003F338: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_8003F368;
    }
    goto skip_15;
    // 0x8003F338: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x8003F33C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8003F340: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F344: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8003F348: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8003F34C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8003F350: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003F354: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x8003F358: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8003F35C: b           L_8003F4C0
    // 0x8003F360: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_8003F4C0;
    // 0x8003F360: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8003F364: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_8003F368:
    // 0x8003F368: bnel        $v0, $at, L_8003F39C
    if (ctx->r2 != ctx->r1) {
        // 0x8003F36C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8003F39C;
    }
    goto skip_16;
    // 0x8003F36C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x8003F370: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8003F374: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F378: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8003F37C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8003F380: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x8003F384: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8003F388: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8003F38C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x8003F390: b           L_8003F4C0
    // 0x8003F394: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_8003F4C0;
    // 0x8003F394: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8003F398: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8003F39C:
    // 0x8003F39C: bnel        $v0, $at, L_8003F3D8
    if (ctx->r2 != ctx->r1) {
        // 0x8003F3A0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8003F3D8;
    }
    goto skip_17;
    // 0x8003F3A0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x8003F3A4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8003F3A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F3AC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8003F3B0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8003F3B4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8003F3B8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003F3BC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x8003F3C0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8003F3C4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8003F3C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8003F3CC: b           L_8003F4C0
    // 0x8003F3D0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_8003F4C0;
    // 0x8003F3D0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8003F3D4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8003F3D8:
    // 0x8003F3D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F3DC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x8003F3E0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8003F3E4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x8003F3E8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003F3EC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8003F3F0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8003F3F4: b           L_8003F4C0
    // 0x8003F3F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_8003F4C0;
    // 0x8003F3F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_8003F3FC:
    // 0x8003F3FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8003F400: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F408: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x8003F40C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8003F410: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8003F414: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8003F418: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x8003F41C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003F420: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8003F424: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8003F428: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8003F42C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x8003F430: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003F434: jal         0x80047CE0
    // 0x8003F438: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x8003F438: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x8003F43C: b           L_8003F4C4
    // 0x8003F440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003F4C4;
    // 0x8003F440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003F444:
    // 0x8003F444: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8003F448: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F44C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x8003F450: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8003F454: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x8003F458: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003F45C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x8003F460: jal         0x8003FB4C
    // 0x8003F464: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x8003F464: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x8003F468: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8003F46C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8003F470: bltz        $v1, L_8003F4C0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003F474: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8003F4C0;
    }
    // 0x8003F474: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003F478: beql        $at, $zero, L_8003F4C4
    if (ctx->r1 == 0) {
        // 0x8003F47C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003F4C4;
    }
    goto skip_18;
    // 0x8003F47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x8003F480: b           L_8003F4C0
    // 0x8003F484: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_8003F4C0;
    // 0x8003F484: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x8003F488: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8003F48C:
    // 0x8003F48C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x8003F490: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8003F494: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8003F498: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003F49C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003F4A0: b           L_8003F4C0
    // 0x8003F4A4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_8003F4C0;
    // 0x8003F4A4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8003F4A8:
    // 0x8003F4A8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_8003F4AC:
    // 0x8003F4AC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x8003F4B0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x8003F4B4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003F4B8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003F4BC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8003F4C0:
    // 0x8003F4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003F4C4:
    // 0x8003F4C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003F4C8: jr          $ra
    // 0x8003F4CC: nop

    return;
    // 0x8003F4CC: nop

;}
RECOMP_FUNC void static_5_80047F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047F84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80047F88: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80047F8C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80047F90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80047F94: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80047F98: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80047F9C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x80047FA0: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x80047FA4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80047FA8: bgtz        $s3, L_80047FBC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80047FAC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80047FBC;
    }
    // 0x80047FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047FB0: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80047FB4: addiu       $s1, $s1, 0x2380
    ctx->r17 = ADD32(ctx->r17, 0X2380);
    // 0x80047FB8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80047FBC:
    // 0x80047FBC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80047FC0: beq         $v0, $s4, L_80047FF4
    if (ctx->r2 == ctx->r20) {
        // 0x80047FC4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80047FF4;
    }
    // 0x80047FC4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80047FC8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x80047FCC: beq         $a0, $v1, L_80047FD8
    if (ctx->r4 == ctx->r3) {
        // 0x80047FD0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80047FD8;
    }
    // 0x80047FD0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80047FD4: bne         $v1, $at, L_80048230
    if (ctx->r3 != ctx->r1) {
        // 0x80047FD8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_80048230;
    }
L_80047FD8:
    // 0x80047FD8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x80047FDC: bne         $at, $zero, L_80048230
    if (ctx->r1 != 0) {
        // 0x80047FE0: nop
    
            goto L_80048230;
    }
    // 0x80047FE0: nop

    // 0x80047FE4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80047FE8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80047FEC: beq         $at, $zero, L_80048230
    if (ctx->r1 == 0) {
        // 0x80047FF0: nop
    
            goto L_80048230;
    }
    // 0x80047FF0: nop

L_80047FF4:
    // 0x80047FF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80047FF8: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80047FFC: beq         $v0, $v1, L_80048038
    if (ctx->r2 == ctx->r3) {
        // 0x80048000: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80048038;
    }
    // 0x80048000: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80048004: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80048008: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8004800C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80048010: bne         $t7, $zero, L_80048028
    if (ctx->r15 != 0) {
        // 0x80048014: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80048028;
    }
    // 0x80048014: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80048018: beql        $at, $zero, L_8004802C
    if (ctx->r1 == 0) {
        // 0x8004801C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_8004802C;
    }
    goto skip_0;
    // 0x8004801C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x80048020: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80048024: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80048028:
    // 0x80048028: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_8004802C:
    // 0x8004802C: bgez        $t8, L_80048038
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80048030: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80048038;
    }
    // 0x80048030: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80048034: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80048038:
    // 0x80048038: bgtz        $s2, L_80048108
    if (SIGNED(ctx->r18) > 0) {
        // 0x8004803C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80048108;
    }
    // 0x8004803C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80048040: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80048044: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048048: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8004804C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80048050: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80048054: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80048058: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8004805C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80048060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80048064: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80048068: bgtz        $v0, L_80048080
    if (SIGNED(ctx->r2) > 0) {
        // 0x8004806C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_80048080;
    }
    // 0x8004806C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80048070: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80048074: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80048078: beql        $t9, $zero, L_800480A8
    if (ctx->r25 == 0) {
        // 0x8004807C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800480A8;
    }
    goto skip_1;
    // 0x8004807C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_80048080:
    // 0x80048080: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80048084: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80048088: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x8004808C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80048090: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x80048094: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048098: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8004809C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800480A0: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800480A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800480A8:
    // 0x800480A8: beql        $at, $zero, L_800480C4
    if (ctx->r1 == 0) {
        // 0x800480AC: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800480C4;
    }
    goto skip_2;
    // 0x800480AC: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800480B0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800480B4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800480B8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800480BC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800480C0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800480C4:
    // 0x800480C4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800480C8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800480CC: beq         $at, $zero, L_800480E0
    if (ctx->r1 == 0) {
        // 0x800480D0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800480E0;
    }
    // 0x800480D0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800480D4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800480D8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800480DC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800480E0:
    // 0x800480E0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800480E4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800480E8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800480EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800480F0: jal         0x8003FB20
    // 0x800480F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800480F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800480F8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800480FC: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x80048100: b           L_8004848C
    // 0x80048104: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_8004848C;
    // 0x80048104: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80048108:
    // 0x80048108: beq         $at, $zero, L_80048180
    if (ctx->r1 == 0) {
        // 0x8004810C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80048180;
    }
    // 0x8004810C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80048110: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80048114: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80048118: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004811C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80048120: jal         0x8003FB20
    // 0x80048124: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80048124: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80048128: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8004812C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80048130: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x80048134: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80048138: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8004813C: bgtz        $v0, L_80048154
    if (SIGNED(ctx->r2) > 0) {
        // 0x80048140: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80048154;
    }
    // 0x80048140: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80048144: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80048148: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x8004814C: beq         $t8, $zero, L_80048178
    if (ctx->r24 == 0) {
        // 0x80048150: nop
    
            goto L_80048178;
    }
    // 0x80048150: nop

L_80048154:
    // 0x80048154: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80048158: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8004815C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80048160: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80048164: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80048168: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8004816C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80048170: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80048174: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80048178:
    // 0x80048178: b           L_8004848C
    // 0x8004817C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_8004848C;
    // 0x8004817C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80048180:
    // 0x80048180: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80048184: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048188: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8004818C: jal         0x8003FB20
    // 0x80048190: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80048190: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x80048194: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80048198: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8004819C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800481A0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800481A4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800481A8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800481AC: bgtz        $v0, L_800481C4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800481B0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800481C4;
    }
    // 0x800481B0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800481B4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800481B8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800481BC: beql        $t9, $zero, L_800481EC
    if (ctx->r25 == 0) {
        // 0x800481C0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800481EC;
    }
    goto skip_3;
    // 0x800481C0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800481C4:
    // 0x800481C4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800481C8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800481CC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800481D0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800481D4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800481D8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800481DC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800481E0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800481E4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800481E8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800481EC:
    // 0x800481EC: beq         $at, $zero, L_80048200
    if (ctx->r1 == 0) {
        // 0x800481F0: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_80048200;
    }
    // 0x800481F0: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800481F4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800481F8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800481FC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80048200:
    // 0x80048200: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80048204: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048208: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8004820C: jal         0x8003FB20
    // 0x80048210: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80048210: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x80048214: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80048218: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8004821C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x80048220: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x80048224: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80048228: b           L_8004848C
    // 0x8004822C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_8004848C;
    // 0x8004822C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_80048230:
    // 0x80048230: beq         $a0, $v1, L_80048240
    if (ctx->r4 == ctx->r3) {
        // 0x80048234: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80048240;
    }
    // 0x80048234: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80048238: bnel        $v1, $at, L_80048280
    if (ctx->r3 != ctx->r1) {
        // 0x8004823C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_80048280;
    }
    goto skip_4;
    // 0x8004823C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_80048240:
    // 0x80048240: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80048244: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x80048248: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004824C: beql        $at, $zero, L_80048260
    if (ctx->r1 == 0) {
        // 0x80048250: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80048260;
    }
    goto skip_5;
    // 0x80048250: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x80048254: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80048258: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8004825C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80048260:
    // 0x80048260: bgez        $t7, L_8004826C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80048264: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_8004826C;
    }
    // 0x80048264: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80048268: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8004826C:
    // 0x8004826C: bne         $a0, $v1, L_8004827C
    if (ctx->r4 != ctx->r3) {
        // 0x80048270: nop
    
            goto L_8004827C;
    }
    // 0x80048270: nop

    // 0x80048274: b           L_8004827C
    // 0x80048278: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_8004827C;
    // 0x80048278: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_8004827C:
    // 0x8004827C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_80048280:
    // 0x80048280: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80048284: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80048288: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004828C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80048290: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x80048294: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048298: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8004829C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800482A0: bgtz        $v0, L_800482B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800482A4: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800482B8;
    }
    // 0x800482A4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800482A8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800482AC: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800482B0: beq         $t6, $zero, L_800482DC
    if (ctx->r14 == 0) {
        // 0x800482B4: nop
    
            goto L_800482DC;
    }
    // 0x800482B4: nop

L_800482B8:
    // 0x800482B8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800482BC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800482C0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800482C4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800482C8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800482CC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800482D0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800482D4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800482D8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800482DC:
    // 0x800482DC: blezl       $v0, L_80048338
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800482E0: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_80048338;
    }
    goto skip_6;
    // 0x800482E0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800482E4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800482E8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800482EC: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800482F0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800482F4: beq         $at, $zero, L_80048308
    if (ctx->r1 == 0) {
        // 0x800482F8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80048308;
    }
    // 0x800482F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800482FC: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80048300: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80048304: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_80048308:
    // 0x80048308: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8004830C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80048310: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80048314: jal         0x8003FB20
    // 0x80048318: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x80048318: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x8004831C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80048320: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80048324: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80048328: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8004832C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80048330: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x80048334: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80048338:
    // 0x80048338: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8004833C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80048340: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048344: bltz        $s2, L_8004835C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80048348: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_8004835C;
    }
    // 0x80048348: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x8004834C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x80048350: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x80048354: b           L_80048378
    // 0x80048358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80048378;
    // 0x80048358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8004835C:
    // 0x8004835C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x80048360: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80048364: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80048368: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004836C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80048370: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048374: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80048378:
    // 0x80048378: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x8004837C: bnel        $at, $zero, L_80048428
    if (ctx->r1 != 0) {
        // 0x80048380: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80048428;
    }
    goto skip_7;
    // 0x80048380: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x80048384: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x80048388: bne         $at, $zero, L_800483D8
    if (ctx->r1 != 0) {
        // 0x8004838C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800483D8;
    }
    // 0x8004838C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80048390: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80048394: bne         $v0, $zero, L_800483A0
    if (ctx->r2 != 0) {
        // 0x80048398: nop
    
            goto L_800483A0;
    }
    // 0x80048398: nop

    // 0x8004839C: break       7
    do_break(2147779484);
L_800483A0:
    // 0x800483A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800483A4: bne         $v0, $at, L_800483B8
    if (ctx->r2 != ctx->r1) {
        // 0x800483A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800483B8;
    }
    // 0x800483A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800483AC: bne         $s2, $at, L_800483B8
    if (ctx->r18 != ctx->r1) {
        // 0x800483B0: nop
    
            goto L_800483B8;
    }
    // 0x800483B0: nop

    // 0x800483B4: break       6
    do_break(2147779508);
L_800483B8:
    // 0x800483B8: mfhi        $s2
    ctx->r18 = hi;
    // 0x800483BC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800483C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800483C4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800483C8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800483CC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800483D0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800483D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800483D8:
    // 0x800483D8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800483DC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800483E0: bne         $v0, $zero, L_800483EC
    if (ctx->r2 != 0) {
        // 0x800483E4: nop
    
            goto L_800483EC;
    }
    // 0x800483E4: nop

    // 0x800483E8: break       7
    do_break(2147779560);
L_800483EC:
    // 0x800483EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800483F0: bne         $v0, $at, L_80048404
    if (ctx->r2 != ctx->r1) {
        // 0x800483F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80048404;
    }
    // 0x800483F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800483F8: bne         $s2, $at, L_80048404
    if (ctx->r18 != ctx->r1) {
        // 0x800483FC: nop
    
            goto L_80048404;
    }
    // 0x800483FC: nop

    // 0x80048400: break       6
    do_break(2147779584);
L_80048404:
    // 0x80048404: mfhi        $s2
    ctx->r18 = hi;
    // 0x80048408: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8004840C: mflo        $t9
    ctx->r25 = lo;
    // 0x80048410: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80048414: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80048418: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8004841C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80048420: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80048424: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80048428:
    // 0x80048428: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8004842C: bne         $v0, $zero, L_80048438
    if (ctx->r2 != 0) {
        // 0x80048430: nop
    
            goto L_80048438;
    }
    // 0x80048430: nop

    // 0x80048434: break       7
    do_break(2147779636);
L_80048438:
    // 0x80048438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004843C: bne         $v0, $at, L_80048450
    if (ctx->r2 != ctx->r1) {
        // 0x80048440: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80048450;
    }
    // 0x80048440: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80048444: bne         $s2, $at, L_80048450
    if (ctx->r18 != ctx->r1) {
        // 0x80048448: nop
    
            goto L_80048450;
    }
    // 0x80048448: nop

    // 0x8004844C: break       6
    do_break(2147779660);
L_80048450:
    // 0x80048450: mfhi        $s2
    ctx->r18 = hi;
    // 0x80048454: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80048458: mflo        $t9
    ctx->r25 = lo;
    // 0x8004845C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80048460: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80048464: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80048468: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8004846C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x80048470: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80048474: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80048478: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8004847C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80048480: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x80048484: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80048488: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_8004848C:
    // 0x8004848C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80048490: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80048494: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x80048498: bnel        $t6, $at, L_800484DC
    if (ctx->r14 != ctx->r1) {
        // 0x8004849C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800484DC;
    }
    goto skip_8;
    // 0x8004849C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800484A0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800484A4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800484A8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800484AC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800484B0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800484B4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800484B8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800484BC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800484C0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800484C4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800484C8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800484CC: beq         $at, $zero, L_800484D8
    if (ctx->r1 == 0) {
        // 0x800484D0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800484D8;
    }
    // 0x800484D0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800484D4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800484D8:
    // 0x800484D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800484DC:
    // 0x800484DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800484E0: jr          $ra
    // 0x800484E4: nop

    return;
    // 0x800484E4: nop

    // 0x800484E8: jr          $ra
    // 0x800484EC: nop

    return;
    // 0x800484EC: nop

;}
