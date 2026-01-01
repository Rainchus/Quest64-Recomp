#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800369B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800369B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800369BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800369C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800369C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800369C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800369CC: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x800369D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800369D4: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x800369D8: beql        $s0, $zero, L_80036A04
    if (ctx->r16 == 0) {
        // 0x800369DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80036A04;
    }
    goto skip_0;
    // 0x800369DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800369E0:
    // 0x800369E0: jal         0x80036820
    // 0x800369E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x800369E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800369E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800369EC: jal         0x80036850
    // 0x800369F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x800369F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800369F4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800369F8: bne         $s0, $zero, L_800369E0
    if (ctx->r16 != 0) {
        // 0x800369FC: nop
    
            goto L_800369E0;
    }
    // 0x800369FC: nop

    // 0x80036A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80036A04:
    // 0x80036A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80036A08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80036A0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80036A10: jr          $ra
    // 0x80036A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80036A14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80024B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024B20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80024B24: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80024B28: addiu       $s2, $s2, -0x968
    ctx->r18 = ADD32(ctx->r18, -0X968);
    // 0x80024B2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024B30: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024B34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024B38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024B3C: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80024B40: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x80024B44: addiu       $s3, $s3, 0x38F8
    ctx->r19 = ADD32(ctx->r19, 0X38F8);
    // 0x80024B48: beq         $s0, $zero, L_80024BB4
    if (ctx->r16 == 0) {
        // 0x80024B4C: nop
    
            goto L_80024BB4;
    }
    // 0x80024B4C: nop

L_80024B50:
    // 0x80024B50: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80024B54: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80024B58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80024B5C: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80024B60: sltu        $at, $t8, $t6
    ctx->r1 = ctx->r24 < ctx->r14 ? 1 : 0;
    // 0x80024B64: beq         $at, $zero, L_80024BAC
    if (ctx->r1 == 0) {
        // 0x80024B68: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80024BAC;
    }
    // 0x80024B68: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80024B6C: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x80024B70: bne         $s0, $t9, L_80024B7C
    if (ctx->r16 != ctx->r25) {
        // 0x80024B74: nop
    
            goto L_80024B7C;
    }
    // 0x80024B74: nop

    // 0x80024B78: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_80024B7C:
    // 0x80024B7C: jal         0x80036820
    // 0x80024B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_0;
    // 0x80024B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80024B84: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80024B88: beql        $a1, $zero, L_80024BA4
    if (ctx->r5 == 0) {
        // 0x80024B8C: sw          $s0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r16;
            goto L_80024BA4;
    }
    goto skip_0;
    // 0x80024B8C: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    skip_0:
    // 0x80024B90: jal         0x80036850
    // 0x80024B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036850(rdram, ctx);
        goto after_1;
    // 0x80024B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80024B98: b           L_80024BAC
    // 0x80024B9C: nop

        goto L_80024BAC;
    // 0x80024B9C: nop

    // 0x80024BA0: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
L_80024BA4:
    // 0x80024BA4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024BA8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80024BAC:
    // 0x80024BAC: bne         $s1, $zero, L_80024B50
    if (ctx->r17 != 0) {
        // 0x80024BB0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80024B50;
    }
    // 0x80024BB0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80024BB4:
    // 0x80024BB4: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x80024BB8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80024BBC: addiu       $s3, $s3, 0x38F8
    ctx->r19 = ADD32(ctx->r19, 0X38F8);
    // 0x80024BC0: sw          $zero, 0x38F4($at)
    MEM_W(0X38F4, ctx->r1) = 0;
    // 0x80024BC4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80024BC8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80024BCC: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80024BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024BD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024BD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024BDC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024BE0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80024BE4: jr          $ra
    // 0x80024BE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80024BE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8003918C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003918C: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80039190: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80039194: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80039198: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8003919C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800391A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800391A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800391A8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800391AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800391B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800391B4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800391B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800391BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800391C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800391C4: ldc1        $f20, 0x1E60($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1E60);
    // 0x800391C8: addiu       $s4, $a0, 0x28
    ctx->r20 = ADD32(ctx->r4, 0X28);
    // 0x800391CC: addiu       $s7, $a0, 0x14
    ctx->r23 = ADD32(ctx->r4, 0X14);
    // 0x800391D0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800391D4:
    // 0x800391D4: lh          $v0, 0x28($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X28);
    // 0x800391D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800391DC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800391E0: bne         $v0, $at, L_80039200
    if (ctx->r2 != ctx->r1) {
        // 0x800391E4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039200;
    }
    // 0x800391E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800391E8: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x800391EC: lw          $a2, 0x48($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X48);
    // 0x800391F0: jal         0x8003FE6C
    // 0x800391F4: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800391F4: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    after_0:
    // 0x800391F8: b           L_80039684
    // 0x800391FC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x800391FC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039200:
    // 0x80039200: lw          $s5, 0x2C($s6)
    ctx->r21 = MEM_W(ctx->r22, 0X2C);
    // 0x80039204: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80039208: beq         $at, $zero, L_80039680
    if (ctx->r1 == 0) {
        // 0x8003920C: lw          $s1, 0x1C($s5)
        ctx->r17 = MEM_W(ctx->r21, 0X1C);
            goto L_80039680;
    }
    // 0x8003920C: lw          $s1, 0x1C($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X1C);
    // 0x80039210: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80039214: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80039218: addu        $at, $at, $t7
    gpr jr_addend_80039220 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8003921C: lw          $t7, 0x1E68($at)
    ctx->r15 = ADD32(ctx->r1, 0X1E68);
    // 0x80039220: jr          $t7
    // 0x80039224: nop

    switch (jr_addend_80039220 >> 2) {
        case 0: goto L_80039228; break;
        case 1: goto L_80039390; break;
        case 2: goto L_8003945C; break;
        case 3: goto L_80039540; break;
        case 4: goto L_800394C4; break;
        case 5: goto L_80039680; break;
        case 6: goto L_800395A4; break;
        case 7: goto L_80039650; break;
        case 8: goto L_80039518; break;
        default: switch_error(__func__, 0x80039220, 0x80071E68);
    }
    // 0x80039224: nop

L_80039228:
    // 0x80039228: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x8003922C: bnel        $t8, $zero, L_80039684
    if (ctx->r24 != 0) {
        // 0x80039230: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039684;
    }
    goto skip_0;
    // 0x80039230: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x80039234: beq         $s1, $zero, L_80039680
    if (ctx->r17 == 0) {
        // 0x80039238: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80039680;
    }
    // 0x80039238: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8003923C: sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // 0x80039240: lh          $t9, 0x20($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X20);
    // 0x80039244: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x80039248: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x8003924C: sh          $t9, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r25;
    // 0x80039250: jal         0x800443A8
    // 0x80039254: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_800443A8(rdram, ctx);
        goto after_1;
    // 0x80039254: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_1:
    // 0x80039258: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8003925C: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x80039260: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80039264: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x80039268: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x8003926C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039270: mflo        $t8
    ctx->r24 = lo;
    // 0x80039274: nop

    // 0x80039278: nop

    // 0x8003927C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80039280: mflo        $t9
    ctx->r25 = lo;
    // 0x80039284: sh          $t9, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r25;
    // 0x80039288: lbu         $t7, 0xC($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XC);
    // 0x8003928C: lbu         $t6, 0x2E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2E);
    // 0x80039290: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80039294: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80039298: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8003929C: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800392A0: bgtzl       $v1, L_800392B0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800392A4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800392B0;
    }
    goto skip_1;
    // 0x800392A4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_1:
    // 0x800392A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800392AC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800392B0:
    // 0x800392B0: beq         $at, $zero, L_800392C0
    if (ctx->r1 == 0) {
        // 0x800392B4: nop
    
            goto L_800392C0;
    }
    // 0x800392B4: nop

    // 0x800392B8: b           L_800392C0
    // 0x800392BC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800392C0;
    // 0x800392BC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800392C0:
    // 0x800392C0: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800392C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800392C8: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800392CC: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x800392D0: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x800392D4: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800392D8: jal         0x80044760
    // 0x800392DC: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    func_80044760(rdram, ctx);
        goto after_2;
    // 0x800392DC: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    after_2:
    // 0x800392E0: lbu         $a2, 0xD7($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD7);
    // 0x800392E4: sw          $fp, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r30;
    // 0x800392E8: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800392EC: jal         0x80044630
    // 0x800392F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80044630(rdram, ctx);
        goto after_3;
    // 0x800392F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x800392F4: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800392F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800392FC: lh          $a2, 0xBA($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XBA);
    // 0x80039300: jal         0x80044190
    // 0x80039304: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80044190(rdram, ctx);
        goto after_4;
    // 0x80039304: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80039308: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8003930C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039310: jal         0x80044230
    // 0x80039314: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    func_80044230(rdram, ctx);
        goto after_5;
    // 0x80039314: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    after_5:
    // 0x80039318: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8003931C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039320: jal         0x800446C0
    // 0x80039324: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    func_800446C0(rdram, ctx);
        goto after_6;
    // 0x80039324: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    after_6:
    // 0x80039328: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8003932C: sh          $t6, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r14;
    // 0x80039330: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80039334: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80039338: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x8003933C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80039340: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80039344: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80039348: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8003934C: nop

    // 0x80039350: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80039354: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80039358: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003935C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80039360: nop

    // 0x80039364: bc1fl       L_80039378
    if (!c1cs) {
        // 0x80039368: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_80039378;
    }
    goto skip_2;
    // 0x80039368: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_2:
    // 0x8003936C: b           L_80039380
    // 0x80039370: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
        goto L_80039380;
    // 0x80039370: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80039374: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_80039378:
    // 0x80039378: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003937C: nop

L_80039380:
    // 0x80039380: jal         0x8003FE6C
    // 0x80039384: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x80039384: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_7:
    // 0x80039388: b           L_80039684
    // 0x8003938C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x8003938C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039390:
    // 0x80039390: lw          $t9, 0x28($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X28);
    // 0x80039394: bnel        $fp, $t9, L_80039684
    if (ctx->r30 != ctx->r25) {
        // 0x80039398: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039684;
    }
    goto skip_3;
    // 0x80039398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_3:
    // 0x8003939C: beq         $s1, $zero, L_80039680
    if (ctx->r17 == 0) {
        // 0x800393A0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80039680;
    }
    // 0x800393A0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800393A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800393A8: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800393AC: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800393B0: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x800393B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800393B8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800393BC: nop

    // 0x800393C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800393C4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800393C8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800393CC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800393D0: nop

    // 0x800393D4: bc1fl       L_800393E8
    if (!c1cs) {
        // 0x800393D8: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800393E8;
    }
    goto skip_4;
    // 0x800393D8: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_4:
    // 0x800393DC: b           L_800393F0
    // 0x800393E0: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800393F0;
    // 0x800393E0: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800393E4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800393E8:
    // 0x800393E8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800393EC: nop

L_800393F0:
    // 0x800393F0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800393F4: jal         0x80044190
    // 0x800393F8: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80044190(rdram, ctx);
        goto after_8;
    // 0x800393F8: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_8:
    // 0x800393FC: beq         $s0, $zero, L_8003942C
    if (ctx->r16 == 0) {
        // 0x80039400: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8003942C;
    }
    // 0x80039400: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039404: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80039408: sh          $t8, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r24;
    // 0x8003940C: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80039410: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80039414: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x80039418: jal         0x8003FE6C
    // 0x8003941C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_9;
    // 0x8003941C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80039420: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80039424: b           L_80039680
    // 0x80039428: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
        goto L_80039680;
    // 0x80039428: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
L_8003942C:
    // 0x8003942C: jal         0x80044060
    // 0x80039430: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80044060(rdram, ctx);
        goto after_10;
    // 0x80039430: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_10:
    // 0x80039434: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80039438: jal         0x800440E0
    // 0x8003943C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800440E0(rdram, ctx);
        goto after_11;
    // 0x8003943C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x80039440: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80039444: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80039448: jal         0x80039100
    // 0x8003944C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_80039100(rdram, ctx);
        goto after_12;
    // 0x8003944C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_12:
    // 0x80039450: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x80039454: b           L_80039680
    // 0x80039458: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
        goto L_80039680;
    // 0x80039458: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_8003945C:
    // 0x8003945C: lw          $t7, 0x28($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X28);
    // 0x80039460: lbu         $t6, 0x8($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X8);
    // 0x80039464: bne         $fp, $t7, L_80039680
    if (ctx->r30 != ctx->r15) {
        // 0x80039468: sb          $t6, 0x2E($s5)
        MEM_B(0X2E, ctx->r21) = ctx->r14;
            goto L_80039680;
    }
    // 0x80039468: sb          $t6, 0x2E($s5)
    MEM_B(0X2E, ctx->r21) = ctx->r14;
    // 0x8003946C: beq         $s1, $zero, L_80039680
    if (ctx->r17 == 0) {
        // 0x80039470: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80039680;
    }
    // 0x80039470: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039474: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x80039478: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8003947C: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x80039480: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80039484: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80039488: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8003948C: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80039490: bgtzl       $v1, L_800394A0
    if (SIGNED(ctx->r3) > 0) {
        // 0x80039494: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800394A0;
    }
    goto skip_5;
    // 0x80039494: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_5:
    // 0x80039498: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003949C: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800394A0:
    // 0x800394A0: beq         $at, $zero, L_800394B0
    if (ctx->r1 == 0) {
        // 0x800394A4: nop
    
            goto L_800394B0;
    }
    // 0x800394A4: nop

    // 0x800394A8: b           L_800394B0
    // 0x800394AC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800394B0;
    // 0x800394AC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800394B0:
    // 0x800394B0: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x800394B4: jal         0x80044630
    // 0x800394B8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    func_80044630(rdram, ctx);
        goto after_13;
    // 0x800394B8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_13:
    // 0x800394BC: b           L_80039684
    // 0x800394C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x800394C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800394C4:
    // 0x800394C4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x800394C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800394CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800394D0: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800394D4: ldc1        $f8, 0x1E90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1E90);
    // 0x800394D8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800394DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800394E0: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800394E4: nop

    // 0x800394E8: bc1fl       L_800394FC
    if (!c1cs) {
        // 0x800394EC: lw          $t8, 0x28($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X28);
            goto L_800394FC;
    }
    goto skip_6;
    // 0x800394EC: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    skip_6:
    // 0x800394F0: lwc1        $f10, 0x1E98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1E98);
    // 0x800394F4: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x800394F8: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
L_800394FC:
    // 0x800394FC: bnel        $fp, $t8, L_80039684
    if (ctx->r30 != ctx->r24) {
        // 0x80039500: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039684;
    }
    goto skip_7;
    // 0x80039500: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_7:
    // 0x80039504: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80039508: jal         0x80044230
    // 0x8003950C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    func_80044230(rdram, ctx);
        goto after_14;
    // 0x8003950C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    after_14:
    // 0x80039510: b           L_80039684
    // 0x80039514: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x80039514: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039518:
    // 0x80039518: lw          $t6, 0x28($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X28);
    // 0x8003951C: lbu         $t9, 0x8($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X8);
    // 0x80039520: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039524: bne         $fp, $t6, L_80039680
    if (ctx->r30 != ctx->r14) {
        // 0x80039528: sb          $t9, 0x2F($s5)
        MEM_B(0X2F, ctx->r21) = ctx->r25;
            goto L_80039680;
    }
    // 0x80039528: sb          $t9, 0x2F($s5)
    MEM_B(0X2F, ctx->r21) = ctx->r25;
    // 0x8003952C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80039530: jal         0x800446C0
    // 0x80039534: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    func_800446C0(rdram, ctx);
        goto after_15;
    // 0x80039534: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_15:
    // 0x80039538: b           L_80039684
    // 0x8003953C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x8003953C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039540:
    // 0x80039540: lw          $t8, 0x28($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X28);
    // 0x80039544: lh          $t7, 0x8($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X8);
    // 0x80039548: bne         $fp, $t8, L_80039680
    if (ctx->r30 != ctx->r24) {
        // 0x8003954C: sh          $t7, 0x2C($s5)
        MEM_H(0X2C, ctx->r21) = ctx->r15;
            goto L_80039680;
    }
    // 0x8003954C: sh          $t7, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r15;
    // 0x80039550: beql        $s1, $zero, L_80039684
    if (ctx->r17 == 0) {
        // 0x80039554: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039684;
    }
    goto skip_8;
    // 0x80039554: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
    // 0x80039558: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003955C: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x80039560: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80039564: lbu         $t6, 0xD($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD);
    // 0x80039568: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x8003956C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80039570: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039574: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80039578: mflo        $t0
    ctx->r8 = lo;
    // 0x8003957C: nop

    // 0x80039580: nop

    // 0x80039584: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80039588: mflo        $t8
    ctx->r24 = lo;
    // 0x8003958C: sll         $a2, $t8, 16
    ctx->r6 = S32(ctx->r24 << 16);
    // 0x80039590: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80039594: jal         0x80044190
    // 0x80039598: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_80044190(rdram, ctx);
        goto after_16;
    // 0x80039598: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_16:
    // 0x8003959C: b           L_80039684
    // 0x800395A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x800395A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800395A4:
    // 0x800395A4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800395A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800395AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800395B0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800395B4: beql        $v1, $at, L_80039684
    if (ctx->r3 == ctx->r1) {
        // 0x800395B8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80039684;
    }
    goto skip_9;
    // 0x800395B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
    // 0x800395BC: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x800395C0: lh          $t7, 0x2C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X2C);
    // 0x800395C4: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800395C8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800395CC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800395D0: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800395D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800395D8: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800395DC: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800395E0: mflo        $t0
    ctx->r8 = lo;
    // 0x800395E4: nop

    // 0x800395E8: nop

    // 0x800395EC: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800395F0: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800395F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800395F8: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800395FC: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x80039600: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80039604: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80039608: bc1fl       L_8003961C
    if (!c1cs) {
        // 0x8003960C: trunc.w.d   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_8003961C;
    }
    goto skip_10;
    // 0x8003960C: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    skip_10:
    // 0x80039610: b           L_80039624
    // 0x80039614: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_80039624;
    // 0x80039614: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80039618: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
L_8003961C:
    // 0x8003961C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80039620: nop

L_80039624:
    // 0x80039624: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80039628: jal         0x80044190
    // 0x8003962C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    func_80044190(rdram, ctx);
        goto after_17;
    // 0x8003962C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    after_17:
    // 0x80039630: sh          $fp, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r30;
    // 0x80039634: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x80039638: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8003963C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x80039640: jal         0x8003FE6C
    // 0x80039644: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x80039644: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80039648: b           L_80039684
    // 0x8003964C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_80039684;
    // 0x8003964C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039650:
    // 0x80039650: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80039654: jal         0x80044060
    // 0x80039658: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80044060(rdram, ctx);
        goto after_19;
    // 0x80039658: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_19:
    // 0x8003965C: lw          $a0, 0x38($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X38);
    // 0x80039660: jal         0x800440E0
    // 0x80039664: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800440E0(rdram, ctx);
        goto after_20;
    // 0x80039664: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x80039668: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8003966C: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80039670: jal         0x80039100
    // 0x80039674: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    func_80039100(rdram, ctx);
        goto after_21;
    // 0x80039674: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_21:
    // 0x80039678: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x8003967C: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_80039680:
    // 0x80039680: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80039684:
    // 0x80039684: jal         0x8003FF90
    // 0x80039688: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_8003FF90(rdram, ctx);
        goto after_22;
    // 0x80039688: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_22:
    // 0x8003968C: beq         $v0, $zero, L_800391D4
    if (ctx->r2 == 0) {
        // 0x80039690: sw          $v0, 0x4C($s6)
        MEM_W(0X4C, ctx->r22) = ctx->r2;
            goto L_800391D4;
    }
    // 0x80039690: sw          $v0, 0x4C($s6)
    MEM_W(0X4C, ctx->r22) = ctx->r2;
    // 0x80039694: lw          $t7, 0x50($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X50);
    // 0x80039698: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8003969C: sw          $t8, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r24;
    // 0x800396A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800396A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800396A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800396AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800396B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800396B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800396B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800396BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800396C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800396C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800396C8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800396CC: jr          $ra
    // 0x800396D0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800396D0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80010B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010B60: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80010B64: lw          $t6, -0x4D0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D0C);
    // 0x80010B68: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010B6C: addiu       $a0, $a0, 0x55E0
    ctx->r4 = ADD32(ctx->r4, 0X55E0);
    // 0x80010B70: beq         $t6, $zero, L_80010B84
    if (ctx->r14 == 0) {
        // 0x80010B74: nop
    
            goto L_80010B84;
    }
    // 0x80010B74: nop

    // 0x80010B78: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80010B7C: b           L_80010B84
    // 0x80010B80: addiu       $a0, $a0, 0x5618
    ctx->r4 = ADD32(ctx->r4, 0X5618);
        goto L_80010B84;
    // 0x80010B80: addiu       $a0, $a0, 0x5618
    ctx->r4 = ADD32(ctx->r4, 0X5618);
L_80010B84:
    // 0x80010B84: jal         0x80010CAC
    // 0x80010B88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80010CAC(rdram, ctx);
        goto after_0;
    // 0x80010B88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80010B8C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80010B90: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80010B94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80010B98: addiu       $a2, $a2, 0x5B98
    ctx->r6 = ADD32(ctx->r6, 0X5B98);
    // 0x80010B9C: jal         0x80011768
    // 0x80010BA0: addiu       $a1, $a1, 0x5B68
    ctx->r5 = ADD32(ctx->r5, 0X5B68);
    func_80011768(rdram, ctx);
        goto after_1;
    // 0x80010BA0: addiu       $a1, $a1, 0x5B68
    ctx->r5 = ADD32(ctx->r5, 0X5B68);
    after_1:
    // 0x80010BA4: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80010BA8: addiu       $t1, $t1, 0x5BC8
    ctx->r9 = ADD32(ctx->r9, 0X5BC8);
    // 0x80010BAC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80010BB0: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x80010BB4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80010BB8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80010BBC: addiu       $t2, $t2, -0x4CE6
    ctx->r10 = ADD32(ctx->r10, -0X4CE6);
    // 0x80010BC0: addiu       $t0, $t0, -0x4CE8
    ctx->r8 = ADD32(ctx->r8, -0X4CE8);
    // 0x80010BC4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80010BC8: addiu       $a3, $a3, -0x4D04
    ctx->r7 = ADD32(ctx->r7, -0X4D04);
    // 0x80010BCC: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x80010BD0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x80010BD4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80010BD8: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x80010BDC: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x80010BE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80010BE4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80010BE8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80010BEC: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80010BF0: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x80010BF4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80010BF8: ori         $t5, $t5, 0xF400
    ctx->r13 = ctx->r13 | 0XF400;
    // 0x80010BFC: subu        $a1, $t4, $a0
    ctx->r5 = SUB32(ctx->r12, ctx->r4);
    // 0x80010C00: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x80010C04: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x80010C08: sll         $t3, $t9, 8
    ctx->r11 = S32(ctx->r25 << 8);
    // 0x80010C0C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x80010C10: mflo        $t6
    ctx->r14 = lo;
    // 0x80010C14: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x80010C18: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80010C1C: div         $zero, $t4, $a1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r5)));
    // 0x80010C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80010C24: bne         $a1, $zero, L_80010C30
    if (ctx->r5 != 0) {
        // 0x80010C28: nop
    
            goto L_80010C30;
    }
    // 0x80010C28: nop

    // 0x80010C2C: break       7
    do_break(2147552300);
L_80010C30:
    // 0x80010C30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010C34: bne         $a1, $at, L_80010C48
    if (ctx->r5 != ctx->r1) {
        // 0x80010C38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010C48;
    }
    // 0x80010C38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010C3C: bne         $t5, $at, L_80010C48
    if (ctx->r13 != ctx->r1) {
        // 0x80010C40: nop
    
            goto L_80010C48;
    }
    // 0x80010C40: nop

    // 0x80010C44: break       6
    do_break(2147552324);
L_80010C48:
    // 0x80010C48: addu        $at, $t5, $zero
    ctx->r1 = ADD32(ctx->r13, 0);
    // 0x80010C4C: mflo        $t5
    ctx->r13 = lo;
    // 0x80010C50: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80010C54: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80010C58: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80010C5C: bne         $a1, $zero, L_80010C68
    if (ctx->r5 != 0) {
        // 0x80010C60: nop
    
            goto L_80010C68;
    }
    // 0x80010C60: nop

    // 0x80010C64: break       7
    do_break(2147552356);
L_80010C68:
    // 0x80010C68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010C6C: bne         $a1, $at, L_80010C80
    if (ctx->r5 != ctx->r1) {
        // 0x80010C70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010C80;
    }
    // 0x80010C70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010C74: bne         $t4, $at, L_80010C80
    if (ctx->r12 != ctx->r1) {
        // 0x80010C78: nop
    
            goto L_80010C80;
    }
    // 0x80010C78: nop

    // 0x80010C7C: break       6
    do_break(2147552380);
L_80010C80:
    // 0x80010C80: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80010C84: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80010C88: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80010C8C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80010C90: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80010C94: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80010C98: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80010C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010CA4: jr          $ra
    // 0x80010CA8: nop

    return;
    // 0x80010CA8: nop

;}
RECOMP_FUNC void func_800208B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800208B8: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800208BC: lhu         $t6, -0x3998($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3998);
    // 0x800208C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800208C4: addiu       $v0, $v0, -0x3998
    ctx->r2 = ADD32(ctx->r2, -0X3998);
    // 0x800208C8: beq         $t6, $zero, L_800208E8
    if (ctx->r14 == 0) {
        // 0x800208CC: addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
            goto L_800208E8;
    }
    // 0x800208CC: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x800208D0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800208D4:
    // 0x800208D4: beq         $v1, $zero, L_800208E8
    if (ctx->r3 == 0) {
        // 0x800208D8: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_800208E8;
    }
    // 0x800208D8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x800208DC: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800208E0: bnel        $t7, $zero, L_800208D4
    if (ctx->r15 != 0) {
        // 0x800208E4: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_800208D4;
    }
    goto skip_0;
    // 0x800208E4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
L_800208E8:
    // 0x800208E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800208EC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800208F0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800208F4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800208F8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800208FC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80020900: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80020904: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020908: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x8002090C: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x80020910: addiu       $t1, $zero, 0x31
    ctx->r9 = ADD32(0, 0X31);
    // 0x80020914: addiu       $t2, $zero, 0x29
    ctx->r10 = ADD32(0, 0X29);
    // 0x80020918: bne         $a1, $zero, L_80020934
    if (ctx->r5 != 0) {
        // 0x8002091C: addiu       $t3, $zero, 0xE
        ctx->r11 = ADD32(0, 0XE);
            goto L_80020934;
    }
    // 0x8002091C: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80020920: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80020924: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80020928: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002092C: b           L_80020970
    // 0x80020930: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
        goto L_80020970;
    // 0x80020930: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_80020934:
    // 0x80020934: bnel        $a1, $at, L_80020958
    if (ctx->r5 != ctx->r1) {
        // 0x80020938: lwc1        $f4, 0x24($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
            goto L_80020958;
    }
    goto skip_1;
    // 0x80020938: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x8002093C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x80020940: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80020944: lwc1        $f10, 0x94($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X94);
    // 0x80020948: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002094C: b           L_80020970
    // 0x80020950: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
        goto L_80020970;
    // 0x80020950: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80020954: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
L_80020958:
    // 0x80020958: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002095C: ldc1        $f8, 0x16C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X16C8);
    // 0x80020960: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80020964: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80020968: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002096C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
L_80020970:
    // 0x80020970: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // 0x80020974: sh          $t1, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r9;
    // 0x80020978: sh          $t2, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r10;
    // 0x8002097C: sh          $t3, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r11;
    // 0x80020980: jr          $ra
    // 0x80020984: nop

    return;
    // 0x80020984: nop

;}
RECOMP_FUNC void func_800041B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800041B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800041BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800041C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800041C4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800041C8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800041CC: addiu       $a2, $a2, -0x43D0
    ctx->r6 = ADD32(ctx->r6, -0X43D0);
    // 0x800041D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800041D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800041D8: jal         0x800056D0
    // 0x800041DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800056D0(rdram, ctx);
        goto after_0;
    // 0x800041DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800041E0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800041E4: addiu       $v0, $v0, -0x43D0
    ctx->r2 = ADD32(ctx->r2, -0X43D0);
    // 0x800041E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800041EC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800041F0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800041F4: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
    // 0x800041F8: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x800041FC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80004200: jal         0x80005748
    // 0x80004204: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    func_80005748(rdram, ctx);
        goto after_1;
    // 0x80004204: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x80004208: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8000420C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004210: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80004214: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x80004218: lhu         $t8, 0x120($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X120);
    // 0x8000421C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80004220: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004224: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80004228: bne         $t8, $t9, L_80004250
    if (ctx->r24 != ctx->r25) {
        // 0x8000422C: sh          $t7, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r15;
            goto L_80004250;
    }
    // 0x8000422C: sh          $t7, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r15;
    // 0x80004230: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004234: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80004238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000423C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004240: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x80004244: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80004248: lwc1        $f16, 0xF58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XF58);
    // 0x8000424C: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
L_80004250:
    // 0x80004250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004258: jr          $ra
    // 0x8000425C: nop

    return;
    // 0x8000425C: nop

;}
RECOMP_FUNC void func_8003FD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FD50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003FD54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003FD58: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x8003FD5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8003FD60: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003FD64: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8003FD68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003FD6C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x8003FD70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003FD74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003FD78: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8003FD7C: jal         0x80034160
    // 0x8003FD80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8003FD80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8003FD84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003FD88: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x8003FD8C: beq         $s0, $zero, L_8003FDD8
    if (ctx->r16 == 0) {
        // 0x8003FD90: nop
    
            goto L_8003FDD8;
    }
    // 0x8003FD90: nop

L_8003FD94:
    // 0x8003FD94: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8003FD98: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8003FD9C: bne         $s3, $t7, L_8003FDD0
    if (ctx->r19 != ctx->r15) {
        // 0x8003FDA0: nop
    
            goto L_8003FDD0;
    }
    // 0x8003FDA0: nop

    // 0x8003FDA4: beq         $s1, $zero, L_8003FDBC
    if (ctx->r17 == 0) {
        // 0x8003FDA8: nop
    
            goto L_8003FDBC;
    }
    // 0x8003FDA8: nop

    // 0x8003FDAC: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8003FDB0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8003FDB4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8003FDB8: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_8003FDBC:
    // 0x8003FDBC: jal         0x80036820
    // 0x8003FDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x8003FDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003FDC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FDC8: jal         0x80036850
    // 0x8003FDCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x8003FDCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_8003FDD0:
    // 0x8003FDD0: bne         $s1, $zero, L_8003FD94
    if (ctx->r17 != 0) {
        // 0x8003FDD4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003FD94;
    }
    // 0x8003FDD4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8003FDD8:
    // 0x8003FDD8: jal         0x80034160
    // 0x8003FDDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8003FDDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8003FDE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003FDE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003FDE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003FDEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FDF0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8003FDF4: jr          $ra
    // 0x8003FDF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003FDF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035A00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80035A04: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80035A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035A0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80035A10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80035A14: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80035A18: jal         0x80035300
    // 0x80035A1C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80035A1C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80035A20: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80035A24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035A28: ldc1        $f6, 0x1B90($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1B90);
    // 0x80035A2C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80035A30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035A34: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80035A38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80035A3C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80035A40: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80035A44: jal         0x800361F0
    // 0x80035A48: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80035A48: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80035A4C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80035A50: jal         0x80035680
    // 0x80035A54: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035A54: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80035A58: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80035A5C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80035A60: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035A64: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80035A68: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80035A6C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80035A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035A74: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80035A78: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80035A7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035A80: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80035A84: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80035A88: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80035A8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80035A90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80035A94: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80035A98: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x80035A9C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80035AA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035AA4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80035AA8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80035AAC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80035AB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80035AB4: nop

    // 0x80035AB8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x80035ABC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80035AC0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80035AC4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80035AC8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80035ACC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80035AD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80035AD4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80035AD8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80035ADC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80035AE0: beq         $v1, $a0, L_80035B24
    if (ctx->r3 == ctx->r4) {
        // 0x80035AE4: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80035B24;
    }
    // 0x80035AE4: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_80035AE8:
    // 0x80035AE8: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035AEC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80035AF0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035AF4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80035AF8: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80035AFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80035B00: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80035B04: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80035B08: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80035B0C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80035B10: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80035B14: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80035B18: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80035B1C: bne         $v1, $a0, L_80035AE8
    if (ctx->r3 != ctx->r4) {
        // 0x80035B20: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_80035AE8;
    }
    // 0x80035B20: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_80035B24:
    // 0x80035B24: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035B28: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80035B2C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80035B30: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80035B34: nop

    // 0x80035B38: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80035B3C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80035B40: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80035B44: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80035B48: beq         $a1, $zero, L_80035C20
    if (ctx->r5 == 0) {
        // 0x80035B4C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80035C20;
    }
    // 0x80035B4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035B50: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80035B54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035B58: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80035B5C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80035B60: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x80035B64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80035B68: bc1fl       L_80035B7C
    if (!c1cs) {
        // 0x80035B6C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_80035B7C;
    }
    goto skip_0;
    // 0x80035B6C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80035B70: b           L_80035C20
    // 0x80035B74: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_80035C20;
    // 0x80035B74: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80035B78: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_80035B7C:
    // 0x80035B7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80035B80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80035B84: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80035B88: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80035B8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80035B90: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80035B94: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80035B98: nop

    // 0x80035B9C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80035BA0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80035BA4: nop

    // 0x80035BA8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80035BAC: beql        $t8, $zero, L_80035C00
    if (ctx->r24 == 0) {
        // 0x80035BB0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80035C00;
    }
    goto skip_1;
    // 0x80035BB0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80035BB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80035BB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80035BBC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80035BC0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80035BC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80035BC8: nop

    // 0x80035BCC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x80035BD0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80035BD4: nop

    // 0x80035BD8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80035BDC: bne         $t8, $zero, L_80035BF4
    if (ctx->r24 != 0) {
        // 0x80035BE0: nop
    
            goto L_80035BF4;
    }
    // 0x80035BE0: nop

    // 0x80035BE4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80035BE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80035BEC: b           L_80035C0C
    // 0x80035BF0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80035C0C;
    // 0x80035BF0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80035BF4:
    // 0x80035BF4: b           L_80035C0C
    // 0x80035BF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80035C0C;
    // 0x80035BF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80035BFC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80035C00:
    // 0x80035C00: nop

    // 0x80035C04: bltz        $t8, L_80035BF4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80035C08: nop
    
            goto L_80035BF4;
    }
    // 0x80035C08: nop

L_80035C0C:
    // 0x80035C0C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80035C10: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80035C14: bgtz        $t9, L_80035C20
    if (SIGNED(ctx->r25) > 0) {
        // 0x80035C18: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_80035C20;
    }
    // 0x80035C18: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80035C1C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_80035C20:
    // 0x80035C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035C24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80035C28: jr          $ra
    // 0x80035C2C: nop

    return;
    // 0x80035C2C: nop

;}
RECOMP_FUNC void nnScExecuteAudio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000900: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80000904: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000908: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000090C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80000910: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80000914: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80000918: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000091C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80000920: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000924: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000928: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000092C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000930: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80000934: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80000938: addiu       $s5, $s2, 0x4
    ctx->r21 = ADD32(ctx->r18, 0X4);
    // 0x8000093C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000940: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80000944: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80000948: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8000094C: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x80000950: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000954:
    // 0x80000954: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80000958: jal         0x80034020
    // 0x8000095C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000095C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000960: jal         0x80034350
    // 0x80000964: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80000964: nop

    after_1:
    // 0x80000968: lw          $s3, 0x66C($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X66C);
    // 0x8000096C: beql        $s3, $zero, L_800009A8
    if (ctx->r19 == 0) {
        // 0x80000970: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800009A8;
    }
    goto skip_0;
    // 0x80000970: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80000974: jal         0x80034380
    // 0x80000978: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    osSpTaskYield_recomp(rdram, ctx);
        goto after_2;
    // 0x80000978: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    after_2:
    // 0x8000097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000980: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000984: jal         0x80034020
    // 0x80000988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80000988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8000098C: jal         0x800343A0
    // 0x80000990: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_4;
    // 0x80000990: addiu       $a0, $s3, 0x10
    ctx->r4 = ADD32(ctx->r19, 0X10);
    after_4:
    // 0x80000994: beq         $v0, $zero, L_800009A4
    if (ctx->r2 == 0) {
        // 0x80000998: or          $s1, $fp, $zero
        ctx->r17 = ctx->r30 | 0;
            goto L_800009A4;
    }
    // 0x80000998: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x8000099C: b           L_800009A4
    // 0x800009A0: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
        goto L_800009A4;
    // 0x800009A0: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
