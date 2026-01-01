#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80011D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011D28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80011D2C: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80011D30: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80011D34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80011D38: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80011D3C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80011D40: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80011D44: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80011D48: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80011D4C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80011D50: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80011D54: lw          $s1, 0x69A0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X69A0);
    // 0x80011D58: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80011D5C: addiu       $s0, $s0, 0x62E0
    ctx->r16 = ADD32(ctx->r16, 0X62E0);
    // 0x80011D60: beq         $s1, $zero, L_80011E50
    if (ctx->r17 == 0) {
        // 0x80011D64: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80011E50;
    }
    // 0x80011D64: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80011D68: lui         $s4, 0xFFFF
    ctx->r20 = S32(0XFFFF << 16);
    // 0x80011D6C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80011D70: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80011D74: addiu       $s2, $s2, -0x23C
    ctx->r18 = ADD32(ctx->r18, -0X23C);
    // 0x80011D78: ori         $s4, $s4, 0x7FFF
    ctx->r20 = ctx->r20 | 0X7FFF;
    // 0x80011D7C: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_80011D80:
    // 0x80011D80: lhu         $v1, 0x60($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X60);
    // 0x80011D84: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x80011D88: beq         $t6, $zero, L_80011DD8
    if (ctx->r14 == 0) {
        // 0x80011D8C: and         $t7, $v1, $s4
        ctx->r15 = ctx->r3 & ctx->r20;
            goto L_80011DD8;
    }
    // 0x80011D8C: and         $t7, $v1, $s4
    ctx->r15 = ctx->r3 & ctx->r20;
    // 0x80011D90: addiu       $v0, $t7, -0x1
    ctx->r2 = ADD32(ctx->r15, -0X1);
    // 0x80011D94: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80011D98: bne         $t8, $zero, L_80011DD0
    if (ctx->r24 != 0) {
        // 0x80011D9C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80011DD0;
    }
    // 0x80011D9C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80011DA0: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x80011DA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80011DA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011DAC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80011DB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80011DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011DB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80011DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80011DC0: jal         0x8001D8B0
    // 0x80011DC4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80011DC4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80011DC8: b           L_80011DDC
    // 0x80011DCC: lh          $t2, 0x52($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X52);
        goto L_80011DDC;
    // 0x80011DCC: lh          $t2, 0x52($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X52);
L_80011DD0:
    // 0x80011DD0: ori         $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 | 0X8000;
    // 0x80011DD4: sh          $t1, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r9;
L_80011DD8:
    // 0x80011DD8: lh          $t2, 0x52($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X52);
L_80011DDC:
    // 0x80011DDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011DE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80011DE4: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011DE8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80011DEC: mflo        $t3
    ctx->r11 = lo;
    // 0x80011DF0: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x80011DF4: jal         0x8001DB38
    // 0x80011DF8: nop

    func_8001DB38(rdram, ctx);
        goto after_1;
    // 0x80011DF8: nop

    after_1:
    // 0x80011DFC: lh          $t4, 0x52($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X52);
    // 0x80011E00: lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X58);
    // 0x80011E04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80011E08: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011E0C: mflo        $t5
    ctx->r13 = lo;
    // 0x80011E10: addu        $a2, $s2, $t5
    ctx->r6 = ADD32(ctx->r18, ctx->r13);
    // 0x80011E14: jal         0x8001E0AC
    // 0x80011E18: nop

    func_8001E0AC(rdram, ctx);
        goto after_2;
    // 0x80011E18: nop

    after_2:
    // 0x80011E1C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80011E20: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80011E24: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80011E28: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80011E2C: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x80011E30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80011E34: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80011E38: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80011E3C: jal         0x80011860
    // 0x80011E40: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80011860(rdram, ctx);
        goto after_3;
    // 0x80011E40: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80011E44: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80011E48: bne         $s1, $zero, L_80011D80
    if (ctx->r17 != 0) {
        // 0x80011E4C: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_80011D80;
    }
    // 0x80011E4C: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_80011E50:
    // 0x80011E50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80011E54: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80011E58: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80011E5C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80011E60: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80011E64: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80011E68: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80011E6C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80011E70: jr          $ra
    // 0x80011E74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80011E74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80102E30_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102E30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102E34: lw          $a0, 0x3420($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3420);
    // 0x80102E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102E40: bne         $a0, $zero, L_80102E64
    if (ctx->r4 != 0) {
        // 0x80102E44: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_80102E64;
    }
    // 0x80102E44: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80102E48: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80102E4C: lh          $t6, 0x3428($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X3428);
    // 0x80102E50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102E54: beql        $t6, $zero, L_80102F08
    if (ctx->r14 == 0) {
        // 0x80102E58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80102F08;
    }
    goto skip_0;
    // 0x80102E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80102E5C: b           L_80102F04
    // 0x80102E60: sh          $zero, 0x3428($at)
    MEM_H(0X3428, ctx->r1) = 0;
        goto L_80102F04;
    // 0x80102E60: sh          $zero, 0x3428($at)
    MEM_H(0X3428, ctx->r1) = 0;
L_80102E64:
    // 0x80102E64: lh          $t7, 0x3428($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3428);
    // 0x80102E68: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80102E6C: bne         $t7, $zero, L_80102EF8
    if (ctx->r15 != 0) {
        // 0x80102E70: nop
    
            goto L_80102EF8;
    }
    // 0x80102E70: nop

    // 0x80102E74: lw          $v0, 0x3424($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3424);
    // 0x80102E78: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80102E7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102E80: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80102E84: sh          $t8, 0x3428($at)
    MEM_H(0X3428, ctx->r1) = ctx->r24;
    // 0x80102E88: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80102E8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80102E90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80102E94: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102E98: sh          $v0, 0x342A($at)
    MEM_H(0X342A, ctx->r1) = ctx->r2;
    // 0x80102E9C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80102EA0: swc1        $f10, 0x342C($at)
    MEM_W(0X342C, ctx->r1) = ctx->f10.u32l;
    // 0x80102EA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80102EA8: beq         $a0, $at, L_80102ED8
    if (ctx->r4 == ctx->r1) {
        // 0x80102EAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80102ED8;
    }
    // 0x80102EAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80102EB0: beq         $a0, $at, L_80102EE8
    if (ctx->r4 == ctx->r1) {
        // 0x80102EB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80102EE8;
    }
    // 0x80102EB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80102EB8: beq         $a0, $at, L_80102ED8
    if (ctx->r4 == ctx->r1) {
        // 0x80102EBC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80102ED8;
    }
    // 0x80102EBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80102EC0: beq         $a0, $at, L_80102EE8
    if (ctx->r4 == ctx->r1) {
        // 0x80102EC4: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_80102EE8;
    }
    // 0x80102EC4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80102EC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80102ECC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102ED0: b           L_80102EF8
    // 0x80102ED4: swc1        $f16, 0x3430($at)
    MEM_W(0X3430, ctx->r1) = ctx->f16.u32l;
        goto L_80102EF8;
    // 0x80102ED4: swc1        $f16, 0x3430($at)
    MEM_W(0X3430, ctx->r1) = ctx->f16.u32l;
L_80102ED8:
    // 0x80102ED8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80102EDC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102EE0: b           L_80102EF8
    // 0x80102EE4: swc1        $f18, 0x3430($at)
    MEM_W(0X3430, ctx->r1) = ctx->f18.u32l;
        goto L_80102EF8;
    // 0x80102EE4: swc1        $f18, 0x3430($at)
    MEM_W(0X3430, ctx->r1) = ctx->f18.u32l;
L_80102EE8:
    // 0x80102EE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80102EEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80102EF0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102EF4: swc1        $f6, 0x3430($at)
    MEM_W(0X3430, ctx->r1) = ctx->f6.u32l;
L_80102EF8:
    // 0x80102EF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102EFC: jal         0x80102F14
    // 0x80102F00: addiu       $a0, $a0, 0x3428
    ctx->r4 = ADD32(ctx->r4, 0X3428);
    func_80102F14_ovl_title(rdram, ctx);
        goto after_0;
    // 0x80102F00: addiu       $a0, $a0, 0x3428
    ctx->r4 = ADD32(ctx->r4, 0X3428);
    after_0:
L_80102F04:
    // 0x80102F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80102F08:
    // 0x80102F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102F0C: jr          $ra
    // 0x80102F10: nop

    return;
    // 0x80102F10: nop

;}
RECOMP_FUNC void func_8000E418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E420: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8000E424: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8000E428: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000E42C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000E430: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E434: lw          $v0, -0x4D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D0C);
    // 0x8000E438: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000E43C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E440: beq         $v0, $zero, L_8000E454
    if (ctx->r2 == 0) {
        // 0x8000E444: addiu       $a3, $a3, -0x2D2C
        ctx->r7 = ADD32(ctx->r7, -0X2D2C);
            goto L_8000E454;
    }
    // 0x8000E444: addiu       $a3, $a3, -0x2D2C
    ctx->r7 = ADD32(ctx->r7, -0X2D2C);
    // 0x8000E448: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E44C: b           L_8000E458
    // 0x8000E450: addiu       $a1, $a1, 0x4098
    ctx->r5 = ADD32(ctx->r5, 0X4098);
        goto L_8000E458;
    // 0x8000E450: addiu       $a1, $a1, 0x4098
    ctx->r5 = ADD32(ctx->r5, 0X4098);
L_8000E454:
    // 0x8000E454: addiu       $a1, $a1, 0x4180
    ctx->r5 = ADD32(ctx->r5, 0X4180);
L_8000E458:
    // 0x8000E458: beq         $v0, $zero, L_8000E46C
    if (ctx->r2 == 0) {
        // 0x8000E45C: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_8000E46C;
    }
    // 0x8000E45C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E460: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E464: b           L_8000E470
    // 0x8000E468: addiu       $v1, $v1, 0x4180
    ctx->r3 = ADD32(ctx->r3, 0X4180);
        goto L_8000E470;
    // 0x8000E468: addiu       $v1, $v1, 0x4180
    ctx->r3 = ADD32(ctx->r3, 0X4180);
L_8000E46C:
    // 0x8000E46C: addiu       $v1, $v1, 0x4098
    ctx->r3 = ADD32(ctx->r3, 0X4098);
L_8000E470:
    // 0x8000E470: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8000E474: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000E478: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8000E47C: beq         $at, $zero, L_8000E578
    if (ctx->r1 == 0) {
        // 0x8000E480: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_8000E578;
    }
    // 0x8000E480: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8000E484: lw          $v0, -0x2D30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2D30);
    // 0x8000E488: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000E48C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E490: beq         $v0, $zero, L_8000E4C0
    if (ctx->r2 == 0) {
        // 0x8000E494: addu        $a1, $a1, $t6
        ctx->r5 = ADD32(ctx->r5, ctx->r14);
            goto L_8000E4C0;
    }
    // 0x8000E494: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8000E498: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000E49C: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x8000E4A0: beq         $a2, $t7, L_8000E4C0
    if (ctx->r6 == ctx->r15) {
        // 0x8000E4A4: nop
    
            goto L_8000E4C0;
    }
    // 0x8000E4A4: nop

    // 0x8000E4A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8000E4AC:
    // 0x8000E4AC: beq         $v0, $zero, L_8000E4C0
    if (ctx->r2 == 0) {
        // 0x8000E4B0: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_8000E4C0;
    }
    // 0x8000E4B0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8000E4B4: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8000E4B8: bnel        $a2, $t8, L_8000E4AC
    if (ctx->r6 != ctx->r24) {
        // 0x8000E4BC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000E4AC;
    }
    goto skip_0;
    // 0x8000E4BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_8000E4C0:
    // 0x8000E4C0: beq         $v0, $zero, L_8000E4DC
    if (ctx->r2 == 0) {
        // 0x8000E4C4: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_8000E4DC;
    }
    // 0x8000E4C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000E4C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000E4CC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000E4D0: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000E4D4: b           L_8000E548
    // 0x8000E4D8: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
        goto L_8000E548;
    // 0x8000E4D8: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
L_8000E4DC:
    // 0x8000E4DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000E4E0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8000E4E4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E4E8: jal         0x80022FD0
    // 0x8000E4EC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x8000E4EC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8000E4F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8000E4F4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000E4F8: addiu       $a3, $a3, -0x2D2C
    ctx->r7 = ADD32(ctx->r7, -0X2D2C);
    // 0x8000E4FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000E500: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000E504: bgez        $v0, L_8000E51C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000E508: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000E51C;
    }
    // 0x8000E508: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000E50C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000E510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000E514: nop

    // 0x8000E518: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8000E51C:
    // 0x8000E51C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E520: ldc1        $f18, 0x1240($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1240);
    // 0x8000E524: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8000E528: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8000E52C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000E530: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000E534: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E538: nop

    // 0x8000E53C: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8000E540: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8000E544: swc1        $f8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f8.u32l;
L_8000E548:
    // 0x8000E548: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000E54C: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x8000E550: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E554: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    // 0x8000E558: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000E55C: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x8000E560: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E564: sw          $a2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r6;
    // 0x8000E568: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x8000E56C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8000E570: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000E574: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_8000E578:
    // 0x8000E578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E57C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E580: jr          $ra
    // 0x8000E584: nop

    return;
    // 0x8000E584: nop

;}
RECOMP_FUNC void func_8001679C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001679C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800167A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800167A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800167A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800167AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800167B0: lhu         $t6, 0x5E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5E);
    // 0x800167B4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800167B8: beql        $t7, $zero, L_80016888
    if (ctx->r15 == 0) {
        // 0x800167BC: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80016888;
    }
    goto skip_0;
    // 0x800167BC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x800167C0: jal         0x8000B140
    // 0x800167C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000B140(rdram, ctx);
        goto after_0;
    // 0x800167C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800167C8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800167CC: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800167D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800167D4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800167D8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800167DC: addiu       $t9, $t9, -0x3668
    ctx->r25 = ADD32(ctx->r25, -0X3668);
    // 0x800167E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800167E4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800167E8: addiu       $t0, $t0, 0x71DC
    ctx->r8 = ADD32(ctx->r8, 0X71DC);
    // 0x800167EC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800167F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800167F4: lhu         $a0, 0xC($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0XC);
    // 0x800167F8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800167FC: addiu       $t1, $t1, -0x4548
    ctx->r9 = ADD32(ctx->r9, -0X4548);
    // 0x80016800: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x80016804: subu        $a3, $a3, $a0
    ctx->r7 = SUB32(ctx->r7, ctx->r4);
    // 0x80016808: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8001680C: subu        $a3, $a3, $a0
    ctx->r7 = SUB32(ctx->r7, ctx->r4);
    // 0x80016810: addiu       $a3, $a3, 0x3F
    ctx->r7 = ADD32(ctx->r7, 0X3F);
    // 0x80016814: sra         $t3, $a3, 6
    ctx->r11 = S32(SIGNED(ctx->r7) >> 6);
    // 0x80016818: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8001681C: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x80016820: sh          $t5, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r13;
    // 0x80016824: lw          $a1, 0x78($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X78);
    // 0x80016828: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8001682C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016830: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x80016834: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x80016838: beql        $t6, $t7, L_80016924
    if (ctx->r14 == ctx->r15) {
        // 0x8001683C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80016924;
    }
    goto skip_1;
    // 0x8001683C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80016840: lw          $t8, -0x44D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44D0);
    // 0x80016844: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80016848: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x8001684C: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x80016850: sh          $t2, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r10;
    // 0x80016854: lw          $t3, -0x44D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X44D0);
    // 0x80016858: lhu         $v0, 0xA($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0XA);
    // 0x8001685C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80016860: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80016864: beql        $at, $zero, L_80016874
    if (ctx->r1 == 0) {
        // 0x80016868: lw          $v0, 0x10($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X10);
            goto L_80016874;
    }
    goto skip_2;
    // 0x80016868: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    skip_2:
    // 0x8001686C: sh          $v0, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r2;
    // 0x80016870: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
L_80016874:
    // 0x80016874: lhu         $t5, 0x2A($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2A);
    // 0x80016878: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001687C: b           L_80016920
    // 0x80016880: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
        goto L_80016920;
    // 0x80016880: sh          $t6, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r14;
    // 0x80016884: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_80016888:
    // 0x80016888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001688C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80016890: sll         $a3, $v1, 2
    ctx->r7 = S32(ctx->r3 << 2);
    // 0x80016894: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x80016898: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8001689C: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x800168A0: addiu       $a3, $a3, 0x3F
    ctx->r7 = ADD32(ctx->r7, 0X3F);
    // 0x800168A4: sra         $t7, $a3, 6
    ctx->r15 = S32(SIGNED(ctx->r7) >> 6);
    // 0x800168A8: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800168AC: subu        $t2, $v1, $t9
    ctx->r10 = SUB32(ctx->r3, ctx->r25);
    // 0x800168B0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800168B4: jal         0x8000B140
    // 0x800168B8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    func_8000B140(rdram, ctx);
        goto after_1;
    // 0x800168B8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_1:
    // 0x800168BC: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800168C0: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800168C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800168C8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800168CC: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x800168D0: addiu       $t4, $t4, -0x3668
    ctx->r12 = ADD32(ctx->r12, -0X3668);
    // 0x800168D4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800168D8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800168DC: addiu       $t0, $t0, 0x71DC
    ctx->r8 = ADD32(ctx->r8, 0X71DC);
    // 0x800168E0: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x800168E4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800168E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800168EC: lhu         $t5, 0xC($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0XC);
    // 0x800168F0: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x800168F4: sh          $t6, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r14;
    // 0x800168F8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800168FC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80016900: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x80016904: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    // 0x80016908: lw          $t2, 0x64($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X64);
    // 0x8001690C: lhu         $a0, 0xA($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0XA);
    // 0x80016910: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80016914: beql        $at, $zero, L_80016924
    if (ctx->r1 == 0) {
        // 0x80016918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80016924;
    }
    goto skip_3;
    // 0x80016918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8001691C: sh          $a0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r4;
L_80016920:
    // 0x80016920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80016924:
    // 0x80016924: jal         0x80018DF4
    // 0x80016928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80018DF4(rdram, ctx);
        goto after_2;
    // 0x80016928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8001692C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016930: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016934: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80016938: jr          $ra
    // 0x8001693C: nop

    return;
    // 0x8001693C: nop

;}
RECOMP_FUNC void func_80100A94_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100A94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80100A98: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80100A9C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80100AA0: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80100AA4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80100AA8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80100AAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80100AB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80100AB4: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x80100AB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80100ABC: lh          $t9, 0x30($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X30);
    // 0x80100AC0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80100AC4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80100AC8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80100ACC: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80100AD0: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x80100AD4: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x80100AD8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80100ADC: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x80100AE0: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x80100AE4: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x80100AE8: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80100AEC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80100AF0: sh          $t8, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r24;
    // 0x80100AF4: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80100AF8: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80100AFC: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    // 0x80100B00: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
    // 0x80100B04: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x80100B08: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x80100B0C: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80100B10: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x80100B14: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x80100B18: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80100B1C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80100B20: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80100B24: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80100B28: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80100B2C: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80100B30: jr          $ra
    // 0x80100B34: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
    return;
    // 0x80100B34: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_8002FEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002FEA8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002FEAC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002FEB0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002FEB4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002FEB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002FEBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002FEC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002FEC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FEC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8002FECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002FED0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002FED4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002FED8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002FEDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002FEE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FEE4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8002FEE8: addiu       $t2, $zero, -0x34
    ctx->r10 = ADD32(0, -0X34);
    // 0x8002FEEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002FEF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002FEF4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8002FEF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002FEFC: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x8002FF00: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x8002FF04: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002FF08: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x8002FF0C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002FF10: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x8002FF14: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002FF18: addiu       $t4, $t4, 0x5E0
    ctx->r12 = ADD32(ctx->r12, 0X5E0);
    // 0x8002FF1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002FF20: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x8002FF24: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x8002FF28: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8002FF2C: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x8002FF30: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8002FF34: jal         0x800307D8
    // 0x8002FF38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800307D8(rdram, ctx);
        goto after_0;
    // 0x8002FF38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x8002FF3C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x8002FF40: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8002FF44: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x8002FF48: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x8002FF4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FF50: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8002FF54: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8002FF58: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002FF5C: jal         0x800307D8
    // 0x8002FF60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800307D8(rdram, ctx);
        goto after_1;
    // 0x8002FF60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8002FF64: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8002FF68: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8002FF6C: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x8002FF70: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002FF74: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002FF78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FF7C: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8002FF80: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002FF84: jal         0x800307D8
    // 0x8002FF88: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    func_800307D8(rdram, ctx);
        goto after_2;
    // 0x8002FF88: addu        $a2, $t9, $t2
    ctx->r6 = ADD32(ctx->r25, ctx->r10);
    after_2:
    // 0x8002FF8C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002FF90: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002FF94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FF98: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8002FF9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002FFA0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8002FFA4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002FFA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002FFAC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002FFB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FFB4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8002FFB8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002FFBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002FFC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002FFC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002FFC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002FFCC: lh          $s1, 0x4($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X4);
    // 0x8002FFD0: lh          $s2, 0x6($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X6);
    // 0x8002FFD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002FFD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002FFDC: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    // 0x8002FFE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002FFE4: jal         0x800307D8
    // 0x8002FFE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800307D8(rdram, ctx);
        goto after_3;
    // 0x8002FFE8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x8002FFEC: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8002FFF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002FFF4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002FFF8: addu        $a2, $t2, $s2
    ctx->r6 = ADD32(ctx->r10, ctx->r18);
    // 0x8002FFFC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80030000: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030004: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80030008: jal         0x800307D8
    // 0x8003000C: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    func_800307D8(rdram, ctx);
        goto after_4;
    // 0x8003000C: lh          $a3, 0x8($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X8);
    after_4:
    // 0x80030010: lh          $t4, 0xA($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA);
    // 0x80030014: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030018: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003001C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030020: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80030024: jal         0x800307D8
    // 0x80030028: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800307D8(rdram, ctx);
        goto after_5;
    // 0x80030028: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x8003002C: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x80030030: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80030034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030038: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    // 0x8003003C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80030040: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030044: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80030048: jal         0x800307D8
    // 0x8003004C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800307D8(rdram, ctx);
        goto after_6;
    // 0x8003004C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_6:
    // 0x80030050: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80030054: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80030058: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003005C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80030060: jr          $ra
    // 0x80030064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80030064: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E210: beq         $a2, $zero, L_8003E27C
    if (ctx->r6 == 0) {
        // 0x8003E214: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8003E27C;
    }
    // 0x8003E214: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8003E218: beq         $a0, $a1, L_8003E27C
    if (ctx->r4 == ctx->r5) {
        // 0x8003E21C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003E27C;
    }
    // 0x8003E21C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003E220: bnel        $at, $zero, L_8003E244
    if (ctx->r1 != 0) {
        // 0x8003E224: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8003E244;
    }
    goto skip_0;
    // 0x8003E224: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x8003E228: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E22C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003E230: beql        $at, $zero, L_8003E244
    if (ctx->r1 == 0) {
        // 0x8003E234: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8003E244;
    }
    goto skip_1;
    // 0x8003E234: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x8003E238: b           L_8003E3A8
    // 0x8003E23C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_8003E3A8;
    // 0x8003E23C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8003E240: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8003E244:
    // 0x8003E244: bne         $at, $zero, L_8003E25C
    if (ctx->r1 != 0) {
        // 0x8003E248: nop
    
            goto L_8003E25C;
    }
    // 0x8003E248: nop

    // 0x8003E24C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8003E250: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8003E254: beq         $v0, $v1, L_8003E284
    if (ctx->r2 == ctx->r3) {
        // 0x8003E258: nop
    
            goto L_8003E284;
    }
    // 0x8003E258: nop

L_8003E25C:
    // 0x8003E25C: beq         $a2, $zero, L_8003E27C
    if (ctx->r6 == 0) {
        // 0x8003E260: nop
    
            goto L_8003E27C;
    }
    // 0x8003E260: nop

    // 0x8003E264: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_8003E268:
    // 0x8003E268: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003E26C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003E270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003E274: bne         $a0, $v1, L_8003E268
    if (ctx->r4 != ctx->r3) {
        // 0x8003E278: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_8003E268;
    }
    // 0x8003E278: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8003E27C:
    // 0x8003E27C: jr          $ra
    // 0x8003E280: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8003E280: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8003E284:
    // 0x8003E284: beq         $v0, $zero, L_8003E2E8
    if (ctx->r2 == 0) {
        // 0x8003E288: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003E2E8;
    }
    // 0x8003E288: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E28C: beq         $v0, $at, L_8003E2CC
    if (ctx->r2 == ctx->r1) {
        // 0x8003E290: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003E2CC;
    }
    // 0x8003E290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E294: beql        $v0, $at, L_8003E2B8
    if (ctx->r2 == ctx->r1) {
        // 0x8003E298: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_8003E2B8;
    }
    goto skip_2;
    // 0x8003E298: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8003E29C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003E2A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003E2A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003E2A8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003E2AC: b           L_8003E2E8
    // 0x8003E2B0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_8003E2E8;
    // 0x8003E2B0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x8003E2B4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8003E2B8:
    // 0x8003E2B8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8003E2BC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8003E2C0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8003E2C4: b           L_8003E2E8
    // 0x8003E2C8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_8003E2E8;
    // 0x8003E2C8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_8003E2CC:
    // 0x8003E2CC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003E2D0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x8003E2D4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8003E2D8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8003E2DC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8003E2E0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x8003E2E4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_8003E2E8:
    // 0x8003E2E8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8003E2EC: bnel        $at, $zero, L_8003E348
    if (ctx->r1 != 0) {
        // 0x8003E2F0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8003E348;
    }
    goto skip_3;
    // 0x8003E2F0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x8003E2F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003E2F8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003E2FC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8003E300: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8003E304: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x8003E308: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8003E30C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8003E310: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x8003E314: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8003E318: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8003E31C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8003E320: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x8003E324: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x8003E328: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8003E32C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x8003E330: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x8003E334: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x8003E338: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8003E33C: b           L_8003E2E8
    // 0x8003E340: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_8003E2E8;
    // 0x8003E340: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_8003E344:
    // 0x8003E344: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8003E348:
    // 0x8003E348: bnel        $at, $zero, L_8003E384
    if (ctx->r1 != 0) {
        // 0x8003E34C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8003E384;
    }
    goto skip_4;
    // 0x8003E34C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x8003E350: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003E354: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003E358: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8003E35C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8003E360: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003E364: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8003E368: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8003E36C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x8003E370: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x8003E374: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x8003E378: b           L_8003E344
    // 0x8003E37C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_8003E344;
    // 0x8003E37C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_8003E380:
    // 0x8003E380: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8003E384:
    // 0x8003E384: bne         $at, $zero, L_8003E25C
    if (ctx->r1 != 0) {
        // 0x8003E388: nop
    
            goto L_8003E25C;
    }
    // 0x8003E388: nop

    // 0x8003E38C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8003E390: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003E394: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8003E398: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003E39C: b           L_8003E380
    // 0x8003E3A0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_8003E380;
    // 0x8003E3A0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x8003E3A4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8003E3A8:
    // 0x8003E3A8: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8003E3AC: bne         $at, $zero, L_8003E3C4
    if (ctx->r1 != 0) {
        // 0x8003E3B0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_8003E3C4;
    }
    // 0x8003E3B0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x8003E3B4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8003E3B8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8003E3BC: beq         $v0, $v1, L_8003E3F4
    if (ctx->r2 == ctx->r3) {
        // 0x8003E3C0: nop
    
            goto L_8003E3F4;
    }
    // 0x8003E3C0: nop

