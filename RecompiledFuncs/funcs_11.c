#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80048DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048DC8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80048DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048DD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048DD4: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80048DD8: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80048DDC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80048DE0: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80048DE4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80048DE8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80048DEC: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x80048DF0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x80048DF4: beq         $at, $zero, L_80048E00
    if (ctx->r1 == 0) {
        // 0x80048DF8: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_80048E00;
    }
    // 0x80048DF8: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x80048DFC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_80048E00:
    // 0x80048E00: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80048E04: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x80048E08: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x80048E0C: beq         $at, $zero, L_80048EEC
    if (ctx->r1 == 0) {
        // 0x80048E10: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_80048EEC;
    }
    // 0x80048E10: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80048E14: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80048E18: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80048E1C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x80048E20: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80048E24: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80048E28: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80048E2C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80048E30: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80048E34: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80048E38: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80048E3C: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x80048E40: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80048E44: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80048E48: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80048E4C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80048E50: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80048E54: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80048E58: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80048E5C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80048E60: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80048E64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048E68: jal         0x80034DD0
    // 0x80048E6C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80048E6C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80048E70: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80048E74: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80048E78: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80048E7C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80048E80: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80048E84: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80048E88: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80048E8C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80048E90: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80048E94: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80048E98: subu        $t8, $a3, $t1
    ctx->r24 = SUB32(ctx->r7, ctx->r9);
    // 0x80048E9C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80048EA0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048EA4: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80048EA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80048EAC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80048EB0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80048EB4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048EB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80048EBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048EC0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80048EC4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80048EC8: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x80048ECC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80048ED0: jal         0x80034DD0
    // 0x80048ED4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80048ED4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x80048ED8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80048EDC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80048EE0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80048EE4: b           L_80048F30
    // 0x80048EE8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_80048F30;
    // 0x80048EE8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_80048EEC:
    // 0x80048EEC: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x80048EF0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80048EF4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80048EF8: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x80048EFC: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x80048F00: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80048F04: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048F08: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80048F0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80048F10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80048F14: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80048F18: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048F1C: jal         0x80034DD0
    // 0x80048F20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80048F20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80048F24: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80048F28: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80048F2C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80048F30:
    // 0x80048F30: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048F34: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80048F38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80048F3C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80048F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048F44: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80048F48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048F4C: jr          $ra
    // 0x80048F50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80048F50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80016A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016A88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016A8C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80016A90: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
    // 0x80016A94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016A98: lhu         $t7, 0x18($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X18);
    // 0x80016A9C: beql        $t7, $at, L_80016B0C
    if (ctx->r15 == ctx->r1) {
        // 0x80016AA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80016B0C;
    }
    goto skip_0;
    // 0x80016AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80016AA4: lhu         $t8, 0x5E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X5E);
    // 0x80016AA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80016AAC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80016AB0: beql        $t9, $zero, L_80016B00
    if (ctx->r25 == 0) {
        // 0x80016AB4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80016B00;
    }
    goto skip_1;
    // 0x80016AB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    skip_1:
    // 0x80016AB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80016ABC: jal         0x8000B140
    // 0x80016AC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8000B140(rdram, ctx);
        goto after_0;
    // 0x80016AC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80016AC4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80016AC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80016ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016AD0: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80016AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80016AD8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80016ADC: jal         0x8000ACC0
    // 0x80016AE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8000ACC0(rdram, ctx);
        goto after_1;
    // 0x80016AE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x80016AE4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016AE8: lw          $v1, -0x4538($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4538);
    // 0x80016AEC: lhu         $t2, 0x2A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2A);
    // 0x80016AF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80016AF4: b           L_80016B08
    // 0x80016AF8: sh          $t3, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r11;
        goto L_80016B08;
    // 0x80016AF8: sh          $t3, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r11;
    // 0x80016AFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80016B00:
    // 0x80016B00: jal         0x80006BEC
    // 0x80016B04: lw          $a2, 0x24($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X24);
    func_80006BEC(rdram, ctx);
        goto after_2;
    // 0x80016B04: lw          $a2, 0x24($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X24);
    after_2:
L_80016B08:
    // 0x80016B08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80016B0C:
    // 0x80016B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016B10: jr          $ra
    // 0x80016B14: nop

    return;
    // 0x80016B14: nop

;}
RECOMP_FUNC void func_80022B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022B40: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80022B44: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80022B48: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80022B4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022B50: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80022B54: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80022B58: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80022B5C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80022B60: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80022B64: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80022B68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80022B6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80022B70: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80022B74: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80022B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022B7C: bnel        $t6, $at, L_80022C4C
    if (ctx->r14 != ctx->r1) {
        // 0x80022B80: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80022C4C;
    }
    goto skip_0;
    // 0x80022B80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80022B84: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80022B88: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80022B8C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80022B90: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80022B94: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80022B98: addiu       $v0, $t8, 0x4
    ctx->r2 = ADD32(ctx->r24, 0X4);
    // 0x80022B9C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80022BA0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80022BA4: beq         $v1, $a0, L_80022BF8
    if (ctx->r3 == ctx->r4) {
        // 0x80022BA8: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80022BF8;
    }
    // 0x80022BA8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80022BAC:
    // 0x80022BAC: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80022BB0: lwc1        $f30, 0x0($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80022BB4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80022BB8: swc1        $f30, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f30.u32l;
    // 0x80022BBC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80022BC0: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80022BC4: lwc1        $f30, 0x4($t6)
    ctx->f30.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80022BC8: swc1        $f30, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f30.u32l;
    // 0x80022BCC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80022BD0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80022BD4: lwc1        $f30, 0x8($t8)
    ctx->f30.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80022BD8: swc1        $f30, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f30.u32l;
    // 0x80022BDC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80022BE0: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80022BE4: lwc1        $f30, 0xC($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80022BE8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80022BEC: swc1        $f30, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f30.u32l;
    // 0x80022BF0: bne         $v1, $a0, L_80022BAC
    if (ctx->r3 != ctx->r4) {
        // 0x80022BF4: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80022BAC;
    }
    // 0x80022BF4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80022BF8:
    // 0x80022BF8: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80022BFC: lwc1        $f30, 0x0($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80022C00: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80022C04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80022C08: swc1        $f30, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f30.u32l;
    // 0x80022C0C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80022C10: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80022C14: lwc1        $f30, 0x4($t6)
    ctx->f30.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80022C18: swc1        $f30, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f30.u32l;
    // 0x80022C1C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80022C20: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80022C24: lwc1        $f30, 0x8($t8)
    ctx->f30.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80022C28: swc1        $f30, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f30.u32l;
    // 0x80022C2C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80022C30: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80022C34: lwc1        $f30, 0xC($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80022C38: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80022C3C: swc1        $f30, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f30.u32l;
    // 0x80022C40: b           L_80022F38
    // 0x80022C44: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80022F38;
    // 0x80022C44: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80022C48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80022C4C:
    // 0x80022C4C: lhu         $v0, 0x66($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X66);
    // 0x80022C50: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80022C54: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80022C58: beql        $at, $zero, L_80022C78
    if (ctx->r1 == 0) {
        // 0x80022C5C: lhu         $v1, -0x2($a0)
        ctx->r3 = MEM_HU(ctx->r4, -0X2);
            goto L_80022C78;
    }
    goto skip_1;
    // 0x80022C5C: lhu         $v1, -0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, -0X2);
    skip_1:
    // 0x80022C60: lhu         $v0, 0x66($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X66);
L_80022C64:
    // 0x80022C64: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x80022C68: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80022C6C: bnel        $at, $zero, L_80022C64
    if (ctx->r1 != 0) {
        // 0x80022C70: lhu         $v0, 0x66($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X66);
            goto L_80022C64;
    }
    goto skip_2;
    // 0x80022C70: lhu         $v0, 0x66($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X66);
    skip_2:
    // 0x80022C74: lhu         $v1, -0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, -0X2);
L_80022C78:
    // 0x80022C78: lhu         $t5, 0x30($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X30);
    // 0x80022C7C: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x80022C80: bne         $t5, $zero, L_80022DDC
    if (ctx->r13 != 0) {
        // 0x80022C84: subu        $t3, $v0, $v1
        ctx->r11 = SUB32(ctx->r2, ctx->r3);
            goto L_80022DDC;
    }
    // 0x80022C84: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x80022C88: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80022C8C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80022C90: addiu       $t6, $sp, 0xC4
    ctx->r14 = ADD32(ctx->r29, 0XC4);
    // 0x80022C94: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80022C98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80022C9C: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x80022CA0: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    // 0x80022CA4: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    // 0x80022CA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80022CAC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x80022CB0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80022CB4: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80022CB8: jal         0x80022F60
    // 0x80022CBC: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    func_80022F60(rdram, ctx);
        goto after_0;
    // 0x80022CBC: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    after_0:
    // 0x80022CC0: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80022CC4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80022CC8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80022CCC: addiu       $t1, $a0, -0x34
    ctx->r9 = ADD32(ctx->r4, -0X34);
    // 0x80022CD0: lwc1        $f4, 0x24($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X24);
    // 0x80022CD4: lwc1        $f8, 0x28($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X28);
    // 0x80022CD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022CDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022CE0: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80022CE4: sub.d       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f0.d - ctx->f6.d;
    // 0x80022CE8: lwc1        $f10, 0x2C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80022CEC: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80022CF0: add.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f0.d + ctx->f18.d;
    // 0x80022CF4: lwc1        $f30, 0x90($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80022CF8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80022CFC: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80022D00: sdc1        $f4, 0x58($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X58, ctx->r29);
    // 0x80022D04: mov.d       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = ctx->f4.d;
    // 0x80022D08: add.d       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f0.d + ctx->f4.d;
    // 0x80022D0C: lhu         $v0, 0x32($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X32);
    // 0x80022D10: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80022D14: sub.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f0.d - ctx->f18.d;
    // 0x80022D18: mul.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80022D1C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x80022D20: sub.d       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f0.d - ctx->f10.d;
    // 0x80022D24: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80022D28: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80022D2C: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80022D30: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80022D34: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x80022D38: sub.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d - ctx->f12.d;
    // 0x80022D3C: sub.d       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f0.d - ctx->f4.d;
    // 0x80022D40: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    // 0x80022D44: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80022D48: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80022D4C: add.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d + ctx->f12.d;
    // 0x80022D50: cvt.d.s     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f14.d = CVT_D_S(ctx->f8.fl);
    // 0x80022D54: add.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f0.d + ctx->f14.d;
    // 0x80022D58: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80022D5C: sub.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f0.d - ctx->f14.d;
    // 0x80022D60: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80022D64: cvt.s.d     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f24.fl = CVT_S_D(ctx->f8.d);
    // 0x80022D68: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80022D6C: beq         $v0, $zero, L_80022D94
    if (ctx->r2 == 0) {
        // 0x80022D70: cvt.s.d     $f26, $f8
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f26.fl = CVT_S_D(ctx->f8.d);
            goto L_80022D94;
    }
    // 0x80022D70: cvt.s.d     $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f26.fl = CVT_S_D(ctx->f8.d);
    // 0x80022D74: lhu         $t7, 0x32($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X32);
    // 0x80022D78: lhu         $t8, -0x2($t1)
    ctx->r24 = MEM_HU(ctx->r9, -0X2);
    // 0x80022D7C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80022D80: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80022D84: nop

    // 0x80022D88: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80022D8C: div.s       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f30.fl, ctx->f4.fl);
    // 0x80022D90: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
L_80022D94:
    // 0x80022D94: swc1        $f20, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f20.u32l;
    // 0x80022D98: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x80022D9C: swc1        $f24, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f24.u32l;
    // 0x80022DA0: swc1        $f26, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f26.u32l;
    // 0x80022DA4: lhu         $t5, 0x32($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X32);
    // 0x80022DA8: lhu         $t4, 0x6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6);
    // 0x80022DAC: beql        $t4, $t5, L_80022DE0
    if (ctx->r12 == ctx->r13) {
        // 0x80022DB0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80022DE0;
    }
    goto skip_3;
    // 0x80022DB0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_3:
    // 0x80022DB4: lhu         $t6, 0x66($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X66);
    // 0x80022DB8: swc1        $f26, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f26.u32l;
    // 0x80022DBC: swc1        $f24, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f24.u32l;
    // 0x80022DC0: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80022DC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80022DC8: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x80022DCC: swc1        $f20, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f20.u32l;
    // 0x80022DD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80022DD4: div.s       $f28, $f30, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = DIV_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80022DD8: swc1        $f28, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f28.u32l;
L_80022DDC:
    // 0x80022DDC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_80022DE0:
    // 0x80022DE0: addiu       $t1, $a0, -0x34
    ctx->r9 = ADD32(ctx->r4, -0X34);
    // 0x80022DE4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022DE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022DEC: lwc1        $f20, 0xB8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80022DF0: lwc1        $f22, 0xB4($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80022DF4: lwc1        $f24, 0xB0($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80022DF8: lwc1        $f26, 0xAC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80022DFC: lwc1        $f28, 0xA4($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80022E00: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x80022E04: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80022E08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80022E0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80022E10: lwc1        $f30, 0xA8($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80022E14: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
L_80022E18:
    // 0x80022E18: lhu         $t8, 0x30($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X30);
    // 0x80022E1C: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80022E20: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80022E24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022E28: bne         $t8, $zero, L_80022F04
    if (ctx->r24 != 0) {
        // 0x80022E2C: sub.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_80022F04;
    }
    // 0x80022E2C: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80022E30: lhu         $t9, 0x32($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X32);
    // 0x80022E34: lhu         $v0, 0x32($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X32);
    // 0x80022E38: lhu         $t0, 0x6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6);
    // 0x80022E3C: bnel        $t9, $zero, L_80022E68
    if (ctx->r25 != 0) {
        // 0x80022E40: lwc1        $f6, -0x34($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, -0X34);
            goto L_80022E68;
    }
    goto skip_4;
    // 0x80022E40: lwc1        $f6, -0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X34);
    skip_4:
    // 0x80022E44: add.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80022E48: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80022E4C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022E50: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80022E54: nop

    // 0x80022E58: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80022E5C: b           L_80022E84
    // 0x80022E60: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
        goto L_80022E84;
    // 0x80022E60: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x80022E64: lwc1        $f6, -0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X34);
L_80022E68:
    // 0x80022E68: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80022E6C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80022E70: nop

    // 0x80022E74: mul.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80022E78: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80022E7C: mul.s       $f16, $f6, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x80022E80: nop

L_80022E84:
    // 0x80022E84: bnel        $t0, $v0, L_80022EB0
    if (ctx->r8 != ctx->r2) {
        // 0x80022E88: lwc1        $f10, 0x34($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
            goto L_80022EB0;
    }
    goto skip_5;
    // 0x80022E88: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    skip_5:
    // 0x80022E8C: add.s       $f8, $f24, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x80022E90: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80022E94: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80022E98: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80022E9C: nop

    // 0x80022EA0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80022EA4: b           L_80022ECC
    // 0x80022EA8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
        goto L_80022ECC;
    // 0x80022EA8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80022EAC: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
L_80022EB0:
    // 0x80022EB0: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80022EB4: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80022EB8: nop

    // 0x80022EBC: mul.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80022EC0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80022EC4: mul.s       $f12, $f10, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x80022EC8: nop

L_80022ECC:
    // 0x80022ECC: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80022ED0: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80022ED4: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80022ED8: nop

    // 0x80022EDC: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80022EE0: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80022EE4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80022EE8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80022EEC: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80022EF0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80022EF4: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80022EF8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80022EFC: b           L_80022F24
    // 0x80022F00: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_80022F24;
    // 0x80022F00: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_80022F04:
    // 0x80022F04: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80022F08: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80022F0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80022F10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022F14: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80022F18: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80022F1C: add.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80022F20: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80022F24:
    // 0x80022F24: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80022F28: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80022F2C: bne         $v1, $t2, L_80022E18
    if (ctx->r3 != ctx->r10) {
        // 0x80022F30: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80022E18;
    }
    // 0x80022F30: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80022F34: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80022F38:
    // 0x80022F38: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80022F3C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80022F40: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80022F44: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80022F48: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80022F4C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80022F50: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80022F54: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80022F58: jr          $ra
    // 0x80022F5C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80022F5C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80000C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C50: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000C54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000C58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80000C5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80000C60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80000C64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80000C68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80000C6C: jal         0x80034840
    // 0x80000C70: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80000C70: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80000C74: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80000C78: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80000C7C: addiu       $a1, $a1, -0x4CC8
    ctx->r5 = ADD32(ctx->r5, -0X4CC8);
    // 0x80000C80: addiu       $a0, $a0, -0x4CE0
    ctx->r4 = ADD32(ctx->r4, -0X4CE0);
    // 0x80000C84: jal         0x80033F10
    // 0x80000C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80000C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80000C8C: jal         0x80024704
    // 0x80000C90: nop

    func_80024704(rdram, ctx);
        goto after_2;
    // 0x80000C90: nop

    after_2:
    // 0x80000C94: lui         $t6, 0xE8
    ctx->r14 = S32(0XE8 << 16);
    // 0x80000C98: addiu       $t6, $t6, 0x1610
    ctx->r14 = ADD32(ctx->r14, 0X1610);
    // 0x80000C9C: lui         $a0, 0xE8
    ctx->r4 = S32(0XE8 << 16);
    // 0x80000CA0: lui         $a1, 0xE8
    ctx->r5 = S32(0XE8 << 16);
    // 0x80000CA4: lui         $a2, 0xEC
    ctx->r6 = S32(0XEC << 16);
    // 0x80000CA8: lui         $a3, 0xEF
    ctx->r7 = S32(0XEF << 16);
    // 0x80000CAC: addiu       $a3, $a3, -0x1FE0
    ctx->r7 = ADD32(ctx->r7, -0X1FE0);
    // 0x80000CB0: addiu       $a2, $a2, -0x5430
    ctx->r6 = ADD32(ctx->r6, -0X5430);
    // 0x80000CB4: addiu       $a1, $a1, 0x1610
    ctx->r5 = ADD32(ctx->r5, 0X1610);
    // 0x80000CB8: addiu       $a0, $a0, -0x1800
    ctx->r4 = ADD32(ctx->r4, -0X1800);
    // 0x80000CBC: jal         0x8002513C
    // 0x80000CC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8002513C(rdram, ctx);
        goto after_3;
    // 0x80000CC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x80000CC4: lui         $a0, 0xEF
    ctx->r4 = S32(0XEF << 16);
    // 0x80000CC8: lui         $a1, 0xEF
    ctx->r5 = S32(0XEF << 16);
    // 0x80000CCC: lui         $a2, 0xEF
    ctx->r6 = S32(0XEF << 16);
    // 0x80000CD0: addiu       $a2, $a2, -0x320
    ctx->r6 = ADD32(ctx->r6, -0X320);
    // 0x80000CD4: addiu       $a1, $a1, -0x320
    ctx->r5 = ADD32(ctx->r5, -0X320);
    // 0x80000CD8: jal         0x80025488
    // 0x80000CDC: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    func_80025488(rdram, ctx);
        goto after_4;
    // 0x80000CDC: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    after_4:
    // 0x80000CE0: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80000CE4: addiu       $s0, $s0, -0x4CA8
    ctx->r16 = ADD32(ctx->r16, -0X4CA8);
    // 0x80000CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000CEC: jal         0x80000530
    // 0x80000CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    nnScCreateScheduler(rdram, ctx);
        goto after_5;
    // 0x80000CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80000CF4: jal         0x80031300
    // 0x80000CF8: nop

    func_80031300(rdram, ctx);
        goto after_6;
    // 0x80000CF8: nop

    after_6:
    // 0x80000CFC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80000D00: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80000D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000D08: bne         $t7, $at, L_80000D20
    if (ctx->r15 != ctx->r1) {
        // 0x80000D0C: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80000D20;
    }
    // 0x80000D0C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80000D10: jal         0x80034BA0
    // 0x80000D14: addiu       $a0, $a0, -0xB10
    ctx->r4 = ADD32(ctx->r4, -0XB10);
    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x80000D14: addiu       $a0, $a0, -0xB10
    ctx->r4 = ADD32(ctx->r4, -0XB10);
    after_7:
    // 0x80000D18: b           L_80000D2C
    // 0x80000D1C: nop

        goto L_80000D2C;
    // 0x80000D1C: nop

L_80000D20:
    // 0x80000D20: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80000D24: jal         0x80034BA0
    // 0x80000D28: addiu       $a0, $a0, -0x250
    ctx->r4 = ADD32(ctx->r4, -0X250);
    osViSetMode_recomp(rdram, ctx);
        goto after_8;
    // 0x80000D28: addiu       $a0, $a0, -0x250
    ctx->r4 = ADD32(ctx->r4, -0X250);
    after_8:
L_80000D2C:
    // 0x80000D2C: jal         0x800346E0
    // 0x80000D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_9;
    // 0x80000D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80000D34: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80000D38: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80000D3C: addiu       $a1, $a1, -0x4C34
    ctx->r5 = ADD32(ctx->r5, -0X4C34);
    // 0x80000D40: jal         0x80032704
    // 0x80000D44: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    func_80032704(rdram, ctx);
        goto after_10;
    // 0x80000D44: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    after_10:
    // 0x80000D48: jal         0x800346E0
    // 0x80000D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_11;
    // 0x80000D4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80000D50: jal         0x80034C10
    // 0x80000D54: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_12;
    // 0x80000D54: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_12:
    // 0x80000D58: jal         0x8000062C
    // 0x80000D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    nnScStartScheduler(rdram, ctx);
        goto after_13;
    // 0x80000D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80000D60: jal         0x800250E8
    // 0x80000D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800250E8(rdram, ctx);
        goto after_14;
    // 0x80000D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80000D68: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80000D6C: addiu       $s1, $s1, -0x4618
    ctx->r17 = ADD32(ctx->r17, -0X4618);
    // 0x80000D70: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80000D74: addiu       $a1, $a1, -0x4600
    ctx->r5 = ADD32(ctx->r5, -0X4600);
    // 0x80000D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000D7C: jal         0x80033F10
    // 0x80000D80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_15;
    // 0x80000D80: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_15:
    // 0x80000D84: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80000D88: addiu       $a1, $a1, -0x4620
    ctx->r5 = ADD32(ctx->r5, -0X4620);
    // 0x80000D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000D90: jal         0x800007D4
    // 0x80000D94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    nnScAddClient(rdram, ctx);
        goto after_16;
    // 0x80000D94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_16:
    // 0x80000D98: jal         0x80000704
    // 0x80000D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    nnScGetGfxMQ(rdram, ctx);
        goto after_17;
    // 0x80000D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80000DA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80000DA4: jal         0x80000FE8
    // 0x80000DA8: sw          $v0, -0x4628($at)
    MEM_W(-0X4628, ctx->r1) = ctx->r2;
    func_80000FE8(rdram, ctx);
        goto after_18;
    // 0x80000DA8: sw          $v0, -0x4628($at)
    MEM_W(-0X4628, ctx->r1) = ctx->r2;
    after_18:
    // 0x80000DAC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80000DB0: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80000DB4: addiu       $s0, $s0, -0x4D1C
    ctx->r16 = ADD32(ctx->r16, -0X4D1C);
    // 0x80000DB8: addiu       $s2, $s2, -0x4D20
    ctx->r18 = ADD32(ctx->r18, -0X4D20);
    // 0x80000DBC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80000DC0: addiu       $s1, $zero, -0x4
    ctx->r17 = ADD32(0, -0X4);
L_80000DC4:
    // 0x80000DC4: jal         0x8000B520
    // 0x80000DC8: nop

    func_8000B520(rdram, ctx);
        goto after_19;
    // 0x80000DC8: nop

    after_19:
    // 0x80000DCC: jal         0x80011B40
    // 0x80000DD0: nop

    func_80011B40(rdram, ctx);
        goto after_20;
    // 0x80000DD0: nop

    after_20:
    // 0x80000DD4: jal         0x800121F0
    // 0x80000DD8: nop

    func_800121F0(rdram, ctx);
        goto after_21;
    // 0x80000DD8: nop

    after_21:
    // 0x80000DDC: jal         0x800027D0
    // 0x80000DE0: nop

    func_800027D0(rdram, ctx);
        goto after_22;
    // 0x80000DE0: nop

    after_22:
    // 0x80000DE4: jal         0x80021170
    // 0x80000DE8: nop

    func_80021170(rdram, ctx);
        goto after_23;
    // 0x80000DE8: nop

    after_23:
    // 0x80000DEC: jal         0x800100D0
    // 0x80000DF0: nop

    func_800100D0(rdram, ctx);
        goto after_24;
    // 0x80000DF0: nop

    after_24:
    // 0x80000DF4: jal         0x80030E58
    // 0x80000DF8: nop

    func_80030E58(rdram, ctx);
        goto after_25;
    // 0x80000DF8: nop

    after_25:
    // 0x80000DFC: jal         0x800265F0
    // 0x80000E00: nop

    func_800265F0(rdram, ctx);
        goto after_26;
    // 0x80000E00: nop

    after_26:
    // 0x80000E04: jal         0x80000EEC
    // 0x80000E08: nop

    func_80000EEC(rdram, ctx);
        goto after_27;
    // 0x80000E08: nop

    after_27:
    // 0x80000E0C: jal         0x80026A40
    // 0x80000E10: nop

    func_80026A40(rdram, ctx);
        goto after_28;
    // 0x80000E10: nop

    after_28:
    // 0x80000E14: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80000E18: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
L_80000E1C:
    // 0x80000E1C: and         $t8, $v1, $s1
    ctx->r24 = ctx->r3 & ctx->r17;
    // 0x80000E20: bne         $v0, $zero, L_80000E30
    if (ctx->r2 != 0) {
        // 0x80000E24: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_80000E30;
    }
    // 0x80000E24: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80000E28: sh          $s3, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r19;
    // 0x80000E2C: andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
L_80000E30:
    // 0x80000E30: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80000E34: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80000E38: beq         $at, $zero, L_80000E9C
    if (ctx->r1 == 0) {
        // 0x80000E3C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80000E9C;
    }
    // 0x80000E3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80000E40: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80000E44: addu        $at, $at, $t9
    gpr jr_addend_80000E4C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80000E48: lw          $t9, 0xEF0($at)
    ctx->r25 = ADD32(ctx->r1, 0XEF0);
    // 0x80000E4C: jr          $t9
    // 0x80000E50: nop

    switch (jr_addend_80000E4C >> 2) {
        case 0: goto L_80000E54; break;
        case 1: goto L_80000E64; break;
        case 2: goto L_80000E74; break;
        case 3: goto L_80000E84; break;
        case 4: goto L_80000E94; break;
        default: switch_error(__func__, 0x80000E4C, 0x80070EF0);
    }
    // 0x80000E50: nop

L_80000E54:
    // 0x80000E54: jal         0x80001800
    // 0x80000E58: nop

    func_80001800(rdram, ctx);
        goto after_29;
    // 0x80000E58: nop

    after_29:
    // 0x80000E5C: b           L_80000EA0
    // 0x80000E60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80000EA0;
    // 0x80000E60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80000E64:
    // 0x80000E64: jal         0x800020B4
    // 0x80000E68: nop

    func_800020B4(rdram, ctx);
        goto after_30;
    // 0x80000E68: nop

    after_30:
    // 0x80000E6C: b           L_80000EA0
    // 0x80000E70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80000EA0;
    // 0x80000E70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80000E74:
    // 0x80000E74: jal         0x8000227C
    // 0x80000E78: nop

    func_8000227C(rdram, ctx);
        goto after_31;
    // 0x80000E78: nop

    after_31:
    // 0x80000E7C: b           L_80000EA0
    // 0x80000E80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80000EA0;
    // 0x80000E80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80000E84:
    // 0x80000E84: jal         0x80002428
    // 0x80000E88: nop

    func_80002428(rdram, ctx);
        goto after_32;
    // 0x80000E88: nop

    after_32:
    // 0x80000E8C: b           L_80000EA0
    // 0x80000E90: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80000EA0;
    // 0x80000E90: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80000E94:
    // 0x80000E94: jal         0x800025E8
    // 0x80000E98: nop

    func_800025E8(rdram, ctx);
        goto after_33;
    // 0x80000E98: nop

    after_33:
L_80000E9C:
    // 0x80000E9C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80000EA0:
    // 0x80000EA0: andi        $t0, $v1, 0x8000
    ctx->r8 = ctx->r3 & 0X8000;
    // 0x80000EA4: bne         $t0, $zero, L_80000DC4
    if (ctx->r8 != 0) {
        // 0x80000EA8: nop
    
            goto L_80000DC4;
    }
    // 0x80000EA8: nop

    // 0x80000EAC: b           L_80000E1C
    // 0x80000EB0: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
        goto L_80000E1C;
    // 0x80000EB0: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80000EB4: nop

    // 0x80000EB8: nop

    // 0x80000EBC: nop

    // 0x80000EC0: nop

    // 0x80000EC4: nop

    // 0x80000EC8: nop

    // 0x80000ECC: nop

    // 0x80000ED0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000ED4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80000ED8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80000EDC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80000EE0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80000EE4: jr          $ra
    // 0x80000EE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80000EE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002E404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E404: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002E408: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002E40C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002E410: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8002E414: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002E418: addiu       $t7, $t7, -0x2A8
    ctx->r15 = ADD32(ctx->r15, -0X2A8);
    // 0x8002E41C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002E420: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8002E424: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8002E428: addiu       $t8, $t8, -0x4580
    ctx->r24 = ADD32(ctx->r24, -0X4580);
    // 0x8002E42C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8002E430: addiu       $t1, $a2, 0x30
    ctx->r9 = ADD32(ctx->r6, 0X30);
L_8002E434:
    // 0x8002E434: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002E438: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8002E43C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8002E440: sw          $at, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r1;
    // 0x8002E444: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x8002E448: sw          $at, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r1;
    // 0x8002E44C: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x8002E450: bne         $t2, $t1, L_8002E434
    if (ctx->r10 != ctx->r9) {
        // 0x8002E454: sw          $at, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r1;
            goto L_8002E434;
    }
    // 0x8002E454: sw          $at, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r1;
    // 0x8002E458: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002E45C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E460: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E464: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8002E468: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x8002E46C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E470: addiu       $v0, $v0, 0x398
    ctx->r2 = ADD32(ctx->r2, 0X398);
    // 0x8002E474: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x8002E478: lhu         $t3, 0x38($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X38);
    // 0x8002E47C: addiu       $v1, $v1, 0x69D8
    ctx->r3 = ADD32(ctx->r3, 0X69D8);
    // 0x8002E480: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8002E484: sh          $t3, 0x59E2($at)
    MEM_H(0X59E2, ctx->r1) = ctx->r11;
    // 0x8002E488: lhu         $t4, 0x3A($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X3A);
    // 0x8002E48C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E490: sh          $t4, 0x59E0($at)
    MEM_H(0X59E0, ctx->r1) = ctx->r12;
    // 0x8002E494: lw          $t5, 0x3C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X3C);
    // 0x8002E498: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E49C: sw          $t5, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = ctx->r13;
    // 0x8002E4A0: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x8002E4A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4A8: sw          $t6, 0x4EE8($at)
    MEM_W(0X4EE8, ctx->r1) = ctx->r14;
    // 0x8002E4AC: lw          $t7, 0x44($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X44);
    // 0x8002E4B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4B4: sw          $t7, 0x4EF8($at)
    MEM_W(0X4EF8, ctx->r1) = ctx->r15;
    // 0x8002E4B8: lw          $t0, 0x48($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X48);
    // 0x8002E4BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4C0: sw          $t0, 0x4EFC($at)
    MEM_W(0X4EFC, ctx->r1) = ctx->r8;
    // 0x8002E4C4: lw          $t9, 0x4C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4C);
    // 0x8002E4C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4CC: sw          $t9, 0x4F00($at)
    MEM_W(0X4F00, ctx->r1) = ctx->r25;
    // 0x8002E4D0: lw          $t1, 0x50($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X50);
    // 0x8002E4D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4D8: sw          $t1, 0x4F04($at)
    MEM_W(0X4F04, ctx->r1) = ctx->r9;
    // 0x8002E4DC: lw          $t2, 0x54($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X54);
    // 0x8002E4E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4E4: sw          $t2, 0x4F08($at)
    MEM_W(0X4F08, ctx->r1) = ctx->r10;
    // 0x8002E4E8: lw          $t8, 0x58($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X58);
    // 0x8002E4EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4F0: sw          $t8, 0x4F0C($at)
    MEM_W(0X4F0C, ctx->r1) = ctx->r24;
    // 0x8002E4F4: lhu         $t3, 0x5C($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X5C);
    // 0x8002E4F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E4FC: sh          $t3, -0x45A0($at)
    MEM_H(-0X45A0, ctx->r1) = ctx->r11;
    // 0x8002E500: lhu         $t4, 0x5E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X5E);
    // 0x8002E504: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E508: sh          $t4, -0x459E($at)
    MEM_H(-0X459E, ctx->r1) = ctx->r12;
    // 0x8002E50C: lhu         $t5, 0x60($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X60);
    // 0x8002E510: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E514: sh          $t5, -0x459C($at)
    MEM_H(-0X459C, ctx->r1) = ctx->r13;
    // 0x8002E518: lb          $t6, 0x62($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X62);
    // 0x8002E51C: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002E520: sb          $t6, -0x600($at)
    MEM_B(-0X600, ctx->r1) = ctx->r14;
    // 0x8002E524: lb          $t7, 0x63($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X63);
    // 0x8002E528: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002E52C: sb          $t7, -0xFF0($at)
    MEM_B(-0XFF0, ctx->r1) = ctx->r15;
L_8002E530:
    // 0x8002E530: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8002E534: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E538: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E53C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E540: bne         $a1, $zero, L_8002E530
    if (ctx->r5 != 0) {
        // 0x8002E544: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_8002E530;
    }
    // 0x8002E544: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x8002E548: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E54C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E550: addiu       $v0, $v0, 0x3B8
    ctx->r2 = ADD32(ctx->r2, 0X3B8);
    // 0x8002E554: addiu       $v1, $v1, 0x6AE8
    ctx->r3 = ADD32(ctx->r3, 0X6AE8);
    // 0x8002E558: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_8002E55C:
    // 0x8002E55C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8002E560: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E564: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E568: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E56C: bne         $a1, $zero, L_8002E55C
    if (ctx->r5 != 0) {
        // 0x8002E570: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_8002E55C;
    }
    // 0x8002E570: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x8002E574: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E578: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002E57C: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, 0X3C8);
    // 0x8002E580: addiu       $v1, $v1, -0x3088
    ctx->r3 = ADD32(ctx->r3, -0X3088);
    // 0x8002E584: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
L_8002E588:
    // 0x8002E588: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8002E58C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E590: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E594: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E598: bne         $a1, $zero, L_8002E588
    if (ctx->r5 != 0) {
        // 0x8002E59C: sb          $t1, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r9;
            goto L_8002E588;
    }
    // 0x8002E59C: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x8002E5A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002E5A4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E5A8: addiu       $v0, $v0, 0x45F
    ctx->r2 = ADD32(ctx->r2, 0X45F);
    // 0x8002E5AC: addiu       $v1, $v1, -0x2E64
    ctx->r3 = ADD32(ctx->r3, -0X2E64);
    // 0x8002E5B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002E5B4:
    // 0x8002E5B4: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8002E5B8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002E5BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E5C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E5C4: bne         $a1, $zero, L_8002E5B4
    if (ctx->r5 != 0) {
        // 0x8002E5C8: sb          $t2, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r10;
            goto L_8002E5B4;
    }
    // 0x8002E5C8: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8002E5CC: jr          $ra
    // 0x8002E5D0: nop

    return;
    // 0x8002E5D0: nop

;}
RECOMP_FUNC void func_8001DB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DB38: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8001DB3C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001DB40: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001DB44: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001DB48: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001DB4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001DB50: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8001DB54: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8001DB58: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8001DB5C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001DB60: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001DB64: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001DB68: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001DB6C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001DB70: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001DB74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001DB78: sw          $zero, -0x3A20($at)
    MEM_W(-0X3A20, ctx->r1) = 0;
    // 0x8001DB7C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001DB80: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8001DB84: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8001DB88: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8001DB8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001DB90: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001DB94: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8001DB98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001DB9C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001DBA0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001DBA4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001DBA8: jal         0x80023360
    // 0x8001DBAC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_80023360(rdram, ctx);
        goto after_0;
    // 0x8001DBAC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8001DBB0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001DBB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001DBB8: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
    // 0x8001DBBC: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x8001DBC0: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001DBC4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x8001DBC8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001DBCC: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8001DBD0: lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X0);
    // 0x8001DBD4: lw          $s4, 0x4($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X4);
    // 0x8001DBD8: lhu         $s5, 0x54($s0)
    ctx->r21 = MEM_HU(ctx->r16, 0X54);
    // 0x8001DBDC: blez        $v0, L_8001DC48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DBE0: lhu         $s6, 0x56($s0)
        ctx->r22 = MEM_HU(ctx->r16, 0X56);
            goto L_8001DC48;
    }
    // 0x8001DBE0: lhu         $s6, 0x56($s0)
    ctx->r22 = MEM_HU(ctx->r16, 0X56);
    // 0x8001DBE4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_8001DBE8:
    // 0x8001DBE8: lb          $t6, 0x14($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X14);
    // 0x8001DBEC: bnel        $t6, $zero, L_8001DC3C
    if (ctx->r14 != 0) {
        // 0x8001DBF0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001DC3C;
    }
    goto skip_0;
    // 0x8001DBF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8001DBF4: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x8001DBF8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8001DBFC: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x8001DC00: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x8001DC04: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8001DC08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001DC0C: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x8001DC10: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001DC14: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001DC18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DC1C: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    // 0x8001DC20: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8001DC24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001DC28: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x8001DC2C: jal         0x8001DC78
    // 0x8001DC30: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_8001DC78(rdram, ctx);
        goto after_1;
    // 0x8001DC30: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001DC34: lh          $v0, 0x0($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X0);
    // 0x8001DC38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001DC3C:
    // 0x8001DC3C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001DC40: bne         $at, $zero, L_8001DBE8
    if (ctx->r1 != 0) {
        // 0x8001DC44: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_8001DBE8;
    }
    // 0x8001DC44: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_8001DC48:
    // 0x8001DC48: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001DC4C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001DC50: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DC54: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001DC58: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001DC5C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001DC60: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001DC64: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001DC68: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001DC6C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001DC70: jr          $ra
    // 0x8001DC74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8001DC74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800398D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800398D0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800398D4: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x800398D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800398DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800398E0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800398E4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800398E8: jr          $ra
    // 0x800398EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    return;
    // 0x800398EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