L_800009A4:
    // 0x800009A4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800009A8:
    // 0x800009A8: addiu       $s0, $s2, 0xAC
    ctx->r16 = ADD32(ctx->r18, 0XAC);
    // 0x800009AC: sw          $t6, 0x670($s2)
    MEM_W(0X670, ctx->r18) = ctx->r14;
    // 0x800009B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800009B4: jal         0x8003452C
    // 0x800009B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_5;
    // 0x800009B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_5:
    // 0x800009BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800009C0: jal         0x80034694
    // 0x800009C4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_6;
    // 0x800009C4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x800009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800009CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800009D0: jal         0x80034020
    // 0x800009D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800009D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800009D8: lw          $t7, 0x674($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X674);
    // 0x800009DC: sw          $zero, 0x670($s2)
    MEM_W(0X670, ctx->r18) = 0;
    // 0x800009E0: addiu       $a0, $s2, 0x11C
    ctx->r4 = ADD32(ctx->r18, 0X11C);
    // 0x800009E4: beq         $t7, $zero, L_800009F4
    if (ctx->r15 == 0) {
        // 0x800009E8: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800009F4;
    }
    // 0x800009E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800009EC: jal         0x80034200
    // 0x800009F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800009F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_800009F4:
    // 0x800009F4: bne         $s1, $s7, L_80000A18
    if (ctx->r17 != ctx->r23) {
        // 0x800009F8: nop
    
            goto L_80000A18;
    }
    // 0x800009F8: nop

    // 0x800009FC: addiu       $s0, $s3, 0x10
    ctx->r16 = ADD32(ctx->r19, 0X10);
    // 0x80000A00: jal         0x8003452C
    // 0x80000A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_9;
    // 0x80000A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80000A08: jal         0x80034694
    // 0x80000A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_10;
    // 0x80000A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80000A10: b           L_80000A30
    // 0x80000A14: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
        goto L_80000A30;
    // 0x80000A14: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_80000A18:
    // 0x80000A18: bne         $s1, $fp, L_80000A2C
    if (ctx->r17 != ctx->r30) {
        // 0x80000A1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80000A2C;
    }
    // 0x80000A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000A20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80000A24: jal         0x80034200
    // 0x80000A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80000A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_80000A2C:
    // 0x80000A2C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_80000A30:
    // 0x80000A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80000A34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000A38: lw          $a0, 0x50($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X50);
    // 0x80000A3C: jal         0x80034200
    // 0x80000A40: lw          $a1, 0x54($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X54);
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80000A40: lw          $a1, 0x54($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X54);
    after_12:
    // 0x80000A44: b           L_80000954
    // 0x80000A48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000954;
    // 0x80000A48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80000A4C: nop

    // 0x80000A50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80000A54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000A58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000A5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000A60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000A64: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000A68: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000A6C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80000A70: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80000A74: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80000A78: jr          $ra
    // 0x80000A7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80000A7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80042ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042ECC: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80042ED0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042ED4: lbu         $s6, 0x8($a0)
    ctx->r22 = MEM_BU(ctx->r4, 0X8);
    // 0x80042ED8: lbu         $s3, 0x9($a0)
    ctx->r19 = MEM_BU(ctx->r4, 0X9);
    // 0x80042EDC: lbu         $s4, 0xA($a0)
    ctx->r20 = MEM_BU(ctx->r4, 0XA);
    // 0x80042EE0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x80042EE4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x80042EE8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x80042EEC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x80042EF0: beq         $at, $zero, L_800436D4
    if (ctx->r1 == 0) {
        // 0x80042EF4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800436D4;
    }
    // 0x80042EF4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80042EF8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80042EFC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80042F00: addu        $at, $at, $t7
    gpr jr_addend_80042F08 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80042F04: lw          $t7, 0x20E0($at)
    ctx->r15 = ADD32(ctx->r1, 0X20E0);
    // 0x80042F08: jr          $t7
    // 0x80042F0C: nop

    switch (jr_addend_80042F08 >> 2) {
        case 0: goto L_80043264; break;
        case 1: goto L_800436D4; break;
        case 2: goto L_800436D4; break;
        case 3: goto L_800436D4; break;
        case 4: goto L_800436D4; break;
        case 5: goto L_800436D4; break;
        case 6: goto L_800436D4; break;
        case 7: goto L_800436D4; break;
        case 8: goto L_800436D4; break;
        case 9: goto L_800436D4; break;
        case 10: goto L_800436D4; break;
        case 11: goto L_800436D4; break;
        case 12: goto L_800436D4; break;
        case 13: goto L_800436D4; break;
        case 14: goto L_800436D4; break;
        case 15: goto L_800436D4; break;
        case 16: goto L_80042F10; break;
        case 17: goto L_800436D4; break;
        case 18: goto L_800436D4; break;
        case 19: goto L_800436D4; break;
        case 20: goto L_800436D4; break;
        case 21: goto L_800436D4; break;
        case 22: goto L_800436D4; break;
        case 23: goto L_800436D4; break;
        case 24: goto L_800436D4; break;
        case 25: goto L_800436D4; break;
        case 26: goto L_800436D4; break;
        case 27: goto L_800436D4; break;
        case 28: goto L_800436D4; break;
        case 29: goto L_800436D4; break;
        case 30: goto L_800436D4; break;
        case 31: goto L_800436D4; break;
        case 32: goto L_800432BC; break;
        case 33: goto L_800436D4; break;
        case 34: goto L_800436D4; break;
        case 35: goto L_800436D4; break;
        case 36: goto L_800436D4; break;
        case 37: goto L_800436D4; break;
        case 38: goto L_800436D4; break;
        case 39: goto L_800436D4; break;
        case 40: goto L_800436D4; break;
        case 41: goto L_800436D4; break;
        case 42: goto L_800436D4; break;
        case 43: goto L_800436D4; break;
        case 44: goto L_800436D4; break;
        case 45: goto L_800436D4; break;
        case 46: goto L_800436D4; break;
        case 47: goto L_800436D4; break;
        case 48: goto L_8004339C; break;
        case 49: goto L_800436D4; break;
        case 50: goto L_800436D4; break;
        case 51: goto L_800436D4; break;
        case 52: goto L_800436D4; break;
        case 53: goto L_800436D4; break;
        case 54: goto L_800436D4; break;
        case 55: goto L_800436D4; break;
        case 56: goto L_800436D4; break;
        case 57: goto L_800436D4; break;
        case 58: goto L_800436D4; break;
        case 59: goto L_800436D4; break;
        case 60: goto L_800436D4; break;
        case 61: goto L_800436D4; break;
        case 62: goto L_800436D4; break;
        case 63: goto L_800436D4; break;
        case 64: goto L_80043608; break;
        case 65: goto L_800436D4; break;
        case 66: goto L_800436D4; break;
        case 67: goto L_800436D4; break;
        case 68: goto L_800436D4; break;
        case 69: goto L_800436D4; break;
        case 70: goto L_800436D4; break;
        case 71: goto L_800436D4; break;
        case 72: goto L_800436D4; break;
        case 73: goto L_800436D4; break;
        case 74: goto L_800436D4; break;
        case 75: goto L_800436D4; break;
        case 76: goto L_800436D4; break;
        case 77: goto L_800436D4; break;
        case 78: goto L_800436D4; break;
        case 79: goto L_800436D4; break;
        case 80: goto L_80043324; break;
        case 81: goto L_800436D4; break;
        case 82: goto L_800436D4; break;
        case 83: goto L_800436D4; break;
        case 84: goto L_800436D4; break;
        case 85: goto L_800436D4; break;
        case 86: goto L_800436D4; break;
        case 87: goto L_800436D4; break;
        case 88: goto L_800436D4; break;
        case 89: goto L_800436D4; break;
        case 90: goto L_800436D4; break;
        case 91: goto L_800436D4; break;
        case 92: goto L_800436D4; break;
        case 93: goto L_800436D4; break;
        case 94: goto L_800436D4; break;
        case 95: goto L_800436D4; break;
        case 96: goto L_8004363C; break;
        default: switch_error(__func__, 0x80042F08, 0x800720E0);
    }
    // 0x80042F0C: nop

L_80042F10:
    // 0x80042F10: beql        $s4, $zero, L_80043268
    if (ctx->r20 == 0) {
        // 0x80042F14: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80043268;
    }
    goto skip_0;
    // 0x80042F14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80042F18: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x80042F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042F20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80042F24: bne         $t8, $at, L_800436D4
    if (ctx->r24 != ctx->r1) {
        // 0x80042F28: andi        $a1, $s3, 0xFF
        ctx->r5 = ctx->r19 & 0XFF;
            goto L_800436D4;
    }
    // 0x80042F28: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80042F2C: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80042F30: jal         0x80042DD0
    // 0x80042F34: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    func_80042DD0(rdram, ctx);
        goto after_0;
    // 0x80042F34: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    after_0:
    // 0x80042F38: beq         $v0, $zero, L_800436D4
    if (ctx->r2 == 0) {
        // 0x80042F3C: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800436D4;
    }
    // 0x80042F3C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80042F40: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x80042F44: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x80042F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80042F4C: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x80042F50: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x80042F54: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x80042F58: sb          $zero, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = 0;
    // 0x80042F5C: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x80042F60: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80042F64: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x80042F68: jal         0x80042D60
    // 0x80042F6C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    func_80042D60(rdram, ctx);
        goto after_1;
    // 0x80042F6C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80042F70: beq         $v0, $zero, L_800436D4
    if (ctx->r2 == 0) {
        // 0x80042F74: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800436D4;
    }
    // 0x80042F74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80042F78: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80042F7C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80042F80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80042F84: jal         0x800443A8
    // 0x80042F88: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    func_800443A8(rdram, ctx);
        goto after_2;
    // 0x80042F88: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    after_2:
    // 0x80042F8C: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x80042F90: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80042F94: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x80042F98: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80042F9C: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x80042FA0: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x80042FA4: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80042FA8: bnel        $at, $zero, L_80042FBC
    if (ctx->r1 != 0) {
        // 0x80042FAC: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_80042FBC;
    }
    goto skip_1;
    // 0x80042FAC: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x80042FB0: b           L_80042FBC
    // 0x80042FB4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_80042FBC;
    // 0x80042FB4: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x80042FB8: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80042FBC:
    // 0x80042FBC: lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X4);
    // 0x80042FC0: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80042FC4: lb          $t6, 0x5($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5);
    // 0x80042FC8: subu        $t8, $s3, $t7
    ctx->r24 = SUB32(ctx->r19, ctx->r15);
    // 0x80042FCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80042FD0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80042FD4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80042FD8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80042FDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80042FE0: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80042FE4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80042FE8: jal         0x800444F0
    // 0x80042FEC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x80042FEC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x80042FF0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80042FF4: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80042FF8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80042FFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043000: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x80043004: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x80043008: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8004300C: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x80043010: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80043014: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x80043018: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8004301C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80043020: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x80043024: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x80043028: lw          $s2, 0x0($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X0);
    // 0x8004302C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80043030: lbu         $a2, 0x4($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4);
    // 0x80043034: beql        $a2, $zero, L_800430A0
    if (ctx->r6 == 0) {
        // 0x80043038: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800430A0;
    }
    goto skip_2;
    // 0x80043038: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x8004303C: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80043040: beql        $v0, $zero, L_800430A0
    if (ctx->r2 == 0) {
        // 0x80043044: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800430A0;
    }
    goto skip_3;
    // 0x80043044: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x80043048: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x8004304C: lbu         $a3, 0x5($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X5);
    // 0x80043050: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80043054: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80043058: lbu         $t6, 0x7($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X7);
    // 0x8004305C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80043060: jalr        $v0
    // 0x80043064: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80043064: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x80043068: beq         $v0, $zero, L_8004309C
    if (ctx->r2 == 0) {
        // 0x8004306C: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_8004309C;
    }
    // 0x8004306C: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80043070: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80043074: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x80043078: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x8004307C: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x80043080: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80043084: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80043088: jal         0x8003FE6C
    // 0x8004308C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x8004308C: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_5:
    // 0x80043090: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x80043094: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x80043098: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_8004309C:
    // 0x8004309C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800430A0:
    // 0x800430A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800430A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800430A8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800430AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800430B0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800430B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800430B8: nop

    // 0x800430BC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800430C0: beql        $t7, $zero, L_80043110
    if (ctx->r15 == 0) {
        // 0x800430C4: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_80043110;
    }
    goto skip_4;
    // 0x800430C4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x800430C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800430CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800430D0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800430D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800430D8: nop

    // 0x800430DC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800430E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800430E4: nop

    // 0x800430E8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800430EC: bne         $t7, $zero, L_80043104
    if (ctx->r15 != 0) {
        // 0x800430F0: nop
    
            goto L_80043104;
    }
    // 0x800430F0: nop

    // 0x800430F4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800430F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800430FC: b           L_8004311C
    // 0x80043100: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8004311C;
    // 0x80043100: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80043104:
    // 0x80043104: b           L_8004311C
    // 0x80043108: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8004311C;
    // 0x80043108: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8004310C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_80043110:
    // 0x80043110: nop

    // 0x80043114: bltz        $t7, L_80043104
    if (SIGNED(ctx->r15) < 0) {
        // 0x80043118: nop
    
            goto L_80043104;
    }
    // 0x80043118: nop

L_8004311C:
    // 0x8004311C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043120: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043124: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x80043128: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004312C: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80043130: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x80043134: addiu       $s5, $s1, 0x48
    ctx->r21 = ADD32(ctx->r17, 0X48);
    // 0x80043138: beql        $a2, $zero, L_800431A8
    if (ctx->r6 == 0) {
        // 0x8004313C: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800431A8;
    }
    goto skip_5;
    // 0x8004313C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_5:
    // 0x80043140: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80043144: beql        $v0, $zero, L_800431A8
    if (ctx->r2 == 0) {
        // 0x80043148: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800431A8;
    }
    goto skip_6;
    // 0x80043148: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_6:
    // 0x8004314C: lbu         $t9, 0xA($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA);
    // 0x80043150: lbu         $a3, 0x9($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X9);
    // 0x80043154: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80043158: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004315C: lbu         $t6, 0xB($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XB);
    // 0x80043160: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80043164: jalr        $v0
    // 0x80043168: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80043168: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x8004316C: beq         $v0, $zero, L_800431A4
    if (ctx->r2 == 0) {
        // 0x80043170: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800431A4;
    }
    // 0x80043170: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80043174: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80043178: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x8004317C: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x80043180: sb          $s6, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r22;
    // 0x80043184: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043188: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x8004318C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80043190: jal         0x8003FE6C
    // 0x80043194: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x80043194: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_7:
    // 0x80043198: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x8004319C: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800431A0: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800431A4:
    // 0x800431A4: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
L_800431A8:
    // 0x800431A8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800431AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800431B0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800431B4: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x800431B8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800431BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800431C0: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800431C4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800431C8: lbu         $s2, 0xA($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0XA);
    // 0x800431CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800431D0: nop

    // 0x800431D4: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800431D8: jal         0x80042CA4
    // 0x800431DC: nop

    func_80042CA4(rdram, ctx);
        goto after_8;
    // 0x800431DC: nop

    after_8:
    // 0x800431E0: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x800431E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800431E8: jal         0x80042884
    // 0x800431EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042884(rdram, ctx);
        goto after_9;
    // 0x800431EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800431F0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800431F4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800431F8: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x800431FC: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x80043200: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80043204: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80043208: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8004320C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80043210: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80043214: jal         0x80044540
    // 0x80043218: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    func_80044540(rdram, ctx);
        goto after_10;
    // 0x80043218: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x8004321C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80043220: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80043224: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x80043228: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x8004322C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80043230: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80043234: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80043238: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x8004323C: sb          $t7, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r15;
    // 0x80043240: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80043244: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x80043248: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x8004324C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80043250: lw          $s3, 0x0($t8)
    ctx->r19 = MEM_W(ctx->r24, 0X0);
    // 0x80043254: jal         0x8003FE6C
    // 0x80043258: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x80043258: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x8004325C: b           L_800436D8
    // 0x80043260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x80043260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80043264:
    // 0x80043264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80043268:
    // 0x80043268: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x8004326C: jal         0x80042CEC
    // 0x80043270: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_80042CEC(rdram, ctx);
        goto after_12;
    // 0x80043270: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_12:
    // 0x80043274: beq         $v0, $zero, L_800436D4
    if (ctx->r2 == 0) {
        // 0x80043278: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800436D4;
    }
    // 0x80043278: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004327C: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x80043280: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80043284: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80043288: bne         $s6, $t7, L_80043298
    if (ctx->r22 != ctx->r15) {
        // 0x8004328C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80043298;
    }
    // 0x8004328C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043290: b           L_800436D4
    // 0x80043294: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800436D4;
    // 0x80043294: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_80043298:
    // 0x80043298: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8004329C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800432A0: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800432A4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800432A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800432AC: jal         0x8004290C
    // 0x800432B0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    func_8004290C(rdram, ctx);
        goto after_13;
    // 0x800432B0: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_13:
    // 0x800432B4: b           L_800436D8
    // 0x800432B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x800432B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800432BC:
    // 0x800432BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800432C0: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // 0x800432C4: jal         0x80042CEC
    // 0x800432C8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    func_80042CEC(rdram, ctx);
        goto after_14;
    // 0x800432C8: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_14:
    // 0x800432CC: beq         $v0, $zero, L_800436D4
    if (ctx->r2 == 0) {
        // 0x800432D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800436D4;
    }
    // 0x800432D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800432D4: sb          $s4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r20;
    // 0x800432D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800432DC: jal         0x80042884
    // 0x800432E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042884(rdram, ctx);
        goto after_15;
    // 0x800432E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x800432E4: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800432E8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800432EC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800432F0: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800432F4: subu        $a0, $t9, $v1
    ctx->r4 = SUB32(ctx->r25, ctx->r3);
    // 0x800432F8: bltz        $a0, L_80043308
    if (SIGNED(ctx->r4) < 0) {
        // 0x800432FC: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80043308;
    }
    // 0x800432FC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80043300: b           L_8004330C
    // 0x80043304: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8004330C;
    // 0x80043304: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80043308:
    // 0x80043308: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_8004330C:
    // 0x8004330C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80043310: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80043314: jal         0x80044190
    // 0x80043318: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_16;
    // 0x80043318: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_16:
    // 0x8004331C: b           L_800436D8
    // 0x80043320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x80043320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80043324:
    // 0x80043324: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80043328: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x8004332C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_7;
    // 0x8004332C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80043330: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80043334: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_80043338:
    // 0x80043338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004333C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80043340: bnel        $s2, $t6, L_8004338C
    if (ctx->r18 != ctx->r14) {
        // 0x80043344: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8004338C;
    }
    goto skip_8;
    // 0x80043344: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x80043348: jal         0x80042884
    // 0x8004334C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    func_80042884(rdram, ctx);
        goto after_17;
    // 0x8004334C: sb          $s3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r19;
    after_17:
    // 0x80043350: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80043354: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80043358: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8004335C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80043360: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x80043364: bltz        $a0, L_80043374
    if (SIGNED(ctx->r4) < 0) {
        // 0x80043368: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80043374;
    }
    // 0x80043368: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8004336C: b           L_80043378
    // 0x80043370: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80043378;
    // 0x80043370: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80043374:
    // 0x80043374: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80043378:
    // 0x80043378: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8004337C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80043380: jal         0x80044190
    // 0x80043384: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_18;
    // 0x80043384: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x80043388: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8004338C:
    // 0x8004338C: bnel        $s0, $zero, L_80043338
    if (ctx->r16 != 0) {
        // 0x80043390: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_80043338;
    }
    goto skip_9;
    // 0x80043390: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_9:
    // 0x80043394: b           L_800436D8
    // 0x80043398: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x80043398: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004339C:
    // 0x8004339C: slti        $at, $s3, 0x41
    ctx->r1 = SIGNED(ctx->r19) < 0X41 ? 1 : 0;
    // 0x800433A0: bne         $at, $zero, L_800433C4
    if (ctx->r1 != 0) {
        // 0x800433A4: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_800433C4;
    }
    // 0x800433A4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800433A8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800433AC: beq         $v0, $at, L_800435B8
    if (ctx->r2 == ctx->r1) {
        // 0x800433B0: addiu       $at, $zero, 0x5D
        ctx->r1 = ADD32(0, 0X5D);
            goto L_800435B8;
    }
    // 0x800433B0: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x800433B4: beql        $v0, $at, L_800436D8
    if (ctx->r2 == ctx->r1) {
        // 0x800433B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_10;
    // 0x800433B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800433BC: b           L_800436D8
    // 0x800433C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x800433C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800433C4:
    // 0x800433C4: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x800433C8: bne         $at, $zero, L_800433E4
    if (ctx->r1 != 0) {
        // 0x800433CC: addiu       $t9, $v0, -0x7
        ctx->r25 = ADD32(ctx->r2, -0X7);
            goto L_800433E4;
    }
    // 0x800433CC: addiu       $t9, $v0, -0x7
    ctx->r25 = ADD32(ctx->r2, -0X7);
    // 0x800433D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800433D4: beql        $v0, $at, L_8004350C
    if (ctx->r2 == ctx->r1) {
        // 0x800433D8: lw          $t7, 0x60($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X60);
            goto L_8004350C;
    }
    goto skip_11;
    // 0x800433D8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    skip_11:
    // 0x800433DC: b           L_800436D8
    // 0x800433E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x800433E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800433E4:
    // 0x800433E4: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x800433E8: beq         $at, $zero, L_800436D4
    if (ctx->r1 == 0) {
        // 0x800433EC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800436D4;
    }
    // 0x800433EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800433F0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800433F4: addu        $at, $at, $t9
    gpr jr_addend_800433FC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800433F8: lw          $t9, 0x2264($at)
    ctx->r25 = ADD32(ctx->r1, 0X2264);
    // 0x800433FC: jr          $t9
    // 0x80043400: nop

    switch (jr_addend_800433FC >> 2) {
        case 0: goto L_80043460; break;
        case 1: goto L_800436D4; break;
        case 2: goto L_800436D4; break;
        case 3: goto L_80043404; break;
        case 4: goto L_800436D4; break;
        case 5: goto L_800436D4; break;
        case 6: goto L_800436D4; break;
        case 7: goto L_800436D4; break;
        case 8: goto L_800436D4; break;
        case 9: goto L_800434F4; break;
        case 10: goto L_800436D4; break;
        case 11: goto L_800436D4; break;
        case 12: goto L_800436D4; break;
        case 13: goto L_800436D4; break;
        case 14: goto L_800436D4; break;
        case 15: goto L_800436D4; break;
        case 16: goto L_800436D4; break;
        case 17: goto L_800436D4; break;
        case 18: goto L_800436D4; break;
        case 19: goto L_800436D4; break;
        case 20: goto L_800436D4; break;
        default: switch_error(__func__, 0x800433FC, 0x80072264);
    }
    // 0x80043400: nop

L_80043404:
    // 0x80043404: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x80043408: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x8004340C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80043410: sb          $s4, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r20;
    // 0x80043414: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80043418: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x8004341C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_12;
    // 0x8004341C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x80043420: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80043424: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_80043428:
    // 0x80043428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004342C: bnel        $s2, $t9, L_80043450
    if (ctx->r18 != ctx->r25) {
        // 0x80043430: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80043450;
    }
    goto skip_13;
    // 0x80043430: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x80043434: jal         0x80042CA4
    // 0x80043438: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042CA4(rdram, ctx);
        goto after_19;
    // 0x80043438: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x8004343C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80043440: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80043444: jal         0x80044630
    // 0x80043448: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_80044630(rdram, ctx);
        goto after_20;
    // 0x80043448: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_20:
    // 0x8004344C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80043450:
    // 0x80043450: bnel        $s0, $zero, L_80043428
    if (ctx->r16 != 0) {
        // 0x80043454: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_80043428;
    }
    goto skip_14;
    // 0x80043454: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x80043458: b           L_800436D8
    // 0x8004345C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x8004345C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80043460:
    // 0x80043460: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x80043464: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x80043468: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8004346C: sb          $s4, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r20;
    // 0x80043470: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80043474: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x80043478: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_15;
    // 0x80043478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_15:
    // 0x8004347C: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80043480: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80043484: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_80043488:
    // 0x80043488: bnel        $s2, $t9, L_800434E4
    if (ctx->r18 != ctx->r25) {
        // 0x8004348C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800434E4;
    }
    goto skip_16;
    // 0x8004348C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_16:
    // 0x80043490: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x80043494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043498: beql        $s3, $t6, L_800434E4
    if (ctx->r19 == ctx->r14) {
        // 0x8004349C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800434E4;
    }
    goto skip_17;
    // 0x8004349C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800434A0: jal         0x80042884
    // 0x800434A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042884(rdram, ctx);
        goto after_21;
    // 0x800434A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x800434A8: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800434AC: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800434B0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800434B4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800434B8: subu        $a0, $t7, $v1
    ctx->r4 = SUB32(ctx->r15, ctx->r3);
    // 0x800434BC: bltz        $a0, L_800434CC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800434C0: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800434CC;
    }
    // 0x800434C0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800434C4: b           L_800434D0
    // 0x800434C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800434D0;
    // 0x800434C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800434CC:
    // 0x800434CC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_800434D0:
    // 0x800434D0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800434D4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800434D8: jal         0x80044190
    // 0x800434DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80044190(rdram, ctx);
        goto after_22;
    // 0x800434DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_22:
    // 0x800434E0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800434E4:
    // 0x800434E4: bnel        $s0, $zero, L_80043488
    if (ctx->r16 != 0) {
        // 0x800434E8: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_80043488;
    }
    goto skip_18;
    // 0x800434E8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x800434EC: b           L_800436D8
    // 0x800434F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x800434F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800434F4:
    // 0x800434F4: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x800434F8: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800434FC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80043500: b           L_800436D4
    // 0x80043504: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_800436D4;
    // 0x80043504: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
    // 0x80043508: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
L_8004350C:
    // 0x8004350C: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x80043510: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80043514: sb          $s4, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r20;
    // 0x80043518: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8004351C: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x80043520: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_19;
    // 0x80043520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_19:
    // 0x80043524: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80043528: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8004352C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80043530: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x80043534: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80043538: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8004353C: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_80043540:
    // 0x80043540: bnel        $s2, $t8, L_800435A8
    if (ctx->r18 != ctx->r24) {
        // 0x80043544: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800435A8;
    }
    goto skip_20;
    // 0x80043544: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x80043548: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x8004354C: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x80043550: beql        $s3, $v0, L_800435A8
    if (ctx->r19 == ctx->r2) {
        // 0x80043554: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800435A8;
    }
    goto skip_21;
    // 0x80043554: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_21:
    // 0x80043558: bne         $at, $zero, L_80043570
    if (ctx->r1 != 0) {
        // 0x8004355C: nop
    
            goto L_80043570;
    }
    // 0x8004355C: nop

    // 0x80043560: bnel        $v0, $zero, L_800435A8
    if (ctx->r2 != 0) {
        // 0x80043564: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800435A8;
    }
    goto skip_22;
    // 0x80043564: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_22:
    // 0x80043568: b           L_800435A4
    // 0x8004356C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800435A4;
    // 0x8004356C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_80043570:
    // 0x80043570: bne         $s6, $v0, L_80043580
    if (ctx->r22 != ctx->r2) {
        // 0x80043574: nop
    
            goto L_80043580;
    }
    // 0x80043574: nop

    // 0x80043578: b           L_800435A4
    // 0x8004357C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800435A4;
    // 0x8004357C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80043580:
    // 0x80043580: bnel        $s7, $v0, L_800435A8
    if (ctx->r23 != ctx->r2) {
        // 0x80043584: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800435A8;
    }
    goto skip_23;
    // 0x80043584: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x80043588: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8004358C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x80043590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043594: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80043598: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8004359C: jal         0x8004290C
    // 0x800435A0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    func_8004290C(rdram, ctx);
        goto after_23;
    // 0x800435A0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    after_23:
L_800435A4:
    // 0x800435A4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800435A8:
    // 0x800435A8: bnel        $s0, $zero, L_80043540
    if (ctx->r16 != 0) {
        // 0x800435AC: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_80043540;
    }
    goto skip_24;
    // 0x800435AC: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x800435B0: b           L_800436D8
    // 0x800435B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x800435B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800435B8:
    // 0x800435B8: lw          $t6, 0x60($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X60);
    // 0x800435BC: sll         $t8, $s6, 4
    ctx->r24 = S32(ctx->r22 << 4);
    // 0x800435C0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800435C4: sb          $s4, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r20;
    // 0x800435C8: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x800435CC: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x800435D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_25;
    // 0x800435D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x800435D4: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x800435D8: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800435DC:
    // 0x800435DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800435E0: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800435E4: bnel        $s2, $t9, L_800435F8
    if (ctx->r18 != ctx->r25) {
        // 0x800435E8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800435F8;
    }
    goto skip_26;
    // 0x800435E8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x800435EC: jal         0x800446C0
    // 0x800435F0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    func_800446C0(rdram, ctx);
        goto after_24;
    // 0x800435F0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    after_24:
    // 0x800435F4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800435F8:
    // 0x800435F8: bnel        $s0, $zero, L_800435DC
    if (ctx->r16 != 0) {
        // 0x800435FC: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800435DC;
    }
    goto skip_27;
    // 0x800435FC: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x80043600: b           L_800436D8
    // 0x80043604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x80043604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80043608:
    // 0x80043608: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8004360C: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80043610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043614: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80043618: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8004361C: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x80043620: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80043624: beql        $at, $zero, L_800436D8
    if (ctx->r1 == 0) {
        // 0x80043628: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_28;
    // 0x80043628: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x8004362C: jal         0x800426D0
    // 0x80043630: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    func_800426D0(rdram, ctx);
        goto after_25;
    // 0x80043630: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_25:
    // 0x80043634: b           L_800436D8
    // 0x80043638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800436D8;
    // 0x80043638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8004363C:
    // 0x8004363C: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x80043640: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x80043644: sll         $t7, $s4, 7
    ctx->r15 = S32(ctx->r20 << 7);
    // 0x80043648: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x8004364C: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x80043650: addu        $t9, $t7, $s3
    ctx->r25 = ADD32(ctx->r15, ctx->r19);
    // 0x80043654: addiu       $t6, $t9, -0x2000
    ctx->r14 = ADD32(ctx->r25, -0X2000);
    // 0x80043658: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004365C: mflo        $a0
    ctx->r4 = lo;
    // 0x80043660: bgez        $a0, L_80043670
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80043664: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_80043670;
    }
    // 0x80043664: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80043668: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x8004366C: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_80043670:
    // 0x80043670: jal         0x800444F0
    // 0x80043674: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_26;
    // 0x80043674: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_26:
    // 0x80043678: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x8004367C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80043680: addu        $t8, $t9, $fp
    ctx->r24 = ADD32(ctx->r25, ctx->r30);
    // 0x80043684: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    // 0x80043688: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8004368C: beql        $s0, $zero, L_800436D8
    if (ctx->r16 == 0) {
        // 0x80043690: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800436D8;
    }
    goto skip_29;
    // 0x80043690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x80043694: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x80043698: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_8004369C:
    // 0x8004369C: bnel        $s2, $t6, L_800436CC
    if (ctx->r18 != ctx->r14) {
        // 0x800436A0: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800436CC;
    }
    goto skip_30;
    // 0x800436A0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_30:
    // 0x800436A4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800436A8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800436AC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x800436B0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800436B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800436B8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800436BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800436C0: jal         0x80044230
    // 0x800436C4: nop

    func_80044230(rdram, ctx);
        goto after_27;
    // 0x800436C4: nop

    after_27:
    // 0x800436C8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800436CC:
    // 0x800436CC: bnel        $s0, $zero, L_8004369C
    if (ctx->r16 != 0) {
        // 0x800436D0: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_8004369C;
    }
    goto skip_31;
    // 0x800436D0: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_800436D4:
    // 0x800436D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800436D8:
    // 0x800436D8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800436DC: jr          $ra
    // 0x800436E0: nop

    return;
    // 0x800436E0: nop

    // 0x800436E4: jr          $ra
    // 0x800436E8: nop

    return;
    // 0x800436E8: nop

;}
RECOMP_FUNC void func_8000B618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B618: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000B61C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B620: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000B624: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000B628: lw          $t6, -0x2E60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E60);
    // 0x8000B62C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000B630: addiu       $t1, $t1, -0x2E58
    ctx->r9 = ADD32(ctx->r9, -0X2E58);
    // 0x8000B634: beq         $t6, $zero, L_8000B730
    if (ctx->r14 == 0) {
        // 0x8000B638: lui         $t2, 0x8008
        ctx->r10 = S32(0X8008 << 16);
            goto L_8000B730;
    }
    // 0x8000B638: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000B63C: lh          $t7, 0x74($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X74);
    // 0x8000B640: lui         $t0, 0x803B
    ctx->r8 = S32(0X803B << 16);
    // 0x8000B644: addiu       $t2, $t2, -0x4D04
    ctx->r10 = ADD32(ctx->r10, -0X4D04);
    // 0x8000B648: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000B64C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8000B650: lw          $t0, -0x5E9C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E9C);
    // 0x8000B654: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8000B658: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8000B65C: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x8000B660: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000B664: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8000B668: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x8000B66C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8000B670: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8000B674: lh          $t5, 0x76($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X76);
    // 0x8000B678: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000B67C: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    // 0x8000B680: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000B684: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8000B688: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000B68C: addu        $a2, $t6, $t0
    ctx->r6 = ADD32(ctx->r14, ctx->r8);
    // 0x8000B690: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000B694: jal         0x8001DB38
    // 0x8000B698: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8001DB38(rdram, ctx);
        goto after_0;
    // 0x8000B698: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8000B69C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000B6A0: lh          $t7, -0x2DE2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DE2);
    // 0x8000B6A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B6A8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000B6AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000B6B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000B6B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000B6B8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000B6BC: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    // 0x8000B6C0: lhu         $a0, -0x2DDC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2DDC);
    // 0x8000B6C4: jal         0x8001E0AC
    // 0x8000B6C8: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    func_8001E0AC(rdram, ctx);
        goto after_1;
    // 0x8000B6C8: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_1:
    // 0x8000B6CC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000B6D0: lw          $t9, -0x2DD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2DD0);
    // 0x8000B6D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B6D8: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x8000B6DC: beq         $t3, $at, L_8000B730
    if (ctx->r11 == ctx->r1) {
        // 0x8000B6E0: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8000B730;
    }
    // 0x8000B6E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B6E4: lwc1        $f12, -0x2E34($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2E34);
    // 0x8000B6E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B6EC: lwc1        $f14, -0x2E30($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8000B6F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B6F4: lwc1        $f4, -0x2E04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E04);
    // 0x8000B6F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B6FC: lwc1        $f6, -0x2E00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E00);
    // 0x8000B700: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B704: lwc1        $f8, -0x2E0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E0C);
    // 0x8000B708: lwc1        $f10, -0x2E10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E10);
    // 0x8000B70C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000B710: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000B714: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000B718: lw          $a3, -0x2E08($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2E08);
    // 0x8000B71C: lw          $a2, -0x2E2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2E2C);
    // 0x8000B720: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000B724: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8000B728: jal         0x80011860
    // 0x8000B72C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    func_80011860(rdram, ctx);
        goto after_2;
    // 0x8000B72C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_2:
L_8000B730:
    // 0x8000B730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B734: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000B738: jr          $ra
    // 0x8000B73C: nop

    return;
    // 0x8000B73C: nop

;}
RECOMP_FUNC void func_8002E768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E768: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002E76C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002E770: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E774: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002E778: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002E77C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002E780: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002E784: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002E788: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002E78C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002E790: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002E794: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002E798: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002E79C: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8002E7A0: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x8002E7A4: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8002E7A8: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002E7AC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002E7B0: addiu       $t3, $t3, -0x3670
    ctx->r11 = ADD32(ctx->r11, -0X3670);
    // 0x8002E7B4: addiu       $t4, $t4, -0x3690
    ctx->r12 = ADD32(ctx->r12, -0X3690);
    // 0x8002E7B8: addiu       $s3, $s3, -0x608
    ctx->r19 = ADD32(ctx->r19, -0X608);
    // 0x8002E7BC: addiu       $fp, $fp, 0x5C0
    ctx->r30 = ADD32(ctx->r30, 0X5C0);
    // 0x8002E7C0: addiu       $t2, $t2, 0x5E0
    ctx->r10 = ADD32(ctx->r10, 0X5E0);
    // 0x8002E7C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002E7C8: lui         $ra, 0x2000
    ctx->r31 = S32(0X2000 << 16);
    // 0x8002E7CC: addiu       $s7, $zero, -0x8
    ctx->r23 = ADD32(0, -0X8);
    // 0x8002E7D0: lui         $s6, 0x8
    ctx->r22 = S32(0X8 << 16);
    // 0x8002E7D4: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