L_8003E3C4:
    // 0x8003E3C4: beq         $a2, $zero, L_8003E27C
    if (ctx->r6 == 0) {
        // 0x8003E3C8: nop
    
            goto L_8003E27C;
    }
    // 0x8003E3C8: nop

    // 0x8003E3CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003E3D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003E3D4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_8003E3D8:
    // 0x8003E3D8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003E3DC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003E3E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003E3E4: bne         $a0, $v1, L_8003E3D8
    if (ctx->r4 != ctx->r3) {
        // 0x8003E3E8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_8003E3D8;
    }
    // 0x8003E3E8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x8003E3EC: jr          $ra
    // 0x8003E3F0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8003E3F0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8003E3F4:
    // 0x8003E3F4: beq         $v0, $zero, L_8003E458
    if (ctx->r2 == 0) {
        // 0x8003E3F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003E458;
    }
    // 0x8003E3F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003E3FC: beq         $v0, $at, L_8003E43C
    if (ctx->r2 == ctx->r1) {
        // 0x8003E400: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003E43C;
    }
    // 0x8003E400: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E404: beql        $v0, $at, L_8003E428
    if (ctx->r2 == ctx->r1) {
        // 0x8003E408: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_8003E428;
    }
    goto skip_5;
    // 0x8003E408: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8003E40C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8003E410: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003E414: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003E418: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003E41C: b           L_8003E458
    // 0x8003E420: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_8003E458;
    // 0x8003E420: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8003E424: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_8003E428:
    // 0x8003E428: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8003E42C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8003E430: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8003E434: b           L_8003E458
    // 0x8003E438: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_8003E458;
    // 0x8003E438: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8003E43C:
    // 0x8003E43C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8003E440: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x8003E444: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x8003E448: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8003E44C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8003E450: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x8003E454: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8003E458:
    // 0x8003E458: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8003E45C: bnel        $at, $zero, L_8003E4B8
    if (ctx->r1 != 0) {
        // 0x8003E460: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8003E4B8;
    }
    goto skip_6;
    // 0x8003E460: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x8003E464: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8003E468: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8003E46C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8003E470: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8003E474: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x8003E478: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8003E47C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x8003E480: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x8003E484: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8003E488: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x8003E48C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8003E490: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8003E494: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x8003E498: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x8003E49C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x8003E4A0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8003E4A4: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8003E4A8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8003E4AC: b           L_8003E458
    // 0x8003E4B0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_8003E458;
    // 0x8003E4B0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_8003E4B4:
    // 0x8003E4B4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8003E4B8:
    // 0x8003E4B8: bnel        $at, $zero, L_8003E4F4
    if (ctx->r1 != 0) {
        // 0x8003E4BC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8003E4F4;
    }
    goto skip_7;
    // 0x8003E4BC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x8003E4C0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8003E4C4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8003E4C8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8003E4CC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8003E4D0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8003E4D4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x8003E4D8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8003E4DC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8003E4E0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x8003E4E4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8003E4E8: b           L_8003E4B4
    // 0x8003E4EC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_8003E4B4;
    // 0x8003E4EC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_8003E4F0:
    // 0x8003E4F0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8003E4F4:
    // 0x8003E4F4: bne         $at, $zero, L_8003E3C4
    if (ctx->r1 != 0) {
        // 0x8003E4F8: nop
    
            goto L_8003E3C4;
    }
    // 0x8003E4F8: nop

    // 0x8003E4FC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8003E500: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8003E504: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8003E508: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003E50C: b           L_8003E4F0
    // 0x8003E510: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8003E4F0;
    // 0x8003E510: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8003E514: nop

    // 0x8003E518: nop

    // 0x8003E51C: nop

;}
RECOMP_FUNC void func_8002DD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DD18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002DD1C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002DD20: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002DD24: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002DD28: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002DD2C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002DD30: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002DD34: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002DD38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002DD3C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002DD40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002DD44: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002DD48: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002DD4C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002DD50: addiu       $v1, $v1, -0x2AE
    ctx->r3 = ADD32(ctx->r3, -0X2AE);
    // 0x8002DD54: addiu       $s0, $s0, -0x2D0
    ctx->r16 = ADD32(ctx->r16, -0X2D0);
    // 0x8002DD58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002DD5C:
    // 0x8002DD5C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8002DD60: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x8002DD64: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8002DD68: bne         $at, $zero, L_8002DD5C
    if (ctx->r1 != 0) {
        // 0x8002DD6C: sb          $v0, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r2;
            goto L_8002DD5C;
    }
    // 0x8002DD6C: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x8002DD70: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002DD74: lb          $t0, 0x2870($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X2870);
    // 0x8002DD78: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002DD7C: addiu       $t7, $t7, 0x2A38
    ctx->r15 = ADD32(ctx->r15, 0X2A38);
    // 0x8002DD80: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8002DD84: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8002DD88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002DD8C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002DD90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DD94: addiu       $a3, $a3, -0x2D0
    ctx->r7 = ADD32(ctx->r7, -0X2D0);
    // 0x8002DD98: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8002DD9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002DDA0: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_8002DDA4:
    // 0x8002DDA4: lb          $v1, 0x2($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X2);
    // 0x8002DDA8: beql        $a2, $v1, L_8002DDCC
    if (ctx->r6 == ctx->r3) {
        // 0x8002DDAC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002DDCC;
    }
    goto skip_0;
    // 0x8002DDAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8002DDB0: bltz        $v1, L_8002DDC8
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002DDB4: sll         $t8, $a1, 1
        ctx->r24 = S32(ctx->r5 << 1);
            goto L_8002DDC8;
    }
    // 0x8002DDB4: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8002DDB8: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x8002DDBC: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x8002DDC0: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8002DDC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8002DDC8:
    // 0x8002DDC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8002DDCC:
    // 0x8002DDCC: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x8002DDD0: bne         $at, $zero, L_8002DDA4
    if (ctx->r1 != 0) {
        // 0x8002DDD4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002DDA4;
    }
    // 0x8002DDD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002DDD8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002DDDC: lhu         $t9, -0x2F4($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2F4);
    // 0x8002DDE0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002DDE4: addiu       $s0, $s0, -0x2D0
    ctx->r16 = ADD32(ctx->r16, -0X2D0);
    // 0x8002DDE8: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x8002DDEC: beq         $t1, $zero, L_8002DE38
    if (ctx->r9 == 0) {
        // 0x8002DDF0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8002DE38;
    }
    // 0x8002DDF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002DDF4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8002DDF8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8002DDFC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002DE00: addiu       $t3, $t3, 0x2A38
    ctx->r11 = ADD32(ctx->r11, 0X2A38);
    // 0x8002DE04: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002DE08: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8002DE0C: lbu         $t4, 0x13($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X13);
    // 0x8002DE10: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8002DE14: bne         $at, $zero, L_8002DE38
    if (ctx->r1 != 0) {
        // 0x8002DE18: nop
    
            goto L_8002DE38;
    }
    // 0x8002DE18: nop

    // 0x8002DE1C: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8002DE20: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8002DE24: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8002DE28: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x8002DE2C: bne         $t6, $zero, L_8002DE38
    if (ctx->r14 != 0) {
        // 0x8002DE30: addiu       $t7, $zero, -0x2
        ctx->r15 = ADD32(0, -0X2);
            goto L_8002DE38;
    }
    // 0x8002DE30: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x8002DE34: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8002DE38:
    // 0x8002DE38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DE3C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8002DE40: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8002DE44: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x8002DE48: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8002DE4C: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002DE50: addiu       $s2, $s2, -0x2E0
    ctx->r18 = ADD32(ctx->r18, -0X2E0);
    // 0x8002DE54: addiu       $s4, $s4, 0x460
    ctx->r20 = ADD32(ctx->r20, 0X460);
    // 0x8002DE58: addiu       $s5, $s5, -0x2DE
    ctx->r21 = ADD32(ctx->r21, -0X2DE);
    // 0x8002DE5C: addiu       $s6, $s6, -0x2D7
    ctx->r22 = ADD32(ctx->r22, -0X2D7);
    // 0x8002DE60: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
L_8002DE64:
    // 0x8002DE64: lb          $a1, 0x0($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X0);
    // 0x8002DE68: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002DE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002DE70: bltz        $a1, L_8002DF2C
    if (SIGNED(ctx->r5) < 0) {
        // 0x8002DE74: addiu       $a3, $zero, 0x80
        ctx->r7 = ADD32(0, 0X80);
            goto L_8002DF2C;
    }
    // 0x8002DE74: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8002DE78: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8002DE7C: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8002DE80: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002DE84: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x8002DE88: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002DE8C: addiu       $t2, $t2, -0x2A8
    ctx->r10 = ADD32(ctx->r10, -0X2A8);
    // 0x8002DE90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002DE94: addu        $s3, $t1, $t2
    ctx->r19 = ADD32(ctx->r9, ctx->r10);
    // 0x8002DE98: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    // 0x8002DE9C: jal         0x800319E0
    // 0x8002DEA0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800319E0(rdram, ctx);
        goto after_0;
    // 0x8002DEA0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_0:
    // 0x8002DEA4: or          $t5, $s4, $zero
    ctx->r13 = ctx->r20 | 0;
    // 0x8002DEA8: or          $t6, $s3, $zero
    ctx->r14 = ctx->r19 | 0;
    // 0x8002DEAC: addiu       $t4, $s4, 0x60
    ctx->r12 = ADD32(ctx->r20, 0X60);
L_8002DEB0:
    // 0x8002DEB0: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8002DEB4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8002DEB8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8002DEBC: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8002DEC0: lw          $at, -0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X8);
    // 0x8002DEC4: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8002DEC8: lw          $at, -0x4($t5)
    ctx->r1 = MEM_W(ctx->r13, -0X4);
    // 0x8002DECC: bne         $t5, $t4, L_8002DEB0
    if (ctx->r13 != ctx->r12) {
        // 0x8002DED0: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8002DEB0;
    }
    // 0x8002DED0: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8002DED4: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x8002DED8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002DEDC: beq         $v0, $zero, L_8002DF2C
    if (ctx->r2 == 0) {
        // 0x8002DEE0: sw          $at, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r1;
            goto L_8002DF2C;
    }
    // 0x8002DEE0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002DEE4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DEE8: jal         0x80031BB0
    // 0x8002DEEC: sw          $fp, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r30;
    func_80031BB0(rdram, ctx);
        goto after_1;
    // 0x8002DEEC: sw          $fp, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r30;
    after_1:
    // 0x8002DEF0: negu        $fp, $v0
    ctx->r30 = SUB32(0, ctx->r2);
    // 0x8002DEF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DEF8: bne         $fp, $at, L_8002DF10
    if (ctx->r30 != ctx->r1) {
        // 0x8002DEFC: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_8002DF10;
    }
    // 0x8002DEFC: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8002DF00: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8002DF04: sb          $t8, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r24;
    // 0x8002DF08: b           L_8002DF18
    // 0x8002DF0C: sb          $s7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r23;
        goto L_8002DF18;
    // 0x8002DF0C: sb          $s7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r23;
L_8002DF10:
    // 0x8002DF10: sb          $t7, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r15;
    // 0x8002DF14: sb          $s7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r23;
L_8002DF18:
    // 0x8002DF18: lhu         $t9, 0x0($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X0);
    // 0x8002DF1C: andi        $t2, $t9, 0xFFF8
    ctx->r10 = ctx->r25 & 0XFFF8;
    // 0x8002DF20: sh          $t2, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r10;
    // 0x8002DF24: ori         $t3, $t2, 0x5
    ctx->r11 = ctx->r10 | 0X5;
    // 0x8002DF28: sh          $t3, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r11;
L_8002DF2C:
    // 0x8002DF2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002DF30: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002DF34: bne         $s1, $at, L_8002DE64
    if (ctx->r17 != ctx->r1) {
        // 0x8002DF38: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8002DE64;
    }
    // 0x8002DF38: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8002DF3C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002DF40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002DF44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002DF48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002DF4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DF50: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002DF54: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002DF58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002DF5C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DF60: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002DF64: jr          $ra
    // 0x8002DF68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002DF68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800222B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800222B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800222B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800222BC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800222C0: lhu         $t6, 0x4EE0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4EE0);
    // 0x800222C4: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800222C8: andi        $t7, $t6, 0xA
    ctx->r15 = ctx->r14 & 0XA;
    // 0x800222CC: bne         $t7, $zero, L_800222EC
    if (ctx->r15 != 0) {
        // 0x800222D0: nop
    
            goto L_800222EC;
    }
    // 0x800222D0: nop

    // 0x800222D4: lw          $t8, 0x4F1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F1C);
    // 0x800222D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800222DC: lhu         $t9, 0x14($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X14);
    // 0x800222E0: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800222E4: beq         $t0, $zero, L_800222F4
    if (ctx->r8 == 0) {
        // 0x800222E8: nop
    
            goto L_800222F4;
    }
    // 0x800222E8: nop

L_800222EC:
    // 0x800222EC: b           L_800222F4
    // 0x800222F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800222F4;
    // 0x800222F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800222F4:
    // 0x800222F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800222F8: jr          $ra
    // 0x800222FC: nop

    return;
    // 0x800222FC: nop

;}
RECOMP_FUNC void func_8001700C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001700C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017014: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80017018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001701C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80017020: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80017024: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80017028: bne         $t7, $zero, L_8001707C
    if (ctx->r15 != 0) {
        // 0x8001702C: nop
    
            goto L_8001707C;
    }
    // 0x8001702C: nop

    // 0x80017030: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80017034: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80017038: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001703C: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80017040: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80017048: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8001704C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80017050: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80017054: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80017058: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001705C: lwc1        $f4, 0x20($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80017060: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80017064: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80017068: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001706C: jal         0x8001FCF8
    // 0x80017070: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x80017070: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    after_0:
    // 0x80017074: b           L_80017088
    // 0x80017078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80017088;
    // 0x80017078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001707C:
    // 0x8001707C: jal         0x800208B8
    // 0x80017080: nop

    func_800208B8(rdram, ctx);
        goto after_1;
    // 0x80017080: nop

    after_1:
    // 0x80017084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017088:
    // 0x80017088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001708C: jr          $ra
    // 0x80017090: nop

    return;
    // 0x80017090: nop

;}
RECOMP_FUNC void func_8000FFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FFE8: lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X14);
    // 0x8000FFEC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8000FFF0: addiu       $a2, $a2, -0x3088
    ctx->r6 = ADD32(ctx->r6, -0X3088);
    // 0x8000FFF4: andi        $t6, $v0, 0x30
    ctx->r14 = ctx->r2 & 0X30;
    // 0x8000FFF8: beq         $t6, $zero, L_80010074
    if (ctx->r14 == 0) {
        // 0x8000FFFC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80010074;
    }
    // 0x8000FFFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80010000: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80010004: addiu       $v1, $v1, -0x2FF2
    ctx->r3 = ADD32(ctx->r3, -0X2FF2);
    // 0x80010008: lhu         $a1, 0x16($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X16);
    // 0x8001000C: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
L_80010010:
    // 0x80010010: beql        $a1, $t7, L_80010028
    if (ctx->r5 == ctx->r15) {
        // 0x80010014: andi        $t8, $v0, 0x10
        ctx->r24 = ctx->r2 & 0X10;
            goto L_80010028;
    }
    goto skip_0;
    // 0x80010014: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    skip_0:
    // 0x80010018: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001001C: bnel        $a2, $v1, L_80010010
    if (ctx->r6 != ctx->r3) {
        // 0x80010020: lbu         $t7, 0x0($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X0);
            goto L_80010010;
    }
    goto skip_1;
    // 0x80010020: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    skip_1:
    // 0x80010024: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
L_80010028:
    // 0x80010028: beq         $t8, $zero, L_80010054
    if (ctx->r24 == 0) {
        // 0x8001002C: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_80010054;
    }
    // 0x8001002C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80010030: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80010034: addiu       $t9, $t9, -0x2FF2
    ctx->r25 = ADD32(ctx->r25, -0X2FF2);
    // 0x80010038: sltu        $at, $a2, $t9
    ctx->r1 = ctx->r6 < ctx->r25 ? 1 : 0;
    // 0x8001003C: beq         $at, $zero, L_8001004C
    if (ctx->r1 == 0) {
        // 0x80010040: nop
    
            goto L_8001004C;
    }
    // 0x80010040: nop

    // 0x80010044: b           L_80010074
    // 0x80010048: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80010074;
    // 0x80010048: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001004C:
    // 0x8001004C: b           L_80010074
    // 0x80010050: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80010074;
    // 0x80010050: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80010054:
    // 0x80010054: addiu       $t0, $t0, -0x2FF2
    ctx->r8 = ADD32(ctx->r8, -0X2FF2);
    // 0x80010058: sltu        $at, $a2, $t0
    ctx->r1 = ctx->r6 < ctx->r8 ? 1 : 0;
    // 0x8001005C: beq         $at, $zero, L_8001006C
    if (ctx->r1 == 0) {
        // 0x80010060: nop
    
            goto L_8001006C;
    }
    // 0x80010060: nop

    // 0x80010064: b           L_80010074
    // 0x80010068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80010074;
    // 0x80010068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001006C:
    // 0x8001006C: b           L_80010074
    // 0x80010070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80010074;
    // 0x80010070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80010074:
    // 0x80010074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80010078: jr          $ra
    // 0x8001007C: nop

    return;
    // 0x8001007C: nop

;}
RECOMP_FUNC void func_80004D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80004D38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004D3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80004D40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80004D44: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80004D48: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80004D4C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80004D50: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80004D54: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80004D58: nop

    // 0x80004D5C: bc1f        L_80004D74
    if (!c1cs) {
        // 0x80004D60: nop
    
            goto L_80004D74;
    }
    // 0x80004D60: nop

    // 0x80004D64: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80004D68: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004D6C: bc1t        L_80004E14
    if (c1cs) {
        // 0x80004D70: nop
    
            goto L_80004E14;
    }
    // 0x80004D70: nop

L_80004D74:
    // 0x80004D74: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80004D78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80004D7C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80004D80: jal         0x80034F60
    // 0x80004D84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80004D84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80004D88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004D8C: ldc1        $f18, 0xFD0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0XFD0);
    // 0x80004D90: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80004D94: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004D98: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80004D9C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80004DA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80004DA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004DA8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80004DAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004DB0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80004DB4: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80004DB8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80004DBC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80004DC0: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80004DC4: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80004DC8: nop

    // 0x80004DCC: bc1fl       L_80004DE0
    if (!c1cs) {
        // 0x80004DD0: lui         $at, 0x3FF8
        ctx->r1 = S32(0X3FF8 << 16);
            goto L_80004DE0;
    }
    goto skip_0;
    // 0x80004DD0: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    skip_0:
    // 0x80004DD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80004DD8: nop

    // 0x80004DDC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
L_80004DE0:
    // 0x80004DE0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80004DE4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x80004DE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004DEC: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80004DF0: nop

    // 0x80004DF4: bc1f        L_80004E0C
    if (!c1cs) {
        // 0x80004DF8: nop
    
            goto L_80004E0C;
    }
    // 0x80004DF8: nop

    // 0x80004DFC: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x80004E00: sh          $t7, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r15;
    // 0x80004E04: b           L_80004E48
    // 0x80004E08: sh          $zero, -0x43D8($at)
    MEM_H(-0X43D8, ctx->r1) = 0;
        goto L_80004E48;
    // 0x80004E08: sh          $zero, -0x43D8($at)
    MEM_H(-0X43D8, ctx->r1) = 0;
L_80004E0C:
    // 0x80004E0C: b           L_80004E48
    // 0x80004E10: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_80004E48;
    // 0x80004E10: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_80004E14:
    // 0x80004E14: lw          $a1, -0x43D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43D4);
    // 0x80004E18: lh          $t9, 0x52($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X52);
    // 0x80004E1C: beql        $a1, $t9, L_80004E4C
    if (ctx->r5 == ctx->r25) {
        // 0x80004E20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004E4C;
    }
    goto skip_1;
    // 0x80004E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80004E24: lh          $t0, 0x5A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X5A);
    // 0x80004E28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004E2C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80004E30: beq         $a1, $t0, L_80004E48
    if (ctx->r5 == ctx->r8) {
        // 0x80004E34: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80004E48;
    }
    // 0x80004E34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004E38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80004E3C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80004E40: jal         0x8001D8B0
    // 0x80004E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x80004E44: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
L_80004E48:
    // 0x80004E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004E4C:
    // 0x80004E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004E50: jr          $ra
    // 0x80004E54: nop

    return;
    // 0x80004E54: nop

;}
RECOMP_FUNC void func_8001FB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB94: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001FB98: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001FB9C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001FBA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001FBA4: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x8001FBA8: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8001FBAC: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001FBB0: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8001FBB4: addiu       $t7, $sp, 0x58
    ctx->r15 = ADD32(ctx->r29, 0X58);
    // 0x8001FBB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001FBBC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FBC0: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001FBC4: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8001FBC8: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    // 0x8001FBCC: jal         0x8002413C
    // 0x8001FBD0: add.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f0.fl;
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001FBD0: add.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f0.fl;
    after_0:
    // 0x8001FBD4: beq         $v0, $zero, L_8001FCE8
    if (ctx->r2 == 0) {
        // 0x8001FBD8: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_8001FCE8;
    }
    // 0x8001FBD8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001FBDC: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001FBE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FBE4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001FBE8: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8001FBEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001FBF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001FBF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001FBF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001FBFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC00: lui         $t8, 0x803A
    ctx->r24 = S32(0X803A << 16);
    // 0x8001FC04: addiu       $t8, $t8, 0x2960
    ctx->r24 = ADD32(ctx->r24, 0X2960);
    // 0x8001FC08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001FC0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001FC10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001FC14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001FC18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC1C: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8001FC20: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8001FC24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001FC28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001FC2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001FC30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001FC34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC38: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8001FC3C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8001FC40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001FC44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001FC48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001FC4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001FC50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC54: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8001FC58: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8001FC5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001FC60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001FC64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001FC68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001FC6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC70: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8001FC74: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8001FC78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001FC7C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001FC80: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001FC84: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001FC88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001FC8C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8001FC90: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001FC94: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001FC98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001FC9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001FCA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001FCA4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8001FCA8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FCAC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8001FCB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001FCB4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001FCB8: addiu       $t6, $zero, 0x51
    ctx->r14 = ADD32(0, 0X51);
    // 0x8001FCBC: addiu       $t7, $zero, 0x31
    ctx->r15 = ADD32(0, 0X31);
    // 0x8001FCC0: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001FCC4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001FCC8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001FCCC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001FCD0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001FCD4: addiu       $a0, $a0, 0x6F70
    ctx->r4 = ADD32(ctx->r4, 0X6F70);
    // 0x8001FCD8: addiu       $a3, $zero, 0x2E
    ctx->r7 = ADD32(0, 0X2E);
    // 0x8001FCDC: addiu       $a1, $a1, -0x17
    ctx->r5 = ADD32(ctx->r5, -0X17);
    // 0x8001FCE0: jal         0x800210FC
    // 0x8001FCE4: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x8001FCE4: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
    after_1:
L_8001FCE8:
    // 0x8001FCE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001FCEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001FCF0: jr          $ra
    // 0x8001FCF4: nop

    return;
    // 0x8001FCF4: nop

;}
RECOMP_FUNC void func_80042858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042858: jr          $ra
    // 0x8004285C: nop

    return;
    // 0x8004285C: nop

;}
RECOMP_FUNC void func_800110D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800110D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800110D4: addiu       $v0, $v0, 0x59E8
    ctx->r2 = ADD32(ctx->r2, 0X59E8);
    // 0x800110D8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800110DC:
    // 0x800110DC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800110E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800110E4: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x800110E8: sw          $zero, 0x60($v0)
    MEM_W(0X60, ctx->r2) = 0;
    // 0x800110EC: sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
    // 0x800110F0: bne         $v1, $zero, L_800110DC
    if (ctx->r3 != 0) {
        // 0x800110F4: addiu       $v0, $v0, 0xC0
        ctx->r2 = ADD32(ctx->r2, 0XC0);
            goto L_800110DC;
    }
    // 0x800110F4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x800110F8: jr          $ra
    // 0x800110FC: nop

    return;
    // 0x800110FC: nop

;}
RECOMP_FUNC void func_800171E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800171E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800171E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800171EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800171F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800171F4: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x800171F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800171FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80017200: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80017204: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017208: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8001720C: beq         $a0, $at, L_80017228
    if (ctx->r4 == ctx->r1) {
        // 0x80017210: sh          $t7, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r15;
            goto L_80017228;
    }
    // 0x80017210: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80017214: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017218: beql        $a0, $at, L_80017240
    if (ctx->r4 == ctx->r1) {
        // 0x8001721C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80017240;
    }
    goto skip_0;
    // 0x8001721C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x80017220: b           L_80017250
    // 0x80017224: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
        goto L_80017250;
    // 0x80017224: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
L_80017228:
    // 0x80017228: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001722C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017230: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x80017234: b           L_8001724C
    // 0x80017238: swc1        $f4, 0x90($t8)
    MEM_W(0X90, ctx->r24) = ctx->f4.u32l;
        goto L_8001724C;
    // 0x80017238: swc1        $f4, 0x90($t8)
    MEM_W(0X90, ctx->r24) = ctx->f4.u32l;
    // 0x8001723C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80017240:
    // 0x80017240: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017244: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80017248: swc1        $f6, 0x90($t9)
    MEM_W(0X90, ctx->r25) = ctx->f6.u32l;
L_8001724C:
    // 0x8001724C: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