;}
RECOMP_FUNC void dma_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    load_overlays(ctx->r4, ctx->r5, ctx->r6);
    // 0x80024260: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80024264: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80024268: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8002426C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80024270: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80024274: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80024278: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002427C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80024280: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80024284: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80024288: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8002428C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80024290: jal         0x800363E0
    // 0x80024294: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osInvalICache_recomp(rdram, ctx);
        goto after_0;
    // 0x80024294: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80024298: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002429C: jal         0x80036460
    // 0x800242A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800242A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800242A4: beq         $s1, $zero, L_8002430C
    if (ctx->r17 == 0) {
        // 0x800242A8: lui         $s5, 0x8009
        ctx->r21 = S32(0X8009 << 16);
            goto L_8002430C;
    }
    // 0x800242A8: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x800242AC: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x800242B0: addiu       $s4, $s4, -0x4CE0
    ctx->r20 = ADD32(ctx->r20, -0X4CE0);
    // 0x800242B4: addiu       $s5, $s5, -0x2F90
    ctx->r21 = ADD32(ctx->r21, -0X2F90);
L_800242B8:
    // 0x800242B8: slti        $at, $s1, 0x4001
    ctx->r1 = SIGNED(ctx->r17) < 0X4001 ? 1 : 0;
    // 0x800242BC: bne         $at, $zero, L_800242CC
    if (ctx->r1 != 0) {
        // 0x800242C0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800242CC;
    }
    // 0x800242C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800242C4: b           L_800242D0
    // 0x800242C8: addiu       $s0, $zero, 0x4000
    ctx->r16 = ADD32(0, 0X4000);
        goto L_800242D0;
    // 0x800242C8: addiu       $s0, $zero, 0x4000
    ctx->r16 = ADD32(0, 0X4000);
L_800242CC:
    // 0x800242CC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800242D0:
    // 0x800242D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800242D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800242D8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800242DC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800242E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800242E4: jal         0x80036510
    // 0x800242E8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x800242E8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_2:
    // 0x800242EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800242F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800242F4: jal         0x80034020
    // 0x800242F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800242F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800242FC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80024300: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80024304: bne         $s1, $zero, L_800242B8
    if (ctx->r17 != 0) {
        // 0x80024308: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_800242B8;
    }
    // 0x80024308: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_8002430C:
    // 0x8002430C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80024310: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80024314: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80024318: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8002431C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80024320: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80024324: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80024328: jr          $ra
    // 0x8002432C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002432C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8004001C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004001C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80040020: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80040024: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80040028: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004002C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80040030: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80040034: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80040038: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8004003C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80040040: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80040044: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80040048: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8004004C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80040050: blez        $a2, L_80040074
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80040054: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80040074;
    }
    // 0x80040054: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80040058: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_8004005C:
    // 0x8004005C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040060: jal         0x80036850
    // 0x80040064: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_0;
    // 0x80040064: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80040068: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004006C: bne         $s0, $s3, L_8004005C
    if (ctx->r16 != ctx->r19) {
        // 0x80040070: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_8004005C;
    }
    // 0x80040070: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_80040074:
    // 0x80040074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80040078: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004007C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80040080: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80040084: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80040088: jr          $ra
    // 0x8004008C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004008C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80104874_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104874: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80104878: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8010487C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80104880: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104884: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80104888: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8010488C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104890: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80104894: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80104898: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8010489C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x801048A0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x801048A4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x801048A8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x801048AC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x801048B0: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    // 0x801048B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801048B8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801048BC: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x801048C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801048C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801048C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801048CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801048D0: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x801048D4: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x801048D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801048DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801048E0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x801048E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801048E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801048EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801048F0: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x801048F4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801048F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801048FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104900: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80104904: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x80104908: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010490C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104910: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104914: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80104918: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8010491C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104920: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104924: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80104928: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x8010492C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80104930: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104934: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104938: lb          $t1, 0x2871($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X2871);
    // 0x8010493C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80104940: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80104944: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x80104948: bne         $at, $zero, L_80104958
    if (ctx->r1 != 0) {
        // 0x8010494C: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80104958;
    }
    // 0x8010494C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80104950: b           L_80104968
    // 0x80104954: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_80104968;
    // 0x80104954: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80104958:
    // 0x80104958: slti        $at, $t1, -0x14
    ctx->r1 = SIGNED(ctx->r9) < -0X14 ? 1 : 0;
    // 0x8010495C: beq         $at, $zero, L_80104968
    if (ctx->r1 == 0) {
        // 0x80104960: nop
    
            goto L_80104968;
    }
    // 0x80104960: nop

    // 0x80104964: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80104968:
    // 0x80104968: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x8010496C: ori         $t6, $a0, 0x1
    ctx->r14 = ctx->r4 | 0X1;
    // 0x80104970: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80104974: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80104978: bne         $at, $zero, L_80104984
    if (ctx->r1 != 0) {
        // 0x8010497C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80104984;
    }
    // 0x8010497C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80104980: sra         $a0, $t7, 24
    ctx->r4 = S32(SIGNED(ctx->r15) >> 24);
L_80104984:
    // 0x80104984: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80104988: beq         $at, $zero, L_80104998
    if (ctx->r1 == 0) {
        // 0x8010498C: ori         $t9, $a0, 0x2
        ctx->r25 = ctx->r4 | 0X2;
            goto L_80104998;
    }
    // 0x8010498C: ori         $t9, $a0, 0x2
    ctx->r25 = ctx->r4 | 0X2;
    // 0x80104990: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80104994: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
L_80104998:
    // 0x80104998: lb          $t8, 0x4DF0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X4DF0);
    // 0x8010499C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801049A0: sb          $a0, 0x4DF0($at)
    MEM_B(0X4DF0, ctx->r1) = ctx->r4;
    // 0x801049A4: xor         $t9, $a0, $t8
    ctx->r25 = ctx->r4 ^ ctx->r24;
    // 0x801049A8: and         $v0, $t9, $a0
    ctx->r2 = ctx->r25 & ctx->r4;
    // 0x801049AC: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x801049B0: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
    // 0x801049B4: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801049B8: beq         $t8, $zero, L_801049C4
    if (ctx->r24 == 0) {
        // 0x801049BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801049C4;
    }
    // 0x801049BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801049C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_801049C4:
    // 0x801049C4: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x801049C8: beq         $t9, $zero, L_801049D4
    if (ctx->r25 == 0) {
        // 0x801049CC: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_801049D4;
    }
    // 0x801049CC: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x801049D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801049D4:
    // 0x801049D4: beq         $t6, $zero, L_801049E0
    if (ctx->r14 == 0) {
        // 0x801049D8: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_801049E0;
    }
    // 0x801049D8: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x801049DC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_801049E0:
    // 0x801049E0: beq         $t7, $zero, L_801049EC
    if (ctx->r15 == 0) {
        // 0x801049E4: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_801049EC;
    }
    // 0x801049E4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801049E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801049EC:
    // 0x801049EC: lb          $v0, 0x622C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X622C);
    // 0x801049F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801049F4: sb          $a1, 0x4DF1($at)
    MEM_B(0X4DF1, ctx->r1) = ctx->r5;
    // 0x801049F8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x801049FC: sll         $t8, $v0, 24
    ctx->r24 = S32(ctx->r2 << 24);
    // 0x80104A00: sra         $v0, $t8, 24
    ctx->r2 = S32(SIGNED(ctx->r24) >> 24);
    // 0x80104A04: bgez        $v0, L_80104A18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80104A08: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80104A18;
    }
    // 0x80104A08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A0C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A10: b           L_80104A30
    // 0x80104A14: sb          $zero, 0x622C($at)
    MEM_B(0X622C, ctx->r1) = 0;
        goto L_80104A30;
    // 0x80104A14: sb          $zero, 0x622C($at)
    MEM_B(0X622C, ctx->r1) = 0;
L_80104A18:
    // 0x80104A18: sb          $v0, 0x622C($at)
    MEM_B(0X622C, ctx->r1) = ctx->r2;
    // 0x80104A1C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80104A20: bne         $at, $zero, L_80104A30
    if (ctx->r1 != 0) {
        // 0x80104A24: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80104A30;
    }
    // 0x80104A24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104A28: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A2C: sb          $v0, 0x622C($at)
    MEM_B(0X622C, ctx->r1) = ctx->r2;
L_80104A30:
    // 0x80104A30: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80104A34: lb          $v0, 0x6230($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6230);
    // 0x80104A38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80104A3C: sb          $a2, 0x4DF2($at)
    MEM_B(0X4DF2, ctx->r1) = ctx->r6;
    // 0x80104A40: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80104A44: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x80104A48: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80104A4C: bgez        $v0, L_80104A60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80104A50: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80104A60;
    }
    // 0x80104A50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A54: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A58: b           L_80104A78
    // 0x80104A5C: sb          $zero, 0x6230($at)
    MEM_B(0X6230, ctx->r1) = 0;
        goto L_80104A78;
    // 0x80104A5C: sb          $zero, 0x6230($at)
    MEM_B(0X6230, ctx->r1) = 0;
L_80104A60:
    // 0x80104A60: sb          $v0, 0x6230($at)
    MEM_B(0X6230, ctx->r1) = ctx->r2;
    // 0x80104A64: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80104A68: bne         $at, $zero, L_80104A78
    if (ctx->r1 != 0) {
        // 0x80104A6C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80104A78;
    }
    // 0x80104A6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80104A70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104A74: sb          $t8, 0x6230($at)
    MEM_B(0X6230, ctx->r1) = ctx->r24;
L_80104A78:
    // 0x80104A78: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80104A7C: lbu         $v0, 0x6228($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6228);
    // 0x80104A80: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80104A84: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
    // 0x80104A88: beq         $v0, $zero, L_80104AA4
    if (ctx->r2 == 0) {
        // 0x80104A8C: lui         $s6, 0xE600
        ctx->r22 = S32(0XE600 << 16);
            goto L_80104AA4;
    }
    // 0x80104A8C: lui         $s6, 0xE600
    ctx->r22 = S32(0XE600 << 16);
    // 0x80104A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80104A94: beq         $v0, $at, L_80104F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80104A98: lui         $s4, 0xE700
        ctx->r20 = S32(0XE700 << 16);
            goto L_80104F1C;
    }
    // 0x80104A98: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80104A9C: b           L_80105184
    // 0x80104AA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80105184;
    // 0x80104AA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80104AA4:
    // 0x80104AA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104AA8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80104AAC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80104AB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104AB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104AB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104ABC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104AC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104AC4: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80104AC8: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80104ACC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104AD0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104AD4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104AD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104ADC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104AE0: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80104AE4: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80104AE8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104AEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104AF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104AF4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104AF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104AFC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80104B00: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x80104B04: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104B08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104B0C: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104B10: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104B14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104B18: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80104B1C: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80104B20: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104B24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104B28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104B2C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80104B30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104B34: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80104B38: addiu       $s2, $zero, 0x50
    ctx->r18 = ADD32(0, 0X50);
    // 0x80104B3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104B40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104B44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104B48: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104B4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104B50: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80104B54: addiu       $t6, $t6, 0x11F8
    ctx->r14 = ADD32(ctx->r14, 0X11F8);
    // 0x80104B58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104B5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104B60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104B64: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104B68: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80104B6C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80104B70: lui         $ra, 0xB400
    ctx->r31 = S32(0XB400 << 16);
    // 0x80104B74: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x80104B78: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
L_80104B7C:
    // 0x80104B7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104B80: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x80104B84: ori         $t8, $t8, 0x5F
    ctx->r24 = ctx->r24 | 0X5F;
    // 0x80104B88: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104B8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104B90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104B94: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80104B98: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80104B9C: ori         $t7, $t7, 0x1800
    ctx->r15 = ctx->r15 | 0X1800;
    // 0x80104BA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104BA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104BA8: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80104BAC: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80104BB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104BB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104BB8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104BBC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104BC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104BC4: lui         $at, 0x717
    ctx->r1 = S32(0X717 << 16);
    // 0x80104BC8: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80104BCC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104BD0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104BD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104BD8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80104BDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104BE0: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80104BE4: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x80104BE8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104BEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104BF0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80104BF4: or          $t7, $t6, $s7
    ctx->r15 = ctx->r14 | ctx->r23;
    // 0x80104BF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104BFC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104C00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104C04: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80104C08: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80104C0C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104C10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104C14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104C18: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104C1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104C20: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80104C24: ori         $t8, $t8, 0x1800
    ctx->r24 = ctx->r24 | 0X1800;
    // 0x80104C28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104C2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104C30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104C34: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104C38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104C3C: lui         $at, 0x2F
    ctx->r1 = S32(0X2F << 16);
    // 0x80104C40: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x80104C44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104C48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104C4C: or          $t6, $t0, $fp
    ctx->r14 = ctx->r8 | ctx->r30;
    // 0x80104C50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104C54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80104C58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104C5C: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80104C60: lui         $at, 0xE43F
    ctx->r1 = S32(0XE43F << 16);
    // 0x80104C64: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80104C68: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80104C6C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104C70: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104C74: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80104C78: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80104C7C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80104C80: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80104C84: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80104C88: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80104C8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104C90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104C94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104C98: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x80104C9C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80104CA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104CA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104CA8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104CAC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80104CB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104CB4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80104CB8: addiu       $at, $zero, 0xB0
    ctx->r1 = ADD32(0, 0XB0);
    // 0x80104CBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104CC0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80104CC4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104CC8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80104CCC: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80104CD0: addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // 0x80104CD4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80104CD8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80104CDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104CE0: bne         $s0, $at, L_80104B7C
    if (ctx->r16 != ctx->r1) {
        // 0x80104CE4: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_80104B7C;
    }
    // 0x80104CE4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104CE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104CEC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80104CF0: addiu       $t8, $t8, 0x3430
    ctx->r24 = ADD32(ctx->r24, 0X3430);
    // 0x80104CF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104CF8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104CFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104D00: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104D04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D08: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80104D0C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80104D10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104D14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104D18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104D1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104D20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D24: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80104D28: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80104D2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104D30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104D34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104D38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104D3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D40: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80104D44: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80104D48: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104D4C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104D50: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104D54: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104D58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D5C: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80104D60: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80104D64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104D68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104D6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104D70: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80104D74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D78: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80104D7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104D80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104D84: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104D88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104D8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104D90: lui         $t7, 0xFD48
    ctx->r15 = S32(0XFD48 << 16);
    // 0x80104D94: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80104D98: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104D9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104DA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104DA4: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104DA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104DAC: addiu       $t8, $t8, 0x33D0
    ctx->r24 = ADD32(ctx->r24, 0X33D0);
    // 0x80104DB0: ori         $t7, $t7, 0x7
    ctx->r15 = ctx->r15 | 0X7;
    // 0x80104DB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104DB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104DBC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104DC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104DC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104DC8: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80104DCC: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80104DD0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104DD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104DD8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104DDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104DE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104DE4: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x80104DE8: ori         $t9, $t9, 0x4028
    ctx->r25 = ctx->r25 | 0X4028;
    // 0x80104DEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104DF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104DF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104DF8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80104DFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E00: lb          $t4, 0x6230($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6230);
    // 0x80104E04: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104E08: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104E0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104E10: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80104E14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E18: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80104E1C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80104E20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104E24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104E28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104E2C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104E30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E34: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80104E38: ori         $t6, $t6, 0x8028
    ctx->r14 = ctx->r14 | 0X8028;
    // 0x80104E3C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104E40: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104E44: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104E48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104E4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E50: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x80104E54: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x80104E58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104E5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104E60: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104E64: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80104E68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104E6C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80104E70: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x80104E74: addiu       $t8, $t1, 0x72
    ctx->r24 = ADD32(ctx->r9, 0X72);
    // 0x80104E78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80104E7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104E80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104E84: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80104E88: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80104E8C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80104E90: ori         $t9, $t8, 0x2A0
    ctx->r25 = ctx->r24 | 0X2A0;
    // 0x80104E94: addiu       $t6, $t1, 0x67
    ctx->r14 = ADD32(ctx->r9, 0X67);
    // 0x80104E98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80104E9C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80104EA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104EA4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80104EA8: ori         $t6, $t9, 0x274
    ctx->r14 = ctx->r25 | 0X274;
    // 0x80104EAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104EB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104EB4: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80104EB8: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80104EBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104EC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104EC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104EC8: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80104ECC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104ED0: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80104ED4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80104ED8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104EDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104EE0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104EE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104EE8: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x80104EEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80104EF0: andi        $t8, $t7, 0xB000
    ctx->r24 = ctx->r15 & 0XB000;
    // 0x80104EF4: beql        $t8, $zero, L_80105184
    if (ctx->r24 == 0) {
        // 0x80104EF8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80105184;
    }
    goto skip_0;
    // 0x80104EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80104EFC: bne         $t4, $at, L_80104F14
    if (ctx->r12 != ctx->r1) {
        // 0x80104F00: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80104F14;
    }
    // 0x80104F00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80104F04: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80104F08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80104F0C: b           L_80105180
    // 0x80104F10: sb          $t9, 0x6228($at)
    MEM_B(0X6228, ctx->r1) = ctx->r25;
        goto L_80105180;
    // 0x80104F10: sb          $t9, 0x6228($at)
    MEM_B(0X6228, ctx->r1) = ctx->r25;
L_80104F14:
    // 0x80104F14: b           L_80105180
    // 0x80104F18: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
        goto L_80105180;
    // 0x80104F18: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
L_80104F1C:
    // 0x80104F1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104F20: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80104F24: addiu       $t6, $t6, 0x5260
    ctx->r14 = ADD32(ctx->r14, 0X5260);
    // 0x80104F28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104F2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104F30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104F34: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104F38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104F3C: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80104F40: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
    // 0x80104F44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104F48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104F4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104F50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104F54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104F58: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80104F5C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80104F60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104F64: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104F68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104F6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104F70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104F74: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80104F78: lui         $s6, 0xE600
    ctx->r22 = S32(0XE600 << 16);
    // 0x80104F7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104F80: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104F84: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104F88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104F8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104F90: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x80104F94: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80104F98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104F9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104FA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104FA4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80104FA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104FAC: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80104FB0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80104FB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104FB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104FBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104FC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104FC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104FC8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80104FCC: addiu       $t8, $t8, 0x3E08
    ctx->r24 = ADD32(ctx->r24, 0X3E08);
    // 0x80104FD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104FD4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104FD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104FDC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104FE0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80104FE4: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x80104FE8: addiu       $s2, $zero, 0x69
    ctx->r18 = ADD32(0, 0X69);
    // 0x80104FEC: addiu       $s0, $zero, 0x5F
    ctx->r16 = ADD32(0, 0X5F);
    // 0x80104FF0: lui         $ra, 0xB400
    ctx->r31 = S32(0XB400 << 16);
    // 0x80104FF4: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x80104FF8: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
L_80104FFC:
    // 0x80104FFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105000: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x80105004: ori         $t6, $t6, 0x67
    ctx->r14 = ctx->r14 | 0X67;
    // 0x80105008: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010500C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105010: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105014: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80105018: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x8010501C: ori         $t9, $t9, 0x1A00
    ctx->r25 = ctx->r25 | 0X1A00;
    // 0x80105020: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105024: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105028: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8010502C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80105030: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105034: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105038: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8010503C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105040: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105044: lui         $at, 0x718
    ctx->r1 = S32(0X718 << 16);
    // 0x80105048: ori         $at, $at, 0xE000
    ctx->r1 = ctx->r1 | 0XE000;
    // 0x8010504C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105050: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105054: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105058: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8010505C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105060: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80105064: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x80105068: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010506C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105070: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80105074: or          $t9, $t8, $s7
    ctx->r25 = ctx->r24 | ctx->r23;
    // 0x80105078: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010507C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105080: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105084: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80105088: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8010508C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105090: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105094: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105098: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8010509C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801050A0: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x801050A4: ori         $t6, $t6, 0x1A00
    ctx->r14 = ctx->r14 | 0X1A00;
    // 0x801050A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801050AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801050B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801050B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801050B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801050BC: lui         $at, 0x31
    ctx->r1 = S32(0X31 << 16);
    // 0x801050C0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801050C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801050C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801050CC: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x801050D0: or          $t8, $t0, $fp
    ctx->r24 = ctx->r8 | ctx->r30;
    // 0x801050D4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801050D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801050DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801050E0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x801050E4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x801050E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801050EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801050F0: lui         $at, 0xE441
    ctx->r1 = S32(0XE441 << 16);
    // 0x801050F4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801050F8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x801050FC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80105100: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80105104: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80105108: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010510C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80105110: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105114: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80105118: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8010511C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105120: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105124: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105128: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8010512C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105130: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80105134: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80105138: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010513C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80105140: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105144: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80105148: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8010514C: addiu       $t5, $t5, 0xA
    ctx->r13 = ADD32(ctx->r13, 0XA);
    // 0x80105150: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x80105154: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80105158: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010515C: bne         $s0, $at, L_80104FFC
    if (ctx->r16 != ctx->r1) {
        // 0x80105160: sw          $t6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r14;
            goto L_80104FFC;
    }
    // 0x80105160: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105164: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80105168: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x8010516C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80105170: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80105174: beql        $t8, $zero, L_80105184
    if (ctx->r24 == 0) {
        // 0x80105178: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80105184;
    }
    goto skip_1;
    // 0x80105178: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8010517C: sb          $zero, 0x6228($at)
    MEM_B(0X6228, ctx->r1) = 0;
L_80105180:
    // 0x80105180: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80105184:
    // 0x80105184: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x80105188: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8010518C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80105190: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80105194: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80105198: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8010519C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x801051A0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x801051A4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x801051A8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x801051AC: jr          $ra
    // 0x801051B0: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x801051B0: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_8010541C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010541C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80105420: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80105424: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80105428: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010542C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80105430: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80105434: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105438: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8010543C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80105440: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80105444: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80105448: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8010544C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80105450: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80105454: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80105458: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010545C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105460: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80105464: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x80105468: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8010546C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105470: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105478: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8010547C: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x80105480: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105484: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105488: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8010548C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105490: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105494: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105498: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x8010549C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801054A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801054A4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801054A8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801054AC: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x801054B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801054B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801054B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801054BC: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x801054C0: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x801054C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801054C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801054CC: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x801054D0: ori         $t9, $t9, 0x4000
    ctx->r25 = ctx->r25 | 0X4000;
    // 0x801054D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801054D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801054DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801054E0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801054E4: addiu       $t8, $t8, -0x4590
    ctx->r24 = ADD32(ctx->r24, -0X4590);
    // 0x801054E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801054EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801054F0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801054F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801054F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801054FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105500: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80105504: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80105508: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010550C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105510: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105514: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105518: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010551C: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
    // 0x80105520: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80105524: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105528: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010552C: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80105530: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105534: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105538: lui         $s6, 0xE600
    ctx->r22 = S32(0XE600 << 16);
    // 0x8010553C: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80105540: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105544: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105548: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010554C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80105550: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105554: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80105558: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8010555C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105560: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105564: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105568: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010556C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105570: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x80105574: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x80105578: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010557C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105580: lui         $fp, 0xFD48
    ctx->r30 = S32(0XFD48 << 16);
    // 0x80105584: lui         $ra, 0xF548
    ctx->r31 = S32(0XF548 << 16);
    // 0x80105588: ori         $ra, $ra, 0x2200
    ctx->r31 = ctx->r31 | 0X2200;
    // 0x8010558C: ori         $fp, $fp, 0x87
    ctx->r30 = ctx->r30 | 0X87;
    // 0x80105590: addiu       $s4, $s4, 0x5468
    ctx->r20 = ADD32(ctx->r20, 0X5468);
    // 0x80105594: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80105598: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x8010559C: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
    // 0x801055A0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x801055A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801055A8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
L_801055AC:
    // 0x801055AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801055B0: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x801055B4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801055B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801055BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801055C0: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x801055C4: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801055C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801055CC: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x801055D0: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x801055D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801055D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801055DC: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x801055E0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801055E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801055E8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801055EC: lui         $at, 0x722
    ctx->r1 = S32(0X722 << 16);
    // 0x801055F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801055F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801055F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801055FC: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80105600: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105604: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80105608: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8010560C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105610: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80105614: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80105618: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010561C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105620: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105624: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80105628: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x8010562C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80105630: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80105634: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105638: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8010563C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105640: ori         $t8, $t8, 0x2200
    ctx->r24 = ctx->r24 | 0X2200;
    // 0x80105644: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80105648: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010564C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105650: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105654: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105658: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010565C: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80105660: lui         $at, 0x44
    ctx->r1 = S32(0X44 << 16);
    // 0x80105664: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80105668: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8010566C: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x80105670: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105674: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105678: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010567C: lui         $at, 0xE449
    ctx->r1 = S32(0XE449 << 16);
    // 0x80105680: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80105684: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80105688: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8010568C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80105690: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80105694: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80105698: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x8010569C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x801056A0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801056A4: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801056A8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801056AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801056B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801056B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801056B8: sll         $t9, $t5, 5
    ctx->r25 = S32(ctx->r13 << 5);
    // 0x801056BC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x801056C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801056C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801056C8: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x801056CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801056D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801056D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801056D8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801056DC: addiu       $at, $zero, 0xD8
    ctx->r1 = ADD32(0, 0XD8);
    // 0x801056E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801056E4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x801056E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801056EC: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x801056F0: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x801056F4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801056F8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x801056FC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80105700: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105704: bne         $s0, $at, L_801055AC
    if (ctx->r16 != ctx->r1) {
        // 0x80105708: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_801055AC;
    }
    // 0x80105708: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010570C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80105710: lhu         $t6, 0x2876($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2876);
    // 0x80105714: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80105718: andi        $t7, $t6, 0x9000
    ctx->r15 = ctx->r14 & 0X9000;
    // 0x8010571C: beql        $t7, $zero, L_8010572C
    if (ctx->r15 == 0) {
        // 0x80105720: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8010572C;
    }
    goto skip_0;
    // 0x80105720: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80105724: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80105728: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8010572C:
    // 0x8010572C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80105730: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80105734: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80105738: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8010573C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80105740: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80105744: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80105748: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8010574C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80105750: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80105754: jr          $ra
    // 0x80105758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80105758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80018318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018318: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001831C: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x80018320: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80018324: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80018328: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8001832C: lhu         $v0, -0x328C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X328C);
    // 0x80018330: lhu         $t7, 0x10C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X10C);
    // 0x80018334: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80018338: nor         $v0, $v0, $zero
    ctx->r2 = ~(ctx->r2 | 0);
    // 0x8001833C: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x80018340: sh          $t8, 0x10C($v1)
    MEM_H(0X10C, ctx->r3) = ctx->r24;
    // 0x80018344: lhu         $t9, -0x354C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X354C);
    // 0x80018348: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001834C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80018350: and         $t0, $t9, $v0
    ctx->r8 = ctx->r25 & ctx->r2;
    // 0x80018354: sh          $t0, -0x354C($at)
    MEM_H(-0X354C, ctx->r1) = ctx->r8;
    // 0x80018358: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001835C: lhu         $t1, -0x3424($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X3424);
    // 0x80018360: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80018364: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80018368: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001836C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018370: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80018374: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80018378: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x8001837C: sh          $t2, -0x3424($at)
    MEM_H(-0X3424, ctx->r1) = ctx->r10;
    // 0x80018380: addiu       $t4, $t4, -0x3668
    ctx->r12 = ADD32(ctx->r12, -0X3668);
    // 0x80018384: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80018388: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8001838C: lhu         $t7, 0x244($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X244);
    // 0x80018390: lhu         $t9, 0x36C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X36C);
    // 0x80018394: lhu         $t1, 0x494($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X494);
    // 0x80018398: lhu         $t5, 0x11C($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X11C);
    // 0x8001839C: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x800183A0: and         $t0, $t9, $v0
    ctx->r8 = ctx->r25 & ctx->r2;
    // 0x800183A4: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x800183A8: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x800183AC: sh          $t2, 0x494($a0)
    MEM_H(0X494, ctx->r4) = ctx->r10;
    // 0x800183B0: sh          $t0, 0x36C($a0)
    MEM_H(0X36C, ctx->r4) = ctx->r8;
    // 0x800183B4: sh          $t8, 0x244($a0)
    MEM_H(0X244, ctx->r4) = ctx->r24;
    // 0x800183B8: sh          $t6, 0x11C($a0)
    MEM_H(0X11C, ctx->r4) = ctx->r14;
    // 0x800183BC: jr          $ra
    // 0x800183C0: nop

    return;
    // 0x800183C0: nop

;}
RECOMP_FUNC void func_8000B9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B9D8: andi        $t6, $a0, 0x7
    ctx->r14 = ctx->r4 & 0X7;
    // 0x8000B9DC: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8000B9E0: srl         $t8, $a0, 3
    ctx->r24 = S32(U32(ctx->r4) >> 3);
    // 0x8000B9E4: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000B9E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000B9EC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B9F0: lbu         $t7, -0x28C0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X28C0);
    // 0x8000B9F4: lbu         $t9, -0x2E64($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2E64);
    // 0x8000B9F8: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    // 0x8000B9FC: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000BA00: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8000BA04: jr          $ra
    // 0x8000BA08: nop

    return;
    // 0x8000BA08: nop

;}
RECOMP_FUNC void func_8010421C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010421C: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80104220: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80104224: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80104228: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010422C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80104230: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80104234: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104238: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8010423C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80104240: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80104244: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80104248: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8010424C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80104250: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80104254: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80104258: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010425C: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80104260: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104264: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104268: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010426C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80104270: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x80104274: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104278: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010427C: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80104280: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104284: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104288: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010428C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80104290: addiu       $t8, $t8, 0x4E18
    ctx->r24 = ADD32(ctx->r24, 0X4E18);
    // 0x80104294: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104298: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010429C: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801042A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801042A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801042A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801042AC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x801042B0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801042B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801042B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801042BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801042C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801042C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801042C8: lui         $s5, 0x700
    ctx->r21 = S32(0X700 << 16);
    // 0x801042CC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x801042D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801042D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801042D8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x801042DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801042E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801042E4: lui         $s6, 0xE600
    ctx->r22 = S32(0XE600 << 16);
    // 0x801042E8: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x801042EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801042F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801042F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801042F8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x801042FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104300: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80104304: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80104308: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010430C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104310: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104314: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104318: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010431C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80104320: addiu       $t6, $t6, 0x3638
    ctx->r14 = ADD32(ctx->r14, 0X3638);
    // 0x80104324: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104328: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8010432C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104330: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104334: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80104338: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x8010433C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80104340: addiu       $s3, $zero, 0x2E
    ctx->r19 = ADD32(0, 0X2E);
    // 0x80104344: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
    // 0x80104348: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8010434C: lui         $ra, 0xB400
    ctx->r31 = S32(0XB400 << 16);
    // 0x80104350: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
L_80104354:
    // 0x80104354: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104358: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x8010435C: ori         $t8, $t8, 0x37
    ctx->r24 = ctx->r24 | 0X37;
    // 0x80104360: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104364: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104368: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010436C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80104370: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80104374: ori         $t7, $t7, 0xE00
    ctx->r15 = ctx->r15 | 0XE00;
    // 0x80104378: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010437C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104380: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x80104384: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80104388: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010438C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104390: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80104394: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104398: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010439C: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x801043A0: lui         $at, 0x70E
    ctx->r1 = S32(0X70E << 16);
    // 0x801043A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801043A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801043AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801043B0: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x801043B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801043B8: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x801043BC: or          $t7, $t6, $s7
    ctx->r15 = ctx->r14 | ctx->r23;
    // 0x801043C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801043C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801043C8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801043CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801043D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801043D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801043D8: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x801043DC: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x801043E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801043E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801043E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801043EC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x801043F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801043F4: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x801043F8: ori         $t8, $t8, 0xE00
    ctx->r24 = ctx->r24 | 0XE00;
    // 0x801043FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104400: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104404: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104408: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010440C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104410: lui         $at, 0x1C
    ctx->r1 = S32(0X1C << 16);
    // 0x80104414: or          $t7, $t0, $at
    ctx->r15 = ctx->r8 | ctx->r1;
    // 0x80104418: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010441C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104420: or          $t6, $t5, $fp
    ctx->r14 = ctx->r13 | ctx->r30;
    // 0x80104424: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104428: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010442C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104430: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80104434: lui         $at, 0xE436
    ctx->r1 = S32(0XE436 << 16);
    // 0x80104438: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8010443C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80104440: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104444: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104448: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8010444C: lui         $at, 0x1A
    ctx->r1 = S32(0X1A << 16);
    // 0x80104450: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80104454: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80104458: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8010445C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80104460: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104464: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104468: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010446C: sll         $t8, $s2, 5
    ctx->r24 = S32(ctx->r18 << 5);
    // 0x80104470: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80104474: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104478: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010447C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104480: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80104484: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104488: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x8010448C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80104490: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104494: slti        $at, $t4, 0xAC
    ctx->r1 = SIGNED(ctx->r12) < 0XAC ? 1 : 0;
    // 0x80104498: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010449C: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x801044A0: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x801044A4: addiu       $s2, $s2, 0x12
    ctx->r18 = ADD32(ctx->r18, 0X12);
    // 0x801044A8: addiu       $s3, $s3, 0x12
    ctx->r19 = ADD32(ctx->r19, 0X12);
    // 0x801044AC: addiu       $s0, $s0, 0x12
    ctx->r16 = ADD32(ctx->r16, 0X12);
    // 0x801044B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801044B4: bne         $at, $zero, L_80104354
    if (ctx->r1 != 0) {
        // 0x801044B8: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_80104354;
    }
    // 0x801044B8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801044BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801044C0: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x801044C4: ori         $t6, $t6, 0x37
    ctx->r14 = ctx->r14 | 0X37;
    // 0x801044C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801044CC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801044D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801044D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801044D8: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x801044DC: ori         $t9, $t9, 0xE00
    ctx->r25 = ctx->r25 | 0XE00;
    // 0x801044E0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801044E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801044E8: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x801044EC: addiu       $t0, $s2, 0x1
    ctx->r8 = ADD32(ctx->r18, 0X1);
    // 0x801044F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801044F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801044F8: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x801044FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104500: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104504: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x80104508: or          $t5, $t8, $zero
    ctx->r13 = ctx->r24 | 0;
    // 0x8010450C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104510: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104518: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8010451C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104520: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80104524: andi        $t0, $t6, 0xFFF
    ctx->r8 = ctx->r14 & 0XFFF;
    // 0x80104528: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010452C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104530: or          $t9, $t8, $s7
    ctx->r25 = ctx->r24 | ctx->r23;
    // 0x80104534: lui         $at, 0x70E
    ctx->r1 = S32(0X70E << 16);
    // 0x80104538: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x8010453C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104540: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104544: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104548: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x8010454C: ori         $t7, $t7, 0xE00
    ctx->r15 = ctx->r15 | 0XE00;
    // 0x80104550: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104554: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104558: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010455C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104560: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104564: lui         $at, 0x1C
    ctx->r1 = S32(0X1C << 16);
    // 0x80104568: or          $t9, $t5, $fp
    ctx->r25 = ctx->r13 | ctx->r30;
    // 0x8010456C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104570: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104574: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104578: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010457C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104580: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80104584: lui         $at, 0xE436
    ctx->r1 = S32(0XE436 << 16);
    // 0x80104588: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010458C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104590: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104594: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80104598: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010459C: addiu       $t8, $s3, 0x1
    ctx->r24 = ADD32(ctx->r19, 0X1);
    // 0x801045A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801045A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801045A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801045AC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801045B0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801045B4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801045B8: lui         $at, 0x1A
    ctx->r1 = S32(0X1A << 16);
    // 0x801045BC: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x801045C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801045C4: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801045C8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801045CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801045D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801045D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801045D8: sll         $t8, $s2, 5
    ctx->r24 = S32(ctx->r18 << 5);
    // 0x801045DC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x801045E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801045E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801045E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801045EC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801045F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801045F4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x801045F8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x801045FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104600: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104604: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80104608: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010460C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104610: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104614: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80104618: addiu       $t8, $t8, 0x5FE8
    ctx->r24 = ADD32(ctx->r24, 0X5FE8);
    // 0x8010461C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104620: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104624: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104628: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8010462C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104630: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80104634: addiu       $s2, $zero, 0xA2
    ctx->r18 = ADD32(0, 0XA2);
    // 0x80104638: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010463C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104640: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104644: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104648: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010464C: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x80104650: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80104654: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104658: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8010465C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104660: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104664: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104668: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8010466C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80104670: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104674: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104678: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8010467C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104680: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104684: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80104688: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8010468C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80104690: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104694: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104698: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8010469C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801046A0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x801046A4: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x801046A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801046AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801046B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801046B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801046B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801046BC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801046C0: addiu       $t6, $t6, 0x5020
    ctx->r14 = ADD32(ctx->r14, 0X5020);
    // 0x801046C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801046C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801046CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801046D0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x801046D4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801046D8: addiu       $s0, $zero, 0xB7
    ctx->r16 = ADD32(0, 0XB7);