L_8002E7D8:
    // 0x8002E7D8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8002E7DC: and         $t6, $v0, $ra
    ctx->r14 = ctx->r2 & ctx->r31;
    // 0x8002E7E0: beq         $t6, $zero, L_8002E820
    if (ctx->r14 == 0) {
        // 0x8002E7E4: andi        $a0, $v0, 0x7
        ctx->r4 = ctx->r2 & 0X7;
            goto L_8002E820;
    }
    // 0x8002E7E4: andi        $a0, $v0, 0x7
    ctx->r4 = ctx->r2 & 0X7;
    // 0x8002E7E8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8002E7EC: blez        $a0, L_8002E810
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002E7F0: and         $t7, $v0, $s7
        ctx->r15 = ctx->r2 & ctx->r23;
            goto L_8002E810;
    }
    // 0x8002E7F0: and         $t7, $v0, $s7
    ctx->r15 = ctx->r2 & ctx->r23;
    // 0x8002E7F4: or          $t9, $t7, $a0
    ctx->r25 = ctx->r15 | ctx->r4;
    // 0x8002E7F8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8002E7FC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8002E800: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002E804: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8002E808: and         $v0, $t9, $at
    ctx->r2 = ctx->r25 & ctx->r1;
    // 0x8002E80C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_8002E810:
    // 0x8002E810: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x8002E814: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8002E818: b           L_8002EA40
    // 0x8002E81C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_8002EA40;
    // 0x8002E81C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8002E820:
    // 0x8002E820: bgez        $v1, L_8002EA40
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002E824: lui         $at, 0x1000
        ctx->r1 = S32(0X1000 << 16);
            goto L_8002EA40;
    }
    // 0x8002E824: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8002E828: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8002E82C: bgez        $s0, L_8002E878
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002E830: sw          $t9, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r25;
            goto L_8002E878;
    }
    // 0x8002E830: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8002E834: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E838: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8002E83C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002E840: bne         $s0, $at, L_8002E860
    if (ctx->r16 != ctx->r1) {
        // 0x8002E844: sw          $t7, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r15;
            goto L_8002E860;
    }
    // 0x8002E844: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8002E848: or          $t9, $t7, $s6
    ctx->r25 = ctx->r15 | ctx->r22;
    // 0x8002E84C: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x8002E850: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002E854: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8002E858: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8002E85C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8002E860:
    // 0x8002E860: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002E864: bnel        $s0, $at, L_8002E87C
    if (ctx->r16 != ctx->r1) {
        // 0x8002E868: lw          $t6, 0x0($t2)
        ctx->r14 = MEM_W(ctx->r10, 0X0);
            goto L_8002E87C;
    }
    goto skip_0;
    // 0x8002E868: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    skip_0:
    // 0x8002E86C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8002E870: or          $t9, $t8, $s6
    ctx->r25 = ctx->r24 | ctx->r22;
    // 0x8002E874: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8002E878:
    // 0x8002E878: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
L_8002E87C:
    // 0x8002E87C: sll         $t8, $s2, 4
    ctx->r24 = S32(ctx->r18 << 4);
    // 0x8002E880: addu        $t8, $t8, $s2
    ctx->r24 = ADD32(ctx->r24, ctx->r18);
    // 0x8002E884: and         $t7, $t6, $s7
    ctx->r15 = ctx->r14 & ctx->r23;
    // 0x8002E888: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8002E88C: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8002E890: and         $t7, $t9, $s6
    ctx->r15 = ctx->r25 & ctx->r22;
    // 0x8002E894: bne         $t7, $zero, L_8002EA18
    if (ctx->r15 != 0) {
        // 0x8002E898: sw          $t9, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r25;
            goto L_8002EA18;
    }
    // 0x8002E898: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8002E89C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002E8A0: addu        $t8, $t8, $s2
    ctx->r24 = ADD32(ctx->r24, ctx->r18);
    // 0x8002E8A4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002E8A8: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002E8AC: lb          $t7, -0x600($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X600);
    // 0x8002E8B0: lb          $t6, -0x650($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X650);
    // 0x8002E8B4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002E8B8: subu        $t8, $t8, $s2
    ctx->r24 = SUB32(ctx->r24, ctx->r18);
    // 0x8002E8BC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002E8C0: addiu       $t9, $t9, 0x5E0
    ctx->r25 = ADD32(ctx->r25, 0X5E0);
    // 0x8002E8C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002E8C8: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x8002E8CC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E8D0: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002E8D4: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x8002E8D8: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x8002E8DC: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8002E8E0: lw          $s4, 0x5CC($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X5CC);
    // 0x8002E8E4: lw          $t5, 0x5C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5C8);
    // 0x8002E8E8: addiu       $v1, $v1, -0x3690
    ctx->r3 = ADD32(ctx->r3, -0X3690);
    // 0x8002E8EC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8002E8F0:
    // 0x8002E8F0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E8F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E8F8: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8002E8FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E900: bne         $at, $zero, L_8002E8F0
    if (ctx->r1 != 0) {
        // 0x8002E904: sb          $t8, 0x16($v0)
        MEM_B(0X16, ctx->r2) = ctx->r24;
            goto L_8002E8F0;
    }
    // 0x8002E904: sb          $t8, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r24;
    // 0x8002E908: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E90C: addiu       $v1, $v1, -0x3A90
    ctx->r3 = ADD32(ctx->r3, -0X3A90);
    // 0x8002E910: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8002E914:
    // 0x8002E914: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8002E918: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002E91C: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x8002E920: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E924: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E928: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002E92C: sb          $t6, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r14;
    // 0x8002E930: sb          $t7, 0x9A($v0)
    MEM_B(0X9A, ctx->r2) = ctx->r15;
    // 0x8002E934: sb          $t8, 0x9B($v0)
    MEM_B(0X9B, ctx->r2) = ctx->r24;
    // 0x8002E938: bne         $v1, $t4, L_8002E914
    if (ctx->r3 != ctx->r12) {
        // 0x8002E93C: sb          $t9, 0x98($v0)
        MEM_B(0X98, ctx->r2) = ctx->r25;
            goto L_8002E914;
    }
    // 0x8002E93C: sb          $t9, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r25;
    // 0x8002E940: blez        $t5, L_8002E9A4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8002E944: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_8002E9A4;
    }
    // 0x8002E944: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002E948: addiu       $a1, $t9, 0x5C8
    ctx->r5 = ADD32(ctx->r25, 0X5C8);
    // 0x8002E94C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002E950: addu        $t1, $t6, $a1
    ctx->r9 = ADD32(ctx->r14, ctx->r5);
    // 0x8002E954: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8002E958:
    // 0x8002E958: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8002E95C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002E960: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8002E964:
    // 0x8002E964: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8002E968: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002E96C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002E970: sb          $t7, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r15;
    // 0x8002E974: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8002E978: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E97C: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x8002E980: lbu         $t6, -0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X2);
    // 0x8002E984: sb          $t6, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r14;
    // 0x8002E988: lbu         $t9, -0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X1);
    // 0x8002E98C: bne         $a0, $t0, L_8002E964
    if (ctx->r4 != ctx->r8) {
        // 0x8002E990: sb          $t9, 0x3B($v0)
        MEM_B(0X3B, ctx->r2) = ctx->r25;
            goto L_8002E964;
    }
    // 0x8002E990: sb          $t9, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r25;
    // 0x8002E994: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002E998: sltu        $at, $a1, $t1
    ctx->r1 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x8002E99C: bne         $at, $zero, L_8002E958
    if (ctx->r1 != 0) {
        // 0x8002E9A0: addiu       $a3, $a3, 0x18
        ctx->r7 = ADD32(ctx->r7, 0X18);
            goto L_8002E958;
    }
    // 0x8002E9A0: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
L_8002E9A4:
    // 0x8002E9A4: sh          $t5, 0x38($t2)
    MEM_H(0X38, ctx->r10) = ctx->r13;
    // 0x8002E9A8: bltz        $s0, L_8002E9E8
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002E9AC: sh          $s4, 0x3A($t2)
        MEM_H(0X3A, ctx->r10) = ctx->r20;
            goto L_8002E9E8;
    }
    // 0x8002E9AC: sh          $s4, 0x3A($t2)
    MEM_H(0X3A, ctx->r10) = ctx->r20;
    // 0x8002E9B0: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8002E9B4: addiu       $t8, $t8, -0x648
    ctx->r24 = ADD32(ctx->r24, -0X648);
    // 0x8002E9B8: sll         $t7, $s0, 3
    ctx->r15 = S32(ctx->r16 << 3);
    // 0x8002E9BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002E9C0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002E9C4: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002E9C8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8002E9CC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8002E9D0: sb          $s0, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r16;
    // 0x8002E9D4: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x8002E9D8: sh          $t9, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r25;
    // 0x8002E9DC: sh          $t7, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r15;
    // 0x8002E9E0: b           L_8002EA10
    // 0x8002E9E4: sh          $t8, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r24;
        goto L_8002EA10;
    // 0x8002E9E4: sh          $t8, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r24;
L_8002E9E8:
    // 0x8002E9E8: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x8002E9EC: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x8002E9F0: lh          $t7, 0x4($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X4);
    // 0x8002E9F4: lh          $t8, 0x6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X6);
    // 0x8002E9F8: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x8002E9FC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8002EA00: sb          $t6, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r14;
    // 0x8002EA04: sh          $t9, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r25;
    // 0x8002EA08: sh          $t7, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r15;
    // 0x8002EA0C: sh          $t8, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r24;
L_8002EA10:
    // 0x8002EA10: sb          $s5, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r21;
    // 0x8002EA14: sb          $s1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r17;
L_8002EA18:
    // 0x8002EA18: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8002EA1C: lbu         $t7, 0x9D($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X9D);
    // 0x8002EA20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002EA24: sh          $t9, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r25;
    // 0x8002EA28: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8002EA2C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8002EA30: sb          $t8, 0x9D($t2)
    MEM_B(0X9D, ctx->r10) = ctx->r24;
    // 0x8002EA34: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8002EA38: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x8002EA3C: sb          $t7, 0x14($t2)
    MEM_B(0X14, ctx->r10) = ctx->r15;
L_8002EA40:
    // 0x8002EA40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002EA44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002EA48: bne         $s2, $at, L_8002E7D8
    if (ctx->r18 != ctx->r1) {
        // 0x8002EA4C: addiu       $t2, $t2, 0x89C
        ctx->r10 = ADD32(ctx->r10, 0X89C);
            goto L_8002E7D8;
    }
    // 0x8002EA4C: addiu       $t2, $t2, 0x89C
    ctx->r10 = ADD32(ctx->r10, 0X89C);
    // 0x8002EA50: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002EA54: addiu       $a0, $a0, -0x4D1C
    ctx->r4 = ADD32(ctx->r4, -0X4D1C);
    // 0x8002EA58: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8002EA5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002EA60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002EA64: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8002EA68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8002EA6C: sb          $zero, 0x2850($at)
    MEM_B(0X2850, ctx->r1) = 0;
    // 0x8002EA70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002EA74: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002EA78: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002EA7C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002EA80: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002EA84: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002EA88: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EA8C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002EA90: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002EA94: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002EA98: jr          $ra
    // 0x8002EA9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002EA9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void nnScEventBroadcast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800008B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800008B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800008B8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800008BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800008C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800008C4: lw          $s0, 0x668($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X668);
    // 0x800008C8: beql        $s0, $zero, L_800008F0
    if (ctx->r16 == 0) {
        // 0x800008CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800008F0;
    }
    goto skip_0;
    // 0x800008CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800008D0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_800008D4:
    // 0x800008D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800008D8: jal         0x80034200
    // 0x800008DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800008DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800008E0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800008E4: bnel        $s0, $zero, L_800008D4
    if (ctx->r16 != 0) {
        // 0x800008E8: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_800008D4;
    }
    goto skip_1;
    // 0x800008E8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800008EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800008F0:
    // 0x800008F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800008F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800008F8: jr          $ra
    // 0x800008FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800008FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80007030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000703C: lhu         $t6, 0x60($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X60);
    // 0x80007040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80007044: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80007048: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000704C: bnel        $t7, $zero, L_800070B0
    if (ctx->r15 != 0) {
        // 0x80007050: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800070B0;
    }
    goto skip_0;
    // 0x80007050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80007054: lw          $t8, -0x4D1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4D1C);
    // 0x80007058: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8000705C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80007060: bnel        $t9, $zero, L_800070B0
    if (ctx->r25 != 0) {
        // 0x80007064: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800070B0;
    }
    goto skip_1;
    // 0x80007064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80007068: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x8000706C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80007070: beq         $t0, $zero, L_800070A8
    if (ctx->r8 == 0) {
        // 0x80007074: andi        $t1, $v0, 0x202
        ctx->r9 = ctx->r2 & 0X202;
            goto L_800070A8;
    }
    // 0x80007074: andi        $t1, $v0, 0x202
    ctx->r9 = ctx->r2 & 0X202;
    // 0x80007078: bnel        $t1, $zero, L_800070B0
    if (ctx->r9 != 0) {
        // 0x8000707C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800070B0;
    }
    goto skip_2;
    // 0x8000707C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80007080: jal         0x80015B50
    // 0x80007084: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80015B50(rdram, ctx);
        goto after_0;
    // 0x80007084: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80007088: bne         $v0, $zero, L_800070AC
    if (ctx->r2 != 0) {
        // 0x8000708C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_800070AC;
    }
    // 0x8000708C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80007090: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80007094: lhu         $t2, -0x3A6C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3A6C);
    // 0x80007098: bnel        $t2, $zero, L_800070B0
    if (ctx->r10 != 0) {
        // 0x8000709C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800070B0;
    }
    goto skip_3;
    // 0x8000709C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
    // 0x800070A0: b           L_800070AC
    // 0x800070A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800070AC;
    // 0x800070A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800070A8:
    // 0x800070A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800070AC:
    // 0x800070AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800070B0:
    // 0x800070B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800070B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800070B8: jr          $ra
    // 0x800070BC: nop

    return;
    // 0x800070BC: nop

;}
RECOMP_FUNC void func_8002AF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF70: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8002AF74: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002AF78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002AF7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002AF80: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002AF84: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8002AF88: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8002AF8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002AF90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002AF94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002AF98: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002AF9C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002AFA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002AFA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AFA8: lui         $t7, 0x3B9A
    ctx->r15 = S32(0X3B9A << 16);
    // 0x8002AFAC: ori         $t7, $t7, 0xCA00
    ctx->r15 = ctx->r15 | 0XCA00;
    // 0x8002AFB0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8002AFB4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002AFB8: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8002AFBC: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8002AFC0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x8002AFC4: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x8002AFC8: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x8002AFCC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002AFD0: bne         $at, $zero, L_8002AFDC
    if (ctx->r1 != 0) {
        // 0x8002AFD4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8002AFDC;
    }
    // 0x8002AFD4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002AFD8: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
L_8002AFDC:
    // 0x8002AFDC: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002AFE0: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
    // 0x8002AFE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002AFE8:
    // 0x8002AFE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AFEC:
    // 0x8002AFEC: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8002AFF0: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8002AFF4: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x8002AFF8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8002AFFC: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8002B000: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8002B004: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8002B008: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8002B00C: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x8002B010: bgtz        $t8, L_8002B044
    if (SIGNED(ctx->r24) > 0) {
        // 0x8002B014: sw          $t9, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r25;
            goto L_8002B044;
    }
    // 0x8002B014: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x8002B018: bltzl       $t8, L_8002B02C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002B01C: addu        $t9, $t9, $t7
        ctx->r25 = ADD32(ctx->r25, ctx->r15);
            goto L_8002B02C;
    }
    goto skip_0;
    // 0x8002B01C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    skip_0:
    // 0x8002B020: b           L_8002AFEC
    // 0x8002B024: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002AFEC;
    // 0x8002B024: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B028: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
L_8002B02C:
    // 0x8002B02C: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8002B030: addu        $t8, $at, $t8
    ctx->r24 = ADD32(ctx->r1, ctx->r24);
    // 0x8002B034: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8002B038: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x8002B03C: b           L_8002B04C
    // 0x8002B040: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
        goto L_8002B04C;
    // 0x8002B040: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
L_8002B044:
    // 0x8002B044: b           L_8002AFEC
    // 0x8002B048: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002AFEC;
    // 0x8002B048: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002B04C:
    // 0x8002B04C: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8002B050: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8002B054: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8002B058: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x8002B05C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002B060: jal         0x80039B38
    // 0x8002B064: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    __ull_div_recomp(rdram, ctx);
        goto after_0;
    // 0x8002B064: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x8002B068: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002B06C: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x8002B070: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x8002B074: bne         $at, $zero, L_8002AFE8
    if (ctx->r1 != 0) {
        // 0x8002B078: sw          $v1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r3;
            goto L_8002AFE8;
    }
    // 0x8002B078: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    // 0x8002B07C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002B080: addiu       $t3, $t3, -0x2F4
    ctx->r11 = ADD32(ctx->r11, -0X2F4);
    // 0x8002B084: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x8002B088: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x8002B08C: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8002B090: andi        $t6, $t9, 0x10
    ctx->r14 = ctx->r25 & 0X10;
    // 0x8002B094: bne         $t6, $zero, L_8002B16C
    if (ctx->r14 != 0) {
        // 0x8002B098: sb          $t7, 0xB4($sp)
        MEM_B(0XB4, ctx->r29) = ctx->r15;
            goto L_8002B16C;
    }
    // 0x8002B098: sb          $t7, 0xB4($sp)
    MEM_B(0XB4, ctx->r29) = ctx->r15;
    // 0x8002B09C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002B0A0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002B0A4: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x8002B0A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0AC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8002B0B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002B0B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002B0B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B0BC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002B0C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0C4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8002B0C8: addiu       $t6, $t6, 0x138
    ctx->r14 = ADD32(ctx->r14, 0X138);
    // 0x8002B0CC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002B0D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002B0D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002B0D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002B0DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0E0: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8002B0E4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8002B0E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002B0EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002B0F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B0F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002B0F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0FC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8002B100: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8002B104: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002B108: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002B10C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002B110: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002B114: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B118: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8002B11C: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8002B120: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002B124: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002B128: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B12C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002B130: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B134: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8002B138: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8002B13C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002B140: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002B144: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002B148: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002B14C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B150: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002B154: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002B158: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B15C: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002B160: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x8002B164: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8002B168: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
L_8002B16C:
    // 0x8002B16C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002B170: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8002B174: bltz        $a0, L_8002B334
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002B178: lui         $s3, 0xE700
        ctx->r19 = S32(0XE700 << 16);
            goto L_8002B334;
    }
    // 0x8002B178: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x8002B17C: lw          $s0, 0xE8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE8);
    // 0x8002B180: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x8002B184: addu        $t4, $s6, $s5
    ctx->r12 = ADD32(ctx->r22, ctx->r21);
    // 0x8002B188: addiu       $s1, $s4, 0xA
    ctx->r17 = ADD32(ctx->r20, 0XA);
    // 0x8002B18C: sll         $s2, $s4, 2
    ctx->r18 = S32(ctx->r20 << 2);
    // 0x8002B190: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x8002B194: andi        $t8, $s2, 0xFFF
    ctx->r24 = ctx->r18 & 0XFFF;
    // 0x8002B198: lui         $s4, 0xF548
    ctx->r20 = S32(0XF548 << 16);
    // 0x8002B19C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8002B1A0: lui         $s5, 0xFD48
    ctx->r21 = S32(0XFD48 << 16);
    // 0x8002B1A4: lui         $s6, 0x8006
    ctx->r22 = S32(0X8006 << 16);
    // 0x8002B1A8: lui         $s7, 0x701
    ctx->r23 = S32(0X701 << 16);
    // 0x8002B1AC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8002B1B0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8002B1B4: ori         $s7, $s7, 0x30
    ctx->r23 = ctx->r23 | 0X30;
    // 0x8002B1B8: addiu       $s6, $s6, -0xF30
    ctx->r22 = ADD32(ctx->r22, -0XF30);
    // 0x8002B1BC: ori         $s5, $s5, 0x7
    ctx->r21 = ctx->r21 | 0X7;
    // 0x8002B1C0: andi        $s1, $t6, 0xFFF
    ctx->r17 = ctx->r14 & 0XFFF;
    // 0x8002B1C4: ori         $s4, $s4, 0x200
    ctx->r20 = ctx->r20 | 0X200;
    // 0x8002B1C8: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8002B1CC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002B1D0: lui         $fp, 0xF400
    ctx->r30 = S32(0XF400 << 16);
L_8002B1D4:
    // 0x8002B1D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B1D8: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8002B1DC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8002B1E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002B1E4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002B1E8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8002B1EC: lb          $t6, 0x1($t3)
    ctx->r14 = MEM_B(ctx->r11, 0X1);
    // 0x8002B1F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B1F4: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8002B1F8: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8002B1FC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8002B200: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002B204: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B208: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002B20C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002B210: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8002B214: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8002B218: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B21C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8002B220: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002B224: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002B228: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B22C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002B230: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B234: lui         $t7, 0x701
    ctx->r15 = S32(0X701 << 16);
    // 0x8002B238: ori         $t7, $t7, 0xC024
    ctx->r15 = ctx->r15 | 0XC024;
    // 0x8002B23C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002B240: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002B244: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002B248: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8002B24C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B250: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002B254: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002B258: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B25C: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002B260: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B264: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8002B268: ori         $t6, $t6, 0x30
    ctx->r14 = ctx->r14 | 0X30;
    // 0x8002B26C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002B270: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002B274: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002B278: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x8002B27C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B280: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8002B284: ori         $t9, $t9, 0xC024
    ctx->r25 = ctx->r25 | 0XC024;
    // 0x8002B288: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002B28C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002B290: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8002B294: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002B298: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002B29C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B2A0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8002B2A4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002B2A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002B2AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002B2B0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8002B2B4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002B2B8: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x8002B2BC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8002B2C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8002B2C4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8002B2C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002B2CC: or          $t7, $t6, $s2
    ctx->r15 = ctx->r14 | ctx->r18;
    // 0x8002B2D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002B2D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B2D8: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8002B2DC: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8002B2E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002B2E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002B2E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B2EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002B2F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B2F4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8002B2F8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8002B2FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8002B300: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002B304: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002B308: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002B30C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002B310: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002B314: addiu       $t4, $t4, 0x7
    ctx->r12 = ADD32(ctx->r12, 0X7);
    // 0x8002B318: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002B31C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002B320: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002B324: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8002B328: sltu        $at, $t3, $t6
    ctx->r1 = ctx->r11 < ctx->r14 ? 1 : 0;
    // 0x8002B32C: beq         $at, $zero, L_8002B1D4
    if (ctx->r1 == 0) {
        // 0x8002B330: addiu       $t5, $t5, 0x7
        ctx->r13 = ADD32(ctx->r13, 0X7);
            goto L_8002B1D4;
    }
    // 0x8002B330: addiu       $t5, $t5, 0x7
    ctx->r13 = ADD32(ctx->r13, 0X7);
L_8002B334:
    // 0x8002B334: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002B33C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B340: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002B344: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002B348: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002B34C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B350: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002B354: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002B358: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002B35C: jr          $ra
    // 0x8002B360: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8002B360: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8000DB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB10: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DB14: addiu       $v0, $v0, 0x4E60
    ctx->r2 = ADD32(ctx->r2, 0X4E60);
    // 0x8000DB18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000DB1C:
    // 0x8000DB1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000DB20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000DB24: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8000DB28: bne         $a0, $zero, L_8000DB1C
    if (ctx->r4 != 0) {
        // 0x8000DB2C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8000DB1C;
    }
    // 0x8000DB2C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000DB30: jr          $ra
    // 0x8000DB34: nop

    return;
    // 0x8000DB34: nop

;}
RECOMP_FUNC void func_80048C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C40: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80048C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048C48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048C4C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80048C50: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80048C54: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80048C58: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80048C5C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80048C60: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80048C64: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x80048C68: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x80048C6C: beq         $at, $zero, L_80048C78
    if (ctx->r1 == 0) {
        // 0x80048C70: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_80048C78;
    }
    // 0x80048C70: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x80048C74: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_80048C78:
    // 0x80048C78: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80048C7C: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x80048C80: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x80048C84: beq         $at, $zero, L_80048D78
    if (ctx->r1 == 0) {
        // 0x80048C88: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_80048D78;
    }
    // 0x80048C88: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80048C8C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x80048C90: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80048C94: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80048C98: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80048C9C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80048CA0: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x80048CA4: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80048CA8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80048CAC: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x80048CB0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80048CB4: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x80048CB8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80048CBC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80048CC0: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80048CC4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80048CC8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80048CCC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80048CD0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80048CD4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80048CD8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80048CDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048CE0: jal         0x80034DD0
    // 0x80048CE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80048CE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80048CE8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80048CEC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80048CF0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80048CF4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80048CF8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80048CFC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80048D00: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048D04: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80048D08: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80048D0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80048D10: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x80048D14: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80048D18: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80048D1C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80048D20: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80048D24: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80048D28: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80048D2C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048D30: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80048D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048D38: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80048D3C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80048D40: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x80048D44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80048D48: jal         0x80034DD0
    // 0x80048D4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80048D4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x80048D50: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80048D54: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80048D58: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048D5C: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x80048D60: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80048D64: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80048D68: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80048D6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80048D70: b           L_80048DB4
    // 0x80048D74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80048DB4;
    // 0x80048D74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80048D78:
    // 0x80048D78: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80048D7C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80048D80: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80048D84: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80048D88: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80048D8C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80048D90: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80048D94: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80048D98: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80048D9C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80048DA0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80048DA4: jal         0x80034DD0
    // 0x80048DA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80048DA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80048DAC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80048DB0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80048DB4:
    // 0x80048DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048DB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80048DBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048DC0: jr          $ra
    // 0x80048DC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80048DC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80036928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036928: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8003692C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80036930: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036934: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80036938: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003693C: ldc1        $f4, 0x1C00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1C00);
    // 0x80036940: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80036944: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036948: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8003694C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80036950: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80036954: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036958: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003695C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80036960: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80036964: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80036968: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8003696C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80036970: nop

    // 0x80036974: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80036978: jr          $ra
    // 0x8003697C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x8003697C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_80030068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030068: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80030070: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80030074: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80030078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003007C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80030080: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80030084: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80030088: addiu       $t8, $t8, 0x5E0
    ctx->r24 = ADD32(ctx->r24, 0X5E0);
    // 0x8003008C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80030090: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80030094: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80030098: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8003009C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800300A0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800300A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800300A8: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x800300AC: lh          $t5, 0x8($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X8);
    // 0x800300B0: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x800300B4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800300B8: addiu       $t5, $t5, -0x20
    ctx->r13 = ADD32(ctx->r13, -0X20);
    // 0x800300BC: bgez        $t5, L_800300CC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800300C0: sra         $t9, $t5, 3
        ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
            goto L_800300CC;
    }
    // 0x800300C0: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x800300C4: addiu       $at, $t5, 0x7
    ctx->r1 = ADD32(ctx->r13, 0X7);
    // 0x800300C8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800300CC:
    // 0x800300CC: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800300D0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800300D4: addiu       $t9, $t7, -0x14
    ctx->r25 = ADD32(ctx->r15, -0X14);
    // 0x800300D8: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x800300DC: mflo        $t7
    ctx->r15 = lo;
    // 0x800300E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800300E4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800300E8: blez        $t7, L_80030318
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800300EC: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80030318;
    }
    // 0x800300EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800300F0: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800300F4: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800300F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800300FC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80030100: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80030104: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80030108: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8003010C: addu        $a3, $t9, $t8
    ctx->r7 = ADD32(ctx->r25, ctx->r24);
    // 0x80030110: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // 0x80030114: addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
    // 0x80030118: addiu       $ra, $zero, 0xFF
    ctx->r31 = ADD32(0, 0XFF);
    // 0x8003011C: addiu       $t4, $zero, 0xE0
    ctx->r12 = ADD32(0, 0XE0);
L_80030120:
    // 0x80030120: blez        $t5, L_80030188
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80030124: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80030188;
    }
    // 0x80030124: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80030128: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
L_8003012C:
    // 0x8003012C: addu        $t7, $a3, $a1
    ctx->r15 = ADD32(ctx->r7, ctx->r5);
    // 0x80030130: lbu         $t6, 0x9C($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X9C);
    // 0x80030134: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x80030138: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x8003013C: sb          $t6, 0x49C($t9)
    MEM_B(0X49C, ctx->r25) = ctx->r14;
    // 0x80030140: lbu         $a2, 0x49D($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49D);
    // 0x80030144: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80030148: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8003014C: andi        $t8, $a2, 0x80
    ctx->r24 = ctx->r6 & 0X80;
    // 0x80030150: beq         $t8, $zero, L_80030178
    if (ctx->r24 == 0) {
        // 0x80030154: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80030178;
    }
    // 0x80030154: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80030158: beql        $t4, $a2, L_8003018C
    if (ctx->r12 == ctx->r6) {
        // 0x8003015C: lbu         $a2, 0x49C($t0)
        ctx->r6 = MEM_BU(ctx->r8, 0X49C);
            goto L_8003018C;
    }
    goto skip_0;
    // 0x8003015C: lbu         $a2, 0x49C($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49C);
    skip_0:
    // 0x80030160: beql        $ra, $a2, L_8003018C
    if (ctx->r31 == ctx->r6) {
        // 0x80030164: lbu         $a2, 0x49C($t0)
        ctx->r6 = MEM_BU(ctx->r8, 0X49C);
            goto L_8003018C;
    }
    goto skip_1;
    // 0x80030164: lbu         $a2, 0x49C($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49C);
    skip_1:
    // 0x80030168: bnel        $s0, $a2, L_80030180
    if (ctx->r16 != ctx->r6) {
        // 0x8003016C: slt         $at, $t1, $t5
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_80030180;
    }
    goto skip_2;
    // 0x8003016C: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    skip_2:
    // 0x80030170: b           L_8003018C
    // 0x80030174: lbu         $a2, 0x49C($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49C);
        goto L_8003018C;
    // 0x80030174: lbu         $a2, 0x49C($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49C);
L_80030178:
    // 0x80030178: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8003017C: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
L_80030180:
    // 0x80030180: bnel        $at, $zero, L_8003012C
    if (ctx->r1 != 0) {
        // 0x80030184: addiu       $a1, $t2, 0x1
        ctx->r5 = ADD32(ctx->r10, 0X1);
            goto L_8003012C;
    }
    goto skip_3;
    // 0x80030184: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
    skip_3:
L_80030188:
    // 0x80030188: lbu         $a2, 0x49C($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X49C);
L_8003018C:
    // 0x8003018C: beql        $ra, $a2, L_8003031C
    if (ctx->r31 == ctx->r6) {
        // 0x80030190: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_8003031C;
    }
    goto skip_4;
    // 0x80030190: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    skip_4:
    // 0x80030194: bne         $s0, $a2, L_800301B0
    if (ctx->r16 != ctx->r6) {
        // 0x80030198: nop
    
            goto L_800301B0;
    }
    // 0x80030198: nop

    // 0x8003019C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800301A0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800301A4: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800301A8: b           L_80030318
    // 0x800301AC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
        goto L_80030318;
    // 0x800301AC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_800301B0:
    // 0x800301B0: beql        $t4, $a2, L_8003030C
    if (ctx->r12 == ctx->r6) {
        // 0x800301B4: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8003030C;
    }
    goto skip_5;
    // 0x800301B4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_5:
    // 0x800301B8: beq         $t4, $a2, L_80030308
    if (ctx->r12 == ctx->r6) {
        // 0x800301BC: addu        $t9, $a3, $t2
        ctx->r25 = ADD32(ctx->r7, ctx->r10);
            goto L_80030308;
    }
    // 0x800301BC: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
    // 0x800301C0: lbu         $t8, 0x9D($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X9D);
    // 0x800301C4: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
    // 0x800301C8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800301CC: slti        $at, $t8, 0x80
    ctx->r1 = SIGNED(ctx->r24) < 0X80 ? 1 : 0;
    // 0x800301D0: bne         $at, $zero, L_800302EC
    if (ctx->r1 != 0) {
        // 0x800301D4: or          $t1, $a1, $zero
        ctx->r9 = ctx->r5 | 0;
            goto L_800302EC;
    }
    // 0x800301D4: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800301D8: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x800301DC: lbu         $t7, 0x9C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X9C);
L_800301E0:
    // 0x800301E0: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x800301E4: addu        $t8, $a3, $v0
    ctx->r24 = ADD32(ctx->r7, ctx->r2);
    // 0x800301E8: bnel        $t4, $t7, L_800302D8
    if (ctx->r12 != ctx->r15) {
        // 0x800301EC: lbu         $t7, 0x9C($t8)
        ctx->r15 = MEM_BU(ctx->r24, 0X9C);
            goto L_800302D8;
    }
    goto skip_6;
    // 0x800301EC: lbu         $t7, 0x9C($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X9C);
    skip_6:
    // 0x800301F0: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x800301F4: blez        $v0, L_800302AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800301F8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800302AC;
    }
    // 0x800301F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800301FC: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80030200: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80030204: beq         $v1, $zero, L_8003023C
    if (ctx->r3 == 0) {
        // 0x80030208: addu        $t1, $v1, $v0
        ctx->r9 = ADD32(ctx->r3, ctx->r2);
            goto L_8003023C;
    }
    // 0x80030208: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
L_8003020C:
    // 0x8003020C: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
    // 0x80030210: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x80030214: lbu         $t9, 0x9C($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X9C);
    // 0x80030218: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x8003021C: addu        $t8, $a3, $v0
    ctx->r24 = ADD32(ctx->r7, ctx->r2);
    // 0x80030220: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80030224: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80030228: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x8003022C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80030230: bne         $t1, $a2, L_8003020C
    if (ctx->r9 != ctx->r6) {
        // 0x80030234: sb          $t9, 0x49C($t8)
        MEM_B(0X49C, ctx->r24) = ctx->r25;
            goto L_8003020C;
    }
    // 0x80030234: sb          $t9, 0x49C($t8)
    MEM_B(0X49C, ctx->r24) = ctx->r25;
    // 0x80030238: beq         $a2, $zero, L_800302A8
    if (ctx->r6 == 0) {
        // 0x8003023C: addiu       $a1, $t2, 0x1
        ctx->r5 = ADD32(ctx->r10, 0X1);
            goto L_800302A8;
    }
L_8003023C:
    // 0x8003023C: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
    // 0x80030240: addu        $t7, $a3, $a1
    ctx->r15 = ADD32(ctx->r7, ctx->r5);
    // 0x80030244: lbu         $t6, 0x9C($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X9C);
    // 0x80030248: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x8003024C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80030250: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x80030254: addu        $t8, $a3, $a1
    ctx->r24 = ADD32(ctx->r7, ctx->r5);
    // 0x80030258: sb          $t6, 0x49C($t9)
    MEM_B(0X49C, ctx->r25) = ctx->r14;
    // 0x8003025C: lbu         $t7, 0x9C($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X9C);
    // 0x80030260: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030264: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x80030268: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003026C: addu        $t9, $a3, $a1
    ctx->r25 = ADD32(ctx->r7, ctx->r5);
    // 0x80030270: sb          $t7, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r15;
    // 0x80030274: lbu         $t8, 0x9C($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X9C);
    // 0x80030278: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003027C: addu        $t7, $a3, $v0
    ctx->r15 = ADD32(ctx->r7, ctx->r2);
    // 0x80030280: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80030284: addu        $t6, $a3, $t2
    ctx->r14 = ADD32(ctx->r7, ctx->r10);
    // 0x80030288: sb          $t8, 0x49C($t7)
    MEM_B(0X49C, ctx->r15) = ctx->r24;
    // 0x8003028C: lbu         $t9, 0x9C($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X9C);
    // 0x80030290: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80030294: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x80030298: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003029C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800302A0: bne         $a2, $zero, L_8003023C
    if (ctx->r6 != 0) {
        // 0x800302A4: sb          $t9, 0x49C($t8)
        MEM_B(0X49C, ctx->r24) = ctx->r25;
            goto L_8003023C;
    }
    // 0x800302A4: sb          $t9, 0x49C($t8)
    MEM_B(0X49C, ctx->r24) = ctx->r25;
L_800302A8:
    // 0x800302A8: addiu       $a1, $t2, 0x1
    ctx->r5 = ADD32(ctx->r10, 0X1);
L_800302AC:
    // 0x800302AC: addu        $t7, $a3, $a1
    ctx->r15 = ADD32(ctx->r7, ctx->r5);
    // 0x800302B0: lbu         $t6, 0x9C($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X9C);
    // 0x800302B4: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x800302B8: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x800302BC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800302C0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800302C4: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800302C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800302CC: b           L_800302EC
    // 0x800302D0: sb          $t6, 0x49C($t9)
    MEM_B(0X49C, ctx->r25) = ctx->r14;
        goto L_800302EC;
    // 0x800302D0: sb          $t6, 0x49C($t9)
    MEM_B(0X49C, ctx->r25) = ctx->r14;
    // 0x800302D4: lbu         $t7, 0x9C($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X9C);
L_800302D8:
    // 0x800302D8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800302DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800302E0: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800302E4: beql        $at, $zero, L_800301E0
    if (ctx->r1 == 0) {
        // 0x800302E8: lbu         $t7, 0x9C($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X9C);
            goto L_800301E0;
    }
    goto skip_7;
    // 0x800302E8: lbu         $t7, 0x9C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X9C);
    skip_7:
L_800302EC:
    // 0x800302EC: beq         $a2, $zero, L_80030308
    if (ctx->r6 == 0) {
        // 0x800302F0: addiu       $v0, $t3, 0x1
        ctx->r2 = ADD32(ctx->r11, 0X1);
            goto L_80030308;
    }
    // 0x800302F0: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x800302F4: addiu       $t6, $zero, 0xE0
    ctx->r14 = ADD32(0, 0XE0);
    // 0x800302F8: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x800302FC: sb          $t6, 0x49C($t9)
    MEM_B(0X49C, ctx->r25) = ctx->r14;
    // 0x80030300: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80030304: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80030308:
    // 0x80030308: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_8003030C:
    // 0x8003030C: slt         $a0, $s1, $t8
    ctx->r4 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80030310: bne         $a0, $zero, L_80030120
    if (ctx->r4 != 0) {
        // 0x80030314: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80030120;
    }
    // 0x80030314: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80030318:
    // 0x80030318: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_8003031C:
    // 0x8003031C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80030320: addiu       $ra, $zero, 0xFF
    ctx->r31 = ADD32(0, 0XFF);
    // 0x80030324: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80030328: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8003032C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80030330: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80030334: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030338: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8003033C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80030340: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80030344: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80030348: lbu         $a2, 0xA7C($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XA7C);
    // 0x8003034C: addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
    // 0x80030350: beql        $ra, $a2, L_800303D4
    if (ctx->r31 == ctx->r6) {
        // 0x80030354: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800303D4;
    }
    goto skip_8;
    // 0x80030354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80030358: beq         $s0, $a2, L_800303D0
    if (ctx->r16 == ctx->r6) {
        // 0x8003035C: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800303D0;
    }
    // 0x8003035C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80030360: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80030364: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80030368: addu        $t6, $s2, $t3
    ctx->r14 = ADD32(ctx->r18, ctx->r11);
    // 0x8003036C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80030370: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80030374: sb          $a0, 0x49D($t6)
    MEM_B(0X49D, ctx->r14) = ctx->r4;
    // 0x80030378: lbu         $v1, 0x14($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X14);
    // 0x8003037C: beql        $ra, $v1, L_800303B0
    if (ctx->r31 == ctx->r3) {
        // 0x80030380: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_800303B0;
    }
    goto skip_9;
    // 0x80030380: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_9:
    // 0x80030384: lhu         $t3, 0x12($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X12);
    // 0x80030388: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8003038C: addu        $v0, $s2, $t2
    ctx->r2 = ADD32(ctx->r18, ctx->r10);
    // 0x80030390: addu        $t9, $s2, $t3
    ctx->r25 = ADD32(ctx->r18, ctx->r11);
    // 0x80030394: sb          $v1, 0x9C($t9)
    MEM_B(0X9C, ctx->r25) = ctx->r3;
    // 0x80030398: sh          $t8, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r24;
    // 0x8003039C: lbu         $t7, 0x9D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X9D);
    // 0x800303A0: sb          $t7, 0x14($s2)
    MEM_B(0X14, ctx->r18) = ctx->r15;
    // 0x800303A4: b           L_800303D0
    // 0x800303A8: sb          $a0, 0x9D($v0)
    MEM_B(0X9D, ctx->r2) = ctx->r4;
        goto L_800303D0;
    // 0x800303A8: sb          $a0, 0x9D($v0)
    MEM_B(0X9D, ctx->r2) = ctx->r4;
    // 0x800303AC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_800303B0:
    // 0x800303B0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800303B4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800303B8: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x800303BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800303C0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800303C4: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800303C8: jal         0x80030D70
    // 0x800303CC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    func_80030D70(rdram, ctx);
        goto after_0;
    // 0x800303CC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    after_0:
L_800303D0:
    // 0x800303D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800303D4:
    // 0x800303D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800303D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800303DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800303E0: jr          $ra
    // 0x800303E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800303E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361F0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800361F4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800361F8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800361FC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80036200: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80036204: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80036208: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8003620C: beql        $at, $zero, L_80036334
    if (ctx->r1 == 0) {
        // 0x80036210: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_80036334;
    }
    goto skip_0;
    // 0x80036210: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x80036214: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036218: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003621C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80036220: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80036224: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80036228: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8003622C: bc1fl       L_80036240
    if (!c1cs) {
        // 0x80036230: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_80036240;
    }
    goto skip_1;
    // 0x80036230: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x80036234: b           L_80036240
    // 0x80036238: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_80036240;
    // 0x80036238: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8003623C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80036240:
    // 0x80036240: ldc1        $f8, 0x1BD8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1BD8);
    // 0x80036244: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x80036248: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003624C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x80036250: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80036254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036258: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8003625C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x80036260: nop

    // 0x80036264: bc1fl       L_80036284
    if (!c1cs) {
        // 0x80036268: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_80036284;
    }
    goto skip_2;
    // 0x80036268: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8003626C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x80036270: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80036274: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80036278: b           L_80036294
    // 0x8003627C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_80036294;
    // 0x8003627C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80036280: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_80036284:
    // 0x80036284: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80036288: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8003628C: nop

    // 0x80036290: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_80036294:
    // 0x80036294: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036298: ldc1        $f10, 0x1BE0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1BE0);
    // 0x8003629C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800362A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800362A4: ldc1        $f6, 0x1BE8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1BE8);
    // 0x800362A8: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800362AC: addiu       $v1, $v1, 0x1BB0
    ctx->r3 = ADD32(ctx->r3, 0X1BB0);
    // 0x800362B0: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800362B4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800362B8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800362BC: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800362C0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800362C4: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800362C8: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800362CC: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800362D0: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800362D4: nop

    // 0x800362D8: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800362DC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800362E0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800362E4: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800362E8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800362EC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800362F0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800362F4: bne         $t0, $zero, L_80036314
    if (ctx->r8 != 0) {
        // 0x800362F8: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_80036314;
    }
    // 0x800362F8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800362FC: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80036300: nop

    // 0x80036304: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80036308: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8003630C: jr          $ra
    // 0x80036310: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80036310: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80036314:
    // 0x80036314: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80036318: nop

    // 0x8003631C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80036320: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x80036324: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80036328: jr          $ra
    // 0x8003632C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8003632C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80036330: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_80036334:
    // 0x80036334: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036338: bc1t        L_8003634C
    if (c1cs) {
        // 0x8003633C: nop
    
            goto L_8003634C;
    }
    // 0x8003633C: nop

    // 0x80036340: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036344: jr          $ra
    // 0x80036348: lwc1        $f0, 0x1F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1F10);
    return;
    // 0x80036348: lwc1        $f0, 0x1F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1F10);
L_8003634C:
    // 0x8003634C: lwc1        $f0, 0x1BF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1BF0);
    // 0x80036350: jr          $ra
    // 0x80036354: nop

    return;
    // 0x80036354: nop

    // 0x80036358: nop

    // 0x8003635C: nop

;}
RECOMP_FUNC void guTranslateF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003615C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80036160: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80036164: jal         0x80035300
    // 0x80036168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80036168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003616C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036170: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80036174: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x80036178: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003617C: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x80036180: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036184: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x80036188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003618C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036190: jr          $ra
    // 0x80036194: nop

    return;
    // 0x80036194: nop

;}
RECOMP_FUNC void func_80012BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012BE0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80012BE4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80012BE8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80012BEC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80012BF0: lw          $t6, 0x4F1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F1C);
    // 0x80012BF4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80012BF8: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x80012BFC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80012C00: beq         $t8, $zero, L_80012C40
    if (ctx->r24 == 0) {
        // 0x80012C04: nop
    
            goto L_80012C40;
    }
    // 0x80012C04: nop

    // 0x80012C08: lhu         $t9, -0x3A6E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A6E);
    // 0x80012C0C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012C10: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x80012C14: bne         $t3, $zero, L_80012C40
    if (ctx->r11 != 0) {
        // 0x80012C18: nop
    
            goto L_80012C40;
    }
    // 0x80012C18: nop

    // 0x80012C1C: lhu         $a0, -0x44D2($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X44D2);
    // 0x80012C20: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80012C24: lw          $t6, 0x6ED8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6ED8);
    // 0x80012C28: sra         $t4, $a0, 1
    ctx->r12 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80012C2C: andi        $a0, $t4, 0x7
    ctx->r4 = ctx->r12 & 0X7;
    // 0x80012C30: beq         $a0, $t6, L_80012C40
    if (ctx->r4 == ctx->r14) {
        // 0x80012C34: nop
    
            goto L_80012C40;
    }
    // 0x80012C34: nop

    // 0x80012C38: jal         0x80013F5C
    // 0x80012C3C: nop

    func_80013F5C(rdram, ctx);
        goto after_0;
    // 0x80012C3C: nop

    after_0:
L_80012C40:
    // 0x80012C40: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80012C44: lw          $t7, 0x6DC0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6DC0);
    // 0x80012C48: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80012C4C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012C50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80012C54: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80012C58: lw          $t9, -0x3368($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3368);
    // 0x80012C5C: addiu       $a0, $a0, 0x6DC0
    ctx->r4 = ADD32(ctx->r4, 0X6DC0);
    // 0x80012C60: jalr        $t9
    // 0x80012C64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80012C64: nop

    after_1:
    // 0x80012C68: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80012C6C: lw          $t3, -0x4D1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4D1C);
    // 0x80012C70: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012C74: addiu       $v1, $v1, 0x6ED8
    ctx->r3 = ADD32(ctx->r3, 0X6ED8);
    // 0x80012C78: andi        $t4, $t3, 0x82
    ctx->r12 = ctx->r11 & 0X82;
    // 0x80012C7C: bne         $t4, $zero, L_80012D08
    if (ctx->r12 != 0) {
        // 0x80012C80: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_80012D08;
    }
    // 0x80012C80: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80012C84: lw          $t5, -0x39C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X39C8);
    // 0x80012C88: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80012C8C: bne         $t5, $zero, L_80012D08
    if (ctx->r13 != 0) {
        // 0x80012C90: nop
    
            goto L_80012D08;
    }
    // 0x80012C90: nop

    // 0x80012C94: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80012C98: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80012C9C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80012CA0: bne         $t7, $zero, L_80012D08
    if (ctx->r15 != 0) {
        // 0x80012CA4: nop
    
            goto L_80012D08;
    }
    // 0x80012CA4: nop

    // 0x80012CA8: lw          $t8, 0x4F1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F1C);
    // 0x80012CAC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80012CB0: lhu         $t9, 0x14($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X14);
    // 0x80012CB4: andi        $t3, $t9, 0x2
    ctx->r11 = ctx->r25 & 0X2;
    // 0x80012CB8: bne         $t3, $zero, L_80012D08
    if (ctx->r11 != 0) {
        // 0x80012CBC: nop
    
            goto L_80012D08;
    }
    // 0x80012CBC: nop

    // 0x80012CC0: lhu         $t4, 0x2876($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2876);
    // 0x80012CC4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80012CC8: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x80012CCC: beq         $t5, $zero, L_80012D08
    if (ctx->r13 == 0) {
        // 0x80012CD0: nop
    
            goto L_80012D08;
    }
    // 0x80012CD0: nop

    // 0x80012CD4: lw          $v0, 0x6B88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6B88);
    // 0x80012CD8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80012CDC: bne         $at, $zero, L_80012D08
    if (ctx->r1 != 0) {
        // 0x80012CE0: nop
    
            goto L_80012D08;
    }
    // 0x80012CE0: nop

    // 0x80012CE4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80012CE8: addiu       $a0, $t6, 0x1
    ctx->r4 = ADD32(ctx->r14, 0X1);
    // 0x80012CEC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80012CF0: bne         $at, $zero, L_80012D00
    if (ctx->r1 != 0) {
        // 0x80012CF4: sw          $a0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r4;
            goto L_80012D00;
    }
    // 0x80012CF4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80012CF8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80012CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80012D00:
    // 0x80012D00: jal         0x80013F5C
    // 0x80012D04: nop

    func_80013F5C(rdram, ctx);
        goto after_2;
    // 0x80012D04: nop

    after_2:
L_80012D08:
    // 0x80012D08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012D0C: lwc1        $f4, 0x6ECC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ECC);
    // 0x80012D10: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012D14: lwc1        $f6, 0x6ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6ED0);
    // 0x80012D18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012D20: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012D24: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80012D28: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012D2C: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80012D30: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80012D34: lw          $a2, 0x6EC8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6EC8);
    // 0x80012D38: addiu       $a1, $a1, 0x6F00
    ctx->r5 = ADD32(ctx->r5, 0X6F00);
    // 0x80012D3C: addiu       $a0, $a0, 0x6E48
    ctx->r4 = ADD32(ctx->r4, 0X6E48);
    // 0x80012D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80012D44: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80012D48: jal         0x80035A00
    // 0x80012D4C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_3;
    // 0x80012D4C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80012D50: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80012D54: ori         $at, $zero, 0x80C0
    ctx->r1 = 0 | 0X80C0;
    // 0x80012D58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80012D5C: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80012D60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012D64: lwc1        $f10, 0x6DD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6DD4);
    // 0x80012D68: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012D6C: lwc1        $f16, 0x6DD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6DD8);
    // 0x80012D70: lwc1        $f18, 0x6DDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6DDC);
    // 0x80012D74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012D78: lwc1        $f4, 0x6DE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6DE0);
    // 0x80012D7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012D80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012D84: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012D88: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012D8C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80012D90: lw          $a3, 0x6DD0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6DD0);
    // 0x80012D94: lw          $a2, 0x6DCC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6DCC);
    // 0x80012D98: addiu       $a0, $a0, 0x6E88
    ctx->r4 = ADD32(ctx->r4, 0X6E88);
    // 0x80012D9C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80012DA0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80012DA4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80012DA8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80012DAC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80012DB0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80012DB4: jal         0x80035C90
    // 0x80012DB8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    guLookAtReflectF(rdram, ctx);
        goto after_4;
    // 0x80012DB8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80012DBC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012DC0: addiu       $a0, $a0, 0x6E48
    ctx->r4 = ADD32(ctx->r4, 0X6E48);
    // 0x80012DC4: jal         0x80035200
    // 0x80012DC8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_5;
    // 0x80012DC8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_5:
    // 0x80012DCC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80012DD0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012DD4: addiu       $a0, $a0, 0x6E88
    ctx->r4 = ADD32(ctx->r4, 0X6E88);
    // 0x80012DD8: jal         0x80035200
    // 0x80012DDC: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    guMtxF2L(rdram, ctx);
        goto after_6;
    // 0x80012DDC: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_6:
    // 0x80012DE0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80012DE4: addiu       $t1, $t1, 0x6C2C
    ctx->r9 = ADD32(ctx->r9, 0X6C2C);
    // 0x80012DE8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80012DEC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80012DF0: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x80012DF4: beq         $t8, $zero, L_80012EEC
    if (ctx->r24 == 0) {
        // 0x80012DF8: lw          $t9, 0x68($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X68);
            goto L_80012EEC;
    }
    // 0x80012DF8: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80012DFC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80012E00: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80012E04: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012E08: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80012E0C: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x80012E10: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x80012E14: lw          $a2, 0x6C34($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6C34);
    // 0x80012E18: lw          $a1, 0x6C30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C30);
    // 0x80012E1C: jal         0x80036198
    // 0x80012E20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    guTranslate(rdram, ctx);
        goto after_7;
    // 0x80012E20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_7:
    // 0x80012E24: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012E28: addiu       $a2, $a2, 0x6C30
    ctx->r6 = ADD32(ctx->r6, 0X6C30);
    // 0x80012E2C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80012E30: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80012E34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012E38: ldc1        $f0, 0x1340($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X1340);
    // 0x80012E3C: addiu       $a3, $a3, 0x6C34
    ctx->r7 = ADD32(ctx->r7, 0X6C34);
    // 0x80012E40: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80012E44: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80012E48: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80012E4C: mul.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80012E50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80012E54: addiu       $t1, $t1, 0x6C2C
    ctx->r9 = ADD32(ctx->r9, 0X6C2C);
    // 0x80012E58: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80012E5C: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80012E60: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012E64: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80012E68: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x80012E6C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80012E70: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x80012E74: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x80012E78: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80012E7C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80012E80: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80012E84: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80012E88: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80012E8C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80012E90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012E94: lui         $t8, 0x103
    ctx->r24 = S32(0X103 << 16);
    // 0x80012E98: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80012E9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80012EA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012EA4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80012EA8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80012EAC: sll         $t9, $t3, 6
    ctx->r25 = S32(ctx->r11 << 6);
    // 0x80012EB0: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
    // 0x80012EB4: addiu       $t5, $t4, 0xC0
    ctx->r13 = ADD32(ctx->r12, 0XC0);
    // 0x80012EB8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80012EBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80012EC0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80012EC4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80012EC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012ECC: lui         $t3, 0x101
    ctx->r11 = S32(0X101 << 16);
    // 0x80012ED0: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80012ED4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012ED8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012EDC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80012EE0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80012EE4: b           L_80012F1C
    // 0x80012EE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_80012F1C;
    // 0x80012EE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80012EEC:
    // 0x80012EEC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80012EF0: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x80012EF4: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x80012EF8: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80012EFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012F00: lui         $t4, 0x103
    ctx->r12 = S32(0X103 << 16);
    // 0x80012F04: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x80012F08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80012F0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80012F10: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80012F14: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80012F18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80012F1C:
    // 0x80012F1C: lui         $t6, 0x101
    ctx->r14 = S32(0X101 << 16);
    // 0x80012F20: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80012F24: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012F28: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80012F2C: addiu       $t7, $t7, 0x80
    ctx->r15 = ADD32(ctx->r15, 0X80);
    // 0x80012F30: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80012F34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012F38: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80012F3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012F40: lui         $t3, 0x384
    ctx->r11 = S32(0X384 << 16);
    // 0x80012F44: lui         $t9, 0x201
    ctx->r25 = S32(0X201 << 16);
    // 0x80012F48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012F4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012F50: addiu       $t9, $t9, -0x7F40
    ctx->r25 = ADD32(ctx->r25, -0X7F40);
    // 0x80012F54: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x80012F58: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80012F5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80012F60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012F64: lui         $t5, 0x382
    ctx->r13 = S32(0X382 << 16);
    // 0x80012F68: lui         $t6, 0x201
    ctx->r14 = S32(0X201 << 16);
    // 0x80012F6C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80012F70: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80012F74: addiu       $t6, $t6, -0x7F30
    ctx->r14 = ADD32(ctx->r14, -0X7F30);
    // 0x80012F78: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80012F7C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80012F80: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012F84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80012F88: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80012F8C: ori         $t8, $t8, 0xE
    ctx->r24 = ctx->r24 | 0XE;
    // 0x80012F90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80012F94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80012F98: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80012F9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80012FA0: lhu         $t3, 0x6F00($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X6F00);
    // 0x80012FA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012FA8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80012FAC: lwc1        $f16, 0x6EC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EC8);
    // 0x80012FB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012FB4: ldc1        $f4, 0x1348($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1348);
    // 0x80012FB8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80012FBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80012FC0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80012FC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80012FC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012FCC: nop

    // 0x80012FD0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80012FD4: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80012FD8: jal         0x80035680
    // 0x80012FDC: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x80012FDC: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    after_8:
    // 0x80012FE0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80012FE4: jal         0x800361F0
    // 0x80012FE8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x80012FE8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80012FEC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012FF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012FF4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80012FF8: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80012FFC: swc1        $f18, 0x6ED4($at)
    MEM_W(0X6ED4, ctx->r1) = ctx->f18.u32l;
    // 0x80013000: jr          $ra
    // 0x80013004: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80013004: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FB74: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8003FB78: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8003FB7C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8003FB80: beql        $t6, $v1, L_8003FBAC
    if (ctx->r14 == ctx->r3) {
        // 0x8003FB84: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003FBAC;
    }
    goto skip_0;
    // 0x8003FB84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_8003FB88:
    // 0x8003FB88: bnel        $v1, $zero, L_8003FB9C
    if (ctx->r3 != 0) {
        // 0x8003FB8C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8003FB9C;
    }
    goto skip_1;
    // 0x8003FB8C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x8003FB90: jr          $ra
    // 0x8003FB94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8003FB94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003FB98: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8003FB9C:
    // 0x8003FB9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003FBA0: bne         $v0, $v1, L_8003FB88
    if (ctx->r2 != ctx->r3) {
        // 0x8003FBA4: nop
    
            goto L_8003FB88;
    }
    // 0x8003FBA4: nop

    // 0x8003FBA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003FBAC:
    // 0x8003FBAC: jr          $ra
    // 0x8003FBB0: nop

    return;
    // 0x8003FBB0: nop

;}
RECOMP_FUNC void func_800182C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800182C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800182C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800182CC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800182D0: sh          $zero, -0x443C($at)
    MEM_H(-0X443C, ctx->r1) = 0;
    // 0x800182D4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800182D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800182DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800182E0: sh          $zero, -0x354C($at)
    MEM_H(-0X354C, ctx->r1) = 0;
    // 0x800182E4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800182E8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800182EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800182F0: addiu       $t7, $t7, -0x3668
    ctx->r15 = ADD32(ctx->r15, -0X3668);
    // 0x800182F4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800182F8: sh          $zero, -0x3424($at)
    MEM_H(-0X3424, ctx->r1) = 0;
    // 0x800182FC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80018300: sh          $zero, 0x244($v1)
    MEM_H(0X244, ctx->r3) = 0;
    // 0x80018304: sh          $zero, 0x36C($v1)
    MEM_H(0X36C, ctx->r3) = 0;
    // 0x80018308: sh          $zero, 0x494($v1)
    MEM_H(0X494, ctx->r3) = 0;
    // 0x8001830C: sh          $zero, 0x11C($v1)
    MEM_H(0X11C, ctx->r3) = 0;
    // 0x80018310: jr          $ra
    // 0x80018314: nop

    return;
    // 0x80018314: nop

;}
RECOMP_FUNC void func_80004708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000470C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80004710: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80004714: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004718: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000471C: ldc1        $f16, 0xF60($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XF60);
    // 0x80004720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004724: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80004728: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000472C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80004730: swc1        $f14, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f14.u32l;
    // 0x80004734: swc1        $f14, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f14.u32l;
    // 0x80004738: lwc1        $f6, 0x128($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X128);
    // 0x8000473C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80004740: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80004744: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80004748: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000474C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004750: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80004754: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x80004758: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8000475C: lwc1        $f18, 0x12C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80004760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004768: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000476C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80004770: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004774: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80004778: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8000477C: lwc1        $f6, 0x130($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X130);
    // 0x80004780: sub.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80004784: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80004788: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x8000478C: nop

    // 0x80004790: bc1f        L_800047B0
    if (!c1cs) {
        // 0x80004794: nop
    
            goto L_800047B0;
    }
    // 0x80004794: nop

    // 0x80004798: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000479C: ldc1        $f14, 0xF68($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0XF68);
    // 0x800047A0: sub.d       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f0.d - ctx->f14.d;
    // 0x800047A4: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800047A8: b           L_800047D8
    // 0x800047AC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
        goto L_800047D8;
    // 0x800047AC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800047B0:
    // 0x800047B0: ldc1        $f10, 0xF70($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0XF70);
    // 0x800047B4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800047B8: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800047BC: nop

    // 0x800047C0: bc1f        L_800047D8
    if (!c1cs) {
        // 0x800047C4: nop
    
            goto L_800047D8;
    }
    // 0x800047C4: nop

    // 0x800047C8: ldc1        $f14, 0xF78($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0XF78);
    // 0x800047CC: add.d       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = ctx->f0.d + ctx->f14.d;
    // 0x800047D0: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800047D4: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800047D8:
    // 0x800047D8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800047DC: ldc1        $f14, 0xF80($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0XF80);
    // 0x800047E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800047E4: ldc1        $f6, 0xF88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0XF88);
    // 0x800047E8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800047EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800047F0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800047F4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800047F8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800047FC: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80004800: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80004804: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x80004808: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x8000480C: nop

    // 0x80004810: bc1f        L_80004828
    if (!c1cs) {
        // 0x80004814: nop
    
            goto L_80004828;
    }
    // 0x80004814: nop

    // 0x80004818: sub.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f2.d - ctx->f14.d;
    // 0x8000481C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80004820: b           L_80004848
    // 0x80004824: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
        goto L_80004848;
    // 0x80004824: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_80004828:
    // 0x80004828: ldc1        $f10, 0xF90($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0XF90);
    // 0x8000482C: c.lt.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d < ctx->f10.d;
    // 0x80004830: nop

    // 0x80004834: bc1fl       L_8000484C
    if (!c1cs) {
        // 0x80004838: lhu         $t6, 0x4($s1)
        ctx->r14 = MEM_HU(ctx->r17, 0X4);
            goto L_8000484C;
    }
    goto skip_0;
    // 0x80004838: lhu         $t6, 0x4($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X4);
    skip_0:
    // 0x8000483C: add.d       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = ctx->f2.d + ctx->f14.d;
    // 0x80004840: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80004844: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_80004848:
    // 0x80004848: lhu         $t6, 0x4($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X4);
L_8000484C:
    // 0x8000484C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004850: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80004854: bne         $t8, $zero, L_800048BC
    if (ctx->r24 != 0) {
        // 0x80004858: sh          $t7, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r15;
            goto L_800048BC;
    }
    // 0x80004858: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x8000485C: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x80004860: sh          $t0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r8;
    // 0x80004864: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x80004868: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8000486C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80004870: jal         0x8001D8B0
    // 0x80004874: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80004874: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    after_0:
    // 0x80004878: jal         0x80006720
    // 0x8000487C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80006720(rdram, ctx);
        goto after_1;
    // 0x8000487C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80004880: lh          $t3, 0x52($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X52);
    // 0x80004884: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80004888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000488C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80004890: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80004894: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80004898: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x8000489C: jal         0x8001D924
    // 0x800048A0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_8001D924(rdram, ctx);
        goto after_2;
    // 0x800048A0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x800048A4: lwc1        $f4, 0x134($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X134);
    // 0x800048A8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x800048AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800048B0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800048B4: jal         0x800268D4
    // 0x800048B8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x800048B8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_3:
L_800048BC:
    // 0x800048BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800048C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800048C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800048C8: jr          $ra
    // 0x800048CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800048CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000EDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EDD8: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000EDDC: lw          $v0, -0x3BD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3BD8);
    // 0x8000EDE0: bltz        $v0, L_8000EE48
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000EDE4: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_8000EE48;
    }
    // 0x8000EDE4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000EDE8: addiu       $a1, $a1, 0x26D8
    ctx->r5 = ADD32(ctx->r5, 0X26D8);
    // 0x8000EDEC: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000EDF0: lhu         $t6, 0x2868($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2868);
    // 0x8000EDF4: lhu         $v1, 0x192($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X192);
    // 0x8000EDF8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EDFC: sw          $zero, -0x3BD8($at)
    MEM_W(-0X3BD8, ctx->r1) = 0;
    // 0x8000EE00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EE04: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000EE08: addiu       $a0, $a0, 0x2866
    ctx->r4 = ADD32(ctx->r4, 0X2866);
    // 0x8000EE0C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x8000EE10: sh          $t6, 0x286A($at)
    MEM_H(0X286A, ctx->r1) = ctx->r14;
L_8000EE14:
    // 0x8000EE14: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8000EE18: lhu         $t8, -0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, -0X2);
    // 0x8000EE1C: lhu         $t9, -0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, -0X4);
    // 0x8000EE20: lhu         $t0, -0x6($a0)
    ctx->r8 = MEM_HU(ctx->r4, -0X6);
    // 0x8000EE24: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000EE28: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8000EE2C: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    // 0x8000EE30: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
    // 0x8000EE34: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x8000EE38: bne         $v0, $zero, L_8000EE14
    if (ctx->r2 != 0) {
        // 0x8000EE3C: sh          $t0, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r8;
            goto L_8000EE14;
    }
    // 0x8000EE3C: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x8000EE40: jr          $ra
    // 0x8000EE44: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    return;
    // 0x8000EE44: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8000EE48:
    // 0x8000EE48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EE4C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000EE50: sw          $v0, -0x3BD8($at)
    MEM_W(-0X3BD8, ctx->r1) = ctx->r2;
    // 0x8000EE54: jr          $ra
    // 0x8000EE58: nop

    return;
    // 0x8000EE58: nop

    // 0x8000EE5C: nop

;}
RECOMP_FUNC void func_80016CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016CB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016CB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80016CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016CC0: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x80016CC4: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80016CC8: beql        $t6, $zero, L_80016D54
    if (ctx->r14 == 0) {
        // 0x80016CCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016D54;
    }
    goto skip_0;
    // 0x80016CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80016CD0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80016CD4: lhu         $t7, 0x5E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X5E);
    // 0x80016CD8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80016CDC: beql        $t8, $zero, L_80016CF4
    if (ctx->r24 == 0) {
        // 0x80016CE0: lw          $t0, 0x68($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X68);
            goto L_80016CF4;
    }
    goto skip_1;
    // 0x80016CE0: lw          $t0, 0x68($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X68);
    skip_1:
    // 0x80016CE4: jal         0x8000B140
    // 0x80016CE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8000B140(rdram, ctx);
        goto after_0;
    // 0x80016CE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016CEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016CF0: lw          $t0, 0x68($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X68);
L_80016CF4:
    // 0x80016CF4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80016CF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016CFC: sh          $t9, 0x8A($t0)
    MEM_H(0X8A, ctx->r8) = ctx->r25;
    // 0x80016D00: lw          $t1, 0x64($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X64);
    // 0x80016D04: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x80016D08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80016D0C: lhu         $t2, 0xE($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XE);
    // 0x80016D10: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016D14: sh          $t2, 0x88($t3)
    MEM_H(0X88, ctx->r11) = ctx->r10;
    // 0x80016D18: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    // 0x80016D1C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80016D20: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x80016D24: sh          $t5, 0x86($t6)
    MEM_H(0X86, ctx->r14) = ctx->r13;
    // 0x80016D28: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x80016D2C: swc1        $f4, 0x90($t7)
    MEM_W(0X90, ctx->r15) = ctx->f4.u32l;
    // 0x80016D30: lhu         $t8, 0x5E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X5E);
    // 0x80016D34: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80016D38: bnel        $t9, $zero, L_80016D54
    if (ctx->r25 != 0) {
        // 0x80016D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016D54;
    }
    goto skip_2;
    // 0x80016D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80016D40: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x80016D44: lhu         $t0, 0x2A($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2A);
    // 0x80016D48: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80016D4C: sh          $t1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r9;
    // 0x80016D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016D54:
    // 0x80016D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016D58: jr          $ra
    // 0x80016D5C: nop

    return;
    // 0x80016D5C: nop

;}
RECOMP_FUNC void func_80036820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036820: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80036824: beql        $v0, $zero, L_80036838
    if (ctx->r2 == 0) {
        // 0x80036828: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_80036838;
    }
    goto skip_0;
    // 0x80036828: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x8003682C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80036830: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80036834: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_80036838:
    // 0x80036838: beq         $v0, $zero, L_80036848
    if (ctx->r2 == 0) {
        // 0x8003683C: nop
    
            goto L_80036848;
    }
    // 0x8003683C: nop

    // 0x80036840: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80036844: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80036848:
    // 0x80036848: jr          $ra
    // 0x8003684C: nop

    return;
    // 0x8003684C: nop

;}
RECOMP_FUNC void func_801006D8_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801006D8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x801006DC: addiu       $a2, $a2, -0x4D04
    ctx->r6 = ADD32(ctx->r6, -0X4D04);
    // 0x801006E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801006E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801006E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801006EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801006F0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x801006F4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801006F8: addiu       $t8, $t8, 0x3138
    ctx->r24 = ADD32(ctx->r24, 0X3138);
    // 0x801006FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80100700: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100704: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80100708: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8010070C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100710: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80100714: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100718: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8010071C: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x80100720: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80100724: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80100728: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8010072C: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x80100730: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80100734: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100738: jal         0x80100BA0
    // 0x8010073C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_80100BA0_ovl_title(rdram, ctx);
        goto after_0;
    // 0x8010073C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_0:
    // 0x80100740: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100744: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80100748: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x8010074C: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x80100750: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80100754: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80100758: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8010075C: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x80100760: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80100764: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80100768: bne         $at, $zero, L_80100784
    if (ctx->r1 != 0) {
        // 0x8010076C: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80100784;
    }
    // 0x8010076C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80100770: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80100774: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x80100778: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8010077C: b           L_80100798
    // 0x80100780: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80100798;
    // 0x80100780: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80100784:
    // 0x80100784: bgez        $v0, L_80100798
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80100788: negu        $t5, $v1
        ctx->r13 = SUB32(0, ctx->r3);
            goto L_80100798;
    }
    // 0x80100788: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x8010078C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80100790: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80100794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100798:
    // 0x80100798: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8010079C: lw          $t6, 0x3420($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3420);
    // 0x801007A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801007A4: sw          $v0, -0x52AC($at)
    MEM_W(-0X52AC, ctx->r1) = ctx->r2;
    // 0x801007A8: bne         $t6, $zero, L_80100AF4
    if (ctx->r14 != 0) {
        // 0x801007AC: nop
    
            goto L_80100AF4;
    }
    // 0x801007AC: nop

    // 0x801007B0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801007B4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801007B8: addiu       $v1, $v1, 0x2876
    ctx->r3 = ADD32(ctx->r3, 0X2876);
    // 0x801007BC: bne         $v0, $zero, L_80100820
    if (ctx->r2 != 0) {
        // 0x801007C0: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80100820;
    }
    // 0x801007C0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801007C4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x801007C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801007CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801007D0: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x801007D4: beq         $t8, $zero, L_80100820
    if (ctx->r24 == 0) {
        // 0x801007D8: nop
    
            goto L_80100820;
    }
    // 0x801007D8: nop

    // 0x801007DC: jal         0x80025B8C
    // 0x801007E0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_1;
    // 0x801007E0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x801007E4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801007E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801007EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801007F0: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x801007F4: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x801007F8: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x801007FC: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80100800: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80100804: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80100808: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8010080C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80100810: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80100814: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100818: b           L_80100AF4
    // 0x8010081C: sw          $t5, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r13;
        goto L_80100AF4;
    // 0x8010081C: sw          $t5, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r13;
L_80100820:
    // 0x80100820: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80100824: bne         $t2, $v0, L_801008F4
    if (ctx->r10 != ctx->r2) {
        // 0x80100828: addiu       $v1, $v1, 0x2876
        ctx->r3 = ADD32(ctx->r3, 0X2876);
            goto L_801008F4;
    }
    // 0x80100828: addiu       $v1, $v1, 0x2876
    ctx->r3 = ADD32(ctx->r3, 0X2876);
    // 0x8010082C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80100830: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100834: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100838: andi        $t6, $v0, 0xB000
    ctx->r14 = ctx->r2 & 0XB000;
    // 0x8010083C: beq         $t6, $zero, L_80100894
    if (ctx->r14 == 0) {
        // 0x80100840: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_80100894;
    }
    // 0x80100840: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x80100844: jal         0x80025B8C
    // 0x80100848: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_2;
    // 0x80100848: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x8010084C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100850: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80100854: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80100858: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x8010085C: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x80100860: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x80100864: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80100868: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8010086C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80100870: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80100874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80100878: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8010087C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100880: sw          $t9, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r25;
    // 0x80100884: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100888: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8010088C: b           L_80100AF4
    // 0x80100890: sw          $t4, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r12;
        goto L_80100AF4;
    // 0x80100890: sw          $t4, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r12;
L_80100894:
    // 0x80100894: beq         $t5, $zero, L_80100AF4
    if (ctx->r13 == 0) {
        // 0x80100898: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80100AF4;
    }
    // 0x80100898: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8010089C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801008A0: jal         0x80025B8C
    // 0x801008A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_3;
    // 0x801008A4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_3:
    // 0x801008A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801008AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801008B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801008B4: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x801008B8: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x801008BC: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x801008C0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801008C4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801008C8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801008CC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801008D0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x801008D4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x801008D8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801008DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801008E0: sw          $t2, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r10;
    // 0x801008E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801008E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801008EC: b           L_80100AF4
    // 0x801008F0: sw          $t9, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r25;
        goto L_80100AF4;
    // 0x801008F0: sw          $t9, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r25;
L_801008F4:
    // 0x801008F4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x801008F8: beq         $t3, $v0, L_80100908
    if (ctx->r11 == ctx->r2) {
        // 0x801008FC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80100908;
    }
    // 0x801008FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80100900: bnel        $v0, $at, L_80100A1C
    if (ctx->r2 != ctx->r1) {
        // 0x80100904: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80100A1C;
    }
    goto skip_0;
    // 0x80100904: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_0:
L_80100908:
    // 0x80100908: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8010090C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100910: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100914: andi        $t4, $v0, 0xB000
    ctx->r12 = ctx->r2 & 0XB000;
    // 0x80100918: beq         $t4, $zero, L_801009BC
    if (ctx->r12 == 0) {
        // 0x8010091C: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_801009BC;
    }
    // 0x8010091C: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x80100920: jal         0x80025B8C
    // 0x80100924: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_4;
    // 0x80100924: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_4:
    // 0x80100928: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8010092C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80100930: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x80100934: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x80100938: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8010093C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80100940: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80100944: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80100948: lb          $t8, -0x52B0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52B0);
    // 0x8010094C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80100950: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100954: sw          $t6, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r14;
    // 0x80100958: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8010095C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100960: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80100964: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x80100968: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8010096C: bne         $t8, $zero, L_80100998
    if (ctx->r24 != 0) {
        // 0x80100970: sw          $t7, -0x52CC($at)
        MEM_W(-0X52CC, ctx->r1) = ctx->r15;
            goto L_80100998;
    }
    // 0x80100970: sw          $t7, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r15;
    // 0x80100974: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80100978: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8010097C: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x80100980: bne         $t3, $t9, L_80100990
    if (ctx->r11 != ctx->r25) {
        // 0x80100984: nop
    
            goto L_80100990;
    }
    // 0x80100984: nop

    // 0x80100988: b           L_80100AF4
    // 0x8010098C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
        goto L_80100AF4;
    // 0x8010098C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_80100990:
    // 0x80100990: b           L_80100AF4
    // 0x80100994: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_80100AF4;
    // 0x80100994: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_80100998:
    // 0x80100998: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8010099C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x801009A0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x801009A4: bne         $t3, $t6, L_801009B4
    if (ctx->r11 != ctx->r14) {
        // 0x801009A8: nop
    
            goto L_801009B4;
    }
    // 0x801009A8: nop

    // 0x801009AC: b           L_80100AF4
    // 0x801009B0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_80100AF4;
    // 0x801009B0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_801009B4:
    // 0x801009B4: b           L_80100AF4
    // 0x801009B8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
        goto L_80100AF4;
    // 0x801009B8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_801009BC:
    // 0x801009BC: beq         $t9, $zero, L_80100AF4
    if (ctx->r25 == 0) {
        // 0x801009C0: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80100AF4;
    }
    // 0x801009C0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x801009C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801009C8: jal         0x80025B8C
    // 0x801009CC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_5;
    // 0x801009CC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_5:
    // 0x801009D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801009D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801009D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801009DC: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x801009E0: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x801009E4: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x801009E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801009EC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801009F0: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x801009F4: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x801009F8: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x801009FC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80100A00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100A04: sw          $t2, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r10;
    // 0x80100A08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100A0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80100A10: b           L_80100AF4
    // 0x80100A14: sw          $t6, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r14;
        goto L_80100AF4;
    // 0x80100A14: sw          $t6, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r14;
    // 0x80100A18: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80100A1C:
    // 0x80100A1C: bnel        $v0, $at, L_80100A84
    if (ctx->r2 != ctx->r1) {
        // 0x80100A20: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80100A84;
    }
    goto skip_1;
    // 0x80100A20: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    skip_1:
    // 0x80100A24: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80100A28: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80100A2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100A30: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80100A34: beq         $t8, $zero, L_80100AF4
    if (ctx->r24 == 0) {
        // 0x80100A38: nop
    
            goto L_80100AF4;
    }
    // 0x80100A38: nop

    // 0x80100A3C: jal         0x80025B8C
    // 0x80100A40: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_6;
    // 0x80100A40: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x80100A44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100A48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80100A4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80100A50: addiu       $t1, $t1, -0x52C0
    ctx->r9 = ADD32(ctx->r9, -0X52C0);
    // 0x80100A54: addiu       $t0, $t0, -0x52BC
    ctx->r8 = ADD32(ctx->r8, -0X52BC);
    // 0x80100A58: addiu       $a3, $a3, -0x52C4
    ctx->r7 = ADD32(ctx->r7, -0X52C4);
    // 0x80100A5C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80100A60: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80100A64: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80100A68: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80100A6C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80100A70: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80100A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100A78: b           L_80100AF4
    // 0x80100A7C: sw          $t2, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r10;
        goto L_80100AF4;
    // 0x80100A7C: sw          $t2, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r10;
    // 0x80100A80: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_80100A84:
    // 0x80100A84: bnel        $v0, $at, L_80100AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80100A88: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80100AC0;
    }
    goto skip_2;
    // 0x80100A88: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_2:
    // 0x80100A8C: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x80100A90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100A94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100A98: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x80100A9C: beq         $t6, $zero, L_80100AF4
    if (ctx->r14 == 0) {
        // 0x80100AA0: nop
    
            goto L_80100AF4;
    }
    // 0x80100AA0: nop

    // 0x80100AA4: jal         0x80025B8C
    // 0x80100AA8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_7;
    // 0x80100AA8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_7:
    // 0x80100AAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80100AB0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100AB4: b           L_80100AF4
    // 0x80100AB8: sw          $t7, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r15;
        goto L_80100AF4;
    // 0x80100AB8: sw          $t7, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r15;
    // 0x80100ABC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80100AC0:
    // 0x80100AC0: bne         $v0, $at, L_80100AF4
    if (ctx->r2 != ctx->r1) {
        // 0x80100AC4: nop
    
            goto L_80100AF4;
    }
    // 0x80100AC4: nop

    // 0x80100AC8: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80100ACC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80100AD0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100AD4: andi        $t9, $t8, 0xB000
    ctx->r25 = ctx->r24 & 0XB000;
    // 0x80100AD8: beq         $t9, $zero, L_80100AF4
    if (ctx->r25 == 0) {
        // 0x80100ADC: nop
    
            goto L_80100AF4;
    }
    // 0x80100ADC: nop

    // 0x80100AE0: jal         0x80025B8C
    // 0x80100AE4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_8;
    // 0x80100AE4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_8:
    // 0x80100AE8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80100AEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100AF0: sw          $t4, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r12;
L_80100AF4:
    // 0x80100AF4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80100AF8: lw          $t5, -0x52CC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X52CC);
    // 0x80100AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100B00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100B04: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80100B08: sw          $t6, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r14;
    // 0x80100B0C: jr          $ra
    // 0x80100B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80100B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800060D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800060D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800060D8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800060DC: addiu       $v1, $v1, 0x5368
    ctx->r3 = ADD32(ctx->r3, 0X5368);
    // 0x800060E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800060E4: lhu         $a2, 0xC($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XC);
    // 0x800060E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800060EC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800060F0: sra         $v0, $a2, 8
    ctx->r2 = S32(SIGNED(ctx->r6) >> 8);
    // 0x800060F4: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800060F8: andi        $t7, $a2, 0x4
    ctx->r15 = ctx->r6 & 0X4;
    // 0x800060FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80006100: beq         $t7, $zero, L_8000616C
    if (ctx->r15 == 0) {
        // 0x80006104: sw          $a2, -0x45B4($at)
        MEM_W(-0X45B4, ctx->r1) = ctx->r6;
            goto L_8000616C;
    }
    // 0x80006104: sw          $a2, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r6;
    // 0x80006108: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000610C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80006110: sh          $t8, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r24;
    // 0x80006114: sh          $t9, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r25;
    // 0x80006118: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x8000611C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80006120: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x80006124: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006128: lw          $a1, -0x43D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43D4);
    // 0x8000612C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006130: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006134: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80006138: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000613C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80006140: sh          $t1, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r9;
    // 0x80006144: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80006148: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8000614C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80006150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006154: jal         0x8001D8B0
    // 0x80006158: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80006158: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x8000615C: addiu       $t4, $zero, 0x13
    ctx->r12 = ADD32(0, 0X13);
    // 0x80006160: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006164: b           L_80006330
    // 0x80006168: sw          $t4, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r12;
        goto L_80006330;
    // 0x80006168: sw          $t4, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r12;
L_8000616C:
    // 0x8000616C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006170: beq         $v0, $at, L_800061A0
    if (ctx->r2 == ctx->r1) {
        // 0x80006174: lui         $a3, 0x8008
        ctx->r7 = S32(0X8008 << 16);
            goto L_800061A0;
    }
    // 0x80006174: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80006178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000617C: beq         $v0, $at, L_80006250
    if (ctx->r2 == ctx->r1) {
        // 0x80006180: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80006250;
    }
    // 0x80006180: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006184: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006188: beq         $v0, $at, L_80006250
    if (ctx->r2 == ctx->r1) {
        // 0x8000618C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80006250;
    }
    // 0x8000618C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006190: beq         $v0, $at, L_800062A8
    if (ctx->r2 == ctx->r1) {
        // 0x80006194: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_800062A8;
    }
    // 0x80006194: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80006198: b           L_80006334
    // 0x8000619C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80006334;
    // 0x8000619C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800061A0:
    // 0x800061A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800061A4: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800061A8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x800061AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800061B0: sh          $t5, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r13;
    // 0x800061B4: sh          $t6, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r14;
    // 0x800061B8: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x800061BC: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800061C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800061C4: swc1        $f0, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->f0.u32l;
    // 0x800061C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800061CC: swc1        $f0, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->f0.u32l;
    // 0x800061D0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800061D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800061D8: addiu       $a1, $a3, -0x43D0
    ctx->r5 = ADD32(ctx->r7, -0X43D0);
    // 0x800061DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800061E0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800061E4: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x800061E8: jal         0x800232F4
    // 0x800061EC: swc1        $f12, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->f12.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x800061EC: swc1        $f12, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->f12.u32l;
    after_1:
    // 0x800061F0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800061F4: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x800061F8: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800061FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006200: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80006204: swc1        $f6, -0x4420($at)
    MEM_W(-0X4420, ctx->r1) = ctx->f6.u32l;
    // 0x80006208: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000620C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80006210: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80006214: swc1        $f8, -0x441C($at)
    MEM_W(-0X441C, ctx->r1) = ctx->f8.u32l;
    // 0x80006218: lhu         $t7, -0x44D4($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X44D4);
    // 0x8000621C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006220: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80006224: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80006228: jal         0x800268D4
    // 0x8000622C: sh          $t8, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r24;
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x8000622C: sh          $t8, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r24;
    after_2:
    // 0x80006230: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80006234: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80006238: jal         0x800268D4
    // 0x8000623C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x8000623C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_3:
    // 0x80006240: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80006244: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006248: b           L_80006330
    // 0x8000624C: sw          $t9, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r25;
        goto L_80006330;
    // 0x8000624C: sw          $t9, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r25;
L_80006250:
    // 0x80006250: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006254: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x80006258: jal         0x80006340
    // 0x8000625C: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_80006340(rdram, ctx);
        goto after_4;
    // 0x8000625C: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_4:
    // 0x80006260: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006264: addiu       $v1, $v1, 0x5368
    ctx->r3 = ADD32(ctx->r3, 0X5368);
    // 0x80006268: lhu         $t0, 0xC($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0XC);
    // 0x8000626C: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80006270: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006274: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80006278: beq         $t1, $zero, L_80006290
    if (ctx->r9 == 0) {
        // 0x8000627C: lui         $t4, 0x8008
        ctx->r12 = S32(0X8008 << 16);
            goto L_80006290;
    }
    // 0x8000627C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80006280: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80006284: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006288: b           L_80006294
    // 0x8000628C: sw          $t2, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r10;
        goto L_80006294;
    // 0x8000628C: sw          $t2, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r10;
L_80006290:
    // 0x80006290: sw          $t3, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r11;
L_80006294:
    // 0x80006294: lhu         $t4, -0x44D4($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X44D4);
    // 0x80006298: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000629C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800062A0: b           L_80006330
    // 0x800062A4: sh          $t5, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r13;
        goto L_80006330;
    // 0x800062A4: sh          $t5, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r13;
L_800062A8:
    // 0x800062A8: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x800062AC: lw          $t8, 0x4F24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F24);
    // 0x800062B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800062B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800062B8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800062BC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800062C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800062C4: jal         0x8000DB7C
    // 0x800062C8: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    func_8000DB7C(rdram, ctx);
        goto after_5;
    // 0x800062C8: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    after_5:
    // 0x800062CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800062D0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800062D4: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x800062D8: sh          $t9, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r25;
    // 0x800062DC: sh          $t0, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r8;
    // 0x800062E0: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x800062E4: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800062E8: lhu         $t1, -0x44D4($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X44D4);
    // 0x800062EC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800062F0: lw          $a1, -0x43D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43D4);
    // 0x800062F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800062F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800062FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80006300: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80006304: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80006308: sh          $t2, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r10;
    // 0x8000630C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80006310: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80006314: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80006318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000631C: jal         0x8001D8B0
    // 0x80006320: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_6;
    // 0x80006320: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_6:
    // 0x80006324: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    // 0x80006328: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000632C: sw          $t5, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r13;
L_80006330:
    // 0x80006330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80006334:
    // 0x80006334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006338: jr          $ra
    // 0x8000633C: nop

    return;
    // 0x8000633C: nop

;}
RECOMP_FUNC void func_8001DC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC78: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001DC7C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001DC80: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001DC84: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001DC88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001DC8C: lw          $s4, 0x104($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X104);
    // 0x8001DC90: lw          $fp, 0x114($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X114);
    // 0x8001DC94: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001DC98: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001DC9C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001DCA0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001DCA4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001DCA8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001DCAC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001DCB0: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x8001DCB4: sw          $a2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r6;
    // 0x8001DCB8: sw          $a3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r7;
    // 0x8001DCBC: sll         $t6, $s4, 5
    ctx->r14 = S32(ctx->r20 << 5);
    // 0x8001DCC0: addu        $s2, $t6, $fp
    ctx->r18 = ADD32(ctx->r14, ctx->r30);
    // 0x8001DCC4: lhu         $a2, 0x6($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X6);
    // 0x8001DCC8: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x8001DCCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001DCD0: beql        $a2, $zero, L_8001DD10
    if (ctx->r6 == 0) {
        // 0x8001DCD4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001DD10;
    }
    goto skip_0;
    // 0x8001DCD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    skip_0:
    // 0x8001DCD8: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x8001DCDC: bne         $a2, $zero, L_8001DCE8
    if (ctx->r6 != 0) {
        // 0x8001DCE0: nop
    
            goto L_8001DCE8;
    }
    // 0x8001DCE0: nop

    // 0x8001DCE4: break       7
    do_break(2147605732);
L_8001DCE8:
    // 0x8001DCE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DCEC: bne         $a2, $at, L_8001DD00
    if (ctx->r6 != ctx->r1) {
        // 0x8001DCF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DD00;
    }
    // 0x8001DCF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DCF4: bne         $t7, $at, L_8001DD00
    if (ctx->r15 != ctx->r1) {
        // 0x8001DCF8: nop
    
            goto L_8001DD00;
    }
    // 0x8001DCF8: nop

    // 0x8001DCFC: break       6
    do_break(2147605756);
L_8001DD00:
    // 0x8001DD00: mfhi        $a2
    ctx->r6 = hi;
    // 0x8001DD04: b           L_8001DD10
    // 0x8001DD08: nop

        goto L_8001DD10;
    // 0x8001DD08: nop

    // 0x8001DD0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001DD10:
    // 0x8001DD10: jal         0x80022B40
    // 0x8001DD14: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    func_80022B40(rdram, ctx);
        goto after_0;
    // 0x8001DD14: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_0:
    // 0x8001DD18: lb          $t8, 0x14($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X14);
    // 0x8001DD1C: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8001DD20: lw          $s7, 0x100($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X100);
    // 0x8001DD24: bne         $t8, $zero, L_8001DD58
    if (ctx->r24 != 0) {
        // 0x8001DD28: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8001DD58;
    }
    // 0x8001DD28: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001DD2C: andi        $t9, $s7, 0x1
    ctx->r25 = ctx->r23 & 0X1;
    // 0x8001DD30: beq         $t9, $zero, L_8001DD48
    if (ctx->r25 == 0) {
        // 0x8001DD34: andi        $t0, $s7, 0x2
        ctx->r8 = ctx->r23 & 0X2;
            goto L_8001DD48;
    }
    // 0x8001DD34: andi        $t0, $s7, 0x2
    ctx->r8 = ctx->r23 & 0X2;
    // 0x8001DD38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DD3C: nop

    // 0x8001DD40: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8001DD44: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
L_8001DD48:
    // 0x8001DD48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DD4C: beql        $t0, $zero, L_8001DD5C
    if (ctx->r8 == 0) {
        // 0x8001DD50: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_8001DD5C;
    }
    goto skip_1;
    // 0x8001DD50: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    skip_1:
    // 0x8001DD54: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_8001DD58:
    // 0x8001DD58: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
L_8001DD5C:
    // 0x8001DD5C: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001DD60: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001DD64: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001DD68: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001DD6C: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001DD70: lw          $s7, 0x100($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X100);
    // 0x8001DD74: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8001DD78: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8001DD7C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8001DD80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001DD84: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001DD88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001DD8C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001DD90: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001DD94: jal         0x80023C1C
    // 0x8001DD98: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_80023C1C(rdram, ctx);
        goto after_1;
    // 0x8001DD98: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8001DD9C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001DDA0: jal         0x8001E138
    // 0x8001DDA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8001E138(rdram, ctx);
        goto after_2;
    // 0x8001DDA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x8001DDA8: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001DDAC: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001DDB0: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8001DDB4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001DDB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001DDBC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001DDC0: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8001DDC4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001DDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DDCC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8001DDD0: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x8001DDD4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001DDD8: swc1        $f18, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f18.u32l;
    // 0x8001DDDC: swc1        $f8, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f8.u32l;
    // 0x8001DDE0: lbu         $t1, 0x16($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X16);
    // 0x8001DDE4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001DDE8: beql        $t2, $zero, L_8001DE78
    if (ctx->r10 == 0) {
        // 0x8001DDEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001DE78;
    }
    goto skip_2;
    // 0x8001DDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8001DDF0: jal         0x80023E80
    // 0x8001DDF4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80023E80(rdram, ctx);
        goto after_3;
    // 0x8001DDF4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8001DDF8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001DDFC: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8001DE00: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001DE04: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001DE08: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001DE0C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8001DE10: addiu       $s1, $s1, -0x3A18
    ctx->r17 = ADD32(ctx->r17, -0X3A18);
    // 0x8001DE14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DE18: lw          $a1, 0xD0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD0);
    // 0x8001DE1C: lw          $a2, 0xD4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD4);
    // 0x8001DE20: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
    // 0x8001DE24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8001DE28: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8001DE2C: jal         0x8002371C
    // 0x8001DE30: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    func_8002371C(rdram, ctx);
        goto after_4;
    // 0x8001DE30: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8001DE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DE38: lw          $a1, 0xF4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF4);
    // 0x8001DE3C: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8001DE40: jal         0x80023DF4
    // 0x8001DE44: lw          $a3, 0xFC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XFC);
    func_80023DF4(rdram, ctx);
        goto after_5;
    // 0x8001DE44: lw          $a3, 0xFC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XFC);
    after_5:
    // 0x8001DE48: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001DE4C: addiu       $s0, $s0, -0x4D08
    ctx->r16 = ADD32(ctx->r16, -0X4D08);
    // 0x8001DE50: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8001DE54: lw          $s6, 0x118($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X118);
    // 0x8001DE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DE5C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8001DE60: addu        $a1, $s6, $t4
    ctx->r5 = ADD32(ctx->r22, ctx->r12);
    // 0x8001DE64: jal         0x80035200
    // 0x8001DE68: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_6;
    // 0x8001DE68: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_6:
    // 0x8001DE6C: b           L_8001DEA8
    // 0x8001DE70: nop

        goto L_8001DEA8;
    // 0x8001DE70: nop

    // 0x8001DE74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001DE78:
    // 0x8001DE78: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8001DE7C: jal         0x80023E80
    // 0x8001DE80: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80023E80(rdram, ctx);
        goto after_7;
    // 0x8001DE80: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_7:
    // 0x8001DE84: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001DE88: addiu       $s0, $s0, -0x4D08
    ctx->r16 = ADD32(ctx->r16, -0X4D08);
    // 0x8001DE8C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001DE90: lw          $s6, 0x118($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X118);
    // 0x8001DE94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001DE98: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8001DE9C: addu        $a1, $s6, $t6
    ctx->r5 = ADD32(ctx->r22, ctx->r14);
    // 0x8001DEA0: jal         0x80035200
    // 0x8001DEA4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_8;
    // 0x8001DEA4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_8:
L_8001DEA8:
    // 0x8001DEA8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001DEAC: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001DEB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001DEB4: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8001DEB8: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8001DEBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001DEC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001DEC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001DEC8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8001DECC: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x8001DED0: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x8001DED4: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x8001DED8: addiu       $t1, $t0, 0xC0
    ctx->r9 = ADD32(ctx->r8, 0XC0);
    // 0x8001DEDC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001DEE0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8001DEE4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8001DEE8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001DEEC: addiu       $a1, $a1, -0x3A20
    ctx->r5 = ADD32(ctx->r5, -0X3A20);
    // 0x8001DEF0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001DEF4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8001DEF8: lbu         $t6, 0x16($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X16);
    // 0x8001DEFC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001DF00: addiu       $t9, $t9, -0x3A50
    ctx->r25 = ADD32(ctx->r25, -0X3A50);
    // 0x8001DF04: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8001DF08: beq         $t7, $zero, L_8001DF44
    if (ctx->r15 == 0) {
        // 0x8001DF0C: or          $s0, $fp, $zero
        ctx->r16 = ctx->r30 | 0;
            goto L_8001DF44;
    }
    // 0x8001DF0C: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x8001DF10: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8001DF14: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8001DF18: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8001DF1C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001DF20: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8001DF24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001DF28: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8001DF2C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DF30: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x8001DF34: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8001DF38: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8001DF3C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8001DF40: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
L_8001DF44:
    // 0x8001DF44: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8001DF48: lw          $s3, 0x110($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X110);
    // 0x8001DF4C: bne         $a2, $zero, L_8001DF98
    if (ctx->r6 != 0) {
        // 0x8001DF50: lw          $a1, 0x8($s3)
        ctx->r5 = MEM_W(ctx->r19, 0X8);
            goto L_8001DF98;
    }
    // 0x8001DF50: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x8001DF54: lb          $s1, 0x15($s2)
    ctx->r17 = MEM_B(ctx->r18, 0X15);
    // 0x8001DF58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DF5C: beq         $s1, $at, L_8001E000
    if (ctx->r17 == ctx->r1) {
        // 0x8001DF60: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_8001E000;
    }
    // 0x8001DF60: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8001DF64: addu        $a2, $a1, $t1
    ctx->r6 = ADD32(ctx->r5, ctx->r9);
    // 0x8001DF68: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8001DF6C: beql        $t2, $zero, L_8001E004
    if (ctx->r10 == 0) {
        // 0x8001DF70: lh          $v0, 0x0($s3)
        ctx->r2 = MEM_H(ctx->r19, 0X0);
            goto L_8001E004;
    }
    goto skip_3;
    // 0x8001DF70: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    skip_3:
    // 0x8001DF74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001DF78: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8001DF7C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8001DF80: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8001DF84: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001DF88: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8001DF8C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8001DF90: b           L_8001E004
    // 0x8001DF94: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
        goto L_8001E004;
    // 0x8001DF94: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
L_8001DF98:
    // 0x8001DF98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001DF9C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8001DFA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001DFA4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001DFA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001DFAC: lhu         $t9, 0x1C($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X1C);
    // 0x8001DFB0: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x8001DFB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001DFB8: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x8001DFBC: mfhi        $t0
    ctx->r8 = hi;
    // 0x8001DFC0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001DFC4: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8001DFC8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001DFCC: bne         $t9, $zero, L_8001DFD8
    if (ctx->r25 != 0) {
        // 0x8001DFD0: nop
    
            goto L_8001DFD8;
    }
    // 0x8001DFD0: nop

    // 0x8001DFD4: break       7
    do_break(2147606484);
L_8001DFD8:
    // 0x8001DFD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001DFDC: bne         $t9, $at, L_8001DFF0
    if (ctx->r25 != ctx->r1) {
        // 0x8001DFE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001DFF0;
    }
    // 0x8001DFE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001DFE4: bne         $t8, $at, L_8001DFF0
    if (ctx->r24 != ctx->r1) {
        // 0x8001DFE8: nop
    
            goto L_8001DFF0;
    }
    // 0x8001DFE8: nop

    // 0x8001DFEC: break       6
    do_break(2147606508);
L_8001DFF0:
    // 0x8001DFF0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001DFF4: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8001DFF8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001DFFC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_8001E000:
    // 0x8001E000: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
L_8001E004:
    // 0x8001E004: addiu       $s2, $s4, 0x1
    ctx->r18 = ADD32(ctx->r20, 0X1);
    // 0x8001E008: addiu       $s4, $sp, 0xF4
    ctx->r20 = ADD32(ctx->r29, 0XF4);
    // 0x8001E00C: blez        $v0, L_8001E07C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001E010: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001E07C;
    }
    // 0x8001E010: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001E014:
    // 0x8001E014: lb          $t7, 0x14($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X14);
    // 0x8001E018: bnel        $s2, $t7, L_8001E070
    if (ctx->r18 != ctx->r15) {
        // 0x8001E01C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001E070;
    }
    goto skip_4;
    // 0x8001E01C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8001E020: lw          $at, 0x0($s4)
    ctx->r1 = MEM_W(ctx->r20, 0X0);
    // 0x8001E024: lw          $t0, 0x108($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X108);
    // 0x8001E028: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x8001E02C: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x8001E030: lw          $a2, 0x4($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X4);
    // 0x8001E034: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8001E038: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001E03C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001E040: lw          $a3, 0x8($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X8);
    // 0x8001E044: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8001E048: sw          $fp, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r30;
    // 0x8001E04C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001E050: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001E054: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x8001E058: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8001E05C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8001E060: jal         0x8001DC78
    // 0x8001E064: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_8001DC78(rdram, ctx);
        goto after_9;
    // 0x8001E064: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_9:
    // 0x8001E068: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x8001E06C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001E070:
    // 0x8001E070: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E074: bne         $at, $zero, L_8001E014
    if (ctx->r1 != 0) {
        // 0x8001E078: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_8001E014;
    }
    // 0x8001E078: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_8001E07C:
    // 0x8001E07C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001E080: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001E084: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E088: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001E08C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001E090: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001E094: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001E098: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001E09C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001E0A0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001E0A4: jr          $ra
    // 0x8001E0A8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8001E0A8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8002B510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B510: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002B514: addiu       $v0, $v0, -0x2F4
    ctx->r2 = ADD32(ctx->r2, -0X2F4);
    // 0x8002B518: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8002B51C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002B520: sh          $t6, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r14;
    // 0x8002B524: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8002B528: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B52C: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x8002B530: or          $t8, $t7, $a0
    ctx->r24 = ctx->r15 | ctx->r4;
    // 0x8002B534: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x8002B538: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8002B53C: sh          $t0, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r8;
    // 0x8002B540: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B544: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8002B548: sb          $t1, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = ctx->r9;
    // 0x8002B54C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B550: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002B554: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B558: sb          $zero, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = 0;
    // 0x8002B55C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B560: sb          $zero, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = 0;
    // 0x8002B564: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B568: sb          $zero, -0x2D5($at)
    MEM_B(-0X2D5, ctx->r1) = 0;
    // 0x8002B56C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B570: sb          $zero, -0x2D4($at)
    MEM_B(-0X2D4, ctx->r1) = 0;
    // 0x8002B574: jr          $ra
    // 0x8002B578: nop

    return;
    // 0x8002B578: nop

;}
RECOMP_FUNC void func_8002C818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C818: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002C81C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002C820: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002C824: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002C828: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002C82C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8002C830: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8002C834: addiu       $t7, $t7, -0x660
    ctx->r15 = ADD32(ctx->r15, -0X660);
    // 0x8002C838: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002C83C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8002C840: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8002C844: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002C848: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002C84C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C850: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8002C854: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8002C858: lhu         $v1, -0x2E0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E0);
    // 0x8002C85C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002C860: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8002C864: andi        $t1, $v1, 0x20
    ctx->r9 = ctx->r3 & 0X20;
    // 0x8002C868: beq         $t1, $zero, L_8002C89C
    if (ctx->r9 == 0) {
        // 0x8002C86C: addiu       $a1, $zero, 0x33
        ctx->r5 = ADD32(0, 0X33);
            goto L_8002C89C;
    }
    // 0x8002C86C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x8002C870: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002C874: lb          $v0, -0x2D6($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2D6);
    // 0x8002C878: andi        $t2, $v1, 0xFFDF
    ctx->r10 = ctx->r3 & 0XFFDF;
    // 0x8002C87C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C880: bne         $v0, $zero, L_8002C894
    if (ctx->r2 != 0) {
        // 0x8002C884: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8002C894;
    }
    // 0x8002C884: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8002C888: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002C88C: b           L_8002C8A4
    // 0x8002C890: sh          $t2, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r10;
        goto L_8002C8A4;
    // 0x8002C890: sh          $t2, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r10;
L_8002C894:
    // 0x8002C894: b           L_8002C8A4
    // 0x8002C898: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
        goto L_8002C8A4;
    // 0x8002C898: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
L_8002C89C:
    // 0x8002C89C: lb          $v0, -0x2D6($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2D6);
    // 0x8002C8A0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8002C8A4:
    // 0x8002C8A4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8002C8A8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002C8AC: addiu       $t9, $t9, -0x2D0
    ctx->r25 = ADD32(ctx->r25, -0X2D0);
    // 0x8002C8B0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002C8B4: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x8002C8B8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8002C8BC: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x8002C8C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002C8C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002C8C8: beq         $t6, $at, L_8002CCB4
    if (ctx->r14 == ctx->r1) {
        // 0x8002C8CC: addiu       $a2, $sp, 0x34
        ctx->r6 = ADD32(ctx->r29, 0X34);
            goto L_8002CCB4;
    }
    // 0x8002C8CC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8002C8D0: lb          $t7, 0x1($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X1);
    // 0x8002C8D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002C8D8: beq         $t7, $at, L_8002CCAC
    if (ctx->r15 == ctx->r1) {
        // 0x8002C8DC: nop
    
            goto L_8002CCAC;
    }
    // 0x8002C8DC: nop

    // 0x8002C8E0: bne         $t4, $v0, L_8002C964
    if (ctx->r12 != ctx->r2) {
        // 0x8002C8E4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8002C964;
    }
    // 0x8002C8E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002C8E8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002C8EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002C8F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002C8F4: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x8002C8F8: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002C8FC: jal         0x8002AB64
    // 0x8002C900: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    func_8002AB64(rdram, ctx);
        goto after_0;
    // 0x8002C900: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    after_0:
    // 0x8002C904: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x8002C908: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C90C: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8002C910: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8002C914: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x8002C918: jal         0x80029B58
    // 0x8002C91C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x8002C91C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_1:
    // 0x8002C920: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002C924: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C928: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8002C92C: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8002C930: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002C934: jal         0x80029B58
    // 0x8002C938: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x8002C938: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x8002C93C: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x8002C940: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002C944: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8002C948: addiu       $a1, $zero, 0xD9
    ctx->r5 = ADD32(0, 0XD9);
    // 0x8002C94C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x8002C950: jal         0x80029B58
    // 0x8002C954: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x8002C954: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_3:
    // 0x8002C958: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002C95C: b           L_8002C9D8
    // 0x8002C960: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
        goto L_8002C9D8;
    // 0x8002C960: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
L_8002C964:
    // 0x8002C964: addiu       $t9, $zero, 0x48
    ctx->r25 = ADD32(0, 0X48);
    // 0x8002C968: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002C96C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x8002C970: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002C974: jal         0x8002AB64
    // 0x8002C978: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_8002AB64(rdram, ctx);
        goto after_4;
    // 0x8002C978: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x8002C97C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8002C980: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002C984: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x8002C988: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8002C98C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x8002C990: jal         0x80029B58
    // 0x8002C994: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x8002C994: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_5:
    // 0x8002C998: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002C99C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002C9A0: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8002C9A4: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8002C9A8: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002C9AC: jal         0x80029B58
    // 0x8002C9B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x8002C9B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
    // 0x8002C9B4: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8002C9B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002C9BC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8002C9C0: addiu       $a1, $zero, 0xD9
    ctx->r5 = ADD32(0, 0XD9);
    // 0x8002C9C4: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x8002C9C8: jal         0x80029B58
    // 0x8002C9CC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x8002C9CC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_7:
    // 0x8002C9D0: addiu       $t4, $zero, 0x48
    ctx->r12 = ADD32(0, 0X48);
    // 0x8002C9D4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_8002C9D8:
    // 0x8002C9D8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8002C9DC: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002C9E0: addiu       $t2, $t2, -0x2A8
    ctx->r10 = ADD32(ctx->r10, -0X2A8);
    // 0x8002C9E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002C9E8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002C9EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002C9F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002C9F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002C9F8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8002C9FC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002CA00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CA04: lbu         $a3, 0x24($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X24);
    // 0x8002CA08: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8002CA0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CA10: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x8002CA14: jal         0x8002AB64
    // 0x8002CA18: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    func_8002AB64(rdram, ctx);
        goto after_8;
    // 0x8002CA18: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_8:
    // 0x8002CA1C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8002CA20: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002CA24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CA28: lbu         $a3, 0x25($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X25);
    // 0x8002CA2C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002CA30: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8002CA34: jal         0x8002AB64
    // 0x8002CA38: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    func_8002AB64(rdram, ctx);
        goto after_9;
    // 0x8002CA38: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_9:
    // 0x8002CA3C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002CA40: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002CA44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CA48: lbu         $a3, 0x26($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X26);
    // 0x8002CA4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002CA50: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8002CA54: jal         0x8002AB64
    // 0x8002CA58: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    func_8002AB64(rdram, ctx);
        goto after_10;
    // 0x8002CA58: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_10:
    // 0x8002CA5C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002CA60: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002CA64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CA68: lbu         $a3, 0x27($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X27);
    // 0x8002CA6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002CA70: addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    // 0x8002CA74: jal         0x8002AB64
    // 0x8002CA78: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    func_8002AB64(rdram, ctx);
        goto after_11;
    // 0x8002CA78: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_11:
    // 0x8002CA7C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8002CA80: lw          $t0, 0x3C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X3C);
    // 0x8002CA84: addiu       $t1, $t0, -0xF
    ctx->r9 = ADD32(ctx->r8, -0XF);
    // 0x8002CA88: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x8002CA8C: beq         $at, $zero, L_8002CBD0
    if (ctx->r1 == 0) {
        // 0x8002CA90: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8002CBD0;
    }
    // 0x8002CA90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002CA94: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002CA98: addu        $at, $at, $t1
    gpr jr_addend_8002CAA0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8002CA9C: lw          $t1, 0x194C($at)
    ctx->r9 = ADD32(ctx->r1, 0X194C);
    // 0x8002CAA0: jr          $t1
    // 0x8002CAA4: nop

    switch (jr_addend_8002CAA0 >> 2) {
        case 0: goto L_8002CAA8; break;
        case 1: goto L_8002CACC; break;
        case 2: goto L_8002CAF0; break;
        case 3: goto L_8002CAFC; break;
        case 4: goto L_8002CBD0; break;
        case 5: goto L_8002CB20; break;
        case 6: goto L_8002CBD0; break;
        case 7: goto L_8002CB2C; break;
        case 8: goto L_8002CB50; break;
        case 9: goto L_8002CBD0; break;
        case 10: goto L_8002CBB0; break;
        case 11: goto L_8002CBBC; break;
        case 12: goto L_8002CBD0; break;
        case 13: goto L_8002CBD0; break;
        case 14: goto L_8002CBD0; break;
        case 15: goto L_8002CBC8; break;
        default: switch_error(__func__, 0x8002CAA0, 0x8007194C);
    }
    // 0x8002CAA4: nop