L_80017250:
    // 0x80017250: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80017254: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80017258: lwc1        $f10, 0x90($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X90);
    // 0x8001725C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017264: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80017268: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001726C: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80017270: nop

    // 0x80017274: bc1f        L_80017284
    if (!c1cs) {
        // 0x80017278: nop
    
            goto L_80017284;
    }
    // 0x80017278: nop

    // 0x8001727C: b           L_80017284
    // 0x80017280: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80017284;
    // 0x80017280: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80017284:
    // 0x80017284: jal         0x8001FCF8
    // 0x80017288: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x80017288: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_0:
    // 0x8001728C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017298: jr          $ra
    // 0x8001729C: nop

    return;
    // 0x8001729C: nop

;}
RECOMP_FUNC void func_80041570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041570: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80041574: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041578: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8004157C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041580: beq         $at, $zero, L_80041630
    if (ctx->r1 == 0) {
        // 0x80041584: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80041630;
    }
    // 0x80041584: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80041588: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8004158C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041590: addu        $at, $at, $t6
    gpr jr_addend_80041598 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80041594: lw          $t6, 0x2040($at)
    ctx->r14 = ADD32(ctx->r1, 0X2040);
    // 0x80041598: jr          $t6
    // 0x8004159C: nop

    switch (jr_addend_80041598 >> 2) {
        case 0: goto L_800415A0; break;
        case 1: goto L_80041630; break;
        case 2: goto L_80041630; break;
        case 3: goto L_800415A8; break;
        case 4: goto L_80041630; break;
        case 5: goto L_80041630; break;
        case 6: goto L_80041614; break;
        case 7: goto L_80041624; break;
        case 8: goto L_800415E4; break;
        default: switch_error(__func__, 0x80041598, 0x80072040);
    }
    // 0x8004159C: nop

L_800415A0:
    // 0x800415A0: b           L_80041648
    // 0x800415A4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_80041648;
    // 0x800415A4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800415A8:
    // 0x800415A8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800415AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800415B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800415B4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800415B8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800415BC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800415C0: beq         $a0, $zero, L_80041648
    if (ctx->r4 == 0) {
        // 0x800415C4: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_80041648;
    }
    // 0x800415C4: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800415C8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800415CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800415D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800415D4: jalr        $t9
    // 0x800415D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800415D8: nop

    after_0:
    // 0x800415DC: b           L_8004164C
    // 0x800415E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004164C;
    // 0x800415E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800415E4:
    // 0x800415E4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800415E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800415EC: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800415F0: beql        $a0, $zero, L_8004164C
    if (ctx->r4 == 0) {
        // 0x800415F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004164C;
    }
    goto skip_0;
    // 0x800415F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800415F8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800415FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80041600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80041604: jalr        $t9
    // 0x80041608: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80041608: nop

    after_1:
    // 0x8004160C: b           L_8004164C
    // 0x80041610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004164C;
    // 0x80041610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80041614:
    // 0x80041614: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80041618: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004161C: b           L_80041648
    // 0x80041620: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_80041648;
    // 0x80041620: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_80041624:
    // 0x80041624: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80041628: b           L_80041648
    // 0x8004162C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_80041648;
    // 0x8004162C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_80041630:
    // 0x80041630: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80041634: beql        $a0, $zero, L_8004164C
    if (ctx->r4 == 0) {
        // 0x80041638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004164C;
    }
    goto skip_1;
    // 0x80041638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004163C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80041640: jalr        $t9
    // 0x80041644: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80041644: nop

    after_2:
L_80041648:
    // 0x80041648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004164C:
    // 0x8004164C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80041650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041654: jr          $ra
    // 0x80041658: nop

    return;
    // 0x80041658: nop

;}
RECOMP_FUNC void func_8001B19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B19C: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8001B1A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001B1A4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001B1A8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001B1AC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001B1B0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001B1B4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001B1B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001B1BC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001B1C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001B1C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001B1C8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8001B1CC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8001B1D0: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x8001B1D4: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x8001B1D8: lw          $s5, -0x7BE0($s5)
    ctx->r21 = MEM_W(ctx->r21, -0X7BE0);
    // 0x8001B1DC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001B1E0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001B1E4: beq         $s5, $zero, L_8001B410
    if (ctx->r21 == 0) {
        // 0x8001B1E8: addiu       $s0, $s0, -0x7BD8
        ctx->r16 = ADD32(ctx->r16, -0X7BD8);
            goto L_8001B410;
    }
    // 0x8001B1E8: addiu       $s0, $s0, -0x7BD8
    ctx->r16 = ADD32(ctx->r16, -0X7BD8);
    // 0x8001B1EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B1F0: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8001B1F4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001B1F8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001B1FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8001B200: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001B204: addiu       $s2, $s2, -0x4D04
    ctx->r18 = ADD32(ctx->r18, -0X4D04);
    // 0x8001B208: addiu       $s3, $s3, -0x4D08
    ctx->r19 = ADD32(ctx->r19, -0X4D08);
    // 0x8001B20C: addiu       $s4, $s4, 0x6DC0
    ctx->r20 = ADD32(ctx->r20, 0X6DC0);
    // 0x8001B210: addiu       $fp, $sp, 0x74
    ctx->r30 = ADD32(ctx->r29, 0X74);
    // 0x8001B214: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8001B218: addiu       $s1, $sp, 0xB4
    ctx->r17 = ADD32(ctx->r29, 0XB4);
L_8001B21C:
    // 0x8001B21C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8001B220: beq         $v0, $zero, L_8001B408
    if (ctx->r2 == 0) {
        // 0x8001B224: nop
    
            goto L_8001B408;
    }
    // 0x8001B224: nop

    // 0x8001B228: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8001B22C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8001B230: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8001B234: beq         $s6, $v1, L_8001B260
    if (ctx->r22 == ctx->r3) {
        // 0x8001B238: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8001B260;
    }
    // 0x8001B238: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8001B23C: lbu         $t7, 0xB($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XB);
    // 0x8001B240: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x8001B244: lbu         $a2, 0x9($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9);
    // 0x8001B248: lbu         $a3, 0xA($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XA);
    // 0x8001B24C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001B250: lbu         $t8, 0xC($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XC);
    // 0x8001B254: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x8001B258: jal         0x8001B448
    // 0x8001B25C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_8001B448(rdram, ctx);
        goto after_0;
    // 0x8001B25C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
L_8001B260:
    // 0x8001B260: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8001B264: beql        $v0, $zero, L_8001B280
    if (ctx->r2 == 0) {
        // 0x8001B268: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_8001B280;
    }
    goto skip_0;
    // 0x8001B268: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x8001B26C: jalr        $v0
    // 0x8001B270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8001B270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001B274: b           L_8001B29C
    // 0x8001B278: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
        goto L_8001B29C;
    // 0x8001B278: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x8001B27C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8001B280:
    // 0x8001B280: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8001B284: addiu       $t0, $t0, -0x2FB0
    ctx->r8 = ADD32(ctx->r8, -0X2FB0);
    // 0x8001B288: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001B28C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8001B290: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8001B294: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8001B298: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
L_8001B29C:
    // 0x8001B29C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001B2A0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001B2A4: beql        $t2, $zero, L_8001B300
    if (ctx->r10 == 0) {
        // 0x8001B2A8: lwc1        $f10, 0xC($s4)
        ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
            goto L_8001B300;
    }
    goto skip_1;
    // 0x8001B2A8: lwc1        $f10, 0xC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
    skip_1:
    // 0x8001B2AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001B2B0: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8001B2B4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x8001B2B8: jal         0x80023A08
    // 0x8001B2BC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80023A08(rdram, ctx);
        goto after_2;
    // 0x8001B2BC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8001B2C0: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8001B2C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001B2C8: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x8001B2CC: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8001B2D0: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x8001B2D4: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8001B2D8: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x8001B2DC: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001B2E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8001B2E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001B2E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001B2EC: jal         0x80023DF4
    // 0x8001B2F0: nop

    func_80023DF4(rdram, ctx);
        goto after_3;
    // 0x8001B2F0: nop

    after_3:
    // 0x8001B2F4: b           L_8001B374
    // 0x8001B2F8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_8001B374;
    // 0x8001B2F8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8001B2FC: lwc1        $f10, 0xC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0XC);
L_8001B300:
    // 0x8001B300: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8001B304: lwc1        $f18, 0x14($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8001B308: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8001B30C: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x8001B310: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x8001B314: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8001B318: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8001B31C: jal         0x8002371C
    // 0x8001B320: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    func_8002371C(rdram, ctx);
        goto after_4;
    // 0x8001B320: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8001B324: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001B328: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x8001B32C: nop

    // 0x8001B330: bc1tl       L_8001B360
    if (c1cs) {
        // 0x8001B334: mfc1        $a3, $f22
        ctx->r7 = (int32_t)ctx->f22.u32l;
            goto L_8001B360;
    }
    goto skip_2;
    // 0x8001B334: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    skip_2:
    // 0x8001B338: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001B33C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001B340: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001B344: jal         0x80023570
    // 0x8001B348: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80023570(rdram, ctx);
        goto after_5;
    // 0x8001B348: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_5:
    // 0x8001B34C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8001B350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001B354: jal         0x80035510
    // 0x8001B358: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80035510(rdram, ctx);
        goto after_6;
    // 0x8001B358: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x8001B35C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
L_8001B360:
    // 0x8001B360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001B364: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8001B368: jal         0x80023DF4
    // 0x8001B36C: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    func_80023DF4(rdram, ctx);
        goto after_7;
    // 0x8001B36C: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    after_7:
    // 0x8001B370: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_8001B374:
    // 0x8001B374: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x8001B378: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001B37C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x8001B380: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x8001B384: jal         0x80035200
    // 0x8001B388: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_8;
    // 0x8001B388: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_8:
    // 0x8001B38C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8001B390: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x8001B394: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8001B398: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001B39C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8001B3A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B3A4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8001B3A8: lui         $t1, 0x200
    ctx->r9 = S32(0X200 << 16);
    // 0x8001B3AC: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x8001B3B0: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x8001B3B4: addiu       $t0, $t9, 0xC0
    ctx->r8 = ADD32(ctx->r25, 0XC0);
    // 0x8001B3B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001B3BC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8001B3C0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8001B3C4: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8001B3C8: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8001B3CC: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8001B3D0: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8001B3D4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8001B3D8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001B3DC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8001B3E0: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8001B3E4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8001B3E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001B3EC: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x8001B3F0: bne         $t7, $zero, L_8001B408
    if (ctx->r15 != 0) {
        // 0x8001B3F4: nop
    
            goto L_8001B408;
    }
    // 0x8001B3F4: nop

    // 0x8001B3F8: lw          $t8, -0x7BE0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BE0);
    // 0x8001B3FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001B400: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8001B404: sw          $t9, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->r25;
L_8001B408:
    // 0x8001B408: bne         $s5, $zero, L_8001B21C
    if (ctx->r21 != 0) {
        // 0x8001B40C: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_8001B21C;
    }
    // 0x8001B40C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_8001B410:
    // 0x8001B410: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B414: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8001B418: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8001B41C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001B420: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001B424: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001B428: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001B42C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001B430: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001B434: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001B438: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001B43C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001B440: jr          $ra
    // 0x8001B444: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8001B444: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80035470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035470: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80035474: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80035478: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8003547C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80035480: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80035484: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80035488: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8003548C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80035490: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80035494: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80035498: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003549C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800354A0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800354A4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800354A8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800354AC: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800354B0: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800354B4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800354B8: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800354BC: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800354C0: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800354C4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800354C8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800354CC: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800354D0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800354D4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800354D8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800354DC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800354E0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800354E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800354E8: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800354EC: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800354F0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800354F4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800354F8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800354FC: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80035500: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80035504: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80035508: jr          $ra
    // 0x8003550C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8003550C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800210FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800210FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021100: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80021104: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80021108: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002110C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80021110: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80021114: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80021118: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002111C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80021120: jal         0x80020E2C
    // 0x80021124: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80020E2C(rdram, ctx);
        goto after_0;
    // 0x80021124: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80021128: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002112C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80021130: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80021134: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80021138: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8002113C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80021140: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80021144: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80021148: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002114C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80021150: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80021154: jal         0x80020F8C
    // 0x80021158: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x80021158: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8002115C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80021160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80021164: jr          $ra
    // 0x80021168: nop

    return;
    // 0x80021168: nop

    // 0x8002116C: nop

;}
RECOMP_FUNC void func_8002AB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AB64: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8002AB68: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002AB6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002AB70: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002AB74: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8002AB78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002AB7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002AB80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002AB84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002AB88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002AB8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002AB90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002AB94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AB98: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8002AB9C: lui         $t7, 0x3B9A
    ctx->r15 = S32(0X3B9A << 16);
    // 0x8002ABA0: ori         $t7, $t7, 0xCA00
    ctx->r15 = ctx->r15 | 0XCA00;
    // 0x8002ABA4: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8002ABA8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002ABAC: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8002ABB0: sw          $t6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r14;
    // 0x8002ABB4: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x8002ABB8: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8002ABBC: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x8002ABC0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002ABC4: bne         $at, $zero, L_8002ABD0
    if (ctx->r1 != 0) {
        // 0x8002ABC8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8002ABD0;
    }
    // 0x8002ABC8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002ABCC: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
L_8002ABD0:
    // 0x8002ABD0: addiu       $t6, $sp, 0xAC
    ctx->r14 = ADD32(ctx->r29, 0XAC);
    // 0x8002ABD4: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
    // 0x8002ABD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002ABDC:
    // 0x8002ABDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002ABE0:
    // 0x8002ABE0: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8002ABE4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8002ABE8: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8002ABEC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8002ABF0: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8002ABF4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8002ABF8: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8002ABFC: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8002AC00: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8002AC04: bgtz        $t8, L_8002AC38
    if (SIGNED(ctx->r24) > 0) {
        // 0x8002AC08: sw          $t9, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r25;
            goto L_8002AC38;
    }
    // 0x8002AC08: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x8002AC0C: bltzl       $t8, L_8002AC20
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002AC10: addu        $t9, $t9, $t7
        ctx->r25 = ADD32(ctx->r25, ctx->r15);
            goto L_8002AC20;
    }
    goto skip_0;
    // 0x8002AC10: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    skip_0:
    // 0x8002AC14: b           L_8002ABE0
    // 0x8002AC18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002ABE0;
    // 0x8002AC18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002AC1C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
L_8002AC20:
    // 0x8002AC20: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8002AC24: addu        $t8, $at, $t8
    ctx->r24 = ADD32(ctx->r1, ctx->r24);
    // 0x8002AC28: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8002AC2C: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8002AC30: b           L_8002AC40
    // 0x8002AC34: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
        goto L_8002AC40;
    // 0x8002AC34: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
L_8002AC38:
    // 0x8002AC38: b           L_8002ABE0
    // 0x8002AC3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002ABE0;
    // 0x8002AC3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002AC40:
    // 0x8002AC40: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8002AC44: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8002AC48: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8002AC4C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x8002AC50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002AC54: jal         0x80039B38
    // 0x8002AC58: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    __ull_div_recomp(rdram, ctx);
        goto after_0;
    // 0x8002AC58: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x8002AC5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002AC60: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x8002AC64: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x8002AC68: bne         $at, $zero, L_8002ABDC
    if (ctx->r1 != 0) {
        // 0x8002AC6C: sw          $v1, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r3;
            goto L_8002ABDC;
    }
    // 0x8002AC6C: sw          $v1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r3;
    // 0x8002AC70: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002AC74: addiu       $t3, $t3, -0x2F4
    ctx->r11 = ADD32(ctx->r11, -0X2F4);
    // 0x8002AC78: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x8002AC7C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8002AC80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002AC84: andi        $t6, $t9, 0x10
    ctx->r14 = ctx->r25 & 0X10;
    // 0x8002AC88: bne         $t6, $zero, L_8002AD60
    if (ctx->r14 != 0) {
        // 0x8002AC8C: sb          $t7, 0xAC($sp)
        MEM_B(0XAC, ctx->r29) = ctx->r15;
            goto L_8002AD60;
    }
    // 0x8002AC8C: sb          $t7, 0xAC($sp)
    MEM_B(0XAC, ctx->r29) = ctx->r15;
    // 0x8002AC90: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002AC94: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002AC98: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x8002AC9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ACA0: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8002ACA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002ACA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002ACAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ACB0: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8002ACB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ACB8: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002ACBC: addiu       $t6, $t6, 0x138
    ctx->r14 = ADD32(ctx->r14, 0X138);
    // 0x8002ACC0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002ACC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002ACC8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002ACCC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002ACD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ACD4: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8002ACD8: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8002ACDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002ACE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002ACE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ACE8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002ACEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ACF0: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8002ACF4: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8002ACF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002ACFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AD00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002AD04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002AD08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AD0C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8002AD10: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8002AD14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002AD18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002AD1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AD20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002AD24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AD28: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8002AD2C: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8002AD30: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002AD34: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002AD38: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002AD3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002AD40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AD44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AD48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AD4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AD50: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8002AD54: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x8002AD58: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8002AD5C: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
L_8002AD60:
    // 0x8002AD60: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002AD64: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8002AD68: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002AD6C: bltz        $a0, L_8002AF40
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002AD70: lui         $s1, 0xE700
        ctx->r17 = S32(0XE700 << 16);
            goto L_8002AF40;
    }
    // 0x8002AD70: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x8002AD74: addiu       $t8, $sp, 0xAC
    ctx->r24 = ADD32(ctx->r29, 0XAC);
    // 0x8002AD78: lui         $fp, 0x8006
    ctx->r30 = S32(0X8006 << 16);
    // 0x8002AD7C: lui         $s7, 0xFD48
    ctx->r23 = S32(0XFD48 << 16);
    // 0x8002AD80: lui         $s2, 0xF548
    ctx->r18 = S32(0XF548 << 16);
    // 0x8002AD84: ori         $s2, $s2, 0x200
    ctx->r18 = ctx->r18 | 0X200;
    // 0x8002AD88: ori         $s7, $s7, 0x7
    ctx->r23 = ctx->r23 | 0X7;
    // 0x8002AD8C: addiu       $fp, $fp, -0xF30
    ctx->r30 = ADD32(ctx->r30, -0XF30);
    // 0x8002AD90: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x8002AD94: addiu       $s6, $sp, 0xAC
    ctx->r22 = ADD32(ctx->r29, 0XAC);
    // 0x8002AD98: lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XE0);
L_8002AD9C:
    // 0x8002AD9C: lb          $t9, 0x0($t3)
    ctx->r25 = MEM_B(ctx->r11, 0X0);
    // 0x8002ADA0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8002ADA4: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8002ADA8: bnel        $s0, $zero, L_8002ADBC
    if (ctx->r16 != 0) {
        // 0x8002ADAC: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8002ADBC;
    }
    goto skip_1;
    // 0x8002ADAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8002ADB0: bnel        $t3, $s6, L_8002AF30
    if (ctx->r11 != ctx->r22) {
        // 0x8002ADB4: addiu       $t3, $t3, -0x1
        ctx->r11 = ADD32(ctx->r11, -0X1);
            goto L_8002AF30;
    }
    goto skip_2;
    // 0x8002ADB4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    skip_2:
    // 0x8002ADB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8002ADBC:
    // 0x8002ADBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002ADC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002ADC4: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8002ADC8: lb          $t7, 0x0($t3)
    ctx->r15 = MEM_B(ctx->r11, 0X0);
    // 0x8002ADCC: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x8002ADD0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002ADD4: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x8002ADD8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002ADDC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002ADE0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002ADE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ADE8: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8002ADEC: ori         $t6, $t6, 0x30
    ctx->r14 = ctx->r14 | 0X30;
    // 0x8002ADF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002ADF4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002ADF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002ADFC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002AE00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE04: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8002AE08: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8002AE0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002AE10: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002AE14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AE18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002AE1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE20: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x8002AE24: ori         $t7, $t7, 0xC024
    ctx->r15 = ctx->r15 | 0XC024;
    // 0x8002AE28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AE2C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AE30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002AE34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002AE38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002AE40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002AE44: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AE48: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8002AE4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE50: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8002AE54: ori         $t6, $t6, 0x30
    ctx->r14 = ctx->r14 | 0X30;
    // 0x8002AE58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AE5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AE60: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002AE64: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8002AE68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE6C: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8002AE70: ori         $t9, $t9, 0xC024
    ctx->r25 = ctx->r25 | 0XC024;
    // 0x8002AE74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002AE78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002AE7C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8002AE80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002AE84: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002AE88: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8002AE8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AE90: sll         $ra, $s5, 2
    ctx->r31 = S32(ctx->r21 << 2);
    // 0x8002AE94: addu        $t5, $t7, $s3
    ctx->r13 = ADD32(ctx->r15, ctx->r19);
    // 0x8002AE98: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8002AE9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002AEA0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002AEA4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002AEA8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8002AEAC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8002AEB0: addiu       $t9, $s5, 0xA
    ctx->r25 = ADD32(ctx->r21, 0XA);
    // 0x8002AEB4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002AEB8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002AEBC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8002AEC0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8002AEC4: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8002AEC8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8002AECC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002AED0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8002AED4: andi        $t6, $ra, 0xFFF
    ctx->r14 = ctx->r31 & 0XFFF;
    // 0x8002AED8: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x8002AEDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002AEE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AEE4: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8002AEE8: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8002AEEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002AEF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002AEF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AEF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002AEFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AF00: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8002AF04: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8002AF08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002AF0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002AF10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002AF14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002AF18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002AF1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002AF20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002AF24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002AF28: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8002AF2C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
L_8002AF30:
    // 0x8002AF30: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
    // 0x8002AF34: sltu        $at, $t3, $t9
    ctx->r1 = ctx->r11 < ctx->r25 ? 1 : 0;
    // 0x8002AF38: beq         $at, $zero, L_8002AD9C
    if (ctx->r1 == 0) {
        // 0x8002AF3C: addiu       $s3, $s3, 0x7
        ctx->r19 = ADD32(ctx->r19, 0X7);
            goto L_8002AD9C;
    }
    // 0x8002AF3C: addiu       $s3, $s3, 0x7
    ctx->r19 = ADD32(ctx->r19, 0X7);
L_8002AF40:
    // 0x8002AF40: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AF44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002AF48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AF4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002AF50: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002AF54: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002AF58: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF5C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002AF60: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002AF64: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002AF68: jr          $ra
    // 0x8002AF6C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8002AF6C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800325A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800325A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800325AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800325B0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x800325B4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800325B8: addiu       $t7, $t7, -0x5390
    ctx->r15 = ADD32(ctx->r15, -0X5390);
    // 0x800325BC: addiu       $t6, $t6, -0x5370
    ctx->r14 = ADD32(ctx->r14, -0X5370);
    // 0x800325C0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800325C4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800325C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800325CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800325D0: lh          $a1, 0x2D12($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2D12);
    // 0x800325D4: lh          $a0, 0x2D10($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2D10);
    // 0x800325D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800325DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800325E0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800325E4: jal         0x80032040
    // 0x800325E8: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80032040(rdram, ctx);
        goto after_0;
    // 0x800325E8: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_0:
    // 0x800325EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800325F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800325F4: jr          $ra
    // 0x800325F8: nop

    return;
    // 0x800325F8: nop

;}
RECOMP_FUNC void func_80032040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032040: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80032044: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80032048: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003204C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80032050: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80032054: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x80032058: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8003205C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80032060: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80032064: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80032068: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003206C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80032070: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80032074: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80032078: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x8003207C: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80032080: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80032084: lw          $t7, 0x2D20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2D20);
    // 0x80032088: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8003208C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80032090: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80032094: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80032098: bne         $t0, $at, L_80032170
    if (ctx->r8 != ctx->r1) {
        // 0x8003209C: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_80032170;
    }
    // 0x8003209C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800320A0: blez        $a3, L_80032210
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800320A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80032210;
    }
    // 0x800320A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800320A8: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x800320AC: subu        $t1, $t8, $a2
    ctx->r9 = SUB32(ctx->r24, ctx->r6);
    // 0x800320B0: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x800320B4: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800320B8: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
L_800320BC:
    // 0x800320BC: blez        $a2, L_8003215C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800320C0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003215C;
    }
    // 0x800320C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800320C4: andi        $t3, $a2, 0x3
    ctx->r11 = ctx->r6 & 0X3;
    // 0x800320C8: beq         $t3, $zero, L_800320FC
    if (ctx->r11 == 0) {
        // 0x800320CC: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_800320FC;
    }
    // 0x800320CC: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_800320D0:
    // 0x800320D0: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800320D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800320D8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800320DC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800320E0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800320E4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800320E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800320EC: bne         $t2, $a1, L_800320D0
    if (ctx->r10 != ctx->r5) {
        // 0x800320F0: sh          $t8, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r24;
            goto L_800320D0;
    }
    // 0x800320F0: sh          $t8, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r24;
    // 0x800320F4: beql        $a1, $a2, L_80032160
    if (ctx->r5 == ctx->r6) {
        // 0x800320F8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80032160;
    }
    goto skip_0;
    // 0x800320F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
L_800320FC:
    // 0x800320FC: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80032100: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80032104: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80032108: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8003210C: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80032110: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80032114: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80032118: sh          $t7, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r15;
    // 0x8003211C: lbu         $t8, -0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X3);
    // 0x80032120: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80032124: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x80032128: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8003212C: sh          $t6, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r14;
    // 0x80032130: lbu         $t7, -0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X2);
    // 0x80032134: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80032138: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8003213C: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x80032140: sh          $t5, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r13;
    // 0x80032144: lbu         $t6, -0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X1);
    // 0x80032148: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8003214C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80032150: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80032154: bne         $a1, $a2, L_800320FC
    if (ctx->r5 != ctx->r6) {
        // 0x80032158: sh          $t9, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r25;
            goto L_800320FC;
    }
    // 0x80032158: sh          $t9, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r25;
L_8003215C:
    // 0x8003215C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80032160:
    // 0x80032160: bne         $a0, $a3, L_800320BC
    if (ctx->r4 != ctx->r7) {
        // 0x80032164: addu        $v0, $v0, $t1
        ctx->r2 = ADD32(ctx->r2, ctx->r9);
            goto L_800320BC;
    }
    // 0x80032164: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80032168: jr          $ra
    // 0x8003216C: nop

    return;
    // 0x8003216C: nop

L_80032170:
    // 0x80032170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032174: bne         $t0, $at, L_80032210
    if (ctx->r8 != ctx->r1) {
        // 0x80032178: nop
    
            goto L_80032210;
    }
    // 0x80032178: nop

    // 0x8003217C: blez        $a3, L_80032210
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80032180: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80032210;
    }
    // 0x80032180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80032184: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x80032188: subu        $t1, $t5, $a2
    ctx->r9 = SUB32(ctx->r13, ctx->r6);
    // 0x8003218C: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x80032190: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x80032194: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