L_801046DC:
    // 0x801046DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801046E0: lui         $t8, 0xFD48
    ctx->r24 = S32(0XFD48 << 16);
    // 0x801046E4: ori         $t8, $t8, 0x5F
    ctx->r24 = ctx->r24 | 0X5F;
    // 0x801046E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801046EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801046F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801046F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801046F8: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x801046FC: ori         $t7, $t7, 0x1800
    ctx->r15 = ctx->r15 | 0X1800;
    // 0x80104700: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104704: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104708: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8010470C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80104710: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104714: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104718: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8010471C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104720: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104724: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x80104728: lui         $at, 0x718
    ctx->r1 = S32(0X718 << 16);
    // 0x8010472C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80104730: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80104734: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104738: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8010473C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104740: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80104744: or          $t7, $t6, $s7
    ctx->r15 = ctx->r14 | ctx->r23;
    // 0x80104748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010474C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80104750: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80104754: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104758: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010475C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104760: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80104764: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80104768: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010476C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104770: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104774: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80104778: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010477C: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80104780: ori         $t8, $t8, 0x1800
    ctx->r24 = ctx->r24 | 0X1800;
    // 0x80104784: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104788: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010478C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80104790: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104794: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104798: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x8010479C: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x801047A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801047A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801047A8: or          $t6, $t0, $fp
    ctx->r14 = ctx->r8 | ctx->r30;
    // 0x801047AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801047B0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801047B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801047B8: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x801047BC: lui         $at, 0xE441
    ctx->r1 = S32(0XE441 << 16);
    // 0x801047C0: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801047C4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801047C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801047CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801047D0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801047D4: lui         $at, 0x11
    ctx->r1 = S32(0X11 << 16);
    // 0x801047D8: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x801047DC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801047E0: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801047E4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801047E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801047EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801047F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801047F4: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x801047F8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x801047FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80104800: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104804: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80104808: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8010480C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104810: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80104814: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80104818: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010481C: addiu       $s0, $s0, 0x15
    ctx->r16 = ADD32(ctx->r16, 0X15);
    // 0x80104820: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104824: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80104828: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8010482C: addiu       $t5, $t5, 0x15
    ctx->r13 = ADD32(ctx->r13, 0X15);
    // 0x80104830: addiu       $s2, $s2, 0x15
    ctx->r18 = ADD32(ctx->r18, 0X15);
    // 0x80104834: addiu       $s1, $s1, 0x15
    ctx->r17 = ADD32(ctx->r17, 0X15);
    // 0x80104838: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010483C: bne         $s0, $at, L_801046DC
    if (ctx->r16 != ctx->r1) {
        // 0x80104840: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_801046DC;
    }
    // 0x80104840: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104844: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80104848: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8010484C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80104850: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80104854: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80104858: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8010485C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80104860: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80104864: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80104868: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8010486C: jr          $ra
    // 0x80104870: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80104870: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80042CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042CEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80042CF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80042CF4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80042CF8: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80042CFC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80042D00: beq         $v1, $zero, L_80042D54
    if (ctx->r3 == 0) {
        // 0x80042D04: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_80042D54;
    }
    // 0x80042D04: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80042D08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80042D0C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80042D10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80042D14: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
L_80042D18:
    // 0x80042D18: bnel        $v0, $t8, L_80042D4C
    if (ctx->r2 != ctx->r24) {
        // 0x80042D1C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80042D4C;
    }
    goto skip_0;
    // 0x80042D1C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80042D20: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x80042D24: bnel        $a2, $t9, L_80042D4C
    if (ctx->r6 != ctx->r25) {
        // 0x80042D28: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80042D4C;
    }
    goto skip_1;
    // 0x80042D28: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80042D2C: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x80042D30: beql        $a1, $a0, L_80042D4C
    if (ctx->r5 == ctx->r4) {
        // 0x80042D34: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80042D4C;
    }
    goto skip_2;
    // 0x80042D34: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x80042D38: beql        $a3, $a0, L_80042D4C
    if (ctx->r7 == ctx->r4) {
        // 0x80042D3C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_80042D4C;
    }
    goto skip_3;
    // 0x80042D3C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x80042D40: jr          $ra
    // 0x80042D44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80042D44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80042D48: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_80042D4C:
    // 0x80042D4C: bnel        $v1, $zero, L_80042D18
    if (ctx->r3 != 0) {
        // 0x80042D50: lbu         $t8, 0x32($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X32);
            goto L_80042D18;
    }
    goto skip_4;
    // 0x80042D50: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    skip_4:
L_80042D54:
    // 0x80042D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042D58: jr          $ra
    // 0x80042D5C: nop

    return;
    // 0x80042D5C: nop

;}
RECOMP_FUNC void func_800111D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800111DC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800111E0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800111E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800111E8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800111EC: sw          $a1, 0x5A14($at)
    MEM_W(0X5A14, ctx->r1) = ctx->r5;
    // 0x800111F0: jr          $ra
    // 0x800111F4: nop

    return;
    // 0x800111F4: nop

;}
RECOMP_FUNC void func_800151D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800151D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800151D8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800151DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800151E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800151E4: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x800151E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800151EC: nop

    // 0x800151F0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800151F4: lw          $t6, 0x64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X64);
    // 0x800151F8: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800151FC: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x80015200: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80015204: lwc1        $f18, 0x1C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80015208: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001520C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80015210: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80015214: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80015218: lwc1        $f12, 0x10($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001521C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015220: jal         0x800232F4
    // 0x80015224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80015224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80015228: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001522C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015230: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015234: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80015238: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001523C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015244: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80015248: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8001524C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80015250: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015254: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80015258: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8001525C: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80015260: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80015264: bnel        $t8, $at, L_8001529C
    if (ctx->r24 != ctx->r1) {
        // 0x80015268: lwc1        $f8, 0x1C($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_8001529C;
    }
    goto skip_0;
    // 0x80015268: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x8001526C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80015270: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015274: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80015278: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
    // 0x8001527C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80015280: lwc1        $f16, 0x94($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X94);
    // 0x80015284: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80015288: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8001528C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80015290: b           L_800152D4
    // 0x80015294: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
        goto L_800152D4;
    // 0x80015294: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80015298: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
L_8001529C:
    // 0x8001529C: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800152A0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800152A4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800152A8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800152AC: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800152B0: lw          $t1, 0x2C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X2C);
    // 0x800152B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800152B8: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800152BC: lwc1        $f16, 0x1C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800152C0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800152C4: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800152C8: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x800152CC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800152D0: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_800152D4:
    // 0x800152D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800152D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800152DC: jr          $ra
    // 0x800152E0: nop

    return;
    // 0x800152E0: nop

;}
RECOMP_FUNC void func_8002571C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002571C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80025720: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80025724: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80025728: addiu       $s2, $s2, -0x6CC
    ctx->r18 = ADD32(ctx->r18, -0X6CC);
    // 0x8002572C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80025730: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80025734: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80025738: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002573C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80025740: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80025744: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80025748: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002574C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025750: slti        $at, $zero, 0x5
    ctx->r1 = SIGNED(0) < 0X5 ? 1 : 0;
    // 0x80025754: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80025758: beq         $at, $zero, L_80025874
    if (ctx->r1 == 0) {
        // 0x8002575C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80025874;
    }
    // 0x8002575C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025760: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x80025764: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x80025768: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x8002576C: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80025770: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80025774: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x80025778: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8002577C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80025780: addiu       $s0, $s0, -0x6D4
    ctx->r16 = ADD32(ctx->r16, -0X6D4);
    // 0x80025784: addiu       $s1, $s1, -0x6D0
    ctx->r17 = ADD32(ctx->r17, -0X6D0);
    // 0x80025788: addiu       $s3, $s3, 0x39A8
    ctx->r19 = ADD32(ctx->r19, 0X39A8);
    // 0x8002578C: addiu       $s4, $s4, -0x6B4
    ctx->r20 = ADD32(ctx->r20, -0X6B4);
    // 0x80025790: addiu       $s5, $s5, -0x6A0
    ctx->r21 = ADD32(ctx->r21, -0X6A0);
    // 0x80025794: addiu       $s6, $s6, -0x6A4
    ctx->r22 = ADD32(ctx->r22, -0X6A4);
    // 0x80025798: addiu       $s7, $s7, -0x690
    ctx->r23 = ADD32(ctx->r23, -0X690);
    // 0x8002579C: addiu       $fp, $fp, -0x6A8
    ctx->r30 = ADD32(ctx->r30, -0X6A8);
L_800257A0:
    // 0x800257A0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800257A4: addu        $v1, $s3, $t6
    ctx->r3 = ADD32(ctx->r19, ctx->r14);
    // 0x800257A8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800257AC: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800257B0: beql        $a0, $zero, L_80025864
    if (ctx->r4 == 0) {
        // 0x800257B4: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80025864;
    }
    goto skip_0;
    // 0x800257B4: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800257B8: beq         $at, $zero, L_80025848
    if (ctx->r1 == 0) {
        // 0x800257BC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80025848;
    }
    // 0x800257BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800257C0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800257C4: addu        $at, $at, $t7
    gpr jr_addend_800257CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800257C8: lw          $t7, 0x1700($at)
    ctx->r15 = ADD32(ctx->r1, 0X1700);
    // 0x800257CC: jr          $t7
    // 0x800257D0: nop

    switch (jr_addend_800257CC >> 2) {
        case 0: goto L_800257D4; break;
        case 1: goto L_800257E8; break;
        case 2: goto L_80025804; break;
        case 3: goto L_80025820; break;
        case 4: goto L_80025838; break;
        default: switch_error(__func__, 0x800257CC, 0x80071700);
    }
    // 0x800257D0: nop

L_800257D4:
    // 0x800257D4: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800257D8: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800257DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800257E0: b           L_80025848
    // 0x800257E4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_80025848;
    // 0x800257E4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800257E8:
    // 0x800257E8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800257EC: lw          $t0, -0x6B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6B0);
    // 0x800257F0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800257F4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800257F8: lw          $t1, -0x69C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X69C);
    // 0x800257FC: b           L_80025848
    // 0x80025800: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_80025848;
    // 0x80025800: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80025804:
    // 0x80025804: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025808: lw          $t2, -0x6AC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6AC);
    // 0x8002580C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80025810: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80025814: lw          $t3, -0x698($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X698);
    // 0x80025818: b           L_80025848
    // 0x8002581C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_80025848;
    // 0x8002581C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_80025820:
    // 0x80025820: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80025824: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80025828: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8002582C: lw          $t5, -0x694($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X694);
    // 0x80025830: b           L_80025848
    // 0x80025834: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_80025848;
    // 0x80025834: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_80025838:
    // 0x80025838: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8002583C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80025840: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80025844: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_80025848:
    // 0x80025848: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x8002584C: bne         $t8, $zero, L_80025860
    if (ctx->r24 != 0) {
        // 0x80025850: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80025860;
    }
    // 0x80025850: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80025854: jal         0x80025E0C
    // 0x80025858: nop

    func_80025E0C(rdram, ctx);
        goto after_0;
    // 0x80025858: nop

    after_0:
    // 0x8002585C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80025860:
    // 0x80025860: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
L_80025864:
    // 0x80025864: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80025868: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x8002586C: bne         $at, $zero, L_800257A0
    if (ctx->r1 != 0) {
        // 0x80025870: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800257A0;
    }
    // 0x80025870: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80025874:
    // 0x80025874: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80025878: lw          $a0, 0x397C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X397C);
    // 0x8002587C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80025880: beq         $a0, $at, L_80025890
    if (ctx->r4 == ctx->r1) {
        // 0x80025884: nop
    
            goto L_80025890;
    }
    // 0x80025884: nop

    // 0x80025888: jal         0x80025984
    // 0x8002588C: nop

    func_80025984(rdram, ctx);
        goto after_1;
    // 0x8002588C: nop

    after_1:
L_80025890:
    // 0x80025890: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80025894: lw          $t1, 0x398C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X398C);
    // 0x80025898: beq         $t1, $zero, L_800258A8
    if (ctx->r9 == 0) {
        // 0x8002589C: nop
    
            goto L_800258A8;
    }
    // 0x8002589C: nop

    // 0x800258A0: jal         0x80026214
    // 0x800258A4: nop

    func_80026214(rdram, ctx);
        goto after_2;
    // 0x800258A4: nop

    after_2:
L_800258A8:
    // 0x800258A8: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800258AC: lw          $t2, 0x3990($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3990);
    // 0x800258B0: beq         $t2, $zero, L_800258C0
    if (ctx->r10 == 0) {
        // 0x800258B4: nop
    
            goto L_800258C0;
    }
    // 0x800258B4: nop

    // 0x800258B8: jal         0x800262F4
    // 0x800258BC: nop

    func_800262F4(rdram, ctx);
        goto after_3;
    // 0x800258BC: nop

    after_3:
L_800258C0:
    // 0x800258C0: jal         0x80025BD8
    // 0x800258C4: nop

    func_80025BD8(rdram, ctx);
        goto after_4;
    // 0x800258C4: nop

    after_4:
    // 0x800258C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800258CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800258D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800258D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800258D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800258DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800258E0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800258E4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800258E8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800258EC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800258F0: jr          $ra
    // 0x800258F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800258F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8000B740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B740: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B748: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000B74C: lw          $t6, -0x2E60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E60);
    // 0x8000B750: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B754: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000B758: beq         $t6, $zero, L_8000B7C8
    if (ctx->r14 == 0) {
        // 0x8000B75C: addiu       $v0, $v0, -0x2E58
        ctx->r2 = ADD32(ctx->r2, -0X2E58);
            goto L_8000B7C8;
    }
    // 0x8000B75C: addiu       $v0, $v0, -0x2E58
    ctx->r2 = ADD32(ctx->r2, -0X2E58);
    // 0x8000B760: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000B764: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x8000B768: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000B76C: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8000B770: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000B774: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8000B778: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000B77C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000B780: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000B784: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000B788: nop

    // 0x8000B78C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000B790: jal         0x80034F60
    // 0x8000B794: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000B794: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x8000B798: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B79C: lw          $v0, -0x2E60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2E60);
    // 0x8000B7A0: lui         $at, 0x803B
    ctx->r1 = S32(0X803B << 16);
    // 0x8000B7A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B7A8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000B7AC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000B7B0: lwc1        $f4, -0x6474($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6474);
    // 0x8000B7B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8000B7B8: nop

    // 0x8000B7BC: bc1fl       L_8000B7CC
    if (!c1cs) {
        // 0x8000B7C0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000B7CC;
    }
    goto skip_0;
    // 0x8000B7C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8000B7C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8000B7C8:
    // 0x8000B7C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B7CC:
    // 0x8000B7CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B7D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B7D4: jr          $ra
    // 0x8000B7D8: nop

    return;
    // 0x8000B7D8: nop

;}
RECOMP_FUNC void func_80022B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022B08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80022B0C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80022B10: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80022B14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80022B18: sw          $a0, -0x2FDC($at)
    MEM_W(-0X2FDC, ctx->r1) = ctx->r4;
    // 0x80022B1C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80022B20: ori         $t7, $a1, 0x1
    ctx->r15 = ctx->r5 | 0X1;
    // 0x80022B24: sh          $t7, -0x2FE0($at)
    MEM_H(-0X2FE0, ctx->r1) = ctx->r15;
    // 0x80022B28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80022B2C: sw          $a2, -0x2FD8($at)
    MEM_W(-0X2FD8, ctx->r1) = ctx->r6;
    // 0x80022B30: jr          $ra
    // 0x80022B34: nop

    return;
    // 0x80022B34: nop

    // 0x80022B38: nop

    // 0x80022B3C: nop

;}
RECOMP_FUNC void func_80042724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042724: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80042728: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x8004272C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x80042730: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80042734: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x80042738: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8004273C: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x80042740: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80042744: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80042748: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x8004274C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x80042750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042754: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80042758: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8004275C: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x80042760: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80042764: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80042768: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8004276C: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x80042770: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80042774: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80042778: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x8004277C: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80042780: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80042784: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x80042788: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8004278C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x80042790: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x80042794: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x80042798: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8004279C: jr          $ra
    // 0x800427A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    return;
    // 0x800427A0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80103954_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103954: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80103958: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8010395C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80103960: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103964: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80103968: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010396C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103970: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80103974: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80103978: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8010397C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80103980: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80103984: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80103988: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8010398C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80103990: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103994: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x80103998: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8010399C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801039A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801039A4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x801039A8: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x801039AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801039B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801039B4: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x801039B8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801039BC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801039C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801039C4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801039C8: addiu       $t8, $t8, 0x21F8
    ctx->r24 = ADD32(ctx->r24, 0X21F8);
    // 0x801039CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801039D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801039D4: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801039D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801039DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801039E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801039E4: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x801039E8: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801039EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801039F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801039F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801039F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801039FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103A00: lui         $s1, 0x700
    ctx->r17 = S32(0X700 << 16);
    // 0x80103A04: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80103A08: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103A0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103A10: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80103A14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103A1C: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x80103A20: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80103A24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103A28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103A2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103A30: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103A34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103A38: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80103A3C: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80103A40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103A44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103A48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103A4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103A50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103A54: lui         $s2, 0x8016
    ctx->r18 = S32(0X8016 << 16);
    // 0x80103A58: lui         $s5, 0xFD48
    ctx->r21 = S32(0XFD48 << 16);
    // 0x80103A5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103A60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80103A68: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80103A6C: ori         $s5, $s5, 0x57
    ctx->r21 = ctx->r21 | 0X57;
    // 0x80103A70: addiu       $s2, $s2, 0x250
    ctx->r18 = ADD32(ctx->r18, 0X250);
    // 0x80103A74: lui         $s6, 0xF548
    ctx->r22 = S32(0XF548 << 16);
    // 0x80103A78: lui         $s7, 0xF400
    ctx->r23 = S32(0XF400 << 16);
    // 0x80103A7C: lui         $fp, 0xF540
    ctx->r30 = S32(0XF540 << 16);
    // 0x80103A80: lui         $ra, 0xF200
    ctx->r31 = S32(0XF200 << 16);
    // 0x80103A84: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103A88: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_80103A8C:
    // 0x80103A8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103A90: subu        $a3, $a0, $a0
    ctx->r7 = SUB32(ctx->r4, ctx->r4);
    // 0x80103A94: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80103A98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103A9C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103AA0: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80103AA4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80103AA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103AAC: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80103AB0: addiu       $a3, $t8, 0x7
    ctx->r7 = ADD32(ctx->r24, 0X7);
    // 0x80103AB4: sra         $t9, $a3, 3
    ctx->r25 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80103AB8: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80103ABC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103AC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103AC4: sll         $a3, $t6, 9
    ctx->r7 = S32(ctx->r14 << 9);
    // 0x80103AC8: or          $t8, $a3, $s6
    ctx->r24 = ctx->r7 | ctx->r22;
    // 0x80103ACC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103AD0: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80103AD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103AD8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80103ADC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103AE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103AE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103AE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103AEC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103AF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103AF4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103AF8: addiu       $t5, $a0, 0x13
    ctx->r13 = ADD32(ctx->r4, 0X13);
    // 0x80103AFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103B00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103B04: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x80103B08: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80103B0C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103B10: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103B14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103B18: or          $t6, $t9, $s1
    ctx->r14 = ctx->r25 | ctx->r17;
    // 0x80103B1C: ori         $t7, $t6, 0x16C
    ctx->r15 = ctx->r14 | 0X16C;
    // 0x80103B20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103B24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103B28: or          $t6, $a3, $fp
    ctx->r14 = ctx->r7 | ctx->r30;
    // 0x80103B2C: addiu       $t0, $a0, 0x4B
    ctx->r8 = ADD32(ctx->r4, 0X4B);
    // 0x80103B30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103B34: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103B38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103B3C: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80103B40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103B44: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80103B48: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80103B4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103B50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103B54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103B58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103B5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103B60: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103B64: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103B68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103B6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103B70: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x80103B74: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80103B78: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103B7C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103B80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103B84: ori         $t7, $t6, 0x16C
    ctx->r15 = ctx->r14 | 0X16C;
    // 0x80103B88: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103B8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103B90: addiu       $t9, $t0, 0x14
    ctx->r25 = ADD32(ctx->r8, 0X14);
    // 0x80103B94: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80103B98: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103B9C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103BA0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80103BA4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80103BA8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80103BAC: ori         $t6, $t9, 0x294
    ctx->r14 = ctx->r25 | 0X294;
    // 0x80103BB0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80103BB4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103BB8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103BBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103BC0: ori         $t6, $t9, 0x124
    ctx->r14 = ctx->r25 | 0X124;
    // 0x80103BC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80103BC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103BCC: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80103BD0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80103BD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103BD8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103BDC: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x80103BE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103BE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103BE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103BEC: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80103BF0: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80103BF4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103BF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103BFC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80103C00: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80103C04: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80103C08: bne         $t4, $zero, L_80103A8C
    if (ctx->r12 != 0) {
        // 0x80103C0C: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80103A8C;
    }
    // 0x80103C0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103C10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103C14: subu        $a3, $a0, $a0
    ctx->r7 = SUB32(ctx->r4, ctx->r4);
    // 0x80103C18: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80103C1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103C20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103C24: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80103C28: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80103C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103C30: sra         $t9, $a3, 1
    ctx->r25 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80103C34: addiu       $a3, $t9, 0x7
    ctx->r7 = ADD32(ctx->r25, 0X7);
    // 0x80103C38: sra         $t6, $a3, 3
    ctx->r14 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80103C3C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80103C40: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103C44: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103C48: sll         $a3, $t7, 9
    ctx->r7 = S32(ctx->r15 << 9);
    // 0x80103C4C: or          $t9, $a3, $s6
    ctx->r25 = ctx->r7 | ctx->r22;
    // 0x80103C50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103C54: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80103C58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103C5C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80103C60: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103C64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103C68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103C6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103C70: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103C74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103C78: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103C7C: addiu       $t4, $a0, 0x7
    ctx->r12 = ADD32(ctx->r4, 0X7);
    // 0x80103C80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103C84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103C88: or          $t7, $t6, $s7
    ctx->r15 = ctx->r14 | ctx->r23;
    // 0x80103C8C: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x80103C90: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103C94: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103C98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103C9C: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x80103CA0: ori         $t8, $t7, 0x16C
    ctx->r24 = ctx->r15 | 0X16C;
    // 0x80103CA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103CA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103CAC: or          $t7, $a3, $fp
    ctx->r15 = ctx->r7 | ctx->r30;
    // 0x80103CB0: addiu       $t0, $a0, 0x4B
    ctx->r8 = ADD32(ctx->r4, 0X4B);
    // 0x80103CB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103CB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103CBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103CC0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80103CC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103CC8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80103CCC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80103CD0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103CD4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103CD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103CDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103CE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103CE4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80103CE8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80103CEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103CF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103CF4: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x80103CF8: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80103CFC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80103D00: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80103D04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103D08: ori         $t8, $t7, 0x16C
    ctx->r24 = ctx->r15 | 0X16C;
    // 0x80103D0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103D10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103D14: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80103D18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80103D1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103D20: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103D24: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103D28: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103D2C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80103D30: ori         $t7, $t6, 0x294
    ctx->r15 = ctx->r14 | 0X294;
    // 0x80103D34: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80103D38: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80103D3C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80103D40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103D44: ori         $t7, $t6, 0x124
    ctx->r15 = ctx->r14 | 0X124;
    // 0x80103D48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103D4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103D50: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80103D54: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80103D58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103D5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103D60: sll         $t8, $a0, 21
    ctx->r24 = S32(ctx->r4 << 21);
    // 0x80103D64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103D68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103D6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103D70: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80103D74: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80103D78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103D7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103D80: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103D84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103D88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80103D8C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80103D90: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80103D94: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80103D98: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80103D9C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80103DA0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80103DA4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80103DA8: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80103DAC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80103DB0: jr          $ra
    // 0x80103DB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80103DB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80010CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010CAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010CB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80010CB4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80010CB8: lhu         $t6, 0x4F12($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4F12);
    // 0x80010CBC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80010CC0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80010CC4: beq         $t7, $zero, L_80010DA4
    if (ctx->r15 == 0) {
        // 0x80010CC8: nop
    
            goto L_80010DA4;
    }
    // 0x80010CC8: nop

    // 0x80010CCC: lw          $t8, 0x59D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X59D8);
    // 0x80010CD0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80010CD4: ldc1        $f2, 0x12B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X12B0);
    // 0x80010CD8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80010CDC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80010CE0: lw          $t9, 0x59DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X59DC);
    // 0x80010CE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80010CE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80010CEC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80010CF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80010CF4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80010CF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80010CFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80010D00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80010D04: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80010D08: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010D0C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80010D10: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80010D14: addiu       $a0, $a0, 0x55A0
    ctx->r4 = ADD32(ctx->r4, 0X55A0);
    // 0x80010D18: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80010D1C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80010D20: div.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f18.d, ctx->f8.d);
    // 0x80010D24: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x80010D28: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80010D2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80010D30: jal         0x80023570
    // 0x80010D34: nop

    func_80023570(rdram, ctx);
        goto after_0;
    // 0x80010D34: nop

    after_0:
    // 0x80010D38: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010D3C: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x80010D40: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x80010D44: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80010D48: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80010D4C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80010D50: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80010D54: addiu       $a0, $a0, 0x55A0
    ctx->r4 = ADD32(ctx->r4, 0X55A0);
    // 0x80010D58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80010D5C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80010D60: jal         0x80035470
    // 0x80010D64: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    func_80035470(rdram, ctx);
        goto after_1;
    // 0x80010D64: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_1:
    // 0x80010D68: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80010D6C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80010D70: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80010D74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80010D78: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010D7C: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, 0X5B98);
    // 0x80010D80: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80010D84: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80010D88: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80010D8C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80010D90: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80010D94: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80010D98: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80010D9C: b           L_80010DFC
    // 0x80010DA0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
        goto L_80010DFC;
    // 0x80010DA0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_80010DA4:
    // 0x80010DA4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010DA8: lw          $v1, 0x59E4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X59E4);
    // 0x80010DAC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80010DB0: beq         $t9, $zero, L_80010DDC
    if (ctx->r25 == 0) {
        // 0x80010DB4: nop
    
            goto L_80010DDC;
    }
    // 0x80010DB4: nop

    // 0x80010DB8: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80010DBC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010DC0: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, 0X5B98);
    // 0x80010DC4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80010DC8: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x80010DCC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80010DD0: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x80010DD4: b           L_80010DFC
    // 0x80010DD8: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
        goto L_80010DFC;
    // 0x80010DD8: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
L_80010DDC:
    // 0x80010DDC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010DE0: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, 0X5B98);
    // 0x80010DE4: addiu       $t3, $zero, -0x59
    ctx->r11 = ADD32(0, -0X59);
    // 0x80010DE8: addiu       $t4, $zero, 0x59
    ctx->r12 = ADD32(0, 0X59);
    // 0x80010DEC: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80010DF0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80010DF4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80010DF8: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
L_80010DFC:
    // 0x80010DFC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010E00: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80010E04: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80010E08: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80010E0C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80010E10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80010E14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80010E18: addiu       $a0, $a0, 0x6E88
    ctx->r4 = ADD32(ctx->r4, 0X6E88);
    // 0x80010E1C: lui         $a1, 0xC2B2
    ctx->r5 = S32(0XC2B2 << 16);
    // 0x80010E20: lui         $a2, 0x42B2
    ctx->r6 = S32(0X42B2 << 16);
    // 0x80010E24: jal         0x800238E4
    // 0x80010E28: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800238E4(rdram, ctx);
        goto after_2;
    // 0x80010E28: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_2:
    // 0x80010E2C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80010E30: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80010E34: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80010E38: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80010E3C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010E40: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, 0X5B98);
    // 0x80010E44: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80010E48: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80010E4C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80010E50: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80010E54: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x80010E58: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80010E5C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x80010E60: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x80010E64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80010E68: jr          $ra
    // 0x80010E6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80010E6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80002EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EA0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80002EA4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002EA8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80002EAC: addiu       $t0, $t0, 0x5368
    ctx->r8 = ADD32(ctx->r8, 0X5368);
    // 0x80002EB0: addiu       $a3, $a3, 0x4EE8
    ctx->r7 = ADD32(ctx->r7, 0X4EE8);
    // 0x80002EB4: addiu       $a2, $a2, 0x4EE4
    ctx->r6 = ADD32(ctx->r6, 0X4EE4);
    // 0x80002EB8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80002EBC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80002EC0: lw          $t6, -0x4538($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4538);
    // 0x80002EC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002EC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002ECC: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80002ED0: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x80002ED4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80002ED8: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80002EDC: addiu       $a0, $a0, 0x4158
    ctx->r4 = ADD32(ctx->r4, 0X4158);
    // 0x80002EE0: sw          $v0, 0x4EEC($at)
    MEM_W(0X4EEC, ctx->r1) = ctx->r2;
    // 0x80002EE4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80002EE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002EEC: addiu       $a1, $a1, 0x4048
    ctx->r5 = ADD32(ctx->r5, 0X4048);
    // 0x80002EF0: sw          $v1, 0x4EF0($at)
    MEM_W(0X4EF0, ctx->r1) = ctx->r3;
    // 0x80002EF4: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x80002EF8: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
L_80002EFC:
    // 0x80002EFC: bnel        $v0, $t7, L_80002F44
    if (ctx->r2 != ctx->r15) {
        // 0x80002F00: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80002F44;
    }
    goto skip_0;
    // 0x80002F00: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    skip_0:
    // 0x80002F04: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x80002F08: bnel        $v1, $t8, L_80002F44
    if (ctx->r3 != ctx->r24) {
        // 0x80002F0C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80002F44;
    }
    goto skip_1;
    // 0x80002F0C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    skip_1:
    // 0x80002F10: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80002F14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002F18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80002F1C: swc1        $f6, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f6.u32l;
    // 0x80002F20: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80002F24: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002F28: swc1        $f8, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f8.u32l;
    // 0x80002F2C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80002F30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002F34: swc1        $f10, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f10.u32l;
    // 0x80002F38: b           L_80002F50
    // 0x80002F3C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
        goto L_80002F50;
    // 0x80002F3C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x80002F40: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_80002F44:
    // 0x80002F44: bnel        $a1, $a0, L_80002EFC
    if (ctx->r5 != ctx->r4) {
        // 0x80002F48: lhu         $t7, 0x0($a1)
        ctx->r15 = MEM_HU(ctx->r5, 0X0);
            goto L_80002EFC;
    }
    goto skip_2;
    // 0x80002F48: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    skip_2:
    // 0x80002F4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80002F50:
    // 0x80002F50: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80002F54: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80002F58: jr          $ra
    // 0x80002F5C: nop

    return;
    // 0x80002F5C: nop

;}
RECOMP_FUNC void func_80044190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044198: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004419C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800441A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800441A4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800441A8: beql        $t7, $zero, L_80044220
    if (ctx->r15 == 0) {
        // 0x800441AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044220;
    }
    goto skip_0;
    // 0x800441AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800441B0: jal         0x80036A30
    // 0x800441B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x800441B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800441B8: beq         $v0, $zero, L_8004421C
    if (ctx->r2 == 0) {
        // 0x800441BC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8004421C;
    }
    // 0x800441BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800441C0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800441C4: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800441C8: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800441CC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800441D0: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800441D4: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800441D8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800441DC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800441E0: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800441E4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800441E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800441EC: jal         0x80036928
    // 0x800441F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80036928(rdram, ctx);
        goto after_1;
    // 0x800441F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800441F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800441F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800441FC: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80044200: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80044204: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80044208: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8004420C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80044210: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80044214: jalr        $t9
    // 0x80044218: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80044218: nop

    after_2:
L_8004421C:
    // 0x8004421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044220:
    // 0x80044220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044224: jr          $ra
    // 0x80044228: nop

    return;
    // 0x80044228: nop

    // 0x8004422C: nop

;}
RECOMP_FUNC void func_8003195C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003195C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031964: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80031968: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003196C: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80031970: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80031974: addiu       $t6, $t6, -0x48C
    ctx->r14 = ADD32(ctx->r14, -0X48C);
    // 0x80031978: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8003197C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80031980: addiu       $t3, $t3, 0x2898
    ctx->r11 = ADD32(ctx->r11, 0X2898);
    // 0x80031984: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80031988: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8003198C: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x80031990: lui         $a2, 0x4E45
    ctx->r6 = S32(0X4E45 << 16);
    // 0x80031994: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80031998: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8003199C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800319A0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800319A4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800319A8: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x800319AC: addiu       $a3, $a3, -0x4C0
    ctx->r7 = ADD32(ctx->r7, -0X4C0);
    // 0x800319B0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800319B4: ori         $a2, $a2, 0x5445
    ctx->r6 = ctx->r6 | 0X5445;
    // 0x800319B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800319BC: addiu       $a1, $zero, 0x3738
    ctx->r5 = ADD32(0, 0X3738);
    // 0x800319C0: jal         0x8003BA20
    // 0x800319C4: sb          $t0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r8;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x800319C4: sb          $t0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x800319C8: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x800319CC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800319D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800319D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800319D8: jr          $ra
    // 0x800319DC: nop

    return;
    // 0x800319DC: nop

;}
RECOMP_FUNC void func_80019CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CA4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80019CA8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80019CAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019CB0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80019CB4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80019CB8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019CBC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80019CC0: sh          $zero, -0x7F58($at)
    MEM_H(-0X7F58, ctx->r1) = 0;
    // 0x80019CC4: jr          $ra
    // 0x80019CC8: nop

    return;
    // 0x80019CC8: nop

;}
RECOMP_FUNC void func_80101E8C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101E8C: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80101E90: bltz        $t6, L_80101EA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80101E94: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80101EA0;
    }
    // 0x80101E94: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80101E98: jr          $ra
    // 0x80101E9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101E9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101EA0:
    // 0x80101EA0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80101EA4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80101EA8: addiu       $t8, $t8, 0x6250
    ctx->r24 = ADD32(ctx->r24, 0X6250);
    // 0x80101EAC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80101EB0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80101EB4: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101EB8: lh          $t1, 0x28($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X28);
    // 0x80101EBC: lw          $t2, 0x38($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X38);
    // 0x80101EC0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80101EC4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80101EC8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80101ECC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101ED0: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x80101ED4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80101ED8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80101EDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80101EE0: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x80101EE4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80101EE8: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80101EEC: div.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80101EF0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80101EF4: nop

    // 0x80101EF8: bc1fl       L_80101F08
    if (!c1cs) {
        // 0x80101EFC: lwc1        $f6, 0x20($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
            goto L_80101F08;
    }
    goto skip_0;
    // 0x80101EFC: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    skip_0:
    // 0x80101F00: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101F04: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
L_80101F08:
    // 0x80101F08: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x80101F0C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80101F10: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101F14: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80101F18: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80101F1C: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80101F20: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80101F24: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80101F28: beq         $at, $zero, L_80101F38
    if (ctx->r1 == 0) {
        // 0x80101F2C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80101F38;
    }
    // 0x80101F2C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80101F30: b           L_80101F3C
    // 0x80101F34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80101F3C;
    // 0x80101F34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80101F38:
    // 0x80101F38: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80101F3C:
    // 0x80101F3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80101F40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80101F44: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x80101F48: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80101F4C: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x80101F50: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80101F54: andi        $t0, $v0, 0x8
    ctx->r8 = ctx->r2 & 0X8;
    // 0x80101F58: bc1fl       L_80101F78
    if (!c1cs) {
        // 0x80101F5C: lh          $t5, 0x24($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X24);
            goto L_80101F78;
    }
    goto skip_1;
    // 0x80101F5C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    skip_1:
    // 0x80101F60: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80101F64: nop

    // 0x80101F68: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101F6C: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80101F70: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x80101F74: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
L_80101F78:
    // 0x80101F78: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80101F7C: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80101F80: bne         $at, $zero, L_80101F90
    if (ctx->r1 != 0) {
        // 0x80101F84: nop
    
            goto L_80101F90;
    }
    // 0x80101F84: nop

    // 0x80101F88: lh          $t7, 0x2C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2C);
    // 0x80101F8C: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
L_80101F90:
    // 0x80101F90: beq         $t8, $zero, L_80101FB4
    if (ctx->r24 == 0) {
        // 0x80101F94: nop
    
            goto L_80101FB4;
    }
    // 0x80101F94: nop

    // 0x80101F98: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101F9C: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80101FA0: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101FA4: bnel        $at, $zero, L_80101FD8
    if (ctx->r1 != 0) {
        // 0x80101FA8: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101FD8;
    }
    goto skip_2;
    // 0x80101FA8: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_2:
    // 0x80101FAC: b           L_80101FD4
    // 0x80101FB0: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
        goto L_80101FD4;
    // 0x80101FB0: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_80101FB4:
    // 0x80101FB4: beql        $t0, $zero, L_80101FD8
    if (ctx->r8 == 0) {
        // 0x80101FB8: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101FD8;
    }
    goto skip_3;
    // 0x80101FB8: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x80101FBC: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101FC0: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80101FC4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80101FC8: bnel        $at, $zero, L_80101FD8
    if (ctx->r1 != 0) {
        // 0x80101FCC: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101FD8;
    }
    goto skip_4;
    // 0x80101FCC: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x80101FD0: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_80101FD4:
    // 0x80101FD4: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
L_80101FD8:
    // 0x80101FD8: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101FE0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101FE4: bne         $at, $zero, L_80102004
    if (ctx->r1 != 0) {
        // 0x80101FE8: nop
    
            goto L_80102004;
    }
    // 0x80101FE8: nop

    // 0x80101FEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101FF0: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x80101FF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101FF8: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80101FFC: jr          $ra
    // 0x80102000: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80102000: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_80102004:
    // 0x80102004: jr          $ra
    // 0x80102008: nop

    return;
    // 0x80102008: nop

