#include "recomp.h"
#include "funcs.h"

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