L_80032198:
    // 0x80032198: blez        $a2, L_80032204
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003219C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80032204;
    }
    // 0x8003219C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800321A0: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
L_800321A4:
    // 0x800321A4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800321A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800321AC: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x800321B0: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800321B4: beq         $t7, $zero, L_800321D4
    if (ctx->r15 == 0) {
        // 0x800321B8: andi        $t6, $t3, 0xF
        ctx->r14 = ctx->r11 & 0XF;
            goto L_800321D4;
    }
    // 0x800321B8: andi        $t6, $t3, 0xF
    ctx->r14 = ctx->r11 & 0XF;
    // 0x800321BC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800321C0: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x800321C4: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x800321C8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800321CC: b           L_800321D8
    // 0x800321D0: sh          $t5, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r13;
        goto L_800321D8;
    // 0x800321D0: sh          $t5, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r13;
L_800321D4:
    // 0x800321D4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800321D8:
    // 0x800321D8: beq         $t6, $zero, L_800321F8
    if (ctx->r14 == 0) {
        // 0x800321DC: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800321F8;
    }
    // 0x800321DC: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800321E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800321E4: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800321E8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800321EC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800321F0: b           L_800321FC
    // 0x800321F4: sh          $t9, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r25;
        goto L_800321FC;
    // 0x800321F4: sh          $t9, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r25;
L_800321F8:
    // 0x800321F8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800321FC:
    // 0x800321FC: bnel        $at, $zero, L_800321A4
    if (ctx->r1 != 0) {
        // 0x80032200: lbu         $t3, 0x0($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X0);
            goto L_800321A4;
    }
    goto skip_1;
    // 0x80032200: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    skip_1:
L_80032204:
    // 0x80032204: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80032208: bne         $a0, $a3, L_80032198
    if (ctx->r4 != ctx->r7) {
        // 0x8003220C: addu        $v0, $v0, $t1
        ctx->r2 = ADD32(ctx->r2, ctx->r9);
            goto L_80032198;
    }
    // 0x8003220C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
L_80032210:
    // 0x80032210: jr          $ra
    // 0x80032214: nop

    return;
    // 0x80032214: nop

;}
RECOMP_FUNC void func_80036980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003698C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80036990: jal         0x80036820
    // 0x80036994: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x80036994: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80036998: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003699C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800369A0: jal         0x80036850
    // 0x800369A4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x800369A4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800369A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800369AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800369B0: jr          $ra
    // 0x800369B4: nop

    return;
    // 0x800369B4: nop

;}
RECOMP_FUNC void func_8000DDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDB0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8000DDB4: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8000DDB8: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8000DDBC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8000DDC0: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000DDC4: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8000DDC8: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8000DDCC: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8000DDD0: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8000DDD4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8000DDD8: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8000DDDC: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8000DDE0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8000DDE4: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8000DDE8: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8000DDEC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8000DDF0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8000DDF4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8000DDF8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000DDFC: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x8000DE00: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x8000DE04: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000DE08: lw          $t6, 0x4F18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F18);
    // 0x8000DE0C: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x8000DE10: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000DE14: lw          $v1, 0x20($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X20);
    // 0x8000DE18: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8000DE1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DE20: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8000DE24: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000DE28: addiu       $fp, $sp, 0xB0
    ctx->r30 = ADD32(ctx->r29, 0XB0);
    // 0x8000DE2C: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8000DE30: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
    // 0x8000DE34: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8000DE38: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8000DE3C: beq         $s4, $zero, L_8000E0C4
    if (ctx->r20 == 0) {
        // 0x8000DE40: sw          $t0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r8;
            goto L_8000E0C4;
    }
    // 0x8000DE40: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x8000DE44: ldc1        $f30, 0x1208($at)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r1, 0X1208);
    // 0x8000DE48: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DE4C: ldc1        $f26, 0x1210($at)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r1, 0X1210);
    // 0x8000DE50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DE54: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000DE58: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000DE5C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8000DE60: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x8000DE64: addiu       $s2, $s2, -0x4D08
    ctx->r18 = ADD32(ctx->r18, -0X4D08);
    // 0x8000DE68: ldc1        $f24, 0x1218($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X1218);
    // 0x8000DE6C: addiu       $s6, $s6, 0x6DC0
    ctx->r22 = ADD32(ctx->r22, 0X6DC0);
    // 0x8000DE70: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
L_8000DE74:
    // 0x8000DE74: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x8000DE78: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000DE7C: lh          $t2, 0x14($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X14);
    // 0x8000DE80: bnel        $t1, $t2, L_8000E0BC
    if (ctx->r9 != ctx->r10) {
        // 0x8000DE84: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_8000E0BC;
    }
    goto skip_0;
    // 0x8000DE84: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_0:
    // 0x8000DE88: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000DE8C: lwc1        $f6, 0xC($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8000DE90: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000DE94: lwc1        $f10, 0x14($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8000DE98: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000DE9C: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000DEA0: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000DEA4: nop

    // 0x8000DEA8: mul.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8000DEAC: jal         0x80034F60
    // 0x8000DEB0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000DEB0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x8000DEB4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DEB8: lwc1        $f4, 0x1220($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1220);
    // 0x8000DEBC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8000DEC0: nop

    // 0x8000DEC4: bc1fl       L_8000E0BC
    if (!c1cs) {
        // 0x8000DEC8: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_8000E0BC;
    }
    goto skip_1;
    // 0x8000DEC8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_1:
    // 0x8000DECC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000DED0: jal         0x80023210
    // 0x8000DED4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80023210(rdram, ctx);
        goto after_1;
    // 0x8000DED4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x8000DED8: lwc1        $f14, 0x2C($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x8000DEDC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000DEE0: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8000DEE4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000DEE8: add.d       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f24.d); 
    ctx->f10.d = ctx->f8.d + ctx->f24.d;
    // 0x8000DEEC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8000DEF0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8000DEF4: c.lt.d      $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f2.d < ctx->f30.d;
    // 0x8000DEF8: nop

    // 0x8000DEFC: bc1fl       L_8000DF14
    if (!c1cs) {
        // 0x8000DF00: c.lt.d      $f24, $f2
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.d < ctx->f2.d;
            goto L_8000DF14;
    }
    goto skip_2;
    // 0x8000DF00: c.lt.d      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.d < ctx->f2.d;
    skip_2:
    // 0x8000DF04: add.d       $f16, $f2, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f26.d); 
    ctx->f16.d = ctx->f2.d + ctx->f26.d;
    // 0x8000DF08: b           L_8000DF28
    // 0x8000DF0C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
        goto L_8000DF28;
    // 0x8000DF0C: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x8000DF10: c.lt.d      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.d < ctx->f2.d;
L_8000DF14:
    // 0x8000DF14: nop

    // 0x8000DF18: bc1fl       L_8000DF2C
    if (!c1cs) {
        // 0x8000DF1C: c.lt.s      $f12, $f28
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
            goto L_8000DF2C;
    }
    goto skip_3;
    // 0x8000DF1C: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    skip_3:
    // 0x8000DF20: sub.d       $f18, $f2, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f26.d); 
    ctx->f18.d = ctx->f2.d - ctx->f26.d;
    // 0x8000DF24: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
L_8000DF28:
    // 0x8000DF28: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
L_8000DF2C:
    // 0x8000DF2C: nop

    // 0x8000DF30: bc1f        L_8000DF3C
    if (!c1cs) {
        // 0x8000DF34: nop
    
            goto L_8000DF3C;
    }
    // 0x8000DF34: nop

    // 0x8000DF38: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8000DF3C:
    // 0x8000DF3C: ldc1        $f6, 0x1228($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1228);
    // 0x8000DF40: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8000DF44: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000DF48: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8000DF4C: lwc1        $f10, 0x6EC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EC8);
    // 0x8000DF50: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8000DF54: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8000DF58: nop

    // 0x8000DF5C: bc1fl       L_8000E0BC
    if (!c1cs) {
        // 0x8000DF60: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_8000E0BC;
    }
    goto skip_4;
    // 0x8000DF60: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_4:
    // 0x8000DF64: bne         $s3, $zero, L_8000DFA8
    if (ctx->r19 != 0) {
        // 0x8000DF68: lui         $t6, 0xBA00
        ctx->r14 = S32(0XBA00 << 16);
            goto L_8000DFA8;
    }
    // 0x8000DF68: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8000DF6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000DF70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000DF74: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8000DF78: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8000DF7C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8000DF80: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x8000DF84: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000DF88: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000DF8C: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x8000DF90: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x8000DF94: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8000DF98: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000DF9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000DFA0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000DFA4: lwc1        $f14, 0x2C($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X2C);
L_8000DFA8:
    // 0x8000DFA8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000DFAC: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x8000DFB0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8000DFB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000DFB8: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000DFBC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8000DFC0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8000DFC4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8000DFC8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000DFCC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8000DFD0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000DFD4: jal         0x80023360
    // 0x8000DFD8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_80023360(rdram, ctx);
        goto after_2;
    // 0x8000DFD8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8000DFDC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8000DFE0: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8000DFE4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8000DFE8: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x8000DFEC: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x8000DFF0: jal         0x80035200
    // 0x8000DFF4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x8000DFF4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_3:
    // 0x8000DFF8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000DFFC: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x8000E000: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x8000E004: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8000E008: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8000E00C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8000E010: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000E014: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8000E018: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8000E01C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8000E020: addiu       $t5, $t4, 0xC0
    ctx->r13 = ADD32(ctx->r12, 0XC0);
    // 0x8000E024: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000E028: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000E02C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8000E030: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8000E034: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000E038: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000E03C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8000E040: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8000E044: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8000E048: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8000E04C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8000E050: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000E054: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8000E058: addiu       $t5, $t5, 0x4260
    ctx->r13 = ADD32(ctx->r13, 0X4260);
    // 0x8000E05C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000E060: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000E064: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000E068: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8000E06C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8000E070: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8000E074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000E078: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000E07C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8000E080: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8000E084: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x8000E088: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000E08C: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x8000E090: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000E094: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8000E098: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8000E09C: jal         0x80011860
    // 0x8000E0A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80011860(rdram, ctx);
        goto after_4;
    // 0x8000E0A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8000E0A4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000E0A8: lw          $t6, 0x4F34($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F34);
    // 0x8000E0AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E0B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000E0B4: sw          $t7, 0x4F34($at)
    MEM_W(0X4F34, ctx->r1) = ctx->r15;
    // 0x8000E0B8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_8000E0BC:
    // 0x8000E0BC: bnel        $s4, $zero, L_8000DE74
    if (ctx->r20 != 0) {
        // 0x8000E0C0: lw          $s0, 0x0($s5)
        ctx->r16 = MEM_W(ctx->r21, 0X0);
            goto L_8000DE74;
    }
    goto skip_5;
    // 0x8000E0C0: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    skip_5:
L_8000E0C4:
    // 0x8000E0C4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8000E0C8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000E0CC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8000E0D0: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8000E0D4: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8000E0D8: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8000E0DC: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8000E0E0: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8000E0E4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8000E0E8: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8000E0EC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8000E0F0: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8000E0F4: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8000E0F8: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8000E0FC: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8000E100: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8000E104: jr          $ra
    // 0x8000E108: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8000E108: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80026A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A40: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80026A44: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026A48: sh          $t6, -0x2F4($at)
    MEM_H(-0X2F4, ctx->r1) = ctx->r14;
    // 0x80026A4C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026A50: sh          $zero, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = 0;
    // 0x80026A54: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026A58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80026A5C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80026A60: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80026A64: sb          $t9, -0x2FD($at)
    MEM_B(-0X2FD, ctx->r1) = ctx->r25;
    // 0x80026A68: sb          $t8, -0x2FE($at)
    MEM_B(-0X2FE, ctx->r1) = ctx->r24;
    // 0x80026A6C: sb          $t7, -0x2FF($at)
    MEM_B(-0X2FF, ctx->r1) = ctx->r15;
    // 0x80026A70: sb          $zero, -0x300($at)
    MEM_B(-0X300, ctx->r1) = 0;
    // 0x80026A74: jr          $ra
    // 0x80026A78: nop

    return;
    // 0x80026A78: nop

;}
RECOMP_FUNC void func_80036A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036A60: jr          $ra
    // 0x80036A64: nop

    return;
    // 0x80036A64: nop

;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F4D0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8003F4D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003F4D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003F4DC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003F4E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003F4E4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003F4E8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003F4EC: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x8003F4F0: lui         $s5, 0x8007
    ctx->r21 = S32(0X8007 << 16);
    // 0x8003F4F4: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x8003F4F8: lui         $s7, 0x8007
    ctx->r23 = S32(0X8007 << 16);
    // 0x8003F4FC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8003F500: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8003F504: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8003F508: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003F50C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003F510: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003F514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003F518: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8003F51C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x8003F520: addiu       $s7, $s7, 0xAA0
    ctx->r23 = ADD32(ctx->r23, 0XAA0);
    // 0x8003F524: addiu       $s6, $s6, 0x1F24
    ctx->r22 = ADD32(ctx->r22, 0X1F24);
    // 0x8003F528: addiu       $s5, $s5, 0xAC4
    ctx->r21 = ADD32(ctx->r21, 0XAC4);
    // 0x8003F52C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_8003F530:
    // 0x8003F530: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8003F534: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8003F538: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8003F53C: beq         $v0, $zero, L_8003F564
    if (ctx->r2 == 0) {
        // 0x8003F540: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F564;
    }
    // 0x8003F540: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003F544: beql        $v1, $v0, L_8003F568
    if (ctx->r3 == ctx->r2) {
        // 0x8003F548: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_8003F568;
    }
    goto skip_0;
    // 0x8003F548: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x8003F54C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_8003F550:
    // 0x8003F550: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F554: beq         $v0, $zero, L_8003F564
    if (ctx->r2 == 0) {
        // 0x8003F558: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F564;
    }
    // 0x8003F558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003F55C: bnel        $v1, $v0, L_8003F550
    if (ctx->r3 != ctx->r2) {
        // 0x8003F560: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_8003F550;
    }
    goto skip_1;
    // 0x8003F560: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_8003F564:
    // 0x8003F564: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_8003F568:
    // 0x8003F568: blez        $v0, L_8003F5A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003F56C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003F5A0;
    }
    // 0x8003F56C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F570: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003F574: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003F578: jalr        $s4
    // 0x8003F57C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8003F57C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x8003F580: beq         $v0, $zero, L_8003F598
    if (ctx->r2 == 0) {
        // 0x8003F584: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F598;
    }
    // 0x8003F584: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F588: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F58C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8003F590: b           L_8003F5A0
    // 0x8003F594: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8003F5A0;
    // 0x8003F594: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8003F598:
    // 0x8003F598: b           L_8003FAE8
    // 0x8003F59C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F59C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F5A0:
    // 0x8003F5A0: bne         $s0, $zero, L_8003F5B0
    if (ctx->r16 != 0) {
        // 0x8003F5A4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003F5B0;
    }
    // 0x8003F5A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F5A8: b           L_8003FAE8
    // 0x8003F5AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F5AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F5B0:
    // 0x8003F5B0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x8003F5B4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F5B8: jal         0x8003FB74
    // 0x8003F5BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x8003F5BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8003F5C0: beq         $v0, $zero, L_8003F600
    if (ctx->r2 == 0) {
        // 0x8003F5C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F600;
    }
    // 0x8003F5C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8003F5C8:
    // 0x8003F5C8: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x8003F5CC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8003F5D0: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8003F5D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8003F5D8: lw          $t7, 0x1F2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1F2C);
    // 0x8003F5DC: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8003F5E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F5E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8003F5E8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8003F5EC: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x8003F5F0: jal         0x8003FB74
    // 0x8003F5F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x8003F5F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x8003F5F8: bne         $v0, $zero, L_8003F5C8
    if (ctx->r2 != 0) {
        // 0x8003F5FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003F5C8;
    }
    // 0x8003F5FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8003F600:
    // 0x8003F600: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F604: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8003F608: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8003F60C: bne         $v0, $t6, L_8003F654
    if (ctx->r2 != ctx->r14) {
        // 0x8003F610: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_8003F654;
    }
    // 0x8003F610: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003F614: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x8003F618: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F61C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8003F620: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x8003F624: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x8003F628: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8003F62C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F630: bgez        $t8, L_8003F64C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003F634: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_8003F64C;
    }
    // 0x8003F634: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8003F638: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8003F63C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x8003F640: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x8003F644: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x8003F648: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_8003F64C:
    // 0x8003F64C: b           L_8003F6B0
    // 0x8003F650: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8003F6B0;
    // 0x8003F650: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8003F654:
    // 0x8003F654: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x8003F658: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F65C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003F660: bne         $at, $zero, L_8003F6B0
    if (ctx->r1 != 0) {
        // 0x8003F664: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003F6B0;
    }
    // 0x8003F664: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8003F668: beql        $at, $zero, L_8003F6B4
    if (ctx->r1 == 0) {
        // 0x8003F66C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8003F6B4;
    }
    goto skip_2;
    // 0x8003F66C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x8003F670: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_8003F674:
    // 0x8003F674: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x8003F678: beql        $at, $zero, L_8003F698
    if (ctx->r1 == 0) {
        // 0x8003F67C: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_8003F698;
    }
    goto skip_3;
    // 0x8003F67C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x8003F680: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F684: mflo        $t7
    ctx->r15 = lo;
    // 0x8003F688: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x8003F68C: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x8003F690: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x8003F694: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_8003F698:
    // 0x8003F698: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F69C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003F6A0: bne         $at, $zero, L_8003F6B0
    if (ctx->r1 != 0) {
        // 0x8003F6A4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003F6B0;
    }
    // 0x8003F6A4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8003F6A8: bnel        $at, $zero, L_8003F674
    if (ctx->r1 != 0) {
        // 0x8003F6AC: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_8003F674;
    }
    goto skip_4;
    // 0x8003F6AC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_8003F6B0:
    // 0x8003F6B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_8003F6B4:
    // 0x8003F6B4: beq         $a1, $at, L_8003F6C8
    if (ctx->r5 == ctx->r1) {
        // 0x8003F6B8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8003F6C8;
    }
    // 0x8003F6B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8003F6BC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x8003F6C0: b           L_8003F75C
    // 0x8003F6C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8003F75C;
    // 0x8003F6C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8003F6C8:
    // 0x8003F6C8: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8003F6CC: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8003F6D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F6D4: bne         $v0, $t7, L_8003F700
    if (ctx->r2 != ctx->r15) {
        // 0x8003F6D8: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_8003F700;
    }
    // 0x8003F6D8: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x8003F6DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003F6E0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8003F6E4: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x8003F6E8: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8003F6EC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8003F6F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F6F4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x8003F6F8: b           L_8003F75C
    // 0x8003F6FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8003F75C;
    // 0x8003F6FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8003F700:
    // 0x8003F700: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x8003F704: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F708: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003F70C: bne         $at, $zero, L_8003F75C
    if (ctx->r1 != 0) {
        // 0x8003F710: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003F75C;
    }
    // 0x8003F710: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8003F714: beq         $at, $zero, L_8003F75C
    if (ctx->r1 == 0) {
        // 0x8003F718: nop
    
            goto L_8003F75C;
    }
    // 0x8003F718: nop

    // 0x8003F71C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_8003F720:
    // 0x8003F720: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x8003F724: beql        $at, $zero, L_8003F744
    if (ctx->r1 == 0) {
        // 0x8003F728: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_8003F744;
    }
    goto skip_5;
    // 0x8003F728: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x8003F72C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F730: mflo        $t7
    ctx->r15 = lo;
    // 0x8003F734: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8003F738: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8003F73C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x8003F740: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_8003F744:
    // 0x8003F744: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F748: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003F74C: bne         $at, $zero, L_8003F75C
    if (ctx->r1 != 0) {
        // 0x8003F750: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003F75C;
    }
    // 0x8003F750: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8003F754: bnel        $at, $zero, L_8003F720
    if (ctx->r1 != 0) {
        // 0x8003F758: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_8003F720;
    }
    goto skip_6;
    // 0x8003F758: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_8003F75C:
    // 0x8003F75C: jal         0x8003FB74
    // 0x8003F760: addiu       $a0, $a0, 0x1F20
    ctx->r4 = ADD32(ctx->r4, 0X1F20);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x8003F760: addiu       $a0, $a0, 0x1F20
    ctx->r4 = ADD32(ctx->r4, 0X1F20);
    after_3:
    // 0x8003F764: beq         $v0, $zero, L_8003F77C
    if (ctx->r2 == 0) {
        // 0x8003F768: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_8003F77C;
    }
    // 0x8003F768: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x8003F76C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F770: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003F774: b           L_8003F780
    // 0x8003F778: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_8003F780;
    // 0x8003F778: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_8003F77C:
    // 0x8003F77C: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_8003F780:
    // 0x8003F780: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x8003F784: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8003F788: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8003F78C: bne         $v0, $t7, L_8003F7AC
    if (ctx->r2 != ctx->r15) {
        // 0x8003F790: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_8003F7AC;
    }
    // 0x8003F790: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x8003F794: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8003F798: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8003F79C: bne         $v0, $t8, L_8003F7AC
    if (ctx->r2 != ctx->r24) {
        // 0x8003F7A0: nop
    
            goto L_8003F7AC;
    }
    // 0x8003F7A0: nop

    // 0x8003F7A4: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x8003F7A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8003F7AC:
    // 0x8003F7AC: jal         0x8003EE60
    // 0x8003F7B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_5_8003EE60(rdram, ctx);
        goto after_4;
    // 0x8003F7B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x8003F7B4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8003F7B8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8003F7BC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8003F7C0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8003F7C4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8003F7C8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8003F7CC: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8003F7D0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8003F7D4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8003F7D8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8003F7DC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8003F7E0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8003F7E4: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8003F7E8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8003F7EC: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x8003F7F0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8003F7F4: bne         $t8, $zero, L_8003F860
    if (ctx->r24 != 0) {
        // 0x8003F7F8: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_8003F860;
    }
    // 0x8003F7F8: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003F7FC: beql        $t6, $zero, L_8003F864
    if (ctx->r14 == 0) {
        // 0x8003F800: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8003F864;
    }
    goto skip_7;
    // 0x8003F800: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x8003F804: beq         $t6, $zero, L_8003F860
    if (ctx->r14 == 0) {
        // 0x8003F808: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003F860;
    }
    // 0x8003F808: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003F80C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003F810:
    // 0x8003F810: bne         $at, $zero, L_8003F820
    if (ctx->r1 != 0) {
        // 0x8003F814: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003F820;
    }
    // 0x8003F814: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003F818: b           L_8003F820
    // 0x8003F81C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003F820;
    // 0x8003F81C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003F820:
    // 0x8003F820: blez        $s0, L_8003F854
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003F824: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003F854;
    }
    // 0x8003F824: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F828: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003F82C: jalr        $s4
    // 0x8003F830: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x8003F830: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8003F834: beq         $v0, $zero, L_8003F84C
    if (ctx->r2 == 0) {
        // 0x8003F838: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F84C;
    }
    // 0x8003F838: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F83C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F840: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003F844: b           L_8003F854
    // 0x8003F848: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003F854;
    // 0x8003F848: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003F84C:
    // 0x8003F84C: b           L_8003FAE8
    // 0x8003F850: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F850: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F854:
    // 0x8003F854: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8003F858: bgtzl       $s1, L_8003F810
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003F85C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003F810;
    }
    goto skip_8;
    // 0x8003F85C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_8003F860:
    // 0x8003F860: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_8003F864:
    // 0x8003F864: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F868: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8003F86C: blezl       $t9, L_8003F8A4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003F870: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_8003F8A4;
    }
    goto skip_9;
    // 0x8003F870: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x8003F874: jalr        $s4
    // 0x8003F878: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x8003F878: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x8003F87C: beq         $v0, $zero, L_8003F898
    if (ctx->r2 == 0) {
        // 0x8003F880: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F898;
    }
    // 0x8003F880: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F884: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F888: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8003F88C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003F890: b           L_8003F8A0
    // 0x8003F894: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003F8A0;
    // 0x8003F894: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003F898:
    // 0x8003F898: b           L_8003FAE8
    // 0x8003F89C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F89C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F8A0:
    // 0x8003F8A0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_8003F8A4:
    // 0x8003F8A4: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003F8A8: beql        $t6, $zero, L_8003F910
    if (ctx->r14 == 0) {
        // 0x8003F8AC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_8003F910;
    }
    goto skip_10;
    // 0x8003F8AC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x8003F8B0: beq         $t6, $zero, L_8003F90C
    if (ctx->r14 == 0) {
        // 0x8003F8B4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003F90C;
    }
    // 0x8003F8B4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003F8B8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003F8BC:
    // 0x8003F8BC: bne         $at, $zero, L_8003F8CC
    if (ctx->r1 != 0) {
        // 0x8003F8C0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003F8CC;
    }
    // 0x8003F8C0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003F8C4: b           L_8003F8CC
    // 0x8003F8C8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003F8CC;
    // 0x8003F8C8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003F8CC:
    // 0x8003F8CC: blez        $s0, L_8003F900
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003F8D0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003F900;
    }
    // 0x8003F8D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F8D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003F8D8: jalr        $s4
    // 0x8003F8DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x8003F8DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8003F8E0: beq         $v0, $zero, L_8003F8F8
    if (ctx->r2 == 0) {
        // 0x8003F8E4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F8F8;
    }
    // 0x8003F8E4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F8E8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F8EC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003F8F0: b           L_8003F900
    // 0x8003F8F4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003F900;
    // 0x8003F8F4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003F8F8:
    // 0x8003F8F8: b           L_8003FAE8
    // 0x8003F8FC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F8FC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F900:
    // 0x8003F900: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8003F904: bgtzl       $s1, L_8003F8BC
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003F908: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003F8BC;
    }
    goto skip_11;
    // 0x8003F908: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_8003F90C:
    // 0x8003F90C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_8003F910:
    // 0x8003F910: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F914: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8003F918: blezl       $t9, L_8003F950
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003F91C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_8003F950;
    }
    goto skip_12;
    // 0x8003F91C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x8003F920: jalr        $s4
    // 0x8003F924: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x8003F924: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x8003F928: beq         $v0, $zero, L_8003F944
    if (ctx->r2 == 0) {
        // 0x8003F92C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F944;
    }
    // 0x8003F92C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F930: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F934: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8003F938: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003F93C: b           L_8003F94C
    // 0x8003F940: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003F94C;
    // 0x8003F940: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003F944:
    // 0x8003F944: b           L_8003FAE8
    // 0x8003F948: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F948: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F94C:
    // 0x8003F94C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_8003F950:
    // 0x8003F950: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003F954: beql        $t6, $zero, L_8003F9BC
    if (ctx->r14 == 0) {
        // 0x8003F958: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_8003F9BC;
    }
    goto skip_13;
    // 0x8003F958: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x8003F95C: beq         $t6, $zero, L_8003F9B8
    if (ctx->r14 == 0) {
        // 0x8003F960: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003F9B8;
    }
    // 0x8003F960: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003F964: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003F968:
    // 0x8003F968: bne         $at, $zero, L_8003F978
    if (ctx->r1 != 0) {
        // 0x8003F96C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003F978;
    }
    // 0x8003F96C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003F970: b           L_8003F978
    // 0x8003F974: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003F978;
    // 0x8003F974: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003F978:
    // 0x8003F978: blez        $s0, L_8003F9AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003F97C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003F9AC;
    }
    // 0x8003F97C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F980: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003F984: jalr        $s4
    // 0x8003F988: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x8003F988: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x8003F98C: beq         $v0, $zero, L_8003F9A4
    if (ctx->r2 == 0) {
        // 0x8003F990: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F9A4;
    }
    // 0x8003F990: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F994: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F998: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003F99C: b           L_8003F9AC
    // 0x8003F9A0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003F9AC;
    // 0x8003F9A0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003F9A4:
    // 0x8003F9A4: b           L_8003FAE8
    // 0x8003F9A8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F9A8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F9AC:
    // 0x8003F9AC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8003F9B0: bgtzl       $s1, L_8003F968
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003F9B4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003F968;
    }
    goto skip_14;
    // 0x8003F9B4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_8003F9B8:
    // 0x8003F9B8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_8003F9BC:
    // 0x8003F9BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003F9C0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8003F9C4: blez        $t9, L_8003F9FC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003F9C8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8003F9FC;
    }
    // 0x8003F9C8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8003F9CC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8003F9D0: jalr        $s4
    // 0x8003F9D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x8003F9D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x8003F9D8: beq         $v0, $zero, L_8003F9F4
    if (ctx->r2 == 0) {
        // 0x8003F9DC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003F9F4;
    }
    // 0x8003F9DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003F9E0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8003F9E4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8003F9E8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8003F9EC: b           L_8003F9FC
    // 0x8003F9F0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8003F9FC;
    // 0x8003F9F0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8003F9F4:
    // 0x8003F9F4: b           L_8003FAE8
    // 0x8003F9F8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003F9F8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003F9FC:
    // 0x8003F9FC: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8003FA00: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003FA04: beql        $t8, $zero, L_8003FA6C
    if (ctx->r24 == 0) {
        // 0x8003FA08: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_8003FA6C;
    }
    goto skip_15;
    // 0x8003FA08: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x8003FA0C: beq         $t8, $zero, L_8003FA68
    if (ctx->r24 == 0) {
        // 0x8003FA10: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003FA68;
    }
    // 0x8003FA10: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003FA14: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003FA18:
    // 0x8003FA18: bne         $at, $zero, L_8003FA28
    if (ctx->r1 != 0) {
        // 0x8003FA1C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003FA28;
    }
    // 0x8003FA1C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003FA20: b           L_8003FA28
    // 0x8003FA24: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003FA28;
    // 0x8003FA24: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003FA28:
    // 0x8003FA28: blez        $s0, L_8003FA5C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003FA2C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003FA5C;
    }
    // 0x8003FA2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003FA30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003FA34: jalr        $s4
    // 0x8003FA38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x8003FA38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8003FA3C: beq         $v0, $zero, L_8003FA54
    if (ctx->r2 == 0) {
        // 0x8003FA40: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FA54;
    }
    // 0x8003FA40: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FA44: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8003FA48: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003FA4C: b           L_8003FA5C
    // 0x8003FA50: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8003FA5C;
    // 0x8003FA50: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8003FA54:
    // 0x8003FA54: b           L_8003FAE8
    // 0x8003FA58: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003FA58: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003FA5C:
    // 0x8003FA5C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8003FA60: bgtzl       $s1, L_8003FA18
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003FA64: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003FA18;
    }
    goto skip_16;
    // 0x8003FA64: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_8003FA68:
    // 0x8003FA68: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_8003FA6C:
    // 0x8003FA6C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8003FA70: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x8003FA74: beq         $t8, $zero, L_8003FAE0
    if (ctx->r24 == 0) {
        // 0x8003FA78: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_8003FAE0;
    }
    // 0x8003FA78: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003FA7C: beq         $t7, $zero, L_8003FAE0
    if (ctx->r15 == 0) {
        // 0x8003FA80: nop
    
            goto L_8003FAE0;
    }
    // 0x8003FA80: nop

    // 0x8003FA84: beq         $t7, $zero, L_8003FAE0
    if (ctx->r15 == 0) {
        // 0x8003FA88: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_8003FAE0;
    }
    // 0x8003FA88: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8003FA8C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003FA90:
    // 0x8003FA90: bne         $at, $zero, L_8003FAA0
    if (ctx->r1 != 0) {
        // 0x8003FA94: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003FAA0;
    }
    // 0x8003FA94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003FA98: b           L_8003FAA0
    // 0x8003FA9C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003FAA0;
    // 0x8003FA9C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003FAA0:
    // 0x8003FAA0: blez        $s0, L_8003FAD4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003FAA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003FAD4;
    }
    // 0x8003FAA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003FAA8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003FAAC: jalr        $s4
    // 0x8003FAB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x8003FAB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x8003FAB4: beq         $v0, $zero, L_8003FACC
    if (ctx->r2 == 0) {
        // 0x8003FAB8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003FACC;
    }
    // 0x8003FAB8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003FABC: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8003FAC0: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x8003FAC4: b           L_8003FAD4
    // 0x8003FAC8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003FAD4;
    // 0x8003FAC8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003FACC:
    // 0x8003FACC: b           L_8003FAE8
    // 0x8003FAD0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8003FAE8;
    // 0x8003FAD0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003FAD4:
    // 0x8003FAD4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8003FAD8: bgtzl       $s1, L_8003FA90
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003FADC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003FA90;
    }
    goto skip_17;
    // 0x8003FADC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_8003FAE0:
    // 0x8003FAE0: b           L_8003F530
    // 0x8003FAE4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_8003F530;
    // 0x8003FAE4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_8003FAE8:
    // 0x8003FAE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FAEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003FAF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FAF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003FAF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003FAFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003FB00: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FB04: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003FB08: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003FB0C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003FB10: jr          $ra
    // 0x8003FB14: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8003FB14: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_80014FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014FDC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80014FE0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014FEC: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80014FF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80014FF4: nop

    // 0x80014FF8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80014FFC: lw          $t6, 0x64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X64);
    // 0x80015000: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015004: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80015008: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x8001500C: lwc1        $f16, 0x1C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80015010: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80015014: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015018: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x8001501C: lwc1        $f12, 0x10($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80015020: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015024: jal         0x800232F4
    // 0x80015028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80015028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001502C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80015030: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015034: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015038: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001503C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80015040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015048: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001504C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80015050: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80015054: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015058: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001505C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80015060: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80015064: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80015068: bnel        $t8, $at, L_80015084
    if (ctx->r24 != ctx->r1) {
        // 0x8001506C: lwc1        $f6, 0x1C($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_80015084;
    }
    goto skip_0;
    // 0x8001506C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x80015070: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80015074: lwc1        $f4, 0x94($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X94);
    // 0x80015078: b           L_800150B8
    // 0x8001507C: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
        goto L_800150B8;
    // 0x8001507C: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80015080: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