;}
RECOMP_FUNC void func_80031574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031574: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80031578: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003157C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80031580: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80031584: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80031588: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003158C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80031590: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80031594: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80031598: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003159C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800315A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800315A4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x800315A8: addu        $t6, $t6, $s2
    ctx->r14 = ADD32(ctx->r14, ctx->r18);
    // 0x800315AC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800315B0: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x800315B4: addiu       $t7, $t7, 0x2A38
    ctx->r15 = ADD32(ctx->r15, 0X2A38);
    // 0x800315B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800315BC: addu        $t9, $t9, $s2
    ctx->r25 = ADD32(ctx->r25, ctx->r18);
    // 0x800315C0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800315C4: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800315C8: addiu       $t0, $t0, 0x2A38
    ctx->r8 = ADD32(ctx->r8, 0X2A38);
    // 0x800315CC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800315D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800315D4: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x800315D8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800315DC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800315E0: sb          $t8, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r24;
    // 0x800315E4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800315E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800315EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800315F0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800315F4:
    // 0x800315F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800315F8: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800315FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80031600: bne         $at, $zero, L_800315F4
    if (ctx->r1 != 0) {
        // 0x80031604: sb          $s3, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r19;
            goto L_800315F4;
    }
    // 0x80031604: sb          $s3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r19;
    // 0x80031608: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8003160C: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80031610: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80031614: addu        $t1, $t1, $s2
    ctx->r9 = ADD32(ctx->r9, ctx->r18);
    // 0x80031618: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8003161C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80031620: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x80031624: addiu       $t2, $t2, 0x2898
    ctx->r10 = ADD32(ctx->r10, 0X2898);
    // 0x80031628: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8003162C: addiu       $s7, $s7, 0x2880
    ctx->r23 = ADD32(ctx->r23, 0X2880);
    // 0x80031630: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80031634: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80031638: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003163C: jal         0x80039D90
    // 0x80031640: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x80031640: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x80031644: beq         $v0, $zero, L_8003167C
    if (ctx->r2 == 0) {
        // 0x80031648: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_8003167C;
    }
    // 0x80031648: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8003164C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80031650: bne         $v0, $at, L_80031674
    if (ctx->r2 != ctx->r1) {
        // 0x80031654: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80031674;
    }
    // 0x80031654: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80031658: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8003165C: jal         0x8003A4BC
    // 0x80031660: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80031660: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80031664: bne         $v0, $zero, L_80031674
    if (ctx->r2 != 0) {
        // 0x80031668: addiu       $s5, $zero, 0xA
        ctx->r21 = ADD32(0, 0XA);
            goto L_80031674;
    }
    // 0x80031668: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8003166C: b           L_800317D0
    // 0x80031670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800317D0;
    // 0x80031670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031674:
    // 0x80031674: b           L_800317D0
    // 0x80031678: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_800317D0;
    // 0x80031678: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8003167C:
    // 0x8003167C: lui         $s7, 0x4E45
    ctx->r23 = S32(0X4E45 << 16);
    // 0x80031680: ori         $s7, $s7, 0x5445
    ctx->r23 = ctx->r23 | 0X5445;
    // 0x80031684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80031688: addiu       $fp, $zero, 0x3738
    ctx->r30 = ADD32(0, 0X3738);
    // 0x8003168C: addiu       $s2, $zero, 0x7F
    ctx->r18 = ADD32(0, 0X7F);
    // 0x80031690: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80031694:
    // 0x80031694: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80031698: jal         0x8003AE30
    // 0x8003169C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x8003169C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    after_2:
    // 0x800316A0: bne         $v0, $zero, L_80031720
    if (ctx->r2 != 0) {
        // 0x800316A4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_80031720;
    }
    // 0x800316A4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800316A8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800316AC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800316B0: lhu         $t4, 0x54($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X54);
    // 0x800316B4: bne         $t3, $s7, L_80031714
    if (ctx->r11 != ctx->r23) {
        // 0x800316B8: addu        $t0, $s0, $a1
        ctx->r8 = ADD32(ctx->r16, ctx->r5);
            goto L_80031714;
    }
    // 0x800316B8: addu        $t0, $s0, $a1
    ctx->r8 = ADD32(ctx->r16, ctx->r5);
    // 0x800316BC: bne         $fp, $t4, L_80031714
    if (ctx->r30 != ctx->r12) {
        // 0x800316C0: lui         $a0, 0x8006
        ctx->r4 = S32(0X8006 << 16);
            goto L_80031714;
    }
    // 0x800316C0: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x800316C4: addiu       $a0, $a0, -0x4C0
    ctx->r4 = ADD32(ctx->r4, -0X4C0);
    // 0x800316C8: addiu       $a1, $sp, 0x5A
    ctx->r5 = ADD32(ctx->r29, 0X5A);
    // 0x800316CC: jal         0x80031C0C
    // 0x800316D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80031C0C(rdram, ctx);
        goto after_3;
    // 0x800316D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_3:
    // 0x800316D4: bne         $v0, $zero, L_80031704
    if (ctx->r2 != 0) {
        // 0x800316D8: lw          $a1, 0x8C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X8C);
            goto L_80031704;
    }
    // 0x800316D8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800316DC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800316E0: lbu         $t5, 0x56($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X56);
    // 0x800316E4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800316E8: addu        $t6, $s1, $a1
    ctx->r14 = ADD32(ctx->r17, ctx->r5);
    // 0x800316EC: sb          $t5, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r13;
    // 0x800316F0: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x800316F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800316F8: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x800316FC: b           L_80031738
    // 0x80031700: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
        goto L_80031738;
    // 0x80031700: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
L_80031704:
    // 0x80031704: addu        $t9, $s0, $a1
    ctx->r25 = ADD32(ctx->r16, ctx->r5);
    // 0x80031708: sb          $s2, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r18;
    // 0x8003170C: b           L_80031738
    // 0x80031710: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
        goto L_80031738;
    // 0x80031710: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80031714:
    // 0x80031714: sb          $s2, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r18;
    // 0x80031718: b           L_80031738
    // 0x8003171C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
        goto L_80031738;
    // 0x8003171C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80031720:
    // 0x80031720: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80031724: bne         $v0, $at, L_8003174C
    if (ctx->r2 != ctx->r1) {
        // 0x80031728: lw          $a1, 0x8C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X8C);
            goto L_8003174C;
    }
    // 0x80031728: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8003172C: addu        $t1, $s0, $a1
    ctx->r9 = ADD32(ctx->r16, ctx->r5);
    // 0x80031730: sb          $s3, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r19;
    // 0x80031734: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_80031738:
    // 0x80031738: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003173C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80031740: bnel        $at, $zero, L_80031694
    if (ctx->r1 != 0) {
        // 0x80031744: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80031694;
    }
    goto skip_0;
    // 0x80031744: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80031748: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
L_8003174C:
    // 0x8003174C: bne         $s5, $zero, L_800317CC
    if (ctx->r21 != 0) {
        // 0x80031750: addiu       $a1, $sp, 0x8C
        ctx->r5 = ADD32(ctx->r29, 0X8C);
            goto L_800317CC;
    }
    // 0x80031750: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80031754: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80031758: slti        $at, $s4, 0x10
    ctx->r1 = SIGNED(ctx->r20) < 0X10 ? 1 : 0;
    // 0x8003175C: andi        $t3, $t2, 0xFFF0
    ctx->r11 = ctx->r10 & 0XFFF0;
    // 0x80031760: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80031764: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80031768: or          $t5, $t4, $s4
    ctx->r13 = ctx->r12 | ctx->r20;
    // 0x8003176C: bne         $at, $zero, L_80031780
    if (ctx->r1 != 0) {
        // 0x80031770: sh          $t5, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r13;
            goto L_80031780;
    }
    // 0x80031770: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
    // 0x80031774: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80031778: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x8003177C: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_80031780:
    // 0x80031780: slti        $at, $s6, 0x10
    ctx->r1 = SIGNED(ctx->r22) < 0X10 ? 1 : 0;
    // 0x80031784: bne         $at, $zero, L_80031798
    if (ctx->r1 != 0) {
        // 0x80031788: nop
    
            goto L_80031798;
    }
    // 0x80031788: nop

    // 0x8003178C: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x80031790: ori         $t9, $t8, 0x2000
    ctx->r25 = ctx->r24 | 0X2000;
    // 0x80031794: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
L_80031798:
    // 0x80031798: jal         0x8003B120
    // 0x8003179C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_4;
    // 0x8003179C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800317A0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800317A4: bgez        $a1, L_800317B4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800317A8: sra         $t0, $a1, 8
        ctx->r8 = S32(SIGNED(ctx->r5) >> 8);
            goto L_800317B4;
    }
    // 0x800317A8: sra         $t0, $a1, 8
    ctx->r8 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800317AC: addiu       $at, $a1, 0xFF
    ctx->r1 = ADD32(ctx->r5, 0XFF);
    // 0x800317B0: sra         $t0, $at, 8
    ctx->r8 = S32(SIGNED(ctx->r1) >> 8);
L_800317B4:
    // 0x800317B4: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800317B8: beq         $at, $zero, L_800317CC
    if (ctx->r1 == 0) {
        // 0x800317BC: sb          $t0, 0x13($s1)
        MEM_B(0X13, ctx->r17) = ctx->r8;
            goto L_800317CC;
    }
    // 0x800317BC: sb          $t0, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r8;
    // 0x800317C0: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x800317C4: ori         $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 | 0X2000;
    // 0x800317C8: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
L_800317CC:
    // 0x800317CC: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800317D0:
    // 0x800317D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800317D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800317D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800317DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800317E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800317E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800317E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800317EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800317F0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800317F4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800317F8: jr          $ra
    // 0x800317FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800317FC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80019A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019A70: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019A74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80019A78: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x80019A7C: sh          $zero, -0x7F58($at)
    MEM_H(-0X7F58, ctx->r1) = 0;
    // 0x80019A80: sh          $zero, 0x1A0($v0)
    MEM_H(0X1A0, ctx->r2) = 0;
    // 0x80019A84: sh          $zero, 0xD0($v0)
    MEM_H(0XD0, ctx->r2) = 0;
    // 0x80019A88: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80019A8C: addiu       $v0, $v0, 0x1A0
    ctx->r2 = ADD32(ctx->r2, 0X1A0);
    // 0x80019A90: jr          $ra
    // 0x80019A94: nop

    return;
    // 0x80019A94: nop

;}
RECOMP_FUNC void func_800172A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800172A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800172A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800172A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800172AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800172B0: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x800172B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800172B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800172BC: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800172C0: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800172C4: beq         $a0, $at, L_800172EC
    if (ctx->r4 == ctx->r1) {
        // 0x800172C8: sh          $t7, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r15;
            goto L_800172EC;
    }
    // 0x800172C8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800172CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800172D0: beq         $a0, $at, L_80017318
    if (ctx->r4 == ctx->r1) {
        // 0x800172D4: addiu       $a1, $zero, 0x20
        ctx->r5 = ADD32(0, 0X20);
            goto L_80017318;
    }
    // 0x800172D4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800172D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800172DC: beq         $a0, $at, L_80017344
    if (ctx->r4 == ctx->r1) {
        // 0x800172E0: addiu       $a1, $zero, 0x20
        ctx->r5 = ADD32(0, 0X20);
            goto L_80017344;
    }
    // 0x800172E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800172E4: b           L_8001736C
    // 0x800172E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001736C;
    // 0x800172E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800172EC:
    // 0x800172EC: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x800172F0: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x800172F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800172F8: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x800172FC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80017300: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017304: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80017308: jal         0x8001FCF8
    // 0x8001730C: sh          $t0, 0x86($t1)
    MEM_H(0X86, ctx->r9) = ctx->r8;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x8001730C: sh          $t0, 0x86($t1)
    MEM_H(0X86, ctx->r9) = ctx->r8;
    after_0:
    // 0x80017310: b           L_8001736C
    // 0x80017314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001736C;
    // 0x80017314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017318:
    // 0x80017318: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x8001731C: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
    // 0x80017320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017324: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x80017328: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8001732C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017330: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80017334: jal         0x8001FCF8
    // 0x80017338: sh          $t4, 0x86($t5)
    MEM_H(0X86, ctx->r13) = ctx->r12;
    func_8001FCF8(rdram, ctx);
        goto after_1;
    // 0x80017338: sh          $t4, 0x86($t5)
    MEM_H(0X86, ctx->r13) = ctx->r12;
    after_1:
    // 0x8001733C: b           L_8001736C
    // 0x80017340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001736C;
    // 0x80017340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017344:
    // 0x80017344: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80017348: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x8001734C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017350: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x80017354: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80017358: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001735C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80017360: jal         0x8001FCF8
    // 0x80017364: sh          $t8, 0x86($t9)
    MEM_H(0X86, ctx->r25) = ctx->r24;
    func_8001FCF8(rdram, ctx);
        goto after_2;
    // 0x80017364: sh          $t8, 0x86($t9)
    MEM_H(0X86, ctx->r25) = ctx->r24;
    after_2:
    // 0x80017368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001736C:
    // 0x8001736C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80017374: jr          $ra
    // 0x80017378: nop

    return;
    // 0x80017378: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036660: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80036664: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80036668: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003666C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036670: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80036674: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80036678: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x8003667C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80036680: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80036684: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036688: mflo        $v0
    ctx->r2 = lo;
    // 0x8003668C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80036690: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80036694: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x80036698: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8003669C: bne         $at, $zero, L_800366AC
    if (ctx->r1 != 0) {
        // 0x800366A0: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800366AC;
    }
    // 0x800366A0: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800366A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800366A8: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800366AC:
    // 0x800366AC: jr          $ra
    // 0x800366B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800366B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800366B4: nop

    // 0x800366B8: nop

    // 0x800366BC: nop

;}
RECOMP_FUNC void func_800314C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800314C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800314C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800314C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800314CC: jal         0x8003ABA0
    // 0x800314D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    osContSetCh_recomp(rdram, ctx);
        goto after_0;
    // 0x800314D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800314D4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800314D8: jal         0x8003AC10
    // 0x800314DC: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    osContStartReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x800314DC: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    after_1:
    // 0x800314E0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800314E4: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    // 0x800314E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800314EC: jal         0x80034020
    // 0x800314F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800314F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800314F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800314F8: beq         $v0, $at, L_80031508
    if (ctx->r2 == ctx->r1) {
        // 0x800314FC: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_80031508;
    }
    // 0x800314FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031500: jal         0x8003AC9C
    // 0x80031504: addiu       $a0, $a0, 0x2AA8
    ctx->r4 = ADD32(ctx->r4, 0X2AA8);
    osContGetReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x80031504: addiu       $a0, $a0, 0x2AA8
    ctx->r4 = ADD32(ctx->r4, 0X2AA8);
    after_3:
L_80031508:
    // 0x80031508: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003150C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80031510: addiu       $t8, $t8, 0x2AA8
    ctx->r24 = ADD32(ctx->r24, 0X2AA8);
    // 0x80031514: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031518: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8003151C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80031520: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80031524: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80031528: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003152C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80031530: sh          $v1, 0x2874($at)
    MEM_H(0X2874, ctx->r1) = ctx->r3;
    // 0x80031534: lb          $t9, 0x2($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X2);
    // 0x80031538: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003153C: addiu       $a1, $a1, 0x2878
    ctx->r5 = ADD32(ctx->r5, 0X2878);
    // 0x80031540: sb          $t9, 0x2871($at)
    MEM_B(0X2871, ctx->r1) = ctx->r25;
    // 0x80031544: lb          $t0, 0x3($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X3);
    // 0x80031548: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003154C: nor         $t3, $v1, $zero
    ctx->r11 = ~(ctx->r3 | 0);
    // 0x80031550: sb          $t0, 0x2872($at)
    MEM_B(0X2872, ctx->r1) = ctx->r8;
    // 0x80031554: lhu         $t1, 0x0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X0);
    // 0x80031558: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003155C: and         $t2, $v1, $t1
    ctx->r10 = ctx->r3 & ctx->r9;
    // 0x80031560: sh          $t2, 0x2876($at)
    MEM_H(0X2876, ctx->r1) = ctx->r10;
    // 0x80031564: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80031568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003156C: jr          $ra
    // 0x80031570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80011150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011150: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80011154: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80011158: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001115C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011160: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80011164: sw          $zero, 0x59E8($at)
    MEM_W(0X59E8, ctx->r1) = 0;
    // 0x80011168: jr          $ra
    // 0x8001116C: nop

    return;
    // 0x8001116C: nop

;}
RECOMP_FUNC void func_80035190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035190: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80035194: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80035198: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8003519C: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x800351A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800351A4: beq         $t9, $zero, L_800351C8
    if (ctx->r25 == 0) {
        // 0x800351A8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800351C8;
    }
    // 0x800351A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800351AC: andi        $t0, $t8, 0x3FF
    ctx->r8 = ctx->r24 & 0X3FF;
    // 0x800351B0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800351B4: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x800351B8: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800351BC: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800351C0: b           L_800351DC
    // 0x800351C4: lh          $v1, 0x98E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X98E);
        goto L_800351DC;
    // 0x800351C4: lh          $v1, 0x98E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X98E);
L_800351C8:
    // 0x800351C8: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x800351CC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800351D0: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800351D4: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x800351D8: lh          $v1, 0x190($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X190);
L_800351DC:
    // 0x800351DC: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x800351E0: beq         $t5, $zero, L_800351F8
    if (ctx->r13 == 0) {
        // 0x800351E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800351F8;
    }
    // 0x800351E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800351E8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800351EC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800351F0: jr          $ra
    // 0x800351F4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    return;
    // 0x800351F4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_800351F8:
    // 0x800351F8: jr          $ra
    // 0x800351FC: nop

    return;
    // 0x800351FC: nop

;}
RECOMP_FUNC void func_800425E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800425E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800425E4: beq         $a1, $at, L_80042600
    if (ctx->r5 == ctx->r1) {
        // 0x800425E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80042600;
    }
    // 0x800425E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800425EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800425F0: beql        $a1, $at, L_8004260C
    if (ctx->r5 == ctx->r1) {
        // 0x800425F4: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_8004260C;
    }
    goto skip_0;
    // 0x800425F4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800425F8: jr          $ra
    // 0x800425FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800425FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80042600:
    // 0x80042600: jr          $ra
    // 0x80042604: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x80042604: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80042608: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_8004260C:
    // 0x8004260C: jr          $ra
    // 0x80042610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80042610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80015FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80015FEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80015FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80015FF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80015FF8: lhu         $t6, 0xA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XA);
    // 0x80015FFC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016000: bnel        $t7, $zero, L_8001612C
    if (ctx->r15 != 0) {
        // 0x80016004: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001612C;
    }
    goto skip_0;
    // 0x80016004: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80016008: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8001600C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80016010: addiu       $t1, $t1, 0x71E0
    ctx->r9 = ADD32(ctx->r9, 0X71E0);
    // 0x80016014: lhu         $t8, 0x2A($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2A);
    // 0x80016018: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x8001601C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80016020: beql        $t9, $zero, L_8001604C
    if (ctx->r25 == 0) {
        // 0x80016024: lwc1        $f18, 0x10($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8001604C;
    }
    goto skip_1;
    // 0x80016024: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x80016028: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8001602C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016030: ldc1        $f8, 0x14A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X14A8);
    // 0x80016034: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80016038: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8001603C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80016040: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80016044: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80016048: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
L_8001604C:
    // 0x8001604C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016054: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80016058: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8001605C: lhu         $t0, 0x14($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X14);
    // 0x80016060: bnel        $t0, $at, L_800160F8
    if (ctx->r8 != ctx->r1) {
        // 0x80016064: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_800160F8;
    }
    goto skip_2;
    // 0x80016064: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x80016068: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001606C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016070: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80016074: jal         0x8000EE60
    // 0x80016078: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8000EE60(rdram, ctx);
        goto after_0;
    // 0x80016078: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8001607C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016080: lwc1        $f2, 0x71E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X71E4);
    // 0x80016084: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016088: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8001608C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80016090: nop

    // 0x80016094: bc1fl       L_800160F8
    if (!c1cs) {
        // 0x80016098: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_800160F8;
    }
    goto skip_3;
    // 0x80016098: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_3:
    // 0x8001609C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800160A0: lhu         $t2, 0xA($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XA);
    // 0x800160A4: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800160A8: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x800160AC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800160B0: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x800160B4: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x800160B8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800160BC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800160C0: beq         $v0, $zero, L_800160E0
    if (ctx->r2 == 0) {
        // 0x800160C4: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_800160E0;
    }
    // 0x800160C4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x800160C8: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800160CC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800160D0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800160D4: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x800160D8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x800160DC: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
L_800160E0:
    // 0x800160E0: jal         0x80013F20
    // 0x800160E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80013F20(rdram, ctx);
        goto after_1;
    // 0x800160E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800160E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800160EC: jal         0x80017FA0
    // 0x800160F0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    func_80017FA0(rdram, ctx);
        goto after_2;
    // 0x800160F0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_2:
    // 0x800160F4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_800160F8:
    // 0x800160F8: lhu         $t9, 0x18($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X18);
    // 0x800160FC: bnel        $t9, $zero, L_8001612C
    if (ctx->r25 != 0) {
        // 0x80016100: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001612C;
    }
    goto skip_4;
    // 0x80016100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80016104: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80016108: lhu         $t0, 0x60($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X60);
    // 0x8001610C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80016110: bnel        $t1, $zero, L_8001612C
    if (ctx->r9 != 0) {
        // 0x80016114: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001612C;
    }
    goto skip_5;
    // 0x80016114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80016118: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001611C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80016120: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80016124: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x80016128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001612C:
    // 0x8001612C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80016130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80016134: jr          $ra
    // 0x80016138: nop

    return;
    // 0x80016138: nop

;}
RECOMP_FUNC void func_8002EAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EAA0: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8002EAA4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002EAA8: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8002EAAC: addiu       $s6, $s6, -0x4D04
    ctx->r22 = ADD32(ctx->r22, -0X4D04);
    // 0x8002EAB0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002EAB4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002EAB8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002EABC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002EAC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002EAC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002EAC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002EACC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002EAD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002EAD4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002EAD8: lw          $t6, -0x5FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5FC);
    // 0x8002EADC: sw          $zero, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = 0;
    // 0x8002EAE0: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x8002EAE4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8002EAE8: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x8002EAEC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002EAF0: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8002EAF4: addiu       $t9, $t9, -0x560
    ctx->r25 = ADD32(ctx->r25, -0X560);
    // 0x8002EAF8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002EAFC: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002EB00: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8002EB04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002EB08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002EB0C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002EB10: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x8002EB14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002EB18: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002EB1C: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002EB20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002EB24: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002EB28: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002EB2C: lw          $a1, 0x5E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5E0);
    // 0x8002EB30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002EB34: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8002EB38: andi        $v0, $a1, 0x7
    ctx->r2 = ctx->r5 & 0X7;
    // 0x8002EB3C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8002EB40: beq         $a2, $a0, L_8002EB78
    if (ctx->r6 == ctx->r4) {
        // 0x8002EB44: addiu       $s5, $zero, 0xFF
        ctx->r21 = ADD32(0, 0XFF);
            goto L_8002EB78;
    }
    // 0x8002EB44: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x8002EB48: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8002EB4C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8002EB50: beq         $v1, $a3, L_8002EB90
    if (ctx->r3 == ctx->r7) {
        // 0x8002EB54: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8002EB90;
    }
    // 0x8002EB54: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002EB58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002EB5C: beq         $v1, $v0, L_8002EB9C
    if (ctx->r3 == ctx->r2) {
        // 0x8002EB60: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8002EB9C;
    }
    // 0x8002EB60: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002EB64: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002EB68: beql        $v1, $t0, L_8002EBA8
    if (ctx->r3 == ctx->r8) {
        // 0x8002EB6C: sb          $zero, 0xEF($sp)
        MEM_B(0XEF, ctx->r29) = 0;
            goto L_8002EBA8;
    }
    goto skip_0;
    // 0x8002EB6C: sb          $zero, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = 0;
    skip_0:
    // 0x8002EB70: b           L_8002EBA8
    // 0x8002EB74: nop

        goto L_8002EBA8;
    // 0x8002EB74: nop

L_8002EB78:
    // 0x8002EB78: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8002EB7C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002EB80: sb          $zero, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = 0;
    // 0x8002EB84: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002EB88: b           L_8002EBA8
    // 0x8002EB8C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8002EBA8;
    // 0x8002EB8C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8002EB90:
    // 0x8002EB90: sb          $zero, 0xED($sp)
    MEM_B(0XED, ctx->r29) = 0;
    // 0x8002EB94: b           L_8002EBA8
    // 0x8002EB98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8002EBA8;
    // 0x8002EB98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8002EB9C:
    // 0x8002EB9C: b           L_8002EBA8
    // 0x8002EBA0: sb          $zero, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = 0;
        goto L_8002EBA8;
    // 0x8002EBA0: sb          $zero, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = 0;
    // 0x8002EBA4: sb          $zero, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = 0;
L_8002EBA8:
    // 0x8002EBA8: beq         $v1, $zero, L_8002EBB4
    if (ctx->r3 == 0) {
        // 0x8002EBAC: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_8002EBB4;
    }
    // 0x8002EBAC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002EBB0: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_8002EBB4:
    // 0x8002EBB4: lw          $t8, 0xE7C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE7C);
    // 0x8002EBB8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002EBBC: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8002EBC0: beq         $a2, $t9, L_8002EBE8
    if (ctx->r6 == ctx->r25) {
        // 0x8002EBC4: or          $s2, $t9, $zero
        ctx->r18 = ctx->r25 | 0;
            goto L_8002EBE8;
    }
    // 0x8002EBC4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8002EBC8: beq         $t9, $a3, L_8002EBF0
    if (ctx->r25 == ctx->r7) {
        // 0x8002EBCC: nop
    
            goto L_8002EBF0;
    }
    // 0x8002EBCC: nop

    // 0x8002EBD0: beq         $t9, $v0, L_8002EBF8
    if (ctx->r25 == ctx->r2) {
        // 0x8002EBD4: nop
    
            goto L_8002EBF8;
    }
    // 0x8002EBD4: nop

    // 0x8002EBD8: beql        $t9, $t0, L_8002EC04
    if (ctx->r25 == ctx->r8) {
        // 0x8002EBDC: sb          $a2, 0xEF($sp)
        MEM_B(0XEF, ctx->r29) = ctx->r6;
            goto L_8002EC04;
    }
    goto skip_1;
    // 0x8002EBDC: sb          $a2, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r6;
    skip_1:
    // 0x8002EBE0: b           L_8002EC04
    // 0x8002EBE4: nop

        goto L_8002EC04;
    // 0x8002EBE4: nop

L_8002EBE8:
    // 0x8002EBE8: b           L_8002EC04
    // 0x8002EBEC: sb          $a2, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r6;
        goto L_8002EC04;
    // 0x8002EBEC: sb          $a2, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r6;
L_8002EBF0:
    // 0x8002EBF0: b           L_8002EC04
    // 0x8002EBF4: sb          $a2, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r6;
        goto L_8002EC04;
    // 0x8002EBF4: sb          $a2, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r6;
L_8002EBF8:
    // 0x8002EBF8: b           L_8002EC04
    // 0x8002EBFC: sb          $a2, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r6;
        goto L_8002EC04;
    // 0x8002EBFC: sb          $a2, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r6;
    // 0x8002EC00: sb          $a2, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r6;
L_8002EC04:
    // 0x8002EC04: beq         $s2, $zero, L_8002EC10
    if (ctx->r18 == 0) {
        // 0x8002EC08: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_8002EC10;
    }
    // 0x8002EC08: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002EC0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8002EC10:
    // 0x8002EC10: lw          $t5, 0x1718($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1718);
    // 0x8002EC14: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002EC18: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8002EC1C: beq         $a2, $t6, L_8002EC44
    if (ctx->r6 == ctx->r14) {
        // 0x8002EC20: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_8002EC44;
    }
    // 0x8002EC20: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8002EC24: beq         $t6, $a3, L_8002EC4C
    if (ctx->r14 == ctx->r7) {
        // 0x8002EC28: nop
    
            goto L_8002EC4C;
    }
    // 0x8002EC28: nop

    // 0x8002EC2C: beq         $t6, $v0, L_8002EC54
    if (ctx->r14 == ctx->r2) {
        // 0x8002EC30: nop
    
            goto L_8002EC54;
    }
    // 0x8002EC30: nop

    // 0x8002EC34: beql        $t6, $t0, L_8002EC60
    if (ctx->r14 == ctx->r8) {
        // 0x8002EC38: sb          $a3, 0xEF($sp)
        MEM_B(0XEF, ctx->r29) = ctx->r7;
            goto L_8002EC60;
    }
    goto skip_2;
    // 0x8002EC38: sb          $a3, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r7;
    skip_2:
    // 0x8002EC3C: b           L_8002EC60
    // 0x8002EC40: nop

        goto L_8002EC60;
    // 0x8002EC40: nop

L_8002EC44:
    // 0x8002EC44: b           L_8002EC60
    // 0x8002EC48: sb          $a3, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r7;
        goto L_8002EC60;
    // 0x8002EC48: sb          $a3, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r7;
L_8002EC4C:
    // 0x8002EC4C: b           L_8002EC60
    // 0x8002EC50: sb          $a3, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r7;
        goto L_8002EC60;
    // 0x8002EC50: sb          $a3, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r7;
L_8002EC54:
    // 0x8002EC54: b           L_8002EC60
    // 0x8002EC58: sb          $a3, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r7;
        goto L_8002EC60;
    // 0x8002EC58: sb          $a3, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r7;
    // 0x8002EC5C: sb          $a3, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r7;
L_8002EC60:
    // 0x8002EC60: beq         $s2, $zero, L_8002EC6C
    if (ctx->r18 == 0) {
        // 0x8002EC64: nop
    
            goto L_8002EC6C;
    }
    // 0x8002EC64: nop

    // 0x8002EC68: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8002EC6C:
    // 0x8002EC6C: lw          $t7, 0x1FB4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1FB4);
    // 0x8002EC70: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8002EC74: beq         $a2, $t8, L_8002EC9C
    if (ctx->r6 == ctx->r24) {
        // 0x8002EC78: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_8002EC9C;
    }
    // 0x8002EC78: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8002EC7C: beq         $t8, $a3, L_8002ECA4
    if (ctx->r24 == ctx->r7) {
        // 0x8002EC80: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8002ECA4;
    }
    // 0x8002EC80: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8002EC84: beq         $t8, $v0, L_8002ECAC
    if (ctx->r24 == ctx->r2) {
        // 0x8002EC88: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8002ECAC;
    }
    // 0x8002EC88: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002EC8C: beq         $t8, $t0, L_8002ECB4
    if (ctx->r24 == ctx->r8) {
        // 0x8002EC90: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8002ECB4;
    }
    // 0x8002EC90: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002EC94: b           L_8002ECB8
    // 0x8002EC98: nop

        goto L_8002ECB8;
    // 0x8002EC98: nop

L_8002EC9C:
    // 0x8002EC9C: b           L_8002ECB8
    // 0x8002ECA0: sb          $t9, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r25;
        goto L_8002ECB8;
    // 0x8002ECA0: sb          $t9, 0xEC($sp)
    MEM_B(0XEC, ctx->r29) = ctx->r25;
L_8002ECA4:
    // 0x8002ECA4: b           L_8002ECB8
    // 0x8002ECA8: sb          $t5, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r13;
        goto L_8002ECB8;
    // 0x8002ECA8: sb          $t5, 0xED($sp)
    MEM_B(0XED, ctx->r29) = ctx->r13;
L_8002ECAC:
    // 0x8002ECAC: b           L_8002ECB8
    // 0x8002ECB0: sb          $t6, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r14;
        goto L_8002ECB8;
    // 0x8002ECB0: sb          $t6, 0xEE($sp)
    MEM_B(0XEE, ctx->r29) = ctx->r14;
L_8002ECB4:
    // 0x8002ECB4: sb          $t7, 0xEF($sp)
    MEM_B(0XEF, ctx->r29) = ctx->r15;
L_8002ECB8:
    // 0x8002ECB8: beq         $s2, $zero, L_8002ECC4
    if (ctx->r18 == 0) {
        // 0x8002ECBC: lui         $t8, 0x8006
        ctx->r24 = S32(0X8006 << 16);
            goto L_8002ECC4;
    }
    // 0x8002ECBC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8002ECC0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8002ECC4:
    // 0x8002ECC4: addiu       $t8, $t8, -0x480
    ctx->r24 = ADD32(ctx->r24, -0X480);
    // 0x8002ECC8: addiu       $t9, $sp, 0xEC
    ctx->r25 = ADD32(ctx->r29, 0XEC);
    // 0x8002ECCC: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8002ECD0: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x8002ECD4: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
L_8002ECD8:
    // 0x8002ECD8: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8002ECDC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ECE0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8002ECE4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002ECE8: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002ECEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ECF0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002ECF4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ECF8: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x8002ECFC: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8002ED00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002ED04: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8002ED08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002ED0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002ED10: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002ED18: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8002ED1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ED20: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002ED24: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED28: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8002ED2C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002ED30: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002ED34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002ED38: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8002ED3C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8002ED40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002ED44: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED48: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8002ED4C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002ED50: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8002ED54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ED58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002ED5C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED60: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8002ED64: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8002ED68: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002ED6C: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002ED70: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002ED74: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002ED78: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED7C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8002ED80: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8002ED84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002ED88: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8002ED8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002ED90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002ED94: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002ED98: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8002ED9C: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8002EDA0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002EDA4: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002EDA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002EDAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002EDB0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002EDB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002EDB8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8002EDBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002EDC0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002EDC4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002EDC8: lb          $fp, 0x0($t9)
    ctx->r30 = MEM_B(ctx->r25, 0X0);
    // 0x8002EDCC: bltz        $fp, L_8002FA34
    if (SIGNED(ctx->r30) < 0) {
        // 0x8002EDD0: sll         $t5, $fp, 4
        ctx->r13 = S32(ctx->r30 << 4);
            goto L_8002FA34;
    }
    // 0x8002EDD0: sll         $t5, $fp, 4
    ctx->r13 = S32(ctx->r30 << 4);
    // 0x8002EDD4: addu        $t5, $t5, $fp
    ctx->r13 = ADD32(ctx->r13, ctx->r30);
    // 0x8002EDD8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002EDDC: addu        $t5, $t5, $fp
    ctx->r13 = ADD32(ctx->r13, ctx->r30);
    // 0x8002EDE0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002EDE4: subu        $t5, $t5, $fp
    ctx->r13 = SUB32(ctx->r13, ctx->r30);
    // 0x8002EDE8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002EDEC: addiu       $t6, $t6, 0x5E0
    ctx->r14 = ADD32(ctx->r14, 0X5E0);
    // 0x8002EDF0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002EDF4: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8002EDF8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002EDFC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8002EE00: bgezl       $t7, L_8002EE40
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002EE04: sll         $t7, $v0, 7
        ctx->r15 = S32(ctx->r2 << 7);
            goto L_8002EE40;
    }
    goto skip_3;
    // 0x8002EE04: sll         $t7, $v0, 7
    ctx->r15 = S32(ctx->r2 << 7);
    skip_3:
    // 0x8002EE08: jal         0x8002FB30
    // 0x8002EE0C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FB30(rdram, ctx);
        goto after_0;
    // 0x8002EE0C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_0:
    // 0x8002EE10: bgezl       $v0, L_8002FA38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002EE14: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_8002FA38;
    }
    goto skip_4;
    // 0x8002EE14: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_4:
    // 0x8002EE18: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8002EE1C: lui         $at, 0xEFFF
    ctx->r1 = S32(0XEFFF << 16);
    // 0x8002EE20: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002EE24: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002EE28: lui         $at, 0xA800
    ctx->r1 = S32(0XA800 << 16);
    // 0x8002EE2C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002EE30: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002EE34: b           L_8002FA34
    // 0x8002EE38: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
        goto L_8002FA34;
    // 0x8002EE38: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002EE3C: sll         $t7, $v0, 7
    ctx->r15 = S32(ctx->r2 << 7);
L_8002EE40:
    // 0x8002EE40: bgez        $t7, L_8002EF40
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002EE44: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8002EF40;
    }
    // 0x8002EE44: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8002EE48: jal         0x8002FB30
    // 0x8002EE4C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FB30(rdram, ctx);
        goto after_1;
    // 0x8002EE4C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_1:
    // 0x8002EE50: bgez        $v0, L_8002FA34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002EE54: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8002FA34;
    }
    // 0x8002EE54: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002EE58: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002EE5C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8002EE60: addiu       $s0, $s0, 0x5E0
    ctx->r16 = ADD32(ctx->r16, 0X5E0);