L_8002CAA8:
    // 0x8002CAA8: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x8002CAAC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002CAB0: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x8002CAB4: bne         $t2, $at, L_8002CAC4
    if (ctx->r10 != ctx->r1) {
        // 0x8002CAB8: nop
    
            goto L_8002CAC4;
    }
    // 0x8002CAB8: nop

    // 0x8002CABC: b           L_8002CAC4
    // 0x8002CAC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8002CAC4;
    // 0x8002CAC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8002CAC4:
    // 0x8002CAC4: b           L_8002CBD0
    // 0x8002CAC8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CAC8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CACC:
    // 0x8002CACC: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8002CAD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002CAD4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8002CAD8: bne         $t3, $at, L_8002CAE8
    if (ctx->r11 != ctx->r1) {
        // 0x8002CADC: nop
    
            goto L_8002CAE8;
    }
    // 0x8002CADC: nop

    // 0x8002CAE0: b           L_8002CAE8
    // 0x8002CAE4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002CAE8;
    // 0x8002CAE4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002CAE8:
    // 0x8002CAE8: b           L_8002CBD0
    // 0x8002CAEC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CAEC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CAF0:
    // 0x8002CAF0: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8002CAF4: b           L_8002CBD0
    // 0x8002CAF8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CAF8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CAFC:
    // 0x8002CAFC: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x8002CB00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002CB04: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8002CB08: bne         $t5, $at, L_8002CB18
    if (ctx->r13 != ctx->r1) {
        // 0x8002CB0C: nop
    
            goto L_8002CB18;
    }
    // 0x8002CB0C: nop

    // 0x8002CB10: b           L_8002CB18
    // 0x8002CB14: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_8002CB18;
    // 0x8002CB14: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_8002CB18:
    // 0x8002CB18: b           L_8002CBD0
    // 0x8002CB1C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CB1C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CB20:
    // 0x8002CB20: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x8002CB24: b           L_8002CBD0
    // 0x8002CB28: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CB28: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CB2C:
    // 0x8002CB2C: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x8002CB30: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002CB34: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8002CB38: bne         $t9, $at, L_8002CB48
    if (ctx->r25 != ctx->r1) {
        // 0x8002CB3C: nop
    
            goto L_8002CB48;
    }
    // 0x8002CB3C: nop

    // 0x8002CB40: b           L_8002CB48
    // 0x8002CB44: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
        goto L_8002CB48;
    // 0x8002CB44: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_8002CB48:
    // 0x8002CB48: b           L_8002CBD0
    // 0x8002CB4C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CB4C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CB50:
    // 0x8002CB50: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x8002CB54: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002CB58: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x8002CB5C: beq         $v0, $zero, L_8002CB8C
    if (ctx->r2 == 0) {
        // 0x8002CB60: nop
    
            goto L_8002CB8C;
    }
    // 0x8002CB60: nop

    // 0x8002CB64: beq         $v0, $at, L_8002CB94
    if (ctx->r2 == ctx->r1) {
        // 0x8002CB68: addiu       $s1, $zero, 0xC
        ctx->r17 = ADD32(0, 0XC);
            goto L_8002CB94;
    }
    // 0x8002CB68: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x8002CB6C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002CB70: beq         $v0, $at, L_8002CB9C
    if (ctx->r2 == ctx->r1) {
        // 0x8002CB74: addiu       $s1, $zero, 0xA
        ctx->r17 = ADD32(0, 0XA);
            goto L_8002CB9C;
    }
    // 0x8002CB74: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x8002CB78: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002CB7C: beq         $v0, $at, L_8002CBA4
    if (ctx->r2 == ctx->r1) {
        // 0x8002CB80: addiu       $s1, $zero, 0xB
        ctx->r17 = ADD32(0, 0XB);
            goto L_8002CBA4;
    }
    // 0x8002CB80: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
    // 0x8002CB84: b           L_8002CBA8
    // 0x8002CB88: nop

        goto L_8002CBA8;
    // 0x8002CB88: nop

L_8002CB8C:
    // 0x8002CB8C: b           L_8002CBA8
    // 0x8002CB90: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBA8;
    // 0x8002CB90: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CB94:
    // 0x8002CB94: b           L_8002CBA8
    // 0x8002CB98: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBA8;
    // 0x8002CB98: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CB9C:
    // 0x8002CB9C: b           L_8002CBA8
    // 0x8002CBA0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBA8;
    // 0x8002CBA0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CBA4:
    // 0x8002CBA4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CBA8:
    // 0x8002CBA8: b           L_8002CBD4
    // 0x8002CBAC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
        goto L_8002CBD4;
    // 0x8002CBAC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
L_8002CBB0:
    // 0x8002CBB0: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x8002CBB4: b           L_8002CBD0
    // 0x8002CBB8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CBB8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CBBC:
    // 0x8002CBBC: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x8002CBC0: b           L_8002CBD0
    // 0x8002CBC4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
        goto L_8002CBD0;
    // 0x8002CBC4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CBC8:
    // 0x8002CBC8: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x8002CBCC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CBD0:
    // 0x8002CBD0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
L_8002CBD4:
    // 0x8002CBD4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002CBD8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8002CBDC: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8002CBE0: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8002CBE4: lw          $a2, -0x5400($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5400);
    // 0x8002CBE8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002CBEC: jal         0x80030EA0
    // 0x8002CBF0: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_80030EA0(rdram, ctx);
        goto after_12;
    // 0x8002CBF0: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_12:
    // 0x8002CBF4: jal         0x8002DF6C
    // 0x8002CBF8: nop

    func_8002DF6C(rdram, ctx);
        goto after_13;
    // 0x8002CBF8: nop

    after_13:
    // 0x8002CBFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002CC04: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    // 0x8002CC08: lhu         $s0, 0x38($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X38);
    // 0x8002CC0C: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002CC10: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002CC14: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x8002CC18: bnel        $at, $zero, L_8002CC34
    if (ctx->r1 != 0) {
        // 0x8002CC1C: or          $a3, $s1, $zero
        ctx->r7 = ctx->r17 | 0;
            goto L_8002CC34;
    }
    goto skip_0;
    // 0x8002CC1C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    skip_0:
L_8002CC20:
    // 0x8002CC20: addiu       $s0, $s0, -0x3C
    ctx->r16 = ADD32(ctx->r16, -0X3C);
    // 0x8002CC24: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x8002CC28: beq         $at, $zero, L_8002CC20
    if (ctx->r1 == 0) {
        // 0x8002CC2C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002CC20;
    }
    // 0x8002CC2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CC30: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
L_8002CC34:
    // 0x8002CC34: jal         0x8002AB64
    // 0x8002CC38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8002AB64(rdram, ctx);
        goto after_14;
    // 0x8002CC38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_14:
    // 0x8002CC3C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002CC40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CC44: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x8002CC48: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002CC4C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002CC50: jal         0x8002AF70
    // 0x8002CC54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8002AF70(rdram, ctx);
        goto after_15;
    // 0x8002CC54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_15:
    // 0x8002CC58: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC5C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8002CC60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002CC64: lhu         $a3, 0x3A($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X3A);
    // 0x8002CC68: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8002CC6C: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x8002CC70: jal         0x8002AB64
    // 0x8002CC74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8002AB64(rdram, ctx);
        goto after_16;
    // 0x8002CC74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_16:
    // 0x8002CC78: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC7C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002CC80: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8002CC84: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8002CC88: jal         0x8002B364
    // 0x8002CC8C: lhu         $a3, 0x4($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X4);
    func_8002B364(rdram, ctx);
        goto after_17;
    // 0x8002CC8C: lhu         $a3, 0x4($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X4);
    after_17:
    // 0x8002CC90: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002CC98: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8002CC9C: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8002CCA0: jal         0x8002B364
    // 0x8002CCA4: lhu         $a3, 0x8($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X8);
    func_8002B364(rdram, ctx);
        goto after_18;
    // 0x8002CCA4: lhu         $a3, 0x8($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X8);
    after_18:
    // 0x8002CCA8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
L_8002CCAC:
    // 0x8002CCAC: b           L_8002CCC0
    // 0x8002CCB0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
        goto L_8002CCC0;
    // 0x8002CCB0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
L_8002CCB4:
    // 0x8002CCB4: jal         0x80030EA0
    // 0x8002CCB8: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    func_80030EA0(rdram, ctx);
        goto after_19;
    // 0x8002CCB8: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    after_19:
    // 0x8002CCBC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
L_8002CCC0:
    // 0x8002CCC0: jal         0x8002DF6C
    // 0x8002CCC4: nop

    func_8002DF6C(rdram, ctx);
        goto after_20;
    // 0x8002CCC4: nop

    after_20:
    // 0x8002CCC8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002CCCC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CCD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002CCD4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8002CCD8: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x8002CCDC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002CCE0: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002CCE4: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8002CCE8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002CCEC: beq         $v0, $at, L_8002D0BC
    if (ctx->r2 == ctx->r1) {
        // 0x8002CCF0: nop
    
            goto L_8002D0BC;
    }
    // 0x8002CCF0: nop

    // 0x8002CCF4: bne         $t4, $zero, L_8002D0BC
    if (ctx->r12 != 0) {
        // 0x8002CCF8: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8002D0BC;
    }
    // 0x8002CCF8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002CCFC: beq         $v0, $at, L_8002D0B0
    if (ctx->r2 == ctx->r1) {
        // 0x8002CD00: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8002D0B0;
    }
    // 0x8002CD00: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8002CD04: lb          $t0, 0x1($t7)
    ctx->r8 = MEM_B(ctx->r15, 0X1);
    // 0x8002CD08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002CD0C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8002CD10: beq         $t0, $at, L_8002D0BC
    if (ctx->r8 == ctx->r1) {
        // 0x8002CD14: subu        $t1, $t1, $t6
        ctx->r9 = SUB32(ctx->r9, ctx->r14);
            goto L_8002D0BC;
    }
    // 0x8002CD14: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8002CD18: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002CD1C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002CD20: lb          $t5, -0x2D6($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2D6);
    // 0x8002CD24: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8002CD28: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002CD2C: addiu       $t2, $t2, -0x2A8
    ctx->r10 = ADD32(ctx->r10, -0X2A8);
    // 0x8002CD30: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002CD34: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8002CD38: bne         $t6, $t5, L_8002CDBC
    if (ctx->r14 != ctx->r13) {
        // 0x8002CD3C: sw          $t3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r11;
            goto L_8002CDBC;
    }
    // 0x8002CD3C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8002CD40: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002CD44: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002CD48: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CD4C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x8002CD50: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002CD54: jal         0x8002AB64
    // 0x8002CD58: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    func_8002AB64(rdram, ctx);
        goto after_21;
    // 0x8002CD58: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    after_21:
    // 0x8002CD5C: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8002CD60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002CD64: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8002CD68: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8002CD6C: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8002CD70: jal         0x80029B58
    // 0x8002CD74: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_22;
    // 0x8002CD74: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_22:
    // 0x8002CD78: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002CD7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002CD80: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8002CD84: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8002CD88: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002CD8C: jal         0x80029B58
    // 0x8002CD90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_23;
    // 0x8002CD90: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_23:
    // 0x8002CD94: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8002CD98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002CD9C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8002CDA0: addiu       $a1, $zero, 0xD9
    ctx->r5 = ADD32(0, 0XD9);
    // 0x8002CDA4: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8002CDA8: jal         0x80029B58
    // 0x8002CDAC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_24;
    // 0x8002CDAC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_24:
    // 0x8002CDB0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CDB4: b           L_8002CE34
    // 0x8002CDB8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
        goto L_8002CE34;
    // 0x8002CDB8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_8002CDBC:
    // 0x8002CDBC: addiu       $t1, $zero, 0x48
    ctx->r9 = ADD32(0, 0X48);
    // 0x8002CDC0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002CDC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CDC8: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x8002CDCC: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002CDD0: jal         0x8002AB64
    // 0x8002CDD4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_8002AB64(rdram, ctx);
        goto after_25;
    // 0x8002CDD4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_25:
    // 0x8002CDD8: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x8002CDDC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002CDE0: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x8002CDE4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8002CDE8: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8002CDEC: jal         0x80029B58
    // 0x8002CDF0: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_26;
    // 0x8002CDF0: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_26:
    // 0x8002CDF4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002CDF8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CDFC: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8002CE00: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8002CE04: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002CE08: jal         0x80029B58
    // 0x8002CE0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_27;
    // 0x8002CE0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_27:
    // 0x8002CE10: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x8002CE14: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002CE18: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8002CE1C: addiu       $a1, $zero, 0xD9
    ctx->r5 = ADD32(0, 0XD9);
    // 0x8002CE20: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8002CE24: jal         0x80029B58
    // 0x8002CE28: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_28;
    // 0x8002CE28: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_28:
    // 0x8002CE2C: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x8002CE30: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_8002CE34:
    // 0x8002CE34: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002CE38: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002CE3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CE40: lbu         $a3, 0x24($t9)
    ctx->r7 = MEM_BU(ctx->r25, 0X24);
    // 0x8002CE44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002CE48: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x8002CE4C: jal         0x8002AB64
    // 0x8002CE50: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    func_8002AB64(rdram, ctx);
        goto after_29;
    // 0x8002CE50: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    after_29:
    // 0x8002CE54: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8002CE58: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002CE5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CE60: lbu         $a3, 0x25($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X25);
    // 0x8002CE64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002CE68: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8002CE6C: jal         0x8002AB64
    // 0x8002CE70: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    func_8002AB64(rdram, ctx);
        goto after_30;
    // 0x8002CE70: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    after_30:
    // 0x8002CE74: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002CE78: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8002CE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CE80: lbu         $a3, 0x26($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X26);
    // 0x8002CE84: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002CE88: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8002CE8C: jal         0x8002AB64
    // 0x8002CE90: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    func_8002AB64(rdram, ctx);
        goto after_31;
    // 0x8002CE90: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    after_31:
    // 0x8002CE94: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8002CE98: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002CE9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002CEA0: lbu         $a3, 0x27($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X27);
    // 0x8002CEA4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CEA8: addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    // 0x8002CEAC: jal         0x8002AB64
    // 0x8002CEB0: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    func_8002AB64(rdram, ctx);
        goto after_32;
    // 0x8002CEB0: addiu       $a2, $zero, 0xBA
    ctx->r6 = ADD32(0, 0XBA);
    after_32:
    // 0x8002CEB4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8002CEB8: lw          $t5, 0x3C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X3C);
    // 0x8002CEBC: addiu       $t6, $t5, -0xF
    ctx->r14 = ADD32(ctx->r13, -0XF);
    // 0x8002CEC0: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x8002CEC4: beq         $at, $zero, L_8002CFD4
    if (ctx->r1 == 0) {
        // 0x8002CEC8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8002CFD4;
    }
    // 0x8002CEC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002CECC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002CED0: addu        $at, $at, $t6
    gpr jr_addend_8002CED8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002CED4: lw          $t6, 0x198C($at)
    ctx->r14 = ADD32(ctx->r1, 0X198C);
    // 0x8002CED8: jr          $t6
    // 0x8002CEDC: nop

    switch (jr_addend_8002CED8 >> 2) {
        case 0: goto L_8002CEE0; break;
        case 1: goto L_8002CF00; break;
        case 2: goto L_8002CF20; break;
        case 3: goto L_8002CF28; break;
        case 4: goto L_8002CFD4; break;
        case 5: goto L_8002CF48; break;
        case 6: goto L_8002CFD4; break;
        case 7: goto L_8002CF50; break;
        case 8: goto L_8002CF70; break;
        case 9: goto L_8002CFD4; break;
        case 10: goto L_8002CFC0; break;
        case 11: goto L_8002CFC8; break;
        case 12: goto L_8002CFD4; break;
        case 13: goto L_8002CFD4; break;
        case 14: goto L_8002CFD4; break;
        case 15: goto L_8002CFD0; break;
        default: switch_error(__func__, 0x8002CED8, 0x8007198C);
    }
    // 0x8002CEDC: nop

L_8002CEE0:
    // 0x8002CEE0: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x8002CEE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002CEE8: bne         $t9, $at, L_8002CEF8
    if (ctx->r25 != ctx->r1) {
        // 0x8002CEEC: nop
    
            goto L_8002CEF8;
    }
    // 0x8002CEEC: nop

    // 0x8002CEF0: b           L_8002CFD4
    // 0x8002CEF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8002CFD4;
    // 0x8002CEF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8002CEF8:
    // 0x8002CEF8: b           L_8002CFD4
    // 0x8002CEFC: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
        goto L_8002CFD4;
    // 0x8002CEFC: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_8002CF00:
    // 0x8002CF00: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x8002CF04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8002CF08: bne         $t8, $at, L_8002CF18
    if (ctx->r24 != ctx->r1) {
        // 0x8002CF0C: nop
    
            goto L_8002CF18;
    }
    // 0x8002CF0C: nop

    // 0x8002CF10: b           L_8002CFD4
    // 0x8002CF14: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002CFD4;
    // 0x8002CF14: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002CF18:
    // 0x8002CF18: b           L_8002CFD4
    // 0x8002CF1C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8002CFD4;
    // 0x8002CF1C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8002CF20:
    // 0x8002CF20: b           L_8002CFD4
    // 0x8002CF24: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
        goto L_8002CFD4;
    // 0x8002CF24: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8002CF28:
    // 0x8002CF28: lw          $t4, 0x40($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X40);
    // 0x8002CF2C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002CF30: bne         $t4, $at, L_8002CF40
    if (ctx->r12 != ctx->r1) {
        // 0x8002CF34: nop
    
            goto L_8002CF40;
    }
    // 0x8002CF34: nop

    // 0x8002CF38: b           L_8002CFD4
    // 0x8002CF3C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_8002CFD4;
    // 0x8002CF3C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_8002CF40:
    // 0x8002CF40: b           L_8002CFD4
    // 0x8002CF44: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
        goto L_8002CFD4;
    // 0x8002CF44: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_8002CF48:
    // 0x8002CF48: b           L_8002CFD4
    // 0x8002CF4C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_8002CFD4;
    // 0x8002CF4C: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8002CF50:
    // 0x8002CF50: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8002CF54: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002CF58: bne         $t7, $at, L_8002CF68
    if (ctx->r15 != ctx->r1) {
        // 0x8002CF5C: nop
    
            goto L_8002CF68;
    }
    // 0x8002CF5C: nop

    // 0x8002CF60: b           L_8002CFD4
    // 0x8002CF64: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
        goto L_8002CFD4;
    // 0x8002CF64: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_8002CF68:
    // 0x8002CF68: b           L_8002CFD4
    // 0x8002CF6C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
        goto L_8002CFD4;
    // 0x8002CF6C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_8002CF70:
    // 0x8002CF70: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x8002CF74: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002CF78: beq         $v0, $zero, L_8002CFA0
    if (ctx->r2 == 0) {
        // 0x8002CF7C: nop
    
            goto L_8002CFA0;
    }
    // 0x8002CF7C: nop

    // 0x8002CF80: beq         $v0, $at, L_8002CFA8
    if (ctx->r2 == ctx->r1) {
        // 0x8002CF84: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8002CFA8;
    }
    // 0x8002CF84: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8002CF88: beq         $v0, $at, L_8002CFB0
    if (ctx->r2 == ctx->r1) {
        // 0x8002CF8C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8002CFB0;
    }
    // 0x8002CF8C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002CF90: beq         $v0, $at, L_8002CFB8
    if (ctx->r2 == ctx->r1) {
        // 0x8002CF94: nop
    
            goto L_8002CFB8;
    }
    // 0x8002CF94: nop

    // 0x8002CF98: b           L_8002CFD8
    // 0x8002CF9C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
        goto L_8002CFD8;
    // 0x8002CF9C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
L_8002CFA0:
    // 0x8002CFA0: b           L_8002CFD4
    // 0x8002CFA4: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
        goto L_8002CFD4;
    // 0x8002CFA4: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_8002CFA8:
    // 0x8002CFA8: b           L_8002CFD4
    // 0x8002CFAC: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
        goto L_8002CFD4;
    // 0x8002CFAC: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_8002CFB0:
    // 0x8002CFB0: b           L_8002CFD4
    // 0x8002CFB4: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
        goto L_8002CFD4;
    // 0x8002CFB4: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_8002CFB8:
    // 0x8002CFB8: b           L_8002CFD4
    // 0x8002CFBC: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
        goto L_8002CFD4;
    // 0x8002CFBC: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_8002CFC0:
    // 0x8002CFC0: b           L_8002CFD4
    // 0x8002CFC4: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
        goto L_8002CFD4;
    // 0x8002CFC4: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
L_8002CFC8:
    // 0x8002CFC8: b           L_8002CFD4
    // 0x8002CFCC: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
        goto L_8002CFD4;
    // 0x8002CFCC: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
L_8002CFD0:
    // 0x8002CFD0: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
L_8002CFD4:
    // 0x8002CFD4: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
L_8002CFD8:
    // 0x8002CFD8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002CFDC: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8002CFE0: lw          $a2, -0x5400($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5400);
    // 0x8002CFE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002CFE8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8002CFEC: jal         0x80030EA0
    // 0x8002CFF0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_80030EA0(rdram, ctx);
        goto after_33;
    // 0x8002CFF0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_33:
    // 0x8002CFF4: jal         0x8002DF6C
    // 0x8002CFF8: nop

    func_8002DF6C(rdram, ctx);
        goto after_34;
    // 0x8002CFF8: nop

    after_34:
    // 0x8002CFFC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002D000: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002D004: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    // 0x8002D008: lhu         $s0, 0x38($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X38);
    // 0x8002D00C: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002D010: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002D014: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x8002D018: bnel        $at, $zero, L_8002D034
    if (ctx->r1 != 0) {
        // 0x8002D01C: or          $a3, $s1, $zero
        ctx->r7 = ctx->r17 | 0;
            goto L_8002D034;
    }
    goto skip_1;
    // 0x8002D01C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    skip_1:
L_8002D020:
    // 0x8002D020: addiu       $s0, $s0, -0x3C
    ctx->r16 = ADD32(ctx->r16, -0X3C);
    // 0x8002D024: slti        $at, $s0, 0x3C
    ctx->r1 = SIGNED(ctx->r16) < 0X3C ? 1 : 0;
    // 0x8002D028: beq         $at, $zero, L_8002D020
    if (ctx->r1 == 0) {
        // 0x8002D02C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8002D020;
    }
    // 0x8002D02C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002D030: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
L_8002D034:
    // 0x8002D034: jal         0x8002AB64
    // 0x8002D038: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8002AB64(rdram, ctx);
        goto after_35;
    // 0x8002D038: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_35:
    // 0x8002D03C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002D040: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002D044: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x8002D048: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002D04C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002D050: jal         0x8002AF70
    // 0x8002D054: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8002AF70(rdram, ctx);
        goto after_36;
    // 0x8002D054: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_36:
    // 0x8002D058: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8002D05C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8002D060: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002D064: lhu         $a3, 0x3A($t5)
    ctx->r7 = MEM_HU(ctx->r13, 0X3A);
    // 0x8002D068: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8002D06C: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x8002D070: jal         0x8002AB64
    // 0x8002D074: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8002AB64(rdram, ctx);
        goto after_37;
    // 0x8002D074: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_37:
    // 0x8002D078: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002D07C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002D080: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8002D084: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x8002D088: jal         0x8002B364
    // 0x8002D08C: lhu         $a3, 0x4($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X4);
    func_8002B364(rdram, ctx);
        goto after_38;
    // 0x8002D08C: lhu         $a3, 0x4($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X4);
    after_38:
    // 0x8002D090: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002D094: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002D098: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8002D09C: addiu       $a2, $zero, 0xA6
    ctx->r6 = ADD32(0, 0XA6);
    // 0x8002D0A0: jal         0x8002B364
    // 0x8002D0A4: lhu         $a3, 0x8($t8)
    ctx->r7 = MEM_HU(ctx->r24, 0X8);
    func_8002B364(rdram, ctx);
        goto after_39;
    // 0x8002D0A4: lhu         $a3, 0x8($t8)
    ctx->r7 = MEM_HU(ctx->r24, 0X8);
    after_39:
    // 0x8002D0A8: b           L_8002D0BC
    // 0x8002D0AC: nop

        goto L_8002D0BC;
    // 0x8002D0AC: nop

L_8002D0B0:
    // 0x8002D0B0: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8002D0B4: jal         0x80030EA0
    // 0x8002D0B8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80030EA0(rdram, ctx);
        goto after_40;
    // 0x8002D0B8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_40:
L_8002D0BC:
    // 0x8002D0BC: jal         0x8002DF6C
    // 0x8002D0C0: nop

    func_8002DF6C(rdram, ctx);
        goto after_41;
    // 0x8002D0C0: nop

    after_41:
    // 0x8002D0C4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002D0C8: lw          $v1, -0x2F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2F0);
    // 0x8002D0CC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D0D0: lb          $v0, -0x2D6($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2D6);
    // 0x8002D0D4: sra         $t4, $v1, 2
    ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8002D0D8: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x8002D0DC: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002D0E0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8002D0E4: lb          $v1, -0xF40($at)
    ctx->r3 = MEM_B(ctx->r1, -0XF40);
    // 0x8002D0E8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002D0EC: bne         $at, $zero, L_8002D138
    if (ctx->r1 != 0) {
        // 0x8002D0F0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_8002D138;
    }
    // 0x8002D0F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002D0F4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8002D0F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002D0FC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8002D100: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x8002D104: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8002D108: jal         0x80029B58
    // 0x8002D10C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_80029B58(rdram, ctx);
        goto after_42;
    // 0x8002D10C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_42:
    // 0x8002D110: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8002D114: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8002D118: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002D11C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x8002D120: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8002D124: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8002D128: jal         0x80029B58
    // 0x8002D12C: addiu       $a2, $a2, 0x3F
    ctx->r6 = ADD32(ctx->r6, 0X3F);
    func_80029B58(rdram, ctx);
        goto after_43;
    // 0x8002D12C: addiu       $a2, $a2, 0x3F
    ctx->r6 = ADD32(ctx->r6, 0X3F);
    after_43:
    // 0x8002D130: b           L_8002D19C
    // 0x8002D134: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
        goto L_8002D19C;
    // 0x8002D134: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_8002D138:
    // 0x8002D138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D13C: bne         $v0, $at, L_8002D198
    if (ctx->r2 != ctx->r1) {
        // 0x8002D140: sw          $v1, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r3;
            goto L_8002D198;
    }
    // 0x8002D140: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8002D144: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002D148: lhu         $t2, -0x2E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2E0);
    // 0x8002D14C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8002D150: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002D154: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x8002D158: bne         $t3, $zero, L_8002D198
    if (ctx->r11 != 0) {
        // 0x8002D15C: addiu       $a1, $zero, 0x38
        ctx->r5 = ADD32(0, 0X38);
            goto L_8002D198;
    }
    // 0x8002D15C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8002D160: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8002D164: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002D168: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    // 0x8002D16C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8002D170: jal         0x80029B58
    // 0x8002D174: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_80029B58(rdram, ctx);
        goto after_44;
    // 0x8002D174: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_44:
    // 0x8002D178: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8002D17C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002D180: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002D184: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x8002D188: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8002D18C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8002D190: jal         0x80029B58
    // 0x8002D194: addiu       $a2, $a2, 0x3F
    ctx->r6 = ADD32(ctx->r6, 0X3F);
    func_80029B58(rdram, ctx);
        goto after_45;
    // 0x8002D194: addiu       $a2, $a2, 0x3F
    ctx->r6 = ADD32(ctx->r6, 0X3F);
    after_45:
L_8002D198:
    // 0x8002D198: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_8002D19C:
    // 0x8002D19C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002D1A0: addiu       $t8, $t8, -0x2B0
    ctx->r24 = ADD32(ctx->r24, -0X2B0);
    // 0x8002D1A4: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8002D1A8: beq         $at, $zero, L_8002D204
    if (ctx->r1 == 0) {
        // 0x8002D1AC: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_8002D204;
    }
    // 0x8002D1AC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8002D1B0: lb          $t4, 0x2($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X2);
    // 0x8002D1B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D1B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002D1BC: beq         $t4, $at, L_8002D204
    if (ctx->r12 == ctx->r1) {
        // 0x8002D1C0: addiu       $a1, $zero, 0x38
        ctx->r5 = ADD32(0, 0X38);
            goto L_8002D204;
    }
    // 0x8002D1C0: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8002D1C4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8002D1C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002D1CC: addiu       $a2, $zero, 0xA4
    ctx->r6 = ADD32(0, 0XA4);
    // 0x8002D1D0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8002D1D4: jal         0x80029B58
    // 0x8002D1D8: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_80029B58(rdram, ctx);
        goto after_46;
    // 0x8002D1D8: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_46:
    // 0x8002D1DC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002D1E0: addiu       $t1, $zero, 0xAC
    ctx->r9 = ADD32(0, 0XAC);
    // 0x8002D1E4: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x8002D1E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002D1EC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x8002D1F0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8002D1F4: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x8002D1F8: jal         0x80029B58
    // 0x8002D1FC: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    func_80029B58(rdram, ctx);
        goto after_47;
    // 0x8002D1FC: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    after_47:
    // 0x8002D200: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_8002D204:
    // 0x8002D204: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002D208: lhu         $t3, -0x2E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2E0);
    // 0x8002D20C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002D210: addiu       $a1, $v1, 0x42
    ctx->r5 = ADD32(ctx->r3, 0X42);
    // 0x8002D214: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x8002D218: beq         $t5, $zero, L_8002D244
    if (ctx->r13 == 0) {
        // 0x8002D21C: addiu       $a2, $zero, 0x37
        ctx->r6 = ADD32(0, 0X37);
            goto L_8002D244;
    }
    // 0x8002D21C: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
    // 0x8002D220: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8002D224: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002D228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002D22C: addiu       $a1, $v1, 0x42
    ctx->r5 = ADD32(ctx->r3, 0X42);
    // 0x8002D230: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8002D234: jal         0x80029B58
    // 0x8002D238: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80029B58(rdram, ctx);
        goto after_48;
    // 0x8002D238: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_48:
    // 0x8002D23C: b           L_8002D258
    // 0x8002D240: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_8002D258;
    // 0x8002D240: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_8002D244:
    // 0x8002D244: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8002D248: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002D24C: jal         0x80029B58
    // 0x8002D250: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80029B58(rdram, ctx);
        goto after_49;
    // 0x8002D250: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_49:
    // 0x8002D254: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_8002D258:
    // 0x8002D258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D25C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D260: beql        $t9, $at, L_8002D5C4
    if (ctx->r25 == ctx->r1) {
        // 0x8002D264: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002D5C4;
    }
    goto skip_2;
    // 0x8002D264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8002D268: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x8002D26C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002D270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002D274: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x8002D278: beq         $at, $zero, L_8002D34C
    if (ctx->r1 == 0) {
        // 0x8002D27C: addiu       $s0, $s0, -0x2D5
        ctx->r16 = ADD32(ctx->r16, -0X2D5);
            goto L_8002D34C;
    }
    // 0x8002D27C: addiu       $s0, $s0, -0x2D5
    ctx->r16 = ADD32(ctx->r16, -0X2D5);
    // 0x8002D280: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8002D284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D28C: bnel        $t4, $zero, L_8002D32C
    if (ctx->r12 != 0) {
        // 0x8002D290: lbu         $t0, 0x0($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X0);
            goto L_8002D32C;
    }
    goto skip_3;
    // 0x8002D290: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    skip_3:
    // 0x8002D294: jal         0x800268D4
    // 0x8002D298: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_50;
    // 0x8002D298: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_50:
    // 0x8002D29C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002D2A0: lb          $t7, -0x2D6($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2D6);
    // 0x8002D2A4: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002D2A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D2AC: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x8002D2B0: sll         $v0, $t1, 24
    ctx->r2 = S32(ctx->r9 << 24);
    // 0x8002D2B4: sra         $t0, $v0, 24
    ctx->r8 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002D2B8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8002D2BC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8002D2C0: lb          $t3, -0x2D0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2D0);
    // 0x8002D2C4: sb          $t1, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = ctx->r9;
    // 0x8002D2C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D2CC: bne         $t3, $at, L_8002D2E4
    if (ctx->r11 != ctx->r1) {
        // 0x8002D2D0: lui         $a3, 0x8009
        ctx->r7 = S32(0X8009 << 16);
            goto L_8002D2E4;
    }
    // 0x8002D2D0: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002D2D4: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x8002D2D8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D2DC: sb          $t5, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = ctx->r13;
    // 0x8002D2E0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002D2E4:
    // 0x8002D2E4: addiu       $a3, $a3, -0x2E0
    ctx->r7 = ADD32(ctx->r7, -0X2E0);
    // 0x8002D2E8: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8002D2EC: andi        $t6, $v1, 0x20
    ctx->r14 = ctx->r3 & 0X20;
    // 0x8002D2F0: bne         $t6, $zero, L_8002D308
    if (ctx->r14 != 0) {
        // 0x8002D2F4: nop
    
            goto L_8002D308;
    }
    // 0x8002D2F4: nop

    // 0x8002D2F8: bne         $s1, $zero, L_8002D308
    if (ctx->r17 != 0) {
        // 0x8002D2FC: ori         $t8, $v1, 0x20
        ctx->r24 = ctx->r3 | 0X20;
            goto L_8002D308;
    }
    // 0x8002D2FC: ori         $t8, $v1, 0x20
    ctx->r24 = ctx->r3 | 0X20;
    // 0x8002D300: b           L_8002D328
    // 0x8002D304: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_8002D328;
    // 0x8002D304: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_8002D308:
    // 0x8002D308: bne         $s1, $zero, L_8002D328
    if (ctx->r17 != 0) {
        // 0x8002D30C: andi        $t4, $v1, 0xFFF8
        ctx->r12 = ctx->r3 & 0XFFF8;
            goto L_8002D328;
    }
    // 0x8002D30C: andi        $t4, $v1, 0xFFF8
    ctx->r12 = ctx->r3 & 0XFFF8;
    // 0x8002D310: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x8002D314: ori         $t7, $t4, 0x6
    ctx->r15 = ctx->r12 | 0X6;
    // 0x8002D318: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8002D31C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8002D320: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D324: sb          $t1, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r9;
L_8002D328:
    // 0x8002D328: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
L_8002D32C:
    // 0x8002D32C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002D330: addiu       $a3, $a3, -0x2E0
    ctx->r7 = ADD32(ctx->r7, -0X2E0);
    // 0x8002D334: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x8002D338: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8002D33C: andi        $t5, $t3, 0xF
    ctx->r13 = ctx->r11 & 0XF;
    // 0x8002D340: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8002D344: b           L_8002D42C
    // 0x8002D348: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
        goto L_8002D42C;
    // 0x8002D348: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8002D34C:
    // 0x8002D34C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8002D350: bne         $at, $zero, L_8002D414
    if (ctx->r1 != 0) {
        // 0x8002D354: lui         $s0, 0x8009
        ctx->r16 = S32(0X8009 << 16);
            goto L_8002D414;
    }
    // 0x8002D354: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002D358: addiu       $s0, $s0, -0x2D5
    ctx->r16 = ADD32(ctx->r16, -0X2D5);
    // 0x8002D35C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8002D360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D368: bnel        $t6, $zero, L_8002D3F4
    if (ctx->r14 != 0) {
        // 0x8002D36C: lbu         $t8, 0x0($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X0);
            goto L_8002D3F4;
    }
    goto skip_4;
    // 0x8002D36C: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    skip_4:
    // 0x8002D370: jal         0x800268D4
    // 0x8002D374: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_51;
    // 0x8002D374: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_51:
    // 0x8002D378: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002D37C: lb          $t8, -0x2D6($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2D6);
    // 0x8002D380: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D384: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002D388: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002D38C: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x8002D390: sra         $t7, $t4, 24
    ctx->r15 = S32(SIGNED(ctx->r12) >> 24);
    // 0x8002D394: bgez        $t7, L_8002D3A8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002D398: sb          $t9, -0x2D6($at)
        MEM_B(-0X2D6, ctx->r1) = ctx->r25;
            goto L_8002D3A8;
    }
    // 0x8002D398: sb          $t9, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = ctx->r25;
    // 0x8002D39C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D3A0: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002D3A4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002D3A8:
    // 0x8002D3A8: lhu         $v1, -0x2E0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2E0);
    // 0x8002D3AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D3B0: andi        $t1, $v1, 0x20
    ctx->r9 = ctx->r3 & 0X20;
    // 0x8002D3B4: beq         $t1, $zero, L_8002D3C4
    if (ctx->r9 == 0) {
        // 0x8002D3B8: andi        $t0, $v1, 0xFFDF
        ctx->r8 = ctx->r3 & 0XFFDF;
            goto L_8002D3C4;
    }
    // 0x8002D3B8: andi        $t0, $v1, 0xFFDF
    ctx->r8 = ctx->r3 & 0XFFDF;
    // 0x8002D3BC: b           L_8002D3F0
    // 0x8002D3C0: sh          $t0, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r8;
        goto L_8002D3F0;
    // 0x8002D3C0: sh          $t0, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r8;
L_8002D3C4:
    // 0x8002D3C4: bne         $s1, $zero, L_8002D3F0
    if (ctx->r17 != 0) {
        // 0x8002D3C8: andi        $t2, $v1, 0xFFF8
        ctx->r10 = ctx->r3 & 0XFFF8;
            goto L_8002D3F0;
    }
    // 0x8002D3C8: andi        $t2, $v1, 0xFFF8
    ctx->r10 = ctx->r3 & 0XFFF8;
    // 0x8002D3CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D3D0: sh          $t2, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r10;
    // 0x8002D3D4: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002D3D8: lhu         $t3, -0x2E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2E0);
    // 0x8002D3DC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002D3E0: ori         $t5, $t3, 0x6
    ctx->r13 = ctx->r11 | 0X6;
    // 0x8002D3E4: sh          $t5, -0x2E0($at)
    MEM_H(-0X2E0, ctx->r1) = ctx->r13;
    // 0x8002D3E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D3EC: sb          $t6, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r14;
L_8002D3F0:
    // 0x8002D3F0: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
L_8002D3F4:
    // 0x8002D3F4: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002D3F8: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
    // 0x8002D3FC: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8002D400: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x8002D404: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x8002D408: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8002D40C: b           L_8002D42C
    // 0x8002D410: addiu       $a3, $a3, -0x2E0
    ctx->r7 = ADD32(ctx->r7, -0X2E0);
        goto L_8002D42C;
    // 0x8002D410: addiu       $a3, $a3, -0x2E0
    ctx->r7 = ADD32(ctx->r7, -0X2E0);