L_80015084:
    // 0x80015084: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015088: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001508C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015090: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80015094: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015098: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001509C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800150A0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800150A4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800150A8: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x800150AC: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x800150B0: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800150B4: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
L_800150B8:
    // 0x800150B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800150BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800150C0: jr          $ra
    // 0x800150C4: nop

    return;
    // 0x800150C4: nop

;}
RECOMP_FUNC void func_80036A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036A68: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80036A6C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80036A70: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80036A74: lw          $s1, 0x990($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X990);
    // 0x80036A78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80036A7C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80036A80: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80036A84: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80036A88: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80036A8C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80036A90: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80036A94: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80036A98: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80036A9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80036AA0: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80036AA4: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x80036AA8: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x80036AAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80036AB0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80036AB4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80036AB8: bne         $t7, $zero, L_80036ACC
    if (ctx->r15 != 0) {
        // 0x80036ABC: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_80036ACC;
    }
    // 0x80036ABC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80036AC0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80036AC4: b           L_80036CCC
    // 0x80036AC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80036CCC;
    // 0x80036AC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80036ACC:
    // 0x80036ACC: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80036AD0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80036AD4: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x80036AD8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80036ADC: beq         $v0, $zero, L_80036B18
    if (ctx->r2 == 0) {
        // 0x80036AE0: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_80036B18;
    }
    // 0x80036AE0: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x80036AE4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036AE8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_80036AEC:
    // 0x80036AEC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x80036AF0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80036AF4: beql        $at, $zero, L_80036B10
    if (ctx->r1 == 0) {
        // 0x80036AF8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_80036B10;
    }
    goto skip_0;
    // 0x80036AF8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80036AFC: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x80036B00: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80036B04: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036B08: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x80036B0C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_80036B10:
    // 0x80036B10: bnel        $v0, $zero, L_80036AEC
    if (ctx->r2 != 0) {
        // 0x80036B14: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_80036AEC;
    }
    goto skip_1;
    // 0x80036B14: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_80036B18:
    // 0x80036B18: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80036B1C: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036B20: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x80036B24: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x80036B28: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036B2C: beq         $at, $zero, L_80036C10
    if (ctx->r1 == 0) {
        // 0x80036B30: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_80036C10;
    }
    // 0x80036B30: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80036B34: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80036B38: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80036B3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036B40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80036B44: ldc1        $f20, 0x1C08($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1C08);
L_80036B48:
    // 0x80036B48: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x80036B4C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x80036B50: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x80036B54: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x80036B58: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x80036B5C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x80036B60: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80036B64: jalr        $t9
    // 0x80036B68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80036B68: nop

    after_0:
    // 0x80036B6C: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x80036B70: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80036B74: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80036B78: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80036B7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80036B80: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80036B84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80036B88: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80036B8C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80036B90: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x80036B94: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x80036B98: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80036B9C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80036BA0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80036BA4: nop

    // 0x80036BA8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80036BAC: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x80036BB0: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x80036BB4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80036BB8: beql        $v1, $zero, L_80036BF8
    if (ctx->r3 == 0) {
        // 0x80036BBC: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_80036BF8;
    }
    goto skip_2;
    // 0x80036BBC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x80036BC0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036BC4: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_80036BC8:
    // 0x80036BC8: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x80036BCC: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80036BD0: beql        $at, $zero, L_80036BEC
    if (ctx->r1 == 0) {
        // 0x80036BD4: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80036BEC;
    }
    goto skip_3;
    // 0x80036BD4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x80036BD8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x80036BDC: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x80036BE0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036BE4: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x80036BE8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_80036BEC:
    // 0x80036BEC: bnel        $v1, $zero, L_80036BC8
    if (ctx->r3 != 0) {
        // 0x80036BF0: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_80036BC8;
    }
    goto skip_4;
    // 0x80036BF0: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x80036BF4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_80036BF8:
    // 0x80036BF8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80036BFC: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x80036C00: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x80036C04: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036C08: bne         $at, $zero, L_80036B48
    if (ctx->r1 != 0) {
        // 0x80036C0C: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_80036B48;
    }
    // 0x80036C0C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_80036C10:
    // 0x80036C10: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x80036C14: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x80036C18: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x80036C1C: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x80036C20: blez        $s3, L_80036CAC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80036C24: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_80036CAC;
    }
    // 0x80036C24: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x80036C28: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_80036C2C:
    // 0x80036C2C: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80036C30: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80036C34: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036C38: beq         $at, $zero, L_80036C48
    if (ctx->r1 == 0) {
        // 0x80036C3C: nop
    
            goto L_80036C48;
    }
    // 0x80036C3C: nop

    // 0x80036C40: b           L_80036C48
    // 0x80036C44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80036C48;
    // 0x80036C44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80036C48:
    // 0x80036C48: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x80036C4C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80036C50: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
    // 0x80036C54: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036C58: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80036C5C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x80036C60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80036C64: jalr        $t9
    // 0x80036C68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80036C68: nop

    after_1:
    // 0x80036C6C: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x80036C70: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x80036C74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80036C78: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x80036C7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80036C80: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80036C84: jalr        $t9
    // 0x80036C88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80036C88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80036C8C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x80036C90: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x80036C94: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80036C98: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80036C9C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80036CA0: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x80036CA4: bgtz        $s3, L_80036C2C
    if (SIGNED(ctx->r19) > 0) {
        // 0x80036CA8: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_80036C2C;
    }
    // 0x80036CA8: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_80036CAC:
    // 0x80036CAC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x80036CB0: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80036CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036CB8: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x80036CBC: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80036CC0: jal         0x800369B8
    // 0x80036CC4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    func_800369B8(rdram, ctx);
        goto after_3;
    // 0x80036CC4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x80036CC8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80036CCC:
    // 0x80036CCC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80036CD0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80036CD4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80036CD8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80036CDC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80036CE0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80036CE4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80036CE8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80036CEC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80036CF0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80036CF4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80036CF8: jr          $ra
    // 0x80036CFC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80036CFC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8001FA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001FA64: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001FA68: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8001FA6C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001FA70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001FA74: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8001FA78: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8001FA7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001FA80: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8001FA84: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001FA88: addiu       $t8, $t8, -0x3668
    ctx->r24 = ADD32(ctx->r24, -0X3668);
    // 0x8001FA8C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001FA90: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001FA94: lw          $t9, 0x88($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X88);
    // 0x8001FA98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FA9C: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    // 0x8001FAA0: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x8001FAA4: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x8001FAA8: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x8001FAAC: bnel        $t1, $at, L_8001FAC8
    if (ctx->r9 != ctx->r1) {
        // 0x8001FAB0: lw          $a0, 0x64($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X64);
            goto L_8001FAC8;
    }
    goto skip_0;
    // 0x8001FAB0: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    skip_0:
    // 0x8001FAB4: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    // 0x8001FAB8: lw          $t2, 0x68($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X68);
    // 0x8001FABC: b           L_8001FB14
    // 0x8001FAC0: lwc1        $f14, 0x94($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X94);
        goto L_8001FB14;
    // 0x8001FAC0: lwc1        $f14, 0x94($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X94);
    // 0x8001FAC4: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
L_8001FAC8:
    // 0x8001FAC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FACC: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8001FAD0: bnel        $t3, $at, L_8001FB04
    if (ctx->r11 != ctx->r1) {
        // 0x8001FAD4: lwc1        $f4, 0x1C($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
            goto L_8001FB04;
    }
    goto skip_1;
    // 0x8001FAD4: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    skip_1:
    // 0x8001FAD8: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8001FADC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001FAE0: ldc1        $f4, 0x16C0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X16C0);
    // 0x8001FAE4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FAE8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001FAEC: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8001FAF0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001FAF4: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x8001FAF8: b           L_8001FB14
    // 0x8001FAFC: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
        goto L_8001FB14;
    // 0x8001FAFC: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x8001FB00: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
L_8001FB04:
    // 0x8001FB04: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8001FB08: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001FB0C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001FB10: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_8001FB14:
    // 0x8001FB14: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001FB18: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8001FB1C: jal         0x8002413C
    // 0x8001FB20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001FB20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8001FB24: beq         $v0, $zero, L_8001FB84
    if (ctx->r2 == 0) {
        // 0x8001FB28: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_8001FB84;
    }
    // 0x8001FB28: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001FB2C: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001FB30: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001FB34: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x8001FB38: addiu       $t7, $t7, -0x7308
    ctx->r15 = ADD32(ctx->r15, -0X7308);
    // 0x8001FB3C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8001FB40: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8001FB44: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8001FB48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001FB4C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8001FB50: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8001FB54: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8001FB58: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001FB5C: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001FB60: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8001FB64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8001FB68: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8001FB6C: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    // 0x8001FB70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001FB74: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001FB78: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8001FB7C: jal         0x80020F8C
    // 0x8001FB80: addiu       $a1, $a1, -0x2A
    ctx->r5 = ADD32(ctx->r5, -0X2A);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x8001FB80: addiu       $a1, $a1, -0x2A
    ctx->r5 = ADD32(ctx->r5, -0X2A);
    after_1:
L_8001FB84:
    // 0x8001FB84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001FB88: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8001FB8C: jr          $ra
    // 0x8001FB90: nop

    return;
    // 0x8001FB90: nop

;}
RECOMP_FUNC void func_801013C0_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801013C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801013C4: lw          $t6, 0x6250($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6250);
    // 0x801013C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801013CC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801013D0: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x801013D4: bgez        $t7, L_801013E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801013D8: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_801013E0;
    }
    // 0x801013D8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801013DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801013E0:
    // 0x801013E0: addiu       $v0, $v0, 0x62A0
    ctx->r2 = ADD32(ctx->r2, 0X62A0);
    // 0x801013E4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801013E8: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x801013EC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801013F0: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x801013F4: beq         $t9, $zero, L_80101400
    if (ctx->r25 == 0) {
        // 0x801013F8: addiu       $a2, $zero, 0x96
        ctx->r6 = ADD32(0, 0X96);
            goto L_80101400;
    }
    // 0x801013F8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x801013FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80101400:
    // 0x80101400: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80101404: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80101408: and         $t1, $t0, $a1
    ctx->r9 = ctx->r8 & ctx->r5;
    // 0x8010140C: beql        $t1, $zero, L_8010141C
    if (ctx->r9 == 0) {
        // 0x80101410: lw          $t2, 0x50($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X50);
            goto L_8010141C;
    }
    goto skip_0;
    // 0x80101410: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x80101414: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101418: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
L_8010141C:
    // 0x8010141C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101420: and         $t3, $t2, $a1
    ctx->r11 = ctx->r10 & ctx->r5;
    // 0x80101424: beql        $t3, $zero, L_80101434
    if (ctx->r11 == 0) {
        // 0x80101428: lw          $t4, 0x50($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X50);
            goto L_80101434;
    }
    goto skip_1;
    // 0x80101428: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x8010142C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101430: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
L_80101434:
    // 0x80101434: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101438: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x8010143C: beql        $t5, $zero, L_8010144C
    if (ctx->r13 == 0) {
        // 0x80101440: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_8010144C;
    }
    goto skip_2;
    // 0x80101440: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x80101444: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101448: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
L_8010144C:
    // 0x8010144C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101450: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x80101454: beq         $t7, $zero, L_80101460
    if (ctx->r15 == 0) {
        // 0x80101458: nop
    
            goto L_80101460;
    }
    // 0x80101458: nop

    // 0x8010145C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80101460:
    // 0x80101460: bne         $v1, $a2, L_80101400
    if (ctx->r3 != ctx->r6) {
        // 0x80101464: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80101400;
    }
    // 0x80101464: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101468: jr          $ra
    // 0x8010146C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8010146C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8000E350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E350: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E354: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x8000E358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000E35C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000E360: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000E364: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000E368: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E36C: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000E370: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8000E374: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000E378: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8000E37C: ldc1        $f18, 0x1238($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1238);
    // 0x8000E380: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x8000E384: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8000E388: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8000E38C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000E390: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8000E394: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8000E398: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8000E39C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000E3A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000E3A4: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x8000E3A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000E3AC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000E3B0: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8000E3B4: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8000E3B8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8000E3BC: jr          $ra
    // 0x8000E3C0: nop

    return;
    // 0x8000E3C0: nop

;}
RECOMP_FUNC void func_801016B4_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801016B4: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x801016B8: bltz        $t6, L_801016C8
    if (SIGNED(ctx->r14) < 0) {
        // 0x801016BC: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_801016C8;
    }
    // 0x801016BC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801016C0: jr          $ra
    // 0x801016C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x801016C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_801016C8:
    // 0x801016C8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x801016CC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801016D0: addiu       $t8, $t8, 0x6FE8
    ctx->r24 = ADD32(ctx->r24, 0X6FE8);
    // 0x801016D4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801016D8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801016DC: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x801016E0: lh          $t1, 0x28($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X28);
    // 0x801016E4: lw          $t2, 0x38($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X38);
    // 0x801016E8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801016EC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801016F0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801016F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801016F8: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x801016FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80101700: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80101704: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80101708: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x8010170C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80101710: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80101714: div.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80101718: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8010171C: nop

    // 0x80101720: bc1fl       L_80101730
    if (!c1cs) {
        // 0x80101724: lwc1        $f6, 0x20($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
            goto L_80101730;
    }
    goto skip_0;
    // 0x80101724: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    skip_0:
    // 0x80101728: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010172C: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
L_80101730:
    // 0x80101730: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x80101734: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80101738: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010173C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80101740: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80101744: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80101748: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8010174C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80101750: beq         $at, $zero, L_80101760
    if (ctx->r1 == 0) {
        // 0x80101754: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80101760;
    }
    // 0x80101754: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80101758: b           L_80101764
    // 0x8010175C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80101764;
    // 0x8010175C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80101760:
    // 0x80101760: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80101764:
    // 0x80101764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80101768: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010176C: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x80101770: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80101774: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x80101778: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8010177C: andi        $t0, $v0, 0x8
    ctx->r8 = ctx->r2 & 0X8;
    // 0x80101780: bc1fl       L_801017A0
    if (!c1cs) {
        // 0x80101784: lh          $t5, 0x24($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X24);
            goto L_801017A0;
    }
    goto skip_1;
    // 0x80101784: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    skip_1:
    // 0x80101788: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8010178C: nop

    // 0x80101790: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101794: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80101798: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x8010179C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
L_801017A0:
    // 0x801017A0: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x801017A4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801017A8: bne         $at, $zero, L_801017B8
    if (ctx->r1 != 0) {
        // 0x801017AC: nop
    
            goto L_801017B8;
    }
    // 0x801017AC: nop

    // 0x801017B0: lh          $t7, 0x2C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2C);
    // 0x801017B4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
L_801017B8:
    // 0x801017B8: beq         $t8, $zero, L_801017DC
    if (ctx->r24 == 0) {
        // 0x801017BC: nop
    
            goto L_801017DC;
    }
    // 0x801017BC: nop

    // 0x801017C0: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x801017C4: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x801017C8: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801017CC: bnel        $at, $zero, L_80101800
    if (ctx->r1 != 0) {
        // 0x801017D0: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101800;
    }
    goto skip_2;
    // 0x801017D0: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_2:
    // 0x801017D4: b           L_801017FC
    // 0x801017D8: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
        goto L_801017FC;
    // 0x801017D8: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_801017DC:
    // 0x801017DC: beql        $t0, $zero, L_80101800
    if (ctx->r8 == 0) {
        // 0x801017E0: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101800;
    }
    goto skip_3;
    // 0x801017E0: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x801017E4: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x801017E8: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x801017EC: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801017F0: bnel        $at, $zero, L_80101800
    if (ctx->r1 != 0) {
        // 0x801017F4: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101800;
    }
    goto skip_4;
    // 0x801017F4: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x801017F8: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_801017FC:
    // 0x801017FC: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
L_80101800:
    // 0x80101800: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101808: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010180C: bne         $at, $zero, L_8010182C
    if (ctx->r1 != 0) {
        // 0x80101810: nop
    
            goto L_8010182C;
    }
    // 0x80101810: nop

    // 0x80101814: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101818: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x8010181C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101820: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80101824: jr          $ra
    // 0x80101828: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80101828: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_8010182C:
    // 0x8010182C: jr          $ra
    // 0x80101830: nop

    return;
    // 0x80101830: nop

;}
RECOMP_FUNC void func_800228F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800228FC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80022900: addiu       $t1, $t1, -0x2FE0
    ctx->r9 = ADD32(ctx->r9, -0X2FE0);
    // 0x80022904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022908: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002290C: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x80022910: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80022914: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80022918: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8002291C: beq         $t7, $zero, L_80022AF8
    if (ctx->r15 == 0) {
        // 0x80022920: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_80022AF8;
    }
    // 0x80022920: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80022924: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x80022928: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002292C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80022930: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x80022934: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80022938: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002293C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80022940: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80022944: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022948: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x8002294C: addiu       $t4, $t4, 0x40
    ctx->r12 = ADD32(ctx->r12, 0X40);
    // 0x80022950: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80022954: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80022958: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x8002295C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80022960: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80022964: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80022968: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8002296C: addu        $a0, $a3, $t6
    ctx->r4 = ADD32(ctx->r7, ctx->r14);
    // 0x80022970: jal         0x80035388
    // 0x80022974: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    guMtxIdent(rdram, ctx);
        goto after_0;
    // 0x80022974: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    after_0:
    // 0x80022978: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002297C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80022980: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80022984: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80022988: addiu       $t1, $t1, -0x2FE0
    ctx->r9 = ADD32(ctx->r9, -0X2FE0);
    // 0x8002298C: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x80022990: addiu       $a3, $a3, -0x2FD8
    ctx->r7 = ADD32(ctx->r7, -0X2FD8);
    // 0x80022994: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80022998: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002299C: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x800229A0: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x800229A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800229A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800229AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800229B0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800229B4: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x800229B8: addiu       $t4, $t4, 0x0
    ctx->r12 = ADD32(ctx->r12, 0X0);
    // 0x800229BC: sll         $t2, $t9, 6
    ctx->r10 = S32(ctx->r25 << 6);
    // 0x800229C0: addiu       $t3, $t2, 0xC0
    ctx->r11 = ADD32(ctx->r10, 0XC0);
    // 0x800229C4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800229C8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800229CC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800229D0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800229D4: addiu       $a2, $a2, -0x2FDC
    ctx->r6 = ADD32(ctx->r6, -0X2FDC);
    // 0x800229D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800229DC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800229E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800229E4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800229E8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800229EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800229F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800229F4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800229F8: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x800229FC: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80022A00: lbu         $t2, 0x2($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2);
    // 0x80022A04: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x80022A08: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80022A0C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80022A10: lbu         $t4, 0x3($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X3);
    // 0x80022A14: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80022A18: or          $t5, $t8, $t3
    ctx->r13 = ctx->r24 | ctx->r11;
    // 0x80022A1C: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x80022A20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80022A24: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80022A28: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80022A2C: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x80022A30: lbu         $t2, 0x3($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X3);
    // 0x80022A34: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x80022A38: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x80022A3C: bne         $t2, $at, L_80022A68
    if (ctx->r10 != ctx->r1) {
        // 0x80022A40: ori         $t4, $t4, 0x31D
        ctx->r12 = ctx->r12 | 0X31D;
            goto L_80022A68;
    }
    // 0x80022A40: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x80022A44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022A48: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x80022A4C: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x80022A50: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80022A54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80022A58: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80022A5C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80022A60: b           L_80022A84
    // 0x80022A64: nop

        goto L_80022A84;
    // 0x80022A64: nop