L_8002EE64:
    // 0x8002EE64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002EE68: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8002EE6C: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x8002EE70: beq         $t8, $zero, L_8002EEEC
    if (ctx->r24 == 0) {
        // 0x8002EE74: addiu       $a0, $t8, 0x1
        ctx->r4 = ADD32(ctx->r24, 0X1);
            goto L_8002EEEC;
    }
    // 0x8002EE74: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x8002EE78: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8002EE7C: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8002EE80: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002EE84: or          $t7, $t5, $t9
    ctx->r15 = ctx->r13 | ctx->r25;
    // 0x8002EE88: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8002EE8C: bne         $at, $zero, L_8002EEEC
    if (ctx->r1 != 0) {
        // 0x8002EE90: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_8002EEEC;
    }
    // 0x8002EE90: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8002EE94: lui         $at, 0xFFBF
    ctx->r1 = S32(0XFFBF << 16);
    // 0x8002EE98: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002EE9C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8002EEA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002EEA4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8002EEA8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002EEAC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002EEB0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002EEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002EEB8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8002EEBC: bgezl       $t8, L_8002EEF0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002EEC0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002EEF0;
    }
    goto skip_5;
    // 0x8002EEC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8002EEC4: jal         0x8002E628
    // 0x8002EEC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002E628(rdram, ctx);
        goto after_2;
    // 0x8002EEC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8002EECC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8002EED0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002EED4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8002EED8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8002EEDC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002EEE0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002EEE4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8002EEE8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8002EEEC:
    // 0x8002EEEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8002EEF0:
    // 0x8002EEF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002EEF4: bne         $s1, $at, L_8002EE64
    if (ctx->r17 != ctx->r1) {
        // 0x8002EEF8: addiu       $s0, $s0, 0x89C
        ctx->r16 = ADD32(ctx->r16, 0X89C);
            goto L_8002EE64;
    }
    // 0x8002EEF8: addiu       $s0, $s0, 0x89C
    ctx->r16 = ADD32(ctx->r16, 0X89C);
    // 0x8002EEFC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002EF00: jal         0x8002E628
    // 0x8002EF04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002E628(rdram, ctx);
        goto after_3;
    // 0x8002EF04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002EF08: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002EF0C: addiu       $v0, $v0, 0x5C0
    ctx->r2 = ADD32(ctx->r2, 0X5C0);
    // 0x8002EF10: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002EF14: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x8002EF18: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002EF1C: bgtz        $t5, L_8002FA34
    if (SIGNED(ctx->r13) > 0) {
        // 0x8002EF20: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_8002FA34;
    }
    // 0x8002EF20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002EF24: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002EF28: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x8002EF2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002EF30: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002EF34: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8002EF38: b           L_8002FA34
    // 0x8002EF3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8002FA34;
    // 0x8002EF3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8002EF40:
    // 0x8002EF40: bgezl       $t8, L_8002FA24
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002EF44: lw          $t9, 0xE0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XE0);
            goto L_8002FA24;
    }
    goto skip_6;
    // 0x8002EF44: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    skip_6:
    // 0x8002EF48: jal         0x8002FEA4
    // 0x8002EF4C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FEA4(rdram, ctx);
        goto after_4;
    // 0x8002EF4C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_4:
    // 0x8002EF50: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002EF54: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8002EF58: bgez        $t9, L_8002F318
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002EF5C: sll         $t8, $v0, 0
        ctx->r24 = S32(ctx->r2 << 0);
            goto L_8002F318;
    }
    // 0x8002EF5C: sll         $t8, $v0, 0
    ctx->r24 = S32(ctx->r2 << 0);
    // 0x8002EF60: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002EF64: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8002EF68: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002EF6C: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002EF70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002EF74: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002EF78: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002EF7C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8002EF80: addiu       $t9, $zero, -0x34
    ctx->r25 = ADD32(0, -0X34);
    // 0x8002EF84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002EF88: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002EF8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002EF90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002EF94: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
    // 0x8002EF98: lh          $s4, 0x4($s3)
    ctx->r20 = MEM_H(ctx->r19, 0X4);
    // 0x8002EF9C: lh          $s2, 0x6($s3)
    ctx->r18 = MEM_H(ctx->r19, 0X6);
    // 0x8002EFA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002EFA4: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
    // 0x8002EFA8: blez        $v1, L_8002F004
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002EFAC: addiu       $s2, $s2, 0x6
        ctx->r18 = ADD32(ctx->r18, 0X6);
            goto L_8002F004;
    }
    // 0x8002EFAC: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x8002EFB0: sll         $t5, $fp, 4
    ctx->r13 = S32(ctx->r30 << 4);
    // 0x8002EFB4: addu        $t5, $t5, $fp
    ctx->r13 = ADD32(ctx->r13, ctx->r30);
    // 0x8002EFB8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002EFBC: addu        $t5, $t5, $fp
    ctx->r13 = ADD32(ctx->r13, ctx->r30);
    // 0x8002EFC0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002EFC4: subu        $t5, $t5, $fp
    ctx->r13 = SUB32(ctx->r13, ctx->r30);
    // 0x8002EFC8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002EFCC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002EFD0: addiu       $t7, $t7, 0x5E0
    ctx->r15 = ADD32(ctx->r15, 0X5E0);
    // 0x8002EFD4: addiu       $t6, $t5, 0x3C
    ctx->r14 = ADD32(ctx->r13, 0X3C);
    // 0x8002EFD8: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
L_8002EFDC:
    // 0x8002EFDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002EFE0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002EFE4: jal         0x80030EA0
    // 0x8002EFE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80030EA0(rdram, ctx);
        goto after_5;
    // 0x8002EFE8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_5:
    // 0x8002EFEC: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
    // 0x8002EFF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002EFF4: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8002EFF8: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002EFFC: bne         $at, $zero, L_8002EFDC
    if (ctx->r1 != 0) {
        // 0x8002F000: addiu       $s2, $s2, 0xA
        ctx->r18 = ADD32(ctx->r18, 0XA);
            goto L_8002EFDC;
    }
    // 0x8002F000: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
L_8002F004:
    // 0x8002F004: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8002F008: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002F00C: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x8002F010: bgezl       $t9, L_8002FA24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002F014: lw          $t9, 0xE0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XE0);
            goto L_8002FA24;
    }
    goto skip_7;
    // 0x8002F014: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    skip_7:
    // 0x8002F018: lhu         $t5, 0x2876($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X2876);
    // 0x8002F01C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F020: andi        $t6, $t5, 0xA000
    ctx->r14 = ctx->r13 & 0XA000;
    // 0x8002F024: beq         $t6, $zero, L_8002F090
    if (ctx->r14 == 0) {
        // 0x8002F028: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002F090;
    }
    // 0x8002F028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F02C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F030: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x8002F034: jal         0x800268D4
    // 0x8002F038: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
    func_800268D4(rdram, ctx);
        goto after_6;
    // 0x8002F038: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
    after_6:
    // 0x8002F03C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002F040: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8002F044: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002F048: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8002F04C: bgez        $t8, L_8002F064
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002F050: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8002F064;
    }
    // 0x8002F050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F054: lb          $t9, 0x15($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X15);
    // 0x8002F058: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002F05C: b           L_8002F070
    // 0x8002F060: sb          $t9, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = ctx->r25;
        goto L_8002F070;
    // 0x8002F060: sb          $t9, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = ctx->r25;
L_8002F064:
    // 0x8002F064: lb          $t5, 0x15($s3)
    ctx->r13 = MEM_B(ctx->r19, 0X15);
    // 0x8002F068: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002F06C: sw          $t5, 0x5C4($at)
    MEM_W(0X5C4, ctx->r1) = ctx->r13;
L_8002F070:
    // 0x8002F070: jal         0x8002E628
    // 0x8002F074: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    func_8002E628(rdram, ctx);
        goto after_7;
    // 0x8002F074: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    after_7:
    // 0x8002F078: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F07C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002F080: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8002F084: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F088: b           L_8002F154
    // 0x8002F08C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
        goto L_8002F154;
    // 0x8002F08C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
L_8002F090:
    // 0x8002F090: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002F094: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x8002F098: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8002F09C: bnel        $at, $zero, L_8002F0E4
    if (ctx->r1 != 0) {
        // 0x8002F0A0: slti        $at, $v0, -0x14
        ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
            goto L_8002F0E4;
    }
    goto skip_8;
    // 0x8002F0A0: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    skip_8:
    // 0x8002F0A4: lbu         $t8, 0x16($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X16);
    // 0x8002F0A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002F0AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F0B0: bne         $t8, $zero, L_8002F130
    if (ctx->r24 != 0) {
        // 0x8002F0B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8002F130;
    }
    // 0x8002F0B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002F0B8: lb          $t9, 0x15($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X15);
    // 0x8002F0BC: sb          $t6, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r14;
    // 0x8002F0C0: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x8002F0C4: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8002F0C8: sb          $t5, 0x15($s3)
    MEM_B(0X15, ctx->r19) = ctx->r13;
    // 0x8002F0CC: jal         0x800268D4
    // 0x8002F0D0: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    func_800268D4(rdram, ctx);
        goto after_8;
    // 0x8002F0D0: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    after_8:
    // 0x8002F0D4: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8002F0D8: b           L_8002F130
    // 0x8002F0DC: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
        goto L_8002F130;
    // 0x8002F0DC: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
    // 0x8002F0E0: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
L_8002F0E4:
    // 0x8002F0E4: beql        $at, $zero, L_8002F12C
    if (ctx->r1 == 0) {
        // 0x8002F0E8: sb          $zero, 0x16($s3)
        MEM_B(0X16, ctx->r19) = 0;
            goto L_8002F12C;
    }
    goto skip_9;
    // 0x8002F0E8: sb          $zero, 0x16($s3)
    MEM_B(0X16, ctx->r19) = 0;
    skip_9:
    // 0x8002F0EC: lbu         $t7, 0x16($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X16);
    // 0x8002F0F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002F0F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F0F8: bne         $t7, $zero, L_8002F130
    if (ctx->r15 != 0) {
        // 0x8002F0FC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8002F130;
    }
    // 0x8002F0FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002F100: lb          $t8, 0x15($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X15);
    // 0x8002F104: sb          $t5, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r13;
    // 0x8002F108: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    // 0x8002F10C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F110: sb          $t9, 0x15($s3)
    MEM_B(0X15, ctx->r19) = ctx->r25;
    // 0x8002F114: jal         0x800268D4
    // 0x8002F118: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    func_800268D4(rdram, ctx);
        goto after_9;
    // 0x8002F118: sw          $a3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r7;
    after_9:
    // 0x8002F11C: lw          $a3, 0x100($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X100);
    // 0x8002F120: b           L_8002F130
    // 0x8002F124: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
        goto L_8002F130;
    // 0x8002F124: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
    // 0x8002F128: sb          $zero, 0x16($s3)
    MEM_B(0X16, ctx->r19) = 0;
L_8002F12C:
    // 0x8002F12C: lh          $v1, 0x38($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X38);
L_8002F130:
    // 0x8002F130: lb          $t4, 0x15($s3)
    ctx->r12 = MEM_B(ctx->r19, 0X15);
    // 0x8002F134: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002F138: bne         $at, $zero, L_8002F148
    if (ctx->r1 != 0) {
        // 0x8002F13C: nop
    
            goto L_8002F148;
    }
    // 0x8002F13C: nop

    // 0x8002F140: b           L_8002F154
    // 0x8002F144: sb          $zero, 0x15($s3)
    MEM_B(0X15, ctx->r19) = 0;
        goto L_8002F154;
    // 0x8002F144: sb          $zero, 0x15($s3)
    MEM_B(0X15, ctx->r19) = 0;
L_8002F148:
    // 0x8002F148: bgez        $t4, L_8002F154
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002F14C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8002F154;
    }
    // 0x8002F14C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8002F150: sb          $t6, 0x15($s3)
    MEM_B(0X15, ctx->r19) = ctx->r14;
L_8002F154:
    // 0x8002F154: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F158: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8002F15C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002F160: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002F164: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F168: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002F16C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F170: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8002F174: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002F178: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002F17C: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8002F180: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002F184: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002F188: lb          $t4, 0x15($s3)
    ctx->r12 = MEM_B(ctx->r19, 0X15);
    // 0x8002F18C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002F190: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8002F194: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8002F198: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002F19C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8002F1A0: lbu         $t9, 0x3C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3C);
    // 0x8002F1A4: beq         $s7, $t9, L_8002F1DC
    if (ctx->r23 == ctx->r25) {
        // 0x8002F1A8: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8002F1DC;
    }
    // 0x8002F1A8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002F1AC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8002F1B0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002F1B4: addu        $v0, $s3, $t5
    ctx->r2 = ADD32(ctx->r19, ctx->r13);
    // 0x8002F1B8: lbu         $v1, 0x3C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3C);
    // 0x8002F1BC: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
L_8002F1C0:
    // 0x8002F1C0: beql        $at, $zero, L_8002F1D0
    if (ctx->r1 == 0) {
        // 0x8002F1C4: lbu         $v1, 0x3D($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X3D);
            goto L_8002F1D0;
    }
    goto skip_10;
    // 0x8002F1C4: lbu         $v1, 0x3D($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3D);
    skip_10:
    // 0x8002F1C8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F1CC: lbu         $v1, 0x3D($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3D);
L_8002F1D0:
    // 0x8002F1D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002F1D4: bnel        $s7, $v1, L_8002F1C0
    if (ctx->r23 != ctx->r3) {
        // 0x8002F1D8: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8002F1C0;
    }
    goto skip_11;
    // 0x8002F1D8: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    skip_11:
L_8002F1DC:
    // 0x8002F1DC: lh          $t6, 0x4($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X4);
    // 0x8002F1E0: lh          $t8, 0x6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X6);
    // 0x8002F1E4: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8002F1E8: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8002F1EC: sll         $t7, $a3, 3
    ctx->r15 = S32(ctx->r7 << 3);
    // 0x8002F1F0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002F1F4: addu        $s4, $t6, $t7
    ctx->r20 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F1F8: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F1FC: addiu       $s4, $s4, 0xA
    ctx->r20 = ADD32(ctx->r20, 0XA);
    // 0x8002F200: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002F204: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F208: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8002F20C: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8002F210: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002F214: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002F218: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F21C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002F220: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F224: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x8002F228: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x8002F22C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002F230: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002F234: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002F238: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002F23C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F240: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8002F244: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002F248: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002F24C: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002F250: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F254: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002F258: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F25C: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8002F260: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002F264: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002F268: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002F26C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002F270: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8002F274: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8002F278: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8002F27C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002F280: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F284: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8002F288: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002F28C: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002F290: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F294: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002F298: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F29C: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8002F2A0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8002F2A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002F2A8: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002F2AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002F2B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002F2B4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F2B8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8002F2BC: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8002F2C0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002F2C4: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002F2C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F2CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002F2D0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F2D4: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8002F2D8: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8002F2DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002F2E0: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002F2E4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002F2E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002F2EC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002F2F0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8002F2F4: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8002F2F8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002F2FC: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002F300: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002F304: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002F308: jal         0x800307D8
    // 0x8002F30C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800307D8(rdram, ctx);
        goto after_10;
    // 0x8002F30C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_10:
    // 0x8002F310: b           L_8002FA24
    // 0x8002F314: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
        goto L_8002FA24;
    // 0x8002F314: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
L_8002F318:
    // 0x8002F318: bgez        $t8, L_8002FA18
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002F31C: sll         $t9, $v0, 4
        ctx->r25 = S32(ctx->r2 << 4);
            goto L_8002FA18;
    }
    // 0x8002F31C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8002F320: bgez        $t9, L_8002F98C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002F324: sll         $t5, $v0, 6
        ctx->r13 = S32(ctx->r2 << 6);
            goto L_8002F98C;
    }
    // 0x8002F324: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x8002F328: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x8002F32C: bgez        $t5, L_8002F4C0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8002F330: lui         $a2, 0x8006
        ctx->r6 = S32(0X8006 << 16);
            goto L_8002F4C0;
    }
    // 0x8002F330: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8002F334: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002F338: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x8002F33C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002F340: sw          $t6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r14;
    // 0x8002F344: andi        $t8, $t7, 0xA000
    ctx->r24 = ctx->r15 & 0XA000;
    // 0x8002F348: beq         $t8, $zero, L_8002F974
    if (ctx->r24 == 0) {
        // 0x8002F34C: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_8002F974;
    }
    // 0x8002F34C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8002F350: sll         $t6, $fp, 4
    ctx->r14 = S32(ctx->r30 << 4);
    // 0x8002F354: addu        $t6, $t6, $fp
    ctx->r14 = ADD32(ctx->r14, ctx->r30);
    // 0x8002F358: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F35C: lhu         $s1, 0x12($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F360: addu        $t6, $t6, $fp
    ctx->r14 = ADD32(ctx->r14, ctx->r30);
    // 0x8002F364: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002F368: lbu         $t9, 0x14($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F36C: subu        $t6, $t6, $fp
    ctx->r14 = SUB32(ctx->r14, ctx->r30);
    // 0x8002F370: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002F374: addiu       $t7, $t7, 0x5E0
    ctx->r15 = ADD32(ctx->r15, 0X5E0);
    // 0x8002F378: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F37C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F380: addu        $t5, $s3, $s1
    ctx->r13 = ADD32(ctx->r19, ctx->r17);
    // 0x8002F384: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F388: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002F38C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8002F390: sb          $t9, 0x9C($t5)
    MEM_B(0X9C, ctx->r13) = ctx->r25;
    // 0x8002F394: lbu         $a0, 0x9C($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X9C);
L_8002F398:
    // 0x8002F398: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8002F39C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8002F3A0: slti        $at, $a0, 0xC0
    ctx->r1 = SIGNED(ctx->r4) < 0XC0 ? 1 : 0;
    // 0x8002F3A4: bne         $at, $zero, L_8002F3D4
    if (ctx->r1 != 0) {
        // 0x8002F3A8: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_8002F3D4;
    }
    // 0x8002F3A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002F3AC: slti        $at, $s2, 0xE0
    ctx->r1 = SIGNED(ctx->r18) < 0XE0 ? 1 : 0;
    // 0x8002F3B0: beq         $at, $zero, L_8002F3D4
    if (ctx->r1 == 0) {
        // 0x8002F3B4: andi        $t8, $a3, 0x1
        ctx->r24 = ctx->r7 & 0X1;
            goto L_8002F3D4;
    }
    // 0x8002F3B4: andi        $t8, $a3, 0x1
    ctx->r24 = ctx->r7 & 0X1;
    // 0x8002F3B8: bne         $t8, $zero, L_8002F3D4
    if (ctx->r24 != 0) {
        // 0x8002F3BC: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8002F3D4;
    }
    // 0x8002F3BC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F3C0: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x8002F3C4: ori         $t5, $a3, 0x1
    ctx->r13 = ctx->r7 | 0X1;
    // 0x8002F3C8: sb          $a0, 0x9C($t9)
    MEM_B(0X9C, ctx->r25) = ctx->r4;
    // 0x8002F3CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F3D0: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
L_8002F3D4:
    // 0x8002F3D4: slti        $at, $s2, 0x80
    ctx->r1 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
    // 0x8002F3D8: bne         $at, $zero, L_8002F404
    if (ctx->r1 != 0) {
        // 0x8002F3DC: slti        $at, $s2, 0xA0
        ctx->r1 = SIGNED(ctx->r18) < 0XA0 ? 1 : 0;
            goto L_8002F404;
    }
    // 0x8002F3DC: slti        $at, $s2, 0xA0
    ctx->r1 = SIGNED(ctx->r18) < 0XA0 ? 1 : 0;
    // 0x8002F3E0: beq         $at, $zero, L_8002F404
    if (ctx->r1 == 0) {
        // 0x8002F3E4: andi        $t6, $a3, 0x2
        ctx->r14 = ctx->r7 & 0X2;
            goto L_8002F404;
    }
    // 0x8002F3E4: andi        $t6, $a3, 0x2
    ctx->r14 = ctx->r7 & 0X2;
    // 0x8002F3E8: bne         $t6, $zero, L_8002F404
    if (ctx->r14 != 0) {
        // 0x8002F3EC: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8002F404;
    }
    // 0x8002F3EC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F3F0: addu        $t7, $t0, $v0
    ctx->r15 = ADD32(ctx->r8, ctx->r2);
    // 0x8002F3F4: ori         $t8, $a3, 0x2
    ctx->r24 = ctx->r7 | 0X2;
    // 0x8002F3F8: sb          $a0, 0x9C($t7)
    MEM_B(0X9C, ctx->r15) = ctx->r4;
    // 0x8002F3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F400: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_8002F404:
    // 0x8002F404: slti        $at, $s2, 0xA0
    ctx->r1 = SIGNED(ctx->r18) < 0XA0 ? 1 : 0;
    // 0x8002F408: bne         $at, $zero, L_8002F434
    if (ctx->r1 != 0) {
        // 0x8002F40C: slti        $at, $s2, 0xB0
        ctx->r1 = SIGNED(ctx->r18) < 0XB0 ? 1 : 0;
            goto L_8002F434;
    }
    // 0x8002F40C: slti        $at, $s2, 0xB0
    ctx->r1 = SIGNED(ctx->r18) < 0XB0 ? 1 : 0;
    // 0x8002F410: beq         $at, $zero, L_8002F434
    if (ctx->r1 == 0) {
        // 0x8002F414: andi        $t9, $a3, 0x4
        ctx->r25 = ctx->r7 & 0X4;
            goto L_8002F434;
    }
    // 0x8002F414: andi        $t9, $a3, 0x4
    ctx->r25 = ctx->r7 & 0X4;
    // 0x8002F418: bne         $t9, $zero, L_8002F434
    if (ctx->r25 != 0) {
        // 0x8002F41C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8002F434;
    }
    // 0x8002F41C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F420: addu        $t5, $t0, $v0
    ctx->r13 = ADD32(ctx->r8, ctx->r2);
    // 0x8002F424: ori         $t6, $a3, 0x4
    ctx->r14 = ctx->r7 | 0X4;
    // 0x8002F428: sb          $a0, 0x9C($t5)
    MEM_B(0X9C, ctx->r13) = ctx->r4;
    // 0x8002F42C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F430: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_8002F434:
    // 0x8002F434: bgezl       $a2, L_8002F398
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8002F438: lbu         $a0, 0x9C($t1)
        ctx->r4 = MEM_BU(ctx->r9, 0X9C);
            goto L_8002F398;
    }
    goto skip_12;
    // 0x8002F438: lbu         $a0, 0x9C($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X9C);
    skip_12:
    // 0x8002F43C: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    // 0x8002F440: addu        $a2, $t0, $a1
    ctx->r6 = ADD32(ctx->r8, ctx->r5);
L_8002F444:
    // 0x8002F444: lbu         $t7, 0x9C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9C);
    // 0x8002F448: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F44C: addu        $t8, $t0, $v0
    ctx->r24 = ADD32(ctx->r8, ctx->r2);
    // 0x8002F450: sb          $t7, 0x9C($t8)
    MEM_B(0X9C, ctx->r24) = ctx->r15;
    // 0x8002F454: lbu         $t9, 0x9D($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X9D);
    // 0x8002F458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F45C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002F460: bne         $s7, $t9, L_8002F444
    if (ctx->r23 != ctx->r25) {
        // 0x8002F464: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002F444;
    }
    // 0x8002F464: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F468: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002F46C: lbu         $t6, 0x9D($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X9D);
    // 0x8002F470: lui         $at, 0xFBFF
    ctx->r1 = S32(0XFBFF << 16);
    // 0x8002F474: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F478: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002F47C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8002F480: sh          $t5, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r13;
    // 0x8002F484: sb          $s5, 0x9D($s3)
    MEM_B(0X9D, ctx->r19) = ctx->r21;
    // 0x8002F488: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8002F48C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002F490: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8002F494: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8002F498: sb          $t6, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r14;
L_8002F49C:
    // 0x8002F49C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002F4A0: sb          $s5, 0x49D($a0)
    MEM_B(0X49D, ctx->r4) = ctx->r21;
    // 0x8002F4A4: sb          $s5, 0x49E($a0)
    MEM_B(0X49E, ctx->r4) = ctx->r21;
    // 0x8002F4A8: sb          $s5, 0x49F($a0)
    MEM_B(0X49F, ctx->r4) = ctx->r21;
    // 0x8002F4AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002F4B0: bne         $s1, $v0, L_8002F49C
    if (ctx->r17 != ctx->r2) {
        // 0x8002F4B4: sb          $s5, 0x498($a0)
        MEM_B(0X498, ctx->r4) = ctx->r21;
            goto L_8002F49C;
    }
    // 0x8002F4B4: sb          $s5, 0x498($a0)
    MEM_B(0X498, ctx->r4) = ctx->r21;
    // 0x8002F4B8: b           L_8002F974
    // 0x8002F4BC: nop

        goto L_8002F974;
    // 0x8002F4BC: nop

L_8002F4C0:
    // 0x8002F4C0: lb          $a2, -0x600($a2)
    ctx->r6 = MEM_B(ctx->r6, -0X600);
    // 0x8002F4C4: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8002F4C8: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8002F4CC: beq         $a2, $zero, L_8002F508
    if (ctx->r6 == 0) {
        // 0x8002F4D0: and         $v1, $t8, $at
        ctx->r3 = ctx->r24 & ctx->r1;
            goto L_8002F508;
    }
    // 0x8002F4D0: and         $v1, $t8, $at
    ctx->r3 = ctx->r24 & ctx->r1;
    // 0x8002F4D4: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8002F4D8: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x8002F4DC: bne         $v1, $zero, L_8002F50C
    if (ctx->r3 != 0) {
        // 0x8002F4E0: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8002F50C;
    }
    // 0x8002F4E0: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002F4E4: lhu         $t9, 0x2876($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2876);
    // 0x8002F4E8: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8002F4EC: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8002F4F0: andi        $t5, $t9, 0xA000
    ctx->r13 = ctx->r25 & 0XA000;
    // 0x8002F4F4: beq         $t5, $zero, L_8002F50C
    if (ctx->r13 == 0) {
        // 0x8002F4F8: nop
    
            goto L_8002F50C;
    }
    // 0x8002F4F8: nop

    // 0x8002F4FC: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002F500: b           L_8002F50C
    // 0x8002F504: and         $v1, $t6, $at
    ctx->r3 = ctx->r14 & ctx->r1;
        goto L_8002F50C;
    // 0x8002F504: and         $v1, $t6, $at
    ctx->r3 = ctx->r14 & ctx->r1;
L_8002F508:
    // 0x8002F508: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
L_8002F50C:
    // 0x8002F50C: bne         $v1, $zero, L_8002F680
    if (ctx->r3 != 0) {
        // 0x8002F510: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002F680;
    }
    // 0x8002F510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002F514: lb          $t5, 0x10($s3)
    ctx->r13 = MEM_B(ctx->r19, 0X10);
    // 0x8002F518: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8002F51C: sb          $t6, 0x10($s3)
    MEM_B(0X10, ctx->r19) = ctx->r14;
    // 0x8002F520: lb          $t7, 0x10($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X10);
    // 0x8002F524: bgtz        $t7, L_8002F974
    if (SIGNED(ctx->r15) > 0) {
        // 0x8002F528: nop
    
            goto L_8002F974;
    }
    // 0x8002F528: nop

    // 0x8002F52C: lhu         $a1, 0x12($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F530: lbu         $t8, 0xF($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0XF);
    // 0x8002F534: lbu         $t5, 0x14($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F538: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8002F53C: sh          $t9, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r25;
    // 0x8002F540: addu        $t6, $s3, $a1
    ctx->r14 = ADD32(ctx->r19, ctx->r5);
    // 0x8002F544: sb          $t8, 0x10($s3)
    MEM_B(0X10, ctx->r19) = ctx->r24;
    // 0x8002F548: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F54C: sb          $t5, 0x9C($t6)
    MEM_B(0X9C, ctx->r14) = ctx->r13;
    // 0x8002F550: lbu         $s2, 0x14($s3)
    ctx->r18 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F554: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F558: lbu         $t8, 0x9C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9C);
    // 0x8002F55C: addiu       $t5, $s2, -0xE1
    ctx->r13 = ADD32(ctx->r18, -0XE1);
    // 0x8002F560: addu        $t9, $s3, $v0
    ctx->r25 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F564: sltiu       $at, $t5, 0x1F
    ctx->r1 = ctx->r13 < 0X1F ? 1 : 0;
    // 0x8002F568: sb          $t8, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r24;
    // 0x8002F56C: beq         $at, $zero, L_8002F620
    if (ctx->r1 == 0) {
        // 0x8002F570: sb          $s5, 0x9C($t9)
        MEM_B(0X9C, ctx->r25) = ctx->r21;
            goto L_8002F620;
    }
    // 0x8002F570: sb          $s5, 0x9C($t9)
    MEM_B(0X9C, ctx->r25) = ctx->r21;
    // 0x8002F574: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002F578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002F57C: addu        $at, $at, $t5
    gpr jr_addend_8002F584 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8002F580: lw          $t5, 0x19D0($at)
    ctx->r13 = ADD32(ctx->r1, 0X19D0);
    // 0x8002F584: jr          $t5
    // 0x8002F588: nop

    switch (jr_addend_8002F584 >> 2) {
        case 0: goto L_8002F600; break;
        case 1: goto L_8002F600; break;
        case 2: goto L_8002F600; break;
        case 3: goto L_8002F600; break;
        case 4: goto L_8002F600; break;
        case 5: goto L_8002F600; break;
        case 6: goto L_8002F600; break;
        case 7: goto L_8002F600; break;
        case 8: goto L_8002F620; break;
        case 9: goto L_8002F620; break;
        case 10: goto L_8002F620; break;
        case 11: goto L_8002F620; break;
        case 12: goto L_8002F620; break;
        case 13: goto L_8002F620; break;
        case 14: goto L_8002F620; break;
        case 15: goto L_8002F5C0; break;
        case 16: goto L_8002F620; break;
        case 17: goto L_8002F58C; break;
        case 18: goto L_8002F620; break;
        case 19: goto L_8002F620; break;
        case 20: goto L_8002F620; break;
        case 21: goto L_8002F620; break;
        case 22: goto L_8002F620; break;
        case 23: goto L_8002F620; break;
        case 24: goto L_8002F620; break;
        case 25: goto L_8002F620; break;
        case 26: goto L_8002F620; break;
        case 27: goto L_8002F620; break;
        case 28: goto L_8002F620; break;
        case 29: goto L_8002F620; break;
        case 30: goto L_8002F5D4; break;
        default: switch_error(__func__, 0x8002F584, 0x800719D0);
    }
    // 0x8002F588: nop

L_8002F58C:
    // 0x8002F58C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F590: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8002F594: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002F598: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F59C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8002F5A0: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x8002F5A4: jal         0x80030668
    // 0x8002F5A8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80030668(rdram, ctx);
        goto after_11;
    // 0x8002F5A8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_11:
    // 0x8002F5AC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002F5B0: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8002F5B4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8002F5B8: b           L_8002F974
    // 0x8002F5BC: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
        goto L_8002F974;
    // 0x8002F5BC: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
L_8002F5C0:
    // 0x8002F5C0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F5C4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F5C8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F5CC: b           L_8002F974
    // 0x8002F5D0: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
        goto L_8002F974;
    // 0x8002F5D0: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
L_8002F5D4:
    // 0x8002F5D4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8002F5D8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8002F5DC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002F5E0: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x8002F5E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F5E8: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002F5EC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x8002F5F0: jal         0x80030D70
    // 0x8002F5F4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    func_80030D70(rdram, ctx);
        goto after_12;
    // 0x8002F5F4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    after_12:
    // 0x8002F5F8: b           L_8002F974
    // 0x8002F5FC: nop

        goto L_8002F974;
    // 0x8002F5FC: nop

L_8002F600:
    // 0x8002F600: andi        $t7, $s2, 0x7
    ctx->r15 = ctx->r18 & 0X7;
    // 0x8002F604: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8002F608: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002F60C: lb          $t8, -0x650($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X650);
    // 0x8002F610: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F614: mflo        $v0
    ctx->r2 = lo;
    // 0x8002F618: sb          $v0, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r2;
    // 0x8002F61C: sb          $v0, 0x10($s3)
    MEM_B(0X10, ctx->r19) = ctx->r2;
L_8002F620:
    // 0x8002F620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F624: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002F628: jal         0x800268D4
    // 0x8002F62C: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    func_800268D4(rdram, ctx);
        goto after_13;
    // 0x8002F62C: andi        $a2, $s5, 0xFF
    ctx->r6 = ctx->r21 & 0XFF;
    after_13:
    // 0x8002F630: slti        $at, $s2, 0x80
    ctx->r1 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
    // 0x8002F634: bne         $at, $zero, L_8002F974
    if (ctx->r1 != 0) {
        // 0x8002F638: nop
    
            goto L_8002F974;
    }
    // 0x8002F638: nop

L_8002F63C:
    // 0x8002F63C: lhu         $a1, 0x12($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F640: lbu         $t5, 0x14($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F644: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8002F648: sh          $t9, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r25;
    // 0x8002F64C: addu        $t6, $s3, $a1
    ctx->r14 = ADD32(ctx->r19, ctx->r5);
    // 0x8002F650: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002F654: sb          $t5, 0x9C($t6)
    MEM_B(0X9C, ctx->r14) = ctx->r13;
    // 0x8002F658: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F65C: lbu         $a0, 0x14($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F660: lbu         $t8, 0x9C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9C);
    // 0x8002F664: addu        $t9, $s3, $v0
    ctx->r25 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F668: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8002F66C: sb          $t8, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r24;
    // 0x8002F670: beq         $at, $zero, L_8002F63C
    if (ctx->r1 == 0) {
        // 0x8002F674: sb          $s5, 0x9C($t9)
        MEM_B(0X9C, ctx->r25) = ctx->r21;
            goto L_8002F63C;
    }
    // 0x8002F674: sb          $s5, 0x9C($t9)
    MEM_B(0X9C, ctx->r25) = ctx->r21;
    // 0x8002F678: b           L_8002F974
    // 0x8002F67C: nop

        goto L_8002F974;
    // 0x8002F67C: nop

L_8002F680:
    // 0x8002F680: lhu         $s1, 0x12($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F684: lbu         $t5, 0x14($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X14);
    // 0x8002F688: sll         $t8, $fp, 4
    ctx->r24 = S32(ctx->r30 << 4);
    // 0x8002F68C: addu        $a1, $s3, $s1
    ctx->r5 = ADD32(ctx->r19, ctx->r17);
    // 0x8002F690: sb          $t5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r13;
    // 0x8002F694: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8002F698: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x8002F69C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F6A0: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x8002F6A4: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8002F6A8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002F6AC: subu        $t8, $t8, $fp
    ctx->r24 = SUB32(ctx->r24, ctx->r30);
    // 0x8002F6B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F6B4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002F6B8: bgez        $a2, L_8002F6C8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8002F6BC: sra         $t6, $a2, 3
        ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
            goto L_8002F6C8;
    }
    // 0x8002F6BC: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002F6C0: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x8002F6C4: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8002F6C8:
    // 0x8002F6C8: addiu       $t5, $t5, 0x5E0
    ctx->r13 = ADD32(ctx->r13, 0X5E0);
    // 0x8002F6CC: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8002F6D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F6D4: sll         $a2, $t6, 2
    ctx->r6 = S32(ctx->r14 << 2);
    // 0x8002F6D8: addu        $a0, $t9, $t5
    ctx->r4 = ADD32(ctx->r25, ctx->r13);
L_8002F6DC:
    // 0x8002F6DC: lbu         $v1, 0x9C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9C);
    // 0x8002F6E0: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x8002F6E4: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x8002F6E8: beql        $t6, $zero, L_8002F778
    if (ctx->r14 == 0) {
        // 0x8002F6EC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002F778;
    }
    goto skip_13;
    // 0x8002F6EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_13:
    // 0x8002F6F0: bnel        $v1, $at, L_8002F80C
    if (ctx->r3 != ctx->r1) {
        // 0x8002F6F4: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8002F80C;
    }
    goto skip_14;
    // 0x8002F6F4: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    skip_14:
    // 0x8002F6F8: lh          $t7, 0x8($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X8);
    // 0x8002F6FC: addiu       $t8, $t7, -0x20
    ctx->r24 = ADD32(ctx->r15, -0X20);
    // 0x8002F700: bgez        $t8, L_8002F710
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002F704: sra         $t9, $t8, 3
        ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
            goto L_8002F710;
    }
    // 0x8002F704: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8002F708: addiu       $at, $t8, 0x7
    ctx->r1 = ADD32(ctx->r24, 0X7);
    // 0x8002F70C: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8002F710:
    // 0x8002F710: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x8002F714: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F718: beq         $at, $zero, L_8002F728
    if (ctx->r1 == 0) {
        // 0x8002F71C: subu        $v0, $v0, $a3
        ctx->r2 = SUB32(ctx->r2, ctx->r7);
            goto L_8002F728;
    }
    // 0x8002F71C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8002F720: b           L_8002F72C
    // 0x8002F724: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
        goto L_8002F72C;
    // 0x8002F724: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
L_8002F728:
    // 0x8002F728: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8002F72C:
    // 0x8002F72C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F730: bnel        $at, $zero, L_8002F80C
    if (ctx->r1 != 0) {
        // 0x8002F734: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8002F80C;
    }
    goto skip_15;
    // 0x8002F734: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    skip_15:
    // 0x8002F738: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8002F73C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F740: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F744: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002F748: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002F74C: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F750: lbu         $t8, 0x9C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9C);
    // 0x8002F754: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F758: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F75C: sb          $t8, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r24;
    // 0x8002F760: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F764: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F768: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8002F76C: b           L_8002F8D0
    // 0x8002F770: sh          $t5, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r13;
        goto L_8002F8D0;
    // 0x8002F770: sh          $t5, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r13;
    // 0x8002F774: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002F778:
    // 0x8002F778: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F77C: bnel        $at, $zero, L_8002F7C4
    if (ctx->r1 != 0) {
        // 0x8002F780: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002F7C4;
    }
    goto skip_16;
    // 0x8002F780: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    skip_16:
    // 0x8002F784: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F788: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F78C: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F790: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F794: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8002F798: addu        $t8, $s3, $v0
    ctx->r24 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F79C: lbu         $t9, 0x9C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9C);
    // 0x8002F7A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F7A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F7A8: sb          $t9, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r25;
    // 0x8002F7AC: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F7B0: lhu         $t5, 0x12($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F7B4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002F7B8: b           L_8002F8D0
    // 0x8002F7BC: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
        goto L_8002F8D0;
    // 0x8002F7BC: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
    // 0x8002F7C0: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002F7C4:
    // 0x8002F7C4: beql        $at, $zero, L_8002F80C
    if (ctx->r1 == 0) {
        // 0x8002F7C8: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8002F80C;
    }
    goto skip_17;
    // 0x8002F7C8: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    skip_17:
    // 0x8002F7CC: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F7D0: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F7D4: lbu         $t8, 0x9C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9C);
    // 0x8002F7D8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F7DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F7E0: sb          $t8, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r24;
    // 0x8002F7E4: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F7E8: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F7EC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F7F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F7F4: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8002F7F8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F7FC: sh          $t5, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r13;
    // 0x8002F800: b           L_8002F8D0
    // 0x8002F804: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
        goto L_8002F8D0;
    // 0x8002F804: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8002F808: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
L_8002F80C:
    // 0x8002F80C: bnel        $v1, $at, L_8002F844
    if (ctx->r3 != ctx->r1) {
        // 0x8002F810: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_8002F844;
    }
    goto skip_18;
    // 0x8002F810: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    skip_18:
    // 0x8002F814: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F818: addu        $t8, $s3, $v0
    ctx->r24 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F81C: lbu         $t9, 0x9C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9C);
    // 0x8002F820: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F824: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F828: sb          $t9, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r25;
    // 0x8002F82C: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F830: lhu         $t5, 0x12($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F834: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002F838: b           L_8002F8D0
    // 0x8002F83C: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
        goto L_8002F8D0;
    // 0x8002F83C: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
    // 0x8002F840: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
L_8002F844:
    // 0x8002F844: bne         $v1, $at, L_8002F888
    if (ctx->r3 != ctx->r1) {
        // 0x8002F848: nop
    
            goto L_8002F888;
    }
    // 0x8002F848: nop

    // 0x8002F84C: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F850: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F854: lbu         $t8, 0x9C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9C);
    // 0x8002F858: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F85C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F860: sb          $t8, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r24;
    // 0x8002F864: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F868: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8002F86C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002F870: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F874: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8002F878: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002F87C: sh          $t5, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r13;
    // 0x8002F880: b           L_8002F8D0
    // 0x8002F884: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
        goto L_8002F8D0;
    // 0x8002F884: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