L_8002D414:
    // 0x8002D414: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002D418: addiu       $s0, $s0, -0x2D5
    ctx->r16 = ADD32(ctx->r16, -0X2D5);
    // 0x8002D41C: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002D420: addiu       $a3, $a3, -0x2E0
    ctx->r7 = ADD32(ctx->r7, -0X2E0);
    // 0x8002D424: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8002D428: addiu       $s1, $zero, -0x8
    ctx->r17 = ADD32(0, -0X8);
L_8002D42C:
    // 0x8002D42C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D430: lhu         $v0, 0x2876($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2876);
    // 0x8002D434: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x8002D438: beq         $t1, $zero, L_8002D57C
    if (ctx->r9 == 0) {
        // 0x8002D43C: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_8002D57C;
    }
    // 0x8002D43C: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D440: lhu         $t0, -0x2F4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2F4);
    // 0x8002D444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002D44C: andi        $t2, $t0, 0xC
    ctx->r10 = ctx->r8 & 0XC;
    // 0x8002D450: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8002D454: jal         0x800268D4
    // 0x8002D458: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_52;
    // 0x8002D458: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_52:
    // 0x8002D45C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8002D460: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D464: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D468: beq         $t3, $zero, L_8002D488
    if (ctx->r11 == 0) {
        // 0x8002D46C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8002D488;
    }
    // 0x8002D46C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D470: beq         $t3, $at, L_8002D4EC
    if (ctx->r11 == ctx->r1) {
        // 0x8002D474: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8002D4EC;
    }
    // 0x8002D474: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002D478: beq         $t3, $at, L_8002D4B8
    if (ctx->r11 == ctx->r1) {
        // 0x8002D47C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002D4B8;
    }
    // 0x8002D47C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D480: b           L_8002D5C4
    // 0x8002D484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8002D5C4;
    // 0x8002D484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002D488:
    // 0x8002D488: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D48C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002D490: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D494: ori         $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 | 0X2000;
    // 0x8002D498: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002D49C: sb          $t8, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r24;
    // 0x8002D4A0: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D4A4: and         $t7, $t9, $s1
    ctx->r15 = ctx->r25 & ctx->r17;
    // 0x8002D4A8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8002D4AC: ori         $t1, $t7, 0x2
    ctx->r9 = ctx->r15 | 0X2;
    // 0x8002D4B0: b           L_8002D5C0
    // 0x8002D4B4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
        goto L_8002D5C0;
    // 0x8002D4B4: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_8002D4B8:
    // 0x8002D4B8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8002D4BC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D4C0: sb          $t0, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r8;
    // 0x8002D4C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D4C8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002D4CC: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D4D0: sb          $t2, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r10;
    // 0x8002D4D4: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D4D8: and         $t6, $t3, $s1
    ctx->r14 = ctx->r11 & ctx->r17;
    // 0x8002D4DC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002D4E0: ori         $t8, $t6, 0x5
    ctx->r24 = ctx->r14 | 0X5;
    // 0x8002D4E4: b           L_8002D5C0
    // 0x8002D4E8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
        goto L_8002D5C0;
    // 0x8002D4E8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_8002D4EC:
    // 0x8002D4EC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002D4F0: lb          $t9, -0x2D6($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2D6);
    // 0x8002D4F4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002D4F8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002D4FC: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8002D500: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8002D504: lb          $t7, -0x2D0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2D0);
    // 0x8002D508: bne         $t7, $at, L_8002D544
    if (ctx->r15 != ctx->r1) {
        // 0x8002D50C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002D544;
    }
    // 0x8002D50C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D510: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D514: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D518: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8002D51C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D520: ori         $t0, $t1, 0x2000
    ctx->r8 = ctx->r9 | 0X2000;
    // 0x8002D524: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8002D528: sb          $t2, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r10;
    // 0x8002D52C: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D530: and         $t6, $t3, $s1
    ctx->r14 = ctx->r11 & ctx->r17;
    // 0x8002D534: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002D538: ori         $t8, $t6, 0x3
    ctx->r24 = ctx->r14 | 0X3;
    // 0x8002D53C: b           L_8002D5C0
    // 0x8002D540: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
        goto L_8002D5C0;
    // 0x8002D540: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_8002D544:
    // 0x8002D544: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8002D548: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D54C: sb          $t9, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r25;
    // 0x8002D550: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D554: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D558: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002D55C: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D560: sb          $t4, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r12;
    // 0x8002D564: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D568: and         $t0, $t7, $s1
    ctx->r8 = ctx->r15 & ctx->r17;
    // 0x8002D56C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8002D570: ori         $t2, $t0, 0x5
    ctx->r10 = ctx->r8 | 0X5;
    // 0x8002D574: b           L_8002D5C0
    // 0x8002D578: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
        goto L_8002D5C0;
    // 0x8002D578: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_8002D57C:
    // 0x8002D57C: andi        $t3, $v0, 0x5000
    ctx->r11 = ctx->r2 & 0X5000;
    // 0x8002D580: beq         $t3, $zero, L_8002D5C0
    if (ctx->r11 == 0) {
        // 0x8002D584: addiu       $t5, $zero, 0x7
        ctx->r13 = ADD32(0, 0X7);
            goto L_8002D5C0;
    }
    // 0x8002D584: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8002D588: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D58C: sb          $t5, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r13;
    // 0x8002D590: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D594: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002D598: sb          $t6, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r14;
    // 0x8002D59C: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x8002D5A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002D5A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8002D5A8: and         $t4, $t8, $s1
    ctx->r12 = ctx->r24 & ctx->r17;
    // 0x8002D5AC: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x8002D5B0: ori         $t7, $t4, 0x5
    ctx->r15 = ctx->r12 | 0X5;
    // 0x8002D5B4: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8002D5B8: jal         0x800268D4
    // 0x8002D5BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_53;
    // 0x8002D5BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_53:
L_8002D5C0:
    // 0x8002D5C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002D5C4:
    // 0x8002D5C4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D5C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002D5CC: jr          $ra
    // 0x8002D5D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002D5D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800125F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800125F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800125F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800125FC: lbu         $t6, 0x3C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3C);
    // 0x80012600: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80012604: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80012608: bgez        $t6, L_8001261C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001260C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001261C;
    }
    // 0x8001260C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012614: nop

    // 0x80012618: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001261C:
    // 0x8001261C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012620: ldc1        $f16, 0x12F8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X12F8);
    // 0x80012624: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80012628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001262C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80012630: jal         0x80035680
    // 0x80012634: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80012634: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x80012638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001263C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012640: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80012644: lbu         $t7, 0x3C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3C);
    // 0x80012648: lwc1        $f16, 0x30($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8001264C: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80012650: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80012654: sb          $t8, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r24;
    // 0x80012658: ldc1        $f8, 0x1300($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1300);
    // 0x8001265C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80012660: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80012664: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80012668: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001266C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80012670: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80012674: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80012678: addiu       $t2, $t2, -0x3418
    ctx->r10 = ADD32(ctx->r10, -0X3418);
    // 0x8001267C: addiu       $a2, $a2, -0x4D04
    ctx->r6 = ADD32(ctx->r6, -0X4D04);
    // 0x80012680: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80012684: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80012688: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8001268C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80012690: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80012694: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80012698: lwc1        $f18, 0x38($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001269C: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800126A0: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x800126A4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800126A8: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800126AC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800126B0: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800126B4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800126B8: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800126BC: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x800126C0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800126C4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800126C8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800126CC: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800126D0: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800126D4: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800126D8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800126DC: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800126E0: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x800126E4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800126E8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800126EC: or          $t6, $t4, $t8
    ctx->r14 = ctx->r12 | ctx->r24;
    // 0x800126F0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800126F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800126F8: jr          $ra
    // 0x800126FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800126FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000932C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000932C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80009330: lhu         $t6, -0x3A68($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A68);
    // 0x80009334: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80009338: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000933C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80009340: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80009344: lhu         $t8, -0x2F50($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2F50);
    // 0x80009348: addiu       $t0, $t0, -0x3668
    ctx->r8 = ADD32(ctx->r8, -0X3668);
    // 0x8000934C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80009350: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80009354: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80009358: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000935C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80009360: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80009364: lhu         $t1, 0x8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X8);
    // 0x80009368: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8000936C: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80009370: jr          $ra
    // 0x80009374: nop

    return;
    // 0x80009374: nop

;}
RECOMP_FUNC void func_80006B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B1C: lw          $a3, 0x10($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X10);
    // 0x80006B20: lhu         $v0, 0x104($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X104);
    // 0x80006B24: lbu         $t0, 0x24($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X24);
    // 0x80006B28: sra         $a1, $v0, 2
    ctx->r5 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80006B2C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80006B30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80006B34: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80006B38: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80006B3C: beq         $at, $zero, L_80006B54
    if (ctx->r1 == 0) {
        // 0x80006B40: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80006B54;
    }
    // 0x80006B40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80006B44: subu        $t7, $a2, $t0
    ctx->r15 = SUB32(ctx->r6, ctx->r8);
    // 0x80006B48: addu        $a2, $t7, $t6
    ctx->r6 = ADD32(ctx->r15, ctx->r14);
    // 0x80006B4C: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80006B50: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_80006B54:
    // 0x80006B54: lbu         $a1, 0x25($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X25);
    // 0x80006B58: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80006B5C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80006B60: beq         $at, $zero, L_80006B74
    if (ctx->r1 == 0) {
        // 0x80006B64: subu        $t9, $a2, $a1
        ctx->r25 = SUB32(ctx->r6, ctx->r5);
            goto L_80006B74;
    }
    // 0x80006B64: subu        $t9, $a2, $a1
    ctx->r25 = SUB32(ctx->r6, ctx->r5);
    // 0x80006B68: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80006B6C: andi        $t1, $a2, 0xFFFF
    ctx->r9 = ctx->r6 & 0XFFFF;
    // 0x80006B70: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_80006B74:
    // 0x80006B74: lbu         $a1, 0x26($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X26);
    // 0x80006B78: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80006B7C: beq         $at, $zero, L_80006B90
    if (ctx->r1 == 0) {
        // 0x80006B80: subu        $t2, $a2, $a1
        ctx->r10 = SUB32(ctx->r6, ctx->r5);
            goto L_80006B90;
    }
    // 0x80006B80: subu        $t2, $a2, $a1
    ctx->r10 = SUB32(ctx->r6, ctx->r5);
    // 0x80006B84: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x80006B88: andi        $t3, $a2, 0xFFFF
    ctx->r11 = ctx->r6 & 0XFFFF;
    // 0x80006B8C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_80006B90:
    // 0x80006B90: lbu         $a1, 0x27($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X27);
    // 0x80006B94: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80006B98: beq         $at, $zero, L_80006BAC
    if (ctx->r1 == 0) {
        // 0x80006B9C: subu        $t4, $a2, $a1
        ctx->r12 = SUB32(ctx->r6, ctx->r5);
            goto L_80006BAC;
    }
    // 0x80006B9C: subu        $t4, $a2, $a1
    ctx->r12 = SUB32(ctx->r6, ctx->r5);
    // 0x80006BA0: addu        $a2, $t4, $v0
    ctx->r6 = ADD32(ctx->r12, ctx->r2);
    // 0x80006BA4: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x80006BA8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_80006BAC:
    // 0x80006BAC: lhu         $t8, 0x10A($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X10A);
    // 0x80006BB0: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x80006BB4: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x80006BB8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006BBC: lhu         $t2, 0x80($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X80);
    // 0x80006BC0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80006BC4: mflo        $v1
    ctx->r3 = lo;
    // 0x80006BC8: sra         $t9, $v1, 4
    ctx->r25 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80006BCC: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x80006BD0: beq         $t3, $zero, L_80006BE0
    if (ctx->r11 == 0) {
        // 0x80006BD4: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_80006BE0;
    }
    // 0x80006BD4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80006BD8: srl         $t4, $t1, 1
    ctx->r12 = S32(U32(ctx->r9) >> 1);
    // 0x80006BDC: andi        $v1, $t4, 0xFFFF
    ctx->r3 = ctx->r12 & 0XFFFF;
L_80006BE0:
    // 0x80006BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80006BE4: jr          $ra
    // 0x80006BE8: nop

    return;
    // 0x80006BE8: nop

;}
RECOMP_FUNC void func_80030D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030D80: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80030D84: lbu         $t6, 0x2850($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2850);
    // 0x80030D88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80030D8C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80030D90: beql        $t6, $zero, L_80030E00
    if (ctx->r14 == 0) {
        // 0x80030D94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80030E00;
    }
    goto skip_0;
    // 0x80030D94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80030D98: lb          $a0, 0x2871($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2871);
    // 0x80030D9C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80030DA0: lb          $a1, 0x2872($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X2872);
    // 0x80030DA4: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030DA8: mflo        $t7
    ctx->r15 = lo;
    // 0x80030DAC: nop

    // 0x80030DB0: nop

    // 0x80030DB4: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030DB8: mflo        $t8
    ctx->r24 = lo;
    // 0x80030DBC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80030DC0: sltiu       $at, $v0, 0xE11
    ctx->r1 = ctx->r2 < 0XE11 ? 1 : 0;
    // 0x80030DC4: bne         $at, $zero, L_80030DF4
    if (ctx->r1 != 0) {
        // 0x80030DC8: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80030DF4;
    }
    // 0x80030DC8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80030DCC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80030DD0: addiu       $v0, $v0, 0x2852
    ctx->r2 = ADD32(ctx->r2, 0X2852);
    // 0x80030DD4: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80030DD8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80030DDC: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80030DE0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80030DE4: bne         $at, $zero, L_80030DFC
    if (ctx->r1 != 0) {
        // 0x80030DE8: sh          $t0, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r8;
            goto L_80030DFC;
    }
    // 0x80030DE8: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80030DEC: b           L_80030DFC
    // 0x80030DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80030DFC;
    // 0x80030DF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80030DF4:
    // 0x80030DF4: addiu       $v0, $v0, 0x2852
    ctx->r2 = ADD32(ctx->r2, 0X2852);
    // 0x80030DF8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80030DFC:
    // 0x80030DFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80030E00:
    // 0x80030E00: jr          $ra
    // 0x80030E04: nop

    return;
    // 0x80030E04: nop

    // 0x80030E08: nop

    // 0x80030E0C: nop

;}
RECOMP_FUNC void func_800202E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800202E4: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800202E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800202EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800202F0:
    // 0x800202F0: lbu         $t6, 0x12($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X12);
    // 0x800202F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800202F8: sltiu       $at, $v1, 0x7
    ctx->r1 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x800202FC: beq         $t6, $zero, L_80020308
    if (ctx->r14 == 0) {
        // 0x80020300: nop
    
            goto L_80020308;
    }
    // 0x80020300: nop

    // 0x80020304: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
L_80020308:
    // 0x80020308: bne         $at, $zero, L_800202F0
    if (ctx->r1 != 0) {
        // 0x8002030C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800202F0;
    }
    // 0x8002030C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020310: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x80020314: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020318: beql        $a0, $zero, L_8002033C
    if (ctx->r4 == 0) {
        // 0x8002031C: lw          $a0, 0x48($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X48);
            goto L_8002033C;
    }
    goto skip_0;
    // 0x8002031C: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    skip_0:
    // 0x80020320: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80020324: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80020328: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x8002032C: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80020330: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
    // 0x80020334: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x80020338: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
L_8002033C:
    // 0x8002033C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80020340: addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // 0x80020344: beql        $a0, $zero, L_80020364
    if (ctx->r4 == 0) {
        // 0x80020348: lw          $a0, 0x4C($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4C);
            goto L_80020364;
    }
    goto skip_1;
    // 0x80020348: lw          $a0, 0x4C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4C);
    skip_1:
    // 0x8002034C: lhu         $t9, 0x8($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X8);
    // 0x80020350: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x80020354: and         $t0, $t9, $a2
    ctx->r8 = ctx->r25 & ctx->r6;
    // 0x80020358: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x8002035C: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x80020360: lw          $a0, 0x4C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4C);
L_80020364:
    // 0x80020364: beql        $a0, $zero, L_80020384
    if (ctx->r4 == 0) {
        // 0x80020368: lw          $a0, 0x50($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X50);
            goto L_80020384;
    }
    goto skip_2;
    // 0x80020368: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    skip_2:
    // 0x8002036C: lhu         $t1, 0x8($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X8);
    // 0x80020370: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x80020374: and         $t2, $t1, $a2
    ctx->r10 = ctx->r9 & ctx->r6;
    // 0x80020378: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
    // 0x8002037C: sw          $zero, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = 0;
    // 0x80020380: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
L_80020384:
    // 0x80020384: beq         $a0, $zero, L_800203A0
    if (ctx->r4 == 0) {
        // 0x80020388: nop
    
            goto L_800203A0;
    }
    // 0x80020388: nop

    // 0x8002038C: lhu         $t3, 0x8($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X8);
    // 0x80020390: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x80020394: and         $t4, $t3, $a2
    ctx->r12 = ctx->r11 & ctx->r6;
    // 0x80020398: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x8002039C: sw          $zero, 0x50($v1)
    MEM_W(0X50, ctx->r3) = 0;
L_800203A0:
    // 0x800203A0: jr          $ra
    // 0x800203A4: nop

    return;
    // 0x800203A4: nop

    // 0x800203A8: jr          $ra
    // 0x800203AC: nop

    return;
    // 0x800203AC: nop

    // 0x800203B0: jr          $ra
    // 0x800203B4: nop

    return;
    // 0x800203B4: nop

    // 0x800203B8: jr          $ra
    // 0x800203BC: nop

    return;
    // 0x800203BC: nop

    // 0x800203C0: jr          $ra
    // 0x800203C4: nop

    return;
    // 0x800203C4: nop

    // 0x800203C8: jr          $ra
    // 0x800203CC: nop

    return;
    // 0x800203CC: nop

;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FE6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003FE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003FE74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003FE78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003FE7C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8003FE80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003FE84: jal         0x80034160
    // 0x8003FE88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8003FE88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003FE8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8003FE90: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003FE94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003FE98: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x8003FE9C: bne         $t0, $zero, L_8003FEB4
    if (ctx->r8 != 0) {
        // 0x8003FEA0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_8003FEB4;
    }
    // 0x8003FEA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8003FEA4: jal         0x80034160
    // 0x8003FEA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8003FEA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8003FEAC: b           L_8003FF84
    // 0x8003FEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003FF84;
    // 0x8003FEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003FEB4:
    // 0x8003FEB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003FEB8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003FEBC: jal         0x80036820
    // 0x8003FEC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80036820(rdram, ctx);
        goto after_2;
    // 0x8003FEC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8003FEC4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FEC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003FECC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8003FED0: jal         0x80048A40
    // 0x8003FED4: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x8003FED4: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x8003FED8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003FEDC: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x8003FEE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8003FEE4: bne         $a3, $at, L_8003FEF4
    if (ctx->r7 != ctx->r1) {
        // 0x8003FEE8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FEF4;
    }
    // 0x8003FEE8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FEEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8003FEF0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8003FEF4:
    // 0x8003FEF4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8003FEF8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8003FEFC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8003FF00: beq         $v0, $at, L_8003FF78
    if (ctx->r2 == ctx->r1) {
        // 0x8003FF04: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_8003FF78;
    }
    // 0x8003FF04: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_8003FF08:
    // 0x8003FF08: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8003FF0C: bnel        $v0, $zero, L_8003FF3C
    if (ctx->r2 != 0) {
        // 0x8003FF10: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_8003FF3C;
    }
    goto skip_0;
    // 0x8003FF10: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x8003FF14: beql        $t8, $zero, L_8003FF28
    if (ctx->r24 == 0) {
        // 0x8003FF18: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_8003FF28;
    }
    goto skip_1;
    // 0x8003FF18: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x8003FF1C: b           L_8003FF28
    // 0x8003FF20: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_8003FF28;
    // 0x8003FF20: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8003FF24: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_8003FF28:
    // 0x8003FF28: jal         0x80036850
    // 0x8003FF2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80036850(rdram, ctx);
        goto after_4;
    // 0x8003FF2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x8003FF30: b           L_8003FF78
    // 0x8003FF34: nop

        goto L_8003FF78;
    // 0x8003FF34: nop

    // 0x8003FF38: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_8003FF3C:
    // 0x8003FF3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8003FF40: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003FF44: beql        $at, $zero, L_8003FF70
    if (ctx->r1 == 0) {
        // 0x8003FF48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8003FF70;
    }
    goto skip_2;
    // 0x8003FF48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x8003FF4C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x8003FF50: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8003FF54: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8003FF58: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x8003FF5C: jal         0x80036850
    // 0x8003FF60: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    func_80036850(rdram, ctx);
        goto after_5;
    // 0x8003FF60: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x8003FF64: b           L_8003FF78
    // 0x8003FF68: nop

        goto L_8003FF78;
    // 0x8003FF68: nop

    // 0x8003FF6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8003FF70:
    // 0x8003FF70: bne         $v0, $zero, L_8003FF08
    if (ctx->r2 != 0) {
        // 0x8003FF74: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_8003FF08;
    }
    // 0x8003FF74: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_8003FF78:
    // 0x8003FF78: jal         0x80034160
    // 0x8003FF7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x8003FF7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x8003FF80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003FF84:
    // 0x8003FF84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003FF88: jr          $ra
    // 0x8003FF8C: nop

    return;
    // 0x8003FF8C: nop

;}
RECOMP_FUNC void func_80043E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043E84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80043E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043E8C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80043E90: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80043E94: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x80043E98: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80043E9C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80043EA0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80043EA4: lw          $t6, 0x990($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X990);
    // 0x80043EA8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80043EAC: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80043EB0: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x80043EB4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x80043EB8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80043EBC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80043EC0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80043EC4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x80043EC8: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80043ECC: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x80043ED0: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x80043ED4: sw          $t1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r9;
    // 0x80043ED8: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80043EDC: sb          $t0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r8;
    // 0x80043EE0: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x80043EE4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80043EE8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80043EEC: sw          $t2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r10;
    // 0x80043EF0: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x80043EF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043EF8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80043EFC: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
    // 0x80043F00: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x80043F04: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80043F08: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x80043F0C: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x80043F10: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x80043F14: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
    // 0x80043F18: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80043F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80043F20: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x80043F24: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80043F28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80043F2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043F30: jal         0x80036660
    // 0x80043F34: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80043F34: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80043F38: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80043F3C: jal         0x80043E14
    // 0x80043F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80043E14(rdram, ctx);
        goto after_1;
    // 0x80043F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80043F44: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80043F48: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80043F4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80043F50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80043F58: jal         0x80036660
    // 0x80043F5C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80043F5C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80043F60: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80043F64: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80043F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80043F70: blez        $t9, L_80043FA0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80043F74: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_80043FA0;
    }
    // 0x80043F74: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80043F78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80043F7C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
L_80043F80:
    // 0x80043F80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80043F84: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80043F88: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x80043F8C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80043F90: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x80043F94: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80043F98: bnel        $at, $zero, L_80043F80
    if (ctx->r1 != 0) {
        // 0x80043F9C: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_80043F80;
    }
    goto skip_0;
    // 0x80043F9C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_0:
L_80043FA0:
    // 0x80043FA0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80043FA4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x80043FA8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x80043FAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80043FB0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80043FB4: jal         0x80036660
    // 0x80043FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80043FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80043FBC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80043FC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80043FC4: jal         0x8004001C
    // 0x80043FC8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    func_8004001C(rdram, ctx);
        goto after_4;
    // 0x80043FC8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x80043FCC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80043FD0: addiu       $t3, $t3, 0x36EC
    ctx->r11 = ADD32(ctx->r11, 0X36EC);
    // 0x80043FD4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80043FD8: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80043FDC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80043FE0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80043FE4: lw          $a0, 0x990($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X990);
    // 0x80043FE8: jal         0x80044010
    // 0x80043FEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80044010(rdram, ctx);
        goto after_5;
    // 0x80043FEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80043FF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80043FF4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80043FF8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80043FFC: jr          $ra
    // 0x80044000: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80044000: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80044004: nop

    // 0x80044008: nop

    // 0x8004400C: nop

;}
RECOMP_FUNC void func_8002FD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002FD94: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8002FD98: addiu       $a3, $a3, -0x4D04
    ctx->r7 = ADD32(ctx->r7, -0X4D04);
    // 0x8002FD9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002FDA0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002FDA4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002FDA8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8002FDAC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8002FDB0: sll         $t1, $a0, 4
    ctx->r9 = S32(ctx->r4 << 4);
    // 0x8002FDB4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8002FDB8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8002FDBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002FDC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002FDC4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8002FDC8: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8002FDCC: addiu       $t0, $zero, -0x34
    ctx->r8 = ADD32(0, -0X34);
    // 0x8002FDD0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8002FDD4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8002FDD8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8002FDDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002FDE0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8002FDE4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002FDE8: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8002FDEC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002FDF0: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8002FDF4: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8002FDF8: addiu       $t2, $t2, 0x5E0
    ctx->r10 = ADD32(ctx->r10, 0X5E0);
    // 0x8002FDFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002FE00: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8002FE04: lbu         $t3, 0x17($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17);
    // 0x8002FE08: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002FE0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002FE10: beq         $t3, $at, L_8002FE78
    if (ctx->r11 == ctx->r1) {
        // 0x8002FE14: addiu       $a3, $zero, 0x28
        ctx->r7 = ADD32(0, 0X28);
            goto L_8002FE78;
    }
    // 0x8002FE14: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8002FE18: lh          $s0, 0x4($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X4);
    // 0x8002FE1C: lh          $s1, 0x6($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X6);
    // 0x8002FE20: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8002FE24: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002FE28: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8002FE2C: addiu       $a1, $s0, 0x1B
    ctx->r5 = ADD32(ctx->r16, 0X1B);
    // 0x8002FE30: jal         0x800307D8
    // 0x8002FE34: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    func_800307D8(rdram, ctx);
        goto after_0;
    // 0x8002FE34: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_0:
    // 0x8002FE38: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FE3C: lh          $s0, 0x4($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X4);
    // 0x8002FE40: lh          $s1, 0x6($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X6);
    // 0x8002FE44: addiu       $a2, $v0, 0x17
    ctx->r6 = ADD32(ctx->r2, 0X17);
    // 0x8002FE48: addiu       $a0, $s0, 0x49
    ctx->r4 = ADD32(ctx->r16, 0X49);
    // 0x8002FE4C: jal         0x80030EA0
    // 0x8002FE50: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_80030EA0(rdram, ctx);
        goto after_1;
    // 0x8002FE50: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_1:
    // 0x8002FE54: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FE58: lh          $s0, 0x4($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X4);
    // 0x8002FE5C: lh          $s1, 0x6($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X6);
    // 0x8002FE60: addiu       $a2, $v0, 0x49C
    ctx->r6 = ADD32(ctx->r2, 0X49C);
    // 0x8002FE64: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8002FE68: jal         0x80030EA0
    // 0x8002FE6C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    func_80030EA0(rdram, ctx);
        goto after_2;
    // 0x8002FE6C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    after_2:
    // 0x8002FE70: b           L_8002FE94
    // 0x8002FE74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8002FE94;
    // 0x8002FE74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002FE78:
    // 0x8002FE78: lh          $s0, 0x4($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X4);
    // 0x8002FE7C: lh          $s1, 0x6($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X6);
    // 0x8002FE80: addiu       $a2, $v0, 0x49C
    ctx->r6 = ADD32(ctx->r2, 0X49C);
    // 0x8002FE84: addiu       $a0, $s0, 0x6
    ctx->r4 = ADD32(ctx->r16, 0X6);
    // 0x8002FE88: jal         0x80030EA0
    // 0x8002FE8C: addiu       $a1, $s1, 0x6
    ctx->r5 = ADD32(ctx->r17, 0X6);
    func_80030EA0(rdram, ctx);
        goto after_3;
    // 0x8002FE8C: addiu       $a1, $s1, 0x6
    ctx->r5 = ADD32(ctx->r17, 0X6);
    after_3:
    // 0x8002FE90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002FE94:
    // 0x8002FE94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002FE9C: jr          $ra
    // 0x8002FEA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002FEA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800390C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800390C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800390C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800390C8: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800390CC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800390D0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800390D4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800390D8: jal         0x8003FE6C
    // 0x800390DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800390DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800390E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800390E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800390E8: jr          $ra
    // 0x800390EC: nop

    return;
    // 0x800390EC: nop

;}
RECOMP_FUNC void func_8000AC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC84: lhu         $v1, 0x114($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X114);
    // 0x8000AC88: lhu         $t6, 0x11A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X11A);
    // 0x8000AC8C: lhu         $t9, 0x90($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X90);
    // 0x8000AC90: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AC94: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000AC98: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AC9C: sra         $t7, $v1, 4
    ctx->r15 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8000ACA0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000ACA4: beq         $t0, $zero, L_8000ACB4
    if (ctx->r8 == 0) {
        // 0x8000ACA8: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000ACB4;
    }
    // 0x8000ACA8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8000ACAC: srl         $t1, $t8, 1
    ctx->r9 = S32(U32(ctx->r24) >> 1);
    // 0x8000ACB0: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
L_8000ACB4:
    // 0x8000ACB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000ACB8: jr          $ra
    // 0x8000ACBC: nop

    return;
    // 0x8000ACBC: nop

;}
RECOMP_FUNC void func_80023C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023C20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80023C24: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80023C28: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80023C2C: lwc1        $f0, -0x28B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28B4);
    // 0x80023C30: lwc1        $f20, 0x60($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023C34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80023C38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023C3C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80023C40: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80023C44: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80023C48: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80023C4C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80023C50: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80023C54: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80023C58: nop

    // 0x80023C5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80023C60: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80023C64: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80023C68: jal         0x80035680
    // 0x80023C6C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023C6C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80023C70: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80023C74: jal         0x800361F0
    // 0x80023C78: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80023C78: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80023C7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80023C80: jal         0x80035680
    // 0x80023C84: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80023C84: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x80023C88: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80023C8C: jal         0x800361F0
    // 0x80023C90: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80023C90: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80023C94: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80023C98: jal         0x80035680
    // 0x80023C9C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80023C9C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80023CA0: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80023CA4: jal         0x800361F0
    // 0x80023CA8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x80023CA8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80023CAC: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023CB0: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023CB4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023CB8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023CBC: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80023CC0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80023CC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023CC8: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80023CCC: nop

    // 0x80023CD0: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80023CD4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023CD8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80023CDC: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x80023CE0: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80023CE4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80023CE8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80023CEC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80023CF0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80023CF4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023CF8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80023CFC: nop

    // 0x80023D00: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80023D04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023D08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023D0C: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x80023D10: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80023D14: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80023D18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023D1C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80023D20: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023D24: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80023D28: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023D2C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023D30: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80023D34: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80023D38: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023D3C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80023D40: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80023D44: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80023D48: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80023D4C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80023D50: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80023D54: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80023D58: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80023D5C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80023D60: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80023D64: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023D68: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023D6C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023D70: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80023D74: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80023D78: nop

    // 0x80023D7C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80023D80: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80023D84: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80023D88: nop

    // 0x80023D8C: mul.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80023D90: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80023D94: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80023D98: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80023D9C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023DA0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80023DA4: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80023DA8: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80023DAC: nop

    // 0x80023DB0: mul.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80023DB4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80023DB8: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80023DBC: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80023DC0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80023DC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023DC8: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x80023DCC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80023DD0: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80023DD4: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80023DD8: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80023DDC: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80023DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023DE4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80023DE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80023DEC: jr          $ra
    // 0x80023DF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023DF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80015630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015630: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80015634: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001563C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015640: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015644: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x80015648: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001564C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015650: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80015654: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80015658: lwc1        $f12, 0x10($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001565C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015660: jal         0x800232F4
    // 0x80015664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80015664: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80015668: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001566C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015670: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015674: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80015678: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8001567C: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80015680: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015684: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80015688: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x8001568C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015690: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80015694: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80015698: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8001569C: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800156A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800156A4: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800156A8: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800156AC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800156B0: lwc1        $f6, 0x24($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800156B4: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800156B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800156BC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800156C0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800156C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800156C8: jr          $ra
    // 0x800156CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800156CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002D8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D8BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D8C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D8C4: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8002D8C8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D8CC: lb          $t0, -0x2D6($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2D6);
    // 0x8002D8D0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002D8D4: addiu       $t7, $t7, -0x2D0
    ctx->r15 = ADD32(ctx->r15, -0X2D0);
    // 0x8002D8D8: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x8002D8DC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8002D8E0: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x8002D8E4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002D8E8: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x8002D8EC: bne         $t1, $t8, L_8002D9C4
    if (ctx->r9 != ctx->r24) {
        // 0x8002D8F0: nop
    
            goto L_8002D9C4;
    }
    // 0x8002D8F0: nop

    // 0x8002D8F4: lb          $t9, 0x2870($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2870);
    // 0x8002D8F8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002D8FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8002D900: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8002D904: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8002D908: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002D90C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8002D910: lh          $a2, 0x2A38($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X2A38);
    // 0x8002D914: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8002D918: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8002D91C: andi        $t3, $a2, 0xF
    ctx->r11 = ctx->r6 & 0XF;
    // 0x8002D920: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_8002D924:
    // 0x8002D924: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D928: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002D92C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002D930: addiu       $v0, $v0, -0x2D0
    ctx->r2 = ADD32(ctx->r2, -0X2D0);
L_8002D934:
    // 0x8002D934: lb          $t4, 0x1($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1);
    // 0x8002D938: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002D93C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002D940: bne         $a0, $t4, L_8002D950
    if (ctx->r4 != ctx->r12) {
        // 0x8002D944: nop
    
            goto L_8002D950;
    }
    // 0x8002D944: nop

    // 0x8002D948: b           L_8002D958
    // 0x8002D94C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_8002D958;
    // 0x8002D94C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8002D950:
    // 0x8002D950: bne         $at, $zero, L_8002D934
    if (ctx->r1 != 0) {
        // 0x8002D954: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8002D934;
    }
    // 0x8002D954: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8002D958:
    // 0x8002D958: beq         $v1, $a1, L_8002D968
    if (ctx->r3 == ctx->r5) {
        // 0x8002D95C: nop
    
            goto L_8002D968;
    }
    // 0x8002D95C: nop

    // 0x8002D960: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002D964: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8002D968:
    // 0x8002D968: bgez        $a0, L_8002D924
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002D96C: nop
    
            goto L_8002D924;
    }
    // 0x8002D96C: nop

    // 0x8002D970: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x8002D974: beq         $at, $zero, L_8002D980
    if (ctx->r1 == 0) {
        // 0x8002D978: sb          $a2, 0x1($a3)
        MEM_B(0X1, ctx->r7) = ctx->r6;
            goto L_8002D980;
    }
    // 0x8002D978: sb          $a2, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r6;
    // 0x8002D97C: sb          $t1, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r9;
L_8002D980:
    // 0x8002D980: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D984: jal         0x80031890
    // 0x8002D988: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    func_80031890(rdram, ctx);
        goto after_0;
    // 0x8002D988: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x8002D98C: bltz        $v0, L_8002D9B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002D990: lui         $t0, 0x8009
        ctx->r8 = S32(0X8009 << 16);
            goto L_8002D9B0;
    }
    // 0x8002D990: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D994: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D998: lb          $t0, -0x2D6($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2D6);
    // 0x8002D99C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D9A0: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x8002D9A4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002D9A8: b           L_8002D9B4
    // 0x8002D9AC: sb          $v0, -0x2D0($at)
    MEM_B(-0X2D0, ctx->r1) = ctx->r2;
        goto L_8002D9B4;
    // 0x8002D9AC: sb          $v0, -0x2D0($at)
    MEM_B(-0X2D0, ctx->r1) = ctx->r2;
L_8002D9B0:
    // 0x8002D9B0: lb          $t0, -0x2D6($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2D6);
L_8002D9B4:
    // 0x8002D9B4: jal         0x8002E234
    // 0x8002D9B8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_8002E234(rdram, ctx);
        goto after_1;
    // 0x8002D9B8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x8002D9BC: b           L_8002D9CC
    // 0x8002D9C0: nop

        goto L_8002D9CC;
    // 0x8002D9C0: nop