L_80022A68:
    // 0x80022A68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022A6C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80022A70: ori         $t7, $t7, 0x4340
    ctx->r15 = ctx->r15 | 0X4340;
    // 0x80022A74: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80022A78: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80022A7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80022A80: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80022A84:
    // 0x80022A84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022A88: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80022A8C: addiu       $t8, $t8, -0x2B10
    ctx->r24 = ADD32(ctx->r24, -0X2B10);
    // 0x80022A90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80022A94: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80022A98: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80022A9C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80022AA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80022AA4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80022AA8: beq         $a1, $zero, L_80022AF8
    if (ctx->r5 == 0) {
        // 0x80022AAC: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_80022AF8;
    }
    // 0x80022AAC: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x80022AB0: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    // 0x80022AB4: sltiu       $t8, $t9, 0x1
    ctx->r24 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80022AB8: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80022ABC: beq         $t3, $zero, L_80022AD4
    if (ctx->r11 == 0) {
        // 0x80022AC0: andi        $v1, $v0, 0x2
        ctx->r3 = ctx->r2 & 0X2;
            goto L_80022AD4;
    }
    // 0x80022AC0: andi        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 & 0X2;
    // 0x80022AC4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80022AC8: addiu       $t5, $t6, -0x4
    ctx->r13 = ADD32(ctx->r14, -0X4);
    // 0x80022ACC: b           L_80022AE0
    // 0x80022AD0: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_80022AE0;
    // 0x80022AD0: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80022AD4:
    // 0x80022AD4: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80022AD8: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x80022ADC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_80022AE0:
    // 0x80022AE0: sltiu       $t2, $v1, 0x1
    ctx->r10 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80022AE4: and         $t3, $t8, $t2
    ctx->r11 = ctx->r24 & ctx->r10;
    // 0x80022AE8: beq         $t3, $zero, L_80022AF8
    if (ctx->r11 == 0) {
        // 0x80022AEC: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80022AF8;
    }
    // 0x80022AEC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80022AF0: andi        $t6, $v0, 0xFFFE
    ctx->r14 = ctx->r2 & 0XFFFE;
    // 0x80022AF4: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
L_80022AF8:
    // 0x80022AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022B00: jr          $ra
    // 0x80022B04: nop

    return;
    // 0x80022B04: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800484F0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800484F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800484F8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800484FC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80048500: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80048504: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80048508: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004850C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80048510: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80048514: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80048518: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8004851C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80048520: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x80048524: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80048528: bgez        $v0, L_80048538
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004852C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80048538;
    }
    // 0x8004852C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80048530: b           L_80048564
    // 0x80048534: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_80048564;
    // 0x80048534: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80048538:
    // 0x80048538: bne         $v0, $zero, L_80048564
    if (ctx->r2 != 0) {
        // 0x8004853C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_80048564;
    }
    // 0x8004853C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x80048540: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80048544: beq         $t8, $at, L_80048558
    if (ctx->r24 == ctx->r1) {
        // 0x80048548: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80048558;
    }
    // 0x80048548: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8004854C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80048550: bnel        $t8, $at, L_80048568
    if (ctx->r24 != ctx->r1) {
        // 0x80048554: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_80048568;
    }
    goto skip_0;
    // 0x80048554: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_80048558:
    // 0x80048558: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8004855C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80048560: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_80048564:
    // 0x80048564: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_80048568:
    // 0x80048568: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x8004856C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80048570: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x80048574: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80048578: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8004857C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80048580: bne         $v1, $at, L_800485E4
    if (ctx->r3 != ctx->r1) {
        // 0x80048584: nop
    
            goto L_800485E4;
    }
    // 0x80048584: nop

    // 0x80048588: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8004858C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80048590: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80048594: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80048598: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8004859C: bnel        $t9, $zero, L_800485C8
    if (ctx->r25 != 0) {
        // 0x800485A0: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800485C8;
    }
    goto skip_1;
    // 0x800485A0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800485A4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800485A8: bnel        $t7, $zero, L_800485C8
    if (ctx->r15 != 0) {
        // 0x800485AC: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800485C8;
    }
    goto skip_2;
    // 0x800485AC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800485B0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800485B4: bnel        $t8, $zero, L_800485C8
    if (ctx->r24 != 0) {
        // 0x800485B8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800485C8;
    }
    goto skip_3;
    // 0x800485B8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800485BC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800485C0: beq         $t9, $zero, L_800485D0
    if (ctx->r25 == 0) {
        // 0x800485C4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800485D0;
    }
    // 0x800485C4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800485C8:
    // 0x800485C8: b           L_8004861C
    // 0x800485CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8004861C;
    // 0x800485CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800485D0:
    // 0x800485D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800485D4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800485D8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800485DC: b           L_8004861C
    // 0x800485E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8004861C;
    // 0x800485E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800485E4:
    // 0x800485E4: blez        $v1, L_80048608
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800485E8: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_80048608;
    }
    // 0x800485E8: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800485EC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800485F0: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800485F4: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800485F8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800485FC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80048600: b           L_8004861C
    // 0x80048604: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8004861C;
    // 0x80048604: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80048608:
    // 0x80048608: bgez        $v1, L_80048618
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004860C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80048618;
    }
    // 0x8004860C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048610: b           L_8004861C
    // 0x80048614: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8004861C;
    // 0x80048614: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80048618:
    // 0x80048618: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8004861C:
    // 0x8004861C: blez        $v0, L_80048668
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048620: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_80048668;
    }
    // 0x80048620: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80048624: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80048628: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004862C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048630: bne         $t6, $at, L_80048644
    if (ctx->r14 != ctx->r1) {
        // 0x80048634: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80048644;
    }
    // 0x80048634: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80048638: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8004863C: b           L_8004864C
    // 0x80048640: addiu       $a1, $a1, 0x2378
    ctx->r5 = ADD32(ctx->r5, 0X2378);
        goto L_8004864C;
    // 0x80048640: addiu       $a1, $a1, 0x2378
    ctx->r5 = ADD32(ctx->r5, 0X2378);
L_80048644:
    // 0x80048644: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80048648: addiu       $a1, $a1, 0x237C
    ctx->r5 = ADD32(ctx->r5, 0X237C);
L_8004864C:
    // 0x8004864C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80048650: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x80048654: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80048658: jal         0x8003FB20
    // 0x8004865C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8004865C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80048660: b           L_80048A18
    // 0x80048664: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80048A18;
    // 0x80048664: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80048668:
    // 0x80048668: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004866C: bne         $t6, $zero, L_8004867C
    if (ctx->r14 != 0) {
        // 0x80048670: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8004867C;
    }
    // 0x80048670: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80048674: b           L_80048A00
    // 0x80048678: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_80048A00;
    // 0x80048678: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8004867C:
    // 0x8004867C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80048680: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80048684: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x80048688: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x8004868C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x80048690: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x80048694: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80048698: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x8004869C: bc1f        L_800486A8
    if (!c1cs) {
        // 0x800486A0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800486A8;
    }
    // 0x800486A0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800486A4: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800486A8:
    // 0x800486A8: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800486AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800486B0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800486B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800486B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800486BC: nop

    // 0x800486C0: nop

    // 0x800486C4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800486C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800486CC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800486D0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800486D4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800486D8: bgez        $t8, L_80048740
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800486DC: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_80048740;
    }
    // 0x800486DC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800486E0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800486E4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800486E8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800486EC: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800486F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800486F4: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800486F8: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800486FC: blez        $v0, L_800487B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048700: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800487B0;
    }
    // 0x80048700: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80048704: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80048708: addiu       $a0, $a0, 0x2330
    ctx->r4 = ADD32(ctx->r4, 0X2330);
L_8004870C:
    // 0x8004870C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80048710: beq         $t6, $zero, L_8004872C
    if (ctx->r14 == 0) {
        // 0x80048714: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004872C;
    }
    // 0x80048714: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80048718: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8004871C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80048720: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x80048724: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x80048728: nop

L_8004872C:
    // 0x8004872C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80048730: bgtz        $t9, L_8004870C
    if (SIGNED(ctx->r25) > 0) {
        // 0x80048734: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004870C;
    }
    // 0x80048734: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80048738: b           L_800487B4
    // 0x8004873C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800487B4;
    // 0x8004873C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80048740:
    // 0x80048740: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80048744: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80048748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004874C: blez        $t6, L_800487B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80048750: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800487B0;
    }
    // 0x80048750: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x80048754: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x80048758: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8004875C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80048760: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048764: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80048768: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004876C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80048770: blez        $t6, L_800487AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80048774: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800487AC;
    }
    // 0x80048774: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80048778: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8004877C: addiu       $a0, $a0, 0x2330
    ctx->r4 = ADD32(ctx->r4, 0X2330);
L_80048780:
    // 0x80048780: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80048784: beq         $t7, $zero, L_800487A0
    if (ctx->r15 == 0) {
        // 0x80048788: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800487A0;
    }
    // 0x80048788: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004878C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80048790: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80048794: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x80048798: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004879C: nop

L_800487A0:
    // 0x800487A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800487A4: bgtz        $t6, L_80048780
    if (SIGNED(ctx->r14) > 0) {
        // 0x800487A8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80048780;
    }
    // 0x800487A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800487AC:
    // 0x800487AC: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800487B0:
    // 0x800487B0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800487B4:
    // 0x800487B4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800487B8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800487BC: bne         $t7, $at, L_800487D0
    if (ctx->r15 != ctx->r1) {
        // 0x800487C0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800487D0;
    }
    // 0x800487C0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800487C4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800487C8: b           L_800487D0
    // 0x800487CC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800487D0;
    // 0x800487CC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800487D0:
    // 0x800487D0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800487D4: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800487D8: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800487DC: bne         $at, $zero, L_800487E8
    if (ctx->r1 != 0) {
        // 0x800487E0: nop
    
            goto L_800487E8;
    }
    // 0x800487E0: nop

    // 0x800487E4: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800487E8:
    // 0x800487E8: blez        $s4, L_800488B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800487EC: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800488B8;
    }
    // 0x800487EC: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800487F0: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800487F4: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800487F8: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800487FC: bc1fl       L_800488BC
    if (!c1cs) {
        // 0x80048800: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800488BC;
    }
    goto skip_4;
    // 0x80048800: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80048804: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80048808:
    // 0x80048808: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x8004880C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80048810: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80048814: blez        $s4, L_80048838
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80048818: nop
    
            goto L_80048838;
    }
    // 0x80048818: nop

    // 0x8004881C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80048820: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80048824: ldc1        $f8, 0x2388($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X2388);
    // 0x80048828: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8004882C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x80048830: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80048834: nop

L_80048838:
    // 0x80048838: blez        $s1, L_80048880
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8004883C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_80048880;
    }
    // 0x8004883C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80048840: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80048844: bltz        $s0, L_80048880
    if (SIGNED(ctx->r16) < 0) {
        // 0x80048848: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80048880;
    }
    // 0x80048848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8004884C:
    // 0x8004884C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80048850: jal         0x80049E60
    // 0x80048854: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x80048854: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80048858: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8004885C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80048860: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x80048864: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x80048868: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x8004886C: blezl       $s1, L_80048884
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80048870: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_80048884;
    }
    goto skip_5;
    // 0x80048870: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x80048874: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80048878: bgezl       $s0, L_8004884C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8004887C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8004884C;
    }
    goto skip_6;
    // 0x8004887C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_80048880:
    // 0x80048880: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_80048884:
    // 0x80048884: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80048888: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8004888C: bltz        $s0, L_800488A0
    if (SIGNED(ctx->r16) < 0) {
        // 0x80048890: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800488A0;
    }
L_80048890:
    // 0x80048890: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80048894: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80048898: bgez        $s0, L_80048890
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8004889C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_80048890;
    }
    // 0x8004889C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800488A0:
    // 0x800488A0: blez        $s4, L_800488B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800488A4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800488B8;
    }
    // 0x800488A4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800488A8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800488AC: nop

    // 0x800488B0: bc1tl       L_80048808
    if (c1cs) {
        // 0x800488B4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80048808;
    }
    goto skip_7;
    // 0x800488B4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800488B8:
    // 0x800488B8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800488BC:
    // 0x800488BC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800488C0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800488C4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800488C8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800488CC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800488D0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800488D4: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800488D8: bne         $v0, $t6, L_80048900
    if (ctx->r2 != ctx->r14) {
        // 0x800488DC: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80048900;
    }
    // 0x800488DC: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800488E0: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800488E4:
    // 0x800488E4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800488E8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800488EC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800488F0: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800488F4: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800488F8: beql        $v0, $t9, L_800488E4
    if (ctx->r2 == ctx->r25) {
        // 0x800488FC: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800488E4;
    }
    goto skip_8;
    // 0x800488FC: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80048900:
    // 0x80048900: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80048904: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80048908: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8004890C: bne         $t6, $at, L_80048920
    if (ctx->r14 != ctx->r1) {
        // 0x80048910: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80048920;
    }
    // 0x80048910: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80048914: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80048918: b           L_80048940
    // 0x8004891C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80048940;
    // 0x8004891C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80048920:
    // 0x80048920: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80048924: beq         $t7, $at, L_80048934
    if (ctx->r15 == ctx->r1) {
        // 0x80048928: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80048934;
    }
    // 0x80048928: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x8004892C: bne         $t7, $at, L_8004893C
    if (ctx->r15 != ctx->r1) {
        // 0x80048930: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004893C;
    }
    // 0x80048930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80048934:
    // 0x80048934: b           L_8004893C
    // 0x80048938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004893C;
    // 0x80048938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004893C:
    // 0x8004893C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80048940:
    // 0x80048940: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80048944: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x80048948: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8004894C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80048950: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80048954: beq         $at, $zero, L_80048968
    if (ctx->r1 == 0) {
        // 0x80048958: nop
    
            goto L_80048968;
    }
    // 0x80048958: nop

    // 0x8004895C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x80048960: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80048964: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80048968:
    // 0x80048968: blez        $s3, L_80048A00
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8004896C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80048A00;
    }
    // 0x8004896C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80048970: beq         $at, $zero, L_80048990
    if (ctx->r1 == 0) {
        // 0x80048974: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_80048990;
    }
    // 0x80048974: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x80048978: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8004897C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x80048980: bnel        $at, $zero, L_80048994
    if (ctx->r1 != 0) {
        // 0x80048984: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_80048994;
    }
    goto skip_9;
    // 0x80048984: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x80048988: b           L_80048998
    // 0x8004898C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_80048998;
    // 0x8004898C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_80048990:
    // 0x80048990: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_80048994:
    // 0x80048994: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_80048998:
    // 0x80048998: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x8004899C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800489A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800489A4: bne         $a1, $t6, L_800489CC
    if (ctx->r5 != ctx->r14) {
        // 0x800489A8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800489CC;
    }
    // 0x800489A8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800489AC: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800489B0:
    // 0x800489B0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800489B4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800489B8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800489BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800489C0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800489C4: beq         $a0, $t9, L_800489B0
    if (ctx->r4 == ctx->r25) {
        // 0x800489C8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800489B0;
    }
    // 0x800489C8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800489CC:
    // 0x800489CC: bne         $a0, $at, L_800489E0
    if (ctx->r4 != ctx->r1) {
        // 0x800489D0: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800489E0;
    }
    // 0x800489D0: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800489D4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800489D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800489DC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800489E0:
    // 0x800489E0: bgez        $v1, L_80048A00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800489E4: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_80048A00;
    }
    // 0x800489E4: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800489E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800489EC: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800489F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800489F4: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800489F8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800489FC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80048A00:
    // 0x80048A00: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x80048A04: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x80048A08: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80048A0C: jal         0x80047F80
    // 0x80048A10: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_5_80047F80(rdram, ctx);
        goto after_2;
    // 0x80048A10: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x80048A14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80048A18:
    // 0x80048A18: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80048A1C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80048A20: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80048A24: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80048A28: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80048A2C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80048A30: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80048A34: jr          $ra
    // 0x80048A38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80048A38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80031DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031DDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80031DE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031DE4: bne         $a2, $at, L_80031E00
    if (ctx->r6 != ctx->r1) {
        // 0x80031DE8: lui         $t1, 0x8009
        ctx->r9 = S32(0X8009 << 16);
            goto L_80031E00;
    }
    // 0x80031DE8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80031DEC: addiu       $t1, $t1, 0x2D30
    ctx->r9 = ADD32(ctx->r9, 0X2D30);
    // 0x80031DF0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80031DF4: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x80031DF8: b           L_80031F0C
    // 0x80031DFC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80031F0C;
    // 0x80031DFC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80031E00:
    // 0x80031E00: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80031E04: bne         $a2, $at, L_80031E34
    if (ctx->r6 != ctx->r1) {
        // 0x80031E08: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80031E34;
    }
    // 0x80031E08: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80031E0C: addiu       $v0, $v0, 0x2D36
    ctx->r2 = ADD32(ctx->r2, 0X2D36);
    // 0x80031E10: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80031E14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031E18: addiu       $t9, $t8, 0xD
    ctx->r25 = ADD32(ctx->r24, 0XD);
    // 0x80031E1C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80031E20: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80031E24: jal         0x80031F1C
    // 0x80031E28: lh          $a0, 0x2D34($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2D34);
    func_80031F1C(rdram, ctx);
        goto after_0;
    // 0x80031E28: lh          $a0, 0x2D34($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2D34);
    after_0:
    // 0x80031E2C: b           L_80031F10
    // 0x80031E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031F10;
    // 0x80031E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031E34:
    // 0x80031E34: slti        $at, $a2, 0xF
    ctx->r1 = SIGNED(ctx->r6) < 0XF ? 1 : 0;
    // 0x80031E38: bne         $at, $zero, L_80031E54
    if (ctx->r1 != 0) {
        // 0x80031E3C: addiu       $t0, $zero, 0xC
        ctx->r8 = ADD32(0, 0XC);
            goto L_80031E54;
    }
    // 0x80031E3C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80031E40: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80031E44: lw          $t2, 0x2CC0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2CC0);
    // 0x80031E48: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80031E4C: beql        $at, $zero, L_80031E5C
    if (ctx->r1 == 0) {
        // 0x80031E50: addiu       $a2, $a2, -0xF
        ctx->r6 = ADD32(ctx->r6, -0XF);
            goto L_80031E5C;
    }
    goto skip_0;
    // 0x80031E50: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
    skip_0:
L_80031E54:
    // 0x80031E54: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x80031E58: addiu       $a2, $a2, -0xF
    ctx->r6 = ADD32(ctx->r6, -0XF);
L_80031E5C:
    // 0x80031E5C: andi        $t3, $a2, 0xF8
    ctx->r11 = ctx->r6 & 0XF8;
    // 0x80031E60: multu       $t3, $t0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80031E64: andi        $t7, $a2, 0x7
    ctx->r15 = ctx->r6 & 0X7;
    // 0x80031E68: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80031E6C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80031E70: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80031E74: addiu       $t1, $t1, 0x2D30
    ctx->r9 = ADD32(ctx->r9, 0X2D30);
    // 0x80031E78: addiu       $t3, $t3, -0x1B40
    ctx->r11 = ADD32(ctx->r11, -0X1B40);
    // 0x80031E7C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80031E80: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80031E84: addiu       $a2, $a2, -0xC08
    ctx->r6 = ADD32(ctx->r6, -0XC08);
    // 0x80031E88: mflo        $t4
    ctx->r12 = lo;
    // 0x80031E8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80031E90: bgez        $t4, L_80031EA0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80031E94: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_80031EA0;
    }
    // 0x80031E94: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80031E98: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x80031E9C: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80031EA0:
    // 0x80031EA0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80031EA4: bgez        $t8, L_80031EB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80031EA8: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80031EB4;
    }
    // 0x80031EA8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80031EAC: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80031EB0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80031EB4:
    // 0x80031EB4: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80031EB8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
L_80031EBC:
    // 0x80031EBC: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80031EC0:
    // 0x80031EC0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80031EC4: srlv        $t5, $t4, $v0
    ctx->r13 = S32(U32(ctx->r12) >> (ctx->r2 & 31));
    // 0x80031EC8: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x80031ECC: beq         $t7, $zero, L_80031EE8
    if (ctx->r15 == 0) {
        // 0x80031ED0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80031EE8;
    }
    // 0x80031ED0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80031ED4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80031ED8: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80031EDC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80031EE0: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x80031EE4: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
L_80031EE8:
    // 0x80031EE8: bgez        $v0, L_80031EC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80031EEC: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80031EC0;
    }
    // 0x80031EEC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80031EF0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80031EF4: addiu       $a0, $a0, 0x270
    ctx->r4 = ADD32(ctx->r4, 0X270);
    // 0x80031EF8: bne         $a3, $t0, L_80031EBC
    if (ctx->r7 != ctx->r8) {
        // 0x80031EFC: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_80031EBC;
    }
    // 0x80031EFC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80031F00: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80031F04: addiu       $t3, $v0, 0x12
    ctx->r11 = ADD32(ctx->r2, 0X12);
    // 0x80031F08: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80031F0C:
    // 0x80031F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031F10:
    // 0x80031F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031F14: jr          $ra
    // 0x80031F18: nop

    return;
    // 0x80031F18: nop

;}
RECOMP_FUNC void func_800262F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800262F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800262F8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800262FC: addiu       $a0, $a0, 0x3990
    ctx->r4 = ADD32(ctx->r4, 0X3990);
    // 0x80026300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026304: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80026308: lw          $a2, 0x3978($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3978);
    // 0x8002630C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80026310: addiu       $t7, $t7, 0x3984
    ctx->r15 = ADD32(ctx->r15, 0X3984);
    // 0x80026314: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80026318: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002631C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80026320: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80026324: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80026328: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8002632C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80026330: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80026334: bltz        $t0, L_8002634C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80026338: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8002634C;
    }
    // 0x80026338: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8002633C: lw          $t1, 0x3974($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3974);
    // 0x80026340: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80026344: beql        $at, $zero, L_80026360
    if (ctx->r1 == 0) {
        // 0x80026348: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80026360;
    }
    goto skip_0;
    // 0x80026348: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    skip_0:
L_8002634C:
    // 0x8002634C: lw          $t2, 0x3974($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3974);
    // 0x80026350: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80026354: b           L_80026398
    // 0x80026358: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_80026398;
    // 0x80026358: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8002635C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
L_80026360:
    // 0x80026360: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80026364: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80026368: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8002636C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80026370: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80026374: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80026378: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002637C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80026380: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026384: addiu       $t5, $t5, -0x688
    ctx->r13 = ADD32(ctx->r13, -0X688);
    // 0x80026388: addiu       $t4, $t3, 0x1C
    ctx->r12 = ADD32(ctx->r11, 0X1C);
    // 0x8002638C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80026390: jal         0x800368E0
    // 0x80026394: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_800368E0(rdram, ctx);
        goto after_0;
    // 0x80026394: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
L_80026398:
    // 0x80026398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002639C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800263A0: jr          $ra
    // 0x800263A4: nop

    return;
    // 0x800263A4: nop

;}
RECOMP_FUNC void func_80030754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030754: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80030758: bltz        $a0, L_80030798
    if (SIGNED(ctx->r4) < 0) {
        // 0x8003075C: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80030798;
    }
    // 0x8003075C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80030760: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80030764: addiu       $a1, $a1, 0x5E0
    ctx->r5 = ADD32(ctx->r5, 0X5E0);
    // 0x80030768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003076C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_80030770:
    // 0x80030770: lbu         $t6, 0xE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XE);
    // 0x80030774: bnel        $a0, $t6, L_80030788
    if (ctx->r4 != ctx->r14) {
        // 0x80030778: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80030788;
    }
    goto skip_0;
    // 0x80030778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8003077C: b           L_800307CC
    // 0x80030780: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800307CC;
    // 0x80030780: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80030784: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80030788:
    // 0x80030788: bne         $v0, $a3, L_80030770
    if (ctx->r2 != ctx->r7) {
        // 0x8003078C: addiu       $a1, $a1, 0x89C
        ctx->r5 = ADD32(ctx->r5, 0X89C);
            goto L_80030770;
    }
    // 0x8003078C: addiu       $a1, $a1, 0x89C
    ctx->r5 = ADD32(ctx->r5, 0X89C);
    // 0x80030790: b           L_800307D0
    // 0x80030794: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800307D0;
    // 0x80030794: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80030798:
    // 0x80030798: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8003079C: addiu       $a1, $a1, 0x5E0
    ctx->r5 = ADD32(ctx->r5, 0X5E0);
    // 0x800307A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800307A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_800307A8:
    // 0x800307A8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800307AC: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800307B0: bnel        $a2, $t8, L_800307C4
    if (ctx->r6 != ctx->r24) {
        // 0x800307B4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800307C4;
    }
    goto skip_1;
    // 0x800307B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800307B8: b           L_800307CC
    // 0x800307BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800307CC;
    // 0x800307BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800307C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800307C4:
    // 0x800307C4: bne         $v0, $a3, L_800307A8
    if (ctx->r2 != ctx->r7) {
        // 0x800307C8: addiu       $a1, $a1, 0x89C
        ctx->r5 = ADD32(ctx->r5, 0X89C);
            goto L_800307A8;
    }
    // 0x800307C8: addiu       $a1, $a1, 0x89C
    ctx->r5 = ADD32(ctx->r5, 0X89C);
L_800307CC:
    // 0x800307CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800307D0:
    // 0x800307D0: jr          $ra
    // 0x800307D4: nop

    return;
    // 0x800307D4: nop