L_8002F888:
    // 0x8002F888: bnel        $s7, $v1, L_8002F8B8
    if (ctx->r23 != ctx->r3) {
        // 0x8002F88C: lhu         $t5, 0x12($s3)
        ctx->r13 = MEM_HU(ctx->r19, 0X12);
            goto L_8002F8B8;
    }
    goto skip_19;
    // 0x8002F88C: lhu         $t5, 0x12($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X12);
    skip_19:
    // 0x8002F890: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x8002F894: addu        $t8, $s3, $v0
    ctx->r24 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F898: lbu         $t9, 0x9C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9C);
    // 0x8002F89C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F8A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F8A4: sb          $t9, 0x14($s3)
    MEM_B(0X14, ctx->r19) = ctx->r25;
    // 0x8002F8A8: sb          $s5, 0x9C($a1)
    MEM_B(0X9C, ctx->r5) = ctx->r21;
    // 0x8002F8AC: b           L_8002F8D0
    // 0x8002F8B0: sb          $s5, 0x9D($a1)
    MEM_B(0X9D, ctx->r5) = ctx->r21;
        goto L_8002F8D0;
    // 0x8002F8B0: sb          $s5, 0x9D($a1)
    MEM_B(0X9D, ctx->r5) = ctx->r21;
    // 0x8002F8B4: lhu         $t5, 0x12($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X12);
L_8002F8B8:
    // 0x8002F8B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002F8BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002F8C0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002F8C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F8C8: b           L_8002F6DC
    // 0x8002F8CC: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
        goto L_8002F6DC;
    // 0x8002F8CC: sh          $t6, 0x12($s3)
    MEM_H(0X12, ctx->r19) = ctx->r14;
L_8002F8D0:
    // 0x8002F8D0: lbu         $v1, 0x9B($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9B);
    // 0x8002F8D4: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8002F8D8: beq         $v1, $at, L_8002F928
    if (ctx->r3 == ctx->r1) {
        // 0x8002F8DC: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8002F928;
    }
    // 0x8002F8DC: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x8002F8E0: beq         $v1, $at, L_8002F8F8
    if (ctx->r3 == ctx->r1) {
        // 0x8002F8E4: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002F8F8;
    }
    // 0x8002F8E4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002F8E8: beql        $v1, $s7, L_8002F940
    if (ctx->r3 == ctx->r23) {
        // 0x8002F8EC: lw          $t9, 0x0($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X0);
            goto L_8002F940;
    }
    goto skip_20;
    // 0x8002F8EC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    skip_20:
    // 0x8002F8F0: b           L_8002F964
    // 0x8002F8F4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
        goto L_8002F964;
    // 0x8002F8F4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8002F8F8:
    // 0x8002F8F8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002F8FC: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8002F900: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F904: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002F908: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8002F90C: jal         0x80030668
    // 0x8002F910: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    func_80030668(rdram, ctx);
        goto after_14;
    // 0x8002F910: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    after_14:
    // 0x8002F914: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8002F918: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8002F91C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002F920: b           L_8002F960
    // 0x8002F924: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
        goto L_8002F960;
    // 0x8002F924: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
L_8002F928:
    // 0x8002F928: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002F92C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002F930: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002F934: b           L_8002F960
    // 0x8002F938: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
        goto L_8002F960;
    // 0x8002F938: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8002F93C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
L_8002F940:
    // 0x8002F940: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8002F944: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8002F948: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x8002F94C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F950: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x8002F954: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8002F958: jal         0x80030D70
    // 0x8002F95C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    func_80030D70(rdram, ctx);
        goto after_15;
    // 0x8002F95C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    after_15:
L_8002F960:
    // 0x8002F960: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8002F964:
    // 0x8002F964: lui         $at, 0xFFEF
    ctx->r1 = S32(0XFFEF << 16);
    // 0x8002F968: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F96C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002F970: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
L_8002F974:
    // 0x8002F974: jal         0x80030068
    // 0x8002F978: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80030068(rdram, ctx);
        goto after_16;
    // 0x8002F978: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_16:
    // 0x8002F97C: jal         0x8002FD90
    // 0x8002F980: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FD90(rdram, ctx);
        goto after_17;
    // 0x8002F980: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_17:
    // 0x8002F984: b           L_8002FA24
    // 0x8002F988: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
        goto L_8002FA24;
    // 0x8002F988: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
L_8002F98C:
    // 0x8002F98C: bgez        $t5, L_8002FA20
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8002F990: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8002FA20;
    }
    // 0x8002F990: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002F994: lhu         $t6, 0x2876($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2876);
    // 0x8002F998: andi        $t7, $t6, 0xA000
    ctx->r15 = ctx->r14 & 0XA000;
    // 0x8002F99C: bnel        $t7, $zero, L_8002F9B4
    if (ctx->r15 != 0) {
        // 0x8002F9A0: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002F9B4;
    }
    goto skip_21;
    // 0x8002F9A0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    skip_21:
    // 0x8002F9A4: jal         0x80030D80
    // 0x8002F9A8: nop

    func_80030D80(rdram, ctx);
        goto after_18;
    // 0x8002F9A8: nop

    after_18:
    // 0x8002F9AC: beq         $v0, $zero, L_8002F9D0
    if (ctx->r2 == 0) {
        // 0x8002F9B0: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002F9D0;
    }
    // 0x8002F9B0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8002F9B4:
    // 0x8002F9B4: jal         0x8002E628
    // 0x8002F9B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002E628(rdram, ctx);
        goto after_19;
    // 0x8002F9B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8002F9BC: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8002F9C0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002F9C4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002F9C8: b           L_8002FA20
    // 0x8002F9CC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
        goto L_8002FA20;
    // 0x8002F9CC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
L_8002F9D0:
    // 0x8002F9D0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002F9D4: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x8002F9D8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002F9DC: sll         $t5, $v0, 13
    ctx->r13 = S32(ctx->r2 << 13);
    // 0x8002F9E0: bgez        $t5, L_8002FA08
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8002F9E4: and         $t6, $v0, $at
        ctx->r14 = ctx->r2 & ctx->r1;
            goto L_8002FA08;
    }
    // 0x8002F9E4: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8002F9E8: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002F9EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002F9F0: jal         0x8002E628
    // 0x8002F9F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002E628(rdram, ctx);
        goto after_20;
    // 0x8002F9F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8002F9F8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002F9FC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8002FA00: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002FA04: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
L_8002FA08:
    // 0x8002FA08: jal         0x8002FD90
    // 0x8002FA0C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FD90(rdram, ctx);
        goto after_21;
    // 0x8002FA0C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_21:
    // 0x8002FA10: b           L_8002FA24
    // 0x8002FA14: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
        goto L_8002FA24;
    // 0x8002FA14: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
L_8002FA18:
    // 0x8002FA18: jal         0x8002FD90
    // 0x8002FA1C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8002FD90(rdram, ctx);
        goto after_22;
    // 0x8002FA1C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_22:
L_8002FA20:
    // 0x8002FA20: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
L_8002FA24:
    // 0x8002FA24: beql        $t9, $zero, L_8002FA38
    if (ctx->r25 == 0) {
        // 0x8002FA28: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_8002FA38;
    }
    goto skip_22;
    // 0x8002FA28: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_22:
    // 0x8002FA2C: jal         0x800303E8
    // 0x8002FA30: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_800303E8(rdram, ctx);
        goto after_23;
    // 0x8002FA30: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_23:
L_8002FA34:
    // 0x8002FA34: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_8002FA38:
    // 0x8002FA38: addiu       $t7, $sp, 0xF0
    ctx->r15 = ADD32(ctx->r29, 0XF0);
    // 0x8002FA3C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x8002FA40: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002FA44: bne         $t6, $t7, L_8002ECD8
    if (ctx->r14 != ctx->r15) {
        // 0x8002FA48: sw          $t6, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r14;
            goto L_8002ECD8;
    }
    // 0x8002FA48: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002FA4C: beq         $t8, $zero, L_8002FA9C
    if (ctx->r24 == 0) {
        // 0x8002FA50: sll         $t9, $fp, 4
        ctx->r25 = S32(ctx->r30 << 4);
            goto L_8002FA9C;
    }
    // 0x8002FA50: sll         $t9, $fp, 4
    ctx->r25 = S32(ctx->r30 << 4);
    // 0x8002FA54: addu        $t9, $t9, $fp
    ctx->r25 = ADD32(ctx->r25, ctx->r30);
    // 0x8002FA58: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002FA5C: addu        $t9, $t9, $fp
    ctx->r25 = ADD32(ctx->r25, ctx->r30);
    // 0x8002FA60: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002FA64: subu        $t9, $t9, $fp
    ctx->r25 = SUB32(ctx->r25, ctx->r30);
    // 0x8002FA68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002FA6C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002FA70: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8002FA74: lw          $t5, 0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5E0);
    // 0x8002FA78: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8002FA7C: bgez        $t6, L_8002FA94
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002FA80: nop
    
            goto L_8002FA94;
    }
    // 0x8002FA80: nop

    // 0x8002FA84: jal         0x8002E768
    // 0x8002FA88: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    func_8002E768(rdram, ctx);
        goto after_24;
    // 0x8002FA88: addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    after_24:
    // 0x8002FA8C: b           L_8002FAA0
    // 0x8002FA90: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
        goto L_8002FAA0;
    // 0x8002FA90: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
L_8002FA94:
    // 0x8002FA94: jal         0x8002E768
    // 0x8002FA98: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8002E768(rdram, ctx);
        goto after_25;
    // 0x8002FA98: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_25:
L_8002FA9C:
    // 0x8002FA9C: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
L_8002FAA0:
    // 0x8002FAA0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002FAA4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8002FAA8: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x8002FAAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002FAB0: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8002FAB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002FAB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002FABC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002FAC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002FAC4: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8002FAC8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002FACC: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8002FAD0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002FAD4: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x8002FAD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002FADC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8002FAE0: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8002FAE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002FAE8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002FAEC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8002FAF0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002FAF4: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8002FAF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002FAFC: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8002FB00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002FB04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002FB08: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002FB0C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002FB10: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FB14: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002FB18: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002FB1C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002FB20: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FB24: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002FB28: jr          $ra
    // 0x8002FB2C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8002FB2C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_800177F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800177FC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80017800: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80017804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80017808: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001780C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80017810: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80017814: lhu         $a3, 0x3A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3A);
    // 0x80017818: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8001781C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x80017820: andi        $t3, $a3, 0xFF
    ctx->r11 = ctx->r7 & 0XFF;
    // 0x80017824: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80017828: beq         $v0, $zero, L_80017850
    if (ctx->r2 == 0) {
        // 0x8001782C: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80017850;
    }
    // 0x8001782C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80017830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017834: beq         $v0, $at, L_8001787C
    if (ctx->r2 == ctx->r1) {
        // 0x80017838: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8001787C;
    }
    // 0x80017838: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8001783C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80017840: beq         $v0, $at, L_800178A4
    if (ctx->r2 == ctx->r1) {
        // 0x80017844: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_800178A4;
    }
    // 0x80017844: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80017848: b           L_800178BC
    // 0x8001784C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
        goto L_800178BC;
    // 0x8001784C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_80017850:
    // 0x80017850: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80017854: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80017858: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x8001785C: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80017860: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80017864: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80017868: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001786C: nop

    // 0x80017870: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80017874: b           L_800178C4
    // 0x80017878: nop

        goto L_800178C4;
    // 0x80017878: nop

L_8001787C:
    // 0x8001787C: lw          $t8, 0x64($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X64);
    // 0x80017880: lwc1        $f18, 0x24($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80017884: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80017888: lwc1        $f16, 0x1C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8001788C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80017890: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80017894: nop

    // 0x80017898: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001789C: b           L_800178C4
    // 0x800178A0: nop

        goto L_800178C4;
    // 0x800178A0: nop

L_800178A4:
    // 0x800178A4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800178A8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800178AC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800178B0: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800178B4: b           L_800178C8
    // 0x800178B8: lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X2);
        goto L_800178C8;
    // 0x800178B8: lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X2);
L_800178BC:
    // 0x800178BC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800178C0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_800178C4:
    // 0x800178C4: lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X2);
L_800178C8:
    // 0x800178C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800178CC: lhu         $t4, 0x3E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3E);
    // 0x800178D0: beql        $v0, $zero, L_800178F4
    if (ctx->r2 == 0) {
        // 0x800178D4: lw          $t0, 0x64($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X64);
            goto L_800178F4;
    }
    goto skip_0;
    // 0x800178D4: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    skip_0:
    // 0x800178D8: beq         $v0, $at, L_80017914
    if (ctx->r2 == ctx->r1) {
        // 0x800178DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80017914;
    }
    // 0x800178DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800178E0: beql        $v0, $at, L_8001793C
    if (ctx->r2 == ctx->r1) {
        // 0x800178E4: lwc1        $f4, 0x8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
            goto L_8001793C;
    }
    goto skip_1;
    // 0x800178E4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800178E8: b           L_80017950
    // 0x800178EC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
        goto L_80017950;
    // 0x800178EC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800178F0: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
L_800178F4:
    // 0x800178F4: lwc1        $f18, 0x24($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800178F8: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800178FC: lwc1        $f16, 0x18($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80017900: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80017904: nop

    // 0x80017908: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001790C: b           L_80017950
    // 0x80017910: nop

        goto L_80017950;
    // 0x80017910: nop

L_80017914:
    // 0x80017914: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x80017918: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8001791C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80017920: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80017924: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80017928: nop

    // 0x8001792C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80017930: b           L_80017950
    // 0x80017934: nop

        goto L_80017950;
    // 0x80017934: nop

    // 0x80017938: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_8001793C:
    // 0x8001793C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80017940: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80017944: b           L_80017954
    // 0x80017948: lhu         $a0, 0x8($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X8);
        goto L_80017954;
    // 0x80017948: lhu         $a0, 0x8($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X8);
    // 0x8001794C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
L_80017950:
    // 0x80017950: lhu         $a0, 0x8($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X8);
L_80017954:
    // 0x80017954: lhu         $a1, 0x4($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X4);
    // 0x80017958: lhu         $a2, 0x6($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X6);
    // 0x8001795C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80017960: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80017964: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80017968: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8001796C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80017970: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80017974: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80017978: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8001797C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80017980: jal         0x8001A268
    // 0x80017984: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_8001A268(rdram, ctx);
        goto after_0;
    // 0x80017984: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80017988: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001798C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80017990: jr          $ra
    // 0x80017994: nop

    return;
    // 0x80017994: nop

;}
RECOMP_FUNC void func_80023A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023A0C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80023A10: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80023A14: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80023A18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023A1C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80023A20: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80023A24: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80023A28: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80023A2C: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80023A30: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80023A34: jal         0x80034F60
    // 0x80023A38: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80023A38: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80023A3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80023A40: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80023A44: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80023A48: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80023A4C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80023A50: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80023A54: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80023A58: bc1tl       L_80023A70
    if (c1cs) {
        // 0x80023A5C: c.le.s      $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
            goto L_80023A70;
    }
    goto skip_0;
    // 0x80023A5C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    skip_0:
    // 0x80023A60: div.s       $f22, $f20, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80023A64: b           L_80023AA4
    // 0x80023A68: div.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
        goto L_80023AA4;
    // 0x80023A68: div.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80023A6C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
L_80023A70:
    // 0x80023A70: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x80023A74: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80023A78: bc1fl       L_80023A98
    if (!c1cs) {
        // 0x80023A7C: mtc1        $at, $f5
        ctx->f_odd[(5 - 1) * 2] = ctx->r1;
            goto L_80023A98;
    }
    goto skip_1;
    // 0x80023A7C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    skip_1:
    // 0x80023A80: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80023A84: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80023A88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023A8C: b           L_80023AA4
    // 0x80023A90: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
        goto L_80023AA4;
    // 0x80023A90: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80023A94: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
L_80023A98:
    // 0x80023A98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023A9C: nop

    // 0x80023AA0: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
L_80023AA4:
    // 0x80023AA4: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80023AA8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80023AAC: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80023AB0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80023AB4: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80023AB8: jal         0x80034F60
    // 0x80023ABC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80023ABC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x80023AC0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023AC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80023AC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023ACC: div.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80023AD0: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023AD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023AD8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80023ADC: neg.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = -ctx->f22.fl;
    // 0x80023AE0: mul.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80023AE4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80023AE8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80023AEC: nop

    // 0x80023AF0: mul.s       $f10, $f12, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80023AF4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023AF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023AFC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80023B00: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80023B04: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x80023B08: div.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80023B0C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80023B10: nop

    // 0x80023B14: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80023B18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023B1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80023B20: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80023B24: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80023B28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80023B2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023B30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023B34: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80023B38: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023B3C: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80023B40: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80023B44: nop

    // 0x80023B48: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80023B4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80023B54: mul.s       $f10, $f16, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80023B58: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023B5C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80023B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023B64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023B68: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80023B6C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80023B70: nop

    // 0x80023B74: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80023B78: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80023B7C: mul.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80023B80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80023B84: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80023B88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023B8C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80023B90: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023B94: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80023B98: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x80023B9C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80023BA0: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x80023BA4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80023BA8: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x80023BAC: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x80023BB0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80023BB4: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80023BB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023BBC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80023BC0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80023BC4: jr          $ra
    // 0x80023BC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023BC8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8010009C_DC16BC_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010009C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x801000A0: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x801000A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801000A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801000AC: bne         $a2, $at, L_801000C4
    if (ctx->r6 != ctx->r1) {
        // 0x801000B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801000C4;
    }
    // 0x801000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801000B4: jal         0x801051B4
    // 0x801000B8: nop

    func_801051B4_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x801000B8: nop

    after_0:
    // 0x801000BC: b           L_80100624
    // 0x801000C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x801000C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801000C4:
    // 0x801000C4: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x801000C8: lbu         $t6, -0x53A4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X53A4);
    // 0x801000CC: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x801000D0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801000D4: bne         $t6, $zero, L_80100278
    if (ctx->r14 != 0) {
        // 0x801000D8: addiu       $v1, $v1, -0x53A8
        ctx->r3 = ADD32(ctx->r3, -0X53A8);
            goto L_80100278;
    }
    // 0x801000D8: addiu       $v1, $v1, -0x53A8
    ctx->r3 = ADD32(ctx->r3, -0X53A8);
    // 0x801000DC: lbu         $v0, 0x6208($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6208);
    // 0x801000E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801000E4: beq         $v0, $zero, L_8010010C
    if (ctx->r2 == 0) {
        // 0x801000E8: nop
    
            goto L_8010010C;
    }
    // 0x801000E8: nop

    // 0x801000EC: beq         $v0, $at, L_80100218
    if (ctx->r2 == ctx->r1) {
        // 0x801000F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80100218;
    }
    // 0x801000F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801000F4: beq         $v0, $at, L_80100238
    if (ctx->r2 == ctx->r1) {
        // 0x801000F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80100238;
    }
    // 0x801000F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801000FC: beq         $v0, $at, L_80100258
    if (ctx->r2 == ctx->r1) {
        // 0x80100100: nop
    
            goto L_80100258;
    }
    // 0x80100100: nop

    // 0x80100104: b           L_80100624
    // 0x80100108: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x80100108: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8010010C:
    // 0x8010010C: jal         0x80031574
    // 0x80100110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80031574(rdram, ctx);
        goto after_1;
    // 0x80100110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80100114: jal         0x80031BB0
    // 0x80100118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x80100118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8010011C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80100120: beq         $v0, $at, L_80100188
    if (ctx->r2 == ctx->r1) {
        // 0x80100124: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80100188;
    }
    // 0x80100124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80100128: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8010012C: beq         $v0, $at, L_80100188
    if (ctx->r2 == ctx->r1) {
        // 0x80100130: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80100188;
    }
    // 0x80100130: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80100134: beq         $v0, $at, L_80100188
    if (ctx->r2 == ctx->r1) {
        // 0x80100138: lui         $t7, 0x8009
        ctx->r15 = S32(0X8009 << 16);
            goto L_80100188;
    }
    // 0x80100138: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8010013C: lb          $t7, 0x2870($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X2870);
    // 0x80100140: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80100144: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80100148: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8010014C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80100150: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80100154: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80100158: lh          $t9, 0x2A38($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2A38);
    // 0x8010015C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80100160: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80100164: andi        $t0, $t9, 0x2000
    ctx->r8 = ctx->r25 & 0X2000;
    // 0x80100168: beq         $t0, $zero, L_80100180
    if (ctx->r8 == 0) {
        // 0x8010016C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80100180;
    }
    // 0x8010016C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80100170: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100174: sb          $t1, 0x6208($at)
    MEM_B(0X6208, ctx->r1) = ctx->r9;
    // 0x80100178: b           L_80100624
    // 0x8010017C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x8010017C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100180:
    // 0x80100180: b           L_80100624
    // 0x80100184: sb          $t2, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r10;
        goto L_80100624;
    // 0x80100184: sb          $t2, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r10;
L_80100188:
    // 0x80100188: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8010018C: addiu       $a0, $a0, 0x61F0
    ctx->r4 = ADD32(ctx->r4, 0X61F0);
    // 0x80100190: jal         0x8003A7BC
    // 0x80100194: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80100194: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x80100198: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8010019C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x801001A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801001A4: beq         $a1, $at, L_8010020C
    if (ctx->r5 == ctx->r1) {
        // 0x801001A8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8010020C;
    }
    // 0x801001A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801001AC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x801001B0: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x801001B4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x801001B8: addiu       $t4, $t4, 0x2898
    ctx->r12 = ADD32(ctx->r12, 0X2898);
    // 0x801001BC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x801001C0: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x801001C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801001C8: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x801001CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801001D0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x801001D4: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    // 0x801001D8: jal         0x8003A4BC
    // 0x801001DC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x801001DC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x801001E0: bne         $v0, $zero, L_801001FC
    if (ctx->r2 != 0) {
        // 0x801001E4: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_801001FC;
    }
    // 0x801001E4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801001E8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801001EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801001F0: sb          $t5, 0x6208($at)
    MEM_B(0X6208, ctx->r1) = ctx->r13;
    // 0x801001F4: b           L_80100624
    // 0x801001F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x801001F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801001FC:
    // 0x801001FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100200: sb          $t6, 0x6208($at)
    MEM_B(0X6208, ctx->r1) = ctx->r14;
    // 0x80100204: b           L_80100624
    // 0x80100208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x80100208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8010020C:
    // 0x8010020C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80100210: b           L_80100624
    // 0x80100214: sb          $t7, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r15;
        goto L_80100624;
    // 0x80100214: sb          $t7, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r15;
L_80100218:
    // 0x80100218: jal         0x8010541C
    // 0x8010021C: nop

    func_8010541C_ovl_intro(rdram, ctx);
        goto after_5;
    // 0x8010021C: nop

    after_5:
    // 0x80100220: beq         $v0, $zero, L_80100270
    if (ctx->r2 == 0) {
        // 0x80100224: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80100270;
    }
    // 0x80100224: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80100228: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8010022C: sb          $t8, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r24;
    // 0x80100230: b           L_80100624
    // 0x80100234: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x80100234: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100238:
    // 0x80100238: jal         0x80104874
    // 0x8010023C: nop

    func_80104874_ovl_intro(rdram, ctx);
        goto after_6;
    // 0x8010023C: nop

    after_6:
    // 0x80100240: beq         $v0, $zero, L_80100270
    if (ctx->r2 == 0) {
        // 0x80100244: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80100270;
    }
    // 0x80100244: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80100248: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8010024C: sb          $t9, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r25;
    // 0x80100250: b           L_80100624
    // 0x80100254: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x80100254: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100258:
    // 0x80100258: jal         0x8010575C
    // 0x8010025C: nop

    func_8010575C_ovl_intro(rdram, ctx);
        goto after_7;
    // 0x8010025C: nop

    after_7:
    // 0x80100260: beq         $v0, $zero, L_80100270
    if (ctx->r2 == 0) {
        // 0x80100264: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80100270;
    }
    // 0x80100264: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80100268: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8010026C: sb          $t0, -0x53A4($at)
    MEM_B(-0X53A4, ctx->r1) = ctx->r8;
L_80100270:
    // 0x80100270: b           L_80100624
    // 0x80100274: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80100624;
    // 0x80100274: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100278:
    // 0x80100278: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8010027C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80100280: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80100284: bne         $v0, $zero, L_80100294
    if (ctx->r2 != 0) {
        // 0x80100288: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80100294;
    }
    // 0x80100288: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8010028C: b           L_80100620
    // 0x80100290: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
        goto L_80100620;
    // 0x80100290: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
L_80100294:
    // 0x80100294: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100298: lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6210);
    // 0x8010029C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x801002A0: beq         $at, $zero, L_80100620
    if (ctx->r1 == 0) {
        // 0x801002A4: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_80100620;
    }
    // 0x801002A4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x801002A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801002AC: addu        $at, $at, $t3
    gpr jr_addend_801002B4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801002B0: lw          $t3, 0x61FC($at)
    ctx->r11 = ADD32(ctx->r1, 0X61FC);
    // 0x801002B4: jr          $t3
    // 0x801002B8: nop

    switch (jr_addend_801002B4 >> 2) {
        case 0: goto L_801002BC; break;
        case 1: goto L_80100304; break;
        case 2: goto L_801003AC; break;
        case 3: goto L_80100454; break;
        case 4: goto L_801004FC; break;
        case 5: goto L_80100530; break;
        default: switch_error(__func__, 0x801002B4, 0x801661FC);
    }
    // 0x801002B8: nop

L_801002BC:
    // 0x801002BC: jal         0x801030E0
    // 0x801002C0: nop

    func_801030E0_ovl_intro(rdram, ctx);
        goto after_8;
    // 0x801002C0: nop

    after_8:
    // 0x801002C4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801002C8: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x801002CC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801002D0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x801002D4: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x801002D8: bne         $t4, $zero, L_80100620
    if (ctx->r12 != 0) {
        // 0x801002DC: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80100620;
    }
    // 0x801002DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801002E0: lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6210);
    // 0x801002E4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801002E8: sw          $zero, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = 0;
    // 0x801002EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801002F0: sw          $zero, 0x6224($at)
    MEM_W(0X6224, ctx->r1) = 0;
    // 0x801002F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801002F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801002FC: b           L_80100620
    // 0x80100300: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
        goto L_80100620;
    // 0x80100300: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
L_80100304:
    // 0x80100304: jal         0x8010324C
    // 0x80100308: nop

    func_8010324C_ovl_intro(rdram, ctx);
        goto after_9;
    // 0x80100308: nop

    after_9:
    // 0x8010030C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80100310: lhu         $t6, 0x2876($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2876);
    // 0x80100314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100318: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8010031C: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80100320: beq         $t7, $zero, L_80100348
    if (ctx->r15 == 0) {
        // 0x80100324: nop
    
            goto L_80100348;
    }
    // 0x80100324: nop

    // 0x80100328: jal         0x80025B8C
    // 0x8010032C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_10;
    // 0x8010032C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_10:
    // 0x80100330: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80100334: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x80100338: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8010033C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80100340: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100344: sb          $t8, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = ctx->r24;
L_80100348:
    // 0x80100348: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8010034C: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x80100350: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80100354: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80100358: bnel        $t9, $zero, L_80100624
    if (ctx->r25 != 0) {
        // 0x8010035C: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_80100624;
    }
    goto skip_0;
    // 0x8010035C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80100360: lbu         $t0, 0x620C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X620C);
    // 0x80100364: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100368: sw          $zero, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = 0;
    // 0x8010036C: beq         $t0, $zero, L_80100388
    if (ctx->r8 == 0) {
        // 0x80100370: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_80100388;
    }
    // 0x80100370: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100374: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80100378: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010037C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80100380: b           L_801003A0
    // 0x80100384: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
        goto L_801003A0;
    // 0x80100384: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80100388:
    // 0x80100388: lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6210);
    // 0x8010038C: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x80100390: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80100394: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100398: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8010039C: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
L_801003A0:
    // 0x801003A0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801003A4: b           L_80100620
    // 0x801003A8: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
        goto L_80100620;
    // 0x801003A8: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
L_801003AC:
    // 0x801003AC: jal         0x801033B8
    // 0x801003B0: nop

    func_801033B8_ovl_intro(rdram, ctx);
        goto after_11;
    // 0x801003B0: nop

    after_11:
    // 0x801003B4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x801003B8: lhu         $t4, 0x2876($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2876);
    // 0x801003BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801003C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801003C4: andi        $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 & 0X1000;
    // 0x801003C8: beq         $t5, $zero, L_801003F0
    if (ctx->r13 == 0) {
        // 0x801003CC: nop
    
            goto L_801003F0;
    }
    // 0x801003CC: nop

    // 0x801003D0: jal         0x80025B8C
    // 0x801003D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_12;
    // 0x801003D4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_12:
    // 0x801003D8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801003DC: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x801003E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801003E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801003E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801003EC: sb          $t6, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = ctx->r14;
L_801003F0:
    // 0x801003F0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801003F4: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x801003F8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801003FC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80100400: bnel        $t7, $zero, L_80100624
    if (ctx->r15 != 0) {
        // 0x80100404: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_80100624;
    }
    goto skip_1;
    // 0x80100404: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80100408: lbu         $t8, 0x620C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X620C);
    // 0x8010040C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100410: sw          $zero, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = 0;
    // 0x80100414: beq         $t8, $zero, L_80100430
    if (ctx->r24 == 0) {
        // 0x80100418: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_80100430;
    }
    // 0x80100418: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8010041C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80100420: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80100424: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100428: b           L_80100448
    // 0x8010042C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
        goto L_80100448;
    // 0x8010042C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80100430:
    // 0x80100430: lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6210);
    // 0x80100434: addiu       $t1, $zero, 0x2D
    ctx->r9 = ADD32(0, 0X2D);
    // 0x80100438: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8010043C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100440: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80100444: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
L_80100448:
    // 0x80100448: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010044C: b           L_80100620
    // 0x80100450: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
        goto L_80100620;
    // 0x80100450: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
L_80100454:
    // 0x80100454: jal         0x80103524
    // 0x80100458: nop

    func_80103524_ovl_intro(rdram, ctx);
        goto after_13;
    // 0x80100458: nop

    after_13:
    // 0x8010045C: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80100460: lhu         $t2, 0x2876($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2876);
    // 0x80100464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100468: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8010046C: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x80100470: beq         $t3, $zero, L_80100498
    if (ctx->r11 == 0) {
        // 0x80100474: nop
    
            goto L_80100498;
    }
    // 0x80100474: nop

    // 0x80100478: jal         0x80025B8C
    // 0x8010047C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_14;
    // 0x8010047C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_14:
    // 0x80100480: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80100484: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x80100488: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8010048C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80100490: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100494: sb          $t4, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = ctx->r12;
L_80100498:
    // 0x80100498: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8010049C: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x801004A0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801004A4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x801004A8: bnel        $t5, $zero, L_80100624
    if (ctx->r13 != 0) {
        // 0x801004AC: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_80100624;
    }
    goto skip_2;
    // 0x801004AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801004B0: lbu         $t6, 0x620C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X620C);
    // 0x801004B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801004B8: sw          $zero, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = 0;
    // 0x801004BC: beq         $t6, $zero, L_801004D8
    if (ctx->r14 == 0) {
        // 0x801004C0: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_801004D8;
    }
    // 0x801004C0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x801004C4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801004C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801004CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801004D0: b           L_801004F0
    // 0x801004D4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_801004F0;
    // 0x801004D4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_801004D8:
    // 0x801004D8: lw          $v1, 0x6210($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6210);
    // 0x801004DC: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x801004E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801004E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801004E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801004EC: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
L_801004F0:
    // 0x801004F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801004F4: b           L_80100620
    // 0x801004F8: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
        goto L_80100620;
    // 0x801004F8: sb          $zero, 0x620C($at)
    MEM_B(0X620C, ctx->r1) = 0;
L_801004FC:
    // 0x801004FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80100500: addiu       $v0, $v0, 0x6200
    ctx->r2 = ADD32(ctx->r2, 0X6200);
    // 0x80100504: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80100508: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8010050C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80100510: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80100514: bne         $t1, $zero, L_80100620
    if (ctx->r9 != 0) {
        // 0x80100518: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_80100620;
    }
    // 0x80100518: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8010051C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100520: jal         0x800267B8
    // 0x80100524: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
    UpdateBGM(rdram, ctx);
        goto after_15;
    // 0x80100524: sw          $v1, 0x6210($at)
    MEM_W(0X6210, ctx->r1) = ctx->r3;
    after_15:
    // 0x80100528: b           L_80100624
    // 0x8010052C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80100624;
    // 0x8010052C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80100530:
    // 0x80100530: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80100534: lw          $a3, 0x6204($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6204);
    // 0x80100538: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8010053C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80100540: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80100544: andi        $t4, $a3, 0x1
    ctx->r12 = ctx->r7 & 0X1;
    // 0x80100548: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8010054C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x80100550: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80100554: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80100558: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8010055C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80100560: sb          $t3, -0x53AC($at)
    MEM_B(-0X53AC, ctx->r1) = ctx->r11;
    // 0x80100564: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80100568: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8010056C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x80100570: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80100574: addiu       $t7, $t7, -0x6ED0
    ctx->r15 = ADD32(ctx->r15, -0X6ED0);
    // 0x80100578: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8010057C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100580: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80100584: sw          $t5, 0x4CB0($at)
    MEM_W(0X4CB0, ctx->r1) = ctx->r13;
    // 0x80100588: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8010058C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80100590: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100594: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80100598: addiu       $t1, $t1, 0x6240
    ctx->r9 = ADD32(ctx->r9, 0X6240);
    // 0x8010059C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801005A0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x801005A4: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x801005A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801005AC: jal         0x80100634
    // 0x801005B0: sw          $t4, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = ctx->r12;
    func_80100634_ovl_intro(rdram, ctx);
        goto after_16;
    // 0x801005B0: sw          $t4, 0x6204($at)
    MEM_W(0X6204, ctx->r1) = ctx->r12;
    after_16:
    // 0x801005B4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x801005B8: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x801005BC: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x801005C0: lw          $a3, 0x6204($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6204);
    // 0x801005C4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801005C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801005CC: lui         $t2, 0xB800
    ctx->r10 = S32(0XB800 << 16);
    // 0x801005D0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801005D4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801005D8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x801005DC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801005E0: lw          $t3, 0x4CB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4CB0);
    // 0x801005E4: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x801005E8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801005EC: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x801005F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801005F4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801005F8: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x801005FC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80100600: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80100604: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80100608: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x8010060C: addiu       $t7, $t7, -0x6ED0
    ctx->r15 = ADD32(ctx->r15, -0X6ED0);
    // 0x80100610: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80100614: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80100618: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8010061C: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
L_80100620:
    // 0x80100620: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80100624:
    // 0x80100624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010062C: jr          $ra
    // 0x80100630: nop

    return;
    // 0x80100630: nop

;}
RECOMP_FUNC void func_80028624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028624: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x80028628: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002862C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80028630: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80028634: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80028638: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8002863C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80028640: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80028644: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x80028648: addiu       $t1, $zero, -0x8
    ctx->r9 = ADD32(0, -0X8);
    // 0x8002864C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80028650: lb          $t6, -0xD88($t6)
    ctx->r14 = MEM_B(ctx->r14, -0XD88);
    // 0x80028654: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x80028658: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002865C: beq         $t1, $t6, L_800286E8
    if (ctx->r9 == ctx->r14) {
        // 0x80028660: addiu       $s5, $zero, -0x1
        ctx->r21 = ADD32(0, -0X1);
            goto L_800286E8;
    }
    // 0x80028660: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80028664: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80028668: addiu       $v0, $t7, -0xD88
    ctx->r2 = ADD32(ctx->r15, -0XD88);
    // 0x8002866C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80028670: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80028674: addiu       $t0, $t0, 0x4EE8
    ctx->r8 = ADD32(ctx->r8, 0X4EE8);
    // 0x80028678: lw          $a1, 0x4EE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4EE4);
    // 0x8002867C: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x80028680: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80028684: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
L_80028688:
    // 0x80028688: beql        $v1, $a2, L_800286A4
    if (ctx->r3 == ctx->r6) {
        // 0x8002868C: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800286A4;
    }
    goto skip_0;
    // 0x8002868C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    skip_0:
    // 0x80028690: beql        $v1, $a3, L_800286B4
    if (ctx->r3 == ctx->r7) {
        // 0x80028694: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800286B4;
    }
    goto skip_1;
    // 0x80028694: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    skip_1:
    // 0x80028698: b           L_800286C0
    // 0x8002869C: nop

        goto L_800286C0;
    // 0x8002869C: nop

    // 0x800286A0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800286A4:
    // 0x800286A4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800286A8: b           L_800286C0
    // 0x800286AC: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
        goto L_800286C0;
    // 0x800286AC: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x800286B0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800286B4:
    // 0x800286B4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800286B8: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800286BC: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
L_800286C0:
    // 0x800286C0: bnel        $a1, $v1, L_800286DC
    if (ctx->r5 != ctx->r3) {
        // 0x800286C4: lb          $v1, 0x2($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X2);
            goto L_800286DC;
    }
    goto skip_2;
    // 0x800286C4: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    skip_2:
    // 0x800286C8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800286CC: lb          $t9, 0x1($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1);
    // 0x800286D0: beql        $t8, $t9, L_800286EC
    if (ctx->r24 == ctx->r25) {
        // 0x800286D4: slti        $at, $s4, 0x6
        ctx->r1 = SIGNED(ctx->r20) < 0X6 ? 1 : 0;
            goto L_800286EC;
    }
    goto skip_3;
    // 0x800286D4: slti        $at, $s4, 0x6
    ctx->r1 = SIGNED(ctx->r20) < 0X6 ? 1 : 0;
    skip_3:
    // 0x800286D8: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
L_800286DC:
    // 0x800286DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800286E0: bne         $t1, $v1, L_80028688
    if (ctx->r9 != ctx->r3) {
        // 0x800286E4: nop
    
            goto L_80028688;
    }
    // 0x800286E4: nop