L_8002D9C4:
    // 0x8002D9C4: jal         0x8002E234
    // 0x8002D9C8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_8002E234(rdram, ctx);
        goto after_2;
    // 0x8002D9C8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_8002D9CC:
    // 0x8002D9CC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D9D0: lb          $t0, -0x2D6($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2D6);
    // 0x8002D9D4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002D9D8: addiu       $t9, $t9, -0x2A8
    ctx->r25 = ADD32(ctx->r25, -0X2A8);
    // 0x8002D9DC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8002D9E0: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x8002D9E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002D9E8: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8002D9EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002D9F0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002D9F4: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x8002D9F8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8002D9FC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8002DA00: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002DA04: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    // 0x8002DA08: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002DA0C: lb          $a1, -0x2D0($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2D0);
    // 0x8002DA10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002DA14: jal         0x80031A44
    // 0x8002DA18: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_80031A44(rdram, ctx);
        goto after_3;
    // 0x8002DA18: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x8002DA1C: beq         $v0, $zero, L_8002DABC
    if (ctx->r2 == 0) {
        // 0x8002DA20: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8002DABC;
    }
    // 0x8002DA20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DA24: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA28: jal         0x80031BB0
    // 0x8002DA2C: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    func_80031BB0(rdram, ctx);
        goto after_4;
    // 0x8002DA2C: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    after_4:
    // 0x8002DA30: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8002DA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DA38: beq         $v1, $at, L_8002DA68
    if (ctx->r3 == ctx->r1) {
        // 0x8002DA3C: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002DA68;
    }
    // 0x8002DA3C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002DA40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002DA44: beq         $v1, $at, L_8002DA84
    if (ctx->r3 == ctx->r1) {
        // 0x8002DA48: addiu       $t7, $zero, 0xE
        ctx->r15 = ADD32(0, 0XE);
            goto L_8002DA84;
    }
    // 0x8002DA48: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8002DA4C: addiu       $t3, $zero, 0x11
    ctx->r11 = ADD32(0, 0X11);
    // 0x8002DA50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA54: sb          $t3, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r11;
    // 0x8002DA58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA5C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002DA60: b           L_8002DA98
    // 0x8002DA64: sb          $t4, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r12;
        goto L_8002DA98;
    // 0x8002DA64: sb          $t4, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r12;
L_8002DA68:
    // 0x8002DA68: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x8002DA6C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA70: sb          $t5, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r13;
    // 0x8002DA74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA78: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002DA7C: b           L_8002DA98
    // 0x8002DA80: sb          $t6, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r14;
        goto L_8002DA98;
    // 0x8002DA80: sb          $t6, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r14;
L_8002DA84:
    // 0x8002DA84: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA88: sb          $t7, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r15;
    // 0x8002DA8C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DA90: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002DA94: sb          $t8, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r24;
L_8002DA98:
    // 0x8002DA98: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002DA9C: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8002DAA0: andi        $t3, $t9, 0xFFF8
    ctx->r11 = ctx->r25 & 0XFFF8;
    // 0x8002DAA4: ori         $t5, $t3, 0x5
    ctx->r13 = ctx->r11 | 0X5;
    // 0x8002DAA8: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x8002DAAC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8002DAB0: andi        $t6, $t5, 0xDFFF
    ctx->r14 = ctx->r13 & 0XDFFF;
    // 0x8002DAB4: b           L_8002DBD0
    // 0x8002DAB8: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
        goto L_8002DBD0;
    // 0x8002DAB8: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
L_8002DABC:
    // 0x8002DABC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002DAC0: lb          $t7, -0x2D6($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2D6);
    // 0x8002DAC4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002DAC8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002DACC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002DAD0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8002DAD4: addiu       $t9, $t9, 0x398
    ctx->r25 = ADD32(ctx->r25, 0X398);
    // 0x8002DAD8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002DADC: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    // 0x8002DAE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002DAE4: lb          $a1, -0x2D0($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2D0);
    // 0x8002DAE8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8002DAEC: jal         0x80031A44
    // 0x8002DAF0: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    func_80031A44(rdram, ctx);
        goto after_5;
    // 0x8002DAF0: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    after_5:
    // 0x8002DAF4: beq         $v0, $zero, L_8002DB94
    if (ctx->r2 == 0) {
        // 0x8002DAF8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8002DB94;
    }
    // 0x8002DAF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DAFC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB00: jal         0x80031BB0
    // 0x8002DB04: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    func_80031BB0(rdram, ctx);
        goto after_6;
    // 0x8002DB04: sw          $v0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r2;
    after_6:
    // 0x8002DB08: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8002DB0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DB10: beq         $v1, $at, L_8002DB40
    if (ctx->r3 == ctx->r1) {
        // 0x8002DB14: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002DB40;
    }
    // 0x8002DB14: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002DB18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002DB1C: beq         $v1, $at, L_8002DB5C
    if (ctx->r3 == ctx->r1) {
        // 0x8002DB20: addiu       $t6, $zero, 0xE
        ctx->r14 = ADD32(0, 0XE);
            goto L_8002DB5C;
    }
    // 0x8002DB20: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002DB24: addiu       $t2, $zero, 0x11
    ctx->r10 = ADD32(0, 0X11);
    // 0x8002DB28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB2C: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
    // 0x8002DB30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB34: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002DB38: b           L_8002DB70
    // 0x8002DB3C: sb          $t3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r11;
        goto L_8002DB70;
    // 0x8002DB3C: sb          $t3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r11;
L_8002DB40:
    // 0x8002DB40: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8002DB44: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB48: sb          $t4, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r12;
    // 0x8002DB4C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB50: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002DB54: b           L_8002DB70
    // 0x8002DB58: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
        goto L_8002DB70;
    // 0x8002DB58: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
L_8002DB5C:
    // 0x8002DB5C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB60: sb          $t6, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r14;
    // 0x8002DB64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DB68: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002DB6C: sb          $t7, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r15;
L_8002DB70:
    // 0x8002DB70: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002DB74: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x8002DB78: andi        $t2, $t8, 0xFFF8
    ctx->r10 = ctx->r24 & 0XFFF8;
    // 0x8002DB7C: ori         $t4, $t2, 0x5
    ctx->r12 = ctx->r10 | 0X5;
    // 0x8002DB80: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x8002DB84: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8002DB88: andi        $t5, $t4, 0xDFFF
    ctx->r13 = ctx->r12 & 0XDFFF;
    // 0x8002DB8C: b           L_8002DBD0
    // 0x8002DB90: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_8002DBD0;
    // 0x8002DB90: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_8002DB94:
    // 0x8002DB94: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002DB98: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002DB9C: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8002DBA0: addiu       $t4, $zero, 0x17
    ctx->r12 = ADD32(0, 0X17);
    // 0x8002DBA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DBA8: andi        $t8, $t6, 0xFFF8
    ctx->r24 = ctx->r14 & 0XFFF8;
    // 0x8002DBAC: ori         $t2, $t8, 0x5
    ctx->r10 = ctx->r24 | 0X5;
    // 0x8002DBB0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8002DBB4: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x8002DBB8: andi        $t3, $t2, 0xDFFF
    ctx->r11 = ctx->r10 & 0XDFFF;
    // 0x8002DBBC: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x8002DBC0: sb          $t4, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r12;
    // 0x8002DBC4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002DBC8: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002DBCC: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
L_8002DBD0:
    // 0x8002DBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DBD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002DBD8: jr          $ra
    // 0x8002DBDC: nop

    return;
    // 0x8002DBDC: nop

;}
RECOMP_FUNC void func_8001FEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FEEC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8001FEF0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001FEF4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001FEF8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001FEFC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8001FF00: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8001FF04: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001FF08: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001FF0C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001FF10: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001FF14: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001FF18: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001FF1C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001FF20: lw          $t6, -0x4D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D1C);
    // 0x8001FF24: lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X68);
    // 0x8001FF28: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // 0x8001FF2C: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8001FF30: bne         $t7, $zero, L_8002013C
    if (ctx->r15 != 0) {
        // 0x8001FF34: or          $fp, $v0, $zero
        ctx->r30 = ctx->r2 | 0;
            goto L_8002013C;
    }
    // 0x8001FF34: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8001FF38: lw          $v1, 0x64($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X64);
    // 0x8001FF3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FF40: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
    // 0x8001FF44: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8001FF48: bnel        $t8, $at, L_8001FF5C
    if (ctx->r24 != ctx->r1) {
        // 0x8001FF4C: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8001FF5C;
    }
    goto skip_0;
    // 0x8001FF4C: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x8001FF50: b           L_8001FF6C
    // 0x8001FF54: lwc1        $f14, 0x94($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X94);
        goto L_8001FF6C;
    // 0x8001FF54: lwc1        $f14, 0x94($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8001FF58: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
L_8001FF5C:
    // 0x8001FF5C: lwc1        $f6, 0x24($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8001FF60: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8001FF64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FF68: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
L_8001FF6C:
    // 0x8001FF6C: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8001FF70: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x8001FF74: jal         0x8002413C
    // 0x8001FF78: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001FF78: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x8001FF7C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001FF80: addiu       $a0, $a0, -0x4D04
    ctx->r4 = ADD32(ctx->r4, -0X4D04);
    // 0x8001FF84: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8001FF88: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8001FF8C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FF90: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8001FF94: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001FF98: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8001FF9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001FFA0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001FFA4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8001FFA8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FFAC: lui         $t9, 0x803A
    ctx->r25 = S32(0X803A << 16);
    // 0x8001FFB0: addiu       $t9, $t9, 0x2960
    ctx->r25 = ADD32(ctx->r25, 0X2960);
    // 0x8001FFB4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8001FFB8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001FFBC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8001FFC0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001FFC4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FFC8: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8001FFCC: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8001FFD0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8001FFD4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001FFD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001FFDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001FFE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FFE4: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8001FFE8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8001FFEC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8001FFF0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001FFF4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8001FFF8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001FFFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80020000: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80020004: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80020008: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8002000C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80020010: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80020014: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80020018: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8002001C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80020020: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80020024: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80020028: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8002002C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80020030: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80020034: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80020038: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002003C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80020040: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80020044: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80020048: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002004C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80020050: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
L_80020054:
    // 0x80020054: lbu         $v1, 0x12($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X12);
    // 0x80020058: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8002005C: addiu       $t6, $t6, -0x7290
    ctx->r14 = ADD32(ctx->r14, -0X7290);
    // 0x80020060: beq         $v1, $zero, L_8002012C
    if (ctx->r3 == 0) {
        // 0x80020064: sll         $t9, $v1, 3
        ctx->r25 = S32(ctx->r3 << 3);
            goto L_8002012C;
    }
    // 0x80020064: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80020068: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x8002006C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80020070: addiu       $t8, $t8, -0x2D34
    ctx->r24 = ADD32(ctx->r24, -0X2D34);
    // 0x80020074: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x80020078: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8002007C: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80020080: lhu         $s1, 0x4($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X4);
    // 0x80020084: lhu         $s2, 0x6($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X6);
    // 0x80020088: beq         $t4, $zero, L_800200E4
    if (ctx->r12 == 0) {
        // 0x8002008C: addu        $s5, $t7, $t8
        ctx->r21 = ADD32(ctx->r15, ctx->r24);
            goto L_800200E4;
    }
    // 0x8002008C: addu        $s5, $t7, $t8
    ctx->r21 = ADD32(ctx->r15, ctx->r24);
    // 0x80020090: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80020094: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80020098: sra         $t7, $s1, 1
    ctx->r15 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8002009C: addu        $t6, $t9, $s7
    ctx->r14 = ADD32(ctx->r25, ctx->r23);
    // 0x800200A0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x800200A4: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x800200A8: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800200AC: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800200B0: sra         $t6, $s2, 1
    ctx->r14 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800200B4: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x800200B8: addiu       $a0, $a0, 0x6F70
    ctx->r4 = ADD32(ctx->r4, 0X6F70);
    // 0x800200BC: subu        $a2, $t9, $t6
    ctx->r6 = SUB32(ctx->r25, ctx->r14);
    // 0x800200C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800200C4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800200C8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800200CC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800200D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800200D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800200D8: jal         0x800210FC
    // 0x800200DC: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x800200DC: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    after_1:
    // 0x800200E0: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
L_800200E4:
    // 0x800200E4: lhu         $t9, 0x0($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X0);
    // 0x800200E8: lhu         $t6, 0x0($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X0);
    // 0x800200EC: sra         $v1, $s1, 1
    ctx->r3 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800200F0: sra         $a0, $s2, 1
    ctx->r4 = S32(SIGNED(ctx->r18) >> 1);
    // 0x800200F4: and         $t7, $t9, $t6
    ctx->r15 = ctx->r25 & ctx->r14;
    // 0x800200F8: bne         $t7, $zero, L_80020108
    if (ctx->r15 != 0) {
        // 0x800200FC: addu        $s7, $s7, $v1
        ctx->r23 = ADD32(ctx->r23, ctx->r3);
            goto L_80020108;
    }
    // 0x800200FC: addu        $s7, $s7, $v1
    ctx->r23 = ADD32(ctx->r23, ctx->r3);
    // 0x80020100: b           L_80020128
    // 0x80020104: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
        goto L_80020128;
    // 0x80020104: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
L_80020108:
    // 0x80020108: lb          $v0, 0x22($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X22);
    // 0x8002010C: blez        $v0, L_80020128
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80020110: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80020128;
    }
    // 0x80020110: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80020114: sb          $t8, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r24;
    // 0x80020118: lb          $t9, 0x22($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X22);
    // 0x8002011C: bnel        $t9, $zero, L_8002012C
    if (ctx->r25 != 0) {
        // 0x80020120: subu        $s6, $s6, $a0
        ctx->r22 = SUB32(ctx->r22, ctx->r4);
            goto L_8002012C;
    }
    goto skip_1;
    // 0x80020120: subu        $s6, $s6, $a0
    ctx->r22 = SUB32(ctx->r22, ctx->r4);
    skip_1:
    // 0x80020124: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
L_80020128:
    // 0x80020128: subu        $s6, $s6, $a0
    ctx->r22 = SUB32(ctx->r22, ctx->r4);
L_8002012C:
    // 0x8002012C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80020130: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80020134: bne         $s4, $at, L_80020054
    if (ctx->r20 != ctx->r1) {
        // 0x80020138: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80020054;
    }
    // 0x80020138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8002013C:
    // 0x8002013C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80020140: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80020144: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80020148: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002014C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020150: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80020154: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80020158: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8002015C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80020160: addiu       $a3, $zero, -0x2
    ctx->r7 = ADD32(0, -0X2);
L_80020164:
    // 0x80020164: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80020168: beql        $t6, $zero, L_800202A8
    if (ctx->r14 == 0) {
        // 0x8002016C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800202A8;
    }
    goto skip_2;
    // 0x8002016C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_2:
    // 0x80020170: lw          $t7, 0x68($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X68);
    // 0x80020174: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80020178: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8002017C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80020180: lw          $v0, 0x44($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X44);
    // 0x80020184: addiu       $t6, $t6, -0x2D24
    ctx->r14 = ADD32(ctx->r14, -0X2D24);
    // 0x80020188: sll         $t9, $s4, 1
    ctx->r25 = S32(ctx->r20 << 1);
    // 0x8002018C: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80020190: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80020194: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x80020198: addu        $s0, $fp, $s4
    ctx->r16 = ADD32(ctx->r30, ctx->r20);
    // 0x8002019C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x800201A0: lw          $v1, 0x64($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X64);
    // 0x800201A4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800201A8: bnel        $t2, $t7, L_800201F4
    if (ctx->r10 != ctx->r15) {
        // 0x800201AC: lhu         $t8, 0x8($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X8);
            goto L_800201F4;
    }
    goto skip_3;
    // 0x800201AC: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    skip_3:
    // 0x800201B0: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x800201B4: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800201B8: beql        $t9, $zero, L_800201D4
    if (ctx->r25 == 0) {
        // 0x800201BC: lwc1        $f6, 0x18($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
            goto L_800201D4;
    }
    goto skip_4;
    // 0x800201BC: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    skip_4:
    // 0x800201C0: lw          $t6, 0x68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X68);
    // 0x800201C4: lwc1        $f4, 0x94($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X94);
    // 0x800201C8: b           L_80020238
    // 0x800201CC: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
        goto L_80020238;
    // 0x800201CC: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800201D0: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
L_800201D4:
    // 0x800201D4: lwc1        $f10, 0x24($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800201D8: lw          $t7, 0x68($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X68);
    // 0x800201DC: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800201E0: lwc1        $f16, 0x94($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X94);
    // 0x800201E4: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800201E8: b           L_80020238
    // 0x800201EC: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
        goto L_80020238;
    // 0x800201EC: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x800201F0: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
L_800201F4:
    // 0x800201F4: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800201F8: beql        $t9, $zero, L_80020234
    if (ctx->r25 == 0) {
        // 0x800201FC: lwc1        $f8, 0x4($s3)
        ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
            goto L_80020234;
    }
    goto skip_5;
    // 0x800201FC: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    skip_5:
    // 0x80020200: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80020204: lwc1        $f16, 0x24($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80020208: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002020C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80020210: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80020214: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020218: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002021C: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80020220: add.d       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f6.d + ctx->f18.d;
    // 0x80020224: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80020228: b           L_80020238
    // 0x8002022C: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
        goto L_80020238;
    // 0x8002022C: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80020230: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
L_80020234:
    // 0x80020234: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
L_80020238:
    // 0x80020238: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x8002023C: lhu         $t7, 0x0($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X0);
    // 0x80020240: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80020244: bnel        $t8, $zero, L_80020270
    if (ctx->r24 != 0) {
        // 0x80020248: lb          $v1, 0x32($s0)
        ctx->r3 = MEM_B(ctx->r16, 0X32);
            goto L_80020270;
    }
    goto skip_6;
    // 0x80020248: lb          $v1, 0x32($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X32);
    skip_6:
    // 0x8002024C: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    // 0x80020250: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80020254: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80020258: beq         $t9, $zero, L_800202A4
    if (ctx->r25 == 0) {
        // 0x8002025C: and         $t6, $v1, $a3
        ctx->r14 = ctx->r3 & ctx->r7;
            goto L_800202A4;
    }
    // 0x8002025C: and         $t6, $v1, $a3
    ctx->r14 = ctx->r3 & ctx->r7;
    // 0x80020260: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80020264: b           L_800202A4
    // 0x80020268: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
        goto L_800202A4;
    // 0x80020268: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8002026C: lb          $v1, 0x32($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X32);
L_80020270:
    // 0x80020270: blez        $v1, L_800202A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020274: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800202A4;
    }
    // 0x80020274: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80020278: sb          $t7, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r15;
    // 0x8002027C: lb          $t8, 0x32($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X32);
    // 0x80020280: bnel        $t8, $zero, L_800202A8
    if (ctx->r24 != 0) {
        // 0x80020284: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800202A8;
    }
    goto skip_7;
    // 0x80020284: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_7:
    // 0x80020288: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    // 0x8002028C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x80020290: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x80020294: beq         $t9, $zero, L_800202A4
    if (ctx->r25 == 0) {
        // 0x80020298: and         $t6, $v1, $a3
        ctx->r14 = ctx->r3 & ctx->r7;
            goto L_800202A4;
    }
    // 0x80020298: and         $t6, $v1, $a3
    ctx->r14 = ctx->r3 & ctx->r7;
    // 0x8002029C: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x800202A0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_800202A4:
    // 0x800202A4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800202A8:
    // 0x800202A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800202AC: bne         $s4, $t1, L_80020164
    if (ctx->r20 != ctx->r9) {
        // 0x800202B0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80020164;
    }
    // 0x800202B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800202B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800202B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800202BC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800202C0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800202C4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800202C8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800202CC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800202D0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800202D4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800202D8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800202DC: jr          $ra
    // 0x800202E0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800202E0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80102F14_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F14: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x80102F18: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80102F1C: addiu       $a1, $a1, 0x3420
    ctx->r5 = ADD32(ctx->r5, 0X3420);
    // 0x80102F20: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80102F24: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80102F28: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80102F2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80102F30: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80102F34: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80102F38: beq         $t9, $zero, L_80102F54
    if (ctx->r25 == 0) {
        // 0x80102F3C: addiu       $t4, $t4, -0x4D04
        ctx->r12 = ADD32(ctx->r12, -0X4D04);
            goto L_80102F54;
    }
    // 0x80102F3C: addiu       $t4, $t4, -0x4D04
    ctx->r12 = ADD32(ctx->r12, -0X4D04);
    // 0x80102F40: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80102F44: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80102F48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80102F4C: b           L_80102F64
    // 0x80102F50: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
        goto L_80102F64;
    // 0x80102F50: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_80102F54:
    // 0x80102F54: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80102F58: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80102F5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80102F60: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_80102F64:
    // 0x80102F64: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80102F68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80102F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80102F70: beq         $v0, $a2, L_80102FA0
    if (ctx->r2 == ctx->r6) {
        // 0x80102F74: lui         $t8, 0xE700
        ctx->r24 = S32(0XE700 << 16);
            goto L_80102FA0;
    }
    // 0x80102F74: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80102F78: beq         $v0, $at, L_80102FA0
    if (ctx->r2 == ctx->r1) {
        // 0x80102F7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80102FA0;
    }
    // 0x80102F7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80102F80: beq         $v0, $at, L_80102F98
    if (ctx->r2 == ctx->r1) {
        // 0x80102F84: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80102F98;
    }
    // 0x80102F84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80102F88: beq         $v0, $at, L_80102F98
    if (ctx->r2 == ctx->r1) {
        // 0x80102F8C: nop
    
            goto L_80102F98;
    }
    // 0x80102F8C: nop

    // 0x80102F90: b           L_80102FA4
    // 0x80102F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102FA4;
    // 0x80102F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102F98:
    // 0x80102F98: b           L_80102FA4
    // 0x80102F9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80102FA4;
    // 0x80102F9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80102FA0:
    // 0x80102FA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102FA4:
    // 0x80102FA4: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80102FA8: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80102FAC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80102FB0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80102FB4: sll         $t6, $t0, 24
    ctx->r14 = S32(ctx->r8 << 24);
    // 0x80102FB8: bc1fl       L_80102FDC
    if (!c1cs) {
        // 0x80102FBC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80102FDC;
    }
    goto skip_0;
    // 0x80102FBC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80102FC0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80102FC4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80102FC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80102FCC: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80102FD0: b           L_80102FFC
    // 0x80102FD4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
        goto L_80102FFC;
    // 0x80102FD4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80102FD8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80102FDC:
    // 0x80102FDC: nop

    // 0x80102FE0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80102FE4: nop

    // 0x80102FE8: bc1fl       L_80103000
    if (!c1cs) {
        // 0x80102FEC: lhu         $t5, 0x2($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X2);
            goto L_80103000;
    }
    goto skip_1;
    // 0x80102FEC: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    skip_1:
    // 0x80102FF0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80102FF4: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80102FF8: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_80102FFC:
    // 0x80102FFC: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
L_80103000:
    // 0x80103000: bnel        $t5, $zero, L_80103050
    if (ctx->r13 != 0) {
        // 0x80103004: lw          $a2, 0x0($t4)
        ctx->r6 = MEM_W(ctx->r12, 0X0);
            goto L_80103050;
    }
    goto skip_2;
    // 0x80103004: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    skip_2:
    // 0x80103008: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8010300C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80103010: beql        $v1, $at, L_80103024
    if (ctx->r3 == ctx->r1) {
        // 0x80103014: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80103024;
    }
    goto skip_3;
    // 0x80103014: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_3:
    // 0x80103018: bne         $a2, $v1, L_80103030
    if (ctx->r6 != ctx->r3) {
        // 0x8010301C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80103030;
    }
    // 0x8010301C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80103020: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80103024:
    // 0x80103024: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80103028: b           L_8010304C
    // 0x8010302C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
        goto L_8010304C;
    // 0x8010302C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_80103030:
    // 0x80103030: beq         $v1, $at, L_80103040
    if (ctx->r3 == ctx->r1) {
        // 0x80103034: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80103040;
    }
    // 0x80103034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80103038: bnel        $v1, $at, L_80103050
    if (ctx->r3 != ctx->r1) {
        // 0x8010303C: lw          $a2, 0x0($t4)
        ctx->r6 = MEM_W(ctx->r12, 0X0);
            goto L_80103050;
    }
    goto skip_4;
    // 0x8010303C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    skip_4:
L_80103040:
    // 0x80103040: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80103044: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80103048: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8010304C:
    // 0x8010304C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
L_80103050:
    // 0x80103050: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80103054: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80103058: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8010305C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80103060: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80103064: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80103068: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010306C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x80103070: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x80103074: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80103078: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8010307C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80103080: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80103084: sll         $t9, $t0, 8
    ctx->r25 = S32(ctx->r8 << 8);
    // 0x80103088: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8010308C: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x80103090: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x80103094: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80103098: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8010309C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x801030A0: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x801030A4: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x801030A8: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x801030AC: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801030B0: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x801030B4: ori         $t5, $t5, 0x41C8
    ctx->r13 = ctx->r13 | 0X41C8;
    // 0x801030B8: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x801030BC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801030C0: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x801030C4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801030C8: addiu       $t8, $t8, 0x33A0
    ctx->r24 = ADD32(ctx->r24, 0X33A0);
    // 0x801030CC: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x801030D0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801030D4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801030D8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801030DC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801030E0: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x801030E4: lui         $t5, 0xF654
    ctx->r13 = S32(0XF654 << 16);
    // 0x801030E8: ori         $t5, $t5, 0xF00
    ctx->r13 = ctx->r13 | 0XF00;
    // 0x801030EC: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x801030F0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x801030F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801030F8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801030FC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80103100: jr          $ra
    // 0x80103104: sw          $v0, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = ctx->r2;
    return;
    // 0x80103104: sw          $v0, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = ctx->r2;
    // 0x80103108: nop

    // 0x8010310C: nop

;}
RECOMP_FUNC void func_8000B530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B530: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000B534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B538: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000B53C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B540: lui         $v1, 0x803B
    ctx->r3 = S32(0X803B << 16);
    // 0x8000B544: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B548: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000B54C: sw          $zero, -0x2E60($at)
    MEM_W(-0X2E60, ctx->r1) = 0;
    // 0x8000B550: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
    // 0x8000B554: lw          $v0, 0x4EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE4);
    // 0x8000B558: addiu       $v1, $v1, -0x6530
    ctx->r3 = ADD32(ctx->r3, -0X6530);
    // 0x8000B55C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000B560: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_8000B564:
    // 0x8000B564: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8000B568: bnel        $v0, $t6, L_8000B5FC
    if (ctx->r2 != ctx->r14) {
        // 0x8000B56C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8000B5FC;
    }
    goto skip_0;
    // 0x8000B56C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8000B570: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000B574: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x8000B578: bnel        $t7, $t8, L_8000B5FC
    if (ctx->r15 != ctx->r24) {
        // 0x8000B57C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8000B5FC;
    }
    goto skip_1;
    // 0x8000B57C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8000B580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B584: jal         0x8000B9D8
    // 0x8000B588: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8000B9D8(rdram, ctx);
        goto after_0;
    // 0x8000B588: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000B58C: bne         $v0, $zero, L_8000B604
    if (ctx->r2 != 0) {
        // 0x8000B590: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8000B604;
    }
    // 0x8000B590: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000B594: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x8000B598: lui         $t1, 0x803B
    ctx->r9 = S32(0X803B << 16);
    // 0x8000B59C: addiu       $t1, $t1, -0x6570
    ctx->r9 = ADD32(ctx->r9, -0X6570);
    // 0x8000B5A0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000B5A4: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8000B5A8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8000B5AC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8000B5B0: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x8000B5B4: addiu       $a1, $a1, 0x7BC0
    ctx->r5 = ADD32(ctx->r5, 0X7BC0);
    // 0x8000B5B8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8000B5BC: jal         0x80024260
    // 0x8000B5C0: subu        $a2, $a3, $a0
    ctx->r6 = SUB32(ctx->r7, ctx->r4);
    dma_write(rdram, ctx);
        goto after_1;
    // 0x8000B5C0: subu        $a2, $a3, $a0
    ctx->r6 = SUB32(ctx->r7, ctx->r4);
    after_1:
    // 0x8000B5C4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000B5C8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000B5CC: addiu       $t2, $t2, -0x2E58
    ctx->r10 = ADD32(ctx->r10, -0X2E58);
    // 0x8000B5D0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8000B5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B5D8: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8000B5DC: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8000B5E0: jal         0x8000B7DC
    // 0x8000B5E4: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    func_8000B7DC(rdram, ctx);
        goto after_2;
    // 0x8000B5E4: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    after_2:
    // 0x8000B5E8: addiu       $t3, $s0, 0x1
    ctx->r11 = ADD32(ctx->r16, 0X1);
    // 0x8000B5EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B5F0: b           L_8000B604
    // 0x8000B5F4: sw          $t3, -0x2E60($at)
    MEM_W(-0X2E60, ctx->r1) = ctx->r11;
        goto L_8000B604;
    // 0x8000B5F4: sw          $t3, -0x2E60($at)
    MEM_W(-0X2E60, ctx->r1) = ctx->r11;
    // 0x8000B5F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8000B5FC:
    // 0x8000B5FC: bne         $s0, $a1, L_8000B564
    if (ctx->r16 != ctx->r5) {
        // 0x8000B600: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_8000B564;
    }
    // 0x8000B600: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_8000B604:
    // 0x8000B604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B60C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000B610: jr          $ra
    // 0x8000B614: nop

    return;
    // 0x8000B614: nop

;}
RECOMP_FUNC void func_80010EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010EC8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80010ECC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80010ED0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80010ED4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80010ED8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80010EDC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80010EE0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010EE4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80010EE8: lw          $v0, 0x5394($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5394);
    // 0x80010EEC: addiu       $v1, $v1, 0x53A0
    ctx->r3 = ADD32(ctx->r3, 0X53A0);
    // 0x80010EF0: beq         $a2, $zero, L_80011090
    if (ctx->r6 == 0) {
        // 0x80010EF4: lw          $a1, 0x5398($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X5398);
            goto L_80011090;
    }
    // 0x80010EF4: lw          $a1, 0x5398($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5398);
    // 0x80010EF8: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80010EFC: beq         $a3, $zero, L_800110B8
    if (ctx->r7 == 0) {
        // 0x80010F00: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800110B8;
    }
    // 0x80010F00: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80010F04: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80010F08: addiu       $s3, $s3, 0x5390
    ctx->r19 = ADD32(ctx->r19, 0X5390);
L_80010F0C:
    // 0x80010F0C: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x80010F10: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80010F14: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x80010F18: andi        $a3, $t0, 0xF800
    ctx->r7 = ctx->r8 & 0XF800;
    // 0x80010F1C: sra         $t6, $a3, 11
    ctx->r14 = S32(SIGNED(ctx->r7) >> 11);
    // 0x80010F20: andi        $a3, $t6, 0xFFFF
    ctx->r7 = ctx->r14 & 0XFFFF;
    // 0x80010F24: subu        $s2, $s1, $a2
    ctx->r18 = SUB32(ctx->r17, ctx->r6);
    // 0x80010F28: multu       $a3, $s2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010F2C: andi        $t2, $t0, 0x3E
    ctx->r10 = ctx->r8 & 0X3E;
    // 0x80010F30: sra         $t6, $t2, 1
    ctx->r14 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80010F34: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80010F38: andi        $t5, $t4, 0x7C0
    ctx->r13 = ctx->r12 & 0X7C0;
    // 0x80010F3C: sra         $t6, $t5, 6
    ctx->r14 = S32(SIGNED(ctx->r13) >> 6);
    // 0x80010F40: andi        $t1, $t0, 0x7C0
    ctx->r9 = ctx->r8 & 0X7C0;
    // 0x80010F44: sra         $t8, $t1, 6
    ctx->r24 = S32(SIGNED(ctx->r9) >> 6);
    // 0x80010F48: andi        $t5, $t6, 0xFFFF
    ctx->r13 = ctx->r14 & 0XFFFF;
    // 0x80010F4C: andi        $t1, $t8, 0xFFFF
    ctx->r9 = ctx->r24 & 0XFFFF;
    // 0x80010F50: mflo        $t6
    ctx->r14 = lo;
    // 0x80010F54: andi        $t3, $t4, 0xF800
    ctx->r11 = ctx->r12 & 0XF800;
    // 0x80010F58: sra         $t8, $t3, 11
    ctx->r24 = S32(SIGNED(ctx->r11) >> 11);
    // 0x80010F5C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80010F60: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010F64: andi        $s0, $t4, 0x3E
    ctx->r16 = ctx->r12 & 0X3E;
    // 0x80010F68: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80010F6C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80010F70: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80010F74: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80010F78: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80010F7C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80010F80: mflo        $t7
    ctx->r15 = lo;
    // 0x80010F84: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80010F88: nop

    // 0x80010F8C: div         $zero, $t8, $s1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r17)));
    // 0x80010F90: mflo        $a3
    ctx->r7 = lo;
    // 0x80010F94: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x80010F98: bne         $s1, $zero, L_80010FA4
    if (ctx->r17 != 0) {
        // 0x80010F9C: nop
    
            goto L_80010FA4;
    }
    // 0x80010F9C: nop

    // 0x80010FA0: break       7
    do_break(2147553184);
L_80010FA4:
    // 0x80010FA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010FA8: bne         $s1, $at, L_80010FBC
    if (ctx->r17 != ctx->r1) {
        // 0x80010FAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80010FBC;
    }
    // 0x80010FAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80010FB0: bne         $t8, $at, L_80010FBC
    if (ctx->r24 != ctx->r1) {
        // 0x80010FB4: nop
    
            goto L_80010FBC;
    }
    // 0x80010FB4: nop

    // 0x80010FB8: break       6
    do_break(2147553208);
L_80010FBC:
    // 0x80010FBC: multu       $t1, $s2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010FC0: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80010FC4: mflo        $t6
    ctx->r14 = lo;
    // 0x80010FC8: nop

    // 0x80010FCC: nop

    // 0x80010FD0: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010FD4: mflo        $t7
    ctx->r15 = lo;
    // 0x80010FD8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80010FDC: nop

    // 0x80010FE0: div         $zero, $t8, $s1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r17)));
    // 0x80010FE4: mflo        $t1
    ctx->r9 = lo;
    // 0x80010FE8: andi        $t9, $t1, 0xFFFF
    ctx->r25 = ctx->r9 & 0XFFFF;
    // 0x80010FEC: bne         $s1, $zero, L_80010FF8
    if (ctx->r17 != 0) {
        // 0x80010FF0: nop
    
            goto L_80010FF8;
    }
    // 0x80010FF0: nop

    // 0x80010FF4: break       7
    do_break(2147553268);
L_80010FF8:
    // 0x80010FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80010FFC: bne         $s1, $at, L_80011010
    if (ctx->r17 != ctx->r1) {
        // 0x80011000: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80011010;
    }
    // 0x80011000: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80011004: bne         $t8, $at, L_80011010
    if (ctx->r24 != ctx->r1) {
        // 0x80011008: nop
    
            goto L_80011010;
    }
    // 0x80011008: nop

    // 0x8001100C: break       6
    do_break(2147553292);
L_80011010:
    // 0x80011010: multu       $t2, $s2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011014: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80011018: mflo        $t6
    ctx->r14 = lo;
    // 0x8001101C: nop

    // 0x80011020: nop

    // 0x80011024: multu       $s0, $a2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011028: mflo        $t7
    ctx->r15 = lo;
    // 0x8001102C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80011030: sll         $t6, $a3, 11
    ctx->r14 = S32(ctx->r7 << 11);
    // 0x80011034: div         $zero, $t8, $s1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r17)));
    // 0x80011038: mflo        $t2
    ctx->r10 = lo;
    // 0x8001103C: andi        $t9, $t2, 0xFFFF
    ctx->r25 = ctx->r10 & 0XFFFF;
    // 0x80011040: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x80011044: sll         $t7, $t1, 6
    ctx->r15 = S32(ctx->r9 << 6);
    // 0x80011048: bne         $s1, $zero, L_80011054
    if (ctx->r17 != 0) {
        // 0x8001104C: nop
    
            goto L_80011054;
    }
    // 0x8001104C: nop

    // 0x80011050: break       7
    do_break(2147553360);
L_80011054:
    // 0x80011054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011058: bne         $s1, $at, L_8001106C
    if (ctx->r17 != ctx->r1) {
        // 0x8001105C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001106C;
    }
    // 0x8001105C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80011060: bne         $t8, $at, L_8001106C
    if (ctx->r24 != ctx->r1) {
        // 0x80011064: nop
    
            goto L_8001106C;
    }
    // 0x80011064: nop

    // 0x80011068: break       6
    do_break(2147553384);
L_8001106C:
    // 0x8001106C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80011070: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80011074: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011078: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8001107C: sh          $t6, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r14;
    // 0x80011080: bne         $a0, $zero, L_80010F0C
    if (ctx->r4 != 0) {
        // 0x80011084: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80010F0C;
    }
    // 0x80011084: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80011088: b           L_800110BC
    // 0x8001108C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_800110BC;
    // 0x8001108C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_80011090:
    // 0x80011090: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80011094: beq         $a3, $zero, L_800110B8
    if (ctx->r7 == 0) {
        // 0x80011098: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800110B8;
    }
    // 0x80011098: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8001109C:
    // 0x8001109C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800110A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800110A4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800110A8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800110AC: sh          $t7, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r15;
    // 0x800110B0: bne         $a0, $zero, L_8001109C
    if (ctx->r4 != 0) {
        // 0x800110B4: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8001109C;
    }
    // 0x800110B4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800110B8:
    // 0x800110B8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_800110BC:
    // 0x800110BC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800110C0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800110C4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800110C8: jr          $ra
    // 0x800110CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800110CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