;}
RECOMP_FUNC void func_80040FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040FA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80040FA8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80040FAC: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80040FB0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x80040FB4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80040FB8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80040FBC: blez        $s1, L_80041028
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80040FC0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80041028;
    }
    // 0x80040FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040FC4: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x80040FC8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80040FCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80040FD0: jalr        $t9
    // 0x80040FD4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80040FD4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x80040FD8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x80040FDC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x80040FE0: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x80040FE4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80040FE8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80040FEC: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x80040FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80040FF4: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x80040FF8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80040FFC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80041000: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80041004: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80041008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004100C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80041010: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x80041014: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80041018: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8004101C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80041020: b           L_8004102C
    // 0x80041024: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_8004102C;
    // 0x80041024: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80041028:
    // 0x80041028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8004102C:
    // 0x8004102C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x80041030: beq         $t6, $zero, L_80041058
    if (ctx->r14 == 0) {
        // 0x80041034: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80041058;
    }
    // 0x80041034: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80041038: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x8004103C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80041040: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x80041044: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x80041048: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8004104C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80041050: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80041054: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80041058:
    // 0x80041058: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x8004105C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80041060: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80041064: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80041068: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8004106C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80041070: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x80041074: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80041078: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x8004107C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80041080: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x80041084: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80041088: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8004108C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80041090: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80041094: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80041098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004109C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800410A0: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800410A4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800410A8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800410AC: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800410B0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800410B4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800410B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800410BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800410C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800410C4: jr          $ra
    // 0x800410C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800410C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8010575C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010575C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80105760: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80105764: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80105768: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010576C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80105770: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80105774: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105778: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8010577C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80105780: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80105784: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80105788: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8010578C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80105790: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80105794: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80105798: sw          $zero, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = 0;
    // 0x8010579C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801057A0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801057A4: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x801057A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801057AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801057B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801057B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801057B8: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x801057BC: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x801057C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801057C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801057C8: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x801057CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801057D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801057D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801057D8: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x801057DC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801057E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801057E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801057E8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801057EC: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x801057F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801057F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801057F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801057FC: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80105800: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80105804: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105808: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010580C: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80105810: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x80105814: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80105818: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010581C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105820: lb          $t1, 0x2871($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X2871);
    // 0x80105824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80105828: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8010582C: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x80105830: bne         $at, $zero, L_80105840
    if (ctx->r1 != 0) {
        // 0x80105834: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80105840;
    }
    // 0x80105834: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80105838: b           L_80105850
    // 0x8010583C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_80105850;
    // 0x8010583C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80105840:
    // 0x80105840: slti        $at, $t1, -0x14
    ctx->r1 = SIGNED(ctx->r9) < -0X14 ? 1 : 0;
    // 0x80105844: beq         $at, $zero, L_80105850
    if (ctx->r1 == 0) {
        // 0x80105848: nop
    
            goto L_80105850;
    }
    // 0x80105848: nop

    // 0x8010584C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80105850:
    // 0x80105850: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x80105854: ori         $t6, $a0, 0x1
    ctx->r14 = ctx->r4 | 0X1;
    // 0x80105858: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8010585C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80105860: bne         $at, $zero, L_8010586C
    if (ctx->r1 != 0) {
        // 0x80105864: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010586C;
    }
    // 0x80105864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80105868: sra         $a0, $t7, 24
    ctx->r4 = S32(SIGNED(ctx->r15) >> 24);
L_8010586C:
    // 0x8010586C: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80105870: beq         $at, $zero, L_80105880
    if (ctx->r1 == 0) {
        // 0x80105874: ori         $t9, $a0, 0x2
        ctx->r25 = ctx->r4 | 0X2;
            goto L_80105880;
    }
    // 0x80105874: ori         $t9, $a0, 0x2
    ctx->r25 = ctx->r4 | 0X2;
    // 0x80105878: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8010587C: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
L_80105880:
    // 0x80105880: lb          $t8, 0x4DF3($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X4DF3);
    // 0x80105884: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80105888: sb          $a0, 0x4DF3($at)
    MEM_B(0X4DF3, ctx->r1) = ctx->r4;
    // 0x8010588C: xor         $t9, $a0, $t8
    ctx->r25 = ctx->r4 ^ ctx->r24;
    // 0x80105890: and         $v0, $t9, $a0
    ctx->r2 = ctx->r25 & ctx->r4;
    // 0x80105894: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x80105898: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8010589C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801058A0: beq         $t8, $zero, L_801058AC
    if (ctx->r24 == 0) {
        // 0x801058A4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801058AC;
    }
    // 0x801058A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801058A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801058AC:
    // 0x801058AC: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x801058B0: beq         $t9, $zero, L_801058BC
    if (ctx->r25 == 0) {
        // 0x801058B4: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_801058BC;
    }
    // 0x801058B4: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x801058B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801058BC:
    // 0x801058BC: beq         $t6, $zero, L_801058C8
    if (ctx->r14 == 0) {
        // 0x801058C0: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_801058C8;
    }
    // 0x801058C0: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x801058C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_801058C8:
    // 0x801058C8: beq         $t7, $zero, L_801058D4
    if (ctx->r15 == 0) {
        // 0x801058CC: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_801058D4;
    }
    // 0x801058CC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801058D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801058D4:
    // 0x801058D4: lb          $v0, 0x6238($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6238);
    // 0x801058D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801058DC: sb          $a1, 0x4DF4($at)
    MEM_B(0X4DF4, ctx->r1) = ctx->r5;
    // 0x801058E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x801058E4: sll         $t8, $v0, 24
    ctx->r24 = S32(ctx->r2 << 24);
    // 0x801058E8: sra         $v0, $t8, 24
    ctx->r2 = S32(SIGNED(ctx->r24) >> 24);
    // 0x801058EC: bgez        $v0, L_80105900
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801058F0: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80105900;
    }
    // 0x801058F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801058F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801058F8: b           L_80105918
    // 0x801058FC: sb          $zero, 0x6238($at)
    MEM_B(0X6238, ctx->r1) = 0;
        goto L_80105918;
    // 0x801058FC: sb          $zero, 0x6238($at)
    MEM_B(0X6238, ctx->r1) = 0;
L_80105900:
    // 0x80105900: sb          $v0, 0x6238($at)
    MEM_B(0X6238, ctx->r1) = ctx->r2;
    // 0x80105904: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80105908: bne         $at, $zero, L_80105918
    if (ctx->r1 != 0) {
        // 0x8010590C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80105918;
    }
    // 0x8010590C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80105910: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80105914: sb          $v0, 0x6238($at)
    MEM_B(0X6238, ctx->r1) = ctx->r2;
L_80105918:
    // 0x80105918: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8010591C: lb          $v0, 0x623C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X623C);
    // 0x80105920: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80105924: sb          $a2, 0x4DF5($at)
    MEM_B(0X4DF5, ctx->r1) = ctx->r6;
    // 0x80105928: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8010592C: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x80105930: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80105934: bgez        $v0, L_80105948
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80105938: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80105948;
    }
    // 0x80105938: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010593C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80105940: b           L_80105960
    // 0x80105944: sb          $zero, 0x623C($at)
    MEM_B(0X623C, ctx->r1) = 0;
        goto L_80105960;
    // 0x80105944: sb          $zero, 0x623C($at)
    MEM_B(0X623C, ctx->r1) = 0;
L_80105948:
    // 0x80105948: sb          $v0, 0x623C($at)
    MEM_B(0X623C, ctx->r1) = ctx->r2;
    // 0x8010594C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80105950: bne         $at, $zero, L_80105960
    if (ctx->r1 != 0) {
        // 0x80105954: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80105960;
    }
    // 0x80105954: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80105958: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010595C: sb          $t8, 0x623C($at)
    MEM_B(0X623C, ctx->r1) = ctx->r24;
L_80105960:
    // 0x80105960: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80105964: lbu         $v0, 0x6234($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6234);
    // 0x80105968: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8010596C: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80105970: beq         $v0, $zero, L_8010598C
    if (ctx->r2 == 0) {
        // 0x80105974: lui         $t8, 0x8016
        ctx->r24 = S32(0X8016 << 16);
            goto L_8010598C;
    }
    // 0x80105974: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80105978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010597C: beq         $v0, $at, L_80105F5C
    if (ctx->r2 == ctx->r1) {
        // 0x80105980: lui         $ra, 0xE700
        ctx->r31 = S32(0XE700 << 16);
            goto L_80105F5C;
    }
    // 0x80105980: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80105984: b           L_801061CC
    // 0x80105988: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801061CC;
    // 0x80105988: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8010598C:
    // 0x8010598C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105990: addiu       $t8, $t8, -0x918
    ctx->r24 = ADD32(ctx->r24, -0X918);
    // 0x80105994: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80105998: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010599C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801059A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801059A4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801059A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801059AC: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x801059B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801059B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801059B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801059BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801059C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801059C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801059C8: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x801059CC: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801059D0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801059D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801059D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801059DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801059E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801059E4: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x801059E8: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x801059EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801059F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801059F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801059F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801059FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105A00: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80105A04: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80105A08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105A0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105A10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105A14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105A1C: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x80105A20: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80105A24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105A28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105A2C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105A30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105A34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105A38: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80105A3C: addiu       $t8, $t8, -0x2F40
    ctx->r24 = ADD32(ctx->r24, -0X2F40);
    // 0x80105A40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105A44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105A48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105A4C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105A50: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80105A54: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80105A58: addiu       $s0, $zero, 0x47
    ctx->r16 = ADD32(0, 0X47);
    // 0x80105A5C: addiu       $s3, $zero, 0x3B
    ctx->r19 = ADD32(0, 0X3B);
    // 0x80105A60: lui         $s7, 0xB300
    ctx->r23 = S32(0XB300 << 16);
    // 0x80105A64: lui         $s6, 0xB400
    ctx->r22 = S32(0XB400 << 16);
    // 0x80105A68: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x80105A6C: lui         $s4, 0xF400
    ctx->r20 = S32(0XF400 << 16);
L_80105A70:
    // 0x80105A70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105A74: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x80105A78: ori         $t6, $t6, 0x4F
    ctx->r14 = ctx->r14 | 0X4F;
    // 0x80105A7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105A80: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105A84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105A88: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80105A8C: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x80105A90: ori         $t9, $t9, 0x1400
    ctx->r25 = ctx->r25 | 0X1400;
    // 0x80105A94: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105A98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105A9C: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80105AA0: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80105AA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105AA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105AAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105AB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105AB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105AB8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80105ABC: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80105AC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105AC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105AC8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105ACC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105AD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105AD4: lui         $at, 0x713
    ctx->r1 = S32(0X713 << 16);
    // 0x80105AD8: ori         $at, $at, 0xE000
    ctx->r1 = ctx->r1 | 0XE000;
    // 0x80105ADC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105AE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105AE4: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x80105AE8: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80105AEC: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x80105AF0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80105AF4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105AF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105AFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105B00: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80105B04: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80105B08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105B0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105B10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105B14: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105B18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105B1C: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80105B20: ori         $t8, $t8, 0x1400
    ctx->r24 = ctx->r24 | 0X1400;
    // 0x80105B24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105B28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105B2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105B30: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105B34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105B38: lui         $at, 0x27
    ctx->r1 = S32(0X27 << 16);
    // 0x80105B3C: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80105B40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105B44: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105B48: or          $t7, $t0, $at
    ctx->r15 = ctx->r8 | ctx->r1;
    // 0x80105B4C: or          $t6, $t4, $s5
    ctx->r14 = ctx->r12 | ctx->r21;
    // 0x80105B50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105B54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105B58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105B5C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80105B60: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80105B64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105B68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105B6C: lui         $at, 0xE43C
    ctx->r1 = S32(0XE43C << 16);
    // 0x80105B70: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80105B74: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80105B78: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80105B7C: lui         $at, 0x14
    ctx->r1 = S32(0X14 << 16);
    // 0x80105B80: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80105B84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105B88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105B8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105B90: sll         $t8, $s1, 5
    ctx->r24 = S32(ctx->r17 << 5);
    // 0x80105B94: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80105B98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105B9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105BA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105BA4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80105BA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105BAC: addiu       $at, $zero, 0xB3
    ctx->r1 = ADD32(0, 0XB3);
    // 0x80105BB0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80105BB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105BB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105BBC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80105BC0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80105BC4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80105BC8: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80105BCC: bne         $s3, $at, L_80105A70
    if (ctx->r19 != ctx->r1) {
        // 0x80105BD0: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_80105A70;
    }
    // 0x80105BD0: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80105BD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105BD8: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x80105BDC: ori         $t8, $t8, 0x4F
    ctx->r24 = ctx->r24 | 0X4F;
    // 0x80105BE0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105BE4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105BE8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105BEC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80105BF0: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80105BF4: ori         $t7, $t7, 0x1400
    ctx->r15 = ctx->r15 | 0X1400;
    // 0x80105BF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105BFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105C00: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80105C04: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80105C08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105C0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105C10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105C14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105C18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105C1C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80105C20: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80105C24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105C28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105C2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105C30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105C34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105C38: addiu       $t0, $s1, 0x1
    ctx->r8 = ADD32(ctx->r17, 0X1);
    // 0x80105C3C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80105C40: lui         $at, 0x713
    ctx->r1 = S32(0X713 << 16);
    // 0x80105C44: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105C48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105C4C: ori         $at, $at, 0xE000
    ctx->r1 = ctx->r1 | 0XE000;
    // 0x80105C50: andi        $t0, $t6, 0xFFF
    ctx->r8 = ctx->r14 & 0XFFF;
    // 0x80105C54: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x80105C58: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80105C5C: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x80105C60: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105C64: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105C68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105C6C: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x80105C70: ori         $t7, $t7, 0x1400
    ctx->r15 = ctx->r15 | 0X1400;
    // 0x80105C74: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105C78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105C7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105C80: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105C84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105C88: lui         $at, 0x27
    ctx->r1 = S32(0X27 << 16);
    // 0x80105C8C: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80105C90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105C94: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105C98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105C9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105CA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105CA4: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80105CA8: or          $t9, $t4, $s5
    ctx->r25 = ctx->r12 | ctx->r21;
    // 0x80105CAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105CB0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105CB4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105CB8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105CBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105CC0: addiu       $t8, $s1, 0x3D
    ctx->r24 = ADD32(ctx->r17, 0X3D);
    // 0x80105CC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80105CC8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105CCC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105CD0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80105CD4: lui         $at, 0xE43C
    ctx->r1 = S32(0XE43C << 16);
    // 0x80105CD8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80105CDC: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80105CE0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80105CE4: lui         $at, 0x14
    ctx->r1 = S32(0X14 << 16);
    // 0x80105CE8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80105CEC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105CF0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105CF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105CF8: sll         $t8, $s1, 5
    ctx->r24 = S32(ctx->r17 << 5);
    // 0x80105CFC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80105D00: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105D04: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105D08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105D0C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80105D10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D14: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80105D18: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x80105D1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105D20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105D24: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80105D28: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80105D2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D30: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80105D34: addiu       $t6, $t6, 0x3430
    ctx->r14 = ADD32(ctx->r14, 0X3430);
    // 0x80105D38: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105D3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105D40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105D44: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105D48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D4C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80105D50: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105D54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105D58: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105D5C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105D60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D64: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80105D68: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80105D6C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105D70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105D74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105D78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105D7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D80: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80105D84: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80105D88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105D8C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105D90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105D94: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105D98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105D9C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80105DA0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80105DA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105DA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105DAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105DB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105DB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105DB8: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80105DBC: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80105DC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105DC4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105DC8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105DCC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105DD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105DD4: lui         $t7, 0xFD48
    ctx->r15 = S32(0XFD48 << 16);
    // 0x80105DD8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80105DDC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105DE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105DE4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105DE8: lb          $s1, 0x623C($s1)
    ctx->r17 = MEM_B(ctx->r17, 0X623C);
    // 0x80105DEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105DF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105DF4: addiu       $t8, $t8, 0x33D0
    ctx->r24 = ADD32(ctx->r24, 0X33D0);
    // 0x80105DF8: ori         $t7, $t7, 0x7
    ctx->r15 = ctx->r15 | 0X7;
    // 0x80105DFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105E00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105E04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105E08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105E0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105E10: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80105E14: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80105E18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105E1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105E20: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80105E24: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105E28: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105E2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105E30: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80105E34: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x80105E38: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105E3C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105E40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105E44: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105E48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105E4C: ori         $t7, $t7, 0x4028
    ctx->r15 = ctx->r15 | 0X4028;
    // 0x80105E50: sll         $t4, $s1, 3
    ctx->r12 = S32(ctx->r17 << 3);
    // 0x80105E54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105E58: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105E5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105E60: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80105E64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105E68: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x80105E6C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80105E70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105E74: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105E78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105E7C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105E80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105E84: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80105E88: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80105E8C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105E90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105E94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105E98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105E9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105EA0: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80105EA4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80105EA8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105EAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105EB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105EB4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80105EB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105EBC: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80105EC0: addiu       $t6, $t4, 0x72
    ctx->r14 = ADD32(ctx->r12, 0X72);
    // 0x80105EC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80105EC8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105ECC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105ED0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80105ED4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80105ED8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80105EDC: ori         $t7, $t6, 0x2D0
    ctx->r15 = ctx->r14 | 0X2D0;
    // 0x80105EE0: addiu       $t8, $t4, 0x67
    ctx->r24 = ADD32(ctx->r12, 0X67);
    // 0x80105EE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80105EE8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80105EEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105EF0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80105EF4: ori         $t8, $t7, 0x2A4
    ctx->r24 = ctx->r15 | 0X2A4;
    // 0x80105EF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105EFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105F00: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80105F04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80105F08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105F0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105F10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105F14: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80105F18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105F1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105F20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105F24: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80105F28: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80105F2C: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x80105F30: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x80105F34: beql        $t8, $zero, L_801061CC
    if (ctx->r24 == 0) {
        // 0x80105F38: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801061CC;
    }
    goto skip_0;
    // 0x80105F38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80105F3C: bne         $s1, $at, L_80105F54
    if (ctx->r17 != ctx->r1) {
        // 0x80105F40: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80105F54;
    }
    // 0x80105F40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80105F44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80105F48: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80105F4C: b           L_801061C8
    // 0x80105F50: sb          $t9, 0x6234($at)
    MEM_B(0X6234, ctx->r1) = ctx->r25;
        goto L_801061C8;
    // 0x80105F50: sb          $t9, 0x6234($at)
    MEM_B(0X6234, ctx->r1) = ctx->r25;
L_80105F54:
    // 0x80105F54: b           L_801061C8
    // 0x80105F58: sw          $t6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r14;
        goto L_801061C8;
    // 0x80105F58: sw          $t6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r14;
L_80105F5C:
    // 0x80105F5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105F60: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80105F64: addiu       $t6, $t6, 0x5260
    ctx->r14 = ADD32(ctx->r14, 0X5260);
    // 0x80105F68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105F6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105F70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105F74: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80105F78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105F7C: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80105F80: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80105F84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105F88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105F8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105F90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105F94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105F98: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80105F9C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80105FA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105FA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105FA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105FAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105FB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105FB4: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80105FB8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80105FBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105FC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105FC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105FC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105FCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105FD0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80105FD4: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80105FD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105FDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105FE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105FE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105FE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105FEC: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80105FF0: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80105FF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105FF8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105FFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80106000: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80106004: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106008: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8010600C: addiu       $t6, $t6, 0x3E08
    ctx->r14 = ADD32(ctx->r14, 0X3E08);
    // 0x80106010: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80106014: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80106018: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010601C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80106020: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80106024: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x80106028: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8010602C: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x80106030: addiu       $s2, $zero, 0x69
    ctx->r18 = ADD32(0, 0X69);
    // 0x80106034: addiu       $s0, $zero, 0x5F
    ctx->r16 = ADD32(0, 0X5F);
    // 0x80106038: lui         $s7, 0xB300
    ctx->r23 = S32(0XB300 << 16);
    // 0x8010603C: lui         $s6, 0xB400
    ctx->r22 = S32(0XB400 << 16);
    // 0x80106040: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x80106044: lui         $s4, 0xF400
    ctx->r20 = S32(0XF400 << 16);
L_80106048:
    // 0x80106048: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010604C: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x80106050: ori         $t8, $t8, 0x67
    ctx->r24 = ctx->r24 | 0X67;
    // 0x80106054: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80106058: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010605C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80106060: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80106064: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80106068: ori         $t7, $t7, 0x1A00
    ctx->r15 = ctx->r15 | 0X1A00;
    // 0x8010606C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80106070: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106074: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80106078: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8010607C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80106080: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80106084: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80106088: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010608C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106090: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80106094: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80106098: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010609C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801060A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801060A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801060A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801060AC: lui         $at, 0x718
    ctx->r1 = S32(0X718 << 16);
    // 0x801060B0: ori         $at, $at, 0xE000
    ctx->r1 = ctx->r1 | 0XE000;
    // 0x801060B4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801060B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801060BC: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x801060C0: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x801060C4: or          $t9, $t8, $s4
    ctx->r25 = ctx->r24 | ctx->r20;
    // 0x801060C8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801060CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801060D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801060D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801060D8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x801060DC: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x801060E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801060E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801060E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801060EC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801060F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801060F4: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x801060F8: ori         $t6, $t6, 0x1A00
    ctx->r14 = ctx->r14 | 0X1A00;
    // 0x801060FC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80106100: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80106104: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80106108: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010610C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106110: lui         $at, 0x31
    ctx->r1 = S32(0X31 << 16);
    // 0x80106114: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80106118: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010611C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80106120: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x80106124: or          $t8, $t0, $s5
    ctx->r24 = ctx->r8 | ctx->r21;
    // 0x80106128: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010612C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80106130: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106134: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80106138: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8010613C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80106140: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80106144: lui         $at, 0xE441
    ctx->r1 = S32(0XE441 << 16);
    // 0x80106148: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8010614C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80106150: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80106154: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80106158: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8010615C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80106160: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80106164: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106168: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8010616C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80106170: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80106174: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80106178: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010617C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80106180: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80106184: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80106188: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8010618C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80106190: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80106194: addiu       $t5, $t5, 0xA
    ctx->r13 = ADD32(ctx->r13, 0XA);
    // 0x80106198: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x8010619C: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x801061A0: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x801061A4: bne         $s0, $at, L_80106048
    if (ctx->r16 != ctx->r1) {
        // 0x801061A8: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_80106048;
    }
    // 0x801061A8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801061AC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x801061B0: lhu         $t9, 0x2876($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2876);
    // 0x801061B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801061B8: andi        $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 & 0X4000;
    // 0x801061BC: beql        $t6, $zero, L_801061CC
    if (ctx->r14 == 0) {
        // 0x801061C0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801061CC;
    }
    goto skip_1;
    // 0x801061C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x801061C4: sb          $zero, 0x6234($at)
    MEM_B(0X6234, ctx->r1) = 0;
L_801061C8:
    // 0x801061C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801061CC:
    // 0x801061CC: lw          $v0, 0x13C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X13C);
    // 0x801061D0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x801061D4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x801061D8: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x801061DC: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x801061E0: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x801061E4: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x801061E8: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x801061EC: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x801061F0: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x801061F4: jr          $ra
    // 0x801061F8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x801061F8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    // 0x801061FC: nop