L_800286E8:
    // 0x800286E8: slti        $at, $s4, 0x6
    ctx->r1 = SIGNED(ctx->r20) < 0X6 ? 1 : 0;
L_800286EC:
    // 0x800286EC: beq         $at, $zero, L_80028A6C
    if (ctx->r1 == 0) {
        // 0x800286F0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80028A6C;
    }
    // 0x800286F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800286F4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800286F8: lw          $t6, -0x6D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D8);
    // 0x800286FC: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80028700: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x80028704: beq         $s4, $t6, L_80028734
    if (ctx->r20 == ctx->r14) {
        // 0x80028708: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80028734;
    }
    // 0x80028708: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002870C: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80028710: addiu       $t8, $t8, -0x7D4
    ctx->r24 = ADD32(ctx->r24, -0X7D4);
    // 0x80028714: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80028718: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8002871C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80028720: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80028724: jal         0x80024260
    // 0x80028728: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80028728: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    after_0:
    // 0x8002872C: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80028730: sw          $s4, -0x6D8($at)
    MEM_W(-0X6D8, ctx->r1) = ctx->r20;
L_80028734:
    // 0x80028734: lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X130);
    // 0x80028738: addiu       $t0, $zero, 0xF4
    ctx->r8 = ADD32(0, 0XF4);
    // 0x8002873C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80028740: addiu       $s0, $s0, 0x27
    ctx->r16 = ADD32(ctx->r16, 0X27);
    // 0x80028744: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80028748: bgez        $s0, L_8002877C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002874C: addiu       $s3, $zero, 0x1D
        ctx->r19 = ADD32(0, 0X1D);
            goto L_8002877C;
    }
    // 0x8002874C: addiu       $s3, $zero, 0x1D
    ctx->r19 = ADD32(0, 0X1D);
    // 0x80028750: addiu       $t6, $s0, 0xF4
    ctx->r14 = ADD32(ctx->r16, 0XF4);
    // 0x80028754: bgez        $t6, L_80028764
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80028758: negu        $t7, $v0
        ctx->r15 = SUB32(0, ctx->r2);
            goto L_80028764;
    }
    // 0x80028758: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x8002875C: b           L_8002877C
    // 0x80028760: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8002877C;
    // 0x80028760: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80028764:
    // 0x80028764: sw          $t7, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r15;
    // 0x80028768: addiu       $t9, $zero, 0xF4
    ctx->r25 = ADD32(0, 0XF4);
    // 0x8002876C: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x80028770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028774: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x80028778: sw          $t6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r14;
L_8002877C:
    // 0x8002877C: slti        $at, $v0, 0x141
    ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x80028780: bne         $at, $zero, L_80028790
    if (ctx->r1 != 0) {
        // 0x80028784: addu        $t7, $v0, $t0
        ctx->r15 = ADD32(ctx->r2, ctx->r8);
            goto L_80028790;
    }
    // 0x80028784: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x80028788: b           L_800287A8
    // 0x8002878C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_800287A8;
    // 0x8002878C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80028790:
    // 0x80028790: slti        $at, $t7, 0x141
    ctx->r1 = SIGNED(ctx->r15) < 0X141 ? 1 : 0;
    // 0x80028794: bne         $at, $zero, L_800287A8
    if (ctx->r1 != 0) {
        // 0x80028798: subu        $t9, $t0, $v0
        ctx->r25 = SUB32(ctx->r8, ctx->r2);
            goto L_800287A8;
    }
    // 0x80028798: subu        $t9, $t0, $v0
    ctx->r25 = SUB32(ctx->r8, ctx->r2);
    // 0x8002879C: subu        $t0, $t9, $t0
    ctx->r8 = SUB32(ctx->r25, ctx->r8);
    // 0x800287A0: addiu       $t0, $t0, 0x140
    ctx->r8 = ADD32(ctx->r8, 0X140);
    // 0x800287A4: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
L_800287A8:
    // 0x800287A8: beq         $s2, $zero, L_80029188
    if (ctx->r18 == 0) {
        // 0x800287AC: sw          $v0, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r2;
            goto L_80029188;
    }
    // 0x800287AC: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x800287B0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800287B4: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x800287B8: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x800287BC: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x800287C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800287C4: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800287C8: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x800287CC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800287D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800287D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800287D8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x800287DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800287E0: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x800287E4: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800287E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800287EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800287F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800287F4: lw          $t8, -0xA5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XA5C);
    // 0x800287F8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800287FC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80028800: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80028804: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028808: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8002880C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80028810: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028814: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028818: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002881C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80028820: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028824: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80028828: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8002882C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028830: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028834: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028838: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002883C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028840: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80028844: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80028848: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002884C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028850: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028854: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028858: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002885C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80028860: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80028864: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028868: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002886C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028870: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028874: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028878: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8002887C: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x80028880: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028884: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028888: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002888C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028890: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80028894: addiu       $t6, $t6, -0xA44
    ctx->r14 = ADD32(ctx->r14, -0XA44);
    // 0x80028898: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8002889C: addu        $t7, $ra, $t0
    ctx->r15 = ADD32(ctx->r31, ctx->r8);
    // 0x800288A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800288A4: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800288A8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800288AC: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800288B0: sll         $t9, $ra, 2
    ctx->r25 = S32(ctx->r31 << 2);
    // 0x800288B4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800288B8: lw          $t9, 0x11C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X11C);
    // 0x800288BC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800288C0: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800288C4: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800288C8: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800288CC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800288D0: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800288D4:
    // 0x800288D4: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x800288D8: bnel        $t4, $at, L_800288E8
    if (ctx->r12 != ctx->r1) {
        // 0x800288DC: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_800288E8;
    }
    goto skip_4;
    // 0x800288DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x800288E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800288E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_800288E8:
    // 0x800288E8: lui         $t7, 0xFD48
    ctx->r15 = S32(0XFD48 << 16);
    // 0x800288EC: ori         $t7, $t7, 0xF3
    ctx->r15 = ctx->r15 | 0XF3;
    // 0x800288F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800288F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800288F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800288FC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80028900: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80028904: addiu       $t0, $s2, -0x1
    ctx->r8 = ADD32(ctx->r18, -0X1);
    // 0x80028908: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002890C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028910: ori         $t6, $t6, 0x3E00
    ctx->r14 = ctx->r14 | 0X3E00;
    // 0x80028914: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80028918: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002891C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028920: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028924: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028928: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002892C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80028930: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x80028934: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028938: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002893C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028940: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028944: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028948: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8002894C: lui         $at, 0x73C
    ctx->r1 = S32(0X73C << 16);
    // 0x80028950: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028954: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028958: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8002895C: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80028960: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80028964: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028968: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002896C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028970: lui         $at, 0x3C
    ctx->r1 = S32(0X3C << 16);
    // 0x80028974: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80028978: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002897C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028980: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028984: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028988: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002898C: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x80028990: ori         $t8, $t8, 0x3E00
    ctx->r24 = ctx->r24 | 0X3E00;
    // 0x80028994: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028998: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002899C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800289A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800289A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800289A8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800289AC: or          $t9, $t0, $at
    ctx->r25 = ctx->r8 | ctx->r1;
    // 0x800289B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800289B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800289B8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800289BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800289C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800289C4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800289C8: addu        $s0, $s3, $s2
    ctx->r16 = ADD32(ctx->r19, ctx->r18);
    // 0x800289CC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800289D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800289D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800289D8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800289DC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800289E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800289E4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800289E8: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x800289EC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800289F0: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800289F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800289F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800289FC: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80028A00: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80028A04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028A08: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028A0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80028A10: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80028A14: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80028A18: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80028A1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028A20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028A24: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80028A28: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80028A2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028A30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028A34: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028A38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028A3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028A40: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x80028A44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028A48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028A4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028A50: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028A54: bne         $t4, $at, L_800288D4
    if (ctx->r12 != ctx->r1) {
        // 0x80028A58: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800288D4;
    }
    // 0x80028A58: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80028A5C: jal         0x8002DF6C
    // 0x80028A60: nop

    func_8002DF6C(rdram, ctx);
        goto after_1;
    // 0x80028A60: nop

    after_1:
    // 0x80028A64: b           L_8002918C
    // 0x80028A68: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
        goto L_8002918C;
    // 0x80028A68: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
L_80028A6C:
    // 0x80028A6C: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80028A70: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80028A74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80028A78: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80028A7C: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80028A80: jal         0x80029B58
    // 0x80028A84: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x80028A84: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
    // 0x80028A88: lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X130);
    // 0x80028A8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80028A90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028A94: addiu       $s0, $s0, 0x29
    ctx->r16 = ADD32(ctx->r16, 0X29);
    // 0x80028A98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028A9C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80028AA0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80028AA4: jal         0x80029B58
    // 0x80028AA8: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x80028AA8: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    after_3:
    // 0x80028AAC: addiu       $t7, $zero, 0xB1
    ctx->r15 = ADD32(0, 0XB1);
    // 0x80028AB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80028AB4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80028AB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028ABC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80028AC0: jal         0x80029B58
    // 0x80028AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x80028AC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80028AC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80028ACC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80028AD0: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80028AD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028AD8: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x80028ADC: jal         0x80029B58
    // 0x80028AE0: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x80028AE0: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    after_5:
    // 0x80028AE4: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80028AE8: addiu       $t8, $zero, 0xB2
    ctx->r24 = ADD32(0, 0XB2);
    // 0x80028AEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80028AF0: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80028AF4: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80028AF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80028AFC: jal         0x80029B58
    // 0x80028B00: addiu       $a1, $a1, 0x117
    ctx->r5 = ADD32(ctx->r5, 0X117);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x80028B00: addiu       $a1, $a1, 0x117
    ctx->r5 = ADD32(ctx->r5, 0X117);
    after_6:
    // 0x80028B04: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80028B08: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80028B0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028B10: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028B14: addiu       $a2, $zero, 0xD4
    ctx->r6 = ADD32(0, 0XD4);
    // 0x80028B18: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80028B1C: jal         0x80029B58
    // 0x80028B20: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x80028B20: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_7:
    // 0x80028B24: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80028B28: addiu       $t7, $zero, 0xB2
    ctx->r15 = ADD32(0, 0XB2);
    // 0x80028B2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80028B30: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028B34: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    // 0x80028B38: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80028B3C: jal         0x80029B58
    // 0x80028B40: addiu       $a1, $a1, 0x11A
    ctx->r5 = ADD32(ctx->r5, 0X11A);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x80028B40: addiu       $a1, $a1, 0x11A
    ctx->r5 = ADD32(ctx->r5, 0X11A);
    after_8:
    // 0x80028B44: lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X130);
    // 0x80028B48: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80028B4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80028B50: addiu       $s0, $s0, 0x27
    ctx->r16 = ADD32(ctx->r16, 0X27);
    // 0x80028B54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028B58: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028B5C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80028B60: jal         0x80029B58
    // 0x80028B64: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x80028B64: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_9:
    // 0x80028B68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028B6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80028B70: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028B74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028B78: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // 0x80028B7C: jal         0x80029B58
    // 0x80028B80: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x80028B80: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_10:
    // 0x80028B84: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80028B88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028B8C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028B90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80028B94: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80028B98: jal         0x80029B58
    // 0x80028B9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x80028B9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80028BA0: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80028BA4: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x80028BA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80028BAC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80028BB0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80028BB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80028BB8: jal         0x80029B58
    // 0x80028BBC: addiu       $a1, $a1, 0x119
    ctx->r5 = ADD32(ctx->r5, 0X119);
    func_80029B58(rdram, ctx);
        goto after_12;
    // 0x80028BBC: addiu       $a1, $a1, 0x119
    ctx->r5 = ADD32(ctx->r5, 0X119);
    after_12:
    // 0x80028BC0: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80028BC4: lw          $t9, -0x6D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6D8);
    // 0x80028BC8: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80028BCC: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x80028BD0: beq         $s4, $t9, L_80028C00
    if (ctx->r20 == ctx->r25) {
        // 0x80028BD4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80028C00;
    }
    // 0x80028BD4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80028BD8: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80028BDC: addiu       $t6, $t6, -0x7D4
    ctx->r14 = ADD32(ctx->r14, -0X7D4);
    // 0x80028BE0: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80028BE4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80028BE8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80028BEC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80028BF0: jal         0x80024260
    // 0x80028BF4: subu        $a2, $t7, $a0
    ctx->r6 = SUB32(ctx->r15, ctx->r4);
    dma_write(rdram, ctx);
        goto after_13;
    // 0x80028BF4: subu        $a2, $t7, $a0
    ctx->r6 = SUB32(ctx->r15, ctx->r4);
    after_13:
    // 0x80028BF8: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x80028BFC: sw          $s4, -0x6D8($at)
    MEM_W(-0X6D8, ctx->r1) = ctx->r20;
L_80028C00:
    // 0x80028C00: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x80028C04: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80028C08: addiu       $t8, $t8, -0x72C
    ctx->r24 = ADD32(ctx->r24, -0X72C);
    // 0x80028C0C: subu        $t9, $t9, $s4
    ctx->r25 = SUB32(ctx->r25, ctx->r20);
    // 0x80028C10: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80028C14: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x80028C18: addiu       $t7, $t7, -0x720
    ctx->r15 = ADD32(ctx->r15, -0X720);
    // 0x80028C1C: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80028C20: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80028C24: lh          $t9, -0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X18);
    // 0x80028C28: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x80028C2C: lbu         $t0, -0x12($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X12);
    // 0x80028C30: lbu         $s2, -0x11($v0)
    ctx->r18 = MEM_BU(ctx->r2, -0X11);
    // 0x80028C34: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x80028C38: bgez        $a0, L_80028C68
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80028C3C: lh          $s3, -0x16($v1)
        ctx->r19 = MEM_H(ctx->r3, -0X16);
            goto L_80028C68;
    }
    // 0x80028C3C: lh          $s3, -0x16($v1)
    ctx->r19 = MEM_H(ctx->r3, -0X16);
    // 0x80028C40: addu        $t6, $a0, $t0
    ctx->r14 = ADD32(ctx->r4, ctx->r8);
    // 0x80028C44: bgez        $t6, L_80028C54
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80028C48: negu        $t7, $a0
        ctx->r15 = SUB32(0, ctx->r4);
            goto L_80028C54;
    }
    // 0x80028C48: negu        $t7, $a0
    ctx->r15 = SUB32(0, ctx->r4);
    // 0x80028C4C: b           L_80028C68
    // 0x80028C50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80028C68;
    // 0x80028C50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80028C54:
    // 0x80028C54: sw          $t7, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r15;
    // 0x80028C58: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80028C5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80028C60: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x80028C64: sw          $t8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r24;
L_80028C68:
    // 0x80028C68: slti        $at, $a0, 0x141
    ctx->r1 = SIGNED(ctx->r4) < 0X141 ? 1 : 0;
    // 0x80028C6C: bne         $at, $zero, L_80028C7C
    if (ctx->r1 != 0) {
        // 0x80028C70: addu        $t6, $a0, $t0
        ctx->r14 = ADD32(ctx->r4, ctx->r8);
            goto L_80028C7C;
    }
    // 0x80028C70: addu        $t6, $a0, $t0
    ctx->r14 = ADD32(ctx->r4, ctx->r8);
    // 0x80028C74: b           L_80028C94
    // 0x80028C78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80028C94;
    // 0x80028C78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80028C7C:
    // 0x80028C7C: slti        $at, $t6, 0x141
    ctx->r1 = SIGNED(ctx->r14) < 0X141 ? 1 : 0;
    // 0x80028C80: bne         $at, $zero, L_80028C94
    if (ctx->r1 != 0) {
        // 0x80028C84: subu        $t7, $t0, $a0
        ctx->r15 = SUB32(ctx->r8, ctx->r4);
            goto L_80028C94;
    }
    // 0x80028C84: subu        $t7, $t0, $a0
    ctx->r15 = SUB32(ctx->r8, ctx->r4);
    // 0x80028C88: subu        $t0, $t7, $t0
    ctx->r8 = SUB32(ctx->r15, ctx->r8);
    // 0x80028C8C: addiu       $t0, $t0, 0x140
    ctx->r8 = ADD32(ctx->r8, 0X140);
    // 0x80028C90: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
L_80028C94:
    // 0x80028C94: beq         $s2, $zero, L_80029188
    if (ctx->r18 == 0) {
        // 0x80028C98: sw          $a0, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r4;
            goto L_80029188;
    }
    // 0x80028C98: sw          $a0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r4;
    // 0x80028C9C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80028CA0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80028CA4: lui         $s1, 0xE700
    ctx->r17 = S32(0XE700 << 16);
    // 0x80028CA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028CAC: addiu       $a1, $s4, -0x6
    ctx->r5 = ADD32(ctx->r20, -0X6);
    // 0x80028CB0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80028CB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028CB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028CBC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80028CC0: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80028CC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80028CC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028CCC: lw          $t7, -0x75C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X75C);
    // 0x80028CD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028CD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028CD8: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80028CDC: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x80028CE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028CE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028CE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028CEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028CF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028CF4: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x80028CF8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80028CFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028D00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028D04: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028D08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80028D0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028D10: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80028D14: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80028D18: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028D1C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028D20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028D24: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028D28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028D2C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x80028D30: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80028D34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028D38: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028D3C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80028D40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028D44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028D48: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80028D4C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028D50: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028D54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028D58: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028D5C: lhu         $t7, -0x2F4($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2F4);
    // 0x80028D60: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80028D64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80028D68: andi        $t9, $t7, 0xFFEF
    ctx->r25 = ctx->r15 & 0XFFEF;
    // 0x80028D6C: sh          $t9, -0x2F4($at)
    MEM_H(-0X2F4, ctx->r1) = ctx->r25;
    // 0x80028D70: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80028D74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028D78: addiu       $t7, $t7, -0x72C
    ctx->r15 = ADD32(ctx->r15, -0X72C);
    // 0x80028D7C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80028D80: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80028D84: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80028D88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028D8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028D90: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80028D94: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80028D98: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80028D9C: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80028DA0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80028DA4: addiu       $t8, $t8, -0x74C
    ctx->r24 = ADD32(ctx->r24, -0X74C);
    // 0x80028DA8: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80028DAC: addu        $s0, $t9, $t8
    ctx->r16 = ADD32(ctx->r25, ctx->r24);
    // 0x80028DB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80028DB4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80028DB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028DBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028DC0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80028DC4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80028DC8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028DCC: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80028DD0: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80028DD4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028DD8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80028DDC: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x80028DE0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80028DE4: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80028DE8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028DEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028DF0: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80028DF4: lui         $ra, 0xF548
    ctx->r31 = S32(0XF548 << 16);
    // 0x80028DF8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x80028DFC: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80028E00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028E04: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80028E08: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028E0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028E10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028E14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028E18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028E1C: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x80028E20: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80028E24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028E28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028E2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028E30: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80028E34: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80028E38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80028E3C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80028E40: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80028E44: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80028E48: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80028E4C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80028E50: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80028E54: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80028E58: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80028E5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028E60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028E64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028E68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028E6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028E70: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028E74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028E78: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80028E7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028E80: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80028E84: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80028E88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028E8C: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x80028E90: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x80028E94: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x80028E98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028E9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028EA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028EA4: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80028EA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028EAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028EB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028EB4: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x80028EB8: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80028EBC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80028EC0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80028EC4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80028EC8: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80028ECC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80028ED0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80028ED4: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80028ED8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80028EDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028EE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028EE4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028EE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028EEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028EF0: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028EF4: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80028EF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028EFC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80028F00: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80028F04: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80028F08: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x80028F0C: addu        $t9, $s3, $s2
    ctx->r25 = ADD32(ctx->r19, ctx->r18);
    // 0x80028F10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028F14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028F18: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80028F1C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80028F20: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x80028F24: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80028F28: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028F2C: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80028F30: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80028F34: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80028F38: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80028F3C: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80028F40: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80028F44: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80028F48: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80028F4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028F50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028F54: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80028F58: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80028F5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028F60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028F64: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028F68: lw          $t7, 0x11C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X11C);
    // 0x80028F6C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80028F70: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80028F74: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028F78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028F7C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80028F80: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80028F84: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028F88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028F8C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80028F90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028F94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028F98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80028F9C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028FA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80028FA4: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80028FA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028FAC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80028FB0: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80028FB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80028FB8: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80028FBC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80028FC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80028FC4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80028FC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80028FCC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80028FD0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80028FD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80028FD8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80028FDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028FE0: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x80028FE4: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80028FE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028FEC: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x80028FF0: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x80028FF4: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x80028FF8: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80028FFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029000: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029004: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029008: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8002900C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029010: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029014: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029018: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002901C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029020: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x80029024: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80029028: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002902C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029030: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80029034: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x80029038: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x8002903C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80029040: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80029044: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80029048: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8002904C: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80029050: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80029054: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80029058: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8002905C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80029060: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029064: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029068: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002906C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029070: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029074: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80029078: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002907C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80029080: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029084: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80029088: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8002908C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029090: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80029094: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x80029098: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x8002909C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800290A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800290A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800290A8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800290AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800290B0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800290B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800290B8: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x800290BC: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800290C0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800290C4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800290C8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800290CC: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800290D0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800290D4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800290D8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800290DC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800290E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800290E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800290E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800290EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800290F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800290F4: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x800290F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800290FC: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x80029100: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80029104: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029108: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x8002910C: addu        $t9, $t6, $s2
    ctx->r25 = ADD32(ctx->r14, ctx->r18);
    // 0x80029110: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029114: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80029118: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002911C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80029120: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x80029124: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029128: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8002912C: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x80029130: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80029134: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80029138: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8002913C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80029140: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029144: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029148: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8002914C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80029150: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029154: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029158: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002915C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80029160: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029164: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029168: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8002916C: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80029170: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029174: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029178: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002917C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80029180: jal         0x8002DF6C
    // 0x80029184: nop

    func_8002DF6C(rdram, ctx);
        goto after_14;
    // 0x80029184: nop

    after_14:
L_80029188:
    // 0x80029188: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
L_8002918C:
    // 0x8002918C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80029190: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029194: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80029198: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8002919C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x800291A0: jal         0x80029B58
    // 0x800291A4: addiu       $a1, $a1, 0x45
    ctx->r5 = ADD32(ctx->r5, 0X45);
    func_80029B58(rdram, ctx);
        goto after_15;
    // 0x800291A4: addiu       $a1, $a1, 0x45
    ctx->r5 = ADD32(ctx->r5, 0X45);
    after_15:
    // 0x800291A8: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x800291AC: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800291B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800291B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800291B8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x800291BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x800291C0: jal         0x80029B58
    // 0x800291C4: addiu       $a1, $a1, 0xF3
    ctx->r5 = ADD32(ctx->r5, 0XF3);
    func_80029B58(rdram, ctx);
        goto after_16;
    // 0x800291C4: addiu       $a1, $a1, 0xF3
    ctx->r5 = ADD32(ctx->r5, 0XF3);
    after_16:
    // 0x800291C8: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800291CC: addiu       $s1, $s1, -0x2F0
    ctx->r17 = ADD32(ctx->r17, -0X2F0);
    // 0x800291D0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800291D4: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x800291D8: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x800291DC: sra         $t6, $s0, 2
    ctx->r14 = S32(SIGNED(ctx->r16) >> 2);
    // 0x800291E0: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x800291E4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800291E8: lb          $s0, -0xF40($at)
    ctx->r16 = MEM_B(ctx->r1, -0XF40);
    // 0x800291EC: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800291F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800291F4: addu        $a1, $t7, $s0
    ctx->r5 = ADD32(ctx->r15, ctx->r16);
    // 0x800291F8: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    // 0x800291FC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80029200: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80029204: jal         0x80029B58
    // 0x80029208: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_17;
    // 0x80029208: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_17:
    // 0x8002920C: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x80029210: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80029214: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80029218: subu        $a1, $t6, $s0
    ctx->r5 = SUB32(ctx->r14, ctx->r16);
    // 0x8002921C: addiu       $a1, $a1, 0xFB
    ctx->r5 = ADD32(ctx->r5, 0XFB);
    // 0x80029220: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80029224: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80029228: jal         0x80029B58
    // 0x8002922C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x8002922C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_18:
    // 0x80029230: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80029234: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80029238: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002923C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x80029240: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80029244: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    // 0x80029248: jal         0x80029B58
    // 0x8002924C: addiu       $a1, $a1, 0x8E
    ctx->r5 = ADD32(ctx->r5, 0X8E);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x8002924C: addiu       $a1, $a1, 0x8E
    ctx->r5 = ADD32(ctx->r5, 0X8E);
    after_19:
    // 0x80029250: slti        $at, $s4, 0x6
    ctx->r1 = SIGNED(ctx->r20) < 0X6 ? 1 : 0;
    // 0x80029254: beq         $at, $zero, L_8002937C
    if (ctx->r1 == 0) {
        // 0x80029258: nop
    
            goto L_8002937C;
    }
    // 0x80029258: nop

    // 0x8002925C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80029260: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x80029264: beq         $t6, $zero, L_8002937C
    if (ctx->r14 == 0) {
        // 0x80029268: nop
    
            goto L_8002937C;
    }
    // 0x80029268: nop

    // 0x8002926C: bgez        $s5, L_80029328
    if (SIGNED(ctx->r21) >= 0) {
        // 0x80029270: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_80029328;
    }
    // 0x80029270: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80029274: addiu       $a1, $a1, -0x4548
    ctx->r5 = ADD32(ctx->r5, -0X4548);
    // 0x80029278: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8002927C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80029280: addiu       $t7, $t7, -0x804
    ctx->r15 = ADD32(ctx->r15, -0X804);
    // 0x80029284: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80029288: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002928C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x80029290: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80029294: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80029298: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8002929C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800292A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800292A4: div         $zero, $t0, $t8
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r24)));
    // 0x800292A8: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x800292AC: bne         $t8, $zero, L_800292B8
    if (ctx->r24 != 0) {
        // 0x800292B0: nop
    
            goto L_800292B8;
    }
    // 0x800292B0: nop

    // 0x800292B4: break       7
    do_break(2147652276);
L_800292B8:
    // 0x800292B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800292BC: bne         $t8, $at, L_800292D0
    if (ctx->r24 != ctx->r1) {
        // 0x800292C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800292D0;
    }
    // 0x800292C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800292C4: bne         $t0, $at, L_800292D0
    if (ctx->r8 != ctx->r1) {
        // 0x800292C8: nop
    
            goto L_800292D0;
    }
    // 0x800292C8: nop

    // 0x800292CC: break       6
    do_break(2147652300);
L_800292D0:
    // 0x800292D0: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    // 0x800292D4: mflo        $t0
    ctx->r8 = lo;
    // 0x800292D8: addiu       $t6, $t6, -0x7EC
    ctx->r14 = ADD32(ctx->r14, -0X7EC);
    // 0x800292DC: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800292E0: div         $zero, $s2, $t8
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r24)));
    // 0x800292E4: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800292E8: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x800292EC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800292F0: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x800292F4: bne         $t8, $zero, L_80029300
    if (ctx->r24 != 0) {
        // 0x800292F8: nop
    
            goto L_80029300;
    }
    // 0x800292F8: nop

    // 0x800292FC: break       7
    do_break(2147652348);
L_80029300:
    // 0x80029300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80029304: bne         $t8, $at, L_80029318
    if (ctx->r24 != ctx->r1) {
        // 0x80029308: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80029318;
    }
    // 0x80029308: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002930C: bne         $s2, $at, L_80029318
    if (ctx->r18 != ctx->r1) {
        // 0x80029310: nop
    
            goto L_80029318;
    }
    // 0x80029310: nop

    // 0x80029314: break       6
    do_break(2147652372);
L_80029318:
    // 0x80029318: mflo        $s2
    ctx->r18 = lo;
    // 0x8002931C: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x80029320: b           L_80029358
    // 0x80029324: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
        goto L_80029358;
    // 0x80029324: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
L_80029328:
    // 0x80029328: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8002932C: addu        $t9, $t9, $s4
    ctx->r25 = ADD32(ctx->r25, ctx->r20);
    // 0x80029330: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80029334: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80029338: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002933C: addiu       $t6, $t6, -0xB34
    ctx->r14 = ADD32(ctx->r14, -0XB34);
    // 0x80029340: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80029344: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80029348: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8002934C: lh          $s2, 0x2($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X2);
    // 0x80029350: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x80029354: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
L_80029358:
    // 0x80029358: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8002935C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80029360: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029364: addu        $a1, $t0, $t9
    ctx->r5 = ADD32(ctx->r8, ctx->r25);
    // 0x80029368: addiu       $a1, $a1, 0x27
    ctx->r5 = ADD32(ctx->r5, 0X27);
    // 0x8002936C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80029370: addiu       $a2, $s2, 0x1D
    ctx->r6 = ADD32(ctx->r18, 0X1D);
    // 0x80029374: jal         0x80029B58
    // 0x80029378: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x80029378: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_20:
L_8002937C:
    // 0x8002937C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80029380: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80029384: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80029388: andi        $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 & 0X2000;
    // 0x8002938C: bne         $t8, $zero, L_80029424
    if (ctx->r24 != 0) {
        // 0x80029390: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80029424;
    }
    // 0x80029390: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80029394: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x80029398: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002939C: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x800293A0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800293A4: beq         $at, $zero, L_800293C0
    if (ctx->r1 == 0) {
        // 0x800293A8: ori         $t7, $a3, 0x2000
        ctx->r15 = ctx->r7 | 0X2000;
            goto L_800293C0;
    }
    // 0x800293A8: ori         $t7, $a3, 0x2000
    ctx->r15 = ctx->r7 | 0X2000;
    // 0x800293AC: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x800293B0: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x800293B4: andi        $t6, $v1, 0x10
    ctx->r14 = ctx->r3 & 0X10;
    // 0x800293B8: beq         $t6, $zero, L_800293EC
    if (ctx->r14 == 0) {
        // 0x800293BC: nop
    
            goto L_800293EC;
    }
    // 0x800293BC: nop

L_800293C0:
    // 0x800293C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800293C4: sw          $t9, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r25;
    // 0x800293C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800293CC: sw          $zero, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = 0;
    // 0x800293D0: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x800293D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800293D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800293DC: jal         0x800268D4
    // 0x800293E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_21;
    // 0x800293E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_21:
    // 0x800293E4: b           L_80029428
    // 0x800293E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80029428;
    // 0x800293E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800293EC:
    // 0x800293EC: bne         $at, $zero, L_800293F8
    if (ctx->r1 != 0) {
        // 0x800293F0: andi        $t8, $v1, 0x2000
        ctx->r24 = ctx->r3 & 0X2000;
            goto L_800293F8;
    }
    // 0x800293F0: andi        $t8, $v1, 0x2000
    ctx->r24 = ctx->r3 & 0X2000;
    // 0x800293F4: beq         $t8, $zero, L_80029424
    if (ctx->r24 == 0) {
        // 0x800293F8: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80029424;
    }
L_800293F8:
    // 0x800293F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800293FC: sw          $zero, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = 0;
    // 0x80029400: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80029404: addiu       $t6, $zero, -0x140
    ctx->r14 = ADD32(0, -0X140);
    // 0x80029408: sw          $t6, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r14;
    // 0x8002940C: ori         $t9, $a3, 0x3000
    ctx->r25 = ctx->r7 | 0X3000;
    // 0x80029410: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80029414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002941C: jal         0x800268D4
    // 0x80029420: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_22;
    // 0x80029420: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_22:
L_80029424:
    // 0x80029424: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80029428:
    // 0x80029428: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002942C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80029430: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80029434: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80029438: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8002943C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80029440: jr          $ra
    // 0x80029444: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x80029444: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void func_80038AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80038AF0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80038AF4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80038AF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80038AFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80038B00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80038B04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038B08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038B0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038B10: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80038B14: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80038B18: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80038B1C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80038B20: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80038B24: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80038B28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80038B2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80038B30: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80038B34: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80038B38: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_80038B3C:
    // 0x80038B3C: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x80038B40: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x80038B44: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x80038B48: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80038B4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038B50: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80038B54: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80038B58: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x80038B5C: beq         $v0, $zero, L_80038B88
    if (ctx->r2 == 0) {
        // 0x80038B60: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_80038B88;
    }
    // 0x80038B60: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x80038B64: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80038B68: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80038B6C: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80038B70: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80038B74: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80038B78: jal         0x80038794
    // 0x80038B7C: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    func_80038794(rdram, ctx);
        goto after_0;
    // 0x80038B7C: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x80038B80: b           L_80038B8C
    // 0x80038B84: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_80038B8C;
    // 0x80038B84: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_80038B88:
    // 0x80038B88: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_80038B8C:
    // 0x80038B8C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80038B90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038B94: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80038B98: bne         $t5, $s3, L_80038B3C
    if (ctx->r13 != ctx->r19) {
        // 0x80038B9C: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_80038B3C;
    }
    // 0x80038B9C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80038BA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80038BA4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80038BA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80038BAC: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x80038BB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80038BB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80038BB8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80038BBC: bgez        $t7, L_80038BD0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80038BC0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80038BD0;
    }
    // 0x80038BC0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80038BC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038BC8: nop

    // 0x80038BCC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80038BD0:
    // 0x80038BD0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80038BD4: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80038BD8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80038BDC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80038BE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80038BE4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80038BE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80038BEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80038BF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80038BF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80038BF8: jr          $ra
    // 0x80038BFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80038BFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80013A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013A28: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x80013A2C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80013A30: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x80013A34: beql        $t7, $zero, L_80013A9C
    if (ctx->r15 == 0) {
        // 0x80013A38: lw          $v0, 0x80($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X80);
            goto L_80013A9C;
    }
    goto skip_0;
    // 0x80013A38: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    skip_0:
    // 0x80013A3C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80013A40: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80013A44: addiu       $t3, $t3, 0x6B00
    ctx->r11 = ADD32(ctx->r11, 0X6B00);
    // 0x80013A48: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80013A4C: bne         $t9, $zero, L_80013C68
    if (ctx->r25 != 0) {
        // 0x80013A50: sw          $t9, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r25;
            goto L_80013C68;
    }
    // 0x80013A50: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80013A54: lhu         $t1, 0x8($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X8);
    // 0x80013A58: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80013A5C: addiu       $t5, $t3, 0x84
    ctx->r13 = ADD32(ctx->r11, 0X84);
    // 0x80013A60: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x80013A64: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
L_80013A68:
    // 0x80013A68: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80013A6C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80013A70: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80013A74: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80013A78: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x80013A7C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80013A80: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x80013A84: bne         $t3, $t5, L_80013A68
    if (ctx->r11 != ctx->r13) {
        // 0x80013A88: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80013A68;
    }
    // 0x80013A88: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80013A8C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80013A90: b           L_80013C68
    // 0x80013A94: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
        goto L_80013C68;
    // 0x80013A94: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80013A98: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
L_80013A9C:
    // 0x80013A9C: lwc1        $f18, -0x3A64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x80013AA0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80013AA4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013AA8: lwc1        $f10, -0x3A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x80013AAC: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013AB0: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80013AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80013AB8: jal         0x80023210
    // 0x80013ABC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80013ABC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_0:
    // 0x80013AC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013AC4: ldc1        $f16, 0x13B0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X13B0);
    // 0x80013AC8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013ACC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80013AD0: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x80013AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80013AD8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013ADC: addiu       $v0, $v0, 0x6EFC
    ctx->r2 = ADD32(ctx->r2, 0X6EFC);
    // 0x80013AE0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80013AE4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80013AE8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80013AEC: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80013AF0: nop

    // 0x80013AF4: bc1f        L_80013B18
    if (!c1cs) {
        // 0x80013AF8: nop
    
            goto L_80013B18;
    }
    // 0x80013AF8: nop

    // 0x80013AFC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B00: ldc1        $f14, 0x13B8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X13B8);
    // 0x80013B04: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B08: ldc1        $f18, 0x13C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X13C0);
    // 0x80013B0C: sub.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f2.d - ctx->f14.d;
    // 0x80013B10: b           L_80013B3C
    // 0x80013B14: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
        goto L_80013B3C;
    // 0x80013B14: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_80013B18:
    // 0x80013B18: ldc1        $f18, 0x13C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X13C8);
    // 0x80013B1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B20: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80013B24: nop

    // 0x80013B28: bc1f        L_80013B3C
    if (!c1cs) {
        // 0x80013B2C: nop
    
            goto L_80013B3C;
    }
    // 0x80013B2C: nop

    // 0x80013B30: ldc1        $f14, 0x13D0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X13D0);
    // 0x80013B34: add.d       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f2.d + ctx->f14.d;
    // 0x80013B38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80013B3C:
    // 0x80013B3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B40: ldc1        $f2, 0x13D8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X13D8);
    // 0x80013B44: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80013B48: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B4C: div.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80013B50: ldc1        $f14, 0x13E0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X13E0);
    // 0x80013B54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013B58: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80013B5C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80013B60: ldc1        $f8, 0x13E8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X13E8);
    // 0x80013B64: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80013B68: nop

    // 0x80013B6C: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80013B70: mul.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80013B74: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80013B78: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80013B7C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80013B80: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80013B84: nop

    // 0x80013B88: bc1fl       L_80013BA0
    if (!c1cs) {
        // 0x80013B8C: c.lt.d      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
            goto L_80013BA0;
    }
    goto skip_1;
    // 0x80013B8C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    skip_1:
    // 0x80013B90: sub.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f0.d - ctx->f14.d;
    // 0x80013B94: b           L_80013BB4
    // 0x80013B98: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_80013BB4;
    // 0x80013B98: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80013B9C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
L_80013BA0:
    // 0x80013BA0: nop

    // 0x80013BA4: bc1fl       L_80013BB8
    if (!c1cs) {
        // 0x80013BA8: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80013BB8;
    }
    goto skip_2;
    // 0x80013BA8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x80013BAC: add.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f0.d + ctx->f14.d;
    // 0x80013BB0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_80013BB4:
    // 0x80013BB4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_80013BB8:
    // 0x80013BB8: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80013BBC: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80013BC0: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80013BC4: nop

    // 0x80013BC8: bc1fl       L_80013BE0
    if (!c1cs) {
        // 0x80013BCC: c.lt.d      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
            goto L_80013BE0;
    }
    goto skip_3;
    // 0x80013BCC: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    skip_3:
    // 0x80013BD0: sub.d       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f0.d - ctx->f14.d;
    // 0x80013BD4: b           L_80013BF4
    // 0x80013BD8: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
        goto L_80013BF4;
    // 0x80013BD8: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80013BDC: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
L_80013BE0:
    // 0x80013BE0: nop

    // 0x80013BE4: bc1fl       L_80013BF8
    if (!c1cs) {
        // 0x80013BE8: swc1        $f12, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->f12.u32l;
            goto L_80013BF8;
    }
    goto skip_4;
    // 0x80013BE8: swc1        $f12, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f12.u32l;
    skip_4:
    // 0x80013BEC: add.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f0.d + ctx->f14.d;
    // 0x80013BF0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_80013BF4:
    // 0x80013BF4: swc1        $f12, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f12.u32l;
L_80013BF8:
    // 0x80013BF8: lhu         $t9, 0x2876($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X2876);
    // 0x80013BFC: andi        $t0, $t9, 0x20
    ctx->r8 = ctx->r25 & 0X20;
    // 0x80013C00: beq         $t0, $zero, L_80013C68
    if (ctx->r8 == 0) {
        // 0x80013C04: nop
    
            goto L_80013C68;
    }
    // 0x80013C04: nop

    // 0x80013C08: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013C0C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013C10: ldc1        $f10, 0x13F0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X13F0);
    // 0x80013C14: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80013C18: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x80013C1C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80013C20: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80013C24: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013C28: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80013C2C: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80013C30: nop

    // 0x80013C34: bc1fl       L_80013C50
    if (!c1cs) {
        // 0x80013C38: c.lt.d      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
            goto L_80013C50;
    }
    goto skip_5;
    // 0x80013C38: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    skip_5:
    // 0x80013C3C: sub.d       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f0.d - ctx->f14.d;
    // 0x80013C40: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80013C44: b           L_80013C68
    // 0x80013C48: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_80013C68;
    // 0x80013C48: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80013C4C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
L_80013C50:
    // 0x80013C50: nop

    // 0x80013C54: bc1f        L_80013C68
    if (!c1cs) {
        // 0x80013C58: nop
    
            goto L_80013C68;
    }
    // 0x80013C58: nop

    // 0x80013C5C: add.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f0.d + ctx->f14.d;
    // 0x80013C60: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80013C64: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80013C68:
    // 0x80013C68: jal         0x80013008
    // 0x80013C6C: nop

    func_80013008(rdram, ctx);
        goto after_1;
    // 0x80013C6C: nop

    after_1:
    // 0x80013C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013C78: jr          $ra
    // 0x80013C7C: nop

    return;
    // 0x80013C7C: nop

;}
RECOMP_FUNC void func_80008AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008AD8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80008ADC: addiu       $v0, $v0, -0x3A90
    ctx->r2 = ADD32(ctx->r2, -0X3A90);
    // 0x80008AE0: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
L_80008AE4:
    // 0x80008AE4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80008AE8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80008AEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008AF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80008AF4: bne         $v1, $zero, L_80008AE4
    if (ctx->r3 != 0) {
        // 0x80008AF8: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_80008AE4;
    }
    // 0x80008AF8: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x80008AFC: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x80008B00: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80008B04: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80008B08: addiu       $t8, $t8, -0x42D0
    ctx->r24 = ADD32(ctx->r24, -0X42D0);
    // 0x80008B0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80008B10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80008B14: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x80008B18: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80008B1C: addiu       $a0, $a0, -0x3690
    ctx->r4 = ADD32(ctx->r4, -0X3690);
    // 0x80008B20: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80008B24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80008B28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80008B2C: beq         $t0, $zero, L_80008B9C
    if (ctx->r8 == 0) {
        // 0x80008B30: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80008B9C;
    }
    // 0x80008B30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008B34: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_80008B38:
    // 0x80008B38: lw          $t1, 0x80($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X80);
    // 0x80008B3C: lw          $t5, 0x80($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X80);
    // 0x80008B40: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x80008B44: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80008B48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80008B4C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80008B50: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80008B54: lw          $t3, 0x80($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X80);
    // 0x80008B58: sb          $t4, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r12;
    // 0x80008B5C: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x80008B60: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80008B64: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80008B68: sb          $t8, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r24;
    // 0x80008B6C: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80008B70: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80008B74: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x80008B78: sb          $t2, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r10;
    // 0x80008B7C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80008B80: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80008B84: lbu         $t6, 0x3($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3);
    // 0x80008B88: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008B8C: bne         $v1, $a1, L_80008B38
    if (ctx->r3 != ctx->r5) {
        // 0x80008B90: sb          $t6, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r14;
            goto L_80008B38;
    }
    // 0x80008B90: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
    // 0x80008B94: jr          $ra
    // 0x80008B98: nop

    return;
    // 0x80008B98: nop

L_80008B9C:
    // 0x80008B9C: sb          $t7, -0x3690($at)
    MEM_B(-0X3690, ctx->r1) = ctx->r15;
    // 0x80008BA0: jr          $ra
    // 0x80008BA4: nop

    return;
    // 0x80008BA4: nop

;}
RECOMP_FUNC void func_800072A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800072A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800072AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800072B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800072B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800072B8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800072BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800072C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800072C4: lhu         $t7, 0x11C($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X11C);
    // 0x800072C8: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x800072CC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800072D0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800072D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800072D8: lhu         $t9, 0x1B26($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1B26);
    // 0x800072DC: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x800072E0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800072E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800072E8: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x800072EC: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x800072F0: lhu         $v1, 0x11E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X11E);
    // 0x800072F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800072F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800072FC: sra         $t1, $v1, 8
    ctx->r9 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80007300: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80007304: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80007308: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000730C: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x80007310: lw          $t4, 0x1B14($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B14);
    // 0x80007314: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80007318: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8000731C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80007320: addu        $a3, $t4, $t7
    ctx->r7 = ADD32(ctx->r12, ctx->r15);
    // 0x80007324: lhu         $t8, 0x18($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X18);
    // 0x80007328: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x8000732C: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x80007330: bne         $t8, $at, L_80007350
    if (ctx->r24 != ctx->r1) {
        // 0x80007334: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80007350;
    }
    // 0x80007334: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007338: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x8000733C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80007340: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x80007344: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80007348: b           L_8000735C
    // 0x8000734C: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
        goto L_8000735C;
    // 0x8000734C: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
L_80007350:
    // 0x80007350: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80007354: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80007358: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
L_8000735C:
    // 0x8000735C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80007360: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80007364: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80007368: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000736C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80007370: lhu         $v0, 0x2($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X2);
    // 0x80007374: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x80007378: sh          $t5, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r13;
    // 0x8000737C: sh          $zero, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = 0;
    // 0x80007380: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80007384: lhu         $t4, 0x60($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X60);
    // 0x80007388: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x8000738C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80007390: ori         $t7, $t4, 0x1
    ctx->r15 = ctx->r12 | 0X1;
    // 0x80007394: sh          $t7, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r15;
    // 0x80007398: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000739C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800073A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800073A4: jal         0x8001D8B0
    // 0x800073A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x800073A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x800073AC: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x800073B0: jal         0x800140EC
    // 0x800073B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800140EC(rdram, ctx);
        goto after_1;
    // 0x800073B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800073B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800073BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800073C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800073C4: jr          $ra
    // 0x800073C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800073C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80020F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F8C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80020F90: lw          $t6, -0x39B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39B8);
    // 0x80020F94: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80020F98: lw          $v0, -0x39B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X39B0);
    // 0x80020F9C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80020FA0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80020FA4: lw          $t7, -0x39B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X39B4);
    // 0x80020FA8: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x80020FAC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80020FB0: bne         $at, $zero, L_800210F4
    if (ctx->r1 != 0) {
        // 0x80020FB4: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_800210F4;
    }
    // 0x80020FB4: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80020FB8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80020FBC: lw          $v1, -0x39AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X39AC);
    // 0x80020FC0: addu        $a3, $a3, $a1
    ctx->r7 = ADD32(ctx->r7, ctx->r5);
    // 0x80020FC4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80020FC8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020FCC: bne         $at, $zero, L_800210F4
    if (ctx->r1 != 0) {
        // 0x80020FD0: nop
    
            goto L_800210F4;
    }
    // 0x80020FD0: nop

    // 0x80020FD4: lw          $t0, -0x39A8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X39A8);
    // 0x80020FD8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80020FDC: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80020FE0: bne         $at, $zero, L_800210F4
    if (ctx->r1 != 0) {
        // 0x80020FE4: nop
    
            goto L_800210F4;
    }
    // 0x80020FE4: nop

    // 0x80020FE8: lw          $t1, -0x39A4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X39A4);
    // 0x80020FEC: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80020FF0: addiu       $t2, $t2, -0x4D04
    ctx->r10 = ADD32(ctx->r10, -0X4D04);
    // 0x80020FF4: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80020FF8: bne         $at, $zero, L_800210F4
    if (ctx->r1 != 0) {
        // 0x80020FFC: slt         $at, $t0, $a2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800210F4;
    }
    // 0x80020FFC: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80021000: beq         $at, $zero, L_8002100C
    if (ctx->r1 == 0) {
        // 0x80021004: lw          $t8, 0x10($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X10);
            goto L_8002100C;
    }
    // 0x80021004: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80021008: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_8002100C:
    // 0x8002100C: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80021010: beq         $at, $zero, L_8002101C
    if (ctx->r1 == 0) {
        // 0x80021014: subu        $t9, $t8, $a0
        ctx->r25 = SUB32(ctx->r24, ctx->r4);
            goto L_8002101C;
    }
    // 0x80021014: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x80021018: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_8002101C:
    // 0x8002101C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80021020: beq         $at, $zero, L_80021034
    if (ctx->r1 == 0) {
        // 0x80021024: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80021034;
    }
    // 0x80021024: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80021028: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x8002102C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80021030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80021034:
    // 0x80021034: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021038: beq         $at, $zero, L_80021054
    if (ctx->r1 == 0) {
        // 0x8002103C: andi        $t9, $t8, 0xFFF
        ctx->r25 = ctx->r24 & 0XFFF;
            goto L_80021054;
    }
    // 0x8002103C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80021040: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80021044: subu        $t5, $t4, $a1
    ctx->r13 = SUB32(ctx->r12, ctx->r5);
    // 0x80021048: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8002104C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80021050: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80021054:
    // 0x80021054: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x80021058: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x8002105C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80021060: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80021064: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80021068: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8002106C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80021070: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80021074: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80021078: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8002107C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80021080: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80021084: andi        $t4, $t5, 0xFFF
    ctx->r12 = ctx->r13 & 0XFFF;
    // 0x80021088: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x8002108C: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x80021090: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80021094: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80021098: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8002109C: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x800210A0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800210A4: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800210A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800210AC: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800210B0: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800210B4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800210B8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800210BC: sll         $t4, $t3, 21
    ctx->r12 = S32(ctx->r11 << 21);
    // 0x800210C0: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800210C4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800210C8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800210CC: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x800210D0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800210D4: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x800210D8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800210DC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800210E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800210E4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800210E8: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800210EC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800210F0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_800210F4:
    // 0x800210F4: jr          $ra
    // 0x800210F8: nop

    return;
    // 0x800210F8: nop

;}
RECOMP_FUNC void func_80037B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037B7C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80037B80: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80037B84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80037B88: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x80037B8C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80037B90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80037B94: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80037B98: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80037B9C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80037BA0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80037BA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80037BA8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80037BAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80037BB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80037BB4: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80037BB8: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_80037BBC:
    // 0x80037BBC: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x80037BC0: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x80037BC4: beq         $at, $zero, L_8003813C
    if (ctx->r1 == 0) {
        // 0x80037BC8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8003813C;
    }
    // 0x80037BC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80037BCC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037BD0: addu        $at, $at, $t7
    gpr jr_addend_80037BD8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80037BD4: lw          $t7, 0x1D94($at)
    ctx->r15 = ADD32(ctx->r1, 0X1D94);
    // 0x80037BD8: jr          $t7
    // 0x80037BDC: nop

    switch (jr_addend_80037BD8 >> 2) {
        case 0: goto L_80037BE0; break;
        case 1: goto L_8003813C; break;
        case 2: goto L_80037F10; break;
        case 3: goto L_8003813C; break;
        case 4: goto L_8003813C; break;
        case 5: goto L_80037CCC; break;
        case 6: goto L_80037D18; break;
        case 7: goto L_80037F2C; break;
        case 8: goto L_8003813C; break;
        case 9: goto L_80037CAC; break;
        case 10: goto L_80037F4C; break;
        case 11: goto L_8003813C; break;
        case 12: goto L_800380DC; break;
        case 13: goto L_800380F8; break;
        case 14: goto L_8003812C; break;
        case 15: goto L_80037FB0; break;
        case 16: goto L_80037FD4; break;
        case 17: goto L_80038040; break;
        case 18: goto L_8003813C; break;
        case 19: goto L_8003813C; break;
        case 20: goto L_8003813C; break;
        case 21: goto L_80037F10; break;
        case 22: goto L_80037D7C; break;
        case 23: goto L_80037E88; break;
        default: switch_error(__func__, 0x80037BD8, 0x80071D94);
    }
    // 0x80037BDC: nop

L_80037BE0:
    // 0x80037BE0: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x80037BE4: beql        $a0, $zero, L_80038140
    if (ctx->r4 == 0) {
        // 0x80037BE8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80038140;
    }
    goto skip_0;
    // 0x80037BE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x80037BEC: jal         0x800387F4
    // 0x80037BF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800387F4(rdram, ctx);
        goto after_0;
    // 0x80037BF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80037BF4: lh          $t8, 0x58($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X58);
    // 0x80037BF8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80037BFC: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x80037C00: beq         $at, $zero, L_8003813C
    if (ctx->r1 == 0) {
        // 0x80037C04: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8003813C;
    }
    // 0x80037C04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80037C08: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80037C0C: addu        $at, $at, $t9
    gpr jr_addend_80037C14 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80037C10: lw          $t9, 0x1DF4($at)
    ctx->r25 = ADD32(ctx->r1, 0X1DF4);
    // 0x80037C14: jr          $t9
    // 0x80037C18: nop

    switch (jr_addend_80037C14 >> 2) {
        case 0: goto L_80037C1C; break;
        case 1: goto L_8003813C; break;
        case 2: goto L_80037C44; break;
        case 3: goto L_80037C70; break;
        case 4: goto L_8003813C; break;
        case 5: goto L_8003813C; break;
        case 6: goto L_8003813C; break;
        case 7: goto L_8003813C; break;
        case 8: goto L_8003813C; break;
        case 9: goto L_8003813C; break;
        case 10: goto L_8003813C; break;
        case 11: goto L_8003813C; break;
        case 12: goto L_8003813C; break;
        case 13: goto L_8003813C; break;
        case 14: goto L_8003813C; break;
        case 15: goto L_8003813C; break;
        case 16: goto L_8003813C; break;
        case 17: goto L_80037C9C; break;
        case 18: goto L_80037C9C; break;
        case 19: goto L_80037C9C; break;
        default: switch_error(__func__, 0x80037C14, 0x80071DF4);
    }
    // 0x80037C18: nop

L_80037C1C:
    // 0x80037C1C: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80037C20: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80037C24: jal         0x8003734C
    // 0x80037C28: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_8003734C(rdram, ctx);
        goto after_1;
    // 0x80037C28: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x80037C2C: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80037C30: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80037C34: jal         0x800370D0
    // 0x80037C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_2;
    // 0x80037C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80037C3C: b           L_80038140
    // 0x80037C40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037C40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037C44:
    // 0x80037C44: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x80037C48: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80037C4C: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80037C50: jal         0x8003717C
    // 0x80037C54: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_8003717C(rdram, ctx);
        goto after_3;
    // 0x80037C54: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_3:
    // 0x80037C58: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80037C5C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80037C60: jal         0x800370D0
    // 0x80037C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_4;
    // 0x80037C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80037C68: b           L_80038140
    // 0x80037C6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037C6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037C70:
    // 0x80037C70: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80037C74: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x80037C78: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80037C7C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80037C80: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x80037C84: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80037C88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80037C8C: jal         0x8003FE6C
    // 0x80037C90: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x80037C90: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x80037C94: b           L_80038140
    // 0x80037C98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037C98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037C9C:
    // 0x80037C9C: jal         0x800370D0
    // 0x80037CA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_6;
    // 0x80037CA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80037CA4: b           L_80038140
    // 0x80037CA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037CA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037CAC:
    // 0x80037CAC: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80037CB0: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x80037CB4: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x80037CB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80037CBC: jal         0x8003FE6C
    // 0x80037CC0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x80037CC0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x80037CC4: b           L_80038140
    // 0x80037CC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037CC8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037CCC:
    // 0x80037CCC: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x80037CD0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037CD4: jal         0x80044060
    // 0x80037CD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80044060(rdram, ctx);
        goto after_8;
    // 0x80037CD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80037CDC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037CE0: jal         0x800440E0
    // 0x80037CE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800440E0(rdram, ctx);
        goto after_9;
    // 0x80037CE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80037CE8: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80037CEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80037CF0: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x80037CF4: beql        $t9, $zero, L_80037D08
    if (ctx->r25 == 0) {
        // 0x80037CF8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80037D08;
    }
    goto skip_1;
    // 0x80037CF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80037CFC: jal         0x80043D10
    // 0x80037D00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80043D10(rdram, ctx);
        goto after_10;
    // 0x80037D00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x80037D04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80037D08:
    // 0x80037D08: jal         0x80042AE0
    // 0x80037D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042AE0(rdram, ctx);
        goto after_11;
    // 0x80037D0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80037D10: b           L_80038140
    // 0x80037D14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037D14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037D18:
    // 0x80037D18: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x80037D1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037D20: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80037D24: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x80037D28: bnel        $t6, $zero, L_80037D38
    if (ctx->r14 != 0) {
        // 0x80037D2C: lw          $s3, 0x40($s2)
        ctx->r19 = MEM_W(ctx->r18, 0X40);
            goto L_80037D38;
    }
    goto skip_2;
    // 0x80037D2C: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    skip_2:
    // 0x80037D30: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x80037D34: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
L_80037D38:
    // 0x80037D38: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x80037D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037D40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80037D44: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x80037D48: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x80037D4C: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    // 0x80037D50: jal         0x80042884
    // 0x80037D54: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    func_80042884(rdram, ctx);
        goto after_12;
    // 0x80037D54: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_12:
    // 0x80037D58: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80037D5C: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80037D60: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80037D64: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037D68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80037D6C: jal         0x80044190
    // 0x80037D70: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80044190(rdram, ctx);
        goto after_13;
    // 0x80037D70: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_13:
    // 0x80037D74: b           L_80038140
    // 0x80037D78: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037D78: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037D7C:
    // 0x80037D7C: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x80037D80: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x80037D84: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80037D88: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80037D8C: jalr        $t9
    // 0x80037D90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x80037D90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80037D94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80037D98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80037D9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80037DA0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80037DA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80037DA8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80037DAC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80037DB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037DB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80037DB8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80037DBC: nop

    // 0x80037DC0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80037DC4: beql        $t6, $zero, L_80037E14
    if (ctx->r14 == 0) {
        // 0x80037DC8: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_80037E14;
    }
    goto skip_3;
    // 0x80037DC8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80037DCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037DD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80037DD4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80037DD8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80037DDC: nop

    // 0x80037DE0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037DE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80037DE8: nop

    // 0x80037DEC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80037DF0: bne         $t6, $zero, L_80037E08
    if (ctx->r14 != 0) {
        // 0x80037DF4: nop
    
            goto L_80037E08;
    }
    // 0x80037DF4: nop

    // 0x80037DF8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80037DFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80037E00: b           L_80037E20
    // 0x80037E04: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80037E20;
    // 0x80037E04: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80037E08:
    // 0x80037E08: b           L_80037E20
    // 0x80037E0C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80037E20;
    // 0x80037E0C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80037E10: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_80037E14:
    // 0x80037E14: nop

    // 0x80037E18: bltz        $t6, L_80037E08
    if (SIGNED(ctx->r14) < 0) {
        // 0x80037E1C: nop
    
            goto L_80037E08;
    }
    // 0x80037E1C: nop

L_80037E20:
    // 0x80037E20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80037E24: jal         0x80042884
    // 0x80037E28: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    func_80042884(rdram, ctx);
        goto after_15;
    // 0x80037E28: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_15:
    // 0x80037E2C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80037E30: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80037E34: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80037E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037E3C: jal         0x80042860
    // 0x80037E40: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_80042860(rdram, ctx);
        goto after_16;
    // 0x80037E40: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_16:
    // 0x80037E44: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80037E48: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80037E4C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80037E50: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037E54: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80037E58: jal         0x80044190
    // 0x80037E5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_17;
    // 0x80037E5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x80037E60: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80037E64: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x80037E68: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x80037E6C: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x80037E70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80037E74: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80037E78: jal         0x8003FE6C
    // 0x80037E7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x80037E7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_18:
    // 0x80037E80: b           L_80038140
    // 0x80037E84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037E84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037E88:
    // 0x80037E88: lw          $t9, 0x74($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X74);
    // 0x80037E8C: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x80037E90: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80037E94: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x80037E98: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80037E9C: jalr        $t9
    // 0x80037EA0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x80037EA0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x80037EA4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80037EA8: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80037EAC: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x80037EB0: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x80037EB4: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80037EB8: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x80037EBC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80037EC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037EC4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80037EC8: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80037ECC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037ED0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80037ED4: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80037ED8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80037EDC: jal         0x80044230
    // 0x80037EE0: nop

    func_80044230(rdram, ctx);
        goto after_20;
    // 0x80037EE0: nop

    after_20:
    // 0x80037EE4: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x80037EE8: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x80037EEC: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x80037EF0: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x80037EF4: sb          $s0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r16;
    // 0x80037EF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80037EFC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80037F00: jal         0x8003FE6C
    // 0x80037F04: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_21;
    // 0x80037F04: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x80037F08: b           L_80038140
    // 0x80037F0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037F0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037F10:
    // 0x80037F10: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80037F14: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80037F18: jal         0x8003734C
    // 0x80037F1C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_8003734C(rdram, ctx);
        goto after_22;
    // 0x80037F1C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_22:
    // 0x80037F20: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80037F24: b           L_8003813C
    // 0x80037F28: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_8003813C;
    // 0x80037F28: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80037F2C:
    // 0x80037F2C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x80037F30: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80037F34: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80037F38: jal         0x8003717C
    // 0x80037F3C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    func_8003717C(rdram, ctx);
        goto after_23;
    // 0x80037F3C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_23:
    // 0x80037F40: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80037F44: b           L_8003813C
    // 0x80037F48: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
        goto L_8003813C;
    // 0x80037F48: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
L_80037F4C:
    // 0x80037F4C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80037F50: lh          $t6, 0x3C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3C);
    // 0x80037F54: beq         $s1, $zero, L_8003813C
    if (ctx->r17 == 0) {
        // 0x80037F58: sh          $t6, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r14;
            goto L_8003813C;
    }
    // 0x80037F58: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x80037F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80037F60:
    // 0x80037F60: jal         0x80042884
    // 0x80037F64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80042884(rdram, ctx);
        goto after_24;
    // 0x80037F64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80037F68: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80037F6C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80037F70: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80037F74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037F78: jal         0x80042860
    // 0x80037F7C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    func_80042860(rdram, ctx);
        goto after_25;
    // 0x80037F7C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_25:
    // 0x80037F80: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80037F84: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80037F88: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80037F8C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80037F90: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80037F94: jal         0x80044190
    // 0x80037F98: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_26;
    // 0x80037F98: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x80037F9C: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80037FA0: bnel        $s1, $zero, L_80037F60
    if (ctx->r17 != 0) {
        // 0x80037FA4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80037F60;
    }
    goto skip_4;
    // 0x80037FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x80037FA8: b           L_80038140
    // 0x80037FAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037FAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037FB0:
    // 0x80037FB0: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80037FB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80037FB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80037FBC: beq         $t9, $at, L_8003813C
    if (ctx->r25 == ctx->r1) {
        // 0x80037FC0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8003813C;
    }
    // 0x80037FC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80037FC4: jal         0x800370D0
    // 0x80037FC8: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_27;
    // 0x80037FC8: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_27:
    // 0x80037FCC: b           L_80038140
    // 0x80037FD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80037FD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80037FD4:
    // 0x80037FD4: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80037FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037FDC: bnel        $t7, $at, L_80038140
    if (ctx->r15 != ctx->r1) {
        // 0x80037FE0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80038140;
    }
    goto skip_5;
    // 0x80037FE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_5:
    // 0x80037FE4: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80037FE8: beq         $s1, $zero, L_80038038
    if (ctx->r17 == 0) {
        // 0x80037FEC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80038038;
    }
    // 0x80037FEC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80037FF0:
    // 0x80037FF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80037FF4: jal         0x80044060
    // 0x80037FF8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    func_80044060(rdram, ctx);
        goto after_28;
    // 0x80037FF8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_28:
    // 0x80037FFC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80038000: jal         0x800440E0
    // 0x80038004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800440E0(rdram, ctx);
        goto after_29;
    // 0x80038004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_29:
    // 0x80038008: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x8003800C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038010: beql        $t8, $zero, L_80038024
    if (ctx->r24 == 0) {
        // 0x80038014: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80038024;
    }
    goto skip_6;
    // 0x80038014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
    // 0x80038018: jal         0x80043D10
    // 0x8003801C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80043D10(rdram, ctx);
        goto after_30;
    // 0x8003801C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x80038020: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80038024:
    // 0x80038024: jal         0x80042AE0
    // 0x80038028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80042AE0(rdram, ctx);
        goto after_31;
    // 0x80038028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x8003802C: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80038030: bnel        $s1, $zero, L_80037FF0
    if (ctx->r17 != 0) {
        // 0x80038034: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80037FF0;
    }
    goto skip_7;
    // 0x80038034: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_7:
L_80038038:
    // 0x80038038: b           L_8003813C
    // 0x8003803C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_8003813C;
    // 0x8003803C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_80038040:
    // 0x80038040: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80038044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038048: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003804C: bnel        $t9, $at, L_80038140
    if (ctx->r25 != ctx->r1) {
        // 0x80038050: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80038140;
    }
    goto skip_8;
    // 0x80038050: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_8:
    // 0x80038054: jal         0x8003FD50
    // 0x80038058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003FD50(rdram, ctx);
        goto after_32;
    // 0x80038058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x8003805C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80038060: jal         0x8003FD50
    // 0x80038064: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8003FD50(rdram, ctx);
        goto after_33;
    // 0x80038064: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_33:
    // 0x80038068: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8003806C: jal         0x8003FD50
    // 0x80038070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8003FD50(rdram, ctx);
        goto after_34;
    // 0x80038070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x80038074: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80038078: beq         $s1, $zero, L_800380B0
    if (ctx->r17 == 0) {
        // 0x8003807C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800380B0;
    }
    // 0x8003807C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80038080:
    // 0x80038080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80038084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038088: jal         0x80042A38
    // 0x8003808C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_80042A38(rdram, ctx);
        goto after_35;
    // 0x8003808C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_35:
    // 0x80038090: beq         $v0, $zero, L_800380A4
    if (ctx->r2 == 0) {
        // 0x80038094: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800380A4;
    }
    // 0x80038094: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003809C: jal         0x8004290C
    // 0x800380A0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    func_8004290C(rdram, ctx);
        goto after_36;
    // 0x800380A0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_36:
L_800380A4:
    // 0x800380A4: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800380A8: bnel        $s1, $zero, L_80038080
    if (ctx->r17 != 0) {
        // 0x800380AC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80038080;
    }
    goto skip_9;
    // 0x800380AC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_9:
L_800380B0:
    // 0x800380B0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800380B4: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800380B8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800380BC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800380C0: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800380C4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800380C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800380CC: jal         0x8003FE6C
    // 0x800380D0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_37;
    // 0x800380D0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_37:
    // 0x800380D4: b           L_80038140
    // 0x800380D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x800380D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800380DC:
    // 0x800380DC: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800380E0: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800380E4: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800380E8: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x800380EC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800380F0: b           L_8003813C
    // 0x800380F4: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_8003813C;
    // 0x800380F4: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800380F8:
    // 0x800380F8: lw          $t9, 0x3C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X3C);
    // 0x800380FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038104: sw          $t9, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r25;
    // 0x80038108: jal         0x80037140
    // 0x8003810C: lwc1        $f12, 0x1E44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1E44);
    func_80037140(rdram, ctx);
        goto after_38;
    // 0x8003810C: lwc1        $f12, 0x1E44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1E44);
    after_38:
    // 0x80038110: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x80038114: beql        $a1, $zero, L_80038140
    if (ctx->r5 == 0) {
        // 0x80038118: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80038140;
    }
    goto skip_10;
    // 0x80038118: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x8003811C: jal         0x800427A4
    // 0x80038120: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800427A4(rdram, ctx);
        goto after_39;
    // 0x80038120: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_39:
    // 0x80038124: b           L_80038140
    // 0x80038128: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80038140;
    // 0x80038128: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8003812C:
    // 0x8003812C: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x80038130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038134: jal         0x800427A4
    // 0x80038138: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    func_800427A4(rdram, ctx);
        goto after_40;
    // 0x80038138: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_40:
L_8003813C:
    // 0x8003813C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80038140:
    // 0x80038140: jal         0x8003FF90
    // 0x80038144: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_8003FF90(rdram, ctx);
        goto after_41;
    // 0x80038144: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_41:
    // 0x80038148: beq         $v0, $zero, L_80037BBC
    if (ctx->r2 == 0) {
        // 0x8003814C: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_80037BBC;
    }
    // 0x8003814C: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80038150: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x80038154: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80038158: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x8003815C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80038160: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80038164: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80038168: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8003816C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80038170: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80038174: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80038178: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003817C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80038180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80038184: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80038188: jr          $ra
    // 0x8003818C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8003818C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80100B38_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100B38: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80100B3C: lw          $t6, 0x6FE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FE8);
    // 0x80100B40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80100B44: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80100B48: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80100B4C: bltz        $t7, L_80100B58
    if (SIGNED(ctx->r15) < 0) {
        // 0x80100B50: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_80100B58;
    }
    // 0x80100B50: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80100B54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80100B58:
    // 0x80100B58: addiu       $v0, $v0, 0x7038
    ctx->r2 = ADD32(ctx->r2, 0X7038);
    // 0x80100B5C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80100B60: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100B64: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80100B68: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80100B6C: bne         $t9, $zero, L_80100B78
    if (ctx->r25 != 0) {
        // 0x80100B70: addiu       $a2, $zero, 0x96
        ctx->r6 = ADD32(0, 0X96);
            goto L_80100B78;
    }
    // 0x80100B70: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80100B74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80100B78:
    // 0x80100B78: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80100B7C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80100B80: and         $t1, $t0, $a1
    ctx->r9 = ctx->r8 & ctx->r5;
    // 0x80100B84: bnel        $t1, $zero, L_80100B94
    if (ctx->r9 != 0) {
        // 0x80100B88: lw          $t2, 0x50($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X50);
            goto L_80100B94;
    }
    goto skip_0;
    // 0x80100B88: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x80100B8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100B90: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
L_80100B94:
    // 0x80100B94: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100B98: and         $t3, $t2, $a1
    ctx->r11 = ctx->r10 & ctx->r5;
    // 0x80100B9C: bnel        $t3, $zero, L_80100BAC
    if (ctx->r11 != 0) {
        // 0x80100BA0: lw          $t4, 0x50($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X50);
            goto L_80100BAC;
    }
    goto skip_1;
    // 0x80100BA0: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x80100BA4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100BA8: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
L_80100BAC:
    // 0x80100BAC: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100BB0: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x80100BB4: bnel        $t5, $zero, L_80100BC4
    if (ctx->r13 != 0) {
        // 0x80100BB8: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_80100BC4;
    }
    goto skip_2;
    // 0x80100BB8: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x80100BBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80100BC0: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
L_80100BC4:
    // 0x80100BC4: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100BC8: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x80100BCC: bne         $t7, $zero, L_80100BD8
    if (ctx->r15 != 0) {
        // 0x80100BD0: nop
    
            goto L_80100BD8;
    }
    // 0x80100BD0: nop

    // 0x80100BD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80100BD8:
    // 0x80100BD8: bne         $v1, $a2, L_80100B78
    if (ctx->r3 != ctx->r6) {
        // 0x80100BDC: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80100B78;
    }
    // 0x80100BDC: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100BE0: jr          $ra
    // 0x80100BE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80100BE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800025E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800025E8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800025EC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800025F0: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x800025F4: addiu       $fp, $fp, -0x4CB8
    ctx->r30 = ADD32(ctx->r30, -0X4CB8);
    // 0x800025F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800025FC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002600: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002604: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002608: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000260C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002610: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002614: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002618: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000261C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80002620: jal         0x80031CB0
    // 0x80002624: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    func_80031CB0(rdram, ctx);
        goto after_0;
    // 0x80002624: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    after_0:
    // 0x80002628: jal         0x80100000
    // 0x8000262C: nop

    LOOKUP_FUNC(0x80100000)(rdram, ctx);
        goto after_1;
    // 0x8000262C: nop

    after_1:
    // 0x80002630: jal         0x800267B8
    // 0x80002634: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    UpdateBGM(rdram, ctx);
        goto after_2;
    // 0x80002634: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80002638: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000263C: lhu         $t6, -0x4D20($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4D20);
    // 0x80002640: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80002644: ori         $s7, $zero, 0xD150
    ctx->r23 = 0 | 0XD150;
    // 0x80002648: bne         $t6, $at, L_80002740
    if (ctx->r14 != ctx->r1) {
        // 0x8000264C: lui         $s6, 0x8030
        ctx->r22 = S32(0X8030 << 16);
            goto L_80002740;
    }
    // 0x8000264C: lui         $s6, 0x8030
    ctx->r22 = S32(0X8030 << 16);
    // 0x80002650: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80002654: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80002658: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x8000265C: addiu       $s4, $s4, -0x4D0C
    ctx->r20 = ADD32(ctx->r20, -0X4D0C);
    // 0x80002660: addiu       $s6, $s6, 0x1000
    ctx->r22 = ADD32(ctx->r22, 0X1000);
    // 0x80002664: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80002668: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000266C: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_80002670:
    // 0x80002670: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002674: jal         0x800314C0
    // 0x80002678: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_800314C0(rdram, ctx);
        goto after_3;
    // 0x80002678: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_3:
    // 0x8000267C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002680: jal         0x80026658
    // 0x80002684: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    func_80026658(rdram, ctx);
        goto after_4;
    // 0x80002684: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    after_4:
    // 0x80002688: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8000268C: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002690: mflo        $t8
    ctx->r24 = lo;
    // 0x80002694: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x80002698: jal         0x800011DC
    // 0x8000269C: nop

    func_800011DC(rdram, ctx);
        goto after_5;
    // 0x8000269C: nop

    after_5:
    // 0x800026A0: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800026A4: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800026A8: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800026AC: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800026B0: mflo        $t0
    ctx->r8 = lo;
    // 0x800026B4: addu        $s5, $s6, $t0
    ctx->r21 = ADD32(ctx->r22, ctx->r8);
    // 0x800026B8: bnel        $v0, $zero, L_800026F0
    if (ctx->r2 != 0) {
        // 0x800026BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800026F0;
    }
    goto skip_0;
    // 0x800026BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800026C0: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    // 0x800026C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800026C8:
    // 0x800026C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800026CC: jal         0x80034020
    // 0x800026D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800026D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x800026D4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800026D8: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800026DC: bnel        $s2, $t3, L_800026C8
    if (ctx->r18 != ctx->r11) {
        // 0x800026E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800026C8;
    }
    goto skip_1;
    // 0x800026E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800026E4: b           L_8000270C
    // 0x800026E8: nop

        goto L_8000270C;
    // 0x800026E8: nop

    // 0x800026EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800026F0:
    // 0x800026F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800026F4: jal         0x80034020
    // 0x800026F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800026F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x800026FC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80002700: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80002704: bnel        $s3, $t5, L_800026F0
    if (ctx->r19 != ctx->r13) {
        // 0x80002708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800026F0;
    }
    goto skip_2;
    // 0x80002708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_8000270C:
    // 0x8000270C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002710: lw          $a0, -0x4628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4628);
    // 0x80002714: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80002718: jal         0x80034200
    // 0x8000271C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x8000271C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80002720: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80002724: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80002728: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000272C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80002730: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x80002734: lhu         $t8, -0x4D20($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4D20);
    // 0x80002738: beq         $t8, $at, L_80002670
    if (ctx->r24 == ctx->r1) {
        // 0x8000273C: nop
    
            goto L_80002670;
    }
    // 0x8000273C: nop

L_80002740:
    // 0x80002740: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80002744: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002748: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x8000274C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80002750: jal         0x800267B8
    // 0x80002754: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    UpdateBGM(rdram, ctx);
        goto after_9;
    // 0x80002754: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
    // 0x80002758: jal         0x80026658
    // 0x8000275C: nop

    func_80026658(rdram, ctx);
        goto after_10;
    // 0x8000275C: nop

    after_10:
    // 0x80002760: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002764: addiu       $v0, $v0, -0x4D1C
    ctx->r2 = ADD32(ctx->r2, -0X4D1C);
    // 0x80002768: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000276C: ori         $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 | 0X8000;
    // 0x80002770: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80002774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002778:
    // 0x80002778: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000277C: jal         0x80034020
    // 0x80002780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80002780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80002784: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80002788: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8000278C: bnel        $s3, $t2, L_80002778
    if (ctx->r19 != ctx->r10) {
        // 0x80002790: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002778;
    }
    goto skip_3;
    // 0x80002790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80002794: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002798: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000279C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800027A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800027A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800027A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800027AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800027B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800027B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800027B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800027BC: jr          $ra
    // 0x800027C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800027C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800027C4: nop

    // 0x800027C8: nop

    // 0x800027CC: nop

;}