;}
RECOMP_FUNC void func_80103DB8_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103DB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80103DBC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80103DC0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80103DC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103DC8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80103DCC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80103DD0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103DD4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80103DD8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80103DDC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80103DE0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80103DE4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80103DE8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80103DEC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80103DF0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80103DF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103DF8: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x80103DFC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80103E00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103E04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E08: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80103E0C: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x80103E10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103E14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103E18: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80103E1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80103E20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103E24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E28: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80103E2C: addiu       $t8, $t8, 0x31C8
    ctx->r24 = ADD32(ctx->r24, 0X31C8);
    // 0x80103E30: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103E34: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103E38: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80103E3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103E40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103E44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E48: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80103E4C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80103E50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103E54: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103E58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103E5C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103E60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E64: lui         $s1, 0x700
    ctx->r17 = S32(0X700 << 16);
    // 0x80103E68: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80103E6C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103E70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103E74: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80103E78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103E7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E80: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x80103E84: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80103E88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103E8C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103E90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103E94: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103E98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103E9C: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80103EA0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80103EA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103EA8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103EAC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103EB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103EB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103EB8: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80103EBC: lui         $s5, 0xFD48
    ctx->r21 = S32(0XFD48 << 16);
    // 0x80103EC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103EC4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80103ECC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80103ED0: ori         $s5, $s5, 0x57
    ctx->r21 = ctx->r21 | 0X57;
    // 0x80103ED4: addiu       $s2, $s2, 0x2400
    ctx->r18 = ADD32(ctx->r18, 0X2400);
    // 0x80103ED8: lui         $s6, 0xF548
    ctx->r22 = S32(0XF548 << 16);
    // 0x80103EDC: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
    // 0x80103EE0: lui         $fp, 0xF540
    ctx->r30 = S32(0XF540 << 16);
    // 0x80103EE4: lui         $ra, 0xF200
    ctx->r31 = S32(0XF200 << 16);
    // 0x80103EE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103EEC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_80103EF0:
    // 0x80103EF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103EF4: subu        $a3, $a0, $a0
    ctx->r7 = SUB32(ctx->r4, ctx->r4);
    // 0x80103EF8: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x80103EFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103F00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103F04: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80103F08: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80103F0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103F10: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80103F14: addiu       $a3, $t8, 0x7
    ctx->r7 = ADD32(ctx->r24, 0X7);
    // 0x80103F18: sra         $t9, $a3, 3
    ctx->r25 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80103F1C: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80103F20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103F24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103F28: sll         $a3, $t6, 9
    ctx->r7 = S32(ctx->r14 << 9);
    // 0x80103F2C: or          $t8, $a3, $s6
    ctx->r24 = ctx->r7 | ctx->r22;
    // 0x80103F30: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103F34: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80103F38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103F3C: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80103F40: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103F44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103F48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103F4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103F50: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103F54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103F58: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103F5C: addiu       $t5, $a0, 0x2F
    ctx->r13 = ADD32(ctx->r4, 0X2F);
    // 0x80103F60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103F64: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103F68: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x80103F6C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80103F70: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103F74: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103F78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103F7C: or          $t6, $t9, $s1
    ctx->r14 = ctx->r25 | ctx->r17;
    // 0x80103F80: ori         $t7, $t6, 0x9C
    ctx->r15 = ctx->r14 | 0X9C;
    // 0x80103F84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103F88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103F8C: or          $t6, $a3, $fp
    ctx->r14 = ctx->r7 | ctx->r30;
    // 0x80103F90: addiu       $t0, $a0, 0x4B
    ctx->r8 = ADD32(ctx->r4, 0X4B);
    // 0x80103F94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103F98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103F9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103FA0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80103FA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103FA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80103FAC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80103FB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103FB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103FB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103FBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103FC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103FC4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103FC8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103FCC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103FD0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103FD4: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x80103FD8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80103FDC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103FE0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103FE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103FE8: ori         $t7, $t6, 0x9C
    ctx->r15 = ctx->r14 | 0X9C;
    // 0x80103FEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103FF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103FF4: addiu       $t9, $t0, 0x30
    ctx->r25 = ADD32(ctx->r8, 0X30);
    // 0x80103FF8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80103FFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104000: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104004: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80104008: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8010400C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80104010: ori         $t6, $t9, 0x22C
    ctx->r14 = ctx->r25 | 0X22C;
    // 0x80104014: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80104018: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8010401C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80104020: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104024: ori         $t6, $t9, 0x18C
    ctx->r14 = ctx->r25 | 0X18C;
    // 0x80104028: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010402C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104030: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80104034: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80104038: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010403C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104040: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x80104044: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80104048: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010404C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104050: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80104054: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80104058: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010405C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104060: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80104064: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80104068: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010406C: bne         $t4, $zero, L_80103EF0
    if (ctx->r12 != 0) {
        // 0x80104070: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80103EF0;
    }
    // 0x80104070: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104074: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104078: subu        $a3, $a0, $a0
    ctx->r7 = SUB32(ctx->r4, ctx->r4);
    // 0x8010407C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x80104080: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104084: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104088: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8010408C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80104090: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104094: sra         $t9, $a3, 1
    ctx->r25 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80104098: addiu       $a3, $t9, 0x7
    ctx->r7 = ADD32(ctx->r25, 0X7);
    // 0x8010409C: sra         $t6, $a3, 3
    ctx->r14 = S32(SIGNED(ctx->r7) >> 3);
    // 0x801040A0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x801040A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801040A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801040AC: sll         $a3, $t7, 9
    ctx->r7 = S32(ctx->r15 << 9);
    // 0x801040B0: or          $t9, $a3, $s6
    ctx->r25 = ctx->r7 | ctx->r22;
    // 0x801040B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801040B8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x801040BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801040C0: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x801040C4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801040C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801040CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801040D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801040D4: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x801040D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801040DC: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x801040E0: addiu       $t4, $a0, 0x17
    ctx->r12 = ADD32(ctx->r4, 0X17);
    // 0x801040E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801040E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801040EC: or          $t7, $t6, $s7
    ctx->r15 = ctx->r14 | ctx->r23;
    // 0x801040F0: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x801040F4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801040F8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x801040FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104100: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x80104104: ori         $t8, $t7, 0x9C
    ctx->r24 = ctx->r15 | 0X9C;
    // 0x80104108: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010410C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104110: or          $t7, $a3, $fp
    ctx->r15 = ctx->r7 | ctx->r30;
    // 0x80104114: addiu       $t0, $a0, 0x4B
    ctx->r8 = ADD32(ctx->r4, 0X4B);
    // 0x80104118: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010411C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104124: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80104128: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010412C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80104130: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80104134: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104138: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010413C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104140: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104144: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104148: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8010414C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80104150: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104154: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104158: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x8010415C: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80104160: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80104164: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80104168: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010416C: ori         $t8, $t7, 0x9C
    ctx->r24 = ctx->r15 | 0X9C;
    // 0x80104170: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104174: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104178: addiu       $t6, $t0, 0x18
    ctx->r14 = ADD32(ctx->r8, 0X18);
    // 0x8010417C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80104180: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104184: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104188: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8010418C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80104190: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80104194: ori         $t7, $t6, 0x22C
    ctx->r15 = ctx->r14 | 0X22C;
    // 0x80104198: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8010419C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801041A0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x801041A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801041A8: ori         $t7, $t6, 0x18C
    ctx->r15 = ctx->r14 | 0X18C;
    // 0x801041AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801041B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801041B4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x801041B8: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x801041BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801041C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801041C4: sll         $t8, $a0, 21
    ctx->r24 = S32(ctx->r4 << 21);
    // 0x801041C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801041CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801041D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801041D4: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x801041D8: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x801041DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801041E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801041E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801041E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801041EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801041F0: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x801041F4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x801041F8: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x801041FC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80104200: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80104204: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80104208: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8010420C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80104210: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80104214: jr          $ra
    // 0x80104218: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80104218: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80101470_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101470: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80101474: lw          $t6, 0x6250($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6250);
    // 0x80101478: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8010147C: addiu       $v0, $v0, 0x62A0
    ctx->r2 = ADD32(ctx->r2, 0X62A0);
    // 0x80101480: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80101484: bltz        $t7, L_80101494
    if (SIGNED(ctx->r15) < 0) {
        // 0x80101488: lui         $a0, 0x8000
        ctx->r4 = S32(0X8000 << 16);
            goto L_80101494;
    }
    // 0x80101488: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8010148C: jr          $ra
    // 0x80101490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80101490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101494:
    // 0x80101494: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101498: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8010149C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x801014A0: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x801014A4: bne         $t9, $zero, L_801014B4
    if (ctx->r25 != 0) {
        // 0x801014A8: addiu       $a1, $zero, 0x96
        ctx->r5 = ADD32(0, 0X96);
            goto L_801014B4;
    }
    // 0x801014A8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x801014AC: jr          $ra
    // 0x801014B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801014B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801014B4:
    // 0x801014B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x801014B8: and         $t1, $t0, $a0
    ctx->r9 = ctx->r8 & ctx->r4;
    // 0x801014BC: bnel        $t1, $zero, L_801014D8
    if (ctx->r9 != 0) {
        // 0x801014C0: lw          $t3, 0x50($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X50);
            goto L_801014D8;
    }
    goto skip_0;
    // 0x801014C0: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x801014C4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x801014C8: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x801014CC: jr          $ra
    // 0x801014D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x801014D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x801014D4: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
L_801014D8:
    // 0x801014D8: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x801014DC: and         $t4, $t3, $a0
    ctx->r12 = ctx->r11 & ctx->r4;
    // 0x801014E0: bnel        $t4, $zero, L_801014FC
    if (ctx->r12 != 0) {
        // 0x801014E4: lw          $t7, 0x50($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X50);
            goto L_801014FC;
    }
    goto skip_1;
    // 0x801014E4: lw          $t7, 0x50($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x801014E8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x801014EC: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x801014F0: jr          $ra
    // 0x801014F4: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    return;
    // 0x801014F4: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x801014F8: lw          $t7, 0x50($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X50);
L_801014FC:
    // 0x801014FC: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101500: and         $t8, $t7, $a0
    ctx->r24 = ctx->r15 & ctx->r4;
    // 0x80101504: bnel        $t8, $zero, L_80101520
    if (ctx->r24 != 0) {
        // 0x80101508: lw          $t1, 0x50($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X50);
            goto L_80101520;
    }
    goto skip_2;
    // 0x80101508: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x8010150C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80101510: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80101514: jr          $ra
    // 0x80101518: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    return;
    // 0x80101518: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8010151C: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
L_80101520:
    // 0x80101520: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101524: and         $t2, $t1, $a0
    ctx->r10 = ctx->r9 & ctx->r4;
    // 0x80101528: bnel        $t2, $zero, L_80101544
    if (ctx->r10 != 0) {
        // 0x8010152C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80101544;
    }
    goto skip_3;
    // 0x8010152C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x80101530: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80101534: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80101538: jr          $ra
    // 0x8010153C: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    return;
    // 0x8010153C: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80101540: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80101544:
    // 0x80101544: bne         $v1, $a1, L_801014B4
    if (ctx->r3 != ctx->r5) {
        // 0x80101548: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_801014B4;
    }
    // 0x80101548: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8010154C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80101550: jr          $ra
    // 0x80101554: nop

    return;
    // 0x80101554: nop

;}
RECOMP_FUNC void func_80038590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038590: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80038594: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038598: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8003859C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800385A0: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800385A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800385A8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800385AC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800385B0: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800385B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800385B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800385BC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800385C0:
    // 0x800385C0: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800385C4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800385C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800385CC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800385D0: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800385D4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800385D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800385DC: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800385E0: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800385E4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800385E8: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800385EC: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800385F0: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800385F4: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800385F8: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800385FC: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x80038600: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x80038604: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x80038608: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x8003860C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x80038610: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x80038614: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x80038618: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x8003861C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x80038620: bne         $v0, $a0, L_800385C0
    if (ctx->r2 != ctx->r4) {
        // 0x80038624: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800385C0;
    }
    // 0x80038624: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x80038628: jr          $ra
    // 0x8003862C: nop

    return;
    // 0x8003862C: nop

;}
RECOMP_FUNC void func_800443A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800443A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800443AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800443B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800443B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800443B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800443BC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800443C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800443C4: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800443C8: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800443CC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800443D0: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800443D4: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800443D8: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800443DC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800443E0: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800443E4: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800443E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800443EC: jal         0x800442C0
    // 0x800443F0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800442C0(rdram, ctx);
        goto after_0;
    // 0x800443F0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800443F4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800443F8: beql        $t9, $zero, L_800444D0
    if (ctx->r25 == 0) {
        // 0x800443FC: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800444D0;
    }
    goto skip_0;
    // 0x800443FC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80044400: beq         $v0, $zero, L_800444B4
    if (ctx->r2 == 0) {
        // 0x80044404: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800444B4;
    }
    // 0x80044404: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x80044408: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x8004440C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x80044410: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80044414: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80044418: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8004441C: jal         0x80036A30
    // 0x80044420: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80036A30(rdram, ctx);
        goto after_1;
    // 0x80044420: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80044424: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80044428: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004442C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80044430: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80044434: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80044438: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004443C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80044440: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80044444: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80044448: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004444C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x80044450: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80044454: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80044458: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8004445C: jalr        $t9
    // 0x80044460: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80044460: nop

    after_2:
    // 0x80044464: jal         0x80036A30
    // 0x80044468: nop

    func_80036A30(rdram, ctx);
        goto after_3;
    // 0x80044468: nop

    after_3:
    // 0x8004446C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80044470: beq         $v0, $zero, L_800444BC
    if (ctx->r2 == 0) {
        // 0x80044474: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800444BC;
    }
    // 0x80044474: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80044478: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8004447C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80044480: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80044484: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x80044488: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x8004448C: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80044490: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80044494: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80044498: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8004449C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800444A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800444A4: jalr        $t9
    // 0x800444A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800444A8: nop

    after_4:
    // 0x800444AC: b           L_800444C0
    // 0x800444B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800444C0;
    // 0x800444B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800444B4:
    // 0x800444B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800444B8: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800444BC:
    // 0x800444BC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800444C0:
    // 0x800444C0: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800444C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800444C8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800444CC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800444D0:
    // 0x800444D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800444D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800444D8: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800444DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800444E0: jr          $ra
    // 0x800444E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800444E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800444E8: nop

    // 0x800444EC: nop

;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FB20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8003FB24: beq         $a2, $zero, L_8003FB44
    if (ctx->r6 == 0) {
        // 0x8003FB28: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8003FB44;
    }
    // 0x8003FB28: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8003FB2C:
    // 0x8003FB2C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8003FB30: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003FB34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003FB38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003FB3C: bne         $a2, $zero, L_8003FB2C
    if (ctx->r6 != 0) {
        // 0x8003FB40: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_8003FB2C;
    }
    // 0x8003FB40: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_8003FB44:
    // 0x8003FB44: jr          $ra
    // 0x8003FB48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8003FB48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8002B57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B584: jal         0x8002DFD0
    // 0x8002B588: nop

    func_8002DFD0(rdram, ctx);
        goto after_0;
    // 0x8002B588: nop

    after_0:
    // 0x8002B58C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002B590: addiu       $a0, $a0, -0x2E0
    ctx->r4 = ADD32(ctx->r4, -0X2E0);
    // 0x8002B594: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002B598: andi        $v1, $v0, 0x4000
    ctx->r3 = ctx->r2 & 0X4000;
    // 0x8002B59C: bne         $v1, $zero, L_8002B5F8
    if (ctx->r3 != 0) {
        // 0x8002B5A0: andi        $t6, $v0, 0x2000
        ctx->r14 = ctx->r2 & 0X2000;
            goto L_8002B5F8;
    }
    // 0x8002B5A0: andi        $t6, $v0, 0x2000
    ctx->r14 = ctx->r2 & 0X2000;
    // 0x8002B5A4: beq         $t6, $zero, L_8002B5E4
    if (ctx->r14 == 0) {
        // 0x8002B5A8: ori         $t1, $v0, 0x2000
        ctx->r9 = ctx->r2 | 0X2000;
            goto L_8002B5E4;
    }
    // 0x8002B5A8: ori         $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 | 0X2000;
    // 0x8002B5AC: jal         0x8002B8C4
    // 0x8002B5B0: nop

    func_8002B8C4(rdram, ctx);
        goto after_1;
    // 0x8002B5B0: nop

    after_1:
    // 0x8002B5B4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002B5B8: addiu       $a0, $a0, -0x2E0
    ctx->r4 = ADD32(ctx->r4, -0X2E0);
    // 0x8002B5BC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8002B5C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B5C4: ori         $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 | 0X4000;
    // 0x8002B5C8: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8002B5CC: andi        $t0, $t9, 0xDFFF
    ctx->r8 = ctx->r25 & 0XDFFF;
    // 0x8002B5D0: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x8002B5D4: sb          $zero, -0x2D4($at)
    MEM_B(-0X2D4, ctx->r1) = 0;
    // 0x8002B5D8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002B5DC: b           L_8002B5F8
    // 0x8002B5E0: andi        $v1, $v0, 0x4000
    ctx->r3 = ctx->r2 & 0X4000;
        goto L_8002B5F8;
    // 0x8002B5E0: andi        $v1, $v0, 0x4000
    ctx->r3 = ctx->r2 & 0X4000;
L_8002B5E4:
    // 0x8002B5E4: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8002B5E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B5EC: sb          $zero, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = 0;
    // 0x8002B5F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002B5F4: andi        $v1, $v0, 0x4000
    ctx->r3 = ctx->r2 & 0X4000;
L_8002B5F8:
    // 0x8002B5F8: beq         $v1, $zero, L_8002B6A8
    if (ctx->r3 == 0) {
        // 0x8002B5FC: andi        $t2, $v0, 0x7
        ctx->r10 = ctx->r2 & 0X7;
            goto L_8002B6A8;
    }
    // 0x8002B5FC: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x8002B600: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x8002B604: beq         $at, $zero, L_8002B6A8
    if (ctx->r1 == 0) {
        // 0x8002B608: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8002B6A8;
    }
    // 0x8002B608: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002B60C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002B610: addu        $at, $at, $t2
    gpr jr_addend_8002B618 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002B614: lw          $t2, 0x1764($at)
    ctx->r10 = ADD32(ctx->r1, 0X1764);
    // 0x8002B618: jr          $t2
    // 0x8002B61C: nop

    switch (jr_addend_8002B618 >> 2) {
        case 0: goto L_8002B634; break;
        case 1: goto L_8002B684; break;
        case 2: goto L_8002B65C; break;
        case 3: goto L_8002B670; break;
        case 4: goto L_8002B648; break;
        case 5: goto L_8002B620; break;
        case 6: goto L_8002B698; break;
        default: switch_error(__func__, 0x8002B618, 0x80071764);
    }
    // 0x8002B61C: nop

L_8002B620:
    // 0x8002B620: jal         0x8002BCA0
    // 0x8002B624: nop

    func_8002BCA0(rdram, ctx);
        goto after_2;
    // 0x8002B624: nop

    after_2:
    // 0x8002B628: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B62C: b           L_8002B6A8
    // 0x8002B630: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B630: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B634:
    // 0x8002B634: jal         0x8002C818
    // 0x8002B638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002C818(rdram, ctx);
        goto after_3;
    // 0x8002B638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8002B63C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B640: b           L_8002B6A8
    // 0x8002B644: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B644: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B648:
    // 0x8002B648: jal         0x8002D614
    // 0x8002B64C: nop

    func_8002D614(rdram, ctx);
        goto after_4;
    // 0x8002B64C: nop

    after_4:
    // 0x8002B650: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B654: b           L_8002B6A8
    // 0x8002B658: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B658: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B65C:
    // 0x8002B65C: jal         0x8002D748
    // 0x8002B660: nop

    func_8002D748(rdram, ctx);
        goto after_5;
    // 0x8002B660: nop

    after_5:
    // 0x8002B664: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B668: b           L_8002B6A8
    // 0x8002B66C: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B66C: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B670:
    // 0x8002B670: jal         0x8002D8BC
    // 0x8002B674: nop

    func_8002D8BC(rdram, ctx);
        goto after_6;
    // 0x8002B674: nop

    after_6:
    // 0x8002B678: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B67C: b           L_8002B6A8
    // 0x8002B680: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B680: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B684:
    // 0x8002B684: jal         0x8002DBE0
    // 0x8002B688: nop

    func_8002DBE0(rdram, ctx);
        goto after_7;
    // 0x8002B688: nop

    after_7:
    // 0x8002B68C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B690: b           L_8002B6A8
    // 0x8002B694: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
        goto L_8002B6A8;
    // 0x8002B694: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B698:
    // 0x8002B698: jal         0x8002D5D4
    // 0x8002B69C: nop

    func_8002D5D4(rdram, ctx);
        goto after_8;
    // 0x8002B69C: nop

    after_8:
    // 0x8002B6A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B6A4: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
L_8002B6A8:
    // 0x8002B6A8: andi        $t3, $v0, 0x2000
    ctx->r11 = ctx->r2 & 0X2000;
    // 0x8002B6AC: beql        $t3, $zero, L_8002B6C8
    if (ctx->r11 == 0) {
        // 0x8002B6B0: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_8002B6C8;
    }
    goto skip_0;
    // 0x8002B6B0: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    skip_0:
    // 0x8002B6B4: jal         0x8002B6F0
    // 0x8002B6B8: nop

    func_8002B6F0(rdram, ctx);
        goto after_9;
    // 0x8002B6B8: nop

    after_9:
    // 0x8002B6BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B6C0: lhu         $v0, -0x2E0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2E0);
    // 0x8002B6C4: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
L_8002B6C8:
    // 0x8002B6C8: beq         $t4, $zero, L_8002B6E0
    if (ctx->r12 == 0) {
        // 0x8002B6CC: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002B6E0;
    }
    // 0x8002B6CC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B6D0: addiu       $v0, $v0, -0x2F4
    ctx->r2 = ADD32(ctx->r2, -0X2F4);
    // 0x8002B6D4: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x8002B6D8: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x8002B6DC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8002B6E0:
    // 0x8002B6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B6E8: jr          $ra
    // 0x8002B6EC: nop

    return;
    // 0x8002B6EC: nop

;}
RECOMP_FUNC void func_80041C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041C34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80041C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041C3C: lw          $t6, 0x48($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X48);
    // 0x80041C40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041C44: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80041C48: bne         $t6, $at, L_80041C58
    if (ctx->r14 != ctx->r1) {
        // 0x80041C4C: nop
    
            goto L_80041C58;
    }
    // 0x80041C4C: nop

    // 0x80041C50: bnel        $s5, $zero, L_80041C64
    if (ctx->r21 != 0) {
        // 0x80041C54: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_80041C64;
    }
    goto skip_0;
    // 0x80041C54: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_80041C58:
    // 0x80041C58: b           L_80041EBC
    // 0x80041C5C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80041EBC;
    // 0x80041C5C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80041C60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_80041C64:
    // 0x80041C64: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80041C68: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80041C6C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80041C70: jalr        $t9
    // 0x80041C74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80041C74: nop

    after_0:
    // 0x80041C78: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x80041C7C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80041C80: sll         $s7, $s5, 1
    ctx->r23 = S32(ctx->r21 << 1);
    // 0x80041C84: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80041C88: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80041C8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80041C90: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80041C94: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x80041C98: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
    // 0x80041C9C: addiu       $t8, $t9, 0x440
    ctx->r24 = ADD32(ctx->r25, 0X440);
    // 0x80041CA0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80041CA4: andi        $t9, $s7, 0xFFFF
    ctx->r25 = ctx->r23 & 0XFFFF;
    // 0x80041CA8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80041CAC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80041CB0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80041CB4: addiu       $t6, $t8, 0x580
    ctx->r14 = ADD32(ctx->r24, 0X580);
    // 0x80041CB8: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x80041CBC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80041CC0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80041CC4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x80041CC8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80041CCC: addiu       $t8, $v1, 0x800
    ctx->r24 = ADD32(ctx->r3, 0X800);
    // 0x80041CD0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x80041CD4: addiu       $t7, $v1, 0x6C0
    ctx->r15 = ADD32(ctx->r3, 0X6C0);
    // 0x80041CD8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80041CDC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80041CE0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80041CE4: lw          $t7, 0x38($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X38);
    // 0x80041CE8: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x80041CEC: beql        $t7, $zero, L_80041E8C
    if (ctx->r15 == 0) {
        // 0x80041CF0: lui         $t7, 0x308
        ctx->r15 = S32(0X308 << 16);
            goto L_80041E8C;
    }
    goto skip_1;
    // 0x80041CF0: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    skip_1:
    // 0x80041CF4: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x80041CF8: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x80041CFC: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x80041D00: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80041D04: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80041D08: lh          $t9, 0xC80($t9)
    ctx->r25 = MEM_H(ctx->r25, 0XC80);
    // 0x80041D0C: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x80041D10: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x80041D14: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041D18: lh          $t9, 0x1C($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1C);
    // 0x80041D1C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80041D20: nop

    // 0x80041D24: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x80041D28: mflo        $t6
    ctx->r14 = lo;
    // 0x80041D2C: sra         $t8, $t6, 15
    ctx->r24 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80041D30: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x80041D34: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x80041D38: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80041D3C: jal         0x80041A64
    // 0x80041D40: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    func_80041A64(rdram, ctx);
        goto after_1;
    // 0x80041D40: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
    // 0x80041D44: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x80041D48: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80041D4C: sh          $v0, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r2;
    // 0x80041D50: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80041D54: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80041D58: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80041D5C: lh          $t7, 0xD7E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XD7E);
    // 0x80041D60: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x80041D64: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x80041D68: addiu       $s1, $s3, 0x2A
    ctx->r17 = ADD32(ctx->r19, 0X2A);
    // 0x80041D6C: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041D70: lh          $t7, 0x1E($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1E);
    // 0x80041D74: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80041D78: nop

    // 0x80041D7C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041D80: mflo        $t8
    ctx->r24 = lo;
    // 0x80041D84: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x80041D88: sh          $t9, 0x2E($s3)
    MEM_H(0X2E, ctx->r19) = ctx->r25;
    // 0x80041D8C: lh          $t6, 0x2E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2E);
    // 0x80041D90: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80041D94: jal         0x80041A64
    // 0x80041D98: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    func_80041A64(rdram, ctx);
        goto after_2;
    // 0x80041D98: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
    // 0x80041D9C: lh          $t8, 0x1C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1C);
    // 0x80041DA0: sh          $v0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r2;
    // 0x80041DA4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80041DA8: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x80041DAC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80041DB0: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80041DB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80041DB8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80041DBC: lh          $t6, 0x1E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1E);
    // 0x80041DC0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80041DC4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80041DC8: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x80041DCC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80041DD0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80041DD4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80041DD8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80041DDC: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x80041DE0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80041DE4: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x80041DE8: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x80041DEC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80041DF0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80041DF4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80041DF8: lh          $t7, 0x26($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X26);
    // 0x80041DFC: lhu         $t9, 0x24($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X24);
    // 0x80041E00: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80041E04: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80041E08: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80041E0C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80041E10: lh          $t8, 0x2E($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2E);
    // 0x80041E14: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x80041E18: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80041E1C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x80041E20: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80041E24: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80041E28: lh          $t8, 0x2C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2C);
    // 0x80041E2C: lhu         $t7, 0x2A($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X2A);
    // 0x80041E30: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80041E34: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80041E38: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80041E3C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80041E40: lh          $t9, 0x20($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X20);
    // 0x80041E44: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x80041E48: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80041E4C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80041E50: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80041E54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80041E58: lh          $t8, 0x22($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X22);
    // 0x80041E5C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80041E60: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80041E64: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80041E68: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80041E6C: lui         $t6, 0x309
    ctx->r14 = S32(0X309 << 16);
    // 0x80041E70: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80041E74: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x80041E78: jal         0x80034DD0
    // 0x80041E7C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x80041E7C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_3:
    // 0x80041E80: b           L_80041EA0
    // 0x80041E84: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_80041EA0;
    // 0x80041E84: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80041E88: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
L_80041E8C:
    // 0x80041E8C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80041E90: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x80041E94: jal         0x80034DD0
    // 0x80041E98: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80041E98: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
    // 0x80041E9C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80041EA0:
    // 0x80041EA0: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x80041EA4: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80041EA8: addu        $t9, $t8, $s7
    ctx->r25 = ADD32(ctx->r24, ctx->r23);
    // 0x80041EAC: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x80041EB0: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x80041EB4: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x80041EB8: sw          $t7, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r15;
L_80041EBC:
    // 0x80041EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80041EC4: jr          $ra
    // 0x80041EC8: nop

    return;
    // 0x80041EC8: nop

;}
RECOMP_FUNC void func_80049770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049770: jr          $ra
    // 0x80049774: nop

    return;
    // 0x80049774: nop

;}
RECOMP_FUNC void nnScStartScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000062C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000630: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80000638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000063C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80000640: addiu       $t6, $t6, -0x6D30
    ctx->r14 = ADD32(ctx->r14, -0X6D30);
    // 0x80000644: addiu       $a0, $s0, 0x158
    ctx->r4 = ADD32(ctx->r16, 0X158);
    // 0x80000648: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8000064C: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80000650: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80000654: addiu       $a2, $a2, 0x710
    ctx->r6 = ADD32(ctx->r6, 0X710);
    // 0x80000658: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8000065C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80000660: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80000664: jal         0x80033AE0
    // 0x80000668: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80000668: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x8000066C: jal         0x80033C30
    // 0x80000670: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80000670: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80000674: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80000678: addiu       $t8, $t8, -0x5D30
    ctx->r24 = ADD32(ctx->r24, -0X5D30);
    // 0x8000067C: addiu       $a0, $s0, 0x308
    ctx->r4 = ADD32(ctx->r16, 0X308);
    // 0x80000680: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000684: addiu       $t9, $zero, 0x6E
    ctx->r25 = ADD32(0, 0X6E);
    // 0x80000688: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000068C: addiu       $a2, $a2, 0x900
    ctx->r6 = ADD32(ctx->r6, 0X900);
    // 0x80000690: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80000694: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80000698: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8000069C: jal         0x80033AE0
    // 0x800006A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800006A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800006A4: jal         0x80033C30
    // 0x800006A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800006A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800006AC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800006B0: addiu       $t0, $t0, -0x4D30
    ctx->r8 = ADD32(ctx->r8, -0X4D30);
    // 0x800006B4: addiu       $a0, $s0, 0x4B8
    ctx->r4 = ADD32(ctx->r16, 0X4B8);
    // 0x800006B8: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800006BC: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x800006C0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800006C4: addiu       $a2, $a2, 0xA80
    ctx->r6 = ADD32(ctx->r6, 0XA80);
    // 0x800006C8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800006CC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800006D0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x800006D4: jal         0x80033AE0
    // 0x800006D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x800006D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800006DC: jal         0x80033C30
    // 0x800006E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x800006E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x800006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800006E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800006EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800006F0: jr          $ra
    // 0x800006F4: nop

    return;
    // 0x800006F4: nop

;}
